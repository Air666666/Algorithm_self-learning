// Source: src/class150/Code01_ShowDetails.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_ShowDetails {
  inline static int max = {};
  inline static int cost = {};
  inline static double ALPHA = 0.7;
  inline static int MAXN = 100001;
  inline static int head = 0;
  inline static int cnt = 0;
  inline static Array<int> key = make_array<int>(MAXN);
  inline static Array<int> count = make_array<int>(MAXN);
  inline static Array<int> left = make_array<int>(MAXN);
  inline static Array<int> right = make_array<int>(MAXN);
  inline static Array<int> size = make_array<int>(MAXN);
  inline static Array<int> diff = make_array<int>(MAXN);
  inline static Array<int> collect = make_array<int>(MAXN);
  inline static int ci = {};
  inline static int top = {};
  inline static int father = {};
  inline static int side = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_ShowDetails() {}
  static void java_main(Array<String> args) {
    (ALPHA = 0.7);
    (max = 10000);
    jout.println(String(u"测试开始"));
    (cost = 0);
    for (int num = 1; (num <= max); (num++)) {
      Code01_ShowDetails::add(num);
    }
    jout.println(((String(u"插入数字 : ") + String(u"1~")) + max));
    jout.println((String(u"平衡因子 : ") + ALPHA));
    jout.println((String(u"树的高度 : ") + Code01_ShowDetails::deep(head)));
    jout.println((String(u"重构节点 : ") + cost));
    jout.println(String(u"测试结束"));
    Code01_ShowDetails::clear();
  }
  static int deep(int i) {
    if ((i == 0)) {
      return 0;
    }
    return ([&]() {
      auto jargument_0 = Code01_ShowDetails::deep(left[i]);
      auto jargument_1 = Code01_ShowDetails::deep(right[i]);
      return jmax(jargument_0, jargument_1);
    }() + 1);
  }
  static int init(int num) {
    (key[(++cnt)] = num);
    (left[cnt] = (right[cnt] = 0));
    (count[cnt] = (size[cnt] = (diff[cnt] = 1)));
    return cnt;
  }
  static void up(int i) {
    (size[i] = ((size[left[i]] + size[right[i]]) + count[i]));
    (diff[i] = ((diff[left[i]] + diff[right[i]]) + ((count[i] > 0) ? 1 : 0)));
  }
  static void inorder(int i) {
    if ((i != 0)) {
      Code01_ShowDetails::inorder(left[i]);
      if ((count[i] > 0)) {
        (collect[(++ci)] = i);
      }
      Code01_ShowDetails::inorder(right[i]);
    }
  }
  static int build(int l, int r) {
    if ((l > r)) {
      return 0;
    }
    int m = jdiv((l + r), 2);
    int h = collect[m];
    (left[h] = Code01_ShowDetails::build(l, (m - 1)));
    (right[h] = Code01_ShowDetails::build((m + 1), r));
    Code01_ShowDetails::up(h);
    return h;
  }
  static void rebuild() {
    if ((top != 0)) {
      (ci = 0);
      Code01_ShowDetails::inorder(top);
      if ((ci > 0)) {
        (cost += ci);
        if ((father == 0)) {
          (head = Code01_ShowDetails::build(1, ci));
        } else if ((side == 1)) {
          (left[father] = Code01_ShowDetails::build(1, ci));
        } else {
          (right[father] = Code01_ShowDetails::build(1, ci));
        }
      }
    }
  }
  static bool balance(int i) {
    return ((ALPHA * diff[i]) >= jmax(diff[left[i]], diff[right[i]]));
  }
  static void add(int i, int f, int s, int num) {
    if ((i == 0)) {
      if ((f == 0)) {
        (head = Code01_ShowDetails::init(num));
      } else if ((s == 1)) {
        (left[f] = Code01_ShowDetails::init(num));
      } else {
        (right[f] = Code01_ShowDetails::init(num));
      }
    } else {
      if ((key[i] == num)) {
        (count[i]++);
      } else if ((key[i] > num)) {
        Code01_ShowDetails::add(left[i], i, 1, num);
      } else {
        Code01_ShowDetails::add(right[i], i, 2, num);
      }
      Code01_ShowDetails::up(i);
      if ((!Code01_ShowDetails::balance(i))) {
        (top = i);
        (father = f);
        (side = s);
      }
    }
  }
  static void add(int num) {
    (top = (father = (side = 0)));
    Code01_ShowDetails::add(head, 0, 0, num);
    Code01_ShowDetails::rebuild();
  }
  static int small(int i, int num) {
    if ((i == 0)) {
      return 0;
    }
    if ((key[i] >= num)) {
      return Code01_ShowDetails::small(left[i], num);
    } else {
      return ((size[left[i]] + count[i]) +
              Code01_ShowDetails::small(right[i], num));
    }
  }
  static int rank(int num) {
    return (Code01_ShowDetails::small(head, num) + 1);
  }
  static int index(int i, int x) {
    if ((size[left[i]] >= x)) {
      return Code01_ShowDetails::index(left[i], x);
    } else if (((size[left[i]] + count[i]) < x)) {
      return Code01_ShowDetails::index(right[i],
                                       ((x - size[left[i]]) - count[i]));
    }
    return key[i];
  }
  static int index(int x) { return Code01_ShowDetails::index(head, x); }
  static int pre(int num) {
    int kth = Code01_ShowDetails::rank(num);
    if ((kth == 1)) {
      return std::numeric_limits<int>::min();
    } else {
      return Code01_ShowDetails::index((kth - 1));
    }
  }
  static int post(int num) {
    int kth = Code01_ShowDetails::rank((num + 1));
    if ((kth == (size[head] + 1))) {
      return std::numeric_limits<int>::max();
    } else {
      return Code01_ShowDetails::index(kth);
    }
  }
  static void remove(int i, int f, int s, int num) {
    if ((key[i] == num)) {
      (count[i]--);
    } else if ((key[i] > num)) {
      Code01_ShowDetails::remove(left[i], i, 1, num);
    } else {
      Code01_ShowDetails::remove(right[i], i, 2, num);
    }
    Code01_ShowDetails::up(i);
    if ((!Code01_ShowDetails::balance(i))) {
      (top = i);
      (father = f);
      (side = s);
    }
  }
  static void remove(int num) {
    if ([&]() {
          auto jleft = Code01_ShowDetails::rank(num);
          auto jright = Code01_ShowDetails::rank((num + 1));
          return (jleft != jright);
        }()) {
      (top = (father = (side = 0)));
      Code01_ShowDetails::remove(head, 0, 0, num);
      Code01_ShowDetails::rebuild();
    }
  }
  static void clear() {
    j::fill(key, 1, (cnt + 1), 0);
    j::fill(count, 1, (cnt + 1), 0);
    j::fill(left, 1, (cnt + 1), 0);
    j::fill(right, 1, (cnt + 1), 0);
    j::fill(size, 1, (cnt + 1), 0);
    j::fill(diff, 1, (cnt + 1), 0);
    (cnt = 0);
    (head = 0);
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code01_ShowDetails::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 平衡因子影响替罪羊树的实验
// 一旦，max(左树节点数，右树节点数) > 平衡因子 * 整树节点数，就会发生重构
// 平衡因子范围是(0.5, 1.0)，否则无意义
// 平衡因子等于0.5时，树高很小，查询效率高，但是重构发生很频繁
// 平衡因子等于1.0时，重构完全不发生，但是树高很大，查询效率低
// 保证查询效率、同时保证重构的节点总数不多，0.7为最常用的平衡因子
// 这保证了查询效率，因为树高几乎是O(log n)
// 同时重构触发的时机合适，单次调整的均摊代价为O(log n)
        // 统计树高
*/

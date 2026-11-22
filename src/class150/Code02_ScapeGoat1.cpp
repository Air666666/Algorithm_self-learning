// Source: src/class150/Code02_ScapeGoat1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_ScapeGoat1 {
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
  Code02_ScapeGoat1() {}
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
      Code02_ScapeGoat1::inorder(left[i]);
      if ((count[i] > 0)) {
        (collect[(++ci)] = i);
      }
      Code02_ScapeGoat1::inorder(right[i]);
    }
  }
  static int build(int l, int r) {
    if ((l > r)) {
      return 0;
    }
    int m = jdiv((l + r), 2);
    int h = collect[m];
    (left[h] = Code02_ScapeGoat1::build(l, (m - 1)));
    (right[h] = Code02_ScapeGoat1::build((m + 1), r));
    Code02_ScapeGoat1::up(h);
    return h;
  }
  static void rebuild() {
    if ((top != 0)) {
      (ci = 0);
      Code02_ScapeGoat1::inorder(top);
      if ((ci > 0)) {
        if ((father == 0)) {
          (head = Code02_ScapeGoat1::build(1, ci));
        } else if ((side == 1)) {
          (left[father] = Code02_ScapeGoat1::build(1, ci));
        } else {
          (right[father] = Code02_ScapeGoat1::build(1, ci));
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
        (head = Code02_ScapeGoat1::init(num));
      } else if ((s == 1)) {
        (left[f] = Code02_ScapeGoat1::init(num));
      } else {
        (right[f] = Code02_ScapeGoat1::init(num));
      }
    } else {
      if ((key[i] == num)) {
        (count[i]++);
      } else if ((key[i] > num)) {
        Code02_ScapeGoat1::add(left[i], i, 1, num);
      } else {
        Code02_ScapeGoat1::add(right[i], i, 2, num);
      }
      Code02_ScapeGoat1::up(i);
      if ((!Code02_ScapeGoat1::balance(i))) {
        (top = i);
        (father = f);
        (side = s);
      }
    }
  }
  static void add(int num) {
    (top = (father = (side = 0)));
    Code02_ScapeGoat1::add(head, 0, 0, num);
    Code02_ScapeGoat1::rebuild();
  }
  static int small(int i, int num) {
    if ((i == 0)) {
      return 0;
    }
    if ((key[i] >= num)) {
      return Code02_ScapeGoat1::small(left[i], num);
    } else {
      return ((size[left[i]] + count[i]) +
              Code02_ScapeGoat1::small(right[i], num));
    }
  }
  static int rank(int num) { return (Code02_ScapeGoat1::small(head, num) + 1); }
  static int index(int i, int x) {
    if ((size[left[i]] >= x)) {
      return Code02_ScapeGoat1::index(left[i], x);
    } else if (((size[left[i]] + count[i]) < x)) {
      return Code02_ScapeGoat1::index(right[i],
                                      ((x - size[left[i]]) - count[i]));
    }
    return key[i];
  }
  static int index(int x) { return Code02_ScapeGoat1::index(head, x); }
  static int pre(int num) {
    int kth = Code02_ScapeGoat1::rank(num);
    if ((kth == 1)) {
      return std::numeric_limits<int>::min();
    } else {
      return Code02_ScapeGoat1::index((kth - 1));
    }
  }
  static int post(int num) {
    int kth = Code02_ScapeGoat1::rank((num + 1));
    if ((kth == (size[head] + 1))) {
      return std::numeric_limits<int>::max();
    } else {
      return Code02_ScapeGoat1::index(kth);
    }
  }
  static void remove(int i, int f, int s, int num) {
    if ((key[i] == num)) {
      (count[i]--);
    } else if ((key[i] > num)) {
      Code02_ScapeGoat1::remove(left[i], i, 1, num);
    } else {
      Code02_ScapeGoat1::remove(right[i], i, 2, num);
    }
    Code02_ScapeGoat1::up(i);
    if ((!Code02_ScapeGoat1::balance(i))) {
      (top = i);
      (father = f);
      (side = s);
    }
  }
  static void remove(int num) {
    if ([&]() {
          auto jleft = Code02_ScapeGoat1::rank(num);
          auto jright = Code02_ScapeGoat1::rank((num + 1));
          return (jleft != jright);
        }()) {
      (top = (father = (side = 0)));
      Code02_ScapeGoat1::remove(head, 0, 0, num);
      Code02_ScapeGoat1::rebuild();
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
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    int n = static_cast<int>(in.nval);
    {
      int i = 1;
      int op = {};
      int x = {};
      for (; (i <= n); (i++)) {
        in.nextToken();
        (op = static_cast<int>(in.nval));
        in.nextToken();
        (x = static_cast<int>(in.nval));
        if ((op == 1)) {
          Code02_ScapeGoat1::add(x);
        } else if ((op == 2)) {
          Code02_ScapeGoat1::remove(x);
        } else if ((op == 3)) {
          out.println(Code02_ScapeGoat1::rank(x));
        } else if ((op == 4)) {
          out.println(Code02_ScapeGoat1::index(x));
        } else if ((op == 5)) {
          out.println(Code02_ScapeGoat1::pre(x));
        } else {
          out.println(Code02_ScapeGoat1::post(x));
        }
      }
    }
    Code02_ScapeGoat1::clear();
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code02_ScapeGoat1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 替罪羊树的实现(java版)
// 实现一种结构，支持如下操作，要求单次调用的时间复杂度O(log n)
// 1，增加x，重复加入算多个词频
// 2，删除x，如果有多个，只删掉一个
// 3，查询x的排名，x的排名为，比x小的数的个数+1
// 4，查询数据中排名为x的数
// 5，查询x的前驱，x的前驱为，小于x的数中最大的数，不存在返回整数最小值
// 6，查询x的后继，x的后继为，大于x的数中最小的数，不存在返回整数最大值
// 所有操作的次数 <= 10^5
// -10^7 <= x <= +10^7
// 测试链接 : https://www.luogu.com.cn/problem/P3369
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 平衡因子
        // 空间的最大使用量
        // 整棵树的头节点编号
        // 空间使用计数
        // 节点的key值
        // 节点key的计数
        // 左孩子
        // 右孩子
        // 数字总数
        // 节点总数
        // 中序收集节点的数组
        // 中序收集节点的计数
        // 最上方的不平衡节点
        // top的父节点
        // top是父节点的什么孩子，1代表左孩子，2代表右孩子
*/

// Source: src/class152/Code05_PersistentFHQTreap1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code05_PersistentFHQTreap1 {
  inline static int MAXN = 500001;
  inline static int MAXM = (MAXN * 50);
  inline static int cnt = 0;
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> key = make_array<int>(MAXM);
  inline static Array<int> left = make_array<int>(MAXM);
  inline static Array<int> right = make_array<int>(MAXM);
  inline static Array<int> size = make_array<int>(MAXM);
  inline static Array<double> priority = make_array<double>(MAXM);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code05_PersistentFHQTreap1() {}
  static int copy(int i) {
    (key[(++cnt)] = key[i]);
    (left[cnt] = left[i]);
    (right[cnt] = right[i]);
    (size[cnt] = size[i]);
    (priority[cnt] = priority[i]);
    return cnt;
  }
  static void up(int i) { (size[i] = ((size[left[i]] + size[right[i]]) + 1)); }
  static void split(int l, int r, int i, int num) {
    if ((i == 0)) {
      (right[l] = (left[r] = 0));
    } else {
      (i = Code05_PersistentFHQTreap1::copy(i));
      if ((key[i] <= num)) {
        (right[l] = i);
        Code05_PersistentFHQTreap1::split(i, r, right[i], num);
      } else {
        (left[r] = i);
        Code05_PersistentFHQTreap1::split(l, i, left[i], num);
      }
      Code05_PersistentFHQTreap1::up(i);
    }
  }
  static int merge(int l, int r) {
    if (((l == 0) || (r == 0))) {
      return (l + r);
    }
    if ((priority[l] >= priority[r])) {
      (l = Code05_PersistentFHQTreap1::copy(l));
      (right[l] = Code05_PersistentFHQTreap1::merge(right[l], r));
      Code05_PersistentFHQTreap1::up(l);
      return l;
    } else {
      (r = Code05_PersistentFHQTreap1::copy(r));
      (left[r] = Code05_PersistentFHQTreap1::merge(l, left[r]));
      Code05_PersistentFHQTreap1::up(r);
      return r;
    }
  }
  static void add(int v, int i, int num) {
    Code05_PersistentFHQTreap1::split(0, 0, i, num);
    int l = right[0];
    int r = left[0];
    (left[0] = (right[0] = 0));
    (key[(++cnt)] = num);
    (size[cnt] = 1);
    (priority[cnt] = j::random());
    (head[v] = Code05_PersistentFHQTreap1::merge(
         Code05_PersistentFHQTreap1::merge(l, cnt), r));
  }
  static void remove(int v, int i, int num) {
    Code05_PersistentFHQTreap1::split(0, 0, i, num);
    int lm = right[0];
    int r = left[0];
    Code05_PersistentFHQTreap1::split(0, 0, lm, (num - 1));
    int l = right[0];
    int m = left[0];
    (left[0] = (right[0] = 0));
    (head[v] = Code05_PersistentFHQTreap1::merge(
         Code05_PersistentFHQTreap1::merge(
             l, Code05_PersistentFHQTreap1::merge(left[m], right[m])),
         r));
  }
  static int small(int i, int num) {
    if ((i == 0)) {
      return 0;
    }
    if ((key[i] >= num)) {
      return Code05_PersistentFHQTreap1::small(left[i], num);
    } else {
      return ((size[left[i]] + 1) +
              Code05_PersistentFHQTreap1::small(right[i], num));
    }
  }
  static int index(int i, int x) {
    if ((size[left[i]] >= x)) {
      return Code05_PersistentFHQTreap1::index(left[i], x);
    } else if (((size[left[i]] + 1) < x)) {
      return Code05_PersistentFHQTreap1::index(right[i],
                                               ((x - size[left[i]]) - 1));
    } else {
      return key[i];
    }
  }
  static int pre(int i, int num) {
    if ((i == 0)) {
      return (std::numeric_limits<int>::min() + 1);
    }
    if ((key[i] >= num)) {
      return Code05_PersistentFHQTreap1::pre(left[i], num);
    } else {
      return jmax(key[i], Code05_PersistentFHQTreap1::pre(right[i], num));
    }
  }
  static int post(int i, int num) {
    if ((i == 0)) {
      return std::numeric_limits<int>::max();
    }
    if ((key[i] <= num)) {
      return Code05_PersistentFHQTreap1::post(right[i], num);
    } else {
      return jmin(key[i], Code05_PersistentFHQTreap1::post(left[i], num));
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(jout);
    int n = in.readInt();
    {
      int i = 1;
      int version = {};
      int op = {};
      int x = {};
      for (; (i <= n); (i++)) {
        (version = in.readInt());
        (op = in.readInt());
        (x = in.readInt());
        if ((op == 1)) {
          Code05_PersistentFHQTreap1::add(i, head[version], x);
        } else if ((op == 2)) {
          Code05_PersistentFHQTreap1::remove(i, head[version], x);
        } else {
          (head[i] = head[version]);
          if ((op == 3)) {
            out.println((Code05_PersistentFHQTreap1::small(head[i], x) + 1));
          } else if ((op == 4)) {
            out.println(Code05_PersistentFHQTreap1::index(head[i], x));
          } else if ((op == 5)) {
            out.println(Code05_PersistentFHQTreap1::pre(head[i], x));
          } else {
            out.println(Code05_PersistentFHQTreap1::post(head[i], x));
          }
        }
      }
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code05_PersistentFHQTreap1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 可持久化平衡树，FHQ-Treap实现，不用词频压缩，java版
// 认为一开始是0版本的树，为空树，实现如下操作，操作一共发生n次
// v 1 x : 基于v版本的树，增加一个x，生成新版本的树
// v 2 x : 基于v版本的树，删除一个x，生成新版本的树
// v 3 x : 基于v版本的树，查询x的排名，生成新版本的树状况=v版本状况
// v 4 x : 基于v版本的树，查询数据中排名为x的数，生成新版本的树状况=v版本状况
// v 5 x : 基于v版本的树，查询x的前驱，生成新版本的树状况=v版本状况
// v 6 x : 基于v版本的树，查询x的后继，生成新版本的树状况=v版本状况
// 不管什么操作，都基于某个v版本，操作完成后得到新版本的树，但v版本不会变化
// 如果x的前驱不存在，返回-2^31 + 1，如果x的后继不存在，返回+2^31 - 1
// 1 <= n <= 5 * 10^5
// -10^9 <= x <= +10^9
// 测试链接 : https://www.luogu.com.cn/problem/P3835
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // v : 新生成的版本编号
        // i : 基于的历史版本，树的头节点编号
        // num : 加入的数字
                //
后续可能基于0版本，去生成新版本的树，所以一定要清空，保证0版本始终是空树
        // v : 新生成的版本编号
        // i : 基于的历史版本，树的头节点编号
        // num : 加入的数字
                //
后续可能基于0版本，去生成新版本的树，所以一定要清空，保证0版本始终是空树
        // 快读
        // 快写
*/

// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P3369

// Source: src/class151/Code02_Treap1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_Treap1 {
  inline static int MAXN = 100001;
  inline static int head = 0;
  inline static int cnt = 0;
  inline static Array<int> key = make_array<int>(MAXN);
  inline static Array<int> count = make_array<int>(MAXN);
  inline static Array<int> left = make_array<int>(MAXN);
  inline static Array<int> right = make_array<int>(MAXN);
  inline static Array<int> size = make_array<int>(MAXN);
  inline static Array<double> priority = make_array<double>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_Treap1() {}
  static void up(int i) {
    (size[i] = ((size[left[i]] + size[right[i]]) + count[i]));
  }
  static int leftRotate(int i) {
    int r = right[i];
    (right[i] = left[r]);
    (left[r] = i);
    Code02_Treap1::up(i);
    Code02_Treap1::up(r);
    return r;
  }
  static int rightRotate(int i) {
    int l = left[i];
    (left[i] = right[l]);
    (right[l] = i);
    Code02_Treap1::up(i);
    Code02_Treap1::up(l);
    return l;
  }
  static int add(int i, int num) {
    if ((i == 0)) {
      (key[(++cnt)] = num);
      (count[cnt] = (size[cnt] = 1));
      (priority[cnt] = j::random());
      return cnt;
    }
    if ((key[i] == num)) {
      (count[i]++);
    } else if ((key[i] > num)) {
      (left[i] = Code02_Treap1::add(left[i], num));
    } else {
      (right[i] = Code02_Treap1::add(right[i], num));
    }
    Code02_Treap1::up(i);
    if (((left[i] != 0) && (priority[left[i]] > priority[i]))) {
      return Code02_Treap1::rightRotate(i);
    }
    if (((right[i] != 0) && (priority[right[i]] > priority[i]))) {
      return Code02_Treap1::leftRotate(i);
    }
    return i;
  }
  static void add(int num) { (head = Code02_Treap1::add(head, num)); }
  static int small(int i, int num) {
    if ((i == 0)) {
      return 0;
    }
    if ((key[i] >= num)) {
      return Code02_Treap1::small(left[i], num);
    } else {
      return ((size[left[i]] + count[i]) + Code02_Treap1::small(right[i], num));
    }
  }
  static int rank(int num) { return (Code02_Treap1::small(head, num) + 1); }
  static int index(int i, int x) {
    if ((size[left[i]] >= x)) {
      return Code02_Treap1::index(left[i], x);
    } else if (((size[left[i]] + count[i]) < x)) {
      return Code02_Treap1::index(right[i], ((x - size[left[i]]) - count[i]));
    }
    return key[i];
  }
  static int index(int x) { return Code02_Treap1::index(head, x); }
  static int pre(int i, int num) {
    if ((i == 0)) {
      return std::numeric_limits<int>::min();
    }
    if ((key[i] >= num)) {
      return Code02_Treap1::pre(left[i], num);
    } else {
      return jmax(key[i], Code02_Treap1::pre(right[i], num));
    }
  }
  static int pre(int num) { return Code02_Treap1::pre(head, num); }
  static int post(int i, int num) {
    if ((i == 0)) {
      return std::numeric_limits<int>::max();
    }
    if ((key[i] <= num)) {
      return Code02_Treap1::post(right[i], num);
    } else {
      return jmin(key[i], Code02_Treap1::post(left[i], num));
    }
  }
  static int post(int num) { return Code02_Treap1::post(head, num); }
  static int remove(int i, int num) {
    if ((key[i] < num)) {
      (right[i] = Code02_Treap1::remove(right[i], num));
    } else if ((key[i] > num)) {
      (left[i] = Code02_Treap1::remove(left[i], num));
    } else {
      if ((count[i] > 1)) {
        (count[i]--);
      } else {
        if (((left[i] == 0) && (right[i] == 0))) {
          return 0;
        } else if (((left[i] != 0) && (right[i] == 0))) {
          (i = left[i]);
        } else if (((left[i] == 0) && (right[i] != 0))) {
          (i = right[i]);
        } else {
          if ((priority[left[i]] >= priority[right[i]])) {
            (i = Code02_Treap1::rightRotate(i));
            (right[i] = Code02_Treap1::remove(right[i], num));
          } else {
            (i = Code02_Treap1::leftRotate(i));
            (left[i] = Code02_Treap1::remove(left[i], num));
          }
        }
      }
    }
    Code02_Treap1::up(i);
    return i;
  }
  static void remove(int num) {
    if ([&]() {
          auto jleft = Code02_Treap1::rank(num);
          auto jright = Code02_Treap1::rank((num + 1));
          return (jleft != jright);
        }()) {
      (head = Code02_Treap1::remove(head, num));
    }
  }
  static void clear() {
    j::fill(key, 1, (cnt + 1), 0);
    j::fill(count, 1, (cnt + 1), 0);
    j::fill(left, 1, (cnt + 1), 0);
    j::fill(right, 1, (cnt + 1), 0);
    j::fill(size, 1, (cnt + 1), 0);
    j::fill(priority, 1, (cnt + 1), 0);
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
          Code02_Treap1::add(x);
        } else if ((op == 2)) {
          Code02_Treap1::remove(x);
        } else if ((op == 3)) {
          out.println(Code02_Treap1::rank(x));
        } else if ((op == 4)) {
          out.println(Code02_Treap1::index(x));
        } else if ((op == 5)) {
          out.println(Code02_Treap1::pre(x));
        } else {
          out.println(Code02_Treap1::post(x));
        }
      }
    }
    Code02_Treap1::clear();
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code02_Treap1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// Treap树的实现(java版)
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
        // 整棵树的头节点编号
        // 空间使用计数
        // 节点的key值
        // 节点key的计数
        // 左孩子
        // 右孩子
        // 数字总数
        // 节点优先级
*/

// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P3369

// Source: src/class152/Code01_FHQTreapWithCount1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_FHQTreapWithCount1 {
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
  Code01_FHQTreapWithCount1() {}
  static void up(int i) {
    (size[i] = ((size[left[i]] + size[right[i]]) + count[i]));
  }
  static void split(int l, int r, int i, int num) {
    if ((i == 0)) {
      (right[l] = (left[r] = 0));
    } else {
      if ((key[i] <= num)) {
        (right[l] = i);
        Code01_FHQTreapWithCount1::split(i, r, right[i], num);
      } else {
        (left[r] = i);
        Code01_FHQTreapWithCount1::split(l, i, left[i], num);
      }
      Code01_FHQTreapWithCount1::up(i);
    }
  }
  static int merge(int l, int r) {
    if (((l == 0) || (r == 0))) {
      return (l + r);
    }
    if ((priority[l] >= priority[r])) {
      (right[l] = Code01_FHQTreapWithCount1::merge(right[l], r));
      Code01_FHQTreapWithCount1::up(l);
      return l;
    } else {
      (left[r] = Code01_FHQTreapWithCount1::merge(l, left[r]));
      Code01_FHQTreapWithCount1::up(r);
      return r;
    }
  }
  static int find(int i, int num) {
    if ((i == 0)) {
      return 0;
    }
    if ((key[i] == num)) {
      return i;
    } else if ((key[i] > num)) {
      return Code01_FHQTreapWithCount1::find(left[i], num);
    } else {
      return Code01_FHQTreapWithCount1::find(right[i], num);
    }
  }
  static void changeCount(int i, int num, int change) {
    if ((key[i] == num)) {
      (count[i] += change);
    } else if ((key[i] > num)) {
      Code01_FHQTreapWithCount1::changeCount(left[i], num, change);
    } else {
      Code01_FHQTreapWithCount1::changeCount(right[i], num, change);
    }
    Code01_FHQTreapWithCount1::up(i);
  }
  static void add(int num) {
    if ((Code01_FHQTreapWithCount1::find(head, num) != 0)) {
      Code01_FHQTreapWithCount1::changeCount(head, num, 1);
    } else {
      Code01_FHQTreapWithCount1::split(0, 0, head, num);
      (key[(++cnt)] = num);
      (count[cnt] = (size[cnt] = 1));
      (priority[cnt] = j::random());
      (head = Code01_FHQTreapWithCount1::merge(
           Code01_FHQTreapWithCount1::merge(right[0], cnt), left[0]));
    }
  }
  static void remove(int num) {
    int i = Code01_FHQTreapWithCount1::find(head, num);
    if ((i != 0)) {
      if ((count[i] > 1)) {
        Code01_FHQTreapWithCount1::changeCount(head, num, (-1));
      } else {
        Code01_FHQTreapWithCount1::split(0, 0, head, num);
        int lm = right[0];
        int r = left[0];
        Code01_FHQTreapWithCount1::split(0, 0, lm, (num - 1));
        int l = right[0];
        (head = Code01_FHQTreapWithCount1::merge(l, r));
      }
    }
  }
  static int small(int i, int num) {
    if ((i == 0)) {
      return 0;
    }
    if ((key[i] >= num)) {
      return Code01_FHQTreapWithCount1::small(left[i], num);
    } else {
      return ((size[left[i]] + count[i]) +
              Code01_FHQTreapWithCount1::small(right[i], num));
    }
  }
  static int rank(int num) {
    return (Code01_FHQTreapWithCount1::small(head, num) + 1);
  }
  static int index(int i, int x) {
    if ((size[left[i]] >= x)) {
      return Code01_FHQTreapWithCount1::index(left[i], x);
    } else if (((size[left[i]] + count[i]) < x)) {
      return Code01_FHQTreapWithCount1::index(right[i],
                                              ((x - size[left[i]]) - count[i]));
    }
    return key[i];
  }
  static int index(int x) { return Code01_FHQTreapWithCount1::index(head, x); }
  static int pre(int i, int num) {
    if ((i == 0)) {
      return std::numeric_limits<int>::min();
    }
    if ((key[i] >= num)) {
      return Code01_FHQTreapWithCount1::pre(left[i], num);
    } else {
      return jmax(key[i], Code01_FHQTreapWithCount1::pre(right[i], num));
    }
  }
  static int pre(int num) { return Code01_FHQTreapWithCount1::pre(head, num); }
  static int post(int i, int num) {
    if ((i == 0)) {
      return std::numeric_limits<int>::max();
    }
    if ((key[i] <= num)) {
      return Code01_FHQTreapWithCount1::post(right[i], num);
    } else {
      return jmin(key[i], Code01_FHQTreapWithCount1::post(left[i], num));
    }
  }
  static int post(int num) {
    return Code01_FHQTreapWithCount1::post(head, num);
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
          Code01_FHQTreapWithCount1::add(x);
        } else if ((op == 2)) {
          Code01_FHQTreapWithCount1::remove(x);
        } else if ((op == 3)) {
          out.println(Code01_FHQTreapWithCount1::rank(x));
        } else if ((op == 4)) {
          out.println(Code01_FHQTreapWithCount1::index(x));
        } else if ((op == 5)) {
          out.println(Code01_FHQTreapWithCount1::pre(x));
        } else {
          out.println(Code01_FHQTreapWithCount1::post(x));
        }
      }
    }
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code01_FHQTreapWithCount1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// FHQ-Treap，使用词频压缩，java版
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

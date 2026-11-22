// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P5621

// Source: src/class171/Code05_Cute1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code05_Cute1 {
  struct Node;
  struct Cmp1;
  struct Cmp2;
  struct Cmp3;
  struct Node {
    int a = {};
    int b = {};
    int c = {};
    int d = {};
    int i = {};
    i64 v = {};
    bool left = {};
    String toString() const { return j::str(static_cast<const void *>(this)); }
    Node(int a_, int b_, int c_, int d_, i64 v_) {
      (a = a_);
      (b = b_);
      (c = c_);
      (d = d_);
      (v = v_);
    }
  };
  struct Cmp1 {
    String toString() const { return j::str(static_cast<const void *>(this)); }
    Cmp1() {}
    int compare(Node *x, Node *y) {
      if ((x->a != y->a)) {
        return (x->a - y->a);
      }
      if ((x->b != y->b)) {
        return (x->b - y->b);
      }
      if ((x->c != y->c)) {
        return (x->c - y->c);
      }
      if ((x->d != y->d)) {
        return (x->d - y->d);
      }
      return jcompare(y->v, x->v);
    }
  };
  struct Cmp2 {
    String toString() const { return j::str(static_cast<const void *>(this)); }
    Cmp2() {}
    int compare(Node *x, Node *y) {
      if ((x->b != y->b)) {
        return (x->b - y->b);
      }
      return (x->i - y->i);
    }
  };
  struct Cmp3 {
    String toString() const { return j::str(static_cast<const void *>(this)); }
    Cmp3() {}
    int compare(Node *x, Node *y) {
      if ((x->c != y->c)) {
        return (x->c - y->c);
      }
      return (x->i - y->i);
    }
  };
  inline static Cmp1 *cmp1 = new Cmp1();
  inline static Cmp2 *cmp2 = new Cmp2();
  inline static Cmp3 *cmp3 = new Cmp3();
  inline static int MAXN = 50001;
  inline static i64 INF = static_cast<i64>((1e18 + 1));
  inline static int n = {};
  inline static int s = {};
  inline static Array<Node *> arr = make_array<Node *>(MAXN);
  inline static Array<int> sortd = make_array<int>(MAXN);
  inline static Array<Node *> tmp1 = make_array<Node *>(MAXN);
  inline static Array<Node *> tmp2 = make_array<Node *>(MAXN);
  inline static Array<i64> tree = make_array<i64>(MAXN);
  inline static Array<i64> dp = make_array<i64>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code05_Cute1() {}
  static int lowbit(int i) { return (i & (-i)); }
  static void more(int i, i64 num) {
    while ((i <= s)) {
      (tree[i] = jmax(tree[i], num));
      (i += Code05_Cute1::lowbit(i));
    }
  }
  static i64 query(int i) {
    i64 ret = (-INF);
    while ((i > 0)) {
      (ret = jmax(ret, tree[i]));
      (i -= Code05_Cute1::lowbit(i));
    }
    return ret;
  }
  static void clear(int i) {
    while ((i <= s)) {
      (tree[i] = (-INF));
      (i += Code05_Cute1::lowbit(i));
    }
  }
  static void merge(int l, int m, int r) {
    for (int i = l; (i <= r); (i++)) {
      (tmp2[i] = tmp1[i]);
    }
    j::sort(tmp2, l, (m + 1), cmp3);
    j::sort(tmp2, (m + 1), (r + 1), cmp3);
    int p1 = {};
    int p2 = {};
    for ((p1 = (l - 1)), (p2 = (m + 1)); (p2 <= r); (p2++)) {
      while ((((p1 + 1) <= m) && (tmp2[(p1 + 1)]->c <= tmp2[p2]->c))) {
        (p1++);
        if (tmp2[p1]->left) {
          Code05_Cute1::more(tmp2[p1]->d, dp[tmp2[p1]->i]);
        }
      }
      if ((!tmp2[p2]->left)) {
        (dp[tmp2[p2]->i] =
             jmax(dp[tmp2[p2]->i],
                  (Code05_Cute1::query(tmp2[p2]->d) + tmp2[p2]->v)));
      }
    }
    for (int i = l; (i <= p1); (i++)) {
      if (tmp2[i]->left) {
        Code05_Cute1::clear(tmp2[i]->d);
      }
    }
  }
  static void cdq2(int l, int r) {
    if ((l == r)) {
      return;
    }
    int mid = jdiv((l + r), 2);
    Code05_Cute1::cdq2(l, mid);
    Code05_Cute1::merge(l, mid, r);
    Code05_Cute1::cdq2((mid + 1), r);
  }
  static void cdq1(int l, int r) {
    if ((l == r)) {
      return;
    }
    int mid = jdiv((l + r), 2);
    Code05_Cute1::cdq1(l, mid);
    for (int i = l; (i <= r); (i++)) {
      (tmp1[i] = arr[i]);
      (tmp1[i]->left = (i <= mid));
    }
    j::sort(tmp1, l, (r + 1), cmp2);
    Code05_Cute1::cdq2(l, r);
    Code05_Cute1::cdq1((mid + 1), r);
  }
  static int lower(i64 num) {
    int l = 1;
    int r = s;
    int m = {};
    int ans = 1;
    while ((l <= r)) {
      (m = jdiv((l + r), 2));
      if ((sortd[m] >= num)) {
        (ans = m);
        (r = (m - 1));
      } else {
        (l = (m + 1));
      }
    }
    return ans;
  }
  static void prepare() {
    for (int i = 1; (i <= n); (i++)) {
      (sortd[i] = arr[i]->d);
    }
    j::sort(sortd, 1, (n + 1));
    (s = 1);
    for (int i = 2; (i <= n); (i++)) {
      if ((sortd[s] != sortd[i])) {
        (sortd[(++s)] = sortd[i]);
      }
    }
    for (int i = 1; (i <= n); (i++)) {
      (arr[i]->d = Code05_Cute1::lower(arr[i]->d));
    }
    j::sort(arr, 1, (n + 1), cmp1);
    int m = 1;
    for (int i = 2; (i <= n); (i++)) {
      if (((((arr[m]->a == arr[i]->a) && (arr[m]->b == arr[i]->b)) &&
            (arr[m]->c == arr[i]->c)) &&
           (arr[m]->d == arr[i]->d))) {
        if ((arr[i]->v > 0)) {
          (arr[m]->v += arr[i]->v);
        }
      } else {
        (arr[(++m)] = arr[i]);
      }
    }
    (n = m);
    for (int i = 1; (i <= n); (i++)) {
      (arr[i]->i = i);
      (dp[i] = arr[i]->v);
    }
    for (int i = 1; (i <= s); (i++)) {
      (tree[i] = (-INF));
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    {
      int i = 1;
      int a = {};
      int b = {};
      int c = {};
      int d = {};
      int v = {};
      for (; (i <= n); (i++)) {
        (a = in.nextInt());
        (b = in.nextInt());
        (c = in.nextInt());
        (d = in.nextInt());
        (v = in.nextInt());
        (arr[i] = new Node(a, b, c, d, v));
      }
    }
    Code05_Cute1::prepare();
    Code05_Cute1::cdq1(1, n);
    i64 ans = (-INF);
    for (int i = 1; (i <= n); (i++)) {
      (ans = jmax(ans, dp[i]));
    }
    out.println(ans);
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code05_Cute1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 德丽莎世界第一可爱，java版
// 一共有n个怪兽，每个怪兽有a、b、c、d四个能力值，以及打败之后的收益v
// 可以选择任意顺序打怪兽，每次打的怪兽的四种能力值都不能小于上次打的怪兽
// 打印能获得的最大收益，可能所有怪兽收益都是负数，那也需要至少打一只怪兽
// 1 <= n <= 5 * 10^4
// -10^5 <= a、b、c、d <= +10^5
// -10^9 <= v <= +10^9
// 测试链接 : https://www.luogu.com.cn/problem/P5621
// 提交以下的code，提交时请把类名改成"Main"
// java实现的逻辑一定是正确的，但是有两个测试用例超时
// 因为这道题只考虑C++能通过的时间标准，根本没考虑java的用户
// 想通过用C++实现，本节课Code05_Cute2文件就是C++的实现
// 两个版本的逻辑完全一样，C++版本可以通过所有测试
        // 根据属性b进行排序，b一样的对象，保持原始次序
        // 根据属性c进行排序，c一样的对象，保持原始次序
        // 根据b重排时，准备的辅助数组，不改变原始次序
        // 根据c重排时，准备的辅助数组，不改变原始次序
        // 树状数组，维护前缀最大值
        // dp[i]表示i号怪兽最后杀死的情况下，最大的收益
        // tmp1[l..r]中所有对象根据b属性值稳定排序了
        // 让每个原左组的对象影响到后面每个原右组对象(更新dp)
        // 读写工具类
*/

// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P4849

// Source: src/class171/Code06_Treasure1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code06_Treasure1 {
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
      return (x->d - y->d);
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
  inline static int MAXN = 80001;
  inline static i64 INF = static_cast<i64>((1e18 + 1));
  inline static int MOD = 998244353;
  inline static int n = {};
  inline static int s = {};
  inline static Array<Node *> arr = make_array<Node *>(MAXN);
  inline static Array<Node *> tmp1 = make_array<Node *>(MAXN);
  inline static Array<Node *> tmp2 = make_array<Node *>(MAXN);
  inline static Array<int> sortd = make_array<int>(MAXN);
  inline static Array<i64> treeVal = make_array<i64>(MAXN);
  inline static Array<int> treeCnt = make_array<int>(MAXN);
  inline static Array<i64> dp = make_array<i64>(MAXN);
  inline static Array<int> cnt = make_array<int>(MAXN);
  inline static i64 queryVal = {};
  inline static int queryCnt = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code06_Treasure1() {}
  static int lowbit(int i) { return (i & (-i)); }
  static void more(int i, i64 v, int c) {
    while ((i <= s)) {
      if ((v > treeVal[i])) {
        (treeVal[i] = v);
        (treeCnt[i] = jrem(c, MOD));
      } else if ((v == treeVal[i])) {
        (treeCnt[i] = jrem((treeCnt[i] + c), MOD));
      }
      (i += Code06_Treasure1::lowbit(i));
    }
  }
  static void query(int i) {
    (queryVal = (-INF));
    (queryCnt = 0);
    while ((i > 0)) {
      if ((treeVal[i] > queryVal)) {
        (queryVal = treeVal[i]);
        (queryCnt = treeCnt[i]);
      } else if ((treeVal[i] == queryVal)) {
        (queryCnt = jrem((queryCnt + treeCnt[i]), MOD));
      }
      (i -= Code06_Treasure1::lowbit(i));
    }
  }
  static void clear(int i) {
    while ((i <= s)) {
      (treeVal[i] = (-INF));
      (treeCnt[i] = 0);
      (i += Code06_Treasure1::lowbit(i));
    }
  }
  static void merge(int l, int mid, int r) {
    for (int i = l; (i <= r); (i++)) {
      (tmp2[i] = tmp1[i]);
    }
    j::sort(tmp2, l, (mid + 1), cmp3);
    j::sort(tmp2, (mid + 1), (r + 1), cmp3);
    int p1 = {};
    int p2 = {};
    int id = {};
    for ((p1 = (l - 1)), (p2 = (mid + 1)); (p2 <= r); (p2++)) {
      while ((((p1 + 1) <= mid) && (tmp2[(p1 + 1)]->c <= tmp2[p2]->c))) {
        (p1++);
        if (tmp2[p1]->left) {
          Code06_Treasure1::more(tmp2[p1]->d, dp[tmp2[p1]->i],
                                 cnt[tmp2[p1]->i]);
        }
      }
      if ((!tmp2[p2]->left)) {
        Code06_Treasure1::query(tmp2[p2]->d);
        (id = tmp2[p2]->i);
        if (((queryVal + tmp2[p2]->v) > dp[id])) {
          (dp[id] = (queryVal + tmp2[p2]->v));
          (cnt[id] = queryCnt);
        } else if (((queryVal + tmp2[p2]->v) == dp[id])) {
          (cnt[id] = jrem((cnt[id] + queryCnt), MOD));
        }
      }
    }
    for (int i = l; (i <= p1); (i++)) {
      if (tmp2[i]->left) {
        Code06_Treasure1::clear(tmp2[i]->d);
      }
    }
  }
  static void cdq2(int l, int r) {
    if ((l == r)) {
      return;
    }
    int mid = jdiv((l + r), 2);
    Code06_Treasure1::cdq2(l, mid);
    Code06_Treasure1::merge(l, mid, r);
    Code06_Treasure1::cdq2((mid + 1), r);
  }
  static void cdq1(int l, int r) {
    if ((l == r)) {
      return;
    }
    int mid = jdiv((l + r), 2);
    Code06_Treasure1::cdq1(l, mid);
    for (int i = l; (i <= r); (i++)) {
      (tmp1[i] = arr[i]);
      (tmp1[i]->left = (i <= mid));
    }
    j::sort(tmp1, l, (r + 1), cmp2);
    Code06_Treasure1::cdq2(l, r);
    Code06_Treasure1::cdq1((mid + 1), r);
  }
  static int lower(int x) {
    int l = 1;
    int r = s;
    int ans = 1;
    while ((l <= r)) {
      int mid = jdiv((l + r), 2);
      if ((sortd[mid] >= x)) {
        (ans = mid);
        (r = (mid - 1));
      } else {
        (l = (mid + 1));
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
      (arr[i]->d = Code06_Treasure1::lower(arr[i]->d));
    }
    j::sort(arr, 1, (n + 1), cmp1);
    int m = 1;
    for (int i = 2; (i <= n); (i++)) {
      if (((((arr[m]->a == arr[i]->a) && (arr[m]->b == arr[i]->b)) &&
            (arr[m]->c == arr[i]->c)) &&
           (arr[m]->d == arr[i]->d))) {
        (arr[m]->v += arr[i]->v);
      } else {
        (arr[(++m)] = arr[i]);
      }
    }
    (n = m);
    for (int i = 1; (i <= n); (i++)) {
      (arr[i]->i = i);
      (dp[i] = arr[i]->v);
      (cnt[i] = 1);
    }
    for (int i = 1; (i <= s); (i++)) {
      (treeVal[i] = (-INF));
      (treeCnt[i] = 0);
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    in.nextInt();
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
    Code06_Treasure1::prepare();
    Code06_Treasure1::cdq1(1, n);
    i64 best = 0;
    int ways = 0;
    for (int i = 1; (i <= n); (i++)) {
      (best = jmax(best, dp[i]));
    }
    for (int i = 1; (i <= n); (i++)) {
      if ((dp[i] == best)) {
        (ways = jrem((ways + cnt[i]), MOD));
      }
    }
    out.println(best);
    out.println(jrem(ways, MOD));
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code06_Treasure1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 寻找宝藏，java版
// 一共有n个宝藏，每个宝藏有a、b、c、d四个属性值，以及拿取之后的收益v
// 可以选择任意顺序拿取宝藏，每次拿的宝藏的四种属性值都不能小于上次拿的宝藏
// 打印能获得的最大收益，打印有多少种最佳拿取方法，方法数对 998244353 取余
// 1 <= n <= 8 * 10^4
// 1 <= a、b、c、d、v <= 10^9
// 测试链接 : https://www.luogu.com.cn/problem/P4849
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 根据属性b进行排序，b一样的对象，保持原始次序
        // 根据属性c进行排序，c一样的对象，保持原始次序
        // 读写工具类
*/

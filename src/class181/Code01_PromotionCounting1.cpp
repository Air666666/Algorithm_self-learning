// Source: src/class181/Code01_PromotionCounting1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_PromotionCounting1 {
  inline static int MAXN = 100001;
  inline static int MAXT = (MAXN * 40);
  inline static int n = {};
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> nxt = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> to = make_array<int>(jshl(MAXN, 1));
  inline static int cntg = {};
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static Array<int> sorted = make_array<int>(MAXN);
  inline static int cntv = {};
  inline static Array<int> root = make_array<int>(MAXN);
  inline static Array<int> ls = make_array<int>(MAXT);
  inline static Array<int> rs = make_array<int>(MAXT);
  inline static Array<int> siz = make_array<int>(MAXT);
  inline static int cntt = {};
  inline static Array<int> ans = make_array<int>(MAXN);
  inline static Array<Array<int>> ufe = make_array<int>(MAXN, 3);
  inline static int stacksize = {};
  inline static int u = {};
  inline static int f = {};
  inline static int e = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_PromotionCounting1() {}
  static void addEdge(int u, int v) {
    (nxt[(++cntg)] = head[u]);
    (to[cntg] = v);
    (head[u] = cntg);
  }
  static int kth(int num) {
    int left = 1;
    int right = cntv;
    int mid = {};
    int ret = 0;
    while ((left <= right)) {
      (mid = jshr((left + right), 1));
      if ((sorted[mid] <= num)) {
        (ret = mid);
        (left = (mid + 1));
      } else {
        (right = (mid - 1));
      }
    }
    return ret;
  }
  static void up(int i) { (siz[i] = (siz[ls[i]] + siz[rs[i]])); }
  static int add(int jobi, int l, int r, int i) {
    int rt = i;
    if ((rt == 0)) {
      (rt = (++cntt));
    }
    if ((l == r)) {
      (siz[rt]++);
    } else {
      int mid = jshr((l + r), 1);
      if ((jobi <= mid)) {
        (ls[rt] = Code01_PromotionCounting1::add(jobi, l, mid, ls[rt]));
      } else {
        (rs[rt] = Code01_PromotionCounting1::add(jobi, (mid + 1), r, rs[rt]));
      }
      Code01_PromotionCounting1::up(rt);
    }
    return rt;
  }
  static int merge(int l, int r, int t1, int t2) {
    if (((t1 == 0) || (t2 == 0))) {
      return (t1 + t2);
    }
    if ((l == r)) {
      (siz[t1] += siz[t2]);
    } else {
      int mid = jshr((l + r), 1);
      (ls[t1] = Code01_PromotionCounting1::merge(l, mid, ls[t1], ls[t2]));
      (rs[t1] = Code01_PromotionCounting1::merge((mid + 1), r, rs[t1], rs[t2]));
      Code01_PromotionCounting1::up(t1);
    }
    return t1;
  }
  static int query(int jobl, int jobr, int l, int r, int i) {
    if (((jobl > jobr) || (i == 0))) {
      return 0;
    }
    if (((jobl <= l) && (r <= jobr))) {
      return siz[i];
    }
    int mid = jshr((l + r), 1);
    int ret = 0;
    if ((jobl <= mid)) {
      (ret += Code01_PromotionCounting1::query(jobl, jobr, l, mid, ls[i]));
    }
    if ((jobr > mid)) {
      (ret +=
       Code01_PromotionCounting1::query(jobl, jobr, (mid + 1), r, rs[i]));
    }
    return ret;
  }
  static void calc1(int u, int fa) {
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      int v = to[e];
      if ((v != fa)) {
        Code01_PromotionCounting1::calc1(v, u);
        (root[u] = Code01_PromotionCounting1::merge(1, cntv, root[u], root[v]));
      }
    }
    (ans[u] = Code01_PromotionCounting1::query((arr[u] + 1), cntv, 1, cntv,
                                               root[u]));
  }
  static void push(int u, int f, int e) {
    (ufe[stacksize][0] = u);
    (ufe[stacksize][1] = f);
    (ufe[stacksize][2] = e);
    (stacksize++);
  }
  static void pop() {
    (--stacksize);
    (u = ufe[stacksize][0]);
    (f = ufe[stacksize][1]);
    (e = ufe[stacksize][2]);
  }
  static void calc2() {
    (stacksize = 0);
    Code01_PromotionCounting1::push(1, 0, (-1));
    while ((stacksize > 0)) {
      Code01_PromotionCounting1::pop();
      if ((e == (-1))) {
        (e = head[u]);
      } else {
        (e = nxt[e]);
      }
      if ((e != 0)) {
        Code01_PromotionCounting1::push(u, f, e);
        if ((to[e] != f)) {
          Code01_PromotionCounting1::push(to[e], u, (-1));
        }
      } else {
        for (int ei = head[u]; (ei > 0); (ei = nxt[ei])) {
          int v = to[ei];
          if ((v != f)) {
            (root[u] =
                 Code01_PromotionCounting1::merge(1, cntv, root[u], root[v]));
          }
        }
        (ans[u] = Code01_PromotionCounting1::query((arr[u] + 1), cntv, 1, cntv,
                                                   root[u]));
      }
    }
  }
  static void compute() {
    for (int i = 1; (i <= n); (i++)) {
      (sorted[i] = arr[i]);
    }
    j::sort(sorted, 1, (n + 1));
    (cntv = 1);
    for (int i = 2; (i <= n); (i++)) {
      if ((sorted[cntv] != sorted[i])) {
        (sorted[(++cntv)] = sorted[i]);
      }
    }
    for (int i = 1; (i <= n); (i++)) {
      (arr[i] = Code01_PromotionCounting1::kth(arr[i]));
    }
    for (int i = 1; (i <= n); (i++)) {
      (root[i] = Code01_PromotionCounting1::add(arr[i], 1, cntv, root[i]));
    }
    Code01_PromotionCounting1::calc2();
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    for (int i = 1; (i <= n); (i++)) {
      (arr[i] = in.nextInt());
    }
    {
      int i = 2;
      int fa = {};
      for (; (i <= n); (i++)) {
        (fa = in.nextInt());
        Code01_PromotionCounting1::addEdge(fa, i);
        Code01_PromotionCounting1::addEdge(i, fa);
      }
    }
    Code01_PromotionCounting1::compute();
    for (int i = 1; (i <= n); (i++)) {
      out.println(ans[i]);
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code01_PromotionCounting1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 晋升者计数，java版
// 一共有n个人，给定每个人的能力值arr[i]，所有人组成一棵树，代表公司的组织
// 1号人是整个公司的老板，从2号人开始，给定每个人的上司编号fa[i]
// 打印第i号人为头的子树中，有多少个人的能力值 > 第i号人的能力值，一共n条打印
// 1 <= n <= 10^5
// 1 <= arr[i] <= 10^9
// 测试链接 : https://www.luogu.com.cn/problem/P3605
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 递归版，java会爆栈，C++可以通过
        // 递归函数改迭代需要的栈，不会改去看讲解118
        // calc1改迭代
                // calc1(1, 0);
        // 读写工具类
*/

// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/CF601E
// https://codeforces.com/problemset/problem/601/E

// Source: src/class167/Code01_MuseumRobbery1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_MuseumRobbery1 {
  inline static int MAXN = 40001;
  inline static int MAXQ = 30001;
  inline static int MAXK = 1001;
  inline static int MAXT = 1000001;
  inline static int DEEP = 20;
  inline static int BAS = 10000019;
  inline static int MOD = 1000000007;
  inline static int n = {};
  inline static int k = {};
  inline static int q = {};
  inline static Array<int> v = make_array<int>(MAXN);
  inline static Array<int> w = make_array<int>(MAXN);
  inline static Array<int> op = make_array<int>(MAXQ);
  inline static Array<int> x = make_array<int>(MAXQ);
  inline static Array<int> y = make_array<int>(MAXQ);
  inline static Array<int> from = make_array<int>(MAXN);
  inline static Array<int> to = make_array<int>(MAXN);
  inline static Array<int> head = make_array<int>(jshl(MAXQ, 2));
  inline static Array<int> next = make_array<int>(MAXT);
  inline static Array<int> tov = make_array<int>(MAXT);
  inline static Array<int> tow = make_array<int>(MAXT);
  inline static int cnt = 0;
  inline static Array<i64> dp = make_array<i64>(MAXK);
  inline static Array<Array<i64>> backup = make_array<i64>(DEEP, MAXK);
  inline static Array<i64> ans = make_array<i64>(MAXQ);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_MuseumRobbery1() {}
  static void clone(Array<i64> a, Array<i64> b) {
    for (int i = 0; (i <= k); (i++)) {
      (a[i] = b[i]);
    }
  }
  static void addEdge(int i, int v, int w) {
    (next[(++cnt)] = head[i]);
    (tov[cnt] = v);
    (tow[cnt] = w);
    (head[i] = cnt);
  }
  static void add(int jobl, int jobr, int jobv, int jobw, int l, int r, int i) {
    if (((jobl <= l) && (r <= jobr))) {
      Code01_MuseumRobbery1::addEdge(i, jobv, jobw);
    } else {
      int mid = jshr((l + r), 1);
      if ((jobl <= mid)) {
        Code01_MuseumRobbery1::add(jobl, jobr, jobv, jobw, l, mid, jshl(i, 1));
      }
      if ((jobr > mid)) {
        Code01_MuseumRobbery1::add(jobl, jobr, jobv, jobw, (mid + 1), r,
                                   (jshl(i, 1) | 1));
      }
    }
  }
  static void dfs(int l, int r, int i, int dep) {
    Code01_MuseumRobbery1::clone(backup[dep], dp);
    for (int e = head[i]; (e > 0); (e = next[e])) {
      int v = tov[e];
      int w = tow[e];
      for (int j = k; (j >= w); (j--)) {
        (dp[j] = jmax(dp[j], (dp[(j - w)] + v)));
      }
    }
    if ((l == r)) {
      if ((op[l] == 3)) {
        i64 ret = 0;
        i64 base = 1;
        for (int j = 1; (j <= k); (j++)) {
          (ret = jrem((ret + (dp[j] * base)), MOD));
          (base = jrem((base * BAS), MOD));
        }
        (ans[l] = ret);
      }
    } else {
      int mid = jshr((l + r), 1);
      Code01_MuseumRobbery1::dfs(l, mid, jshl(i, 1), (dep + 1));
      Code01_MuseumRobbery1::dfs((mid + 1), r, (jshl(i, 1) | 1), (dep + 1));
    }
    Code01_MuseumRobbery1::clone(dp, backup[dep]);
  }
  static void prepare() {
    for (int i = 1; (i <= n); (i++)) {
      (from[i] = 1);
      (to[i] = q);
    }
    for (int i = 1; (i <= q); (i++)) {
      if ((op[i] == 1)) {
        (n++);
        (v[n] = x[i]);
        (w[n] = y[i]);
        (from[n] = i);
        (to[n] = q);
      } else if ((op[i] == 2)) {
        (to[x[i]] = (i - 1));
      }
    }
    for (int i = 1; (i <= n); (i++)) {
      if ((from[i] <= to[i])) {
        Code01_MuseumRobbery1::add(from[i], to[i], v[i], w[i], 1, q, 1);
      }
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (k = in.nextInt());
    for (int i = 1; (i <= n); (i++)) {
      (v[i] = in.nextInt());
      (w[i] = in.nextInt());
    }
    (q = in.nextInt());
    for (int i = 1; (i <= q); (i++)) {
      (op[i] = in.nextInt());
      if ((op[i] == 1)) {
        (x[i] = in.nextInt());
        (y[i] = in.nextInt());
      } else if ((op[i] == 2)) {
        (x[i] = in.nextInt());
      }
    }
    Code01_MuseumRobbery1::prepare();
    Code01_MuseumRobbery1::dfs(1, q, 1, 1);
    for (int i = 1; (i <= q); (i++)) {
      if ((op[i] == 3)) {
        out.println(ans[i]);
      }
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code01_MuseumRobbery1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 博物馆劫案，java版
// 给定n件商品，商品有价值v和重量w，1~n号商品加入集合s
// 接下来有q个操作，每种操作是如下三种类型中的一种
// 操作 1 x y : 集合s中增加价值x、重量y的商品，商品编号自增得到
// 操作 2 x   : 集合s中删除编号为x的商品，删除时保证x号商品存在
// 操作 3     : 查询当前的f(s)
// 定义a(s, m) = 集合s中，挑选商品总重量<=m，能获得的最大价值
// 给定正数k、BAS、MOD，定义f(s) = ∑(m = 1...k) (a(s, m) * BAS的m-1次方 % MOD)
// 1 <= n <= 5 * 10^3    1 <= q <= 3 * 10^4
// 1 <= k、每件商品重量 <= 10^3    1 <= 每件商品价值 <= 10^6
// 测试链接 : https://www.luogu.com.cn/problem/CF601E
// 测试链接 : https://codeforces.com/problemset/problem/601/E
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 第i号商品的生效时间段，从from[i]持续到to[i]
        // 时间轴线段树的区间上挂上生效的商品，价值v，重量w
        // 动态规划表
        // 动态规划表的备份
        // 答案
        // 读写工具类
*/

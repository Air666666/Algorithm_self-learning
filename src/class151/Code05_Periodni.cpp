// Source: src/class151/Code05_Periodni.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code05_Periodni {
  inline static int MOD = 1000000007;
  inline static int MAXN = 501;
  inline static int MAXH = 1000000;
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static Array<int> fac = make_array<int>((MAXH + 1));
  inline static Array<int> inv = make_array<int>((MAXH + 1));
  inline static Array<int> left = make_array<int>(MAXN);
  inline static Array<int> right = make_array<int>(MAXN);
  inline static Array<int> stack = make_array<int>(MAXN);
  inline static Array<int> size = make_array<int>(MAXN);
  inline static Array<Array<int>> dp = make_array<int>(MAXN, MAXN);
  inline static Array<int> tmp = make_array<int>(MAXN);
  inline static int n = {};
  inline static int k = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code05_Periodni() {}
  static int power(i64 x, i64 p) {
    i64 ans = 1;
    while ((p > 0)) {
      if (((p & 1) == 1)) {
        (ans = jrem((ans * x), MOD));
      }
      (x = jrem((x * x), MOD));
      (p = jshr(p, 1));
    }
    return static_cast<int>(ans);
  }
  static int c(int n, int k) {
    return ((n < k) ? 0
                    : static_cast<int>(
                          jrem((jrem((static_cast<i64>(fac[n]) * inv[k]), MOD) *
                                inv[(n - k)]),
                               MOD)));
  }
  static void build() {
    (fac[0] = (fac[1] = (inv[0] = 1)));
    for (int i = 2; (i <= MAXH); (i++)) {
      (fac[i] =
           static_cast<int>(jrem((static_cast<i64>(fac[(i - 1)]) * i), MOD)));
    }
    (inv[MAXH] = Code05_Periodni::power(fac[MAXH], (MOD - 2)));
    for (int i = (MAXH - 1); (i >= 1); (i--)) {
      (inv[i] = static_cast<int>(
           jrem((static_cast<i64>(inv[(i + 1)]) * (i + 1)), MOD)));
    }
    {
      int i = 1;
      int top = 0;
      int pos = {};
      for (; (i <= n); (i++)) {
        (pos = top);
        while (((pos > 0) && (arr[stack[pos]] > arr[i]))) {
          (pos--);
        }
        if ((pos > 0)) {
          (right[stack[pos]] = i);
        }
        if ((pos < top)) {
          (left[i] = stack[(pos + 1)]);
        }
        (stack[(++pos)] = i);
        (top = pos);
      }
    }
  }
  static void dfs(int u, int fa) {
    if ((u == 0)) {
      return;
    }
    Code05_Periodni::dfs(left[u], u);
    Code05_Periodni::dfs(right[u], u);
    (size[u] = ((size[left[u]] + size[right[u]]) + 1));
    j::fill(tmp, 0, (k + 1), 0);
    for (int l = 0; (l <= jmin(size[left[u]], k)); (l++)) {
      for (int r = 0; (r <= jmin(size[right[u]], (k - l))); (r++)) {
        (tmp[(l + r)] =
             jrem(static_cast<int>((
                      tmp[(l + r)] +
                      jrem((static_cast<i64>(dp[left[u]][l]) * dp[right[u]][r]),
                           MOD))),
                  MOD));
      }
    }
    for (int i = 0; (i <= jmin(size[u], k)); (i++)) {
      for (int p = 0; (p <= i); (p++)) {
        (dp[u][i] = jrem(
             static_cast<int>(
                 (dp[u][i] + jrem((jrem((jrem(
                                             [&]() {
                                               auto jleft = static_cast<i64>(
                                                   Code05_Periodni::c(
                                                       (size[u] - p), (i - p)));
                                               auto jright = Code05_Periodni::c(
                                                   (arr[u] - arr[fa]), (i - p));
                                               return (jleft * jright);
                                             }(),
                                             MOD) *
                                         fac[(i - p)]),
                                        MOD) *
                                   tmp[p]),
                                  MOD))),
             MOD));
      }
    }
  }
  static int compute() {
    Code05_Periodni::build();
    (dp[0][0] = 1);
    Code05_Periodni::dfs(stack[1], 0);
    return dp[stack[1]][k];
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    (n = static_cast<int>(in.nval));
    in.nextToken();
    (k = static_cast<int>(in.nval));
    for (int i = 1; (i <= n); (i++)) {
      in.nextToken();
      (arr[i] = static_cast<int>(in.nval));
    }
    out.println(Code05_Periodni::compute());
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code05_Periodni::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 表格填数
// 给定一个长度为n的数组arr，arr[i]表示i位置上方的正方形格子数量
// 那么从1位置到n位置，每个位置就是一个直方图，所有的直方图紧靠在一起
// 在这片区域中，你要放入k个相同数字，不能有任意两个数字在同一行或者同一列
//
注意在这片区域中，如果某一行中间断开了，使得两个数字无法在这一行连通，则不算违规
// 返回填入数字的方法数，答案对 1000000007 取模
// 1 <= n、k <= 500    0 <= arr[i] <= 10^6
// 测试链接 : https://www.luogu.com.cn/problem/P6453
// 因为本题给定的可用空间很少，所以数组为int类型，不用long类型
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 所有数字
        // 阶乘余数表
        // 阶乘逆元表
        // 笛卡尔树需要
        // dfs需要
        // dp是动态规划表
        // tmp是动态规划的临时结果
                // 所有dfs过程都算上，这一部分的总复杂度O(n^2)
                // 所有dfs过程都算上，这一部分的总复杂度O(min(n的3次方, n *
k平方))
*/

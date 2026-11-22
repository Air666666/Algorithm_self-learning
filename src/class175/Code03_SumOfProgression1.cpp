// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/CF1921F
// https://codeforces.com/problemset/problem/1921/F

// Source: src/class175/Code03_SumOfProgression1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_SumOfProgression1 {
  inline static int MAXN = 100001;
  inline static int MAXB = 401;
  inline static int t = {};
  inline static int n = {};
  inline static int q = {};
  inline static int blen = {};
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static Array<Array<i64>> f = make_array<i64>(MAXB, MAXN);
  inline static Array<Array<i64>> g = make_array<i64>(MAXB, MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_SumOfProgression1() {}
  static i64 query(int s, int d, int k) {
    i64 ans = 0;
    if ((d <= blen)) {
      (ans = g[d][s]);
      if (((s + (d * k)) <= n)) {
        (ans = ((ans - g[d][(s + (d * k))]) - (f[d][(s + (d * k))] * k)));
      }
    } else {
      for (int i = 1; (i <= k); (i++)) {
        (ans += ((1LL * arr[(s + ((i - 1) * d))]) * i));
      }
    }
    return ans;
  }
  static void prepare() {
    (blen = static_cast<int>(std::sqrt(n)));
    for (int d = 1; (d <= blen); (d++)) {
      for (int i = n; (i >= 1); (i--)) {
        (f[d][i] = (arr[i] + (((i + d) > n) ? 0 : f[d][(i + d)])));
      }
    }
    for (int d = 1; (d <= blen); (d++)) {
      for (int i = n; (i >= 1); (i--)) {
        (g[d][i] = (f[d][i] + (((i + d) > n) ? 0 : g[d][(i + d)])));
      }
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (t = in.nextInt());
    for (int c = 1; (c <= t); (c++)) {
      (n = in.nextInt());
      (q = in.nextInt());
      for (int i = 1; (i <= n); (i++)) {
        (arr[i] = in.nextInt());
      }
      Code03_SumOfProgression1::prepare();
      {
        int i = 1;
        int s = {};
        int d = {};
        int k = {};
        for (; (i <= q); (i++)) {
          (s = in.nextInt());
          (d = in.nextInt());
          (k = in.nextInt());
          out.println(Code03_SumOfProgression1::query(s, d, k));
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
  Code03_SumOfProgression1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 等差数列求和，java版
// 一共有t组测试，每组测试遵循同样的设定
// 给定一个长度为n的数组arr，接下来有q条查询，查询格式如下
// 查询 s d k : arr[s]作为第1项、arr[s + 1d]作为第2项、arr[s + 2d]作为第3项...
//             每项的值 * 项的编号，一共k项都累加起来，打印累加和
// 1 <= n <= 10^5
// 1 <= q <= 2 * 10^5
// 测试链接 : https://www.luogu.com.cn/problem/CF1921F
// 测试链接 : https://codeforces.com/problemset/problem/1921/F
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 读写工具类
*/

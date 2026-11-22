// Source: src/class125/Code02_PavingTile2.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_PavingTile2 {
  inline static int MAXN = 11;
  inline static Array<Array<i64>> dp =
      make_array<i64>((MAXN + 1), jshl(1, MAXN));
  inline static Array<i64> prepare = make_array<i64>(jshl(1, MAXN));
  inline static int n = {};
  inline static int m = {};
  inline static int maxs = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_PavingTile2() {}
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    while ((in.nextToken() != -1)) {
      (n = static_cast<int>(in.nval));
      in.nextToken();
      (m = static_cast<int>(in.nval));
      (maxs = jshl(1, m));
      if (((n != 0) || (m != 0))) {
        out.println(Code02_PavingTile2::compute());
      }
    }
    out.flush();
    out.close();
    br.close();
  }
  static i64 compute() {
    j::fill(prepare, 0, maxs, 1);
    for (int i = (n - 1); (i >= 0); (i--)) {
      for (int s = 0; (s < maxs); (s++)) {
        (dp[m][s] = prepare[s]);
      }
      for (int j = (m - 1); (j >= 0); (j--)) {
        for (int s = 0; (s < maxs); (s++)) {
          i64 ans = 0;
          if ((Code02_PavingTile2::get(s, j) == 1)) {
            (ans = dp[(j + 1)][Code02_PavingTile2::set(s, j, 0)]);
          } else {
            if (((i + 1) < n)) {
              (ans = dp[(j + 1)][Code02_PavingTile2::set(s, j, 1)]);
            }
            if ((((j + 1) < m) && (Code02_PavingTile2::get(s, (j + 1)) == 0))) {
              (ans += dp[(j + 2)][s]);
            }
          }
          (dp[j][s] = ans);
        }
      }
      for (int s = 0; (s < maxs); (s++)) {
        (prepare[s] = dp[0][s]);
      }
    }
    return dp[0][0];
  }
  static int get(int s, int j) { return (jshr(s, j) & 1); }
  static int set(int s, int j, int v) {
    return ((v == 0) ? (s & (~jshl(1, j))) : (s | jshl(1, j)));
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code02_PavingTile2::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 贴瓷砖的方法数(轮廓线dp+空间压缩)
// 给定两个参数n和m，表示n行m列的空白区域
// 有无限多的1*2规格的瓷砖，目标是严丝合缝的铺满所有的空白区域
// 返回有多少种铺满的方法
// 1 <= n, m <= 11
// 测试链接 : http://poj.org/problem?id=2411
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有用例
                        // j == m
                        // 普通位置
                        // 设置prepare
*/

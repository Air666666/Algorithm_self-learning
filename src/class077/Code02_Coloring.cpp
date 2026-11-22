// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P4170
// https://leetcode.cn/problems/strange-printer/

// Source: src/class077/Code02_Coloring.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_Coloring {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_Coloring() {}
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    IO out = IO(IO(jout));
    String str = br.readLine();
    out.println(Code02_Coloring::strangePrinter(str));
    out.flush();
    out.close();
    br.close();
  }
  static int strangePrinter(String str) {
    Array<jchar> s = str.toCharArray();
    int n = s.length;
    Array<Array<int>> dp = make_array<int>(n, n);
    (dp[(n - 1)][(n - 1)] = 1);
    for (int i = 0; (i < (n - 1)); (i++)) {
      (dp[i][i] = 1);
      (dp[i][(i + 1)] = ((s[i] == s[(i + 1)]) ? 1 : 2));
    }
    {
      int l = (n - 3);
      int ans = {};
      for (; (l >= 0); (l--)) {
        for (int r = (l + 2); (r < n); (r++)) {
          if ((s[l] == s[r])) {
            (dp[l][r] = dp[l][(r - 1)]);
          } else {
            (ans = std::numeric_limits<int>::max());
            for (int m = l; (m < r); (m++)) {
              (ans = jmin(ans, (dp[l][m] + dp[(m + 1)][r])));
            }
            (dp[l][r] = ans);
          }
        }
      }
    }
    return dp[0][(n - 1)];
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code02_Coloring::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 涂色 & 奇怪打印机
// 假设你有一条长度为5的木板，初始时没有涂过任何颜色
// 你希望把它的5个单位长度分别涂上红、绿、蓝、绿、红
// 用一个长度为5的字符串表示这个目标：RGBGR
// 每次你可以把一段连续的木板涂成一个给定的颜色，后涂的颜色覆盖先涂的颜色
// 例如第一次把木板涂成RRRRR
// 第二次涂成RGGGR
// 第三次涂成RGBGR，达到目标
// 返回尽量少的涂色次数
// 测试链接 : https://www.luogu.com.cn/problem/P4170
// 测试链接 : https://leetcode.cn/problems/strange-printer/
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下的code，提交时请把类名改成"Main"，可以直接通过
        // 时间复杂度O(n^3)
        // 测试链接 : https://leetcode.cn/problems/strange-printer/
                                // dp[l][r]
                                        // dp[l][r] = dp[l + 1][r];
*/

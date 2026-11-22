// Source: src/class077/Code03_HeightAndChoir.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_HeightAndChoir {
  inline static int MAXN = 1001;
  inline static Array<int> nums = make_array<int>(MAXN);
  inline static Array<Array<int>> dp = make_array<int>(MAXN, 2);
  inline static int n = {};
  inline static int MOD = 19650827;
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_HeightAndChoir() {}
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    while ((in.nextToken() != -1)) {
      (n = static_cast<int>(in.nval));
      for (int i = 1; (i <= n); (i++)) {
        in.nextToken();
        (nums[i] = static_cast<int>(in.nval));
      }
      if ((n == 1)) {
        out.println(1);
      } else {
        out.println(Code03_HeightAndChoir::compute2());
      }
    }
    out.flush();
    out.close();
    br.close();
  }
  static int compute1() {
    Array<Array<Array<int>>> dp = make_array<int>((n + 1), (n + 1), 2);
    for (int i = 1; (i < n); (i++)) {
      if ((nums[i] < nums[(i + 1)])) {
        (dp[i][(i + 1)][0] = 1);
        (dp[i][(i + 1)][1] = 1);
      }
    }
    for (int l = (n - 2); (l >= 1); (l--)) {
      for (int r = (l + 2); (r <= n); (r++)) {
        if ((nums[l] < nums[(l + 1)])) {
          (dp[l][r][0] = jrem((dp[l][r][0] + dp[(l + 1)][r][0]), MOD));
        }
        if ((nums[l] < nums[r])) {
          (dp[l][r][0] = jrem((dp[l][r][0] + dp[(l + 1)][r][1]), MOD));
        }
        if ((nums[r] > nums[l])) {
          (dp[l][r][1] = jrem((dp[l][r][1] + dp[l][(r - 1)][0]), MOD));
        }
        if ((nums[r] > nums[(r - 1)])) {
          (dp[l][r][1] = jrem((dp[l][r][1] + dp[l][(r - 1)][1]), MOD));
        }
      }
    }
    return jrem((dp[1][n][0] + dp[1][n][1]), MOD);
  }
  static int compute2() {
    if ((nums[(n - 1)] < nums[n])) {
      (dp[n][0] = 1);
      (dp[n][1] = 1);
    }
    for (int l = (n - 2); (l >= 1); (l--)) {
      if ((nums[l] < nums[(l + 1)])) {
        (dp[(l + 1)][0] = 1);
        (dp[(l + 1)][1] = 1);
      } else {
        (dp[(l + 1)][0] = 0);
        (dp[(l + 1)][1] = 0);
      }
      for (int r = (l + 2); (r <= n); (r++)) {
        int a = 0;
        int b = 0;
        if ((nums[l] < nums[(l + 1)])) {
          (a = jrem((a + dp[r][0]), MOD));
        }
        if ((nums[l] < nums[r])) {
          (a = jrem((a + dp[r][1]), MOD));
        }
        if ((nums[r] > nums[l])) {
          (b = jrem((b + dp[(r - 1)][0]), MOD));
        }
        if ((nums[r] > nums[(r - 1)])) {
          (b = jrem((b + dp[(r - 1)][1]), MOD));
        }
        (dp[r][0] = a);
        (dp[r][1] = b);
      }
    }
    return jrem((dp[n][0] + dp[n][1]), MOD);
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code03_HeightAndChoir::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 合唱队
// 具体描述情打开链接查看
// 测试链接 : https://www.luogu.com.cn/problem/P3205
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下的所有代码，并把主类名改成"Main"，可以直接通过
        // 时间复杂度O(n^2)
        // 严格位置依赖的动态规划
                // 人的编号范围 : 1...n
                // dp[l][r][0] :
形成l...r的状况的方法数，同时要求l位置的数字是最后出现的
                // dp[l][r][1] :
形成l...r的状况的方法数，同时要求r位置的数字是最后出现的
        // 时间复杂度O(n^2)
        // 空间压缩
*/

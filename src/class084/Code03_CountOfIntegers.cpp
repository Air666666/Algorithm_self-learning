// Source: src/class084/Code03_CountOfIntegers.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_CountOfIntegers {
  inline static int MOD = 1000000007;
  inline static int MAXN = 23;
  inline static int MAXM = 401;
  inline static Array<Array<Array<int>>> dp = make_array<int>(MAXN, MAXM, 2);
  inline static Array<jchar> num = {};
  inline static int min = {};
  inline static int max = {};
  inline static int len = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_CountOfIntegers() {}
  static void build() {
    for (int i = 0; (i < len); (i++)) {
      for (int j = 0; (j <= max); (j++)) {
        (dp[i][j][0] = (-1));
        (dp[i][j][1] = (-1));
      }
    }
  }
  static int count(String num1, String num2, int min_sum, int max_sum) {
    (min = min_sum);
    (max = max_sum);
    (num = num2.toCharArray());
    (len = num2.length());
    Code03_CountOfIntegers::build();
    int ans = Code03_CountOfIntegers::f(0, 0, 0);
    (num = num1.toCharArray());
    (len = num1.length());
    Code03_CountOfIntegers::build();
    (ans = jrem(((ans - Code03_CountOfIntegers::f(0, 0, 0)) + MOD), MOD));
    if (Code03_CountOfIntegers::check()) {
      (ans = jrem((ans + 1), MOD));
    }
    return ans;
  }
  static int f(int i, int sum, int free) {
    if ((sum > max)) {
      return 0;
    }
    if (((sum + ((len - i) * 9)) < min)) {
      return 0;
    }
    if ((i == len)) {
      return 1;
    }
    if ((dp[i][sum][free] != (-1))) {
      return dp[i][sum][free];
    }
    int cur = (num[i] - u'0');
    int ans = 0;
    if ((free == 0)) {
      for (int pick = 0; (pick < cur); (pick++)) {
        (ans = jrem((ans + Code03_CountOfIntegers::f((i + 1), (sum + pick), 1)),
                    MOD));
      }
      (ans = jrem((ans + Code03_CountOfIntegers::f((i + 1), (sum + cur), 0)),
                  MOD));
    } else {
      for (int pick = 0; (pick <= 9); (pick++)) {
        (ans = jrem((ans + Code03_CountOfIntegers::f((i + 1), (sum + pick), 1)),
                    MOD));
      }
    }
    (dp[i][sum][free] = ans);
    return ans;
  }
  static bool check() {
    int sum = 0;
    for (jchar cha : num) {
      (sum += (cha - u'0'));
    }
    return ((sum >= min) && (sum <= max));
  }
};

/* Original teaching comments:
// 统计整数数目
// 给你两个数字字符串 num1 和 num2 ，以及两个整数max_sum和min_sum
// 如果一个整数 x 满足以下条件，我们称它是一个好整数
// num1 <= x <= num2
// min_sum <= digit_sum(x) <= max_sum
// 请你返回好整数的数目
// 答案可能很大，答案对 1000000007 取模
// 注意，digit_sum(x)表示x各位数字之和
// 测试链接 : https://leetcode.cn/problems/count-of-integers/
        // 注意：
        // 数字，char[] num
        // 数字长度，int len
        // 累加和最小要求，int min
        // 累加和最大要求，int max
        // 这四个变量都是全局静态变量，所以不用带参数，直接访问即可
        // 递归含义：
        // 从num的高位出发，当前来到i位上
        // 之前决定的数字累加和是sum
        // 之前的决定已经比num小，后续可以自由选择数字，那么free == 1
        // 之前的决定和num一样，后续不可以自由选择数字，那么free == 0
        // 返回有多少种可能性
                // cur : num当前位的数字
                        // 还不能自由选择
                        // 可以自由选择
*/

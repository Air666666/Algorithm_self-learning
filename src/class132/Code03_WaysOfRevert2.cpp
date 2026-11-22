// 原题测试 / 参考链接（保留上游原始地址）
// https://www.nowcoder.com/practice/49c5284278974cbda474ec13d8bd86a9

// Source: src/class132/Code03_WaysOfRevert2.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_WaysOfRevert2 {
  inline static int MOD = 998244353;
  inline static int MAXN = 10000;
  inline static Array<int> arr = make_array<int>((MAXN + 1));
  inline static int n = {};
  inline static int m = 200;
  inline static Array<Array<int>> memo = make_array<int>((m + 1), 2);
  inline static Array<Array<int>> dp = make_array<int>((m + 1), 2);
  inline static Array<int> suf0 = make_array<int>((m + 1));
  inline static Array<int> pre1 = make_array<int>((m + 1));
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_WaysOfRevert2() {}
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    while ((in.nextToken() != -1)) {
      (n = static_cast<int>(in.nval));
      for (int i = 1; (i <= n); (i++)) {
        in.nextToken();
        (arr[i] = static_cast<int>(in.nval));
      }
      out.println(Code03_WaysOfRevert2::compute());
    }
    out.flush();
    out.close();
    br.close();
  }
  static int compute() {
    for (int v = 0; (v <= m); (v++)) {
      (memo[v][0] = 0);
      (memo[v][1] = 1);
    }
    for (int i = 1; (i <= n); (i++)) {
      Code03_WaysOfRevert2::prepare();
      for (int v = 0; (v <= m); (v++)) {
        for (int s = 0; (s <= 1); (s++)) {
          int ans = 0;
          if ((arr[i] != 0)) {
            if (((arr[i] >= v) || (s == 1))) {
              (ans = memo[arr[i]][((arr[i] > v) ? 0 : 1)]);
            }
          } else {
            if (((v + 1) <= m)) {
              (ans = jrem((ans + suf0[(v + 1)]), MOD));
            }
            if ((v != 0)) {
              (ans = jrem((ans + memo[v][1]), MOD));
            }
            if ((s == 1)) {
              if (((v - 1) >= 0)) {
                (ans = jrem((ans + pre1[(v - 1)]), MOD));
              }
            }
          }
          (dp[v][s] = ans);
        }
      }
      Array<Array<int>> tmp = memo;
      (memo = dp);
      (dp = tmp);
    }
    return memo[0][1];
  }
  static void prepare() {
    (suf0[m] = memo[m][0]);
    for (int v = (m - 1); (v >= 0); (v--)) {
      (suf0[v] = jrem((suf0[(v + 1)] + memo[v][0]), MOD));
    }
    (pre1[1] = memo[1][1]);
    for (int v = 2; (v <= m); (v++)) {
      (pre1[v] = jrem((pre1[(v - 1)] + memo[v][1]), MOD));
    }
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code03_WaysOfRevert2::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 还原数组的方法数(优化枚举)
// 原本有一个长度为n的数组arr，下标从1开始，数组中都是<=200的正数
// 并且任意i位置的数字都满足 : arr[i] <= max(arr[i-1], arr[i+1])
// 特别的，arr[1] <= arr[2]，arr[n] <= arr[n-1]
// 但是输入的arr中有些数字丢失了，丢失的数字用0表示
// 返回还原成不违规的arr有多少种方法，答案对 998244353 取模
// 3 <= n <= 10^4
// 测试链接 : https://www.nowcoder.com/practice/49c5284278974cbda474ec13d8bd86a9
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 正式方法
        // 优化枚举 + 空间压缩
        // 时间复杂度O(n * m)，可以通过所有测试用例
        // 预处理结构优化枚举
*/

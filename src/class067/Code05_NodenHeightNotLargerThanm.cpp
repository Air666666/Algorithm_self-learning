// 原题测试 / 参考链接（保留上游原始地址）
// https://www.nowcoder.com/practice/aaefe5896cce4204b276e213e725f3ea

// Source: src/class067/Code05_NodenHeightNotLargerThanm.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code05_NodenHeightNotLargerThanm {
  inline static int MAXN = 51;
  inline static int MOD = 1000000007;
  inline static Array<Array<i64>> dp1 = make_array<i64>(MAXN, MAXN);
  inline static Array<Array<i64>> dp2 = make_array<i64>(MAXN, MAXN);
  inline static Array<i64> dp3 = make_array<i64>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code05_NodenHeightNotLargerThanm() {}
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    while ((in.nextToken() != -1)) {
      int n = static_cast<int>(in.nval);
      in.nextToken();
      int m = static_cast<int>(in.nval);
      out.println(Code05_NodenHeightNotLargerThanm::compute3(n, m));
    }
    out.flush();
    out.close();
    br.close();
  }
  static int compute1(int n, int m) {
    if ((n == 0)) {
      return 1;
    }
    if ((m == 0)) {
      return 0;
    }
    if ((dp1[n][m] != (-1))) {
      return static_cast<int>(dp1[n][m]);
    }
    i64 ans = 0;
    for (int k = 0; (k < n); (k++)) {
      (ans = jrem((ans + jrem(
                             [&]() {
                               auto jleft = static_cast<i64>(
                                   Code05_NodenHeightNotLargerThanm::compute1(
                                       k, (m - 1)));
                               auto jright =
                                   Code05_NodenHeightNotLargerThanm::compute1(
                                       ((n - k) - 1), (m - 1));
                               return (jleft * jright);
                             }(),
                             MOD)),
                  MOD));
    }
    (dp1[n][m] = ans);
    return static_cast<int>(ans);
  }
  static int compute2(int n, int m) {
    for (int j = 0; (j <= m); (j++)) {
      (dp2[0][j] = 1);
    }
    for (int i = 1; (i <= n); (i++)) {
      for (int j = 1; (j <= m); (j++)) {
        (dp2[i][j] = 0);
        for (int k = 0; (k < i); (k++)) {
          (dp2[i][j] = jrem(
               (dp2[i][j] +
                jrem((dp2[k][(j - 1)] * dp2[((i - k) - 1)][(j - 1)]), MOD)),
               MOD));
        }
      }
    }
    return static_cast<int>(dp2[n][m]);
  }
  static int compute3(int n, int m) {
    (dp3[0] = 1);
    for (int i = 1; (i <= n); (i++)) {
      (dp3[i] = 0);
    }
    for (int j = 1; (j <= m); (j++)) {
      for (int i = n; (i >= 1); (i--)) {
        (dp3[i] = 0);
        for (int k = 0; (k < i); (k++)) {
          (dp3[i] =
               jrem((dp3[i] + jrem((dp3[k] * dp3[((i - k) - 1)]), MOD)), MOD));
        }
      }
    }
    return static_cast<int>(dp3[n]);
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code05_NodenHeightNotLargerThanm::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 节点数为n高度不大于m的二叉树个数
// 现在有n个节点，计算出有多少个不同结构的二叉树
// 满足节点个数为n且树的高度不超过m的方案
// 因为答案很大，所以答案需要模上1000000007后输出
// 测试链接 : https://www.nowcoder.com/practice/aaefe5896cce4204b276e213e725f3ea
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下所有代码，把主类名改成Main，可以直接通过
        // 记忆化搜索
        // 二叉树节点数为n
        // 高度不能超过m
        // 结构数返回
        // 记忆化搜索
                // n > 0
                // n个点，头占掉1个
                        // 一共n个节点，头节点已经占用了1个名额
                        // 如果左树占用k个，那么右树就占用i-k-1个
        // 严格位置依赖的动态规划
                                        // 一共i个节点，头节点已经占用了1个名额
                                        //
如果左树占用k个，那么右树就占用i-k-1个
        // 空间压缩
                        // 根据依赖，一定要先枚举列
                                // 再枚举行，而且i不需要到达0，i>=1即可
                                        // 枚举
*/

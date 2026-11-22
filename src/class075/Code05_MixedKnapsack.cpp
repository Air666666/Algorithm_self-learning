// Source: src/class075/Code05_MixedKnapsack.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code05_MixedKnapsack {
  inline static int MAXN = 101;
  inline static int MAXM = 100001;
  inline static Array<int> val = make_array<int>(MAXN);
  inline static Array<int> cnt = make_array<int>(MAXN);
  inline static Array<bool> dp = make_array<bool>(MAXM);
  inline static int n = {};
  inline static int m = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code05_MixedKnapsack() {}
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    while ((in.nextToken() != -1)) {
      (n = static_cast<int>(in.nval));
      in.nextToken();
      (m = static_cast<int>(in.nval));
      if (((n != 0) || (m != 0))) {
        for (int i = 1; (i <= n); (i++)) {
          in.nextToken();
          (val[i] = static_cast<int>(in.nval));
        }
        for (int i = 1; (i <= n); (i++)) {
          in.nextToken();
          (cnt[i] = static_cast<int>(in.nval));
        }
        out.println(Code05_MixedKnapsack::compute());
      }
    }
    out.flush();
    out.close();
    br.close();
  }
  static int compute() {
    j::fill(dp, 1, (m + 1), false);
    (dp[0] = true);
    for (int i = 1; (i <= n); (i++)) {
      if ((cnt[i] == 1)) {
        for (int j = m; (j >= val[i]); (j--)) {
          if (dp[(j - val[i])]) {
            (dp[j] = true);
          }
        }
      } else if (((val[i] * cnt[i]) > m)) {
        for (int j = val[i]; (j <= m); (j++)) {
          if (dp[(j - val[i])]) {
            (dp[j] = true);
          }
        }
      } else {
        for (int mod = 0; (mod < val[i]); (mod++)) {
          int trueCnt = 0;
          {
            int j = (m - mod);
            int size = 0;
            for (; ((j >= 0) && (size <= cnt[i])); (j -= val[i]), (size++)) {
              (trueCnt += (dp[j] ? 1 : 0));
            }
          }
          {
            int j = (m - mod);
            int l = (j - (val[i] * (cnt[i] + 1)));
            for (; (j >= 1); (j -= val[i]), (l -= val[i])) {
              if (dp[j]) {
                (trueCnt--);
              } else {
                if ((trueCnt != 0)) {
                  (dp[j] = true);
                }
              }
              if ((l >= 0)) {
                (trueCnt += (dp[l] ? 1 : 0));
              }
            }
          }
        }
      }
    }
    int ans = 0;
    for (int i = 1; (i <= m); (i++)) {
      if (dp[i]) {
        (ans++);
      }
    }
    return ans;
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code05_MixedKnapsack::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 混合背包 + 多重背包普通窗口优化
// 能成功找零的钱数种类
// 每一种货币都给定面值val[i]，和拥有的数量cnt[i]
// 想知道目前拥有的货币，在钱数为1、2、3...m时
// 能找零成功的钱数有多少
// 也就是说当钱数的范围是1~m
// 返回这个范围上有多少可以找零成功的钱数
// 比如只有3元的货币，数量是5张
// m = 10
// 那么在1~10范围上，只有钱数是3、6、9时，可以成功找零
// 所以返回3表示有3种钱数可以找零成功
// 测试链接 : http://poj.org/problem?id=1742
// 测试链接 : https://www.luogu.com.cn/problem/P10973
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下的code，提交时请把类名改成"Main"，可以直接通过
        // 直接提供空间压缩版
                                // 01背包的空间压缩实现是从右往左更新的
                                // 完全背包的空间压缩实现是从左往右更新的
                                // 多重背包的空间压缩实现
                                // 每一组都是从右往左更新的
                                // 同余分组
*/

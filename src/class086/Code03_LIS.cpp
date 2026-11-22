// Source: src/class086/Code03_LIS.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_LIS {
  inline static int MAXN = 100001;
  inline static Array<int> nums = make_array<int>(MAXN);
  inline static Array<int> dp = make_array<int>(MAXN);
  inline static Array<int> ends = make_array<int>(MAXN);
  inline static Array<int> ans = make_array<int>(MAXN);
  inline static int n = {};
  inline static int k = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_LIS() {}
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    while ((in.nextToken() != -1)) {
      (n = static_cast<int>(in.nval));
      for (int i = 0; (i < n); (i++)) {
        in.nextToken();
        (nums[i] = static_cast<int>(in.nval));
      }
      Code03_LIS::lis();
      for (int i = 0; (i < (k - 1)); (i++)) {
        out.print((ans[i] + String(u" ")));
      }
      out.println(ans[(k - 1)]);
    }
    out.flush();
    out.close();
    br.close();
  }
  static void lis() {
    (k = Code03_LIS::dp_method());
    j::fill(ans, 0, k, std::numeric_limits<int>::max());
    for (int i = 0; (i < n); (i++)) {
      if ((dp[i] == k)) {
        (ans[0] = nums[i]);
      } else {
        if ((ans[((k - dp[i]) - 1)] < nums[i])) {
          (ans[(k - dp[i])] = nums[i]);
        }
      }
    }
  }
  static int dp_method() {
    int len = 0;
    {
      int i = (n - 1);
      int find = {};
      for (; (i >= 0); (i--)) {
        (find = Code03_LIS::bs(len, nums[i]));
        if ((find == (-1))) {
          (ends[(len++)] = nums[i]);
          (dp[i] = len);
        } else {
          (ends[find] = nums[i]);
          (dp[i] = (find + 1));
        }
      }
    }
    return len;
  }
  static int bs(int len, int num) {
    int l = 0;
    int r = (len - 1);
    int m = {};
    int ans = (-1);
    while ((l <= r)) {
      (m = jdiv((l + r), 2));
      if ((ends[m] <= num)) {
        (ans = m);
        (r = (m - 1));
      } else {
        (l = (m + 1));
      }
    }
    return ans;
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code03_LIS::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 最长递增子序列字典序最小的结果
// 给定数组arr，设长度为n
// 输出arr的最长递增子序列
// 如果有多个答案，请输出其中字典序最小的
// 注意这道题的字典序设定（根据提交的结果推论的）：
// 每个数字看作是单独的字符，比如120认为比36的字典序大
// 保证从左到右每个数字尽量小
// 测试链接 : https://www.nowcoder.com/practice/30fb9b3cab9742ecae9acda1c75bf927
// 测试链接 : https://www.luogu.com.cn/problem/T386911
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下的code，提交时请把类名改成"Main"，可以直接通过
// 讲解072 - 最长递增子序列及其扩展
        // nums[...]
                                // 注意这里
                                // 为什么不用判断直接设置
                                // 有讲究，课上重点讲了
                                        // 注意这里
                                        //
为什么只需要判断比前一位(ans[k-dp[i]-1])大即可
                                        // 有讲究，课上重点讲了
        // dp[i] : 必须以i位置的数字开头的情况下，最长递增子序列长度
        // 填好dp表 + 返回最长递增子序列长度
        // ends[有效区]从大到小的
        // 二分的方式找<=num的最左位置
*/

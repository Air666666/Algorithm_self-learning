// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P1809

// Source: src/class093/Code04_CrossRiver.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_CrossRiver {
  inline static int MAXN = 100001;
  inline static Array<int> nums = make_array<int>(MAXN);
  inline static Array<int> dp = make_array<int>(MAXN);
  inline static int n = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_CrossRiver() {}
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
      out.println(Code04_CrossRiver::minCost());
    }
    out.flush();
    out.close();
    br.close();
  }
  static int minCost() {
    j::sort(nums, 0, n);
    if ((n >= 1)) {
      (dp[0] = nums[0]);
    }
    if ((n >= 2)) {
      (dp[1] = nums[1]);
    }
    if ((n >= 3)) {
      (dp[2] = ((nums[0] + nums[1]) + nums[2]));
    }
    for (int i = 3; (i < n); (i++)) {
      (dp[i] =
           jmin(((dp[(i - 1)] + nums[i]) + nums[0]),
                ((((dp[(i - 2)] + nums[1]) + nums[1]) + nums[i]) + nums[0])));
    }
    return dp[(n - 1)];
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code04_CrossRiver::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 过河问题
// 一共n人出游，他们走到一条河的西岸，想要过河到东岸
// 每个人都有一个渡河时间ti，西岸有一条船，一次最多乘坐两人
// 如果船上有一个人，划到对岸的时间，等于这个人的渡河时间
// 如果船上有两个人，划到对岸的时间，等于两个人的渡河时间的最大值
// 返回最少要花费多少时间，才能使所有人都过河
// 测试链接 : https://www.luogu.com.cn/problem/P1809
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下的code，提交时请把类名改成"Main"，可以直接通过
*/

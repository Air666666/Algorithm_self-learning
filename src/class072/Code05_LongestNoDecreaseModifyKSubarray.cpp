// Source: src/class072/Code05_LongestNoDecreaseModifyKSubarray.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code05_LongestNoDecreaseModifyKSubarray {
  inline static int MAXN = 100001;
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static Array<int> right = make_array<int>(MAXN);
  inline static Array<int> ends = make_array<int>(MAXN);
  inline static int n = {};
  inline static int k = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code05_LongestNoDecreaseModifyKSubarray() {}
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    while ((in.nextToken() != -1)) {
      (n = static_cast<int>(in.nval));
      in.nextToken();
      (k = static_cast<int>(in.nval));
      for (int i = 0; (i < n); (i++)) {
        in.nextToken();
        (arr[i] = static_cast<int>(in.nval));
      }
      if ((k >= n)) {
        out.println(n);
      } else {
        out.println(Code05_LongestNoDecreaseModifyKSubarray::compute());
      }
    }
    out.flush();
    out.close();
    br.close();
  }
  static int compute() {
    Code05_LongestNoDecreaseModifyKSubarray::right_method();
    int len = 0;
    int ans = 0;
    {
      int i = 0;
      int j = k;
      int find = {};
      int left = {};
      for (; (j < n); (i++), (j++)) {
        (find = Code05_LongestNoDecreaseModifyKSubarray::bs2(len, arr[j]));
        (left = ((find == (-1)) ? len : find));
        (ans = jmax(ans, ((left + k) + right[j])));
        (find = Code05_LongestNoDecreaseModifyKSubarray::bs2(len, arr[i]));
        if ((find == (-1))) {
          (ends[(len++)] = arr[i]);
        } else {
          (ends[find] = arr[i]);
        }
      }
    }
    (ans = jmax(ans, (len + k)));
    return ans;
  }
  static void right_method() {
    int len = 0;
    {
      int i = (n - 1);
      int find = {};
      for (; (i >= 0); (i--)) {
        (find = Code05_LongestNoDecreaseModifyKSubarray::bs1(len, arr[i]));
        if ((find == (-1))) {
          (ends[(len++)] = arr[i]);
          (right[i] = len);
        } else {
          (ends[find] = arr[i]);
          (right[i] = (find + 1));
        }
      }
    }
  }
  static int bs1(int len, int num) {
    int l = 0;
    int r = (len - 1);
    int m = {};
    int ans = (-1);
    while ((l <= r)) {
      (m = jdiv((l + r), 2));
      if ((ends[m] < num)) {
        (ans = m);
        (r = (m - 1));
      } else {
        (l = (m + 1));
      }
    }
    return ans;
  }
  static int bs2(int len, int num) {
    int l = 0;
    int r = (len - 1);
    int m = {};
    int ans = (-1);
    while ((l <= r)) {
      (m = jdiv((l + r), 2));
      if ((ends[m] > num)) {
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
  Code05_LongestNoDecreaseModifyKSubarray::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 有一次修改机会的最长不下降子序列
// 给定一个长度为n的数组arr，和一个整数k
// 只有一次机会可以将其中连续的k个数全修改成任意一个值
// 这次机会你可以用也可以不用，请返回最长不下降子序列长度
// 1 <= k, n <= 10^5
// 1 <= arr[i] <= 10^6
// 测试链接 : https://www.luogu.com.cn/problem/P8776
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下的所有代码，并把主类名改成"Main"，可以直接通过
        // 生成辅助数组right
        // right[j] :
        // 一定以arr[j]做开头的情况下，arr[j...]上最长不下降子序列长度是多少
        // 关键逻辑 :
        // 一定以arr[i]做开头的情况下，arr[i...]上最长不下降子序列
        //
就是！从n-1出发来看(从右往左遍历)，以arr[i]做结尾的情况下的最长不上升子序列
        // 求最长不上升子序列长度的二分
        // ends[0...len-1]是降序的，找到<num的最左位置
        // 不存在返回-1
        // 求最长不下降子序列长度的二分
        // ends[0...len-1]是升序的，找到>num的最左位置
        // 不存在返回-1
*/

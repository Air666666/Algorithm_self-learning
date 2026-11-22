// Source: src/class046/Code04_PositivesEqualsNegtivesLongestSubarray.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_PositivesEqualsNegtivesLongestSubarray {
  inline static int MAXN = 100001;
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static int n = {};
  inline static JMap<int, int> map = JMap<int, int>();
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_PositivesEqualsNegtivesLongestSubarray() {}
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    while ((in.nextToken() != -1)) {
      (n = static_cast<int>(in.nval));
      {
        int i = 0;
        int num = {};
        for (; (i < n); (i++)) {
          in.nextToken();
          (num = static_cast<int>(in.nval));
          (arr[i] = ((num != 0) ? ((num > 0) ? 1 : (-1)) : 0));
        }
      }
      out.println(Code04_PositivesEqualsNegtivesLongestSubarray::compute());
    }
    out.flush();
    out.close();
    br.close();
  }
  static int compute() {
    map.clear();
    map.put(0, (-1));
    int ans = 0;
    {
      int i = 0;
      int sum = 0;
      for (; (i < n); (i++)) {
        (sum += arr[i]);
        if (map.containsKey(sum)) {
          (ans = jmax(ans, (i - map.get(sum))));
        } else {
          map.put(sum, i);
        }
      }
    }
    return ans;
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code04_PositivesEqualsNegtivesLongestSubarray::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 返回无序数组中正数和负数个数相等的最长子数组长度
// 给定一个无序数组arr，其中元素可正、可负、可0
// 求arr所有子数组中正数与负数个数相等的最长子数组的长度
// 测试链接 : https://www.nowcoder.com/practice/545544c060804eceaed0bb84fcd992fb
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下的code，提交时请把类名改成"Main"，可以直接通过
*/

// Source: src/class046/Code02_LongestSubarraySumEqualsAim.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_LongestSubarraySumEqualsAim {
  inline static int MAXN = 100001;
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static int n = {};
  inline static int aim = {};
  inline static JMap<int, int> map = JMap<int, int>();
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_LongestSubarraySumEqualsAim() {}
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    while ((in.nextToken() != -1)) {
      (n = static_cast<int>(in.nval));
      in.nextToken();
      (aim = static_cast<int>(in.nval));
      for (int i = 0; (i < n); (i++)) {
        in.nextToken();
        (arr[i] = static_cast<int>(in.nval));
      }
      out.println(Code02_LongestSubarraySumEqualsAim::compute());
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
        if (map.containsKey((sum - aim))) {
          (ans = jmax(ans, (i - map.get((sum - aim)))));
        }
        if ((!map.containsKey(sum))) {
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
  Code02_LongestSubarraySumEqualsAim::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 返回无序数组中累加和为给定值的最长子数组长度
// 给定一个无序数组arr, 其中元素可正、可负、可0
// 给定一个整数aim
// 求arr所有子数组中累加和为aim的最长子数组长度
// 测试链接 : https://www.nowcoder.com/practice/36fb0fd3c656480c92b569258a1223d5
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下的code，提交时请把类名改成"Main"，可以直接通过
        // key : 某个前缀和
        // value : 这个前缀和最早出现的位置
                // 重要 : 0这个前缀和，一个数字也没有的时候，就存在了
*/

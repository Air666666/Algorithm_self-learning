// Source: src/class052/Code01_LeftRightLess.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_LeftRightLess {
  inline static int MAXN = 1000001;
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static Array<int> stack = make_array<int>(MAXN);
  inline static Array<Array<int>> ans = make_array<int>(MAXN, 2);
  inline static int n = {};
  inline static int r = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_LeftRightLess() {}
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    while ((in.nextToken() != -1)) {
      (n = static_cast<int>(in.nval));
      for (int i = 0; (i < n); (i++)) {
        in.nextToken();
        (arr[i] = static_cast<int>(in.nval));
      }
      Code01_LeftRightLess::compute();
      for (int i = 0; (i < n); (i++)) {
        out.println(((ans[i][0] + String(u" ")) + ans[i][1]));
      }
    }
    out.flush();
    out.close();
    br.close();
  }
  static void compute() {
    (r = 0);
    int cur = {};
    for (int i = 0; (i < n); (i++)) {
      while (((r > 0) && (arr[stack[(r - 1)]] >= arr[i]))) {
        (cur = stack[(--r)]);
        (ans[cur][0] = ((r > 0) ? stack[(r - 1)] : (-1)));
        (ans[cur][1] = i);
      }
      (stack[(r++)] = i);
    }
    while ((r > 0)) {
      (cur = stack[(--r)]);
      (ans[cur][0] = ((r > 0) ? stack[(r - 1)] : (-1)));
      (ans[cur][1] = (-1));
    }
    for (int i = (n - 2); (i >= 0); (i--)) {
      if (((ans[i][1] != (-1)) && (arr[ans[i][1]] == arr[i]))) {
        (ans[i][1] = ans[ans[i][1]][1]);
      }
    }
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code01_LeftRightLess::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 单调栈求每个位置左右两侧，离当前位置最近、且值严格小于的位置
// 给定一个可能含有重复值的数组 arr
// 找到每一个 i 位置左边和右边离 i 位置最近且值比 arr[i] 小的位置
// 返回所有位置相应的信息。
// 输入描述：
// 第一行输入一个数字 n，表示数组 arr 的长度。
// 以下一行输入 n 个数字，表示数组的值
// 输出描述：
// 输出n行，每行两个数字 L 和 R，如果不存在，则值为 -1，下标从 0 开始。
// 测试链接 : https://www.nowcoder.com/practice/2a2c00e7a88a498693568cef63a4b7bb
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下的code，提交时请把类名改成"Main"，可以直接通过
        // arr[0...n-1]
                // 遍历阶段
                        // i -> arr[i]
                                // cur当前弹出的位置，左边最近且小
                // 清算阶段
                // 修正阶段
                // 左侧的答案不需要修正一定是正确的，只有右侧答案需要修正
                // 从右往左修正，n-1位置的右侧答案一定是-1，不需要修正
*/

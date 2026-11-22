// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P4310

// Source: src/class127/Code04_LongestAddNotZero.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_LongestAddNotZero {
  inline static int MAXN = 100001;
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static Array<int> pre = make_array<int>(32);
  inline static int n = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_LongestAddNotZero() {}
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    (n = static_cast<int>(in.nval));
    for (int i = 0; (i < n); (i++)) {
      in.nextToken();
      (arr[i] = static_cast<int>(in.nval));
    }
    out.println(Code04_LongestAddNotZero::compute());
    out.flush();
    out.close();
    br.close();
  }
  static int compute() {
    j::fill(pre, 0);
    {
      int i = 0;
      int num = {};
      int cur = {};
      for (; (i < n); (i++)) {
        (num = arr[i]);
        (cur = 1);
        for (int j = 0; (j < 31); (j++)) {
          if (((jshr(num, j) & 1) == 1)) {
            (cur = jmax(cur, (pre[j] + 1)));
          }
        }
        for (int j = 0; (j < 31); (j++)) {
          if (((jshr(num, j) & 1) == 1)) {
            (pre[j] = jmax(pre[j], cur));
          }
        }
      }
    }
    int ans = 0;
    for (int j = 0; (j < 31); (j++)) {
      (ans = jmax(ans, pre[j]));
    }
    return ans;
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code04_LongestAddNotZero::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 相邻与结果不为0的最长子序列
// 给定一个长度为n的数组arr，你可以随意选择数字组成子序列
// 但是要求任意相邻的两个数&的结果不能是0，这样的子序列才是合法的
// 返回最长合法子序列的长度
// 1 <= n <= 10^5
// 0 <= arr[i] <= 10^9
// 测试链接 : https://www.luogu.com.cn/problem/P4310
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有用例
*/

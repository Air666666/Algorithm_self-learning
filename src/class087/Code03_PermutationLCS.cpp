// Source: src/class087/Code03_PermutationLCS.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_PermutationLCS {
  inline static int MAXN = 100001;
  inline static Array<int> a = make_array<int>(MAXN);
  inline static Array<int> b = make_array<int>(MAXN);
  inline static Array<int> where = make_array<int>(MAXN);
  inline static Array<int> ends = make_array<int>(MAXN);
  inline static int n = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_PermutationLCS() {}
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    while ((in.nextToken() != -1)) {
      (n = static_cast<int>(in.nval));
      for (int i = 0; (i < n); (i++)) {
        in.nextToken();
        (a[i] = static_cast<int>(in.nval));
      }
      for (int i = 0; (i < n); (i++)) {
        in.nextToken();
        (b[i] = static_cast<int>(in.nval));
      }
      out.println(Code03_PermutationLCS::compute());
    }
    out.flush();
    out.close();
    br.close();
  }
  static int compute() {
    for (int i = 0; (i < n); (i++)) {
      (where[a[i]] = i);
    }
    for (int i = 0; (i < n); (i++)) {
      (b[i] = where[b[i]]);
    }
    return Code03_PermutationLCS::lis();
  }
  static int lis() {
    int len = 0;
    {
      int i = 0;
      int find = {};
      for (; (i < n); (i++)) {
        (find = Code03_PermutationLCS::bs(len, b[i]));
        if ((find == (-1))) {
          (ends[(len++)] = b[i]);
        } else {
          (ends[find] = b[i]);
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
      if ((ends[m] >= num)) {
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
  Code03_PermutationLCS::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 两个排列的最长公共子序列长度
// 给出由1~n这些数字组成的两个排列
// 求它们的最长公共子序列长度
// n <= 10^5
// 测试链接 : https://www.luogu.com.cn/problem/P1439
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下的code，提交时请把类名改成"Main"，可以直接通过
        // 讲解072 - 最长递增子序列及其扩展
*/

// Source: src/class047/Code02_ArithmeticSequenceDifference.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_ArithmeticSequenceDifference {
  inline static int MAXN = 10000005;
  inline static Array<i64> arr = make_array<i64>(MAXN);
  inline static int n = {};
  inline static int m = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_ArithmeticSequenceDifference() {}
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    while ((in.nextToken() != -1)) {
      (n = static_cast<int>(in.nval));
      in.nextToken();
      (m = static_cast<int>(in.nval));
      {
        int i = 0;
        int l = {};
        int r = {};
        int s = {};
        int e = {};
        for (; (i < m); (i++)) {
          in.nextToken();
          (l = static_cast<int>(in.nval));
          in.nextToken();
          (r = static_cast<int>(in.nval));
          in.nextToken();
          (s = static_cast<int>(in.nval));
          in.nextToken();
          (e = static_cast<int>(in.nval));
          Code02_ArithmeticSequenceDifference::set(l, r, s, e,
                                                   jdiv((e - s), (r - l)));
        }
      }
      Code02_ArithmeticSequenceDifference::build();
      i64 max = 0;
      i64 xor_java = 0;
      for (int i = 1; (i <= n); (i++)) {
        (max = jmax(max, arr[i]));
        (xor_java ^= arr[i]);
      }
      out.println(((xor_java + String(u" ")) + max));
    }
    out.flush();
    out.close();
    br.close();
  }
  static void set(int l, int r, int s, int e, int d) {
    (arr[l] += s);
    (arr[(l + 1)] += (d - s));
    (arr[(r + 1)] -= (d + e));
    (arr[(r + 2)] += e);
  }
  static void build() {
    for (int i = 1; (i <= n); (i++)) {
      (arr[i] += arr[(i - 1)]);
    }
    for (int i = 1; (i <= n); (i++)) {
      (arr[i] += arr[(i - 1)]);
    }
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code02_ArithmeticSequenceDifference::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 一开始1~n范围上的数字都是0，一共有m个操作，每次操作为(l,r,s,e,d)
// 表示在l~r范围上依次加上首项为s、末项为e、公差为d的数列
// m个操作做完之后，统计1~n范围上所有数字的最大值和异或和
// 测试链接 : https://www.luogu.com.cn/problem/P4231
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下的code，提交时请把类名改成"Main"，可以直接通过
*/

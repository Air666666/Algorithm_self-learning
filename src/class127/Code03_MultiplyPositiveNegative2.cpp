// Source: src/class127/Code03_MultiplyPositiveNegative2.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_MultiplyPositiveNegative2 {
  inline static int MAXN = 200001;
  inline static int n = {};
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static i64 ans1 = {};
  inline static i64 ans2 = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_MultiplyPositiveNegative2() {}
  static void compute() {
    Array<int> cnt = make_array<int>(2);
    (cnt[0] = 1);
    (cnt[1] = 0);
    (ans1 = (ans2 = 0));
    {
      int i = 1;
      int cur = 0;
      for (; (i <= n); (i++)) {
        (cur ^= ((arr[i] > 0) ? 0 : 1));
        (ans1 += cnt[cur]);
        (ans2 += cnt[(cur ^ 1)]);
        (cnt[cur]++);
      }
    }
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    (n = static_cast<int>(in.nval));
    for (int i = 1; (i <= n); (i++)) {
      in.nextToken();
      (arr[i] = static_cast<int>(in.nval));
    }
    Code03_MultiplyPositiveNegative2::compute();
    out.println(((ans2 + String(u" ")) + ans1));
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code03_MultiplyPositiveNegative2::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 感谢热心的同学，找到了题目3的在线测试
// 测试链接 : https://codeforces.com/problemset/problem/1215/B
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 结果可能很大，所以用long类型
*/

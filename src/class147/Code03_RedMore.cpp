// Source: src/class147/Code03_RedMore.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_RedMore {
  inline static int MOD = 100;
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_RedMore() {}
  static i64 compute(int n) {
    Array<i64> f = make_array<i64>((n + 1));
    (f[0] = (f[1] = 1));
    for (int i = 2; (i <= n); (i++)) {
      {
        int l = 0;
        int r = (i - 1);
        for (; (l < i); (l++), (r--)) {
          (f[i] = jrem((f[i] + jrem((f[l] * f[r]), MOD)), MOD));
        }
      }
    }
    return f[n];
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    int n = static_cast<int>(in.nval);
    out.println(Code03_RedMore::compute(n));
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code03_RedMore::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 任意前缀上红多于黑
// 有n个红和n个黑，要组成2n长度的数列，保证任意前缀上，红的数量 >= 黑的数量
// 返回有多少种排列方法，答案对 100 取模
// 1 <= n <= 100
// 测试链接 : https://www.luogu.com.cn/problem/P1722
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 因为取模的数字含有很多因子
        // 无法用费马小定理或者扩展欧几里得求逆元
        // 同时注意到n的范围并不大，直接使用公式4
*/

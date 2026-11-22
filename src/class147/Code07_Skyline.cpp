// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/SP7897
// https://www.spoj.com/problems/SKYLINE

// Source: src/class147/Code07_Skyline.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code07_Skyline {
  inline static int MOD = 1000000;
  inline static int MAXN = 1001;
  inline static Array<i64> f = make_array<i64>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code07_Skyline() {}
  static void build() {
    (f[0] = (f[1] = 1));
    for (int i = 2; (i < MAXN); (i++)) {
      {
        int l = 0;
        int r = (i - 1);
        for (; (l < i); (l++), (r--)) {
          (f[i] = jrem((f[i] + jrem((f[l] * f[r]), MOD)), MOD));
        }
      }
    }
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    Code07_Skyline::build();
    while ((in.nextToken() != -1)) {
      int n = static_cast<int>(in.nval);
      if ((n == 0)) {
        break;
      }
      out.println(f[n]);
    }
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code07_Skyline::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 不含递增三元组的排列方法数
//
数字从1到n，可以形成很多排列，要求任意从左往右的三个位置，不能出现依次递增的样子
// 返回排列的方法数，答案对 1000000 取模
// 1 <= n <= 1000
// 测试链接 : https://www.luogu.com.cn/problem/SP7897
// 测试链接 : https://www.spoj.com/problems/SKYLINE
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 因为取模的数字含有很多因子
        // 无法用费马小定理或者扩展欧几里得求逆元
        // 同时注意到n的范围并不大，直接使用公式4
*/

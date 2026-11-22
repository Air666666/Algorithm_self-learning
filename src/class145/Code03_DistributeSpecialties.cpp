// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P5505

// Source: src/class145/Code03_DistributeSpecialties.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_DistributeSpecialties {
  inline static int MAXN = 1001;
  inline static int MAXK = (MAXN * 2);
  inline static int MOD = 1000000007;
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static Array<Array<i64>> c = make_array<i64>(MAXK, MAXK);
  inline static Array<i64> g = make_array<i64>(MAXN);
  inline static int n = {};
  inline static int k = {};
  inline static int m = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_DistributeSpecialties() {}
  static i64 compute() {
    for (int i = 0; (i <= k); (i++)) {
      (c[i][0] = 1);
      for (int j = 1; (j <= i); (j++)) {
        (c[i][j] = jrem((c[(i - 1)][j] + c[(i - 1)][(j - 1)]), MOD));
      }
    }
    for (int i = 0; (i < n); (i++)) {
      (g[i] = c[n][i]);
      for (int j = 1; (j <= m); (j++)) {
        (g[i] = static_cast<int>(
             jrem((g[i] * c[(((arr[j] + n) - i) - 1)][((n - i) - 1)]), MOD)));
      }
    }
    (g[n] = 0);
    i64 ans = 0;
    for (int i = 0; (i <= n); (i++)) {
      if (((i & 1) == 0)) {
        (ans = jrem((ans + g[i]), MOD));
      } else {
        (ans = jrem((ans + jrem((g[i] * (MOD - 1)), MOD)), MOD));
      }
    }
    return ans;
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    (n = static_cast<int>(in.nval));
    (k = (n * 2));
    in.nextToken();
    (m = static_cast<int>(in.nval));
    for (int i = 1; (i <= m); (i++)) {
      in.nextToken();
      (arr[i] = static_cast<int>(in.nval));
    }
    out.println(Code03_DistributeSpecialties::compute());
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code03_DistributeSpecialties::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 分特产
// 一共有m种特产，arr[i]表示i种特产有几个
// 一共有n个同学，每个同学至少要得到一个特产
// 返回分配特产的方法数，答案对 1000000007 取模
// 0 <= n、m <= 1000
// 0 <= arr[i] <= 1000
// 测试链接 : https://www.luogu.com.cn/problem/P5505
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
                                // -1 和 (MOD-1) 同余
*/

// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P5367

// Source: src/class146/Code01_CantorExpansion.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_CantorExpansion {
  inline static int MAXN = 1000001;
  inline static int MOD = 998244353;
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static Array<int> fac = make_array<int>(MAXN);
  inline static Array<int> tree = make_array<int>(MAXN);
  inline static int n = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_CantorExpansion() {}
  static int lowbit(int i) { return (i & (-i)); }
  static int sum(int i) {
    int ans = 0;
    while ((i > 0)) {
      (ans = jrem((ans + tree[i]), MOD));
      (i -= Code01_CantorExpansion::lowbit(i));
    }
    return ans;
  }
  static void add(int i, int v) {
    while ((i <= n)) {
      (tree[i] += v);
      (i += Code01_CantorExpansion::lowbit(i));
    }
  }
  static i64 compute() {
    (fac[0] = 1);
    for (int i = 1; (i < n); (i++)) {
      (fac[i] =
           static_cast<int>(jrem((static_cast<i64>(fac[(i - 1)]) * i), MOD)));
    }
    for (int i = 1; (i <= n); (i++)) {
      Code01_CantorExpansion::add(i, 1);
    }
    i64 ans = 0;
    for (int i = 1; (i <= n); (i++)) {
      (ans = jrem((ans + jrem((static_cast<i64>(
                                   Code01_CantorExpansion::sum((arr[i] - 1))) *
                               fac[(n - i)]),
                              MOD)),
                  MOD));
      Code01_CantorExpansion::add(arr[i], (-1));
    }
    (ans = jrem((ans + 1), MOD));
    return ans;
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
    out.println(Code01_CantorExpansion::compute());
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code01_CantorExpansion::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 康托展开
// 数字从1到n，可以有很多排列，给出具体的一个排列，求该排列的名次，答案对
998244353 取模
// 1 <= n <= 10^6
// 测试链接 : https://www.luogu.com.cn/problem/P5367
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 阶乘余数表
        // 树状数组
                // 求的排名从0开始，但是题目要求从1开始，所以最后+1再返回
*/

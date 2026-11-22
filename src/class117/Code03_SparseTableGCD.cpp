// Source: src/class117/Code03_SparseTableGCD.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_SparseTableGCD {
  inline static int MAXN = 1001;
  inline static int LIMIT = 10;
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static Array<int> log2 = make_array<int>(MAXN);
  inline static Array<Array<int>> stgcd = make_array<int>(MAXN, LIMIT);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_SparseTableGCD() {}
  static void build(int n) {
    (log2[0] = (-1));
    for (int i = 1; (i <= n); (i++)) {
      (log2[i] = (log2[jshr(i, 1)] + 1));
      (stgcd[i][0] = arr[i]);
    }
    for (int p = 1; (p <= log2[n]); (p++)) {
      for (int i = 1; (((i + jshl(1, p)) - 1) <= n); (i++)) {
        (stgcd[i][p] = Code03_SparseTableGCD::gcd(
             stgcd[i][(p - 1)], stgcd[(i + jshl(1, (p - 1)))][(p - 1)]));
      }
    }
  }
  static int gcd(int a, int b) {
    return ((b == 0) ? a : Code03_SparseTableGCD::gcd(b, jrem(a, b)));
  }
  static int query(int l, int r) {
    int p = log2[((r - l) + 1)];
    return Code03_SparseTableGCD::gcd(stgcd[l][p],
                                      stgcd[((r - jshl(1, p)) + 1)][p]);
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    int n = static_cast<int>(in.nval);
    in.nextToken();
    int m = static_cast<int>(in.nval);
    for (int i = 1; (i <= n); (i++)) {
      in.nextToken();
      (arr[i] = static_cast<int>(in.nval));
    }
    Code03_SparseTableGCD::build(n);
    {
      int i = 1;
      int l = {};
      int r = {};
      for (; (i <= m); (i++)) {
        in.nextToken();
        (l = static_cast<int>(in.nval));
        in.nextToken();
        (r = static_cast<int>(in.nval));
        out.println(Code03_SparseTableGCD::query(l, r));
      }
    }
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code03_SparseTableGCD::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// ST表查询最大公约数
// 给定一个长度为n的数组arr，一共有m次查询
// 每次查询arr[l~r]上所有数的最大公约数
// 测试链接 : https://www.luogu.com.cn/problem/P1890
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下的code，提交时请把类名改成"Main"，可以直接通过
        // 算法讲解041 - 辗转相除法求最大公约数
*/

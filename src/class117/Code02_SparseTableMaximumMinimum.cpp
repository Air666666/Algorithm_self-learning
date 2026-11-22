// Source: src/class117/Code02_SparseTableMaximumMinimum.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_SparseTableMaximumMinimum {
  inline static int MAXN = 50001;
  inline static int LIMIT = 16;
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static Array<int> log2 = make_array<int>(MAXN);
  inline static Array<Array<int>> stmax = make_array<int>(MAXN, LIMIT);
  inline static Array<Array<int>> stmin = make_array<int>(MAXN, LIMIT);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_SparseTableMaximumMinimum() {}
  static void build(int n) {
    (log2[0] = (-1));
    for (int i = 1; (i <= n); (i++)) {
      (log2[i] = (log2[jshr(i, 1)] + 1));
      (stmax[i][0] = arr[i]);
      (stmin[i][0] = arr[i]);
    }
    for (int p = 1; (p <= log2[n]); (p++)) {
      for (int i = 1; (((i + jshl(1, p)) - 1) <= n); (i++)) {
        (stmax[i][p] =
             jmax(stmax[i][(p - 1)], stmax[(i + jshl(1, (p - 1)))][(p - 1)]));
        (stmin[i][p] =
             jmin(stmin[i][(p - 1)], stmin[(i + jshl(1, (p - 1)))][(p - 1)]));
      }
    }
  }
  static int query(int l, int r) {
    int p = log2[((r - l) + 1)];
    int a = jmax(stmax[l][p], stmax[((r - jshl(1, p)) + 1)][p]);
    int b = jmin(stmin[l][p], stmin[((r - jshl(1, p)) + 1)][p]);
    return (a - b);
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
    Code02_SparseTableMaximumMinimum::build(n);
    {
      int i = 1;
      int l = {};
      int r = {};
      for (; (i <= m); (i++)) {
        in.nextToken();
        (l = static_cast<int>(in.nval));
        in.nextToken();
        (r = static_cast<int>(in.nval));
        out.println(Code02_SparseTableMaximumMinimum::query(l, r));
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
  Code02_SparseTableMaximumMinimum::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// ST表查询最大值和最小值
// 给定一个长度为n的数组arr，一共有m次查询
// 每次查询arr[l~r]上的最大值和最小值
// 每次查询只需要打印最大值-最小值的结果
// 测试链接 : https://www.luogu.com.cn/problem/P2880
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下的code，提交时请把类名改成"Main"，可以直接通过
        // 2的15次方是<=50001且最接近的
        // 所以次方可能是0~15
        // 于是准备16长度够用了
        // log2[i] : 查询<=i情况下，最大的2的幂，是2的几次方
*/

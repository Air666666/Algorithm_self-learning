// Source: src/class207/Code02_TransitiveClosure1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_TransitiveClosure1 {
  inline static int MAXN = 101;
  inline static int n = {};
  inline static Array<BitSet> dp = make_array<BitSet>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_TransitiveClosure1() {}
  static void floyd() {
    for (int bridge = 1; (bridge <= n); (bridge++)) {
      for (int i = 1; (i <= n); (i++)) {
        if (dp[i].get(bridge)) {
          dp[i].or_java(dp[bridge]);
        }
      }
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    for (int i = 1; (i <= n); (i++)) {
      (dp[i] = BitSet((n + 1)));
    }
    int s = {};
    for (int i = 1; (i <= n); (i++)) {
      for (int j = 1; (j <= n); (j++)) {
        (s = in.nextInt());
        dp[i].set(j, (s == 1));
      }
    }
    Code02_TransitiveClosure1::floyd();
    for (int i = 1; (i <= n); (i++)) {
      for (int j = 1; (j <= n); (j++)) {
        if (dp[i].get(j)) {
          out.print(String(u"1 "));
        } else {
          out.print(String(u"0 "));
        }
      }
      out.println();
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code02_TransitiveClosure1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 传递闭包，java版
// 一共n个点，给定有向图的邻接矩阵a，原图没有自环
// 如果 a[i][j] == 1，表示存在从i到j的有向边
// 如果 a[i][j] == 0，表示不存在从i到j的有向边
// 求有向图的传递闭包，输出关系矩阵b
// 如果i经过至少一条有向边可以到达j，那么b[i][j]为1，否则为0
// 1 <= n <= 100
// 测试链接 : https://www.luogu.com.cn/problem/B3611
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 读写工具类
*/

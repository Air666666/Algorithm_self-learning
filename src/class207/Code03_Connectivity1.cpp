// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P4306

// Source: src/class207/Code03_Connectivity1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_Connectivity1 {
  inline static int MAXN = 2001;
  inline static int n = {};
  inline static Array<BitSet> dp = make_array<BitSet>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_Connectivity1() {}
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
    jchar s = {};
    for (int i = 1; (i <= n); (i++)) {
      for (int j = 1; (j <= n); (j++)) {
        (s = in.nextChar());
        dp[i].set(j, (s == u'1'));
      }
    }
    for (int i = 1; (i <= n); (i++)) {
      dp[i].set(i);
    }
    Code03_Connectivity1::floyd();
    int ans = 0;
    for (int i = 1; (i <= n); (i++)) {
      (ans += dp[i].cardinality());
    }
    out.println(ans);
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code03_Connectivity1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 连通数，java版
// 一共n个点，给定有向图的邻接矩阵a
// 如果 a[i][j] == 1，表示存在从i到j的有向边
// 如果 a[i][j] == 0，表示不存在从i到j的有向边
// 如果i可以直接或间接到达j，则有序点对(i, j)计入答案
// 每个点都认为可以到达自己，因此(i, i)也计入答案
// 求所有可达有序点对的数量，打印这个数量
// 1 <= n <= 2000
// 测试链接 : https://www.luogu.com.cn/problem/P4306
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
                // 主动设置对角线
        // 读写工具类
*/

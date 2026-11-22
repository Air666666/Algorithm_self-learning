// Source: src/class207/Code06_DirectedGraphAndQuery1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code06_DirectedGraphAndQuery1 {
  inline static int MAXN = 2001;
  inline static int MAXQ = 10001;
  inline static int n = {};
  inline static int m = {};
  inline static int q = {};
  inline static Array<int> s = make_array<int>(MAXQ);
  inline static Array<int> t = make_array<int>(MAXQ);
  inline static Array<BitSet> dp = make_array<BitSet>(MAXN);
  inline static Array<int> ans = make_array<int>(MAXQ);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code06_DirectedGraphAndQuery1() {}
  static void floyd() {
    for (int i = 1; (i <= q); (i++)) {
      (ans[i] = (-1));
    }
    for (int bridge = 1; (bridge <= n); (bridge++)) {
      for (int i = 1; (i <= n); (i++)) {
        if (dp[i].get(bridge)) {
          dp[i].or_java(dp[bridge]);
        }
      }
      for (int i = 1; (i <= q); (i++)) {
        if (((ans[i] == (-1)) && dp[s[i]].get(t[i]))) {
          (ans[i] = jmax(bridge, jmax(s[i], t[i])));
        }
      }
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (m = in.nextInt());
    for (int i = 1; (i <= n); (i++)) {
      (dp[i] = BitSet((n + 1)));
    }
    {
      int i = 1;
      int a = {};
      int b = {};
      for (; (i <= m); (i++)) {
        (a = in.nextInt());
        (b = in.nextInt());
        dp[a].set(b);
      }
    }
    (q = in.nextInt());
    for (int i = 1; (i <= q); (i++)) {
      (s[i] = in.nextInt());
      (t[i] = in.nextInt());
    }
    Code06_DirectedGraphAndQuery1::floyd();
    for (int i = 1; (i <= q); (i++)) {
      out.println(ans[i]);
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code06_DirectedGraphAndQuery1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 有向图与查询，java版
// 一共n个点，编号1~n，给定m条有向边，没有重边和自环
// 每条边的格式 a b，表示存在从a到b的有向边
// 定义有向路径的代价，路径上所有点的编号最大值，包括起点和终点
// 一共q条查询，每条查询的格式 s t，保证 s != t
// 求从s到t的所有有向路径中，最小的路径代价，不存在路径输出-1
// 2 <= n <= 2000
// 0 <= m <= n * (n - 1)
// 1 <= q <= 10000
// 测试链接 : https://www.luogu.com.cn/problem/AT_abc287_h
// 测试链接 : https://atcoder.jp/contests/abc287/tasks/abc287_h
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 读写工具类
*/

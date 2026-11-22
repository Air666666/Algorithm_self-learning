// Source: src/class173/Code07_Royal1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code07_Royal1 {
  inline static int MAXN = 1001;
  inline static int n = {};
  inline static int b = {};
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> next = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> to = make_array<int>(jshl(MAXN, 1));
  inline static int cntg = {};
  inline static Array<int> capital = make_array<int>(MAXN);
  inline static Array<int> belong = make_array<int>(MAXN);
  inline static int cntb = {};
  inline static Array<int> stack = make_array<int>(MAXN);
  inline static int siz = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code07_Royal1() {}
  static void addEdge(int u, int v) {
    (next[(++cntg)] = head[u]);
    (to[cntg] = v);
    (head[u] = cntg);
  }
  static void dfs(int u, int f) {
    int x = siz;
    {
      int e = head[u];
      int v = {};
      for (; (e > 0); (e = next[e])) {
        (v = to[e]);
        if ((v != f)) {
          Code07_Royal1::dfs(v, u);
          if (((siz - x) >= b)) {
            (capital[(++cntb)] = u);
            while ((siz != x)) {
              (belong[stack[(siz--)]] = cntb);
            }
          }
        }
      }
    }
    (stack[(++siz)] = u);
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (b = in.nextInt());
    {
      int i = 1;
      int u = {};
      int v = {};
      for (; (i < n); (i++)) {
        (u = in.nextInt());
        (v = in.nextInt());
        Code07_Royal1::addEdge(u, v);
        Code07_Royal1::addEdge(v, u);
      }
    }
    Code07_Royal1::dfs(1, 0);
    if ((cntb == 0)) {
      (capital[(++cntb)] = 1);
    }
    while ((siz > 0)) {
      (belong[stack[(siz--)]] = cntb);
    }
    out.println(cntb);
    for (int i = 1; (i <= n); (i++)) {
      out.print((belong[i] + String(u" ")));
    }
    out.println();
    for (int i = 1; (i <= cntb); (i++)) {
      out.print((capital[i] + String(u" ")));
    }
    out.println();
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code07_Royal1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 王室联邦，java版
// 一共有n个城市，编号1~n，给定n-1条边，所有城市连成一棵树
// 给定数值b，请把树划分成若干个省，划分要求如下
// 每个省至少要有b个城市，最多有3 * b个城市，每个省必须有一个省会
// 省会可在省内也可在省外，一个城市可以是多个省的省会
// 一个省里，任何城市到达省会的路径上，除了省会之外的其他城市，必须都在省内
// 根据要求完成一种有效划分即可，先打印划分了多少个省，假设数量为k
// 然后打印n个数字，范围[1, k]，表示每个城市被划分给了哪个省
// 最后打印k个数字，表示每个省会的城市编号
// 1 <= n、b <= 10^3
// 测试链接 : https://www.luogu.com.cn/problem/P2325
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 读写工具类
*/

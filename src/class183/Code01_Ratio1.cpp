// Source: src/class183/Code01_Ratio1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_Ratio1 {
  inline static int MAXN = 20001;
  inline static int n = {};
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> nxt = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> to = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> weight = make_array<int>(jshl(MAXN, 1));
  inline static int cntg = {};
  inline static Array<bool> vis = make_array<bool>(MAXN);
  inline static Array<int> siz = make_array<int>(MAXN);
  inline static Array<int> cur = make_array<int>(3);
  inline static Array<int> all = make_array<int>(3);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_Ratio1() {}
  static int gcd(int a, int b) {
    return ((b == 0) ? a : Code01_Ratio1::gcd(b, jrem(a, b)));
  }
  static void addEdge(int u, int v, int w) {
    (nxt[(++cntg)] = head[u]);
    (to[cntg] = v);
    (weight[cntg] = w);
    (head[u] = cntg);
  }
  static void getSize(int u, int fa) {
    (siz[u] = 1);
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      int v = to[e];
      if (((v != fa) && (!vis[v]))) {
        Code01_Ratio1::getSize(v, u);
        (siz[u] += siz[v]);
      }
    }
  }
  static int getCentroid(int u, int fa) {
    Code01_Ratio1::getSize(u, fa);
    int half = jshr(siz[u], 1);
    bool find = false;
    while ((!find)) {
      (find = true);
      for (int e = head[u]; (e > 0); (e = nxt[e])) {
        int v = to[e];
        if ((((v != fa) && (!vis[v])) && (siz[v] > half))) {
          (fa = u);
          (u = v);
          (find = false);
          break;
        }
      }
    }
    return u;
  }
  static void dfs(int u, int fa, int dis) {
    (cur[jrem(dis, 3)]++);
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      int v = to[e];
      if (((v != fa) && (!vis[v]))) {
        Code01_Ratio1::dfs(v, u, (dis + weight[e]));
      }
    }
  }
  static int calc(int u) {
    int ans = 1;
    (all[0] = (all[1] = (all[2] = 0)));
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      int v = to[e];
      int w = weight[e];
      if ((!vis[v])) {
        (cur[0] = (cur[1] = (cur[2] = 0)));
        Code01_Ratio1::dfs(v, u, w);
        (ans += (((((all[0] * cur[0]) * 2) + ((all[1] * cur[2]) * 2)) +
                  ((all[2] * cur[1]) * 2)) +
                 (cur[0] * 2)));
        (all[0] += cur[0]);
        (all[1] += cur[1]);
        (all[2] += cur[2]);
      }
    }
    return ans;
  }
  static int solve(int u) {
    int ans = 0;
    (vis[u] = true);
    (ans += Code01_Ratio1::calc(u));
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      int v = to[e];
      if ((!vis[v])) {
        (ans += Code01_Ratio1::solve(Code01_Ratio1::getCentroid(v, u)));
      }
    }
    return ans;
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    {
      int i = 1;
      int u = {};
      int v = {};
      int w = {};
      for (; (i < n); (i++)) {
        (u = in.nextInt());
        (v = in.nextInt());
        (w = in.nextInt());
        Code01_Ratio1::addEdge(u, v, w);
        Code01_Ratio1::addEdge(v, u, w);
      }
    }
    int centroid = Code01_Ratio1::getCentroid(1, 0);
    int a = Code01_Ratio1::solve(centroid);
    int b = (n * n);
    int c = Code01_Ratio1::gcd(a, b);
    (a /= c);
    (b /= c);
    out.println(((a + String(u"/")) + b));
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code01_Ratio1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 聪聪可可，java版
// 一共有n个节点，给定n-1条边，每条边有边权，所有节点组成一棵树
// 如果点对(u, v)的简单路径权值和能被3整除，则称这个点对是合法的
// 认为点对(x, x)的简单路径权值和是0，并且认为(x, y)和(y, x)是不同的点对
// 打印(合法点对的数量 / 点对的总数量)的最简分数形式
// 1 <= n、边权 <= 2 * 10^4
// 测试链接 : https://www.luogu.com.cn/problem/P2634
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // vis[u] = true，表示u是之前的分治点
        // cur[v]，表示往下走的当前路径中，路径权值和 % 3 == v的路径有多少条
        // all[v]，表示往下走的所有路径中，路径权值和 % 3 == v的路径有多少条
        // 读写工具类
*/

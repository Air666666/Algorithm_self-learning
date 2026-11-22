// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P4178

// Source: src/class183/Code04_Tree1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_Tree1 {
  inline static int MAXN = 50001;
  inline static int n = {};
  inline static int k = {};
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> nxt = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> to = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> weight = make_array<int>(jshl(MAXN, 1));
  inline static int cntg = {};
  inline static Array<bool> vis = make_array<bool>(MAXN);
  inline static Array<int> siz = make_array<int>(MAXN);
  inline static Array<int> disArr = make_array<int>(MAXN);
  inline static int cnta = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_Tree1() {}
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
        Code04_Tree1::getSize(v, u);
        (siz[u] += siz[v]);
      }
    }
  }
  static int getCentroid(int u, int fa) {
    Code04_Tree1::getSize(u, fa);
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
    if ((dis > k)) {
      return;
    }
    (disArr[(++cnta)] = dis);
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      int v = to[e];
      if (((v != fa) && (!vis[v]))) {
        Code04_Tree1::dfs(v, u, (dis + weight[e]));
      }
    }
  }
  static i64 calc(int u, int dis) {
    (cnta = 0);
    Code04_Tree1::dfs(u, 0, dis);
    i64 ans = 0;
    j::sort(disArr, 1, (cnta + 1));
    {
      int l = 1;
      int r = cnta;
      for (; (l <= r);) {
        if (((disArr[l] + disArr[r]) <= k)) {
          (ans += (r - l));
          (l++);
        } else {
          (r--);
        }
      }
    }
    return ans;
  }
  static i64 solve(int u) {
    (vis[u] = true);
    i64 ans = Code04_Tree1::calc(u, 0);
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      int v = to[e];
      if ((!vis[v])) {
        (ans -= Code04_Tree1::calc(v, weight[e]));
        (ans += Code04_Tree1::solve(Code04_Tree1::getCentroid(v, u)));
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
        Code04_Tree1::addEdge(u, v, w);
        Code04_Tree1::addEdge(v, u, w);
      }
    }
    (k = in.nextInt());
    out.println(Code04_Tree1::solve(Code04_Tree1::getCentroid(1, 0)));
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code04_Tree1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 距离<=k的点对数量，java版
// 一共有n个节点，给定n-1条边，每条边有边权，所有节点组成一棵树
// 给定数字k，求出树上两点距离<=k的点对数量
// 本题规定(x, x)不是点对，(x, y)和(y, x)认为是同一个点对
// 1 <= n <= 4 * 10^4
// 0 <= 边权 <= 10^3
// 0 <= k <= 2 * 10^4
// 测试链接 : https://www.luogu.com.cn/problem/P4178
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 从真正的头来到u时，路径权值和为dis
        // 子树u上的点对(x, y)，需要走过，x -> 真正的头 -> y
        // 返回距离<=k的点对数量
        // 读写工具类
*/

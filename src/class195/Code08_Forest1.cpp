// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P5344

// Source: src/class195/Code08_Forest1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code08_Forest1 {
  inline static int MAXN = 50001;
  inline static int MAXM = 1000001;
  inline static int MAXT = 4000001;
  inline static int MAXE = 30000001;
  inline static int MAXP = 17;
  inline static int INF = jshl(1, 30);
  inline static int n = {};
  inline static int m = {};
  inline static int s = {};
  inline static Array<int> u1 = make_array<int>(MAXM);
  inline static Array<int> v1 = make_array<int>(MAXM);
  inline static Array<int> u2 = make_array<int>(MAXM);
  inline static Array<int> v2 = make_array<int>(MAXM);
  inline static Array<int> weight = make_array<int>(MAXM);
  inline static int cntq = {};
  inline static Array<int> head1 = make_array<int>(MAXN);
  inline static Array<int> next1 = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> to1 = make_array<int>(jshl(MAXN, 1));
  inline static int cnt1 = {};
  inline static Array<int> head2 = make_array<int>(MAXT);
  inline static Array<int> next2 = make_array<int>(MAXE);
  inline static Array<int> to2 = make_array<int>(MAXE);
  inline static Array<int> weight2 = make_array<int>(MAXE);
  inline static int cnt2 = {};
  inline static Array<int> father = make_array<int>(MAXN);
  inline static Array<int> dep = make_array<int>(MAXN);
  inline static Array<Array<int>> stjump = make_array<int>(MAXN, MAXP);
  inline static Array<Array<int>> stout = make_array<int>(MAXN, MAXP);
  inline static Array<Array<int>> stin = make_array<int>(MAXN, MAXP);
  inline static int cntt = {};
  inline static Array<int> dist = make_array<int>(MAXT);
  inline static Array<bool> vis = make_array<bool>(MAXT);
  inline static JHeap<Array<int>> heap = JHeap<Array<int>>(
      [](Array<int> a, Array<int> b) { return (a[1] - b[1]); });
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code08_Forest1() {}
  static void addEdge1(int u, int v) {
    (next1[(++cnt1)] = head1[u]);
    (to1[cnt1] = v);
    (head1[u] = cnt1);
  }
  static void addEdge2(int u, int v, int w) {
    (next2[(++cnt2)] = head2[u]);
    (to2[cnt2] = v);
    (weight2[cnt2] = w);
    (head2[u] = cnt2);
  }
  static int find(int i) {
    if ((i != father[i])) {
      (father[i] = Code08_Forest1::find(father[i]));
    }
    return father[i];
  }
  static void build(int u, int fa) {
    (dep[u] = (dep[fa] + 1));
    (stjump[u][0] = fa);
    (stout[u][0] = (++cntt));
    Code08_Forest1::addEdge2(u, cntt, 0);
    Code08_Forest1::addEdge2(fa, cntt, 0);
    (stin[u][0] = (++cntt));
    Code08_Forest1::addEdge2(cntt, u, 0);
    Code08_Forest1::addEdge2(cntt, fa, 0);
    for (int p = 1; (p < MAXP); (p++)) {
      (stjump[u][p] = stjump[stjump[u][(p - 1)]][(p - 1)]);
      (stout[u][p] = (++cntt));
      Code08_Forest1::addEdge2(stout[u][(p - 1)], cntt, 0);
      Code08_Forest1::addEdge2(stout[stjump[u][(p - 1)]][(p - 1)], cntt, 0);
      (stin[u][p] = (++cntt));
      Code08_Forest1::addEdge2(cntt, stin[u][(p - 1)], 0);
      Code08_Forest1::addEdge2(cntt, stin[stjump[u][(p - 1)]][(p - 1)], 0);
    }
    for (int e = head1[u]; (e > 0); (e = next1[e])) {
      int v = to1[e];
      if ((v != fa)) {
        Code08_Forest1::build(v, u);
      }
    }
  }
  static void pathOut(int x, int y, int vnode) {
    if ((dep[x] < dep[y])) {
      int tmp = x;
      (x = y);
      (y = tmp);
    }
    Code08_Forest1::addEdge2(y, vnode, 0);
    for (int p = (MAXP - 1); (p >= 0); (p--)) {
      if ((dep[stjump[x][p]] >= dep[y])) {
        Code08_Forest1::addEdge2(stout[x][p], vnode, 0);
        (x = stjump[x][p]);
      }
    }
    if ((x == y)) {
      return;
    }
    for (int p = (MAXP - 1); (p >= 0); (p--)) {
      if ((stjump[x][p] != stjump[y][p])) {
        Code08_Forest1::addEdge2(stout[x][p], vnode, 0);
        Code08_Forest1::addEdge2(stout[y][p], vnode, 0);
        (x = stjump[x][p]);
        (y = stjump[y][p]);
      }
    }
    Code08_Forest1::addEdge2(stout[x][0], vnode, 0);
  }
  static void pathIn(int x, int y, int vnode) {
    if ((dep[x] < dep[y])) {
      int tmp = x;
      (x = y);
      (y = tmp);
    }
    Code08_Forest1::addEdge2(vnode, y, 0);
    for (int p = (MAXP - 1); (p >= 0); (p--)) {
      if ((dep[stjump[x][p]] >= dep[y])) {
        Code08_Forest1::addEdge2(vnode, stin[x][p], 0);
        (x = stjump[x][p]);
      }
    }
    if ((x == y)) {
      return;
    }
    for (int p = (MAXP - 1); (p >= 0); (p--)) {
      if ((stjump[x][p] != stjump[y][p])) {
        Code08_Forest1::addEdge2(vnode, stin[x][p], 0);
        Code08_Forest1::addEdge2(vnode, stin[y][p], 0);
        (x = stjump[x][p]);
        (y = stjump[y][p]);
      }
    }
    Code08_Forest1::addEdge2(vnode, stin[x][0], 0);
  }
  static void pathToPath(int a, int b, int c, int d, int w) {
    int x = (++cntt);
    int y = (++cntt);
    Code08_Forest1::pathOut(a, b, x);
    Code08_Forest1::pathIn(c, d, y);
    Code08_Forest1::addEdge2(x, y, w);
  }
  static void dijkstra() {
    for (int i = 1; (i <= cntt); (i++)) {
      (dist[i] = INF);
    }
    (dist[s] = 0);
    heap.add(Array<int>{s, 0});
    while ((!heap.isEmpty())) {
      Array<int> cur = heap.poll();
      int u = cur[0];
      int d = cur[1];
      if ((!vis[u])) {
        (vis[u] = true);
        for (int e = head2[u]; (e > 0); (e = next2[e])) {
          int v = to2[e];
          int w = weight2[e];
          if (((!vis[v]) && (dist[v] > (d + w)))) {
            (dist[v] = (d + w));
            heap.add(Array<int>{v, dist[v]});
          }
        }
      }
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (m = in.nextInt());
    (s = in.nextInt());
    (cntt = n);
    for (int i = 1; (i <= n); (i++)) {
      (father[i] = i);
    }
    {
      int i = 1;
      int op = {};
      int a = {};
      int b = {};
      int c = {};
      int d = {};
      int w = {};
      int u = {};
      int v = {};
      for (; (i <= m); (i++)) {
        (op = in.nextInt());
        if ((op == 1)) {
          (a = in.nextInt());
          (b = in.nextInt());
          (c = in.nextInt());
          (d = in.nextInt());
          (w = in.nextInt());
          if (([&]() {
                auto jleft = Code08_Forest1::find(a);
                auto jright = Code08_Forest1::find(b);
                return (jleft == jright);
              }() &&
               [&]() {
                 auto jleft = Code08_Forest1::find(c);
                 auto jright = Code08_Forest1::find(d);
                 return (jleft == jright);
               }())) {
            (u1[(++cntq)] = a);
            (v1[cntq] = b);
            (u2[cntq] = c);
            (v2[cntq] = d);
            (weight[cntq] = w);
          }
        } else {
          (u = in.nextInt());
          (v = in.nextInt());
          (w = in.nextInt());
          int ufa = Code08_Forest1::find(u);
          int vfa = Code08_Forest1::find(v);
          if ((ufa != vfa)) {
            Code08_Forest1::addEdge1(u, v);
            Code08_Forest1::addEdge1(v, u);
            Code08_Forest1::addEdge2(u, v, w);
            Code08_Forest1::addEdge2(v, u, w);
            (father[ufa] = vfa);
          }
        }
      }
    }
    for (int i = 1; (i <= n); (i++)) {
      if ((dep[i] == 0)) {
        Code08_Forest1::build(i, i);
      }
    }
    for (int i = 1; (i <= cntq); (i++)) {
      Code08_Forest1::pathToPath(u1[i], v1[i], u2[i], v2[i], weight[i]);
    }
    Code08_Forest1::dijkstra();
    for (int i = 1; (i <= n); (i++)) {
      out.print(((dist[i] == INF) ? (-1) : dist[i]));
      out.print(String(u" "));
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code08_Forest1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 逛森林，java版
// 一共n个点，给定出发点s，初始时没有边，一共m条操作，操作类型有两种
// 操作 1 a b c d w : 如果点a和点b不连通，或者点c和点d不连通，忽略该操作
// 点a到点b路径上的任何一点，可以花费w的代价，传送到点c到点d路径上的任何一点
//       该操作是单向传送，不代表加边，判断连通性只考虑2类型的操作加入的边
// 操作 2 u v w : 点u和点v如果已经连通，忽略该操作，否则增加一条边权为w的无向边
// 完成m条操作后，打印从s点出发，到每个节点的最小花费，到达不了的节点打印-1
// 1 <= n <= 5 * 10^4    1 <= m <= 10^6    1 <= w <= 100
// 测试链接 : https://www.luogu.com.cn/problem/P5344
// 提交以下的code，提交时请把类名改成"Main"
// 本题卡常java的实现无法通过
// 想通过用C++实现，本节课Code08_Forest2文件就是C++的实现
// 两个版本的逻辑完全一样，C++版本可以通过所有测试
        // 操作1记录一下，只记录应该发生的操作1
        // 操作2建立的树
        // 操作1 + 操作2 建立的图
        // 并查集
        // 树上倍增
        // dijkstra算法
        // 读写工具类
*/

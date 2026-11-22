// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P3320

// Source: src/class180/Code06_TreasureHunt1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code06_TreasureHunt1 {
  inline static int MAXN = 100001;
  inline static int MAXP = 20;
  inline static int n = {};
  inline static int m = {};
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> nxt = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> to = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> weight = make_array<int>(jshl(MAXN, 1));
  inline static int cntg = {};
  inline static Array<int> dep = make_array<int>(MAXN);
  inline static Array<i64> dist = make_array<i64>(MAXN);
  inline static Array<int> dfn = make_array<int>(MAXN);
  inline static Array<int> seg = make_array<int>(MAXN);
  inline static Array<Array<int>> stjump = make_array<int>(MAXN, MAXP);
  inline static int cntd = {};
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static Array<bool> treasure = make_array<bool>(MAXN);
  inline static JSet<int> set = JSet<int>();
  inline static Array<i64> ans = make_array<i64>(MAXN);
  inline static Array<Array<int>> ufwe = make_array<int>(MAXN, 4);
  inline static int stacksize = {};
  inline static int u = {};
  inline static int f = {};
  inline static int w = {};
  inline static int e = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code06_TreasureHunt1() {}
  static void addEdge(int u, int v, int w) {
    (nxt[(++cntg)] = head[u]);
    (to[cntg] = v);
    (weight[cntg] = w);
    (head[u] = cntg);
  }
  static void dfs1(int u, int fa, int w) {
    (dep[u] = (dep[fa] + 1));
    (dfn[u] = (++cntd));
    (seg[cntd] = u);
    (dist[u] = (dist[fa] + w));
    (stjump[u][0] = fa);
    for (int p = 1; (p < MAXP); (p++)) {
      (stjump[u][p] = stjump[stjump[u][(p - 1)]][(p - 1)]);
    }
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      if ((to[e] != fa)) {
        Code06_TreasureHunt1::dfs1(to[e], u, weight[e]);
      }
    }
  }
  static void push(int u, int f, int w, int e) {
    (ufwe[stacksize][0] = u);
    (ufwe[stacksize][1] = f);
    (ufwe[stacksize][2] = w);
    (ufwe[stacksize][3] = e);
    (stacksize++);
  }
  static void pop() {
    (--stacksize);
    (u = ufwe[stacksize][0]);
    (f = ufwe[stacksize][1]);
    (w = ufwe[stacksize][2]);
    (e = ufwe[stacksize][3]);
  }
  static void dfs2() {
    (stacksize = 0);
    Code06_TreasureHunt1::push(1, 0, 0, (-1));
    while ((stacksize > 0)) {
      Code06_TreasureHunt1::pop();
      if ((e == (-1))) {
        (dep[u] = (dep[f] + 1));
        (dfn[u] = (++cntd));
        (seg[cntd] = u);
        (dist[u] = (dist[f] + w));
        (stjump[u][0] = f);
        for (int p = 1; (p < MAXP); (p++)) {
          (stjump[u][p] = stjump[stjump[u][(p - 1)]][(p - 1)]);
        }
        (e = head[u]);
      } else {
        (e = nxt[e]);
      }
      if ((e != 0)) {
        Code06_TreasureHunt1::push(u, f, w, e);
        if ((to[e] != f)) {
          Code06_TreasureHunt1::push(to[e], u, weight[e], (-1));
        }
      }
    }
  }
  static int getLca(int a, int b) {
    if ((dep[a] < dep[b])) {
      int tmp = a;
      (a = b);
      (b = tmp);
    }
    for (int p = (MAXP - 1); (p >= 0); (p--)) {
      if ((dep[stjump[a][p]] >= dep[b])) {
        (a = stjump[a][p]);
      }
    }
    if ((a == b)) {
      return a;
    }
    for (int p = (MAXP - 1); (p >= 0); (p--)) {
      if ((stjump[a][p] != stjump[b][p])) {
        (a = stjump[a][p]);
        (b = stjump[b][p]);
      }
    }
    return stjump[a][0];
  }
  static i64 getDist(int x, int y) {
    return ((dist[x] + dist[y]) -
            (2 * dist[Code06_TreasureHunt1::getLca(x, y)]));
  }
  static void compute() {
    i64 curAns = 0;
    for (int i = 1; (i <= m); (i++)) {
      int nodeId = arr[i];
      int dfnId = dfn[nodeId];
      if ((!treasure[nodeId])) {
        (treasure[nodeId] = true);
        set.add(dfnId);
      } else {
        (treasure[nodeId] = false);
        set.remove(dfnId);
      }
      if ((set.size() <= 1)) {
        (curAns = 0);
      } else {
        int low = seg[((set.lower(dfnId) != nullptr) ? unbox(set.lower(dfnId))
                                                     : unbox(set.last()))];
        int high =
            seg[((set.higher(dfnId) != nullptr) ? unbox(set.higher(dfnId))
                                                : unbox(set.first()))];
        i64 delta = [&]() {
          auto jleft = [&]() {
            auto jleft = Code06_TreasureHunt1::getDist(nodeId, low);
            auto jright = Code06_TreasureHunt1::getDist(nodeId, high);
            return (jleft + jright);
          }();
          auto jright = Code06_TreasureHunt1::getDist(low, high);
          return (jleft - jright);
        }();
        if (treasure[nodeId]) {
          (curAns += delta);
        } else {
          (curAns -= delta);
        }
      }
      (ans[i] = curAns);
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (m = in.nextInt());
    {
      int i = 1;
      int u = {};
      int v = {};
      int w = {};
      for (; (i < n); (i++)) {
        (u = in.nextInt());
        (v = in.nextInt());
        (w = in.nextInt());
        Code06_TreasureHunt1::addEdge(u, v, w);
        Code06_TreasureHunt1::addEdge(v, u, w);
      }
    }
    Code06_TreasureHunt1::dfs2();
    for (int i = 1; (i <= m); (i++)) {
      (arr[i] = in.nextInt());
    }
    Code06_TreasureHunt1::compute();
    for (int i = 1; (i <= m); (i++)) {
      out.println(ans[i]);
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code06_TreasureHunt1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 寻宝游戏，java版
// 一共有n个节点，节点有两种类型，刷宝的点 和 不刷宝的点
// 一共有n-1条无向边，每条边有边权，所有节点组成一棵树
// 开始时所有节点都是不刷宝的点，接下来有m条操作，格式如下
// 操作 x : x号点的类型翻转，刷宝的点 变成 不刷宝的点，不刷宝的点 变成 刷宝的点
//
一次操作后，每个刷宝的点都会产生宝物，你可以瞬移到任何点作为出发点，瞬移是无代价的
// 你需要走路拿到所有的宝物，最后回到出发点，打印最小的行走总路程，一共有m条打印
// 1 <= n、m <= 10^5
// 测试链接 : https://www.luogu.com.cn/problem/P3320
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 这里为了方便，使用语言自带的有序表
        // dfs递归版，java会爆栈，C++可以通过
        // 不会改迭代版，去看讲解118，详解了从递归版改迭代版
        // dfs1的迭代版
                // dfs1(1, 0, 0);
        // 读写工具类
*/

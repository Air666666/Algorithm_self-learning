// Source: src/class200/Code05_CactusDiameter1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code05_CactusDiameter1 {
  inline static int MAXN = 50001;
  inline static int MAXM = 1000001;
  inline static int n = {};
  inline static int m = {};
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> nxt = make_array<int>(jshl(MAXM, 1));
  inline static Array<int> to = make_array<int>(jshl(MAXM, 1));
  inline static int cntg = {};
  inline static Array<int> dfn = make_array<int>(MAXN);
  inline static Array<int> low = make_array<int>(MAXN);
  inline static int cntd = {};
  inline static Array<int> sta = make_array<int>(MAXN);
  inline static int top = {};
  inline static Array<int> dist = make_array<int>(MAXN);
  inline static Array<int> arr = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> que = make_array<int>(jshl(MAXN, 1));
  inline static int diameter = {};
  inline static Array<int> stau = make_array<int>(MAXN);
  inline static Array<int> stap = make_array<int>(MAXN);
  inline static Array<int> stas = make_array<int>(MAXN);
  inline static Array<int> stae = make_array<int>(MAXN);
  inline static int u = {};
  inline static int preEdge = {};
  inline static int status = {};
  inline static int e = {};
  inline static int stacksiz = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code05_CactusDiameter1() {}
  static void push(int u, int preEdge, int status, int e) {
    (stau[stacksiz] = u);
    (stap[stacksiz] = preEdge);
    (stas[stacksiz] = status);
    (stae[stacksiz] = e);
    (stacksiz++);
  }
  static void pop() {
    (stacksiz--);
    (u = stau[stacksiz]);
    (preEdge = stap[stacksiz]);
    (status = stas[stacksiz]);
    (e = stae[stacksiz]);
  }
  static void addEdge(int u, int v) {
    (nxt[(++cntg)] = head[u]);
    (to[cntg] = v);
    (head[u] = cntg);
  }
  static void dpOnCycle(int u, int v) {
    int siz = 0;
    (arr[(++siz)] = dist[u]);
    int pop = {};
    do {
      (pop = sta[(top--)]);
      (arr[(++siz)] = dist[pop]);
    } while ((pop != v));
    for (int i = 1; (i <= siz); (i++)) {
      (arr[(i + siz)] = arr[i]);
    }
    int l = 1;
    int r = 0;
    (que[(++r)] = 1);
    for (int i = 2; (i <= jshl(siz, 1)); (i++)) {
      while (((l <= r) && (((i - que[l]) * 2) > siz))) {
        (l++);
      }
      (diameter = jmax(diameter, (((arr[i] + i) + arr[que[l]]) - que[l])));
      while (((l <= r) && ((arr[que[r]] - que[r]) <= (arr[i] - i)))) {
        (r--);
      }
      (que[(++r)] = i);
    }
    for (int i = 2; (i <= siz); (i++)) {
      (dist[u] = jmax(dist[u], (arr[i] + jmin((i - 1), (siz - (i - 1))))));
    }
  }
  static void tarjan1(int u, int preEdge) {
    (dfn[u] = (low[u] = (++cntd)));
    (sta[(++top)] = u);
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      if (((e ^ 1) == preEdge)) {
        continue;
      }
      int v = to[e];
      if ((dfn[v] == 0)) {
        Code05_CactusDiameter1::tarjan1(v, e);
        if ((low[v] < dfn[u])) {
          (low[u] = jmin(low[u], low[v]));
        } else if ((low[v] > dfn[u])) {
          (top--);
          (diameter = jmax(diameter, ((dist[u] + dist[v]) + 1)));
          (dist[u] = jmax(dist[u], (dist[v] + 1)));
        } else {
          Code05_CactusDiameter1::dpOnCycle(u, v);
        }
      } else if ((dfn[v] < dfn[u])) {
        (low[u] = jmin(low[u], dfn[v]));
      }
    }
  }
  static void tarjan2(int node, int pree) {
    (stacksiz = 0);
    Code05_CactusDiameter1::push(node, pree, (-1), (-1));
    int v = {};
    while ((stacksiz > 0)) {
      Code05_CactusDiameter1::pop();
      if ((status == (-1))) {
        (dfn[u] = (low[u] = (++cntd)));
        (sta[(++top)] = u);
        (e = head[u]);
      } else {
        (v = to[e]);
        if ((status == 0)) {
          if ((low[v] < dfn[u])) {
            (low[u] = jmin(low[u], low[v]));
          } else if ((low[v] > dfn[u])) {
            (top--);
            (diameter = jmax(diameter, ((dist[u] + dist[v]) + 1)));
            (dist[u] = jmax(dist[u], (dist[v] + 1)));
          } else {
            Code05_CactusDiameter1::dpOnCycle(u, v);
          }
        } else {
          if ((dfn[v] < dfn[u])) {
            (low[u] = jmin(low[u], dfn[v]));
          }
        }
        (e = nxt[e]);
      }
      if (((e ^ 1) == preEdge)) {
        (e = nxt[e]);
      }
      if ((e != 0)) {
        (v = to[e]);
        if ((dfn[v] == 0)) {
          Code05_CactusDiameter1::push(u, preEdge, 0, e);
          Code05_CactusDiameter1::push(v, e, (-1), (-1));
        } else {
          Code05_CactusDiameter1::push(u, preEdge, 1, e);
        }
      }
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (m = in.nextInt());
    (cntg = 1);
    {
      int i = 1;
      int k = {};
      int x = {};
      int y = {};
      for (; (i <= m); (i++)) {
        (k = in.nextInt());
        (x = in.nextInt());
        for (int j = 2; (j <= k); (j++)) {
          (y = in.nextInt());
          Code05_CactusDiameter1::addEdge(x, y);
          Code05_CactusDiameter1::addEdge(y, x);
          (x = y);
        }
      }
    }
    Code05_CactusDiameter1::tarjan2(1, 0);
    out.println(diameter);
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code05_CactusDiameter1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 仙人掌直径，java版
// 给定n个点、m条路径表示无向图，每条路径的相邻两点之间都有边
// 点x到点y的距离，是指x到y的最短路径中的边数
// 仙人掌直径，是指任意两点距离的最大值
// 输入保证图是仙人掌，计算仙人掌直径
// 1 <= n <= 5 * 10^4
// 1 <= 边总数 <= 10^6
// 测试链接 : https://www.luogu.com.cn/problem/P4244
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // dist[u] : 以u为头的子仙人掌中，u到任意点的最短路距离的最大值
        // 收集环中每个点的dist，然后复制一份
        // 单调队列
        // 答案
        // 递归改迭代需要的栈
        // 递归版
        // 迭代版
                // tarjan1(1, 0);
        // 读写工具类
*/

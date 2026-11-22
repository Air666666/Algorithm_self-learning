// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P7924

// Source: src/class192/Code05_Traveler1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code05_Traveler1 {
  inline static int MAXN = 500001;
  inline static int MAXM = 2000001;
  inline static int MAXP = 20;
  inline static int n = {};
  inline static int m = {};
  inline static int q = {};
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static Array<int> a = make_array<int>(MAXM);
  inline static Array<int> b = make_array<int>(MAXM);
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> nxt = make_array<int>(jshl(MAXM, 1));
  inline static Array<int> to = make_array<int>(jshl(MAXM, 1));
  inline static int cntg = {};
  inline static Array<int> dfn = make_array<int>(MAXN);
  inline static Array<int> low = make_array<int>(MAXN);
  inline static int cntd = {};
  inline static Array<int> sta = make_array<int>(MAXN);
  inline static int top = {};
  inline static Array<int> belong = make_array<int>(MAXN);
  inline static Array<int> sum = make_array<int>(MAXN);
  inline static int ebccCnt = {};
  inline static Array<int> lg2 = make_array<int>(MAXN);
  inline static Array<Array<int>> rmq = make_array<int>(MAXN, MAXP);
  inline static Array<int> useCnt = make_array<int>(MAXN);
  inline static Array<Array<int>> stack = make_array<int>(MAXN, 4);
  inline static int u = {};
  inline static int preEdge = {};
  inline static int status = {};
  inline static int e = {};
  inline static int stacksize = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code05_Traveler1() {}
  static void push(int u, int preEdge, int status, int e) {
    (stack[stacksize][0] = u);
    (stack[stacksize][1] = preEdge);
    (stack[stacksize][2] = status);
    (stack[stacksize][3] = e);
    (stacksize++);
  }
  static void pop() {
    (stacksize--);
    (u = stack[stacksize][0]);
    (preEdge = stack[stacksize][1]);
    (status = stack[stacksize][2]);
    (e = stack[stacksize][3]);
  }
  static void addEdge(int u, int v) {
    (nxt[(++cntg)] = head[u]);
    (to[cntg] = v);
    (head[u] = cntg);
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
        Code05_Traveler1::tarjan1(v, e);
        (low[u] = jmin(low[u], low[v]));
      } else {
        (low[u] = jmin(low[u], dfn[v]));
      }
    }
    if ((dfn[u] == low[u])) {
      (ebccCnt++);
      int pop = {};
      do {
        (pop = sta[(top--)]);
        (belong[pop] = ebccCnt);
        (sum[ebccCnt] += arr[pop]);
      } while ((pop != u));
    }
  }
  static void tarjan2(int node, int pree) {
    (stacksize = 0);
    Code05_Traveler1::push(node, pree, (-1), (-1));
    int v = {};
    while ((stacksize > 0)) {
      Code05_Traveler1::pop();
      if ((status == (-1))) {
        (dfn[u] = (low[u] = (++cntd)));
        (sta[(++top)] = u);
        (e = head[u]);
      } else {
        (v = to[e]);
        if ((status == 0)) {
          (low[u] = jmin(low[u], low[v]));
        } else {
          (low[u] = jmin(low[u], dfn[v]));
        }
        (e = nxt[e]);
      }
      if (((e ^ 1) == preEdge)) {
        (e = nxt[e]);
      }
      if ((e != 0)) {
        (v = to[e]);
        if ((dfn[v] == 0)) {
          Code05_Traveler1::push(u, preEdge, 0, e);
          Code05_Traveler1::push(v, e, (-1), (-1));
        } else {
          Code05_Traveler1::push(u, preEdge, 1, e);
        }
      } else {
        if ((dfn[u] == low[u])) {
          (ebccCnt++);
          int pop = {};
          do {
            (pop = sta[(top--)]);
            (belong[pop] = ebccCnt);
            (sum[ebccCnt] += arr[pop]);
          } while ((pop != u));
        }
      }
    }
  }
  static void condense() {
    (cntg = 0);
    for (int i = 1; (i <= ebccCnt); (i++)) {
      (head[i] = 0);
    }
    for (int i = 1; (i <= m); (i++)) {
      int ebcc1 = belong[a[i]];
      int ebcc2 = belong[b[i]];
      if ((ebcc1 != ebcc2)) {
        Code05_Traveler1::addEdge(ebcc1, ebcc2);
        Code05_Traveler1::addEdge(ebcc2, ebcc1);
      }
    }
  }
  static int getUp(int x, int y) { return ((dfn[x] < dfn[y]) ? x : y); }
  static void dfs(int u, int fa) {
    (dfn[u] = (++cntd));
    (rmq[dfn[u]][0] = fa);
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      int v = to[e];
      if ((v != fa)) {
        Code05_Traveler1::dfs(v, u);
      }
    }
  }
  static void buildRmq() {
    (cntd = 0);
    Code05_Traveler1::dfs(1, 0);
    for (int i = 2; (i <= ebccCnt); (i++)) {
      (lg2[i] = (lg2[jshr(i, 1)] + 1));
    }
    {
      int pre = 0;
      int cur = 1;
      for (; (cur <= lg2[ebccCnt]); (pre++), (cur++)) {
        for (int i = 1; (((i + jshl(1, cur)) - 1) <= ebccCnt); (i++)) {
          (rmq[i][cur] = Code05_Traveler1::getUp(rmq[i][pre],
                                                 rmq[(i + jshl(1, pre))][pre]));
        }
      }
    }
  }
  static int getFather(int x) { return rmq[dfn[x]][0]; }
  static int getLCA(int x, int y) {
    if ((x == y)) {
      return x;
    }
    (x = dfn[x]);
    (y = dfn[y]);
    if ((x > y)) {
      int tmp = x;
      (x = y);
      (y = tmp);
    }
    (x++);
    int k = lg2[((y - x) + 1)];
    return Code05_Traveler1::getUp(rmq[x][k], rmq[((y - jshl(1, k)) + 1)][k]);
  }
  static void dfsOnTree(int u, int fa) {
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      int v = to[e];
      if ((v != fa)) {
        Code05_Traveler1::dfsOnTree(v, u);
        (useCnt[u] += useCnt[v]);
      }
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (cntg = 1);
    (n = in.nextInt());
    (m = in.nextInt());
    for (int i = 1; (i <= n); (i++)) {
      (arr[i] = in.nextInt());
    }
    for (int i = 1; (i <= m); (i++)) {
      (a[i] = in.nextInt());
      (b[i] = in.nextInt());
      Code05_Traveler1::addEdge(a[i], b[i]);
      Code05_Traveler1::addEdge(b[i], a[i]);
    }
    Code05_Traveler1::tarjan2(1, 0);
    Code05_Traveler1::condense();
    Code05_Traveler1::buildRmq();
    (q = in.nextInt());
    {
      int i = 1;
      int x = {};
      int y = {};
      int xylca = {};
      int lcafa = {};
      for (; (i <= q); (i++)) {
        (x = in.nextInt());
        (y = in.nextInt());
        (x = belong[x]);
        (y = belong[y]);
        (xylca = Code05_Traveler1::getLCA(x, y));
        (lcafa = Code05_Traveler1::getFather(xylca));
        (useCnt[x]++);
        (useCnt[y]++);
        (useCnt[xylca]--);
        (useCnt[lcafa]--);
      }
    }
    Code05_Traveler1::dfsOnTree(1, 0);
    int ans = 0;
    for (int i = 1; (i <= ebccCnt); (i++)) {
      if ((useCnt[i] > 0)) {
        (ans += sum[i]);
      }
    }
    out.println(ans);
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code05_Traveler1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 旅行家，java版
// 给定一张无向图，一共n个点、m条边，每个点给定点权，保证所有点连通
// 一条路径要求，点可以重复经过，边不能重复经过
// 一共有q条操作，格式 x y : 从点x到点y所有可能的路径都走一遍
// 一共q条操作，可能涉及非常多的路径，如果一条路径通过了某个点
// 该点的点权就算入收益，但是以后再有其他路径通过该点，不重复获得收益
// 打印总收益是多少
// 1 <= n <= 5 * 10^5
// 1 <= m <= 2 * 10^6
// 1 <= q <= 10^6
// 测试链接 : https://www.luogu.com.cn/problem/P7924
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 迭代版需要的栈，讲解118讲了递归改迭代的技巧
        // 递归版
        // 迭代版
                // tarjan1(1, 0);
        // 读写工具类
*/

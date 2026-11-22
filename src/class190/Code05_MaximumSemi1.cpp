// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P2272

// Source: src/class190/Code05_MaximumSemi1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code05_MaximumSemi1 {
  inline static int MAXN = 100001;
  inline static int MAXM = 1000001;
  inline static int n = {};
  inline static int m = {};
  inline static int x = {};
  inline static Array<int> a = make_array<int>(MAXM);
  inline static Array<int> b = make_array<int>(MAXM);
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> nxt = make_array<int>(MAXM);
  inline static Array<int> to = make_array<int>(MAXM);
  inline static int cntg = {};
  inline static Array<int> dfn = make_array<int>(MAXN);
  inline static Array<int> low = make_array<int>(MAXN);
  inline static int cntd = {};
  inline static Array<int> sta = make_array<int>(MAXN);
  inline static int top = {};
  inline static Array<int> belong = make_array<int>(MAXN);
  inline static Array<int> sccSiz = make_array<int>(MAXN);
  inline static int sccCnt = {};
  inline static Array<i64> edgeArr = make_array<i64>(MAXM);
  inline static int cnte = {};
  inline static Array<int> indegree = make_array<int>(MAXN);
  inline static Array<int> dpSum = make_array<int>(MAXN);
  inline static Array<int> dpCnt = make_array<int>(MAXN);
  inline static int ans1 = {};
  inline static int ans2 = {};
  inline static Array<Array<int>> stack = make_array<int>(MAXN, 3);
  inline static int u = {};
  inline static int status = {};
  inline static int e = {};
  inline static int stacksize = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code05_MaximumSemi1() {}
  static void push(int u, int status, int e) {
    (stack[stacksize][0] = u);
    (stack[stacksize][1] = status);
    (stack[stacksize][2] = e);
    (stacksize++);
  }
  static void pop() {
    (stacksize--);
    (u = stack[stacksize][0]);
    (status = stack[stacksize][1]);
    (e = stack[stacksize][2]);
  }
  static void addEdge(int u, int v) {
    (nxt[(++cntg)] = head[u]);
    (to[cntg] = v);
    (head[u] = cntg);
  }
  static void tarjan1(int u) {
    (dfn[u] = (low[u] = (++cntd)));
    (sta[(++top)] = u);
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      int v = to[e];
      if ((dfn[v] == 0)) {
        Code05_MaximumSemi1::tarjan1(v);
        (low[u] = jmin(low[u], low[v]));
      } else {
        if ((belong[v] == 0)) {
          (low[u] = jmin(low[u], dfn[v]));
        }
      }
    }
    if ((dfn[u] == low[u])) {
      (sccCnt++);
      (sccSiz[sccCnt] = 0);
      int pop = {};
      do {
        (pop = sta[(top--)]);
        (belong[pop] = sccCnt);
        (sccSiz[sccCnt]++);
      } while ((pop != u));
    }
  }
  static void tarjan2(int node) {
    (stacksize = 0);
    Code05_MaximumSemi1::push(node, (-1), (-1));
    int v = {};
    while ((stacksize > 0)) {
      Code05_MaximumSemi1::pop();
      if ((status == (-1))) {
        (dfn[u] = (low[u] = (++cntd)));
        (sta[(++top)] = u);
        (e = head[u]);
      } else {
        (v = to[e]);
        if ((status == 0)) {
          (low[u] = jmin(low[u], low[v]));
        }
        if (((status == 1) && (belong[v] == 0))) {
          (low[u] = jmin(low[u], dfn[v]));
        }
        (e = nxt[e]);
      }
      if ((e != 0)) {
        (v = to[e]);
        if ((dfn[v] == 0)) {
          Code05_MaximumSemi1::push(u, 0, e);
          Code05_MaximumSemi1::push(v, (-1), (-1));
        } else {
          Code05_MaximumSemi1::push(u, 1, e);
        }
      } else {
        if ((dfn[u] == low[u])) {
          (sccCnt++);
          (sccSiz[sccCnt] = 0);
          int pop = {};
          do {
            (pop = sta[(top--)]);
            (belong[pop] = sccCnt);
            (sccSiz[sccCnt]++);
          } while ((pop != u));
        }
      }
    }
  }
  static void condense() {
    (cntg = 0);
    for (int i = 1; (i <= sccCnt); (i++)) {
      (head[i] = 0);
    }
    for (int i = 1; (i <= m); (i++)) {
      int scc1 = belong[a[i]];
      int scc2 = belong[b[i]];
      if ((scc1 != scc2)) {
        (edgeArr[(++cnte)] = (jshl(static_cast<i64>(scc1), 32) | scc2));
      }
    }
    j::sort(edgeArr, 1, (cnte + 1));
    i64 pre = 0;
    i64 cur = {};
    for (int i = 1; (i <= cnte); (i++)) {
      (cur = edgeArr[i]);
      if ((cur != pre)) {
        int scc1 = static_cast<int>(jushr(cur, 32));
        int scc2 = static_cast<int>((cur & 0xffffffffLL));
        (indegree[scc2]++);
        Code05_MaximumSemi1::addEdge(scc1, scc2);
        (pre = cur);
      }
    }
  }
  static void dpOnDAG() {
    for (int u = sccCnt; (u > 0); (u--)) {
      if ((indegree[u] == 0)) {
        (dpSum[u] = sccSiz[u]);
        (dpCnt[u] = 1);
      }
      for (int e = head[u]; (e > 0); (e = nxt[e])) {
        int v = to[e];
        if ((dpSum[v] < (dpSum[u] + sccSiz[v]))) {
          (dpSum[v] = (dpSum[u] + sccSiz[v]));
          (dpCnt[v] = dpCnt[u]);
        } else if ((dpSum[v] == (dpSum[u] + sccSiz[v]))) {
          (dpCnt[v] = jrem((dpCnt[v] + dpCnt[u]), x));
        }
      }
    }
    (ans1 = (ans2 = 0));
    for (int i = 1; (i <= sccCnt); (i++)) {
      if ((dpSum[i] > ans1)) {
        (ans1 = dpSum[i]);
        (ans2 = dpCnt[i]);
      } else if ((dpSum[i] == ans1)) {
        (ans2 = jrem((ans2 + dpCnt[i]), x));
      }
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (m = in.nextInt());
    (x = in.nextInt());
    for (int i = 1; (i <= m); (i++)) {
      (a[i] = in.nextInt());
      (b[i] = in.nextInt());
      Code05_MaximumSemi1::addEdge(a[i], b[i]);
    }
    for (int i = 1; (i <= n); (i++)) {
      if ((dfn[i] == 0)) {
        Code05_MaximumSemi1::tarjan2(i);
      }
    }
    Code05_MaximumSemi1::condense();
    Code05_MaximumSemi1::dpOnDAG();
    out.println(ans1);
    out.println(ans2);
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code05_MaximumSemi1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 最大半连通子图，java版
// 有向图中节点u和v，只要其中一点能到达另一点，就说两点是半连通的
// 如果一个有向图，任意两点都是半连通的，这样的有向图就是半连通图
//
有向图中的一个点集，该点集中只要某两点在原图中有边，那么这条边就保留，则可以得到一个子图
//
如果该子图既是半连通图，又有节点数量最多，那么这个子图就是原图的最大半连通子图
// 给定一张n个点，m条边的有向图，打印最大半连通子图的大小
// 可能存在多个最大半连通子图，打印这个数量，数量对给定的数字x取余
// 1 <= n <= 10^5
// 1 <= m <= 10^6
// 测试链接 : https://www.luogu.com.cn/problem/P2272
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 迭代版需要的栈，讲解118讲了递归改迭代的技巧
        // 递归版，java会爆栈，C++可以通过
        // 迭代版
                                // tarjan1(i);
        // 读写工具类
*/

// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P3275

// Source: src/class190/Code08_Candy1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code08_Candy1 {
  inline static int MAXN = 100001;
  inline static int MAXM = 200001;
  inline static int n = {};
  inline static int k = {};
  inline static int m = {};
  inline static Array<int> a = make_array<int>(MAXM);
  inline static Array<int> b = make_array<int>(MAXM);
  inline static Array<int> c = make_array<int>(MAXM);
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> nxt = make_array<int>(MAXM);
  inline static Array<int> to = make_array<int>(MAXM);
  inline static Array<int> weight = make_array<int>(MAXM);
  inline static int cntg = {};
  inline static Array<int> dfn = make_array<int>(MAXN);
  inline static Array<int> low = make_array<int>(MAXN);
  inline static int cntd = {};
  inline static Array<int> sta = make_array<int>(MAXN);
  inline static int top = {};
  inline static Array<int> belong = make_array<int>(MAXN);
  inline static Array<int> sccSiz = make_array<int>(MAXN);
  inline static int sccCnt = {};
  inline static Array<int> indegree = make_array<int>(MAXN);
  inline static Array<i64> dp = make_array<i64>(MAXN);
  inline static Array<Array<int>> stack = make_array<int>(MAXN, 3);
  inline static int u = {};
  inline static int status = {};
  inline static int e = {};
  inline static int stacksize = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code08_Candy1() {}
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
  static void addEdge(int u, int v, int w) {
    (nxt[(++cntg)] = head[u]);
    (to[cntg] = v);
    (weight[cntg] = w);
    (head[u] = cntg);
  }
  static void tarjan1(int u) {
    (dfn[u] = (low[u] = (++cntd)));
    (sta[(++top)] = u);
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      int v = to[e];
      if ((dfn[v] == 0)) {
        Code08_Candy1::tarjan1(v);
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
    Code08_Candy1::push(node, (-1), (-1));
    int v = {};
    while ((stacksize > 0)) {
      Code08_Candy1::pop();
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
          Code08_Candy1::push(u, 0, e);
          Code08_Candy1::push(v, (-1), (-1));
        } else {
          Code08_Candy1::push(u, 1, e);
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
  static bool condense() {
    (cntg = 0);
    for (int i = 1; (i <= sccCnt); (i++)) {
      (head[i] = 0);
    }
    for (int i = 1; (i <= m); (i++)) {
      int scc1 = belong[a[i]];
      int scc2 = belong[b[i]];
      int w = c[i];
      if (((scc1 == scc2) && (w > 0))) {
        return false;
      }
      if ((scc1 != scc2)) {
        (indegree[scc2]++);
        Code08_Candy1::addEdge(scc1, scc2, w);
      }
    }
    return true;
  }
  static i64 dpOnDAG() {
    for (int u = sccCnt; (u > 0); (u--)) {
      if ((indegree[u] == 0)) {
        (dp[u] = 1);
      }
      for (int e = head[u]; (e > 0); (e = nxt[e])) {
        int v = to[e];
        int w = weight[e];
        (dp[v] = jmax(dp[v], (dp[u] + w)));
      }
    }
    i64 ans = 0;
    for (int i = 1; (i <= sccCnt); (i++)) {
      (ans += (dp[i] * sccSiz[i]));
    }
    return ans;
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (k = in.nextInt());
    (m = 0);
    {
      int i = 1;
      int op = {};
      int u = {};
      int v = {};
      for (; (i <= k); (i++)) {
        (op = in.nextInt());
        (u = in.nextInt());
        (v = in.nextInt());
        if ((op == 1)) {
          (a[(++m)] = u);
          (b[m] = v);
          (c[m] = 0);
          (a[(++m)] = v);
          (b[m] = u);
          (c[m] = 0);
        } else if ((op == 2)) {
          (a[(++m)] = u);
          (b[m] = v);
          (c[m] = 1);
        } else if ((op == 3)) {
          (a[(++m)] = v);
          (b[m] = u);
          (c[m] = 0);
        } else if ((op == 4)) {
          (a[(++m)] = v);
          (b[m] = u);
          (c[m] = 1);
        } else {
          (a[(++m)] = u);
          (b[m] = v);
          (c[m] = 0);
        }
      }
    }
    for (int i = 1; (i <= m); (i++)) {
      Code08_Candy1::addEdge(a[i], b[i], c[i]);
    }
    for (int i = 1; (i <= n); (i++)) {
      if ((dfn[i] == 0)) {
        Code08_Candy1::tarjan2(i);
      }
    }
    bool check = Code08_Candy1::condense();
    if ((!check)) {
      out.println((-1));
    } else {
      i64 ans = Code08_Candy1::dpOnDAG();
      out.println(ans);
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code08_Candy1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 糖果，java版
// 一共n个人，每人至少得到一个糖果，一共k条要求，要求有5种类型
// 1 u v : u的糖果 == v的糖果    2 u v : u的糖果 < v的糖果
// 3 u v : u的糖果 >= v的糖果    4 u v : u的糖果 > v的糖果
// 5 u v : u的糖果 <= v的糖果
// 如果无法满足所有要求打印-1，否则打印需要的最少糖果数
// 1 <= n、k <= 10^5
// 测试链接 : https://www.luogu.com.cn/problem/P3275
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 迭代版需要的栈，讲解118讲了递归改迭代的技巧
        // 递归版，java会爆栈，C++可以通过
        // 迭代版
                                // tarjan1(i);
        // 读写工具类
*/

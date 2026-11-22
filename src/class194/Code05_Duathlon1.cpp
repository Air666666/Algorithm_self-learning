// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P4630

// Source: src/class194/Code05_Duathlon1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code05_Duathlon1 {
  inline static int MAXN = 100001;
  inline static int MAXM = 200001;
  inline static int n = {};
  inline static int m = {};
  inline static int cntn = {};
  inline static Array<int> head1 = make_array<int>(MAXN);
  inline static Array<int> next1 = make_array<int>(jshl(MAXM, 1));
  inline static Array<int> to1 = make_array<int>(jshl(MAXM, 1));
  inline static int cnt1 = {};
  inline static Array<int> head2 = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> next2 = make_array<int>(jshl(MAXM, 2));
  inline static Array<int> to2 = make_array<int>(jshl(MAXM, 2));
  inline static int cnt2 = {};
  inline static Array<int> dfn = make_array<int>(MAXN);
  inline static Array<int> low = make_array<int>(MAXN);
  inline static int cntd = {};
  inline static Array<int> sta = make_array<int>(MAXN);
  inline static int top = {};
  inline static Array<int> deg = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> siz = make_array<int>(jshl(MAXN, 1));
  inline static int total = {};
  inline static i64 ans = {};
  inline static Array<Array<int>> stack = make_array<int>(jshl(MAXN, 1), 4);
  inline static int u = {};
  inline static int status = {};
  inline static int fa = {};
  inline static int e = {};
  inline static int stacksize = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code05_Duathlon1() {}
  static void push(int u, int status, int fa, int e) {
    (stack[stacksize][0] = u);
    (stack[stacksize][1] = status);
    (stack[stacksize][2] = fa);
    (stack[stacksize][3] = e);
    (stacksize++);
  }
  static void pop() {
    (stacksize--);
    (u = stack[stacksize][0]);
    (status = stack[stacksize][1]);
    (fa = stack[stacksize][2]);
    (e = stack[stacksize][3]);
  }
  static void addEdge1(int u, int v) {
    (next1[(++cnt1)] = head1[u]);
    (to1[cnt1] = v);
    (head1[u] = cnt1);
  }
  static void addEdge2(int u, int v) {
    (next2[(++cnt2)] = head2[u]);
    (to2[cnt2] = v);
    (head2[u] = cnt2);
  }
  static void tarjan1(int u) {
    (total++);
    (dfn[u] = (low[u] = (++cntd)));
    (sta[(++top)] = u);
    for (int e = head1[u]; (e > 0); (e = next1[e])) {
      int v = to1[e];
      if ((dfn[v] == 0)) {
        Code05_Duathlon1::tarjan1(v);
        (low[u] = jmin(low[u], low[v]));
        if ((low[v] >= dfn[u])) {
          (cntn++);
          Code05_Duathlon1::addEdge2(cntn, u);
          Code05_Duathlon1::addEdge2(u, cntn);
          (deg[cntn]++);
          int pop = {};
          do {
            (pop = sta[(top--)]);
            Code05_Duathlon1::addEdge2(cntn, pop);
            Code05_Duathlon1::addEdge2(pop, cntn);
            (deg[cntn]++);
          } while ((pop != v));
        }
      } else {
        (low[u] = jmin(low[u], dfn[v]));
      }
    }
  }
  static void tarjan2(int node) {
    (stacksize = 0);
    Code05_Duathlon1::push(node, (-1), 0, (-1));
    int v = {};
    while ((stacksize > 0)) {
      Code05_Duathlon1::pop();
      if ((status == (-1))) {
        (total++);
        (dfn[u] = (low[u] = (++cntd)));
        (sta[(++top)] = u);
        (e = head1[u]);
      } else {
        (v = to1[e]);
        if ((status == 0)) {
          (low[u] = jmin(low[u], low[v]));
          if ((low[v] >= dfn[u])) {
            (cntn++);
            Code05_Duathlon1::addEdge2(cntn, u);
            Code05_Duathlon1::addEdge2(u, cntn);
            (deg[cntn]++);
            int pop = {};
            do {
              (pop = sta[(top--)]);
              Code05_Duathlon1::addEdge2(cntn, pop);
              Code05_Duathlon1::addEdge2(pop, cntn);
              (deg[cntn]++);
            } while ((pop != v));
          }
        } else {
          (low[u] = jmin(low[u], dfn[v]));
        }
        (e = next1[e]);
      }
      if ((e != 0)) {
        (v = to1[e]);
        if ((dfn[v] == 0)) {
          Code05_Duathlon1::push(u, 0, 0, e);
          Code05_Duathlon1::push(v, (-1), 0, (-1));
        } else {
          Code05_Duathlon1::push(u, 1, 0, e);
        }
      }
    }
  }
  static void dpOnTree1(int u, int fa) {
    for (int e = head2[u]; (e > 0); (e = next2[e])) {
      int v = to2[e];
      if ((v != fa)) {
        Code05_Duathlon1::dpOnTree1(v, u);
        if ((u <= n)) {
          (ans += ((1LL * siz[v]) * ((total - siz[v]) - 1)));
        } else {
          (ans += (((1LL * siz[v]) * (deg[u] - 2)) * (total - siz[v])));
        }
        (siz[u] += siz[v]);
      }
    }
    (siz[u] += ((u <= n) ? 1 : 0));
    if ((u <= n)) {
      (ans += ((1LL * (siz[u] - 1)) * (total - siz[u])));
    } else {
      (ans += (((1LL * siz[u]) * (deg[u] - 2)) * (total - siz[u])));
    }
  }
  static void dpOnTree2(int cur, int father) {
    (stacksize = 0);
    Code05_Duathlon1::push(cur, 0, fa, (-1));
    while ((stacksize > 0)) {
      Code05_Duathlon1::pop();
      if ((e == (-1))) {
        (e = head2[u]);
      } else {
        (e = next2[e]);
      }
      if ((e != 0)) {
        Code05_Duathlon1::push(u, 0, fa, e);
        if ((to2[e] != fa)) {
          Code05_Duathlon1::push(to2[e], 0, u, (-1));
        }
      } else {
        for (int ei = head2[u]; (ei > 0); (ei = next2[ei])) {
          int v = to2[ei];
          if ((v != fa)) {
            if ((u <= n)) {
              (ans += ((1LL * siz[v]) * ((total - siz[v]) - 1)));
            } else {
              (ans += (((1LL * siz[v]) * (deg[u] - 2)) * (total - siz[v])));
            }
            (siz[u] += siz[v]);
          }
        }
        (siz[u] += ((u <= n) ? 1 : 0));
        if ((u <= n)) {
          (ans += ((1LL * (siz[u] - 1)) * (total - siz[u])));
        } else {
          (ans += (((1LL * siz[u]) * (deg[u] - 2)) * (total - siz[u])));
        }
      }
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (m = in.nextInt());
    (cntn = n);
    {
      int i = 1;
      int u = {};
      int v = {};
      for (; (i <= m); (i++)) {
        (u = in.nextInt());
        (v = in.nextInt());
        Code05_Duathlon1::addEdge1(u, v);
        Code05_Duathlon1::addEdge1(v, u);
      }
    }
    for (int i = 1; (i <= n); (i++)) {
      if ((dfn[i] == 0)) {
        (total = 0);
        Code05_Duathlon1::tarjan2(i);
        Code05_Duathlon1::dpOnTree2(i, 0);
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
  Code05_Duathlon1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 铁人两项，java版
// 给定一张无向图，一共n个点、m条边，图中可能存在多个连通区
// 有效的点对三元组(a, b, c)，首先要求a、b、c是不同的点
// 其次要求存在一条从a出发，经过b，最终到达c的路径，沿途无重复节点
// 打印有效的点对三元组的数量
// 1 <= n <= 10^5
// 1 <= m <= 2 * 10^5
// 测试链接 : https://www.luogu.com.cn/problem/P4630
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 方点才有deg，点双连通分量的节点数，也就是度
        // dfs过程中，子树中的圆点数量
        // 当前连通区的总节点数
        // 答案
        // 迭代版需要的栈，讲解118讲了递归改迭代的技巧
        // 递归版
        // 迭代版
        // 递归版
        // 迭代版
                                // tarjan1(i);
                                // dpOnTree1(i, 0);
        // 读写工具类
*/

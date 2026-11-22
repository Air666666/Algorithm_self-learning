// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P3469

// Source: src/class194/Code04_Blockade1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_Blockade1 {
  inline static int MAXN = 100001;
  inline static int MAXM = 500001;
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
  inline static Array<int> siz = make_array<int>(jshl(MAXN, 1));
  inline static Array<i64> ans = make_array<i64>(MAXN);
  inline static Array<Array<int>> stack = make_array<int>(jshl(MAXN, 1), 4);
  inline static int u = {};
  inline static int status = {};
  inline static int fa = {};
  inline static int e = {};
  inline static int stacksize = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_Blockade1() {}
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
    (dfn[u] = (low[u] = (++cntd)));
    (sta[(++top)] = u);
    for (int e = head1[u]; (e > 0); (e = next1[e])) {
      int v = to1[e];
      if ((dfn[v] == 0)) {
        Code04_Blockade1::tarjan1(v);
        (low[u] = jmin(low[u], low[v]));
        if ((low[v] >= dfn[u])) {
          (cntn++);
          Code04_Blockade1::addEdge2(cntn, u);
          Code04_Blockade1::addEdge2(u, cntn);
          int pop = {};
          do {
            (pop = sta[(top--)]);
            Code04_Blockade1::addEdge2(cntn, pop);
            Code04_Blockade1::addEdge2(pop, cntn);
          } while ((pop != v));
        }
      } else {
        (low[u] = jmin(low[u], dfn[v]));
      }
    }
  }
  static void tarjan2(int node) {
    (stacksize = 0);
    Code04_Blockade1::push(node, (-1), 0, (-1));
    int v = {};
    while ((stacksize > 0)) {
      Code04_Blockade1::pop();
      if ((status == (-1))) {
        (dfn[u] = (low[u] = (++cntd)));
        (sta[(++top)] = u);
        (e = head1[u]);
      } else {
        (v = to1[e]);
        if ((status == 0)) {
          (low[u] = jmin(low[u], low[v]));
          if ((low[v] >= dfn[u])) {
            (cntn++);
            Code04_Blockade1::addEdge2(cntn, u);
            Code04_Blockade1::addEdge2(u, cntn);
            int pop = {};
            do {
              (pop = sta[(top--)]);
              Code04_Blockade1::addEdge2(cntn, pop);
              Code04_Blockade1::addEdge2(pop, cntn);
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
          Code04_Blockade1::push(u, 0, 0, e);
          Code04_Blockade1::push(v, (-1), 0, (-1));
        } else {
          Code04_Blockade1::push(u, 1, 0, e);
        }
      }
    }
  }
  static void dpOnTree1(int u, int fa) {
    for (int e = head2[u]; (e > 0); (e = next2[e])) {
      int v = to2[e];
      if ((v != fa)) {
        Code04_Blockade1::dpOnTree1(v, u);
        if ((u <= n)) {
          (ans[u] += ((1LL * siz[v]) * ((n - siz[v]) - 1)));
        }
        (siz[u] += siz[v]);
      }
    }
    (siz[u] += ((u <= n) ? 1 : 0));
    if ((u <= n)) {
      (ans[u] += ((1LL * (n - siz[u])) * (siz[u] - 1)));
      (ans[u] += (2LL * (n - 1)));
    }
  }
  static void dpOnTree2(int cur, int father) {
    (stacksize = 0);
    Code04_Blockade1::push(cur, 0, fa, (-1));
    while ((stacksize > 0)) {
      Code04_Blockade1::pop();
      if ((e == (-1))) {
        (e = head2[u]);
      } else {
        (e = next2[e]);
      }
      if ((e != 0)) {
        Code04_Blockade1::push(u, 0, fa, e);
        if ((to2[e] != fa)) {
          Code04_Blockade1::push(to2[e], 0, u, (-1));
        }
      } else {
        for (int ei = head2[u]; (ei > 0); (ei = next2[ei])) {
          int v = to2[ei];
          if ((v != fa)) {
            if ((u <= n)) {
              (ans[u] += ((1LL * siz[v]) * ((n - siz[v]) - 1)));
            }
            (siz[u] += siz[v]);
          }
        }
        (siz[u] += ((u <= n) ? 1 : 0));
        if ((u <= n)) {
          (ans[u] += ((1LL * (n - siz[u])) * (siz[u] - 1)));
          (ans[u] += (2LL * (n - 1)));
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
        Code04_Blockade1::addEdge1(u, v);
        Code04_Blockade1::addEdge1(v, u);
      }
    }
    Code04_Blockade1::tarjan2(1);
    Code04_Blockade1::dpOnTree2(1, 0);
    for (int i = 1; (i <= n); (i++)) {
      out.println(ans[i]);
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code04_Blockade1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 城市阻断，java版
// 给定一张无向图，一共n个点、m条边，所有点保证连通
// 对每个点i，打印如下的答案
// 节点i相连的边去掉以后，无向图有多少点对(x, y)，x和y不连通
// 注意(x, y)和(y, x)是不同点对
// 删掉和i相连的边，但是节点i本身不删掉，要参与点对数量的计算
// 1 <= n <= 10^5
// 1 <= m <= 5 * 10^5
// 测试链接 : https://www.luogu.com.cn/problem/P3469
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // dfs过程中，子树中的圆点数量
        // 每个原图中的点，如果把相邻的边删掉，所统计的答案
        // 迭代版需要的栈，讲解118讲了递归改迭代的技巧
        // 递归版
        // 迭代版
        // 递归版
        // 迭代版
                // tarjan1(1);
                // dpOnTree1(1, 0);
        // 读写工具类
*/

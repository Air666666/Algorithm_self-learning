// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P3854

// Source: src/class194/Code02_NetworkDamage1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_NetworkDamage1 {
  inline static int MAXN = 20001;
  inline static int MAXM = 100001;
  inline static int MAXP = 18;
  inline static int n = {};
  inline static int m = {};
  inline static int q = {};
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
  inline static Array<int> dep = make_array<int>(jshl(MAXN, 1));
  inline static Array<Array<int>> stjump = make_array<int>(jshl(MAXN, 1), MAXP);
  inline static Array<Array<int>> stack = make_array<int>(jshl(MAXN, 1), 3);
  inline static int u = {};
  inline static int status = {};
  inline static int e = {};
  inline static int stacksize = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_NetworkDamage1() {}
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
        Code02_NetworkDamage1::tarjan1(v);
        (low[u] = jmin(low[u], low[v]));
        if ((low[v] >= dfn[u])) {
          (cntn++);
          Code02_NetworkDamage1::addEdge2(cntn, u);
          Code02_NetworkDamage1::addEdge2(u, cntn);
          int pop = {};
          do {
            (pop = sta[(top--)]);
            Code02_NetworkDamage1::addEdge2(cntn, pop);
            Code02_NetworkDamage1::addEdge2(pop, cntn);
          } while ((pop != v));
        }
      } else {
        (low[u] = jmin(low[u], dfn[v]));
      }
    }
  }
  static void tarjan2(int node) {
    (stacksize = 0);
    Code02_NetworkDamage1::push(node, (-1), (-1));
    int v = {};
    while ((stacksize > 0)) {
      Code02_NetworkDamage1::pop();
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
            Code02_NetworkDamage1::addEdge2(cntn, u);
            Code02_NetworkDamage1::addEdge2(u, cntn);
            int pop = {};
            do {
              (pop = sta[(top--)]);
              Code02_NetworkDamage1::addEdge2(cntn, pop);
              Code02_NetworkDamage1::addEdge2(pop, cntn);
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
          Code02_NetworkDamage1::push(u, 0, e);
          Code02_NetworkDamage1::push(v, (-1), (-1));
        } else {
          Code02_NetworkDamage1::push(u, 1, e);
        }
      }
    }
  }
  static void dfs(int u, int fa) {
    (dep[u] = (dep[fa] + 1));
    (stjump[u][0] = fa);
    for (int p = 1; (p < MAXP); (p++)) {
      (stjump[u][p] = stjump[stjump[u][(p - 1)]][(p - 1)]);
    }
    for (int e = head2[u]; (e > 0); (e = next2[e])) {
      int v = to2[e];
      if ((v != fa)) {
        Code02_NetworkDamage1::dfs(v, u);
      }
    }
  }
  static int getLca(int x, int y) {
    if ((dep[x] < dep[y])) {
      int tmp = x;
      (x = y);
      (y = tmp);
    }
    for (int p = (MAXP - 1); (p >= 0); (p--)) {
      if ((dep[stjump[x][p]] >= dep[y])) {
        (x = stjump[x][p]);
      }
    }
    if ((x == y)) {
      return x;
    }
    for (int p = (MAXP - 1); (p >= 0); (p--)) {
      if ((stjump[x][p] != stjump[y][p])) {
        (x = stjump[x][p]);
        (y = stjump[y][p]);
      }
    }
    return stjump[x][0];
  }
  static int getDist(int x, int y) {
    return ((dep[x] + dep[y]) - (2 * dep[Code02_NetworkDamage1::getLca(x, y)]));
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
        Code02_NetworkDamage1::addEdge1(u, v);
        Code02_NetworkDamage1::addEdge1(v, u);
      }
    }
    Code02_NetworkDamage1::tarjan2(1);
    Code02_NetworkDamage1::dfs(1, 0);
    (q = in.nextInt());
    {
      int i = 1;
      int x = {};
      int y = {};
      int z = {};
      for (; (i <= q); (i++)) {
        (x = in.nextInt());
        (y = in.nextInt());
        (z = in.nextInt());
        if ([&]() {
              auto jleft = Code02_NetworkDamage1::getDist(x, y);
              auto jright = [&]() {
                auto jleft = Code02_NetworkDamage1::getDist(x, z);
                auto jright = Code02_NetworkDamage1::getDist(y, z);
                return (jleft + jright);
              }();
              return (jleft == jright);
            }()) {
          out.println(String(u"yes"));
        } else {
          out.println(String(u"no"));
        }
      }
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code02_NetworkDamage1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 通讯网破坏，java版
// 给定一张无向图，一共n个点、m条边，所有点保证连通
// 一共q条查询，格式 x y z : 如果删除点z，打印x和y是否断连
// 1 <= n <= 2 * 10^4
// 1 <= m <= 10 ^ 5
// 1 <= q <= 10 ^ 5
// 测试链接 : https://www.luogu.com.cn/problem/P3854
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 迭代版需要的栈，讲解118讲了递归改迭代的技巧
        // 递归版
        // 迭代版
        // 圆方树上建立深度和倍增表
        // 圆方树上任意两点的最低公共祖先
        // 圆方树上任意两点间的距离
                // tarjan1(1);
        // 读写工具类
*/

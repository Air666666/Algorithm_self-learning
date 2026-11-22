// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P8867

// Source: src/class192/Code07_MilitaryCamp1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code07_MilitaryCamp1 {
  inline static int MAXN = 500001;
  inline static int MAXM = 1000001;
  inline static int MOD = 1000000007;
  inline static int n = {};
  inline static int m = {};
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
  inline static Array<int> ebccSiz = make_array<int>(MAXN);
  inline static int ebccCnt = {};
  inline static Array<i64> power2 = make_array<i64>(MAXM);
  inline static Array<i64> dp = make_array<i64>(MAXN);
  inline static Array<int> bridge = make_array<int>(MAXN);
  inline static Array<Array<int>> stack = make_array<int>(MAXN, 5);
  inline static int u = {};
  inline static int preEdge = {};
  inline static int status = {};
  inline static int fa = {};
  inline static int e = {};
  inline static int stacksize = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code07_MilitaryCamp1() {}
  static void push(int u, int preEdge, int status, int fa, int e) {
    (stack[stacksize][0] = u);
    (stack[stacksize][1] = preEdge);
    (stack[stacksize][2] = status);
    (stack[stacksize][3] = fa);
    (stack[stacksize][4] = e);
    (stacksize++);
  }
  static void pop() {
    (stacksize--);
    (u = stack[stacksize][0]);
    (preEdge = stack[stacksize][1]);
    (status = stack[stacksize][2]);
    (fa = stack[stacksize][3]);
    (e = stack[stacksize][4]);
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
        Code07_MilitaryCamp1::tarjan1(v, e);
        (low[u] = jmin(low[u], low[v]));
      } else {
        (low[u] = jmin(low[u], dfn[v]));
      }
    }
    if ((dfn[u] == low[u])) {
      (ebccCnt++);
      (ebccSiz[ebccCnt] = 0);
      int pop = {};
      do {
        (pop = sta[(top--)]);
        (belong[pop] = ebccCnt);
        (ebccSiz[ebccCnt]++);
      } while ((pop != u));
    }
  }
  static void tarjan2(int node, int pree) {
    (stacksize = 0);
    Code07_MilitaryCamp1::push(node, pree, (-1), 0, (-1));
    int v = {};
    while ((stacksize > 0)) {
      Code07_MilitaryCamp1::pop();
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
          Code07_MilitaryCamp1::push(u, preEdge, 0, 0, e);
          Code07_MilitaryCamp1::push(v, e, (-1), 0, (-1));
        } else {
          Code07_MilitaryCamp1::push(u, preEdge, 1, 0, e);
        }
      } else {
        if ((dfn[u] == low[u])) {
          (ebccCnt++);
          (ebccSiz[ebccCnt] = 0);
          int pop = {};
          do {
            (pop = sta[(top--)]);
            (belong[pop] = ebccCnt);
            (ebccSiz[ebccCnt]++);
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
        Code07_MilitaryCamp1::addEdge(ebcc1, ebcc2);
        Code07_MilitaryCamp1::addEdge(ebcc2, ebcc1);
      }
    }
  }
  static void dpOnTree1(int u, int fa) {
    (dp[u] = (power2[ebccSiz[u]] - 1));
    (bridge[u] = 0);
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      int v = to[e];
      if ((v != fa)) {
        Code07_MilitaryCamp1::dpOnTree1(v, u);
        (dp[u] = jrem(((jrem(((dp[u] * power2[bridge[v]]) * 2), MOD) +
                        jrem((power2[bridge[u]] * dp[v]), MOD)) +
                       jrem((dp[u] * dp[v]), MOD)),
                      MOD));
        (bridge[u] += (bridge[v] + 1));
      }
    }
  }
  static void dpOnTree2(int cur, int father) {
    (stacksize = 0);
    Code07_MilitaryCamp1::push(cur, 0, 0, father, (-1));
    while ((stacksize > 0)) {
      Code07_MilitaryCamp1::pop();
      if ((e == (-1))) {
        (dp[u] = (power2[ebccSiz[u]] - 1));
        (bridge[u] = 0);
        (e = head[u]);
      } else {
        (e = nxt[e]);
      }
      if ((e != 0)) {
        Code07_MilitaryCamp1::push(u, 0, 0, fa, e);
        int v = to[e];
        if ((v != fa)) {
          Code07_MilitaryCamp1::push(v, 0, 0, u, (-1));
        }
      } else {
        for (int ei = head[u]; (ei > 0); (ei = nxt[ei])) {
          int v = to[ei];
          if ((v != fa)) {
            (dp[u] = jrem(((jrem((dp[u] * power2[(bridge[v] + 1)]), MOD) +
                            jrem((power2[bridge[u]] * dp[v]), MOD)) +
                           jrem((dp[u] * dp[v]), MOD)),
                          MOD));
            (bridge[u] += (bridge[v] + 1));
          }
        }
      }
    }
  }
  static i64 compute() {
    (power2[0] = 1);
    for (int i = 1; (i <= m); (i++)) {
      (power2[i] = jrem((power2[(i - 1)] * 2), MOD));
    }
    Code07_MilitaryCamp1::dpOnTree2(1, 0);
    int total = bridge[1];
    i64 ans = dp[1];
    for (int i = 2; (i <= ebccCnt); (i++)) {
      (ans =
           jrem((ans + jrem((dp[i] * power2[((total - bridge[i]) - 1)]), MOD)),
                MOD));
    }
    (ans = jrem((ans * power2[(m - total)]), MOD));
    return ans;
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (cntg = 1);
    (n = in.nextInt());
    (m = in.nextInt());
    for (int i = 1; (i <= m); (i++)) {
      (a[i] = in.nextInt());
      (b[i] = in.nextInt());
      Code07_MilitaryCamp1::addEdge(a[i], b[i]);
      Code07_MilitaryCamp1::addEdge(b[i], a[i]);
    }
    Code07_MilitaryCamp1::tarjan2(1, 0);
    Code07_MilitaryCamp1::condense();
    i64 ans = Code07_MilitaryCamp1::compute();
    out.println(ans);
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code07_MilitaryCamp1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 建造军营，java版
// 一共n个城市、m条道路，道路是无向边，保证所有城市连通
// 你可以选择任何城市，在城市内建造军营，至少要选一座城市
// 你可以选择任何道路，在道路上派兵看守，也可以一条都不选
// 选择的城市集合 + 选择的道路集合，被认为是一种方案
// 敌人会袭击任意一条道路，如果有兵看守就不会被切断，否则会被切断
// 敌人袭击之后，如果造成任意两座军营无法连通，那么算你失败
// 确保不会失败的情况下，计算方案数，答案对 1000000007 取余
// 1 <= n <= 5 * 10^5
// 1 <= m <= 10^6
// 测试链接 : https://www.luogu.com.cn/problem/P8867
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // power2[i] = 2的i次方
        // dp[u] : 子树u上，原图的点可以考虑造军营，至少造一个
        //         从所造军营到u的割边都派兵，其他割边随意，这样的方案数
        // bridge[u] : 子树u上割边的数量
        // 迭代版需要的栈，讲解118讲了递归改迭代的技巧
        // 递归版
        // 迭代版
        // 递归版
                // 情况1，不考虑下方的节点，在u自己的边双连通分量里，选点造军营
                                // 情况2，之前部分的方案数 *
子树v完全不造军营时割边的自由发挥 * u到v的割边自由发挥
                                // 情况3，之前部分完全不造军营时割边的自由发挥 *
子树v的方案数
                                // 情况4，之前部分的方案数 * 子树v的方案数
        // 迭代版
                // dpOnTree1(1, 0);
                // tarjan1(1, 0);
        // 读写工具类
*/

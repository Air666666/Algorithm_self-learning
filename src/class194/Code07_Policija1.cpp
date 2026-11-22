// Source: src/class194/Code07_Policija1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code07_Policija1 {
  inline static int MAXN = 100001;
  inline static int MAXM = 500001;
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
  inline static int cnts = {};
  inline static JMap<i64, int> cutMap = JMap<i64, int>();
  inline static Array<int> fa = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> dep = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> siz = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> son = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> top = make_array<int>(jshl(MAXN, 1));
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code07_Policija1() {}
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
  static void addCut(int x, int y, int cut) {
    int a = jmin(x, y);
    int b = jmax(x, y);
    cutMap.put((jshl(static_cast<i64>(a), 32) | b), cut);
  }
  static int getCut(int x, int y) {
    int a = jmin(x, y);
    int b = jmax(x, y);
    Box<int> ans = cutMap.get((jshl(static_cast<i64>(a), 32) | b));
    return ((ans == nullptr) ? unbox(0) : unbox(ans));
  }
  static void tarjan(int u, int preEdge) {
    (dfn[u] = (low[u] = (++cntd)));
    (sta[(++cnts)] = u);
    for (int e = head1[u]; (e > 0); (e = next1[e])) {
      if (((e ^ 1) == preEdge)) {
        continue;
      }
      int v = to1[e];
      if ((dfn[v] == 0)) {
        Code07_Policija1::tarjan(v, e);
        (low[u] = jmin(low[u], low[v]));
        if ((low[v] >= dfn[u])) {
          (cntn++);
          if ((low[v] > dfn[u])) {
            Code07_Policija1::addCut(u, v, cntn);
          }
          Code07_Policija1::addEdge2(cntn, u);
          Code07_Policija1::addEdge2(u, cntn);
          int pop = {};
          do {
            (pop = sta[(cnts--)]);
            Code07_Policija1::addEdge2(cntn, pop);
            Code07_Policija1::addEdge2(pop, cntn);
          } while ((pop != v));
        }
      } else {
        (low[u] = jmin(low[u], dfn[v]));
      }
    }
  }
  static void dfs1(int u, int f) {
    (fa[u] = f);
    (dep[u] = (dep[f] + 1));
    (siz[u] = 1);
    {
      int e = head2[u];
      int v = {};
      for (; (e > 0); (e = next2[e])) {
        (v = to2[e]);
        if ((v != f)) {
          Code07_Policija1::dfs1(v, u);
          (siz[u] += siz[v]);
          if (((son[u] == 0) || (siz[son[u]] < siz[v]))) {
            (son[u] = v);
          }
        }
      }
    }
  }
  static void dfs2(int u, int t) {
    (top[u] = t);
    if ((son[u] == 0)) {
      return;
    }
    Code07_Policija1::dfs2(son[u], t);
    {
      int e = head2[u];
      int v = {};
      for (; (e > 0); (e = next2[e])) {
        (v = to2[e]);
        if (((v != fa[u]) && (v != son[u]))) {
          Code07_Policija1::dfs2(v, v);
        }
      }
    }
  }
  static bool mustPass(int a, int b, int c) {
    while ((top[a] != top[b])) {
      if ((dep[top[a]] < dep[top[b]])) {
        int tmp = a;
        (a = b);
        (b = tmp);
      }
      if (((top[c] == top[a]) && (dep[c] <= dep[a]))) {
        return true;
      }
      (a = fa[top[a]]);
    }
    if ((dep[a] < dep[b])) {
      int tmp = a;
      (a = b);
      (b = tmp);
    }
    return (((top[a] == top[c]) && (dep[b] <= dep[c])) && (dep[c] <= dep[a]));
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (m = in.nextInt());
    (cntn = n);
    (cnt1 = 1);
    {
      int i = 1;
      int u = {};
      int v = {};
      for (; (i <= m); (i++)) {
        (u = in.nextInt());
        (v = in.nextInt());
        Code07_Policija1::addEdge1(u, v);
        Code07_Policija1::addEdge1(v, u);
      }
    }
    Code07_Policija1::tarjan(1, 0);
    Code07_Policija1::dfs1(1, 0);
    Code07_Policija1::dfs2(1, 1);
    (q = in.nextInt());
    {
      int i = 1;
      int op = {};
      int a = {};
      int b = {};
      int c = {};
      int d = {};
      for (; (i <= q); (i++)) {
        (op = in.nextInt());
        if ((op == 1)) {
          (a = in.nextInt());
          (b = in.nextInt());
          (c = in.nextInt());
          (d = in.nextInt());
          int cut = Code07_Policija1::getCut(c, d);
          if ((cut == 0)) {
            out.println(String(u"yes"));
          } else {
            out.println((Code07_Policija1::mustPass(a, b, cut)
                             ? String(u"no")
                             : String(u"yes")));
          }
        } else {
          (a = in.nextInt());
          (b = in.nextInt());
          (c = in.nextInt());
          out.println((Code07_Policija1::mustPass(a, b, c) ? String(u"no")
                                                           : String(u"yes")));
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
  Code07_Policija1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 警察，java版
// 给定一张无向图，一共n个点、m条边，所有点保证连通并且无重边
// 一共q条查询，每条查询是如下两种类型中的一种
// 查询 1 a b c d : 已知c和d之间有边，如果删去这条边，打印a和b是否连通
// 查询 2 a b c   : 如果删除点c，打印a和b是否连通
// 1 <= n <= 10^5
// 1 <= m <= 5 * 10^5
// 1 <= q <= 3 * 10^5
// 测试链接 : https://www.luogu.com.cn/problem/P4334
// 提交以下的code，提交时请把类名改成"Main"
// 本题卡常导致java的实现无法通过，很多递归函数索性也不改迭代了
// 想通过用C++实现，本节课Code07_Policija2文件就是C++的实现
// 两个版本的逻辑完全一样，C++版本可以通过所有测试
        // 读写工具类
*/

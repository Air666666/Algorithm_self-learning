// Source: src/class202/Code04_TreeDyeing1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_TreeDyeing1 {
  inline static int MAXN = 100001;
  inline static int n = {};
  inline static int m = {};
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> nxt = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> to = make_array<int>(jshl(MAXN, 1));
  inline static int cntg = {};
  inline static Array<int> pa = make_array<int>(MAXN);
  inline static Array<int> dep = make_array<int>(MAXN);
  inline static Array<int> siz = make_array<int>(MAXN);
  inline static Array<int> son = make_array<int>(MAXN);
  inline static Array<int> top = make_array<int>(MAXN);
  inline static Array<int> dfn = make_array<int>(MAXN);
  inline static Array<int> seg = make_array<int>(MAXN);
  inline static int cntd = {};
  inline static Array<int> fa = make_array<int>(MAXN);
  inline static Array<int> ls = make_array<int>(MAXN);
  inline static Array<int> rs = make_array<int>(MAXN);
  inline static Array<int> mostl = make_array<int>(MAXN);
  inline static Array<int> maxVal = make_array<int>(jshl(MAXN, 2));
  inline static Array<int> addTag = make_array<int>(jshl(MAXN, 2));
  inline static Array<int> stau = make_array<int>(MAXN);
  inline static Array<int> staf = make_array<int>(MAXN);
  inline static Array<int> stat = make_array<int>(MAXN);
  inline static Array<int> stae = make_array<int>(MAXN);
  inline static int stacksize = {};
  inline static int u = {};
  inline static int f = {};
  inline static int t = {};
  inline static int e = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_TreeDyeing1() {}
  static void push(int u, int f, int t, int e) {
    (stau[stacksize] = u);
    (staf[stacksize] = f);
    (stat[stacksize] = t);
    (stae[stacksize] = e);
    (stacksize++);
  }
  static void pop() {
    (--stacksize);
    (u = stau[stacksize]);
    (f = staf[stacksize]);
    (t = stat[stacksize]);
    (e = stae[stacksize]);
  }
  static void addEdge(int u, int v) {
    (nxt[(++cntg)] = head[u]);
    (to[cntg] = v);
    (head[u] = cntg);
  }
  static void dfs1(int u, int f) {
    (pa[u] = f);
    (dep[u] = (dep[f] + 1));
    (siz[u] = 1);
    {
      int e = head[u];
      int v = {};
      for (; (e != 0); (e = nxt[e])) {
        (v = to[e]);
        if ((v != f)) {
          Code04_TreeDyeing1::dfs1(v, u);
          (siz[u] += siz[v]);
          if ((siz[v] > siz[son[u]])) {
            (son[u] = v);
          }
        }
      }
    }
  }
  static void dfs2(int u, int t) {
    (top[u] = t);
    (dfn[u] = (++cntd));
    (seg[cntd] = u);
    if ((son[u] != 0)) {
      Code04_TreeDyeing1::dfs2(son[u], t);
    }
    {
      int e = head[u];
      int v = {};
      for (; (e != 0); (e = nxt[e])) {
        (v = to[e]);
        if (((v != pa[u]) && (v != son[u]))) {
          Code04_TreeDyeing1::dfs2(v, v);
        }
      }
    }
  }
  static void dfs3(int cur, int father) {
    (stacksize = 0);
    Code04_TreeDyeing1::push(cur, father, 0, (-1));
    while ((stacksize > 0)) {
      Code04_TreeDyeing1::pop();
      if ((e == (-1))) {
        (pa[u] = f);
        (dep[u] = (dep[f] + 1));
        (siz[u] = 1);
        (e = head[u]);
      } else {
        (e = nxt[e]);
      }
      if ((e != 0)) {
        Code04_TreeDyeing1::push(u, f, 0, e);
        if ((to[e] != f)) {
          Code04_TreeDyeing1::push(to[e], u, 0, (-1));
        }
      } else {
        {
          int ei = head[u];
          int v = {};
          for (; (ei != 0); (ei = nxt[ei])) {
            (v = to[ei]);
            if ((v != f)) {
              (siz[u] += siz[v]);
              if ((siz[v] > siz[son[u]])) {
                (son[u] = v);
              }
            }
          }
        }
      }
    }
  }
  static void dfs4(int cur, int curt) {
    (stacksize = 0);
    Code04_TreeDyeing1::push(cur, 0, curt, (-1));
    while ((stacksize > 0)) {
      Code04_TreeDyeing1::pop();
      if ((e == (-1))) {
        (top[u] = t);
        (dfn[u] = (++cntd));
        (seg[cntd] = u);
        if ((son[u] != 0)) {
          Code04_TreeDyeing1::push(u, 0, t, (-2));
          Code04_TreeDyeing1::push(son[u], 0, t, (-1));
        }
        continue;
      } else if ((e == (-2))) {
        (e = head[u]);
      } else {
        (e = nxt[e]);
      }
      if ((e != 0)) {
        Code04_TreeDyeing1::push(u, 0, t, e);
        if (((to[e] != pa[u]) && (to[e] != son[u]))) {
          Code04_TreeDyeing1::push(to[e], 0, to[e], (-1));
        }
      }
    }
  }
  static int lca(int x, int y) {
    while ((top[x] != top[y])) {
      if ((dep[top[x]] < dep[top[y]])) {
        (y = pa[top[y]]);
      } else {
        (x = pa[top[x]]);
      }
    }
    return ((dep[x] < dep[y]) ? x : y);
  }
  static void up(int x) { (mostl[x] = ((ls[x] == 0) ? x : mostl[ls[x]])); }
  static bool isroot(int x) { return ((ls[fa[x]] != x) && (rs[fa[x]] != x)); }
  static int lr(int x) { return ((ls[fa[x]] == x) ? 0 : 1); }
  static void rotate(int x) {
    int f = fa[x];
    int g = fa[f];
    if ((Code04_TreeDyeing1::lr(x) == 0)) {
      (ls[f] = rs[x]);
      if ((ls[f] != 0)) {
        (fa[ls[f]] = f);
      }
      (rs[x] = f);
    } else {
      (rs[f] = ls[x]);
      if ((rs[f] != 0)) {
        (fa[rs[f]] = f);
      }
      (ls[x] = f);
    }
    if ((!Code04_TreeDyeing1::isroot(f))) {
      if ((Code04_TreeDyeing1::lr(f) == 0)) {
        (ls[g] = x);
      } else {
        (rs[g] = x);
      }
    }
    (fa[f] = x);
    (fa[x] = g);
    Code04_TreeDyeing1::up(f);
    Code04_TreeDyeing1::up(x);
  }
  static void splay(int x) {
    while ((!Code04_TreeDyeing1::isroot(x))) {
      int f = fa[x];
      if ((!Code04_TreeDyeing1::isroot(f))) {
        if ([&]() {
              auto jleft = Code04_TreeDyeing1::lr(x);
              auto jright = Code04_TreeDyeing1::lr(f);
              return (jleft == jright);
            }()) {
          Code04_TreeDyeing1::rotate(f);
        } else {
          Code04_TreeDyeing1::rotate(x);
        }
      }
      Code04_TreeDyeing1::rotate(x);
    }
  }
  static void build(int l, int r, int i) {
    if ((l == r)) {
      (maxVal[i] = dep[seg[l]]);
    } else {
      int mid = jshr((l + r), 1);
      Code04_TreeDyeing1::build(l, mid, jshl(i, 1));
      Code04_TreeDyeing1::build((mid + 1), r, (jshl(i, 1) | 1));
      Code04_TreeDyeing1::upSeg(i);
    }
  }
  static void upSeg(int i) {
    (maxVal[i] = jmax(maxVal[jshl(i, 1)], maxVal[(jshl(i, 1) | 1)]));
  }
  static void lazy(int i, int v) {
    (maxVal[i] += v);
    (addTag[i] += v);
  }
  static void down(int i) {
    if ((addTag[i] != 0)) {
      Code04_TreeDyeing1::lazy(jshl(i, 1), addTag[i]);
      Code04_TreeDyeing1::lazy((jshl(i, 1) | 1), addTag[i]);
      (addTag[i] = 0);
    }
  }
  static void add(int jobl, int jobr, int jobv, int l, int r, int i) {
    if (((jobl <= l) && (r <= jobr))) {
      Code04_TreeDyeing1::lazy(i, jobv);
    } else {
      Code04_TreeDyeing1::down(i);
      int mid = jshr((l + r), 1);
      if ((jobl <= mid)) {
        Code04_TreeDyeing1::add(jobl, jobr, jobv, l, mid, jshl(i, 1));
      }
      if ((jobr > mid)) {
        Code04_TreeDyeing1::add(jobl, jobr, jobv, (mid + 1), r,
                                (jshl(i, 1) | 1));
      }
      Code04_TreeDyeing1::upSeg(i);
    }
  }
  static int query(int jobl, int jobr, int l, int r, int i) {
    if (((jobl <= l) && (r <= jobr))) {
      return maxVal[i];
    }
    Code04_TreeDyeing1::down(i);
    int mid = jshr((l + r), 1);
    int ans = 0;
    if ((jobl <= mid)) {
      (ans = jmax(ans,
                  Code04_TreeDyeing1::query(jobl, jobr, l, mid, jshl(i, 1))));
    }
    if ((jobr > mid)) {
      (ans = jmax(ans, Code04_TreeDyeing1::query(jobl, jobr, (mid + 1), r,
                                                 (jshl(i, 1) | 1))));
    }
    return ans;
  }
  static void add(int x, int v) {
    Code04_TreeDyeing1::add(dfn[x], ((dfn[x] + siz[x]) - 1), v, 1, n, 1);
  }
  static void access(int x) {
    for (int y = 0; (x != 0); (y = x), (x = fa[x])) {
      Code04_TreeDyeing1::splay(x);
      if ((rs[x] != 0)) {
        Code04_TreeDyeing1::add(mostl[rs[x]], 1);
      }
      if ((y != 0)) {
        Code04_TreeDyeing1::add(mostl[y], (-1));
      }
      (rs[x] = y);
      Code04_TreeDyeing1::up(x);
    }
  }
  static int pathQuery(int x, int y) {
    int xylca = Code04_TreeDyeing1::lca(x, y);
    int a = Code04_TreeDyeing1::query(dfn[x], dfn[x], 1, n, 1);
    int b = Code04_TreeDyeing1::query(dfn[y], dfn[y], 1, n, 1);
    int c = Code04_TreeDyeing1::query(dfn[xylca], dfn[xylca], 1, n, 1);
    return (((a + b) - (2 * c)) + 1);
  }
  static int subtreeQuery(int x) {
    return Code04_TreeDyeing1::query(dfn[x], ((dfn[x] + siz[x]) - 1), 1, n, 1);
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (m = in.nextInt());
    {
      int i = 1;
      int x = {};
      int y = {};
      for (; (i < n); (i++)) {
        (x = in.nextInt());
        (y = in.nextInt());
        Code04_TreeDyeing1::addEdge(x, y);
        Code04_TreeDyeing1::addEdge(y, x);
      }
    }
    Code04_TreeDyeing1::dfs3(1, 0);
    Code04_TreeDyeing1::dfs4(1, 1);
    Code04_TreeDyeing1::build(1, n, 1);
    for (int i = 1; (i <= n); (i++)) {
      (fa[i] = pa[i]);
      (mostl[i] = i);
    }
    {
      int i = 1;
      int op = {};
      int x = {};
      int y = {};
      for (; (i <= m); (i++)) {
        (op = in.nextInt());
        (x = in.nextInt());
        if ((op == 1)) {
          Code04_TreeDyeing1::access(x);
        } else if ((op == 2)) {
          (y = in.nextInt());
          out.println(Code04_TreeDyeing1::pathQuery(x, y));
        } else {
          out.println(Code04_TreeDyeing1::subtreeQuery(x));
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
  Code04_TreeDyeing1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 树点涂色，java版
// 一共n个节点，所有节点组成一棵树，规定1号节点是根
// 初始所有节点的颜色都不同，路径中的颜色数量叫做路径权值
// 接下来有m条操作，操作有三种类型，具体格式如下
// 操作 1 x   : 根到点x的路径上，所有点染上一种没有用过的新颜色
// 操作 2 x y : 查询点x到点y的路径权值
// 操作 3 x   :
x为头的子树中选择一个点，希望该点到根节点的路径权值最大，打印这个值
// 1 <= n、m <= 10^5
// 测试链接 : https://www.luogu.com.cn/problem/P3703
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 树链剖分
        // 辅助splay
        // 线段树
        // 递归改迭代需要的栈
        // 递归版
        // 递归版
        // 树剖dfs1的迭代版
        // 树剖dfs2的迭代版
        // 以x为根的原树子树中，所有点的点权加上v
        // 根节点到x的路径，涂新颜色，改写access方法
//		dfs1(1, 0);
//		dfs2(1, 1);
        // 读写工具类
*/

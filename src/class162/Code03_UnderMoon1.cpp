// Source: src/class162/Code03_UnderMoon1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_UnderMoon1 {
  inline static int MAXN = 100001;
  inline static int n = {};
  inline static Array<Array<int>> arr = make_array<int>(MAXN, 3);
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> next = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> to = make_array<int>(jshl(MAXN, 1));
  inline static int cntg = 0;
  inline static Array<int> fa = make_array<int>(MAXN);
  inline static Array<int> dep = make_array<int>(MAXN);
  inline static Array<int> siz = make_array<int>(MAXN);
  inline static Array<int> son = make_array<int>(MAXN);
  inline static Array<int> top = make_array<int>(MAXN);
  inline static Array<int> dfn = make_array<int>(MAXN);
  inline static int cntd = 0;
  inline static Array<int> max = make_array<int>(jshl(MAXN, 2));
  inline static Array<int> addTag = make_array<int>(jshl(MAXN, 2));
  inline static Array<bool> updateTag = make_array<bool>(jshl(MAXN, 2));
  inline static Array<int> change = make_array<int>(jshl(MAXN, 2));
  inline static Array<Array<int>> fse = make_array<int>(MAXN, 3);
  inline static int stacksize = {};
  inline static int first = {};
  inline static int second = {};
  inline static int edge = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_UnderMoon1() {}
  static void addEdge(int u, int v) {
    (next[(++cntg)] = head[u]);
    (to[cntg] = v);
    (head[u] = cntg);
  }
  static void dfs1(int u, int f) {
    (fa[u] = f);
    (dep[u] = (dep[f] + 1));
    (siz[u] = 1);
    {
      int e = head[u];
      int v = {};
      for (; (e > 0); (e = next[e])) {
        (v = to[e]);
        if ((v != f)) {
          Code03_UnderMoon1::dfs1(v, u);
        }
      }
    }
    {
      int e = head[u];
      int v = {};
      for (; (e > 0); (e = next[e])) {
        (v = to[e]);
        if ((v != f)) {
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
    (dfn[u] = (++cntd));
    if ((son[u] == 0)) {
      return;
    }
    Code03_UnderMoon1::dfs2(son[u], t);
    {
      int e = head[u];
      int v = {};
      for (; (e > 0); (e = next[e])) {
        (v = to[e]);
        if (((v != fa[u]) && (v != son[u]))) {
          Code03_UnderMoon1::dfs2(v, v);
        }
      }
    }
  }
  static void push(int fir, int sec, int edg) {
    (fse[stacksize][0] = fir);
    (fse[stacksize][1] = sec);
    (fse[stacksize][2] = edg);
    (stacksize++);
  }
  static void pop() {
    (--stacksize);
    (first = fse[stacksize][0]);
    (second = fse[stacksize][1]);
    (edge = fse[stacksize][2]);
  }
  static void dfs3() {
    (stacksize = 0);
    Code03_UnderMoon1::push(1, 0, (-1));
    while ((stacksize > 0)) {
      Code03_UnderMoon1::pop();
      if ((edge == (-1))) {
        (fa[first] = second);
        (dep[first] = (dep[second] + 1));
        (siz[first] = 1);
        (edge = head[first]);
      } else {
        (edge = next[edge]);
      }
      if ((edge != 0)) {
        Code03_UnderMoon1::push(first, second, edge);
        if ((to[edge] != second)) {
          Code03_UnderMoon1::push(to[edge], first, (-1));
        }
      } else {
        {
          int e = head[first];
          int v = {};
          for (; (e > 0); (e = next[e])) {
            (v = to[e]);
            if ((v != second)) {
              (siz[first] += siz[v]);
              if (((son[first] == 0) || (siz[son[first]] < siz[v]))) {
                (son[first] = v);
              }
            }
          }
        }
      }
    }
  }
  static void dfs4() {
    (stacksize = 0);
    Code03_UnderMoon1::push(1, 1, (-1));
    while ((stacksize > 0)) {
      Code03_UnderMoon1::pop();
      if ((edge == (-1))) {
        (top[first] = second);
        (dfn[first] = (++cntd));
        if ((son[first] == 0)) {
          continue;
        }
        Code03_UnderMoon1::push(first, second, (-2));
        Code03_UnderMoon1::push(son[first], second, (-1));
        continue;
      } else if ((edge == (-2))) {
        (edge = head[first]);
      } else {
        (edge = next[edge]);
      }
      if ((edge != 0)) {
        Code03_UnderMoon1::push(first, second, edge);
        if (((to[edge] != fa[first]) && (to[edge] != son[first]))) {
          Code03_UnderMoon1::push(to[edge], to[edge], (-1));
        }
      }
    }
  }
  static void up(int i) {
    (max[i] = jmax(max[jshl(i, 1)], max[(jshl(i, 1) | 1)]));
  }
  static void addLazy(int i, int v) {
    (max[i] += v);
    (addTag[i] += v);
  }
  static void updateLazy(int i, int v) {
    (max[i] = v);
    (addTag[i] = 0);
    (updateTag[i] = true);
    (change[i] = v);
  }
  static void down(int i) {
    if (updateTag[i]) {
      Code03_UnderMoon1::updateLazy(jshl(i, 1), change[i]);
      Code03_UnderMoon1::updateLazy((jshl(i, 1) | 1), change[i]);
      (updateTag[i] = false);
    }
    if ((addTag[i] != 0)) {
      Code03_UnderMoon1::addLazy(jshl(i, 1), addTag[i]);
      Code03_UnderMoon1::addLazy((jshl(i, 1) | 1), addTag[i]);
      (addTag[i] = 0);
    }
  }
  static void update(int jobl, int jobr, int jobv, int l, int r, int i) {
    if (((jobl <= l) && (r <= jobr))) {
      Code03_UnderMoon1::updateLazy(i, jobv);
    } else {
      int mid = jshr((l + r), 1);
      Code03_UnderMoon1::down(i);
      if ((jobl <= mid)) {
        Code03_UnderMoon1::update(jobl, jobr, jobv, l, mid, jshl(i, 1));
      }
      if ((jobr > mid)) {
        Code03_UnderMoon1::update(jobl, jobr, jobv, (mid + 1), r,
                                  (jshl(i, 1) | 1));
      }
      Code03_UnderMoon1::up(i);
    }
  }
  static void add(int jobl, int jobr, int jobv, int l, int r, int i) {
    if (((jobl <= l) && (r <= jobr))) {
      Code03_UnderMoon1::addLazy(i, jobv);
    } else {
      int mid = jshr((l + r), 1);
      Code03_UnderMoon1::down(i);
      if ((jobl <= mid)) {
        Code03_UnderMoon1::add(jobl, jobr, jobv, l, mid, jshl(i, 1));
      }
      if ((jobr > mid)) {
        Code03_UnderMoon1::add(jobl, jobr, jobv, (mid + 1), r,
                               (jshl(i, 1) | 1));
      }
      Code03_UnderMoon1::up(i);
    }
  }
  static int query(int jobl, int jobr, int l, int r, int i) {
    if (((jobl <= l) && (r <= jobr))) {
      return max[i];
    }
    int mid = jshr((l + r), 1);
    Code03_UnderMoon1::down(i);
    int ans = std::numeric_limits<int>::min();
    if ((jobl <= mid)) {
      (ans =
           jmax(ans, Code03_UnderMoon1::query(jobl, jobr, l, mid, jshl(i, 1))));
    }
    if ((jobr > mid)) {
      (ans = jmax(ans, Code03_UnderMoon1::query(jobl, jobr, (mid + 1), r,
                                                (jshl(i, 1) | 1))));
    }
    return ans;
  }
  static void edgeUpdate(int ei, int val) {
    int x = arr[ei][0];
    int y = arr[ei][1];
    int down = jmax(dfn[x], dfn[y]);
    Code03_UnderMoon1::update(down, down, val, 1, n, 1);
  }
  static void pathUpdate(int x, int y, int v) {
    while ((top[x] != top[y])) {
      if ((dep[top[x]] <= dep[top[y]])) {
        Code03_UnderMoon1::update(dfn[top[y]], dfn[y], v, 1, n, 1);
        (y = fa[top[y]]);
      } else {
        Code03_UnderMoon1::update(dfn[top[x]], dfn[x], v, 1, n, 1);
        (x = fa[top[x]]);
      }
    }
    [&]() {
      auto jargument_0 = (jmin(dfn[x], dfn[y]) + 1);
      auto jargument_1 = jmax(dfn[x], dfn[y]);
      auto jargument_2 = v;
      auto jargument_3 = 1;
      auto jargument_4 = n;
      auto jargument_5 = 1;
      return Code03_UnderMoon1::update(jargument_0, jargument_1, jargument_2,
                                       jargument_3, jargument_4, jargument_5);
    }();
  }
  static void pathAdd(int x, int y, int v) {
    while ((top[x] != top[y])) {
      if ((dep[top[x]] <= dep[top[y]])) {
        Code03_UnderMoon1::add(dfn[top[y]], dfn[y], v, 1, n, 1);
        (y = fa[top[y]]);
      } else {
        Code03_UnderMoon1::add(dfn[top[x]], dfn[x], v, 1, n, 1);
        (x = fa[top[x]]);
      }
    }
    [&]() {
      auto jargument_0 = (jmin(dfn[x], dfn[y]) + 1);
      auto jargument_1 = jmax(dfn[x], dfn[y]);
      auto jargument_2 = v;
      auto jargument_3 = 1;
      auto jargument_4 = n;
      auto jargument_5 = 1;
      return Code03_UnderMoon1::add(jargument_0, jargument_1, jargument_2,
                                    jargument_3, jargument_4, jargument_5);
    }();
  }
  static int pathMax(int x, int y) {
    int ans = std::numeric_limits<int>::min();
    while ((top[x] != top[y])) {
      if ((dep[top[x]] <= dep[top[y]])) {
        (ans =
             jmax(ans, Code03_UnderMoon1::query(dfn[top[y]], dfn[y], 1, n, 1)));
        (y = fa[top[y]]);
      } else {
        (ans =
             jmax(ans, Code03_UnderMoon1::query(dfn[top[x]], dfn[x], 1, n, 1)));
        (x = fa[top[x]]);
      }
    }
    (ans = jmax(ans, [&]() {
       auto jargument_0 = (jmin(dfn[x], dfn[y]) + 1);
       auto jargument_1 = jmax(dfn[x], dfn[y]);
       auto jargument_2 = 1;
       auto jargument_3 = n;
       auto jargument_4 = 1;
       return Code03_UnderMoon1::query(jargument_0, jargument_1, jargument_2,
                                       jargument_3, jargument_4);
     }()));
    return ans;
  }
  static void prepare() {
    for (int i = 1; (i < n); (i++)) {
      Code03_UnderMoon1::addEdge(arr[i][0], arr[i][1]);
      Code03_UnderMoon1::addEdge(arr[i][1], arr[i][0]);
    }
    Code03_UnderMoon1::dfs3();
    Code03_UnderMoon1::dfs4();
    for (int i = 1; (i < n); (i++)) {
      Code03_UnderMoon1::edgeUpdate(i, arr[i][2]);
    }
  }
  static void java_main(Array<String> args) {
    IO io = IO();
    (n = io.nextInt());
    for (int i = 1; (i < n); (i++)) {
      (arr[i][0] = io.nextInt());
      (arr[i][1] = io.nextInt());
      (arr[i][2] = io.nextInt());
    }
    Code03_UnderMoon1::prepare();
    String op = io.next();
    int x = {};
    int y = {};
    int v = {};
    while ((!op.equals(String(u"Stop")))) {
      if (op.equals(String(u"Change"))) {
        (x = io.nextInt());
        (v = io.nextInt());
        Code03_UnderMoon1::edgeUpdate(x, v);
      } else if (op.equals(String(u"Cover"))) {
        (x = io.nextInt());
        (y = io.nextInt());
        (v = io.nextInt());
        Code03_UnderMoon1::pathUpdate(x, y, v);
      } else if (op.equals(String(u"Add"))) {
        (x = io.nextInt());
        (y = io.nextInt());
        (v = io.nextInt());
        Code03_UnderMoon1::pathAdd(x, y, v);
      } else {
        (x = io.nextInt());
        (y = io.nextInt());
        io.println(Code03_UnderMoon1::pathMax(x, y));
      }
      (op = io.next());
    }
    io.flush();
    io.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code03_UnderMoon1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 月下毛景树，java版
// 一共有n个节点，节点编号从1到n，所有节点连成一棵树
// 给定n-1条边，边的编号从1到n-1，每条边给定初始边权
// 会进行若干次操作，每条操作的类型是如下4种类型中的一种
// 操作 Change x v  : 第x条边的边权改成v
// 操作 Cover x y v : x号点到y号点的路径上，所有边权改成v
// 操作 Add x y v   : x号点到y号点的路径上，所有边权增加v
// 操作 Max x y     : x号点到y号点的路径上，打印最大的边权
// 1 <= n <= 10^5
// 任何时候的边权 <= 10^9
// 测试链接 : https://www.luogu.com.cn/problem/P4315
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 链式前向星
        // 重链剖分
        // 线段树查询区间最大值
        // 但是需要同时兼顾，区间增加、区间重置，这两种操作
        // 那么就牵扯到两种操作相互影响的问题
        // 因为区间重置操作会取消之前的区间增加操作
        // 讲解110，线段树章节，题目5、题目6，重点讲了这种线段树
        // 不会的同学可以看看，讲的非常清楚
        // dfs1的迭代版
        // dfs2的迭代版
        // 读写工具类
*/

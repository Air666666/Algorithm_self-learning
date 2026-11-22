// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P2146

// Source: src/class161/Code04_PackageManager1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_PackageManager1 {
  inline static int MAXN = 100001;
  inline static int n = {};
  inline static int m = {};
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
  inline static Array<int> sum = make_array<int>(jshl(MAXN, 2));
  inline static Array<bool> update = make_array<bool>(jshl(MAXN, 2));
  inline static Array<int> change = make_array<int>(jshl(MAXN, 2));
  inline static Array<Array<int>> fse = make_array<int>(MAXN, 3);
  inline static int stacksize = {};
  inline static int first = {};
  inline static int second = {};
  inline static int edge = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_PackageManager1() {}
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
          Code04_PackageManager1::dfs1(v, u);
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
    Code04_PackageManager1::dfs2(son[u], t);
    {
      int e = head[u];
      int v = {};
      for (; (e > 0); (e = next[e])) {
        (v = to[e]);
        if (((v != fa[u]) && (v != son[u]))) {
          Code04_PackageManager1::dfs2(v, v);
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
    Code04_PackageManager1::push(1, 0, (-1));
    while ((stacksize > 0)) {
      Code04_PackageManager1::pop();
      if ((edge == (-1))) {
        (fa[first] = second);
        (dep[first] = (dep[second] + 1));
        (siz[first] = 1);
        (edge = head[first]);
      } else {
        (edge = next[edge]);
      }
      if ((edge != 0)) {
        Code04_PackageManager1::push(first, second, edge);
        if ((to[edge] != second)) {
          Code04_PackageManager1::push(to[edge], first, (-1));
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
    Code04_PackageManager1::push(1, 1, (-1));
    while ((stacksize > 0)) {
      Code04_PackageManager1::pop();
      if ((edge == (-1))) {
        (top[first] = second);
        (dfn[first] = (++cntd));
        if ((son[first] == 0)) {
          continue;
        }
        Code04_PackageManager1::push(first, second, (-2));
        Code04_PackageManager1::push(son[first], second, (-1));
        continue;
      } else if ((edge == (-2))) {
        (edge = head[first]);
      } else {
        (edge = next[edge]);
      }
      if ((edge != 0)) {
        Code04_PackageManager1::push(first, second, edge);
        if (((to[edge] != fa[first]) && (to[edge] != son[first]))) {
          Code04_PackageManager1::push(to[edge], to[edge], (-1));
        }
      }
    }
  }
  static void up(int i) {
    (sum[i] = (sum[jshl(i, 1)] + sum[(jshl(i, 1) | 1)]));
  }
  static void lazy(int i, int v, int n) {
    (sum[i] = (v * n));
    (update[i] = true);
    (change[i] = v);
  }
  static void down(int i, int ln, int rn) {
    if (update[i]) {
      Code04_PackageManager1::lazy(jshl(i, 1), change[i], ln);
      Code04_PackageManager1::lazy((jshl(i, 1) | 1), change[i], rn);
      (update[i] = false);
    }
  }
  static void update_method(int jobl, int jobr, int jobv, int l, int r, int i) {
    if (((jobl <= l) && (r <= jobr))) {
      Code04_PackageManager1::lazy(i, jobv, ((r - l) + 1));
    } else {
      int mid = jdiv((l + r), 2);
      Code04_PackageManager1::down(i, ((mid - l) + 1), (r - mid));
      if ((jobl <= mid)) {
        Code04_PackageManager1::update_method(jobl, jobr, jobv, l, mid,
                                              jshl(i, 1));
      }
      if ((jobr > mid)) {
        Code04_PackageManager1::update_method(jobl, jobr, jobv, (mid + 1), r,
                                              (jshl(i, 1) | 1));
      }
      Code04_PackageManager1::up(i);
    }
  }
  static i64 query(int jobl, int jobr, int l, int r, int i) {
    if (((jobl <= l) && (r <= jobr))) {
      return sum[i];
    }
    int mid = jdiv((l + r), 2);
    Code04_PackageManager1::down(i, ((mid - l) + 1), (r - mid));
    i64 ans = 0;
    if ((jobl <= mid)) {
      (ans += Code04_PackageManager1::query(jobl, jobr, l, mid, jshl(i, 1)));
    }
    if ((jobr > mid)) {
      (ans += Code04_PackageManager1::query(jobl, jobr, (mid + 1), r,
                                            (jshl(i, 1) | 1)));
    }
    return ans;
  }
  static void pathUpdate(int x, int v) {
    int y = 1;
    while ((top[x] != top[y])) {
      if ((dep[top[x]] <= dep[top[y]])) {
        Code04_PackageManager1::update_method(dfn[top[y]], dfn[y], v, 1, n, 1);
        (y = fa[top[y]]);
      } else {
        Code04_PackageManager1::update_method(dfn[top[x]], dfn[x], v, 1, n, 1);
        (x = fa[top[x]]);
      }
    }
    [&]() {
      auto jargument_0 = jmin(dfn[x], dfn[y]);
      auto jargument_1 = jmax(dfn[x], dfn[y]);
      auto jargument_2 = v;
      auto jargument_3 = 1;
      auto jargument_4 = n;
      auto jargument_5 = 1;
      return Code04_PackageManager1::update_method(jargument_0, jargument_1,
                                                   jargument_2, jargument_3,
                                                   jargument_4, jargument_5);
    }();
  }
  static int install(int x) {
    int pre = sum[1];
    Code04_PackageManager1::pathUpdate(x, 1);
    int post = sum[1];
    return std::abs((post - pre));
  }
  static int uninstall(int x) {
    int pre = sum[1];
    Code04_PackageManager1::update_method(dfn[x], ((dfn[x] + siz[x]) - 1), 0, 1,
                                          n, 1);
    int post = sum[1];
    return std::abs((post - pre));
  }
  static void java_main(Array<String> args) {
    IO io = IO();
    (n = io.nextInt());
    {
      int u = 2;
      int v = {};
      for (; (u <= n); (u++)) {
        (v = (io.nextInt() + 1));
        Code04_PackageManager1::addEdge(v, u);
      }
    }
    Code04_PackageManager1::dfs3();
    Code04_PackageManager1::dfs4();
    (m = io.nextInt());
    String op = {};
    int x = {};
    for (int i = 1; (i <= m); (i++)) {
      (op = io.next());
      (x = (io.nextInt() + 1));
      if (op.equals(String(u"install"))) {
        io.println(Code04_PackageManager1::install(x));
      } else {
        io.println(Code04_PackageManager1::uninstall(x));
      }
    }
    io.flush();
    io.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code04_PackageManager1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 软件包管理器，java版
// 一共有n个软件，编号0~n-1，0号软件不依赖任何软件，其他每个软件都仅依赖一个软件
// 依赖关系由数组形式给出，题目保证不会出现循环依赖
//
一开始所有软件都是没有安装的，如果a依赖b，那么安装a需要安装b，同时卸载b需要卸载a
// 一共有m条操作，每种操作是如下2种类型中的一种
// 操作 install x    :
安装x，如果x已经安装打印0，否则打印有多少个软件的状态需要改变
// 操作 uninstall x  :
卸载x，如果x没有安装打印0，否则打印有多少个软件的状态需要改变
// 1 <= n、m <= 10^6
// 测试链接 : https://www.luogu.com.cn/problem/P2146
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 递归版，C++可以通过，java会爆栈
        // 递归版，C++可以通过，java会爆栈
        // 不会改迭代版，去看讲解118，详解了从递归版改迭代版
        // dfs1的迭代版
        // dfs2的迭代版
        // 线段树重置操作的懒更新
        // 从1到x的路径上，所有节点值改成v
        // 读写工具类
*/

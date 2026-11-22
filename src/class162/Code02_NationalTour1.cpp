// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P1505

// Source: src/class162/Code02_NationalTour1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_NationalTour1 {
  inline static int MAXN = 200001;
  inline static int n = {};
  inline static int m = {};
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
  inline static Array<int> sum = make_array<int>(jshl(MAXN, 2));
  inline static Array<int> max = make_array<int>(jshl(MAXN, 2));
  inline static Array<int> min = make_array<int>(jshl(MAXN, 2));
  inline static Array<bool> negativeTag = make_array<bool>(jshl(MAXN, 2));
  inline static Array<Array<int>> fse = make_array<int>(MAXN, 3);
  inline static int stacksize = {};
  inline static int first = {};
  inline static int second = {};
  inline static int edge = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_NationalTour1() {}
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
          Code02_NationalTour1::dfs1(v, u);
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
    Code02_NationalTour1::dfs2(son[u], t);
    {
      int e = head[u];
      int v = {};
      for (; (e > 0); (e = next[e])) {
        (v = to[e]);
        if (((v != fa[u]) && (v != son[u]))) {
          Code02_NationalTour1::dfs2(v, v);
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
    Code02_NationalTour1::push(1, 0, (-1));
    while ((stacksize > 0)) {
      Code02_NationalTour1::pop();
      if ((edge == (-1))) {
        (fa[first] = second);
        (dep[first] = (dep[second] + 1));
        (siz[first] = 1);
        (edge = head[first]);
      } else {
        (edge = next[edge]);
      }
      if ((edge != 0)) {
        Code02_NationalTour1::push(first, second, edge);
        if ((to[edge] != second)) {
          Code02_NationalTour1::push(to[edge], first, (-1));
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
    Code02_NationalTour1::push(1, 1, (-1));
    while ((stacksize > 0)) {
      Code02_NationalTour1::pop();
      if ((edge == (-1))) {
        (top[first] = second);
        (dfn[first] = (++cntd));
        if ((son[first] == 0)) {
          continue;
        }
        Code02_NationalTour1::push(first, second, (-2));
        Code02_NationalTour1::push(son[first], second, (-1));
        continue;
      } else if ((edge == (-2))) {
        (edge = head[first]);
      } else {
        (edge = next[edge]);
      }
      if ((edge != 0)) {
        Code02_NationalTour1::push(first, second, edge);
        if (((to[edge] != fa[first]) && (to[edge] != son[first]))) {
          Code02_NationalTour1::push(to[edge], to[edge], (-1));
        }
      }
    }
  }
  static void up(int i) {
    int l = jshl(i, 1);
    int r = (jshl(i, 1) | 1);
    (sum[i] = (sum[l] + sum[r]));
    (max[i] = jmax(max[l], max[r]));
    (min[i] = jmin(min[l], min[r]));
  }
  static void lazy(int i) {
    (sum[i] = (-sum[i]));
    int tmp = max[i];
    (max[i] = (-min[i]));
    (min[i] = (-tmp));
    (negativeTag[i] = (!negativeTag[i]));
  }
  static void down(int i) {
    if (negativeTag[i]) {
      Code02_NationalTour1::lazy(jshl(i, 1));
      Code02_NationalTour1::lazy((jshl(i, 1) | 1));
      (negativeTag[i] = false);
    }
  }
  static void update(int jobi, int jobv, int l, int r, int i) {
    if ((l == r)) {
      (sum[i] = (max[i] = (min[i] = jobv)));
    } else {
      Code02_NationalTour1::down(i);
      int mid = jdiv((l + r), 2);
      if ((jobi <= mid)) {
        Code02_NationalTour1::update(jobi, jobv, l, mid, jshl(i, 1));
      } else {
        Code02_NationalTour1::update(jobi, jobv, (mid + 1), r,
                                     (jshl(i, 1) | 1));
      }
      Code02_NationalTour1::up(i);
    }
  }
  static void negative(int jobl, int jobr, int l, int r, int i) {
    if (((jobl <= l) && (r <= jobr))) {
      Code02_NationalTour1::lazy(i);
    } else {
      Code02_NationalTour1::down(i);
      int mid = jdiv((l + r), 2);
      if ((jobl <= mid)) {
        Code02_NationalTour1::negative(jobl, jobr, l, mid, jshl(i, 1));
      }
      if ((jobr > mid)) {
        Code02_NationalTour1::negative(jobl, jobr, (mid + 1), r,
                                       (jshl(i, 1) | 1));
      }
      Code02_NationalTour1::up(i);
    }
  }
  static int querySum(int jobl, int jobr, int l, int r, int i) {
    if (((jobl <= l) && (r <= jobr))) {
      return sum[i];
    }
    Code02_NationalTour1::down(i);
    int mid = jdiv((l + r), 2);
    int ans = 0;
    if ((jobl <= mid)) {
      (ans += Code02_NationalTour1::querySum(jobl, jobr, l, mid, jshl(i, 1)));
    }
    if ((jobr > mid)) {
      (ans += Code02_NationalTour1::querySum(jobl, jobr, (mid + 1), r,
                                             (jshl(i, 1) | 1)));
    }
    return ans;
  }
  static int queryMax(int jobl, int jobr, int l, int r, int i) {
    if (((jobl <= l) && (r <= jobr))) {
      return max[i];
    }
    Code02_NationalTour1::down(i);
    int mid = jdiv((l + r), 2);
    int ans = std::numeric_limits<int>::min();
    if ((jobl <= mid)) {
      (ans = jmax(ans, Code02_NationalTour1::queryMax(jobl, jobr, l, mid,
                                                      jshl(i, 1))));
    }
    if ((jobr > mid)) {
      (ans = jmax(ans, Code02_NationalTour1::queryMax(jobl, jobr, (mid + 1), r,
                                                      (jshl(i, 1) | 1))));
    }
    return ans;
  }
  static int queryMin(int jobl, int jobr, int l, int r, int i) {
    if (((jobl <= l) && (r <= jobr))) {
      return min[i];
    }
    Code02_NationalTour1::down(i);
    int mid = jdiv((l + r), 2);
    int ans = std::numeric_limits<int>::max();
    if ((jobl <= mid)) {
      (ans = jmin(ans, Code02_NationalTour1::queryMin(jobl, jobr, l, mid,
                                                      jshl(i, 1))));
    }
    if ((jobr > mid)) {
      (ans = jmin(ans, Code02_NationalTour1::queryMin(jobl, jobr, (mid + 1), r,
                                                      (jshl(i, 1) | 1))));
    }
    return ans;
  }
  static void edgeUpdate(int ei, int val) {
    int x = arr[ei][0];
    int y = arr[ei][1];
    int down = jmax(dfn[x], dfn[y]);
    Code02_NationalTour1::update(down, val, 1, n, 1);
  }
  static void pathNegative(int x, int y) {
    while ((top[x] != top[y])) {
      if ((dep[top[x]] <= dep[top[y]])) {
        Code02_NationalTour1::negative(dfn[top[y]], dfn[y], 1, n, 1);
        (y = fa[top[y]]);
      } else {
        Code02_NationalTour1::negative(dfn[top[x]], dfn[x], 1, n, 1);
        (x = fa[top[x]]);
      }
    }
    [&]() {
      auto jargument_0 = (jmin(dfn[x], dfn[y]) + 1);
      auto jargument_1 = jmax(dfn[x], dfn[y]);
      auto jargument_2 = 1;
      auto jargument_3 = n;
      auto jargument_4 = 1;
      return Code02_NationalTour1::negative(
          jargument_0, jargument_1, jargument_2, jargument_3, jargument_4);
    }();
  }
  static int pathSum(int x, int y) {
    int ans = 0;
    while ((top[x] != top[y])) {
      if ((dep[top[x]] <= dep[top[y]])) {
        (ans += Code02_NationalTour1::querySum(dfn[top[y]], dfn[y], 1, n, 1));
        (y = fa[top[y]]);
      } else {
        (ans += Code02_NationalTour1::querySum(dfn[top[x]], dfn[x], 1, n, 1));
        (x = fa[top[x]]);
      }
    }
    (ans += [&]() {
      auto jargument_0 = (jmin(dfn[x], dfn[y]) + 1);
      auto jargument_1 = jmax(dfn[x], dfn[y]);
      auto jargument_2 = 1;
      auto jargument_3 = n;
      auto jargument_4 = 1;
      return Code02_NationalTour1::querySum(
          jargument_0, jargument_1, jargument_2, jargument_3, jargument_4);
    }());
    return ans;
  }
  static int pathMax(int x, int y) {
    int ans = std::numeric_limits<int>::min();
    while ((top[x] != top[y])) {
      if ((dep[top[x]] <= dep[top[y]])) {
        (ans = jmax(ans, Code02_NationalTour1::queryMax(dfn[top[y]], dfn[y], 1,
                                                        n, 1)));
        (y = fa[top[y]]);
      } else {
        (ans = jmax(ans, Code02_NationalTour1::queryMax(dfn[top[x]], dfn[x], 1,
                                                        n, 1)));
        (x = fa[top[x]]);
      }
    }
    (ans = jmax(ans, [&]() {
       auto jargument_0 = (jmin(dfn[x], dfn[y]) + 1);
       auto jargument_1 = jmax(dfn[x], dfn[y]);
       auto jargument_2 = 1;
       auto jargument_3 = n;
       auto jargument_4 = 1;
       return Code02_NationalTour1::queryMax(
           jargument_0, jargument_1, jargument_2, jargument_3, jargument_4);
     }()));
    return ans;
  }
  static int pathMin(int x, int y) {
    int ans = std::numeric_limits<int>::max();
    while ((top[x] != top[y])) {
      if ((dep[top[x]] <= dep[top[y]])) {
        (ans = jmin(ans, Code02_NationalTour1::queryMin(dfn[top[y]], dfn[y], 1,
                                                        n, 1)));
        (y = fa[top[y]]);
      } else {
        (ans = jmin(ans, Code02_NationalTour1::queryMin(dfn[top[x]], dfn[x], 1,
                                                        n, 1)));
        (x = fa[top[x]]);
      }
    }
    (ans = jmin(ans, [&]() {
       auto jargument_0 = (jmin(dfn[x], dfn[y]) + 1);
       auto jargument_1 = jmax(dfn[x], dfn[y]);
       auto jargument_2 = 1;
       auto jargument_3 = n;
       auto jargument_4 = 1;
       return Code02_NationalTour1::queryMin(
           jargument_0, jargument_1, jargument_2, jargument_3, jargument_4);
     }()));
    return ans;
  }
  static void prepare() {
    for (int i = 1; (i < n); (i++)) {
      Code02_NationalTour1::addEdge(arr[i][0], arr[i][1]);
      Code02_NationalTour1::addEdge(arr[i][1], arr[i][0]);
    }
    Code02_NationalTour1::dfs3();
    Code02_NationalTour1::dfs4();
    for (int i = 1; (i < n); (i++)) {
      Code02_NationalTour1::edgeUpdate(i, arr[i][2]);
    }
  }
  static void java_main(Array<String> args) {
    IO io = IO();
    (n = io.nextInt());
    for (int i = 1; (i < n); (i++)) {
      (arr[i][0] = (io.nextInt() + 1));
      (arr[i][1] = (io.nextInt() + 1));
      (arr[i][2] = io.nextInt());
    }
    Code02_NationalTour1::prepare();
    (m = io.nextInt());
    String op = {};
    {
      int i = 1;
      int x = {};
      int y = {};
      for (; (i <= m); (i++)) {
        (op = io.next());
        if (op.equals(String(u"C"))) {
          (x = io.nextInt());
          (y = io.nextInt());
          Code02_NationalTour1::edgeUpdate(x, y);
        } else {
          (x = (io.nextInt() + 1));
          (y = (io.nextInt() + 1));
          if (op.equals(String(u"N"))) {
            Code02_NationalTour1::pathNegative(x, y);
          } else if (op.equals(String(u"SUM"))) {
            io.println(Code02_NationalTour1::pathSum(x, y));
          } else if (op.equals(String(u"MAX"))) {
            io.println(Code02_NationalTour1::pathMax(x, y));
          } else {
            io.println(Code02_NationalTour1::pathMin(x, y));
          }
        }
      }
    }
    io.flush();
    io.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code02_NationalTour1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 国家集训队旅游，java版
// 一共有n个节点，节点编号从0到n-1，所有节点连成一棵树
// 给定n-1条边，边的编号从1到n-1，每条边给定初始边权
// 一共有m条操作，每条操作的类型是如下5种类型中的一种
// 操作 C x y   : 第x条边的边权改成y
// 操作 N x y   : x号点到y号点的路径上，所有边权变成相反数
// 操作 SUM x y : x号点到y号点的路径上，查询所有边权的累加和
// 操作 MAX x y : x号点到y号点的路径上，查询所有边权的最大值
// 操作 MIN x y : x号点到y号点的路径上，查询所有边权的最小值
// 1 <= n、m <= 2 * 10^5
// -1000 <= 任何时候的边权 <= +1000
// 测试链接 : https://www.luogu.com.cn/problem/P1505
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // arr[i][0] : 第i条边的其中一点
        // arr[i][1] : 第i条边的另外一点
        // arr[i][2] : 第i条边的初始边权
        // 链式前向星
        // 重链剖分
        // 线段树
        // dfs1的迭代版
        // dfs2的迭代版
        // 读写工具类
*/

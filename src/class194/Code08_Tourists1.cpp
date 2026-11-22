// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/CF487E
// https://codeforces.com/problemset/problem/487/E

// Source: src/class194/Code08_Tourists1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code08_Tourists1 {
  inline static int MAXN = 100001;
  inline static int MAXM = 100001;
  inline static int INF = 1000000001;
  inline static int n = {};
  inline static int m = {};
  inline static int q = {};
  inline static int cntn = {};
  inline static Array<int> arr = make_array<int>(MAXN);
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
  inline static Array<int> fa = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> dep = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> siz = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> son = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> top = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> nid = make_array<int>(jshl(MAXN, 1));
  inline static int cnti = {};
  inline static JMap<int, JTreeMap<int, int>> maps =
      JMap<int, JTreeMap<int, int>>();
  inline static Array<int> val = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> minv = make_array<int>(jshl(MAXN, 3));
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code08_Tourists1() {}
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
  static void addNum(int u, int num) {
    if ((!maps.containsKey(u))) {
      maps.put(u, JTreeMap<int, int>());
    }
    maps.get(u).put(num, (maps.get(u).getOrDefault(num, 0) + 1));
  }
  static void delNum(int u, int num) {
    int cnt = maps.get(u).get(num);
    if ((cnt == 1)) {
      maps.get(u).remove(num);
    } else {
      maps.get(u).put(num, (cnt - 1));
    }
  }
  static int getMin(int u) { return maps.get(u).firstKey(); }
  static void tarjan(int u) {
    (dfn[u] = (low[u] = (++cntd)));
    (sta[(++cnts)] = u);
    for (int e = head1[u]; (e > 0); (e = next1[e])) {
      int v = to1[e];
      if ((dfn[v] == 0)) {
        Code08_Tourists1::tarjan(v);
        (low[u] = jmin(low[u], low[v]));
        if ((low[v] >= dfn[u])) {
          (cntn++);
          Code08_Tourists1::addEdge2(cntn, u);
          Code08_Tourists1::addEdge2(u, cntn);
          int pop = {};
          do {
            (pop = sta[(cnts--)]);
            Code08_Tourists1::addEdge2(cntn, pop);
            Code08_Tourists1::addEdge2(pop, cntn);
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
    for (int e = head2[u]; (e > 0); (e = next2[e])) {
      int v = to2[e];
      if ((v != f)) {
        Code08_Tourists1::dfs1(v, u);
        (siz[u] += siz[v]);
        if (((son[u] == 0) || (siz[son[u]] < siz[v]))) {
          (son[u] = v);
        }
        if ((u > n)) {
          Code08_Tourists1::addNum(u, arr[v]);
        }
      }
    }
  }
  static void dfs2(int u, int t) {
    (top[u] = t);
    (nid[u] = (++cnti));
    (val[nid[u]] = ((u <= n) ? arr[u] : Code08_Tourists1::getMin(u)));
    if ((son[u] == 0)) {
      return;
    }
    Code08_Tourists1::dfs2(son[u], t);
    {
      int e = head2[u];
      int v = {};
      for (; (e > 0); (e = next2[e])) {
        (v = to2[e]);
        if (((v != fa[u]) && (v != son[u]))) {
          Code08_Tourists1::dfs2(v, v);
        }
      }
    }
  }
  static void up(int i) {
    (minv[i] = jmin(minv[jshl(i, 1)], minv[(jshl(i, 1) | 1)]));
  }
  static void build(int l, int r, int i) {
    if ((l == r)) {
      (minv[i] = val[l]);
    } else {
      int mid = jdiv((l + r), 2);
      Code08_Tourists1::build(l, mid, jshl(i, 1));
      Code08_Tourists1::build((mid + 1), r, (jshl(i, 1) | 1));
      Code08_Tourists1::up(i);
    }
  }
  static void update(int jobi, int jobv, int l, int r, int i) {
    if ((l == r)) {
      (minv[i] = jobv);
    } else {
      int mid = jdiv((l + r), 2);
      if ((jobi <= mid)) {
        Code08_Tourists1::update(jobi, jobv, l, mid, jshl(i, 1));
      } else {
        Code08_Tourists1::update(jobi, jobv, (mid + 1), r, (jshl(i, 1) | 1));
      }
      Code08_Tourists1::up(i);
    }
  }
  static int query(int jobl, int jobr, int l, int r, int i) {
    if (((jobl <= l) && (r <= jobr))) {
      return minv[i];
    }
    int mid = jdiv((l + r), 2);
    int ans = INF;
    if ((jobl <= mid)) {
      (ans =
           jmin(ans, Code08_Tourists1::query(jobl, jobr, l, mid, jshl(i, 1))));
    }
    if ((jobr > mid)) {
      (ans = jmin(ans, Code08_Tourists1::query(jobl, jobr, (mid + 1), r,
                                               (jshl(i, 1) | 1))));
    }
    return ans;
  }
  static int pathMin(int x, int y) {
    int ans = INF;
    while ((top[x] != top[y])) {
      if ((dep[top[x]] < dep[top[y]])) {
        int tmp = x;
        (x = y);
        (y = tmp);
      }
      (ans =
           jmin(ans, Code08_Tourists1::query(nid[top[x]], nid[x], 1, cnti, 1)));
      (x = fa[top[x]]);
    }
    if ((dep[x] < dep[y])) {
      int tmp = x;
      (x = y);
      (y = tmp);
    }
    (ans = jmin(ans, Code08_Tourists1::query(nid[y], nid[x], 1, cnti, 1)));
    if ((y > n)) {
      (ans = jmin(ans, arr[fa[y]]));
    }
    return ans;
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (m = in.nextInt());
    (q = in.nextInt());
    (cntn = n);
    for (int i = 1; (i <= n); (i++)) {
      (arr[i] = in.nextInt());
    }
    {
      int i = 1;
      int u = {};
      int v = {};
      for (; (i <= m); (i++)) {
        (u = in.nextInt());
        (v = in.nextInt());
        Code08_Tourists1::addEdge1(u, v);
        Code08_Tourists1::addEdge1(v, u);
      }
    }
    Code08_Tourists1::tarjan(1);
    Code08_Tourists1::dfs1(1, 0);
    Code08_Tourists1::dfs2(1, 1);
    Code08_Tourists1::build(1, cnti, 1);
    for (int i = 1; (i <= q); (i++)) {
      jchar op = in.nextLetter();
      int x = in.nextInt();
      int y = in.nextInt();
      if ((op == u'C')) {
        int father = fa[x];
        if ((father > 0)) {
          Code08_Tourists1::delNum(father, arr[x]);
          Code08_Tourists1::addNum(father, y);
          Code08_Tourists1::update(
              nid[father], Code08_Tourists1::getMin(father), 1, cnti, 1);
        }
        (arr[x] = y);
        Code08_Tourists1::update(nid[x], y, 1, cnti, 1);
      } else {
        out.println(Code08_Tourists1::pathMin(x, y));
      }
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code08_Tourists1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 游客，java版
// 一共n个城市、m条双向道路，所有城市都连通，商品只有一种
// 每个城市给定商品报价，接下来有q条操作，操作类型有两种
// 操作 C x y : 城市x的商品报价改成y
// 操作 A x y : 从x到y可自由选路，但不能有重复城市，打印能遇到的最低报价
// 1 <= n、m、q <= 10^5
// 1 <= 商品报价 <= 10^9
// 测试链接 : https://www.luogu.com.cn/problem/CF487E
// 测试链接 : https://codeforces.com/problemset/problem/487/E
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // nid是圆方树的点获得的dfn序号
        // cnti是圆方树的dfn序号计数
        // 每个方点分配有序表
        // 圆方树中每个点的点权
        // 线段树
        // 读写工具类
*/

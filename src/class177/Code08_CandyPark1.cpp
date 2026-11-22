// Source: src/class177/Code08_CandyPark1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code08_CandyPark1 {
  struct QueryCmp;
  struct QueryCmp {
    String toString() const { return j::str(static_cast<const void *>(this)); }
    QueryCmp() {}
    int compare(Array<int> a, Array<int> b) {
      if ((bi[a[0]] != bi[b[0]])) {
        return (bi[a[0]] - bi[b[0]]);
      }
      if ((bi[a[1]] != bi[b[1]])) {
        return (bi[a[1]] - bi[b[1]]);
      }
      return (a[2] - b[2]);
    }
  };
  inline static int MAXN = 100001;
  inline static int MAXP = 20;
  inline static int n = {};
  inline static int m = {};
  inline static int q = {};
  inline static Array<int> v = make_array<int>(MAXN);
  inline static Array<int> w = make_array<int>(MAXN);
  inline static Array<int> c = make_array<int>(MAXN);
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> to = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> next = make_array<int>(jshl(MAXN, 1));
  inline static int cntg = {};
  inline static Array<Array<int>> query = make_array<int>(MAXN, 5);
  inline static Array<Array<int>> update = make_array<int>(MAXN, 2);
  inline static int cntq = {};
  inline static int cntu = {};
  inline static Array<int> dep = make_array<int>(MAXN);
  inline static Array<int> seg = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> st = make_array<int>(MAXN);
  inline static Array<int> ed = make_array<int>(MAXN);
  inline static Array<Array<int>> stjump = make_array<int>(MAXN, MAXP);
  inline static int cntd = {};
  inline static Array<int> bi = make_array<int>(jshl(MAXN, 1));
  inline static Array<bool> vis = make_array<bool>(MAXN);
  inline static Array<int> cnt = make_array<int>(MAXN);
  inline static i64 happy = {};
  inline static Array<i64> ans = make_array<i64>(MAXN);
  inline static Array<Array<int>> ufe = make_array<int>(MAXN, 3);
  inline static int stacksize = {};
  inline static int u = {};
  inline static int f = {};
  inline static int e = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code08_CandyPark1() {}
  static void addEdge(int u, int v) {
    (next[(++cntg)] = head[u]);
    (to[cntg] = v);
    (head[u] = cntg);
  }
  static void dfs1(int u, int fa) {
    (dep[u] = (dep[fa] + 1));
    (seg[(++cntd)] = u);
    (st[u] = cntd);
    (stjump[u][0] = fa);
    for (int p = 1; (p < MAXP); (p++)) {
      (stjump[u][p] = stjump[stjump[u][(p - 1)]][(p - 1)]);
    }
    {
      int e = head[u];
      int v = {};
      for (; (e > 0); (e = next[e])) {
        (v = to[e]);
        if ((v != fa)) {
          Code08_CandyPark1::dfs1(v, u);
        }
      }
    }
    (seg[(++cntd)] = u);
    (ed[u] = cntd);
  }
  static void push(int u, int f, int e) {
    (ufe[stacksize][0] = u);
    (ufe[stacksize][1] = f);
    (ufe[stacksize][2] = e);
    (stacksize++);
  }
  static void pop() {
    (--stacksize);
    (u = ufe[stacksize][0]);
    (f = ufe[stacksize][1]);
    (e = ufe[stacksize][2]);
  }
  static void dfs2() {
    (stacksize = 0);
    Code08_CandyPark1::push(1, 0, (-1));
    while ((stacksize > 0)) {
      Code08_CandyPark1::pop();
      if ((e == (-1))) {
        (dep[u] = (dep[f] + 1));
        (seg[(++cntd)] = u);
        (st[u] = cntd);
        (stjump[u][0] = f);
        for (int p = 1; (p < MAXP); (p++)) {
          (stjump[u][p] = stjump[stjump[u][(p - 1)]][(p - 1)]);
        }
        (e = head[u]);
      } else {
        (e = next[e]);
      }
      if ((e != 0)) {
        Code08_CandyPark1::push(u, f, e);
        if ((to[e] != f)) {
          Code08_CandyPark1::push(to[e], u, (-1));
        }
      } else {
        (seg[(++cntd)] = u);
        (ed[u] = cntd);
      }
    }
  }
  static int lca(int a, int b) {
    if ((dep[a] < dep[b])) {
      int tmp = a;
      (a = b);
      (b = tmp);
    }
    for (int p = (MAXP - 1); (p >= 0); (p--)) {
      if ((dep[stjump[a][p]] >= dep[b])) {
        (a = stjump[a][p]);
      }
    }
    if ((a == b)) {
      return a;
    }
    for (int p = (MAXP - 1); (p >= 0); (p--)) {
      if ((stjump[a][p] != stjump[b][p])) {
        (a = stjump[a][p]);
        (b = stjump[b][p]);
      }
    }
    return stjump[a][0];
  }
  static void invert(int node) {
    int candy = c[node];
    if (vis[node]) {
      (happy -= (static_cast<i64>(v[candy]) * w[(cnt[candy]--)]));
    } else {
      (happy += (static_cast<i64>(v[candy]) * w[(++cnt[candy])]));
    }
    (vis[node] = (!vis[node]));
  }
  static void moveTime(int tim) {
    int pos = update[tim][0];
    int oldVal = c[pos];
    int newVal = update[tim][1];
    if (vis[pos]) {
      Code08_CandyPark1::invert(pos);
      (c[pos] = newVal);
      (update[tim][1] = oldVal);
      Code08_CandyPark1::invert(pos);
    } else {
      (c[pos] = newVal);
      (update[tim][1] = oldVal);
    }
  }
  static void compute() {
    int winl = 1;
    int winr = 0;
    int wint = 0;
    for (int i = 1; (i <= cntq); (i++)) {
      int jobl = query[i][0];
      int jobr = query[i][1];
      int jobt = query[i][2];
      int lca = query[i][3];
      int id = query[i][4];
      while ((winl > jobl)) {
        Code08_CandyPark1::invert(seg[(--winl)]);
      }
      while ((winr < jobr)) {
        Code08_CandyPark1::invert(seg[(++winr)]);
      }
      while ((winl < jobl)) {
        Code08_CandyPark1::invert(seg[(winl++)]);
      }
      while ((winr > jobr)) {
        Code08_CandyPark1::invert(seg[(winr--)]);
      }
      while ((wint < jobt)) {
        Code08_CandyPark1::moveTime((++wint));
      }
      while ((wint > jobt)) {
        Code08_CandyPark1::moveTime((wint--));
      }
      if ((lca > 0)) {
        Code08_CandyPark1::invert(lca);
      }
      (ans[id] = happy);
      if ((lca > 0)) {
        Code08_CandyPark1::invert(lca);
      }
    }
  }
  static void prapare() {
    int blen = jmax(1, static_cast<int>(std::pow(cntd, jdiv(2.0, 3))));
    for (int i = 1; (i <= cntd); (i++)) {
      (bi[i] = (jdiv((i - 1), blen) + 1));
    }
    j::sort(query, 1, (cntq + 1), new QueryCmp());
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (m = in.nextInt());
    (q = in.nextInt());
    for (int i = 1; (i <= m); (i++)) {
      (v[i] = in.nextInt());
    }
    for (int i = 1; (i <= n); (i++)) {
      (w[i] = in.nextInt());
    }
    {
      int i = 1;
      int u = {};
      int v = {};
      for (; (i < n); (i++)) {
        (u = in.nextInt());
        (v = in.nextInt());
        Code08_CandyPark1::addEdge(u, v);
        Code08_CandyPark1::addEdge(v, u);
      }
    }
    for (int i = 1; (i <= n); (i++)) {
      (c[i] = in.nextInt());
    }
    Code08_CandyPark1::dfs2();
    {
      int i = 1;
      int op = {};
      int x = {};
      int y = {};
      for (; (i <= q); (i++)) {
        (op = in.nextInt());
        (x = in.nextInt());
        (y = in.nextInt());
        if ((op == 0)) {
          (cntu++);
          (update[cntu][0] = x);
          (update[cntu][1] = y);
        } else {
          if ((st[x] > st[y])) {
            int tmp = x;
            (x = y);
            (y = tmp);
          }
          int xylca = Code08_CandyPark1::lca(x, y);
          if ((x == xylca)) {
            (query[(++cntq)][0] = st[x]);
            (query[cntq][1] = st[y]);
            (query[cntq][2] = cntu);
            (query[cntq][3] = 0);
            (query[cntq][4] = cntq);
          } else {
            (query[(++cntq)][0] = ed[x]);
            (query[cntq][1] = st[y]);
            (query[cntq][2] = cntu);
            (query[cntq][3] = xylca);
            (query[cntq][4] = cntq);
          }
        }
      }
    }
    Code08_CandyPark1::prapare();
    Code08_CandyPark1::compute();
    for (int i = 1; (i <= cntq); (i++)) {
      out.println(ans[i]);
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code08_CandyPark1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 糖果公园，java版
// 一共有n个公园，给定n-1条边，所有公园连成一棵树，c[i]为i号公园的糖果型号
// 一共有m种糖果，v[y]表示y号糖果的美味指数，给定长度为n的数组w，用于计算愉悦值
// 假设游客当前遇到了y号糖果，并且是第x次遇到，那么愉悦值会增加 v[y] * w[x]
// 随着游客遇到各种各样的糖果，愉悦值会不断上升，接下来有q条操作，操作类型如下
// 操作 0 x y : 第x号公园的糖果型号改成y
// 操作 1 x y :
游客从点x出发走过简单路径到达y，依次遇到每个公园的糖果，打印最终的愉悦值
// 1 <= n、m、q <= 10^5
// 1 <= v[i]、w[i] <= 10^6
// 测试链接 : https://www.luogu.com.cn/problem/P4074
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 每条查询 : l、r、t、lca、id
        // 每条修改 : pos、val
        // 递归版，C++可以通过，java会爆栈，需要改迭代
        // 不会改迭代版，去看讲解118，详解了从递归版改迭代版
        // dfs1的迭代版
        // 带修莫队经典排序
        // 窗口不管是加入还是删除node
        // 只要遇到node就翻转信息即可
        // 上节课带修莫队的重要过程
        // tim为生效或者撤销的修改时间点，公园更换糖果
                        // 老糖果invert效果
                        // 新老糖果换位
                        // 新糖果invert效果
                        // 新老糖果换位即可
        // 读写工具类
*/

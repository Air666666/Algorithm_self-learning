// Source: src/class200/Code08_CactusPathFlip1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code08_CactusPathFlip1 {
  inline static int MAXN = 100001;
  inline static int n = {};
  inline static int m = {};
  inline static int q = {};
  inline static int cntn = {};
  inline static Array<int> head1 = make_array<int>(MAXN);
  inline static Array<int> next1 = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> to1 = make_array<int>(jshl(MAXN, 1));
  inline static int cnt1 = {};
  inline static Array<int> head2 = make_array<int>(MAXN);
  inline static Array<int> next2 = make_array<int>(MAXN);
  inline static Array<int> to2 = make_array<int>(MAXN);
  inline static int cnt2 = {};
  inline static Array<int> dfn = make_array<int>(MAXN);
  inline static Array<int> low = make_array<int>(MAXN);
  inline static int cntd = {};
  inline static Array<int> sta = make_array<int>(MAXN);
  inline static int stasiz = {};
  inline static Array<int> fa = make_array<int>(MAXN);
  inline static Array<int> dep = make_array<int>(MAXN);
  inline static Array<int> siz = make_array<int>(MAXN);
  inline static Array<int> son = make_array<int>(MAXN);
  inline static Array<int> top = make_array<int>(MAXN);
  inline static Array<int> belongCycle = make_array<int>(MAXN);
  inline static Array<int> cycleRoot = make_array<int>(MAXN);
  inline static Array<int> pos = make_array<int>(MAXN);
  inline static Array<int> cycleSum = make_array<int>(MAXN);
  inline static Array<int> cyclel = make_array<int>(MAXN);
  inline static Array<int> cycler = make_array<int>(MAXN);
  inline static Array<int> treel = make_array<int>(MAXN);
  inline static Array<int> treer = make_array<int>(MAXN);
  inline static Array<int> dfnType = make_array<int>(MAXN);
  inline static Array<int> all1 = make_array<int>(jshl(MAXN, 2));
  inline static Array<int> black1 = make_array<int>(jshl(MAXN, 2));
  inline static Array<bool> lazy1 = make_array<bool>(jshl(MAXN, 2));
  inline static Array<int> all2 = make_array<int>(jshl(MAXN, 2));
  inline static Array<int> black2 = make_array<int>(jshl(MAXN, 2));
  inline static Array<bool> lazy2 = make_array<bool>(jshl(MAXN, 2));
  inline static Array<int> all3 = make_array<int>(jshl(MAXN, 2));
  inline static Array<int> black3 = make_array<int>(jshl(MAXN, 2));
  inline static Array<bool> lazy3 = make_array<bool>(jshl(MAXN, 2));
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code08_CactusPathFlip1() {}
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
  static void cycleLink(int u, int v) {
    (cntn++);
    (cycleRoot[cntn] = u);
    Code08_CactusPathFlip1::addEdge2(u, cntn);
    int tmp = stasiz;
    int pop = {};
    int cnt = 0;
    do {
      (pop = sta[(tmp--)]);
      (cnt++);
    } while ((pop != v));
    (cycleSum[cntn] = (cnt + 1));
    do {
      (pop = sta[(stasiz--)]);
      (belongCycle[pop] = cntn);
      (pos[pop] = (cnt--));
      Code08_CactusPathFlip1::addEdge2(cntn, pop);
    } while ((pop != v));
  }
  static void tarjan(int u, int preEdge) {
    (dfn[u] = (low[u] = (++cntd)));
    (sta[(++stasiz)] = u);
    for (int e = head1[u]; (e > 0); (e = next1[e])) {
      if (((e ^ 1) == preEdge)) {
        continue;
      }
      int v = to1[e];
      if ((dfn[v] == 0)) {
        Code08_CactusPathFlip1::tarjan(v, e);
        if ((low[v] < dfn[u])) {
          (low[u] = jmin(low[u], low[v]));
        } else if ((low[v] > dfn[u])) {
          (stasiz--);
          Code08_CactusPathFlip1::addEdge2(u, v);
        } else {
          Code08_CactusPathFlip1::cycleLink(u, v);
        }
      } else if ((dfn[v] < dfn[u])) {
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
        Code08_CactusPathFlip1::dfs1(v, u);
        (siz[u] += siz[v]);
        if (((son[u] == 0) || (siz[son[u]] < siz[v]))) {
          (son[u] = v);
        }
      }
    }
  }
  static void cycleDfn(int u) {
    int h = son[u];
    bool near = ((pos[h] * 2) < cycleSum[u]);
    (cyclel[u] = (cntd + 1));
    for (int e = head2[u]; (e > 0); (e = next2[e])) {
      int v = to2[e];
      if (((v != fa[u]) && (v != h))) {
        (dfn[v] = (++cntd));
        if (((near && (pos[v] < pos[h])) || ((!near) && (pos[v] > pos[h])))) {
          (dfnType[cntd] = 1);
        } else {
          (dfnType[cntd] = 2);
        }
      }
    }
    (cycler[u] = cntd);
    (dfn[h] = (++cntd));
  }
  static void dfs2(int u, int t) {
    (top[u] = t);
    if ((dfn[u] == 0)) {
      (dfn[u] = (++cntd));
    }
    if ((u > n)) {
      Code08_CactusPathFlip1::cycleDfn(u);
    }
    if ((u <= n)) {
      (treel[u] = (cntd + 1));
    }
    if ((son[u] != 0)) {
      Code08_CactusPathFlip1::dfs2(son[u], t);
    }
    for (int e = head2[u]; (e > 0); (e = next2[e])) {
      int v = to2[e];
      if (((v != fa[u]) && (v != son[u]))) {
        Code08_CactusPathFlip1::dfs2(v, v);
      }
    }
    if ((u <= n)) {
      (treer[u] = cntd);
    }
  }
  static void up(int i) {
    (all1[i] = (all1[jshl(i, 1)] + all1[(jshl(i, 1) | 1)]));
    (all2[i] = (all2[jshl(i, 1)] + all2[(jshl(i, 1) | 1)]));
    (all3[i] = (all3[jshl(i, 1)] + all3[(jshl(i, 1) | 1)]));
    (black1[i] = (black1[jshl(i, 1)] + black1[(jshl(i, 1) | 1)]));
    (black2[i] = (black2[jshl(i, 1)] + black2[(jshl(i, 1) | 1)]));
    (black3[i] = (black3[jshl(i, 1)] + black3[(jshl(i, 1) | 1)]));
  }
  static void reverse1(int i) {
    (black1[i] = (all1[i] - black1[i]));
    (lazy1[i] = (!lazy1[i]));
  }
  static void reverse2(int i) {
    (black2[i] = (all2[i] - black2[i]));
    (lazy2[i] = (!lazy2[i]));
  }
  static void reverse3(int i) {
    (black3[i] = (all3[i] - black3[i]));
    (lazy3[i] = (!lazy3[i]));
  }
  static void down(int i) {
    if (lazy1[i]) {
      Code08_CactusPathFlip1::reverse1(jshl(i, 1));
      Code08_CactusPathFlip1::reverse1((jshl(i, 1) | 1));
      (lazy1[i] = false);
    }
    if (lazy2[i]) {
      Code08_CactusPathFlip1::reverse2(jshl(i, 1));
      Code08_CactusPathFlip1::reverse2((jshl(i, 1) | 1));
      (lazy2[i] = false);
    }
    if (lazy3[i]) {
      Code08_CactusPathFlip1::reverse3(jshl(i, 1));
      Code08_CactusPathFlip1::reverse3((jshl(i, 1) | 1));
      (lazy3[i] = false);
    }
  }
  static void build(int l, int r, int i) {
    if ((l == r)) {
      if ((dfnType[l] == 1)) {
        (all1[i] = (black1[i] = 1));
      }
      if ((dfnType[l] == 2)) {
        (all2[i] = (black2[i] = 1));
      }
      if ((dfnType[l] == 3)) {
        (all3[i] = (black3[i] = 1));
      }
    } else {
      int mid = jshr((l + r), 1);
      Code08_CactusPathFlip1::build(l, mid, jshl(i, 1));
      Code08_CactusPathFlip1::build((mid + 1), r, (jshl(i, 1) | 1));
      Code08_CactusPathFlip1::up(i);
    }
  }
  static void reverse(int jobl, int jobr, int jobt, int l, int r, int i) {
    if ((jobl > jobr)) {
      return;
    }
    if (((jobl <= l) && (r <= jobr))) {
      if (((jobt == 1) || (jobt == 3))) {
        Code08_CactusPathFlip1::reverse1(i);
      }
      if (((jobt == 2) || (jobt == 3))) {
        Code08_CactusPathFlip1::reverse2(i);
      }
      Code08_CactusPathFlip1::reverse3(i);
      return;
    }
    Code08_CactusPathFlip1::down(i);
    int mid = jshr((l + r), 1);
    if ((jobl <= mid)) {
      Code08_CactusPathFlip1::reverse(jobl, jobr, jobt, l, mid, jshl(i, 1));
    }
    if ((mid < jobr)) {
      Code08_CactusPathFlip1::reverse(jobl, jobr, jobt, (mid + 1), r,
                                      (jshl(i, 1) | 1));
    }
    Code08_CactusPathFlip1::up(i);
  }
  static int query(int jobl, int jobr, int l, int r, int i) {
    if ((jobl > jobr)) {
      return 0;
    }
    if (((jobl <= l) && (r <= jobr))) {
      return ((black1[i] + black2[i]) + black3[i]);
    }
    Code08_CactusPathFlip1::down(i);
    int mid = jshr((l + r), 1);
    int ans = 0;
    if ((jobl <= mid)) {
      (ans += Code08_CactusPathFlip1::query(jobl, jobr, l, mid, jshl(i, 1)));
    }
    if ((mid < jobr)) {
      (ans += Code08_CactusPathFlip1::query(jobl, jobr, (mid + 1), r,
                                            (jshl(i, 1) | 1)));
    }
    return ans;
  }
  static void flipCycle(int u, int x, int op) {
    int h = son[u];
    bool near = ((pos[x] * 2) < cycleSum[u]);
    if (((near && (op == 1)) || ((!near) && (op == 2)))) {
      Code08_CactusPathFlip1::reverse(cyclel[u], dfn[x], 3, 1, cntn, 1);
      if ((pos[h] < pos[x])) {
        Code08_CactusPathFlip1::reverse(dfn[h], dfn[h], 3, 1, cntn, 1);
      }
    } else {
      Code08_CactusPathFlip1::reverse(dfn[x], cycler[u], 3, 1, cntn, 1);
      if ((pos[h] > pos[x])) {
        Code08_CactusPathFlip1::reverse(dfn[h], dfn[h], 3, 1, cntn, 1);
      }
    }
  }
  static void flip(int x, int op) {
    while ((x != 0)) {
      int xtop = top[x];
      if (((xtop > n) || (belongCycle[xtop] == 0))) {
        Code08_CactusPathFlip1::reverse(dfn[xtop], dfn[x], op, 1, cntn, 1);
        (x = fa[xtop]);
      } else {
        if ((x != xtop)) {
          Code08_CactusPathFlip1::reverse(dfn[son[xtop]], dfn[x], op, 1, cntn,
                                          1);
          (x = xtop);
        }
        Code08_CactusPathFlip1::flipCycle(belongCycle[x], x, op);
        (x = cycleRoot[belongCycle[x]]);
      }
    }
  }
  static void prepare() {
    Code08_CactusPathFlip1::tarjan(1, 0);
    (cntd = 0);
    for (int i = 1; (i <= n); (i++)) {
      (dfn[i] = 0);
    }
    Code08_CactusPathFlip1::dfs1(1, 0);
    Code08_CactusPathFlip1::dfs2(1, 1);
    for (int i = 1; (i <= n); (i++)) {
      if ((dfnType[dfn[i]] == 0)) {
        (dfnType[dfn[i]] = 3);
      }
    }
    Code08_CactusPathFlip1::build(1, cntn, 1);
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (m = in.nextInt());
    (q = in.nextInt());
    (cntn = n);
    (cnt1 = 1);
    {
      int i = 1;
      int u = {};
      int v = {};
      for (; (i <= m); (i++)) {
        (u = in.nextInt());
        (v = in.nextInt());
        Code08_CactusPathFlip1::addEdge1(u, v);
        Code08_CactusPathFlip1::addEdge1(v, u);
      }
    }
    Code08_CactusPathFlip1::prepare();
    {
      int i = 1;
      int op = {};
      int x = {};
      for (; (i <= q); (i++)) {
        (op = in.nextInt());
        (x = in.nextInt());
        if (((op == 1) || (op == 2))) {
          Code08_CactusPathFlip1::flip(x, op);
        } else {
          int ans = Code08_CactusPathFlip1::query(dfn[x], dfn[x], 1, cntn, 1);
          (ans +=
           Code08_CactusPathFlip1::query(treel[x], treer[x], 1, cntn, 1));
          out.println(ans);
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
  Code08_CactusPathFlip1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 仙人掌路径翻转，java版
// 给定n个点、m条边的仙人掌图，没有自环，没有重边，1号节点是仙人掌的根
// 输入保证每个简单环的边数都为奇数，所以点x到根的最短路和最长路都是唯一的
// 以点x为头的子仙人掌，是指删掉根到x路径上的边后，包含x的连通块
// 每个节点只有黑白两种颜色，初始时所有节点为黑，一共有q条操作，类型如下
// 操作 1 x : 点x到根的最短路上所有节点，颜色翻转
// 操作 2 x : 点x到根的最长路上所有节点，颜色翻转
// 操作 3 x : 查询以点x为头的子仙人掌中，黑色节点的数量
// 1 <= n、m、q <= 5 * 10^4
// 测试链接 : https://uoj.ac/problem/158
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 原图
        // 圆方树
        // tarjan算法
        // 树链剖分
        // 仙人掌中，一个节点可能是多个环的环顶，但不做环顶的话，最多参与一个环
        // belongCycle[x]，表示节点x归属的环，x不是环顶节点
        // 环顶节点，只对方点有意义
        // 圆点在环中的位置
        // 环的边数
        // 除了环顶和重儿子之外，环中圆点的dfn编号范围，只对方点有意义
        // 子树上，所有后代节点的dfn编号范围，只对圆点有意义
        // dfnType[x] = 0，dfn序号为x的节点是方点
        // dfnType[x] =
1，dfn序号为x的节点是圆点，位于环顶到环中重儿子的短路径侧
        // dfnType[x] =
2，dfn序号为x的节点是圆点，位于环顶到环中重儿子的长路径侧
        // dfnType[x] =
3，dfn序号为x的节点是圆点，如果不是1或2类型，那就是3类型，表示必经点
        // 必经点的情况比较多，可能是环中重儿子 或者 只做环顶 或者 不参与任何环
        // 总之无论短路径还是长路径，通过重链向上必经的点，就算3类型
        // 短路径线段树
        // 长路径线段树
        // 必经点线段树
        // 读写工具类
*/

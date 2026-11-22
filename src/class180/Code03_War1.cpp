// Source: src/class180/Code03_War1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_War1 {
  inline static int MAXN = 500001;
  inline static int MAXP = 20;
  inline static int n = {};
  inline static int q = {};
  inline static int k = {};
  inline static Array<int> headg = make_array<int>(MAXN);
  inline static Array<int> nextg = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> tog = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> weightg = make_array<int>(jshl(MAXN, 1));
  inline static int cntg = {};
  inline static Array<int> headv = make_array<int>(MAXN);
  inline static Array<int> nextv = make_array<int>(MAXN);
  inline static Array<int> tov = make_array<int>(MAXN);
  inline static Array<int> weightv = make_array<int>(MAXN);
  inline static int cntv = {};
  inline static Array<int> dep = make_array<int>(MAXN);
  inline static Array<int> dfn = make_array<int>(MAXN);
  inline static Array<Array<int>> stjump = make_array<int>(MAXN, MAXP);
  inline static Array<Array<int>> mindist = make_array<int>(MAXN, MAXP);
  inline static int cntd = {};
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static Array<bool> isKey = make_array<bool>(MAXN);
  inline static Array<int> tmp = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> stk = make_array<int>(MAXN);
  inline static Array<i64> cost = make_array<i64>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_War1() {}
  static void addEdgeG(int u, int v, int w) {
    (nextg[(++cntg)] = headg[u]);
    (tog[cntg] = v);
    (weightg[cntg] = w);
    (headg[u] = cntg);
  }
  static void addEdgeV(int u, int v, int w) {
    (nextv[(++cntv)] = headv[u]);
    (tov[cntv] = v);
    (weightv[cntv] = w);
    (headv[u] = cntv);
  }
  static void sortByDfn(Array<int> nums, int l, int r) {
    if ((l >= r))
      return;
    int i = l;
    int j = r;
    int pivot = nums[jshr((l + r), 1)];
    while ((i <= j)) {
      while ((dfn[nums[i]] < dfn[pivot]))
        (i++);
      while ((dfn[nums[j]] > dfn[pivot]))
        (j--);
      if ((i <= j)) {
        int tmp = nums[i];
        (nums[i] = nums[j]);
        (nums[j] = tmp);
        (i++);
        (j--);
      }
    }
    Code03_War1::sortByDfn(nums, l, j);
    Code03_War1::sortByDfn(nums, i, r);
  }
  static void dfs(int u, int fa, int w) {
    (dep[u] = (dep[fa] + 1));
    (dfn[u] = (++cntd));
    (stjump[u][0] = fa);
    (mindist[u][0] = w);
    for (int p = 1; (p < MAXP); (p++)) {
      (stjump[u][p] = stjump[stjump[u][(p - 1)]][(p - 1)]);
      (mindist[u][p] =
           jmin(mindist[u][(p - 1)], mindist[stjump[u][(p - 1)]][(p - 1)]));
    }
    for (int e = headg[u]; (e > 0); (e = nextg[e])) {
      if ((tog[e] != fa)) {
        Code03_War1::dfs(tog[e], u, weightg[e]);
      }
    }
  }
  static int getLca(int a, int b) {
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
  static int getDist(int u, int v) {
    int dist = 100000001;
    for (int p = (MAXP - 1); (p >= 0); (p--)) {
      if ((dep[stjump[v][p]] >= dep[u])) {
        (dist = jmin(dist, mindist[v][p]));
        (v = stjump[v][p]);
      }
    }
    return dist;
  }
  static int buildVirtualTree1() {
    Code03_War1::sortByDfn(arr, 1, k);
    int len = 0;
    (tmp[(++len)] = 1);
    for (int i = 1; (i < k); (i++)) {
      (tmp[(++len)] = arr[i]);
      (tmp[(++len)] = Code03_War1::getLca(arr[i], arr[(i + 1)]));
    }
    (tmp[(++len)] = arr[k]);
    Code03_War1::sortByDfn(tmp, 1, len);
    int unique = 1;
    for (int i = 2; (i <= len); (i++)) {
      if ((tmp[unique] != tmp[i])) {
        (tmp[(++unique)] = tmp[i]);
      }
    }
    (cntv = 0);
    for (int i = 1; (i <= unique); (i++)) {
      (headv[tmp[i]] = 0);
    }
    for (int i = 1; (i < unique); (i++)) {
      int lca = Code03_War1::getLca(tmp[i], tmp[(i + 1)]);
      Code03_War1::addEdgeV(lca, tmp[(i + 1)],
                            Code03_War1::getDist(lca, tmp[(i + 1)]));
    }
    return tmp[1];
  }
  static int buildVirtualTree2() {
    Code03_War1::sortByDfn(arr, 1, k);
    (cntv = 0);
    (headv[1] = 0);
    int top = 0;
    (stk[(++top)] = 1);
    for (int i = 1; (i <= k); (i++)) {
      int x = arr[i];
      int y = stk[top];
      int lca = Code03_War1::getLca(x, y);
      while (((top > 1) && (dfn[stk[(top - 1)]] >= dfn[lca]))) {
        Code03_War1::addEdgeV(stk[(top - 1)], stk[top],
                              Code03_War1::getDist(stk[(top - 1)], stk[top]));
        (top--);
      }
      if ((lca != stk[top])) {
        (headv[lca] = 0);
        Code03_War1::addEdgeV(lca, stk[top],
                              Code03_War1::getDist(lca, stk[top]));
        (stk[top] = lca);
      }
      (headv[x] = 0);
      (stk[(++top)] = x);
    }
    while ((top > 1)) {
      Code03_War1::addEdgeV(stk[(top - 1)], stk[top],
                            Code03_War1::getDist(stk[(top - 1)], stk[top]));
      (top--);
    }
    return stk[1];
  }
  static void dp(int u) {
    for (int e = headv[u]; (e > 0); (e = nextv[e])) {
      Code03_War1::dp(tov[e]);
    }
    (cost[u] = 0);
    {
      int e = headv[u];
      int v = {};
      int w = {};
      for (; (e > 0); (e = nextv[e])) {
        (v = tov[e]);
        (w = weightv[e]);
        if (isKey[v]) {
          (cost[u] += w);
        } else {
          (cost[u] += jmin(cost[v], w));
        }
      }
    }
  }
  static i64 compute() {
    for (int i = 1; (i <= k); (i++)) {
      (isKey[arr[i]] = true);
    }
    int tree = Code03_War1::buildVirtualTree1();
    Code03_War1::dp(tree);
    for (int i = 1; (i <= k); (i++)) {
      (isKey[arr[i]] = false);
    }
    return cost[tree];
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    {
      int i = 1;
      int u = {};
      int v = {};
      int w = {};
      for (; (i < n); (i++)) {
        (u = in.nextInt());
        (v = in.nextInt());
        (w = in.nextInt());
        Code03_War1::addEdgeG(u, v, w);
        Code03_War1::addEdgeG(v, u, w);
      }
    }
    Code03_War1::dfs(1, 0, 0);
    (q = in.nextInt());
    for (int t = 1; (t <= q); (t++)) {
      (k = in.nextInt());
      for (int i = 1; (i <= k); (i++)) {
        (arr[i] = in.nextInt());
      }
      out.println(Code03_War1::compute());
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code03_War1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 消耗战，java版
// 一共有n个节点，给定n-1条无向边，每条边有边权，所有节点组成一棵树
// 一共有q条查询，每条查询格式如下
// 查询 k a1 a2 ... ak : 给出了k个不同的关键节点，并且一定不包含1号节点
//                       你可以随意选择边进行切断，切断的代价就是边权
//                       目的是让所有关键点都无法到达1号节点，打印最小总代价
// 1 <= n、q <= 5 * 10^5
// 1 <= 所有查询给出的点的总数 <= 5 * 10^5
// 测试链接 : https://www.luogu.com.cn/problem/P2495
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 上方最小距离的倍增表
        // cost[u]表示虚树中，u下方的所有关键节点，都连不上u的话，最小总代价
        // 已知u一定是v的祖先节点，返回u到v路径上的最小边权
        // 二次排序 + LCA连边的方式建立虚树
                // 因为题目是让所有关键点不能和1号点连通
                // 所以一定要让1号点加入
        // 单调栈的方式建立虚树
                // 因为题目是让所有关键点不能和1号点连通
                // 所以一定要让1号点加入
                // int tree = buildVirtualTree2();
        // 读写工具类
*/

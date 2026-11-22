// Source: src/class200/Code07_MaximumOfShortestPath1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code07_MaximumOfShortestPath1 {
  inline static int MAXN = 600001;
  inline static int n = {};
  inline static int m = {};
  inline static int q = {};
  inline static int k = {};
  inline static int cntn = {};
  inline static Array<int> head1 = make_array<int>(MAXN);
  inline static Array<int> next1 = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> to1 = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> weight1 = make_array<int>(jshl(MAXN, 1));
  inline static int cnt1 = {};
  inline static Array<int> head2 = make_array<int>(MAXN);
  inline static Array<int> next2 = make_array<int>(MAXN);
  inline static Array<int> to2 = make_array<int>(MAXN);
  inline static Array<i64> weight2 = make_array<i64>(MAXN);
  inline static int cnt2 = {};
  inline static Array<int> head3 = make_array<int>(MAXN);
  inline static Array<int> next3 = make_array<int>(MAXN);
  inline static Array<int> to3 = make_array<int>(MAXN);
  inline static int cnt3 = {};
  inline static Array<int> dfn = make_array<int>(MAXN);
  inline static Array<int> low = make_array<int>(MAXN);
  inline static int cntd = {};
  inline static Array<int> sta = make_array<int>(MAXN);
  inline static int stasiz = {};
  inline static Array<i64> fromWeight = make_array<i64>(MAXN);
  inline static Array<i64> cycleLen = make_array<i64>(MAXN);
  inline static Array<i64> cycleSum = make_array<i64>(MAXN);
  inline static Array<int> fa = make_array<int>(MAXN);
  inline static Array<int> dep = make_array<int>(MAXN);
  inline static Array<int> siz = make_array<int>(MAXN);
  inline static Array<i64> len = make_array<i64>(MAXN);
  inline static Array<int> son = make_array<int>(MAXN);
  inline static Array<int> top = make_array<int>(MAXN);
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static Array<int> tmp = make_array<int>(MAXN);
  inline static Array<i64> dist = make_array<i64>(MAXN);
  inline static i64 diameter = {};
  inline static Array<int> idx = make_array<int>(MAXN);
  inline static Array<i64> pre = make_array<i64>(MAXN);
  inline static Array<i64> val = make_array<i64>(MAXN);
  inline static Array<int> que = make_array<int>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code07_MaximumOfShortestPath1() {}
  static void addEdge1(int u, int v, int w) {
    (next1[(++cnt1)] = head1[u]);
    (to1[cnt1] = v);
    (weight1[cnt1] = w);
    (head1[u] = cnt1);
  }
  static void addEdge2(int u, int v, i64 w) {
    (next2[(++cnt2)] = head2[u]);
    (to2[cnt2] = v);
    (weight2[cnt2] = w);
    (head2[u] = cnt2);
  }
  static void addEdge3(int u, int v) {
    (next3[(++cnt3)] = head3[u]);
    (to3[cnt3] = v);
    (head3[u] = cnt3);
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
    Code07_MaximumOfShortestPath1::sortByDfn(nums, l, j);
    Code07_MaximumOfShortestPath1::sortByDfn(nums, i, r);
  }
  static void sortByLen(Array<int> nums, int l, int r) {
    if ((l >= r))
      return;
    int i = l;
    int j = r;
    int pivot = nums[jshr((l + r), 1)];
    while ((i <= j)) {
      while ((cycleLen[nums[i]] < cycleLen[pivot]))
        (i++);
      while ((cycleLen[nums[j]] > cycleLen[pivot]))
        (j--);
      if ((i <= j)) {
        int tmp = nums[i];
        (nums[i] = nums[j]);
        (nums[j] = tmp);
        (i++);
        (j--);
      }
    }
    Code07_MaximumOfShortestPath1::sortByLen(nums, l, j);
    Code07_MaximumOfShortestPath1::sortByLen(nums, i, r);
  }
  static void cycleLink(int u, int v) {
    (cntn++);
    (cycleSum[cntn] = fromWeight[u]);
    Code07_MaximumOfShortestPath1::addEdge2(u, cntn, 0);
    int tmp = stasiz;
    int pop = {};
    do {
      (pop = sta[(tmp--)]);
      (cycleLen[pop] = cycleSum[cntn]);
      (cycleSum[cntn] += fromWeight[pop]);
    } while ((pop != v));
    do {
      (pop = sta[(stasiz--)]);
      Code07_MaximumOfShortestPath1::addEdge2(
          cntn, pop, jmin(cycleLen[pop], (cycleSum[cntn] - cycleLen[pop])));
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
      i64 w = weight1[e];
      if ((dfn[v] == 0)) {
        Code07_MaximumOfShortestPath1::tarjan(v, e);
        (fromWeight[v] = w);
        if ((low[v] < dfn[u])) {
          (low[u] = jmin(low[u], low[v]));
        } else if ((low[v] > dfn[u])) {
          (stasiz--);
          Code07_MaximumOfShortestPath1::addEdge2(u, v, w);
        } else {
          Code07_MaximumOfShortestPath1::cycleLink(u, v);
        }
      } else if ((dfn[v] < dfn[u])) {
        (fromWeight[v] = w);
        (low[u] = jmin(low[u], dfn[v]));
      }
    }
  }
  static void dfs1(int u, int f, i64 l) {
    (fa[u] = f);
    (dep[u] = (dep[f] + 1));
    (siz[u] = 1);
    (len[u] = l);
    {
      int e = head2[u];
      int v = {};
      for (; (e > 0); (e = next2[e])) {
        (v = to2[e]);
        if ((v != f)) {
          Code07_MaximumOfShortestPath1::dfs1(v, u, (len[u] + weight2[e]));
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
    if ((son[u] != 0)) {
      Code07_MaximumOfShortestPath1::dfs2(son[u], t);
    }
    for (int e = head2[u]; (e > 0); (e = next2[e])) {
      int v = to2[e];
      if (((v != fa[u]) && (v != son[u]))) {
        Code07_MaximumOfShortestPath1::dfs2(v, v);
      }
    }
  }
  static int lca(int a, int b) {
    while ((top[a] != top[b])) {
      if ((dep[top[a]] <= dep[top[b]])) {
        (b = fa[top[b]]);
      } else {
        (a = fa[top[a]]);
      }
    }
    return ((dep[a] <= dep[b]) ? a : b);
  }
  static int find(int x, int square) {
    int pre = 0;
    while ((top[x] != top[square])) {
      (pre = top[x]);
      (x = fa[pre]);
    }
    return ((x == square) ? pre : son[square]);
  }
  static int buildVirtualTree() {
    Code07_MaximumOfShortestPath1::sortByDfn(arr, 1, k);
    int len = 0;
    for (int i = 1; (i < k); (i++)) {
      (tmp[(++len)] = arr[i]);
      (tmp[(++len)] = Code07_MaximumOfShortestPath1::lca(arr[i], arr[(i + 1)]));
    }
    (tmp[(++len)] = arr[k]);
    Code07_MaximumOfShortestPath1::sortByDfn(tmp, 1, len);
    int unique = 1;
    for (int i = 2; (i <= len); (i++)) {
      if ((tmp[unique] != tmp[i])) {
        (tmp[(++unique)] = tmp[i]);
      }
    }
    (cnt3 = 0);
    for (int i = 1; (i <= unique); (i++)) {
      (head3[tmp[i]] = 0);
    }
    for (int i = 1; (i < unique); (i++)) {
      Code07_MaximumOfShortestPath1::addEdge3(
          Code07_MaximumOfShortestPath1::lca(tmp[i], tmp[(i + 1)]),
          tmp[(i + 1)]);
    }
    return tmp[1];
  }
  static void computeOnCycle(int u, int siz) {
    Code07_MaximumOfShortestPath1::sortByLen(idx, 1, siz);
    for (int i = 1; (i <= siz); (i++)) {
      (pre[i] = cycleLen[idx[i]]);
      (pre[(i + siz)] = (pre[i] + cycleSum[u]));
      (val[i] = dist[idx[i]]);
      (val[(i + siz)] = val[i]);
    }
    int l = 1;
    int r = 0;
    for (int i = 1; (i <= (siz * 2)); (i++)) {
      while (((l <= r) && (((pre[i] - pre[que[l]]) * 2) > cycleSum[u]))) {
        (l++);
      }
      if ((l <= r)) {
        (diameter =
             jmax(diameter, (((val[que[l]] - pre[que[l]]) + val[i]) + pre[i])));
      }
      while (((l <= r) && ((val[que[r]] - pre[que[r]]) <= (val[i] - pre[i])))) {
        (r--);
      }
      (que[(++r)] = i);
    }
  }
  static void dpOnTree(int u) {
    (dist[u] = 0);
    if ((u <= n)) {
      for (int e = head3[u]; (e > 0); (e = next3[e])) {
        int v = to3[e];
        Code07_MaximumOfShortestPath1::dpOnTree(v);
        (diameter = jmax(diameter, (((dist[u] + dist[v]) + len[v]) - len[u])));
        (dist[u] = jmax(dist[u], ((dist[v] + len[v]) - len[u])));
      }
    } else {
      for (int e = head3[u]; (e > 0); (e = next3[e])) {
        int v = to3[e];
        Code07_MaximumOfShortestPath1::dpOnTree(v);
      }
      int siz = 0;
      for (int e = head3[u]; (e > 0); (e = next3[e])) {
        int v = to3[e];
        int f = Code07_MaximumOfShortestPath1::find(v, u);
        (dist[f] = ((dist[v] + len[v]) - len[f]));
        (idx[(++siz)] = f);
        (dist[u] = jmax(dist[u], ((dist[v] + len[v]) - len[u])));
      }
      Code07_MaximumOfShortestPath1::computeOnCycle(u, siz);
    }
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
      int w = {};
      for (; (i <= m); (i++)) {
        (u = in.nextInt());
        (v = in.nextInt());
        (w = in.nextInt());
        Code07_MaximumOfShortestPath1::addEdge1(u, v, w);
        Code07_MaximumOfShortestPath1::addEdge1(v, u, w);
      }
    }
    Code07_MaximumOfShortestPath1::tarjan(1, 0);
    (cntd = 0);
    Code07_MaximumOfShortestPath1::dfs1(1, 0, 0);
    Code07_MaximumOfShortestPath1::dfs2(1, 1);
    (q = in.nextInt());
    for (int i = 1; (i <= q); (i++)) {
      (k = in.nextInt());
      for (int j = 1; (j <= k); (j++)) {
        (arr[j] = in.nextInt());
      }
      (diameter = 0);
      int tree = Code07_MaximumOfShortestPath1::buildVirtualTree();
      Code07_MaximumOfShortestPath1::dpOnTree(tree);
      out.println(diameter);
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code07_MaximumOfShortestPath1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 最短路最大值，java版
// 给定n个点、m条边的仙人掌图，每条边有边权，没有自环，可能有重边
// 一共q条查询，格式 k a1 a2 .. ak 含义如下
// 给定的k个点中，任意选两个点，可以选择相同点
// 打印它们之间最短路的最大值是多少
// 1 <= n、查询中k的总和 <= 3 * 10^5
// 测试链接 : https://uoj.ac/problem/87
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 原图
        // 圆方树
        // 虚树
        // dfn数组，tarjan和树剖都要使用
        // 环的信息
        // 树链剖分
        // 批量节点
        // dist[u] : 以u为头的树，u到任意点的最短路距离的最大值
        // 单调队列
        // 虚树的建立方式，二次排序 + 相邻LCA连边
                        // 注意，下面的for循环，不能和上面的for循环合并处理
                        // 因为idx是全局数组，此时u是方点，会收集环上的相关节点
                        // 如果边递归边收集idx，那么当前已经写入的idx[1..siz]
                        // 可能会被孩子的递归过程覆盖掉，导致idx收集脏数据
                        // 所以先执行所有孩子的递归，再收集环上节点
        // 读写工具类
*/

// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P3233

// Source: src/class180/Code04_WorldTree1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_WorldTree1 {
  inline static int MAXN = 300001;
  inline static int MAXP = 20;
  inline static int n = {};
  inline static int q = {};
  inline static int k = {};
  inline static Array<int> headg = make_array<int>(MAXN);
  inline static Array<int> nextg = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> tog = make_array<int>(jshl(MAXN, 1));
  inline static int cntg = {};
  inline static Array<int> headv = make_array<int>(MAXN);
  inline static Array<int> nextv = make_array<int>(MAXN);
  inline static Array<int> tov = make_array<int>(MAXN);
  inline static int cntv = {};
  inline static Array<int> dep = make_array<int>(MAXN);
  inline static Array<int> siz = make_array<int>(MAXN);
  inline static Array<int> dfn = make_array<int>(MAXN);
  inline static Array<Array<int>> stjump = make_array<int>(MAXN, MAXP);
  inline static int cntd = {};
  inline static Array<int> order = make_array<int>(MAXN);
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static Array<bool> isKey = make_array<bool>(MAXN);
  inline static Array<int> tmp = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> manager = make_array<int>(MAXN);
  inline static Array<int> dist = make_array<int>(MAXN);
  inline static Array<int> ans = make_array<int>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_WorldTree1() {}
  static void addEdgeG(int u, int v) {
    (nextg[(++cntg)] = headg[u]);
    (tog[cntg] = v);
    (headg[u] = cntg);
  }
  static void addEdgeV(int u, int v) {
    (nextv[(++cntv)] = headv[u]);
    (tov[cntv] = v);
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
    Code04_WorldTree1::sortByDfn(nums, l, j);
    Code04_WorldTree1::sortByDfn(nums, i, r);
  }
  static void dfs(int u, int fa) {
    (dep[u] = (dep[fa] + 1));
    (siz[u] = 1);
    (dfn[u] = (++cntd));
    (stjump[u][0] = fa);
    for (int p = 1; (p < MAXP); (p++)) {
      (stjump[u][p] = stjump[stjump[u][(p - 1)]][(p - 1)]);
    }
    for (int e = headg[u]; (e > 0); (e = nextg[e])) {
      int v = tog[e];
      if ((v != fa)) {
        Code04_WorldTree1::dfs(v, u);
        (siz[u] += siz[v]);
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
  static int buildVirtualTree() {
    Code04_WorldTree1::sortByDfn(arr, 1, k);
    int len = 0;
    (tmp[(++len)] = 1);
    for (int i = 1; (i < k); (i++)) {
      (tmp[(++len)] = arr[i]);
      (tmp[(++len)] = Code04_WorldTree1::getLca(arr[i], arr[(i + 1)]));
    }
    (tmp[(++len)] = arr[k]);
    Code04_WorldTree1::sortByDfn(tmp, 1, len);
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
      Code04_WorldTree1::addEdgeV(
          Code04_WorldTree1::getLca(tmp[i], tmp[(i + 1)]), tmp[(i + 1)]);
    }
    return tmp[1];
  }
  static void dp1(int u) {
    (dist[u] = 1000000001);
    for (int e = headv[u]; (e > 0); (e = nextv[e])) {
      int v = tov[e];
      Code04_WorldTree1::dp1(v);
      int w = (dep[v] - dep[u]);
      if ((((dist[v] + w) < dist[u]) ||
           (((dist[v] + w) == dist[u]) && (manager[v] < manager[u])))) {
        (dist[u] = (dist[v] + w));
        (manager[u] = manager[v]);
      }
    }
    if (isKey[u]) {
      (dist[u] = 0);
      (manager[u] = u);
    }
  }
  static void dp2(int u) {
    for (int e = headv[u]; (e > 0); (e = nextv[e])) {
      int v = tov[e];
      int w = (dep[v] - dep[u]);
      if ((((dist[u] + w) < dist[v]) ||
           (((dist[u] + w) == dist[v]) && (manager[u] < manager[v])))) {
        (dist[v] = (dist[u] + w));
        (manager[v] = manager[u]);
      }
      Code04_WorldTree1::dp2(v);
    }
  }
  static void amend(int u, int v) {
    if ((manager[u] == manager[v])) {
      return;
    }
    int x = v;
    for (int p = (MAXP - 1); (p >= 0); (p--)) {
      int jump = stjump[x][p];
      if ((dep[u] < dep[jump])) {
        int tou = ((dep[jump] - dep[u]) + dist[u]);
        int tov = ((dep[v] - dep[jump]) + dist[v]);
        if (((tov < tou) || ((tov == tou) && (manager[v] < manager[u])))) {
          (x = jump);
        }
      }
    }
    int delta = (siz[x] - siz[v]);
    (ans[manager[u]] -= delta);
    (ans[manager[v]] += delta);
  }
  static void dp3(int u) {
    (ans[manager[u]] += siz[u]);
    for (int e = headv[u]; (e > 0); (e = nextv[e])) {
      int v = tov[e];
      Code04_WorldTree1::amend(u, v);
      (ans[manager[u]] -= siz[v]);
      Code04_WorldTree1::dp3(v);
    }
  }
  static void compute() {
    for (int i = 1; (i <= k); (i++)) {
      (arr[i] = order[i]);
    }
    for (int i = 1; (i <= k); (i++)) {
      (isKey[arr[i]] = true);
      (ans[arr[i]] = 0);
    }
    int tree = Code04_WorldTree1::buildVirtualTree();
    Code04_WorldTree1::dp1(tree);
    Code04_WorldTree1::dp2(tree);
    Code04_WorldTree1::dp3(tree);
    for (int i = 1; (i <= k); (i++)) {
      (isKey[arr[i]] = false);
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    {
      int i = 1;
      int u = {};
      int v = {};
      for (; (i < n); (i++)) {
        (u = in.nextInt());
        (v = in.nextInt());
        Code04_WorldTree1::addEdgeG(u, v);
        Code04_WorldTree1::addEdgeG(v, u);
      }
    }
    Code04_WorldTree1::dfs(1, 0);
    (q = in.nextInt());
    for (int t = 1; (t <= q); (t++)) {
      (k = in.nextInt());
      for (int i = 1; (i <= k); (i++)) {
        (order[i] = in.nextInt());
      }
      Code04_WorldTree1::compute();
      for (int i = 1; (i <= k); (i++)) {
        out.print((ans[order[i]] + String(u" ")));
      }
      out.println();
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code04_WorldTree1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 世界树，java版
// 一共有n个节点，给定n-1条无向边，所有节点组成一棵树
// 一共有q条查询，每条查询格式如下
// 查询 k a1 a2 ... ak :
给出了k个不同的管理点，树上每个点都找最近的管理点来管理自己
//                       如果某个节点的最近管理点有多个，选择编号最小的管理点
//                       打印每个管理点，管理的节点数量
// 1 <= n、q <= 3 * 10^5
// 1 <= 所有查询给出的点的总数 <= 3 * 10^5
// 测试链接 : https://www.luogu.com.cn/problem/P3233
// 提交以下的code，提交时请把类名改成"Main"
// 本题递归函数较多，java版不改成迭代会爆栈，导致无法通过
// 但是这种改动没啥价值，因为和算法无关，纯粹语言歧视，索性不改了
// 想通过用C++实现，本节课Code04_WorldTree2文件就是C++的实现
// 两个版本的逻辑完全一样，C++版本可以通过所有测试
        // 注意siz[u]表示在原树里，子树u有几个节点
        // manager[u]表示u节点找到的最近管理点
        // dist[u]表示u节点到最近管理点的距离
        // ans[i]表示i这个管理点，管理了几个点
                // 一定要加入1号点
                // 因为题目问的是所有节点的归属问题
        // 下方找最近管理点，节点u根据孩子的管理点，找到离u最近的管理点
        //
上方找最近管理点，根据u找到的最近管理点，更新每个孩子节点v的最近管理点
        // 已知u一定是v的祖先节点，u到v之间的大量节点没有被纳入到虚树
        // 这部分节点之前都分配给了manager[u]，现在根据最近距离做重新分配
        // 可能若干节点会重新分配给manager[v]，修正相关的计数
        // 每个点都有了最近的管理点，更新相关管理点的管理节点计数
                // u的管理节点，先获得原树里子树u的所有节点
                // 然后经历修正的过程，把管理节点的数量更新正确
                        // 修正的过程
                        // 马上要执行dp3(v)，所以子树v的节点现在扣除
                        // 子树v怎么分配节点，那是后续dp3(v)的事情
        // 读写工具类
*/

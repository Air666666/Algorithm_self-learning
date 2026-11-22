// Source: src/class185/Code03_AtmTree1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_AtmTree1 {
  inline static int MAXN = 20001;
  inline static int MAXP = 18;
  inline static int MAXT = 1000001;
  inline static int n = {};
  inline static int k = {};
  inline static int sumw = {};
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> nxt = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> to = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> weight = make_array<int>(jshl(MAXN, 1));
  inline static int cntg = {};
  inline static Array<int> dep = make_array<int>(MAXN);
  inline static Array<int> dist = make_array<int>(MAXN);
  inline static Array<Array<int>> stjump = make_array<int>(MAXN, MAXP);
  inline static Array<bool> vis = make_array<bool>(MAXN);
  inline static Array<int> siz = make_array<int>(MAXN);
  inline static Array<int> centfa = make_array<int>(MAXN);
  inline static Array<int> addTree = make_array<int>(MAXN);
  inline static Array<int> minusTree = make_array<int>(MAXN);
  inline static Array<int> ls = make_array<int>(MAXT);
  inline static Array<int> rs = make_array<int>(MAXT);
  inline static Array<int> sum = make_array<int>(MAXT);
  inline static int cntt = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_AtmTree1() {}
  static void addEdge(int u, int v, int w) {
    (nxt[(++cntg)] = head[u]);
    (to[cntg] = v);
    (weight[cntg] = w);
    (head[u] = cntg);
  }
  static void dfs(int u, int fa, int dis) {
    (dep[u] = (dep[fa] + 1));
    (dist[u] = dis);
    (stjump[u][0] = fa);
    for (int p = 1; (p < MAXP); (p++)) {
      (stjump[u][p] = stjump[stjump[u][(p - 1)]][(p - 1)]);
    }
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      int v = to[e];
      int w = weight[e];
      if ((v != fa)) {
        Code03_AtmTree1::dfs(v, u, (dis + w));
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
  static int getDist(int x, int y) {
    return ((dist[x] + dist[y]) - jshl(dist[Code03_AtmTree1::getLca(x, y)], 1));
  }
  static void getSize(int u, int fa) {
    (siz[u] = 1);
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      int v = to[e];
      if (((v != fa) && (!vis[v]))) {
        Code03_AtmTree1::getSize(v, u);
        (siz[u] += siz[v]);
      }
    }
  }
  static int getCentroid(int u, int fa) {
    Code03_AtmTree1::getSize(u, fa);
    int half = jshr(siz[u], 1);
    bool find = false;
    while ((!find)) {
      (find = true);
      for (int e = head[u]; (e > 0); (e = nxt[e])) {
        int v = to[e];
        if ((((v != fa) && (!vis[v])) && (siz[v] > half))) {
          (fa = u);
          (u = v);
          (find = false);
          break;
        }
      }
    }
    return u;
  }
  static void centroidTree(int u, int fa) {
    (centfa[u] = fa);
    (vis[u] = true);
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      int v = to[e];
      if ((!vis[v])) {
        Code03_AtmTree1::centroidTree(Code03_AtmTree1::getCentroid(v, u), u);
      }
    }
  }
  static int add(int jobi, int jobv, int l, int r, int i) {
    if ((i == 0)) {
      (i = (++cntt));
    }
    if ((l == r)) {
      (sum[i] += jobv);
    } else {
      int mid = jshr((l + r), 1);
      if ((jobi <= mid)) {
        (ls[i] = Code03_AtmTree1::add(jobi, jobv, l, mid, ls[i]));
      } else {
        (rs[i] = Code03_AtmTree1::add(jobi, jobv, (mid + 1), r, rs[i]));
      }
      (sum[i] = (sum[ls[i]] + sum[rs[i]]));
    }
    return i;
  }
  static int query(int jobl, int jobr, int l, int r, int i) {
    if ((i == 0)) {
      return 0;
    }
    if (((jobl <= l) && (r <= jobr))) {
      return sum[i];
    }
    int mid = jshr((l + r), 1);
    int ans = 0;
    if ((jobl <= mid)) {
      (ans += Code03_AtmTree1::query(jobl, jobr, l, mid, ls[i]));
    }
    if ((jobr > mid)) {
      (ans += Code03_AtmTree1::query(jobl, jobr, (mid + 1), r, rs[i]));
    }
    return ans;
  }
  static void add(int x, int v) {
    (addTree[x] = Code03_AtmTree1::add(0, v, 0, sumw, addTree[x]));
    {
      int cur = x;
      int fa = centfa[cur];
      for (; (fa > 0); (cur = fa), (fa = centfa[cur])) {
        int dist = Code03_AtmTree1::getDist(x, fa);
        (addTree[fa] = Code03_AtmTree1::add(dist, v, 0, sumw, addTree[fa]));
        (minusTree[cur] =
             Code03_AtmTree1::add(dist, v, 0, sumw, minusTree[cur]));
      }
    }
  }
  static int query(int x, int limit) {
    int ans = Code03_AtmTree1::query(0, limit, 0, sumw, addTree[x]);
    {
      int cur = x;
      int fa = centfa[cur];
      for (; (fa > 0); (cur = fa), (fa = centfa[cur])) {
        int dist = Code03_AtmTree1::getDist(x, fa);
        if (((limit - dist) >= 0)) {
          (ans +=
           Code03_AtmTree1::query(0, (limit - dist), 0, sumw, addTree[fa]));
          (ans -=
           Code03_AtmTree1::query(0, (limit - dist), 0, sumw, minusTree[cur]));
        }
      }
    }
    return ans;
  }
  static int compute(int x) {
    int ans = 0;
    int l = 0;
    int r = sumw;
    int mid = {};
    while ((l <= r)) {
      (mid = jshr((l + r), 1));
      if ((Code03_AtmTree1::query(x, mid) >= k)) {
        (ans = mid);
        (r = (mid - 1));
      } else {
        (l = (mid + 1));
      }
    }
    return ans;
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (k = (in.nextInt() + 1));
    {
      int i = 1;
      int u = {};
      int v = {};
      int w = {};
      for (; (i < n); (i++)) {
        (u = in.nextInt());
        (v = in.nextInt());
        (w = in.nextInt());
        Code03_AtmTree1::addEdge(u, v, w);
        Code03_AtmTree1::addEdge(v, u, w);
        (sumw += w);
      }
    }
    Code03_AtmTree1::dfs(1, 0, 0);
    Code03_AtmTree1::centroidTree(Code03_AtmTree1::getCentroid(1, 0), 0);
    for (int i = 1; (i <= n); (i++)) {
      Code03_AtmTree1::add(i, 1);
    }
    for (int i = 1; (i <= n); (i++)) {
      out.println(Code03_AtmTree1::compute(i));
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code03_AtmTree1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// Atm的树，java版
// 树上有n个点，给定n-1条边，每条边有边权
// 现在关心，从节点x出发到达其他点的距离中，第k小的距离
// 注意，节点x到自己的距离0，不参与距离评比
// 给定正数k，打印每个节点的第k小距离，一共n条打印
// 1 <= n <= 15000
// 1 <= k <= 5000
// 1 <= 边权 <= 10
// 测试链接 : https://www.luogu.com.cn/problem/P10604
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 读写工具类
*/

// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/CF757G
// https://codeforces.com/problemset/problem/757/G

// Source: src/class187/Code03_PersistentEdgeDecompositionTree1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_PersistentEdgeDecompositionTree1 {
  inline static int MAXN = 400001;
  inline static int MAXT = (MAXN * 30);
  inline static int n = {};
  inline static int q = {};
  inline static int cntn = {};
  inline static Array<int> head1 = make_array<int>(MAXN);
  inline static Array<int> next1 = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> to1 = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> weight1 = make_array<int>(jshl(MAXN, 1));
  inline static int cnt1 = {};
  inline static Array<int> head2 = make_array<int>(MAXN);
  inline static Array<int> next2 = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> to2 = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> weight2 = make_array<int>(jshl(MAXN, 1));
  inline static int cnt2 = {};
  inline static Array<bool> vis = make_array<bool>(MAXN);
  inline static Array<int> siz = make_array<int>(MAXN);
  inline static Array<int> up = make_array<int>(MAXN);
  inline static Array<int> root = make_array<int>(MAXN);
  inline static Array<int> ls = make_array<int>(MAXT);
  inline static Array<int> rs = make_array<int>(MAXT);
  inline static Array<int> lcnt = make_array<int>(MAXT);
  inline static Array<int> rcnt = make_array<int>(MAXT);
  inline static Array<i64> lsum = make_array<i64>(MAXT);
  inline static Array<i64> rsum = make_array<i64>(MAXT);
  inline static int cntt = {};
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static Array<int> pre = make_array<int>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_PersistentEdgeDecompositionTree1() {}
  static void addEdge1(int u, int v, int w) {
    (next1[(++cnt1)] = head1[u]);
    (to1[cnt1] = v);
    (weight1[cnt1] = w);
    (head1[u] = cnt1);
  }
  static void addEdge2(int u, int v, int w) {
    (next2[(++cnt2)] = head2[u]);
    (to2[cnt2] = v);
    (weight2[cnt2] = w);
    (head2[u] = cnt2);
  }
  static void rebuild(int u, int fa) {
    int last = 0;
    for (int e = head1[u]; (e > 0); (e = next1[e])) {
      int v = to1[e];
      int w = weight1[e];
      if ((v != fa)) {
        if ((last == 0)) {
          (last = u);
          Code03_PersistentEdgeDecompositionTree1::addEdge2(u, v, w);
          Code03_PersistentEdgeDecompositionTree1::addEdge2(v, u, w);
        } else {
          int add = (++cntn);
          Code03_PersistentEdgeDecompositionTree1::addEdge2(last, add, 0);
          Code03_PersistentEdgeDecompositionTree1::addEdge2(add, last, 0);
          Code03_PersistentEdgeDecompositionTree1::addEdge2(add, v, w);
          Code03_PersistentEdgeDecompositionTree1::addEdge2(v, add, w);
          (last = add);
        }
        Code03_PersistentEdgeDecompositionTree1::rebuild(v, u);
      }
    }
  }
  static void getSize(int u, int fa) {
    (siz[u] = 1);
    for (int e = head2[u]; (e > 0); (e = next2[e])) {
      int v = to2[e];
      if (((v != fa) && (!vis[jshr(e, 1)]))) {
        Code03_PersistentEdgeDecompositionTree1::getSize(v, u);
        (siz[u] += siz[v]);
      }
    }
  }
  static int getCentroidEdge(int u, int fa) {
    Code03_PersistentEdgeDecompositionTree1::getSize(u, fa);
    int total = siz[u];
    int half = jshr(total, 1);
    bool find = false;
    while ((!find)) {
      (find = true);
      for (int e = head2[u]; (e > 0); (e = next2[e])) {
        int v = to2[e];
        if ((((v != fa) && (!vis[jshr(e, 1)])) && (siz[v] > half))) {
          (fa = u);
          (u = v);
          (find = false);
          break;
        }
      }
    }
    int best = 0;
    int edge = 0;
    for (int e = head2[u]; (e > 0); (e = next2[e])) {
      if ((!vis[jshr(e, 1)])) {
        int v = to2[e];
        int sub = ((v == fa) ? (total - siz[u]) : siz[v]);
        if ((sub > best)) {
          (best = sub);
          (edge = e);
        }
      }
    }
    return edge;
  }
  static void dfs(int u, int fa, i64 dist, int op) {
    if ((u <= n)) {
      if ((up[u] == 0)) {
        (up[u] = (++cntt));
        (root[u] = cntt);
      }
      int cur = up[u];
      int nxt = (++cntt);
      if ((op == 0)) {
        (ls[cur] = nxt);
        (lsum[cur] = dist);
        (lcnt[cur] = 1);
      } else {
        (rs[cur] = nxt);
        (rsum[cur] = dist);
        (rcnt[cur] = 1);
      }
      (up[u] = nxt);
    }
    for (int e = head2[u]; (e > 0); (e = next2[e])) {
      int v = to2[e];
      if (((v != fa) && (!vis[jshr(e, 1)]))) {
        Code03_PersistentEdgeDecompositionTree1::dfs(v, u, (dist + weight2[e]),
                                                     op);
      }
    }
  }
  static void solve(int u) {
    int edge = Code03_PersistentEdgeDecompositionTree1::getCentroidEdge(u, 0);
    if ((edge > 0)) {
      (vis[jshr(edge, 1)] = true);
      int v1 = to2[edge];
      int v2 = to2[(edge ^ 1)];
      Code03_PersistentEdgeDecompositionTree1::dfs(v1, 0, 0, 0);
      Code03_PersistentEdgeDecompositionTree1::dfs(v2, 0, weight2[edge], 1);
      Code03_PersistentEdgeDecompositionTree1::solve(v1);
      Code03_PersistentEdgeDecompositionTree1::solve(v2);
    }
  }
  static int add(int p, int i) {
    if (((p == 0) || (i == 0))) {
      return (p + i);
    }
    int rt = (++cntt);
    (ls[rt] = ls[p]);
    (rs[rt] = rs[p]);
    (lcnt[rt] = (lcnt[p] + lcnt[i]));
    (rcnt[rt] = (rcnt[p] + rcnt[i]));
    (lsum[rt] = (lsum[p] + lsum[i]));
    (rsum[rt] = (rsum[p] + rsum[i]));
    if ((ls[i] > 0)) {
      (ls[rt] = Code03_PersistentEdgeDecompositionTree1::add(ls[rt], ls[i]));
    } else {
      (rs[rt] = Code03_PersistentEdgeDecompositionTree1::add(rs[rt], rs[i]));
    }
    return rt;
  }
  static i64 query(int p1, int p2, int i) {
    if (((ls[i] == 0) && (rs[i] == 0))) {
      return 0;
    } else if ((ls[i] > 0)) {
      return (((Code03_PersistentEdgeDecompositionTree1::query(ls[p1], ls[p2],
                                                               ls[i]) +
                rsum[p2]) -
               rsum[p1]) +
              (lsum[i] * (rcnt[p2] - rcnt[p1])));
    } else {
      return (((Code03_PersistentEdgeDecompositionTree1::query(rs[p1], rs[p2],
                                                               rs[i]) +
                lsum[p2]) -
               lsum[p1]) +
              (rsum[i] * (lcnt[p2] - lcnt[p1])));
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (q = in.nextInt());
    for (int i = 1; (i <= n); (i++)) {
      (arr[i] = in.nextInt());
    }
    {
      int i = 1;
      int u = {};
      int v = {};
      int w = {};
      for (; (i < n); (i++)) {
        (u = in.nextInt());
        (v = in.nextInt());
        (w = in.nextInt());
        Code03_PersistentEdgeDecompositionTree1::addEdge1(u, v, w);
        Code03_PersistentEdgeDecompositionTree1::addEdge1(v, u, w);
      }
    }
    (cntn = n);
    (cnt2 = 1);
    Code03_PersistentEdgeDecompositionTree1::rebuild(1, 0);
    Code03_PersistentEdgeDecompositionTree1::solve(1);
    for (int i = 1; (i <= n); (i++)) {
      (pre[i] = Code03_PersistentEdgeDecompositionTree1::add(pre[(i - 1)],
                                                             root[arr[i]]));
    }
    i64 mask = (jshl(1LL, 30) - 1);
    i64 lastAns = 0;
    i64 a = {};
    i64 b = {};
    i64 c = {};
    int op = {};
    int x = {};
    int y = {};
    int z = {};
    int tmp = {};
    for (int i = 1; (i <= q); (i++)) {
      (op = in.nextInt());
      if ((op == 1)) {
        (a = in.nextInt());
        (b = in.nextInt());
        (c = in.nextInt());
        (a ^= lastAns);
        (b ^= lastAns);
        (c ^= lastAns);
        (x = static_cast<int>(a));
        (y = static_cast<int>(b));
        (z = static_cast<int>(c));
        (lastAns = Code03_PersistentEdgeDecompositionTree1::query(
             pre[(x - 1)], pre[y], root[z]));
        out.println(lastAns);
        (lastAns &= mask);
      } else {
        (a = in.nextInt());
        (a ^= lastAns);
        (x = static_cast<int>(a));
        (tmp = arr[x]);
        (arr[x] = arr[(x + 1)]);
        (arr[(x + 1)] = tmp);
        (pre[x] = Code03_PersistentEdgeDecompositionTree1::add(pre[(x - 1)],
                                                               root[arr[x]]));
      }
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code03_PersistentEdgeDecompositionTree1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 可持久化边分树，java版
// 树上有n个节点，给定n-1条边，每条边有边权
// 给定长度为n的数组arr，代表点编号组成的一个排列
// 接下来有q条操作，每条操作是如下两种类型中的一种
// 操作 1 x y z : 打印arr[x..y]中每个节点到节点z的简单路径距离之和
// 操作 2 x     : 交换arr[x]和arr[x+1]的值，输入保证 1 <= x < n
// 1 <= n、q <= 2 * 10^5
// 本题要求强制在线，得到操作参数的规则，打开测试链接查看
// 测试链接 : https://www.luogu.com.cn/problem/CF757G
// 测试链接 : https://codeforces.com/problemset/problem/757/G
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 读写工具类
*/

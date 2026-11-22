// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P3588

// Source: src/class195/Code04_Desert1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_Desert1 {
  inline static int MAXN = 100001;
  inline static int MAXT = (MAXN * 5);
  inline static int MAXE = (MAXN * 20);
  inline static int LIMIT = 1000000000;
  inline static int n = {};
  inline static int s = {};
  inline static int m = {};
  inline static Array<int> head = make_array<int>(MAXT);
  inline static Array<int> nxt = make_array<int>(MAXE);
  inline static Array<int> to = make_array<int>(MAXE);
  inline static Array<int> weight = make_array<int>(MAXE);
  inline static int cntg = {};
  inline static Array<int> ls = make_array<int>(MAXT);
  inline static Array<int> rs = make_array<int>(MAXT);
  inline static int root = {};
  inline static int cntt = {};
  inline static Array<int> val = make_array<int>(MAXT);
  inline static Array<int> atMost = make_array<int>(MAXT);
  inline static Array<int> indegree = make_array<int>(MAXT);
  inline static Array<int> que = make_array<int>(MAXT);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_Desert1() {}
  static void addEdge(int u, int v, int w) {
    (nxt[(++cntg)] = head[u]);
    (to[cntg] = v);
    (weight[cntg] = w);
    (head[u] = cntg);
    (indegree[v]++);
  }
  static int build(int l, int r) {
    int rt = {};
    if ((l == r)) {
      (rt = l);
    } else {
      (rt = (++cntt));
      int mid = jshr((l + r), 1);
      (ls[rt] = Code04_Desert1::build(l, mid));
      (rs[rt] = Code04_Desert1::build((mid + 1), r));
      Code04_Desert1::addEdge(rt, ls[rt], 0);
      Code04_Desert1::addEdge(rt, rs[rt], 0);
    }
    return rt;
  }
  static void xToRange(int jobx, int jobl, int jobr, int jobw, int l, int r,
                       int i) {
    if ((jobl > jobr)) {
      return;
    }
    if (((jobl <= l) && (r <= jobr))) {
      Code04_Desert1::addEdge(jobx, i, jobw);
    } else {
      int mid = jshr((l + r), 1);
      if ((jobl <= mid)) {
        Code04_Desert1::xToRange(jobx, jobl, jobr, jobw, l, mid, ls[i]);
      }
      if ((jobr > mid)) {
        Code04_Desert1::xToRange(jobx, jobl, jobr, jobw, (mid + 1), r, rs[i]);
      }
    }
  }
  static bool topo() {
    int qi = 1;
    int qsiz = 0;
    for (int i = 1; (i <= cntt); (i++)) {
      if ((indegree[i] == 0)) {
        (que[(++qsiz)] = i);
      }
      (atMost[i] = ((val[i] == 0) ? LIMIT : val[i]));
    }
    while ((qi <= qsiz)) {
      int u = que[(qi++)];
      for (int e = head[u]; (e > 0); (e = nxt[e])) {
        int v = to[e];
        int w = weight[e];
        if ((atMost[v] > (atMost[u] + w))) {
          (atMost[v] = (atMost[u] + w));
          if ((((val[v] != 0) && (atMost[v] < val[v])) || (atMost[v] < 1))) {
            return false;
          }
        }
        if (((--indegree[v]) == 0)) {
          (que[(++qsiz)] = v);
        }
      }
    }
    return (qsiz == cntt);
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (s = in.nextInt());
    (m = in.nextInt());
    (cntt = n);
    (root = Code04_Desert1::build(1, n));
    for (int i = 1; (i <= s); (i++)) {
      int x = in.nextInt();
      int v = in.nextInt();
      (val[x] = v);
    }
    for (int i = 1; (i <= m); (i++)) {
      int l = in.nextInt();
      int r = in.nextInt();
      int k = in.nextInt();
      int vnode = (++cntt);
      for (int j = 1; (j <= k); (j++)) {
        int x = in.nextInt();
        Code04_Desert1::addEdge(x, vnode, 0);
        Code04_Desert1::xToRange(vnode, l, (x - 1), (-1), 1, n, root);
        (l = (x + 1));
      }
      Code04_Desert1::xToRange(vnode, l, r, (-1), 1, n, root);
    }
    bool check = Code04_Desert1::topo();
    if (check) {
      out.println(String(u"TAK"));
      for (int i = 1; (i <= n); (i++)) {
        out.print((atMost[i] + String(u" ")));
      }
      out.println();
    } else {
      out.println(String(u"NIE"));
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code04_Desert1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 沙漠，java版
// 一共n个数字，所有数字都在 1 ~ 10^9 的范围，这是范围说明
// 接下来给定s条设置说明，格式 x v ，表示第x个数的值确定是v
// 接下来给定m条关系说明，格式 l r k x1 x2 ... xk 含义如下
// 第l到第r个数字，其中有k个数字，分别是第x1、第x2 .. 第xk个数字
// 这k个数字中的每一个，都比剩下的(r - l + 1 - k)个数字要大，严格大于
// 根据上面的说明，找到没有矛盾的，给每个数字赋值的方案，任何一个方案即可
// 如果存在方案打印"TAK"，然后打印每个数字，不存在方案打印"NIE"
// 1 <= n、s <= 10^5
// 1 <= m <= 2 * 10^5
// 所有k的累加和 <= 3 * 10^5
// 测试链接 : https://www.luogu.com.cn/problem/P3588
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 读写工具类
*/

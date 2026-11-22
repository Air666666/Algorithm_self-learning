// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P7477

// Source: src/class198/Code05_Partition_Multiset_java_2.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code05_Partition_Multiset_java_2 {
  inline static int MAXN = 20001;
  inline static int MAXM = 20001;
  inline static int MAXT = 2000001;
  inline static int MAXE = 5000001;
  inline static int n = {};
  inline static int m = {};
  inline static int cntt = {};
  inline static Array<int> v = make_array<int>(MAXN);
  inline static Array<int> x = make_array<int>(MAXM);
  inline static Array<int> y = make_array<int>(MAXM);
  inline static Array<int> rak = make_array<int>(MAXN);
  inline static Array<Array<int>> arr = make_array<int>(MAXN, 2);
  inline static Array<int> head = make_array<int>(MAXT);
  inline static Array<int> nxt = make_array<int>(MAXE);
  inline static Array<int> to = make_array<int>(MAXE);
  inline static int cntg = {};
  inline static Array<int> dfn = make_array<int>(MAXT);
  inline static Array<int> low = make_array<int>(MAXT);
  inline static int cntd = {};
  inline static Array<int> sta = make_array<int>(MAXT);
  inline static int top = {};
  inline static Array<int> belong = make_array<int>(MAXT);
  inline static int sccCnt = {};
  inline static Array<int> rootOut1 = make_array<int>(MAXN);
  inline static Array<int> rootIn1 = make_array<int>(MAXN);
  inline static Array<int> rootOut2 = make_array<int>(MAXN);
  inline static Array<int> rootIn2 = make_array<int>(MAXN);
  inline static Array<int> ls = make_array<int>(MAXT);
  inline static Array<int> rs = make_array<int>(MAXT);
  inline static int curVersion = {};
  inline static Array<int> stau = make_array<int>(MAXT);
  inline static Array<int> stas = make_array<int>(MAXT);
  inline static Array<int> stae = make_array<int>(MAXT);
  inline static int u = {};
  inline static int status = {};
  inline static int e = {};
  inline static int stacksize = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code05_Partition_Multiset_java_2() {}
  static void push(int u, int status, int e) {
    (stau[stacksize] = u);
    (stas[stacksize] = status);
    (stae[stacksize] = e);
    (stacksize++);
  }
  static void pop() {
    (stacksize--);
    (u = stau[stacksize]);
    (status = stas[stacksize]);
    (e = stae[stacksize]);
  }
  static int small(int num) {
    int l = 1;
    int r = n;
    int mid = {};
    int ans = 0;
    while ((l <= r)) {
      (mid = jshr((l + r), 1));
      if ((arr[mid][0] <= num)) {
        (ans = mid);
        (l = (mid + 1));
      } else {
        (r = (mid - 1));
      }
    }
    return ans;
  }
  static int big(int num) {
    int l = 1;
    int r = n;
    int mid = {};
    int ans = (n + 1);
    while ((l <= r)) {
      (mid = jshr((l + r), 1));
      if ((arr[mid][0] >= num)) {
        (ans = mid);
        (r = (mid - 1));
      } else {
        (l = (mid + 1));
      }
    }
    return ((n - ans) + 1);
  }
  static void addEdge(int u, int v) {
    (nxt[(++cntg)] = head[u]);
    (to[cntg] = v);
    (head[u] = cntg);
  }
  static void tarjan1(int u) {
    (dfn[u] = (low[u] = (++cntd)));
    (sta[(++top)] = u);
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      int v = to[e];
      if ((dfn[v] == 0)) {
        Code05_Partition_Multiset_java_2::tarjan1(v);
        (low[u] = jmin(low[u], low[v]));
      } else {
        if ((belong[v] == 0)) {
          (low[u] = jmin(low[u], dfn[v]));
        }
      }
    }
    if ((dfn[u] == low[u])) {
      (sccCnt++);
      int pop = {};
      do {
        (pop = sta[(top--)]);
        (belong[pop] = sccCnt);
      } while ((pop != u));
    }
  }
  static void tarjan2(int node) {
    (stacksize = 0);
    Code05_Partition_Multiset_java_2::push(node, (-1), (-1));
    int v = {};
    while ((stacksize > 0)) {
      Code05_Partition_Multiset_java_2::pop();
      if ((status == (-1))) {
        (dfn[u] = (low[u] = (++cntd)));
        (sta[(++top)] = u);
        (e = head[u]);
      } else {
        (v = to[e]);
        if ((status == 0)) {
          (low[u] = jmin(low[u], low[v]));
        }
        if (((status == 1) && (belong[v] == 0))) {
          (low[u] = jmin(low[u], dfn[v]));
        }
        (e = nxt[e]);
      }
      if ((e != 0)) {
        (v = to[e]);
        if ((dfn[v] == 0)) {
          Code05_Partition_Multiset_java_2::push(u, 0, e);
          Code05_Partition_Multiset_java_2::push(v, (-1), (-1));
        } else {
          Code05_Partition_Multiset_java_2::push(u, 1, e);
        }
      } else {
        if ((dfn[u] == low[u])) {
          (sccCnt++);
          int pop = {};
          do {
            (pop = sta[(top--)]);
            (belong[pop] = sccCnt);
          } while ((pop != u));
        }
      }
    }
  }
  static int buildOut(int l, int r) {
    int rt = (++cntt);
    if ((l < r)) {
      int mid = jshr((l + r), 1);
      (ls[rt] = Code05_Partition_Multiset_java_2::buildOut(l, mid));
      (rs[rt] = Code05_Partition_Multiset_java_2::buildOut((mid + 1), r));
      Code05_Partition_Multiset_java_2::addEdge(ls[rt], rt);
      Code05_Partition_Multiset_java_2::addEdge(rs[rt], rt);
    }
    return rt;
  }
  static int buildIn(int l, int r) {
    int rt = (++cntt);
    if ((l < r)) {
      int mid = jshr((l + r), 1);
      (ls[rt] = Code05_Partition_Multiset_java_2::buildIn(l, mid));
      (rs[rt] = Code05_Partition_Multiset_java_2::buildIn((mid + 1), r));
      Code05_Partition_Multiset_java_2::addEdge(rt, ls[rt]);
      Code05_Partition_Multiset_java_2::addEdge(rt, rs[rt]);
    }
    return rt;
  }
  static int addOut(int jobx, int jobv, int l, int r, int i) {
    int rt = (++cntt);
    (ls[rt] = ls[i]);
    (rs[rt] = rs[i]);
    Code05_Partition_Multiset_java_2::addEdge(i, rt);
    if ((l == r)) {
      Code05_Partition_Multiset_java_2::addEdge(jobx, rt);
    } else {
      int mid = jshr((l + r), 1);
      if ((jobv <= mid)) {
        (ls[rt] = Code05_Partition_Multiset_java_2::addOut(jobx, jobv, l, mid,
                                                           ls[rt]));
        Code05_Partition_Multiset_java_2::addEdge(ls[rt], rt);
      } else {
        (rs[rt] = Code05_Partition_Multiset_java_2::addOut(
             jobx, jobv, (mid + 1), r, rs[rt]));
        Code05_Partition_Multiset_java_2::addEdge(rs[rt], rt);
      }
    }
    return rt;
  }
  static int addIn(int jobx, int jobv, int l, int r, int i) {
    int rt = (++cntt);
    (ls[rt] = ls[i]);
    (rs[rt] = rs[i]);
    Code05_Partition_Multiset_java_2::addEdge(rt, i);
    if ((l == r)) {
      Code05_Partition_Multiset_java_2::addEdge(rt, jobx);
    } else {
      int mid = jshr((l + r), 1);
      if ((jobv <= mid)) {
        (ls[rt] = Code05_Partition_Multiset_java_2::addIn(jobx, jobv, l, mid,
                                                          ls[rt]));
        Code05_Partition_Multiset_java_2::addEdge(rt, ls[rt]);
      } else {
        (rs[rt] = Code05_Partition_Multiset_java_2::addIn(jobx, jobv, (mid + 1),
                                                          r, rs[rt]));
        Code05_Partition_Multiset_java_2::addEdge(rt, rs[rt]);
      }
    }
    return rt;
  }
  static void rangeToX(int jobl, int jobr, int jobx, int l, int r, int i) {
    if (((jobl <= l) && (r <= jobr))) {
      Code05_Partition_Multiset_java_2::addEdge(i, jobx);
    } else {
      int mid = jshr((l + r), 1);
      if ((jobl <= mid)) {
        Code05_Partition_Multiset_java_2::rangeToX(jobl, jobr, jobx, l, mid,
                                                   ls[i]);
      }
      if ((jobr > mid)) {
        Code05_Partition_Multiset_java_2::rangeToX(jobl, jobr, jobx, (mid + 1),
                                                   r, rs[i]);
      }
    }
  }
  static void xToRange(int jobx, int jobl, int jobr, int l, int r, int i) {
    if (((jobl <= l) && (r <= jobr))) {
      Code05_Partition_Multiset_java_2::addEdge(jobx, i);
    } else {
      int mid = jshr((l + r), 1);
      if ((jobl <= mid)) {
        Code05_Partition_Multiset_java_2::xToRange(jobx, jobl, jobr, l, mid,
                                                   ls[i]);
      }
      if ((jobr > mid)) {
        Code05_Partition_Multiset_java_2::xToRange(jobx, jobl, jobr, (mid + 1),
                                                   r, rs[i]);
      }
    }
  }
  static void add(int x, int otherx, int si, int bi) {
    (curVersion++);
    (rootOut1[curVersion] = Code05_Partition_Multiset_java_2::addOut(
         x, si, 1, n, rootOut1[(curVersion - 1)]));
    (rootIn1[curVersion] = Code05_Partition_Multiset_java_2::addIn(
         otherx, si, 1, n, rootIn1[(curVersion - 1)]));
    (rootOut2[curVersion] = Code05_Partition_Multiset_java_2::addOut(
         otherx, bi, 1, n, rootOut2[(curVersion - 1)]));
    (rootIn2[curVersion] = Code05_Partition_Multiset_java_2::addIn(
         x, bi, 1, n, rootIn2[(curVersion - 1)]));
  }
  static void link(int x, int otherx, int lowCnt, int hightCnt) {
    if ((lowCnt > 0)) {
      Code05_Partition_Multiset_java_2::xToRange(x, 1, lowCnt, 1, n,
                                                 rootIn1[curVersion]);
      Code05_Partition_Multiset_java_2::rangeToX(1, lowCnt, otherx, 1, n,
                                                 rootOut1[curVersion]);
    }
    if ((hightCnt > 0)) {
      Code05_Partition_Multiset_java_2::xToRange(otherx, 1, hightCnt, 1, n,
                                                 rootIn2[curVersion]);
      Code05_Partition_Multiset_java_2::rangeToX(1, hightCnt, x, 1, n,
                                                 rootOut2[curVersion]);
    }
  }
  static int other(int x) { return ((x <= n) ? (x + n) : (x - n)); }
  static void buildGraph(int k) {
    (cntt = jshl(n, 1));
    (rootOut1[0] = Code05_Partition_Multiset_java_2::buildOut(1, n));
    (rootIn1[0] = Code05_Partition_Multiset_java_2::buildIn(1, n));
    (rootOut2[0] = Code05_Partition_Multiset_java_2::buildOut(1, n));
    (rootIn2[0] = Code05_Partition_Multiset_java_2::buildIn(1, n));
    for (int i = 1; (i <= m); (i++)) {
      Code05_Partition_Multiset_java_2::addEdge(
          x[i], Code05_Partition_Multiset_java_2::other(y[i]));
      Code05_Partition_Multiset_java_2::addEdge(
          y[i], Code05_Partition_Multiset_java_2::other(x[i]));
      Code05_Partition_Multiset_java_2::addEdge(
          Code05_Partition_Multiset_java_2::other(x[i]), y[i]);
      Code05_Partition_Multiset_java_2::addEdge(
          Code05_Partition_Multiset_java_2::other(y[i]), x[i]);
    }
    for (int i = 1; (i <= n); (i++)) {
      [&]() {
        auto jargument_0 = i;
        auto jargument_1 = Code05_Partition_Multiset_java_2::other(i);
        auto jargument_2 = Code05_Partition_Multiset_java_2::small((v[i] - k));
        auto jargument_3 = Code05_Partition_Multiset_java_2::big((v[i] + k));
        return Code05_Partition_Multiset_java_2::link(jargument_0, jargument_1,
                                                      jargument_2, jargument_3);
      }();
      Code05_Partition_Multiset_java_2::add(
          i, Code05_Partition_Multiset_java_2::other(i), rak[i],
          ((n - rak[i]) + 1));
    }
  }
  static void clear() {
    for (int i = 1; (i <= cntt); (i++)) {
      (head[i] = (dfn[i] = (belong[i] = 0)));
    }
    (cntt = (cntg = (cntd = (top = (sccCnt = (curVersion = 0))))));
  }
  static bool check(int k) {
    Code05_Partition_Multiset_java_2::buildGraph(k);
    for (int i = 1; (i <= jshl(n, 1)); (i++)) {
      if ((dfn[i] == 0)) {
        Code05_Partition_Multiset_java_2::tarjan2(i);
      }
    }
    bool check = true;
    for (int i = 1; (i <= n); (i++)) {
      if ((belong[i] == belong[(i + n)])) {
        (check = false);
        break;
      }
    }
    Code05_Partition_Multiset_java_2::clear();
    return check;
  }
  static int compute() {
    for (int i = 1; (i <= n); (i++)) {
      (arr[i][0] = v[i]);
      (arr[i][1] = i);
    }
    j::sort(arr, 1, (n + 1), [=](Array<int> a, Array<int> b) {
      return ((a[0] != b[0]) ? (a[0] - b[0]) : (a[1] - b[1]));
    });
    for (int i = 1; (i <= n); (i++)) {
      (rak[arr[i][1]] = i);
    }
    int l = 0;
    int r = arr[n][0];
    int mid = {};
    int ans = (-1);
    while ((l <= r)) {
      (mid = jshr((l + r), 1));
      if (Code05_Partition_Multiset_java_2::check(mid)) {
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
    (m = in.nextInt());
    for (int i = 1; (i <= n); (i++)) {
      (v[i] = in.nextInt());
    }
    for (int i = 1; (i <= m); (i++)) {
      (x[i] = in.nextInt());
      (y[i] = in.nextInt());
    }
    int ans = Code05_Partition_Multiset_java_2::compute();
    out.println(ans);
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code05_Partition_Multiset_java_2::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 划分可重集，主席树优化建图，java版
// 给定长度为n的数组arr，从左到右把每个数划分进可重集a、b
// 每个数至少要进入a或b中的一个
// arr[i]能进集合a的条件为，i左侧任何 <= arr[i] - k的数字，都没进集合a
// arr[i]能进集合b的条件为，i左侧任何 >= arr[i] + k的数字，都没进集合b
// 然后有m组关系，每组 x y，保证 x < y，表示两个位置的数不能进入同一个集合
// 如果不存在合法划分，打印-1，如果存在方案，打印能划分成功的最小k值
// n、m <= 2 * 10^4
// arr[i] <= 10^9
// 测试链接 : https://www.luogu.com.cn/problem/P7477
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 主席树
        // 迭代版需要的栈，讲解118讲了递归改迭代的技巧
        // <= num的范围长度
        // >= num的范围长度
        // 递归版
        // 迭代版
                                // tarjan1(i);
        // 读写工具类
*/

// Source: src/class197/Code02_Flags1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_Flags1 {
  inline static int MAXN = 10001;
  inline static int MAXT = 100001;
  inline static int MAXE = 1000001;
  inline static int n = {};
  inline static int k = {};
  inline static Array<int> a = make_array<int>(MAXN);
  inline static Array<int> b = make_array<int>(MAXN);
  inline static Array<Array<int>> arr = make_array<int>(jshl(MAXN, 1), 2);
  inline static Array<int> ls = make_array<int>(MAXT);
  inline static Array<int> rs = make_array<int>(MAXT);
  inline static int root = {};
  inline static int cntt = {};
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
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_Flags1() {}
  static int kth(int num) {
    int l = 1;
    int r = k;
    int mid = {};
    int ans = (k + 1);
    while ((l <= r)) {
      (mid = jshr((l + r), 1));
      if ((arr[mid][0] >= num)) {
        (ans = mid);
        (r = (mid - 1));
      } else {
        (l = (mid + 1));
      }
    }
    return ans;
  }
  static void addEdge(int u, int v) {
    (nxt[(++cntg)] = head[u]);
    (to[cntg] = v);
    (head[u] = cntg);
  }
  static void tarjan(int u) {
    (dfn[u] = (low[u] = (++cntd)));
    (sta[(++top)] = u);
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      int v = to[e];
      if ((dfn[v] == 0)) {
        Code02_Flags1::tarjan(v);
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
  static int other(int i) { return ((i <= n) ? (i + n) : (i - n)); }
  static int build(int l, int r) {
    int rt = {};
    if ((l == r)) {
      (rt = Code02_Flags1::other(arr[l][1]));
    } else {
      (rt = (++cntt));
      int mid = jshr((l + r), 1);
      (ls[rt] = Code02_Flags1::build(l, mid));
      (rs[rt] = Code02_Flags1::build((mid + 1), r));
      Code02_Flags1::addEdge(rt, ls[rt]);
      Code02_Flags1::addEdge(rt, rs[rt]);
    }
    return rt;
  }
  static void xToRange(int xid, int jobl, int jobr, int l, int r, int i) {
    if ((jobl > jobr)) {
      return;
    }
    if (((jobl <= l) && (r <= jobr))) {
      Code02_Flags1::addEdge(xid, i);
    } else {
      int mid = jshr((l + r), 1);
      if ((jobl <= mid)) {
        Code02_Flags1::xToRange(xid, jobl, jobr, l, mid, ls[i]);
      }
      if ((jobr > mid)) {
        Code02_Flags1::xToRange(xid, jobl, jobr, (mid + 1), r, rs[i]);
      }
    }
  }
  static void buildGraph(int d) {
    (cntt = k);
    (root = Code02_Flags1::build(1, k));
    for (int i = 1; (i <= k); (i++)) {
      int pos = arr[i][0];
      int l = Code02_Flags1::kth(((pos - d) + 1));
      int r = (Code02_Flags1::kth((pos + d)) - 1);
      int x = arr[i][1];
      Code02_Flags1::xToRange(x, l, (i - 1), 1, k, root);
      Code02_Flags1::xToRange(x, (i + 1), r, 1, k, root);
    }
  }
  static void clear() {
    for (int i = 1; (i <= cntt); (i++)) {
      (head[i] = (dfn[i] = (belong[i] = 0)));
    }
    (cntt = (cntg = (cntd = (top = (sccCnt = 0)))));
  }
  static bool check(int d) {
    Code02_Flags1::buildGraph(d);
    for (int i = 1; (i <= jshl(n, 1)); (i++)) {
      if ((dfn[i] == 0)) {
        Code02_Flags1::tarjan(i);
      }
    }
    bool check = true;
    for (int i = 1; (i <= n); (i++)) {
      if ((belong[i] == belong[(i + n)])) {
        (check = false);
        break;
      }
    }
    Code02_Flags1::clear();
    return check;
  }
  static int compute() {
    for (int i = 1; (i <= n); (i++)) {
      (arr[i][0] = a[i]);
      (arr[i][1] = i);
      (arr[(i + n)][0] = b[i]);
      (arr[(i + n)][1] = (i + n));
    }
    (k = jshl(n, 1));
    j::sort(arr, 1, (k + 1), [=](Array<int> x, Array<int> y) {
      return ((x[0] != y[0]) ? (x[0] - y[0]) : (x[1] - y[1]));
    });
    int l = 0;
    int r = arr[k][0];
    int d = {};
    int ans = 0;
    while ((l <= r)) {
      (d = jshr((l + r), 1));
      if (Code02_Flags1::check(d)) {
        (ans = d);
        (l = (d + 1));
      } else {
        (r = (d - 1));
      }
    }
    return ans;
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    for (int i = 1; (i <= n); (i++)) {
      (a[i] = in.nextInt());
      (b[i] = in.nextInt());
    }
    int ans = Code02_Flags1::compute();
    out.println(ans);
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code02_Flags1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 旗帜，java版
// 一共n个旗子，第i号旗子有a[i]和b[i]两个可选位置
// 你需要决定每个旗子，到底放在两个可选位置中的哪一个
// 两面旗子之间的最小距离 d 越大，排列看起来就越美观
// 找到最美观的情况，即求出所有可能的 d 值中的最大值
// 2 <= n <= 10^4
// 1 <= a[i]、b[i] <= 10^9
// 测试链接 : https://www.luogu.com.cn/problem/AT_arc069_d
// 测试链接 : https://atcoder.jp/contests/arc069/tasks/arc069_d
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 所在的地点pos、决定的编号xid
        // 读写工具类
*/

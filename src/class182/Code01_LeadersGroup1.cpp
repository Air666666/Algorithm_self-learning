// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P4577

// Source: src/class182/Code01_LeadersGroup1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_LeadersGroup1 {
  inline static int MAXN = 200001;
  inline static int MAXT = (MAXN * 20);
  inline static int n = {};
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static Array<int> sorted = make_array<int>(MAXN);
  inline static int cntv = {};
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> nxt = make_array<int>(MAXN);
  inline static Array<int> to = make_array<int>(MAXN);
  inline static int cntg = {};
  inline static Array<int> root = make_array<int>(MAXN);
  inline static Array<int> ls = make_array<int>(MAXT);
  inline static Array<int> rs = make_array<int>(MAXT);
  inline static Array<int> maxv = make_array<int>(MAXT);
  inline static Array<int> addLazy = make_array<int>(MAXT);
  inline static int cntt = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_LeadersGroup1() {}
  static int kth(int num) {
    int left = 1;
    int right = cntv;
    int mid = {};
    int ret = 0;
    while ((left <= right)) {
      (mid = jshr((left + right), 1));
      if ((sorted[mid] <= num)) {
        (ret = mid);
        (left = (mid + 1));
      } else {
        (right = (mid - 1));
      }
    }
    return ret;
  }
  static void addEdge(int u, int v) {
    (nxt[(++cntg)] = head[u]);
    (to[cntg] = v);
    (head[u] = cntg);
  }
  static void up(int i) { (maxv[i] = jmax(maxv[ls[i]], maxv[rs[i]])); }
  static void lazy(int i, int v) {
    if ((i != 0)) {
      (maxv[i] += v);
      (addLazy[i] += v);
    }
  }
  static void down(int i) {
    if ((addLazy[i] > 0)) {
      Code01_LeadersGroup1::lazy(ls[i], addLazy[i]);
      Code01_LeadersGroup1::lazy(rs[i], addLazy[i]);
      (addLazy[i] = 0);
    }
  }
  static int update(int jobi, int jobv, int l, int r, int i) {
    int rt = i;
    if ((rt == 0)) {
      (rt = (++cntt));
    }
    if ((l == r)) {
      (maxv[rt] = jmax(maxv[rt], jobv));
    } else {
      Code01_LeadersGroup1::down(rt);
      int mid = jshr((l + r), 1);
      if ((jobi <= mid)) {
        (ls[rt] = Code01_LeadersGroup1::update(jobi, jobv, l, mid, ls[rt]));
      } else {
        (rs[rt] =
             Code01_LeadersGroup1::update(jobi, jobv, (mid + 1), r, rs[rt]));
      }
      Code01_LeadersGroup1::up(rt);
    }
    return rt;
  }
  static int query(int jobl, int jobr, int l, int r, int i) {
    if ((i == 0)) {
      return 0;
    }
    if (((jobl <= l) && (r <= jobr))) {
      return maxv[i];
    }
    Code01_LeadersGroup1::down(i);
    int mid = jshr((l + r), 1);
    int ans = 0;
    if ((jobl <= mid)) {
      (ans = jmax(ans, Code01_LeadersGroup1::query(jobl, jobr, l, mid, ls[i])));
    }
    if ((jobr > mid)) {
      (ans = jmax(
           ans, Code01_LeadersGroup1::query(jobl, jobr, (mid + 1), r, rs[i])));
    }
    return ans;
  }
  static int merge(int l, int r, int t1, int t2, int max1, int max2) {
    if (((t1 == 0) || (t2 == 0))) {
      if ((t1 != 0)) {
        Code01_LeadersGroup1::lazy(t1, max2);
      }
      if ((t2 != 0)) {
        Code01_LeadersGroup1::lazy(t2, max1);
      }
      return (t1 + t2);
    }
    if ((l == r)) {
      (maxv[t1] += jmax(maxv[t2], max2));
    } else {
      Code01_LeadersGroup1::down(t1);
      Code01_LeadersGroup1::down(t2);
      int mid = jshr((l + r), 1);
      (ls[t1] = [&]() {
        auto jargument_0 = l;
        auto jargument_1 = mid;
        auto jargument_2 = ls[t1];
        auto jargument_3 = ls[t2];
        auto jargument_4 = jmax(max1, maxv[rs[t1]]);
        auto jargument_5 = jmax(max2, maxv[rs[t2]]);
        return Code01_LeadersGroup1::merge(jargument_0, jargument_1,
                                           jargument_2, jargument_3,
                                           jargument_4, jargument_5);
      }());
      (rs[t1] = Code01_LeadersGroup1::merge((mid + 1), r, rs[t1], rs[t2], max1,
                                            max2));
      Code01_LeadersGroup1::up(t1);
    }
    return t1;
  }
  static void dp(int u) {
    int sum = 0;
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      int v = to[e];
      Code01_LeadersGroup1::dp(v);
      (sum += Code01_LeadersGroup1::query(arr[u], cntv, 1, cntv, root[v]));
      (root[u] = Code01_LeadersGroup1::merge(1, cntv, root[u], root[v], 0, 0));
    }
    (root[u] =
         Code01_LeadersGroup1::update(arr[u], (sum + 1), 1, cntv, root[u]));
  }
  static void prepare() {
    for (int i = 1; (i <= n); (i++)) {
      (sorted[(++cntv)] = arr[i]);
    }
    j::sort(sorted, 1, (cntv + 1));
    int len = 1;
    for (int i = 2; (i <= cntv); (i++)) {
      if ((sorted[len] != sorted[i])) {
        (sorted[(++len)] = sorted[i]);
      }
    }
    (cntv = len);
    for (int i = 1; (i <= n); (i++)) {
      (arr[i] = Code01_LeadersGroup1::kth(arr[i]));
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    for (int i = 1; (i <= n); (i++)) {
      (arr[i] = in.nextInt());
    }
    {
      int i = 2;
      int fa = {};
      for (; (i <= n); (i++)) {
        (fa = in.nextInt());
        Code01_LeadersGroup1::addEdge(fa, i);
      }
    }
    Code01_LeadersGroup1::prepare();
    Code01_LeadersGroup1::dp(1);
    out.println(Code01_LeadersGroup1::query(1, cntv, 1, cntv, root[1]));
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code01_LeadersGroup1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 领导集团问题，java版
// 一共有n个节点，给定每个点的点权，所有节点组成一棵树
// 已知1号节点是整棵树的头，其他节点的父亲节点都会给出
// 如果你在树上选择了u、v两个节点，并且u是v的祖先节点的话
// 那么需要保证 u的点权 <= v的点权，除此之外就没有别的限制了
// 打印你最多能在树上选择几个点
// 1 <= n <= 2 * 10^5
// 1 <= 点权 <= 10^9
// 测试链接 : https://www.luogu.com.cn/problem/P4577
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // jobi来了个新值jobv，如果比之前获得的值更大就更新，否则不更新
        // 查询[jobl..jobr]范围上的最大值
        // 线段树合并
        // max1代表dp[u][r+1...]的最大值，max2代表dp[v][r+1...]的最大值
                        // 不选u的情况，每棵子树合并一遍
                // 选u的情况，最后sum需要加1
        // 读写工具类
*/

// Source: src/class184/Code06_TreeDistance1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code06_TreeDistance1 {
  inline static int MAXN = 200001;
  inline static int MAXM = 1000001;
  inline static int MAXP = 10000001;
  inline static i64 INF = jshl(1LL, 60);
  inline static int n = {};
  inline static int m = {};
  inline static Array<int> qx = make_array<int>(MAXM);
  inline static Array<int> qy = make_array<int>(MAXM);
  inline static Array<int> qid = make_array<int>(MAXM);
  inline static Array<int> pa = make_array<int>(MAXP);
  inline static Array<int> pb = make_array<int>(MAXP);
  inline static Array<i64> pdist = make_array<i64>(MAXP);
  inline static int cntp = {};
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> nxt = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> to = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> weight = make_array<int>(jshl(MAXN, 1));
  inline static int cntg = {};
  inline static Array<bool> vis = make_array<bool>(MAXN);
  inline static Array<int> siz = make_array<int>(MAXN);
  inline static Array<i64> dist = make_array<i64>(MAXN);
  inline static Array<int> nodeArr = make_array<int>(MAXN);
  inline static int cnta = {};
  inline static Array<int> sta = make_array<int>(MAXN);
  inline static int top = {};
  inline static Array<i64> minTree = make_array<i64>(jshl(MAXN, 2));
  inline static Array<i64> ans = make_array<i64>(MAXM);
  inline static Array<Array<int>> stack = make_array<int>(MAXN, 3);
  inline static Array<i64> distst = make_array<i64>(MAXN);
  inline static int u = {};
  inline static int f = {};
  inline static int e = {};
  inline static i64 dis = {};
  inline static int stacksize = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code06_TreeDistance1() {}
  static void push(int u, int f, i64 dis, int e) {
    (stack[stacksize][0] = u);
    (stack[stacksize][1] = f);
    (stack[stacksize][2] = e);
    (distst[stacksize] = dis);
    (stacksize++);
  }
  static void pop() {
    (--stacksize);
    (u = stack[stacksize][0]);
    (f = stack[stacksize][1]);
    (e = stack[stacksize][2]);
    (dis = distst[stacksize]);
  }
  static void sortQuery(int l, int r) {
    if ((l >= r))
      return;
    int i = l;
    int j = r;
    int pivot = qy[jshr((l + r), 1)];
    int tmp = {};
    while ((i <= j)) {
      while ((qy[i] < pivot))
        (i++);
      while ((qy[j] > pivot))
        (j--);
      if ((i <= j)) {
        (tmp = qx[i]);
        (qx[i] = qx[j]);
        (qx[j] = tmp);
        (tmp = qy[i]);
        (qy[i] = qy[j]);
        (qy[j] = tmp);
        (tmp = qid[i]);
        (qid[i] = qid[j]);
        (qid[j] = tmp);
        (i++);
        (j--);
      }
    }
    Code06_TreeDistance1::sortQuery(l, j);
    Code06_TreeDistance1::sortQuery(i, r);
  }
  static void sortPair(int l, int r) {
    if ((l >= r))
      return;
    int i = l;
    int j = r;
    int pivot = pb[jshr((l + r), 1)];
    int t1 = {};
    i64 t2 = {};
    while ((i <= j)) {
      while ((pb[i] < pivot))
        (i++);
      while ((pb[j] > pivot))
        (j--);
      if ((i <= j)) {
        (t1 = pa[i]);
        (pa[i] = pa[j]);
        (pa[j] = t1);
        (t1 = pb[i]);
        (pb[i] = pb[j]);
        (pb[j] = t1);
        (t2 = pdist[i]);
        (pdist[i] = pdist[j]);
        (pdist[j] = t2);
        (i++);
        (j--);
      }
    }
    Code06_TreeDistance1::sortPair(l, j);
    Code06_TreeDistance1::sortPair(i, r);
  }
  static void addEdge(int u, int v, int w) {
    (nxt[(++cntg)] = head[u]);
    (to[cntg] = v);
    (weight[cntg] = w);
    (head[u] = cntg);
  }
  static void getSize1(int u, int fa) {
    (siz[u] = 1);
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      int v = to[e];
      if (((v != fa) && (!vis[v]))) {
        Code06_TreeDistance1::getSize1(v, u);
        (siz[u] += siz[v]);
      }
    }
  }
  static void getSize2(int cur, int fa) {
    (stacksize = 0);
    Code06_TreeDistance1::push(cur, fa, 0, (-1));
    while ((stacksize > 0)) {
      Code06_TreeDistance1::pop();
      if ((e == (-1))) {
        (siz[u] = 1);
        (e = head[u]);
      } else {
        (e = nxt[e]);
      }
      if ((e != 0)) {
        Code06_TreeDistance1::push(u, f, 0, e);
        int v = to[e];
        if (((v != f) && (!vis[v]))) {
          Code06_TreeDistance1::push(v, u, 0, (-1));
        }
      } else {
        for (int ei = head[u]; (ei > 0); (ei = nxt[ei])) {
          int v = to[ei];
          if (((v != f) && (!vis[v]))) {
            (siz[u] += siz[v]);
          }
        }
      }
    }
  }
  static int getCentroid(int u, int fa) {
    Code06_TreeDistance1::getSize2(u, fa);
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
  static void dfs1(int u, int fa, i64 dis) {
    (dist[u] = dis);
    (nodeArr[(++cnta)] = u);
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      int v = to[e];
      int w = weight[e];
      if (((v != fa) && (!vis[v]))) {
        Code06_TreeDistance1::dfs1(v, u, (dis + w));
      }
    }
  }
  static void dfs2(int cur, int fa, i64 d) {
    (stacksize = 0);
    Code06_TreeDistance1::push(cur, fa, d, (-1));
    while ((stacksize > 0)) {
      Code06_TreeDistance1::pop();
      if ((e == (-1))) {
        (dist[u] = dis);
        (nodeArr[(++cnta)] = u);
        (e = head[u]);
      } else {
        (e = nxt[e]);
      }
      if ((e != 0)) {
        Code06_TreeDistance1::push(u, f, dis, e);
        int v = to[e];
        int w = weight[e];
        if (((v != f) && (!vis[v]))) {
          Code06_TreeDistance1::push(v, u, (dis + w), (-1));
        }
      }
    }
  }
  static void stackAdd(int cur) {
    while (((top > 0) && (dist[sta[top]] >= dist[cur]))) {
      (pa[(++cntp)] = jmin(sta[top], cur));
      (pb[cntp] = jmax(sta[top], cur));
      (pdist[cntp] = (dist[sta[top]] + dist[cur]));
      (top--);
    }
    (sta[(++top)] = cur);
  }
  static void calc(int u) {
    (cnta = 0);
    Code06_TreeDistance1::dfs2(u, 0, 0);
    j::sort(nodeArr, 1, (cnta + 1));
    (top = 0);
    for (int i = 1; (i <= cnta); (i++)) {
      Code06_TreeDistance1::stackAdd(nodeArr[i]);
    }
    (top = 0);
    for (int i = cnta; (i >= 1); (i--)) {
      Code06_TreeDistance1::stackAdd(nodeArr[i]);
    }
  }
  static void solve(int u) {
    (vis[u] = true);
    Code06_TreeDistance1::calc(u);
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      int v = to[e];
      if ((!vis[v])) {
        Code06_TreeDistance1::solve(Code06_TreeDistance1::getCentroid(v, u));
      }
    }
  }
  static void up(int i) {
    (minTree[i] = jmin(minTree[jshl(i, 1)], minTree[(jshl(i, 1) | 1)]));
  }
  static void build(int l, int r, int i) {
    if ((l == r)) {
      (minTree[i] = INF);
    } else {
      int mid = jshr((l + r), 1);
      Code06_TreeDistance1::build(l, mid, jshl(i, 1));
      Code06_TreeDistance1::build((mid + 1), r, (jshl(i, 1) | 1));
      Code06_TreeDistance1::up(i);
    }
  }
  static void update(int jobi, i64 jobv, int l, int r, int i) {
    if ((l == r)) {
      (minTree[i] = jmin(minTree[i], jobv));
    } else {
      int mid = jshr((l + r), 1);
      if ((jobi <= mid)) {
        Code06_TreeDistance1::update(jobi, jobv, l, mid, jshl(i, 1));
      } else {
        Code06_TreeDistance1::update(jobi, jobv, (mid + 1), r,
                                     (jshl(i, 1) | 1));
      }
      Code06_TreeDistance1::up(i);
    }
  }
  static i64 query(int jobl, int jobr, int l, int r, int i) {
    if (((jobl <= l) && (r <= jobr))) {
      return minTree[i];
    }
    i64 ans = INF;
    int mid = jshr((l + r), 1);
    if ((jobl <= mid)) {
      (ans = jmin(ans,
                  Code06_TreeDistance1::query(jobl, jobr, l, mid, jshl(i, 1))));
    }
    if ((jobr > mid)) {
      (ans = jmin(ans, Code06_TreeDistance1::query(jobl, jobr, (mid + 1), r,
                                                   (jshl(i, 1) | 1))));
    }
    return ans;
  }
  static void compute() {
    Code06_TreeDistance1::solve(Code06_TreeDistance1::getCentroid(1, 0));
    Code06_TreeDistance1::sortQuery(1, m);
    Code06_TreeDistance1::sortPair(1, cntp);
    Code06_TreeDistance1::build(1, n, 1);
    {
      int i = 1;
      int j = 1;
      for (; (i <= m); (i++)) {
        for (; ((j <= cntp) && (pb[j] <= qy[i])); (j++)) {
          Code06_TreeDistance1::update(pa[j], pdist[j], 1, n, 1);
        }
        if ((qx[i] == qy[i])) {
          (ans[qid[i]] = (-1));
        } else {
          (ans[qid[i]] = Code06_TreeDistance1::query(qx[i], qy[i], 1, n, 1));
        }
      }
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
      int w = {};
      for (; (i < n); (i++)) {
        (u = in.nextInt());
        (v = in.nextInt());
        (w = in.nextInt());
        Code06_TreeDistance1::addEdge(u, v, w);
        Code06_TreeDistance1::addEdge(v, u, w);
      }
    }
    (m = in.nextInt());
    for (int i = 1; (i <= m); (i++)) {
      (qx[i] = in.nextInt());
      (qy[i] = in.nextInt());
      (qid[i] = i);
    }
    Code06_TreeDistance1::compute();
    for (int i = 1; (i <= m); (i++)) {
      out.println(ans[i]);
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code06_TreeDistance1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 支配点对距离，java版
// 一共有n个节点，给定n-1条边，每条边给定边权，所有节点组成一棵树
// 节点i到节点j的简单路径，边权的累加和，定义为dist(i, j)
// 编号区间[x, y]，考虑所有点对(a, b)，要求 x <= a < b <= y
// 如果dist(a, b)是所有情况中最小的，则称(a, b)为区间[x, y]的支配点对
// 也可以说，区间[x, y]的支配点对距离为dist(a, b)
// 特别的，如果x == y，那么不存在满足要求的点对，此时支配点对距离为-1
// 一共有m次查询，格式 x y : 保证x <= y，打印[x, y]的支配点对距离
// 1 <= n <= 2 * 10^5    1 <= m <= 10^6    1 <= 边权 <= 10^9
// 测试链接 : https://www.luogu.com.cn/problem/P9678
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 所有查询
        // 保留的点对
        // 单调栈
        // 维护最小值的线段树
        // 查询的答案
        // 讲解118，递归函数改成迭代所需要的栈
        // 所有查询根据y从小到大排序，java自带的排序慢，手撸双指针快排
        // 所有点对根据b从小到大排序，java自带的排序慢，手撸双指针快排
        // 得到子树大小递归版，java会爆栈，C++可以通过
        // 得到子树大小迭代版
                // getSize1(u, fa);
        // 收集信息递归版，java会爆栈，C++可以通过
        // 收集信息迭代版
                // dfs1(u, 0, 0);
                // 所有点的编号，从左往右遍历
                // 找右侧最近的、距离 <= dist的点，去生成点对
                // 所有点的编号，从右往左遍历
                // 找左侧最近的、距离 <= dist的点，去生成点对
        // 读写工具类
*/

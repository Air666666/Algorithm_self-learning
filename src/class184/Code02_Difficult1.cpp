// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P3714

// Source: src/class184/Code02_Difficult1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_Difficult1 {
  inline static int MAXN = 200001;
  inline static i64 INF = jshl(1LL, 60);
  inline static int n = {};
  inline static int m = {};
  inline static int limitl = {};
  inline static int limitr = {};
  inline static Array<int> val = make_array<int>(MAXN);
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> nxt = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> to = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> color = make_array<int>(jshl(MAXN, 1));
  inline static int cntg = {};
  inline static Array<i64> preTree = make_array<i64>(jshl(MAXN, 2));
  inline static Array<i64> curTree = make_array<i64>(jshl(MAXN, 2));
  inline static Array<bool> vis = make_array<bool>(MAXN);
  inline static Array<int> siz = make_array<int>(MAXN);
  inline static Array<Array<int>> edgeArr = make_array<int>(MAXN, 2);
  inline static int cnte = {};
  inline static Array<int> edgeCnt = make_array<int>(MAXN);
  inline static Array<i64> pathSum = make_array<i64>(MAXN);
  inline static Array<int> subtreeNode = make_array<int>(MAXN);
  inline static int cnts = {};
  inline static Array<int> colorNode = make_array<int>(MAXN);
  inline static int cntc = {};
  inline static Array<Array<int>> stack = make_array<int>(MAXN, 5);
  inline static Array<i64> sumst = make_array<i64>(MAXN);
  inline static int u = {};
  inline static int f = {};
  inline static int preColor = {};
  inline static int edge = {};
  inline static int e = {};
  inline static i64 sum = {};
  inline static int stacksize = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_Difficult1() {}
  static void push(int u, int f, int preColor, int edge, i64 sum, int e) {
    (stack[stacksize][0] = u);
    (stack[stacksize][1] = f);
    (stack[stacksize][2] = preColor);
    (stack[stacksize][3] = edge);
    (stack[stacksize][4] = e);
    (sumst[stacksize] = sum);
    (stacksize++);
  }
  static void pop() {
    (--stacksize);
    (u = stack[stacksize][0]);
    (f = stack[stacksize][1]);
    (preColor = stack[stacksize][2]);
    (edge = stack[stacksize][3]);
    (e = stack[stacksize][4]);
    (sum = sumst[stacksize]);
  }
  static void addEdge(int u, int v, int c) {
    (nxt[(++cntg)] = head[u]);
    (to[cntg] = v);
    (color[cntg] = c);
    (head[u] = cntg);
  }
  static void build(Array<i64> tree, int l, int r, int i) {
    (tree[i] = (-INF));
    if ((l < r)) {
      int mid = jshr((l + r), 1);
      Code02_Difficult1::build(tree, l, mid, jshl(i, 1));
      Code02_Difficult1::build(tree, (mid + 1), r, (jshl(i, 1) | 1));
    }
  }
  static void clear(Array<i64> tree, int l, int r, int i) {
    if ((tree[i] == (-INF))) {
      return;
    }
    (tree[i] = (-INF));
    if ((l < r)) {
      int mid = jshr((l + r), 1);
      Code02_Difficult1::clear(tree, l, mid, jshl(i, 1));
      Code02_Difficult1::clear(tree, (mid + 1), r, (jshl(i, 1) | 1));
    }
  }
  static void update(Array<i64> tree, int jobi, i64 jobv, int l, int r, int i) {
    if ((l == r)) {
      (tree[i] = jmax(tree[i], jobv));
    } else {
      int mid = jshr((l + r), 1);
      if ((jobi <= mid)) {
        Code02_Difficult1::update(tree, jobi, jobv, l, mid, jshl(i, 1));
      } else {
        Code02_Difficult1::update(tree, jobi, jobv, (mid + 1), r,
                                  (jshl(i, 1) | 1));
      }
      (tree[i] = jmax(tree[jshl(i, 1)], tree[(jshl(i, 1) | 1)]));
    }
  }
  static i64 query(Array<i64> tree, int jobl, int jobr, int l, int r, int i) {
    if (((jobl <= l) && (r <= jobr))) {
      return tree[i];
    }
    int mid = jshr((l + r), 1);
    i64 ans = (-INF);
    if ((jobl <= mid)) {
      (ans = jmax(ans, Code02_Difficult1::query(tree, jobl, jobr, l, mid,
                                                jshl(i, 1))));
    }
    if ((jobr > mid)) {
      (ans = jmax(ans, Code02_Difficult1::query(tree, jobl, jobr, (mid + 1), r,
                                                (jshl(i, 1) | 1))));
    }
    return ans;
  }
  static void getSize1(int u, int fa) {
    (siz[u] = 1);
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      int v = to[e];
      if (((v != fa) && (!vis[v]))) {
        Code02_Difficult1::getSize1(v, u);
        (siz[u] += siz[v]);
      }
    }
  }
  static void getSize2(int cur, int fa) {
    (stacksize = 0);
    Code02_Difficult1::push(cur, fa, 0, 0, 0, (-1));
    while ((stacksize > 0)) {
      Code02_Difficult1::pop();
      if ((e == (-1))) {
        (siz[u] = 1);
        (e = head[u]);
      } else {
        (e = nxt[e]);
      }
      if ((e != 0)) {
        Code02_Difficult1::push(u, f, 0, 0, 0, e);
        int v = to[e];
        if (((v != f) && (!vis[v]))) {
          Code02_Difficult1::push(v, u, 0, 0, 0, (-1));
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
    Code02_Difficult1::getSize2(u, fa);
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
  static void dfs1(int u, int fa, int preColor, int edge, i64 sum) {
    if ((edge > limitr)) {
      return;
    }
    (edgeCnt[u] = edge);
    (pathSum[u] = sum);
    (subtreeNode[(++cnts)] = u);
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      int v = to[e];
      int c = color[e];
      if (((v != fa) && (!vis[v]))) {
        Code02_Difficult1::dfs1(v, u, c, (edge + 1),
                                (sum + ((preColor == c) ? 0 : val[c])));
      }
    }
  }
  static void dfs2(int cur, int fa, int pcolor, int pedge, i64 psum) {
    (stacksize = 0);
    Code02_Difficult1::push(cur, fa, pcolor, pedge, psum, (-1));
    while ((stacksize > 0)) {
      Code02_Difficult1::pop();
      if ((e == (-1))) {
        if ((edge > limitr)) {
          continue;
        }
        (edgeCnt[u] = edge);
        (pathSum[u] = sum);
        (subtreeNode[(++cnts)] = u);
        (e = head[u]);
      } else {
        (e = nxt[e]);
      }
      if ((e != 0)) {
        Code02_Difficult1::push(u, f, preColor, edge, sum, e);
        int v = to[e];
        int c = color[e];
        if (((v != f) && (!vis[v]))) {
          Code02_Difficult1::push(v, u, c, (edge + 1),
                                  (sum + ((preColor == c) ? 0 : val[c])), (-1));
        }
      }
    }
  }
  static i64 calc(int u) {
    (cnte = 0);
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      int v = to[e];
      int c = color[e];
      if ((!vis[v])) {
        (edgeArr[(++cnte)][0] = v);
        (edgeArr[cnte][1] = c);
      }
    }
    j::sort(edgeArr, 1, (cnte + 1),
            [=](Array<int> a, Array<int> b) { return (a[1] - b[1]); });
    Code02_Difficult1::update(preTree, 0, 0, 0, n, 1);
    i64 ans = (-INF);
    (cntc = 0);
    for (int k = 1; (k <= cnte); (k++)) {
      int v = edgeArr[k][0];
      int c = edgeArr[k][1];
      if (((k > 1) && (edgeArr[(k - 1)][1] != c))) {
        Code02_Difficult1::clear(curTree, 0, n, 1);
        for (int i = 1; (i <= cntc); (i++)) {
          int node = colorNode[i];
          Code02_Difficult1::update(preTree, edgeCnt[node], pathSum[node], 0, n,
                                    1);
        }
        (cntc = 0);
      }
      (cnts = 0);
      Code02_Difficult1::dfs2(v, u, c, 1, val[c]);
      for (int i = 1; (i <= cnts); (i++)) {
        int node = subtreeNode[i];
        int l = jmax(0, (limitl - edgeCnt[node]));
        int r = (limitr - edgeCnt[node]);
        (ans = jmax(ans, (Code02_Difficult1::query(preTree, l, r, 0, n, 1) +
                          pathSum[node])));
        (ans = jmax(ans, ((Code02_Difficult1::query(curTree, l, r, 0, n, 1) +
                           pathSum[node]) -
                          val[c])));
      }
      for (int i = 1; (i <= cnts); (i++)) {
        int node = subtreeNode[i];
        (colorNode[(++cntc)] = node);
        Code02_Difficult1::update(curTree, edgeCnt[node], pathSum[node], 0, n,
                                  1);
      }
    }
    Code02_Difficult1::clear(preTree, 0, n, 1);
    Code02_Difficult1::clear(curTree, 0, n, 1);
    return ans;
  }
  static i64 solve(int u) {
    (vis[u] = true);
    i64 ans = Code02_Difficult1::calc(u);
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      int v = to[e];
      if ((!vis[v])) {
        (ans = jmax(ans, Code02_Difficult1::solve(
                             Code02_Difficult1::getCentroid(v, u))));
      }
    }
    return ans;
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (m = in.nextInt());
    (limitl = in.nextInt());
    (limitr = in.nextInt());
    for (int i = 1; (i <= m); (i++)) {
      (val[i] = in.nextInt());
    }
    {
      int i = 1;
      int u = {};
      int v = {};
      int c = {};
      for (; (i < n); (i++)) {
        (u = in.nextInt());
        (v = in.nextInt());
        (c = in.nextInt());
        Code02_Difficult1::addEdge(u, v, c);
        Code02_Difficult1::addEdge(v, u, c);
      }
    }
    Code02_Difficult1::build(preTree, 0, n, 1);
    Code02_Difficult1::build(curTree, 0, n, 1);
    out.println(Code02_Difficult1::solve(Code02_Difficult1::getCentroid(1, 0)));
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code02_Difficult1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 树的难题，java版
// 一共有n个节点，给定n-1条边，每条边给定颜色，所有节点组成一棵树
// 颜色一共有m种，val[i]表示第i种颜色的权值，可能为负数
// 树上的一条简单路径，依次经过的边收集其颜色，可以组成一个颜色序列
// 颜色序列划分成若干个连续同色段，比如AABAACC，有4个连续同色段
// 每个连续同色段只算一次颜色权值，颜色权值的累加和作为路径的权
// 请计算边数在[limitl, limitr]范围的所有路径中，最大的权是多少
// 1 <= n、m <= 2 * 10^5
// 题目保证一定存在边数在[limitl, limitr]的路径
// 测试链接 : https://www.luogu.com.cn/problem/P3714
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 之前颜色的子树形成的线段树，维护最大值信息
        // 当前颜色的子树形成的线段树，维护最大值信息
        // 每条边信息(连接的点，边的颜色)，根据边的颜色排序
        // 讲解118，递归函数改成迭代所需要的栈
        // 得到子树大小递归版，java会爆栈，C++可以通过
        // 得到子树大小迭代版
                // getSize1(u, fa);
        // 收集信息递归版，java会爆栈，C++可以通过
        // 收集信息迭代版
                        // dfs1(v, u, c, 1, val[c]);
        // 读写工具类
*/

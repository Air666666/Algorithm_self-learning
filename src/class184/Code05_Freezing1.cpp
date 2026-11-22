// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/CF150E
// https://codeforces.com/problemset/problem/150/E

// Source: src/class184/Code05_Freezing1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code05_Freezing1 {
  inline static int MAXN = 100001;
  inline static int INF = 1000000001;
  inline static int n = {};
  inline static int limitl = {};
  inline static int limitr = {};
  inline static int cntw = {};
  inline static Array<Array<int>> arr = make_array<int>(MAXN, 3);
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> nxt = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> to = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> weight = make_array<int>(jshl(MAXN, 1));
  inline static int cntg = {};
  inline static Array<bool> vis = make_array<bool>(MAXN);
  inline static Array<int> siz = make_array<int>(MAXN);
  inline static Array<Array<int>> edgeArr = make_array<int>(MAXN, 2);
  inline static int cnte = {};
  inline static Array<int> preVal = make_array<int>(MAXN);
  inline static Array<int> preNode = make_array<int>(MAXN);
  inline static int preLen = {};
  inline static Array<int> curVal = make_array<int>(MAXN);
  inline static Array<int> curNode = make_array<int>(MAXN);
  inline static int curLen = {};
  inline static Array<int> que = make_array<int>(MAXN);
  inline static int ans = {};
  inline static int ansu = {};
  inline static int ansv = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code05_Freezing1() {}
  static void addEdge(int u, int v, int w) {
    (nxt[(++cntg)] = head[u]);
    (to[cntg] = v);
    (weight[cntg] = w);
    (head[u] = cntg);
  }
  static void getSize(int u, int fa) {
    (siz[u] = 1);
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      int v = to[e];
      if (((v != fa) && (!vis[v]))) {
        Code05_Freezing1::getSize(v, u);
        (siz[u] += siz[v]);
      }
    }
  }
  static int getCentroid(int u, int fa) {
    Code05_Freezing1::getSize(u, fa);
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
  static void dfs(int u, int fa, int edge, int sum, int limit) {
    (curLen = jmax(curLen, edge));
    if ((sum > curVal[edge])) {
      (curVal[edge] = sum);
      (curNode[edge] = u);
    }
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      int v = to[e];
      int w = weight[e];
      if (((v != fa) && (!vis[v]))) {
        Code05_Freezing1::dfs(v, u, (edge + 1),
                              (sum + ((w >= limit) ? 1 : (-1))), limit);
      }
    }
  }
  static bool check(int u, int limit) {
    (preVal[0] = 0);
    (preNode[0] = u);
    (preLen = 0);
    for (int k = 1; (k <= cnte); (k++)) {
      int v = to[edgeArr[k][0]];
      int w = weight[edgeArr[k][0]];
      for (int i = 1; (i <= siz[v]); (i++)) {
        (curVal[i] = (-INF));
      }
      (curLen = 0);
      Code05_Freezing1::dfs(v, u, 1, ((w >= limit) ? 1 : (-1)), limit);
      int ql = 1;
      int qr = 0;
      for (int i = jmin(preLen, limitr); (i >= limitl); (i--)) {
        while (((ql <= qr) && (preVal[que[qr]] <= preVal[i]))) {
          (qr--);
        }
        (que[(++qr)] = i);
      }
      int down = limitr;
      int up = limitl;
      for (int i = 1; (i <= curLen); (i++)) {
        (up--);
        if (((up >= 0) && (up <= preLen))) {
          while (((ql <= qr) && (preVal[que[qr]] <= preVal[up]))) {
            (qr--);
          }
          (que[(++qr)] = up);
        }
        if (((ql <= qr) && (que[ql] == down))) {
          (ql++);
        }
        (down--);
        if (((ql <= qr) && ((preVal[que[ql]] + curVal[i]) >= 0))) {
          if ((limit > ans)) {
            (ans = limit);
            (ansu = curNode[i]);
            (ansv = preNode[que[ql]]);
          }
          return true;
        }
      }
      for (int i = 1; (i <= curLen); (i++)) {
        if (((i > preLen) || (curVal[i] > preVal[i]))) {
          (preVal[i] = curVal[i]);
          (preNode[i] = curNode[i]);
        }
      }
      (preLen = jmax(preLen, curLen));
    }
    return false;
  }
  static void calc(int u) {
    Code05_Freezing1::getSize(u, 0);
    (cnte = 0);
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      int v = to[e];
      if ((!vis[v])) {
        (edgeArr[(++cnte)][0] = e);
        (edgeArr[cnte][1] = siz[v]);
      }
    }
    j::sort(edgeArr, 1, (cnte + 1),
            [=](Array<int> a, Array<int> b) { return (a[1] - b[1]); });
    int l = 1;
    int r = cntw;
    int mid = {};
    while ((l <= r)) {
      (mid = jshr((l + r), 1));
      if (Code05_Freezing1::check(u, mid)) {
        (l = (mid + 1));
      } else {
        (r = (mid - 1));
      }
      if ((r <= ans)) {
        break;
      }
    }
  }
  static void solve(int u) {
    (vis[u] = true);
    Code05_Freezing1::calc(u);
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      int v = to[e];
      if ((!vis[v])) {
        Code05_Freezing1::solve(Code05_Freezing1::getCentroid(v, u));
      }
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (limitl = in.nextInt());
    (limitr = in.nextInt());
    for (int i = 1; (i < n); (i++)) {
      (arr[i][0] = in.nextInt());
      (arr[i][1] = in.nextInt());
      (arr[i][2] = in.nextInt());
    }
    j::sort(arr, 1, n,
            [=](Array<int> a, Array<int> b) { return (a[2] - b[2]); });
    (cntw = 0);
    for (int i = 1; (i < n); (i++)) {
      if (((i == 1) || (arr[(i - 1)][2] != arr[i][2]))) {
        (cntw++);
      }
      Code05_Freezing1::addEdge(arr[i][0], arr[i][1], cntw);
      Code05_Freezing1::addEdge(arr[i][1], arr[i][0], cntw);
    }
    Code05_Freezing1::solve(Code05_Freezing1::getCentroid(1, 0));
    out.println(((ansu + String(u" ")) + ansv));
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code05_Freezing1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 最大中位数路径，java版
// 一共有n个节点，给定n-1条边，每条边给定边权，所有节点组成一棵树
// 一条简单路径上，收集所有边权组成序列，其中的 下中位数 作为路径的权
// 边数在[limitl, limitr]范围的所有路径中，找到最大权的路径
// 如果有多条路径，找到其中一个方案即可，打印两个端点
// 1 <= n <= 10^5    0 <= 边权 <= 10^9
// 测试链接 : https://www.luogu.com.cn/problem/CF150E
// 测试链接 : https://codeforces.com/problemset/problem/150/E
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 端点u、端点v、边权w
        // 边的编号eid、边连接的子树大小size
                        // 根据之前的信息，初步建立窗口，子树按秩处理非常重要
                // 子树按大小或者高度排序，然后依次处理
                // 如果不按秩处理，建立窗口阶段，复杂度会炸
                // 课上会重点解释
        // 读写工具类
*/

// 原题测试 / 参考链接（保留上游原始地址）
// https://hydro.ac/p/bzoj-P2870
// https://darkbzoj.cc/problem/2870

// Source: src/class187/Code01_LongestPathTree1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_LongestPathTree1 {
  inline static int MAXN = 100001;
  inline static int n = {};
  inline static int cntn = {};
  inline static Array<int> arr = make_array<int>(MAXN);
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
  inline static Array<int> ledge = make_array<int>(MAXN);
  inline static Array<int> lminv = make_array<int>(MAXN);
  inline static int cntl = {};
  inline static Array<int> redge = make_array<int>(MAXN);
  inline static Array<int> rminv = make_array<int>(MAXN);
  inline static int cntr = {};
  inline static i64 ans = {};
  inline static Array<Array<int>> stack = make_array<int>(MAXN, 6);
  inline static int u = {};
  inline static int f = {};
  inline static int edge = {};
  inline static int minv = {};
  inline static int op = {};
  inline static int e = {};
  inline static int stacksize = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_LongestPathTree1() {}
  static void push(int u, int f, int edge, int minv, int op, int e) {
    (stack[stacksize][0] = u);
    (stack[stacksize][1] = f);
    (stack[stacksize][2] = edge);
    (stack[stacksize][3] = minv);
    (stack[stacksize][4] = op);
    (stack[stacksize][5] = e);
    (stacksize++);
  }
  static void pop() {
    (--stacksize);
    (u = stack[stacksize][0]);
    (f = stack[stacksize][1]);
    (edge = stack[stacksize][2]);
    (minv = stack[stacksize][3]);
    (op = stack[stacksize][4]);
    (e = stack[stacksize][5]);
  }
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
  static void rebuild1(int u, int fa) {
    int last = 0;
    for (int e = head1[u]; (e > 0); (e = next1[e])) {
      int v = to1[e];
      int w = weight1[e];
      if ((v != fa)) {
        if ((last == 0)) {
          (last = u);
          Code01_LongestPathTree1::addEdge2(u, v, w);
          Code01_LongestPathTree1::addEdge2(v, u, w);
        } else {
          int add = (++cntn);
          (arr[add] = arr[u]);
          Code01_LongestPathTree1::addEdge2(last, add, 0);
          Code01_LongestPathTree1::addEdge2(add, last, 0);
          Code01_LongestPathTree1::addEdge2(add, v, w);
          Code01_LongestPathTree1::addEdge2(v, add, w);
          (last = add);
        }
        Code01_LongestPathTree1::rebuild1(v, u);
      }
    }
  }
  static void rebuild2(int cur, int fa) {
    (stacksize = 0);
    Code01_LongestPathTree1::push(cur, fa, 0, 0, 0, (-1));
    while ((stacksize > 0)) {
      Code01_LongestPathTree1::pop();
      if ((e == (-1))) {
        int last = 0;
        for (int ei = head1[u]; (ei > 0); (ei = next1[ei])) {
          int v = to1[ei];
          int w = weight1[ei];
          if ((v != f)) {
            if ((last == 0)) {
              (last = u);
              Code01_LongestPathTree1::addEdge2(u, v, w);
              Code01_LongestPathTree1::addEdge2(v, u, w);
            } else {
              int add = (++cntn);
              (arr[add] = arr[u]);
              Code01_LongestPathTree1::addEdge2(last, add, 0);
              Code01_LongestPathTree1::addEdge2(add, last, 0);
              Code01_LongestPathTree1::addEdge2(add, v, w);
              Code01_LongestPathTree1::addEdge2(v, add, w);
              (last = add);
            }
          }
        }
        (e = head1[u]);
      } else {
        (e = next1[e]);
      }
      if ((e != 0)) {
        Code01_LongestPathTree1::push(u, f, 0, 0, 0, e);
        int v = to1[e];
        if ((v != f)) {
          Code01_LongestPathTree1::push(v, u, 0, 0, 0, (-1));
        }
      }
    }
  }
  static void getSize1(int u, int fa) {
    (siz[u] = 1);
    for (int e = head2[u]; (e > 0); (e = next2[e])) {
      int v = to2[e];
      if (((v != fa) && (!vis[jshr(e, 1)]))) {
        Code01_LongestPathTree1::getSize1(v, u);
        (siz[u] += siz[v]);
      }
    }
  }
  static void getSize2(int cur, int fa) {
    (stacksize = 0);
    Code01_LongestPathTree1::push(cur, fa, 0, 0, 0, (-1));
    while ((stacksize > 0)) {
      Code01_LongestPathTree1::pop();
      if ((e == (-1))) {
        (siz[u] = 1);
        (e = head2[u]);
      } else {
        (e = next2[e]);
      }
      if ((e != 0)) {
        Code01_LongestPathTree1::push(u, f, 0, 0, 0, e);
        int v = to2[e];
        if (((v != f) && (!vis[jshr(e, 1)]))) {
          Code01_LongestPathTree1::push(v, u, 0, 0, 0, (-1));
        }
      } else {
        for (int ei = head2[u]; (ei > 0); (ei = next2[ei])) {
          int v = to2[ei];
          if (((v != f) && (!vis[jshr(ei, 1)]))) {
            (siz[u] += siz[v]);
          }
        }
      }
    }
  }
  static int getCentroidEdge(int u, int fa) {
    Code01_LongestPathTree1::getSize2(u, fa);
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
  static void dfs1(int u, int fa, int edge, int minv, int op) {
    if ((op == 0)) {
      (ledge[(++cntl)] = edge);
      (lminv[cntl] = minv);
    } else {
      (redge[(++cntr)] = edge);
      (rminv[cntr] = minv);
    }
    for (int e = head2[u]; (e > 0); (e = next2[e])) {
      int v = to2[e];
      if (((v != fa) && (!vis[jshr(e, 1)]))) {
        Code01_LongestPathTree1::dfs1(v, u, (edge + weight2[e]),
                                      jmin(minv, arr[v]), op);
      }
    }
  }
  static void dfs2(int cur, int fa, int pedge, int pminv, int opt) {
    (stacksize = 0);
    Code01_LongestPathTree1::push(cur, fa, pedge, pminv, opt, (-1));
    while ((stacksize > 0)) {
      Code01_LongestPathTree1::pop();
      if ((e == (-1))) {
        if ((op == 0)) {
          (ledge[(++cntl)] = edge);
          (lminv[cntl] = minv);
        } else {
          (redge[(++cntr)] = edge);
          (rminv[cntr] = minv);
        }
        (e = head2[u]);
      } else {
        (e = next2[e]);
      }
      if ((e != 0)) {
        Code01_LongestPathTree1::push(u, f, edge, minv, op, e);
        int v = to2[e];
        if (((v != f) && (!vis[jshr(e, 1)]))) {
          Code01_LongestPathTree1::push(v, u, (edge + weight2[e]),
                                        jmin(minv, arr[v]), op, (-1));
        }
      }
    }
  }
  static void sort(Array<int> edge, Array<int> minv, int l, int r) {
    if ((l >= r))
      return;
    int i = l;
    int j = r;
    int pivot = minv[jshr((l + r), 1)];
    int tmp = {};
    while ((i <= j)) {
      while ((minv[i] < pivot))
        (i++);
      while ((minv[j] > pivot))
        (j--);
      if ((i <= j)) {
        (tmp = edge[i]);
        (edge[i] = edge[j]);
        (edge[j] = tmp);
        (tmp = minv[i]);
        (minv[i] = minv[j]);
        (minv[j] = tmp);
        (i++);
        (j--);
      }
    }
    Code01_LongestPathTree1::sort(edge, minv, l, j);
    Code01_LongestPathTree1::sort(edge, minv, i, r);
  }
  static void calc(int edge) {
    (cntl = (cntr = 0));
    int v1 = to2[edge];
    int v2 = to2[(edge ^ 1)];
    Code01_LongestPathTree1::dfs2(v1, 0, 0, arr[v1], 0);
    Code01_LongestPathTree1::dfs2(v2, 0, weight2[edge], arr[v2], 1);
    Code01_LongestPathTree1::sort(ledge, lminv, 1, cntl);
    Code01_LongestPathTree1::sort(redge, rminv, 1, cntr);
    i64 maxEdge = 0;
    {
      int i = cntl;
      int j = cntr;
      for (; (i >= 1); (i--)) {
        while (((j >= 1) && (rminv[j] >= lminv[i]))) {
          (maxEdge = jmax(maxEdge, redge[j]));
          (j--);
        }
        if ((j < cntr)) {
          (ans = jmax(ans, ((1LL * lminv[i]) * ((maxEdge + ledge[i]) + 1))));
        }
      }
    }
    (maxEdge = 0);
    {
      int i = cntr;
      int j = cntl;
      for (; (i >= 1); (i--)) {
        while (((j >= 1) && (lminv[j] >= rminv[i]))) {
          (maxEdge = jmax(maxEdge, ledge[j]));
          (j--);
        }
        if ((j < cntl)) {
          (ans = jmax(ans, ((1LL * rminv[i]) * ((maxEdge + redge[i]) + 1))));
        }
      }
    }
  }
  static void solve(int u) {
    int edge = Code01_LongestPathTree1::getCentroidEdge(u, 0);
    if ((edge > 0)) {
      (vis[jshr(edge, 1)] = true);
      Code01_LongestPathTree1::calc(edge);
      Code01_LongestPathTree1::solve(to2[edge]);
      Code01_LongestPathTree1::solve(to2[(edge ^ 1)]);
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
      int i = 1;
      int u = {};
      int v = {};
      for (; (i < n); (i++)) {
        (u = in.nextInt());
        (v = in.nextInt());
        Code01_LongestPathTree1::addEdge1(u, v, 1);
        Code01_LongestPathTree1::addEdge1(v, u, 1);
      }
    }
    (cntn = n);
    (cnt2 = 1);
    Code01_LongestPathTree1::rebuild2(1, 0);
    Code01_LongestPathTree1::solve(1);
    out.println(ans);
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code01_LongestPathTree1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 最长道路tree，java版
// 一共n个节点，每个点给定点权，给定n-1条边，所有节点组成一棵树
// 树上任何一条链的指标 = 链的节点数 * 链上节点的最小值
// 打印这个指标的最大值
// 1 <= n <= 5 * 10^4
// 测试链接 : https://hydro.ac/p/bzoj-P2870
// 测试链接 : https://darkbzoj.cc/problem/2870
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 讲解118，递归函数改成迭代所需要的栈
        // 普通树进行三度化的重构递归版，java会爆栈，C++可以通过
        // rebuild1迭代版
        // 得到子树大小递归版，java会爆栈，C++可以通过
        // getSize1的迭代版
        // 找寻重心边，重心边的序号返回
                // getSize1(u, fa);
        // 收集信息递归版，java会爆栈，C++可以通过
        // dfs1的迭代版
        // 根据minv的值从小到大排序
        // java自带的排序慢，手撸双指针快排，C++实现时可以用自带的排序
                // dfs1(v1, 0, 0, arr[v1], 0);
                // dfs1(v2, 0, weight2[edge], arr[v2], 1);
                // rebuild1(1, 0);
        // 读写工具类
*/

// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P2680

// Source: src/class122/Code05_TransportPlan2.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code05_TransportPlan2 {
  struct FastIO;
  struct FastIO {
    int SIZE = jshl(1, 20);
    Array<signed char> buf = {};
    int pos = {};
    int count = {};
    IO is = {};
    String toString() const { return j::str(static_cast<const void *>(this)); }
    FastIO() {
      (buf = make_array<signed char>(SIZE));
      (pos = 0);
      (count = 0);
      (is = jin);
    }
    int readByte() {
      if ((count == (-1))) {
        return (-1);
      }
      if ((pos >= count)) {
        (pos = 0);
        (count = is.read(buf));
        if ((count == (-1))) {
          return (-1);
        }
      }
      return (buf[(pos++)] & 0xff);
    }
    int nextInt() {
      int c = {};
      int value = 0;
      bool neg = false;
      do {
        (c = FastIO::readByte());
        if ((c == (-1))) {
          return (-1);
        }
      } while ((c <= u' '));
      if ((c == u'-')) {
        (neg = true);
        (c = FastIO::readByte());
      }
      for (; ((c >= u'0') && (c <= u'9')); (c = FastIO::readByte())) {
        (value = ((value * 10) + (c - u'0')));
      }
      return (neg ? (-value) : value);
    }
  };
  inline static int MAXN = 300001;
  inline static int MAXM = 300001;
  inline static int n = {};
  inline static int m = {};
  inline static Array<int> num = make_array<int>(MAXN);
  inline static Array<int> headEdge = make_array<int>(MAXN);
  inline static Array<int> edgeNext = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> edgeTo = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> edgeWeight = make_array<int>(jshl(MAXN, 1));
  inline static int tcnt = {};
  inline static Array<int> headQuery = make_array<int>(MAXN);
  inline static Array<int> queryNext = make_array<int>(jshl(MAXM, 1));
  inline static Array<int> queryTo = make_array<int>(jshl(MAXM, 1));
  inline static Array<int> queryIndex = make_array<int>(jshl(MAXM, 1));
  inline static int qcnt = {};
  inline static Array<bool> visited = make_array<bool>(MAXN);
  inline static Array<int> unionfind = make_array<int>(MAXN);
  inline static Array<int> quesu = make_array<int>(MAXM);
  inline static Array<int> quesv = make_array<int>(MAXM);
  inline static Array<int> distance = make_array<int>(MAXN);
  inline static Array<int> lca = make_array<int>(MAXM);
  inline static Array<int> cost = make_array<int>(MAXM);
  inline static int maxCost = {};
  inline static Array<int> stack = make_array<int>(MAXN);
  inline static Array<Array<int>> ufwe = make_array<int>(MAXN, 4);
  inline static int stackSize = {};
  inline static int u = {};
  inline static int f = {};
  inline static int w = {};
  inline static int e = {};
  inline static int atLeast = {};
  inline static int beyond = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code05_TransportPlan2() {}
  static void build() {
    (tcnt = (qcnt = 1));
    j::fill(headEdge, 1, (n + 1), 0);
    j::fill(headQuery, 1, (n + 1), 0);
    j::fill(visited, 1, (n + 1), false);
    for (int i = 1; (i <= n); (i++)) {
      (unionfind[i] = i);
    }
    (maxCost = 0);
  }
  static void addEdge(int u, int v, int w) {
    (edgeNext[tcnt] = headEdge[u]);
    (edgeTo[tcnt] = v);
    (edgeWeight[tcnt] = w);
    (headEdge[u] = (tcnt++));
  }
  static void addQuery(int u, int v, int i) {
    (queryNext[qcnt] = headQuery[u]);
    (queryTo[qcnt] = v);
    (queryIndex[qcnt] = i);
    (headQuery[u] = (qcnt++));
  }
  static int find(int i) {
    int size = 0;
    while ((i != unionfind[i])) {
      (stack[(size++)] = i);
      (i = unionfind[i]);
    }
    while ((size > 0)) {
      (unionfind[stack[(--size)]] = i);
    }
    return i;
  }
  static void push(int u, int f, int w, int e) {
    (ufwe[stackSize][0] = u);
    (ufwe[stackSize][1] = f);
    (ufwe[stackSize][2] = w);
    (ufwe[stackSize][3] = e);
    (stackSize++);
  }
  static void pop() {
    (--stackSize);
    (u = ufwe[stackSize][0]);
    (f = ufwe[stackSize][1]);
    (w = ufwe[stackSize][2]);
    (e = ufwe[stackSize][3]);
  }
  static void tarjan(int root) {
    (stackSize = 0);
    Code05_TransportPlan2::push(root, 0, 0, (-1));
    while ((stackSize > 0)) {
      Code05_TransportPlan2::pop();
      if ((e == (-1))) {
        (visited[u] = true);
        (distance[u] = (distance[f] + w));
        (e = headEdge[u]);
      } else {
        (e = edgeNext[e]);
      }
      if ((e != 0)) {
        Code05_TransportPlan2::push(u, f, w, e);
        if ((edgeTo[e] != f)) {
          Code05_TransportPlan2::push(edgeTo[e], u, edgeWeight[e], (-1));
        }
      } else {
        {
          int q = headQuery[u];
          int v = {};
          int i = {};
          for (; (q != 0); (q = queryNext[q])) {
            (v = queryTo[q]);
            if (visited[v]) {
              (i = queryIndex[q]);
              (lca[i] = Code05_TransportPlan2::find(v));
              (cost[i] =
                   ((distance[u] + distance[v]) - (2 * distance[lca[i]])));
              (maxCost = jmax(maxCost, cost[i]));
            }
          }
        }
        (unionfind[u] = f);
      }
    }
  }
  static bool f_method(int limit) {
    (atLeast = (maxCost - limit));
    j::fill(num, 1, (n + 1), 0);
    (beyond = 0);
    for (int i = 1; (i <= m); (i++)) {
      if ((cost[i] > limit)) {
        (num[quesu[i]]++);
        (num[quesv[i]]++);
        (num[lca[i]] -= 2);
        (beyond++);
      }
    }
    return ((beyond == 0) || Code05_TransportPlan2::dfs(1));
  }
  static bool dfs(int root) {
    (stackSize = 0);
    Code05_TransportPlan2::push(root, 0, 0, (-1));
    while ((stackSize > 0)) {
      Code05_TransportPlan2::pop();
      if ((e == (-1))) {
        (e = headEdge[u]);
      } else {
        (e = edgeNext[e]);
      }
      if ((e != 0)) {
        Code05_TransportPlan2::push(u, f, w, e);
        if ((edgeTo[e] != f)) {
          Code05_TransportPlan2::push(edgeTo[e], u, edgeWeight[e], (-1));
        }
      } else {
        {
          int e = headEdge[u];
          int v = {};
          for (; (e != 0); (e = edgeNext[e])) {
            (v = edgeTo[e]);
            if ((v != f)) {
              (num[u] += num[v]);
            }
          }
        }
        if (((num[u] == beyond) && (w >= atLeast))) {
          return true;
        }
      }
    }
    return false;
  }
  static int compute() {
    Code05_TransportPlan2::tarjan(1);
    int l = 0;
    int r = maxCost;
    int mid = {};
    int ans = 0;
    while ((l <= r)) {
      (mid = jdiv((l + r), 2));
      if (Code05_TransportPlan2::f_method(mid)) {
        (ans = mid);
        (r = (mid - 1));
      } else {
        (l = (mid + 1));
      }
    }
    return ans;
  }
  static void java_main(Array<String> args) {
    FastIO *in = new FastIO();
    IO out = IO(IO(jout), false);
    (n = in->nextInt());
    Code05_TransportPlan2::build();
    (m = in->nextInt());
    {
      int i = 1;
      int u = {};
      int v = {};
      int w = {};
      for (; (i < n); (i++)) {
        (u = in->nextInt());
        (v = in->nextInt());
        (w = in->nextInt());
        Code05_TransportPlan2::addEdge(u, v, w);
        Code05_TransportPlan2::addEdge(v, u, w);
      }
    }
    {
      int i = 1;
      int u = {};
      int v = {};
      for (; (i <= m); (i++)) {
        (u = in->nextInt());
        (v = in->nextInt());
        (quesu[i] = u);
        (quesv[i] = v);
        Code05_TransportPlan2::addQuery(u, v, i);
        Code05_TransportPlan2::addQuery(v, u, i);
      }
    }
    out.println(Code05_TransportPlan2::compute());
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code05_TransportPlan2::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 运输计划，java迭代版
// 有n个节点，给定n-1条边使其连接成一棵树，每条边有正数边权
// 给定很多运输计划，每个运输计划(a,b)表示从a去往b
// 每个运输计划的代价就是沿途边权和，运输计划之间完全互不干扰
// 你只能选择一条边，将其边权变成0
// 你的目的是让所有运输计划代价的最大值尽量小
// 返回所有运输计划代价的最大值最小能是多少
// 测试链接 : https://www.luogu.com.cn/problem/P2680
// 提交以下的code，提交时请把类名改成"Main"
// 有时候可以完全通过，有时候会有一个测试用例超时
// 因为这道题根据C++的运行时间，制定通过标准，根本没考虑java的用户
// 本节课Code05_TransportPlan3文件就是C++的实现
// 两个版本的逻辑完全一样，C++版本可以通过所有测试
        // find方法的递归版改迭代版
        // tarjan方法的递归版改迭代版
        // 不会改，看讲解118，讲了怎么从递归版改成迭代版
        // 至少要减少多少边权
        // 超过要求的运输计划有几个
        // dfs方法的递归版改迭代版
        // 不会改，看讲解118，讲了怎么从递归版改成迭代版
        // IO工具类
*/

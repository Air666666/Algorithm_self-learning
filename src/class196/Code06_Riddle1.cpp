// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P6378

// Source: src/class196/Code06_Riddle1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code06_Riddle1 {
  inline static int MAXN = 5000001;
  inline static int MAXM = 10000001;
  inline static int n = {};
  inline static int m = {};
  inline static int k = {};
  inline static int w = {};
  inline static int cntt = {};
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> nxt = make_array<int>(MAXM);
  inline static Array<int> to = make_array<int>(MAXM);
  inline static int cntg = {};
  inline static Array<int> dfn = make_array<int>(MAXN);
  inline static Array<int> low = make_array<int>(MAXN);
  inline static int cntd = {};
  inline static Array<int> sta = make_array<int>(MAXN);
  inline static int top = {};
  inline static Array<int> belong = make_array<int>(MAXN);
  inline static int sccCnt = {};
  inline static Array<Array<int>> stack = make_array<int>(MAXN, 3);
  inline static int u = {};
  inline static int status = {};
  inline static int e = {};
  inline static int stacksize = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code06_Riddle1() {}
  static void push(int u, int status, int e) {
    (stack[stacksize][0] = u);
    (stack[stacksize][1] = status);
    (stack[stacksize][2] = e);
    (stacksize++);
  }
  static void pop() {
    (stacksize--);
    (u = stack[stacksize][0]);
    (status = stack[stacksize][1]);
    (e = stack[stacksize][2]);
  }
  static void addEdge(int u, int v) {
    (nxt[(++cntg)] = head[u]);
    (to[cntg] = v);
    (head[u] = cntg);
  }
  static void link() {
    (cntt++);
    Code06_Riddle1::addEdge(cntt, (arr[1] + n));
    for (int i = 2; (i <= w); (i++)) {
      (cntt++);
      Code06_Riddle1::addEdge(cntt, (arr[i] + n));
      Code06_Riddle1::addEdge(arr[i], (cntt - 1));
      Code06_Riddle1::addEdge(cntt, (cntt - 1));
    }
    (cntt++);
    Code06_Riddle1::addEdge(cntt, (arr[w] + n));
    for (int i = (w - 1); (i >= 1); (i--)) {
      (cntt++);
      Code06_Riddle1::addEdge(cntt, (arr[i] + n));
      Code06_Riddle1::addEdge(arr[i], (cntt - 1));
      Code06_Riddle1::addEdge(cntt, (cntt - 1));
    }
  }
  static void tarjan1(int u) {
    (dfn[u] = (low[u] = (++cntd)));
    (sta[(++top)] = u);
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      int v = to[e];
      if ((dfn[v] == 0)) {
        Code06_Riddle1::tarjan1(v);
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
    Code06_Riddle1::push(node, (-1), (-1));
    int v = {};
    while ((stacksize > 0)) {
      Code06_Riddle1::pop();
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
          Code06_Riddle1::push(u, 0, e);
          Code06_Riddle1::push(v, (-1), (-1));
        } else {
          Code06_Riddle1::push(u, 1, e);
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
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (m = in.nextInt());
    (k = in.nextInt());
    (cntt = jshl(n, 1));
    {
      int i = 1;
      int u = {};
      int v = {};
      for (; (i <= m); (i++)) {
        (u = in.nextInt());
        (v = in.nextInt());
        Code06_Riddle1::addEdge((u + n), v);
        Code06_Riddle1::addEdge((v + n), u);
      }
    }
    for (int i = 1; (i <= k); (i++)) {
      (w = in.nextInt());
      for (int j = 1; (j <= w); (j++)) {
        (arr[j] = in.nextInt());
      }
      Code06_Riddle1::link();
    }
    for (int i = 1; (i <= cntt); (i++)) {
      if ((dfn[i] == 0)) {
        Code06_Riddle1::tarjan2(i);
      }
    }
    bool check = true;
    for (int i = 1; (i <= n); (i++)) {
      if ((belong[i] == belong[(i + n)])) {
        (check = false);
        break;
      }
    }
    out.println((check ? String(u"TAK") : String(u"NIE")));
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code06_Riddle1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 谜语，java版
// 无向图中有n个点、m条边，一共有k个阵营，每个阵营拥有一些点
// 给定每个阵营拥有的节点列表，每个点都会进入且只进一个阵营
// 选择一些点成为关键点，要求每个阵营必须有一个点成为关键点
// 同时要求每条边的两个端点中，至少有一个端点成为关键点
// 如果存在选择方案，打印"TAK"，否则打印"NIE"
// 1 <= n、m、k <= 10^6
// 测试链接 : https://www.luogu.com.cn/problem/P6378
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 迭代版需要的栈，讲解118讲了递归改迭代的技巧
        // 前后缀优化建图
        // 递归版
        // 迭代版
                                // tarjan1(i);
        // 读写工具类
*/

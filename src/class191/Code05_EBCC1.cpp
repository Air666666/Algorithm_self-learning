// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P8436

// Source: src/class191/Code05_EBCC1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code05_EBCC1 {
  inline static int MAXN = 500001;
  inline static int MAXM = 2000001;
  inline static int n = {};
  inline static int m = {};
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> nxt = make_array<int>(jshl(MAXM, 1));
  inline static Array<int> to = make_array<int>(jshl(MAXM, 1));
  inline static int cntg = {};
  inline static Array<int> dfn = make_array<int>(MAXN);
  inline static Array<int> low = make_array<int>(MAXN);
  inline static int cntd = {};
  inline static Array<int> sta = make_array<int>(MAXN);
  inline static int top = {};
  inline static Array<int> ebccSiz = make_array<int>(MAXN);
  inline static Array<int> ebccArr = make_array<int>(MAXN);
  inline static Array<int> ebccl = make_array<int>(MAXN);
  inline static Array<int> ebccr = make_array<int>(MAXN);
  inline static int idx = {};
  inline static int ebccCnt = {};
  inline static Array<Array<int>> stack = make_array<int>(MAXN, 4);
  inline static int u = {};
  inline static int preEdge = {};
  inline static int status = {};
  inline static int e = {};
  inline static int stacksize = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code05_EBCC1() {}
  static void push(int u, int preEdge, int status, int e) {
    (stack[stacksize][0] = u);
    (stack[stacksize][1] = preEdge);
    (stack[stacksize][2] = status);
    (stack[stacksize][3] = e);
    (stacksize++);
  }
  static void pop() {
    (stacksize--);
    (u = stack[stacksize][0]);
    (preEdge = stack[stacksize][1]);
    (status = stack[stacksize][2]);
    (e = stack[stacksize][3]);
  }
  static void addEdge(int u, int v) {
    (nxt[(++cntg)] = head[u]);
    (to[cntg] = v);
    (head[u] = cntg);
  }
  static void tarjan1(int u, int preEdge) {
    (dfn[u] = (low[u] = (++cntd)));
    (sta[(++top)] = u);
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      if (((e ^ 1) == preEdge)) {
        continue;
      }
      int v = to[e];
      if ((dfn[v] == 0)) {
        Code05_EBCC1::tarjan1(v, e);
        (low[u] = jmin(low[u], low[v]));
      } else {
        (low[u] = jmin(low[u], dfn[v]));
      }
    }
    if ((dfn[u] == low[u])) {
      (ebccCnt++);
      (ebccSiz[ebccCnt] = 0);
      (ebccl[ebccCnt] = (idx + 1));
      int pop = {};
      do {
        (pop = sta[(top--)]);
        (ebccSiz[ebccCnt]++);
        (ebccArr[(++idx)] = pop);
      } while ((pop != u));
      (ebccr[ebccCnt] = idx);
    }
  }
  static void tarjan2(int node, int pree) {
    (stacksize = 0);
    Code05_EBCC1::push(node, pree, (-1), (-1));
    int v = {};
    while ((stacksize > 0)) {
      Code05_EBCC1::pop();
      if ((status == (-1))) {
        (dfn[u] = (low[u] = (++cntd)));
        (sta[(++top)] = u);
        (e = head[u]);
      } else {
        (v = to[e]);
        if ((status == 0)) {
          (low[u] = jmin(low[u], low[v]));
        } else {
          (low[u] = jmin(low[u], dfn[v]));
        }
        (e = nxt[e]);
      }
      if (((e ^ 1) == preEdge)) {
        (e = nxt[e]);
      }
      if ((e != 0)) {
        (v = to[e]);
        if ((dfn[v] == 0)) {
          Code05_EBCC1::push(u, preEdge, 0, e);
          Code05_EBCC1::push(v, e, (-1), (-1));
        } else {
          Code05_EBCC1::push(u, preEdge, 1, e);
        }
      } else {
        if ((dfn[u] == low[u])) {
          (ebccCnt++);
          (ebccSiz[ebccCnt] = 0);
          (ebccl[ebccCnt] = (idx + 1));
          int pop = {};
          do {
            (pop = sta[(top--)]);
            (ebccSiz[ebccCnt]++);
            (ebccArr[(++idx)] = pop);
          } while ((pop != u));
          (ebccr[ebccCnt] = idx);
        }
      }
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (cntg = 1);
    (n = in.nextInt());
    (m = in.nextInt());
    {
      int i = 1;
      int u = {};
      int v = {};
      for (; (i <= m); (i++)) {
        (u = in.nextInt());
        (v = in.nextInt());
        Code05_EBCC1::addEdge(u, v);
        Code05_EBCC1::addEdge(v, u);
      }
    }
    for (int i = 1; (i <= n); (i++)) {
      if ((dfn[i] == 0)) {
        Code05_EBCC1::tarjan2(i, 0);
      }
    }
    out.println(ebccCnt);
    for (int i = 1; (i <= ebccCnt); (i++)) {
      out.println(ebccSiz[i]);
      for (int j = ebccl[i]; (j <= ebccr[i]); (j++)) {
        out.print((ebccArr[j] + String(u" ")));
      }
      out.println();
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code05_EBCC1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 边双连通分量模版题，java版
// 给定一张无向图，一共n个点、m条边
// 图中可能存在多个连通区，对每个连通区求边双连通分量
// 先打印边双连通分量的总数量，然后对每个边双连通分量
// 打印节点个数，然后任意顺序打印该边双连通分量的节点
// 请保证原图即使有重边和自环，答案依然正确
// 1 <= n <= 5 * 10^5
// 1 <= m <= 2 * 10^6
// 测试链接 : https://www.luogu.com.cn/problem/P8436
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 迭代版需要的栈，讲解118讲了递归改迭代的技巧
        // 递归版
        // 迭代版
                                // tarjan1(i, 0);
        // 读写工具类
*/

// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P8435

// Source: src/class193/Code04_VBCC1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_VBCC1 {
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
  inline static Array<int> vbccSiz = make_array<int>(MAXN);
  inline static Array<int> vbccArr = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> vbccl = make_array<int>(MAXN);
  inline static Array<int> vbccr = make_array<int>(MAXN);
  inline static int idx = {};
  inline static int vbccCnt = {};
  inline static Array<Array<int>> stack = make_array<int>(MAXN, 3);
  inline static int u = {};
  inline static int status = {};
  inline static int e = {};
  inline static int stacksize = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_VBCC1() {}
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
  static void tarjan1(int u) {
    (dfn[u] = (low[u] = (++cntd)));
    (sta[(++top)] = u);
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      int v = to[e];
      if ((dfn[v] == 0)) {
        Code04_VBCC1::tarjan1(v);
        (low[u] = jmin(low[u], low[v]));
        if ((low[v] >= dfn[u])) {
          (vbccCnt++);
          (vbccSiz[vbccCnt] = 1);
          (vbccArr[(++idx)] = u);
          (vbccl[vbccCnt] = idx);
          int pop = {};
          do {
            (pop = sta[(top--)]);
            (vbccSiz[vbccCnt]++);
            (vbccArr[(++idx)] = pop);
          } while ((pop != v));
          (vbccr[vbccCnt] = idx);
        }
      } else {
        (low[u] = jmin(low[u], dfn[v]));
      }
    }
  }
  static void tarjan2(int node) {
    (stacksize = 0);
    Code04_VBCC1::push(node, (-1), (-1));
    int v = {};
    while ((stacksize > 0)) {
      Code04_VBCC1::pop();
      if ((status == (-1))) {
        (dfn[u] = (low[u] = (++cntd)));
        (sta[(++top)] = u);
        (e = head[u]);
      } else {
        (v = to[e]);
        if ((status == 0)) {
          (low[u] = jmin(low[u], low[v]));
          if ((low[v] >= dfn[u])) {
            (vbccCnt++);
            (vbccSiz[vbccCnt] = 1);
            (vbccArr[(++idx)] = u);
            (vbccl[vbccCnt] = idx);
            int pop = {};
            do {
              (pop = sta[(top--)]);
              (vbccSiz[vbccCnt]++);
              (vbccArr[(++idx)] = pop);
            } while ((pop != v));
            (vbccr[vbccCnt] = idx);
          }
        } else {
          (low[u] = jmin(low[u], dfn[v]));
        }
        (e = nxt[e]);
      }
      if ((e != 0)) {
        (v = to[e]);
        if ((dfn[v] == 0)) {
          Code04_VBCC1::push(u, 0, e);
          Code04_VBCC1::push(v, (-1), (-1));
        } else {
          Code04_VBCC1::push(u, 1, e);
        }
      }
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (m = in.nextInt());
    {
      int i = 1;
      int u = {};
      int v = {};
      for (; (i <= m); (i++)) {
        (u = in.nextInt());
        (v = in.nextInt());
        if ((u != v)) {
          Code04_VBCC1::addEdge(u, v);
          Code04_VBCC1::addEdge(v, u);
        }
      }
    }
    for (int i = 1; (i <= n); (i++)) {
      if ((dfn[i] == 0)) {
        if ((head[i] == 0)) {
          (vbccCnt++);
          (vbccSiz[vbccCnt] = 1);
          (vbccArr[(++idx)] = i);
          (vbccl[vbccCnt] = (vbccr[vbccCnt] = idx));
        } else {
          Code04_VBCC1::tarjan2(i);
        }
      }
    }
    out.println(vbccCnt);
    for (int i = 1; (i <= vbccCnt); (i++)) {
      out.println(vbccSiz[i]);
      for (int j = vbccl[i]; (j <= vbccr[i]); (j++)) {
        out.print((vbccArr[j] + String(u" ")));
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
  Code04_VBCC1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 点双连通分量模版题1，java版
// 给定一张无向图，一共n个点、m条边，建图时忽略自环
// 打印点双连通分量的个数
// 打印每个点双连通分量的大小和节点编号
// 打印顺序随意
// 每个孤立点分配一个点双连通分量
// 1 <= n <= 5 * 10^5
// 1 <= m <= 2 * 10^6
// 测试链接 : https://www.luogu.com.cn/problem/P8435
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 迭代版需要的栈，讲解118讲了递归改迭代的技巧
        // 递归版，Tarjan算法求解点双连通分量
        // 迭代版，Tarjan算法求解点双连通分量
                                        // tarjan1(i);
        // 读写工具类
*/

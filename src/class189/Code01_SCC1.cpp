// Source: src/class189/Code01_SCC1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_SCC1 {
  inline static int MAXN = 10001;
  inline static int MAXM = 100001;
  inline static int n = {};
  inline static int m = {};
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
  inline static Array<int> sccArr = make_array<int>(MAXN);
  inline static Array<int> sccl = make_array<int>(MAXN);
  inline static Array<int> sccr = make_array<int>(MAXN);
  inline static int idx = {};
  inline static int sccCnt = {};
  inline static Array<bool> sccPrint = make_array<bool>(MAXN);
  inline static Array<Array<int>> stack = make_array<int>(MAXN, 3);
  inline static int u = {};
  inline static int status = {};
  inline static int e = {};
  inline static int stacksize = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_SCC1() {}
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
        Code01_SCC1::tarjan1(v);
        (low[u] = jmin(low[u], low[v]));
      } else {
        if ((belong[v] == 0)) {
          (low[u] = jmin(low[u], dfn[v]));
        }
      }
    }
    if ((dfn[u] == low[u])) {
      (sccCnt++);
      (sccl[sccCnt] = (idx + 1));
      int pop = {};
      do {
        (pop = sta[(top--)]);
        (belong[pop] = sccCnt);
        (sccArr[(++idx)] = pop);
      } while ((pop != u));
      (sccr[sccCnt] = idx);
    }
  }
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
  static void tarjan2(int node) {
    (stacksize = 0);
    Code01_SCC1::push(node, (-1), (-1));
    int v = {};
    while ((stacksize > 0)) {
      Code01_SCC1::pop();
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
          Code01_SCC1::push(u, 0, e);
          Code01_SCC1::push(v, (-1), (-1));
        } else {
          Code01_SCC1::push(u, 1, e);
        }
      } else {
        if ((dfn[u] == low[u])) {
          (sccCnt++);
          (sccl[sccCnt] = (idx + 1));
          int pop = {};
          do {
            (pop = sta[(top--)]);
            (belong[pop] = sccCnt);
            (sccArr[(++idx)] = pop);
          } while ((pop != u));
          (sccr[sccCnt] = idx);
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
        Code01_SCC1::addEdge(u, v);
      }
    }
    for (int i = 1; (i <= n); (i++)) {
      if ((dfn[i] == 0)) {
        Code01_SCC1::tarjan2(i);
      }
    }
    out.println(sccCnt);
    for (int i = 1; (i <= sccCnt); (i++)) {
      j::sort(sccArr, sccl[i], (sccr[i] + 1));
    }
    for (int i = 1; (i <= n); (i++)) {
      int scc = belong[i];
      if ((!sccPrint[scc])) {
        (sccPrint[scc] = true);
        for (int j = sccl[scc]; (j <= sccr[scc]); (j++)) {
          out.print((sccArr[j] + String(u" ")));
        }
        out.println();
      }
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code01_SCC1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 强连通分量模版题1，java版
// 给定一张n个点，m条边的有向图
// 求出所有强连通分量，先打印强连通分量的数量
// 然后打印1号点所在的强连通分量，然后打印2号点所在的强连通分量，以此类推
// 如果当前节点属于之前的强连通分量，那就跳过，直到打印所有强连通分量
// 打印每个强连通分量时，按照节点编号从小到大打印
// 1 <= n <= 10^4
// 1 <= m <= 10^5
// 测试链接 : https://www.luogu.com.cn/problem/B3609
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 递归版
                                // 如果 belong[v] != 0
就是遇到了弃边，什么也不做
        // 迭代版需要的栈，讲解118讲了递归改迭代的技巧
        // 迭代版
        // u表示当前节点
        // e表示u当前处理的边，如果e == 0，说明所有边都处理完了
        // status的具体说明如下
        //     如果status == -1，表示u没有遍历过任何儿子
        //     如果status == 0，表示u遍历到儿子v，然后发现dfn[v] == 0
        //         并且执行完了tarjan(v)，对应递归版for循环中的第一个分支
        //     如果status == 1，表示u遍历到儿子v，然后发现dfn[v] != 0
        //         对应递归版for循环中的第二个分支
                                        // (当前节点, 状态, 边)先进入栈
                                        // (儿子节点, 状态, 边)再进入栈
                                        // 那么儿子节点的tarjan过程会先执行
                                        //
等到处理当前节点时，low[儿子节点]信息就生成好了
                                // tarjan1(i);
        // 读写工具类
*/

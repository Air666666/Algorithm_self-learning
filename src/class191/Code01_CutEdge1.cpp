// Source: src/class191/Code01_CutEdge1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_CutEdge1 {
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
  inline static Array<bool> cutEdge = make_array<bool>(MAXM);
  inline static Array<Array<int>> stack = make_array<int>(MAXN, 4);
  inline static int u = {};
  inline static int preEdge = {};
  inline static int status = {};
  inline static int e = {};
  inline static int stacksize = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_CutEdge1() {}
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
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      if (((e ^ 1) == preEdge)) {
        continue;
      }
      int v = to[e];
      if ((dfn[v] == 0)) {
        Code01_CutEdge1::tarjan1(v, e);
        (low[u] = jmin(low[u], low[v]));
        if ((low[v] > dfn[u])) {
          (cutEdge[jshr(e, 1)] = true);
        }
      } else {
        (low[u] = jmin(low[u], dfn[v]));
      }
    }
  }
  static void tarjan2(int node, int pree) {
    (stacksize = 0);
    Code01_CutEdge1::push(node, pree, (-1), (-1));
    int v = {};
    while ((stacksize > 0)) {
      Code01_CutEdge1::pop();
      if ((status == (-1))) {
        (dfn[u] = (low[u] = (++cntd)));
        (e = head[u]);
      } else {
        (v = to[e]);
        if ((status == 0)) {
          (low[u] = jmin(low[u], low[v]));
          if ((low[v] > dfn[u])) {
            (cutEdge[jshr(e, 1)] = true);
          }
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
          Code01_CutEdge1::push(u, preEdge, 0, e);
          Code01_CutEdge1::push(v, e, (-1), (-1));
        } else {
          Code01_CutEdge1::push(u, preEdge, 1, e);
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
        Code01_CutEdge1::addEdge(u, v);
        Code01_CutEdge1::addEdge(v, u);
      }
    }
    for (int i = 1; (i <= n); (i++)) {
      if ((dfn[i] == 0)) {
        Code01_CutEdge1::tarjan2(i, 0);
      }
    }
    int ansCnt = 0;
    for (int i = 1; (i <= m); (i++)) {
      if (cutEdge[i]) {
        (ansCnt++);
      }
    }
    out.println(ansCnt);
    for (int i = 1; (i <= m); (i++)) {
      if (cutEdge[i]) {
        out.print((i + String(u" ")));
      }
    }
    out.println();
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code01_CutEdge1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 割边模版题1，java版
// 给定一张无向图，一共n个点、m条边
// 图中可能存在多个连通区，对每个连通区求割边
// 先打印割边的总数量，然后从小到大打印所有割边的序号
// 请保证原图即使有重边和自环，答案依然正确
// 1 <= n <= 5 * 10^5
// 1 <= m <= 2 * 10^6
// 测试链接 : https://www.luogu.com.cn/problem/U582665
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 迭代版需要的栈，讲解118讲了递归改迭代的技巧
        // 递归版
                                // 回边是dfn[v] < dfn[u]，弃边是dfn[v] > dfn[u]
                                //
因为low[u]初始值就是dfn[u]，所以弃边出现时，无法更新low[u]
        // 迭代版
        // u表示当前节点，preEdge表示来边
        // e表示u当前处理的边
        //     如果(e ^ 1) == preEdge，跳过当前边，对应递归版中的第一个if
        //     如果e == 0，说明所有边都处理完了
        // status的具体说明如下
        //     如果status == -1，表示u没有遍历过任何儿子
        //     如果status == 0，表示u遍历到儿子v，然后发现dfn[v] == 0
        //         并且执行完了tarjan(v, e)，对应递归版for循环的第二个if
        //     如果status == 1，表示u遍历到儿子v，然后发现dfn[v] != 0
        //         对应递归版for循环中的else分支
                                // tarjan1(i, 0);
        // 读写工具类
*/

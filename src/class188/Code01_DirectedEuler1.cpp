// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P7771

// Source: src/class188/Code01_DirectedEuler1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_DirectedEuler1 {
  struct EdgeCmp;
  struct EdgeCmp {
    String toString() const { return j::str(static_cast<const void *>(this)); }
    EdgeCmp() {}
    int compare(Array<int> e1, Array<int> e2) {
      return ((e1[0] != e2[0]) ? (e1[0] - e2[0]) : (e1[1] - e2[1]));
    }
  };
  inline static int MAXN = 100001;
  inline static int MAXM = 200002;
  inline static int n = {};
  inline static int m = {};
  inline static Array<Array<int>> edgeArr = make_array<int>(MAXM, 2);
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> nxt = make_array<int>(MAXM);
  inline static Array<int> to = make_array<int>(MAXM);
  inline static int cntg = {};
  inline static Array<int> cur = make_array<int>(MAXN);
  inline static Array<int> outDeg = make_array<int>(MAXN);
  inline static Array<int> inDeg = make_array<int>(MAXN);
  inline static Array<int> path = make_array<int>(MAXM);
  inline static int cntp = {};
  inline static Array<int> sta = make_array<int>(MAXM);
  inline static int top = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_DirectedEuler1() {}
  static void addEdge(int u, int v) {
    (nxt[(++cntg)] = head[u]);
    (to[cntg] = v);
    (head[u] = cntg);
  }
  static void connect() {
    j::sort(edgeArr, 1, (m + 1), new EdgeCmp());
    {
      int l = 1;
      int r = 1;
      for (; (l <= m); (l = (++r))) {
        while ((((r + 1) <= m) && (edgeArr[l][0] == edgeArr[(r + 1)][0]))) {
          (r++);
        }
        {
          int i = r;
          int u = {};
          int v = {};
          for (; (i >= l); (i--)) {
            (u = edgeArr[i][0]);
            (v = edgeArr[i][1]);
            (outDeg[u]++);
            (inDeg[v]++);
            Code01_DirectedEuler1::addEdge(u, v);
          }
        }
      }
    }
    for (int i = 1; (i <= n); (i++)) {
      (cur[i] = head[i]);
    }
  }
  static int directedStart() {
    int start = (-1);
    int end = (-1);
    for (int i = 1; (i <= n); (i++)) {
      int v = (outDeg[i] - inDeg[i]);
      if (((((v < (-1)) || (v > 1)) || ((v == 1) && (start != (-1)))) ||
           ((v == (-1)) && (end != (-1))))) {
        return (-1);
      }
      if ((v == 1)) {
        (start = i);
      }
      if ((v == (-1))) {
        (end = i);
      }
    }
    if (((start == (-1)) ^ (end == (-1)))) {
      return (-1);
    }
    if ((start != (-1))) {
      return start;
    }
    for (int i = 1; (i <= n); (i++)) {
      if ((outDeg[i] > 0)) {
        return i;
      }
    }
    return (-1);
  }
  static void euler1(int u) {
    for (int e = cur[u]; (e > 0); (e = cur[u])) {
      (cur[u] = nxt[e]);
      Code01_DirectedEuler1::euler1(to[e]);
    }
    (path[(++cntp)] = u);
  }
  static void euler2(int node) {
    (top = 0);
    (sta[(++top)] = node);
    while ((top > 0)) {
      int u = sta[(top--)];
      int e = cur[u];
      if ((e != 0)) {
        (cur[u] = nxt[e]);
        (sta[(++top)] = u);
        (sta[(++top)] = to[e]);
      } else {
        (path[(++cntp)] = u);
      }
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (m = in.nextInt());
    for (int i = 1; (i <= m); (i++)) {
      (edgeArr[i][0] = in.nextInt());
      (edgeArr[i][1] = in.nextInt());
    }
    Code01_DirectedEuler1::connect();
    int start = Code01_DirectedEuler1::directedStart();
    if ((start == (-1))) {
      out.println(String(u"No"));
    } else {
      Code01_DirectedEuler1::euler2(start);
      if ((cntp != (m + 1))) {
        out.println(String(u"No"));
      } else {
        for (int i = cntp; (i >= 1); (i--)) {
          out.print((path[i] + String(u" ")));
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
  Code01_DirectedEuler1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 有向图的欧拉路径，java版
// 图中有n个点，m条有向边，每条边给出两个端点
// 如果存在欧拉路径，输出字典序最小的结果，如果不存在打印No
// 1 <= n <= 10^5
// 1 <= m <= 2 * 10^5
// 测试链接 : https://www.luogu.com.cn/problem/P7771
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 有向图中找到一个起点，去生成欧拉回路 或者 欧拉路径
        // Hierholzer算法递归版，java会爆栈，C++可以通过
        // Hierholzer算法迭代版
                        // euler1(start);
        // 读写工具类
*/

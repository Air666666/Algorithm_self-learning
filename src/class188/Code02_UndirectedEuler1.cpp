// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P2731

// Source: src/class188/Code02_UndirectedEuler1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_UndirectedEuler1 {
  struct EdgeCmp;
  struct EdgeCmp {
    String toString() const { return j::str(static_cast<const void *>(this)); }
    EdgeCmp() {}
    int compare(Array<int> e1, Array<int> e2) {
      return ((e1[0] != e2[0]) ? (e1[0] - e2[0]) : (e1[1] - e2[1]));
    }
  };
  inline static int MAXN = 501;
  inline static int MAXM = 2001;
  inline static int n = 500;
  inline static int m = {};
  inline static int k = {};
  inline static Array<Array<int>> edgeArr = make_array<int>(jshl(MAXM, 1), 3);
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> nxt = make_array<int>(jshl(MAXM, 1));
  inline static Array<int> to = make_array<int>(jshl(MAXM, 1));
  inline static Array<int> eid = make_array<int>(jshl(MAXM, 1));
  inline static int cntg = {};
  inline static Array<int> cur = make_array<int>(MAXN);
  inline static Array<int> deg = make_array<int>(MAXN);
  inline static Array<bool> vis = make_array<bool>(MAXM);
  inline static Array<int> path = make_array<int>(MAXM);
  inline static int cntp = {};
  inline static Array<int> sta = make_array<int>(MAXM);
  inline static int top = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_UndirectedEuler1() {}
  static void addEdge(int u, int v, int id) {
    (nxt[(++cntg)] = head[u]);
    (to[cntg] = v);
    (eid[cntg] = id);
    (head[u] = cntg);
  }
  static void connect() {
    j::sort(edgeArr, 1, (k + 1), new EdgeCmp());
    {
      int l = 1;
      int r = 1;
      for (; (l <= k); (l = (++r))) {
        while ((((r + 1) <= k) && (edgeArr[l][0] == edgeArr[(r + 1)][0]))) {
          (r++);
        }
        {
          int i = r;
          int u = {};
          int v = {};
          int id = {};
          for (; (i >= l); (i--)) {
            (u = edgeArr[i][0]);
            (v = edgeArr[i][1]);
            (id = edgeArr[i][2]);
            (deg[u]++);
            Code02_UndirectedEuler1::addEdge(u, v, id);
          }
        }
      }
    }
    for (int i = 1; (i <= n); (i++)) {
      (cur[i] = head[i]);
    }
  }
  static int undirectedStart() {
    int odd = 0;
    for (int i = 1; (i <= n); (i++)) {
      if (((deg[i] & 1) == 1)) {
        (odd++);
      }
    }
    if (((odd != 0) && (odd != 2))) {
      return (-1);
    }
    for (int i = 1; (i <= n); (i++)) {
      if (((odd == 0) && (deg[i] > 0))) {
        return i;
      }
      if (((odd == 2) && ((deg[i] & 1) == 1))) {
        return i;
      }
    }
    return (-1);
  }
  static void euler1(int u) {
    for (int e = cur[u]; (e > 0); (e = cur[u])) {
      (cur[u] = nxt[e]);
      if ((!vis[eid[e]])) {
        (vis[eid[e]] = true);
        Code02_UndirectedEuler1::euler1(to[e]);
      }
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
        if ((!vis[eid[e]])) {
          (vis[eid[e]] = true);
          (sta[(++top)] = u);
          (sta[(++top)] = to[e]);
        } else {
          (sta[(++top)] = u);
        }
      } else {
        (path[(++cntp)] = u);
      }
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (m = in.nextInt());
    (k = 0);
    {
      int i = 1;
      int u = {};
      int v = {};
      for (; (i <= m); (i++)) {
        (u = in.nextInt());
        (v = in.nextInt());
        (edgeArr[(++k)][0] = u);
        (edgeArr[k][1] = v);
        (edgeArr[k][2] = i);
        (edgeArr[(++k)][0] = v);
        (edgeArr[k][1] = u);
        (edgeArr[k][2] = i);
      }
    }
    Code02_UndirectedEuler1::connect();
    int start = Code02_UndirectedEuler1::undirectedStart();
    if ((start == (-1))) {
      out.println(String(u"No"));
    } else {
      Code02_UndirectedEuler1::euler2(start);
      if ((cntp != (m + 1))) {
        out.println(String(u"No"));
      } else {
        for (int i = cntp; (i >= 1); (i--)) {
          out.println(path[i]);
        }
      }
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code02_UndirectedEuler1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 无向图的欧拉路径，java版
// 图中给定m条无向边，每条边给出两个端点
// 如果存在欧拉路径，输出字典序最小的结果，如果不存在打印No
// 节点编号的范围是[1, 500]，所有点不一定都出现，以给定的边为准
// 1 <= m <= 1024
// 测试链接 : https://www.luogu.com.cn/problem/P2731
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 无向图中找到一个起点，去生成欧拉回路 或者 欧拉路径
        // Hierholzer算法递归版
        // Hierholzer算法迭代版
                        // euler1(start);
        // 读写工具类
*/

// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P5782

// Source: src/class196/Code02_Committee1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_Committee1 {
  inline static int MAXN = 20001;
  inline static int MAXM = 50001;
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
  inline static int sccCnt = {};
  inline static Array<Array<int>> stack = make_array<int>(MAXN, 3);
  inline static int u = {};
  inline static int status = {};
  inline static int e = {};
  inline static int stacksize = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_Committee1() {}
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
        Code02_Committee1::tarjan1(v);
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
    Code02_Committee1::push(node, (-1), (-1));
    int v = {};
    while ((stacksize > 0)) {
      Code02_Committee1::pop();
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
          Code02_Committee1::push(u, 0, e);
          Code02_Committee1::push(v, (-1), (-1));
        } else {
          Code02_Committee1::push(u, 1, e);
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
  static int other(int x) { return (((x & 1) == 0) ? (x - 1) : (x + 1)); }
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
        Code02_Committee1::addEdge(u, Code02_Committee1::other(v));
        Code02_Committee1::addEdge(v, Code02_Committee1::other(u));
      }
    }
    for (int i = 1; (i <= jshl(n, 1)); (i++)) {
      if ((dfn[i] == 0)) {
        Code02_Committee1::tarjan2(i);
      }
    }
    bool check = true;
    {
      int i = 1;
      int a = {};
      int b = {};
      for (; (i <= n); (i++)) {
        (a = jshl(i, 1));
        (b = (a - 1));
        if ((belong[a] == belong[b])) {
          (check = false);
        }
      }
    }
    if (check) {
      {
        int i = 1;
        int a = {};
        int b = {};
        for (; (i <= n); (i++)) {
          (a = jshl(i, 1));
          (b = (a - 1));
          if ((belong[a] < belong[b])) {
            out.println(a);
          } else {
            out.println(b);
          }
        }
      }
    } else {
      out.println(String(u"NIE"));
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code02_Committee1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 和平委员会，java版
// 一共n个团体，每个团体有两个代表，所以有2n个代表
// 第i号团体两个代表的编号为2i−1和2i，然后给定m个讨厌关系
// 格式 x y : 编号x和编号y这两个代表，相互讨厌，不可共事
// 现在要选出n个人组成委员会，每个团体的两个代表，有且仅有1人入选
// 同时要求选出的委员会中，没有相互讨厌的代表，如果做不到，打印"NIE"
// 如果能做到，按升序打印组成委员会的n个人的编号，任何一种方案都可以
// 1 <= n <= 8 * 10^3
// 0 <= m <= 2 * 10^4
// 测试链接 : https://www.luogu.com.cn/problem/P5782
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 迭代版需要的栈，讲解118讲了递归改迭代的技巧
        // 递归版
        // 迭代版
                                // tarjan1(i);
        // 读写工具类
*/

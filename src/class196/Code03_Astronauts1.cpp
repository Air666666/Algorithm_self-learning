// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/UVA1391
// https://vjudge.net/problem/UVA-1391

// Source: src/class196/Code03_Astronauts1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_Astronauts1 {
  inline static int MAXN = 200001;
  inline static int MAXM = 500001;
  inline static int n = {};
  inline static int m = {};
  inline static Array<int> age = make_array<int>(MAXN);
  inline static int sumAge = {};
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
  Code03_Astronauts1() {}
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
  static void prepare() {
    (sumAge = (cntg = (cntd = (sccCnt = 0))));
    for (int i = 1; (i <= jshl(n, 1)); (i++)) {
      (head[i] = (dfn[i] = (low[i] = (belong[i] = 0))));
    }
  }
  static void addEdge(int u, int v) {
    (nxt[(++cntg)] = head[u]);
    (to[cntg] = v);
    (head[u] = cntg);
  }
  static bool older(int x) { return ((age[x] * n) >= sumAge); }
  static void tarjan1(int u) {
    (dfn[u] = (low[u] = (++cntd)));
    (sta[(++top)] = u);
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      int v = to[e];
      if ((dfn[v] == 0)) {
        Code03_Astronauts1::tarjan1(v);
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
    Code03_Astronauts1::push(node, (-1), (-1));
    int v = {};
    while ((stacksize > 0)) {
      Code03_Astronauts1::pop();
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
          Code03_Astronauts1::push(u, 0, e);
          Code03_Astronauts1::push(v, (-1), (-1));
        } else {
          Code03_Astronauts1::push(u, 1, e);
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
    while (((n != 0) && (m != 0))) {
      Code03_Astronauts1::prepare();
      for (int i = 1; (i <= n); (i++)) {
        (age[i] = in.nextInt());
        (sumAge += age[i]);
      }
      {
        int i = 1;
        int x = {};
        int y = {};
        for (; (i <= m); (i++)) {
          (x = in.nextInt());
          (y = in.nextInt());
          Code03_Astronauts1::addEdge((x + n), y);
          Code03_Astronauts1::addEdge((y + n), x);
          if ([&]() {
                auto jleft = Code03_Astronauts1::older(x);
                auto jright = Code03_Astronauts1::older(y);
                return (jleft == jright);
              }()) {
            Code03_Astronauts1::addEdge(x, (y + n));
            Code03_Astronauts1::addEdge(y, (x + n));
          }
        }
      }
      for (int i = 1; (i <= jshl(n, 1)); (i++)) {
        if ((dfn[i] == 0)) {
          Code03_Astronauts1::tarjan2(i);
        }
      }
      bool check = true;
      for (int i = 1; (i <= n); (i++)) {
        if ((belong[i] == belong[(i + n)])) {
          (check = false);
          break;
        }
      }
      if (check) {
        for (int i = 1; (i <= n); (i++)) {
          if ((belong[i] < belong[(i + n)])) {
            if (Code03_Astronauts1::older(i)) {
              out.println(String(u"A"));
            } else {
              out.println(String(u"B"));
            }
          } else {
            out.println(String(u"C"));
          }
        }
      } else {
        out.println(String(u"No solution."));
      }
      (n = in.nextInt());
      (m = in.nextInt());
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code03_Astronauts1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 宇航员，java版
//
一共n个人，一共A、B、C三个任务，所有人都能执行C任务，给定每人的年龄，假设平均年龄为f
// 年龄 >= f 的人可以执行A任务，年龄 < f 的人可以执行B任务
// 给定m个厌恶关系，格式 x y，代表编号x和编号y的两人相互讨厌
// 每个人必须选一个任务，相互讨厌的人不能分配相同任务，允许某个任务无人执行
// 如果存在分配任务的方案，打印每个人分配了什么任务，任何一种方案都可以
// 如果不存在方案，打印"No solution."
// 1 <= n、m <= 10^5
// 测试链接 : https://www.luogu.com.cn/problem/UVA1391
// 测试链接 : https://vjudge.net/problem/UVA-1391
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 迭代版需要的栈，讲解118讲了递归改迭代的技巧
        // 递归版
        // 迭代版
                                        // tarjan1(i);
        // 读写工具类
*/

// Source: src/class190/Code09_KillingGame1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code09_KillingGame1 {
  inline static int MAXN = 100001;
  inline static int MAXM = 300001;
  inline static int n = {};
  inline static int m = {};
  inline static Array<int> a = make_array<int>(MAXM);
  inline static Array<int> b = make_array<int>(MAXM);
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
  inline static Array<int> sccSiz = make_array<int>(MAXN);
  inline static int sccCnt = {};
  inline static Array<i64> edgeArr = make_array<i64>(MAXM);
  inline static int cnte = {};
  inline static Array<int> indegree = make_array<int>(MAXN);
  inline static Array<Array<int>> stack = make_array<int>(MAXN, 3);
  inline static int u = {};
  inline static int status = {};
  inline static int e = {};
  inline static int stacksize = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code09_KillingGame1() {}
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
        Code09_KillingGame1::tarjan1(v);
        (low[u] = jmin(low[u], low[v]));
      } else {
        if ((belong[v] == 0)) {
          (low[u] = jmin(low[u], dfn[v]));
        }
      }
    }
    if ((dfn[u] == low[u])) {
      (sccCnt++);
      (sccSiz[sccCnt] = 0);
      int pop = {};
      do {
        (pop = sta[(top--)]);
        (belong[pop] = sccCnt);
        (sccSiz[sccCnt]++);
      } while ((pop != u));
    }
  }
  static void tarjan2(int node) {
    (stacksize = 0);
    Code09_KillingGame1::push(node, (-1), (-1));
    int v = {};
    while ((stacksize > 0)) {
      Code09_KillingGame1::pop();
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
          Code09_KillingGame1::push(u, 0, e);
          Code09_KillingGame1::push(v, (-1), (-1));
        } else {
          Code09_KillingGame1::push(u, 1, e);
        }
      } else {
        if ((dfn[u] == low[u])) {
          (sccCnt++);
          (sccSiz[sccCnt] = 0);
          int pop = {};
          do {
            (pop = sta[(top--)]);
            (belong[pop] = sccCnt);
            (sccSiz[sccCnt]++);
          } while ((pop != u));
        }
      }
    }
  }
  static void condense() {
    (cntg = 0);
    for (int i = 1; (i <= sccCnt); (i++)) {
      (head[i] = 0);
    }
    for (int i = 1; (i <= m); (i++)) {
      int scc1 = belong[a[i]];
      int scc2 = belong[b[i]];
      if ((scc1 != scc2)) {
        (edgeArr[(++cnte)] = (jshl(static_cast<i64>(scc1), 32) | scc2));
      }
    }
    j::sort(edgeArr, 1, (cnte + 1));
    i64 pre = 0;
    i64 cur = {};
    for (int i = 1; (i <= cnte); (i++)) {
      (cur = edgeArr[i]);
      if ((cur != pre)) {
        int scc1 = static_cast<int>(jushr(cur, 32));
        int scc2 = static_cast<int>((cur & 0xffffffffLL));
        (indegree[scc2]++);
        Code09_KillingGame1::addEdge(scc1, scc2);
        (pre = cur);
      }
    }
  }
  static bool isolated(int i) {
    if (((indegree[i] > 0) || (sccSiz[i] > 1))) {
      return false;
    }
    if ((head[i] == 0)) {
      return true;
    }
    for (int e = head[i]; (e > 0); (e = nxt[e])) {
      int v = to[e];
      if ((indegree[v] == 1)) {
        return false;
      }
    }
    return true;
  }
  static double compute() {
    int inZero = 0;
    for (int i = 1; (i <= sccCnt); (i++)) {
      if ((indegree[i] == 0)) {
        (inZero++);
      }
    }
    for (int i = 1; (i <= sccCnt); (i++)) {
      if (Code09_KillingGame1::isolated(i)) {
        (inZero--);
        break;
      }
    }
    return (1.0 - jdiv(static_cast<double>(inZero), n));
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (m = in.nextInt());
    for (int i = 1; (i <= m); (i++)) {
      (a[i] = in.nextInt());
      (b[i] = in.nextInt());
      Code09_KillingGame1::addEdge(a[i], b[i]);
    }
    for (int i = 1; (i <= n); (i++)) {
      if ((dfn[i] == 0)) {
        Code09_KillingGame1::tarjan2(i);
      }
    }
    Code09_KillingGame1::condense();
    double ans = Code09_KillingGame1::compute();
    out.printf(String(u"%.6f\n"), ans);
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code09_KillingGame1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 杀人游戏，java版
// 一共n个人，只有一个杀手，每个人是杀手的概率均等，其他人都是平民
// 给定m个知晓关系，如果x知晓y，那么y是不是杀手，x就知道情况了
// 知晓关系是单向且可传递的，比如a知晓b，b知晓c，那么a知晓c
// 你可以盘问任何人，不仅能知道对方身份，并且对方知晓的所有情况都能获得
// 但是如果你直接盘问到杀手的话，杀手会原地爆炸，炸死所有人
// 你一定要确定所有人的身份，而且你充分了解知晓关系网，会用最优的盘问策略
// 返回最优盘问策略下，杀手不爆炸还能被揪出来的概率，保留小数点后面6位
// 1 <= n <= 10^5
// 0 <= m <= 3 * 10^5
// 测试链接 : https://www.luogu.com.cn/problem/P4819
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 迭代版需要的栈，讲解118讲了递归改迭代的技巧
        // 递归版，java会爆栈，C++可以通过
        // 迭代版
                                // tarjan1(i);
        // 读写工具类
*/

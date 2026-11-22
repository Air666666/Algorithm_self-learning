// Source: src/class195/Code09_Jail1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code09_Jail1 {
  inline static int MAXN = 120001;
  inline static int MAXT = (MAXN * 50);
  inline static int MAXE = (MAXN * 200);
  inline static int MAXP = 18;
  inline static int t = {};
  inline static int n = {};
  inline static int m = {};
  inline static Array<int> startTag = make_array<int>(MAXN);
  inline static Array<int> endTag = make_array<int>(MAXN);
  inline static Array<int> head1 = make_array<int>(MAXN);
  inline static Array<int> next1 = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> to1 = make_array<int>(jshl(MAXN, 1));
  inline static int cnt1 = {};
  inline static Array<int> indegree = make_array<int>(MAXT);
  inline static Array<int> head2 = make_array<int>(MAXT);
  inline static Array<int> next2 = make_array<int>(MAXE);
  inline static Array<int> to2 = make_array<int>(MAXE);
  inline static int cnt2 = {};
  inline static Array<int> dep = make_array<int>(MAXN);
  inline static Array<int> dfn = make_array<int>(MAXN);
  inline static Array<int> siz = make_array<int>(MAXN);
  inline static Array<Array<int>> stjump = make_array<int>(MAXN, MAXP);
  inline static int cntd = {};
  inline static Array<Array<int>> stout = make_array<int>(MAXN, MAXP);
  inline static Array<Array<int>> stin = make_array<int>(MAXN, MAXP);
  inline static int cntt = {};
  inline static Array<int> que = make_array<int>(MAXT);
  inline static Array<Array<int>> ufe = make_array<int>(MAXN, 3);
  inline static int stacksize = {};
  inline static int u = {};
  inline static int fa = {};
  inline static int e = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code09_Jail1() {}
  static void push(int u, int fa, int e) {
    (ufe[stacksize][0] = u);
    (ufe[stacksize][1] = fa);
    (ufe[stacksize][2] = e);
    (stacksize++);
  }
  static void pop() {
    (--stacksize);
    (u = ufe[stacksize][0]);
    (fa = ufe[stacksize][1]);
    (e = ufe[stacksize][2]);
  }
  static void addEdge1(int u, int v) {
    (next1[(++cnt1)] = head1[u]);
    (to1[cnt1] = v);
    (head1[u] = cnt1);
  }
  static void addEdge2(int u, int v) {
    (indegree[v]++);
    (next2[(++cnt2)] = head2[u]);
    (to2[cnt2] = v);
    (head2[u] = cnt2);
  }
  static void build1(int u, int fa) {
    (dep[u] = (dep[fa] + 1));
    (dfn[u] = (++cntd));
    (siz[u] = 1);
    (stjump[u][0] = fa);
    (stout[u][0] = (++cntt));
    Code09_Jail1::addEdge2(startTag[u], cntt);
    Code09_Jail1::addEdge2(startTag[fa], cntt);
    (stin[u][0] = (++cntt));
    Code09_Jail1::addEdge2(cntt, endTag[u]);
    Code09_Jail1::addEdge2(cntt, endTag[fa]);
    for (int p = 1; (p < MAXP); (p++)) {
      (stjump[u][p] = stjump[stjump[u][(p - 1)]][(p - 1)]);
      (stout[u][p] = (++cntt));
      Code09_Jail1::addEdge2(stout[u][(p - 1)], cntt);
      Code09_Jail1::addEdge2(stout[stjump[u][(p - 1)]][(p - 1)], cntt);
      (stin[u][p] = (++cntt));
      Code09_Jail1::addEdge2(cntt, stin[u][(p - 1)]);
      Code09_Jail1::addEdge2(cntt, stin[stjump[u][(p - 1)]][(p - 1)]);
    }
    for (int e = head1[u]; (e > 0); (e = next1[e])) {
      int v = to1[e];
      if ((v != fa)) {
        Code09_Jail1::build1(v, u);
        (siz[u] += siz[v]);
      }
    }
  }
  static void build2(int cur, int father) {
    (stacksize = 0);
    Code09_Jail1::push(cur, father, (-1));
    while ((stacksize > 0)) {
      Code09_Jail1::pop();
      if ((e == (-1))) {
        (dep[u] = (dep[fa] + 1));
        (dfn[u] = (++cntd));
        (siz[u] = 1);
        (stjump[u][0] = fa);
        (stout[u][0] = (++cntt));
        Code09_Jail1::addEdge2(startTag[u], cntt);
        Code09_Jail1::addEdge2(startTag[fa], cntt);
        (stin[u][0] = (++cntt));
        Code09_Jail1::addEdge2(cntt, endTag[u]);
        Code09_Jail1::addEdge2(cntt, endTag[fa]);
        for (int p = 1; (p < MAXP); (p++)) {
          (stjump[u][p] = stjump[stjump[u][(p - 1)]][(p - 1)]);
          (stout[u][p] = (++cntt));
          Code09_Jail1::addEdge2(stout[u][(p - 1)], cntt);
          Code09_Jail1::addEdge2(stout[stjump[u][(p - 1)]][(p - 1)], cntt);
          (stin[u][p] = (++cntt));
          Code09_Jail1::addEdge2(cntt, stin[u][(p - 1)]);
          Code09_Jail1::addEdge2(cntt, stin[stjump[u][(p - 1)]][(p - 1)]);
        }
        (e = head1[u]);
      } else {
        (e = next1[e]);
      }
      if ((e != 0)) {
        Code09_Jail1::push(u, fa, e);
        if ((to1[e] != fa)) {
          Code09_Jail1::push(to1[e], u, (-1));
        }
      } else {
        for (int ei = head1[u]; (ei > 0); (ei = next1[ei])) {
          int v = to1[ei];
          if ((v != fa)) {
            (siz[u] += siz[v]);
          }
        }
      }
    }
  }
  static bool isAncestor(int a, int b) {
    return ((dfn[a] <= dfn[b]) && (dfn[b] < (dfn[a] + siz[a])));
  }
  static int kthAncestor(int x, int k) {
    for (int p = 0; (p < MAXP); (p++)) {
      if (((jshr(k, p) & 1) != 0)) {
        (x = stjump[x][p]);
      }
    }
    return x;
  }
  static int nearest(int x, int y) {
    if (Code09_Jail1::isAncestor(y, x)) {
      return Code09_Jail1::kthAncestor(x, ((dep[x] - dep[y]) - 1));
    } else {
      return stjump[y][0];
    }
  }
  static void pathSet(int x, int y, int prisoner) {
    if ((dep[x] < dep[y])) {
      int tmp = x;
      (x = y);
      (y = tmp);
    }
    Code09_Jail1::addEdge2(startTag[y], prisoner);
    Code09_Jail1::addEdge2(prisoner, endTag[y]);
    for (int p = (MAXP - 1); (p >= 0); (p--)) {
      if ((dep[stjump[x][p]] >= dep[y])) {
        Code09_Jail1::addEdge2(stout[x][p], prisoner);
        Code09_Jail1::addEdge2(prisoner, stin[x][p]);
        (x = stjump[x][p]);
      }
    }
    if ((x == y)) {
      return;
    }
    for (int p = (MAXP - 1); (p >= 0); (p--)) {
      if ((stjump[x][p] != stjump[y][p])) {
        Code09_Jail1::addEdge2(stout[x][p], prisoner);
        Code09_Jail1::addEdge2(stout[y][p], prisoner);
        Code09_Jail1::addEdge2(prisoner, stin[x][p]);
        Code09_Jail1::addEdge2(prisoner, stin[y][p]);
        (x = stjump[x][p]);
        (y = stjump[y][p]);
      }
    }
    Code09_Jail1::addEdge2(stout[x][0], prisoner);
    Code09_Jail1::addEdge2(prisoner, stin[x][0]);
  }
  static void link(int x, int y) {
    int prisoner = (++cntt);
    Code09_Jail1::addEdge2(prisoner, startTag[x]);
    Code09_Jail1::addEdge2(prisoner, endTag[x]);
    Code09_Jail1::addEdge2(startTag[y], prisoner);
    Code09_Jail1::addEdge2(endTag[y], prisoner);
    if (((stjump[x][0] != y) && (stjump[y][0] != x))) {
      int a = Code09_Jail1::nearest(y, x);
      int b = Code09_Jail1::nearest(x, y);
      Code09_Jail1::pathSet(a, b, prisoner);
    }
  }
  static bool topo() {
    int qi = 1;
    int qsiz = 0;
    for (int i = 1; (i <= cntt); (i++)) {
      if ((indegree[i] == 0)) {
        (que[(++qsiz)] = i);
      }
    }
    while ((qi <= qsiz)) {
      int u = que[(qi++)];
      for (int e = head2[u]; (e > 0); (e = next2[e])) {
        int v = to2[e];
        if (((--indegree[v]) == 0)) {
          (que[(++qsiz)] = v);
        }
      }
    }
    return (qsiz == cntt);
  }
  static void clear() {
    for (int i = 1; (i <= n); (i++)) {
      (head1[i] = 0);
    }
    for (int i = 1; (i <= cntt); (i++)) {
      (head2[i] = (indegree[i] = 0));
    }
    (cnt1 = (cnt2 = (cntt = (cntd = 0))));
    (dep[1] = 0);
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (t = in.nextInt());
    for (int c = 1; (c <= t); (c++)) {
      (n = in.nextInt());
      (cntt = jshl(n, 1));
      for (int i = 1; (i <= n); (i++)) {
        (startTag[i] = i);
        (endTag[i] = (i + n));
      }
      {
        int i = 1;
        int u = {};
        int v = {};
        for (; (i < n); (i++)) {
          (u = in.nextInt());
          (v = in.nextInt());
          Code09_Jail1::addEdge1(u, v);
          Code09_Jail1::addEdge1(v, u);
        }
      }
      Code09_Jail1::build2(1, 1);
      (m = in.nextInt());
      {
        int i = 1;
        int x = {};
        int y = {};
        for (; (i <= m); (i++)) {
          (x = in.nextInt());
          (y = in.nextInt());
          Code09_Jail1::link(x, y);
        }
      }
      bool ans = Code09_Jail1::topo();
      out.println((ans ? String(u"Yes") : String(u"No")));
      Code09_Jail1::clear();
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code09_Jail1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 监狱，java版
// 一共有n个房间，给定n-1条无向边，所有房间组成一棵树
// 一共有m个囚犯，每个囚犯给出卧室房间号和工作室房间号，囚犯初始时都在卧室
// 每个囚犯的卧室和工作室一定不同，任何两个囚犯既不共用卧室，也不共用工作室
// 但是有可能某个房间，作为一个囚犯的卧室，同时作为另一个囚犯的工作室
// 你的任务是让所有囚犯从自己的卧室出发，只走最短路去自己的工作室
// 你可以随意下达指令，每条指令只能选择一个囚犯，沿一条边移动一步
// 任何时刻不能让任何房间里出现两个囚犯，打印你能否完成任务
// 1 <= n、m <= 1.2 * 10^5
// 测试链接 : https://www.luogu.com.cn/problem/P9520
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 两个标签的编号
        // 原始的树
        // 相对次序的关系图
        // 树上倍增
        // 倍增优化建图
        // 拓扑排序判环
        // 讲解118，递归改迭代需要的栈
        // 递归版
        // 迭代版
                        // build1(1, 1);
        // 读写工具类
*/

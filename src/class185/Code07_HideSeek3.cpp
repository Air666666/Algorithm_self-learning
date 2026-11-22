// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P2056

// Source: src/class185/Code07_HideSeek3.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code07_HideSeek3 {
  inline static int MAXN = 100001;
  inline static int MAXT = (MAXN * 12);
  inline static int INF = 1000000001;
  inline static int PAR = (-1);
  inline static int PAL = (-2);
  inline static int n = {};
  inline static int m = {};
  inline static Array<bool> black = make_array<bool>(MAXN);
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> nxt = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> to = make_array<int>(jshl(MAXN, 1));
  inline static int cntg = {};
  inline static Array<int> dfn = make_array<int>(MAXN);
  inline static Array<int> seg = make_array<int>((MAXN * 3));
  inline static int cntd = {};
  inline static Array<int> pr = make_array<int>(MAXT);
  inline static Array<int> pl = make_array<int>(MAXT);
  inline static Array<int> ladd = make_array<int>(MAXT);
  inline static Array<int> lminus = make_array<int>(MAXT);
  inline static Array<int> radd = make_array<int>(MAXT);
  inline static Array<int> rminus = make_array<int>(MAXT);
  inline static Array<int> dist = make_array<int>(MAXT);
  inline static Array<Array<int>> stack = make_array<int>(MAXN, 3);
  inline static int u = {};
  inline static int f = {};
  inline static int e = {};
  inline static int stacksize = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code07_HideSeek3() {}
  static void push(int u, int f, int e) {
    (stack[stacksize][0] = u);
    (stack[stacksize][1] = f);
    (stack[stacksize][2] = e);
    (stacksize++);
  }
  static void pop() {
    (--stacksize);
    (u = stack[stacksize][0]);
    (f = stack[stacksize][1]);
    (e = stack[stacksize][2]);
  }
  static void addEdge(int u, int v) {
    (nxt[(++cntg)] = head[u]);
    (to[cntg] = v);
    (head[u] = cntg);
  }
  static void dfs1(int u, int fa) {
    (seg[(++cntd)] = PAL);
    (seg[(++cntd)] = u);
    (dfn[u] = cntd);
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      int v = to[e];
      if ((v != fa)) {
        Code07_HideSeek3::dfs1(v, u);
      }
    }
    (seg[(++cntd)] = PAR);
  }
  static void dfs2(int cur, int fa) {
    (stacksize = 0);
    Code07_HideSeek3::push(cur, fa, (-1));
    while ((stacksize > 0)) {
      Code07_HideSeek3::pop();
      if ((e == (-1))) {
        (seg[(++cntd)] = PAL);
        (seg[(++cntd)] = u);
        (dfn[u] = cntd);
        (e = head[u]);
      } else {
        (e = nxt[e]);
      }
      if ((e != 0)) {
        Code07_HideSeek3::push(u, f, e);
        int v = to[e];
        if ((v != f)) {
          Code07_HideSeek3::push(v, u, (-1));
        }
      } else {
        (seg[(++cntd)] = PAR);
      }
    }
  }
  static void up(int i) {
    int pre = jshl(i, 1);
    int post = (jshl(i, 1) | 1);
    if ((pl[pre] > pr[post])) {
      (pr[i] = pr[pre]);
      (pl[i] = ((pl[pre] - pr[post]) + pl[post]));
    } else {
      (pr[i] = ((pr[pre] + pr[post]) - pl[pre]));
      (pl[i] = pl[post]);
    }
    (ladd[i] = jmax(ladd[pre], jmax(((pr[pre] + ladd[post]) - pl[pre]),
                                    ((pr[pre] + pl[pre]) + lminus[post]))));
    (lminus[i] = jmax(lminus[pre], ((pl[pre] - pr[pre]) + lminus[post])));
    (radd[i] = jmax(radd[post], jmax(((radd[pre] - pr[post]) + pl[post]),
                                     ((rminus[pre] + pr[post]) + pl[post]))));
    (rminus[i] = jmax(rminus[post], ((rminus[pre] + pr[post]) - pl[post])));
    (dist[i] = [&]() {
      auto jargument_0 = jmax(dist[pre], dist[post]);
      auto jargument_1 =
          jmax((radd[pre] + lminus[post]), (rminus[pre] + ladd[post]));
      return jmax(jargument_0, jargument_1);
    }());
  }
  static void point(int i, int v) {
    (pr[i] = (pl[i] = 0));
    (ladd[i] = (lminus[i] = (radd[i] = (rminus[i] = (dist[i] = (-INF))))));
    if ((v == PAR)) {
      (pr[i] = 1);
    } else if ((v == PAL)) {
      (pl[i] = 1);
    } else if (black[v]) {
      (ladd[i] = (lminus[i] = (radd[i] = (rminus[i] = (dist[i] = 0)))));
    }
  }
  static void build(int l, int r, int i) {
    if ((l == r)) {
      Code07_HideSeek3::point(i, seg[l]);
    } else {
      int mid = jshr((l + r), 1);
      Code07_HideSeek3::build(l, mid, jshl(i, 1));
      Code07_HideSeek3::build((mid + 1), r, (jshl(i, 1) | 1));
      Code07_HideSeek3::up(i);
    }
  }
  static void update(int jobi, int l, int r, int i) {
    if ((l == r)) {
      Code07_HideSeek3::point(i, seg[l]);
    } else {
      int mid = jshr((l + r), 1);
      if ((jobi <= mid)) {
        Code07_HideSeek3::update(jobi, l, mid, jshl(i, 1));
      } else {
        Code07_HideSeek3::update(jobi, (mid + 1), r, (jshl(i, 1) | 1));
      }
      Code07_HideSeek3::up(i);
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO();
    IO out = IO(IO(jout));
    (n = in.nextInt());
    for (int i = 1; (i <= n); (i++)) {
      (black[i] = true);
    }
    {
      int i = 1;
      int u = {};
      int v = {};
      for (; (i < n); (i++)) {
        (u = in.nextInt());
        (v = in.nextInt());
        Code07_HideSeek3::addEdge(u, v);
        Code07_HideSeek3::addEdge(v, u);
      }
    }
    Code07_HideSeek3::dfs2(1, 0);
    Code07_HideSeek3::build(1, cntd, 1);
    (m = in.nextInt());
    int blackCnt = n;
    jchar op = {};
    {
      int i = 1;
      int x = {};
      for (; (i <= m); (i++)) {
        (op = in.nextTokenLastChar());
        if ((op == u'C')) {
          (x = in.nextInt());
          (black[x] = (!black[x]));
          if (black[x]) {
            (blackCnt++);
          } else {
            (blackCnt--);
          }
          Code07_HideSeek3::update(dfn[x], 1, cntd, 1);
        } else {
          if ((blackCnt <= 1)) {
            out.println((blackCnt - 1));
          } else {
            out.println(dist[1]);
          }
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
  Code07_HideSeek3::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 捉迷藏，最优解，树的括号序 + 巧妙线段树，java版
// 树上有n个点，点的初始颜色为黑，给定n-1条边，边权都是1
// 一共有m条操作，每条操作是如下两种类型中的一种
// 操作 C x : 改变点x的颜色，黑变成白，白变成黑
// 操作 G   : 打印最远的两个黑点的距离，只有一个黑点打印0，无黑点打印-1
// 1 <= n <= 10^5    1 <= m <= 5 * 10^5
// 测试链接 : https://www.luogu.com.cn/problem/P2056
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 以下概念都是括号序列消除到最简状态之后的情况
        // pr : 右括号数量
        // pl : 左括号数量
        // ladd   : 左端点到任意黑点，max(右括号 + 左括号)
        // lminus : 左端点到任意黑点，max(左括号 - 右括号)
        // radd   : 任意黑点到右端点，max(右括号 + 左括号)
        // rminus : 任意黑点到右端点，max(右括号 - 左括号)
        // dist   : 选择两个黑点的最大距离
        // 注意区分lminus、rminus
        // 讲解118，递归函数改成迭代所需要的栈
        // 收集括号序递归版，java会爆栈，C++可以通过
        // dfs1的迭代版
                // dfs1(1, 0);
        // 读写工具类
*/

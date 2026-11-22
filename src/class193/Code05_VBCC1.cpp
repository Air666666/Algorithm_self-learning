// Source: src/class193/Code05_VBCC1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code05_VBCC1 {
  struct VbccCmp;
  struct VbccCmp {
    String toString() const { return j::str(static_cast<const void *>(this)); }
    VbccCmp() {}
    int compare(JList<int> o1, JList<int> o2) {
      int size = [&]() {
        auto jargument_0 = o1.size();
        auto jargument_1 = o2.size();
        return jmin(jargument_0, jargument_1);
      }();
      for (int i = 0; (i < size); (i++)) {
        if ((!(o1.get(i) == o2.get(i)))) {
          return jcompare(o1.get(i), o2.get(i));
        }
      }
      return [&]() {
        auto jleft = o1.size();
        auto jright = o2.size();
        return (jleft - jright);
      }();
    }
  };
  inline static int MAXN = 50001;
  inline static int MAXM = 300001;
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
  inline static JList<JList<int>> vbccArr = JList<JList<int>>();
  inline static Array<Array<int>> stack = make_array<int>(MAXN, 3);
  inline static int u = {};
  inline static int status = {};
  inline static int e = {};
  inline static int stacksize = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code05_VBCC1() {}
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
        Code05_VBCC1::tarjan1(v);
        (low[u] = jmin(low[u], low[v]));
        if ((low[v] == dfn[u])) {
          JList<int> list = JList<int>();
          list.add(u);
          int pop = {};
          do {
            (pop = sta[(top--)]);
            list.add(pop);
          } while ((pop != v));
          vbccArr.add(list);
        }
      } else {
        (low[u] = jmin(low[u], dfn[v]));
      }
    }
  }
  static void tarjan2(int node) {
    (stacksize = 0);
    Code05_VBCC1::push(node, (-1), (-1));
    int v = {};
    while ((stacksize > 0)) {
      Code05_VBCC1::pop();
      if ((status == (-1))) {
        (dfn[u] = (low[u] = (++cntd)));
        (sta[(++top)] = u);
        (e = head[u]);
      } else {
        (v = to[e]);
        if ((status == 0)) {
          (low[u] = jmin(low[u], low[v]));
          if ((low[v] == dfn[u])) {
            JList<int> list = JList<int>();
            list.add(u);
            int pop = {};
            do {
              (pop = sta[(top--)]);
              list.add(pop);
            } while ((pop != v));
            vbccArr.add(list);
          }
        } else {
          (low[u] = jmin(low[u], dfn[v]));
        }
        (e = nxt[e]);
      }
      if ((e != 0)) {
        (v = to[e]);
        if ((dfn[v] == 0)) {
          Code05_VBCC1::push(u, 0, e);
          Code05_VBCC1::push(v, (-1), (-1));
        } else {
          Code05_VBCC1::push(u, 1, e);
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
        Code05_VBCC1::addEdge(u, v);
        Code05_VBCC1::addEdge(v, u);
      }
    }
    for (int i = 1; (i <= n); (i++)) {
      if (((dfn[i] == 0) && (head[i] > 0))) {
        Code05_VBCC1::tarjan2(i);
      }
    }
    out.println(vbccArr.size());
    for (int i = 0; (i < vbccArr.size()); (i++)) {
      vbccArr.get(i).sort(
          [=](Box<int> a, Box<int> b) { return jcompare(a, b); });
    }
    vbccArr.sort(new VbccCmp());
    for (int i = 0; (i < vbccArr.size()); (i++)) {
      for (int node : vbccArr.get(i)) {
        out.print((node + String(u" ")));
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
  Code05_VBCC1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 点双连通分量模版题2，java版
// 给定一张无向图，一共n个点、m条边
// 忽略所有孤立点，打印点双连通分量的个数
// 打印每个点双连通分量内部的节点编号，编号按照从小到大组织
// 内部节点编号是一个序列，序列字典序小的点双连通分量先打印
// 1 <= n <= 5 * 10^4
// 1 <= m <= 3 * 10^5
// 测试链接 : https://www.luogu.com.cn/problem/B3610
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 迭代版需要的栈，讲解118讲了递归改迭代的技巧
        // 递归版，Tarjan算法求解点双连通分量
        // 迭代版，Tarjan算法求解点双连通分量
                                // tarjan1(i);
        // 读写工具类
*/

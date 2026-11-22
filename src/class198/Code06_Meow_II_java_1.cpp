// Source: src/class198/Code06_Meow_II_java_1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code06_Meow_II_java_1 {
  inline static int MAXV = 50001;
  inline static int MAXN = 200001;
  inline static int MAXT = 5000001;
  inline static int MAXE = 20000001;
  inline static int v = {};
  inline static int n = {};
  inline static int cntt = {};
  inline static Array<Array<int>> vi = make_array<int>(MAXN, 2);
  inline static Array<Array<int>> group = make_array<int>(MAXN, 3);
  inline static int cntp = {};
  inline static Array<int> head = make_array<int>(MAXT);
  inline static Array<int> nxt = make_array<int>(MAXE);
  inline static Array<int> to = make_array<int>(MAXE);
  inline static int cntg = {};
  inline static Array<int> dfn = make_array<int>(MAXT);
  inline static Array<int> low = make_array<int>(MAXT);
  inline static int cntd = {};
  inline static Array<int> sta = make_array<int>(MAXT);
  inline static int top = {};
  inline static Array<int> belong = make_array<int>(MAXT);
  inline static int sccCnt = {};
  inline static Array<int> inTree = make_array<int>(MAXN);
  inline static Array<int> outTree = make_array<int>(MAXN);
  inline static Array<int> ans = make_array<int>(MAXN);
  inline static Array<int> stau = make_array<int>(MAXT);
  inline static Array<int> stas = make_array<int>(MAXT);
  inline static Array<int> stae = make_array<int>(MAXT);
  inline static int u = {};
  inline static int status = {};
  inline static int e = {};
  inline static int stacksize = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code06_Meow_II_java_1() {}
  static void push(int u, int status, int e) {
    (stau[stacksize] = u);
    (stas[stacksize] = status);
    (stae[stacksize] = e);
    (stacksize++);
  }
  static void pop() {
    (stacksize--);
    (u = stau[stacksize]);
    (status = stas[stacksize]);
    (e = stae[stacksize]);
  }
  static void addGroup(int l, int r, int x) {
    (group[(++cntp)][0] = l);
    (group[cntp][1] = r);
    (group[cntp][2] = x);
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
        Code06_Meow_II_java_1::tarjan1(v);
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
    Code06_Meow_II_java_1::push(node, (-1), (-1));
    int v = {};
    while ((stacksize > 0)) {
      Code06_Meow_II_java_1::pop();
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
          Code06_Meow_II_java_1::push(u, 0, e);
          Code06_Meow_II_java_1::push(v, (-1), (-1));
        } else {
          Code06_Meow_II_java_1::push(u, 1, e);
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
  static int lowbit(int i) { return (i & (-i)); }
  static void addOut(int i, int x) {
    while ((i <= n)) {
      int preo = outTree[i];
      int curo = (++cntt);
      if ((preo > 0)) {
        Code06_Meow_II_java_1::addEdge(preo, curo);
      }
      Code06_Meow_II_java_1::addEdge(x, curo);
      (outTree[i] = curo);
      (i += Code06_Meow_II_java_1::lowbit(i));
    }
  }
  static void addIn(int i, int x) {
    while ((i <= n)) {
      int prei = inTree[i];
      int curi = (++cntt);
      if ((prei > 0)) {
        Code06_Meow_II_java_1::addEdge(curi, prei);
      }
      Code06_Meow_II_java_1::addEdge(curi, x);
      (inTree[i] = curi);
      (i += Code06_Meow_II_java_1::lowbit(i));
    }
  }
  static void rangeToX(int i, int x) {
    while ((i > 0)) {
      if ((outTree[i] > 0)) {
        Code06_Meow_II_java_1::addEdge(outTree[i], x);
      }
      (i -= Code06_Meow_II_java_1::lowbit(i));
    }
  }
  static void xToRange(int x, int i) {
    while ((i > 0)) {
      if ((inTree[i] > 0)) {
        Code06_Meow_II_java_1::addEdge(x, inTree[i]);
      }
      (i -= Code06_Meow_II_java_1::lowbit(i));
    }
  }
  static int other(int x) { return ((x <= v) ? (x + v) : (x - v)); }
  static void buildGraph() {
    j::sort(group, 1, (cntp + 1),
            [=](Array<int> a, Array<int> b) { return (a[1] - b[1]); });
    (cntt = jshl(v, 1));
    for (int i = 1; (i <= cntp); (i++)) {
      int l = group[i][0];
      int p = ((n - l) + 1);
      int x = group[i][2];
      Code06_Meow_II_java_1::xToRange(x, p);
      Code06_Meow_II_java_1::rangeToX(p, Code06_Meow_II_java_1::other(x));
      Code06_Meow_II_java_1::addIn(p, Code06_Meow_II_java_1::other(x));
      Code06_Meow_II_java_1::addOut(p, x);
    }
  }
  static bool compute() {
    j::sort(vi, 1, (n + 1), [=](Array<int> a, Array<int> b) {
      return ((a[0] != b[0]) ? (a[0] - b[0]) : (a[1] - b[1]));
    });
    for (int i = 1; (i <= n); (i += 4)) {
      int x = vi[i][0];
      int a = vi[i][1];
      int b = vi[(i + 1)][1];
      int c = vi[(i + 2)][1];
      int d = vi[(i + 3)][1];
      Code06_Meow_II_java_1::addGroup(a, c, x);
      Code06_Meow_II_java_1::addGroup(b, d, x);
      Code06_Meow_II_java_1::addGroup(a, b, (x + v));
      Code06_Meow_II_java_1::addGroup(c, d, (x + v));
    }
    Code06_Meow_II_java_1::buildGraph();
    for (int i = 1; (i <= jshl(v, 1)); (i++)) {
      if ((dfn[i] == 0)) {
        Code06_Meow_II_java_1::tarjan2(i);
      }
    }
    bool check = true;
    for (int i = 1; (i <= v); (i++)) {
      if ((belong[i] == belong[(i + v)])) {
        (check = false);
        break;
      }
    }
    if (check) {
      for (int i = 1; (i <= n); (i += 4)) {
        int x = vi[i][0];
        int a = vi[i][1];
        int b = vi[(i + 1)][1];
        int c = vi[(i + 2)][1];
        int d = vi[(i + 3)][1];
        if ((belong[x] < belong[(x + v)])) {
          (ans[a] = 0);
          (ans[b] = 0);
          (ans[c] = 1);
          (ans[d] = 1);
        } else {
          (ans[a] = 0);
          (ans[b] = 1);
          (ans[c] = 0);
          (ans[d] = 1);
        }
      }
    }
    return check;
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (v = in.nextInt());
    (n = jshl(v, 2));
    for (int i = 1; (i <= n); (i++)) {
      (vi[i][0] = in.nextInt());
      (vi[i][1] = i);
    }
    bool check = Code06_Meow_II_java_1::compute();
    if (check) {
      out.println(String(u"Yes"));
      for (int i = 1; (i <= n); (i++)) {
        out.print(ans[i]);
      }
    } else {
      out.println(String(u"No"));
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code06_Meow_II_java_1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 喵了个喵 II，树状数组优化建图，java版
// 给定一个长度为4n的数组arr，1~n每种数字都出现4次
// 从左到右把每个数字划分进序列0或序列1，要求划分出的两个序列完全相等
// 如果能做到，先打印"Yes"，然后从左到右打印每个位置划分进了什么序列
// 如果不能做到，打印"No"
// 1 <= n <= 5 * 10^4
// 测试链接 : https://www.luogu.com.cn/problem/P9139
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 值v、位置i
        // 左l、右r、决定编号x
        // 树状数组
        // 迭代版需要的栈，讲解118讲了递归改迭代的技巧
        // 递归版
        // 迭代版
                        // 后缀查询转化成前缀查询
                                // tarjan1(i);
        // 读写工具类
*/

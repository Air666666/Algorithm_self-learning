// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P6965

// Source: src/class197/Code03_BinaryCode1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_BinaryCode1 {
  inline static int MAXN = 500001;
  inline static int MAXP = 1000002;
  inline static int MAXT = 5000001;
  inline static int MAXE = 10000001;
  inline static int n = {};
  inline static int cntt = {};
  inline static Array<String> arr = make_array<String>(jshl(MAXN, 1));
  inline static Array<int> headg = make_array<int>(MAXT);
  inline static Array<int> nextg = make_array<int>(MAXE);
  inline static Array<int> tog = make_array<int>(MAXE);
  inline static int cntg = {};
  inline static Array<Array<int>> tree = make_array<int>(MAXP, 2);
  inline static Array<int> fa = make_array<int>(MAXP);
  inline static Array<int> up = make_array<int>(MAXP);
  inline static Array<int> down = make_array<int>(MAXP);
  inline static int cntp = {};
  inline static Array<int> headx = make_array<int>(MAXP);
  inline static Array<int> nextx = make_array<int>(MAXP);
  inline static Array<int> tox = make_array<int>(MAXP);
  inline static int cntx = {};
  inline static Array<int> group = make_array<int>(MAXN);
  inline static int gsiz = {};
  inline static Array<int> dfn = make_array<int>(MAXT);
  inline static Array<int> low = make_array<int>(MAXT);
  inline static int cntd = {};
  inline static Array<int> sta = make_array<int>(MAXT);
  inline static int top = {};
  inline static Array<int> belong = make_array<int>(MAXT);
  inline static int sccCnt = {};
  inline static Array<int> stau = make_array<int>(MAXT);
  inline static Array<int> stas = make_array<int>(MAXT);
  inline static Array<int> stae = make_array<int>(MAXT);
  inline static int u = {};
  inline static int status = {};
  inline static int e = {};
  inline static int stacksize = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_BinaryCode1() {}
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
  static void addEdge(int u, int v) {
    (nextg[(++cntg)] = headg[u]);
    (tog[cntg] = v);
    (headg[u] = cntg);
  }
  static void tarjan1(int u) {
    (dfn[u] = (low[u] = (++cntd)));
    (sta[(++top)] = u);
    for (int e = headg[u]; (e > 0); (e = nextg[e])) {
      int v = tog[e];
      if ((dfn[v] == 0)) {
        Code03_BinaryCode1::tarjan1(v);
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
    Code03_BinaryCode1::push(node, (-1), (-1));
    int v = {};
    while ((stacksize > 0)) {
      Code03_BinaryCode1::pop();
      if ((status == (-1))) {
        (dfn[u] = (low[u] = (++cntd)));
        (sta[(++top)] = u);
        (e = headg[u]);
      } else {
        (v = tog[e]);
        if ((status == 0)) {
          (low[u] = jmin(low[u], low[v]));
        }
        if (((status == 1) && (belong[v] == 0))) {
          (low[u] = jmin(low[u], dfn[v]));
        }
        (e = nextg[e]);
      }
      if ((e != 0)) {
        (v = tog[e]);
        if ((dfn[v] == 0)) {
          Code03_BinaryCode1::push(u, 0, e);
          Code03_BinaryCode1::push(v, (-1), (-1));
        } else {
          Code03_BinaryCode1::push(u, 1, e);
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
  static int other(int x) { return ((x <= n) ? (x + n) : (x - n)); }
  static void addGroup(int u, int x) {
    (nextx[(++cntx)] = headx[u]);
    (tox[cntx] = x);
    (headx[u] = cntx);
  }
  static void insert(int x) {
    String str = arr[x];
    int cur = 1;
    for (int si = 0; (si < str.length()); (si++)) {
      int path = ((str.charAt(si) == u'0') ? 0 : 1);
      if ((tree[cur][path] == 0)) {
        (tree[cur][path] = (++cntp));
        (fa[cntp] = cur);
        (up[cntp] = (++cntt));
        (down[cntp] = (++cntt));
        Code03_BinaryCode1::addEdge(up[cntp], up[cur]);
        Code03_BinaryCode1::addEdge(down[cur], down[cntp]);
      }
      (cur = tree[cur][path]);
    }
    Code03_BinaryCode1::addEdge(x, up[fa[cur]]);
    Code03_BinaryCode1::addEdge(up[cur], Code03_BinaryCode1::other(x));
    Code03_BinaryCode1::addEdge(x, down[cur]);
    Code03_BinaryCode1::addEdge(down[fa[cur]], Code03_BinaryCode1::other(x));
    Code03_BinaryCode1::addGroup(cur, x);
  }
  static void groupLink() {
    if ((gsiz > 1)) {
      (cntt++);
      Code03_BinaryCode1::addEdge(cntt, Code03_BinaryCode1::other(group[1]));
      for (int i = 2; (i <= gsiz); (i++)) {
        (cntt++);
        Code03_BinaryCode1::addEdge(cntt, Code03_BinaryCode1::other(group[i]));
        Code03_BinaryCode1::addEdge(group[i], (cntt - 1));
        Code03_BinaryCode1::addEdge(cntt, (cntt - 1));
      }
      (cntt++);
      Code03_BinaryCode1::addEdge(cntt, Code03_BinaryCode1::other(group[gsiz]));
      for (int i = (gsiz - 1); (i >= 1); (i--)) {
        (cntt++);
        Code03_BinaryCode1::addEdge(cntt, Code03_BinaryCode1::other(group[i]));
        Code03_BinaryCode1::addEdge(group[i], (cntt - 1));
        Code03_BinaryCode1::addEdge(cntt, (cntt - 1));
      }
    }
  }
  static void buildGraph() {
    (cntt = jshl(n, 1));
    (cntp = 1);
    (up[1] = (++cntt));
    (down[1] = (++cntt));
    for (int x = 1; (x <= jshl(n, 1)); (x++)) {
      Code03_BinaryCode1::insert(x);
    }
    for (int u = 1; (u <= cntp); (u++)) {
      (gsiz = 0);
      for (int e = headx[u]; (e > 0); (e = nextx[e])) {
        (group[(++gsiz)] = tox[e]);
      }
      Code03_BinaryCode1::groupLink();
    }
  }
  static void addString(int i, String s) {
    int mark = (-1);
    Array<jchar> str = s.toCharArray();
    for (int si = 0; (si < str.length); (si++)) {
      if ((str[si] == u'?')) {
        (mark = si);
        break;
      }
    }
    if ((mark == (-1))) {
      if ((str[0] == u'0')) {
        Code03_BinaryCode1::addEdge((i + n), i);
      } else {
        Code03_BinaryCode1::addEdge(i, (i + n));
      }
      (mark = 0);
    }
    (str[mark] = u'0');
    (arr[i] = j::str(str));
    (str[mark] = u'1');
    (arr[(i + n)] = j::str(str));
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    String s = {};
    for (int i = 1; (i <= n); (i++)) {
      (s = in.nextString());
      Code03_BinaryCode1::addString(i, s);
    }
    Code03_BinaryCode1::buildGraph();
    for (int i = 1; (i <= jshl(n, 1)); (i++)) {
      if ((dfn[i] == 0)) {
        Code03_BinaryCode1::tarjan2(i);
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
      out.println(String(u"YES"));
      for (int i = 1; (i <= n); (i++)) {
        if ((belong[i] < belong[(i + n)])) {
          out.println(arr[i]);
        } else {
          out.println(arr[(i + n)]);
        }
      }
    } else {
      out.println(String(u"NO"));
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code03_BinaryCode1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 编码，java版
// 一共有n个字符串，都由字符 '0'、'1'、'?' 组成
// 每个字符串最多含有一个'?'，如果不含有，说明该字符串已经确定了
// 如果字符串含有'?'，那么这个'?'必须变成'0'或'1'中的一个
// 请把所有字符串都确定下来，要求任意一个字符串不是其它字符串的前缀
// 存在方案打印"YES"，然后打印每个确定后的字符串，不存在方案打印"NO"
// 1 <= n、字符总数 <= 5 * 10^5
// 测试链接 : https://www.luogu.com.cn/problem/P6965
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 每个字符串，有两个决定，所以得到两个决定串
        // 2-SAT建图
        // 前缀树优化建图
        // 前缀树的节点x，拥有哪些决定串，用链式前向星实现
        // 相同的决定串构成一组，进行前后缀优化建图
        // 迭代版需要的栈，讲解118讲了递归改迭代的技巧
        // 递归版
        // 迭代版
                                // tarjan1(i);
        // 读写工具类
*/

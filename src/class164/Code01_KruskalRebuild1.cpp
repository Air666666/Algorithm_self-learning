// Source: src/class164/Code01_KruskalRebuild1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_KruskalRebuild1 {
  struct FastIO;
  struct FastIO {
    IO is = {};
    IO os = {};
    Array<signed char> inbuf = make_array<signed char>(jshl(1, 16));
    int lenbuf = 0;
    int ptrbuf = 0;
    StringBuilder outBuf = StringBuilder();
    String toString() const { return j::str(static_cast<const void *>(this)); }
    FastIO(IO is, IO os) {
      (this->is = is);
      (this->os = os);
    }
    int readByte() {
      if ((ptrbuf >= lenbuf)) {
        (ptrbuf = 0);
        try {
          (lenbuf = is.read(inbuf));
        } catch (Exception &e) {
          throw Exception(e);
        }
        if ((lenbuf == (-1))) {
          return (-1);
        }
      }
      return (inbuf[(ptrbuf++)] & 0xff);
    }
    int skip() {
      int b = {};
      while (((b = FastIO::readByte()) != (-1))) {
        if ((b > u' ')) {
          return b;
        }
      }
      return (-1);
    }
    int nextInt() {
      int b = FastIO::skip();
      if ((b == (-1))) {
        throw Exception(String(u"No more integers (EOF)"));
      }
      bool negative = false;
      if ((b == u'-')) {
        (negative = true);
        (b = FastIO::readByte());
      }
      int val = 0;
      while (((b >= u'0') && (b <= u'9'))) {
        (val = ((val * 10) + (b - u'0')));
        (b = FastIO::readByte());
      }
      return (negative ? (-val) : val);
    }
    void write(String s) { outBuf.append(s); }
    void writeInt(int x) { outBuf.append(x); }
    void writelnInt(int x) { outBuf.append(x).append(u'\n'); }
    void flush() {
      try {
        os.write(outBuf.toString().getBytes());
        os.flush();
        outBuf.setLength(0);
      } catch (Exception &e) {
        throw Exception(e);
      }
    }
  };
  inline static int MAXK = 200001;
  inline static int MAXM = 300001;
  inline static int MAXP = 20;
  inline static int n = {};
  inline static int m = {};
  inline static int q = {};
  inline static Array<Array<int>> edge = make_array<int>(MAXM, 3);
  inline static Array<int> father = make_array<int>(MAXK);
  inline static Array<int> head = make_array<int>(MAXK);
  inline static Array<int> next = make_array<int>(MAXK);
  inline static Array<int> to = make_array<int>(MAXK);
  inline static int cntg = 0;
  inline static Array<int> nodeKey = make_array<int>(MAXK);
  inline static int cntu = {};
  inline static Array<int> dep = make_array<int>(MAXK);
  inline static Array<Array<int>> stjump = make_array<int>(MAXK, MAXP);
  inline static Array<Array<int>> ufe = make_array<int>(MAXK, 3);
  inline static int stacksize = {};
  inline static int u = {};
  inline static int f = {};
  inline static int e = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_KruskalRebuild1() {}
  static int find(int i) {
    if ((i != father[i])) {
      (father[i] = Code01_KruskalRebuild1::find(father[i]));
    }
    return father[i];
  }
  static void addEdge(int u, int v) {
    (next[(++cntg)] = head[u]);
    (to[cntg] = v);
    (head[u] = cntg);
  }
  static void kruskalRebuild() {
    for (int i = 1; (i <= n); (i++)) {
      (father[i] = i);
    }
    j::sort(edge, 1, (m + 1),
            [=](Array<int> a, Array<int> b) { return (a[2] - b[2]); });
    (cntu = n);
    {
      int i = 1;
      int fx = {};
      int fy = {};
      for (; (i <= m); (i++)) {
        (fx = Code01_KruskalRebuild1::find(edge[i][0]));
        (fy = Code01_KruskalRebuild1::find(edge[i][1]));
        if ((fx != fy)) {
          (father[fx] = (father[fy] = (++cntu)));
          (father[cntu] = cntu);
          (nodeKey[cntu] = edge[i][2]);
          Code01_KruskalRebuild1::addEdge(cntu, fx);
          Code01_KruskalRebuild1::addEdge(cntu, fy);
        }
      }
    }
  }
  static void dfs1(int u, int fa) {
    (dep[u] = (dep[fa] + 1));
    (stjump[u][0] = fa);
    for (int p = 1; (p < MAXP); (p++)) {
      (stjump[u][p] = stjump[stjump[u][(p - 1)]][(p - 1)]);
    }
    for (int e = head[u]; (e > 0); (e = next[e])) {
      Code01_KruskalRebuild1::dfs1(to[e], u);
    }
  }
  static void push(int u, int f, int e) {
    (ufe[stacksize][0] = u);
    (ufe[stacksize][1] = f);
    (ufe[stacksize][2] = e);
    (stacksize++);
  }
  static void pop() {
    (--stacksize);
    (u = ufe[stacksize][0]);
    (f = ufe[stacksize][1]);
    (e = ufe[stacksize][2]);
  }
  static void dfs2(int cur, int fa) {
    (stacksize = 0);
    Code01_KruskalRebuild1::push(cur, fa, (-1));
    while ((stacksize > 0)) {
      Code01_KruskalRebuild1::pop();
      if ((e == (-1))) {
        (dep[u] = (dep[f] + 1));
        (stjump[u][0] = f);
        for (int p = 1; (p < MAXP); (p++)) {
          (stjump[u][p] = stjump[stjump[u][(p - 1)]][(p - 1)]);
        }
        (e = head[u]);
      } else {
        (e = next[e]);
      }
      if ((e != 0)) {
        Code01_KruskalRebuild1::push(u, f, e);
        Code01_KruskalRebuild1::push(to[e], u, (-1));
      }
    }
  }
  static int lca(int a, int b) {
    if ((dep[a] < dep[b])) {
      int tmp = a;
      (a = b);
      (b = tmp);
    }
    for (int p = (MAXP - 1); (p >= 0); (p--)) {
      if ((dep[stjump[a][p]] >= dep[b])) {
        (a = stjump[a][p]);
      }
    }
    if ((a == b)) {
      return a;
    }
    for (int p = (MAXP - 1); (p >= 0); (p--)) {
      if ((stjump[a][p] != stjump[b][p])) {
        (a = stjump[a][p]);
        (b = stjump[b][p]);
      }
    }
    return stjump[a][0];
  }
  static void java_main(Array<String> args) {
    FastIO *io = new FastIO(jin, jout);
    (n = io->nextInt());
    (m = io->nextInt());
    for (int i = 1; (i <= m); (i++)) {
      (edge[i][0] = io->nextInt());
      (edge[i][1] = io->nextInt());
      (edge[i][2] = io->nextInt());
    }
    Code01_KruskalRebuild1::kruskalRebuild();
    for (int i = 1; (i <= cntu); (i++)) {
      if ((i == father[i])) {
        Code01_KruskalRebuild1::dfs2(i, 0);
      }
    }
    (q = io->nextInt());
    {
      int i = 1;
      int x = {};
      int y = {};
      for (; (i <= q); (i++)) {
        (x = io->nextInt());
        (y = io->nextInt());
        if ([&]() {
              auto jleft = Code01_KruskalRebuild1::find(x);
              auto jright = Code01_KruskalRebuild1::find(y);
              return (jleft != jright);
            }()) {
          io->write(String(u"impossible\n"));
        } else {
          io->writelnInt(nodeKey[Code01_KruskalRebuild1::lca(x, y)]);
        }
      }
    }
    io->flush();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code01_KruskalRebuild1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// Kruskal重构树模版题，java版
// 图里有n个点，m条无向边，每条边给定边权，图里可能有若干个连通的部分
// 一共有q条查询，每条查询都是如下的格式
// 查询 x y : 点x和点y希望连通起来，其中的最大边权希望尽量小，打印这个值
//            如果怎样都无法联通，打印"impossible"
// 1 <= n <= 10^5
// 1 <= m <= 3 * 10^5
// 1 <= q <= 10^5
// 测试链接 : https://www.luogu.com.cn/problem/P2245
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 每条边有三个信息，节点u、节点v、边权w
        // 并查集
        // Kruskal重构树的建图
        // Kruskal重构树上，节点的权值
        // Kruskal重构树上，点的数量
        // Kruskal重构树上，dfs过程建立的信息
        // dfs1是递归函数，需要改成迭代版，不然会爆栈，C++实现不需要
        // dfs2是dfs1的迭代版
        // 读写工具类
*/

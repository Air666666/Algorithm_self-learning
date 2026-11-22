// Source: src/class164/Code02_Training1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_Training1 {
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
  inline static int MAXK = 800001;
  inline static int MAXM = 400001;
  inline static int MAXP = 20;
  inline static int n = {};
  inline static int m = {};
  inline static int q = {};
  inline static Array<Array<int>> edge = make_array<int>(MAXM, 4);
  inline static Array<int> edgeToTree = make_array<int>(MAXM);
  inline static Array<int> pendEdge = make_array<int>(MAXM);
  inline static Array<int> pendVal = make_array<int>(MAXM);
  inline static int cntp = 0;
  inline static Array<int> father = make_array<int>(MAXK);
  inline static Array<int> stack = make_array<int>(MAXK);
  inline static Array<int> head = make_array<int>(MAXK);
  inline static Array<int> next = make_array<int>(MAXK);
  inline static Array<int> to = make_array<int>(MAXK);
  inline static int cntg = 0;
  inline static Array<int> nodeKey = make_array<int>(MAXK);
  inline static int cntu = {};
  inline static Array<int> leafsiz = make_array<int>(MAXK);
  inline static Array<Array<int>> stjump = make_array<int>(MAXK, MAXP);
  inline static Array<Array<int>> ufe = make_array<int>(MAXK, 3);
  inline static int stacksize = {};
  inline static int u = {};
  inline static int f = {};
  inline static int e = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_Training1() {}
  static int find(int i) {
    int size = 0;
    while ((i != father[i])) {
      (stack[(size++)] = i);
      (i = father[i]);
    }
    while ((size > 0)) {
      (father[stack[(--size)]] = i);
    }
    return i;
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
            [=](Array<int> a, Array<int> b) { return (b[2] - a[2]); });
    (cntu = n);
    {
      int i = 1;
      int fx = {};
      int fy = {};
      for (; (i <= m); (i++)) {
        (fx = Code02_Training1::find(edge[i][0]));
        (fy = Code02_Training1::find(edge[i][1]));
        if ((fx != fy)) {
          (father[fx] = (father[fy] = (++cntu)));
          (father[cntu] = cntu);
          (nodeKey[cntu] = edge[i][2]);
          Code02_Training1::addEdge(cntu, fx);
          Code02_Training1::addEdge(cntu, fy);
          (edgeToTree[edge[i][3]] = cntu);
        }
      }
    }
  }
  static void dfs1(int u, int fa) {
    (stjump[u][0] = fa);
    for (int p = 1; (p < MAXP); (p++)) {
      (stjump[u][p] = stjump[stjump[u][(p - 1)]][(p - 1)]);
    }
    for (int e = head[u]; (e > 0); (e = next[e])) {
      Code02_Training1::dfs1(to[e], u);
    }
    if ((u <= n)) {
      (leafsiz[u] = 1);
    } else {
      (leafsiz[u] = 0);
    }
    for (int e = head[u]; (e > 0); (e = next[e])) {
      (leafsiz[u] += leafsiz[to[e]]);
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
    Code02_Training1::push(cur, fa, (-1));
    while ((stacksize > 0)) {
      Code02_Training1::pop();
      if ((e == (-1))) {
        (stjump[u][0] = f);
        for (int p = 1; (p < MAXP); (p++)) {
          (stjump[u][p] = stjump[stjump[u][(p - 1)]][(p - 1)]);
        }
        (e = head[u]);
      } else {
        (e = next[e]);
      }
      if ((e != 0)) {
        Code02_Training1::push(u, f, e);
        Code02_Training1::push(to[e], u, (-1));
      } else {
        if ((u <= n)) {
          (leafsiz[u] = 1);
        } else {
          (leafsiz[u] = 0);
        }
        for (int ei = head[u]; (ei > 0); (ei = next[ei])) {
          (leafsiz[u] += leafsiz[to[ei]]);
        }
      }
    }
  }
  static int query(int u, int limit) {
    for (int p = (MAXP - 1); (p >= 0); (p--)) {
      if (((stjump[u][p] > 0) && (nodeKey[stjump[u][p]] >= limit))) {
        (u = stjump[u][p]);
      }
    }
    return leafsiz[u];
  }
  static void java_main(Array<String> args) {
    FastIO *io = new FastIO(jin, jout);
    (n = io->nextInt());
    (m = io->nextInt());
    (q = io->nextInt());
    for (int i = 1; (i <= m); (i++)) {
      (edge[i][0] = io->nextInt());
      (edge[i][1] = io->nextInt());
      (edge[i][2] = io->nextInt());
      (edge[i][3] = i);
    }
    Code02_Training1::kruskalRebuild();
    for (int i = 1; (i <= cntu); (i++)) {
      if ((i == father[i])) {
        Code02_Training1::dfs2(i, 0);
      }
    }
    int op = {};
    int x = {};
    int y = {};
    int limit = 0;
    for (int i = 1; (i <= q); (i++)) {
      (op = io->nextInt());
      if ((op == 1)) {
        for (int k = 1; (k <= cntp); (k++)) {
          (nodeKey[edgeToTree[pendEdge[k]]] = pendVal[k]);
        }
        (cntp = 0);
        (limit = io->nextInt());
      } else if ((op == 2)) {
        (x = io->nextInt());
        io->writelnInt(Code02_Training1::query(x, limit));
      } else {
        (x = io->nextInt());
        (y = io->nextInt());
        if ((edgeToTree[x] != 0)) {
          (pendEdge[(++cntp)] = x);
          (pendVal[cntp] = y);
        }
      }
    }
    io->flush();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code02_Training1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// youyou的军训，java版
// 图里有n个点，m条无向边，每条边给定不同的边权，图里可能有若干个连通的部分
// 一开始limit = 0，接下来有q条操作，每种操作的格式如下
// 操作 1 x   : 所有修改操作生效，然后limit设置成x
// 操作 2 x   : 从点x出发，只能走 边权 >= limit 的边，查询最多到达几个点
// 操作 3 x y : 第x条边的边权修改为y，不是立刻生效，等到下次操作1发生时生效
// 题目保证边权不管如何修改，所有边权都不相等，并且每条边的边权排名不发生变化
// 1 <= n、m、q <= 4 * 10^5
// 测试链接 : https://www.luogu.com.cn/problem/P9638
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 每条边的信息，节点u、节点v、边权w、边的编号i
        // 边的编号对应重构树上的点的编号
        // 边权的修改操作先不生效，等到下次操作1发生时生效
        // 修改了哪些边
        // 修改成了什么边权
        // 修改操作的个数
        // 并查集
        // Kruskal重构树
        // 树上dfs，Kruskal重构树的节点，子树上面有几个叶节点
        // 树上dfs，Kruskal重构树的节点，倍增表
        // 并查集的find方法，需要改成迭代版不然会爆栈，C++实现不需要
        // dfs1是递归函数，需要改成迭代版，不然会爆栈，C++实现不需要
        // dfs2是dfs1的迭代版
                                // 收集的修改操作生效
                                // 收集修改操作
        // 读写工具类
*/

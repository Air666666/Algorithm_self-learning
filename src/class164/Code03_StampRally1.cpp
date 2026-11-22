// Source: src/class164/Code03_StampRally1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_StampRally1 {
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
  inline static int MAXM = 100001;
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
  inline static Array<int> leafsiz = make_array<int>(MAXK);
  inline static Array<Array<int>> stjump = make_array<int>(MAXK, MAXP);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_StampRally1() {}
  static void addEdge(int u, int v) {
    (next[(++cntg)] = head[u]);
    (to[cntg] = v);
    (head[u] = cntg);
  }
  static int find(int i) {
    if ((i != father[i])) {
      (father[i] = Code03_StampRally1::find(father[i]));
    }
    return father[i];
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
        (fx = Code03_StampRally1::find(edge[i][0]));
        (fy = Code03_StampRally1::find(edge[i][1]));
        if ((fx != fy)) {
          (father[fx] = (father[fy] = (++cntu)));
          (father[cntu] = cntu);
          (nodeKey[cntu] = edge[i][2]);
          Code03_StampRally1::addEdge(cntu, fx);
          Code03_StampRally1::addEdge(cntu, fy);
        }
      }
    }
  }
  static void dfs(int u, int fa) {
    (stjump[u][0] = fa);
    for (int p = 1; (p < MAXP); (p++)) {
      (stjump[u][p] = stjump[stjump[u][(p - 1)]][(p - 1)]);
    }
    for (int e = head[u]; (e > 0); (e = next[e])) {
      Code03_StampRally1::dfs(to[e], u);
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
  static bool check(int x, int y, int z, int limit) {
    for (int p = (MAXP - 1); (p >= 0); (p--)) {
      if (((stjump[x][p] > 0) && (nodeKey[stjump[x][p]] <= limit))) {
        (x = stjump[x][p]);
      }
    }
    for (int p = (MAXP - 1); (p >= 0); (p--)) {
      if (((stjump[y][p] > 0) && (nodeKey[stjump[y][p]] <= limit))) {
        (y = stjump[y][p]);
      }
    }
    if ((x == y)) {
      return (leafsiz[x] >= z);
    } else {
      return ((leafsiz[x] + leafsiz[y]) >= z);
    }
  }
  static int query(int x, int y, int z) {
    int l = 1;
    int r = m;
    int mid = {};
    int ans = 0;
    while ((l <= r)) {
      (mid = jdiv((l + r), 2));
      if (Code03_StampRally1::check(x, y, z, mid)) {
        (ans = mid);
        (r = (mid - 1));
      } else {
        (l = (mid + 1));
      }
    }
    return ans;
  }
  static void java_main(Array<String> args) {
    FastIO *io = new FastIO(jin, jout);
    (n = io->nextInt());
    (m = io->nextInt());
    for (int i = 1; (i <= m); (i++)) {
      (edge[i][0] = io->nextInt());
      (edge[i][1] = io->nextInt());
      (edge[i][2] = i);
    }
    Code03_StampRally1::kruskalRebuild();
    Code03_StampRally1::dfs(cntu, 0);
    (q = io->nextInt());
    {
      int i = 1;
      int x = {};
      int y = {};
      int z = {};
      for (; (i <= q); (i++)) {
        (x = io->nextInt());
        (y = io->nextInt());
        (z = io->nextInt());
        io->writelnInt(Code03_StampRally1::query(x, y, z));
      }
    }
    io->flush();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code03_StampRally1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 边的最大编号的最小值，java版
// 图里有n个点，m条无向边，边的编号1~m，没有边权，所有点都连通
// 一共有q条查询，查询的格式如下
// 查询 x y z : 从两个点x和y出发，希望经过的点数量等于z
//              每个点可以重复经过，但是重复经过只计算一次
//              经过边的最大编号，最小是多少
// 3 <= n、m、q <= 10^5
// 3 <= z <= n
// 测试链接 : https://www.luogu.com.cn/problem/AT_agc002_d
// 测试链接 : https://atcoder.jp/contests/agc002/tasks/agc002_d
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 并查集
        // Kruskal重构树
        // 树上dfs
        // 读写工具类
*/

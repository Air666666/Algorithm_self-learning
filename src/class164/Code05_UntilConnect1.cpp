// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/CF1706E
// https://codeforces.com/problemset/problem/1706/E

// Source: src/class164/Code05_UntilConnect1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code05_UntilConnect1 {
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
  inline static int MAXN = 100001;
  inline static int MAXK = 200001;
  inline static int MAXM = 200001;
  inline static int MAXP = 20;
  inline static int t = {};
  inline static int n = {};
  inline static int m = {};
  inline static int q = {};
  inline static Array<Array<int>> edge = make_array<int>(MAXM, 3);
  inline static Array<int> father = make_array<int>(MAXK);
  inline static Array<int> head = make_array<int>(MAXK);
  inline static Array<int> next = make_array<int>(MAXK);
  inline static Array<int> to = make_array<int>(MAXK);
  inline static int cntg = {};
  inline static Array<int> nodeKey = make_array<int>(MAXK);
  inline static int cntu = {};
  inline static Array<int> dep = make_array<int>(MAXK);
  inline static Array<int> dfn = make_array<int>(MAXK);
  inline static Array<int> seg = make_array<int>(MAXK);
  inline static Array<Array<int>> stjump = make_array<int>(MAXK, MAXP);
  inline static int cntd = {};
  inline static Array<int> lg2 = make_array<int>(MAXN);
  inline static Array<Array<int>> stmax = make_array<int>(MAXN, MAXP);
  inline static Array<Array<int>> stmin = make_array<int>(MAXN, MAXP);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code05_UntilConnect1() {}
  static void clear() {
    (cntg = (cntd = 0));
    j::fill(head, 1, (n * 2), 0);
  }
  static int find(int i) {
    if ((i != father[i])) {
      (father[i] = Code05_UntilConnect1::find(father[i]));
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
        (fx = Code05_UntilConnect1::find(edge[i][0]));
        (fy = Code05_UntilConnect1::find(edge[i][1]));
        if ((fx != fy)) {
          (father[fx] = (father[fy] = (++cntu)));
          (father[cntu] = cntu);
          (nodeKey[cntu] = edge[i][2]);
          Code05_UntilConnect1::addEdge(cntu, fx);
          Code05_UntilConnect1::addEdge(cntu, fy);
        }
      }
    }
  }
  static void dfs(int u, int fa) {
    (dep[u] = (dep[fa] + 1));
    (dfn[u] = (++cntd));
    (seg[cntd] = u);
    (stjump[u][0] = fa);
    for (int p = 1; (p < MAXP); (p++)) {
      (stjump[u][p] = stjump[stjump[u][(p - 1)]][(p - 1)]);
    }
    for (int e = head[u]; (e > 0); (e = next[e])) {
      Code05_UntilConnect1::dfs(to[e], u);
    }
  }
  static void buildst() {
    (lg2[0] = (-1));
    for (int i = 1; (i <= n); (i++)) {
      (lg2[i] = (lg2[jshr(i, 1)] + 1));
      (stmax[i][0] = dfn[i]);
      (stmin[i][0] = dfn[i]);
    }
    for (int p = 1; (p <= lg2[n]); (p++)) {
      for (int i = 1; (((i + jshl(1, p)) - 1) <= n); (i++)) {
        (stmax[i][p] =
             jmax(stmax[i][(p - 1)], stmax[(i + jshl(1, (p - 1)))][(p - 1)]));
        (stmin[i][p] =
             jmin(stmin[i][(p - 1)], stmin[(i + jshl(1, (p - 1)))][(p - 1)]));
      }
    }
  }
  static int dfnmin(int l, int r) {
    int p = lg2[((r - l) + 1)];
    int ans = jmin(stmin[l][p], stmin[((r - jshl(1, p)) + 1)][p]);
    return ans;
  }
  static int dfnmax(int l, int r) {
    int p = lg2[((r - l) + 1)];
    int ans = jmax(stmax[l][p], stmax[((r - jshl(1, p)) + 1)][p]);
    return ans;
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
  static int query(int l, int r) {
    int x = seg[Code05_UntilConnect1::dfnmin(l, r)];
    int y = seg[Code05_UntilConnect1::dfnmax(l, r)];
    return nodeKey[Code05_UntilConnect1::lca(x, y)];
  }
  static void java_main(Array<String> args) {
    FastIO *io = new FastIO(jin, jout);
    (t = io->nextInt());
    for (int test = 1; (test <= t); (test++)) {
      (n = io->nextInt());
      (m = io->nextInt());
      (q = io->nextInt());
      for (int i = 1; (i <= m); (i++)) {
        (edge[i][0] = io->nextInt());
        (edge[i][1] = io->nextInt());
        (edge[i][2] = i);
      }
      Code05_UntilConnect1::clear();
      Code05_UntilConnect1::kruskalRebuild();
      Code05_UntilConnect1::dfs(cntu, 0);
      Code05_UntilConnect1::buildst();
      {
        int i = 1;
        int l = {};
        int r = {};
        for (; (i <= q); (i++)) {
          (l = io->nextInt());
          (r = io->nextInt());
          if ((l == r)) {
            io->write(String(u"0 "));
          } else {
            io->write((Code05_UntilConnect1::query(l, r) + String(u" ")));
          }
        }
      }
      io->write(String(u"\n"));
    }
    io->flush();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code05_UntilConnect1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 加边直到连通，java版
// 图里有n个点，m条无向边，点的编号1~n，边的编号1~m，所有点都连通
// 一共有q条查询，每条查询格式如下
// 查询 l r : 至少要加完编号前多少的边，才能使得[l, r]中的所有点连通
// 1 <= n <= 10^5
// 1 <= m、q <= 2 * 10^5
// 测试链接 : https://www.luogu.com.cn/problem/CF1706E
// 测试链接 : https://codeforces.com/problemset/problem/1706/E
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 并查集
        // Kruskal重构树
        // 深度
        // dfn序
        // seg[i] = j，代表树上节点的dfn序号为i，对应原始节点的编号为j
        // 树上的倍增表
        // dfn序号的计数
        // 一维数组的倍增表，查询区间最大值、最小值
        // 构建数组上的st表，讲解117进行了详细的讲述
        // 根据st表，[l..r]范围上的最小值，讲解117进行了详细的讲述
        // 根据st表，[l..r]范围上的最大值，讲解117进行了详细的讲述
        // 读写工具类
*/

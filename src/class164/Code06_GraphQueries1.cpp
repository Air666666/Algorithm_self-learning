// Source: src/class164/Code06_GraphQueries1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code06_GraphQueries1 {
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
  inline static int MAXN = 200001;
  inline static int MAXK = 400001;
  inline static int MAXM = 300001;
  inline static int MAXQ = 500001;
  inline static int MAXP = 20;
  inline static int n = {};
  inline static int m = {};
  inline static int q = {};
  inline static Array<int> node = make_array<int>(MAXN);
  inline static Array<Array<int>> edge = make_array<int>(MAXM, 3);
  inline static Array<Array<int>> ques = make_array<int>(MAXQ, 2);
  inline static Array<int> father = make_array<int>(MAXK);
  inline static Array<int> head = make_array<int>(MAXK);
  inline static Array<int> next = make_array<int>(MAXK);
  inline static Array<int> to = make_array<int>(MAXK);
  inline static int cntg = 0;
  inline static Array<int> nodeKey = make_array<int>(MAXK);
  inline static int cntu = {};
  inline static Array<Array<int>> stjump = make_array<int>(MAXK, MAXP);
  inline static Array<int> leafsiz = make_array<int>(MAXK);
  inline static Array<int> leafDfnMin = make_array<int>(MAXK);
  inline static Array<int> leafseg = make_array<int>(MAXK);
  inline static int cntd = 0;
  inline static Array<int> maxValueDfn = make_array<int>(jshl(MAXN, 2));
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code06_GraphQueries1() {}
  static void prepare() {
    for (int i = 1; (i <= q); (i++)) {
      if ((ques[i][0] == 2)) {
        (edge[ques[i][1]][2] = (-1));
      }
    }
    int weight = 0;
    for (int i = 1; (i <= m); (i++)) {
      if ((edge[i][2] != (-1))) {
        (edge[i][2] = (++weight));
      }
    }
    for (int i = q; (i >= 1); (i--)) {
      if ((ques[i][0] == 2)) {
        (edge[ques[i][1]][2] = (++weight));
      }
    }
  }
  static int find(int i) {
    if ((i != father[i])) {
      (father[i] = Code06_GraphQueries1::find(father[i]));
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
        (fx = Code06_GraphQueries1::find(edge[i][0]));
        (fy = Code06_GraphQueries1::find(edge[i][1]));
        if ((fx != fy)) {
          (father[fx] = (father[fy] = (++cntu)));
          (father[cntu] = cntu);
          (nodeKey[cntu] = edge[i][2]);
          Code06_GraphQueries1::addEdge(cntu, fx);
          Code06_GraphQueries1::addEdge(cntu, fy);
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
      Code06_GraphQueries1::dfs(to[e], u);
    }
    if ((u <= n)) {
      (leafsiz[u] = 1);
      (leafDfnMin[u] = (++cntd));
      (leafseg[cntd] = u);
    } else {
      (leafsiz[u] = 0);
      (leafDfnMin[u] = (n + 1));
    }
    for (int e = head[u]; (e > 0); (e = next[e])) {
      (leafsiz[u] += leafsiz[to[e]]);
      (leafDfnMin[u] = jmin(leafDfnMin[u], leafDfnMin[to[e]]));
    }
  }
  static int getAncestor(int u, int limit) {
    for (int p = (MAXP - 1); (p >= 0); (p--)) {
      if (((stjump[u][p] > 0) && (nodeKey[stjump[u][p]] <= limit))) {
        (u = stjump[u][p]);
      }
    }
    return u;
  }
  static void up(int i) {
    int l = jshl(i, 1);
    int r = (jshl(i, 1) | 1);
    if ((node[leafseg[maxValueDfn[l]]] > node[leafseg[maxValueDfn[r]]])) {
      (maxValueDfn[i] = maxValueDfn[l]);
    } else {
      (maxValueDfn[i] = maxValueDfn[r]);
    }
  }
  static void build(int l, int r, int i) {
    if ((l == r)) {
      (maxValueDfn[i] = l);
    } else {
      int mid = jdiv((l + r), 2);
      Code06_GraphQueries1::build(l, mid, jshl(i, 1));
      Code06_GraphQueries1::build((mid + 1), r, (jshl(i, 1) | 1));
      Code06_GraphQueries1::up(i);
    }
  }
  static void update(int jobi, int jobv, int l, int r, int i) {
    if ((l == r)) {
      (node[leafseg[jobi]] = jobv);
    } else {
      int mid = jdiv((l + r), 2);
      if ((jobi <= mid)) {
        Code06_GraphQueries1::update(jobi, jobv, l, mid, jshl(i, 1));
      } else {
        Code06_GraphQueries1::update(jobi, jobv, (mid + 1), r,
                                     (jshl(i, 1) | 1));
      }
      Code06_GraphQueries1::up(i);
    }
  }
  static int query(int jobl, int jobr, int l, int r, int i) {
    if (((jobl <= l) && (r <= jobr))) {
      return maxValueDfn[i];
    } else {
      int mid = jdiv((l + r), 2);
      int ldfn = 0;
      int rdfn = 0;
      if ((jobl <= mid)) {
        (ldfn = Code06_GraphQueries1::query(jobl, jobr, l, mid, jshl(i, 1)));
      }
      if ((jobr > mid)) {
        (rdfn = Code06_GraphQueries1::query(jobl, jobr, (mid + 1), r,
                                            (jshl(i, 1) | 1)));
      }
      if ((node[leafseg[ldfn]] > node[leafseg[rdfn]])) {
        return ldfn;
      } else {
        return rdfn;
      }
    }
  }
  static int queryAndUpdate(int x, int limit) {
    int anc = Code06_GraphQueries1::getAncestor(x, limit);
    int dfn = Code06_GraphQueries1::query(
        leafDfnMin[anc], ((leafDfnMin[anc] + leafsiz[anc]) - 1), 1, n, 1);
    int ans = node[leafseg[dfn]];
    Code06_GraphQueries1::update(dfn, 0, 1, n, 1);
    return ans;
  }
  static void java_main(Array<String> args) {
    FastIO *io = new FastIO(jin, jout);
    (n = io->nextInt());
    (m = io->nextInt());
    (q = io->nextInt());
    for (int i = 1; (i <= n); (i++)) {
      (node[i] = io->nextInt());
    }
    for (int i = 1; (i <= m); (i++)) {
      (edge[i][0] = io->nextInt());
      (edge[i][1] = io->nextInt());
      (edge[i][2] = 0);
    }
    for (int i = 1; (i <= q); (i++)) {
      (ques[i][0] = io->nextInt());
      (ques[i][1] = io->nextInt());
    }
    Code06_GraphQueries1::prepare();
    Code06_GraphQueries1::kruskalRebuild();
    for (int i = 1; (i <= cntu); (i++)) {
      if ((i == father[i])) {
        Code06_GraphQueries1::dfs(i, 0);
      }
    }
    Code06_GraphQueries1::build(1, n, 1);
    int limit = m;
    for (int i = 1; (i <= q); (i++)) {
      if ((ques[i][0] == 1)) {
        io->writelnInt(Code06_GraphQueries1::queryAndUpdate(ques[i][1], limit));
      } else {
        (limit--);
      }
    }
    io->flush();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code06_GraphQueries1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 删边和查询，java版
// 图里有n个点，m条无向边，初始时点权都不同，图里可能有若干个连通的部分
// 一共有q条操作，每条操作是如下两种类型中的一种
// 操作 1 x : 点x所在的连通区域中，假设点y拥有最大的点权
//            打印y的点权，然后把y的点权修改为0
// 操作 2 x : 删掉第x条边
// 1 <= n <= 2 * 10^5    1 <= m <= 3 * 10^5    1 <= q <= 5 * 10^5
// 测试链接 : https://www.luogu.com.cn/problem/CF1416D
// 测试链接 : https://codeforces.com/problemset/problem/1416/D
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 节点值的数组，需要记录，线段树也要使用
        // 所有边的数组，逆序处理删除操作，设置每条边的权值
        // 记录所有操作
        // 并查集
        // Kruskal重构树
        // 倍增表
        // 子树上的叶节点个数
        // 子树上叶节点的dfn序号最小值
        // leafseg[i] = j，表示dfn序号为i的叶节点，原始编号为j
        // dfn的计数
        // 线段树的下标是dfn序号，维护范围内，拥有最大点权的dfn序号
        // dfn序号为jobi，点权更新成jobv
        // dfn范围[jobl..jobr]，哪个节点拥有最大点权，返回该节点的dfn序号
        // 读写工具类
*/

// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P7834

// Source: src/class164/Code07_Peaks1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code07_Peaks1 {
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
  inline static int MAXM = 500001;
  inline static int MAXT = (MAXN * 40);
  inline static int MAXP = 20;
  inline static int n = {};
  inline static int m = {};
  inline static int q = {};
  inline static int s = {};
  inline static Array<int> node = make_array<int>(MAXN);
  inline static Array<int> sorted = make_array<int>(MAXN);
  inline static Array<Array<int>> edge = make_array<int>(MAXM, 3);
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
  inline static Array<int> root = make_array<int>(MAXN);
  inline static Array<int> ls = make_array<int>(MAXT);
  inline static Array<int> rs = make_array<int>(MAXT);
  inline static Array<int> numcnt = make_array<int>(MAXT);
  inline static int cntt = 0;
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code07_Peaks1() {}
  static int kth(int num) {
    int left = 1;
    int right = s;
    int mid = {};
    while ((left <= right)) {
      (mid = jdiv((left + right), 2));
      if ((sorted[mid] == num)) {
        return mid;
      } else if ((sorted[mid] < num)) {
        (left = (mid + 1));
      } else {
        (right = (mid - 1));
      }
    }
    return (-1);
  }
  static void prepare() {
    for (int i = 1; (i <= n); (i++)) {
      (sorted[i] = node[i]);
    }
    j::sort(sorted, 1, (n + 1));
    (s = 1);
    for (int i = 2; (i <= n); (i++)) {
      if ((sorted[s] != sorted[i])) {
        (sorted[(++s)] = sorted[i]);
      }
    }
    for (int i = 1; (i <= n); (i++)) {
      (node[i] = Code07_Peaks1::kth(node[i]));
    }
  }
  static void addEdge(int u, int v) {
    (next[(++cntg)] = head[u]);
    (to[cntg] = v);
    (head[u] = cntg);
  }
  static int find(int i) {
    if ((i != father[i])) {
      (father[i] = Code07_Peaks1::find(father[i]));
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
        (fx = Code07_Peaks1::find(edge[i][0]));
        (fy = Code07_Peaks1::find(edge[i][1]));
        if ((fx != fy)) {
          (father[fx] = (father[fy] = (++cntu)));
          (father[cntu] = cntu);
          (nodeKey[cntu] = edge[i][2]);
          Code07_Peaks1::addEdge(cntu, fx);
          Code07_Peaks1::addEdge(cntu, fy);
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
      Code07_Peaks1::dfs(to[e], u);
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
  static int build(int l, int r) {
    int rt = (++cntt);
    (numcnt[rt] = 0);
    if ((l < r)) {
      int mid = jdiv((l + r), 2);
      (ls[rt] = Code07_Peaks1::build(l, mid));
      (rs[rt] = Code07_Peaks1::build((mid + 1), r));
    }
    return rt;
  }
  static int insert(int jobi, int l, int r, int i) {
    int rt = (++cntt);
    (ls[rt] = ls[i]);
    (rs[rt] = rs[i]);
    (numcnt[rt] = (numcnt[i] + 1));
    if ((l < r)) {
      int mid = jdiv((l + r), 2);
      if ((jobi <= mid)) {
        (ls[rt] = Code07_Peaks1::insert(jobi, l, mid, ls[rt]));
      } else {
        (rs[rt] = Code07_Peaks1::insert(jobi, (mid + 1), r, rs[rt]));
      }
    }
    return rt;
  }
  static int query(int jobk, int l, int r, int pre, int post) {
    if ((l == r)) {
      return l;
    }
    int rsize = (numcnt[rs[post]] - numcnt[rs[pre]]);
    int mid = jdiv((l + r), 2);
    if ((rsize >= jobk)) {
      return Code07_Peaks1::query(jobk, (mid + 1), r, rs[pre], rs[post]);
    } else {
      return Code07_Peaks1::query((jobk - rsize), l, mid, ls[pre], ls[post]);
    }
  }
  static int kthMax(int u, int x, int k) {
    for (int p = (MAXP - 1); (p >= 0); (p--)) {
      if (((stjump[u][p] > 0) && (nodeKey[stjump[u][p]] <= x))) {
        (u = stjump[u][p]);
      }
    }
    if ((leafsiz[u] < k)) {
      return 0;
    }
    int idx = Code07_Peaks1::query(k, 1, s, root[(leafDfnMin[u] - 1)],
                                   root[((leafDfnMin[u] + leafsiz[u]) - 1)]);
    return sorted[idx];
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
      (edge[i][2] = io->nextInt());
    }
    Code07_Peaks1::prepare();
    Code07_Peaks1::kruskalRebuild();
    for (int i = 1; (i <= cntu); (i++)) {
      if ((i == father[i])) {
        Code07_Peaks1::dfs(i, 0);
      }
    }
    (root[0] = Code07_Peaks1::build(1, s));
    for (int i = 1; (i <= n); (i++)) {
      (root[i] = Code07_Peaks1::insert(node[leafseg[i]], 1, s, root[(i - 1)]));
    }
    {
      int i = 1;
      int u = {};
      int x = {};
      int k = {};
      int lastAns = 0;
      for (; (i <= q); (i++)) {
        (u = io->nextInt());
        (x = io->nextInt());
        (k = io->nextInt());
        (u = (jrem((u ^ lastAns), n) + 1));
        (x = (x ^ lastAns));
        (k = (jrem((k ^ lastAns), n) + 1));
        (lastAns = Code07_Peaks1::kthMax(u, x, k));
        if ((lastAns == 0)) {
          io->writelnInt((-1));
        } else {
          io->writelnInt(lastAns);
        }
      }
    }
    io->flush();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code07_Peaks1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 边权上限内第k大点权，java版
// 图里有n个点，m条无向边，点有点权，边有边权，图里可能有若干个连通的部分
// 一共有q条查询，查询格式如下
// 查询 u x k : 从点u开始，只能走过权值<=x的边
//              所有能到达的点中，打印第k大点权，如果不存在打印-1
// 1 <= n <= 10^5
// 0 <= m、q <= 5 * 10^5
// 1 <= 点权、边权 <= 10^9
// 本题要求强制在线，具体规定请打开测试链接查看
// 测试链接 : https://www.luogu.com.cn/problem/P7834
// 提交以下的code，提交时请把类名改成"Main"
// java实现的逻辑一定是正确的，但是通过不了
// 因为这道题根据C++的运行空间，制定通过标准，根本没考虑java的用户
// 想通过用C++实现，本节课Code07_Peaks2文件就是C++的实现
// 两个版本的逻辑完全一样，C++版本可以通过所有测试
        // 并查集
        // Kruskal重构树
        // 倍增表
        // 子树上的叶节点个数
        // 子树上叶节点的dfn序号最小值
        // leafseg[i] = j，表示dfn序号为i的叶节点，原始编号为j
        // dfn的计数
        // 可持久化线段树
        // 线段树的下标为某个数字，所以是值域线段树
        // 数值范围[l..r]上，一共有几个数字，就是numcnt的含义
        // 可持久化线段树的build
        // 数值范围[l..r]，加了一个数字jobi，生成新版本的可持久化线段树
        //
可持久化线段树，前版本pre，后版本post，两个版本做差，得到数值范围[l..r]的词频
        // 查询这个数值范围上，第jobk大的数字是什么
        // 读写工具类
*/

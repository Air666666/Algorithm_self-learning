// Source: src/class166/Code01_SegmentTreeDivideConquer1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_SegmentTreeDivideConquer1 {
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
  inline static int MAXN = 5001;
  inline static int MAXM = 500001;
  inline static int MAXT = 5000001;
  inline static int n = {};
  inline static int m = {};
  inline static Array<int> op = make_array<int>(MAXM);
  inline static Array<int> u = make_array<int>(MAXM);
  inline static Array<int> v = make_array<int>(MAXM);
  inline static Array<Array<int>> last = make_array<int>(MAXN, MAXN);
  inline static Array<int> father = make_array<int>(MAXN);
  inline static Array<int> siz = make_array<int>(MAXN);
  inline static Array<Array<int>> rollback = make_array<int>(MAXN, 2);
  inline static int opsize = 0;
  inline static Array<int> head = make_array<int>(jshl(MAXM, 2));
  inline static Array<int> next = make_array<int>(MAXT);
  inline static Array<int> tox = make_array<int>(MAXT);
  inline static Array<int> toy = make_array<int>(MAXT);
  inline static int cnt = 0;
  inline static Array<bool> ans = make_array<bool>(MAXM);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_SegmentTreeDivideConquer1() {}
  static void addEdge(int i, int x, int y) {
    (next[(++cnt)] = head[i]);
    (tox[cnt] = x);
    (toy[cnt] = y);
    (head[i] = cnt);
  }
  static int find(int i) {
    while ((i != father[i])) {
      (i = father[i]);
    }
    return i;
  }
  static void union_method(int x, int y) {
    int fx = Code01_SegmentTreeDivideConquer1::find(x);
    int fy = Code01_SegmentTreeDivideConquer1::find(y);
    if ((siz[fx] < siz[fy])) {
      int tmp = fx;
      (fx = fy);
      (fy = tmp);
    }
    (father[fy] = fx);
    (siz[fx] += siz[fy]);
    (rollback[(++opsize)][0] = fx);
    (rollback[opsize][1] = fy);
  }
  static void undo() {
    int fx = rollback[opsize][0];
    int fy = rollback[(opsize--)][1];
    (father[fy] = fy);
    (siz[fx] -= siz[fy]);
  }
  static void add(int jobl, int jobr, int jobx, int joby, int l, int r, int i) {
    if (((jobl <= l) && (r <= jobr))) {
      Code01_SegmentTreeDivideConquer1::addEdge(i, jobx, joby);
    } else {
      int mid = jshr((l + r), 1);
      if ((jobl <= mid)) {
        Code01_SegmentTreeDivideConquer1::add(jobl, jobr, jobx, joby, l, mid,
                                              jshl(i, 1));
      }
      if ((jobr > mid)) {
        Code01_SegmentTreeDivideConquer1::add(jobl, jobr, jobx, joby, (mid + 1),
                                              r, (jshl(i, 1) | 1));
      }
    }
  }
  static void dfs(int l, int r, int i) {
    int unionCnt = 0;
    {
      int ei = head[i];
      int x = {};
      int y = {};
      int fx = {};
      int fy = {};
      for (; (ei > 0); (ei = next[ei])) {
        (x = tox[ei]);
        (y = toy[ei]);
        (fx = Code01_SegmentTreeDivideConquer1::find(x));
        (fy = Code01_SegmentTreeDivideConquer1::find(y));
        if ((fx != fy)) {
          Code01_SegmentTreeDivideConquer1::union_method(fx, fy);
          (unionCnt++);
        }
      }
    }
    if ((l == r)) {
      if ((op[l] == 2)) {
        (ans[l] = [&]() {
          auto jleft = Code01_SegmentTreeDivideConquer1::find(u[l]);
          auto jright = Code01_SegmentTreeDivideConquer1::find(v[l]);
          return (jleft == jright);
        }());
      }
    } else {
      int mid = jdiv((l + r), 2);
      Code01_SegmentTreeDivideConquer1::dfs(l, mid, jshl(i, 1));
      Code01_SegmentTreeDivideConquer1::dfs((mid + 1), r, (jshl(i, 1) | 1));
    }
    for (int j = 1; (j <= unionCnt); (j++)) {
      Code01_SegmentTreeDivideConquer1::undo();
    }
  }
  static void prepare() {
    for (int i = 1; (i <= n); (i++)) {
      (father[i] = i);
      (siz[i] = 1);
    }
    {
      int i = 1;
      int t = {};
      int x = {};
      int y = {};
      for (; (i <= m); (i++)) {
        (t = op[i]);
        (x = u[i]);
        (y = v[i]);
        if ((t == 0)) {
          (last[x][y] = i);
        } else if ((t == 1)) {
          Code01_SegmentTreeDivideConquer1::add(last[x][y], (i - 1), x, y, 1, m,
                                                1);
          (last[x][y] = 0);
        }
      }
    }
    for (int x = 1; (x <= n); (x++)) {
      for (int y = (x + 1); (y <= n); (y++)) {
        if ((last[x][y] != 0)) {
          Code01_SegmentTreeDivideConquer1::add(last[x][y], m, x, y, 1, m, 1);
        }
      }
    }
  }
  static void java_main(Array<String> args) {
    FastIO *io = new FastIO(jin, jout);
    (n = io->nextInt());
    (m = io->nextInt());
    {
      int i = 1;
      int t = {};
      int x = {};
      int y = {};
      for (; (i <= m); (i++)) {
        (t = io->nextInt());
        (x = io->nextInt());
        (y = io->nextInt());
        (op[i] = t);
        (u[i] = jmin(x, y));
        (v[i] = jmax(x, y));
      }
    }
    Code01_SegmentTreeDivideConquer1::prepare();
    Code01_SegmentTreeDivideConquer1::dfs(1, m, 1);
    for (int i = 1; (i <= m); (i++)) {
      if ((op[i] == 2)) {
        if (ans[i]) {
          io->write(String(u"Y\n"));
        } else {
          io->write(String(u"N\n"));
        }
      }
    }
    io->flush();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code01_SegmentTreeDivideConquer1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 线段树分治模版题，java版
// 一共有n个节点，一共有m条操作，每条操作是如下三种类型中的一种
// 操作 0 x y : 点x和点y之间一定没有边，现在增加一条边
// 操作 1 x y : 点x和点y之间一定存在边，现在删除这条边
// 操作 2 x y : 查询点x和点y是否联通
// 1 <= n <= 5000
// 1 <= m <= 500000
// 不强制在线，可以离线处理
// 测试链接 : https://loj.ac/p/121
// 提交以下的code，提交时类名改成"Main"，多提交几次，可以通过所有测试用例
        // 点的数量最大值
        // 操作数量最大值
        // 任务数量最大值
        // 操作类型op、端点u、端点v
        // last[x][y] : 点x和点y的边，上次出现的时间点
        // 可撤销并查集
        // 线段树每个区间拥有哪些任务的列表，链式前向星表示
        // ans[i]为第i条操作的答案，只有查询操作才有答案
        // 读写工具类
*/

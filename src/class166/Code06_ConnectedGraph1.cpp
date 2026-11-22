// Source: src/class166/Code06_ConnectedGraph1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code06_ConnectedGraph1 {
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
  inline static int MAXM = 200001;
  inline static int MAXE = 400001;
  inline static int MAXT = 10000001;
  inline static int n = {};
  inline static int m = {};
  inline static int k = {};
  inline static Array<int> u = make_array<int>(MAXM);
  inline static Array<int> v = make_array<int>(MAXM);
  inline static Array<Array<int>> event = make_array<int>(MAXE, 2);
  inline static int ecnt = 0;
  inline static Array<bool> visit = make_array<bool>(MAXM);
  inline static Array<int> father = make_array<int>(MAXN);
  inline static Array<int> siz = make_array<int>(MAXN);
  inline static Array<Array<int>> rollback = make_array<int>(MAXN, 2);
  inline static int opsize = 0;
  inline static Array<int> head = make_array<int>(jshl(MAXN, 2));
  inline static Array<int> next = make_array<int>(MAXT);
  inline static Array<int> tox = make_array<int>(MAXT);
  inline static Array<int> toy = make_array<int>(MAXT);
  inline static int cnt = 0;
  inline static Array<bool> ans = make_array<bool>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code06_ConnectedGraph1() {}
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
    int fx = Code06_ConnectedGraph1::find(x);
    int fy = Code06_ConnectedGraph1::find(y);
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
      Code06_ConnectedGraph1::addEdge(i, jobx, joby);
    } else {
      int mid = jshr((l + r), 1);
      if ((jobl <= mid)) {
        Code06_ConnectedGraph1::add(jobl, jobr, jobx, joby, l, mid, jshl(i, 1));
      }
      if ((jobr > mid)) {
        Code06_ConnectedGraph1::add(jobl, jobr, jobx, joby, (mid + 1), r,
                                    (jshl(i, 1) | 1));
      }
    }
  }
  static void dfs(int l, int r, int i) {
    bool check = false;
    int unionCnt = 0;
    for (int ei = head[i]; (ei > 0); (ei = next[ei])) {
      int x = tox[ei];
      int y = toy[ei];
      int fx = Code06_ConnectedGraph1::find(x);
      int fy = Code06_ConnectedGraph1::find(y);
      if ((fx != fy)) {
        Code06_ConnectedGraph1::union_method(fx, fy);
        (unionCnt++);
      }
      if ((siz[Code06_ConnectedGraph1::find(fx)] == n)) {
        (check = true);
        break;
      }
    }
    if (check) {
      for (int j = l; (j <= r); (j++)) {
        (ans[j] = true);
      }
    } else {
      if ((l == r)) {
        (ans[l] = false);
      } else {
        int mid = jshr((l + r), 1);
        Code06_ConnectedGraph1::dfs(l, mid, jshl(i, 1));
        Code06_ConnectedGraph1::dfs((mid + 1), r, (jshl(i, 1) | 1));
      }
    }
    for (int j = 1; (j <= unionCnt); (j++)) {
      Code06_ConnectedGraph1::undo();
    }
  }
  static void prepare() {
    for (int i = 1; (i <= n); (i++)) {
      (father[i] = i);
      (siz[i] = 1);
    }
    j::sort(event, 1, (ecnt + 1), [=](Array<int> a, Array<int> b) {
      return ((a[0] != b[0]) ? (a[0] - b[0]) : (a[1] - b[1]));
    });
    int eid = {};
    int t = {};
    {
      int l = 1;
      int r = 1;
      for (; (l <= ecnt); (l = (++r))) {
        (eid = event[l][0]);
        (visit[eid] = true);
        while ((((r + 1) <= ecnt) && (event[(r + 1)][0] == eid))) {
          (r++);
        }
        (t = 1);
        for (int i = l; (i <= r); (i++)) {
          if ((t <= (event[i][1] - 1))) {
            Code06_ConnectedGraph1::add(t, (event[i][1] - 1), u[eid], v[eid], 1,
                                        k, 1);
          }
          (t = (event[i][1] + 1));
        }
        if ((t <= k)) {
          Code06_ConnectedGraph1::add(t, k, u[eid], v[eid], 1, k, 1);
        }
      }
    }
    for (int i = 1; (i <= m); (i++)) {
      if ((!visit[i])) {
        Code06_ConnectedGraph1::add(1, k, u[i], v[i], 1, k, 1);
      }
    }
  }
  static void java_main(Array<String> args) {
    FastIO *io = new FastIO(jin, jout);
    (n = io->nextInt());
    (m = io->nextInt());
    for (int i = 1; (i <= m); (i++)) {
      (u[i] = io->nextInt());
      (v[i] = io->nextInt());
    }
    (k = io->nextInt());
    {
      int i = 1;
      int c = {};
      for (; (i <= k); (i++)) {
        (c = io->nextInt());
        for (int j = 1; (j <= c); (j++)) {
          (event[(++ecnt)][0] = io->nextInt());
          (event[ecnt][1] = i);
        }
      }
    }
    Code06_ConnectedGraph1::prepare();
    Code06_ConnectedGraph1::dfs(1, k, 1);
    for (int i = 1; (i <= k); (i++)) {
      if (ans[i]) {
        io->write(String(u"Connected\n"));
      } else {
        io->write(String(u"Disconnected\n"));
      }
    }
    io->flush();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code06_ConnectedGraph1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 连通图，java版
// 一共有n个点，给定m条边，所有点一开始就连通在一起了
// 一共有k条操作，每条操作格式如下
// 操作 c ... : 操作涉及c条边，这些边的编号 ... 一共c个
//              假设删掉这些边，打印整张图是否联通
// 每条操作都是独立的，相互之间没有任何关系
// 1 <= n、k <= 10^5
// 1 <= m <= 2 * 10^5
// 1 <= c <= 4
// 测试链接 : https://www.luogu.com.cn/problem/P5227
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 读写工具类
*/

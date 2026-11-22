// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P5787

// Source: src/class166/Code02_CheckBipartiteGraph1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_CheckBipartiteGraph1 {
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
  inline static int MAXT = 3000001;
  inline static int n = {};
  inline static int m = {};
  inline static int k = {};
  inline static Array<int> father = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> siz = make_array<int>(jshl(MAXN, 1));
  inline static Array<Array<int>> rollback = make_array<int>(jshl(MAXN, 1), 2);
  inline static int opsize = 0;
  inline static Array<int> head = make_array<int>(jshl(MAXN, 2));
  inline static Array<int> next = make_array<int>(MAXT);
  inline static Array<int> tox = make_array<int>(MAXT);
  inline static Array<int> toy = make_array<int>(MAXT);
  inline static int cnt = 0;
  inline static Array<bool> ans = make_array<bool>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_CheckBipartiteGraph1() {}
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
    int fx = Code02_CheckBipartiteGraph1::find(x);
    int fy = Code02_CheckBipartiteGraph1::find(y);
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
      Code02_CheckBipartiteGraph1::addEdge(i, jobx, joby);
    } else {
      int mid = jdiv((l + r), 2);
      if ((jobl <= mid)) {
        Code02_CheckBipartiteGraph1::add(jobl, jobr, jobx, joby, l, mid,
                                         jshl(i, 1));
      }
      if ((jobr > mid)) {
        Code02_CheckBipartiteGraph1::add(jobl, jobr, jobx, joby, (mid + 1), r,
                                         (jshl(i, 1) | 1));
      }
    }
  }
  static void dfs(int l, int r, int i) {
    bool check = true;
    int unionCnt = 0;
    for (int ei = head[i]; (ei > 0); (ei = next[ei])) {
      int x = tox[ei];
      int y = toy[ei];
      int fx = Code02_CheckBipartiteGraph1::find(x);
      int fy = Code02_CheckBipartiteGraph1::find(y);
      if ((fx == fy)) {
        (check = false);
        break;
      } else {
        Code02_CheckBipartiteGraph1::union_method(x, (y + n));
        Code02_CheckBipartiteGraph1::union_method(y, (x + n));
        (unionCnt += 2);
      }
    }
    if (check) {
      if ((l == r)) {
        (ans[l] = true);
      } else {
        int mid = jdiv((l + r), 2);
        Code02_CheckBipartiteGraph1::dfs(l, mid, jshl(i, 1));
        Code02_CheckBipartiteGraph1::dfs((mid + 1), r, (jshl(i, 1) | 1));
      }
    } else {
      for (int k = l; (k <= r); (k++)) {
        (ans[k] = false);
      }
    }
    for (int k = 1; (k <= unionCnt); (k++)) {
      Code02_CheckBipartiteGraph1::undo();
    }
  }
  static void java_main(Array<String> args) {
    FastIO *io = new FastIO(jin, jout);
    (n = io->nextInt());
    (m = io->nextInt());
    (k = io->nextInt());
    for (int i = 1; (i <= (n * 2)); (i++)) {
      (father[i] = i);
      (siz[i] = 1);
    }
    {
      int i = 1;
      int x = {};
      int y = {};
      int l = {};
      int r = {};
      for (; (i <= m); (i++)) {
        (x = io->nextInt());
        (y = io->nextInt());
        (l = io->nextInt());
        (r = io->nextInt());
        Code02_CheckBipartiteGraph1::add((l + 1), r, x, y, 1, k, 1);
      }
    }
    Code02_CheckBipartiteGraph1::dfs(1, k, 1);
    for (int i = 1; (i <= k); (i++)) {
      if (ans[i]) {
        io->write(String(u"Yes\n"));
      } else {
        io->write(String(u"No\n"));
      }
    }
    io->flush();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code02_CheckBipartiteGraph1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 判断二分图，java版
// 一共有n个节点，时刻的范围0~k，一共有m条操作，每条操作含义如下
// 操作 x y l r : 点x到点y之间连一条边，该边在l时刻出现，在r时刻消失
// 分别打印1时刻以内、2时刻以内..k时刻以内，图是不是二分图
// 注意i时刻以内是0~i-1时间段的意思
// 1 <= n、k <= 10^5    1 <= m <= 2 * 10^5
// 1 <= x、y <= n       0 <= l、r <= k
// 测试链接 : https://www.luogu.com.cn/problem/P5787
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 读写工具类
*/

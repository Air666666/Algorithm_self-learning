// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/CF1681F
// https://codeforces.com/problemset/problem/1681/F

// Source: src/class166/Code04_UniqueOccurrences1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_UniqueOccurrences1 {
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
    void writelnLong(i64 x) { outBuf.append(x).append(u'\n'); }
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
  inline static int MAXN = 500001;
  inline static int MAXT = 10000001;
  inline static int n = {};
  inline static int v = {};
  inline static Array<int> father = make_array<int>(MAXN);
  inline static Array<int> siz = make_array<int>(MAXN);
  inline static Array<Array<int>> rollback = make_array<int>(MAXN, 2);
  inline static int opsize = 0;
  inline static Array<int> headc = make_array<int>(MAXN);
  inline static Array<int> nextc = make_array<int>(MAXN);
  inline static Array<int> xc = make_array<int>(MAXN);
  inline static Array<int> yc = make_array<int>(MAXN);
  inline static int cntc = 0;
  inline static Array<int> headt = make_array<int>(jshl(MAXN, 2));
  inline static Array<int> nextt = make_array<int>(MAXT);
  inline static Array<int> xt = make_array<int>(MAXT);
  inline static Array<int> yt = make_array<int>(MAXT);
  inline static int cntt = 0;
  inline static i64 ans = 0;
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_UniqueOccurrences1() {}
  static void addEdgeC(int i, int x, int y) {
    (nextc[(++cntc)] = headc[i]);
    (xc[cntc] = x);
    (yc[cntc] = y);
    (headc[i] = cntc);
  }
  static void addEdgeS(int i, int x, int y) {
    (nextt[(++cntt)] = headt[i]);
    (xt[cntt] = x);
    (yt[cntt] = y);
    (headt[i] = cntt);
  }
  static int find(int i) {
    while ((i != father[i])) {
      (i = father[i]);
    }
    return i;
  }
  static void union_method(int x, int y) {
    int fx = Code04_UniqueOccurrences1::find(x);
    int fy = Code04_UniqueOccurrences1::find(y);
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
      Code04_UniqueOccurrences1::addEdgeS(i, jobx, joby);
    } else {
      int mid = jshr((l + r), 1);
      if ((jobl <= mid)) {
        Code04_UniqueOccurrences1::add(jobl, jobr, jobx, joby, l, mid,
                                       jshl(i, 1));
      }
      if ((jobr > mid)) {
        Code04_UniqueOccurrences1::add(jobl, jobr, jobx, joby, (mid + 1), r,
                                       (jshl(i, 1) | 1));
      }
    }
  }
  static void dfs(int l, int r, int i) {
    int unionCnt = 0;
    for (int ei = headt[i]; (ei > 0); (ei = nextt[ei])) {
      Code04_UniqueOccurrences1::union_method(xt[ei], yt[ei]);
      (unionCnt++);
    }
    if ((l == r)) {
      {
        int ei = headc[l];
        int fx = {};
        int fy = {};
        for (; (ei > 0); (ei = nextc[ei])) {
          (fx = Code04_UniqueOccurrences1::find(xc[ei]));
          (fy = Code04_UniqueOccurrences1::find(yc[ei]));
          (ans += (static_cast<i64>(siz[fx]) * siz[fy]));
        }
      }
    } else {
      int mid = jshr((l + r), 1);
      Code04_UniqueOccurrences1::dfs(l, mid, jshl(i, 1));
      Code04_UniqueOccurrences1::dfs((mid + 1), r, (jshl(i, 1) | 1));
    }
    for (int k = 1; (k <= unionCnt); (k++)) {
      Code04_UniqueOccurrences1::undo();
    }
  }
  static void java_main(Array<String> args) {
    FastIO *io = new FastIO(jin, jout);
    (n = io->nextInt());
    (v = n);
    {
      int i = 1;
      int x = {};
      int y = {};
      int c = {};
      for (; (i < n); (i++)) {
        (x = io->nextInt());
        (y = io->nextInt());
        (c = io->nextInt());
        Code04_UniqueOccurrences1::addEdgeC(c, x, y);
        if ((c > 1)) {
          Code04_UniqueOccurrences1::add(1, (c - 1), x, y, 1, v, 1);
        }
        if ((c < v)) {
          Code04_UniqueOccurrences1::add((c + 1), v, x, y, 1, v, 1);
        }
      }
    }
    for (int i = 1; (i <= n); (i++)) {
      (father[i] = i);
      (siz[i] = 1);
    }
    Code04_UniqueOccurrences1::dfs(1, v, 1);
    io->writelnLong(ans);
    io->flush();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code04_UniqueOccurrences1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 独特事件，java版
// 一共有n个节点，n-1条无向边，边给定颜色值，所有节点连成一棵树
// 定义f(u, v) : 点u到点v的简单路径上恰好出现一次的颜色的数量
// 打印 ∑(u = 1..n) ∑(v = u + 1..n) f(u, v) 的结果
// 1 <= 颜色值 <= n <= 2 * 10^5
// 测试链接 : https://www.luogu.com.cn/problem/CF1681F
// 测试链接 : https://codeforces.com/problemset/problem/1681/F
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 每种颜色拥有哪些边的列表
        // 颜色轴线段树的区间任务列表
        // 读写工具类
*/

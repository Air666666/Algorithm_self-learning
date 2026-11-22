// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P5631

// Source: src/class166/Code03_MinimumMexTree1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_MinimumMexTree1 {
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
  inline static int MAXN = 1000001;
  inline static int MAXV = 100001;
  inline static int MAXT = 30000001;
  inline static int n = {};
  inline static int m = {};
  inline static int v = {};
  inline static Array<int> father = make_array<int>(MAXN);
  inline static Array<int> siz = make_array<int>(MAXN);
  inline static Array<Array<int>> rollback = make_array<int>(MAXN, 2);
  inline static int opsize = 0;
  inline static Array<int> head = make_array<int>(jshl(MAXV, 2));
  inline static Array<int> next = make_array<int>(MAXT);
  inline static Array<int> tox = make_array<int>(MAXT);
  inline static Array<int> toy = make_array<int>(MAXT);
  inline static int cnt = 0;
  inline static int part = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_MinimumMexTree1() {}
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
    int fx = Code03_MinimumMexTree1::find(x);
    int fy = Code03_MinimumMexTree1::find(y);
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
      Code03_MinimumMexTree1::addEdge(i, jobx, joby);
    } else {
      int mid = jshr((l + r), 1);
      if ((jobl <= mid)) {
        Code03_MinimumMexTree1::add(jobl, jobr, jobx, joby, l, mid, jshl(i, 1));
      }
      if ((jobr > mid)) {
        Code03_MinimumMexTree1::add(jobl, jobr, jobx, joby, (mid + 1), r,
                                    (jshl(i, 1) | 1));
      }
    }
  }
  static int dfs(int l, int r, int i) {
    int unionCnt = 0;
    {
      int ei = head[i];
      int fx = {};
      int fy = {};
      for (; (ei > 0); (ei = next[ei])) {
        (fx = Code03_MinimumMexTree1::find(tox[ei]));
        (fy = Code03_MinimumMexTree1::find(toy[ei]));
        if ((fx != fy)) {
          Code03_MinimumMexTree1::union_method(fx, fy);
          (part--);
          (unionCnt++);
        }
      }
    }
    int ans = (-1);
    if ((l == r)) {
      if ((part == 1)) {
        (ans = l);
      }
    } else {
      int mid = jshr((l + r), 1);
      (ans = Code03_MinimumMexTree1::dfs(l, mid, jshl(i, 1)));
      if ((ans == (-1))) {
        (ans = Code03_MinimumMexTree1::dfs((mid + 1), r, (jshl(i, 1) | 1)));
      }
    }
    for (int k = 1; (k <= unionCnt); (k++)) {
      Code03_MinimumMexTree1::undo();
      (part++);
    }
    return ans;
  }
  static void java_main(Array<String> args) {
    FastIO *io = new FastIO(jin, jout);
    (n = io->nextInt());
    (m = io->nextInt());
    (v = MAXV);
    for (int i = 1; (i <= n); (i++)) {
      (father[i] = i);
      (siz[i] = 1);
    }
    {
      int i = 1;
      int x = {};
      int y = {};
      int w = {};
      for (; (i <= m); (i++)) {
        (x = io->nextInt());
        (y = io->nextInt());
        (w = io->nextInt());
        if ((w > 0)) {
          Code03_MinimumMexTree1::add(0, (w - 1), x, y, 0, v, 1);
        }
        Code03_MinimumMexTree1::add((w + 1), v, x, y, 0, v, 1);
      }
    }
    (part = n);
    io->writelnInt(Code03_MinimumMexTree1::dfs(0, v, 1));
    io->flush();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code03_MinimumMexTree1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 最小mex生成树，java版
// 给定n个点，m条边的无向连通图，边有边权
// 自然数集合S的mex含义为：最小的、没有出现在S中的自然数
// 现在你要求出一个这个图的生成树，使得其边权集合的mex尽可能小
// 对本题来说，注意0是自然数
// 1 <= n <= 10^6
// 1 <= m <= 2 * 10^6
// 0 <= 边权 <= 10^5
// 测试链接 : https://www.luogu.com.cn/problem/P5631
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 读写工具类
*/

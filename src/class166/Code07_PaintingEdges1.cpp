// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/CF576E
// https://codeforces.com/problemset/problem/576/E

// Source: src/class166/Code07_PaintingEdges1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code07_PaintingEdges1 {
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
  inline static int MAXN = 500001;
  inline static int MAXK = 51;
  inline static int MAXT = 10000001;
  inline static int n = {};
  inline static int m = {};
  inline static int k = {};
  inline static int q = {};
  inline static Array<int> u = make_array<int>(MAXN);
  inline static Array<int> v = make_array<int>(MAXN);
  inline static Array<int> e = make_array<int>(MAXN);
  inline static Array<int> c = make_array<int>(MAXN);
  inline static Array<int> post = make_array<int>(MAXN);
  inline static Array<Array<int>> father = make_array<int>(MAXK, jshl(MAXN, 1));
  inline static Array<Array<int>> siz = make_array<int>(MAXK, jshl(MAXN, 1));
  inline static Array<Array<int>> rollback = make_array<int>(jshl(MAXN, 1), 3);
  inline static int opsize = 0;
  inline static Array<int> head = make_array<int>(jshl(MAXN, 2));
  inline static Array<int> next = make_array<int>(MAXT);
  inline static Array<int> qid = make_array<int>(MAXT);
  inline static int cnt = 0;
  inline static Array<int> lastColor = make_array<int>(MAXN);
  inline static Array<bool> ans = make_array<bool>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code07_PaintingEdges1() {}
  static void addEdge(int i, int qi) {
    (next[(++cnt)] = head[i]);
    (qid[cnt] = qi);
    (head[i] = cnt);
  }
  static int find(int color, int i) {
    while ((i != father[color][i])) {
      (i = father[color][i]);
    }
    return i;
  }
  static void union_method(int color, int x, int y) {
    int fx = Code07_PaintingEdges1::find(color, x);
    int fy = Code07_PaintingEdges1::find(color, y);
    if ((siz[color][fx] < siz[color][fy])) {
      int tmp = fx;
      (fx = fy);
      (fy = tmp);
    }
    (father[color][fy] = fx);
    (siz[color][fx] += siz[color][fy]);
    (rollback[(++opsize)][0] = color);
    (rollback[opsize][1] = fx);
    (rollback[opsize][2] = fy);
  }
  static void undo() {
    int color = rollback[opsize][0];
    int fx = rollback[opsize][1];
    int fy = rollback[(opsize--)][2];
    (father[color][fy] = fy);
    (siz[color][fx] -= siz[color][fy]);
  }
  static void add(int jobl, int jobr, int jobq, int l, int r, int i) {
    if (((jobl <= l) && (r <= jobr))) {
      Code07_PaintingEdges1::addEdge(i, jobq);
    } else {
      int mid = jshr((l + r), 1);
      if ((jobl <= mid)) {
        Code07_PaintingEdges1::add(jobl, jobr, jobq, l, mid, jshl(i, 1));
      }
      if ((jobr > mid)) {
        Code07_PaintingEdges1::add(jobl, jobr, jobq, (mid + 1), r,
                                   (jshl(i, 1) | 1));
      }
    }
  }
  static void dfs(int l, int r, int i) {
    int unionCnt = 0;
    int color = {};
    int x = {};
    int y = {};
    int xn = {};
    int yn = {};
    int fx = {};
    int fy = {};
    int fxn = {};
    int fyn = {};
    for (int ei = head[i]; (ei > 0); (ei = next[ei])) {
      (color = c[qid[ei]]);
      (x = u[e[qid[ei]]]);
      (y = v[e[qid[ei]]]);
      (xn = (x + n));
      (yn = (y + n));
      (fx = Code07_PaintingEdges1::find(color, x));
      (fy = Code07_PaintingEdges1::find(color, y));
      (fxn = Code07_PaintingEdges1::find(color, xn));
      (fyn = Code07_PaintingEdges1::find(color, yn));
      if ((fx != fyn)) {
        Code07_PaintingEdges1::union_method(color, fx, fyn);
        (unionCnt++);
      }
      if ((fy != fxn)) {
        Code07_PaintingEdges1::union_method(color, fy, fxn);
        (unionCnt++);
      }
    }
    if ((l == r)) {
      if ([&]() {
            auto jleft = Code07_PaintingEdges1::find(c[l], u[e[l]]);
            auto jright = Code07_PaintingEdges1::find(c[l], v[e[l]]);
            return (jleft == jright);
          }()) {
        (ans[l] = false);
        (c[l] = lastColor[e[l]]);
      } else {
        (ans[l] = true);
        (lastColor[e[l]] = c[l]);
      }
    } else {
      int mid = jshr((l + r), 1);
      Code07_PaintingEdges1::dfs(l, mid, jshl(i, 1));
      Code07_PaintingEdges1::dfs((mid + 1), r, (jshl(i, 1) | 1));
    }
    for (int j = 1; (j <= unionCnt); (j++)) {
      Code07_PaintingEdges1::undo();
    }
  }
  static void prepare() {
    for (int color = 1; (color <= k); (color++)) {
      for (int i = 1; (i <= n); (i++)) {
        (father[color][i] = i);
        (father[color][(i + n)] = (i + n));
        (siz[color][i] = 1);
        (siz[color][(i + n)] = 1);
      }
    }
    for (int i = 1; (i <= m); (i++)) {
      (post[i] = q);
    }
    for (int i = q; (i >= 1); (i--)) {
      if (((i + 1) <= post[e[i]])) {
        Code07_PaintingEdges1::add((i + 1), post[e[i]], i, 1, q, 1);
      }
      (post[e[i]] = i);
    }
  }
  static void java_main(Array<String> args) {
    FastIO *io = new FastIO(jin, jout);
    (n = io->nextInt());
    (m = io->nextInt());
    (k = io->nextInt());
    (q = io->nextInt());
    for (int i = 1; (i <= m); (i++)) {
      (u[i] = io->nextInt());
      (v[i] = io->nextInt());
    }
    for (int i = 1; (i <= q); (i++)) {
      (e[i] = io->nextInt());
      (c[i] = io->nextInt());
    }
    Code07_PaintingEdges1::prepare();
    Code07_PaintingEdges1::dfs(1, q, 1);
    for (int i = 1; (i <= q); (i++)) {
      if (ans[i]) {
        io->write(String(u"YES\n"));
      } else {
        io->write(String(u"NO\n"));
      }
    }
    io->flush();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code07_PaintingEdges1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 给边涂色，java版
// 一共有n个点，给定m条无向边，一开始每条边无颜色，一共有k种颜色
// 合法状态的定义为，仅保留染成k种颜色中的任何一种颜色的边，图都是一张二分图
// 一共有q条操作，每条操作格式如下
// 操作 e c : 第e条边，现在要涂成c颜色
//           如果执行此操作之后，整张图还是合法状态，那么执行并打印"YES"
//           如果执行此操作之后，整张图不再是合法状态，那么不执行并打印"NO"
// 1 <= n、m、q <= 5 * 10^5    1 <= k <= 50
// 测试链接 : https://www.luogu.com.cn/problem/CF576E
// 测试链接 : https://codeforces.com/problemset/problem/576/E
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 时间轴线段树的区间上的任务列表
        // 尤其注意qid的设置，课上进行了重点解释
        // lastColor[i] : 第i号边上次成功涂上的颜色
        // 读写工具类
*/

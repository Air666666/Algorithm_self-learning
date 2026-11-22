// Source: src/class164/Code04_Journey1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_Journey1 {
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
  inline static int MAXM = 400001;
  inline static int MAXP = 20;
  inline static int INF = 2000000001;
  inline static int t = {};
  inline static int n = {};
  inline static int m = {};
  inline static int q = {};
  inline static int k = {};
  inline static int s = {};
  inline static Array<Array<int>> edge = make_array<int>(MAXM, 4);
  inline static Array<int> headg = make_array<int>(MAXN);
  inline static Array<int> nextg = make_array<int>(jshl(MAXM, 1));
  inline static Array<int> tog = make_array<int>(jshl(MAXM, 1));
  inline static Array<int> weightg = make_array<int>(jshl(MAXM, 1));
  inline static int cntg = {};
  inline static Array<int> dist = make_array<int>(MAXN);
  inline static Array<bool> visit = make_array<bool>(MAXN);
  inline static JHeap<Array<int>> heap = JHeap<Array<int>>(
      [](Array<int> a, Array<int> b) { return (a[1] - b[1]); });
  inline static Array<int> father = make_array<int>(MAXK);
  inline static Array<int> stack = make_array<int>(MAXK);
  inline static Array<int> headk = make_array<int>(MAXK);
  inline static Array<int> nextk = make_array<int>(MAXK);
  inline static Array<int> tok = make_array<int>(MAXK);
  inline static int cntk = {};
  inline static Array<int> nodeKey = make_array<int>(MAXK);
  inline static int cntu = {};
  inline static Array<int> mindist = make_array<int>(MAXK);
  inline static Array<Array<int>> stjump = make_array<int>(MAXK, MAXP);
  inline static Array<Array<int>> ufe = make_array<int>(MAXK, 3);
  inline static int stacksize = {};
  inline static int u = {};
  inline static int f = {};
  inline static int e = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_Journey1() {}
  static void clear() {
    (cntg = (cntk = 0));
    j::fill(headg, 1, (n + 1), 0);
    j::fill(headk, 1, (n * 2), 0);
  }
  static void addEdgeG(int u, int v, int w) {
    (nextg[(++cntg)] = headg[u]);
    (tog[cntg] = v);
    (weightg[cntg] = w);
    (headg[u] = cntg);
  }
  static void dijkstra() {
    for (int i = 1; (i <= m); (i++)) {
      Code04_Journey1::addEdgeG(edge[i][0], edge[i][1], edge[i][2]);
      Code04_Journey1::addEdgeG(edge[i][1], edge[i][0], edge[i][2]);
    }
    j::fill(dist, 1, (n + 1), INF);
    j::fill(visit, 1, (n + 1), false);
    (dist[1] = 0);
    heap.add(Array<int>{1, 0});
    Array<int> cur = {};
    int x = {};
    int v = {};
    while ((!heap.isEmpty())) {
      (cur = heap.poll());
      (x = cur[0]);
      (v = cur[1]);
      if ((!visit[x])) {
        (visit[x] = true);
        {
          int e = headg[x];
          int y = {};
          int w = {};
          for (; (e > 0); (e = nextg[e])) {
            (y = tog[e]);
            (w = weightg[e]);
            if (((!visit[y]) && (dist[y] > (v + w)))) {
              (dist[y] = (v + w));
              heap.add(Array<int>{y, dist[y]});
            }
          }
        }
      }
    }
  }
  static void addEdgeK(int u, int v) {
    (nextk[(++cntk)] = headk[u]);
    (tok[cntk] = v);
    (headk[u] = cntk);
  }
  static int find(int i) {
    int size = 0;
    while ((i != father[i])) {
      (stack[(size++)] = i);
      (i = father[i]);
    }
    while ((size > 0)) {
      (father[stack[(--size)]] = i);
    }
    return i;
  }
  static void kruskalRebuild() {
    for (int i = 1; (i <= n); (i++)) {
      (father[i] = i);
    }
    j::sort(edge, 1, (m + 1),
            [=](Array<int> a, Array<int> b) { return (b[3] - a[3]); });
    (cntu = n);
    {
      int i = 1;
      int fx = {};
      int fy = {};
      for (; (i <= m); (i++)) {
        (fx = Code04_Journey1::find(edge[i][0]));
        (fy = Code04_Journey1::find(edge[i][1]));
        if ((fx != fy)) {
          (father[fx] = (father[fy] = (++cntu)));
          (father[cntu] = cntu);
          (nodeKey[cntu] = edge[i][3]);
          Code04_Journey1::addEdgeK(cntu, fx);
          Code04_Journey1::addEdgeK(cntu, fy);
        }
      }
    }
  }
  static void dfs1(int u, int fa) {
    (stjump[u][0] = fa);
    for (int p = 1; (p < MAXP); (p++)) {
      (stjump[u][p] = stjump[stjump[u][(p - 1)]][(p - 1)]);
    }
    for (int e = headk[u]; (e > 0); (e = nextk[e])) {
      Code04_Journey1::dfs1(tok[e], u);
    }
    if ((u <= n)) {
      (mindist[u] = dist[u]);
    } else {
      (mindist[u] = INF);
    }
    for (int e = headk[u]; (e > 0); (e = nextk[e])) {
      (mindist[u] = jmin(mindist[u], mindist[tok[e]]));
    }
  }
  static void push(int u, int f, int e) {
    (ufe[stacksize][0] = u);
    (ufe[stacksize][1] = f);
    (ufe[stacksize][2] = e);
    (stacksize++);
  }
  static void pop() {
    (--stacksize);
    (u = ufe[stacksize][0]);
    (f = ufe[stacksize][1]);
    (e = ufe[stacksize][2]);
  }
  static void dfs2(int cur, int fa) {
    (stacksize = 0);
    Code04_Journey1::push(cur, fa, (-1));
    while ((stacksize > 0)) {
      Code04_Journey1::pop();
      if ((e == (-1))) {
        (stjump[u][0] = f);
        for (int p = 1; (p < MAXP); (p++)) {
          (stjump[u][p] = stjump[stjump[u][(p - 1)]][(p - 1)]);
        }
        (e = headk[u]);
      } else {
        (e = nextk[e]);
      }
      if ((e != 0)) {
        Code04_Journey1::push(u, f, e);
        Code04_Journey1::push(tok[e], u, (-1));
      } else {
        if ((u <= n)) {
          (mindist[u] = dist[u]);
        } else {
          (mindist[u] = INF);
        }
        for (int ei = headk[u]; (ei > 0); (ei = nextk[ei])) {
          (mindist[u] = jmin(mindist[u], mindist[tok[ei]]));
        }
      }
    }
  }
  static int query(int node, int line) {
    for (int p = (MAXP - 1); (p >= 0); (p--)) {
      if (((stjump[node][p] > 0) && (nodeKey[stjump[node][p]] > line))) {
        (node = stjump[node][p]);
      }
    }
    return mindist[node];
  }
  static void java_main(Array<String> args) {
    FastIO *io = new FastIO(jin, jout);
    (t = io->nextInt());
    for (int test = 1; (test <= t); (test++)) {
      (n = io->nextInt());
      (m = io->nextInt());
      Code04_Journey1::clear();
      for (int i = 1; (i <= m); (i++)) {
        (edge[i][0] = io->nextInt());
        (edge[i][1] = io->nextInt());
        (edge[i][2] = io->nextInt());
        (edge[i][3] = io->nextInt());
      }
      Code04_Journey1::dijkstra();
      Code04_Journey1::kruskalRebuild();
      Code04_Journey1::dfs2(cntu, 0);
      (q = io->nextInt());
      (k = io->nextInt());
      (s = io->nextInt());
      {
        int i = 1;
        int x = {};
        int y = {};
        int lastAns = 0;
        for (; (i <= q); (i++)) {
          (x = (jrem(((io->nextInt() + (k * lastAns)) - 1), n) + 1));
          (y = jrem((io->nextInt() + (k * lastAns)), (s + 1)));
          (lastAns = Code04_Journey1::query(x, y));
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
  Code04_Journey1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 归程，java版
// 一共有n个点，m条无向边，原图连通，每条边有长度l和海拔a
// 一共有q条查询，格式如下
// 查询 x y : 起初走过海拔 > y的边免费，可视为开车，但是车不能走海拔 <= y的边
//            你可以在任意节点下车，车不能再用
//            下车后经过每条边的长度(包括海拔 > y 的边)，都算入步行长度
//            你想从点x到1号点，打印最小步行长度
// 1 <= n <= 2 * 10^5
// 1 <= m、q <= 4 * 10^5
// 本题要求强制在线，具体规定请打开测试链接查看
// 测试链接 : https://www.luogu.com.cn/problem/P4768
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 建图
        // dijkstra算法
        // 并查集
        // Kruskal重构树
        // 树上dfs，Kruskal重构树的节点，子树中的所有点，走到1号节点的最小距离
        // 树上dfs，Kruskal重构树的节点，倍增表
        // 并查集的find方法，需要改成迭代版不然会爆栈，C++实现不需要
        // dfs1是递归函数，需要改成迭代版不然会爆栈，C++实现不需要
        // dfs2是dfs1的迭代版
        // 读写工具类
*/

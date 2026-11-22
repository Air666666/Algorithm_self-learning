// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P3443

// Source: src/class188/Code10_Postman1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code10_Postman1 {
  struct PairMap;
  struct PairMap {
    JMap<i64, int> map = JMap<i64, int>();
    String toString() const { return j::str(static_cast<const void *>(this)); }
    PairMap() {}
    i64 key(int a, int b) {
      return (jshl(static_cast<i64>(a), 32) | (b & 0xffffffffLL));
    }
    bool contains(int a, int b) { return map.containsKey(PairMap::key(a, b)); }
    bool isEmpty() { return map.isEmpty(); }
    void put(int a, int b, int v) { map.put(PairMap::key(a, b), v); }
    int get(int a, int b) { return map.get(PairMap::key(a, b)); }
    void remove(int a, int b) { map.remove(PairMap::key(a, b)); }
    void clear() { map.clear(); }
  };
  inline static int MAXN = 50005;
  inline static int MAXM = 200005;
  inline static int MAXC = 2000005;
  inline static int n = {};
  inline static int m = {};
  inline static int t = {};
  inline static Array<int> a = make_array<int>(MAXM);
  inline static Array<int> b = make_array<int>(MAXM);
  inline static Array<int> seq = make_array<int>(MAXC);
  inline static PairMap *pairEdge = new PairMap();
  inline static Array<int> headg = make_array<int>(MAXN);
  inline static Array<int> nextg = make_array<int>(MAXM);
  inline static Array<int> tog = make_array<int>(MAXM);
  inline static Array<int> chainHead = make_array<int>(MAXM);
  inline static int cntg = {};
  inline static int edgeCnt = {};
  inline static Array<int> cur = make_array<int>(MAXN);
  inline static Array<int> inDeg = make_array<int>(MAXN);
  inline static Array<int> outDeg = make_array<int>(MAXN);
  inline static Array<bool> isHead = make_array<bool>(MAXM);
  inline static Array<int> etoe = make_array<int>(MAXM);
  inline static Array<bool> vis = make_array<bool>(MAXM);
  inline static Array<int> path = make_array<int>(MAXM);
  inline static int cntp = {};
  inline static Array<int> ans = make_array<int>(MAXM);
  inline static int cnta = {};
  inline static Array<Array<int>> sta = make_array<int>(MAXM, 2);
  inline static int u = {};
  inline static int h = {};
  inline static int stacksize = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code10_Postman1() {}
  static void push(int u, int c) {
    (sta[stacksize][0] = u);
    (sta[stacksize][1] = c);
    (stacksize++);
  }
  static void pop() {
    (stacksize--);
    (u = sta[stacksize][0]);
    (h = sta[stacksize][1]);
  }
  static void addEdge(int x, int y, int h) {
    (nextg[(++cntg)] = headg[x]);
    (tog[cntg] = y);
    (chainHead[cntg] = h);
    (headg[x] = cntg);
  }
  static bool linkEdge() {
    for (int i = 1; (i <= m); (i++)) {
      pairEdge->put(a[i], b[i], i);
      (isHead[i] = true);
    }
    int siz = seq[1];
    int l = 2;
    int r = ((l + siz) - 1);
    int a = {};
    int b = {};
    int ledge = {};
    int redge = {};
    while ((siz > 0)) {
      (ledge = 0);
      for (int i = l; (i < r); (i++)) {
        (a = seq[i]);
        (b = seq[(i + 1)]);
        if ((!pairEdge->contains(a, b))) {
          return false;
        }
        (redge = pairEdge->get(a, b));
        if ((ledge != 0)) {
          if (((etoe[ledge] != 0) && (etoe[ledge] != redge))) {
            return false;
          }
          (etoe[ledge] = redge);
          (isHead[redge] = false);
        }
        (ledge = redge);
      }
      (siz = seq[(r + 1)]);
      (l = (r + 2));
      (r = ((l + siz) - 1));
    }
    return true;
  }
  static int getLinkEnd(int edge) {
    while ((etoe[edge] != 0)) {
      if ((vis[edge] == true)) {
        return (-1);
      }
      (vis[edge] = true);
      (edge = etoe[edge]);
    }
    return edge;
  }
  static bool compress() {
    for (int i = 1; (i <= m); (i++)) {
      if (isHead[i]) {
        int x = a[i];
        int y = b[i];
        if ((etoe[i] != 0)) {
          int end = Code10_Postman1::getLinkEnd(i);
          if ((end == (-1))) {
            return false;
          }
          (y = b[end]);
        }
        (outDeg[x]++);
        (inDeg[y]++);
        (edgeCnt++);
        Code10_Postman1::addEdge(x, y, i);
      }
    }
    for (int i = 1; (i <= n); (i++)) {
      if ((inDeg[i] != outDeg[i])) {
        return false;
      }
    }
    for (int i = 1; (i <= n); (i++)) {
      (cur[i] = headg[i]);
    }
    return true;
  }
  static void euler1(int u, int h) {
    for (int e = cur[u]; (e > 0); (e = cur[u])) {
      (cur[u] = nextg[e]);
      Code10_Postman1::euler1(tog[e], chainHead[e]);
    }
    (path[(++cntp)] = h);
  }
  static void euler2(int node, int chainh) {
    (stacksize = 0);
    Code10_Postman1::push(node, chainh);
    while ((stacksize > 0)) {
      Code10_Postman1::pop();
      int e = cur[u];
      if ((e > 0)) {
        (cur[u] = nextg[e]);
        Code10_Postman1::push(u, h);
        Code10_Postman1::push(tog[e], chainHead[e]);
      } else {
        (path[(++cntp)] = h);
      }
    }
  }
  static void decompress() {
    (ans[(++cnta)] = 1);
    for (int i = (cntp - 1); (i >= 1); (i--)) {
      int e = path[i];
      while ((e > 0)) {
        (ans[(++cnta)] = b[e]);
        (e = etoe[e]);
      }
    }
  }
  static bool compute() {
    if ((!Code10_Postman1::linkEdge())) {
      return false;
    }
    if ((!Code10_Postman1::compress())) {
      return false;
    }
    Code10_Postman1::euler2(1, (-1));
    if ((cntp != (edgeCnt + 1))) {
      return false;
    }
    Code10_Postman1::decompress();
    return (cnta == (m + 1));
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (m = in.nextInt());
    for (int i = 1; (i <= m); (i++)) {
      (a[i] = in.nextInt());
      (b[i] = in.nextInt());
    }
    (t = in.nextInt());
    {
      int i = 1;
      int siz = {};
      int idx = 0;
      for (; (i <= t); (i++)) {
        (siz = in.nextInt());
        (seq[(++idx)] = siz);
        for (int j = 1; (j <= siz); (j++)) {
          (seq[(++idx)] = in.nextInt());
        }
      }
    }
    bool check = Code10_Postman1::compute();
    if ((!check)) {
      out.println(String(u"NIE"));
    } else {
      out.println(String(u"TAK"));
      for (int i = 1; (i <= cnta); (i++)) {
        out.println(ans[i]);
      }
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code10_Postman1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 邮递员，java版
// 一共n个点，m条有向边，不会有重边和自环
// 邮递员一定要从1号点开始，最后回到1号点，每条边都要走1次
// 邮递员依次走过的点的编号，就可以形成一个路径
// 给定t个序列，每个序列先给定长度k，然后是k个节点的编号
// 希望每个序列都是路径的连续子段，如果不存在这样的路径，打印"NIE"
// 如果存在这样的路径，先打印"TAK"，然后打印依次走过的节点编号
// 2 <= n <= 5 * 10^4    1 <= m <= 2 * 10^5
// 0 <= t <= 10^4        所有序列的节点总量 <= 2 * 10^6
// 测试链接 : https://www.luogu.com.cn/problem/P3443
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 递归版，u表示当前节点，h表示来到当前节点的链，链头是什么边的序号
        // 迭代版
                // euler1(1, -1);
        // 读写工具类
*/

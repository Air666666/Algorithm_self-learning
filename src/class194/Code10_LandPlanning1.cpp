// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P10517

// Source: src/class194/Code10_LandPlanning1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code10_LandPlanning1 {
  inline static int MAXN = 100001;
  inline static int MAXM = 200001;
  inline static int MAXP = 20;
  inline static int n = {};
  inline static int m = {};
  inline static int q = {};
  inline static int cntn = {};
  inline static Array<bool> arr = make_array<bool>(MAXN);
  inline static Array<int> head1 = make_array<int>(MAXN);
  inline static Array<int> next1 = make_array<int>(jshl(MAXM, 1));
  inline static Array<int> to1 = make_array<int>(jshl(MAXM, 1));
  inline static int cnt1 = {};
  inline static Array<int> head2 = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> next2 = make_array<int>(jshl(MAXM, 2));
  inline static Array<int> to2 = make_array<int>(jshl(MAXM, 2));
  inline static int cnt2 = {};
  inline static Array<int> dfn = make_array<int>(MAXN);
  inline static Array<int> low = make_array<int>(MAXN);
  inline static int cntd = {};
  inline static Array<int> sta = make_array<int>(MAXN);
  inline static int top = {};
  inline static Array<int> dist = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> dep = make_array<int>(jshl(MAXN, 1));
  inline static Array<Array<int>> stjump = make_array<int>(jshl(MAXN, 1), MAXP);
  inline static Array<int> nid = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> seg = make_array<int>(jshl(MAXN, 1));
  inline static int cnti = {};
  inline static JSet<int> set = JSet<int>();
  inline static int sumDist = {};
  inline static Array<Array<int>> stack = make_array<int>(jshl(MAXN, 1), 4);
  inline static int u = {};
  inline static int status = {};
  inline static int fa = {};
  inline static int e = {};
  inline static int stacksize = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code10_LandPlanning1() {}
  static void push(int u, int status, int fa, int e) {
    (stack[stacksize][0] = u);
    (stack[stacksize][1] = status);
    (stack[stacksize][2] = fa);
    (stack[stacksize][3] = e);
    (stacksize++);
  }
  static void pop() {
    (stacksize--);
    (u = stack[stacksize][0]);
    (status = stack[stacksize][1]);
    (fa = stack[stacksize][2]);
    (e = stack[stacksize][3]);
  }
  static void addEdge1(int u, int v) {
    (next1[(++cnt1)] = head1[u]);
    (to1[cnt1] = v);
    (head1[u] = cnt1);
  }
  static void addEdge2(int u, int v) {
    (next2[(++cnt2)] = head2[u]);
    (to2[cnt2] = v);
    (head2[u] = cnt2);
  }
  static void tarjan1(int u) {
    (dfn[u] = (low[u] = (++cntd)));
    (sta[(++top)] = u);
    for (int e = head1[u]; (e > 0); (e = next1[e])) {
      int v = to1[e];
      if ((dfn[v] == 0)) {
        Code10_LandPlanning1::tarjan1(v);
        (low[u] = jmin(low[u], low[v]));
        if ((low[v] >= dfn[u])) {
          (cntn++);
          Code10_LandPlanning1::addEdge2(cntn, u);
          Code10_LandPlanning1::addEdge2(u, cntn);
          int pop = {};
          do {
            (pop = sta[(top--)]);
            Code10_LandPlanning1::addEdge2(cntn, pop);
            Code10_LandPlanning1::addEdge2(pop, cntn);
          } while ((pop != v));
        }
      } else {
        (low[u] = jmin(low[u], dfn[v]));
      }
    }
  }
  static void tarjan2(int node) {
    (stacksize = 0);
    Code10_LandPlanning1::push(node, (-1), 0, (-1));
    int v = {};
    while ((stacksize > 0)) {
      Code10_LandPlanning1::pop();
      if ((status == (-1))) {
        (dfn[u] = (low[u] = (++cntd)));
        (sta[(++top)] = u);
        (e = head1[u]);
      } else {
        (v = to1[e]);
        if ((status == 0)) {
          (low[u] = jmin(low[u], low[v]));
          if ((low[v] >= dfn[u])) {
            (cntn++);
            Code10_LandPlanning1::addEdge2(cntn, u);
            Code10_LandPlanning1::addEdge2(u, cntn);
            int pop = {};
            do {
              (pop = sta[(top--)]);
              Code10_LandPlanning1::addEdge2(cntn, pop);
              Code10_LandPlanning1::addEdge2(pop, cntn);
            } while ((pop != v));
          }
        } else {
          (low[u] = jmin(low[u], dfn[v]));
        }
        (e = next1[e]);
      }
      if ((e != 0)) {
        (v = to1[e]);
        if ((dfn[v] == 0)) {
          Code10_LandPlanning1::push(u, 0, 0, e);
          Code10_LandPlanning1::push(v, (-1), 0, (-1));
        } else {
          Code10_LandPlanning1::push(u, 1, 0, e);
        }
      }
    }
  }
  static void dfs1(int u, int fa) {
    (nid[u] = (++cnti));
    (seg[cnti] = u);
    (dist[u] = (dist[fa] + ((u <= n) ? 1 : 0)));
    (dep[u] = (dep[fa] + 1));
    (stjump[u][0] = fa);
    for (int p = 1; (p < MAXP); (p++)) {
      (stjump[u][p] = stjump[stjump[u][(p - 1)]][(p - 1)]);
    }
    for (int e = head2[u]; (e > 0); (e = next2[e])) {
      int v = to2[e];
      if ((v != fa)) {
        Code10_LandPlanning1::dfs1(v, u);
      }
    }
  }
  static void dfs2(int cur, int father) {
    (stacksize = 0);
    Code10_LandPlanning1::push(cur, 0, father, (-1));
    while ((stacksize > 0)) {
      Code10_LandPlanning1::pop();
      if ((e == (-1))) {
        (nid[u] = (++cnti));
        (seg[cnti] = u);
        (dist[u] = (dist[fa] + ((u <= n) ? 1 : 0)));
        (dep[u] = (dep[fa] + 1));
        (stjump[u][0] = fa);
        for (int p = 1; (p < MAXP); (p++)) {
          (stjump[u][p] = stjump[stjump[u][(p - 1)]][(p - 1)]);
        }
        (e = head2[u]);
      } else {
        (e = next2[e]);
      }
      if ((e != 0)) {
        Code10_LandPlanning1::push(u, 0, fa, e);
        if ((to2[e] != fa)) {
          Code10_LandPlanning1::push(to2[e], 0, u, (-1));
        }
      }
    }
  }
  static int getLca(int a, int b) {
    if ((dep[a] < dep[b])) {
      int tmp = a;
      (a = b);
      (b = tmp);
    }
    for (int p = (MAXP - 1); (p >= 0); (p--)) {
      if ((dep[stjump[a][p]] >= dep[b])) {
        (a = stjump[a][p]);
      }
    }
    if ((a == b)) {
      return a;
    }
    for (int p = (MAXP - 1); (p >= 0); (p--)) {
      if ((stjump[a][p] != stjump[b][p])) {
        (a = stjump[a][p]);
        (b = stjump[b][p]);
      }
    }
    return stjump[a][0];
  }
  static int getDist(int x, int y) {
    return ((dist[x] + dist[y]) -
            (2 * dist[Code10_LandPlanning1::getLca(x, y)]));
  }
  static int compute(int u) {
    int id = nid[u];
    if ((!arr[u])) {
      (arr[u] = true);
      set.add(id);
    } else {
      (arr[u] = false);
      set.remove(id);
    }
    if ((set.size() <= 1)) {
      (sumDist = 0);
    } else {
      int low = seg[((set.lower(id) != nullptr) ? unbox(set.lower(id))
                                                : unbox(set.last()))];
      int high = seg[((set.higher(id) != nullptr) ? unbox(set.higher(id))
                                                  : unbox(set.first()))];
      int delta = [&]() {
        auto jleft = [&]() {
          auto jleft = Code10_LandPlanning1::getDist(u, low);
          auto jright = Code10_LandPlanning1::getDist(u, high);
          return (jleft + jright);
        }();
        auto jright = Code10_LandPlanning1::getDist(low, high);
        return (jleft - jright);
      }();
      if (arr[u]) {
        (sumDist += delta);
      } else {
        (sumDist -= delta);
      }
    }
    if (set.isEmpty()) {
      return 0;
    }
    int extra = (([&]() {
      auto jargument_0 = seg[set.first()];
      auto jargument_1 = seg[set.last()];
      return Code10_LandPlanning1::getLca(jargument_0, jargument_1);
    }() <= n)
                     ? 1
                     : 0);
    return static_cast<int>((jdiv(sumDist, 2) + extra));
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (m = in.nextInt());
    (q = in.nextInt());
    (cntn = n);
    {
      int i = 1;
      int u = {};
      int v = {};
      for (; (i <= m); (i++)) {
        (u = in.nextInt());
        (v = in.nextInt());
        Code10_LandPlanning1::addEdge1(u, v);
        Code10_LandPlanning1::addEdge1(v, u);
      }
    }
    Code10_LandPlanning1::tarjan2(1);
    Code10_LandPlanning1::dfs2(1, 0);
    {
      int i = 1;
      int x = {};
      for (; (i <= q); (i++)) {
        (x = in.nextInt());
        int ans = (n - Code10_LandPlanning1::compute(x));
        out.println(ans);
      }
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code10_LandPlanning1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 国土规划，java版
// 一张无向图有n个点、m条边，所有点连通，可能有重边，但是无自环
// 初始时所有点的状态都是0，一共q次操作，每次操作只有一个参数x，含义如下
// 点x的状态翻转，0变1，1变0，然后考虑如下问题
// 如果某个状态为0的点删除后，所有状态为1的点依然连通，这样的点叫无所谓点
// 每次操作后都打印无所谓点的数量
// 2 <= n <= 10^5
// 1 <= m、q <= 2 * 10^5
// 测试链接 : https://www.luogu.com.cn/problem/P10517
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // nid是圆方树的点获得的dfn序号
        // seg是dfn序号对应的圆方树节点编号
        // cnti是圆方树的dfn序号计数
        // 迭代版需要的栈，讲解118讲了递归改迭代的技巧
        // 递归版
        // 迭代版
        // 递归版
        // 迭代版
                // tarjan1(1);
                // dfs1(1, 0);
        // 读写工具类
*/

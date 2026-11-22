// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P4606

// Source: src/class194/Code09_StrategyGame1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code09_StrategyGame1 {
  inline static int MAXN = 100001;
  inline static int MAXM = 200001;
  inline static int MAXP = 20;
  inline static int t = {};
  inline static int n = {};
  inline static int m = {};
  inline static int q = {};
  inline static int s = {};
  inline static int cntn = {};
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
  inline static int cnti = {};
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static Array<Array<int>> stack = make_array<int>(jshl(MAXN, 1), 4);
  inline static int u = {};
  inline static int status = {};
  inline static int fa = {};
  inline static int e = {};
  inline static int stacksize = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code09_StrategyGame1() {}
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
        Code09_StrategyGame1::tarjan1(v);
        (low[u] = jmin(low[u], low[v]));
        if ((low[v] >= dfn[u])) {
          (cntn++);
          Code09_StrategyGame1::addEdge2(cntn, u);
          Code09_StrategyGame1::addEdge2(u, cntn);
          int pop = {};
          do {
            (pop = sta[(top--)]);
            Code09_StrategyGame1::addEdge2(cntn, pop);
            Code09_StrategyGame1::addEdge2(pop, cntn);
          } while ((pop != v));
        }
      } else {
        (low[u] = jmin(low[u], dfn[v]));
      }
    }
  }
  static void tarjan2(int node) {
    (stacksize = 0);
    Code09_StrategyGame1::push(node, (-1), 0, (-1));
    int v = {};
    while ((stacksize > 0)) {
      Code09_StrategyGame1::pop();
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
            Code09_StrategyGame1::addEdge2(cntn, u);
            Code09_StrategyGame1::addEdge2(u, cntn);
            int pop = {};
            do {
              (pop = sta[(top--)]);
              Code09_StrategyGame1::addEdge2(cntn, pop);
              Code09_StrategyGame1::addEdge2(pop, cntn);
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
          Code09_StrategyGame1::push(u, 0, 0, e);
          Code09_StrategyGame1::push(v, (-1), 0, (-1));
        } else {
          Code09_StrategyGame1::push(u, 1, 0, e);
        }
      }
    }
  }
  static void dfs1(int u, int fa) {
    (nid[u] = (++cnti));
    (dist[u] = (dist[fa] + ((u <= n) ? 1 : 0)));
    (dep[u] = (dep[fa] + 1));
    (stjump[u][0] = fa);
    for (int p = 1; (p < MAXP); (p++)) {
      (stjump[u][p] = stjump[stjump[u][(p - 1)]][(p - 1)]);
    }
    for (int e = head2[u]; (e > 0); (e = next2[e])) {
      int v = to2[e];
      if ((v != fa)) {
        Code09_StrategyGame1::dfs1(v, u);
      }
    }
  }
  static void dfs2(int cur, int father) {
    (stacksize = 0);
    Code09_StrategyGame1::push(cur, 0, father, (-1));
    while ((stacksize > 0)) {
      Code09_StrategyGame1::pop();
      if ((e == (-1))) {
        (nid[u] = (++cnti));
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
        Code09_StrategyGame1::push(u, 0, fa, e);
        if ((to2[e] != fa)) {
          Code09_StrategyGame1::push(to2[e], 0, u, (-1));
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
            (2 * dist[Code09_StrategyGame1::getLca(x, y)]));
  }
  static void sort(Array<int> nums, int l, int r) {
    if ((l >= r))
      return;
    int i = l;
    int j = r;
    int pivot = nums[jshr((l + r), 1)];
    while ((i <= j)) {
      while ((nid[nums[i]] < nid[pivot]))
        (i++);
      while ((nid[nums[j]] > nid[pivot]))
        (j--);
      if ((i <= j)) {
        int tmp = nums[i];
        (nums[i] = nums[j]);
        (nums[j] = tmp);
        (i++);
        (j--);
      }
    }
    Code09_StrategyGame1::sort(nums, l, j);
    Code09_StrategyGame1::sort(nums, i, r);
  }
  static int compute() {
    Code09_StrategyGame1::sort(arr, 1, s);
    int sumDist = 0;
    for (int i = 1; (i < s); (i++)) {
      (sumDist += Code09_StrategyGame1::getDist(arr[i], arr[(i + 1)]));
    }
    (sumDist += Code09_StrategyGame1::getDist(arr[1], arr[s]));
    int extra = ((Code09_StrategyGame1::getLca(arr[1], arr[s]) <= n) ? 1 : 0);
    return ((jdiv(sumDist, 2) + extra) - s);
  }
  static void prepare() {
    (cnt1 = (cnt2 = (cntd = (top = (cnti = 0)))));
    for (int i = 1; (i <= n); (i++)) {
      (head1[i] = (head2[i] = (dfn[i] = 0)));
      (head2[(i + n)] = 0);
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (t = in.nextInt());
    for (int c = 1; (c <= t); (c++)) {
      (n = in.nextInt());
      (m = in.nextInt());
      (cntn = n);
      Code09_StrategyGame1::prepare();
      {
        int i = 1;
        int u = {};
        int v = {};
        for (; (i <= m); (i++)) {
          (u = in.nextInt());
          (v = in.nextInt());
          Code09_StrategyGame1::addEdge1(u, v);
          Code09_StrategyGame1::addEdge1(v, u);
        }
      }
      Code09_StrategyGame1::tarjan2(1);
      Code09_StrategyGame1::dfs2(1, 0);
      (q = in.nextInt());
      for (int i = 1; (i <= q); (i++)) {
        (s = in.nextInt());
        for (int j = 1; (j <= s); (j++)) {
          (arr[j] = in.nextInt());
        }
        out.println(Code09_StrategyGame1::compute());
      }
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code09_StrategyGame1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 战略游戏，java版
// 给定一张无向图，一共n个点、m条边，所有点保证连通，图中可能有重边
// 一共有q条查询，每条查询格式 s K1 K2 .. Ks，含义如下
// 当前查询涉及s个点，给出s个点的编号，你只能删掉一个另外的点
// 删除该点后，只要这s个点中存在任意两点不连通，就算成功
// 对每条查询，打印你能选择的点的个数
// 2 <= n <= 10^5    1 <= m <= 2 * 10^5    1 <= q <= 10^5
// 所有查询中s的总和 <= 2 * 10^5
// 测试链接 : https://www.luogu.com.cn/problem/P4606
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // nid是圆方树的点获得的dfn序号
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

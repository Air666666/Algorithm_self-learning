// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P4103

// Source: src/class180/Code02_BigProject1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_BigProject1 {
  inline static int MAXN = 1000001;
  inline static int MAXP = 20;
  inline static i64 INF = jshl(1LL, 60);
  inline static int n = {};
  inline static int q = {};
  inline static int k = {};
  inline static Array<int> headg = make_array<int>(MAXN);
  inline static Array<int> nextg = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> tog = make_array<int>(jshl(MAXN, 1));
  inline static int cntg = {};
  inline static Array<int> headv = make_array<int>(MAXN);
  inline static Array<int> nextv = make_array<int>(MAXN);
  inline static Array<int> tov = make_array<int>(MAXN);
  inline static int cntv = {};
  inline static Array<int> dep = make_array<int>(MAXN);
  inline static Array<int> dfn = make_array<int>(MAXN);
  inline static Array<Array<int>> stjump = make_array<int>(MAXN, MAXP);
  inline static int cntd = {};
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static Array<bool> isKey = make_array<bool>(MAXN);
  inline static Array<int> tmp = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> stk = make_array<int>(MAXN);
  inline static Array<int> siz = make_array<int>(MAXN);
  inline static Array<i64> sum = make_array<i64>(MAXN);
  inline static Array<i64> near = make_array<i64>(MAXN);
  inline static Array<i64> far = make_array<i64>(MAXN);
  inline static i64 costSum = {};
  inline static i64 costMin = {};
  inline static i64 costMax = {};
  inline static Array<Array<int>> ufe = make_array<int>(MAXN, 3);
  inline static int stacksize = {};
  inline static int u = {};
  inline static int f = {};
  inline static int e = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_BigProject1() {}
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
  static void addEdgeG(int u, int v) {
    (nextg[(++cntg)] = headg[u]);
    (tog[cntg] = v);
    (headg[u] = cntg);
  }
  static void addEdgeV(int u, int v) {
    (nextv[(++cntv)] = headv[u]);
    (tov[cntv] = v);
    (headv[u] = cntv);
  }
  static void sortByDfn(Array<int> nums, int l, int r) {
    if ((l >= r))
      return;
    int i = l;
    int j = r;
    int pivot = nums[jshr((l + r), 1)];
    while ((i <= j)) {
      while ((dfn[nums[i]] < dfn[pivot]))
        (i++);
      while ((dfn[nums[j]] > dfn[pivot]))
        (j--);
      if ((i <= j)) {
        int tmp = nums[i];
        (nums[i] = nums[j]);
        (nums[j] = tmp);
        (i++);
        (j--);
      }
    }
    Code02_BigProject1::sortByDfn(nums, l, j);
    Code02_BigProject1::sortByDfn(nums, i, r);
  }
  static void dfs1(int u, int fa) {
    (dep[u] = (dep[fa] + 1));
    (dfn[u] = (++cntd));
    (stjump[u][0] = fa);
    for (int p = 1; (p < MAXP); (p++)) {
      (stjump[u][p] = stjump[stjump[u][(p - 1)]][(p - 1)]);
    }
    for (int e = headg[u]; (e > 0); (e = nextg[e])) {
      if ((tog[e] != fa)) {
        Code02_BigProject1::dfs1(tog[e], u);
      }
    }
  }
  static void dfs2() {
    (stacksize = 0);
    Code02_BigProject1::push(1, 0, (-1));
    while ((stacksize > 0)) {
      Code02_BigProject1::pop();
      if ((e == (-1))) {
        (dep[u] = (dep[f] + 1));
        (dfn[u] = (++cntd));
        (stjump[u][0] = f);
        for (int p = 1; (p < MAXP); (p++)) {
          (stjump[u][p] = stjump[stjump[u][(p - 1)]][(p - 1)]);
        }
        (e = headg[u]);
      } else {
        (e = nextg[e]);
      }
      if ((e != 0)) {
        Code02_BigProject1::push(u, f, e);
        if ((tog[e] != f)) {
          Code02_BigProject1::push(tog[e], u, (-1));
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
  static int buildVirtualTree1() {
    Code02_BigProject1::sortByDfn(arr, 1, k);
    int len = 0;
    for (int i = 1; (i < k); (i++)) {
      (tmp[(++len)] = arr[i]);
      (tmp[(++len)] = Code02_BigProject1::getLca(arr[i], arr[(i + 1)]));
    }
    (tmp[(++len)] = arr[k]);
    Code02_BigProject1::sortByDfn(tmp, 1, len);
    int unique = 1;
    for (int i = 2; (i <= len); (i++)) {
      if ((tmp[unique] != tmp[i])) {
        (tmp[(++unique)] = tmp[i]);
      }
    }
    (cntv = 0);
    for (int i = 1; (i <= unique); (i++)) {
      (headv[tmp[i]] = 0);
    }
    for (int i = 1; (i < unique); (i++)) {
      Code02_BigProject1::addEdgeV(
          Code02_BigProject1::getLca(tmp[i], tmp[(i + 1)]), tmp[(i + 1)]);
    }
    return tmp[1];
  }
  static int buildVirtualTree2() {
    Code02_BigProject1::sortByDfn(arr, 1, k);
    (cntv = 0);
    (headv[arr[1]] = 0);
    int top = 0;
    (stk[(++top)] = arr[1]);
    for (int i = 2; (i <= k); (i++)) {
      int x = arr[i];
      int y = stk[top];
      int lca = Code02_BigProject1::getLca(x, y);
      while (((top > 1) && (dfn[stk[(top - 1)]] >= dfn[lca]))) {
        Code02_BigProject1::addEdgeV(stk[(top - 1)], stk[top]);
        (top--);
      }
      if ((lca != stk[top])) {
        (headv[lca] = 0);
        Code02_BigProject1::addEdgeV(lca, stk[top]);
        (stk[top] = lca);
      }
      (headv[x] = 0);
      (stk[(++top)] = x);
    }
    while ((top > 1)) {
      Code02_BigProject1::addEdgeV(stk[(top - 1)], stk[top]);
      (top--);
    }
    return stk[1];
  }
  static void dp1(int u) {
    (siz[u] = (isKey[u] ? 1 : 0));
    (sum[u] = 0);
    if (isKey[u]) {
      (far[u] = (near[u] = 0));
    } else {
      (near[u] = INF);
      (far[u] = (-INF));
    }
    for (int e = headv[u]; (e > 0); (e = nextv[e])) {
      Code02_BigProject1::dp1(tov[e]);
    }
    for (int e = headv[u]; (e > 0); (e = nextv[e])) {
      int v = tov[e];
      i64 len = (dep[v] - dep[u]);
      (costSum +=
       (((sum[u] + ((1LL * siz[u]) * len)) * siz[v]) + (sum[v] * siz[u])));
      (siz[u] += siz[v]);
      (sum[u] += (sum[v] + (len * siz[v])));
      (costMin = jmin(costMin, ((near[u] + near[v]) + len)));
      (costMax = jmax(costMax, ((far[u] + far[v]) + len)));
      (near[u] = jmin(near[u], (near[v] + len)));
      (far[u] = jmax(far[u], (far[v] + len)));
    }
  }
  static void dp2(int tree) {
    (stacksize = 0);
    Code02_BigProject1::push(tree, 0, (-1));
    while ((stacksize > 0)) {
      Code02_BigProject1::pop();
      if ((e == (-1))) {
        (siz[u] = (isKey[u] ? 1 : 0));
        (sum[u] = 0);
        if (isKey[u]) {
          (far[u] = (near[u] = 0));
        } else {
          (near[u] = INF);
          (far[u] = (-INF));
        }
        (e = headv[u]);
      } else {
        (e = nextv[e]);
      }
      if ((e != 0)) {
        Code02_BigProject1::push(u, 0, e);
        Code02_BigProject1::push(tov[e], 0, (-1));
      } else {
        for (int ei = headv[u]; (ei > 0); (ei = nextv[ei])) {
          int v = tov[ei];
          i64 len = (dep[v] - dep[u]);
          (costSum +=
           (((sum[u] + ((1LL * siz[u]) * len)) * siz[v]) + (sum[v] * siz[u])));
          (siz[u] += siz[v]);
          (sum[u] += (sum[v] + (len * siz[v])));
          (costMin = jmin(costMin, ((near[u] + near[v]) + len)));
          (costMax = jmax(costMax, ((far[u] + far[v]) + len)));
          (near[u] = jmin(near[u], (near[v] + len)));
          (far[u] = jmax(far[u], (far[v] + len)));
        }
      }
    }
  }
  static void compute() {
    for (int i = 1; (i <= k); (i++)) {
      (isKey[arr[i]] = true);
    }
    int tree = Code02_BigProject1::buildVirtualTree1();
    (costSum = 0);
    (costMin = INF);
    (costMax = (-INF));
    Code02_BigProject1::dp2(tree);
    for (int i = 1; (i <= k); (i++)) {
      (isKey[arr[i]] = false);
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    {
      int i = 1;
      int u = {};
      int v = {};
      for (; (i < n); (i++)) {
        (u = in.nextInt());
        (v = in.nextInt());
        Code02_BigProject1::addEdgeG(u, v);
        Code02_BigProject1::addEdgeG(v, u);
      }
    }
    Code02_BigProject1::dfs2();
    (q = in.nextInt());
    for (int t = 1; (t <= q); (t++)) {
      (k = in.nextInt());
      for (int i = 1; (i <= k); (i++)) {
        (arr[i] = in.nextInt());
      }
      Code02_BigProject1::compute();
      out.println(
          ((((costSum + String(u" ")) + costMin) + String(u" ")) + costMax));
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code02_BigProject1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 大工程，java版
// 一共有n个节点，给定n-1条无向边，所有节点组成一棵树
// 如果在节点a和节点b之间建立新通道，那么代价是两个节点在树上的距离
// 一共有q条查询，每条查询格式如下
// 查询 k a1 a2 ... ak : 给出了k个不同的节点，任意两个节点之间都会建立新通道
// 打印新通道的代价和、新通道中代价最小的值、新通道中代价最大的值
// 1 <= n <= 10^6
// 1 <= q <= 5 * 10^4
// 1 <= 所有查询给出的点的总数 <= 2 * n
// 测试链接 : https://www.luogu.com.cn/problem/P4103
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // siz[u]表示子树u上，关键点的数量
        // sum[u]表示子树u上，所有关键点到u的总距离
        // near[u]表示子树u上，到u最近关键点的距离
        // far[u]表示子树u上，到u最远关键点的距离
        // 新通道的代价和、新通道中代价最小的值、新通道中代价最大的值
        // dfs过程和dp过程，C++同学可以使用递归版
        // 但是java同学必须改迭代版否则会爆栈
        // 不会改迭代版，去看讲解118，详解了从递归版改迭代版
        // ufe不仅用于dfs改迭代，也用于dp改迭代
        // dfs递归版，java会爆栈，C++可以通过
        // dfs1的迭代版
        // 二次排序 + LCA连边的方式建立虚树
        // 单调栈的方式建立虚树
        // dp递归版，java会爆栈，C++可以通过
        // dp1的迭代版
                // int tree = buildVirtualTree2();
                // dp1(tree);
                // dfs1(1, 0);
        // 读写工具类
*/

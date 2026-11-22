// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/CF613D
// https://codeforces.com/problemset/problem/613/D

// Source: src/class180/Code01_KingdomAndCities1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_KingdomAndCities1 {
  inline static int MAXN = 100001;
  inline static int MAXP = 20;
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
  inline static Array<int> cost = make_array<int>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_KingdomAndCities1() {}
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
    Code01_KingdomAndCities1::sortByDfn(nums, l, j);
    Code01_KingdomAndCities1::sortByDfn(nums, i, r);
  }
  static void dfs(int u, int fa) {
    (dep[u] = (dep[fa] + 1));
    (dfn[u] = (++cntd));
    (stjump[u][0] = fa);
    for (int p = 1; (p < MAXP); (p++)) {
      (stjump[u][p] = stjump[stjump[u][(p - 1)]][(p - 1)]);
    }
    for (int e = headg[u]; (e > 0); (e = nextg[e])) {
      if ((tog[e] != fa)) {
        Code01_KingdomAndCities1::dfs(tog[e], u);
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
    Code01_KingdomAndCities1::sortByDfn(arr, 1, k);
    int len = 0;
    for (int i = 1; (i < k); (i++)) {
      (tmp[(++len)] = arr[i]);
      (tmp[(++len)] = Code01_KingdomAndCities1::getLca(arr[i], arr[(i + 1)]));
    }
    (tmp[(++len)] = arr[k]);
    Code01_KingdomAndCities1::sortByDfn(tmp, 1, len);
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
      Code01_KingdomAndCities1::addEdgeV(
          Code01_KingdomAndCities1::getLca(tmp[i], tmp[(i + 1)]), tmp[(i + 1)]);
    }
    return tmp[1];
  }
  static int buildVirtualTree2() {
    Code01_KingdomAndCities1::sortByDfn(arr, 1, k);
    (cntv = 0);
    (headv[arr[1]] = 0);
    int top = 0;
    (stk[(++top)] = arr[1]);
    for (int i = 2; (i <= k); (i++)) {
      int x = arr[i];
      int y = stk[top];
      int lca = Code01_KingdomAndCities1::getLca(x, y);
      while (((top > 1) && (dfn[stk[(top - 1)]] >= dfn[lca]))) {
        Code01_KingdomAndCities1::addEdgeV(stk[(top - 1)], stk[top]);
        (top--);
      }
      if ((lca != stk[top])) {
        (headv[lca] = 0);
        Code01_KingdomAndCities1::addEdgeV(lca, stk[top]);
        (stk[top] = lca);
      }
      (headv[x] = 0);
      (stk[(++top)] = x);
    }
    while ((top > 1)) {
      Code01_KingdomAndCities1::addEdgeV(stk[(top - 1)], stk[top]);
      (top--);
    }
    return stk[1];
  }
  static void dp(int u) {
    (cost[u] = (siz[u] = 0));
    for (int e = headv[u]; (e > 0); (e = nextv[e])) {
      int v = tov[e];
      Code01_KingdomAndCities1::dp(v);
      (cost[u] += cost[v]);
      (siz[u] += siz[v]);
    }
    if (isKey[u]) {
      (cost[u] += siz[u]);
      (siz[u] = 1);
    } else if ((siz[u] > 1)) {
      (cost[u]++);
      (siz[u] = 0);
    }
  }
  static int compute() {
    for (int i = 1; (i <= k); (i++)) {
      (isKey[arr[i]] = true);
    }
    bool check = true;
    for (int i = 1; (i <= k); (i++)) {
      if (isKey[stjump[arr[i]][0]]) {
        (check = false);
        break;
      }
    }
    int ans = (-1);
    if (check) {
      int tree = Code01_KingdomAndCities1::buildVirtualTree1();
      Code01_KingdomAndCities1::dp(tree);
      (ans = cost[tree]);
    }
    for (int i = 1; (i <= k); (i++)) {
      (isKey[arr[i]] = false);
    }
    return ans;
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
        Code01_KingdomAndCities1::addEdgeG(u, v);
        Code01_KingdomAndCities1::addEdgeG(v, u);
      }
    }
    Code01_KingdomAndCities1::dfs(1, 0);
    (q = in.nextInt());
    for (int t = 1; (t <= q); (t++)) {
      (k = in.nextInt());
      for (int i = 1; (i <= k); (i++)) {
        (arr[i] = in.nextInt());
      }
      out.println(Code01_KingdomAndCities1::compute());
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code01_KingdomAndCities1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 王国和城市，java版
// 一共有n个节点，给定n-1条无向边，所有节点组成一棵树
// 一共有q条查询，每条查询格式如下
// 查询 k a1 a2 ... ak : 给出了k个不同的重要点，其他点是非重要点
//                       你可以攻占非重要点，被攻占的点无法通行
// 要让重要点两两之间不再连通，打印至少需要攻占几个非重要点
//                       如果攻占非重要点无法达成目标，打印-1
// 1 <= n、q <= 10^5
// 1 <= 所有查询给出的点的总数 <= 10^5
// 测试链接 : https://www.luogu.com.cn/problem/CF613D
// 测试链接 : https://codeforces.com/problemset/problem/613/D
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 原始树
        // 虚树
        // 树上倍增求LCA + 生成dfn序
        // 关键点数组
        // 标记节点是否是关键点
        // 第一种建树方式
        // 第二种建树方式
        // 动态规划相关
        // siz[u]，还有几个重要点没和u断开，值为0或者1
        // cost[u]，表示节点u的子树中，做到不违规，至少需要攻占几个非重要点
        // 原始树连边
        // 虚树连边
        // nums中的数，根据dfn的大小排序，手撸双指针快排
        // 树上倍增的dfs过程
        // 返回a和b的最低公共祖先
        // 二次排序 + LCA连边的方式建立虚树
        // 单调栈的方式建立虚树
        // 树型dp的过程
                // 节点标记关键点信息
                        // 只能通过攻占非关键点的方式，来隔开关键点
                        // 所以如果 a 和 a的父节点
都是关键点，这是怎么也隔不开的
                        // 直接返回-1即可
                        // int tree = buildVirtualTree2();
                // 节点撤销关键点信息
        // 读写工具类
*/

// Source: src/class177/Code07_MoOnTree1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code07_MoOnTree1 {
  struct QueryCmp;
  struct QueryCmp {
    String toString() const { return j::str(static_cast<const void *>(this)); }
    QueryCmp() {}
    int compare(Array<int> a, Array<int> b) {
      if ((bi[a[0]] != bi[b[0]])) {
        return (bi[a[0]] - bi[b[0]]);
      }
      return (a[1] - b[1]);
    }
  };
  inline static int MAXN = 40001;
  inline static int MAXM = 100001;
  inline static int MAXP = 20;
  inline static int n = {};
  inline static int m = {};
  inline static Array<int> color = make_array<int>(MAXN);
  inline static Array<int> sorted = make_array<int>(MAXN);
  inline static int cntv = {};
  inline static Array<Array<int>> query = make_array<int>(MAXM, 4);
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> to = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> next = make_array<int>(jshl(MAXN, 1));
  inline static int cntg = {};
  inline static Array<int> dep = make_array<int>(MAXN);
  inline static Array<int> seg = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> st = make_array<int>(MAXN);
  inline static Array<int> ed = make_array<int>(MAXN);
  inline static Array<Array<int>> stjump = make_array<int>(MAXN, MAXP);
  inline static int cntd = {};
  inline static Array<int> bi = make_array<int>(jshl(MAXN, 1));
  inline static Array<bool> vis = make_array<bool>(MAXN);
  inline static Array<int> cnt = make_array<int>(MAXN);
  inline static int kind = 0;
  inline static Array<int> ans = make_array<int>(MAXM);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code07_MoOnTree1() {}
  static void addEdge(int u, int v) {
    (next[(++cntg)] = head[u]);
    (to[cntg] = v);
    (head[u] = cntg);
  }
  static int kth(int num) {
    int left = 1;
    int right = cntv;
    int mid = {};
    int ret = 0;
    while ((left <= right)) {
      (mid = jshr((left + right), 1));
      if ((sorted[mid] <= num)) {
        (ret = mid);
        (left = (mid + 1));
      } else {
        (right = (mid - 1));
      }
    }
    return ret;
  }
  static void dfs(int u, int fa) {
    (dep[u] = (dep[fa] + 1));
    (seg[(++cntd)] = u);
    (st[u] = cntd);
    (stjump[u][0] = fa);
    for (int p = 1; (p < MAXP); (p++)) {
      (stjump[u][p] = stjump[stjump[u][(p - 1)]][(p - 1)]);
    }
    {
      int e = head[u];
      int v = {};
      for (; (e > 0); (e = next[e])) {
        (v = to[e]);
        if ((v != fa)) {
          Code07_MoOnTree1::dfs(v, u);
        }
      }
    }
    (seg[(++cntd)] = u);
    (ed[u] = cntd);
  }
  static int lca(int a, int b) {
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
  static void invert(int node) {
    int val = color[node];
    if (vis[node]) {
      if (((--cnt[val]) == 0)) {
        (kind--);
      }
    } else {
      if (((++cnt[val]) == 1)) {
        (kind++);
      }
    }
    (vis[node] = (!vis[node]));
  }
  static void compute() {
    int winl = 1;
    int winr = 0;
    for (int i = 1; (i <= m); (i++)) {
      int jobl = query[i][0];
      int jobr = query[i][1];
      int lca = query[i][2];
      int id = query[i][3];
      while ((winl > jobl)) {
        Code07_MoOnTree1::invert(seg[(--winl)]);
      }
      while ((winr < jobr)) {
        Code07_MoOnTree1::invert(seg[(++winr)]);
      }
      while ((winl < jobl)) {
        Code07_MoOnTree1::invert(seg[(winl++)]);
      }
      while ((winr > jobr)) {
        Code07_MoOnTree1::invert(seg[(winr--)]);
      }
      if ((lca > 0)) {
        Code07_MoOnTree1::invert(lca);
      }
      (ans[id] = kind);
      if ((lca > 0)) {
        Code07_MoOnTree1::invert(lca);
      }
    }
  }
  static void prepare() {
    for (int i = 1; (i <= n); (i++)) {
      (sorted[i] = color[i]);
    }
    j::sort(sorted, 1, (n + 1));
    (cntv = 1);
    for (int i = 2; (i <= n); (i++)) {
      if ((sorted[cntv] != sorted[i])) {
        (sorted[(++cntv)] = sorted[i]);
      }
    }
    for (int i = 1; (i <= n); (i++)) {
      (color[i] = Code07_MoOnTree1::kth(color[i]));
    }
    int blen = static_cast<int>(std::sqrt(cntd));
    for (int i = 1; (i <= cntd); (i++)) {
      (bi[i] = (jdiv((i - 1), blen) + 1));
    }
    j::sort(query, 1, (m + 1), new QueryCmp());
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (m = in.nextInt());
    for (int i = 1; (i <= n); (i++)) {
      (color[i] = in.nextInt());
    }
    {
      int i = 1;
      int u = {};
      int v = {};
      for (; (i < n); (i++)) {
        (u = in.nextInt());
        (v = in.nextInt());
        Code07_MoOnTree1::addEdge(u, v);
        Code07_MoOnTree1::addEdge(v, u);
      }
    }
    Code07_MoOnTree1::dfs(1, 0);
    {
      int i = 1;
      int u = {};
      int v = {};
      int uvlca = {};
      for (; (i <= m); (i++)) {
        (u = in.nextInt());
        (v = in.nextInt());
        if ((st[v] < st[u])) {
          int tmp = u;
          (u = v);
          (v = tmp);
        }
        (uvlca = Code07_MoOnTree1::lca(u, v));
        if ((u == uvlca)) {
          (query[i][0] = st[u]);
          (query[i][1] = st[v]);
          (query[i][2] = 0);
        } else {
          (query[i][0] = ed[u]);
          (query[i][1] = st[v]);
          (query[i][2] = uvlca);
        }
        (query[i][3] = i);
      }
    }
    Code07_MoOnTree1::prepare();
    Code07_MoOnTree1::compute();
    for (int i = 1; (i <= m); (i++)) {
      out.println(ans[i]);
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code07_MoOnTree1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 树上莫队入门题，java版
// 一共有n个节点，每个节点给定颜色值，给定n-1条边，所有节点连成一棵树
// 一共有m条查询，格式 u v : 打印点u到点v的简单路径上，有几种不同的颜色
// 1 <= n <= 4 * 10^4
// 1 <= m <= 10^5
// 1 <= 颜色值 <= 2 * 10^9
// 测试链接 : https://www.luogu.com.cn/problem/SP10707
// 测试链接 : https://www.spoj.com/problems/COT2/
// 提交以下的code，提交时请把类名改成"Main"
// java实现的逻辑一定是正确的，但是本题卡常，无法通过所有测试用例
// 想通过用C++实现，本节课Code07_MoOnTree2文件就是C++的实现
// 两个版本的逻辑完全一样，C++版本可以通过所有测试
        // 查询的参数，jobl、jobr、lca、id
        // 如果是类型1，那么lca == 0，表示空缺
        // 如果是类型2，那么lca > 0，查询结果需要补充这个单点信息
        // 链式前向星
        // dep是深度
        // seg是括号序
        // st是节点开始序
        // ed是节点结束序
        // stjump是倍增表
        // cntd是括号序列的长度
        // 分块
        // 窗口信息
        // 普通莫队经典排序
        // 窗口不管是加入还是删除node
        // 只要遇到node就翻转信息即可
                // 括号序列分块
        // 读写工具类
*/

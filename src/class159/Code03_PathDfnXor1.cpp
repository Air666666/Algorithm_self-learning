// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P4592

// Source: src/class159/Code03_PathDfnXor1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_PathDfnXor1 {
  inline static int MAXN = 100001;
  inline static int MAXT = (MAXN * 62);
  inline static int MAXP = 16;
  inline static int BIT = 29;
  inline static int n = {};
  inline static int m = {};
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> next = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> to = make_array<int>(jshl(MAXN, 1));
  inline static int cntg = 0;
  inline static Array<int> deep = make_array<int>(MAXN);
  inline static Array<int> size = make_array<int>(MAXN);
  inline static Array<Array<int>> stjump = make_array<int>(MAXN, MAXP);
  inline static Array<int> dfn = make_array<int>(MAXN);
  inline static int cntd = 0;
  inline static Array<int> root1 = make_array<int>(MAXN);
  inline static Array<int> root2 = make_array<int>(MAXN);
  inline static Array<Array<int>> tree = make_array<int>(MAXT, 2);
  inline static Array<int> pass = make_array<int>(MAXT);
  inline static int cntt = 0;
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_PathDfnXor1() {}
  static void addEdge(int u, int v) {
    (next[(++cntg)] = head[u]);
    (to[cntg] = v);
    (head[u] = cntg);
  }
  static int insert(int num, int i) {
    int rt = (++cntt);
    (tree[rt][0] = tree[i][0]);
    (tree[rt][1] = tree[i][1]);
    (pass[rt] = (pass[i] + 1));
    {
      int b = BIT;
      int path = {};
      int pre = rt;
      int cur = {};
      for (; (b >= 0); (b--), (pre = cur)) {
        (path = (jshr(num, b) & 1));
        (i = tree[i][path]);
        (cur = (++cntt));
        (tree[cur][0] = tree[i][0]);
        (tree[cur][1] = tree[i][1]);
        (pass[cur] = (pass[i] + 1));
        (tree[pre][path] = cur);
      }
    }
    return rt;
  }
  static int query(int num, int u, int v) {
    int ans = 0;
    {
      int b = BIT;
      int path = {};
      int best = {};
      for (; (b >= 0); (b--)) {
        (path = (jshr(num, b) & 1));
        (best = (path ^ 1));
        if ((pass[tree[v][best]] > pass[tree[u][best]])) {
          (ans += jshl(1, b));
          (u = tree[u][best]);
          (v = tree[v][best]);
        } else {
          (u = tree[u][path]);
          (v = tree[v][path]);
        }
      }
    }
    return ans;
  }
  static void dfs1(int u, int fa) {
    (deep[u] = (deep[fa] + 1));
    (size[u] = 1);
    (stjump[u][0] = fa);
    (dfn[u] = (++cntd));
    for (int p = 1; (p < MAXP); (p++)) {
      (stjump[u][p] = stjump[stjump[u][(p - 1)]][(p - 1)]);
    }
    {
      int ei = head[u];
      int v = {};
      for (; (ei > 0); (ei = next[ei])) {
        (v = to[ei]);
        if ((v != fa)) {
          Code03_PathDfnXor1::dfs1(v, u);
          (size[u] += size[v]);
        }
      }
    }
  }
  static void dfs2(int u, int fa) {
    (root1[dfn[u]] = Code03_PathDfnXor1::insert(arr[u], root1[(dfn[u] - 1)]));
    (root2[u] = Code03_PathDfnXor1::insert(arr[u], root2[fa]));
    for (int ei = head[u]; (ei > 0); (ei = next[ei])) {
      if ((to[ei] != fa)) {
        Code03_PathDfnXor1::dfs2(to[ei], u);
      }
    }
  }
  static int lca(int a, int b) {
    if ((deep[a] < deep[b])) {
      int tmp = a;
      (a = b);
      (b = tmp);
    }
    for (int p = (MAXP - 1); (p >= 0); (p--)) {
      if ((deep[stjump[a][p]] >= deep[b])) {
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
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    (n = static_cast<int>(in.nval));
    in.nextToken();
    (m = static_cast<int>(in.nval));
    for (int i = 1; (i <= n); (i++)) {
      in.nextToken();
      (arr[i] = static_cast<int>(in.nval));
    }
    {
      int i = 1;
      int u = {};
      int v = {};
      for (; (i < n); (i++)) {
        in.nextToken();
        (u = static_cast<int>(in.nval));
        in.nextToken();
        (v = static_cast<int>(in.nval));
        Code03_PathDfnXor1::addEdge(u, v);
        Code03_PathDfnXor1::addEdge(v, u);
      }
    }
    Code03_PathDfnXor1::dfs1(1, 0);
    Code03_PathDfnXor1::dfs2(1, 0);
    {
      int i = 1;
      int op = {};
      int x = {};
      int y = {};
      int z = {};
      for (; (i <= m); (i++)) {
        in.nextToken();
        (op = static_cast<int>(in.nval));
        in.nextToken();
        (x = static_cast<int>(in.nval));
        in.nextToken();
        (y = static_cast<int>(in.nval));
        if ((op == 1)) {
          out.println(Code03_PathDfnXor1::query(
              y, root1[(dfn[x] - 1)], root1[((dfn[x] + size[x]) - 1)]));
        } else {
          in.nextToken();
          (z = static_cast<int>(in.nval));
          int lcafa = stjump[Code03_PathDfnXor1::lca(x, y)][0];
          int ans = [&]() {
            auto jargument_0 =
                Code03_PathDfnXor1::query(z, root2[lcafa], root2[x]);
            auto jargument_1 =
                Code03_PathDfnXor1::query(z, root2[lcafa], root2[y]);
            return jmax(jargument_0, jargument_1);
          }();
          out.println(ans);
        }
      }
    }
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code03_PathDfnXor1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 路径和子树的异或，java版
// 一共有n个节点，n-1条边，组成一棵树，1号节点为树头，每个节点给定点权
// 一共有m条查询，每条查询是如下两种类型中的一种
// 1 x y   : 以x为头的子树中任选一个值，希望异或y之后的值最大，打印最大值
// 2 x y z : 节点x到节点y的路径中任选一个值，希望异或z之后的值最大，打印最大值
// 2 <= n、m <= 10^5
// 1 <= 点权、z < 2^30
// 测试链接 : https://www.luogu.com.cn/problem/P4592
// java实现的逻辑一定是正确的，但是通过不了
// 因为这道题根据C++的运行空间，制定通过标准，根本没考虑java的用户
// 想通过用C++实现，本节课Code03_PathDfnXor2文件就是C++的实现
// 两个版本的逻辑完全一样，C++版本可以通过所有测试
        // 每个节点的点权
        // 链式前向星需要
        // 链式前向星的边的计数
        // 树上dfs求节点深度
        // 树上dfs求子树大小
        // 树上dfs求st表
        // 树上dfs求每个节点的dfn序号
        // dfn序号计数
        // 1类型的可持久化01Trie，根据dfn序号的次序建树
        // 2类型的可持久化01Trie，根据父节点的版本建新树
        // 1类型和2类型都可以用这个tree结构
        // 1类型和2类型都可以用这个pass数组
        // 1类型和2类型一起的节点计数
        // 按道理说dfs1应该改成迭代版，防止递归爆栈
        // 不过本题给定的空间很小，java版怎么也无法通过，索性不改了
        // 有兴趣的同学可以看一下，讲解118，详解了树上dfs从递归版改迭代版
        // 按道理说dfs2应该改成迭代版，防止递归爆栈
        // 不过本题给定的空间很小，java版怎么也无法通过，索性不改了
        // 有兴趣的同学可以看一下，讲解118，详解了树上dfs从递归版改迭代版
*/

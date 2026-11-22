// Source: src/class163/Code01_DsuOnTree1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_DsuOnTree1 {
  inline static int MAXN = 100001;
  inline static int n = {};
  inline static int m = {};
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> next = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> to = make_array<int>(jshl(MAXN, 1));
  inline static int cnt = 0;
  inline static Array<int> fa = make_array<int>(MAXN);
  inline static Array<int> siz = make_array<int>(MAXN);
  inline static Array<int> son = make_array<int>(MAXN);
  inline static Array<int> colorCnt = make_array<int>(MAXN);
  inline static Array<int> ans = make_array<int>(MAXN);
  inline static int diffColors = 0;
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_DsuOnTree1() {}
  static void addEdge(int u, int v) {
    (next[(++cnt)] = head[u]);
    (to[cnt] = v);
    (head[u] = cnt);
  }
  static void dfs1(int u, int f) {
    (fa[u] = f);
    (siz[u] = 1);
    {
      int e = head[u];
      int v = {};
      for (; (e > 0); (e = next[e])) {
        (v = to[e]);
        if ((v != f)) {
          Code01_DsuOnTree1::dfs1(v, u);
        }
      }
    }
    {
      int e = head[u];
      int v = {};
      for (; (e > 0); (e = next[e])) {
        (v = to[e]);
        if ((v != f)) {
          (siz[u] += siz[v]);
          if (((son[u] == 0) || (siz[son[u]] < siz[v]))) {
            (son[u] = v);
          }
        }
      }
    }
  }
  static void effect(int u) {
    if (((++colorCnt[arr[u]]) == 1)) {
      (diffColors++);
    }
    {
      int e = head[u];
      int v = {};
      for (; (e > 0); (e = next[e])) {
        (v = to[e]);
        if ((v != fa[u])) {
          Code01_DsuOnTree1::effect(v);
        }
      }
    }
  }
  static void cancel(int u) {
    if (((--colorCnt[arr[u]]) == 0)) {
      (diffColors--);
    }
    {
      int e = head[u];
      int v = {};
      for (; (e > 0); (e = next[e])) {
        (v = to[e]);
        if ((v != fa[u])) {
          Code01_DsuOnTree1::cancel(v);
        }
      }
    }
  }
  static void dfs2(int u, int keep) {
    {
      int e = head[u];
      int v = {};
      for (; (e > 0); (e = next[e])) {
        (v = to[e]);
        if (((v != fa[u]) && (v != son[u]))) {
          Code01_DsuOnTree1::dfs2(v, 0);
        }
      }
    }
    if ((son[u] != 0)) {
      Code01_DsuOnTree1::dfs2(son[u], 1);
    }
    if (((++colorCnt[arr[u]]) == 1)) {
      (diffColors++);
    }
    {
      int e = head[u];
      int v = {};
      for (; (e > 0); (e = next[e])) {
        (v = to[e]);
        if (((v != fa[u]) && (v != son[u]))) {
          Code01_DsuOnTree1::effect(v);
        }
      }
    }
    (ans[u] = diffColors);
    if ((keep == 0)) {
      Code01_DsuOnTree1::cancel(u);
    }
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    (n = static_cast<int>(in.nval));
    {
      int i = 1;
      int u = {};
      int v = {};
      for (; (i < n); (i++)) {
        in.nextToken();
        (u = static_cast<int>(in.nval));
        in.nextToken();
        (v = static_cast<int>(in.nval));
        Code01_DsuOnTree1::addEdge(u, v);
        Code01_DsuOnTree1::addEdge(v, u);
      }
    }
    for (int i = 1; (i <= n); (i++)) {
      in.nextToken();
      (arr[i] = static_cast<int>(in.nval));
    }
    Code01_DsuOnTree1::dfs1(1, 0);
    Code01_DsuOnTree1::dfs2(1, 0);
    in.nextToken();
    (m = static_cast<int>(in.nval));
    {
      int i = 1;
      int cur = {};
      for (; (i <= m); (i++)) {
        in.nextToken();
        (cur = static_cast<int>(in.nval));
        out.println(ans[cur]);
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
  Code01_DsuOnTree1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 树上启发式合并模版题，java版
// 一共有n个节点，编号1~n，给定n-1条边，所有节点连成一棵树，1号节点为树头
// 每个节点给定一种颜色值，一共有m条查询，每条查询给定参数x
// 每条查询打印x为头的子树上，一共有多少种不同的颜色
// 1 <= n、m、颜色值 <= 10^5
// 测试链接 : https://www.luogu.com.cn/problem/U41492
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 每个节点的颜色
        // 链式前向星
        // 树链剖分
        // 树上启发式合并
        // colorCnt[i] = j，表示i这种颜色出现了j次
        // 重链剖分
        // 子树u每个节点贡献信息
        // 子树u每个节点取消贡献
        // 树上启发式合并的过程
                // 遍历轻儿子的子树，统计子树的答案，然后取消贡献
                // 遍历重儿子的子树，统计子树的答案，然后保留贡献
                // 当前节点贡献信息
                // 遍历轻儿子的子树，重新贡献一遍
                // 记录子树u的答案
                // 如果u是上级节点的轻儿子，子树u的贡献取消，否则保留
*/

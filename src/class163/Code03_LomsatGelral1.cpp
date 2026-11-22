// Source: src/class163/Code03_LomsatGelral1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_LomsatGelral1 {
  inline static int MAXN = 100001;
  inline static int n = {};
  inline static Array<int> color = make_array<int>(MAXN);
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> next = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> to = make_array<int>(jshl(MAXN, 1));
  inline static int cnt = 0;
  inline static Array<int> fa = make_array<int>(MAXN);
  inline static Array<int> siz = make_array<int>(MAXN);
  inline static Array<int> son = make_array<int>(MAXN);
  inline static Array<int> colorCnt = make_array<int>(MAXN);
  inline static Array<int> maxCnt = make_array<int>(MAXN);
  inline static Array<i64> ans = make_array<i64>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_LomsatGelral1() {}
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
          Code03_LomsatGelral1::dfs1(v, u);
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
  static void effect(int u, int h) {
    (colorCnt[color[u]]++);
    if ((colorCnt[color[u]] == maxCnt[h])) {
      (ans[h] += color[u]);
    } else if ((colorCnt[color[u]] > maxCnt[h])) {
      (maxCnt[h] = colorCnt[color[u]]);
      (ans[h] = color[u]);
    }
    {
      int e = head[u];
      int v = {};
      for (; (e > 0); (e = next[e])) {
        (v = to[e]);
        if ((v != fa[u])) {
          Code03_LomsatGelral1::effect(v, h);
        }
      }
    }
  }
  static void cancel(int u) {
    (colorCnt[color[u]] = 0);
    (maxCnt[u] = 0);
    {
      int e = head[u];
      int v = {};
      for (; (e > 0); (e = next[e])) {
        (v = to[e]);
        if ((v != fa[u])) {
          Code03_LomsatGelral1::cancel(v);
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
          Code03_LomsatGelral1::dfs2(v, 0);
        }
      }
    }
    if ((son[u] != 0)) {
      Code03_LomsatGelral1::dfs2(son[u], 1);
    }
    (maxCnt[u] = maxCnt[son[u]]);
    (ans[u] = ans[son[u]]);
    (colorCnt[color[u]]++);
    if ((colorCnt[color[u]] == maxCnt[u])) {
      (ans[u] += color[u]);
    } else if ((colorCnt[color[u]] > maxCnt[u])) {
      (maxCnt[u] = colorCnt[color[u]]);
      (ans[u] = color[u]);
    }
    {
      int e = head[u];
      int v = {};
      for (; (e > 0); (e = next[e])) {
        (v = to[e]);
        if (((v != fa[u]) && (v != son[u]))) {
          Code03_LomsatGelral1::effect(v, u);
        }
      }
    }
    if ((keep == 0)) {
      Code03_LomsatGelral1::cancel(u);
    }
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    (n = static_cast<int>(in.nval));
    for (int i = 1; (i <= n); (i++)) {
      in.nextToken();
      (color[i] = static_cast<int>(in.nval));
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
        Code03_LomsatGelral1::addEdge(u, v);
        Code03_LomsatGelral1::addEdge(v, u);
      }
    }
    Code03_LomsatGelral1::dfs1(1, 0);
    Code03_LomsatGelral1::dfs2(1, 0);
    for (int i = 1; (i <= n); (i++)) {
      out.print((ans[i] + String(u" ")));
    }
    out.println();
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code03_LomsatGelral1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 主导颜色累加和，java版
// 一共有n个节点，编号1~n，给定n-1条边，所有节点连成一棵树，1号节点为树头
// 每个节点给定一种颜色值，主导颜色累加和定义如下
// 以x为头的子树上，哪种颜色出现最多，那种颜色就是主导颜色，主导颜色可能不止一种
// 所有主导颜色的值累加起来，每个主导颜色只累加一次，就是该子树的主导颜色累加和
// 打印1~n每个节点为头的子树的主导颜色累加和
// 1 <= n、颜色值 <= 10^5
// 测试链接 : https://www.luogu.com.cn/problem/CF600E
// 测试链接 : https://codeforces.com/problemset/problem/600/E
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
*/

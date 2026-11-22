// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/CF741D
// https://codeforces.com/problemset/problem/741/D

// Source: src/class163/Code06_RearrangePalindrome1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code06_RearrangePalindrome1 {
  inline static int MAXN = 500001;
  inline static int MAXV = 22;
  inline static int n = {};
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> next = make_array<int>(MAXN);
  inline static Array<int> to = make_array<int>(MAXN);
  inline static Array<int> weight = make_array<int>(MAXN);
  inline static int cnt = 0;
  inline static Array<int> siz = make_array<int>(MAXN);
  inline static Array<int> dep = make_array<int>(MAXN);
  inline static Array<int> eor = make_array<int>(MAXN);
  inline static Array<int> son = make_array<int>(MAXN);
  inline static Array<int> maxdep = make_array<int>(jshl(1, MAXV));
  inline static Array<int> ans = make_array<int>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code06_RearrangePalindrome1() {}
  static void addEdge(int u, int v, int w) {
    (next[(++cnt)] = head[u]);
    (to[cnt] = v);
    (weight[cnt] = w);
    (head[u] = cnt);
  }
  static void dfs1(int u, int d, int x) {
    (siz[u] = 1);
    (dep[u] = d);
    (eor[u] = x);
    for (int e = head[u]; (e > 0); (e = next[e])) {
      Code06_RearrangePalindrome1::dfs1(to[e], (d + 1),
                                        (x ^ jshl(1, weight[e])));
    }
    {
      int e = head[u];
      int v = {};
      for (; (e > 0); (e = next[e])) {
        (v = to[e]);
        (siz[u] += siz[v]);
        if (((son[u] == 0) || (siz[son[u]] < siz[v]))) {
          (son[u] = v);
        }
      }
    }
  }
  static void effect(int u) {
    (maxdep[eor[u]] = jmax(maxdep[eor[u]], dep[u]));
    for (int e = head[u]; (e > 0); (e = next[e])) {
      Code06_RearrangePalindrome1::effect(to[e]);
    }
  }
  static void cancel(int u) {
    (maxdep[eor[u]] = 0);
    for (int e = head[u]; (e > 0); (e = next[e])) {
      Code06_RearrangePalindrome1::cancel(to[e]);
    }
  }
  static void answerFromLight(int light, int u) {
    if ((maxdep[eor[light]] != 0)) {
      (ans[u] =
           jmax(ans[u], ((maxdep[eor[light]] + dep[light]) - (dep[u] * 2))));
    }
    for (int i = 0; (i < MAXV); (i++)) {
      if ((maxdep[(eor[light] ^ jshl(1, i))] != 0)) {
        (ans[u] =
             jmax(ans[u], ((maxdep[(eor[light] ^ jshl(1, i))] + dep[light]) -
                           (dep[u] * 2))));
      }
    }
    for (int e = head[light]; (e > 0); (e = next[e])) {
      Code06_RearrangePalindrome1::answerFromLight(to[e], u);
    }
  }
  static void dfs2(int u, int keep) {
    {
      int e = head[u];
      int v = {};
      for (; (e > 0); (e = next[e])) {
        (v = to[e]);
        if ((v != son[u])) {
          Code06_RearrangePalindrome1::dfs2(v, 0);
        }
      }
    }
    if ((son[u] != 0)) {
      Code06_RearrangePalindrome1::dfs2(son[u], 1);
    }
    for (int e = head[u]; (e > 0); (e = next[e])) {
      (ans[u] = jmax(ans[u], ans[to[e]]));
    }
    if ((maxdep[eor[u]] != 0)) {
      (ans[u] = jmax(ans[u], (maxdep[eor[u]] - dep[u])));
    }
    for (int i = 0; (i < MAXV); (i++)) {
      if ((maxdep[(eor[u] ^ jshl(1, i))] != 0)) {
        (ans[u] = jmax(ans[u], (maxdep[(eor[u] ^ jshl(1, i))] - dep[u])));
      }
    }
    (maxdep[eor[u]] = jmax(maxdep[eor[u]], dep[u]));
    {
      int e = head[u];
      int v = {};
      for (; (e > 0); (e = next[e])) {
        (v = to[e]);
        if ((v != son[u])) {
          Code06_RearrangePalindrome1::answerFromLight(v, u);
          Code06_RearrangePalindrome1::effect(v);
        }
      }
    }
    if ((keep == 0)) {
      Code06_RearrangePalindrome1::cancel(u);
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO();
    IO out = IO(IO(jout));
    (n = in.nextInt());
    {
      int i = 2;
      int fth = {};
      int edg = {};
      for (; (i <= n); (i++)) {
        (fth = in.nextInt());
        (edg = (in.nextChar() - u'a'));
        Code06_RearrangePalindrome1::addEdge(fth, i, edg);
      }
    }
    Code06_RearrangePalindrome1::dfs1(1, 1, 0);
    Code06_RearrangePalindrome1::dfs2(1, 0);
    for (int i = 1; (i <= n); (i++)) {
      out.print((ans[i] + String(u" ")));
    }
    out.println();
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code06_RearrangePalindrome1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 最长重排回文路径，java版
// 一共有n个节点，编号1~n，给定n-1条边，所有节点连成一棵树，1号节点为树头
// 每条边上都有一个字符，字符范围[a~v]，字符一共22种，重排回文路径的定义如下
//
节点a到节点b的路径，如果所有边的字符收集起来，能重新排列成回文串，该路径是重排回文路径
// 打印1~n每个节点为头的子树中，最长重排回文路径的长度
// 1 <= n <= 5 * 10^5
// 测试链接 : https://www.luogu.com.cn/problem/CF741D
// 测试链接 : https://codeforces.com/problemset/problem/741/D
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 字符种类最多22种
        // 链式前向星
        // 树链剖分
        // 树上启发式合并
                // 每一个儿子的子树，里得到的答案
                // 选择当前节点，再选择重儿子树上的任意一点，得到的答案
                // 枚举所有可能得到的异或值
                // 当前点的异或值，更新最大深度信息
                //
选择遍历过的部分里的任意一点，再选择当前遍历到的子树里的任意一点，得到的答案
        // 读写工具类
*/

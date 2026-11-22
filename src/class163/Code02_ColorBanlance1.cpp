// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P9233

// Source: src/class163/Code02_ColorBanlance1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_ColorBanlance1 {
  inline static int MAXN = 200001;
  inline static int n = {};
  inline static Array<int> color = make_array<int>(MAXN);
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> next = make_array<int>(MAXN);
  inline static Array<int> to = make_array<int>(MAXN);
  inline static int cnt = 0;
  inline static Array<int> siz = make_array<int>(MAXN);
  inline static Array<int> son = make_array<int>(MAXN);
  inline static Array<int> colorCnt = make_array<int>(MAXN);
  inline static Array<int> colorNum = make_array<int>(MAXN);
  inline static int ans = 0;
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_ColorBanlance1() {}
  static void addEdge(int u, int v) {
    (next[(++cnt)] = head[u]);
    (to[cnt] = v);
    (head[u] = cnt);
  }
  static void dfs1(int u) {
    (siz[u] = 1);
    for (int e = head[u]; (e > 0); (e = next[e])) {
      Code02_ColorBanlance1::dfs1(to[e]);
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
    (colorCnt[color[u]]++);
    (colorNum[(colorCnt[color[u]] - 1)]--);
    (colorNum[colorCnt[color[u]]]++);
    for (int e = head[u]; (e > 0); (e = next[e])) {
      Code02_ColorBanlance1::effect(to[e]);
    }
  }
  static void cancel(int u) {
    (colorCnt[color[u]]--);
    (colorNum[(colorCnt[color[u]] + 1)]--);
    (colorNum[colorCnt[color[u]]]++);
    for (int e = head[u]; (e > 0); (e = next[e])) {
      Code02_ColorBanlance1::cancel(to[e]);
    }
  }
  static void dfs2(int u, int keep) {
    {
      int e = head[u];
      int v = {};
      for (; (e > 0); (e = next[e])) {
        (v = to[e]);
        if ((v != son[u])) {
          Code02_ColorBanlance1::dfs2(v, 0);
        }
      }
    }
    if ((son[u] != 0)) {
      Code02_ColorBanlance1::dfs2(son[u], 1);
    }
    (colorCnt[color[u]]++);
    (colorNum[(colorCnt[color[u]] - 1)]--);
    (colorNum[colorCnt[color[u]]]++);
    {
      int e = head[u];
      int v = {};
      for (; (e > 0); (e = next[e])) {
        (v = to[e]);
        if ((v != son[u])) {
          Code02_ColorBanlance1::effect(v);
        }
      }
    }
    if (((colorCnt[color[u]] * colorNum[colorCnt[color[u]]]) == siz[u])) {
      (ans++);
    }
    if ((keep == 0)) {
      Code02_ColorBanlance1::cancel(u);
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
      int father = {};
      for (; (i <= n); (i++)) {
        in.nextToken();
        (color[i] = static_cast<int>(in.nval));
        in.nextToken();
        (father = static_cast<int>(in.nval));
        if ((i != 1)) {
          Code02_ColorBanlance1::addEdge(father, i);
        }
      }
    }
    Code02_ColorBanlance1::dfs1(1);
    Code02_ColorBanlance1::dfs2(1, 0);
    out.println(ans);
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code02_ColorBanlance1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 颜色平衡的子树，java实现递归版
// 一共有n个节点，编号1~n，给定每个节点的颜色值和父亲节点编号
// 输入保证所有节点一定组成一棵树，并且1号节点是树头
// 如果一棵子树中，存在的每种颜色的节点个数都相同，这棵子树叫颜色平衡树
// 打印整棵树中有多少个子树是颜色平衡树
// 1 <= n、颜色值 <= 2 * 10^5
// 测试链接 : https://www.luogu.com.cn/problem/P9233
// 提交以下的code，提交时请把类名改成"Main"
// 因为树的深度太大，递归函数爆栈了，所以会有两个测试用例无法通过
// 迭代版可以完全通过，就是本节课Code02_ColorBanlance2文件
        // colorCnt[i] = j，表示i这种颜色出现了j次
        // colorNum[i] = j，表示出现次数为i的颜色一共有j种
        // 颜色平衡子树的个数
*/

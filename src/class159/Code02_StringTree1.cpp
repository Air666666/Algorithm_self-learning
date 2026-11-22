// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P6088

// Source: src/class159/Code02_StringTree1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_StringTree1 {
  inline static int MAXN = 100001;
  inline static int MAXT = 1000001;
  inline static int MAXP = 20;
  inline static int n = {};
  inline static int m = {};
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> next = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> to = make_array<int>(jshl(MAXN, 1));
  inline static Array<String> weight = make_array<String>(jshl(MAXN, 1));
  inline static int cntg = 0;
  inline static Array<int> root = make_array<int>(MAXN);
  inline static Array<Array<int>> tree = make_array<int>(MAXT, 27);
  inline static Array<int> pass = make_array<int>(MAXT);
  inline static int cntt = 0;
  inline static Array<int> deep = make_array<int>(MAXN);
  inline static Array<Array<int>> stjump = make_array<int>(MAXN, MAXP);
  inline static Array<int> us = make_array<int>(MAXN);
  inline static Array<int> fs = make_array<int>(MAXN);
  inline static Array<int> es = make_array<int>(MAXN);
  inline static Array<String> ps = make_array<String>(MAXN);
  inline static int stackSize = {};
  inline static int u = {};
  inline static int f = {};
  inline static int e = {};
  inline static String p = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_StringTree1() {}
  static void addEdge(int u, int v, String w) {
    (next[(++cntg)] = head[u]);
    (to[cntg] = v);
    (weight[cntg] = w);
    (head[u] = cntg);
  }
  static int num(jchar cha) { return ((cha - u'a') + 1); }
  static int clone(int i) {
    int rt = (++cntt);
    for (int cha = 1; (cha <= 26); (cha++)) {
      (tree[rt][cha] = tree[i][cha]);
    }
    (pass[rt] = pass[i]);
    return rt;
  }
  static int insert(String str, int i) {
    int rt = Code02_StringTree1::clone(i);
    (pass[rt]++);
    {
      int j = 0;
      int path = {};
      int pre = rt;
      int cur = {};
      for (; (j < str.length()); (j++), (pre = cur)) {
        (path = Code02_StringTree1::num(str.charAt(j)));
        (i = tree[i][path]);
        (cur = Code02_StringTree1::clone(i));
        (pass[cur]++);
        (tree[pre][path] = cur);
      }
    }
    return rt;
  }
  static int query(String str, int i) {
    {
      int j = 0;
      int path = {};
      for (; (j < str.length()); (j++)) {
        (path = Code02_StringTree1::num(str.charAt(j)));
        (i = tree[i][path]);
        if ((i == 0)) {
          return 0;
        }
      }
    }
    return pass[i];
  }
  static void dfs1(int u, int fa, String path) {
    (root[u] = Code02_StringTree1::insert(path, root[fa]));
    (deep[u] = (deep[fa] + 1));
    (stjump[u][0] = fa);
    for (int p = 1; (p < MAXP); (p++)) {
      (stjump[u][p] = stjump[stjump[u][(p - 1)]][(p - 1)]);
    }
    for (int e = head[u]; (e > 0); (e = next[e])) {
      if ((to[e] != fa)) {
        Code02_StringTree1::dfs1(to[e], u, weight[e]);
      }
    }
  }
  static void push(int u, int f, int e, String p) {
    (us[stackSize] = u);
    (fs[stackSize] = f);
    (es[stackSize] = e);
    (ps[stackSize] = p);
    (stackSize++);
  }
  static void pop() {
    (--stackSize);
    (u = us[stackSize]);
    (f = fs[stackSize]);
    (e = es[stackSize]);
    (p = ps[stackSize]);
  }
  static void dfs2() {
    (stackSize = 0);
    Code02_StringTree1::push(1, 0, (-1), String(u""));
    while ((stackSize > 0)) {
      Code02_StringTree1::pop();
      if ((e == (-1))) {
        (root[u] = Code02_StringTree1::insert(p, root[f]));
        (deep[u] = (deep[f] + 1));
        (stjump[u][0] = f);
        for (int p = 1; (p < MAXP); (p++)) {
          (stjump[u][p] = stjump[stjump[u][(p - 1)]][(p - 1)]);
        }
        (e = head[u]);
      } else {
        (e = next[e]);
      }
      if ((e != 0)) {
        Code02_StringTree1::push(u, f, e, p);
        if ((to[e] != f)) {
          Code02_StringTree1::push(to[e], u, (-1), weight[e]);
        }
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
  static int compute(int u, int v, String s) {
    return [&]() {
      auto jleft = [&]() {
        auto jleft = Code02_StringTree1::query(s, root[u]);
        auto jright = Code02_StringTree1::query(s, root[v]);
        return (jleft + jright);
      }();
      auto jright = (2 * Code02_StringTree1::query(
                             s, root[Code02_StringTree1::lca(u, v)]));
      return (jleft - jright);
    }();
  }
  static void java_main(Array<String> args) {
    IO io = IO();
    (n = io.nextInt());
    int u = {};
    int v = {};
    String s = {};
    for (int i = 1; (i < n); (i++)) {
      (u = io.nextInt());
      (v = io.nextInt());
      (s = io.next());
      Code02_StringTree1::addEdge(u, v, s);
      Code02_StringTree1::addEdge(v, u, s);
    }
    Code02_StringTree1::dfs2();
    (m = io.nextInt());
    for (int i = 1; (i <= m); (i++)) {
      (u = io.nextInt());
      (v = io.nextInt());
      (s = io.next());
      io.println(Code02_StringTree1::compute(u, v, s));
    }
    io.flush();
    io.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code02_StringTree1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 字符串树，java版
// 一共有n个节点，n-1条边，组成一棵树，每条边的边权为字符串
// 一共有m条查询，每条查询的格式为
// u v s : 查询节点u到节点v的路径中，有多少边的字符串以字符串s作为前缀
// 1 <= n、m <= 10^5
// 所有字符串长度不超过10，并且都由字符a~z组成
// 测试链接 : https://www.luogu.com.cn/problem/P6088
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 链式前向星需要
        // 可持久化前缀树需要
        // 树上倍增和LCA需要
        // 递归版，C++可以通过，java无法通过，递归会爆栈
        // 迭代版，都可以通过
        // 讲解118，详解了从递归版改迭代版
        // dfs1方法改成迭代版
        // 读写工具类
*/

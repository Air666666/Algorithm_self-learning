// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P5903

// Source: src/class162/Code04_TreeKthAncestor1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_TreeKthAncestor1 {
  inline static int MAXN = 500001;
  inline static int MAXP = 20;
  inline static int n = {};
  inline static int m = {};
  inline static i64 s = {};
  inline static int root = {};
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> next = make_array<int>(MAXN);
  inline static Array<int> to = make_array<int>(MAXN);
  inline static int cntg = 0;
  inline static Array<Array<int>> stjump = make_array<int>(MAXN, MAXP);
  inline static Array<int> dep = make_array<int>(MAXN);
  inline static Array<int> len = make_array<int>(MAXN);
  inline static Array<int> son = make_array<int>(MAXN);
  inline static Array<int> top = make_array<int>(MAXN);
  inline static Array<int> dfn = make_array<int>(MAXN);
  inline static int cntd = 0;
  inline static Array<int> high = make_array<int>(MAXN);
  inline static Array<int> up = make_array<int>(MAXN);
  inline static Array<int> down = make_array<int>(MAXN);
  inline static Array<Array<int>> fse = make_array<int>(MAXN, 3);
  inline static int stacksize = {};
  inline static int first = {};
  inline static int second = {};
  inline static int edge = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_TreeKthAncestor1() {}
  static i64 get(i64 x) {
    (x ^= jshl(x, 13));
    (x &= 0xffffffffLL);
    (x ^= jushr(x, 17));
    (x ^= jshl(x, 5));
    (x &= 0xffffffffLL);
    return (s = x);
  }
  static void setUp(int u, int i, int v) { (up[(dfn[u] + i)] = v); }
  static int getUp(int u, int i) { return up[(dfn[u] + i)]; }
  static void setDown(int u, int i, int v) { (down[(dfn[u] + i)] = v); }
  static int getDown(int u, int i) { return down[(dfn[u] + i)]; }
  static void addEdge(int u, int v) {
    (next[(++cntg)] = head[u]);
    (to[cntg] = v);
    (head[u] = cntg);
  }
  static void dfs1(int u, int f) {
    (stjump[u][0] = f);
    for (int p = 1; (p < MAXP); (p++)) {
      (stjump[u][p] = stjump[stjump[u][(p - 1)]][(p - 1)]);
    }
    (dep[u] = (dep[f] + 1));
    {
      int e = head[u];
      int v = {};
      for (; (e > 0); (e = next[e])) {
        (v = to[e]);
        if ((v != f)) {
          Code04_TreeKthAncestor1::dfs1(v, u);
        }
      }
    }
    {
      int e = head[u];
      int v = {};
      for (; (e > 0); (e = next[e])) {
        (v = to[e]);
        if ((v != f)) {
          if (((son[u] == 0) || (len[son[u]] < len[v]))) {
            (son[u] = v);
          }
        }
      }
    }
    (len[u] = (len[son[u]] + 1));
  }
  static void dfs2(int u, int t) {
    (top[u] = t);
    (dfn[u] = (++cntd));
    if ((son[u] == 0)) {
      return;
    }
    Code04_TreeKthAncestor1::dfs2(son[u], t);
    {
      int e = head[u];
      int v = {};
      for (; (e > 0); (e = next[e])) {
        (v = to[e]);
        if (((v != stjump[u][0]) && (v != son[u]))) {
          Code04_TreeKthAncestor1::dfs2(v, v);
        }
      }
    }
  }
  static void push(int fir, int sec, int edg) {
    (fse[stacksize][0] = fir);
    (fse[stacksize][1] = sec);
    (fse[stacksize][2] = edg);
    (stacksize++);
  }
  static void pop() {
    (--stacksize);
    (first = fse[stacksize][0]);
    (second = fse[stacksize][1]);
    (edge = fse[stacksize][2]);
  }
  static void dfs3() {
    (stacksize = 0);
    Code04_TreeKthAncestor1::push(root, 0, (-1));
    while ((stacksize > 0)) {
      Code04_TreeKthAncestor1::pop();
      if ((edge == (-1))) {
        (stjump[first][0] = second);
        for (int p = 1; (p < MAXP); (p++)) {
          (stjump[first][p] = stjump[stjump[first][(p - 1)]][(p - 1)]);
        }
        (dep[first] = (dep[second] + 1));
        (edge = head[first]);
      } else {
        (edge = next[edge]);
      }
      if ((edge != 0)) {
        Code04_TreeKthAncestor1::push(first, second, edge);
        if ((to[edge] != second)) {
          Code04_TreeKthAncestor1::push(to[edge], first, (-1));
        }
      } else {
        {
          int e = head[first];
          int v = {};
          for (; (e > 0); (e = next[e])) {
            (v = to[e]);
            if ((v != second)) {
              if (((son[first] == 0) || (len[son[first]] < len[v]))) {
                (son[first] = v);
              }
            }
          }
        }
        (len[first] = (len[son[first]] + 1));
      }
    }
  }
  static void dfs4() {
    (stacksize = 0);
    Code04_TreeKthAncestor1::push(root, root, (-1));
    while ((stacksize > 0)) {
      Code04_TreeKthAncestor1::pop();
      if ((edge == (-1))) {
        (top[first] = second);
        (dfn[first] = (++cntd));
        if ((son[first] == 0)) {
          continue;
        }
        Code04_TreeKthAncestor1::push(first, second, (-2));
        Code04_TreeKthAncestor1::push(son[first], second, (-1));
        continue;
      } else if ((edge == (-2))) {
        (edge = head[first]);
      } else {
        (edge = next[edge]);
      }
      if ((edge != 0)) {
        Code04_TreeKthAncestor1::push(first, second, edge);
        if (((to[edge] != stjump[first][0]) && (to[edge] != son[first]))) {
          Code04_TreeKthAncestor1::push(to[edge], to[edge], (-1));
        }
      }
    }
  }
  static void prepare() {
    Code04_TreeKthAncestor1::dfs3();
    Code04_TreeKthAncestor1::dfs4();
    (high[0] = (-1));
    for (int i = 1; (i <= n); (i++)) {
      (high[i] = (high[jdiv(i, 2)] + 1));
    }
    for (int u = 1; (u <= n); (u++)) {
      if ((top[u] == u)) {
        {
          int i = 0;
          int a = u;
          int b = u;
          for (; (i < len[u]); (i++), (a = stjump[a][0]), (b = son[b])) {
            Code04_TreeKthAncestor1::setUp(u, i, a);
            Code04_TreeKthAncestor1::setDown(u, i, b);
          }
        }
      }
    }
  }
  static int query(int x, int k) {
    if ((k == 0)) {
      return x;
    }
    if ((k == jshl(1, high[k]))) {
      return stjump[x][high[k]];
    }
    (x = stjump[x][high[k]]);
    (k -= jshl(1, high[k]));
    (k -= (dep[x] - dep[top[x]]));
    (x = top[x]);
    return ((k >= 0) ? Code04_TreeKthAncestor1::getUp(x, k)
                     : Code04_TreeKthAncestor1::getDown(x, (-k)));
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    (n = static_cast<int>(in.nval));
    in.nextToken();
    (m = static_cast<int>(in.nval));
    in.nextToken();
    (s = static_cast<i64>(in.nval));
    {
      int i = 1;
      int father = {};
      for (; (i <= n); (i++)) {
        in.nextToken();
        (father = static_cast<int>(in.nval));
        if ((father == 0)) {
          (root = i);
        } else {
          Code04_TreeKthAncestor1::addEdge(father, i);
        }
      }
    }
    Code04_TreeKthAncestor1::prepare();
    i64 ans = 0;
    {
      int i = 1;
      int x = {};
      int k = {};
      int lastAns = 0;
      for (; (i <= m); (i++)) {
        (x = static_cast<int>(
             (jrem((Code04_TreeKthAncestor1::get(s) ^ lastAns), n) + 1)));
        (k = static_cast<int>(
             jrem((Code04_TreeKthAncestor1::get(s) ^ lastAns), dep[x])));
        (lastAns = Code04_TreeKthAncestor1::query(x, k));
        (ans ^= (static_cast<i64>(i) * lastAns));
      }
    }
    out.println(ans);
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code04_TreeKthAncestor1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 树上k级祖先，java版
// 一共有n个节点，编号1~n，给定一个长度为n的数组arr，表示依赖关系
// 如果arr[i] = j，表示i号节点的父节点是j，如果arr[i] == 0，表示i号节点是树头
// 一共有m条查询，每条查询 x k : 打印x往上走k步的祖先节点编号
// 题目要求预处理的时间复杂度O(n * log n)，处理每条查询的时间复杂度O(1)
//
题目要求强制在线，必须按顺序处理每条查询，如何得到每条查询的入参，请打开测试链接查看
// 1 <= n <= 5 * 10^5
// 1 <= m <= 5 * 10^6
// 测试链接 : https://www.luogu.com.cn/problem/P5903
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 链式前向星，注意是有向图，所以边的数量不需要增倍
        // 倍增表 + 长链剖分
        // 查询答案需要
        // 题目规定如何得到输入数据的函数
        // C++中有无符号整数，java中没有，选择用long类型代替
        // 递归版
        // 递归版
        // 不会改迭代版，去看讲解118，详解了从递归版改迭代版
        // dfs1的迭代版
        // dfs2的迭代版
*/

// Source: src/class158/Code05_MoreImpressive1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code05_MoreImpressive1 {
  inline static int MAXN = 300001;
  inline static int MAXT = (MAXN * 22);
  inline static int n = {};
  inline static int m = {};
  inline static int depth = {};
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> to = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> next = make_array<int>(jshl(MAXN, 1));
  inline static int cntg = 0;
  inline static Array<int> root = make_array<int>(MAXN);
  inline static Array<int> left = make_array<int>(MAXT);
  inline static Array<int> right = make_array<int>(MAXT);
  inline static Array<i64> sum = make_array<i64>(MAXT);
  inline static int cntt = 0;
  inline static Array<int> deep = make_array<int>(MAXN);
  inline static Array<int> size = make_array<int>(MAXN);
  inline static Array<int> dfn = make_array<int>(MAXN);
  inline static int cntd = 0;
  inline static Array<Array<int>> ufe = make_array<int>(MAXN, 3);
  inline static int stackSize = {};
  inline static int u = {};
  inline static int f = {};
  inline static int e = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code05_MoreImpressive1() {}
  static void addEdge(int u, int v) {
    (next[(++cntg)] = head[u]);
    (to[cntg] = v);
    (head[u] = cntg);
  }
  static int build(int l, int r) {
    int rt = (++cntt);
    (sum[rt] = 0);
    if ((l < r)) {
      int mid = jdiv((l + r), 2);
      (left[rt] = Code05_MoreImpressive1::build(l, mid));
      (right[rt] = Code05_MoreImpressive1::build((mid + 1), r));
    }
    return rt;
  }
  static int add(int jobi, i64 jobv, int l, int r, int i) {
    int rt = (++cntt);
    (left[rt] = left[i]);
    (right[rt] = right[i]);
    (sum[rt] = (sum[i] + jobv));
    if ((l < r)) {
      int mid = jdiv((l + r), 2);
      if ((jobi <= mid)) {
        (left[rt] = Code05_MoreImpressive1::add(jobi, jobv, l, mid, left[rt]));
      } else {
        (right[rt] =
             Code05_MoreImpressive1::add(jobi, jobv, (mid + 1), r, right[rt]));
      }
    }
    return rt;
  }
  static i64 query(int jobl, int jobr, int l, int r, int u, int v) {
    if (((jobl <= l) && (r <= jobr))) {
      return (sum[v] - sum[u]);
    }
    i64 ans = 0;
    int mid = jdiv((l + r), 2);
    if ((jobl <= mid)) {
      (ans +=
       Code05_MoreImpressive1::query(jobl, jobr, l, mid, left[u], left[v]));
    }
    if ((jobr > mid)) {
      (ans += Code05_MoreImpressive1::query(jobl, jobr, (mid + 1), r, right[u],
                                            right[v]));
    }
    return ans;
  }
  static void dfs1(int u, int f) {
    (deep[u] = (deep[f] + 1));
    (depth = jmax(depth, deep[u]));
    (size[u] = 1);
    (dfn[u] = (++cntd));
    for (int ei = head[u]; (ei > 0); (ei = next[ei])) {
      if ((to[ei] != f)) {
        Code05_MoreImpressive1::dfs1(to[ei], u);
      }
    }
    for (int ei = head[u]; (ei > 0); (ei = next[ei])) {
      if ((to[ei] != f)) {
        (size[u] += size[to[ei]]);
      }
    }
  }
  static void dfs2(int u, int f) {
    (root[dfn[u]] = Code05_MoreImpressive1::add(deep[u], (size[u] - 1), 1,
                                                depth, root[(dfn[u] - 1)]));
    for (int ei = head[u]; (ei > 0); (ei = next[ei])) {
      if ((to[ei] != f)) {
        Code05_MoreImpressive1::dfs2(to[ei], u);
      }
    }
  }
  static void push(int u, int f, int e) {
    (ufe[stackSize][0] = u);
    (ufe[stackSize][1] = f);
    (ufe[stackSize][2] = e);
    (stackSize++);
  }
  static void pop() {
    (--stackSize);
    (u = ufe[stackSize][0]);
    (f = ufe[stackSize][1]);
    (e = ufe[stackSize][2]);
  }
  static void dfs3() {
    (stackSize = 0);
    Code05_MoreImpressive1::push(1, 0, (-1));
    while ((stackSize > 0)) {
      Code05_MoreImpressive1::pop();
      if ((e == (-1))) {
        (deep[u] = (deep[f] + 1));
        (depth = jmax(depth, deep[u]));
        (size[u] = 1);
        (dfn[u] = (++cntd));
        (e = head[u]);
      } else {
        (e = next[e]);
      }
      if ((e != 0)) {
        Code05_MoreImpressive1::push(u, f, e);
        if ((to[e] != f)) {
          Code05_MoreImpressive1::push(to[e], u, (-1));
        }
      } else {
        for (int ei = head[u]; (ei > 0); (ei = next[ei])) {
          if ((to[ei] != f)) {
            (size[u] += size[to[ei]]);
          }
        }
      }
    }
  }
  static void dfs4() {
    (stackSize = 0);
    Code05_MoreImpressive1::push(1, 0, (-1));
    while ((stackSize > 0)) {
      Code05_MoreImpressive1::pop();
      if ((e == (-1))) {
        (root[dfn[u]] = Code05_MoreImpressive1::add(deep[u], (size[u] - 1), 1,
                                                    depth, root[(dfn[u] - 1)]));
        (e = head[u]);
      } else {
        (e = next[e]);
      }
      if ((e != 0)) {
        Code05_MoreImpressive1::push(u, f, e);
        if ((to[e] != f)) {
          Code05_MoreImpressive1::push(to[e], u, (-1));
        }
      }
    }
  }
  static void prepare() {
    (depth = 0);
    Code05_MoreImpressive1::dfs3();
    (root[0] = Code05_MoreImpressive1::build(1, depth));
    Code05_MoreImpressive1::dfs4();
  }
  static i64 compute(int a, int k) {
    i64 ans = (static_cast<i64>((size[a] - 1)) * jmin(k, (deep[a] - 1)));
    (ans += Code05_MoreImpressive1::query((deep[a] + 1), (deep[a] + k), 1,
                                          depth, root[(dfn[a] - 1)],
                                          root[((dfn[a] + size[a]) - 1)]));
    return ans;
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    (n = static_cast<int>(in.nval));
    in.nextToken();
    (m = static_cast<int>(in.nval));
    {
      int i = 1;
      int u = {};
      int v = {};
      for (; (i < n); (i++)) {
        in.nextToken();
        (u = static_cast<int>(in.nval));
        in.nextToken();
        (v = static_cast<int>(in.nval));
        Code05_MoreImpressive1::addEdge(u, v);
        Code05_MoreImpressive1::addEdge(v, u);
      }
    }
    Code05_MoreImpressive1::prepare();
    {
      int i = 1;
      int a = {};
      int k = {};
      for (; (i <= m); (i++)) {
        in.nextToken();
        (a = static_cast<int>(in.nval));
        in.nextToken();
        (k = static_cast<int>(in.nval));
        out.println(Code05_MoreImpressive1::compute(a, k));
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
  Code05_MoreImpressive1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 更为厉害，java版
// 为了方便理解，我改写了题意，但是改写的题意和原始题意等效
// 有n个节点，编号1~n，给定n-1条边，连成一棵树，1号点是树头
// 如果x是y的祖先节点，认为"x比y更厉害"
// 如果x到y的路径上，边的数量 <= 某个常数，认为"x和y是邻居"
// 一共有m条查询，每条查询 a k : 打印有多少三元组(a, b, c)满足如下规定
// a、b、c为三个不同的点；a和b都比c厉害；a和b是邻居，路径边的数量 <= 给定的k
// 1 <= n、m、k <= 3 * 10^5
// 测试链接 : https://www.luogu.com.cn/problem/P3899
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 链式前向星需要
        // 可持久化线段树需要
        // dfs需要
        // deep[i] : i号节点的深度
        // size[i] : 以i号节点为头的树，有多少个节点
        // dfn[i] : i号节点的dfn序号
        // 递归版，C++可以通过，java无法通过，递归会爆栈
        // 递归版，C++可以通过，java无法通过，递归会爆栈
        // dfs1、dfs2，分别改成迭代版，dfs3、dfs4
        // 讲解118，详解了从递归版改迭代版
        // dfs1的迭代版
        // dfs2的迭代版
*/

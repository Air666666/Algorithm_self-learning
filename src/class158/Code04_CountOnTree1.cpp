// Source: src/class158/Code04_CountOnTree1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_CountOnTree1 {
  inline static int MAXN = 100001;
  inline static int MAXP = 20;
  inline static int MAXT = (MAXN * MAXP);
  inline static int n = {};
  inline static int m = {};
  inline static int s = {};
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static Array<int> sorted = make_array<int>(MAXN);
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> to = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> next = make_array<int>(jshl(MAXN, 1));
  inline static int cntg = 0;
  inline static Array<int> root = make_array<int>(MAXN);
  inline static Array<int> left = make_array<int>(MAXT);
  inline static Array<int> right = make_array<int>(MAXT);
  inline static Array<int> size = make_array<int>(MAXT);
  inline static int cntt = 0;
  inline static Array<int> deep = make_array<int>(MAXN);
  inline static Array<Array<int>> stjump = make_array<int>(MAXN, MAXP);
  inline static Array<Array<int>> ufe = make_array<int>(MAXN, 3);
  inline static int stackSize = {};
  inline static int u = {};
  inline static int f = {};
  inline static int e = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_CountOnTree1() {}
  static int kth(int num) {
    int left = 1;
    int right = s;
    int mid = {};
    while ((left <= right)) {
      (mid = jdiv((left + right), 2));
      if ((sorted[mid] == num)) {
        return mid;
      } else if ((sorted[mid] < num)) {
        (left = (mid + 1));
      } else {
        (right = (mid - 1));
      }
    }
    return (-1);
  }
  static int build(int l, int r) {
    int rt = (++cntt);
    (size[rt] = 0);
    if ((l < r)) {
      int mid = jdiv((l + r), 2);
      (left[rt] = Code04_CountOnTree1::build(l, mid));
      (right[rt] = Code04_CountOnTree1::build((mid + 1), r));
    }
    return rt;
  }
  static void prepare() {
    for (int i = 1; (i <= n); (i++)) {
      (sorted[i] = arr[i]);
    }
    j::sort(sorted, 1, (n + 1));
    (s = 1);
    for (int i = 2; (i <= n); (i++)) {
      if ((sorted[s] != sorted[i])) {
        (sorted[(++s)] = sorted[i]);
      }
    }
    (root[0] = Code04_CountOnTree1::build(1, s));
  }
  static void addEdge(int u, int v) {
    (next[(++cntg)] = head[u]);
    (to[cntg] = v);
    (head[u] = cntg);
  }
  static int insert(int jobi, int l, int r, int i) {
    int rt = (++cntt);
    (left[rt] = left[i]);
    (right[rt] = right[i]);
    (size[rt] = (size[i] + 1));
    if ((l < r)) {
      int mid = jdiv((l + r), 2);
      if ((jobi <= mid)) {
        (left[rt] = Code04_CountOnTree1::insert(jobi, l, mid, left[rt]));
      } else {
        (right[rt] =
             Code04_CountOnTree1::insert(jobi, (mid + 1), r, right[rt]));
      }
    }
    return rt;
  }
  static int query(int jobk, int l, int r, int u, int v, int lca, int lcafa) {
    if ((l == r)) {
      return l;
    }
    int lsize = (((size[left[u]] + size[left[v]]) - size[left[lca]]) -
                 size[left[lcafa]]);
    int mid = jdiv((l + r), 2);
    if ((lsize >= jobk)) {
      return Code04_CountOnTree1::query(jobk, l, mid, left[u], left[v],
                                        left[lca], left[lcafa]);
    } else {
      return Code04_CountOnTree1::query((jobk - lsize), (mid + 1), r, right[u],
                                        right[v], right[lca], right[lcafa]);
    }
  }
  static void dfs1(int u, int f) {
    (root[u] = Code04_CountOnTree1::insert(Code04_CountOnTree1::kth(arr[u]), 1,
                                           s, root[f]));
    (deep[u] = (deep[f] + 1));
    (stjump[u][0] = f);
    for (int p = 1; (p < MAXP); (p++)) {
      (stjump[u][p] = stjump[stjump[u][(p - 1)]][(p - 1)]);
    }
    for (int ei = head[u]; (ei > 0); (ei = next[ei])) {
      if ((to[ei] != f)) {
        Code04_CountOnTree1::dfs1(to[ei], u);
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
  static void dfs2() {
    (stackSize = 0);
    Code04_CountOnTree1::push(1, 0, (-1));
    while ((stackSize > 0)) {
      Code04_CountOnTree1::pop();
      if ((e == (-1))) {
        (root[u] = Code04_CountOnTree1::insert(Code04_CountOnTree1::kth(arr[u]),
                                               1, s, root[f]));
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
        Code04_CountOnTree1::push(u, f, e);
        if ((to[e] != f)) {
          Code04_CountOnTree1::push(to[e], u, (-1));
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
  static int kth(int u, int v, int k) {
    int lca = Code04_CountOnTree1::lca(u, v);
    int i = Code04_CountOnTree1::query(k, 1, s, root[u], root[v], root[lca],
                                       root[stjump[lca][0]]);
    return sorted[i];
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
    Code04_CountOnTree1::prepare();
    {
      int i = 1;
      int u = {};
      int v = {};
      for (; (i < n); (i++)) {
        in.nextToken();
        (u = static_cast<int>(in.nval));
        in.nextToken();
        (v = static_cast<int>(in.nval));
        Code04_CountOnTree1::addEdge(u, v);
        Code04_CountOnTree1::addEdge(v, u);
      }
    }
    Code04_CountOnTree1::dfs2();
    {
      int i = 1;
      int u = {};
      int v = {};
      int k = {};
      int lastAns = 0;
      for (; (i <= m); (i++)) {
        in.nextToken();
        (u = (static_cast<int>(in.nval) ^ lastAns));
        in.nextToken();
        (v = static_cast<int>(in.nval));
        in.nextToken();
        (k = static_cast<int>(in.nval));
        (lastAns = Code04_CountOnTree1::kth(u, v, k));
        out.println(lastAns);
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
  Code04_CountOnTree1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 路径上的第k小，java版
// 有n个节点，编号1~n，每个节点有权值，有n-1条边，所有节点组成一棵树
// 一共有m条查询，每条查询 u v k : 打印u号点到v号点的路径上，第k小的点权
// 题目有强制在线的要求，上一次打印的答案为lastAns，初始时lastAns = 0
// 每次给定的u、v、k，按照如下方式得到真实的u、v、k，查询完成后更新lastAns
// 真实u = 给定u ^ lastAns
// 真实v = 给定v
// 真实k = 给定k
// 1 <= n、m <= 10^5
// 1 <= arr[i] <= 2^32 - 1
// 测试链接 : https://www.luogu.com.cn/problem/P2633
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 各个节点权值
        // 收集权值排序并且去重做离散化
        // 链式前向星需要
        // 可持久化线段树需要
        // 树上倍增找lca需要
        // 递归版，C++可以通过，java无法通过，递归会爆栈
        // 迭代版，都可以通过
        // 讲解118，详解了从递归版改迭代版
        // dfs1的迭代版
*/

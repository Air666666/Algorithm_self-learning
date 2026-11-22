// Source: src/class118/Code02_Multiply2.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_Multiply2 {
  inline static int MAXN = 500001;
  inline static int LIMIT = 20;
  inline static int power = {};
  inline static int cnt = {};
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> next = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> to = make_array<int>(jshl(MAXN, 1));
  inline static Array<Array<int>> stjump = make_array<int>(MAXN, LIMIT);
  inline static Array<int> deep = make_array<int>(MAXN);
  inline static Array<Array<int>> ufe = make_array<int>(MAXN, 3);
  inline static int stackSize = {};
  inline static int u = {};
  inline static int f = {};
  inline static int e = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_Multiply2() {}
  static int log2(int n) {
    int ans = 0;
    while ((jshl(1, ans) <= jshr(n, 1))) {
      (ans++);
    }
    return ans;
  }
  static void build(int n) {
    (power = Code02_Multiply2::log2(n));
    (cnt = 1);
    j::fill(head, 1, (n + 1), 0);
  }
  static void addEdge(int u, int v) {
    (next[cnt] = head[u]);
    (to[cnt] = v);
    (head[u] = (cnt++));
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
  static void dfs(int root) {
    (stackSize = 0);
    Code02_Multiply2::push(root, 0, (-1));
    while ((stackSize > 0)) {
      Code02_Multiply2::pop();
      if ((e == (-1))) {
        (deep[u] = (deep[f] + 1));
        (stjump[u][0] = f);
        for (int p = 1; (p <= power); (p++)) {
          (stjump[u][p] = stjump[stjump[u][(p - 1)]][(p - 1)]);
        }
        (e = head[u]);
      } else {
        (e = next[e]);
      }
      if ((e != 0)) {
        Code02_Multiply2::push(u, f, e);
        if ((to[e] != f)) {
          Code02_Multiply2::push(to[e], u, (-1));
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
    for (int p = power; (p >= 0); (p--)) {
      if ((deep[stjump[a][p]] >= deep[b])) {
        (a = stjump[a][p]);
      }
    }
    if ((a == b)) {
      return a;
    }
    for (int p = power; (p >= 0); (p--)) {
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
    int n = static_cast<int>(in.nval);
    in.nextToken();
    int m = static_cast<int>(in.nval);
    in.nextToken();
    int root = static_cast<int>(in.nval);
    Code02_Multiply2::build(n);
    {
      int i = 1;
      int u = {};
      int v = {};
      for (; (i < n); (i++)) {
        in.nextToken();
        (u = static_cast<int>(in.nval));
        in.nextToken();
        (v = static_cast<int>(in.nval));
        Code02_Multiply2::addEdge(u, v);
        Code02_Multiply2::addEdge(v, u);
      }
    }
    Code02_Multiply2::dfs(root);
    {
      int i = 1;
      int a = {};
      int b = {};
      for (; (i <= m); (i++)) {
        in.nextToken();
        (a = static_cast<int>(in.nval));
        in.nextToken();
        (b = static_cast<int>(in.nval));
        out.println(Code02_Multiply2::lca(a, b));
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
  Code02_Multiply2::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 树上倍增解法迭代版
// 测试链接 : https://www.luogu.com.cn/problem/P3379
// 所有递归函数一律改成等义的迭代版
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有用例
        // dfs迭代版
        // ufe是为了实现迭代版而准备的栈
                // 栈里存放三个信息
                // u : 当前处理的点
                // f : 当前点u的父节点
                // e : 处理到几号边了
                // 如果e==-1，表示之前没有处理过u的任何边
                // 如果e==0，表示u的边都已经处理完了
*/

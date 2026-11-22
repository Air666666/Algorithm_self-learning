// 原题测试 / 参考链接（保留上游原始地址）
// http://poj.org/problem?id=1655

// Source: src/class120/Code01_BalancingAct.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_BalancingAct {
  inline static int MAXN = 20001;
  inline static int n = {};
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> next = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> to = make_array<int>(jshl(MAXN, 1));
  inline static int cnt = {};
  inline static Array<int> size = make_array<int>(MAXN);
  inline static int center = {};
  inline static int best = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_BalancingAct() {}
  static void build() {
    (cnt = 1);
    j::fill(head, 1, (n + 1), 0);
    (best = std::numeric_limits<int>::max());
  }
  static void addEdge(int u, int v) {
    (next[cnt] = head[u]);
    (to[cnt] = v);
    (head[u] = (cnt++));
  }
  static void dfs(int u, int f) {
    (size[u] = 1);
    int maxsub = 0;
    {
      int e = head[u];
      int v = {};
      for (; (e != 0); (e = next[e])) {
        (v = to[e]);
        if ((v != f)) {
          Code01_BalancingAct::dfs(v, u);
          (size[u] += size[v]);
          (maxsub = jmax(maxsub, size[v]));
        }
      }
    }
    (maxsub = jmax(maxsub, (n - size[u])));
    if (((maxsub < best) || ((maxsub == best) && (u < center)))) {
      (best = maxsub);
      (center = u);
    }
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    int testCase = static_cast<int>(in.nval);
    for (int t = 1; (t <= testCase); (t++)) {
      in.nextToken();
      (n = static_cast<int>(in.nval));
      Code01_BalancingAct::build();
      {
        int i = 1;
        int u = {};
        int v = {};
        for (; (i < n); (i++)) {
          in.nextToken();
          (u = static_cast<int>(in.nval));
          in.nextToken();
          (v = static_cast<int>(in.nval));
          Code01_BalancingAct::addEdge(u, v);
          Code01_BalancingAct::addEdge(v, u);
        }
      }
      Code01_BalancingAct::dfs(1, 0);
      out.println(((center + String(u" ")) + best));
    }
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code01_BalancingAct::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 平衡行为
// 一共有n个节点，编号1~n，有n-1条边形成一棵树
// 返回重心点，返回重心点最大子树的节点数
// 树的重心第一种求解方式
// 以某个节点为根时，最大子树的节点数最少，那么这个节点是重心
// 测试链接 : http://poj.org/problem?id=1655
// 提交以下的code，提交时请把类名改成"Main"，可以直接通过
        // 当前来到u节点，父亲节点是f
                // 以当前节点u做根节点，最大的子树有多少节点
                // 题目要求找到编号最小的重心
*/

// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/CF219D

// Source: src/class123/Code03_ChooseCapital.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_ChooseCapital {
  inline static int MAXN = 200001;
  inline static int n = {};
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> next = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> to = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> weight = make_array<int>(jshl(MAXN, 1));
  inline static int cnt = {};
  inline static Array<int> reverse = make_array<int>(MAXN);
  inline static Array<int> dp = make_array<int>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_ChooseCapital() {}
  static void build() {
    (cnt = 1);
    j::fill(head, 1, (n + 1), 0);
    j::fill(reverse, 1, (n + 1), 0);
    j::fill(dp, 1, (n + 1), 0);
  }
  static void addEdge(int u, int v, int w) {
    (next[cnt] = head[u]);
    (to[cnt] = v);
    (weight[cnt] = w);
    (head[u] = (cnt++));
  }
  static void dfs1(int u, int f) {
    {
      int e = head[u];
      int v = {};
      int w = {};
      for (; (e != 0); (e = next[e])) {
        (v = to[e]);
        (w = weight[e]);
        if ((v != f)) {
          Code03_ChooseCapital::dfs1(v, u);
          (reverse[u] += (reverse[v] + w));
        }
      }
    }
  }
  static void dfs2(int u, int f) {
    {
      int e = head[u];
      int v = {};
      int w = {};
      for (; (e != 0); (e = next[e])) {
        (v = to[e]);
        (w = weight[e]);
        if ((v != f)) {
          if ((w == 0)) {
            (dp[v] = (dp[u] + 1));
          } else {
            (dp[v] = (dp[u] - 1));
          }
          Code03_ChooseCapital::dfs2(v, u);
        }
      }
    }
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    while ((in.nextToken() != -1)) {
      (n = static_cast<int>(in.nval));
      Code03_ChooseCapital::build();
      {
        int i = 1;
        int u = {};
        int v = {};
        for (; (i < n); (i++)) {
          in.nextToken();
          (u = static_cast<int>(in.nval));
          in.nextToken();
          (v = static_cast<int>(in.nval));
          Code03_ChooseCapital::addEdge(u, v, 0);
          Code03_ChooseCapital::addEdge(v, u, 1);
        }
      }
      Code03_ChooseCapital::dfs1(1, 0);
      (dp[1] = reverse[1]);
      Code03_ChooseCapital::dfs2(1, 0);
      int min = std::numeric_limits<int>::max();
      for (int i = 1; (i <= n); (i++)) {
        if ((min > dp[i])) {
          (min = dp[i]);
        }
      }
      out.println(min);
      for (int i = 1; (i <= n); (i++)) {
        if ((min == dp[i])) {
          out.print((i + String(u" ")));
        }
      }
      out.println();
    }
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code03_ChooseCapital::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 翻转道路数量最少的首都
// 给定一棵n个点的树，但是给定的每条边都是有向的
// 需要选择某个城市为首都，要求首都一定可以去往任何一个城市
// 这样一来，可能需要翻转一些边的方向才能做到，现在想翻转道路的数量尽量少
// 打印最少翻转几条道路就可以拥有首都
// 如果有若干点做首都时，翻转道路的数量都是最少的，那么打印这些点
// 测试链接 : https://www.luogu.com.cn/problem/CF219D
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有用例
        // reverse[u] : u到所有子节点需要逆转的边数
        // dp[u] : u做根到全树节点需要逆转的边数
                                        // 边的方向 : u -> v
                                        // 边的方向 : v -> u
*/

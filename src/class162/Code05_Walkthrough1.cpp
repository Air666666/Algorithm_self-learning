// Source: src/class162/Code05_Walkthrough1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code05_Walkthrough1 {
  inline static int MAXN = 200001;
  inline static int n = {};
  inline static int k = {};
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> next = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> to = make_array<int>(jshl(MAXN, 1));
  inline static int cnt = 0;
  inline static Array<int> fa = make_array<int>(MAXN);
  inline static Array<int> son = make_array<int>(MAXN);
  inline static Array<int> top = make_array<int>(MAXN);
  inline static Array<i64> money = make_array<i64>(MAXN);
  inline static Array<i64> sorted = make_array<i64>(MAXN);
  inline static Array<Array<int>> fse = make_array<int>(MAXN, 3);
  inline static int stacksize = {};
  inline static int first = {};
  inline static int second = {};
  inline static int edge = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code05_Walkthrough1() {}
  static void addEdge(int u, int v) {
    (next[(++cnt)] = head[u]);
    (to[cnt] = v);
    (head[u] = cnt);
  }
  static void dfs1(int u, int f) {
    {
      int e = head[u];
      int v = {};
      for (; (e > 0); (e = next[e])) {
        (v = to[e]);
        if ((v != f)) {
          Code05_Walkthrough1::dfs1(v, u);
        }
      }
    }
    {
      int e = head[u];
      int v = {};
      for (; (e > 0); (e = next[e])) {
        (v = to[e]);
        if ((v != f)) {
          if (((son[u] == 0) || (money[son[u]] < money[v]))) {
            (son[u] = v);
          }
        }
      }
    }
    (fa[u] = f);
    (money[u] = (money[son[u]] + arr[u]));
  }
  static void dfs2(int u, int t) {
    (top[u] = t);
    if ((son[u] == 0)) {
      return;
    }
    Code05_Walkthrough1::dfs2(son[u], t);
    {
      int e = head[u];
      int v = {};
      for (; (e > 0); (e = next[e])) {
        (v = to[e]);
        if (((v != fa[u]) && (v != son[u]))) {
          Code05_Walkthrough1::dfs2(v, v);
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
    Code05_Walkthrough1::push(1, 0, (-1));
    while ((stacksize > 0)) {
      Code05_Walkthrough1::pop();
      if ((edge == (-1))) {
        (edge = head[first]);
      } else {
        (edge = next[edge]);
      }
      if ((edge != 0)) {
        Code05_Walkthrough1::push(first, second, edge);
        if ((to[edge] != second)) {
          Code05_Walkthrough1::push(to[edge], first, (-1));
        }
      } else {
        {
          int e = head[first];
          int v = {};
          for (; (e > 0); (e = next[e])) {
            (v = to[e]);
            if ((v != second)) {
              if (((son[first] == 0) || (money[son[first]] < money[v]))) {
                (son[first] = v);
              }
            }
          }
        }
        (fa[first] = second);
        (money[first] = (money[son[first]] + arr[first]));
      }
    }
  }
  static void dfs4() {
    (stacksize = 0);
    Code05_Walkthrough1::push(1, 1, (-1));
    while ((stacksize > 0)) {
      Code05_Walkthrough1::pop();
      if ((edge == (-1))) {
        (top[first] = second);
        if ((son[first] == 0)) {
          continue;
        }
        Code05_Walkthrough1::push(first, second, (-2));
        Code05_Walkthrough1::push(son[first], second, (-1));
        continue;
      } else if ((edge == (-2))) {
        (edge = head[first]);
      } else {
        (edge = next[edge]);
      }
      if ((edge != 0)) {
        Code05_Walkthrough1::push(first, second, edge);
        if (((to[edge] != fa[first]) && (to[edge] != son[first]))) {
          Code05_Walkthrough1::push(to[edge], to[edge], (-1));
        }
      }
    }
  }
  static i64 compute() {
    int len = 0;
    for (int i = 1; (i <= n); (i++)) {
      if ((top[i] == i)) {
        (sorted[(++len)] = money[i]);
      }
    }
    j::sort(sorted, 1, (len + 1));
    i64 ans = 0;
    {
      int i = 1;
      int j = len;
      for (; (i <= k); (i++), (j--)) {
        (ans += sorted[j]);
      }
    }
    return ans;
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    (n = static_cast<int>(in.nval));
    in.nextToken();
    (k = static_cast<int>(in.nval));
    for (int i = 1; (i <= n); (i++)) {
      in.nextToken();
      (arr[i] = static_cast<int>(in.nval));
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
        Code05_Walkthrough1::addEdge(u, v);
        Code05_Walkthrough1::addEdge(v, u);
      }
    }
    Code05_Walkthrough1::dfs3();
    Code05_Walkthrough1::dfs4();
    out.println(Code05_Walkthrough1::compute());
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code05_Walkthrough1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 攻略，java版
// 一共有n个节点，给定n-1条边，所有节点连成一棵树，每个点给定点权
// 规定1号点是头，任何路径都必须从头开始，然后走到某个叶节点停止
// 路径上的点，点权的累加和，叫做这个路径的收益
// 给定数字k，你可以随意选出k条路径，所有路径经过的点，需要取并集，也就是去重
// 并集中的点，点权的累加和，叫做k条路径的收益
// 打印k条路径的收益最大值
// 1 <= n、k <= 2 * 10^5
// 所有点权都是int类型的正数
// 测试链接 : https://www.luogu.com.cn/problem/P10641
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 链式前向星
        // 长链剖分的改写，根据money的值来标记最值钱儿子
        // 每条链的头节点收益排序
        // 递归版
        // 递归版
        // dfs1的迭代版
        // dfs2的迭代版
*/

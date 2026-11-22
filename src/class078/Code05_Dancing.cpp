// Source: src/class078/Code05_Dancing.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code05_Dancing {
  inline static int MAXN = 6001;
  inline static Array<int> nums = make_array<int>(MAXN);
  inline static Array<bool> boss = make_array<bool>(MAXN);
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> next = make_array<int>(MAXN);
  inline static Array<int> to = make_array<int>(MAXN);
  inline static int cnt = {};
  inline static Array<int> no = make_array<int>(MAXN);
  inline static Array<int> yes = make_array<int>(MAXN);
  inline static int n = {};
  inline static int h = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code05_Dancing() {}
  static void build(int n) {
    j::fill(boss, 1, (n + 1), true);
    j::fill(head, 1, (n + 1), 0);
    (cnt = 1);
  }
  static void addEdge(int u, int v) {
    (next[cnt] = head[u]);
    (to[cnt] = v);
    (head[u] = (cnt++));
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    while ((in.nextToken() != -1)) {
      (n = static_cast<int>(in.nval));
      Code05_Dancing::build(n);
      for (int i = 1; (i <= n); (i++)) {
        in.nextToken();
        (nums[i] = static_cast<int>(in.nval));
      }
      {
        int i = 1;
        int low = {};
        int high = {};
        for (; (i < n); (i++)) {
          in.nextToken();
          (low = static_cast<int>(in.nval));
          in.nextToken();
          (high = static_cast<int>(in.nval));
          Code05_Dancing::addEdge(high, low);
          (boss[low] = false);
        }
      }
      for (int i = 1; (i <= n); (i++)) {
        if (boss[i]) {
          (h = i);
          break;
        }
      }
      Code05_Dancing::f(h);
      out.println(jmax(no[h], yes[h]));
    }
    out.flush();
    out.close();
    br.close();
  }
  static void f(int u) {
    (no[u] = 0);
    (yes[u] = nums[u]);
    {
      int ei = head[u];
      int v = {};
      for (; (ei > 0); (ei = next[ei])) {
        (v = to[ei]);
        Code05_Dancing::f(v);
        (no[u] += jmax(no[v], yes[v]));
        (yes[u] += no[v]);
      }
    }
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code05_Dancing::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 没有上司的舞会
// 某大学有n个职员，编号为1...n
// 他们之间有从属关系，也就是说他们的关系就像一棵以校长为根的树
// 父结点就是子结点的直接上司
// 现在有个周年庆宴会，宴会每邀请来一个职员都会增加一定的快乐指数
// 但是如果某个职员的直接上司来参加舞会了
// 那么这个职员就无论如何也不肯来参加舞会了
// 所以请你编程计算邀请哪些职员可以使快乐指数最大
// 返回最大的快乐指数。
// 测试链接 : https://www.luogu.com.cn/problem/P1352
// 本题和讲解037的题目7类似
// 链式链接 : https://leetcode.cn/problems/house-robber-iii/
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下的code，提交时请把类名改成"Main"，可以直接通过
        // 链式前向星建图
        // 动态规划表
        // no[i] : i为头的整棵树，在i不来的情况下，整棵树能得到的最大快乐值
        // no[i] : i为头的整棵树，在i来的情况下，整棵树能得到的最大快乐值
*/

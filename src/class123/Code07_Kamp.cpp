// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P6419

// Source: src/class123/Code07_Kamp.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code07_Kamp {
  inline static int MAXN = 500001;
  inline static int n = {};
  inline static int k = {};
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> next = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> to = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> weight = make_array<int>(jshl(MAXN, 1));
  inline static int cnt = {};
  inline static Array<int> people = make_array<int>(MAXN);
  inline static Array<i64> incost = make_array<i64>(MAXN);
  inline static Array<i64> inner1 = make_array<i64>(MAXN);
  inline static Array<i64> inner2 = make_array<i64>(MAXN);
  inline static Array<int> choose = make_array<int>(MAXN);
  inline static Array<i64> outcost = make_array<i64>(MAXN);
  inline static Array<i64> outer = make_array<i64>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code07_Kamp() {}
  static void build() {
    (cnt = 1);
    j::fill(head, 1, (n + 1), 0);
    j::fill(people, 1, (n + 1), 0);
    j::fill(incost, 1, (n + 1), 0);
    j::fill(inner1, 1, (n + 1), 0);
    j::fill(inner2, 1, (n + 1), 0);
    j::fill(choose, 1, (n + 1), 0);
    j::fill(outcost, 1, (n + 1), 0);
    j::fill(outer, 1, (n + 1), 0);
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
          Code07_Kamp::dfs1(v, u);
          (people[u] += people[v]);
          if ((people[v] > 0)) {
            (incost[u] += (incost[v] + (static_cast<i64>(w) * 2)));
            if ((inner1[u] < (inner1[v] + w))) {
              (choose[u] = v);
              (inner2[u] = inner1[u]);
              (inner1[u] = (inner1[v] + w));
            } else if ((inner2[u] < (inner1[v] + w))) {
              (inner2[u] = (inner1[v] + w));
            }
          }
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
          if (((k - people[v]) > 0)) {
            if ((people[v] == 0)) {
              (outcost[v] =
                   ((outcost[u] + incost[u]) + (static_cast<i64>(w) * 2)));
            } else {
              (outcost[v] = ((outcost[u] + incost[u]) - incost[v]));
            }
            if ((v != choose[u])) {
              (outer[v] = (jmax(outer[u], inner1[u]) + w));
            } else {
              (outer[v] = (jmax(outer[u], inner2[u]) + w));
            }
          }
          Code07_Kamp::dfs2(v, u);
        }
      }
    }
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    (n = static_cast<int>(in.nval));
    Code07_Kamp::build();
    in.nextToken();
    (k = static_cast<int>(in.nval));
    {
      int i = 1;
      int u = {};
      int v = {};
      int w = {};
      for (; (i < n); (i++)) {
        in.nextToken();
        (u = static_cast<int>(in.nval));
        in.nextToken();
        (v = static_cast<int>(in.nval));
        in.nextToken();
        (w = static_cast<int>(in.nval));
        Code07_Kamp::addEdge(u, v, w);
        Code07_Kamp::addEdge(v, u, w);
      }
    }
    {
      int i = 1;
      int u = {};
      for (; (i <= k); (i++)) {
        in.nextToken();
        (u = static_cast<int>(in.nval));
        (people[u]++);
      }
    }
    Code07_Kamp::dfs1(1, 0);
    Code07_Kamp::dfs2(1, 0);
    for (int i = 1; (i <= n); (i++)) {
      out.println(((incost[i] + outcost[i]) - jmax(inner1[i], outer[i])));
    }
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code07_Kamp::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 聚会后送每个人回家最短用时
// 给定一棵n个点的树，边权代表走过边需要花费的时间
// 给定k个人分别在树上的哪些节点
// 这k个人选择了一个聚会点，所有的人都去往聚会点进行聚会
// 聚会结束后，所有人都会上一辆车，车会把每个人送回家
// 送完最后一个乘客，车不需要回到聚会点
// 如果聚会点在i，请问从聚会地点出发直到送最后一个人回家，最短用时多少
// i = 1 ~ n，打印所有的答案
// 测试链接 : https://www.luogu.com.cn/problem/P6419
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有用例
        // people[i]: i内部，有多少乘客要送
        // incost[i]: i内部，从i出发送完所有乘客回到i的最少代价
        // inner1[i]: i内部，从i出发送乘客的最长链
        // inner2[i]: i内部，从i出发送乘客的次长链
        // 注意 : inner1[i]和inner2[i]所代表的链，一定要来自i的不同儿子
        // choose[i]: 送乘客的最长链来自i的哪个儿子
        // outcost[i]: i外部，从i出发送完所有乘客回到i的最少代价
        // outer[i]: i外部，从i出发送乘客的最长链
*/

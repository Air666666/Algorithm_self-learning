// Source: src/class121/Code05_FireFighting1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code05_FireFighting1 {
  inline static int MAXN = 300001;
  inline static int n = {};
  inline static int s = {};
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> next = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> to = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> weight = make_array<int>(jshl(MAXN, 1));
  inline static int cnt = {};
  inline static int start = {};
  inline static int end = {};
  inline static int diameter = {};
  inline static Array<int> dist = make_array<int>(MAXN);
  inline static Array<int> last = make_array<int>(MAXN);
  inline static Array<int> pred = make_array<int>(MAXN);
  inline static Array<bool> diameterPath = make_array<bool>(MAXN);
  inline static Array<int> maxDist = make_array<int>(MAXN);
  inline static Array<int> queue = make_array<int>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code05_FireFighting1() {}
  static void build() {
    (cnt = 1);
    j::fill(head, 1, (n + 1), 0);
    j::fill(diameterPath, 1, n, false);
  }
  static void addEdge(int u, int v, int w) {
    (next[cnt] = head[u]);
    (to[cnt] = v);
    (weight[cnt] = w);
    (head[u] = (cnt++));
  }
  static void road() {
    Code05_FireFighting1::dfs(1, 0, 0);
    (start = 1);
    for (int i = 2; (i <= n); (i++)) {
      if ((dist[i] > dist[start])) {
        (start = i);
      }
    }
    Code05_FireFighting1::dfs(start, 0, 0);
    (end = 1);
    for (int i = 2; (i <= n); (i++)) {
      if ((dist[i] > dist[end])) {
        (end = i);
      }
    }
    (diameter = dist[end]);
  }
  static void dfs(int u, int f, int w) {
    (last[u] = f);
    (dist[u] = (dist[f] + w));
    (pred[u] = w);
    for (int e = head[u]; (e != 0); (e = next[e])) {
      if ((to[e] != f)) {
        Code05_FireFighting1::dfs(to[e], u, weight[e]);
      }
    }
  }
  static void distance() {
    for (int i = end; (i != 0); (i = last[i])) {
      (diameterPath[i] = true);
    }
    for (int i = end; (i != 0); (i = last[i])) {
      (maxDist[i] = Code05_FireFighting1::maxDistanceExceptDiameter(i, 0, 0));
    }
  }
  static int maxDistanceExceptDiameter(int u, int f, int c) {
    int ans = c;
    {
      int e = head[u];
      int v = {};
      for (; (e != 0); (e = next[e])) {
        (v = to[e]);
        if (((!diameterPath[v]) && (v != f))) {
          (ans = jmax(ans, Code05_FireFighting1::maxDistanceExceptDiameter(
                               v, u, (c + weight[e]))));
        }
      }
    }
    return ans;
  }
  static int compute() {
    int suml = 0;
    int sumr = 0;
    int h = 0;
    int t = 0;
    int ans = std::numeric_limits<int>::max();
    {
      int l = end;
      int r = end;
      for (; (l != 0); (l = last[l])) {
        while (((r != 0) && (((sumr - suml) + pred[r]) <= s))) {
          while (((h < t) && (maxDist[queue[(t - 1)]] <= maxDist[r]))) {
            (t--);
          }
          (sumr += pred[r]);
          (queue[(t++)] = r);
          (r = last[r]);
        }
        (ans =
             jmin(ans, jmax(jmax(suml, maxDist[queue[h]]), (diameter - sumr))));
        if ((queue[h] == l)) {
          (h++);
        }
        (suml += pred[l]);
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
    (s = static_cast<int>(in.nval));
    Code05_FireFighting1::build();
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
        Code05_FireFighting1::addEdge(u, v, w);
        Code05_FireFighting1::addEdge(v, u, w);
      }
    }
    Code05_FireFighting1::road();
    Code05_FireFighting1::distance();
    out.println(Code05_FireFighting1::compute());
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code05_FireFighting1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 消防(递归版)
// 一共n个节点，编号1~n，有n-1条边连接成一棵树，每条边上有非负权值
// 给定一个非负整数s，表示可以在树上选择一条长度不超过s的路径
// 然后在这条路径的点上建立消防站，每个居民可以去往这条路径上的任何消防站
// 目标：哪怕最远的居民走到消防站的距离也要尽量少
// 返回最远居民走到消防站的最短距离
// 测试链接 : https://www.luogu.com.cn/problem/P2491
// 提交以下的code，提交时请把类名改成"Main"
// C++这么写能通过，java会因为递归层数太多而爆栈
// java能通过的写法参考本节课Code05_FireFighting2文件
        // pred[i] : i节点在直径上，和前一个点之间的距离，以start做根
        // 不能走向直径路径上的节点
        // 能走出的最大距离
        // 单调队列维护窗口内最大值
        // 不会的看讲解054
                // 用h和t表示单调队列的头和尾
                // 窗口范围[l,r)，左闭右开，直径上的窗口[l...r-1]
                // l是窗口左端点，r是窗口右端点的再下一个点
                // 课上图解是从start到end，实际是从end到start，思路没有区别
*/

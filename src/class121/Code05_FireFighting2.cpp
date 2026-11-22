// Source: src/class121/Code05_FireFighting2.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code05_FireFighting2 {
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
  inline static Array<Array<int>> ufwe = make_array<int>(MAXN, 4);
  inline static int stackSize = {};
  inline static int u = {};
  inline static int f = {};
  inline static int w = {};
  inline static int e = {};
  inline static Array<int> queue = make_array<int>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code05_FireFighting2() {}
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
    Code05_FireFighting2::dfs(1);
    (start = 1);
    for (int i = 2; (i <= n); (i++)) {
      if ((dist[i] > dist[start])) {
        (start = i);
      }
    }
    Code05_FireFighting2::dfs(start);
    (end = 1);
    for (int i = 2; (i <= n); (i++)) {
      if ((dist[i] > dist[end])) {
        (end = i);
      }
    }
    (diameter = dist[end]);
  }
  static void push(int u, int f, int w, int e) {
    (ufwe[stackSize][0] = u);
    (ufwe[stackSize][1] = f);
    (ufwe[stackSize][2] = w);
    (ufwe[stackSize][3] = e);
    (stackSize++);
  }
  static void pop() {
    (--stackSize);
    (u = ufwe[stackSize][0]);
    (f = ufwe[stackSize][1]);
    (w = ufwe[stackSize][2]);
    (e = ufwe[stackSize][3]);
  }
  static void dfs(int root) {
    (stackSize = 0);
    Code05_FireFighting2::push(root, 0, 0, (-1));
    while ((stackSize > 0)) {
      Code05_FireFighting2::pop();
      if ((e == (-1))) {
        (last[u] = f);
        (dist[u] = (dist[f] + w));
        (pred[u] = w);
        (e = head[u]);
      } else {
        (e = next[e]);
      }
      if ((e != 0)) {
        Code05_FireFighting2::push(u, f, w, e);
        if ((to[e] != f)) {
          Code05_FireFighting2::push(to[e], u, weight[e], (-1));
        }
      }
    }
  }
  static void distance() {
    for (int i = end; (i != 0); (i = last[i])) {
      (diameterPath[i] = true);
    }
    for (int i = end; (i != 0); (i = last[i])) {
      (maxDist[i] = Code05_FireFighting2::maxDistanceExceptDiameter(i, 0, 0));
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
          (ans = jmax(ans, Code05_FireFighting2::maxDistanceExceptDiameter(
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
        while (((r != 0) && (((sumr + pred[r]) - suml) <= s))) {
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
    Code05_FireFighting2::build();
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
        Code05_FireFighting2::addEdge(u, v, w);
        Code05_FireFighting2::addEdge(v, u, w);
      }
    }
    Code05_FireFighting2::road();
    Code05_FireFighting2::distance();
    out.println(Code05_FireFighting2::compute());
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code05_FireFighting2::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 消防(迭代版)
// 一共n个节点，编号1~n，有n-1条边连接成一棵树，每条边上有非负权值
// 给定一个非负整数s，表示可以在树上选择一条长度不超过s的路径
// 然后在这条路径的点上建立消防站，每个居民可以去往这条路径上的任何消防站
// 目标：哪怕最远的居民走到消防站的距离也要尽量少
// 返回最远居民走到消防站的最短距离
// 测试链接 : https://www.luogu.com.cn/problem/P2491
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有用例
        // dfs方法改迭代版
        // 不会改，看讲解118，讲了怎么从递归版改成迭代版
        // maxDistanceExceptDiameter方法不用改迭代居然能通过
        // 那就不改了
*/

// Source: src/class188/Code11_DingXiangRoad1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code11_DingXiangRoad1 {
  struct EdgeCmp;
  struct EdgeCmp {
    String toString() const { return j::str(static_cast<const void *>(this)); }
    EdgeCmp() {}
    int compare(Array<int> e1, Array<int> e2) {
      if ((e1[2] != e2[2])) {
        return (e1[2] - e2[2]);
      }
      if ((e1[0] != e2[0])) {
        return (e1[0] - e2[0]);
      }
      return (e1[1] - e2[1]);
    }
  };
  inline static int MAXN = 3001;
  inline static int MAXM = 3000001;
  inline static int n = {};
  inline static int m = {};
  inline static int s = {};
  inline static Array<int> a = make_array<int>(MAXM);
  inline static Array<int> b = make_array<int>(MAXM);
  inline static Array<bool> fix = make_array<bool>(MAXN);
  inline static JSet<int> nodeSet = JSet<int>();
  inline static Array<int> nodeArr = make_array<int>(MAXN);
  inline static int cnt = {};
  inline static Array<int> fa1 = make_array<int>(MAXN);
  inline static Array<int> deg1 = make_array<int>(MAXN);
  inline static Array<int> fa2 = make_array<int>(MAXN);
  inline static Array<int> deg2 = make_array<int>(MAXN);
  inline static Array<Array<int>> edgeArr = make_array<int>(MAXN, 3);
  inline static i64 sum = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code11_DingXiangRoad1() {}
  static int dist(int x, int y) { return std::abs((x - y)); }
  static int find(Array<int> fa, int x) {
    if ((x != fa[x])) {
      (fa[x] = Code11_DingXiangRoad1::find(fa, fa[x]));
    }
    return fa[x];
  }
  static void union_method(Array<int> fa, int x, int y) {
    int fx = Code11_DingXiangRoad1::find(fa, x);
    int fy = Code11_DingXiangRoad1::find(fa, y);
    if ((fx != fy)) {
      (fa[fx] = fy);
    }
  }
  static i64 kruskal() {
    i64 cost = 0;
    int edgeCnt = (cnt - 1);
    j::sort(edgeArr, 1, (edgeCnt + 1), new EdgeCmp());
    for (int i = 1; (i <= edgeCnt); (i++)) {
      int u = edgeArr[i][0];
      int v = edgeArr[i][1];
      int w = edgeArr[i][2];
      if ([&]() {
            auto jleft = Code11_DingXiangRoad1::find(fa2, u);
            auto jright = Code11_DingXiangRoad1::find(fa2, v);
            return (jleft != jright);
          }()) {
        (cost += (w * 2));
        Code11_DingXiangRoad1::union_method(fa2, u, v);
      }
    }
    return cost;
  }
  static i64 compute(int start, int end) {
    (cnt = 0);
    for (int x : nodeSet) {
      (nodeArr[(++cnt)] = x);
    }
    for (int i = 1; (i <= n); (i++)) {
      (fa2[i] = Code11_DingXiangRoad1::find(fa1, i));
      (deg2[i] = deg1[i]);
    }
    i64 ans = sum;
    (deg2[start]++);
    (deg2[end]++);
    Code11_DingXiangRoad1::union_method(fa2, start, end);
    {
      int i = 1;
      int p = 0;
      for (; (i <= cnt); (i++)) {
        if (((deg2[nodeArr[i]] & 1) == 1)) {
          if ((p == 0)) {
            (p = i);
          } else {
            (ans += Code11_DingXiangRoad1::dist(nodeArr[p], nodeArr[i]));
            while ((p < i)) {
              Code11_DingXiangRoad1::union_method(fa2, nodeArr[(p++)],
                                                  nodeArr[i]);
            }
            (p = 0);
          }
        }
      }
    }
    for (int i = 1; (i <= (cnt - 1)); (i++)) {
      (edgeArr[i][0] = nodeArr[i]);
      (edgeArr[i][1] = nodeArr[(i + 1)]);
      (edgeArr[i][2] = (nodeArr[(i + 1)] - nodeArr[i]));
    }
    (ans += Code11_DingXiangRoad1::kruskal());
    return ans;
  }
  static void prepare() {
    (fix[s] = true);
    nodeSet.add(s);
    (sum = 0);
    for (int i = 1; (i <= n); (i++)) {
      (fa1[i] = i);
    }
    {
      int i = 1;
      int u = {};
      int v = {};
      for (; (i <= m); (i++)) {
        (u = a[i]);
        (v = b[i]);
        (deg1[u]++);
        (deg1[v]++);
        (fix[u] = true);
        (fix[v] = true);
        nodeSet.add(u);
        nodeSet.add(v);
        Code11_DingXiangRoad1::union_method(fa1, u, v);
        (sum += Code11_DingXiangRoad1::dist(u, v));
      }
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (m = in.nextInt());
    (s = in.nextInt());
    for (int i = 1; (i <= m); (i++)) {
      (a[i] = in.nextInt());
      (b[i] = in.nextInt());
    }
    Code11_DingXiangRoad1::prepare();
    for (int i = 1; (i <= n); (i++)) {
      if ((!fix[i])) {
        nodeSet.add(i);
      }
      out.print((Code11_DingXiangRoad1::compute(s, i) + String(u" ")));
      if ((!fix[i])) {
        nodeSet.remove(i);
      }
    }
    out.println();
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code11_DingXiangRoad1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 丁香之路，java版
// 一共有n个点，点i和点j的距离为|i - j|，所以这是完全图，边是无向边
// 给定m个点对，每个点对(a, b)，保证 a != b，表示a和b之间的无向边做了标记
// 给定起点s，不管终点是什么，每条被标记的无向边，走过至少一次
// 打印起点s，终点i的情况下，走过路程的最小距离是多少
// 终点i可以是1~n中的任意一点，所以一共打印n个数值
// 1 <= n <= 2500
// m <= n个顶点的完全图的边数
// 测试链接 : https://www.luogu.com.cn/problem/P6628
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // u、v、w
        // 读写工具类
*/

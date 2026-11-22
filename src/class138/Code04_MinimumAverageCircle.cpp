// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P3199

// Source: src/class138/Code04_MinimumAverageCircle.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_MinimumAverageCircle {
  inline static int MAXN = 3001;
  inline static int MAXM = 10001;
  inline static double MAXE = 1e7;
  inline static double sml = 1e-9;
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> next = make_array<int>(MAXM);
  inline static Array<int> to = make_array<int>(MAXM);
  inline static Array<double> weight = make_array<double>(MAXM);
  inline static int cnt = {};
  inline static Array<double> value = make_array<double>(MAXN);
  inline static Array<bool> path = make_array<bool>(MAXN);
  inline static int n = {};
  inline static int m = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_MinimumAverageCircle() {}
  static void prepare() {
    (cnt = 1);
    j::fill(head, 1, (n + 1), 0);
  }
  static void addEdge(int u, int v, double w) {
    (next[cnt] = head[u]);
    (to[cnt] = v);
    (weight[cnt] = w);
    (head[u] = (cnt++));
  }
  static bool check(double x) {
    j::fill(value, 1, (n + 1), 0);
    j::fill(path, 1, (n + 1), false);
    return Code04_MinimumAverageCircle::dfs(0, x);
  }
  static bool dfs(int u, double x) {
    if ((u == 0)) {
      for (int i = 1; (i <= n); (i++)) {
        if (Code04_MinimumAverageCircle::dfs(i, x)) {
          return true;
        }
      }
    } else {
      (path[u] = true);
      for (int e = head[u]; (e != 0); (e = next[e])) {
        int v = to[e];
        double w = (weight[e] - x);
        if ((value[v] > (value[u] + w))) {
          (value[v] = (value[u] + w));
          if ((path[v] || Code04_MinimumAverageCircle::dfs(v, x))) {
            return true;
          }
        }
      }
      (path[u] = false);
    }
    return false;
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    (n = static_cast<int>(in.nval));
    in.nextToken();
    (m = static_cast<int>(in.nval));
    Code04_MinimumAverageCircle::prepare();
    for (int i = 1; (i <= m); (i++)) {
      in.nextToken();
      int u = static_cast<int>(in.nval);
      in.nextToken();
      int v = static_cast<int>(in.nval);
      in.nextToken();
      double w = in.nval;
      Code04_MinimumAverageCircle::addEdge(u, v, w);
    }
    double l = (-MAXE);
    double r = MAXE;
    double x = {};
    double ans = 0;
    while (((l < r) && ((r - l) >= sml))) {
      (x = jdiv((l + r), 2));
      if (Code04_MinimumAverageCircle::check(x)) {
        (r = (x - sml));
      } else {
        (ans = x);
        (l = (x + sml));
      }
    }
    out.printf(String(u"%.8f\n"), ans);
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code04_MinimumAverageCircle::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 最小圈
// 一共有n个节点，m条有向边，每条边有权值
// 这个有向带权图中，可能有若干环，规定环的平均值为
// 环中边的权值和 / 环中边的数量
// 返回所有环的平均值中最少的平均值，结果保留小数点后8位，其余部分舍弃
// 1 <= n <= 3000
// 1 <= m <= 10000
// -10^7 <= 边权 <= 10^7
// 测试链接 : https://www.luogu.com.cn/problem/P3199
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 链式前向星
        // dfs判断负环，每个点的累积边权
        // dfs判断负环，每个点是否是递归路径上的点
        // 所有边都减去x，返回图中是否存在负环
        // 其实就是spfa的递归版，时间复杂度O(n * m)
                        // 认为0号点是超级源点，具有通往所有点的有向边
                                // 只有v的累积边权变小，才会递归，非常强的剪枝
                                //
如果递归路径回到v，并且此时是v的累积边权更小的情况，说明遇到了负环
                                // 或者后续递归找到了负环
                                // 直接返回true
*/

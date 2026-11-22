// Source: src/class138/Other3.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Other3 {
  inline static int MAXN = 1001;
  inline static Array<int> x = make_array<int>(MAXN);
  inline static Array<int> y = make_array<int>(MAXN);
  inline static Array<int> z = make_array<int>(MAXN);
  inline static Array<Array<double>> dist = make_array<double>(MAXN, MAXN);
  inline static Array<Array<double>> cost = make_array<double>(MAXN, MAXN);
  inline static Array<bool> visit = make_array<bool>(MAXN);
  inline static Array<double> value = make_array<double>(MAXN);
  inline static int n = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Other3() {}
  static double prim(double x) {
    for (int i = 1; (i <= n); (i++)) {
      (visit[i] = false);
      (value[i] = (cost[1][i] - (x * dist[1][i])));
    }
    (visit[1] = true);
    double sum = 0;
    for (int i = 1; (i <= (n - 1)); (i++)) {
      double minDist = std::numeric_limits<double>::max();
      int next = 0;
      for (int j = 1; (j <= n); (j++)) {
        if (((!visit[j]) && (value[j] < minDist))) {
          (minDist = value[j]);
          (next = j);
        }
      }
      (sum += minDist);
      (visit[next] = true);
      for (int j = 1; (j <= n); (j++)) {
        if (((!visit[j]) &&
             (value[j] > (cost[next][j] - (x * dist[next][j]))))) {
          (value[j] = (cost[next][j] - (x * dist[next][j])));
        }
      }
    }
    return sum;
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    (n = static_cast<int>(in.nval));
    while ((n != 0)) {
      for (int i = 1; (i <= n); (i++)) {
        in.nextToken();
        (x[i] = static_cast<int>(in.nval));
        in.nextToken();
        (y[i] = static_cast<int>(in.nval));
        in.nextToken();
        (z[i] = static_cast<int>(in.nval));
      }
      for (int i = 1; (i <= n); (i++)) {
        for (int j = 1; (j <= n); (j++)) {
          if ((i != j)) {
            (dist[i][j] = std::sqrt((((x[i] - x[j]) * (x[i] - x[j])) +
                                     ((y[i] - y[j]) * (y[i] - y[j])))));
            (cost[i][j] = std::abs((z[i] - z[j])));
          }
        }
      }
      double l = 0;
      double r = 100;
      double x = {};
      for (int i = 1; (i <= 60); (i++)) {
        (x = jdiv((l + r), 2));
        if ((Other3::prim(x) <= 0)) {
          (r = x);
        } else {
          (l = x);
        }
      }
      out.printf(String(u"%.3f\n"), l);
      in.nextToken();
      (n = static_cast<int>(in.nval));
    }
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Other3::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 题目3，最优比率生成树，另一种二分的写法
// 思路是不变的，二分的写法多种多样
// 代码中打注释的位置，就是更简单的二分逻辑，其他代码没有变化
// 测试链接 : http://poj.org/problem?id=2728
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
                        // 二分进行60次，足够达到题目要求的精度
                        // 二分完成后，l就是答案
*/

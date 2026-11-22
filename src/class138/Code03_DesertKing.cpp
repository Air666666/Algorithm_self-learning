// 原题测试 / 参考链接（保留上游原始地址）
// http://poj.org/problem?id=2728

// Source: src/class138/Code03_DesertKing.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_DesertKing {
  inline static int MAXN = 1001;
  inline static double sml = 1e-6;
  inline static Array<int> x = make_array<int>(MAXN);
  inline static Array<int> y = make_array<int>(MAXN);
  inline static Array<int> z = make_array<int>(MAXN);
  inline static Array<Array<double>> dist = make_array<double>(MAXN, MAXN);
  inline static Array<Array<double>> cost = make_array<double>(MAXN, MAXN);
  inline static Array<bool> visit = make_array<bool>(MAXN);
  inline static Array<double> value = make_array<double>(MAXN);
  inline static int n = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_DesertKing() {}
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
      double ans = 0;
      while (((l < r) && ((r - l) >= sml))) {
        (x = jdiv((l + r), 2));
        if ((Code03_DesertKing::prim(x) <= 0)) {
          (ans = x);
          (r = (x - sml));
        } else {
          (l = (x + sml));
        }
      }
      out.printf(String(u"%.3f\n"), ans);
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
  Code03_DesertKing::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 最优比率生成树
// 一共有n个村庄，每个村庄由(x, y, z)表示
// 其中(x,y)代表村庄在二维地图中的位置，z代表其海拔高度
// 任意两个村庄之间的距离就是二维地图中的欧式距离
// 任意两个村庄之间的修路花费就是海拔差值的绝对值
// 现在想把所有村庄连通起来，希望修路的条数尽量少，同时希望让
// 总花费 /
总距离，这个比值尽量小，返回最小的比值是多少，结果保留小数点后3位其余部分舍弃
// 2 <= n <= 10^3
// 0 <= x、y <= 10^4
// 0 <= z <= 10^7
// 测试链接 : http://poj.org/problem?id=2728
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 邻接矩阵结构下的prim算法，从节点1出发得到最小生成树的权值和
                // 结余值做边权，进而统计距离
                // 距离只和边权有关，原始的dist、cost不重要
                // 从1号点出发，更新到所有点的距离，也就是value数组
                //
最小生成树一定有n-1条边，所以一共有n-1轮解锁，每次解锁新的点进入最小生成树的点集
                        //
在没有解锁的点中，找到离最小生成树的点集最近的点，进行解锁
                        //
最小的边进入最小生成树的边集，解锁的点进入最小生成树的点集
                        // 查看新的解锁点能不能拉进其他点的距离
                // 返回最小生成树的权值和
                                // 如果最小生成树的权值 <=
0，达标，左侧二分找寻更小比值
                                // 如果最小生成树的权值 >
0，不达标，右侧二分找寻更大比值
*/

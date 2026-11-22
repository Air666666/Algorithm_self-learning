// Source: src/class061/Code03_Water_Luogu.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_Water_Luogu {
  inline static int MAXN = 301;
  inline static int MAXM = 100001;
  inline static int n = {};
  inline static Array<int> cost = make_array<int>(MAXN);
  inline static Array<Array<int>> mat = make_array<int>(MAXN, MAXN);
  inline static Array<Array<int>> edges = make_array<int>(MAXM, 3);
  inline static Array<int> father = make_array<int>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_Water_Luogu() {}
  static int find(int i) {
    if ((i != father[i])) {
      (father[i] = Code03_Water_Luogu::find(father[i]));
    }
    return father[i];
  }
  static bool union_method(int x, int y) {
    int fx = Code03_Water_Luogu::find(x);
    int fy = Code03_Water_Luogu::find(y);
    if ((fx != fy)) {
      (father[fx] = fy);
      return true;
    } else {
      return false;
    }
  }
  static int compute() {
    for (int i = 0; (i <= n); (i++)) {
      (father[i] = i);
    }
    int cnt = 0;
    for (int i = 1; (i <= n); (i++)) {
      (edges[(++cnt)][0] = 0);
      (edges[cnt][1] = i);
      (edges[cnt][2] = cost[i]);
    }
    for (int i = 1; (i <= n); (i++)) {
      for (int j = (i + 1); (j <= n); (j++)) {
        (edges[(++cnt)][0] = i);
        (edges[cnt][1] = j);
        (edges[cnt][2] = mat[i][j]);
      }
    }
    j::sort(edges, 1, (cnt + 1),
            [=](Array<int> a, Array<int> b) { return (a[2] - b[2]); });
    int ans = 0;
    for (int i = 1; (i <= cnt); (i++)) {
      if (Code03_Water_Luogu::union_method(edges[i][0], edges[i][1])) {
        (ans += edges[i][2]);
      }
    }
    return ans;
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    for (int i = 1; (i <= n); (i++)) {
      (cost[i] = in.nextInt());
    }
    for (int i = 1; (i <= n); (i++)) {
      for (int j = 1; (j <= n); (j++)) {
        (mat[i][j] = in.nextInt());
      }
    }
    int ans = Code03_Water_Luogu::compute();
    out.println(ans);
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code03_Water_Luogu::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 水井
// 本题就是题目3，题意是一样的，来自洛谷的测试
// 一共n个田地，给定长度为n的数组cost，cost[i]表示在i号田地打井的花费
// 给定n * n的矩阵mat，mat[i][j]表示i号田地和j号田地连通的花费
// 题目保证 mat[i][j] == mat[j][i]
// 如果某个田地打了井，那么认为该田地有水可用
// 或者某个田地和有水可用的田地连通，也认为该田地有水可用
// 打印让所有田地都有水可用，最小的花费
// 1 <= n <= 300
// 0 <= 花费 <= 10^5
// 测试链接 : https://www.luogu.com.cn/problem/P1550
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 题目输入
        // 端点u、端点v、边权w
        // 并查集
                // 节点0是虚拟水源，连接0和i的边表示在i号田地打井，边权为cost[i]
                // 根据给定的连通代价，去生成其他的边
                // 边按照权值排序
        // 读写工具类
*/

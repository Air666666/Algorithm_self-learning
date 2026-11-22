// Source: src/class065/Code02_Floyd.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_Floyd {
  inline static int MAXN = 101;
  inline static int MAXM = 10001;
  inline static Array<int> path = make_array<int>(MAXM);
  inline static Array<Array<int>> distance = make_array<int>(MAXN, MAXN);
  inline static int n = {};
  inline static int m = {};
  inline static int ans = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_Floyd() {}
  static void build() {
    for (int i = 0; (i < n); (i++)) {
      for (int j = 0; (j < n); (j++)) {
        (distance[i][j] = std::numeric_limits<int>::max());
      }
    }
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    while ((in.nextToken() != -1)) {
      (n = static_cast<int>(in.nval));
      in.nextToken();
      (m = static_cast<int>(in.nval));
      for (int i = 0; (i < m); (i++)) {
        in.nextToken();
        (path[i] = (static_cast<int>(in.nval) - 1));
      }
      Code02_Floyd::build();
      for (int i = 0; (i < n); (i++)) {
        for (int j = 0; (j < n); (j++)) {
          in.nextToken();
          (distance[i][j] = static_cast<int>(in.nval));
        }
      }
      Code02_Floyd::floyd();
      (ans = 0);
      for (int i = 1; (i < m); (i++)) {
        (ans += distance[path[(i - 1)]][path[i]]);
      }
      out.println(ans);
    }
    out.flush();
    out.close();
    br.close();
  }
  static void floyd() {
    for (int bridge = 0; (bridge < n); (bridge++)) {
      for (int i = 0; (i < n); (i++)) {
        for (int j = 0; (j < n); (j++)) {
          if ((((distance[i][bridge] != std::numeric_limits<int>::max()) &&
                (distance[bridge][j] != std::numeric_limits<int>::max())) &&
               (distance[i][j] >
                (distance[i][bridge] + distance[bridge][j])))) {
            (distance[i][j] = (distance[i][bridge] + distance[bridge][j]));
          }
        }
      }
    }
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code02_Floyd::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// Floyd算法模版（洛谷）
// 测试链接 : https://www.luogu.com.cn/problem/P2910
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下所有代码，把主类名改成Main，可以直接通过
        // 初始时设置任意两点之间的最短距离为无穷大，表示任何路不存在
                        // 这道题给的图是邻接矩阵的形式
                        // 任意两点之间的边权都会给定
                        // 所以显得distance初始化不太必要
                        // 但是一般情况下，distance初始化一定要做
                // O(N^3)的过程
                // 枚举每个跳板
                // 注意，跳板要最先枚举！跳板要最先枚举！跳板要最先枚举！
                                        // i -> .....bridge .... -> j
                                        // distance[i][j]能不能缩短
                                        // distance[i][j] = min ( distance[i][j]
, distance[i][bridge] + distance[bridge][j])
*/

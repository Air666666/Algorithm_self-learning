// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P2962

// Source: src/class134/Code02_MinimumOperations.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_MinimumOperations {
  inline static int MAXN = 37;
  inline static Array<Array<int>> mat = make_array<int>(MAXN, MAXN);
  inline static Array<int> op = make_array<int>(MAXN);
  inline static int n = {};
  inline static int ans = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_MinimumOperations() {}
  static void prepare() {
    for (int i = 1; (i <= n); (i++)) {
      for (int j = 1; (j <= n); (j++)) {
        (mat[i][j] = 0);
      }
      (mat[i][i] = 1);
      (mat[i][(n + 1)] = 1);
      (op[i] = 0);
    }
  }
  static void gauss(int n) {
    for (int i = 1; (i <= n); (i++)) {
      for (int j = 1; (j <= n); (j++)) {
        if (((j < i) && (mat[j][j] == 1))) {
          continue;
        }
        if ((mat[j][i] == 1)) {
          Code02_MinimumOperations::swap(i, j);
          break;
        }
      }
      if ((mat[i][i] == 1)) {
        for (int j = 1; (j <= n); (j++)) {
          if (((i != j) && (mat[j][i] == 1))) {
            for (int k = i; (k <= (n + 1)); (k++)) {
              (mat[j][k] ^= mat[i][k]);
            }
          }
        }
      }
    }
  }
  static void swap(int a, int b) {
    Array<int> tmp = mat[a];
    (mat[a] = mat[b]);
    (mat[b] = tmp);
  }
  static void dfs(int i, int num) {
    if ((num >= ans)) {
      return;
    }
    if ((i == 0)) {
      (ans = num);
    } else {
      if ((mat[i][i] == 0)) {
        (op[i] = 0);
        Code02_MinimumOperations::dfs((i - 1), num);
        (op[i] = 1);
        Code02_MinimumOperations::dfs((i - 1), (num + 1));
      } else {
        int cur = mat[i][(n + 1)];
        for (int j = (i + 1); (j <= n); (j++)) {
          if ((mat[i][j] == 1)) {
            (cur ^= op[j]);
          }
        }
        Code02_MinimumOperations::dfs((i - 1), (num + cur));
      }
    }
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    (n = static_cast<int>(in.nval));
    Code02_MinimumOperations::prepare();
    in.nextToken();
    int m = static_cast<int>(in.nval);
    {
      int i = 1;
      int u = {};
      int v = {};
      for (; (i <= m); (i++)) {
        in.nextToken();
        (u = static_cast<int>(in.nval));
        in.nextToken();
        (v = static_cast<int>(in.nval));
        (mat[u][v] = 1);
        (mat[v][u] = 1);
      }
    }
    Code02_MinimumOperations::gauss(n);
    int sign = 1;
    for (int i = 1; (i <= n); (i++)) {
      if ((mat[i][i] == 0)) {
        (sign = 0);
        break;
      }
    }
    if ((sign == 1)) {
      (ans = 0);
      for (int i = 1; (i <= n); (i++)) {
        if ((mat[i][(n + 1)] == 1)) {
          (ans++);
        }
      }
    } else {
      (ans = n);
      Code02_MinimumOperations::dfs(n, 0);
    }
    out.println(ans);
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code02_MinimumOperations::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 全变成1的最少操作次数
// 一共有n个点，m条无向边，每个点的初始状态都是0
// 可以操作任意一个点，操作后该点以及相邻点的状态都会改变
// 最终是希望所有点都变成1状态，那么可能会若干方案都可以做到
// 那么其中存在需要最少操作次数的方案，打印这个最少操作次数
// 题目保证一定能做到所有点都变成1状态，并且没有重边和自环
// 1 <= n <= 35
// 1 <= m <= 595
// 测试链接 : https://www.luogu.com.cn/problem/P2962
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 高斯消元解决异或方程组模版
                                // 当前是自由元
                                // 自由元一定不依赖主元
                                // 自由元也一定不依赖其他自由元
                                // 所以当前自由元一定可以自行决定要不要操作
                                // 当前是主元
                                // 主元可能被其他自由元影响
                                // 而且一定有，当前主元的编号 <
影响它的自由元编号
                                //
所以会影响当前主元的自由元们，一定已经确定了要不要操作
                                // 那么当前主元要不要操作，也就确定了
                        // 唯一解
                        // 多解
*/

// Source: src/class129/Code02_RanAway.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_RanAway {
  inline static int MAXN = 61;
  inline static int MAXP = 64;
  inline static int NA = std::numeric_limits<int>::max();
  inline static Array<Array<Array<bool>>> st =
      make_array<bool>(MAXN, MAXN, (MAXP + 1));
  inline static Array<Array<int>> time = make_array<int>(MAXN, MAXN);
  inline static int n = {};
  inline static int m = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_RanAway() {}
  static void build() {
    for (int i = 1; (i <= n); (i++)) {
      for (int j = 1; (j <= n); (j++)) {
        (st[i][j][0] = false);
        (time[i][j] = NA);
      }
    }
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    (n = static_cast<int>(in.nval));
    Code02_RanAway::build();
    in.nextToken();
    (m = static_cast<int>(in.nval));
    {
      int i = 1;
      int u = {};
      int v = {};
      for (; (i <= m); (i++)) {
        in.nextToken();
        (u = static_cast<int>(in.nval));
        in.nextToken();
        (v = static_cast<int>(in.nval));
        (st[u][v][0] = true);
        (time[u][v] = 1);
      }
    }
    out.println(Code02_RanAway::compute());
    out.flush();
    out.close();
    br.close();
  }
  static int compute() {
    for (int p = 1; (p <= MAXP); (p++)) {
      for (int jump = 1; (jump <= n); (jump++)) {
        for (int i = 1; (i <= n); (i++)) {
          for (int j = 1; (j <= n); (j++)) {
            if ((st[i][jump][(p - 1)] && st[jump][j][(p - 1)])) {
              (st[i][j][p] = true);
              (time[i][j] = 1);
            }
          }
        }
      }
    }
    if ((time[1][n] != 1)) {
      for (int jump = 1; (jump <= n); (jump++)) {
        for (int i = 1; (i <= n); (i++)) {
          for (int j = 1; (j <= n); (j++)) {
            if (((time[i][jump] != NA) && (time[jump][j] != NA))) {
              (time[i][j] = jmin(time[i][j], (time[i][jump] + time[jump][j])));
            }
          }
        }
      }
    }
    return time[1][n];
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code02_RanAway::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 跑路
// 一共有n个节点，编号1~n，一共有m条有向边，每条边1公里
// 有一个空间跑路器，每秒你都可以直接移动2^k公里，每秒钟可以随意决定k的值
// 题目保证1到n之间一定可以到达，返回1到n最少用几秒
// 2 <= n <= 50
// m <= 10^4
// k <= 64
// 测试链接 : https://www.luogu.com.cn/problem/P1613
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有用例
        // st[i][j][p] : i到j的距离是不是2^p
        // time[i][j] : i到j的最短时间
        // 需要先掌握，讲解065 - Floyd算法
                // 先枚举次方
                // 再枚举跳板
                // 最后枚举每一组(i,j)
                        // 先枚举跳板
                        // 最后枚举每一组(i,j)
*/

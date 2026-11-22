// Source: src/class132/Code02_SoldierPosition1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_SoldierPosition1 {
  inline static int MAXN = 100;
  inline static int MAXM = 10;
  inline static int MAXS = 60;
  inline static Array<Array<int>> grid = make_array<int>(MAXN, MAXM);
  inline static Array<Array<Array<int>>> dp = make_array<int>(MAXN, MAXS, MAXS);
  inline static Array<int> sta = make_array<int>(MAXS);
  inline static int n = {};
  inline static int m = {};
  inline static int k = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_SoldierPosition1() {}
  static void java_main(Array<String> args) {
    IO io = IO();
    (n = io.nextInt());
    (m = io.nextInt());
    (k = 0);
    Array<jchar> line = {};
    for (int i = 0; (i < n); (i++)) {
      (line = io.next().toCharArray());
      for (int j = 0; (j < m); (j++)) {
        (grid[i][j] = ((line[j] == u'H') ? 0 : 1));
      }
    }
    Code02_SoldierPosition1::prepare(0, 0);
    io.println(Code02_SoldierPosition1::compute());
    io.flush();
    io.close();
  }
  static void prepare(int j, int s) {
    if ((j >= m)) {
      (sta[(k++)] = s);
    } else {
      Code02_SoldierPosition1::prepare((j + 1), s);
      Code02_SoldierPosition1::prepare((j + 3), (s | jshl(1, j)));
    }
  }
  static int compute() {
    {
      int a = 0;
      int cnt = {};
      for (; (a < k); (a++)) {
        (cnt = Code02_SoldierPosition1::cnt(0, sta[a]));
        (dp[0][a][0] = cnt);
      }
    }
    for (int i = 1; (i < n); (i++)) {
      {
        int a = 0;
        int cnt = {};
        for (; (a < k); (a++)) {
          (cnt = Code02_SoldierPosition1::cnt(i, sta[a]));
          for (int b = 0; (b < k); (b++)) {
            if (((sta[a] & sta[b]) == 0)) {
              for (int c = 0; (c < k); (c++)) {
                if ((((sta[b] & sta[c]) == 0) && ((sta[a] & sta[c]) == 0))) {
                  (dp[i][a][b] = jmax(dp[i][a][b], (dp[(i - 1)][b][c] + cnt)));
                }
              }
            }
          }
        }
      }
    }
    int ans = 0;
    for (int a = 0; (a < k); (a++)) {
      for (int b = 0; (b < k); (b++)) {
        (ans = jmax(ans, dp[(n - 1)][a][b]));
      }
    }
    return ans;
  }
  static int cnt(int i, int s) {
    int ans = 0;
    for (int j = 0; (j < m); (j++)) {
      if ((((jshr(s, j) & 1) == 1) && (grid[i][j] == 1))) {
        (ans++);
      }
    }
    return ans;
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code02_SoldierPosition1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 炮兵阵地
// 给定一个n * m的二维数组grid，其中的1代表可以摆放炮兵，0代表不可以摆放
// 任何炮兵攻击范围是一个"十字型"的区域，具体是上下左右两个格子的区域
// 你的目的是在gird里摆尽量多的炮兵，但要保证任何两个炮兵之间无法互相攻击
// 返回最多能摆几个炮兵
// 1 <= n <= 100
// 1 <= m <= 10
// 0 <= grid[i][j] <= 1
// 测试链接 : https://www.luogu.com.cn/problem/P2704
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
//	// 打印num第m-1位到第0位的二进制状态
//	public static void printBinary(int num) {
//		for (int i = m - 1; i >= 0; i--) {
//			System.out.print((num & (1 << i)) == 0 ? "0" : "1");
//		}
//		System.out.println();
//	}
//		m = 10;
//		k = 0;
//		prepare(0, 0);
//		for (int i = 0; i < k; i++) {
//			printBinary(sta[i]);
//		}
//		System.out.println("有效状态数量 : " + k);
        // 第i行士兵状态为s，结合grid第i号的状况
        // 返回摆放士兵的数量
        // Kattio类IO效率很好，但还是不如StreamTokenizer
        // 只有StreamTokenizer无法正确处理时，才考虑使用这个类
        // 参考链接 : https://oi-wiki.org/lang/java-pro/
*/

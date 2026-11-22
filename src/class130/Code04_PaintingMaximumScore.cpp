// 原题测试 / 参考链接（保留上游原始地址）
// http://poj.org/problem?id=1821

// Source: src/class130/Code04_PaintingMaximumScore.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_PaintingMaximumScore {
  struct WorkerComparator;
  struct WorkerComparator {
    String toString() const { return j::str(static_cast<const void *>(this)); }
    WorkerComparator() {}
    int compare(Array<int> o1, Array<int> o2) { return (o1[2] - o2[2]); }
  };
  inline static int MAXN = 16001;
  inline static int MAXM = 101;
  inline static Array<Array<int>> workers = make_array<int>(MAXM, 3);
  inline static Array<Array<int>> dp = make_array<int>(MAXM, MAXN);
  inline static Array<int> queue = make_array<int>(MAXN);
  inline static int l = {};
  inline static int r = {};
  inline static int n = {};
  inline static int m = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_PaintingMaximumScore() {}
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    while ((in.nextToken() != -1)) {
      (n = static_cast<int>(in.nval));
      in.nextToken();
      (m = static_cast<int>(in.nval));
      for (int i = 1; (i <= m); (i++)) {
        in.nextToken();
        (workers[i][0] = static_cast<int>(in.nval));
        in.nextToken();
        (workers[i][1] = static_cast<int>(in.nval));
        in.nextToken();
        (workers[i][2] = static_cast<int>(in.nval));
      }
      out.println(Code04_PaintingMaximumScore::compute());
    }
    out.flush();
    out.close();
    br.close();
  }
  static int compute() {
    j::sort(workers, 1, (m + 1), new WorkerComparator());
    {
      int i = 1;
      int li = {};
      int pi = {};
      int si = {};
      for (; (i <= m); (i++)) {
        (li = workers[i][0]);
        (pi = workers[i][1]);
        (si = workers[i][2]);
        (l = (r = 0));
        for (int j = jmax(0, (si - li)); (j < si); (j++)) {
          while (((l < r) && [&]() {
            auto jleft =
                Code04_PaintingMaximumScore::value(i, pi, queue[(r - 1)]);
            auto jright = Code04_PaintingMaximumScore::value(i, pi, j);
            return (jleft <= jright);
          }())) {
            (r--);
          }
          (queue[(r++)] = j);
        }
        for (int j = 1; (j <= n); (j++)) {
          (dp[i][j] = jmax(dp[(i - 1)][j], dp[i][(j - 1)]));
          if ((j >= si)) {
            if (((l < r) && (queue[l] == ((j - li) - 1)))) {
              (l++);
            }
            if ((l < r)) {
              (dp[i][j] =
                   jmax(dp[i][j],
                        (Code04_PaintingMaximumScore::value(i, pi, queue[l]) +
                         (pi * j))));
            }
          }
        }
      }
    }
    return dp[m][n];
  }
  static int value(int i, int pi, int j) { return (dp[(i - 1)][j] - (pi * j)); }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code04_PaintingMaximumScore::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 粉刷木板的最大收益
// 一共有n个木板，每个木板长度为1，最多粉刷一次，也可以不刷
// 一共有m个工人，每个工人用(li, pi, si)表示：
// 该工人必须刷连续区域的木板，并且连续的长度不超过li
// 该工人每刷一块木板可以得到pi的钱
// 该工人刷的连续区域必须包含si位置的木板
// 返回所有工人最多能获得多少钱
// 1 <= n <= 16000
// 1 <= m <= 100
// 1 <= pi <= 10000
// 测试链接 : http://poj.org/problem?id=1821
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有用例
        // 之前工人负责的区域以j号木板结尾时，返回指标的值
        // poj平台java版本较老，不支持Lambda表达式方式的比较器，需要自己定义
*/

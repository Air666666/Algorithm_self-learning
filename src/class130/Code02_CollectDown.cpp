// Source: src/class130/Code02_CollectDown.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_CollectDown {
  inline static int MAXN = 4001;
  inline static int MAXM = 4001;
  inline static Array<Array<int>> dp = make_array<int>(MAXN, MAXM);
  inline static Array<int> queue = make_array<int>(MAXM);
  inline static int l = {};
  inline static int r = {};
  inline static int n = {};
  inline static int m = {};
  inline static int k = {};
  inline static int t = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_CollectDown() {}
  static void build() {
    for (int i = 1; (i <= n); (i++)) {
      for (int j = 1; (j <= m); (j++)) {
        (dp[i][j] = 0);
      }
    }
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    (n = static_cast<int>(in.nval));
    in.nextToken();
    (m = static_cast<int>(in.nval));
    in.nextToken();
    (k = static_cast<int>(in.nval));
    in.nextToken();
    (t = static_cast<int>(in.nval));
    Code02_CollectDown::build();
    {
      int i = 1;
      int r = {};
      int c = {};
      int v = {};
      for (; (i <= k); (i++)) {
        in.nextToken();
        (r = static_cast<int>(in.nval));
        in.nextToken();
        (c = static_cast<int>(in.nval));
        in.nextToken();
        (v = static_cast<int>(in.nval));
        (dp[r][c] = v);
      }
    }
    out.println(Code02_CollectDown::compute());
    out.flush();
    out.close();
    br.close();
  }
  static int compute() {
    for (int i = 2; (i <= n); (i++)) {
      (l = (r = 0));
      for (int j = 1; (j <= t); (j++)) {
        Code02_CollectDown::add((i - 1), j);
      }
      for (int j = 1; (j <= m); (j++)) {
        Code02_CollectDown::add((i - 1), (j + t));
        Code02_CollectDown::overdue(((j - t) - 1));
        (dp[i][j] += dp[(i - 1)][queue[l]]);
      }
    }
    int ans = std::numeric_limits<int>::min();
    for (int j = 1; (j <= m); (j++)) {
      (ans = jmax(ans, dp[n][j]));
    }
    return ans;
  }
  static void add(int i, int j) {
    if ((j <= m)) {
      while (((l < r) && (dp[i][queue[(r - 1)]] <= dp[i][j]))) {
        (r--);
      }
      (queue[(r++)] = j);
    }
  }
  static void overdue(int t) {
    if (((l < r) && (queue[l] == t))) {
      (l++);
    }
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code02_CollectDown::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 向下收集获得最大能量
// 有一个n * m的区域，行和列的编号从1开始
// 每个能量点用(i, j, v)表示，i行j列上有价值为v的能量点
// 一共有k个能量点，并且所有能量点一定在不同的位置
// 一开始可以在第1行的任意位置，然后每一步必须向下移动
// 向下去往哪个格子是一个范围，如果当前在(i, j)位置
// 那么往下可以选择(i+1, j-t)...(i+1, j+t)其中的一个格子
// 到达最后一行时，收集过程停止，返回能收集到的最大能量价值
// 1 <= n、m、k、t <= 4000
// 1 <= v <= 100
// 测试链接 : https://www.luogu.com.cn/problem/P3800
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有用例
*/

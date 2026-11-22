// Source: src/class130/Code01_JumpRight.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_JumpRight {
  inline static int MAXN = 200001;
  inline static int NA = std::numeric_limits<int>::min();
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static Array<int> dp = make_array<int>(MAXN);
  inline static Array<int> queue = make_array<int>(MAXN);
  inline static int l = {};
  inline static int r = {};
  inline static int n = {};
  inline static int a = {};
  inline static int b = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_JumpRight() {}
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    (n = static_cast<int>(in.nval));
    in.nextToken();
    (a = static_cast<int>(in.nval));
    in.nextToken();
    (b = static_cast<int>(in.nval));
    for (int i = 0; (i <= n); (i++)) {
      in.nextToken();
      (arr[i] = static_cast<int>(in.nval));
    }
    out.println(Code01_JumpRight::compute());
    out.flush();
    out.close();
    br.close();
  }
  static int compute() {
    (dp[0] = arr[0]);
    (l = (r = 0));
    for (int i = 1; (i <= n); (i++)) {
      Code01_JumpRight::add((i - a));
      Code01_JumpRight::overdue(((i - b) - 1));
      (dp[i] = ((l < r) ? (dp[queue[l]] + arr[i]) : NA));
    }
    int ans = NA;
    for (int i = ((n + 1) - b); (i <= n); (i++)) {
      (ans = jmax(ans, dp[i]));
    }
    return ans;
  }
  static void add(int j) {
    if (((j >= 0) && (dp[j] != NA))) {
      while (((l < r) && (dp[queue[(r - 1)]] <= dp[j]))) {
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
  Code01_JumpRight::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 向右跳跃获得最大得分
// 给定长度为n+1的数组arr，下标编号0 ~ n，给定正数a、b
// 一开始在0位置，每次可以选择[a,b]之间的一个整数，作为向右跳跃的距离
// 每来到一个位置i，可以获得arr[i]作为得分，位置一旦大于n就停止
// 返回能获得的最大得分
// 1 <= n <= 2 * 10^5
// 1 <= a <= b <= n
// -1000 <= arr[i] <= +1000
// 测试链接 : https://www.luogu.com.cn/problem/P1725
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有用例
*/

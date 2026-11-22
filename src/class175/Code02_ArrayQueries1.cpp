// Source: src/class175/Code02_ArrayQueries1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_ArrayQueries1 {
  inline static int MAXN = 100001;
  inline static int MAXB = 401;
  inline static int n = {};
  inline static int q = {};
  inline static int blen = {};
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static Array<Array<int>> dp = make_array<int>(MAXN, MAXB);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_ArrayQueries1() {}
  static int query(int p, int k) {
    if ((k <= blen)) {
      return dp[p][k];
    }
    int ans = 0;
    while ((p <= n)) {
      (ans++);
      (p += (arr[p] + k));
    }
    return ans;
  }
  static void prepare() {
    (blen = static_cast<int>(std::sqrt(n)));
    for (int p = n; (p >= 1); (p--)) {
      for (int k = 1; (k <= blen); (k++)) {
        (dp[p][k] =
             (1 + ((((p + arr[p]) + k) > n) ? 0 : dp[((p + arr[p]) + k)][k])));
      }
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    for (int i = 1; (i <= n); (i++)) {
      (arr[i] = in.nextInt());
    }
    Code02_ArrayQueries1::prepare();
    (q = in.nextInt());
    {
      int i = 1;
      int p = {};
      int k = {};
      for (; (i <= q); (i++)) {
        (p = in.nextInt());
        (k = in.nextInt());
        out.println(Code02_ArrayQueries1::query(p, k));
      }
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code02_ArrayQueries1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 数组查询，java版
// 给定一个长度为n的数组arr，接下来有q条查询，查询格式如下
// 查询 p k : p 不断变成 p + arr[p] + k，直到 p > n 停止，打印操作次数
// 1 <= n、q <= 10 ^ 5
// 1 <= arr[i] <= n
// 测试链接 : https://www.luogu.com.cn/problem/CF797E
// 测试链接 : https://codeforces.com/problemset/problem/797/E
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 读写工具类
*/

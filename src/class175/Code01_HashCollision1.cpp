// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P3396

// Source: src/class175/Code01_HashCollision1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_HashCollision1 {
  inline static int MAXN = 150001;
  inline static int MAXB = 401;
  inline static int n = {};
  inline static int m = {};
  inline static int blen = {};
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static Array<Array<i64>> dp = make_array<i64>(MAXB, MAXB);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_HashCollision1() {}
  static i64 query(int x, int y) {
    if ((x <= blen)) {
      return dp[x][y];
    }
    i64 ans = 0;
    for (int i = y; (i <= n); (i += x)) {
      (ans += arr[i]);
    }
    return ans;
  }
  static void update(int i, int v) {
    int delta = (v - arr[i]);
    (arr[i] = v);
    for (int x = 1; (x <= blen); (x++)) {
      (dp[x][jrem(i, x)] += delta);
    }
  }
  static void prepare() {
    (blen = static_cast<int>(std::sqrt(n)));
    for (int x = 1; (x <= blen); (x++)) {
      for (int i = 1; (i <= n); (i++)) {
        (dp[x][jrem(i, x)] += arr[i]);
      }
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO();
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (m = in.nextInt());
    for (int i = 1; (i <= n); (i++)) {
      (arr[i] = in.nextInt());
    }
    Code01_HashCollision1::prepare();
    jchar op = {};
    int x = {};
    int y = {};
    for (int i = 1; (i <= m); (i++)) {
      (op = in.nextTokenLastChar());
      (x = in.nextInt());
      (y = in.nextInt());
      if ((op == u'A')) {
        out.println(Code01_HashCollision1::query(x, y));
      } else {
        Code01_HashCollision1::update(x, y);
      }
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code01_HashCollision1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 哈希冲突，java版
// 给定一个长度为n的数组arr，接下来有m条操作，操作格式如下
// 操作 A x y : 下标 % x == y，符合要求的下标，把对应的值累加起来，打印结果
// 操作 C x y : arr[x]的值改成y
// 1 <= n、m <= 1.5 * 10^5
// 测试链接 : https://www.luogu.com.cn/problem/P3396
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 读写工具类
*/

// Source: src/class063/Code02_SnacksWaysBuyTickets.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_SnacksWaysBuyTickets {
  inline static int MAXN = 40;
  inline static int MAXM = jshl(1, 20);
  inline static Array<i64> arr = make_array<i64>(MAXN);
  inline static Array<i64> lsum = make_array<i64>(MAXM);
  inline static Array<i64> rsum = make_array<i64>(MAXM);
  inline static int n = {};
  inline static i64 w = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_SnacksWaysBuyTickets() {}
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    while ((in.nextToken() != -1)) {
      (n = static_cast<int>(in.nval));
      in.nextToken();
      (w = static_cast<i64>(in.nval));
      for (int i = 0; (i < n); (i++)) {
        in.nextToken();
        (arr[i] = static_cast<i64>(in.nval));
      }
      out.println(Code02_SnacksWaysBuyTickets::compute());
    }
    out.flush();
    out.close();
    br.close();
  }
  static i64 compute() {
    int lsize = Code02_SnacksWaysBuyTickets::f(0, jshr(n, 1), 0, w, lsum, 0);
    int rsize = Code02_SnacksWaysBuyTickets::f(jshr(n, 1), n, 0, w, rsum, 0);
    j::sort(lsum, 0, lsize);
    j::sort(rsum, 0, rsize);
    i64 ans = 0;
    {
      int i = (lsize - 1);
      int j = 0;
      for (; (i >= 0); (i--)) {
        while (((j < rsize) && ((lsum[i] + rsum[j]) <= w))) {
          (j++);
        }
        (ans += j);
      }
    }
    return ans;
  }
  static int f(int i, int e, i64 s, i64 w, Array<i64> ans, int j) {
    if ((s > w)) {
      return j;
    }
    if ((i == e)) {
      (ans[(j++)] = s);
    } else {
      (j = Code02_SnacksWaysBuyTickets::f((i + 1), e, s, w, ans, j));
      (j = Code02_SnacksWaysBuyTickets::f((i + 1), e, (s + arr[i]), w, ans, j));
    }
    return j;
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code02_SnacksWaysBuyTickets::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 牛牛的背包问题 & 世界冰球锦标赛
// 牛牛准备参加学校组织的春游, 出发前牛牛准备往背包里装入一些零食,
牛牛的背包容量为w。
// 牛牛家里一共有n袋零食, 第i袋零食体积为v[i]。
//
牛牛想知道在总体积不超过背包容量的情况下,他一共有多少种零食放法(总体积为0也算一种放法)。
// 输入描述：
// 输入包括两行
// 第一行为两个正整数n和w(1 <= n <= 30, 1 <= w <= 2 *
10^9),表示零食的数量和背包的容量
// 第二行n个正整数v[i](0 <= v[i] <= 10^9),表示每袋零食的体积
// 输出描述：
// 输出一个正整数, 表示牛牛一共有多少种零食放法。
// 测试链接 : https://www.luogu.com.cn/problem/P4799
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下所有代码，把主类名改成Main，可以直接通过
        // arr[i..e-1]范围上展开，到达e就停止
        // 返回值 : ans数组填到了什么位置！
                // s <= w
                        // 不要arr[i]位置的数
                        // 要arr[i]位置的数
*/

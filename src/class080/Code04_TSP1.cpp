// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P1171

// Source: src/class080/Code04_TSP1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_TSP1 {
  inline static int MAXN = 19;
  inline static Array<Array<int>> graph = make_array<int>(MAXN, MAXN);
  inline static Array<Array<int>> dp = make_array<int>(jshl(1, MAXN), MAXN);
  inline static int n = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_TSP1() {}
  static void build() {
    for (int s = 0; (s < jshl(1, n)); (s++)) {
      for (int i = 0; (i < n); (i++)) {
        (dp[s][i] = (-1));
      }
    }
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    while ((in.nextToken() != -1)) {
      (n = static_cast<int>(in.nval));
      Code04_TSP1::build();
      for (int i = 0; (i < n); (i++)) {
        for (int j = 0; (j < n); (j++)) {
          in.nextToken();
          (graph[i][j] = static_cast<int>(in.nval));
        }
      }
      out.println(Code04_TSP1::compute());
    }
    out.flush();
    out.close();
    br.close();
  }
  static int compute() { return Code04_TSP1::f(1, 0); }
  static int f(int s, int i) {
    if ((s == (jshl(1, n) - 1))) {
      return graph[i][0];
    }
    if ((dp[s][i] != (-1))) {
      return dp[s][i];
    }
    int ans = std::numeric_limits<int>::max();
    for (int j = 0; (j < n); (j++)) {
      if (((s & jshl(1, j)) == 0)) {
        (ans = jmin(ans, (graph[i][j] + Code04_TSP1::f((s | jshl(1, j)), j))));
      }
    }
    (dp[s][i] = ans);
    return ans;
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code04_TSP1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 售货员的难题 - TSP问题
// 某乡有n个村庄(1<=n<=20)，有一个售货员，他要到各个村庄去售货
// 各村庄之间的路程s(1<=s<=1000)是已知的
// 且A村到B村的路程，与B到A的路大多不同(有向带权图)
// 为了提高效率，他从商店出发到每个村庄一次，然后返回商店所在的村，
// 假设商店所在的村庄为1
// 他不知道选择什么样的路线才能使所走的路程最短
// 请你帮他选择一条最短的路
// 测试链接 : https://www.luogu.com.cn/problem/P1171
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下的code，提交时请把类名改成"Main"，可以直接通过
// 正常来说把MAXN改成20能通过，实现是正确的
// 问题是卡空间，而且c++的实现不卡空间，就卡java的实现
// 但如果把MAXN改成19，会有一个测试用例通过不了
// 那就差这么一点空间...看不起java是吗？
// 好，你歧视java实现，那就别怪我了
// 完全能通过的版本看Code04_TSP2的实现
        // s : 村里走没走过的状态，1走过了不要再走了，0可以走
        // i : 目前在哪个村
                        // n : 000011111
                        // 0...n-1这些村，都看看是不是下一个落脚点
*/

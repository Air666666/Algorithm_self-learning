// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P2881

// Source: src/class207/Code05_Ranking1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code05_Ranking1 {
  inline static int MAXN = 1001;
  inline static int n = {};
  inline static int m = {};
  inline static Array<BitSet> dp = make_array<BitSet>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code05_Ranking1() {}
  static void floyd() {
    for (int bridge = 1; (bridge <= n); (bridge++)) {
      for (int i = 1; (i <= n); (i++)) {
        if (dp[i].get(bridge)) {
          dp[i].or_java(dp[bridge]);
        }
      }
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (m = in.nextInt());
    for (int i = 1; (i <= n); (i++)) {
      (dp[i] = BitSet((n + 1)));
    }
    {
      int i = 1;
      int a = {};
      int b = {};
      for (; (i <= m); (i++)) {
        (a = in.nextInt());
        (b = in.nextInt());
        dp[a].set(b);
      }
    }
    Code05_Ranking1::floyd();
    int need = 0;
    for (int i = 1; (i <= n); (i++)) {
      for (int j = (i + 1); (j <= n); (j++)) {
        if (((!dp[i].get(j)) && (!dp[j].get(i)))) {
          (need++);
        }
      }
    }
    out.println(need);
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code05_Ranking1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 需要关系，java版
// 一共n头奶牛，编号为1~n，每头奶牛的能力互不相同
// 给定m条已知关系，格式 a b，表示a的能力强于b
// 能力关系具有传递性，如果a强于b，b强于c，那么a强于c
// 希望确定所有奶牛能力从强到弱的完整排名，所以m条关系可能不够
// 你可以询问任意两只奶牛的强弱，所有询问必须提前准备好，不可以动态调整
// 求至少需要询问多少次，才能保证确定完整排名，打印这个数量
// 1 <= n <= 1000
// 1 <= m <= 10000
// 测试链接 : https://www.luogu.com.cn/problem/P2881
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 读写工具类
*/

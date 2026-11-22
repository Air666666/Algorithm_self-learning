// Source: src/class207/Code04_Contest1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_Contest1 {
  inline static int MAXN = 101;
  inline static int n = {};
  inline static int m = {};
  inline static Array<BitSet> dp = make_array<BitSet>(MAXN);
  inline static Array<int> cnt = make_array<int>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_Contest1() {}
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
    Code04_Contest1::floyd();
    for (int i = 1; (i <= n); (i++)) {
      for (int j = (i + 1); (j <= n); (j++)) {
        if ((dp[i].get(j) || dp[j].get(i))) {
          (cnt[i]++);
          (cnt[j]++);
        }
      }
    }
    int ans = 0;
    for (int i = 1; (i <= n); (i++)) {
      if ((cnt[i] == (n - 1))) {
        (ans++);
      }
    }
    out.println(ans);
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code04_Contest1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 确定能力，java版
// 一共n头奶牛，编号为1~n，每头奶牛的能力互不相同
// 给定m条已知关系，格式 a b，表示a的能力强于b
// 能力关系具有传递性，如果a强于b，b强于c，那么a强于c
// 题目保证没有矛盾，根据已知关系，希望确定奶牛的排名
// 计算有多少头奶牛的具体名次已经能够确定，打印这个数量
// 1 <= n <= 100
// 1 <= m <= 4500
// 测试链接 : https://www.luogu.com.cn/problem/P2419
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 读写工具类
*/

// 原题测试 / 参考链接（保留上游原始地址）
// https://pintia.cn/problem-sets/91827364500/exam/problems/type/7?problemSetProblemId=91827367873

// Source: src/class094/Code05_CuttingTree.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code05_CuttingTree {
  inline static int MAXN = 251;
  inline static Array<Array<int>> tree = make_array<int>(MAXN, 2);
  inline static Array<Array<int>> dp = make_array<int>(MAXN, MAXN);
  inline static int t = {};
  inline static int n = {};
  inline static int m = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code05_CuttingTree() {}
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    (t = static_cast<int>(in.nval));
    for (int i = 1; (i <= t); (i++)) {
      in.nextToken();
      (n = static_cast<int>(in.nval));
      in.nextToken();
      (m = static_cast<int>(in.nval));
      for (int j = 1; (j <= n); (j++)) {
        in.nextToken();
        (tree[j][0] = static_cast<int>(in.nval));
      }
      for (int j = 1; (j <= n); (j++)) {
        in.nextToken();
        (tree[j][1] = static_cast<int>(in.nval));
      }
      out.println(Code05_CuttingTree::compute());
    }
    out.flush();
    out.close();
    br.close();
  }
  static int compute() {
    j::sort(tree, 1, (n + 1),
            [=](Array<int> o1, Array<int> o2) { return (o1[1] - o2[1]); });
    for (int i = 1; (i <= n); (i++)) {
      for (int j = 1; (j <= m); (j++)) {
        (dp[i][j] = jmax(dp[(i - 1)][j], ((dp[(i - 1)][(j - 1)] + tree[i][0]) +
                                          (tree[i][1] * (j - 1)))));
      }
    }
    return dp[n][m];
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code05_CuttingTree::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 砍树
// 一共有n棵树，每棵树都有两个信息：
// 第一天这棵树的初始重量、这棵树每天的增长重量
// 你每天最多能砍1棵树，砍下这棵树的收益为：
// 这棵树的初始重量 + 这棵树增长到这一天的总增重
// 从第1天开始，你一共有m天可以砍树，返回m天内你获得的最大收益
// 测试链接 :
https://pintia.cn/problem-sets/91827364500/exam/problems/type/7?problemSetProblemId=91827367873
// 提交以下的code，提交时请把类名改成"Main"，可以直接通过
// 不过现在这个题收费了，验证很困难了，于是我找到了一个平替的题目
// 本节课Code06_CookingPlan文件就是平替题目，贪心的思路是非常类似的
        // 树的个数、天数最大值，不超过的量
        // 树的编号为1 ~ n
        // tree[i][0] : 第i棵树第一天的初始重量
        // tree[i][1] : 第i棵树每天的增长重量
        // dp[i][j] : 在j天内，从前i棵树中选若干棵树进行砍伐，最大收益是多少
        // 讲解073 - 01背包
                //
树的初始重量不决定树的顺序，因为任何树砍了，就获得固定的初始量，和砍伐的顺序无关
                // 根据增长速度排序，增长量小的在前，增长量大的在后
                // 认为越靠后的树，越要尽量晚的砍伐，课上的重点内容
                // dp[0][...] = 0 : 表示如果没有树，不管过去多少天，收益都是0
                // dp[...][0] = 0 : 表示不管有几棵树，没有时间砍树，收益都是0
*/

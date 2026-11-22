// Source: src/class079/Code05_CourseSelection1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code05_CourseSelection1 {
  inline static int MAXN = 301;
  inline static Array<int> nums = make_array<int>(MAXN);
  inline static JList<JList<int>> graph = {};
  inline static Array<Array<Array<int>>> dp =
      make_array<Array<Array<int>>>(MAXN);
  inline static int n = {};
  inline static int m = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code05_CourseSelection1() {}
  static void build(int n) {
    for (int i = 0; (i <= n); (i++)) {
      graph.get(i).clear();
    }
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    while ((in.nextToken() != -1)) {
      (n = static_cast<int>(in.nval));
      in.nextToken();
      (m = (static_cast<int>(in.nval) + 1));
      Code05_CourseSelection1::build(n);
      {
        int i = 1;
        int pre = {};
        for (; (i <= n); (i++)) {
          in.nextToken();
          (pre = static_cast<int>(in.nval));
          graph.get(pre).add(i);
          in.nextToken();
          (nums[i] = static_cast<int>(in.nval));
        }
      }
      out.println(Code05_CourseSelection1::compute());
    }
    out.flush();
    out.close();
    br.close();
  }
  static int compute() {
    for (int i = 0; (i <= n); (i++)) {
      (dp[i] = make_array<int>((graph.get(i).size() + 1), (m + 1)));
    }
    for (int i = 0; (i <= n); (i++)) {
      for (int j = 0; (j < dp[i].length); (j++)) {
        for (int k = 0; (k <= m); (k++)) {
          (dp[i][j][k] = (-1));
        }
      }
    }
    return Code05_CourseSelection1::f(0, graph.get(0).size(), m);
  }
  static int f(int i, int j, int k) {
    if ((k == 0)) {
      return 0;
    }
    if (((j == 0) || (k == 1))) {
      return nums[i];
    }
    if ((dp[i][j][k] != (-1))) {
      return dp[i][j][k];
    }
    int ans = Code05_CourseSelection1::f(i, (j - 1), k);
    int v = graph.get(i).get((j - 1));
    for (int s = 1; (s < k); (s++)) {
      (ans = jmax(ans, [&]() {
         auto jleft = Code05_CourseSelection1::f(i, (j - 1), (k - s));
         auto jright = Code05_CourseSelection1::f(v, graph.get(v).size(), s);
         return (jleft + jright);
       }()));
    }
    (dp[i][j][k] = ans);
    return ans;
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code05_CourseSelection1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 选课，树上01背包的普通解法
// 在大学里每个学生，为了达到一定的学分，必须从很多课程里选择一些课程来学习
// 在课程里有些课程必须在某些课程之前学习，如高等数学总是在其它课程之前学习
// 现在有 N 门功课，每门课有个学分，每门课有一门或没有直接先修课
// 若课程 a 是课程 b 的先修课即只有学完了课程 a，才能学习课程 b
// 一个学生要从这些课程里选择 M 门课程学习
// 问他能获得的最大学分是多少
// 测试链接 : https://www.luogu.com.cn/problem/P2014
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下的code，提交时请把类名改成"Main"，可以直接通过
// 普通解法，邻接表建图 + 相对好懂的动态规划
// 几乎所有题解都是普通解法的思路，只不过优化了常数时间、做了空间压缩
// 但时间复杂度依然是O(n * 每个节点的孩子平均数量 * m的平方)
                        // 节点编号从0~n
        // 当前来到i号节点为头的子树
        // 只在i号节点、及其i号节点下方的前j棵子树上挑选节点
        // 一共挑选k个节点，并且保证挑选的节点连成一片
        // 返回最大的累加和
                // 第j棵子树头节点v
*/

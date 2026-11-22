// Source: src/class079/Code05_CourseSelection2.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code05_CourseSelection2 {
  inline static int MAXN = 301;
  inline static Array<int> nums = make_array<int>(MAXN);
  inline static int edgeCnt = {};
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> next = make_array<int>(MAXN);
  inline static Array<int> to = make_array<int>(MAXN);
  inline static int dfnCnt = {};
  inline static Array<int> val = make_array<int>((MAXN + 1));
  inline static Array<int> size = make_array<int>((MAXN + 1));
  inline static Array<Array<int>> dp = make_array<int>((MAXN + 2), MAXN);
  inline static int n = {};
  inline static int m = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code05_CourseSelection2() {}
  static void build(int n, int m) {
    (edgeCnt = 1);
    (dfnCnt = 0);
    j::fill(head, 0, (n + 1), 0);
    j::fill(dp[(n + 2)], 0, (m + 1), 0);
  }
  static void addEdge(int u, int v) {
    (next[edgeCnt] = head[u]);
    (to[edgeCnt] = v);
    (head[u] = (edgeCnt++));
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    while ((in.nextToken() != -1)) {
      (n = static_cast<int>(in.nval));
      in.nextToken();
      (m = static_cast<int>(in.nval));
      Code05_CourseSelection2::build(n, m);
      for (int i = 1; (i <= n); (i++)) {
        in.nextToken();
        Code05_CourseSelection2::addEdge(static_cast<int>(in.nval), i);
        in.nextToken();
        (nums[i] = static_cast<int>(in.nval));
      }
      out.println(Code05_CourseSelection2::compute());
    }
    out.flush();
    out.close();
    br.close();
  }
  static int compute() {
    Code05_CourseSelection2::f(0);
    for (int i = (n + 1); (i >= 2); (i--)) {
      for (int j = 1; (j <= m); (j++)) {
        (dp[i][j] =
             jmax(dp[(i + size[i])][j], (val[i] + dp[(i + 1)][(j - 1)])));
      }
    }
    return (nums[0] + dp[2][m]);
  }
  static int f(int u) {
    int i = (++dfnCnt);
    (val[i] = nums[u]);
    (size[i] = 1);
    {
      int ei = head[u];
      int v = {};
      for (; (ei > 0); (ei = next[ei])) {
        (v = to[ei]);
        (size[i] += Code05_CourseSelection2::f(v));
      }
    }
    return size[i];
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code05_CourseSelection2::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 选课，树上01背包的最优解
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
// 最优解，链式前向星建图 + dfn序的利用 + 巧妙定义下的尝试
// 时间复杂度O(n * m)，推荐掌握，尤其是理解有效结构
        // 链式前向星建图
        // dfn的计数
        // 下标为dfn序号
        // 下标为dfn序号
        // 动态规划表
                // 节点编号0 ~ n，dfn序号范围1 ~ n+1
                // 接下来的逻辑其实就是01背包！不过经历了很多转化
                // 整体的顺序是根据dfn序来进行的，从大的dfn序，遍历到小的dfn序
                // dp[i][j] : i ~ n+1
范围的节点，选择j个节点一定要形成有效结构的情况下，最大的累加和
                // 怎么定义有效结构？重点！重点！重点！
                // 假设i ~ n+1范围上，目前所有头节点的上方，有一个总的头节点
                // i ~ n+1范围所有节点，选出来j个节点的结构，
                // 挂在这个假想的总头节点之下，是一个连续的结构，没有断开的情况
                // 那么就说，i ~
n+1范围所有节点，选出来j个节点的结构是一个有效结构
                // dp[2][m] : 2 ~
n范围上，选择m个节点一定要形成有效结构的情况下，最大的累加和
                // 最后来到dfn序为1的节点，一定是原始的0号节点
                // 原始0号节点下方一定挂着有效结构
                // 并且和补充的0号节点一定能整体连在一起，没有任何跳跃连接
                // 于是整个问题解决
        // u这棵子树的节点数返回
*/

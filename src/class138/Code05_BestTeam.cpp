// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P4322

// Source: src/class138/Code05_BestTeam.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code05_BestTeam {
  inline static int MAXN = 3001;
  inline static int LIMIT = 10000;
  inline static double NA = (-1e9);
  inline static double sml = 1e-6;
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> next = make_array<int>(MAXN);
  inline static Array<int> to = make_array<int>(MAXN);
  inline static int edgeCnt = {};
  inline static Array<int> cost = make_array<int>(MAXN);
  inline static Array<int> strength = make_array<int>(MAXN);
  inline static Array<int> dfn = make_array<int>(MAXN);
  inline static int dfnCnt = {};
  inline static Array<double> value = make_array<double>(MAXN);
  inline static Array<int> size = make_array<int>(MAXN);
  inline static Array<Array<double>> dp = make_array<double>(MAXN, MAXN);
  inline static int k = {};
  inline static int n = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code05_BestTeam() {}
  static void prepare() {
    (edgeCnt = 1);
    (dfnCnt = 0);
    j::fill(head, 1, (n + 1), 0);
  }
  static void addEdge(int u, int v) {
    (next[edgeCnt] = head[u]);
    (to[edgeCnt] = v);
    (head[u] = (edgeCnt++));
  }
  static int dfs(int u) {
    int i = (++dfnCnt);
    (dfn[u] = i);
    (size[i] = 1);
    {
      int e = head[u];
      int v = {};
      for (; (e != 0); (e = next[e])) {
        (v = to[e]);
        (size[i] += Code05_BestTeam::dfs(v));
      }
    }
    return size[i];
  }
  static bool check(double x) {
    for (int i = 0; (i <= n); (i++)) {
      (value[dfn[i]] = (static_cast<double>(strength[i]) - (x * cost[i])));
    }
    for (int j = 1; (j <= k); (j++)) {
      (dp[(dfnCnt + 1)][j] = NA);
    }
    for (int i = dfnCnt; (i >= 2); (i--)) {
      for (int j = 1; (j <= k); (j++)) {
        (dp[i][j] =
             jmax(dp[(i + size[i])][j], (value[i] + dp[(i + 1)][(j - 1)])));
      }
    }
    return (dp[2][k] >= 0);
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    (k = static_cast<int>(in.nval));
    in.nextToken();
    (n = static_cast<int>(in.nval));
    Code05_BestTeam::prepare();
    for (int i = 1; (i <= n); (i++)) {
      in.nextToken();
      (cost[i] = static_cast<int>(in.nval));
      in.nextToken();
      (strength[i] = static_cast<int>(in.nval));
      in.nextToken();
      Code05_BestTeam::addEdge(static_cast<int>(in.nval), i);
    }
    Code05_BestTeam::dfs(0);
    double l = 0;
    double r = LIMIT;
    double x = {};
    double ans = 0;
    while (((l < r) && ((r - l) >= sml))) {
      (x = jdiv((l + r), 2));
      if (Code05_BestTeam::check(x)) {
        (ans = x);
        (l = (x + sml));
      } else {
        (r = (x - sml));
      }
    }
    out.printf(String(u"%.3f\n"), ans);
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code05_BestTeam::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 最佳团体
// 给定一棵树，节点编号0~n，0号节点是整棵树的头
// 编号1~n的节点，每个节点都有招募花费和战斗值，0号节点这两个值都是0
// 给定每条边(a,b)，表示节点a的父节点是b，有些节点的父节点是0节点
// 当招募了某个节点，那么该节点及其上方的所有祖先节点都需要招募
// 除了0号节点之外，一共可以招募k个人，希望让
// 战斗值之和 /
招募花费之和，这个比值尽量大，答案只需保留三位小数，更大的精度舍弃
// 1 <= k <= n <= 2500
// 0 <= 招募花费、战斗值 <= 10^4
// 测试链接 : https://www.luogu.com.cn/problem/P4322
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 链式前向星
        // 招募花费，下标为节点原始编号
        // 战斗值，下标为节点原始编号
        // dfn[a] = b，表示原始a号节点的dfn编号为b
        // dfn序计数
        // (战斗值 - x * 招募花费)的结余，下标为节点dfn编号
        // 子树大小，下标为节点dfn编号
        // 树型dp
        // 记录节点u的dfn编号 + 返回u这棵子树的节点数
        // 如下实现和讲解079，题目5，选课问题的最优解，几乎完全一样
        // 根据x的值，计算节点的结余值，在树上选k+1个点
        // 一定要形成有效结构，返回最大的结余和
        // 核心逻辑完全来自讲解079，题目5，选课问题，重点介绍的最优解
                // value[节点i的dfn编号] = 节点i的战斗值 - x * 节点i的招募花费
                // 越界位置认为都是无效解
                // 讲解079题目5的最优解逻辑
                // 原始的0号节点，dfn编号是1，其他节点的dfn编号从2开始
                // 0号节点的战斗值和招募花费都是0，其他节点一共招募k个
*/

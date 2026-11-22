// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/number-of-good-paths/

// Source: src/class057/Code03_NumberOfGoodPaths.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_NumberOfGoodPaths {
  inline static int MAXN = 30001;
  inline static Array<int> father = make_array<int>(MAXN);
  inline static Array<int> maxcnt = make_array<int>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_NumberOfGoodPaths() {}
  static void build(int n) {
    for (int i = 0; (i < n); (i++)) {
      (father[i] = i);
      (maxcnt[i] = 1);
    }
  }
  static int find(int i) {
    if ((i != father[i])) {
      (father[i] = Code03_NumberOfGoodPaths::find(father[i]));
    }
    return father[i];
  }
  static int union_method(int x, int y, Array<int> vals) {
    int fx = Code03_NumberOfGoodPaths::find(x);
    int fy = Code03_NumberOfGoodPaths::find(y);
    int path = 0;
    if ((vals[fx] > vals[fy])) {
      (father[fy] = fx);
    } else if ((vals[fx] < vals[fy])) {
      (father[fx] = fy);
    } else {
      (path = (maxcnt[fx] * maxcnt[fy]));
      (father[fy] = fx);
      (maxcnt[fx] += maxcnt[fy]);
    }
    return path;
  }
  static int numberOfGoodPaths(Array<int> vals, Array<Array<int>> edges) {
    int n = vals.length;
    Code03_NumberOfGoodPaths::build(n);
    int ans = n;
    j::sort(edges, [=](Array<int> e1, Array<int> e2) {
      return [&]() {
        auto jleft = jmax(vals[e1[0]], vals[e1[1]]);
        auto jright = jmax(vals[e2[0]], vals[e2[1]]);
        return (jleft - jright);
      }();
    });
    for (Array<int> edge : edges) {
      (ans += Code03_NumberOfGoodPaths::union_method(edge[0], edge[1], vals));
    }
    return ans;
  }
  static void java_main(Array<String> args) {
    Array<int> vals1 = Array<int>{2, 1, 1, 2, 2, 1, 1, 2};
    Array<Array<int>> edges1 = Array<Array<int>>{
        Array<int>{0, 1}, Array<int>{0, 2}, Array<int>{1, 3}, Array<int>{2, 4},
        Array<int>{2, 5}, Array<int>{5, 6}, Array<int>{6, 7}};
    jout.println(Code03_NumberOfGoodPaths::numberOfGoodPaths(vals1, edges1));
    Array<int> vals2 = Array<int>{1, 2, 2, 3, 1, 2, 2, 1, 1, 3, 3, 3, 3};
    Array<Array<int>> edges2 = Array<Array<int>>{
        Array<int>{0, 1},  Array<int>{0, 2},  Array<int>{0, 3},
        Array<int>{1, 4},  Array<int>{4, 7},  Array<int>{4, 8},
        Array<int>{3, 5},  Array<int>{3, 6},  Array<int>{6, 9},
        Array<int>{6, 10}, Array<int>{6, 11}, Array<int>{9, 12}};
    jout.println(Code03_NumberOfGoodPaths::numberOfGoodPaths(vals2, edges2));
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code03_NumberOfGoodPaths::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 好路径的数目
// 给你一棵 n 个节点的树（连通无向无环的图）
// 节点编号从0到n-1，且恰好有n-1条边
// 给你一个长度为 n 下标从 0 开始的整数数组 vals
// 分别表示每个节点的值。同时给你一个二维整数数组 edges
// 其中 edges[i] = [ai, bi] 表示节点 ai 和 bi 之间有一条 无向 边
// 好路径需要满足以下条件：开始和结束节点的值相同、
路径中所有值都小于等于开始的值
// 请你返回不同好路径的数目
// 注意，一条路径和它反向的路径算作 同一 路径
// 比方说， 0 -> 1 与 1 -> 0 视为同一条路径。单个节点也视为一条合法路径
// 测试链接 : https://leetcode.cn/problems/number-of-good-paths/
        // 需要保证集合中，代表节点的值，一定是整个集合的最大值
        // 集合中最大值的次数，也就是 集合中代表节点的值有几个
        // 这个并查集的优化只来自扁平化
        // 核心！
        // 注意以下的写法！
        // 谁的值大，谁做代表节点
        // 同时注意 maxcnt 的更新
                // fx : x所在集团的代表节点，同时也是x所在集团的最大值下标
                // fy : y所在集团的代表节点，同时也是y所在集团的最大值下标
                        // 两个集团最大值一样！
                // 课上重点讲这个核心排序！
                // 处理边的时候，依次从小节点往大节点处理
        // 课上讲解的例子1和例子2
                // 课上例子1
                //              0  1  2  3  4  5  6  7
                // 课上例子2
                //              0  1  2  3  4  5  6  7  8  9 10 11 12
*/

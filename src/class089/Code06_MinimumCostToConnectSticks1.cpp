// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/minimum-cost-to-connect-sticks/

// Source: src/class089/Code06_MinimumCostToConnectSticks1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code06_MinimumCostToConnectSticks1 {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code06_MinimumCostToConnectSticks1() {}
  static int connectSticks(Array<int> arr) {
    JHeap<int> heap = JHeap<int>();
    for (int i = 0; (i < arr.length); (i++)) {
      heap.add(arr[i]);
    }
    int sum = 0;
    int cur = 0;
    while ((heap.size() > 1)) {
      (cur = [&]() {
        auto jleft = heap.poll();
        auto jright = heap.poll();
        return (jleft + jright);
      }());
      (sum += cur);
      heap.add(cur);
    }
    return sum;
  }
};

/* Original teaching comments:
// 连接棒材的最低费用(leetcode测试)
// 你有一些长度为正整数的棍子
// 这些长度以数组sticks的形式给出
// sticks[i]是第i个木棍的长度
// 你可以通过支付x+y的成本将任意两个长度为x和y的棍子连接成一个棍子
// 你必须连接所有的棍子，直到剩下一个棍子
// 返回以这种方式将所有给定的棍子连接成一个棍子的最小成本
// 测试链接 : https://leetcode.cn/problems/minimum-cost-to-connect-sticks/
                // 小根堆
*/

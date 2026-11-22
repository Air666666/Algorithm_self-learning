// Source: src/class093/Code05_SuperWashingMachines.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code05_SuperWashingMachines {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code05_SuperWashingMachines() {}
  static int findMinMoves(Array<int> arr) {
    int n = arr.length;
    int sum = 0;
    for (int i = 0; (i < n); (i++)) {
      (sum += arr[i]);
    }
    if ((jrem(sum, n) != 0)) {
      return (-1);
    }
    int avg = jdiv(sum, n);
    int leftSum = 0;
    int leftNeed = 0;
    int rightNeed = 0;
    int bottleNeck = 0;
    int ans = 0;
    for (int i = 0; (i < n); (leftSum += arr[i]), (i++)) {
      (leftNeed = ((i * avg) - leftSum));
      (rightNeed = ((((n - i) - 1) * avg) - ((sum - leftSum) - arr[i])));
      if (((leftNeed > 0) && (rightNeed > 0))) {
        (bottleNeck = (leftNeed + rightNeed));
      } else {
        (bottleNeck = [&]() {
          auto jargument_0 = std::abs(leftNeed);
          auto jargument_1 = std::abs(rightNeed);
          return jmax(jargument_0, jargument_1);
        }());
      }
      (ans = jmax(ans, bottleNeck));
    }
    return ans;
  }
};

/* Original teaching comments:
// 超级洗衣机
// 假设有n台超级洗衣机放在同一排上
// 开始的时候，每台洗衣机内可能有一定量的衣服，也可能是空的
// 在每一步操作中，你可以选择任意 m (1 <= m <= n) 台洗衣机
// 与此同时将每台洗衣机的一件衣服送到相邻的一台洗衣机
// 给定一个整数数组machines代表从左至右每台洗衣机中的衣物数量
// 请给出能让所有洗衣机中剩下的衣物的数量相等的最少的操作步数
// 如果不能使每台洗衣机中衣物的数量相等则返回-1
// 测试链接 : https://leetcode.cn/problems/super-washing-machines/
*/

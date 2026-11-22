// Source: src/class087/Code02_PickNumbersClosedSum.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_PickNumbersClosedSum {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_PickNumbersClosedSum() {}
  static Array<int> pick(int n, int k) {
    i64 sum = jdiv(((n + 1) * n), 2);
    Array<int> ans = Code02_PickNumbersClosedSum::generate(jdiv(sum, 2), n, k);
    if (((ans.length == 0) && ((sum & 1) == 1))) {
      (ans = Code02_PickNumbersClosedSum::generate((jdiv(sum, 2) + 1), n, k));
    }
    return ans;
  }
  static Array<int> generate(i64 sum, int n, int k) {
    i64 minKSum = jdiv(((k + 1) * k), 2);
    int range = (n - k);
    if (((sum < minKSum) ||
         (sum > (minKSum + (static_cast<i64>(range) * k))))) {
      return make_array<int>(0);
    }
    i64 need = (sum - minKSum);
    int rightSize = static_cast<int>(jdiv(need, range));
    int midIndex = ((k - rightSize) + static_cast<int>(jrem(need, range)));
    int leftSize = ((k - rightSize) - ((jrem(need, range) == 0) ? 0 : 1));
    Array<int> ans = make_array<int>(k);
    for (int i = 0; (i < leftSize); (i++)) {
      (ans[i] = (i + 1));
    }
    if ((jrem(need, range) != 0)) {
      (ans[leftSize] = midIndex);
    }
    {
      int i = (k - 1);
      int j = 0;
      for (; (j < rightSize); (i--), (j++)) {
        (ans[i] = (n - j));
      }
    }
    return ans;
  }
  static bool pass(int n, int k, Array<int> ans) {
    if ((ans.length == 0)) {
      if (Code02_PickNumbersClosedSum::canSplit(n, k)) {
        return false;
      } else {
        return true;
      }
    } else {
      if ((ans.length != k)) {
        return false;
      }
      int sum = jdiv(((n + 1) * n), 2);
      int pickSum = 0;
      for (int num : ans) {
        (pickSum += num);
      }
      return (std::abs((pickSum - (sum - pickSum))) <= 1);
    }
  }
  static bool canSplit(int n, int k) {
    int sum = jdiv(((n + 1) * n), 2);
    int wantSum = (jdiv(sum, 2) + (((sum & 1) == 0) ? 0 : 1));
    Array<Array<Array<int>>> dp =
        make_array<int>((n + 1), (k + 1), (wantSum + 1));
    return Code02_PickNumbersClosedSum::f(n, 1, k, wantSum, dp);
  }
  static bool f(int n, int i, int k, int s, Array<Array<Array<int>>> dp) {
    if (((k < 0) || (s < 0))) {
      return false;
    }
    if ((i == (n + 1))) {
      return ((k == 0) && (s == 0));
    }
    if ((dp[i][k][s] != 0)) {
      return (dp[i][k][s] == 1);
    }
    bool ans =
        (Code02_PickNumbersClosedSum::f(n, (i + 1), k, s, dp) ||
         Code02_PickNumbersClosedSum::f(n, (i + 1), (k - 1), (s - i), dp));
    (dp[i][k][s] = (ans ? 1 : (-1)));
    return ans;
  }
  static void java_main(Array<String> args) {
    int N = 60;
    int testTime = 5000;
    jout.println(String(u"测试开始"));
    for (int i = 0; (i < testTime); (i++)) {
      int n = (static_cast<int>((j::random() * N)) + 2);
      int k = (static_cast<int>((j::random() * n)) + 1);
      Array<int> ans = Code02_PickNumbersClosedSum::pick(n, k);
      if ((!Code02_PickNumbersClosedSum::pass(n, k, ans))) {
        jout.println(String(u"出错了!"));
      }
    }
    jout.println(String(u"测试结束"));
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code02_PickNumbersClosedSum::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 选择k个数字使得两集合累加和相差不超过1
// 给定一个正数n，表示1~n这些数字都可以选择
// 给定一个正数k，表示要从1~n中选择k个数字组成集合A，剩下数字组成集合B
// 希望做到集合A和集合B的累加和相差不超过1
// 如果能做到，返回集合A选择了哪些数字，任何一种方案都可以
// 如果不能做到，返回长度为0的数组
// 2 <= n <= 10^6
// 1 <= k <= n
// 来自真实大厂笔试，没有测试链接，用对数器验证
        // 正式方法
        // 最优解
        // 1 ~ n这些数字挑选k个
        // 能不能凑够累加和sum
        // 能的话，返回挑选了哪些数字
        // 不能的话，返回长度为0的数组
                // 100 15 -> 85
        // 为了验证
        // 检验得到的结果是否正确
        // 记忆化搜索
        // 不是最优解，只是为了验证
        // 返回能不能做到
        // 为了验证
        // 对数器
*/

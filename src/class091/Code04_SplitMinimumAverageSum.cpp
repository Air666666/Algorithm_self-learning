// Source: src/class091/Code04_SplitMinimumAverageSum.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_SplitMinimumAverageSum {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_SplitMinimumAverageSum() {}
  static int minAverageSum1(Array<int> arr, int k) {
    Array<int> sum = make_array<int>(k);
    Array<int> cnt = make_array<int>(k);
    return Code04_SplitMinimumAverageSum::f(arr, 0, sum, cnt);
  }
  static int f(Array<int> arr, int i, Array<int> sum, Array<int> cnt) {
    if ((i == arr.length)) {
      int ans = 0;
      for (int j = 0; (j < sum.length); (j++)) {
        if ((cnt[j] == 0)) {
          return std::numeric_limits<int>::max();
        }
        (ans += jdiv(sum[j], cnt[j]));
      }
      return ans;
    } else {
      int ans = std::numeric_limits<int>::max();
      for (int j = 0; (j < sum.length); (j++)) {
        (sum[j] += arr[i]);
        (cnt[j]++);
        (ans = jmin(ans,
                    Code04_SplitMinimumAverageSum::f(arr, (i + 1), sum, cnt)));
        (sum[j] -= arr[i]);
        (cnt[j]--);
      }
      return ans;
    }
  }
  static int minAverageSum2(Array<int> arr, int k) {
    j::sort(arr);
    int ans = 0;
    for (int i = 0; (i < (k - 1)); (i++)) {
      (ans += arr[i]);
    }
    int sum = 0;
    for (int i = (k - 1); (i < arr.length); (i++)) {
      (sum += arr[i]);
    }
    (ans += jdiv(sum, ((arr.length - k) + 1)));
    return ans;
  }
  static Array<int> randomArray(int n, int v) {
    Array<int> ans = make_array<int>(n);
    for (int i = 0; (i < n); (i++)) {
      (ans[i] = static_cast<int>((j::random() * v)));
    }
    return ans;
  }
  static void java_main(Array<String> args) {
    int N = 8;
    int V = 10000;
    int testTimes = 2000;
    jout.println(String(u"测试开始"));
    for (int i = 1; (i <= testTimes); (i++)) {
      int n = (static_cast<int>((j::random() * N)) + 1);
      Array<int> arr = Code04_SplitMinimumAverageSum::randomArray(n, V);
      int k = (static_cast<int>((j::random() * n)) + 1);
      int ans1 = Code04_SplitMinimumAverageSum::minAverageSum1(arr, k);
      int ans2 = Code04_SplitMinimumAverageSum::minAverageSum2(arr, k);
      if ((ans1 != ans2)) {
        jout.println(String(u"出错了!"));
      }
      if ((jrem(i, 100) == 0)) {
        jout.println(((String(u"测试到第") + i) + String(u"组")));
      }
    }
    jout.println(String(u"测试结束"));
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code04_SplitMinimumAverageSum::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 平均值最小累加和
// 给定一个数组arr，长度为n
// 再给定一个数字k，表示一定要将arr划分成k个集合
// 每个数字只能进一个集合
// 返回每个集合的平均值都累加起来的最小值
// 平均值向下取整
// 1 <= n <= 10^5
// 0 <= arr[i] <= 10^5
// 1 <= k <= n
// 来自真实大厂笔试，没有在线测试，对数器验证
        // 暴力方法
        // 为了验证
        // 每个数字做出所有可能的选择
        // 时间复杂度O(k的n次方)
        // 暴力方法
        // 为了验证
        // 正式方法
        // 时间复杂度O(n * logn)
                        // 最小的k-1个数，每个数独自成一个集合
        // 为了测试
        // 为了测试
*/

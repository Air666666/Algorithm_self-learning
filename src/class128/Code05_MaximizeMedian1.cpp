// Source: src/class128/Code05_MaximizeMedian1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code05_MaximizeMedian1 {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code05_MaximizeMedian1() {}
  static int maximizeMedian(Array<int> arr) {
    int n = arr.length;
    Array<int> sort = make_array<int>(n);
    for (int i = 0; (i < n); (i++)) {
      (sort[i] = arr[i]);
    }
    j::sort(sort);
    int l = 0;
    int r = (n - 1);
    int m = 0;
    int ans = (-1);
    Array<int> help = make_array<int>(n);
    Array<Array<int>> dp = make_array<int>((n + 1), 2);
    while ((l <= r)) {
      (m = jdiv((l + r), 2));
      if (Code05_MaximizeMedian1::check(arr, help, dp, sort[m], n)) {
        (ans = sort[m]);
        (l = (m + 1));
      } else {
        (r = (m - 1));
      }
    }
    return ans;
  }
  static bool check(Array<int> arr, Array<int> help, Array<Array<int>> dp,
                    int x, int n) {
    for (int i = 0; (i < n); (i++)) {
      (help[i] = ((arr[i] >= x) ? 1 : (-1)));
    }
    return (Code05_MaximizeMedian1::dp(help, dp, n) > 0);
  }
  static int dp(Array<int> arr, Array<Array<int>> dp, int n) {
    for (int i = (n - 1); (i >= 0); (i--)) {
      (dp[i][0] = jmax((arr[i] + dp[(i + 1)][0]), dp[(i + 1)][1]));
      (dp[i][1] = (arr[i] + dp[(i + 1)][0]));
    }
    return dp[0][0];
  }
  static int right(Array<int> arr) {
    Array<int> path = make_array<int>(arr.length);
    return Code05_MaximizeMedian1::dfs(arr, 0, true, path, 0);
  }
  static int dfs(Array<int> arr, int i, bool pre, Array<int> path, int size) {
    if ((i == arr.length)) {
      if ((size == 0)) {
        return 0;
      }
      Array<int> sort = make_array<int>(size);
      for (int j = 0; (j < size); (j++)) {
        (sort[j] = path[j]);
      }
      j::sort(sort);
      return sort[jdiv((sort.length - 1), 2)];
    } else {
      (path[size] = arr[i]);
      int ans =
          Code05_MaximizeMedian1::dfs(arr, (i + 1), true, path, (size + 1));
      if (pre) {
        (ans = jmax(ans, Code05_MaximizeMedian1::dfs(arr, (i + 1), false, path,
                                                     size)));
      }
      return ans;
    }
  }
  static Array<int> randomArray(int n, int v) {
    Array<int> ans = make_array<int>(n);
    for (int i = 0; (i < n); (i++)) {
      (ans[i] = static_cast<int>((j::random() * v)));
    }
    return ans;
  }
  static void java_main(Array<String> args) {
    int n = 20;
    int v = 1000;
    int testTime = 10000;
    jout.println(String(u"功能测试开始"));
    for (int i = 0; (i < testTime); (i++)) {
      int size = (static_cast<int>((j::random() * n)) + 1);
      Array<int> arr = Code05_MaximizeMedian1::randomArray(size, v);
      int ans1 = Code05_MaximizeMedian1::right(arr);
      int ans2 = Code05_MaximizeMedian1::maximizeMedian(arr);
      if ((ans1 != ans2)) {
        jout.println(String(u"出错了!"));
      }
    }
    jout.println(String(u"功能测试结束"));
    jout.println();
    jout.println(String(u"性能测试开始"));
    (n = 100000);
    (v = 50000000);
    jout.println((String(u"数组长度 : ") + n));
    jout.println((String(u"数值范围 : ") + v));
    Array<int> arr = Code05_MaximizeMedian1::randomArray(n, v);
    i64 start = millis();
    Code05_MaximizeMedian1::maximizeMedian(arr);
    i64 end = millis();
    jout.println(((String(u"正式方法的运行时间 : ") + (end - start)) +
                  String(u" 毫秒")));
    jout.println(String(u"性能测试结束"));
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code05_MaximizeMedian1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 相邻必选的子序列最大中位数
// 给定一个长度为n的数组arr
// 合法子序列定义为，任意相邻的两个数至少要有一个被挑选所组成的子序列
// 求所有合法子序列中，最大中位数是多少
// 中位数的定义为上中位数
// [1, 2, 3, 4]的上中位数是2
// [1, 2, 3, 4, 5]的上中位数是3
// 2 <=  n <= 10^5
// 1 <= arr[i] <= 10^9
// 来自真实大厂笔试，对数器验证
        // 正式方法
        // 时间复杂度O(n * log n)
        // 任意相邻的两数至少选一个来生成子序列
        // 到底有没有一个合法子序列，能让其中>=x的数达到一半以上
        // 任意相邻的两数至少选一个来生成子序列
        // 返回合法子序列的最大累加和
                        // dp[i][0] :
i位置的数字，选和不选皆可，i...范围上形成合法子序列的最大累加和
                        // dp[i][1] :
i位置的数字，一定要选，i...范围上形成合法子序列的最大累加和
        // 暴力方法
        // 为了验证
        // 暴力方法
        // 为了验证
        // 为了测试
        // 为了测试
*/

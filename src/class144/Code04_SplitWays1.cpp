// Source: src/class144/Code04_SplitWays1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_SplitWays1 {
  inline static int MOD = 1000000007;
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_SplitWays1() {}
  static int ways1(Array<int> arr) {
    int ans = 0;
    {
      int b = 1;
      int c = (arr[0] - 1);
      for (; (b < arr[0]); (b++), (c--)) {
        (ans += Code04_SplitWays1::f(arr, 1, b, c));
      }
    }
    return ans;
  }
  static int f(Array<int> arr, int i, int preb, int prec) {
    if ((i == arr.length)) {
      return 1;
    }
    int ans = 0;
    {
      int b = 1;
      int c = (arr[i] - 1);
      for (; (b < arr[i]); (b++), (c--)) {
        if (((preb <= b) && (prec >= c))) {
          (ans += Code04_SplitWays1::f(arr, (i + 1), b, c));
        }
      }
    }
    return ans;
  }
  static int ways2(Array<int> arr) {
    int n = arr.length;
    int k = (arr[0] - 1);
    for (int i = 1; ((i < n) && (k > 0)); (i++)) {
      if ((arr[(i - 1)] > arr[i])) {
        (k -= (arr[(i - 1)] - arr[i]));
      }
    }
    if ((k <= 0)) {
      return 0;
    }
    return Code04_SplitWays1::c(((k + n) - 1), n);
  }
  static int c(int n, int k) {
    i64 fac = 1;
    i64 inv1 = 1;
    i64 inv2 = 1;
    for (int i = 1; (i <= n); (i++)) {
      (fac = jrem((fac * i), MOD));
      if ((i == k)) {
        (inv1 = Code04_SplitWays1::power(fac, (MOD - 2)));
      }
      if ((i == (n - k))) {
        (inv2 = Code04_SplitWays1::power(fac, (MOD - 2)));
      }
    }
    return static_cast<int>(jrem((jrem((fac * inv1), MOD) * inv2), MOD));
  }
  static i64 power(i64 x, i64 p) {
    i64 ans = 1;
    while ((p > 0)) {
      if (((p & 1) == 1)) {
        (ans = jrem((ans * x), MOD));
      }
      (x = jrem((x * x), MOD));
      (p = jshr(p, 1));
    }
    return ans;
  }
  static Array<int> randomArray(int n, int v) {
    Array<int> ans = make_array<int>(n);
    for (int i = 0; (i < n); (i++)) {
      (ans[i] = (static_cast<int>((j::random() * v)) + 1));
    }
    return ans;
  }
  static void java_main(Array<String> args) {
    jout.println(String(u"功能测试开始"));
    int N = 10;
    int V = 20;
    int test = 20000;
    for (int i = 0; (i < test); (i++)) {
      int n = (static_cast<int>((j::random() * N)) + 1);
      Array<int> arr = Code04_SplitWays1::randomArray(n, V);
      int ans1 = Code04_SplitWays1::ways1(arr);
      int ans2 = Code04_SplitWays1::ways2(arr);
      if ((ans1 != ans2)) {
        jout.println(String(u"出错了!"));
      }
    }
    jout.println(String(u"功能测试结束"));
    jout.println(String(u"=========="));
    jout.println(String(u"性能测试开始"));
    int n = 10000000;
    int v = 10000000;
    i64 start = {};
    i64 end = {};
    Array<int> arr = make_array<int>(n);
    jout.println(String(u"随机生成的数据测试"));
    jout.println((String(u"数组长度 : ") + n));
    jout.println(
        ((((String(u"数值范围 : [") + 1) + String(u",")) + v) + String(u"]")));
    for (int i = 0; (i < n); (i++)) {
      (arr[i] = (static_cast<int>((j::random() * v)) + 1));
    }
    (start = millis());
    Code04_SplitWays1::ways2(arr);
    (end = millis());
    jout.println(((String(u"运行时间 : ") + (end - start)) + String(u" 毫秒")));
    jout.println();
    jout.println(String(u"运行最慢的数据测试"));
    jout.println((String(u"数组长度 : ") + n));
    jout.println((String(u"数值都是 : ") + v));
    jout.println(String(u"这种情况其实是复杂度最高的情况"));
    for (int i = 0; (i < n); (i++)) {
      (arr[i] = v);
    }
    (start = millis());
    Code04_SplitWays1::ways2(arr);
    (end = millis());
    jout.println(((String(u"运行时间 : ") + (end - start)) + String(u" 毫秒")));
    jout.println(String(u"性能测试结束"));
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code04_SplitWays1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 分割的方法数
// 给定一个长度为n的数组A, 将其分割成数组B和数组C，满足A[i] = B[i] + C[i]
// 也就是一个数字分成两份，然后各自进入B和C，要求B[i], C[i] >= 1
// 同时要求，B数组从左到右不能降序，C数组从左到右不能升序
// 比如，A = { 5, 4, 5 }，一种有效的划分，B = { 2, 2, 3 }，C = { 3, 2, 2 }
// 返回有多少种有效的划分方式
// 1 <= n <= 10^7
// 1 <= A[i] <= 10^7
// 最终结果可能很大，答案对 1000000007 取模
// 来自真实大厂笔试题，该实现为对数器版本
// 有同学找到了测试链接，就是Code04_SplitWays2文件
        // 暴力方法
        // 为了验证
        // 正式方法
        // 转化成杨辉三角
        // 组合公式
        // 乘法快速幂
        // 为了测试
        // 为了测试
*/

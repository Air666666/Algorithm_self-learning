// Source: src/class127/Code03_MultiplyPositiveNegative1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_MultiplyPositiveNegative1 {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_MultiplyPositiveNegative1() {}
  static Array<int> num(Array<int> arr) {
    Array<int> cnt = make_array<int>(2);
    (cnt[0] = 1);
    (cnt[1] = 0);
    int ans1 = 0;
    int ans2 = 0;
    {
      int i = 0;
      int cur = 0;
      for (; (i < arr.length); (i++)) {
        (cur ^= ((arr[i] > 0) ? 0 : 1));
        (ans1 += cnt[cur]);
        (ans2 += cnt[(cur ^ 1)]);
        (cnt[cur]++);
      }
    }
    return Array<int>{ans1, ans2};
  }
  static Array<int> right(Array<int> arr) {
    int n = arr.length;
    int ans1 = 0;
    int ans2 = 0;
    for (int i = 0; (i < n); (i++)) {
      i64 cur = 1;
      for (int j = i; (j < n); (j++)) {
        (cur = (cur * arr[j]));
        if ((cur > 0)) {
          (ans1++);
        } else {
          (ans2++);
        }
      }
    }
    return Array<int>{ans1, ans2};
  }
  static Array<int> randomArray(int n, int v) {
    Array<int> ans = make_array<int>(n);
    for (int i = 0; (i < n); (i++)) {
      do {
        (ans[i] = (static_cast<int>(((j::random() * v) * 2)) - v));
      } while ((ans[i] == 0));
    }
    return ans;
  }
  static void java_main(Array<String> args) {
    int n = 20;
    int v = 10;
    int testTime = 10000;
    jout.println(String(u"测试开始"));
    for (int i = 0; (i < testTime); (i++)) {
      int size = static_cast<int>((j::random() * n));
      Array<int> arr = Code03_MultiplyPositiveNegative1::randomArray(size, v);
      Array<int> ans1 = Code03_MultiplyPositiveNegative1::num(arr);
      Array<int> ans2 = Code03_MultiplyPositiveNegative1::right(arr);
      if (((ans1[0] != ans2[0]) || (ans1[1] != ans2[1]))) {
        jout.println(String(u"出错了!"));
      }
    }
    jout.println(String(u"测试结束"));
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code03_MultiplyPositiveNegative1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 相乘为正或负的子数组数量
// 给定一个长度为n的数组arr，其中所有值都不是0
// 返回有多少个子数组相乘的结果是正
// 返回有多少个子数组相乘的结果是负
// 1 <= n <= 10^6
// -10^9 <= arr[i] <= +10^9，arr[i]一定不是0
// 来自真实大厂笔试，对数器验证
        // 正式方法
                // 0 : 正状态
                // 1 : 负状态
                // ^ : 乘法运算
        // 暴力方法
        // 为了验证
        // 为了验证
                // 正式方法无所谓，怎么都正确
                // 但是对数器方法是暴力乘起来，所以n和v不要太大，防止溢出
*/

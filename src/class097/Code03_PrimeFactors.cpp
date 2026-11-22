// Source: src/class097/Code03_PrimeFactors.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_PrimeFactors {
  inline static int MAXV = 100001;
  inline static Array<int> factors = make_array<int>(MAXV);
  inline static int MAXN = 20001;
  inline static Array<int> father = make_array<int>(MAXN);
  inline static Array<int> size = make_array<int>(MAXN);
  inline static int n = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_PrimeFactors() {}
  static void java_main(Array<String> args) {
    int n = 4012100;
    Code03_PrimeFactors::f(n);
  }
  static void f(int n) {
    for (int i = 2; ((i * i) <= n); (i++)) {
      if ((jrem(n, i) == 0)) {
        jout.println(i);
        while ((jrem(n, i) == 0)) {
          (n /= i);
        }
      }
    }
    if ((n > 1)) {
      jout.println(n);
    }
  }
  static void build() {
    for (int i = 0; (i < n); (i++)) {
      (father[i] = i);
      (size[i] = 1);
    }
    j::fill(factors, (-1));
  }
  static int find(int i) {
    if ((i != father[i])) {
      (father[i] = Code03_PrimeFactors::find(father[i]));
    }
    return father[i];
  }
  static void union_method(int x, int y) {
    int fx = Code03_PrimeFactors::find(x);
    int fy = Code03_PrimeFactors::find(y);
    if ((fx != fy)) {
      (father[fx] = fy);
      (size[fy] += size[fx]);
    }
  }
  static int maxSize() {
    int ans = 0;
    for (int i = 0; (i < n); (i++)) {
      (ans = jmax(ans, size[i]));
    }
    return ans;
  }
  static int largestComponentSize(Array<int> arr) {
    (n = arr.length);
    Code03_PrimeFactors::build();
    {
      int i = 0;
      int x = {};
      for (; (i < n); (i++)) {
        (x = arr[i]);
        for (int j = 2; ((j * j) <= x); (j++)) {
          if ((jrem(x, j) == 0)) {
            if ((factors[j] == (-1))) {
              (factors[j] = i);
            } else {
              Code03_PrimeFactors::union_method(factors[j], i);
            }
            while ((jrem(x, j) == 0)) {
              (x /= j);
            }
          }
        }
        if ((x > 1)) {
          if ((factors[x] == (-1))) {
            (factors[x] = i);
          } else {
            Code03_PrimeFactors::union_method(factors[x], i);
          }
        }
      }
    }
    return Code03_PrimeFactors::maxSize();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code03_PrimeFactors::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 数字n拆分质数因子
        // 展示分解质因子过程
        // 打印所有n的质因子，时间复杂度O(根号n)
        // 按公因数计算最大组件大小
        // 给定一个由不同正整数的组成的非空数组 nums
        // 如果 nums[i] 和 nums[j]
有一个大于1的公因子，那么这两个数之间有一条无向边
        // 返回 nums中最大连通组件的大小。
        // 测试链接 :
https://leetcode.cn/problems/largest-component-size-by-common-factor/
        // 提交以下代码，可以通过所有测试用例
        // factors[a] = b
        // a这个质数因子，最早被下标b的数字拥有
        // 讲解056、讲解057 - 并查集模版
        // 正式方法
        // 时间复杂度O(n * 根号v)
*/

// Source: src/class146/Code05_PerfectShuffle.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code05_PerfectShuffle {
  inline static int MAXN = 20;
  inline static Array<int> start = make_array<int>(MAXN);
  inline static Array<int> split = make_array<int>(MAXN);
  inline static int size = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code05_PerfectShuffle() {}
  static void shuffle1(Array<int> arr, int l, int r) {
    int n = ((r - l) + 1);
    Array<int> help = make_array<int>(n);
    {
      int l1 = l;
      int r1 = (jdiv((l + r), 2) + 1);
      int j = 0;
      for (; (j < n); (l1++), (r1++)) {
        (help[(j++)] = arr[r1]);
        (help[(j++)] = arr[l1]);
      }
    }
    {
      int i = l;
      int j = 0;
      for (; (j < n); (i++), (j++)) {
        (arr[i] = help[j]);
      }
    }
  }
  static void shuffle2(Array<int> arr, int l, int r) {
    int n = ((r - l) + 1);
    Code05_PerfectShuffle::build(n);
    {
      int i = size;
      int m = {};
      for (; (n > 0);) {
        if ((split[i] <= n)) {
          (m = jdiv((l + r), 2));
          Code05_PerfectShuffle::rotate(arr, (l + jdiv(split[i], 2)), m,
                                        (m + jdiv(split[i], 2)));
          Code05_PerfectShuffle::circle(arr, l, ((l + split[i]) - 1), i);
          (l += split[i]);
          (n -= split[i]);
        } else {
          (i--);
        }
      }
    }
  }
  static void build(int n) {
    (size = 0);
    {
      int s = 1;
      int p = 2;
      for (; (p <= n); (s *= 3), (p = ((s * 3) - 1))) {
        (start[(++size)] = s);
        (split[size] = p);
      }
    }
  }
  static void rotate(Array<int> arr, int l, int m, int r) {
    Code05_PerfectShuffle::reverse(arr, l, m);
    Code05_PerfectShuffle::reverse(arr, (m + 1), r);
    Code05_PerfectShuffle::reverse(arr, l, r);
  }
  static void reverse(Array<int> arr, int l, int r) {
    while ((l < r)) {
      [&]() {
        auto jargument_0 = arr;
        auto jargument_1 = (l++);
        auto jargument_2 = (r--);
        return Code05_PerfectShuffle::swap(jargument_0, jargument_1,
                                           jargument_2);
      }();
    }
  }
  static void swap(Array<int> arr, int i, int j) {
    int tmp = arr[i];
    (arr[i] = arr[j]);
    (arr[j] = tmp);
  }
  static void circle(Array<int> arr, int l, int r, int i) {
    {
      int j = 1;
      int init = {};
      int cur = {};
      int next = {};
      int curv = {};
      int nextv = {};
      for (; (j <= i); (j++)) {
        (init = (cur = ((l + start[j]) - 1)));
        (next = Code05_PerfectShuffle::to(cur, l, r));
        (curv = arr[cur]);
        while ((next != init)) {
          (nextv = arr[next]);
          (arr[next] = curv);
          (curv = nextv);
          (cur = next);
          (next = Code05_PerfectShuffle::to(cur, l, r));
        }
        (arr[init] = curv);
      }
    }
  }
  static int to(int i, int l, int r) {
    if ((i <= jshr((l + r), 1))) {
      return (i + ((i - l) + 1));
    } else {
      return (i - ((r - i) + 1));
    }
  }
  static Array<int> randomArray(int n, int v) {
    Array<int> ans = make_array<int>(n);
    for (int i = 0; (i < n); (i++)) {
      (ans[i] = static_cast<int>((j::random() * v)));
    }
    return ans;
  }
  static Array<int> copyArray(Array<int> arr) {
    int n = arr.length;
    Array<int> ans = make_array<int>(n);
    for (int i = 0; (i < n); (i++)) {
      (ans[i] = arr[i]);
    }
    return ans;
  }
  static void java_main(Array<String> args) {
    int n = 10000;
    int v = 100000;
    Array<int> arr1 = Code05_PerfectShuffle::randomArray(n, v);
    Array<int> arr2 = Code05_PerfectShuffle::copyArray(arr1);
    int test = 50000;
    jout.println(String(u"测试开始"));
    {
      int i = 1;
      int a = {};
      int b = {};
      int l = {};
      int r = {};
      for (; (i <= test); (i++)) {
        (a = static_cast<int>((j::random() * n)));
        (b = static_cast<int>((j::random() * n)));
        (l = jmin(a, b));
        (r = jmax(a, b));
        if (((((r - l) + 1) & 1) == 0)) {
          Code05_PerfectShuffle::shuffle1(arr1, l, r);
          Code05_PerfectShuffle::shuffle2(arr2, l, r);
        }
      }
    }
    for (int i = 0; (i < n); (i++)) {
      if ((arr1[i] != arr2[i])) {
        jout.println(String(u"出错了!"));
      }
    }
    jout.println(String(u"测试结束"));
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code05_PerfectShuffle::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 完美洗牌算法
// 给定数组arr，给定某个范围arr[l..r]，该范围长度为n，n是偶数
// 因为n是偶数，所以给定的范围可以分成左右两个部分，arr[l1, l2, ...lk, r1, r2,
...rk]
// 请把arr[l..r]范围上的数字调整成arr[r1, l1, r2, l2, ... rk,
lk]，其他位置的数字不变
// 要求时间复杂度O(n)，额外空间复杂度O(1)，对数器验证
        // 申请额外空间的做法
        // 保证调整的范围是偶数长度
        // 为了测试
        // 正式方法
        // 完美洗牌算法
        // 保证调整的范围是偶数长度
        // 生成随机数组
        // 为了测试
        // 拷贝数组
        // 为了测试
*/

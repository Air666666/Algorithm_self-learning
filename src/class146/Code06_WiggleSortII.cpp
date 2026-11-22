// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/wiggle-sort-ii/

// Source: src/class146/Code06_WiggleSortII.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code06_WiggleSortII {
  inline static int first = {};
  inline static int last = {};
  inline static int MAXN = 20;
  inline static Array<int> start = make_array<int>(MAXN);
  inline static Array<int> split = make_array<int>(MAXN);
  inline static int size = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code06_WiggleSortII() {}
  static void wiggleSort(Array<int> arr) {
    int n = arr.length;
    Code06_WiggleSortII::randomizedSelect(arr, n, jdiv(n, 2));
    if (((n & 1) == 0)) {
      Code06_WiggleSortII::shuffle(arr, 0, (n - 1));
      Code06_WiggleSortII::reverse(arr, 0, (n - 1));
    } else {
      Code06_WiggleSortII::shuffle(arr, 1, (n - 1));
    }
  }
  static int randomizedSelect(Array<int> arr, int n, int i) {
    int ans = 0;
    {
      int l = 0;
      int r = (n - 1);
      for (; (l <= r);) {
        Code06_WiggleSortII::partition(
            arr, l, r,
            arr[(l + static_cast<int>((j::random() * ((r - l) + 1))))]);
        if ((i < first)) {
          (r = (first - 1));
        } else if ((i > last)) {
          (l = (last + 1));
        } else {
          (ans = arr[i]);
          break;
        }
      }
    }
    return ans;
  }
  static void partition(Array<int> arr, int l, int r, int x) {
    (first = l);
    (last = r);
    int i = l;
    while ((i <= last)) {
      if ((arr[i] == x)) {
        (i++);
      } else if ((arr[i] < x)) {
        [&]() {
          auto jargument_0 = arr;
          auto jargument_1 = (first++);
          auto jargument_2 = (i++);
          return Code06_WiggleSortII::swap(jargument_0, jargument_1,
                                           jargument_2);
        }();
      } else {
        Code06_WiggleSortII::swap(arr, i, (last--));
      }
    }
  }
  static void shuffle(Array<int> arr, int l, int r) {
    int n = ((r - l) + 1);
    Code06_WiggleSortII::build(n);
    {
      int i = size;
      int m = {};
      for (; (n > 0);) {
        if ((split[i] <= n)) {
          (m = jdiv((l + r), 2));
          Code06_WiggleSortII::rotate(arr, (l + jdiv(split[i], 2)), m,
                                      (m + jdiv(split[i], 2)));
          Code06_WiggleSortII::circle(arr, l, ((l + split[i]) - 1), i);
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
    Code06_WiggleSortII::reverse(arr, l, m);
    Code06_WiggleSortII::reverse(arr, (m + 1), r);
    Code06_WiggleSortII::reverse(arr, l, r);
  }
  static void reverse(Array<int> arr, int l, int r) {
    while ((l < r)) {
      [&]() {
        auto jargument_0 = arr;
        auto jargument_1 = (l++);
        auto jargument_2 = (r--);
        return Code06_WiggleSortII::swap(jargument_0, jargument_1, jargument_2);
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
        (next = Code06_WiggleSortII::to(cur, l, r));
        (curv = arr[cur]);
        while ((next != init)) {
          (nextv = arr[next]);
          (arr[next] = curv);
          (curv = nextv);
          (cur = next);
          (next = Code06_WiggleSortII::to(cur, l, r));
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
};

/* Original teaching comments:
// 摇摆排序ii(满足全部进阶要求)
// 给定一个数组arr，重新排列数组，确保满足：arr[0] < arr[1] > arr[2] < arr[3] >
...
// 题目保证输入的数组一定有解，要求时间复杂度O(n)，额外空间复杂度O(1)
// 测试链接 : https://leetcode.cn/problems/wiggle-sort-ii/
        // 最优解
        // 时间复杂度O(n)，额外空间复杂度O(1)
        // 随机选择算法，不会去看讲解024
        // 无序数组中找到，如果排序之后，在i位置的数x，顺便把数组调整为
        // 左边是小于x的部分    中间是等于x的部分    右边是大于x的部分
        // 时间复杂度O(n)，额外空间复杂度O(1)
        // 完美洗牌算法
        // 时间复杂度O(n)，额外空间复杂度O(1)
*/

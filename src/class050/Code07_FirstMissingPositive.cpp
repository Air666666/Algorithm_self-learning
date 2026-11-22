// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/first-missing-positive/

// Source: src/class050/Code07_FirstMissingPositive.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code07_FirstMissingPositive {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code07_FirstMissingPositive() {}
  static int firstMissingPositive(Array<int> arr) {
    int l = 0;
    int r = arr.length;
    while ((l < r)) {
      if ((arr[l] == (l + 1))) {
        (l++);
      } else if ((((arr[l] <= l) || (arr[l] > r)) ||
                  (arr[(arr[l] - 1)] == arr[l]))) {
        Code07_FirstMissingPositive::swap(arr, l, (--r));
      } else {
        Code07_FirstMissingPositive::swap(arr, l, (arr[l] - 1));
      }
    }
    return (l + 1);
  }
  static void swap(Array<int> arr, int i, int j) {
    int tmp = arr[i];
    (arr[i] = arr[j]);
    (arr[j] = tmp);
  }
};

/* Original teaching comments:
// 缺失的第一个正数
// 给你一个未排序的整数数组 nums ，请你找出其中没有出现的最小的正整数。
// 请你实现时间复杂度为 O(n) 并且只使用常数级别额外空间的解决方案。
// 测试链接 : https://leetcode.cn/problems/first-missing-positive/
        // 时间复杂度O(n)，额外空间复杂度O(1)
                // l的左边，都是做到i位置上放着i+1的区域
                // 永远盯着l位置的数字看，看能不能扩充(l++)
                // [r....]垃圾区
                //
最好的状况下，认为1~r是可以收集全的，每个数字收集1个，不能有垃圾
                // 有垃圾呢？预期就会变差(r--)
*/

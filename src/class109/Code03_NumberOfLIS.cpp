// Source: src/class109/Code03_NumberOfLIS.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_NumberOfLIS {
  inline static int MAXN = 2001;
  inline static Array<int> sort = make_array<int>(MAXN);
  inline static Array<int> treeMaxLen = make_array<int>(MAXN);
  inline static Array<int> treeMaxLenCnt = make_array<int>(MAXN);
  inline static int m = {};
  inline static int maxLen = {};
  inline static int maxLenCnt = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_NumberOfLIS() {}
  static int lowbit(int i) { return (i & (-i)); }
  static void query(int i) {
    (maxLen = (maxLenCnt = 0));
    while ((i > 0)) {
      if ((maxLen == treeMaxLen[i])) {
        (maxLenCnt += treeMaxLenCnt[i]);
      } else if ((maxLen < treeMaxLen[i])) {
        (maxLen = treeMaxLen[i]);
        (maxLenCnt = treeMaxLenCnt[i]);
      }
      (i -= Code03_NumberOfLIS::lowbit(i));
    }
  }
  static void add(int i, int len, int cnt) {
    while ((i <= m)) {
      if ((treeMaxLen[i] == len)) {
        (treeMaxLenCnt[i] += cnt);
      } else if ((treeMaxLen[i] < len)) {
        (treeMaxLen[i] = len);
        (treeMaxLenCnt[i] = cnt);
      }
      (i += Code03_NumberOfLIS::lowbit(i));
    }
  }
  static int findNumberOfLIS(Array<int> nums) {
    int n = nums.length;
    for (int i = 1; (i <= n); (i++)) {
      (sort[i] = nums[(i - 1)]);
    }
    j::sort(sort, 1, (n + 1));
    (m = 1);
    for (int i = 2; (i <= n); (i++)) {
      if ((sort[m] != sort[i])) {
        (sort[(++m)] = sort[i]);
      }
    }
    j::fill(treeMaxLen, 1, (m + 1), 0);
    j::fill(treeMaxLenCnt, 1, (m + 1), 0);
    int i = {};
    for (int num : nums) {
      (i = Code03_NumberOfLIS::rank(num));
      Code03_NumberOfLIS::query((i - 1));
      if ((maxLen == 0)) {
        Code03_NumberOfLIS::add(i, 1, 1);
      } else {
        Code03_NumberOfLIS::add(i, (maxLen + 1), maxLenCnt);
      }
    }
    Code03_NumberOfLIS::query(m);
    return maxLenCnt;
  }
  static int rank(int v) {
    int ans = 0;
    int l = 1;
    int r = m;
    int mid = {};
    while ((l <= r)) {
      (mid = jdiv((l + r), 2));
      if ((sort[mid] >= v)) {
        (ans = mid);
        (r = (mid - 1));
      } else {
        (l = (mid + 1));
      }
    }
    return ans;
  }
};

/* Original teaching comments:
// 最长递增子序列的个数
// 给定一个未排序的整数数组nums，返回最长递增子序列的个数
// 测试链接 :
https://leetcode.cn/problems/number-of-longest-increasing-subsequence/
// 本题在讲解072，最长递增子序列问题与扩展，就做出过预告
// 具体可以看讲解072视频最后的部分
// 用树状数组实现时间复杂度O(n * logn)
        // 维护信息 : 以数值i结尾的最长递增子序列，长度是多少
        // 维护的信息以树状数组组织
        // 维护信息 : 以数值i结尾的最长递增子序列，个数是多少
        // 维护的信息以树状数组组织
        // 查询结尾数值<=i的最长递增子序列的长度，赋值给maxLen
        // 查询结尾数值<=i的最长递增子序列的个数，赋值给maxLenCnt
        // 以数值i结尾的最长递增子序列，长度达到了len，个数增加了cnt
        // 更新树状数组
                                // 如果查出数值<=i-1结尾的最长递增子序列长度为0
                                //
那么说明，以值i结尾的最长递增子序列长度就是1，计数增加1
                                //
如果查出数值<=i-1结尾的最长递增子序列长度为maxLen != 0
                                //
那么说明，以值i结尾的最长递增子序列长度就是maxLen + 1，计数增加maxLenCnt
*/

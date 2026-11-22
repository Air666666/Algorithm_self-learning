// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/the-skyline-problem/

// Source: src/class115/Code02_SkylineLeetcode1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_SkylineLeetcode1 {
  inline static int MAXN = 100001;
  inline static Array<int> xsort = make_array<int>(MAXN);
  inline static Array<int> height = make_array<int>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_SkylineLeetcode1() {}
  static JList<JList<int>> getSkyline(Array<Array<int>> arr) {
    int n = arr.length;
    int m = Code02_SkylineLeetcode1::prepare(arr, n);
    JHeap<Array<int>> heap = JHeap<Array<int>>(
        [=](Array<int> a, Array<int> b) { return (b[0] - a[0]); });
    {
      int i = 1;
      int j = 0;
      for (; (i <= m); (i++)) {
        for (; ((j < n) && (arr[j][0] <= i)); (j++)) {
          heap.add(Array<int>{arr[j][2], arr[j][1]});
        }
        while (((!heap.isEmpty()) && (heap.peek()[1] < i))) {
          heap.poll();
        }
        if ((!heap.isEmpty())) {
          (height[i] = heap.peek()[0]);
        }
      }
    }
    JList<JList<int>> ans = JList<JList<int>>();
    {
      int i = 1;
      int pre = 0;
      for (; (i <= m); (i++)) {
        if ((pre != height[i])) {
          ans.add(j::asList(xsort[i], height[i]));
        }
        (pre = height[i]);
      }
    }
    return ans;
  }
  static int prepare(Array<Array<int>> arr, int n) {
    int size = 0;
    for (int i = 0; (i < n); (i++)) {
      (xsort[(++size)] = arr[i][0]);
      (xsort[(++size)] = (arr[i][1] - 1));
      (xsort[(++size)] = arr[i][1]);
    }
    j::sort(xsort, 1, (size + 1));
    int m = 1;
    for (int i = 1; (i <= size); (i++)) {
      if ((xsort[m] != xsort[i])) {
        (xsort[(++m)] = xsort[i]);
      }
    }
    for (int i = 0; (i < n); (i++)) {
      (arr[i][0] = Code02_SkylineLeetcode1::rank(m, arr[i][0]));
      (arr[i][1] = Code02_SkylineLeetcode1::rank(m, (arr[i][1] - 1)));
    }
    j::sort(arr, 0, n,
            [=](Array<int> a, Array<int> b) { return (a[0] - b[0]); });
    j::fill(height, 1, (m + 1), 0);
    return m;
  }
  static int rank(int n, int v) {
    int ans = 0;
    int l = 1;
    int r = n;
    int mid = {};
    while ((l <= r)) {
      (mid = jshr((l + r), 1));
      if ((xsort[mid] >= v)) {
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
// 天际线问题(Leetcode测试)
// 测试链接 : https://leetcode.cn/problems/the-skyline-problem/
        // 堆结构是现成结构
                // 0 : 高度
                // 1 : 影响到的位置
        // 准备工作如下
        // 1) 收集大楼左边界、右边界-1、右边界的值
        // 2) 收集的所有值排序、去重
        // 3) 大楼的左边界和右边界，修改成排名值
        // 4) 大楼根据左边界排序
        // 5) 清空height数组
        // 6) 返回离散值的个数
                // 大楼的左边界、右边界-1、右边界，三个值都去离散化
                // 排序之后去重，去重后的数值有m个
                // 修改大楼影响到的左右边界，都变成排名值
                        // 大楼影响到的右边界，减少1！
                        // 课上重点说明的内容
                // 所有大楼根据左边界排序
                // 高度数组清空
                // 返回有多少个不同的离散值
        // 查询数值v的排名(离散值)
*/

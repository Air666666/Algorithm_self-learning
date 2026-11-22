// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/the-skyline-problem/

// Source: src/class115/Code02_SkylineLeetcode2.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_SkylineLeetcode2 {
  inline static int MAXN = 100001;
  inline static Array<int> xsort = make_array<int>(MAXN);
  inline static Array<int> height = make_array<int>(MAXN);
  inline static Array<Array<int>> heap = make_array<int>(MAXN, 2);
  inline static int heapSize = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_SkylineLeetcode2() {}
  static JList<JList<int>> getSkyline(Array<Array<int>> arr) {
    int n = arr.length;
    int m = Code02_SkylineLeetcode2::prepare(arr, n);
    {
      int i = 1;
      int j = 0;
      for (; (i <= m); (i++)) {
        for (; ((j < n) && (arr[j][0] <= i)); (j++)) {
          Code02_SkylineLeetcode2::push(arr[j][2], arr[j][1]);
        }
        while (((!Code02_SkylineLeetcode2::isEmpty()) &&
                (Code02_SkylineLeetcode2::peekEnd() < i))) {
          Code02_SkylineLeetcode2::poll();
        }
        if ((!Code02_SkylineLeetcode2::isEmpty())) {
          (height[i] = Code02_SkylineLeetcode2::peekHeight());
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
      (arr[i][0] = Code02_SkylineLeetcode2::rank(m, arr[i][0]));
      (arr[i][1] = Code02_SkylineLeetcode2::rank(m, (arr[i][1] - 1)));
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
  static bool isEmpty() { return (heapSize == 0); }
  static int peekHeight() { return heap[0][0]; }
  static int peekEnd() { return heap[0][1]; }
  static void push(int h, int e) {
    (heap[heapSize][0] = h);
    (heap[heapSize][1] = e);
    Code02_SkylineLeetcode2::heapInsert((heapSize++));
  }
  static void poll() {
    Code02_SkylineLeetcode2::swap(0, (--heapSize));
    Code02_SkylineLeetcode2::heapify(0);
  }
  static void heapInsert(int i) {
    while ((heap[i][0] > heap[jdiv((i - 1), 2)][0])) {
      Code02_SkylineLeetcode2::swap(i, jdiv((i - 1), 2));
      (i = jdiv((i - 1), 2));
    }
  }
  static void heapify(int i) {
    int l = ((i * 2) + 1);
    while ((l < heapSize)) {
      int best =
          ((((l + 1) < heapSize) && (heap[(l + 1)][0] > heap[l][0])) ? (l + 1)
                                                                     : l);
      (best = ((heap[best][0] > heap[i][0]) ? best : i));
      if ((best == i)) {
        break;
      }
      Code02_SkylineLeetcode2::swap(best, i);
      (i = best);
      (l = ((i * 2) + 1));
    }
  }
  static void swap(int i, int j) {
    Array<int> tmp = heap[i];
    (heap[i] = heap[j]);
    (heap[j] = tmp);
  }
};

/* Original teaching comments:
// 天际线问题(Leetcode测试)
// 测试链接 : https://leetcode.cn/problems/the-skyline-problem/
        // 堆结构由自己实现
*/

// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/online-majority-element-in-subarray/

// Source: src/class116/Code06_FindSeaKing.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code06_FindSeaKing {
  struct MajorityChecker;
  struct MajorityChecker {
    inline static int MAXN = 20001;
    inline static Array<Array<int>> nums = make_array<int>(MAXN, 2);
    inline static Array<int> cand = make_array<int>(jshl(MAXN, 2));
    inline static Array<int> hp = make_array<int>(jshl(MAXN, 2));
    inline static int n = {};
    String toString() const { return j::str(static_cast<const void *>(this)); }
    MajorityChecker(Array<int> arr) {
      (n = arr.length);
      MajorityChecker::buildCnt(arr);
      MajorityChecker::buildTree(arr, 1, n, 1);
    }
    int query(int l, int r, int t) {
      Array<int> ch = MajorityChecker::findCandidate((l + 1), (r + 1), 1, n, 1);
      int candidate = ch[0];
      return ((MajorityChecker::cnt(l, r, candidate) >= t) ? candidate : (-1));
    }
    void buildCnt(Array<int> arr) {
      for (int i = 0; (i < n); (i++)) {
        (nums[i][0] = arr[i]);
        (nums[i][1] = i);
      }
      j::sort(nums, 0, n, [=](Array<int> a, Array<int> b) {
        return ((a[0] != b[0]) ? (a[0] - b[0]) : (a[1] - b[1]));
      });
    }
    int cnt(int l, int r, int v) {
      return [&]() {
        auto jleft = MajorityChecker::bs(v, r);
        auto jright = MajorityChecker::bs(v, (l - 1));
        return (jleft - jright);
      }();
    }
    int bs(int v, int i) {
      int left = 0;
      int right = (n - 1);
      int mid = {};
      int find = (-1);
      while ((left <= right)) {
        (mid = jshr((left + right), 1));
        if (((nums[mid][0] < v) ||
             ((nums[mid][0] == v) && (nums[mid][1] <= i)))) {
          (find = mid);
          (left = (mid + 1));
        } else {
          (right = (mid - 1));
        }
      }
      return (find + 1);
    }
    void up(int i) {
      int lc = cand[jshl(i, 1)];
      int lh = hp[jshl(i, 1)];
      int rc = cand[(jshl(i, 1) | 1)];
      int rh = hp[(jshl(i, 1) | 1)];
      (cand[i] = (((lc == rc) || (lh >= rh)) ? lc : rc));
      (hp[i] = ((lc == rc) ? (lh + rh) : std::abs((lh - rh))));
    }
    void buildTree(Array<int> arr, int l, int r, int i) {
      if ((l == r)) {
        (cand[i] = arr[(l - 1)]);
        (hp[i] = 1);
      } else {
        int mid = jshr((l + r), 1);
        MajorityChecker::buildTree(arr, l, mid, jshl(i, 1));
        MajorityChecker::buildTree(arr, (mid + 1), r, (jshl(i, 1) | 1));
        MajorityChecker::up(i);
      }
    }
    Array<int> findCandidate(int jobl, int jobr, int l, int r, int i) {
      if (((jobl <= l) && (r <= jobr))) {
        return Array<int>{cand[i], hp[i]};
      } else {
        int mid = jshr((l + r), 1);
        if ((jobr <= mid)) {
          return MajorityChecker::findCandidate(jobl, jobr, l, mid, jshl(i, 1));
        }
        if ((jobl > mid)) {
          return MajorityChecker::findCandidate(jobl, jobr, (mid + 1), r,
                                                (jshl(i, 1) | 1));
        }
        Array<int> lch =
            MajorityChecker::findCandidate(jobl, jobr, l, mid, jshl(i, 1));
        Array<int> rch = MajorityChecker::findCandidate(jobl, jobr, (mid + 1),
                                                        r, (jshl(i, 1) | 1));
        int lc = lch[0];
        int lh = lch[1];
        int rc = rch[0];
        int rh = rch[1];
        int c = (((lc == rc) || (lh >= rh)) ? lc : rc);
        int h = ((lc == rc) ? (lh + rh) : std::abs((lh - rh)));
        return Array<int>{c, h};
      }
    }
  };
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code06_FindSeaKing() {}
};

/* Original teaching comments:
// 子数组里的海王数
//
子数组的海王数首先必须是子数组上出现次数最多的数(水王数)，并且要求出现次数>=t，t是参数
// 设计一个数据结构并实现如下两个方法
// 1) MajorityChecker(int[] arr) : 用数组arr对MajorityChecker初始化
// 2) int query(int l, int r, int t) : 返回arr[l...r]上的海王数，不存在返回-1
// 测试链接 : https://leetcode.cn/problems/online-majority-element-in-subarray/
        // 本实现只使用固定数组结构
        // 其他语言的同学很容易改写
        // 时间复杂度也保证了是最优
                // 维护线段树一段范围，候选是谁
                // 维护线段树一段范围，候选血量
                // arr[0 ~ i]范围上
                // (<v的数) + (==v但下标<=i的数)，有几个
*/

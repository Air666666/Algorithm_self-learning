// Source: src/class114/Code03_SegmentTreeSetminQueryMaxSum1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_SegmentTreeSetminQueryMaxSum1 {
  inline static int MAXN = 100001;
  inline static int LOWEST = (-100001);
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static Array<i64> sum = make_array<i64>(jshl(MAXN, 2));
  inline static Array<int> max = make_array<int>(jshl(MAXN, 2));
  inline static Array<int> cnt = make_array<int>(jshl(MAXN, 2));
  inline static Array<int> sem = make_array<int>(jshl(MAXN, 2));
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_SegmentTreeSetminQueryMaxSum1() {}
  static void up(int i) {
    int l = jshl(i, 1);
    int r = (jshl(i, 1) | 1);
    (sum[i] = (sum[l] + sum[r]));
    (max[i] = jmax(max[l], max[r]));
    if ((max[l] > max[r])) {
      (cnt[i] = cnt[l]);
      (sem[i] = jmax(sem[l], max[r]));
    } else if ((max[l] < max[r])) {
      (cnt[i] = cnt[r]);
      (sem[i] = jmax(max[l], sem[r]));
    } else {
      (cnt[i] = (cnt[l] + cnt[r]));
      (sem[i] = jmax(sem[l], sem[r]));
    }
  }
  static void down(int i) {
    Code03_SegmentTreeSetminQueryMaxSum1::lazy(jshl(i, 1), max[i]);
    Code03_SegmentTreeSetminQueryMaxSum1::lazy((jshl(i, 1) | 1), max[i]);
  }
  static void lazy(int i, int v) {
    if ((v < max[i])) {
      (sum[i] -= ((static_cast<i64>(max[i]) - v) * cnt[i]));
      (max[i] = v);
    }
  }
  static void build(int l, int r, int i) {
    if ((l == r)) {
      (sum[i] = (max[i] = arr[l]));
      (cnt[i] = 1);
      (sem[i] = LOWEST);
    } else {
      int mid = jshr((l + r), 1);
      Code03_SegmentTreeSetminQueryMaxSum1::build(l, mid, jshl(i, 1));
      Code03_SegmentTreeSetminQueryMaxSum1::build((mid + 1), r,
                                                  (jshl(i, 1) | 1));
      Code03_SegmentTreeSetminQueryMaxSum1::up(i);
    }
  }
  static void setMin(int jobl, int jobr, int jobv, int l, int r, int i) {
    if ((jobv >= max[i])) {
      return;
    }
    if ((((jobl <= l) && (r <= jobr)) && (sem[i] < jobv))) {
      Code03_SegmentTreeSetminQueryMaxSum1::lazy(i, jobv);
    } else {
      Code03_SegmentTreeSetminQueryMaxSum1::down(i);
      int mid = jshr((l + r), 1);
      if ((jobl <= mid)) {
        Code03_SegmentTreeSetminQueryMaxSum1::setMin(jobl, jobr, jobv, l, mid,
                                                     jshl(i, 1));
      }
      if ((jobr > mid)) {
        Code03_SegmentTreeSetminQueryMaxSum1::setMin(
            jobl, jobr, jobv, (mid + 1), r, (jshl(i, 1) | 1));
      }
      Code03_SegmentTreeSetminQueryMaxSum1::up(i);
    }
  }
  static int queryMax(int jobl, int jobr, int l, int r, int i) {
    if (((jobl <= l) && (r <= jobr))) {
      return max[i];
    }
    Code03_SegmentTreeSetminQueryMaxSum1::down(i);
    int mid = jshr((l + r), 1);
    int ans = std::numeric_limits<int>::min();
    if ((jobl <= mid)) {
      (ans = jmax(ans, Code03_SegmentTreeSetminQueryMaxSum1::queryMax(
                           jobl, jobr, l, mid, jshl(i, 1))));
    }
    if ((jobr > mid)) {
      (ans = jmax(ans, Code03_SegmentTreeSetminQueryMaxSum1::queryMax(
                           jobl, jobr, (mid + 1), r, (jshl(i, 1) | 1))));
    }
    return ans;
  }
  static i64 querySum(int jobl, int jobr, int l, int r, int i) {
    if (((jobl <= l) && (r <= jobr))) {
      return sum[i];
    }
    Code03_SegmentTreeSetminQueryMaxSum1::down(i);
    int mid = jshr((l + r), 1);
    i64 ans = 0;
    if ((jobl <= mid)) {
      (ans += Code03_SegmentTreeSetminQueryMaxSum1::querySum(jobl, jobr, l, mid,
                                                             jshl(i, 1)));
    }
    if ((jobr > mid)) {
      (ans += Code03_SegmentTreeSetminQueryMaxSum1::querySum(
           jobl, jobr, (mid + 1), r, (jshl(i, 1) | 1)));
    }
    return ans;
  }
  static void java_main(Array<String> args) {
    jout.println(String(u"测试开始"));
    int n = 2000;
    int v = 5000;
    int t = 1000000;
    Code03_SegmentTreeSetminQueryMaxSum1::randomArray(n, v);
    Array<int> check = make_array<int>((n + 1));
    for (int i = 1; (i <= n); (i++)) {
      (check[i] = arr[i]);
    }
    Code03_SegmentTreeSetminQueryMaxSum1::build(1, n, 1);
    {
      int i = 1;
      int op = {};
      int a = {};
      int b = {};
      int jobl = {};
      int jobr = {};
      int jobv = {};
      for (; (i <= t); (i++)) {
        (op = static_cast<int>((j::random() * 3)));
        (a = (static_cast<int>((j::random() * n)) + 1));
        (b = (static_cast<int>((j::random() * n)) + 1));
        (jobl = jmin(a, b));
        (jobr = jmax(a, b));
        if ((op == 0)) {
          (jobv = (static_cast<int>(((j::random() * v) * 2)) - v));
          Code03_SegmentTreeSetminQueryMaxSum1::setMin(jobl, jobr, jobv, 1, n,
                                                       1);
          Code03_SegmentTreeSetminQueryMaxSum1::checkSetMin(check, jobl, jobr,
                                                            jobv);
        } else if ((op == 1)) {
          int ans1 = Code03_SegmentTreeSetminQueryMaxSum1::queryMax(jobl, jobr,
                                                                    1, n, 1);
          int ans2 = Code03_SegmentTreeSetminQueryMaxSum1::checkQueryMax(
              check, jobl, jobr);
          if ((ans1 != ans2)) {
            jout.println(String(u"出错了!"));
          }
        } else {
          i64 ans1 = Code03_SegmentTreeSetminQueryMaxSum1::querySum(jobl, jobr,
                                                                    1, n, 1);
          i64 ans2 = Code03_SegmentTreeSetminQueryMaxSum1::checkQuerySum(
              check, jobl, jobr);
          if ((ans1 != ans2)) {
            jout.println(String(u"出错了!"));
          }
        }
      }
    }
    jout.println(String(u"测试结束"));
  }
  static void randomArray(int n, int v) {
    for (int i = 1; (i <= n); (i++)) {
      (arr[i] = (static_cast<int>(((j::random() * v) * 2)) - v));
    }
  }
  static void checkSetMin(Array<int> check, int jobl, int jobr, int jobv) {
    for (int i = jobl; (i <= jobr); (i++)) {
      (check[i] = jmin(check[i], jobv));
    }
  }
  static int checkQueryMax(Array<int> check, int jobl, int jobr) {
    int ans = std::numeric_limits<int>::min();
    for (int i = jobl; (i <= jobr); (i++)) {
      (ans = jmax(ans, check[i]));
    }
    return ans;
  }
  static i64 checkQuerySum(Array<int> check, int jobl, int jobr) {
    i64 ans = 0;
    for (int i = jobl; (i <= jobr); (i++)) {
      (ans += check[i]);
    }
    return ans;
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code03_SegmentTreeSetminQueryMaxSum1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 线段树的区间最值操作
// 给定一个长度为n的数组arr，实现支持以下三种操作的结构
// 操作 0 l r x : 把arr[l..r]范围的每个数v，更新成min(v, x)
// 操作 1 l r   : 查询arr[l..r]范围上的最大值
// 操作 2 l r   : 查询arr[l..r]范围上的累加和
// 三种操作一共调用m次，做到时间复杂度O(n * log n + m * log n)
// 对数器验证
        // 假设初始数组中的值不会出现比LOWEST还小的值
        // 假设更新操作时jobv的数值也不会出现比LOWEST还小的值
        // 原始数组
        // 累加和
        // 最大值(既是查询信息也是懒更新信息，课上已经讲解了)
        // 最大值个数
        // 严格次大值(second max)
        // 一定是没有颠覆掉次大值的懒更新信息下发，也就是说：
        // 最大值被压成v，并且v > 严格次大值的情况下
        // sum和max怎么调整
                        // 1) 任务没有全包
                        // 2) jobv <= sem[i]
        // 为了验证
        // 为了验证
        // 为了验证
        // 为了验证
*/

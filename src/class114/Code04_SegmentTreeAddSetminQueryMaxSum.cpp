// Source: src/class114/Code04_SegmentTreeAddSetminQueryMaxSum.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_SegmentTreeAddSetminQueryMaxSum {
  inline static int MAXN = 500001;
  inline static i64 LOWEST = std::numeric_limits<i64>::min();
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static Array<i64> sum = make_array<i64>(jshl(MAXN, 2));
  inline static Array<i64> max = make_array<i64>(jshl(MAXN, 2));
  inline static Array<int> cnt = make_array<int>(jshl(MAXN, 2));
  inline static Array<i64> sem = make_array<i64>(jshl(MAXN, 2));
  inline static Array<i64> maxAdd = make_array<i64>(jshl(MAXN, 2));
  inline static Array<i64> otherAdd = make_array<i64>(jshl(MAXN, 2));
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_SegmentTreeAddSetminQueryMaxSum() {}
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
  static void lazy(int i, int n, i64 maxAddv, i64 otherAddv) {
    (sum[i] += ((maxAddv * cnt[i]) + (otherAddv * (n - cnt[i]))));
    (max[i] += maxAddv);
    (sem[i] += ((sem[i] == LOWEST) ? 0 : otherAddv));
    (maxAdd[i] += maxAddv);
    (otherAdd[i] += otherAddv);
  }
  static void down(int i, int ln, int rn) {
    int l = jshl(i, 1);
    int r = (jshl(i, 1) | 1);
    i64 tmp = jmax(max[l], max[r]);
    if ((max[l] == tmp)) {
      Code04_SegmentTreeAddSetminQueryMaxSum::lazy(l, ln, maxAdd[i],
                                                   otherAdd[i]);
    } else {
      Code04_SegmentTreeAddSetminQueryMaxSum::lazy(l, ln, otherAdd[i],
                                                   otherAdd[i]);
    }
    if ((max[r] == tmp)) {
      Code04_SegmentTreeAddSetminQueryMaxSum::lazy(r, rn, maxAdd[i],
                                                   otherAdd[i]);
    } else {
      Code04_SegmentTreeAddSetminQueryMaxSum::lazy(r, rn, otherAdd[i],
                                                   otherAdd[i]);
    }
    (maxAdd[i] = (otherAdd[i] = 0));
  }
  static void build(int l, int r, int i) {
    if ((l == r)) {
      (sum[i] = (max[i] = arr[l]));
      (sem[i] = LOWEST);
      (cnt[i] = 1);
    } else {
      int mid = jshr((l + r), 1);
      Code04_SegmentTreeAddSetminQueryMaxSum::build(l, mid, jshl(i, 1));
      Code04_SegmentTreeAddSetminQueryMaxSum::build((mid + 1), r,
                                                    (jshl(i, 1) | 1));
      Code04_SegmentTreeAddSetminQueryMaxSum::up(i);
    }
    (maxAdd[i] = (otherAdd[i] = 0));
  }
  static void add(int jobl, int jobr, i64 jobv, int l, int r, int i) {
    if (((jobl <= l) && (r <= jobr))) {
      Code04_SegmentTreeAddSetminQueryMaxSum::lazy(i, ((r - l) + 1), jobv,
                                                   jobv);
    } else {
      int mid = jshr((l + r), 1);
      Code04_SegmentTreeAddSetminQueryMaxSum::down(i, ((mid - l) + 1),
                                                   (r - mid));
      if ((jobl <= mid)) {
        Code04_SegmentTreeAddSetminQueryMaxSum::add(jobl, jobr, jobv, l, mid,
                                                    jshl(i, 1));
      }
      if ((jobr > mid)) {
        Code04_SegmentTreeAddSetminQueryMaxSum::add(jobl, jobr, jobv, (mid + 1),
                                                    r, (jshl(i, 1) | 1));
      }
      Code04_SegmentTreeAddSetminQueryMaxSum::up(i);
    }
  }
  static void setMin(int jobl, int jobr, i64 jobv, int l, int r, int i) {
    if ((jobv >= max[i])) {
      return;
    }
    if ((((jobl <= l) && (r <= jobr)) && (sem[i] < jobv))) {
      Code04_SegmentTreeAddSetminQueryMaxSum::lazy(i, ((r - l) + 1),
                                                   (jobv - max[i]), 0);
    } else {
      int mid = jshr((l + r), 1);
      Code04_SegmentTreeAddSetminQueryMaxSum::down(i, ((mid - l) + 1),
                                                   (r - mid));
      if ((jobl <= mid)) {
        Code04_SegmentTreeAddSetminQueryMaxSum::setMin(jobl, jobr, jobv, l, mid,
                                                       jshl(i, 1));
      }
      if ((jobr > mid)) {
        Code04_SegmentTreeAddSetminQueryMaxSum::setMin(
            jobl, jobr, jobv, (mid + 1), r, (jshl(i, 1) | 1));
      }
      Code04_SegmentTreeAddSetminQueryMaxSum::up(i);
    }
  }
  static i64 querySum(int jobl, int jobr, int l, int r, int i) {
    if (((jobl <= l) && (r <= jobr))) {
      return sum[i];
    } else {
      int mid = jshr((l + r), 1);
      Code04_SegmentTreeAddSetminQueryMaxSum::down(i, ((mid - l) + 1),
                                                   (r - mid));
      i64 ans = 0;
      if ((jobl <= mid)) {
        (ans += Code04_SegmentTreeAddSetminQueryMaxSum::querySum(
             jobl, jobr, l, mid, jshl(i, 1)));
      }
      if ((jobr > mid)) {
        (ans += Code04_SegmentTreeAddSetminQueryMaxSum::querySum(
             jobl, jobr, (mid + 1), r, (jshl(i, 1) | 1)));
      }
      return ans;
    }
  }
  static i64 queryMax(int jobl, int jobr, int l, int r, int i) {
    if (((jobl <= l) && (r <= jobr))) {
      return max[i];
    } else {
      int mid = jshr((l + r), 1);
      Code04_SegmentTreeAddSetminQueryMaxSum::down(i, ((mid - l) + 1),
                                                   (r - mid));
      Box<i64> ans = std::numeric_limits<i64>::min();
      if ((jobl <= mid)) {
        (ans = jmax(ans, Code04_SegmentTreeAddSetminQueryMaxSum::queryMax(
                             jobl, jobr, l, mid, jshl(i, 1))));
      }
      if ((jobr > mid)) {
        (ans = jmax(ans, Code04_SegmentTreeAddSetminQueryMaxSum::queryMax(
                             jobl, jobr, (mid + 1), r, (jshl(i, 1) | 1))));
      }
      return ans;
    }
  }
  static void java_main(Array<String> args) {
    jout.println(String(u"测试开始"));
    int n = 2000;
    int v = 5000;
    int t = 1000000;
    Code04_SegmentTreeAddSetminQueryMaxSum::randomArray(n, v);
    Array<i64> check = make_array<i64>((n + 1));
    for (int i = 1; (i <= n); (i++)) {
      (check[i] = arr[i]);
    }
    Code04_SegmentTreeAddSetminQueryMaxSum::build(1, n, 1);
    {
      int i = 1;
      int op = {};
      int a = {};
      int b = {};
      int jobl = {};
      int jobr = {};
      int jobv = {};
      for (; (i <= t); (i++)) {
        (op = static_cast<int>((j::random() * 4)));
        (a = (static_cast<int>((j::random() * n)) + 1));
        (b = (static_cast<int>((j::random() * n)) + 1));
        (jobl = jmin(a, b));
        (jobr = jmax(a, b));
        if ((op == 0)) {
          (jobv = (static_cast<int>(((j::random() * v) * 2)) - v));
          Code04_SegmentTreeAddSetminQueryMaxSum::add(jobl, jobr, jobv, 1, n,
                                                      1);
          Code04_SegmentTreeAddSetminQueryMaxSum::checkAdd(check, jobl, jobr,
                                                           jobv);
        } else if ((op == 1)) {
          (jobv = (static_cast<int>(((j::random() * v) * 2)) - v));
          Code04_SegmentTreeAddSetminQueryMaxSum::setMin(jobl, jobr, jobv, 1, n,
                                                         1);
          Code04_SegmentTreeAddSetminQueryMaxSum::checkSetMin(check, jobl, jobr,
                                                              jobv);
        } else if ((op == 2)) {
          i64 ans1 = Code04_SegmentTreeAddSetminQueryMaxSum::queryMax(
              jobl, jobr, 1, n, 1);
          i64 ans2 = Code04_SegmentTreeAddSetminQueryMaxSum::checkQueryMax(
              check, jobl, jobr);
          if ((ans1 != ans2)) {
            jout.println(String(u"出错了!"));
          }
        } else {
          i64 ans1 = Code04_SegmentTreeAddSetminQueryMaxSum::querySum(
              jobl, jobr, 1, n, 1);
          i64 ans2 = Code04_SegmentTreeAddSetminQueryMaxSum::checkQuerySum(
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
  static void checkAdd(Array<i64> check, int jobl, int jobr, i64 jobv) {
    for (int i = jobl; (i <= jobr); (i++)) {
      (check[i] += jobv);
    }
  }
  static void checkSetMin(Array<i64> check, int jobl, int jobr, i64 jobv) {
    for (int i = jobl; (i <= jobr); (i++)) {
      (check[i] = jmin(check[i], jobv));
    }
  }
  static i64 checkQueryMax(Array<i64> check, int jobl, int jobr) {
    i64 ans = std::numeric_limits<i64>::min();
    for (int i = jobl; (i <= jobr); (i++)) {
      (ans = jmax(ans, check[i]));
    }
    return ans;
  }
  static i64 checkQuerySum(Array<i64> check, int jobl, int jobr) {
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
  Code04_SegmentTreeAddSetminQueryMaxSum::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 线段树范围增加操作 + 区间最值操作
// 给定一个长度为n的数组arr，实现支持以下四种操作的结构
// 操作 0 l r x : 把arr[l..r]范围的每个数v，增加x
// 操作 1 l r x : 把arr[l..r]范围的每个数v，更新成min(v, x)
// 操作 2 l r   : 查询arr[l..r]范围上的最大值
// 操作 3 l r   : 查询arr[l..r]范围上的累加和
// 对数器验证
        // 原始数组
        // 累加和信息(查询信息)
        //
最大值信息(只是查询信息，不再是懒更新信息，懒更新功能被maxAdd数组替代了)
        // 最大值个数(查询信息)
        // 严格次大值(查询信息)
        // 最大值的增加幅度(懒更新信息)
        // 除最大值以外其他数字的增加幅度(懒更新信息)
                // 为什么拿全局最大值不写成 : tmp = max[i]
                // 因为父亲范围的最大值可能已经被懒更新任务修改过了
                // 现在希望拿的是懒更新之前的最大值
                // 子范围的max值没有修改过，所以写成 : tmp = Math.max(max[l],
max[r])
        // 为了验证
        // 为了验证
        // 为了验证
        // 为了验证
        // 为了验证
*/

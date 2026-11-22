// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P6242

// Source: src/class114/Code05_MaximumMinimumHistory1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code05_MaximumMinimumHistory1 {
  inline static int MAXN = 500001;
  inline static i64 LOWEST = std::numeric_limits<i64>::min();
  inline static int n = {};
  inline static int m = {};
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static Array<i64> sum = make_array<i64>(jshl(MAXN, 2));
  inline static Array<i64> max = make_array<i64>(jshl(MAXN, 2));
  inline static Array<int> cnt = make_array<int>(jshl(MAXN, 2));
  inline static Array<i64> sem = make_array<i64>(jshl(MAXN, 2));
  inline static Array<i64> maxAdd = make_array<i64>(jshl(MAXN, 2));
  inline static Array<i64> otherAdd = make_array<i64>(jshl(MAXN, 2));
  inline static Array<i64> maxHistory = make_array<i64>(jshl(MAXN, 2));
  inline static Array<i64> maxAddTop = make_array<i64>(jshl(MAXN, 2));
  inline static Array<i64> otherAddTop = make_array<i64>(jshl(MAXN, 2));
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code05_MaximumMinimumHistory1() {}
  static void up(int i) {
    int l = jshl(i, 1);
    int r = (jshl(i, 1) | 1);
    (maxHistory[i] = jmax(maxHistory[l], maxHistory[r]));
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
  static void lazy(int i, int n, i64 maxAddv, i64 otherAddv, i64 maxUpv,
                   i64 otherUpv) {
    (maxHistory[i] = jmax(maxHistory[i], (max[i] + maxUpv)));
    (maxAddTop[i] = jmax(maxAddTop[i], (maxAdd[i] + maxUpv)));
    (otherAddTop[i] = jmax(otherAddTop[i], (otherAdd[i] + otherUpv)));
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
      Code05_MaximumMinimumHistory1::lazy(l, ln, maxAdd[i], otherAdd[i],
                                          maxAddTop[i], otherAddTop[i]);
    } else {
      Code05_MaximumMinimumHistory1::lazy(l, ln, otherAdd[i], otherAdd[i],
                                          otherAddTop[i], otherAddTop[i]);
    }
    if ((max[r] == tmp)) {
      Code05_MaximumMinimumHistory1::lazy(r, rn, maxAdd[i], otherAdd[i],
                                          maxAddTop[i], otherAddTop[i]);
    } else {
      Code05_MaximumMinimumHistory1::lazy(r, rn, otherAdd[i], otherAdd[i],
                                          otherAddTop[i], otherAddTop[i]);
    }
    (maxAdd[i] = (otherAdd[i] = (maxAddTop[i] = (otherAddTop[i] = 0))));
  }
  static void build(int l, int r, int i) {
    if ((l == r)) {
      (sum[i] = (max[i] = (maxHistory[i] = arr[l])));
      (sem[i] = LOWEST);
      (cnt[i] = 1);
    } else {
      int mid = jshr((l + r), 1);
      Code05_MaximumMinimumHistory1::build(l, mid, jshl(i, 1));
      Code05_MaximumMinimumHistory1::build((mid + 1), r, (jshl(i, 1) | 1));
      Code05_MaximumMinimumHistory1::up(i);
    }
    (maxAdd[i] = (otherAdd[i] = (maxAddTop[i] = (otherAddTop[i] = 0))));
  }
  static void add(int jobl, int jobr, i64 jobv, int l, int r, int i) {
    if (((jobl <= l) && (r <= jobr))) {
      Code05_MaximumMinimumHistory1::lazy(i, ((r - l) + 1), jobv, jobv, jobv,
                                          jobv);
    } else {
      int mid = jshr((l + r), 1);
      Code05_MaximumMinimumHistory1::down(i, ((mid - l) + 1), (r - mid));
      if ((jobl <= mid)) {
        Code05_MaximumMinimumHistory1::add(jobl, jobr, jobv, l, mid,
                                           jshl(i, 1));
      }
      if ((jobr > mid)) {
        Code05_MaximumMinimumHistory1::add(jobl, jobr, jobv, (mid + 1), r,
                                           (jshl(i, 1) | 1));
      }
      Code05_MaximumMinimumHistory1::up(i);
    }
  }
  static void setMin(int jobl, int jobr, i64 jobv, int l, int r, int i) {
    if ((jobv >= max[i])) {
      return;
    }
    if ((((jobl <= l) && (r <= jobr)) && (sem[i] < jobv))) {
      Code05_MaximumMinimumHistory1::lazy(i, ((r - l) + 1), (jobv - max[i]), 0,
                                          (jobv - max[i]), 0);
    } else {
      int mid = jshr((l + r), 1);
      Code05_MaximumMinimumHistory1::down(i, ((mid - l) + 1), (r - mid));
      if ((jobl <= mid)) {
        Code05_MaximumMinimumHistory1::setMin(jobl, jobr, jobv, l, mid,
                                              jshl(i, 1));
      }
      if ((jobr > mid)) {
        Code05_MaximumMinimumHistory1::setMin(jobl, jobr, jobv, (mid + 1), r,
                                              (jshl(i, 1) | 1));
      }
      Code05_MaximumMinimumHistory1::up(i);
    }
  }
  static i64 querySum(int jobl, int jobr, int l, int r, int i) {
    if (((jobl <= l) && (r <= jobr))) {
      return sum[i];
    } else {
      int mid = jshr((l + r), 1);
      Code05_MaximumMinimumHistory1::down(i, ((mid - l) + 1), (r - mid));
      i64 ans = 0;
      if ((jobl <= mid)) {
        (ans += Code05_MaximumMinimumHistory1::querySum(jobl, jobr, l, mid,
                                                        jshl(i, 1)));
      }
      if ((jobr > mid)) {
        (ans += Code05_MaximumMinimumHistory1::querySum(jobl, jobr, (mid + 1),
                                                        r, (jshl(i, 1) | 1)));
      }
      return ans;
    }
  }
  static i64 queryMax(int jobl, int jobr, int l, int r, int i) {
    if (((jobl <= l) && (r <= jobr))) {
      return max[i];
    } else {
      int mid = jshr((l + r), 1);
      Code05_MaximumMinimumHistory1::down(i, ((mid - l) + 1), (r - mid));
      Box<i64> ans = LOWEST;
      if ((jobl <= mid)) {
        (ans = jmax(ans, Code05_MaximumMinimumHistory1::queryMax(
                             jobl, jobr, l, mid, jshl(i, 1))));
      }
      if ((jobr > mid)) {
        (ans = jmax(ans, Code05_MaximumMinimumHistory1::queryMax(
                             jobl, jobr, (mid + 1), r, (jshl(i, 1) | 1))));
      }
      return ans;
    }
  }
  static i64 queryHistoryMax(int jobl, int jobr, int l, int r, int i) {
    if (((jobl <= l) && (r <= jobr))) {
      return maxHistory[i];
    } else {
      int mid = jshr((l + r), 1);
      Code05_MaximumMinimumHistory1::down(i, ((mid - l) + 1), (r - mid));
      Box<i64> ans = LOWEST;
      if ((jobl <= mid)) {
        (ans = jmax(ans, Code05_MaximumMinimumHistory1::queryHistoryMax(
                             jobl, jobr, l, mid, jshl(i, 1))));
      }
      if ((jobr > mid)) {
        (ans = jmax(ans, Code05_MaximumMinimumHistory1::queryHistoryMax(
                             jobl, jobr, (mid + 1), r, (jshl(i, 1) | 1))));
      }
      return ans;
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (m = in.nextInt());
    for (int i = 1; (i <= n); (i++)) {
      (arr[i] = in.nextInt());
    }
    Code05_MaximumMinimumHistory1::build(1, n, 1);
    int op = {};
    int jobl = {};
    int jobr = {};
    i64 jobv = {};
    for (int i = 1; (i <= m); (i++)) {
      (op = in.nextInt());
      (jobl = in.nextInt());
      (jobr = in.nextInt());
      if ((op == 1)) {
        (jobv = in.nextInt());
        Code05_MaximumMinimumHistory1::add(jobl, jobr, jobv, 1, n, 1);
      } else if ((op == 2)) {
        (jobv = in.nextInt());
        Code05_MaximumMinimumHistory1::setMin(jobl, jobr, jobv, 1, n, 1);
      } else if ((op == 3)) {
        out.println(
            Code05_MaximumMinimumHistory1::querySum(jobl, jobr, 1, n, 1));
      } else if ((op == 4)) {
        out.println(
            Code05_MaximumMinimumHistory1::queryMax(jobl, jobr, 1, n, 1));
      } else {
        out.println(Code05_MaximumMinimumHistory1::queryHistoryMax(jobl, jobr,
                                                                   1, n, 1));
      }
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code05_MaximumMinimumHistory1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 区间最值和历史最值，java版
// 给定两个长度都为n的数组A和B，一开始两个数组完全一样
// 任何操作做完，都更新B数组，B[i] = max(B[i],A[i])
// 实现以下五种操作，一共会调用m次
// 操作 1 l r v : A[l..r]范围上每个数加上v
// 操作 2 l r v : A[l..r]范围上每个数A[i]变成min(A[i],v)
// 操作 3 l r   : 返回A[l..r]范围上的累加和
// 操作 4 l r   : 返回A[l..r]范围上的最大值
// 操作 5 l r   : 返回B[l..r]范围上的最大值
// 1 <= n、m <= 5 * 10^5
// 测试链接 : https://www.luogu.com.cn/problem/P6242
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 历史最大值
        // 最大值达到过的最大提升幅度(懒更新信息)
        // 除最大值以外的其他数字，达到过的最大提升幅度(懒更新信息)
        // maxAddv   : 最大值增加多少
        // otherAddv : 其他数增加多少
        // maxUpv    : 最大值达到过的最大提升幅度
        // otherUpv  : 其他数达到过的最大提升幅度
        // 读写工具类
*/

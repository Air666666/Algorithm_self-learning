// 原题测试 / 参考链接（保留上游原始地址）
// https://acm.hdu.edu.cn/showproblem.php?pid=5306

// Source: src/class114/Code03_SegmentTreeSetminQueryMaxSum2.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_SegmentTreeSetminQueryMaxSum2 {
  inline static int MAXN = 1000001;
  inline static int LOWEST = (-1);
  inline static Array<i64> sum = make_array<i64>(jshl(MAXN, 2));
  inline static Array<int> max = make_array<int>(jshl(MAXN, 2));
  inline static Array<int> cnt = make_array<int>(jshl(MAXN, 2));
  inline static Array<int> sem = make_array<int>(jshl(MAXN, 2));
  inline static IO br = IO(IO(jin));
  inline static Tokenizer in = Tokenizer(br);
  inline static IO out = IO(IO(jout));
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_SegmentTreeSetminQueryMaxSum2() {}
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
    Code03_SegmentTreeSetminQueryMaxSum2::lazy(jshl(i, 1), max[i]);
    Code03_SegmentTreeSetminQueryMaxSum2::lazy((jshl(i, 1) | 1), max[i]);
  }
  static void lazy(int i, int v) {
    if ((v < max[i])) {
      (sum[i] -= ((static_cast<i64>(max[i]) - v) * cnt[i]));
      (max[i] = v);
    }
  }
  static void build(int l, int r, int i) {
    if ((l == r)) {
      in.nextToken();
      (sum[i] = (max[i] = static_cast<int>(in.nval)));
      (cnt[i] = 1);
      (sem[i] = LOWEST);
    } else {
      int mid = jshr((l + r), 1);
      Code03_SegmentTreeSetminQueryMaxSum2::build(l, mid, jshl(i, 1));
      Code03_SegmentTreeSetminQueryMaxSum2::build((mid + 1), r,
                                                  (jshl(i, 1) | 1));
      Code03_SegmentTreeSetminQueryMaxSum2::up(i);
    }
  }
  static void setMin(int jobl, int jobr, int jobv, int l, int r, int i) {
    if ((jobv >= max[i])) {
      return;
    }
    if ((((jobl <= l) && (r <= jobr)) && (sem[i] < jobv))) {
      Code03_SegmentTreeSetminQueryMaxSum2::lazy(i, jobv);
    } else {
      Code03_SegmentTreeSetminQueryMaxSum2::down(i);
      int mid = jshr((l + r), 1);
      if ((jobl <= mid)) {
        Code03_SegmentTreeSetminQueryMaxSum2::setMin(jobl, jobr, jobv, l, mid,
                                                     jshl(i, 1));
      }
      if ((jobr > mid)) {
        Code03_SegmentTreeSetminQueryMaxSum2::setMin(
            jobl, jobr, jobv, (mid + 1), r, (jshl(i, 1) | 1));
      }
      Code03_SegmentTreeSetminQueryMaxSum2::up(i);
    }
  }
  static int queryMax(int jobl, int jobr, int l, int r, int i) {
    if (((jobl <= l) && (r <= jobr))) {
      return max[i];
    }
    Code03_SegmentTreeSetminQueryMaxSum2::down(i);
    int mid = jshr((l + r), 1);
    int ans = std::numeric_limits<int>::min();
    if ((jobl <= mid)) {
      (ans = jmax(ans, Code03_SegmentTreeSetminQueryMaxSum2::queryMax(
                           jobl, jobr, l, mid, jshl(i, 1))));
    }
    if ((jobr > mid)) {
      (ans = jmax(ans, Code03_SegmentTreeSetminQueryMaxSum2::queryMax(
                           jobl, jobr, (mid + 1), r, (jshl(i, 1) | 1))));
    }
    return ans;
  }
  static i64 querySum(int jobl, int jobr, int l, int r, int i) {
    if (((jobl <= l) && (r <= jobr))) {
      return sum[i];
    }
    Code03_SegmentTreeSetminQueryMaxSum2::down(i);
    int mid = jshr((l + r), 1);
    i64 ans = 0;
    if ((jobl <= mid)) {
      (ans += Code03_SegmentTreeSetminQueryMaxSum2::querySum(jobl, jobr, l, mid,
                                                             jshl(i, 1)));
    }
    if ((jobr > mid)) {
      (ans += Code03_SegmentTreeSetminQueryMaxSum2::querySum(
           jobl, jobr, (mid + 1), r, (jshl(i, 1) | 1)));
    }
    return ans;
  }
  static void java_main(Array<String> args) {
    in.nextToken();
    int testCases = static_cast<int>(in.nval);
    for (int t = 1; (t <= testCases); (t++)) {
      in.nextToken();
      int n = static_cast<int>(in.nval);
      in.nextToken();
      int m = static_cast<int>(in.nval);
      Code03_SegmentTreeSetminQueryMaxSum2::build(1, n, 1);
      {
        int i = 1;
        int op = {};
        int jobl = {};
        int jobr = {};
        int jobv = {};
        for (; (i <= m); (i++)) {
          in.nextToken();
          (op = static_cast<int>(in.nval));
          if ((op == 0)) {
            in.nextToken();
            (jobl = static_cast<int>(in.nval));
            in.nextToken();
            (jobr = static_cast<int>(in.nval));
            in.nextToken();
            (jobv = static_cast<int>(in.nval));
            Code03_SegmentTreeSetminQueryMaxSum2::setMin(jobl, jobr, jobv, 1, n,
                                                         1);
          } else if ((op == 1)) {
            in.nextToken();
            (jobl = static_cast<int>(in.nval));
            in.nextToken();
            (jobr = static_cast<int>(in.nval));
            out.println(Code03_SegmentTreeSetminQueryMaxSum2::queryMax(
                jobl, jobr, 1, n, 1));
          } else {
            in.nextToken();
            (jobl = static_cast<int>(in.nval));
            in.nextToken();
            (jobr = static_cast<int>(in.nval));
            out.println(Code03_SegmentTreeSetminQueryMaxSum2::querySum(
                jobl, jobr, 1, n, 1));
          }
        }
      }
    }
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code03_SegmentTreeSetminQueryMaxSum2::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 线段树的区间最值操作(hdu测试)
// 给定一个长度为n的数组arr，实现支持以下三种操作的结构
// 操作 0 l r x : 把arr[l..r]范围的每个数v，更新成min(v, x)
// 操作 1 l r   : 查询arr[l..r]范围上的最大值
// 操作 2 l r   : 查询arr[l..r]范围上的累加和
// 三种操作一共调用m次，做到时间复杂度O(n * log n + m * log n)
// 测试链接 : https://acm.hdu.edu.cn/showproblem.php?pid=5306
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下的code，提交时请把类名改成"Main"，可以直接通过
        // 一定是没有颠覆掉次大值的懒更新信息下发，也就是说：
        // 最大值被压成v，并且v > 严格次大值的情况下
        // sum和max怎么调整
                        // 不能生成原始数组然后build
                        // 因为这道题空间非常极限
                        // 生成原始数组然后build
                        // 空间就是会超过限制
                        // 所以build的过程直接从输入流读入
                        // 一般情况下不会这么极限的
        // 为了不生成原始数组
        // 让build函数可以直接从输入流拿数据
        // 所以把输入输出流定义成全局静态变量
*/

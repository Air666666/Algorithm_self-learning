// Source: src/class113/Code01_SequenceOperation.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_SequenceOperation {
  inline static int MAXN = 100001;
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static Array<int> sum = make_array<int>(jshl(MAXN, 2));
  inline static Array<int> len0 = make_array<int>(jshl(MAXN, 2));
  inline static Array<int> pre0 = make_array<int>(jshl(MAXN, 2));
  inline static Array<int> suf0 = make_array<int>(jshl(MAXN, 2));
  inline static Array<int> len1 = make_array<int>(jshl(MAXN, 2));
  inline static Array<int> pre1 = make_array<int>(jshl(MAXN, 2));
  inline static Array<int> suf1 = make_array<int>(jshl(MAXN, 2));
  inline static Array<int> change = make_array<int>(jshl(MAXN, 2));
  inline static Array<bool> update = make_array<bool>(jshl(MAXN, 2));
  inline static Array<bool> reverse = make_array<bool>(jshl(MAXN, 2));
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_SequenceOperation() {}
  static void up(int i, int ln, int rn) {
    int l = jshl(i, 1);
    int r = (jshl(i, 1) | 1);
    (sum[i] = (sum[l] + sum[r]));
    (len0[i] = jmax(jmax(len0[l], len0[r]), (suf0[l] + pre0[r])));
    (pre0[i] = ((len0[l] < ln) ? pre0[l] : (pre0[l] + pre0[r])));
    (suf0[i] = ((len0[r] < rn) ? suf0[r] : (suf0[l] + suf0[r])));
    (len1[i] = jmax(jmax(len1[l], len1[r]), (suf1[l] + pre1[r])));
    (pre1[i] = ((len1[l] < ln) ? pre1[l] : (pre1[l] + pre1[r])));
    (suf1[i] = ((len1[r] < rn) ? suf1[r] : (suf1[l] + suf1[r])));
  }
  static void down(int i, int ln, int rn) {
    if (update[i]) {
      Code01_SequenceOperation::updateLazy(jshl(i, 1), change[i], ln);
      Code01_SequenceOperation::updateLazy((jshl(i, 1) | 1), change[i], rn);
      (update[i] = false);
    }
    if (reverse[i]) {
      Code01_SequenceOperation::reverseLazy(jshl(i, 1), ln);
      Code01_SequenceOperation::reverseLazy((jshl(i, 1) | 1), rn);
      (reverse[i] = false);
    }
  }
  static void updateLazy(int i, int v, int n) {
    (sum[i] = (v * n));
    (len0[i] = (pre0[i] = (suf0[i] = ((v == 0) ? n : 0))));
    (len1[i] = (pre1[i] = (suf1[i] = ((v == 1) ? n : 0))));
    (change[i] = v);
    (update[i] = true);
    (reverse[i] = false);
  }
  static void reverseLazy(int i, int n) {
    (sum[i] = (n - sum[i]));
    int tmp = {};
    (tmp = len0[i]);
    (len0[i] = len1[i]);
    (len1[i] = tmp);
    (tmp = pre0[i]);
    (pre0[i] = pre1[i]);
    (pre1[i] = tmp);
    (tmp = suf0[i]);
    (suf0[i] = suf1[i]);
    (suf1[i] = tmp);
    (reverse[i] = (!reverse[i]));
  }
  static void build(int l, int r, int i) {
    if ((l == r)) {
      (sum[i] = arr[l]);
      (len0[i] = (pre0[i] = (suf0[i] = ((arr[l] == 0) ? 1 : 0))));
      (len1[i] = (pre1[i] = (suf1[i] = ((arr[l] == 1) ? 1 : 0))));
    } else {
      int mid = jshr((l + r), 1);
      Code01_SequenceOperation::build(l, mid, jshl(i, 1));
      Code01_SequenceOperation::build((mid + 1), r, (jshl(i, 1) | 1));
      Code01_SequenceOperation::up(i, ((mid - l) + 1), (r - mid));
    }
    (update[i] = false);
    (reverse[i] = false);
  }
  static void update_method(int jobl, int jobr, int jobv, int l, int r, int i) {
    if (((jobl <= l) && (r <= jobr))) {
      Code01_SequenceOperation::updateLazy(i, jobv, ((r - l) + 1));
    } else {
      int mid = jshr((l + r), 1);
      Code01_SequenceOperation::down(i, ((mid - l) + 1), (r - mid));
      if ((jobl <= mid)) {
        Code01_SequenceOperation::update_method(jobl, jobr, jobv, l, mid,
                                                jshl(i, 1));
      }
      if ((jobr > mid)) {
        Code01_SequenceOperation::update_method(jobl, jobr, jobv, (mid + 1), r,
                                                (jshl(i, 1) | 1));
      }
      Code01_SequenceOperation::up(i, ((mid - l) + 1), (r - mid));
    }
  }
  static void reverse_method(int jobl, int jobr, int l, int r, int i) {
    if (((jobl <= l) && (r <= jobr))) {
      Code01_SequenceOperation::reverseLazy(i, ((r - l) + 1));
    } else {
      int mid = jshr((l + r), 1);
      Code01_SequenceOperation::down(i, ((mid - l) + 1), (r - mid));
      if ((jobl <= mid)) {
        Code01_SequenceOperation::reverse_method(jobl, jobr, l, mid,
                                                 jshl(i, 1));
      }
      if ((jobr > mid)) {
        Code01_SequenceOperation::reverse_method(jobl, jobr, (mid + 1), r,
                                                 (jshl(i, 1) | 1));
      }
      Code01_SequenceOperation::up(i, ((mid - l) + 1), (r - mid));
    }
  }
  static int querySum(int jobl, int jobr, int l, int r, int i) {
    if (((jobl <= l) && (r <= jobr))) {
      return sum[i];
    }
    int mid = jshr((l + r), 1);
    Code01_SequenceOperation::down(i, ((mid - l) + 1), (r - mid));
    int ans = 0;
    if ((jobl <= mid)) {
      (ans +=
       Code01_SequenceOperation::querySum(jobl, jobr, l, mid, jshl(i, 1)));
    }
    if ((jobr > mid)) {
      (ans += Code01_SequenceOperation::querySum(jobl, jobr, (mid + 1), r,
                                                 (jshl(i, 1) | 1)));
    }
    return ans;
  }
  static Array<int> queryLongest(int jobl, int jobr, int l, int r, int i) {
    if (((jobl <= l) && (r <= jobr))) {
      return Array<int>{len1[i], pre1[i], suf1[i]};
    } else {
      int mid = jshr((l + r), 1);
      int ln = ((mid - l) + 1);
      int rn = (r - mid);
      Code01_SequenceOperation::down(i, ln, rn);
      if ((jobr <= mid)) {
        return Code01_SequenceOperation::queryLongest(jobl, jobr, l, mid,
                                                      jshl(i, 1));
      }
      if ((jobl > mid)) {
        return Code01_SequenceOperation::queryLongest(jobl, jobr, (mid + 1), r,
                                                      (jshl(i, 1) | 1));
      }
      Array<int> l3 = Code01_SequenceOperation::queryLongest(jobl, jobr, l, mid,
                                                             jshl(i, 1));
      Array<int> r3 = Code01_SequenceOperation::queryLongest(
          jobl, jobr, (mid + 1), r, (jshl(i, 1) | 1));
      int llen = l3[0];
      int lpre = l3[1];
      int lsuf = l3[2];
      int rlen = r3[0];
      int rpre = r3[1];
      int rsuf = r3[2];
      int len = jmax(jmax(llen, rlen), (lsuf + rpre));
      int pre = ((llen < ((mid - jmax(jobl, l)) + 1)) ? lpre : (lpre + rpre));
      int suf = ((rlen < (jmin(r, jobr) - mid)) ? rsuf : (lsuf + rsuf));
      return Array<int>{len, pre, suf};
    }
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    int n = static_cast<int>(in.nval);
    in.nextToken();
    int m = static_cast<int>(in.nval);
    for (int i = 1; (i <= n); (i++)) {
      in.nextToken();
      (arr[i] = static_cast<int>(in.nval));
    }
    Code01_SequenceOperation::build(1, n, 1);
    {
      int i = 1;
      int op = {};
      int jobl = {};
      int jobr = {};
      for (; (i <= m); (i++)) {
        in.nextToken();
        (op = static_cast<int>(in.nval));
        in.nextToken();
        (jobl = (static_cast<int>(in.nval) + 1));
        in.nextToken();
        (jobr = (static_cast<int>(in.nval) + 1));
        if ((op == 0)) {
          Code01_SequenceOperation::update_method(jobl, jobr, 0, 1, n, 1);
        } else if ((op == 1)) {
          Code01_SequenceOperation::update_method(jobl, jobr, 1, 1, n, 1);
        } else if ((op == 2)) {
          Code01_SequenceOperation::reverse_method(jobl, jobr, 1, n, 1);
        } else if ((op == 3)) {
          out.println(Code01_SequenceOperation::querySum(jobl, jobr, 1, n, 1));
        } else {
          out.println(
              Code01_SequenceOperation::queryLongest(jobl, jobr, 1, n, 1)[0]);
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
  Code01_SequenceOperation::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 序列操作
// 给定一个长度为n的数组arr，内部只有01两种值，下标从0开始
// 对于这个序列有五种变换操作和询问操作
// 操作 0 l r : 把l~r范围上所有数字全改成0
// 操作 1 l r : 把l~r范围上所有数字全改成1
// 操作 2 l r : 把l~r范围上所有数字全取反
// 操作 3 l r : 询问l~r范围上有多少个1
// 操作 4 l r : 询问l~r范围上连续1的最长子串长度
// 测试链接 : https://www.luogu.com.cn/problem/P2572
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下的code，提交时请把类名改成"Main"，可以直接通过
        // 原始数组
        // 累加和用来统计1的数量
        // 连续0的最长子串长度
        // 连续0的最长前缀长度
        // 连续0的最长后缀长度
        // 连续1的最长子串长度
        // 连续1的最长前缀长度
        // 连续1的最长后缀长度
        // 懒更新信息，范围上所有数字被重置成了什么
        // 懒更新信息，范围上有没有重置任务
        // 懒更新信息，范围上有没有翻转任务
        // 线段树范围l~r上，被jobl~jobr影响的区域里，返回1的数量
        // 返回一个长度为3的数组ans，代表结果，具体含义如下：
        // ans[0] :
线段树范围l~r上，被jobl~jobr影响的区域里，连续1的最长子串长度
        // ans[1] :
线段树范围l~r上，被jobl~jobr影响的区域里，连续1的最长前缀长度
        // ans[2] :
线段树范围l~r上，被jobl~jobr影响的区域里，连续1的最长后缀长度
                        // 任务实际影响了左侧范围的几个点 -> mid -
Math.max(jobl, l) + 1
                        // 任务实际影响了右侧范围的几个点 -> Math.min(r, jobr) -
mid
*/

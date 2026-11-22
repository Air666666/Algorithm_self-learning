// Source: src/class110/Code04_SegmentTreeUpdateQueryMax.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_SegmentTreeUpdateQueryMax {
  inline static int MAXN = 100001;
  inline static Array<i64> arr = make_array<i64>(MAXN);
  inline static Array<i64> max = make_array<i64>(jshl(MAXN, 2));
  inline static Array<i64> change = make_array<i64>(jshl(MAXN, 2));
  inline static Array<bool> update = make_array<bool>(jshl(MAXN, 2));
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_SegmentTreeUpdateQueryMax() {}
  static void up(int i) {
    (max[i] = jmax(max[jshl(i, 1)], max[(jshl(i, 1) | 1)]));
  }
  static void down(int i) {
    if (update[i]) {
      Code04_SegmentTreeUpdateQueryMax::lazy(jshl(i, 1), change[i]);
      Code04_SegmentTreeUpdateQueryMax::lazy((jshl(i, 1) | 1), change[i]);
      (update[i] = false);
    }
  }
  static void lazy(int i, i64 v) {
    (max[i] = v);
    (change[i] = v);
    (update[i] = true);
  }
  static void build(int l, int r, int i) {
    if ((l == r)) {
      (max[i] = arr[l]);
    } else {
      int mid = jshr((l + r), 1);
      Code04_SegmentTreeUpdateQueryMax::build(l, mid, jshl(i, 1));
      Code04_SegmentTreeUpdateQueryMax::build((mid + 1), r, (jshl(i, 1) | 1));
      Code04_SegmentTreeUpdateQueryMax::up(i);
    }
    (change[i] = 0);
    (update[i] = false);
  }
  static void update_method(int jobl, int jobr, i64 jobv, int l, int r, int i) {
    if (((jobl <= l) && (r <= jobr))) {
      Code04_SegmentTreeUpdateQueryMax::lazy(i, jobv);
    } else {
      Code04_SegmentTreeUpdateQueryMax::down(i);
      int mid = jshr((l + r), 1);
      if ((jobl <= mid)) {
        Code04_SegmentTreeUpdateQueryMax::update_method(jobl, jobr, jobv, l,
                                                        mid, jshl(i, 1));
      }
      if ((jobr > mid)) {
        Code04_SegmentTreeUpdateQueryMax::update_method(
            jobl, jobr, jobv, (mid + 1), r, (jshl(i, 1) | 1));
      }
      Code04_SegmentTreeUpdateQueryMax::up(i);
    }
  }
  static i64 query(int jobl, int jobr, int l, int r, int i) {
    if (((jobl <= l) && (r <= jobr))) {
      return max[i];
    }
    Code04_SegmentTreeUpdateQueryMax::down(i);
    int mid = jshr((l + r), 1);
    i64 ans = std::numeric_limits<i64>::min();
    if ((jobl <= mid)) {
      (ans = jmax(ans, Code04_SegmentTreeUpdateQueryMax::query(
                           jobl, jobr, l, mid, jshl(i, 1))));
    }
    if ((jobr > mid)) {
      (ans = jmax(ans, Code04_SegmentTreeUpdateQueryMax::query(
                           jobl, jobr, (mid + 1), r, (jshl(i, 1) | 1))));
    }
    return ans;
  }
  static void java_main(Array<String> args) {
    jout.println(String(u"测试开始"));
    int n = 1000;
    int v = 2000;
    int t = 5000000;
    Code04_SegmentTreeUpdateQueryMax::randomArray(n, v);
    Code04_SegmentTreeUpdateQueryMax::build(1, n, 1);
    Array<i64> check = make_array<i64>((n + 1));
    for (int i = 1; (i <= n); (i++)) {
      (check[i] = arr[i]);
    }
    for (int i = 1; (i <= t); (i++)) {
      int op = static_cast<int>((j::random() * 2));
      int a = (static_cast<int>((j::random() * n)) + 1);
      int b = (static_cast<int>((j::random() * n)) + 1);
      int jobl = jmin(a, b);
      int jobr = jmax(a, b);
      if ((op == 0)) {
        int jobv = (static_cast<int>(((j::random() * v) * 2)) - v);
        Code04_SegmentTreeUpdateQueryMax::update_method(jobl, jobr, jobv, 1, n,
                                                        1);
        Code04_SegmentTreeUpdateQueryMax::checkUpdate(check, jobl, jobr, jobv);
      } else {
        i64 ans1 = Code04_SegmentTreeUpdateQueryMax::query(jobl, jobr, 1, n, 1);
        i64 ans2 =
            Code04_SegmentTreeUpdateQueryMax::checkQuery(check, jobl, jobr);
        if ((ans1 != ans2)) {
          jout.println(String(u"出错了!"));
        }
      }
    }
    jout.println(String(u"测试结束"));
  }
  static void randomArray(int n, int v) {
    for (int i = 1; (i <= n); (i++)) {
      (arr[i] = static_cast<i64>((j::random() * v)));
    }
  }
  static void checkUpdate(Array<i64> check, int jobl, int jobr, i64 jobv) {
    for (int i = jobl; (i <= jobr); (i++)) {
      (check[i] = jobv);
    }
  }
  static i64 checkQuery(Array<i64> check, int jobl, int jobr) {
    i64 ans = std::numeric_limits<i64>::min();
    for (int i = jobl; (i <= jobr); (i++)) {
      (ans = jmax(ans, check[i]));
    }
    return ans;
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code04_SegmentTreeUpdateQueryMax::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 线段树支持范围重置、范围查询
// 维护最大值
// 对数器验证
// 当你写线段树出错了，就需要用对数器的方式来排查
// 所以本题选择对数器验证，来展示一下怎么写测试
        // 对数器逻辑
        // 展示了线段树的建立和使用
        // 使用验证结构来检查线段树是否正常工作
                // 生成随机值填入arr数组
                // 建立线段树
                // 生成验证的结构
                        // 生成操作类型
                        // op = 0 更新操作
                        // op = 1 查询操作
                        // 下标从1开始，不从0开始，生成两个随机下标
                        // 确保jobl <= jobr
                                // 更新操作
                                // 线段树、验证结构同步更新
                                // 查询操作
                                // 线段树、验证结构同步查询
                                // 比对答案
        // 生成随机值填入arr数组
        // 为了验证
        // 验证结构的更新
        // 暴力更新
        // 为了验证
        // 验证结构的查询
        // 暴力查询
        // 为了验证
*/

// Source: src/class110/Code05_SegmentTreeUpdateAddQuerySum.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code05_SegmentTreeUpdateAddQuerySum {
  inline static int MAXN = 1000001;
  inline static Array<i64> arr = make_array<i64>(MAXN);
  inline static Array<i64> sum = make_array<i64>(jshl(MAXN, 2));
  inline static Array<i64> add = make_array<i64>(jshl(MAXN, 2));
  inline static Array<i64> change = make_array<i64>(jshl(MAXN, 2));
  inline static Array<bool> update = make_array<bool>(jshl(MAXN, 2));
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code05_SegmentTreeUpdateAddQuerySum() {}
  static void up(int i) {
    (sum[i] = (sum[jshl(i, 1)] + sum[(jshl(i, 1) | 1)]));
  }
  static void down(int i, int ln, int rn) {
    if (update[i]) {
      Code05_SegmentTreeUpdateAddQuerySum::updateLazy(jshl(i, 1), change[i],
                                                      ln);
      Code05_SegmentTreeUpdateAddQuerySum::updateLazy((jshl(i, 1) | 1),
                                                      change[i], rn);
      (update[i] = false);
    }
    if ((add[i] != 0)) {
      Code05_SegmentTreeUpdateAddQuerySum::addLazy(jshl(i, 1), add[i], ln);
      Code05_SegmentTreeUpdateAddQuerySum::addLazy((jshl(i, 1) | 1), add[i],
                                                   rn);
      (add[i] = 0);
    }
  }
  static void updateLazy(int i, i64 v, int n) {
    (sum[i] = (v * n));
    (add[i] = 0);
    (change[i] = v);
    (update[i] = true);
  }
  static void addLazy(int i, i64 v, int n) {
    (sum[i] += (v * n));
    (add[i] += v);
  }
  static void build(int l, int r, int i) {
    if ((l == r)) {
      (sum[i] = arr[l]);
    } else {
      int mid = jshr((l + r), 1);
      Code05_SegmentTreeUpdateAddQuerySum::build(l, mid, jshl(i, 1));
      Code05_SegmentTreeUpdateAddQuerySum::build((mid + 1), r,
                                                 (jshl(i, 1) | 1));
      Code05_SegmentTreeUpdateAddQuerySum::up(i);
    }
    (add[i] = 0);
    (change[i] = 0);
    (update[i] = false);
  }
  static void update_method(int jobl, int jobr, i64 jobv, int l, int r, int i) {
    if (((jobl <= l) && (r <= jobr))) {
      Code05_SegmentTreeUpdateAddQuerySum::updateLazy(i, jobv, ((r - l) + 1));
    } else {
      int mid = jshr((l + r), 1);
      Code05_SegmentTreeUpdateAddQuerySum::down(i, ((mid - l) + 1), (r - mid));
      if ((jobl <= mid)) {
        Code05_SegmentTreeUpdateAddQuerySum::update_method(jobl, jobr, jobv, l,
                                                           mid, jshl(i, 1));
      }
      if ((jobr > mid)) {
        Code05_SegmentTreeUpdateAddQuerySum::update_method(
            jobl, jobr, jobv, (mid + 1), r, (jshl(i, 1) | 1));
      }
      Code05_SegmentTreeUpdateAddQuerySum::up(i);
    }
  }
  static void add_method(int jobl, int jobr, i64 jobv, int l, int r, int i) {
    if (((jobl <= l) && (r <= jobr))) {
      Code05_SegmentTreeUpdateAddQuerySum::addLazy(i, jobv, ((r - l) + 1));
    } else {
      int mid = jshr((l + r), 1);
      Code05_SegmentTreeUpdateAddQuerySum::down(i, ((mid - l) + 1), (r - mid));
      if ((jobl <= mid)) {
        Code05_SegmentTreeUpdateAddQuerySum::add_method(jobl, jobr, jobv, l,
                                                        mid, jshl(i, 1));
      }
      if ((jobr > mid)) {
        Code05_SegmentTreeUpdateAddQuerySum::add_method(
            jobl, jobr, jobv, (mid + 1), r, (jshl(i, 1) | 1));
      }
      Code05_SegmentTreeUpdateAddQuerySum::up(i);
    }
  }
  static i64 query(int jobl, int jobr, int l, int r, int i) {
    if (((jobl <= l) && (r <= jobr))) {
      return sum[i];
    }
    int mid = jshr((l + r), 1);
    Code05_SegmentTreeUpdateAddQuerySum::down(i, ((mid - l) + 1), (r - mid));
    i64 ans = 0;
    if ((jobl <= mid)) {
      (ans += Code05_SegmentTreeUpdateAddQuerySum::query(jobl, jobr, l, mid,
                                                         jshl(i, 1)));
    }
    if ((jobr > mid)) {
      (ans += Code05_SegmentTreeUpdateAddQuerySum::query(jobl, jobr, (mid + 1),
                                                         r, (jshl(i, 1) | 1)));
    }
    return ans;
  }
  static void java_main(Array<String> args) {
    jout.println(String(u"测试开始"));
    int n = 1000;
    int v = 2000;
    int t = 5000000;
    Code05_SegmentTreeUpdateAddQuerySum::randomArray(n, v);
    Code05_SegmentTreeUpdateAddQuerySum::build(1, n, 1);
    Array<i64> check = make_array<i64>((n + 1));
    for (int i = 1; (i <= n); (i++)) {
      (check[i] = arr[i]);
    }
    for (int i = 1; (i <= t); (i++)) {
      int op = static_cast<int>((j::random() * 3));
      int a = (static_cast<int>((j::random() * n)) + 1);
      int b = (static_cast<int>((j::random() * n)) + 1);
      int jobl = jmin(a, b);
      int jobr = jmax(a, b);
      if ((op == 0)) {
        int jobv = (static_cast<int>(((j::random() * v) * 2)) - v);
        Code05_SegmentTreeUpdateAddQuerySum::add_method(jobl, jobr, jobv, 1, n,
                                                        1);
        Code05_SegmentTreeUpdateAddQuerySum::checkAdd(check, jobl, jobr, jobv);
      } else if ((op == 1)) {
        int jobv = (static_cast<int>(((j::random() * v) * 2)) - v);
        Code05_SegmentTreeUpdateAddQuerySum::update_method(jobl, jobr, jobv, 1,
                                                           n, 1);
        Code05_SegmentTreeUpdateAddQuerySum::checkUpdate(check, jobl, jobr,
                                                         jobv);
      } else {
        i64 ans1 =
            Code05_SegmentTreeUpdateAddQuerySum::query(jobl, jobr, 1, n, 1);
        i64 ans2 =
            Code05_SegmentTreeUpdateAddQuerySum::checkQuery(check, jobl, jobr);
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
  static void checkAdd(Array<i64> check, int jobl, int jobr, i64 jobv) {
    for (int i = jobl; (i <= jobr); (i++)) {
      (check[i] += jobv);
    }
  }
  static void checkUpdate(Array<i64> check, int jobl, int jobr, i64 jobv) {
    for (int i = jobl; (i <= jobr); (i++)) {
      (check[i] = jobv);
    }
  }
  static i64 checkQuery(Array<i64> check, int jobl, int jobr) {
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
  Code05_SegmentTreeUpdateAddQuerySum::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 线段树同时支持范围重置、范围增加、范围查询
// 维护累加和
// 对数器验证
// 当你写线段树出错了，就需要用对数器的方式来排查
// 所以本题选择对数器验证，来展示一下怎么写测试
                // 生成随机值填入arr数组
                // 建立线段树
                // 生成验证的结构
                        // 生成操作类型
                        // op = 0 增加操作
                        // op = 1 更新操作
                        // op = 2 查询操作
                        // 下标从1开始，不从0开始，生成两个随机下标
                        // 确保jobl <= jobr
                                // 增加操作
                                // 线段树、验证结构同步增加
                                // 更新操作
                                // 线段树、验证结构同步更新
                                // 查询操作
                                // 线段树、验证结构同步查询
                                // 比对答案
        // 生成随机值填入arr数组
        // 为了验证
        // 验证结构的增加
        // 暴力增加
        // 为了验证
        // 验证结构的更新
        // 暴力更新
        // 为了验证
        // 验证结构的查询
        // 暴力查询
        // 为了验证
*/

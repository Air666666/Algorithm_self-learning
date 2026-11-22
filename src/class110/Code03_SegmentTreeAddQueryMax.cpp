// Source: src/class110/Code03_SegmentTreeAddQueryMax.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_SegmentTreeAddQueryMax {
  inline static int MAXN = 100001;
  inline static Array<i64> arr = make_array<i64>(MAXN);
  inline static Array<i64> max = make_array<i64>(jshl(MAXN, 2));
  inline static Array<i64> add = make_array<i64>(jshl(MAXN, 2));
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_SegmentTreeAddQueryMax() {}
  static void up(int i) {
    (max[i] = jmax(max[jshl(i, 1)], max[(jshl(i, 1) | 1)]));
  }
  static void down(int i) {
    if ((add[i] != 0)) {
      Code03_SegmentTreeAddQueryMax::lazy(jshl(i, 1), add[i]);
      Code03_SegmentTreeAddQueryMax::lazy((jshl(i, 1) | 1), add[i]);
      (add[i] = 0);
    }
  }
  static void lazy(int i, i64 v) {
    (max[i] += v);
    (add[i] += v);
  }
  static void build(int l, int r, int i) {
    if ((l == r)) {
      (max[i] = arr[l]);
    } else {
      int mid = jshr((l + r), 1);
      Code03_SegmentTreeAddQueryMax::build(l, mid, jshl(i, 1));
      Code03_SegmentTreeAddQueryMax::build((mid + 1), r, (jshl(i, 1) | 1));
      Code03_SegmentTreeAddQueryMax::up(i);
    }
    (add[i] = 0);
  }
  static void add_method(int jobl, int jobr, i64 jobv, int l, int r, int i) {
    if (((jobl <= l) && (r <= jobr))) {
      Code03_SegmentTreeAddQueryMax::lazy(i, jobv);
    } else {
      Code03_SegmentTreeAddQueryMax::down(i);
      int mid = jshr((l + r), 1);
      if ((jobl <= mid)) {
        Code03_SegmentTreeAddQueryMax::add_method(jobl, jobr, jobv, l, mid,
                                                  jshl(i, 1));
      }
      if ((jobr > mid)) {
        Code03_SegmentTreeAddQueryMax::add_method(jobl, jobr, jobv, (mid + 1),
                                                  r, (jshl(i, 1) | 1));
      }
      Code03_SegmentTreeAddQueryMax::up(i);
    }
  }
  static i64 query(int jobl, int jobr, int l, int r, int i) {
    if (((jobl <= l) && (r <= jobr))) {
      return max[i];
    }
    Code03_SegmentTreeAddQueryMax::down(i);
    int mid = jshr((l + r), 1);
    i64 ans = std::numeric_limits<i64>::min();
    if ((jobl <= mid)) {
      (ans = jmax(ans, Code03_SegmentTreeAddQueryMax::query(jobl, jobr, l, mid,
                                                            jshl(i, 1))));
    }
    if ((jobr > mid)) {
      (ans = jmax(ans, Code03_SegmentTreeAddQueryMax::query(
                           jobl, jobr, (mid + 1), r, (jshl(i, 1) | 1))));
    }
    return ans;
  }
  static void java_main(Array<String> args) {
    jout.println(String(u"测试开始"));
    int n = 1000;
    int v = 2000;
    int t = 5000000;
    Code03_SegmentTreeAddQueryMax::randomArray(n, v);
    Code03_SegmentTreeAddQueryMax::build(1, n, 1);
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
        Code03_SegmentTreeAddQueryMax::add_method(jobl, jobr, jobv, 1, n, 1);
        Code03_SegmentTreeAddQueryMax::checkAdd(check, jobl, jobr, jobv);
      } else {
        i64 ans1 = Code03_SegmentTreeAddQueryMax::query(jobl, jobr, 1, n, 1);
        i64 ans2 = Code03_SegmentTreeAddQueryMax::checkQuery(check, jobl, jobr);
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
  Code03_SegmentTreeAddQueryMax::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 线段树支持范围增加、范围查询
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
                        // op = 0 增加操作
                        // op = 1 查询操作
                        // 下标从1开始，不从0开始，生成两个随机下标
                        // 确保jobl <= jobr
                                // 增加操作
                                // 线段树、验证结构同步增加
                                // 查询操作
                                // 线段树、验证结构同步查询
                                // 比对答案
        // 生成随机值填入arr数组
        // 为了验证
        // 验证结构的增加
        // 暴力增加
        // 为了验证
        // 验证结构的查询
        // 暴力查询
        // 为了验证
*/

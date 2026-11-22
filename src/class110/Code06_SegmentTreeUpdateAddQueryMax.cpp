// Source: src/class110/Code06_SegmentTreeUpdateAddQueryMax.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code06_SegmentTreeUpdateAddQueryMax {
  inline static int MAXN = 1000001;
  inline static Array<i64> arr = make_array<i64>(MAXN);
  inline static Array<i64> max = make_array<i64>(jshl(MAXN, 2));
  inline static Array<i64> add = make_array<i64>(jshl(MAXN, 2));
  inline static Array<i64> change = make_array<i64>(jshl(MAXN, 2));
  inline static Array<bool> update = make_array<bool>(jshl(MAXN, 2));
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code06_SegmentTreeUpdateAddQueryMax() {}
  static void up(int i) {
    (max[i] = jmax(max[jshl(i, 1)], max[(jshl(i, 1) | 1)]));
  }
  static void down(int i) {
    if (update[i]) {
      Code06_SegmentTreeUpdateAddQueryMax::updateLazy(jshl(i, 1), change[i]);
      Code06_SegmentTreeUpdateAddQueryMax::updateLazy((jshl(i, 1) | 1),
                                                      change[i]);
      (update[i] = false);
    }
    if ((add[i] != 0)) {
      Code06_SegmentTreeUpdateAddQueryMax::addLazy(jshl(i, 1), add[i]);
      Code06_SegmentTreeUpdateAddQueryMax::addLazy((jshl(i, 1) | 1), add[i]);
      (add[i] = 0);
    }
  }
  static void updateLazy(int i, i64 v) {
    (max[i] = v);
    (add[i] = 0);
    (change[i] = v);
    (update[i] = true);
  }
  static void addLazy(int i, i64 v) {
    (max[i] += v);
    (add[i] += v);
  }
  static void build(int l, int r, int i) {
    if ((l == r)) {
      (max[i] = arr[l]);
    } else {
      int mid = jshr((l + r), 1);
      Code06_SegmentTreeUpdateAddQueryMax::build(l, mid, jshl(i, 1));
      Code06_SegmentTreeUpdateAddQueryMax::build((mid + 1), r,
                                                 (jshl(i, 1) | 1));
      Code06_SegmentTreeUpdateAddQueryMax::up(i);
    }
    (add[i] = 0);
    (change[i] = 0);
    (update[i] = false);
  }
  static void update_method(int jobl, int jobr, i64 jobv, int l, int r, int i) {
    if (((jobl <= l) && (r <= jobr))) {
      Code06_SegmentTreeUpdateAddQueryMax::updateLazy(i, jobv);
    } else {
      int mid = jshr((l + r), 1);
      Code06_SegmentTreeUpdateAddQueryMax::down(i);
      if ((jobl <= mid)) {
        Code06_SegmentTreeUpdateAddQueryMax::update_method(jobl, jobr, jobv, l,
                                                           mid, jshl(i, 1));
      }
      if ((jobr > mid)) {
        Code06_SegmentTreeUpdateAddQueryMax::update_method(
            jobl, jobr, jobv, (mid + 1), r, (jshl(i, 1) | 1));
      }
      Code06_SegmentTreeUpdateAddQueryMax::up(i);
    }
  }
  static void add_method(int jobl, int jobr, i64 jobv, int l, int r, int i) {
    if (((jobl <= l) && (r <= jobr))) {
      Code06_SegmentTreeUpdateAddQueryMax::addLazy(i, jobv);
    } else {
      int mid = jshr((l + r), 1);
      Code06_SegmentTreeUpdateAddQueryMax::down(i);
      if ((jobl <= mid)) {
        Code06_SegmentTreeUpdateAddQueryMax::add_method(jobl, jobr, jobv, l,
                                                        mid, jshl(i, 1));
      }
      if ((jobr > mid)) {
        Code06_SegmentTreeUpdateAddQueryMax::add_method(
            jobl, jobr, jobv, (mid + 1), r, (jshl(i, 1) | 1));
      }
      Code06_SegmentTreeUpdateAddQueryMax::up(i);
    }
  }
  static i64 query(int jobl, int jobr, int l, int r, int i) {
    if (((jobl <= l) && (r <= jobr))) {
      return max[i];
    }
    int mid = jshr((l + r), 1);
    Code06_SegmentTreeUpdateAddQueryMax::down(i);
    i64 ans = std::numeric_limits<i64>::min();
    if ((jobl <= mid)) {
      (ans = jmax(ans, Code06_SegmentTreeUpdateAddQueryMax::query(
                           jobl, jobr, l, mid, jshl(i, 1))));
    }
    if ((jobr > mid)) {
      (ans = jmax(ans, Code06_SegmentTreeUpdateAddQueryMax::query(
                           jobl, jobr, (mid + 1), r, (jshl(i, 1) | 1))));
    }
    return ans;
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
      (arr[i] = static_cast<i64>(in.nval));
    }
    Code06_SegmentTreeUpdateAddQueryMax::build(1, n, 1);
    i64 jobv = {};
    {
      int i = 1;
      int op = {};
      int jobl = {};
      int jobr = {};
      for (; (i <= m); (i++)) {
        in.nextToken();
        (op = static_cast<int>(in.nval));
        if ((op == 1)) {
          in.nextToken();
          (jobl = static_cast<int>(in.nval));
          in.nextToken();
          (jobr = static_cast<int>(in.nval));
          in.nextToken();
          (jobv = static_cast<i64>(in.nval));
          Code06_SegmentTreeUpdateAddQueryMax::update_method(jobl, jobr, jobv,
                                                             1, n, 1);
        } else if ((op == 2)) {
          in.nextToken();
          (jobl = static_cast<int>(in.nval));
          in.nextToken();
          (jobr = static_cast<int>(in.nval));
          in.nextToken();
          (jobv = static_cast<i64>(in.nval));
          Code06_SegmentTreeUpdateAddQueryMax::add_method(jobl, jobr, jobv, 1,
                                                          n, 1);
        } else {
          in.nextToken();
          (jobl = static_cast<int>(in.nval));
          in.nextToken();
          (jobr = static_cast<int>(in.nval));
          out.println(
              Code06_SegmentTreeUpdateAddQueryMax::query(jobl, jobr, 1, n, 1));
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
  Code06_SegmentTreeUpdateAddQueryMax::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 线段树同时支持范围重置、范围增加、范围查询
// 维护最大值
// 测试链接 : https://www.luogu.com.cn/problem/P1253
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下的code，提交时请把类名改成"Main"，可以直接通过
*/

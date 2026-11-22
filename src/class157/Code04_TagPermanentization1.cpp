// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P3372

// Source: src/class157/Code04_TagPermanentization1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_TagPermanentization1 {
  inline static int MAXN = 100001;
  inline static Array<i64> arr = make_array<i64>(MAXN);
  inline static Array<i64> sum = make_array<i64>(jshl(MAXN, 2));
  inline static Array<i64> addTag = make_array<i64>(jshl(MAXN, 2));
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_TagPermanentization1() {}
  static void build(int l, int r, int i) {
    if ((l == r)) {
      (sum[i] = arr[l]);
    } else {
      int mid = jdiv((l + r), 2);
      Code04_TagPermanentization1::build(l, mid, jshl(i, 1));
      Code04_TagPermanentization1::build((mid + 1), r, (jshl(i, 1) | 1));
      (sum[i] = (sum[jshl(i, 1)] + sum[(jshl(i, 1) | 1)]));
    }
    (addTag[i] = 0);
  }
  static void add(int jobl, int jobr, i64 jobv, int l, int r, int i) {
    int a = jmax(jobl, l);
    int b = jmin(jobr, r);
    (sum[i] += (jobv * ((b - a) + 1)));
    if (((jobl <= l) && (r <= jobr))) {
      (addTag[i] += jobv);
    } else {
      int mid = jdiv((l + r), 2);
      if ((jobl <= mid)) {
        Code04_TagPermanentization1::add(jobl, jobr, jobv, l, mid, jshl(i, 1));
      }
      if ((jobr > mid)) {
        Code04_TagPermanentization1::add(jobl, jobr, jobv, (mid + 1), r,
                                         (jshl(i, 1) | 1));
      }
    }
  }
  static i64 query(int jobl, int jobr, i64 addHistory, int l, int r, int i) {
    if (((jobl <= l) && (r <= jobr))) {
      return (sum[i] + (addHistory * ((r - l) + 1)));
    }
    int mid = jshr((l + r), 1);
    i64 ans = 0;
    if ((jobl <= mid)) {
      (ans += Code04_TagPermanentization1::query(
           jobl, jobr, (addHistory + addTag[i]), l, mid, jshl(i, 1)));
    }
    if ((jobr > mid)) {
      (ans +=
       Code04_TagPermanentization1::query(jobl, jobr, (addHistory + addTag[i]),
                                          (mid + 1), r, (jshl(i, 1) | 1)));
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
    Code04_TagPermanentization1::build(1, n, 1);
    int op = {};
    int jobl = {};
    int jobr = {};
    i64 jobv = {};
    for (int i = 1; (i <= m); (i++)) {
      in.nextToken();
      (op = static_cast<int>(in.nval));
      if ((op == 1)) {
        in.nextToken();
        (jobl = static_cast<int>(in.nval));
        in.nextToken();
        (jobr = static_cast<int>(in.nval));
        in.nextToken();
        (jobv = static_cast<i64>(in.nval));
        Code04_TagPermanentization1::add(jobl, jobr, jobv, 1, n, 1);
      } else {
        in.nextToken();
        (jobl = static_cast<int>(in.nval));
        in.nextToken();
        (jobr = static_cast<int>(in.nval));
        out.println(Code04_TagPermanentization1::query(jobl, jobr, 0, 1, n, 1));
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
  Code04_TagPermanentization1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 标记永久化，范围增加 + 查询累加和，java版
// 给定一个长度为n的数组arr，下标1~n，一共有m条操作，操作类型如下
// 1 x y k : 将区间[x, y]每个数加上k
// 2 x y   : 打印区间[x, y]的累加和
// 这就是普通线段树，请用标记永久化的方式实现
// 测试链接 : https://www.luogu.com.cn/problem/P3372
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 不是真实累加和，而是之前的任务中
        // 不考虑被上方范围截住的任务，只考虑来到当前范围 或者 往下走的任务
        // 累加和变成了什么
        // 不再是懒更新信息，变成标记信息
*/

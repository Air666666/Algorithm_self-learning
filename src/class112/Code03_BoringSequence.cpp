// Source: src/class112/Code03_BoringSequence.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_BoringSequence {
  inline static int MAXN = 100001;
  inline static Array<int> diff = make_array<int>(MAXN);
  inline static Array<i64> sum = make_array<i64>(jshl(MAXN, 2));
  inline static Array<i64> add = make_array<i64>(jshl(MAXN, 2));
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_BoringSequence() {}
  static void up(int i) {
    (sum[i] = (sum[jshl(i, 1)] + sum[(jshl(i, 1) | 1)]));
  }
  static void down(int i, int ln, int rn) {
    if ((add[i] != 0)) {
      Code03_BoringSequence::lazy(jshl(i, 1), add[i], ln);
      Code03_BoringSequence::lazy((jshl(i, 1) | 1), add[i], rn);
      (add[i] = 0);
    }
  }
  static void lazy(int i, i64 v, int n) {
    (add[i] += v);
    (sum[i] += (v * n));
  }
  static void build(int l, int r, int i) {
    if ((l == r)) {
      (sum[i] = diff[l]);
    } else {
      int mid = jshr((l + r), 1);
      Code03_BoringSequence::build(l, mid, jshl(i, 1));
      Code03_BoringSequence::build((mid + 1), r, (jshl(i, 1) | 1));
      Code03_BoringSequence::up(i);
    }
    (add[i] = 0);
  }
  static void add_method(int jobl, int jobr, i64 jobv, int l, int r, int i) {
    if (((jobl <= l) && (r <= jobr))) {
      Code03_BoringSequence::lazy(i, jobv, ((r - l) + 1));
    } else {
      int mid = jshr((l + r), 1);
      Code03_BoringSequence::down(i, ((mid - l) + 1), (r - mid));
      if ((jobl <= mid)) {
        Code03_BoringSequence::add_method(jobl, jobr, jobv, l, mid, jshl(i, 1));
      }
      if ((jobr > mid)) {
        Code03_BoringSequence::add_method(jobl, jobr, jobv, (mid + 1), r,
                                          (jshl(i, 1) | 1));
      }
      Code03_BoringSequence::up(i);
    }
  }
  static i64 query(int jobl, int jobr, int l, int r, int i) {
    if (((jobl <= l) && (r <= jobr))) {
      return sum[i];
    }
    int mid = jshr((l + r), 1);
    Code03_BoringSequence::down(i, ((mid - l) + 1), (r - mid));
    i64 ans = 0;
    if ((jobl <= mid)) {
      (ans += Code03_BoringSequence::query(jobl, jobr, l, mid, jshl(i, 1)));
    }
    if ((jobr > mid)) {
      (ans += Code03_BoringSequence::query(jobl, jobr, (mid + 1), r,
                                           (jshl(i, 1) | 1)));
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
    {
      int i = 1;
      int pre = 0;
      int cur = {};
      for (; (i <= n); (i++)) {
        in.nextToken();
        (cur = static_cast<int>(in.nval));
        (diff[i] = (cur - pre));
        (pre = cur);
      }
    }
    Code03_BoringSequence::build(1, n, 1);
    {
      int i = 1;
      int op = {};
      for (; (i <= m); (i++)) {
        in.nextToken();
        (op = static_cast<int>(in.nval));
        if ((op == 1)) {
          in.nextToken();
          int jobl = static_cast<int>(in.nval);
          in.nextToken();
          int jobr = static_cast<int>(in.nval);
          in.nextToken();
          i64 k = static_cast<i64>(in.nval);
          in.nextToken();
          i64 d = static_cast<i64>(in.nval);
          i64 e = (k + (d * (jobr - jobl)));
          Code03_BoringSequence::add_method(jobl, jobl, k, 1, n, 1);
          if (((jobl + 1) <= jobr)) {
            Code03_BoringSequence::add_method((jobl + 1), jobr, d, 1, n, 1);
          }
          if ((jobr < n)) {
            Code03_BoringSequence::add_method((jobr + 1), (jobr + 1), (-e), 1,
                                              n, 1);
          }
        } else {
          in.nextToken();
          int p = static_cast<int>(in.nval);
          out.println(Code03_BoringSequence::query(1, p, 1, n, 1));
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
  Code03_BoringSequence::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 无聊的数列
// 给定一个长度为n的数组arr，实现如下两种操作
// 操作 1 l r k d : arr[l..r]范围上的数依次加上等差数列，首项k，公差d
// 操作 2 p       : 查询arr[p]的值
// 测试链接 : https://www.luogu.com.cn/problem/P1438
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下的code，提交时请把类名改成"Main"，可以直接通过
*/

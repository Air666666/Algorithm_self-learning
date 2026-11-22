// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/CF438D
// https://codeforces.com/problemset/problem/438/D

// Source: src/class111/Code04_QueryModUpdate.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_QueryModUpdate {
  inline static int MAXN = 100001;
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static Array<i64> sum = make_array<i64>(jshl(MAXN, 2));
  inline static Array<int> max = make_array<int>(jshl(MAXN, 2));
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_QueryModUpdate() {}
  static void up(int i) {
    (sum[i] = (sum[jshl(i, 1)] + sum[(jshl(i, 1) | 1)]));
    (max[i] = jmax(max[jshl(i, 1)], max[(jshl(i, 1) | 1)]));
  }
  static void build(int l, int r, int i) {
    if ((l == r)) {
      (sum[i] = (max[i] = arr[l]));
    } else {
      int mid = jshr((l + r), 1);
      Code04_QueryModUpdate::build(l, mid, jshl(i, 1));
      Code04_QueryModUpdate::build((mid + 1), r, (jshl(i, 1) | 1));
      Code04_QueryModUpdate::up(i);
    }
  }
  static i64 query(int jobl, int jobr, int l, int r, int i) {
    if (((jobl <= l) && (r <= jobr))) {
      return sum[i];
    }
    int mid = jshr((l + r), 1);
    i64 ans = 0;
    if ((jobl <= mid)) {
      (ans += Code04_QueryModUpdate::query(jobl, jobr, l, mid, jshl(i, 1)));
    }
    if ((jobr > mid)) {
      (ans += Code04_QueryModUpdate::query(jobl, jobr, (mid + 1), r,
                                           (jshl(i, 1) | 1)));
    }
    return ans;
  }
  static void mod(int jobl, int jobr, int jobv, int l, int r, int i) {
    if ((jobv > max[i])) {
      return;
    }
    if ((l == r)) {
      (sum[i] %= jobv);
      (max[i] %= jobv);
    } else {
      int mid = jshr((l + r), 1);
      if ((jobl <= mid)) {
        Code04_QueryModUpdate::mod(jobl, jobr, jobv, l, mid, jshl(i, 1));
      }
      if ((jobr > mid)) {
        Code04_QueryModUpdate::mod(jobl, jobr, jobv, (mid + 1), r,
                                   (jshl(i, 1) | 1));
      }
      Code04_QueryModUpdate::up(i);
    }
  }
  static void update(int jobi, int jobv, int l, int r, int i) {
    if ((l == r)) {
      (sum[i] = (max[i] = jobv));
    } else {
      int mid = jshr((l + r), 1);
      if ((jobi <= mid)) {
        Code04_QueryModUpdate::update(jobi, jobv, l, mid, jshl(i, 1));
      } else {
        Code04_QueryModUpdate::update(jobi, jobv, (mid + 1), r,
                                      (jshl(i, 1) | 1));
      }
      Code04_QueryModUpdate::up(i);
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
    Code04_QueryModUpdate::build(1, n, 1);
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
          out.println(Code04_QueryModUpdate::query(jobl, jobr, 1, n, 1));
        } else if ((op == 2)) {
          in.nextToken();
          int jobl = static_cast<int>(in.nval);
          in.nextToken();
          int jobr = static_cast<int>(in.nval);
          in.nextToken();
          int jobv = static_cast<int>(in.nval);
          Code04_QueryModUpdate::mod(jobl, jobr, jobv, 1, n, 1);
        } else {
          in.nextToken();
          int jobi = static_cast<int>(in.nval);
          in.nextToken();
          int jobv = static_cast<int>(in.nval);
          Code04_QueryModUpdate::update(jobi, jobv, 1, n, 1);
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
  Code04_QueryModUpdate::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 包含取模操作的线段树
// 给定一个长度为n的数组arr，实现如下三种操作，一共调用m次
// 操作 1 l r : 查询arr[l..r]的累加和
// 操作 2 l r x : 把arr[l..r]上每个数字对x取模
// 操作 3 k x : 把arr[k]上的数字设置为x
// 1 <= n, m <= 10^5，操作1得到的结果，有可能超过int范围
// 测试链接 : https://www.luogu.com.cn/problem/CF438D
// 测试链接 : https://codeforces.com/problemset/problem/438/D
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下的code，提交时请把类名改成"Main"，可以直接通过
*/

// Source: src/class111/Code03_SquareRoot.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_SquareRoot {
  inline static int MAXN = 100001;
  inline static Array<i64> arr = make_array<i64>(MAXN);
  inline static Array<i64> sum = make_array<i64>(jshl(MAXN, 2));
  inline static Array<i64> max = make_array<i64>(jshl(MAXN, 2));
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_SquareRoot() {}
  static void up(int i) {
    (sum[i] = (sum[jshl(i, 1)] + sum[(jshl(i, 1) | 1)]));
    (max[i] = jmax(max[jshl(i, 1)], max[(jshl(i, 1) | 1)]));
  }
  static void build(int l, int r, int i) {
    if ((l == r)) {
      (sum[i] = arr[l]);
      (max[i] = arr[l]);
    } else {
      int mid = jshr((l + r), 1);
      Code03_SquareRoot::build(l, mid, jshl(i, 1));
      Code03_SquareRoot::build((mid + 1), r, (jshl(i, 1) | 1));
      Code03_SquareRoot::up(i);
    }
  }
  static void sqrt(int jobl, int jobr, int l, int r, int i) {
    if ((l == r)) {
      i64 sqrt = static_cast<i64>(std::sqrt(max[i]));
      (sum[i] = sqrt);
      (max[i] = sqrt);
    } else {
      int mid = jshr((l + r), 1);
      if (((jobl <= mid) && (max[jshl(i, 1)] > 1))) {
        Code03_SquareRoot::sqrt(jobl, jobr, l, mid, jshl(i, 1));
      }
      if (((jobr > mid) && (max[(jshl(i, 1) | 1)] > 1))) {
        Code03_SquareRoot::sqrt(jobl, jobr, (mid + 1), r, (jshl(i, 1) | 1));
      }
      Code03_SquareRoot::up(i);
    }
  }
  static i64 query(int jobl, int jobr, int l, int r, int i) {
    if (((jobl <= l) && (r <= jobr))) {
      return sum[i];
    }
    int mid = jshr((l + r), 1);
    i64 ans = 0;
    if ((jobl <= mid)) {
      (ans += Code03_SquareRoot::query(jobl, jobr, l, mid, jshl(i, 1)));
    }
    if ((jobr > mid)) {
      (ans +=
       Code03_SquareRoot::query(jobl, jobr, (mid + 1), r, (jshl(i, 1) | 1)));
    }
    return ans;
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    int n = static_cast<int>(in.nval);
    for (int i = 1; (i <= n); (i++)) {
      in.nextToken();
      (arr[i] = static_cast<i64>(in.nval));
    }
    Code03_SquareRoot::build(1, n, 1);
    in.nextToken();
    int m = static_cast<int>(in.nval);
    {
      int i = 1;
      int op = {};
      int jobl = {};
      int jobr = {};
      int tmp = {};
      for (; (i <= m); (i++)) {
        in.nextToken();
        (op = static_cast<int>(in.nval));
        in.nextToken();
        (jobl = static_cast<int>(in.nval));
        in.nextToken();
        (jobr = static_cast<int>(in.nval));
        if ((jobl > jobr)) {
          (tmp = jobl);
          (jobl = jobr);
          (jobr = tmp);
        }
        if ((op == 0)) {
          Code03_SquareRoot::sqrt(jobl, jobr, 1, n, 1);
        } else {
          out.println(Code03_SquareRoot::query(jobl, jobr, 1, n, 1));
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
  Code03_SquareRoot::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 范围上开平方并求累加和
// 给定一个长度为n的数组arr，实现以下两种类型的操作
// 操作 0 l r : 把arr[l..r]范围上的每个数开平方，结果向下取整
// 操作 1 l r : 查询arr[l..r]范围上所有数字的累加和
// 两种操作一共发生m次，数据中有可能l>r，遇到这种情况请交换l和r
// 1 <= n, m <= 10^5，1 <= arr[i] <= 10^12
// 测试链接 : https://www.luogu.com.cn/problem/P4145
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下的code，提交时请把类名改成"Main"，可以直接通过
        // sqrt方法是最核心的
        // 注意和常规线段树不一样，这里没有懒更新，也就不需要有down方法
        // 只有根据范围最大值信息的剪枝
        // 时间复杂度的分析就是课上讲的势能分析
        // 不用纠结单次调用的复杂度
        // 哪怕调用再多次sqrt方法，总的时间复杂度也就是O(n * 6 * logn)
        // 没有懒更新
        // 不需要调用down方法
*/

// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P1471
// https://oi-wiki.org/lang/java-pro/

// Source: src/class112/Code04_MeanVariance1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_MeanVariance1 {
  inline static int MAXN = 100001;
  inline static Array<double> arr = make_array<double>(MAXN);
  inline static Array<double> sum1 = make_array<double>(jshl(MAXN, 2));
  inline static Array<double> sum2 = make_array<double>(jshl(MAXN, 2));
  inline static Array<double> addv = make_array<double>(jshl(MAXN, 2));
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_MeanVariance1() {}
  static void up(int i) {
    (sum1[i] = (sum1[jshl(i, 1)] + sum1[(jshl(i, 1) | 1)]));
    (sum2[i] = (sum2[jshl(i, 1)] + sum2[(jshl(i, 1) | 1)]));
  }
  static void down(int i, int ln, int rn) {
    if ((addv[i] != 0)) {
      Code04_MeanVariance1::lazy(jshl(i, 1), addv[i], ln);
      Code04_MeanVariance1::lazy((jshl(i, 1) | 1), addv[i], rn);
      (addv[i] = 0);
    }
  }
  static void lazy(int i, double v, int n) {
    (sum2[i] += (((sum1[i] * v) * 2) + ((v * v) * n)));
    (sum1[i] += (v * n));
    (addv[i] += v);
  }
  static void build(int l, int r, int i) {
    if ((l == r)) {
      (sum1[i] = arr[l]);
      (sum2[i] = (arr[l] * arr[l]));
    } else {
      int mid = jshr((l + r), 1);
      Code04_MeanVariance1::build(l, mid, jshl(i, 1));
      Code04_MeanVariance1::build((mid + 1), r, (jshl(i, 1) | 1));
      Code04_MeanVariance1::up(i);
    }
    (addv[i] = 0);
  }
  static void add(int jobl, int jobr, double jobv, int l, int r, int i) {
    if (((jobl <= l) && (r <= jobr))) {
      Code04_MeanVariance1::lazy(i, jobv, ((r - l) + 1));
    } else {
      int mid = jshr((l + r), 1);
      Code04_MeanVariance1::down(i, ((mid - l) + 1), (r - mid));
      if ((jobl <= mid)) {
        Code04_MeanVariance1::add(jobl, jobr, jobv, l, mid, jshl(i, 1));
      }
      if ((jobr > mid)) {
        Code04_MeanVariance1::add(jobl, jobr, jobv, (mid + 1), r,
                                  (jshl(i, 1) | 1));
      }
      Code04_MeanVariance1::up(i);
    }
  }
  static double query(Array<double> sum, int jobl, int jobr, int l, int r,
                      int i) {
    if (((jobl <= l) && (r <= jobr))) {
      return sum[i];
    }
    int mid = jshr((l + r), 1);
    Code04_MeanVariance1::down(i, ((mid - l) + 1), (r - mid));
    double ans = 0;
    if ((jobl <= mid)) {
      (ans += Code04_MeanVariance1::query(sum, jobl, jobr, l, mid, jshl(i, 1)));
    }
    if ((jobr > mid)) {
      (ans += Code04_MeanVariance1::query(sum, jobl, jobr, (mid + 1), r,
                                          (jshl(i, 1) | 1)));
    }
    return ans;
  }
  static void java_main(Array<String> args) {
    IO io = IO();
    int n = io.nextInt();
    int m = io.nextInt();
    for (int i = 1; (i <= n); (i++)) {
      (arr[i] = io.nextDouble());
    }
    Code04_MeanVariance1::build(1, n, 1);
    double jobv = {};
    {
      int i = 1;
      int op = {};
      int jobl = {};
      int jobr = {};
      for (; (i <= m); (i++)) {
        (op = io.nextInt());
        if ((op == 1)) {
          (jobl = io.nextInt());
          (jobr = io.nextInt());
          (jobv = io.nextDouble());
          Code04_MeanVariance1::add(jobl, jobr, jobv, 1, n, 1);
        } else if ((op == 2)) {
          (jobl = io.nextInt());
          (jobr = io.nextInt());
          double ans =
              jdiv(Code04_MeanVariance1::query(sum1, jobl, jobr, 1, n, 1),
                   ((jobr - jobl) + 1));
          io.println(String::format(String(u"%.4f"), ans));
        } else {
          (jobl = io.nextInt());
          (jobr = io.nextInt());
          double a = Code04_MeanVariance1::query(sum1, jobl, jobr, 1, n, 1);
          double b = Code04_MeanVariance1::query(sum2, jobl, jobr, 1, n, 1);
          double size = ((jobr - jobl) + 1);
          double ans = (jdiv(b, size) - (jdiv(a, size) * jdiv(a, size)));
          io.println(String::format(String(u"%.4f"), ans));
        }
      }
    }
    io.flush();
    io.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code04_MeanVariance1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 平均数和方差
// 给定一个长度为n的数组arr，操作分为三种类型，一共调用m次
// 操作 1 l r : arr数组中[l, r]范围上每个数字加上k，k为double类型
// 操作 2 l r : 查询arr数组中[l, r]范围上所有数字的平均数，返回double类型
// 操作 3 l r : 查询arr数组中[l, r]范围上所有数字的方差，返回double类型
// 测试链接 : https://www.luogu.com.cn/problem/P1471
// 如下实现是正确的，但是洛谷平台对空间卡的很严，只有使用C++能全部通过
// C++版本就是本节代码中的Code04_MeanVariance2文件
// C++版本和java版本逻辑完全一样，但只有C++版本可以通过所有测试用例
// java的版本就是无法完全通过，空间会超过限制，主要是IO空间占用大
// 这是洛谷平台没有照顾各种语言的实现所导致的
// 在真正笔试、比赛时，一定是兼顾各种语言的，该实现是一定正确的
        // 区间累加和
        // 区间平方和
        // 懒更新信息(范围内每个数字增加多少)
        // Kattio类IO效率很好，但还是不如StreamTokenizer
        // 只有StreamTokenizer无法正确处理时，才考虑使用这个类
        // 参考链接 : https://oi-wiki.org/lang/java-pro/
*/

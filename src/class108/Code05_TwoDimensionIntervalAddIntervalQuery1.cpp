// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P4514

// Source: src/class108/Code05_TwoDimensionIntervalAddIntervalQuery1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code05_TwoDimensionIntervalAddIntervalQuery1 {
  inline static int MAXN = 2050;
  inline static int MAXM = 2050;
  inline static Array<Array<int>> info1 = make_array<int>(MAXN, MAXM);
  inline static Array<Array<int>> info2 = make_array<int>(MAXN, MAXM);
  inline static Array<Array<int>> info3 = make_array<int>(MAXN, MAXM);
  inline static Array<Array<int>> info4 = make_array<int>(MAXN, MAXM);
  inline static int n = {};
  inline static int m = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code05_TwoDimensionIntervalAddIntervalQuery1() {}
  static int lowbit(int i) { return (i & (-i)); }
  static void add(int x, int y, int v) {
    int v1 = v;
    int v2 = (x * v);
    int v3 = (y * v);
    int v4 = ((x * y) * v);
    for (int i = x; (i <= n);
         (i += Code05_TwoDimensionIntervalAddIntervalQuery1::lowbit(i))) {
      for (int j = y; (j <= m);
           (j += Code05_TwoDimensionIntervalAddIntervalQuery1::lowbit(j))) {
        (info1[i][j] += v1);
        (info2[i][j] += v2);
        (info3[i][j] += v3);
        (info4[i][j] += v4);
      }
    }
  }
  static int sum(int x, int y) {
    int ans = 0;
    for (int i = x; (i > 0);
         (i -= Code05_TwoDimensionIntervalAddIntervalQuery1::lowbit(i))) {
      for (int j = y; (j > 0);
           (j -= Code05_TwoDimensionIntervalAddIntervalQuery1::lowbit(j))) {
        (ans +=
         ((((((x + 1) * (y + 1)) * info1[i][j]) - ((y + 1) * info2[i][j])) -
           ((x + 1) * info3[i][j])) +
          info4[i][j]));
      }
    }
    return ans;
  }
  static void add(int a, int b, int c, int d, int v) {
    Code05_TwoDimensionIntervalAddIntervalQuery1::add(a, b, v);
    Code05_TwoDimensionIntervalAddIntervalQuery1::add(a, (d + 1), (-v));
    Code05_TwoDimensionIntervalAddIntervalQuery1::add((c + 1), b, (-v));
    Code05_TwoDimensionIntervalAddIntervalQuery1::add((c + 1), (d + 1), v);
  }
  static int range(int a, int b, int c, int d) {
    return [&]() {
      auto jleft = [&]() {
        auto jleft = [&]() {
          auto jleft = Code05_TwoDimensionIntervalAddIntervalQuery1::sum(c, d);
          auto jright =
              Code05_TwoDimensionIntervalAddIntervalQuery1::sum((a - 1), d);
          return (jleft - jright);
        }();
        auto jright =
            Code05_TwoDimensionIntervalAddIntervalQuery1::sum(c, (b - 1));
        return (jleft - jright);
      }();
      auto jright =
          Code05_TwoDimensionIntervalAddIntervalQuery1::sum((a - 1), (b - 1));
      return (jleft + jright);
    }();
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    String op = {};
    int a = {};
    int b = {};
    int c = {};
    int d = {};
    int v = {};
    while ((in.nextToken() != -1)) {
      (op = in.sval);
      if (op.equals(String(u"X"))) {
        in.nextToken();
        (n = static_cast<int>(in.nval));
        in.nextToken();
        (m = static_cast<int>(in.nval));
      } else if (op.equals(String(u"L"))) {
        in.nextToken();
        (a = static_cast<int>(in.nval));
        in.nextToken();
        (b = static_cast<int>(in.nval));
        in.nextToken();
        (c = static_cast<int>(in.nval));
        in.nextToken();
        (d = static_cast<int>(in.nval));
        in.nextToken();
        (v = static_cast<int>(in.nval));
        Code05_TwoDimensionIntervalAddIntervalQuery1::add(a, b, c, d, v);
      } else {
        in.nextToken();
        (a = static_cast<int>(in.nval));
        in.nextToken();
        (b = static_cast<int>(in.nval));
        in.nextToken();
        (c = static_cast<int>(in.nval));
        in.nextToken();
        (d = static_cast<int>(in.nval));
        jout.println(
            Code05_TwoDimensionIntervalAddIntervalQuery1::range(a, b, c, d));
      }
    }
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code05_TwoDimensionIntervalAddIntervalQuery1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 二维数组上范围增加、范围查询，使用树状数组的模版(java)
// 测试链接 : https://www.luogu.com.cn/problem/P4514
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 维护信息 : d[i][j]
        // 维护信息 : d[i][j] * i
        // 维护信息 : d[i][j] * j
        // 维护信息 : d[i][j] * i * j
        // 以(1,1)左上角，以(x,y)右下角
*/

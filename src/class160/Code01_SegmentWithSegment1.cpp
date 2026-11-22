// Source: src/class160/Code01_SegmentWithSegment1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_SegmentWithSegment1 {
  inline static int n = 101;
  inline static int m = 1001;
  inline static int MINX = 100;
  inline static int MAXX = 200;
  inline static int MINY = 0;
  inline static int MAXY = 1000;
  inline static Array<Array<int>> tree =
      make_array<int>(jshl(n, 2), jshl(m, 2));
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_SegmentWithSegment1() {}
  static void innerBuild(int yl, int yr, int xi, int yi) {
    (tree[xi][yi] = (-1));
    if ((yl < yr)) {
      int mid = jdiv((yl + yr), 2);
      Code01_SegmentWithSegment1::innerBuild(yl, mid, xi, jshl(yi, 1));
      Code01_SegmentWithSegment1::innerBuild((mid + 1), yr, xi,
                                             (jshl(yi, 1) | 1));
    }
  }
  static void innerUpdate(int jobi, int jobv, int yl, int yr, int xi, int yi) {
    if ((yl == yr)) {
      (tree[xi][yi] = jmax(tree[xi][yi], jobv));
    } else {
      int mid = jdiv((yl + yr), 2);
      if ((jobi <= mid)) {
        Code01_SegmentWithSegment1::innerUpdate(jobi, jobv, yl, mid, xi,
                                                jshl(yi, 1));
      } else {
        Code01_SegmentWithSegment1::innerUpdate(jobi, jobv, (mid + 1), yr, xi,
                                                (jshl(yi, 1) | 1));
      }
      (tree[xi][yi] = jmax(tree[xi][jshl(yi, 1)], tree[xi][(jshl(yi, 1) | 1)]));
    }
  }
  static int innerQuery(int jobl, int jobr, int yl, int yr, int xi, int yi) {
    if (((jobl <= yl) && (yr <= jobr))) {
      return tree[xi][yi];
    }
    int mid = jdiv((yl + yr), 2);
    int ans = (-1);
    if ((jobl <= mid)) {
      (ans = Code01_SegmentWithSegment1::innerQuery(jobl, jobr, yl, mid, xi,
                                                    jshl(yi, 1)));
    }
    if ((jobr > mid)) {
      (ans = jmax(ans, Code01_SegmentWithSegment1::innerQuery(
                           jobl, jobr, (mid + 1), yr, xi, (jshl(yi, 1) | 1))));
    }
    return ans;
  }
  static void outerBuild(int xl, int xr, int xi) {
    Code01_SegmentWithSegment1::innerBuild(MINY, MAXY, xi, 1);
    if ((xl < xr)) {
      int mid = jdiv((xl + xr), 2);
      Code01_SegmentWithSegment1::outerBuild(xl, mid, jshl(xi, 1));
      Code01_SegmentWithSegment1::outerBuild((mid + 1), xr, (jshl(xi, 1) | 1));
    }
  }
  static void outerUpdate(int jobx, int joby, int jobv, int xl, int xr,
                          int xi) {
    Code01_SegmentWithSegment1::innerUpdate(joby, jobv, MINY, MAXY, xi, 1);
    if ((xl < xr)) {
      int mid = jdiv((xl + xr), 2);
      if ((jobx <= mid)) {
        Code01_SegmentWithSegment1::outerUpdate(jobx, joby, jobv, xl, mid,
                                                jshl(xi, 1));
      } else {
        Code01_SegmentWithSegment1::outerUpdate(jobx, joby, jobv, (mid + 1), xr,
                                                (jshl(xi, 1) | 1));
      }
    }
  }
  static int outerQuery(int jobxl, int jobxr, int jobyl, int jobyr, int xl,
                        int xr, int xi) {
    if (((jobxl <= xl) && (xr <= jobxr))) {
      return Code01_SegmentWithSegment1::innerQuery(jobyl, jobyr, MINY, MAXY,
                                                    xi, 1);
    }
    int mid = jdiv((xl + xr), 2);
    int ans = (-1);
    if ((jobxl <= mid)) {
      (ans = Code01_SegmentWithSegment1::outerQuery(jobxl, jobxr, jobyl, jobyr,
                                                    xl, mid, jshl(xi, 1)));
    }
    if ((jobxr > mid)) {
      (ans = jmax(ans, Code01_SegmentWithSegment1::outerQuery(
                           jobxl, jobxr, jobyl, jobyr, (mid + 1), xr,
                           (jshl(xi, 1) | 1))));
    }
    return ans;
  }
  static void java_main(Array<String> args) {
    IO io = IO();
    int q = io.nextInt();
    String op = {};
    int a = {};
    int b = {};
    int c = {};
    int d = {};
    while ((q != 0)) {
      Code01_SegmentWithSegment1::outerBuild(MINX, MAXX, 1);
      for (int i = 1; (i <= q); (i++)) {
        (op = io.next());
        if (op.equals(String(u"I"))) {
          (a = io.nextInt());
          (b = static_cast<int>((io.nextDouble() * 10)));
          (c = static_cast<int>((io.nextDouble() * 10)));
          Code01_SegmentWithSegment1::outerUpdate(a, b, c, MINX, MAXX, 1);
        } else {
          (a = io.nextInt());
          (b = io.nextInt());
          (c = static_cast<int>((io.nextDouble() * 10)));
          (d = static_cast<int>((io.nextDouble() * 10)));
          int xl = jmin(a, b);
          int xr = jmax(a, b);
          int yl = jmin(c, d);
          int yr = jmax(c, d);
          int ans = Code01_SegmentWithSegment1::outerQuery(xl, xr, yl, yr, MINX,
                                                           MAXX, 1);
          if ((ans == (-1))) {
            io.println(ans);
          } else {
            io.println(jdiv(static_cast<double>(ans), 10));
          }
        }
      }
      (q = io.nextInt());
    }
    io.flush();
    io.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code01_SegmentWithSegment1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 线段树套线段树，java版
// 人有三种属性，身高、活泼度、缘分值
// 身高为int类型，活泼度和缘分值为小数点后最多1位的double类型
// 实现一种结构，提供如下两种类型的操作
// 操作 I a b c   : 加入一个人，身高为a，活泼度为b，缘分值为c
// 操作 Q a b c d : 查询身高范围[a,b]，活泼度范围[c,d]，所有人中的缘分最大值
// 注意操作Q，如果a > b需要交换，如果c > d需要交换
// 100 <= 身高 <= 200
// 0.0 <= 活泼度、缘分值 <= 100.0
// 测试链接 : https://acm.hdu.edu.cn/showproblem.php?pid=1823
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 身高范围内有多少数字
        // 活泼度范围内有多少数字
        // 身高范围对应[MINX, MAXX]，活泼度范围对应[MINY, MAXY]
        // 外层是身高线段树，内层是活泼度线段树
        // 每一个外层线段树的节点，对应着一棵内层线段树
        // 内层线段树收集缘分值
        // 读写工具类
*/

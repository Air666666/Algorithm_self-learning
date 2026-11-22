// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P5656

// Source: src/class140/Code01_DiophantineEquation1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_DiophantineEquation1 {
  inline static i64 d = {};
  inline static i64 x = {};
  inline static i64 y = {};
  inline static i64 px = {};
  inline static i64 py = {};
  inline static i64 a = {};
  inline static i64 b = {};
  inline static i64 c = {};
  inline static i64 xd = {};
  inline static i64 yd = {};
  inline static i64 times = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_DiophantineEquation1() {}
  static void exgcd(i64 a, i64 b) {
    if ((b == 0)) {
      (d = a);
      (x = 1);
      (y = 0);
    } else {
      Code01_DiophantineEquation1::exgcd(b, jrem(a, b));
      (px = x);
      (py = y);
      (x = py);
      (y = (px - (py * jdiv(a, b))));
    }
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    int cases = static_cast<int>(in.nval);
    for (int t = 1; (t <= cases); (t++)) {
      in.nextToken();
      (a = static_cast<i64>(in.nval));
      in.nextToken();
      (b = static_cast<i64>(in.nval));
      in.nextToken();
      (c = static_cast<i64>(in.nval));
      Code01_DiophantineEquation1::exgcd(a, b);
      if ((jrem(c, d) != 0)) {
        out.println((-1));
      } else {
        (x *= jdiv(c, d));
        (y *= jdiv(c, d));
        (xd = jdiv(b, d));
        (yd = jdiv(a, d));
        if ((x < 0)) {
          (times = jdiv((((1 - x) + xd) - 1), xd));
          (x += (xd * times));
          (y -= (yd * times));
        } else {
          (times = jdiv((x - 1), xd));
          (x -= (xd * times));
          (y += (yd * times));
        }
        if ((y <= 0)) {
          out.print((x + String(u" ")));
          out.println((y + (yd * jdiv((((1 - y) + yd) - 1), yd))));
        } else {
          out.print(((jdiv((y - 1), yd) + 1) + String(u" ")));
          out.print((x + String(u" ")));
          out.print(((y - (jdiv((y - 1), yd) * yd)) + String(u" ")));
          out.print(((x + (jdiv((y - 1), yd) * xd)) + String(u" ")));
          out.println(y);
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
  Code01_DiophantineEquation1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 二元一次不定方程模版
// 给定a、b、c，求解方程ax + by = c
// 如果方程无解打印-1
// 如果方程无正整数解，但是有整数解
// 打印这些整数解中，x的最小正数值，y的最小正数值
// 如果方程有正整数解，打印正整数解的数量，同时打印所有正整数解中，
// x的最小正数值，y的最小正数值，x的最大正数值，y的最大正数值
// 1 <= a、b、c <= 10^9
// 测试链接 : https://www.luogu.com.cn/problem/P5656
// 如下实现是正确的，但是洛谷平台对空间卡的很严，只有使用C++能全部通过
// java的版本就是无法完全通过的，空间会超过限制，主要是IO空间占用大
// 这是洛谷平台没有照顾各种语言的实现所导致的
// 在真正笔试、比赛时，一定是兼顾各种语言的，该实现是一定正确的
// C++版本就是Code01_DiophantineEquation2文件
// C++版本和java版本逻辑完全一样，但只有C++版本可以通过所有测试用例
        // 扩展欧几里得算法
                                        //
x要想增长到>=1且最小的值，差几个xd，算出来就是k的值
                                        // 那应该是(1-x)/xd，结果向上取整
                                        //
x要想减少到>=1且最小的值，差几个xd，算出来就是k的值，向下取整
                                // 此时得到的(x, y)，是x为最小正整数时的一组解
                                // 然后继续讨论
                                        // x能取得的最小正数
                                        // y能取得的最小正数
                                        //
y减少到1以下，能减几次，就是正整数解的个数
                                        // x能取得的最小正数
                                        // y能取得的最小正数
                                        // x能取得的最大正数
                                        // y能取得的最大正数
*/

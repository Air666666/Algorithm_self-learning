// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P1516

// Source: src/class140/Code02_FrogsMeeting.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_FrogsMeeting {
  inline static i64 d = {};
  inline static i64 x = {};
  inline static i64 y = {};
  inline static i64 px = {};
  inline static i64 py = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_FrogsMeeting() {}
  static void exgcd(i64 a, i64 b) {
    if ((b == 0)) {
      (d = a);
      (x = 1);
      (y = 0);
    } else {
      Code02_FrogsMeeting::exgcd(b, jrem(a, b));
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
    i64 x1 = static_cast<i64>(in.nval);
    in.nextToken();
    i64 x2 = static_cast<i64>(in.nval);
    in.nextToken();
    i64 m = static_cast<i64>(in.nval);
    in.nextToken();
    i64 n = static_cast<i64>(in.nval);
    in.nextToken();
    i64 l = static_cast<i64>(in.nval);
    i64 a = {};
    i64 c = {};
    if ((x1 < x2)) {
      (a = (m - n));
      (c = (x2 - x1));
    } else {
      (a = (n - m));
      (c = (x1 - x2));
    }
    if ((a < 0)) {
      (a = (-a));
      (c = (l - c));
    }
    Code02_FrogsMeeting::exgcd(a, l);
    if ((jrem(c, d) != 0)) {
      out.println(String(u"Impossible"));
    } else {
      i64 x0 = jdiv((x * c), d);
      i64 xd = jdiv(l, d);
      if ((x0 < 0)) {
        (x0 += (jdiv((((1 - x0) + xd) - 1), xd) * xd));
      } else {
        (x0 -= (jdiv((x0 - 1), xd) * xd));
      }
      out.println(x0);
    }
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code02_FrogsMeeting::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 青蛙的约会
// 有一个周长为l的环，从环的0位置开始，规定只能沿着顺时针方向不停转圈
// 青蛙A在环的x1位置，每秒跳m个单位，青蛙B在x2位置，每秒跳n个单位
// 只有在某时刻，青蛙A和青蛙B来到环的同一个位置，才算相遇
// 如果两只青蛙相遇不了，打印"Impossible"
// 如果可以相遇，打印两只青蛙至少多久才能相遇
// 1 <= l <= 3 * 10^9
// 1 <= x1、x2、m、n <= 2 * 10^9
// x1 != x2
// 测试链接 : https://www.luogu.com.cn/problem/P1516
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 扩展欧几里得算法
                        // 解出的特解
                        // 单次幅度
                        // x0调整成>=1的最小正整数，处理办法和上一题一样
*/

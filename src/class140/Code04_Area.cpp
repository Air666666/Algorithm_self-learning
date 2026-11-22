// Source: src/class140/Code04_Area.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_Area {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_Area() {}
  static i64 gcd(i64 a, i64 b) {
    return ((b == 0) ? a : Code04_Area::gcd(b, jrem(a, b)));
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    int cases = static_cast<int>(in.nval);
    for (int t = 1; (t <= cases); (t++)) {
      in.nextToken();
      int n = static_cast<int>(in.nval);
      int edges = 0;
      double area = 0;
      {
        int i = 1;
        int x = 0;
        int y = 0;
        int dx = {};
        int dy = {};
        for (; (i <= n); (i++)) {
          in.nextToken();
          (dx = static_cast<int>(in.nval));
          in.nextToken();
          (dy = static_cast<int>(in.nval));
          (edges += [&]() {
            auto jargument_0 = std::abs(dx);
            auto jargument_1 = std::abs(dy);
            return Code04_Area::gcd(jargument_0, jargument_1);
          }());
          (area += ((x * (y + dy)) - ((x + dx) * y)));
          (x += dx);
          (y += dy);
        }
      }
      (area /= 2);
      int inners = (jdiv(static_cast<int>((area - edges)), 2) + 1);
      out.println(((String(u"Scenario #") + t) + String(u":")));
      out.print((inners + String(u" ")));
      out.print((edges + String(u" ")));
      out.printf(String(u"%.1f"), area);
      out.println();
      out.println();
    }
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code04_Area::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 机器人的移动区域
// 二维网格中只有x和y的值都为整数的坐标，才叫格点
// 某个机器人从格点(0,0)出发，每次机器人都走直线到达(x + dx, y + dy)的格点
// 一共移动n次，每次的(dx,
dy)都给定，途中路线不会交叉，输入保证机器人最终回到(0,0)
// 机器人走的路线所围成的区域一定是多边形，输入保证机器人一定沿着逆时针方向行动
// 返回多边形的内部一共几个格点，多边形的边上一共几个格点，多边形的面积
// 3 <= n <= 100
// -100 <= dx、dy <= 100
// 测试链接 : http://poj.org/problem?id=1265
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
                                // 题目3的重要结论
                                // 逆时针方向转动的鞋带公式
                        // 鞋带公式最后要/2
                        // pick定理
                        // 多边形面积 = 边界上格点数/2 + 内部格点数 - 1
                        // 内部格点数 = 多边形面积 - 边界上格点数/2 + 1
*/

// 原题测试 / 参考链接（保留上游原始地址）
// http://poj.org/problem?id=2947
// https://oi-wiki.org/lang/java-pro/

// Source: src/class135/Code02_WidgetFactory.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_WidgetFactory {
  inline static int MOD = 7;
  inline static int MAXN = 302;
  inline static Array<Array<int>> mat = make_array<int>(MAXN, MAXN);
  inline static Array<int> inv = make_array<int>(MOD);
  inline static Array<String> days = Array<String>{
      String(u"MON"), String(u"TUE"), String(u"WED"), String(u"THU"),
      String(u"FRI"), String(u"SAT"), String(u"SUN")};
  inline static int n = {};
  inline static int m = {};
  inline static int s = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_WidgetFactory() {}
  static void inv_method() {
    (inv[1] = 1);
    for (int i = 2; (i < MOD); (i++)) {
      (inv[i] = static_cast<int>(
           (MOD -
            jrem((static_cast<i64>(inv[jrem(MOD, i)]) * jdiv(MOD, i)), MOD))));
    }
  }
  static int gcd(int a, int b) {
    return ((b == 0) ? a : Code02_WidgetFactory::gcd(b, jrem(a, b)));
  }
  static void prepare() {
    for (int i = 1; (i <= s); (i++)) {
      for (int j = 1; (j <= (s + 1)); (j++)) {
        (mat[i][j] = 0);
      }
    }
  }
  static int day(String str) {
    for (int i = 0; (i < days.length); (i++)) {
      if (str.equals(days[i])) {
        return i;
      }
    }
    return (-1);
  }
  static void gauss(int n) {
    for (int i = 1; (i <= n); (i++)) {
      for (int j = 1; (j <= n); (j++)) {
        if (((j < i) && (mat[j][j] != 0))) {
          continue;
        }
        if ((mat[j][i] != 0)) {
          Code02_WidgetFactory::swap(i, j);
          break;
        }
      }
      if ((mat[i][i] != 0)) {
        for (int j = 1; (j <= n); (j++)) {
          if (((i != j) && (mat[j][i] != 0))) {
            int gcd = Code02_WidgetFactory::gcd(mat[j][i], mat[i][i]);
            int a = jdiv(mat[i][i], gcd);
            int b = jdiv(mat[j][i], gcd);
            if (((j < i) && (mat[j][j] != 0))) {
              for (int k = j; (k < i); (k++)) {
                (mat[j][k] = jrem((mat[j][k] * a), MOD));
              }
            }
            for (int k = i; (k <= (n + 1)); (k++)) {
              (mat[j][k] =
                   jrem((jrem(((mat[j][k] * a) - (mat[i][k] * b)), MOD) + MOD),
                        MOD));
            }
          }
        }
      }
    }
    for (int i = 1; (i <= n); (i++)) {
      if ((mat[i][i] != 0)) {
        bool flag = false;
        for (int j = (i + 1); (j <= n); (j++)) {
          if ((mat[i][j] != 0)) {
            (flag = true);
            break;
          }
        }
        if ((!flag)) {
          (mat[i][(n + 1)] = jrem((mat[i][(n + 1)] * inv[mat[i][i]]), MOD));
          (mat[i][i] = 1);
        }
      }
    }
  }
  static void swap(int a, int b) {
    Array<int> tmp = mat[a];
    (mat[a] = mat[b]);
    (mat[b] = tmp);
  }
  static void java_main(Array<String> args) {
    Code02_WidgetFactory::inv_method();
    IO io = IO();
    (n = io.nextInt());
    (m = io.nextInt());
    while (((n != 0) && (m != 0))) {
      (s = jmax(n, m));
      Code02_WidgetFactory::prepare();
      for (int i = 1; (i <= m); (i++)) {
        int k = io.nextInt();
        String st = io.next();
        String et = io.next();
        for (int j = 1; (j <= k); (j++)) {
          int tool = io.nextInt();
          (mat[i][tool] = jrem((mat[i][tool] + 1), MOD));
        }
        (mat[i][(s + 1)] =
             jrem((jrem(([&]() {
                          auto jleft = Code02_WidgetFactory::day(et);
                          auto jright = Code02_WidgetFactory::day(st);
                          return (jleft - jright);
                        }() +
                         1),
                        MOD) +
                   MOD),
                  MOD));
      }
      Code02_WidgetFactory::gauss(s);
      int sign = 1;
      for (int i = 1; (i <= s); (i++)) {
        if (((mat[i][i] == 0) && (mat[i][(s + 1)] != 0))) {
          (sign = (-1));
          break;
        }
        if (((i <= n) && (mat[i][i] == 0))) {
          (sign = 0);
        }
      }
      if ((sign == (-1))) {
        io.println(String(u"Inconsistent data."));
      } else if ((sign == 0)) {
        io.println(String(u"Multiple solutions."));
      } else {
        for (int i = 1; (i <= n); (i++)) {
          if ((mat[i][(s + 1)] < 3)) {
            (mat[i][(s + 1)] += 7);
          }
        }
        for (int i = 1; (i < n); (i++)) {
          io.print((mat[i][(s + 1)] + String(u" ")));
        }
        io.println(mat[n][(s + 1)]);
      }
      (n = io.nextInt());
      (m = io.nextInt());
    }
    io.flush();
    io.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code02_WidgetFactory::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 工具工厂
// 一共有n种工具，编号1~n，一共有m条记录，其中一条记录格式如下：
// 4 WED SUN 13 18 1 13
// 表示有个工人一共加工了4件工具，从某个星期三开始工作，到某个星期天结束工作
// 加工的工具依次为13号、18号、1号、13号
// 每个工人在工作期间不休息，每件工具都是串行加工的，完成一件后才开始下一件
// 每种工具制作天数是固定的，并且任何工具的制作天数最少3天、最多9天
// 但该数据丢失了，所以现在需要根据记录，推断出每种工具的制作天数
// 如果记录之间存在矛盾，打印"Inconsistent data."
// 如果记录无法确定每种工具的制作天数，打印"Multiple solutions."
// 如果记录能够确定每种工具的制作天数，打印所有结果
// 1 <= n、m <= 300
// 测试链接 : http://poj.org/problem?id=2947
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 高斯消元解决同余方程组模版，保证初始系数没有负数
                        // 下一组n和m
        // Kattio类IO效率很好，但还是不如StreamTokenizer
        // 只有StreamTokenizer无法正确处理时，才考虑使用这个类
        // 参考链接 : https://oi-wiki.org/lang/java-pro/
*/

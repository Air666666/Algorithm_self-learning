// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P2474

// Source: src/class142/Code05_Balance.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code05_Balance {
  inline static int MAXN = 51;
  inline static Array<Array<int>> dmin = make_array<int>(MAXN, MAXN);
  inline static Array<Array<int>> dmax = make_array<int>(MAXN, MAXN);
  inline static Array<Array<jchar>> s = make_array<jchar>(MAXN, MAXN);
  inline static int n = {};
  inline static int a = {};
  inline static int b = {};
  inline static int ans1 = {};
  inline static int ans2 = {};
  inline static int ans3 = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code05_Balance() {}
  static void compute() {
    for (int i = 1; (i <= n); (i++)) {
      for (int j = 1; (j <= n); (j++)) {
        if ((s[i][j] == u'=')) {
          (dmin[i][j] = 0);
          (dmax[i][j] = 0);
        } else if ((s[i][j] == u'+')) {
          (dmin[i][j] = 1);
          (dmax[i][j] = 2);
        } else if ((s[i][j] == u'-')) {
          (dmin[i][j] = (-2));
          (dmax[i][j] = (-1));
        } else {
          (dmin[i][j] = (-2));
          (dmax[i][j] = 2);
        }
      }
    }
    for (int i = 1; (i <= n); (i++)) {
      (dmin[i][i] = 0);
      (dmax[i][i] = 0);
    }
    for (int bridge = 1; (bridge <= n); (bridge++)) {
      for (int i = 1; (i <= n); (i++)) {
        for (int j = 1; (j <= n); (j++)) {
          (dmin[i][j] = jmax(dmin[i][j], (dmin[i][bridge] + dmin[bridge][j])));
          (dmax[i][j] = jmin(dmax[i][j], (dmax[i][bridge] + dmax[bridge][j])));
        }
      }
    }
    (ans1 = (ans2 = (ans3 = 0)));
    for (int i = 1; (i <= n); (i++)) {
      for (int j = 1; (j < i); (j++)) {
        if (((((i != a) && (i != b)) && (j != a)) && (j != b))) {
          if (((dmin[a][i] > dmax[j][b]) || (dmin[a][j] > dmax[i][b]))) {
            (ans1++);
          }
          if (((dmax[a][i] < dmin[j][b]) || (dmax[a][j] < dmin[i][b]))) {
            (ans3++);
          }
          if ((((dmin[a][i] == dmax[a][i]) && (dmin[j][b] == dmax[j][b])) &&
               (dmin[a][i] == dmin[j][b]))) {
            (ans2++);
          } else if ((((dmin[b][i] == dmax[b][i]) &&
                       (dmin[j][a] == dmax[j][a])) &&
                      (dmin[b][i] == dmin[j][a]))) {
            (ans2++);
          }
        }
      }
    }
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    IO out = IO(IO(jout));
    Array<String> numbers = br.readLine().split(String(u" "));
    (n = std::stoi(text(numbers[0])));
    (a = std::stoi(text(numbers[1])));
    (b = std::stoi(text(numbers[2])));
    Array<jchar> line = {};
    for (int i = 1; (i <= n); (i++)) {
      (line = br.readLine().toCharArray());
      for (int j = 1; (j <= n); (j++)) {
        (s[i][j] = line[(j - 1)]);
      }
    }
    Code05_Balance::compute();
    out.println(((((ans1 + String(u" ")) + ans2) + String(u" ")) + ans3));
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code05_Balance::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 天平
// 一共有n个砝码，编号1~n，每个砝码的重量均为1克，或者2克，或者3克
// 砝码与砝码之间的关系是一个n * n的二维数组s
// s[i][j] == '+'，砝码i比砝码j重        s[i][j] == '-'，砝码i比砝码j轻
// s[i][j] == '='，砝码i和砝码j重量一样   s[i][j] == '?'，砝码i和砝码j关系未知
// 数据保证至少存在一种情况符合该矩阵
//
给定编号为a和b的砝码，这两个砝码一定会放在天平的左边，你要另选两个砝码放在天平右边
//
返回有多少种方法，一定让天平左边重(ans1)，一定让天平一样重(ans2)，一定让天平右边重(ans3)
// 1 <= n <= 50
// 测试链接 : https://www.luogu.com.cn/problem/P2474
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
                // 设置初始关系
                // 来自讲解065，Floyd算法
                // 统计答案
*/

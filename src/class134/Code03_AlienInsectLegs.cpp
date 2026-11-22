// Source: src/class134/Code03_AlienInsectLegs.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_AlienInsectLegs {
  inline static int BIT = 64;
  inline static int MAXN = 2002;
  inline static int MAXM = (jdiv(MAXN, BIT) + 1);
  inline static Array<Array<i64>> mat = make_array<i64>(MAXN, MAXM);
  inline static int n = {};
  inline static int m = {};
  inline static int s = {};
  inline static int need = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_AlienInsectLegs() {}
  static void gauss(int n) {
    (need = 0);
    for (int i = 1; (i <= n); (i++)) {
      for (int j = i; (j <= n); (j++)) {
        if ((Code03_AlienInsectLegs::get(j, i) == 1)) {
          Code03_AlienInsectLegs::swap(i, j);
          (need = jmax(need, j));
          break;
        }
      }
      if ((Code03_AlienInsectLegs::get(i, i) == 0)) {
        return;
      }
      for (int j = 1; (j <= n); (j++)) {
        if (((i != j) && (Code03_AlienInsectLegs::get(j, i) == 1))) {
          Code03_AlienInsectLegs::eor(i, j, (n + 2));
        }
      }
    }
  }
  static void set(int row, int col, int v) {
    if ((v == 0)) {
      (mat[row][jdiv(col, BIT)] &= (~jshl(1LL, jrem(col, BIT))));
    } else {
      (mat[row][jdiv(col, BIT)] |= jshl(1LL, jrem(col, BIT)));
    }
  }
  static int get(int row, int col) {
    return (((jshr(mat[row][jdiv(col, BIT)], jrem(col, BIT)) & 1) == 1) ? 1
                                                                        : 0);
  }
  static void eor(int row1, int row2, int bits) {
    for (int k = 0; (k <= jdiv(bits, BIT)); (k++)) {
      (mat[row2][k] ^= mat[row1][k]);
    }
  }
  static void swap(int a, int b) {
    Array<i64> tmp = mat[a];
    (mat[a] = mat[b]);
    (mat[b] = tmp);
  }
  static void java_main(Array<String> args) {
    IO io = IO();
    (n = io.nextInt());
    (m = io.nextInt());
    (s = jmax(n, m));
    for (int i = 1; (i <= m); (i++)) {
      Array<jchar> line = io.next().toCharArray();
      for (int j = 1; (j <= n); (j++)) {
        Code03_AlienInsectLegs::set(i, j, (line[(j - 1)] - u'0'));
      }
      Code03_AlienInsectLegs::set(i, (s + 1), io.nextInt());
    }
    Code03_AlienInsectLegs::gauss(s);
    int sign = 1;
    for (int i = 1; (i <= n); (i++)) {
      if ((Code03_AlienInsectLegs::get(i, i) == 0)) {
        (sign = 0);
        break;
      }
    }
    if ((sign == 0)) {
      io.println(String(u"Cannot Determine"));
    } else {
      io.println(need);
      for (int i = 1; (i <= n); (i++)) {
        if ((Code03_AlienInsectLegs::get(i, (s + 1)) == 1)) {
          io.println(String(u"?y7M#"));
        } else {
          io.println(String(u"Earth"));
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
  Code03_AlienInsectLegs::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 外星千足虫
// 一共有n种虫子，编号1~n，虫子腿为奇数认为是外星虫，偶数认为是地球虫
// 一共有m条虫子腿的测量记录，记录编号1~m
// 比如其中一条测量记录为，011
1，表示1号虫没参与，2号、3号虫参与了，总腿数为奇数
// 测量记录保证不会有自相矛盾的情况，但是可能有冗余的测量结果
//
也许拥有从第1号到第k号测量记录就够了，k+1~m号测量记录有或者没有都不影响测量结果
// 打印这个k，并且打印每种虫子到底是外星虫还是地球虫
// 如果使用所有的测量结果，依然无法确定每种虫子的属性，打印"Cannot Determine"
// 1 <= n <= 1000
// 1 <= m <= 2000
// 测试链接 : https://www.luogu.com.cn/problem/P2447
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 高斯消元解决异或方程组模版 + 位图，很小的改写
                        // 一旦没有唯一解，可以结束了
                                        //
因为列从1开始，所以从第1位状态开始才有用
                                        // 于是1~n+1列的状态，对应1~n+1位
                                        // 但是位图中永远有0位，只不过从来不使用
                                        // 于是一共有n+2位状态，都需要异或
        // 把row行，col列的状态设置成v
        // 得到row行，col列的状态
        // row2行状态 = row2行状态 ^ row1行状态
        // 状态一共有bits位
        // Kattio类IO效率很好，但还是不如StreamTokenizer
        // 只有StreamTokenizer无法正确处理时，才考虑使用这个类
        // 参考链接 : https://oi-wiki.org/lang/java-pro/
*/

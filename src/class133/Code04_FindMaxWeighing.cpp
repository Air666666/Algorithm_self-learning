// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P5027

// Source: src/class133/Code04_FindMaxWeighing.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_FindMaxWeighing {
  inline static int MAXN = 102;
  inline static Array<Array<int>> data = make_array<int>(MAXN, MAXN);
  inline static Array<Array<double>> mat = make_array<double>(MAXN, MAXN);
  inline static int n = {};
  inline static double sml = 1e-7;
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_FindMaxWeighing() {}
  static void gauss(int n) {
    for (int i = 1; (i <= n); (i++)) {
      int max = i;
      for (int j = 1; (j <= n); (j++)) {
        if (((j < i) && (std::abs(mat[j][j]) >= sml))) {
          continue;
        }
        if ([&]() {
              auto jleft = std::abs(mat[j][i]);
              auto jright = std::abs(mat[max][i]);
              return (jleft > jright);
            }()) {
          (max = j);
        }
      }
      Code04_FindMaxWeighing::swap(i, max);
      if ((std::abs(mat[i][i]) >= sml)) {
        double tmp = mat[i][i];
        for (int j = i; (j <= (n + 1)); (j++)) {
          (mat[i][j] /= tmp);
        }
        for (int j = 1; (j <= n); (j++)) {
          if ((i != j)) {
            double rate = jdiv(mat[j][i], mat[i][i]);
            for (int k = i; (k <= (n + 1)); (k++)) {
              (mat[j][k] -= (mat[i][k] * rate));
            }
          }
        }
      }
    }
  }
  static void swap(int a, int b) {
    Array<double> tmp = mat[a];
    (mat[a] = mat[b]);
    (mat[b] = tmp);
  }
  static int check() {
    Code04_FindMaxWeighing::gauss(n);
    double maxv = std::numeric_limits<double>::denorm_min();
    int maxt = 0;
    int ans = 0;
    for (int i = 1; (i <= n); (i++)) {
      if ((mat[i][i] == 0)) {
        return 0;
      }
      if (((mat[i][(n + 1)] <= 0) ||
           (mat[i][(n + 1)] != static_cast<int>(mat[i][(n + 1)])))) {
        return 0;
      }
      if ((maxv < mat[i][(n + 1)])) {
        (maxv = mat[i][(n + 1)]);
        (maxt = 1);
        (ans = i);
      } else if ((maxv == mat[i][(n + 1)])) {
        (maxt++);
      }
    }
    if ((maxt > 1)) {
      return 0;
    }
    return ans;
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    (n = static_cast<int>(in.nval));
    {
      int i = 1;
      int m = {};
      for (; (i <= (n + 1)); (i++)) {
        in.nextToken();
        (m = static_cast<int>(in.nval));
        {
          int j = 1;
          int cur = {};
          for (; (j <= m); (j++)) {
            in.nextToken();
            (cur = static_cast<int>(in.nval));
            (data[i][cur] = 1);
          }
        }
        in.nextToken();
        (data[i][(n + 1)] = static_cast<int>(in.nval));
      }
    }
    int ans = 0;
    int times = 0;
    for (int k = 1; (k <= (n + 1)); (k++)) {
      Code04_FindMaxWeighing::swapData(k, (n + 1));
      for (int i = 1; (i <= n); (i++)) {
        for (int j = 1; (j <= (n + 1)); (j++)) {
          (mat[i][j] = data[i][j]);
        }
      }
      Code04_FindMaxWeighing::swapData(k, (n + 1));
      int cur = Code04_FindMaxWeighing::check();
      if ((cur != 0)) {
        (times++);
        (ans = cur);
      }
    }
    if ((times != 1)) {
      out.println(String(u"illegal"));
    } else {
      out.println(ans);
    }
    out.flush();
    out.close();
    br.close();
  }
  static void swapData(int i, int j) {
    Array<int> tmp = data[i];
    (data[i] = data[j]);
    (data[j] = tmp);
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code04_FindMaxWeighing::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 有一次错误称重求最重物品
// 一共有n个物品，编号1~n，定义合法方案如下：
// 1，每个物品的重量都是确定的
// 2，每个物品的重量一定都是正整数
// 3，最重的物品有且仅有1个
// 每次称重格式类似：3 2 5 6 10，代表本次称重涉3个物品，编号为2、5、6，总重量10
// 一共有n+1条称重数据，称重数据整体有效的条件为：
// 错误的称重数据有且仅有1条，只有排除这条错误称重，才能求出一种合法方案
// 如果称重数据有效，打印最重三角形的编号
// 如果称重数据无效，打印"illegal"
// 1 <= m <= n <= 100
// 测试链接 : https://www.luogu.com.cn/problem/P5027
// 提交以下的code，提交时请把类名改成"Main"
// 这道题目后来增加了一个测试用例，让double类型的精度不够，导致出错
// 能通过的代码，就是本节课 Code04_FindMaxWeighing2 文件
        // 高斯消元解决加法方程组模版
        // 如果计算结果不是合法方案返回0
        // 如果计算结果是合法方案返回最重三角形的编号
*/

// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P1759

// Source: src/class086/Code04_Diving1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_Diving1 {
  inline static int MAXN = 101;
  inline static int MAXM = 201;
  inline static Array<int> a = make_array<int>(MAXN);
  inline static Array<int> b = make_array<int>(MAXN);
  inline static Array<int> c = make_array<int>(MAXN);
  inline static Array<Array<Array<int>>> dp = make_array<int>(MAXN, MAXM, MAXM);
  inline static Array<Array<Array<String>>> path =
      make_array<String>(MAXN, MAXM, MAXM);
  inline static int m = {};
  inline static int v = {};
  inline static int n = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_Diving1() {}
  static void build() {
    for (int i = 1; (i <= n); (i++)) {
      for (int j = 0; (j <= m); (j++)) {
        for (int k = 0; (k <= v); (k++)) {
          (dp[i][j][k] = 0);
          (path[i][j][k] = nullptr);
        }
      }
    }
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    while ((in.nextToken() != -1)) {
      (m = static_cast<int>(in.nval));
      in.nextToken();
      (v = static_cast<int>(in.nval));
      in.nextToken();
      (n = static_cast<int>(in.nval));
      Code04_Diving1::build();
      for (int i = 1; (i <= n); (i++)) {
        in.nextToken();
        (a[i] = static_cast<int>(in.nval));
        in.nextToken();
        (b[i] = static_cast<int>(in.nval));
        in.nextToken();
        (c[i] = static_cast<int>(in.nval));
      }
      Code04_Diving1::compute();
      out.println(dp[n][m][v]);
      out.println(path[n][m][v]);
    }
    out.flush();
    out.close();
    br.close();
  }
  static void compute() {
    String p2 = {};
    for (int i = 1; (i <= n); (i++)) {
      for (int j = 0; (j <= m); (j++)) {
        for (int k = 0; (k <= v); (k++)) {
          (dp[i][j][k] = dp[(i - 1)][j][k]);
          (path[i][j][k] = path[(i - 1)][j][k]);
          if (((j >= a[i]) && (k >= b[i]))) {
            if ((path[(i - 1)][(j - a[i])][(k - b[i])] == nullptr)) {
              (p2 = j::str(i));
            } else {
              (p2 = ((path[(i - 1)][(j - a[i])][(k - b[i])] + String(u" ")) +
                     j::str(i)));
            }
            if ((dp[i][j][k] < (dp[(i - 1)][(j - a[i])][(k - b[i])] + c[i]))) {
              (dp[i][j][k] = (dp[(i - 1)][(j - a[i])][(k - b[i])] + c[i]));
              (path[i][j][k] = p2);
            } else if ((dp[i][j][k] ==
                        (dp[(i - 1)][(j - a[i])][(k - b[i])] + c[i]))) {
              if ((p2.compareTo(path[i][j][k]) < 0)) {
                (path[i][j][k] = p2);
              }
            }
          }
        }
      }
    }
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code04_Diving1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 潜水的最大时间与方案
// 一共有n个工具，每个工具都有自己的重量a、阻力b、提升的停留时间c
// 因为背包有限，所以只能背重量不超过m的工具
// 因为力气有限，所以只能背阻力不超过v的工具
// 希望能在水下停留的时间最久
// 返回最久的停留时间和下标字典序最小的选择工具的方案
// 注意这道题的字典序设定（根据提交的结果推论的）：
// 下标方案整体构成的字符串保证字典序最小
// 比如下标方案"1 120"比下标方案"1 2"字典序小
// 测试链接 : https://www.luogu.com.cn/problem/P1759
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下的code，提交时请把类名改成"Main"，可以直接通过
// 讲解069 - 多维费用背包
// 不做空间压缩的版本
// 无法通过全部测试用例
// 这个题必须做空间压缩
// 空间压缩的实现在Code04_Diving2
        // 普通版本的多维费用背包
        // 为了好懂先实现不进行空间压缩的版本
                                        // 可能性1 : 不要i位置的货
                                        // 先把可能性1的答案设置上
                                        // 包括dp信息和path信息
                                                // 可能性2 : 要i位置的货
                                                // 那么需要:
                                                // 背包总重量限制j >= a[i]
                                                // 背包总阻力限制k >= b[i]
                                                //
然后选了i位置的货，就可以获得收益c[i]了
                                                // 可能性2收益 :
dp[i-1][j-a[i]][k-b[i]] + c[i]
                                                // 可能性2路径(p2) :
path[i-1][j-a[i]][k-b[i]] + " " + i
                                                                //
如果可能性2的路径，字典序小于，可能性1的路径
                                                                //
那么把路径设置成可能性2的路径
*/

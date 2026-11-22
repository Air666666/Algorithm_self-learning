// Source: src/class133/Code04_FindMaxWeighing2.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_FindMaxWeighing2 {
  inline static int MAXN = 102;
  inline static Array<Array<int>> data = make_array<int>(MAXN, MAXN);
  inline static Array<Array<i64>> mat = make_array<i64>(MAXN, MAXN);
  inline static int n = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_FindMaxWeighing2() {}
  static void swap(int a, int b) {
    Array<i64> tmp = mat[a];
    (mat[a] = mat[b]);
    (mat[b] = tmp);
  }
  static void gauss(int n) {
    for (int i = 1; (i <= n); (i++)) {
      int max = i;
      for (int j = 1; (j <= n); (j++)) {
        if (((j < i) && (mat[j][j] != 0))) {
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
      Code04_FindMaxWeighing2::swap(i, max);
      if ((mat[i][i] == 0)) {
        return;
      }
      for (int j = (i + 1); (j <= n); (j++)) {
        while ((mat[j][i] != 0)) {
          i64 rate = jdiv(mat[i][i], mat[j][i]);
          if ((rate != 0)) {
            for (int k = i; (k <= (n + 1)); (k++)) {
              (mat[i][k] -= (mat[j][k] * rate));
            }
          }
          Code04_FindMaxWeighing2::swap(i, j);
        }
      }
    }
  }
  static int check() {
    Code04_FindMaxWeighing2::gauss(n);
    for (int i = n; (i >= 1); (i--)) {
      if ((mat[i][i] == 0)) {
        return 0;
      }
      for (int j = (i + 1); (j <= n); (j++)) {
        (mat[i][(n + 1)] -= (mat[i][j] * mat[j][(n + 1)]));
      }
      if ((jrem(mat[i][(n + 1)], mat[i][i]) != 0)) {
        return 0;
      }
      (mat[i][(n + 1)] /= mat[i][i]);
    }
    i64 maxv = 0;
    int maxt = 0;
    int ans = 0;
    for (int i = 1; (i <= n); (i++)) {
      if ((mat[i][i] == 0)) {
        return 0;
      }
      if ((mat[i][(n + 1)] <= 0)) {
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
  static void swapData(int i, int j) {
    Array<int> tmp = data[i];
    (data[i] = data[j]);
    (data[j] = tmp);
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    {
      int i = 1;
      int m = {};
      for (; (i <= (n + 1)); (i++)) {
        (m = in.nextInt());
        {
          int j = 1;
          int cur = {};
          for (; (j <= m); (j++)) {
            (cur = in.nextInt());
            (data[i][cur] = 1);
          }
        }
        (data[i][(n + 1)] = in.nextInt());
      }
    }
    int ans = 0;
    int times = 0;
    for (int k = 1; (k <= (n + 1)); (k++)) {
      Code04_FindMaxWeighing2::swapData(k, (n + 1));
      for (int i = 1; (i <= n); (i++)) {
        for (int j = 1; (j <= (n + 1)); (j++)) {
          (mat[i][j] = data[i][j]);
        }
      }
      Code04_FindMaxWeighing2::swapData(k, (n + 1));
      int cur = Code04_FindMaxWeighing2::check();
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
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code04_FindMaxWeighing2::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 有一次错误称重求最重物品
// 这道题后来增加了测试数据，其实没意思
// 为了能通过，进行了如下改动，看看就好
// 看看注释的部分，其他代码和课上的一样
// 测试链接 : https://www.luogu.com.cn/problem/P5027
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // mat改成long[][]，删除sml，整数直接判断是否为0，不使用浮点误差阈值
                                // 原来是Math.abs(mat[j][j]) >= sml
                        // 找不到主元直接返回，由check检查零对角元素并判不合法
                        // 原版把主元行除以主元，使主元变为1的操作
                        // long除法会截断分数，所以不再进行这种归一化
                        // 原版消去当前列其他所有行的元素
                        // 现在只消去下方元素，得到上三角矩阵，之后再回代
                                // 反复进行整行相减、交换，直到mat[j][i]变为0
                                        // 原来是double rate = mat[j][i] /
mat[i][i]
                                        // 现在使用反方向的整数商，进行辗转消元
                                        //
商为0时可以跳过相减，但仍然需要交换两行
                                                        //
原版更新第j行，现在更新第i行
                                                        //
当前列的元素变成整数除法的余数
                                        // 设当前列两元素为a、b
                                        //
相减再交换后，变成b、a%b，与辗转相除相同
                                        //
在运算不溢出的前提下，最终下方元素变为0
                // 原版消元后直接读取最后一列，现在需要倒序回代
                // 因为只消去了下方元素，第i行仍然可能包含编号大于i的变量
                        // 编号大于i的变量已经求出，保存在对应行的最后一列
                        // 从当前方程右侧减去这些变量的贡献
                        // 通过余数精确判断重量是否为整数
                        // 除以当前变量的系数，得到重量，仍保存在最后一列
                // 原来是double maxv = Double.MIN_VALUE;
                        // 删除原来的浮点判整：
                        // mat[i][n + 1] != (int) mat[i][n + 1]
                        // 整数条件已在回代时检查，这里只检查正数
        // 读写工具类
*/

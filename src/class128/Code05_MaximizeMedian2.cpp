// Source: src/class128/Code05_MaximizeMedian2.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code05_MaximizeMedian2 {
  inline static int MAXN = 100005;
  inline static int n = {};
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static Array<double> help1 = make_array<double>(MAXN);
  inline static Array<Array<double>> dp1 = make_array<double>(MAXN, 2);
  inline static Array<int> sorted = make_array<int>(MAXN);
  inline static Array<int> help2 = make_array<int>(MAXN);
  inline static Array<Array<int>> dp2 = make_array<int>(MAXN, 2);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code05_MaximizeMedian2() {}
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    (n = static_cast<int>(in.nval));
    for (int i = 1; (i <= n); (i++)) {
      in.nextToken();
      (arr[i] = static_cast<int>(in.nval));
    }
    out.println(Code05_MaximizeMedian2::average());
    out.println(Code05_MaximizeMedian2::median());
    out.flush();
    out.close();
    br.close();
  }
  static double average() {
    double l = std::numeric_limits<double>::max();
    double r = std::numeric_limits<double>::denorm_min();
    double m = {};
    for (int i = 1; (i <= n); (i++)) {
      (l = jmin(l, arr[i]));
      (r = jmax(r, arr[i]));
    }
    for (int i = 1; (i <= 60); (i++)) {
      (m = jdiv((l + r), 2));
      if (Code05_MaximizeMedian2::check1(m)) {
        (l = m);
      } else {
        (r = m);
      }
    }
    return l;
  }
  static bool check1(double x) {
    for (int i = 1; (i <= n); (i++)) {
      (help1[i] = (static_cast<double>(arr[i]) - x));
    }
    (dp1[(n + 1)][0] = (dp1[(n + 1)][1] = 0));
    for (int i = n; (i >= 1); (i--)) {
      (dp1[i][0] = jmax((help1[i] + dp1[(i + 1)][0]), dp1[(i + 1)][1]));
      (dp1[i][1] = (help1[i] + dp1[(i + 1)][0]));
    }
    return (dp1[1][0] >= 0);
  }
  static int median() {
    for (int i = 1; (i <= n); (i++)) {
      (sorted[i] = arr[i]);
    }
    j::sort(sorted, 1, (n + 1));
    int l = 1;
    int r = n;
    int m = {};
    int ans = 0;
    while ((l <= r)) {
      (m = jdiv((l + r), 2));
      if (Code05_MaximizeMedian2::check2(sorted[m])) {
        (ans = sorted[m]);
        (l = (m + 1));
      } else {
        (r = (m - 1));
      }
    }
    return ans;
  }
  static bool check2(int x) {
    for (int i = 1; (i <= n); (i++)) {
      (help2[i] = ((arr[i] >= x) ? 1 : (-1)));
    }
    (dp2[(n + 1)][0] = (dp2[(n + 1)][1] = 0));
    for (int i = n; (i >= 1); (i--)) {
      (dp2[i][0] = jmax((help2[i] + dp2[(i + 1)][0]), dp2[(i + 1)][1]));
      (dp2[i][1] = (help2[i] + dp2[(i + 1)][0]));
    }
    return (dp2[1][0] > 0);
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code05_MaximizeMedian2::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 感谢热心的同学，找到了题目5的在线测试
// 最大平均值和中位数
// 给定一个长度为n的数组arr，现在要选出一些数
// 满足 任意两个相邻的数中至少有一个数被选择
// 被选中的数字平均值的最大值，打印的答案为double类型，误差在0.001以内
// 被选中的数字中位数的最大值，打印的答案为int类型，中位数认为是上中位数
// 2 <= n <= 10^5
// 1 <= arr[i] <= 10^9
// 测试链接 : https://atcoder.jp/contests/abc236/tasks/abc236_e
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 求最大平均数需要
        // 求最大上中位数需要
        // 最大平均数
        // 课上没有讲，但是很好理解，也是二分答案
        // 假设arr中最小值为l，最大值为r
        // 那么最大平均值必然在[l, r]范围上
        // 假设平均值设为中点m，arr中所有的数字都减去m
        // 如果此时，任意两个相邻的数中至少有一个数被选择
        // 最后得到的结果 >= 0，说明最大平均值至少是m，去右侧二分
        // 否则去左侧二分
                // 二分60次，足够让误差小于0.001
                // arr中所有的数字都减去x，得到的数字填入help1
                // 和课上讲的一样的逻辑
                // 任意两个相邻的数中至少有一个数被选择，去得到dp表
        // 最大上中位数，就和课上讲的一样了
*/

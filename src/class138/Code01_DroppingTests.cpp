// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P10505
// http://poj.org/problem?id=2976

// Source: src/class138/Code01_DroppingTests.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_DroppingTests {
  struct MyComparator;
  struct MyComparator {
    String toString() const { return j::str(static_cast<const void *>(this)); }
    MyComparator() {}
    int compare(Array<double> o1, Array<double> o2) {
      return jcompare(o2[2], o1[2]);
    }
  };
  inline static int MAXN = 1001;
  inline static double sml = 1e-6;
  inline static Array<Array<double>> arr = make_array<double>(MAXN, 3);
  inline static int n = {};
  inline static int k = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_DroppingTests() {}
  static bool check(double x) {
    for (int i = 1; (i <= n); (i++)) {
      (arr[i][2] = (arr[i][0] - (x * arr[i][1])));
    }
    j::sort(arr, 1, (n + 1), new MyComparator());
    double sum = 0;
    for (int i = 1; (i <= k); (i++)) {
      (sum += arr[i][2]);
    }
    return (sum >= 0);
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    (n = static_cast<int>(in.nval));
    in.nextToken();
    (k = static_cast<int>(in.nval));
    while (((n != 0) || (k != 0))) {
      (k = (n - k));
      for (int i = 1; (i <= n); (i++)) {
        in.nextToken();
        (arr[i][0] = in.nval);
      }
      for (int i = 1; (i <= n); (i++)) {
        in.nextToken();
        (arr[i][1] = in.nval);
      }
      double l = 0;
      double r = 0;
      double x = {};
      for (int i = 1; (i <= n); (i++)) {
        (r += arr[i][0]);
      }
      double ans = 0;
      while (((l < r) && ((r - l) >= sml))) {
        (x = jdiv((l + r), 2));
        if (Code01_DroppingTests::check(x)) {
          (ans = x);
          (l = (x + sml));
        } else {
          (r = (x - sml));
        }
      }
      out.println(static_cast<int>((100 * (ans + 0.005))));
      in.nextToken();
      (n = static_cast<int>(in.nval));
      in.nextToken();
      (k = static_cast<int>(in.nval));
    }
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code01_DroppingTests::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 01分数规划模版题
// 给定n个数据，每个数据有(a, b)两个值，都为整数，并且都是非负的
// 请舍弃掉k个数据，希望让剩下数据做到，所有a的和 / 所有b的和，这个比值尽量大
// 如果剩下数据所有b的和为0，认为无意义
// 最后，将该比值 * 100，小数部分四舍五入的整数结果返回
// 1 <= n <= 100
// 0 <= a、b <= 10^9
// 测试链接 : https://www.luogu.com.cn/problem/P10505
// 测试链接 : http://poj.org/problem?id=2976
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // arr[i][0] = i号数据的a
        // arr[i][1] = i号数据的b
        // arr[i][2] = i号数据的结余，a - x * b
                // x固定的情况下，得到所有数据的结余
                // 结余从大到小排序
                // 最大k个结余的累加和
        // poj平台java版本较老，不支持Lambda表达式方式的比较器，需要自己定义
                        // 题目要求舍弃掉k个，其实就是挑选n-k个
*/

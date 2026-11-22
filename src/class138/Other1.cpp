// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P10505
// http://poj.org/problem?id=2976

// Source: src/class138/Other1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Other1 {
  struct MyComparator;
  struct MyComparator {
    String toString() const { return j::str(static_cast<const void *>(this)); }
    MyComparator() {}
    int compare(Array<double> o1, Array<double> o2) {
      return ((o1[2] >= o2[2]) ? (-1) : 1);
    }
  };
  inline static int MAXN = 1001;
  inline static Array<Array<double>> arr = make_array<double>(MAXN, 3);
  inline static int n = {};
  inline static int k = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Other1() {}
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
      for (int i = 1; (i <= 60); (i++)) {
        (x = jdiv((l + r), 2));
        if (Other1::check(x)) {
          (l = x);
        } else {
          (r = x);
        }
      }
      out.println(static_cast<int>((100 * (l + 0.005))));
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
  Other1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 题目1，01分数规划模版题，另一种二分的写法
// 思路是不变的，二分的写法多种多样
// 代码中打注释的位置，就是更简单的二分逻辑，其他代码没有变化
// 测试链接 : https://www.luogu.com.cn/problem/P10505
// 测试链接 : http://poj.org/problem?id=2976
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
                        // 二分进行60次，足够达到题目要求的精度
                        // 二分完成后，l就是答案
*/

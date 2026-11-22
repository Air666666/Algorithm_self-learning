// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P1908

// Source: src/class109/Code01_NumberOfReversePair1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_NumberOfReversePair1 {
  inline static int MAXN = 500001;
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static Array<int> help = make_array<int>(MAXN);
  inline static int n = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_NumberOfReversePair1() {}
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
    out.println(Code01_NumberOfReversePair1::compute());
    out.flush();
    out.close();
    br.close();
  }
  static i64 compute() { return Code01_NumberOfReversePair1::f(1, n); }
  static i64 f(int l, int r) {
    if ((l == r)) {
      return 0;
    }
    int m = jdiv((l + r), 2);
    return [&]() {
      auto jleft = [&]() {
        auto jleft = Code01_NumberOfReversePair1::f(l, m);
        auto jright = Code01_NumberOfReversePair1::f((m + 1), r);
        return (jleft + jright);
      }();
      auto jright = Code01_NumberOfReversePair1::merge(l, m, r);
      return (jleft + jright);
    }();
  }
  static i64 merge(int l, int m, int r) {
    i64 ans = 0;
    {
      int i = m;
      int j = r;
      for (; (i >= l); (i--)) {
        while (((j >= (m + 1)) && (arr[i] <= arr[j]))) {
          (j--);
        }
        (ans += (j - m));
      }
    }
    int i = l;
    int a = l;
    int b = (m + 1);
    while (((a <= m) && (b <= r))) {
      (help[(i++)] = ((arr[a] <= arr[b]) ? arr[(a++)] : arr[(b++)]));
    }
    while ((a <= m)) {
      (help[(i++)] = arr[(a++)]);
    }
    while ((b <= r)) {
      (help[(i++)] = arr[(b++)]);
    }
    for ((i = l); (i <= r); (i++)) {
      (arr[i] = help[i]);
    }
    return ans;
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code01_NumberOfReversePair1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 逆序对数量(归并分治)
// 给定一个长度为n的数组arr
// 如果 i < j 且 arr[i] > arr[j]
// 那么(i,j)就是一个逆序对
// 求arr中逆序对的数量
// 1 <= n <= 5 * 10^5
// 1 <= arr[i] <= 10^9
// 测试链接 : https://www.luogu.com.cn/problem/P1908
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下的code，提交时请把类名改成"Main"，可以直接通过
        // 归并分治
        // 1) 统计i、j来自l~r范围的情况下，逆序对数量
        // 2) 统计完成后，让arr[l...r]变成有序的
                // i来自l.....m
                // j来自m+1...r
                // 统计有多少逆序对
                // 左右部分合并，整体变有序，归并排序的过程
*/

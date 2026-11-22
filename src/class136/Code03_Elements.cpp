// Source: src/class136/Code03_Elements.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_Elements {
  inline static int MAXN = 1001;
  inline static int BIT = 60;
  inline static Array<Array<i64>> arr = make_array<i64>(MAXN, 2);
  inline static Array<i64> basis = make_array<i64>((BIT + 1));
  inline static int n = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_Elements() {}
  static i64 compute() {
    i64 ans = 0;
    j::sort(arr, 1, (n + 1), [=](Array<i64> a, Array<i64> b) {
      return ((a[1] >= b[1]) ? (-1) : 1);
    });
    for (int i = 1; (i <= n); (i++)) {
      if (Code03_Elements::insert(arr[i][0])) {
        (ans += arr[i][1]);
      }
    }
    return ans;
  }
  static bool insert(i64 num) {
    for (int i = BIT; (i >= 0); (i--)) {
      if ((jshr(num, i) == 1)) {
        if ((basis[i] == 0)) {
          (basis[i] = num);
          return true;
        }
        (num ^= basis[i]);
      }
    }
    return false;
  }
  static void java_main(Array<String> args) {
    IO io = IO();
    (n = io.nextInt());
    for (int i = 1; (i <= n); (i++)) {
      (arr[i][0] = io.nextLong());
      (arr[i][1] = io.nextInt());
    }
    io.println(Code03_Elements::compute());
    io.flush();
    io.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code03_Elements::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 元素
// 给定n个魔法矿石，每个矿石有状态和魔力，都是整数
// 若干矿石组成的组合能否有效，根据状态异或的结果来决定
// 如果一个矿石组合内部会产生异或和为0的子集，那么这个组合无效
// 返回有效的矿石组合中，最大的魔力和是多少
// 1 <= n <= 1000
// 1 <= 状态 <= 10^18
// 1 <= 魔力 <= 10^4
// 测试链接 : https://www.luogu.com.cn/problem/P4570
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 普通消元
        // 计算得到最大线性基的最少花费
        // 线性基里插入num，如果线性基增加了返回true，否则返回false
                // 题目会读取10^18范围内的long类型数字
                // 用StreamTokenizer可能无法正确读取，因为先变成double再转成long
                // 这里用Kattio类，具体看讲解019的代码中，Code05_Kattio文件
                // 有详细的说明
        // Kattio类IO效率很好，但还是不如StreamTokenizer
        // 只有StreamTokenizer无法正确处理时，才考虑使用这个类
        // 参考链接 : https://oi-wiki.org/lang/java-pro/
*/

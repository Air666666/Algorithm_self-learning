// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P3857
// https://oi-wiki.org/lang/java-pro/

// Source: src/class136/Code04_Lanterns.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_Lanterns {
  inline static int MAXN = 51;
  inline static int MOD = 2008;
  inline static Array<i64> arr = make_array<i64>(MAXN);
  inline static Array<i64> basis = make_array<i64>(MAXN);
  inline static int n = {};
  inline static int m = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_Lanterns() {}
  static int compute() {
    int size = 0;
    for (int i = 1; (i <= m); (i++)) {
      if (Code04_Lanterns::insert(arr[i])) {
        (size++);
      }
    }
    return size;
  }
  static bool insert(i64 num) {
    for (int i = n; (i >= 0); (i--)) {
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
    (n = (io.nextInt() - 1));
    (m = io.nextInt());
    Array<jchar> s = {};
    for (int i = 1; (i <= m); (i++)) {
      (s = io.next().toCharArray());
      i64 num = 0;
      for (int j = 0; (j <= n); (j++)) {
        if ((s[j] == u'O')) {
          (num |= jshl(1LL, j));
        }
      }
      (arr[i] = num);
    }
    int size = Code04_Lanterns::compute();
    io.println(jrem(jshl(1LL, size), MOD));
    io.flush();
    io.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code04_Lanterns::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 彩灯
// 一共有n个灯泡，开始都是不亮的状态，有m个开关
// 每个开关能改变若干灯泡的状态，改变是指，亮变不亮、不亮变亮
// 比如n=5，某个开关为XXOOO，表示这个开关只能改变后3个灯泡的状态
// 可以随意使用开关，返回有多少种亮灯的组合，全不亮也算一种组合
// 答案可能很大，对 2008 取模
// 1 <= n <= 50
// 1 <= m <= 50
// 测试链接 : https://www.luogu.com.cn/problem/P3857
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 普通消元
        // 计算线性基的大小
        // 线性基里插入num，如果线性基增加了返回true，否则返回false
        // Kattio类IO效率很好，但还是不如StreamTokenizer
        // 只有StreamTokenizer无法正确处理时，才考虑使用这个类
        // 参考链接 : https://oi-wiki.org/lang/java-pro/
*/

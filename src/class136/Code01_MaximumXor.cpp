// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P3812

// Source: src/class136/Code01_MaximumXor.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_MaximumXor {
  inline static int MAXN = 51;
  inline static int BIT = 50;
  inline static Array<i64> arr = make_array<i64>(MAXN);
  inline static Array<i64> basis = make_array<i64>((BIT + 1));
  inline static int n = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_MaximumXor() {}
  static i64 compute() {
    for (int i = 1; (i <= n); (i++)) {
      Code01_MaximumXor::insert(arr[i]);
    }
    i64 ans = 0;
    for (int i = BIT; (i >= 0); (i--)) {
      (ans = jmax(ans, (ans ^ basis[i])));
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
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    (n = static_cast<int>(in.nval));
    for (int i = 1; (i <= n); (i++)) {
      in.nextToken();
      (arr[i] = static_cast<i64>(in.nval));
    }
    Code01_MaximumXor::compute();
    out.println(Code01_MaximumXor::compute());
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code01_MaximumXor::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 最大异或和
// 给定一个长度为n的数组arr，arr中都是long类型的非负数，可能有重复值
// 在这些数中选取任意个，使得异或和最大，返回最大的异或和
// 1 <= n <= 50
// 0 <= arr[i] <= 2^50
// 测试链接 : https://www.luogu.com.cn/problem/P3812
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 普通消元
        // 计算最大异或和
        // 线性基里插入num，如果线性基增加了返回true，否则返回false
*/

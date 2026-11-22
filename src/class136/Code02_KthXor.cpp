// 原题测试 / 参考链接（保留上游原始地址）
// https://loj.ac/p/114

// Source: src/class136/Code02_KthXor.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_KthXor {
  inline static int MAXN = 100001;
  inline static int BIT = 50;
  inline static Array<i64> arr = make_array<i64>(MAXN);
  inline static int len = {};
  inline static bool zero = {};
  inline static int n = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_KthXor() {}
  static void compute() {
    (len = 1);
    for (i64 i = BIT; (i >= 0); (i--)) {
      for (int j = len; (j <= n); (j++)) {
        if (((arr[j] & jshl(1LL, i)) != 0)) {
          Code02_KthXor::swap(j, len);
          break;
        }
      }
      if (((arr[len] & jshl(1LL, i)) != 0)) {
        for (int j = 1; (j <= n); (j++)) {
          if (((j != len) && ((arr[j] & jshl(1LL, i)) != 0))) {
            (arr[j] ^= arr[len]);
          }
        }
        (len++);
      }
    }
    (len--);
    (zero = (len != n));
  }
  static void swap(int a, int b) {
    i64 tmp = arr[a];
    (arr[a] = arr[b]);
    (arr[b] = tmp);
  }
  static i64 query(i64 k) {
    if ((zero && (k == 1))) {
      return 0;
    }
    if (zero) {
      (k--);
    }
    if ((k >= jshl(1LL, len))) {
      return (-1);
    }
    i64 ans = 0;
    {
      int i = len;
      int j = 0;
      for (; (i >= 1); (i--), (j++)) {
        if (((k & jshl(1LL, j)) != 0)) {
          (ans ^= arr[i]);
        }
      }
    }
    return ans;
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
    Code02_KthXor::compute();
    in.nextToken();
    int q = static_cast<int>(in.nval);
    for (int i = 1; (i <= q); (i++)) {
      in.nextToken();
      i64 k = static_cast<i64>(in.nval);
      out.println(Code02_KthXor::query(k));
    }
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code02_KthXor::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 第k小的异或和
// 给定一个长度为n的数组arr，arr中都是long类型的非负数，可能有重复值
// 在这些数中选取任意个，至少要选一个数字
// 可以得到很多异或和，假设异或和的结果去重
// 返回第k小的异或和
// 1 <= n <= 10^5
// 0 <= arr[i] <= 2^50
// 1 <= k <= 2^50
// 测试链接 : https://loj.ac/p/114
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 高斯消元
        // 返回第k小的异或和
*/

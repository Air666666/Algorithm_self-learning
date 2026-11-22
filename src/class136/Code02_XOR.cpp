// Source: src/class136/Code02_XOR.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_XOR {
  inline static int MAXN = 100001;
  inline static int BIT = 60;
  inline static Array<i64> arr = make_array<i64>(MAXN);
  inline static int len = {};
  inline static bool zero = {};
  inline static int t = {};
  inline static int n = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_XOR() {}
  static void compute() {
    (len = 1);
    for (i64 i = BIT; (i >= 0); (i--)) {
      for (int j = len; (j <= n); (j++)) {
        if (((arr[j] & jshl(1LL, i)) != 0)) {
          Code02_XOR::swap(j, len);
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
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (t = in.nextInt());
    for (int c = 1; (c <= t); (c++)) {
      (n = in.nextInt());
      for (int i = 1; (i <= n); (i++)) {
        (arr[i] = in.nextLong());
      }
      (arr[(n + 1)] = 0);
      Code02_XOR::compute();
      out.println(((String(u"Case #") + c) + String(u":")));
      int q = in.nextInt();
      for (int i = 1; (i <= q); (i++)) {
        i64 k = in.nextLong();
        out.println(Code02_XOR::query(k));
      }
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code02_XOR::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 第k小的异或和，HDU的题目
// 这道题课上没有讲，核心逻辑和题目2一样，只是数据范围稍有不同
// 注意如下代码中，有注释的部分即可，其他代码都一样
// 给定一个长度为n的数组arr，arr中都是long类型的非负数，可能有重复值
// 在这些数中选取任意个，至少要选一个数字，可以得到很多异或和
// 假设异或和的结果去重，返回第k小的异或和
// 测试链接 : https://acm.hdu.edu.cn/showproblem.php?pid=3949
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 数字最大为10^18，需要更高的二进制位
                // 注意有多组测试
                        // 确保arr[n + 1]是0
        // 读写工具类
*/

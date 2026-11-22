// Source: src/class134/Code01_GaussEor.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_GaussEor {
  inline static int MOD = 1000000007;
  inline static int MAXV = 2000;
  inline static int MAXN = 305;
  inline static Array<i64> arr = make_array<i64>(MAXN);
  inline static Array<Array<int>> mat = make_array<int>(MAXN, MAXN);
  inline static Array<int> prime = make_array<int>((MAXV + 1));
  inline static int cnt = {};
  inline static Array<bool> visit = make_array<bool>((MAXV + 1));
  inline static Array<int> pow2 = make_array<int>(MAXN);
  inline static int n = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_GaussEor() {}
  static void prepare() {
    for (int i = 2; ((i * i) <= MAXV); (i++)) {
      if ((!visit[i])) {
        for (int j = (i * i); (j <= MAXV); (j += i)) {
          (visit[j] = true);
        }
      }
    }
    (cnt = 0);
    for (int i = 2; (i <= MAXV); (i++)) {
      if ((!visit[i])) {
        (prime[(++cnt)] = i);
      }
    }
    (pow2[0] = 1);
    for (int i = 1; (i < MAXN); (i++)) {
      (pow2[i] = jrem((pow2[(i - 1)] * 2), MOD));
    }
  }
  static void java_main(Array<String> args) {
    Code01_GaussEor::prepare();
    IO io = IO();
    int test = io.nextInt();
    for (int t = 1; (t <= test); (t++)) {
      (n = io.nextInt());
      for (int i = 1; (i <= n); (i++)) {
        (arr[i] = io.nextLong());
      }
      io.println(((String(u"Case #") + t) + String(u":")));
      io.println(Code01_GaussEor::compute());
    }
    io.flush();
    io.close();
  }
  static int compute() {
    for (int i = 1; (i <= cnt); (i++)) {
      for (int j = 1; (j <= (cnt + 1)); (j++)) {
        (mat[i][j] = 0);
      }
    }
    i64 cur = {};
    for (int i = 1; (i <= n); (i++)) {
      (cur = arr[i]);
      for (int j = 1; ((j <= cnt) && (cur != 0)); (j++)) {
        while ((jrem(cur, prime[j]) == 0)) {
          (mat[j][i] ^= 1);
          (cur /= prime[j]);
        }
      }
    }
    Code01_GaussEor::gauss(cnt);
    int main = 0;
    for (int i = 1; (i <= cnt); (i++)) {
      if ((mat[i][i] == 1)) {
        (main++);
      }
    }
    return (pow2[(n - main)] - 1);
  }
  static void gauss(int n) {
    for (int i = 1; (i <= n); (i++)) {
      for (int j = 1; (j <= n); (j++)) {
        if (((j < i) && (mat[j][j] == 1))) {
          continue;
        }
        if ((mat[j][i] == 1)) {
          Code01_GaussEor::swap(i, j);
          break;
        }
      }
      if ((mat[i][i] == 1)) {
        for (int j = 1; (j <= n); (j++)) {
          if (((i != j) && (mat[j][i] == 1))) {
            for (int k = i; (k <= (n + 1)); (k++)) {
              (mat[j][k] ^= mat[i][k]);
            }
          }
        }
      }
    }
  }
  static void swap(int a, int b) {
    Array<int> tmp = mat[a];
    (mat[a] = mat[b]);
    (mat[b] = tmp);
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code01_GaussEor::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 高斯消元解决异或方程组模版题
// 有一个长度为n的数组arr，可能有重复值，数字都是long类型的正数
// 每个数拥有的质数因子一定不超过2000，每个数最多挑选一次
// 在至少要选一个数的情况下，你可以随意挑选数字乘起来
// 乘得的结果需要是完全平方数，请问有几种挑选数字的方法
// 方法数可能很大，答案对 1000000007 取模
// 1 <= n <= 300
// 1 <= arr[i] <= 10^18
// 测试链接 : https://acm.hdu.edu.cn/showproblem.php?pid=5833
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 收集2000以内的质数，一共就303个，这是大于arr的个数的
        // 2000以内质数的个数，一共就303个，这是大于arr的个数的
        // 埃氏筛需要
        // pow2[i] : 2的i次方 % MOD
                // 得到2000以内的质数
                // 如果不会就去看，讲解097，埃氏筛
                // 当然也可以用欧拉筛，也在讲解097
                // 2的i次方%MOD的结果
                // 题目会读取10^18范围内的long类型数字
                // 用StreamTokenizer可能无法正确读取，因为先变成double再转成long
                // 这里用Kattio类，具体看讲解019的代码中，Code05_Kattio文件
                // 有详细的说明
                // 影响每个主元的自由元们一旦确定
                // 那么该主元选和不选也就唯一确定了
                // 所以重点是自由元如何决策，n - main就是自由元的数量
                // 自由元之间一定相互独立，每个自由元都可以做出选和不选的决定
                // 所以一共是2的(n - main)次方种决策
                // 但是想象一下，如果所有自由元都不选，
                // mat值的部分(cnt+1列)全是0啊！那么意味着，所有主元也都不选
                // 但是题目要求至少要选一个数，所以不能出现自由元都不选的情况
                // 所以返回方法数-1
                // 能够分析的前提是对主元和自由元之间的关系有清晰的认识
        // 高斯消元解决异或方程组模版
        // Kattio类IO效率很好，但还是不如StreamTokenizer
        // 只有StreamTokenizer无法正确处理时，才考虑使用这个类
        // 参考链接 : https://oi-wiki.org/lang/java-pro/
*/

// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P5309

// Source: src/class175/Code04_Initialization1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_Initialization1 {
  inline static int MAXN = 200001;
  inline static int MAXB = 501;
  inline static int MOD = 1000000007;
  inline static int n = {};
  inline static int m = {};
  inline static Array<Array<i64>> pre = make_array<i64>(MAXB, MAXB);
  inline static Array<Array<i64>> suf = make_array<i64>(MAXB, MAXB);
  inline static Array<i64> arr = make_array<i64>(MAXN);
  inline static Array<i64> sum = make_array<i64>(MAXB);
  inline static int blen = {};
  inline static int bnum = {};
  inline static Array<int> bi = make_array<int>(MAXN);
  inline static Array<int> bl = make_array<int>(MAXB);
  inline static Array<int> br = make_array<int>(MAXB);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_Initialization1() {}
  static void add(int x, int y, int z) {
    if ((x <= blen)) {
      for (int i = y; (i <= x); (i++)) {
        (pre[x][i] += z);
      }
      for (int i = y; (i >= 1); (i--)) {
        (suf[x][i] += z);
      }
    } else {
      for (int i = y; (i <= n); (i += x)) {
        (arr[i] += z);
        (sum[bi[i]] += z);
      }
    }
  }
  static i64 querySum(int l, int r) {
    int lb = bi[l];
    int rb = bi[r];
    i64 ans = 0;
    if ((lb == rb)) {
      for (int i = l; (i <= r); (i++)) {
        (ans += arr[i]);
      }
    } else {
      for (int i = l; (i <= br[lb]); (i++)) {
        (ans += arr[i]);
      }
      for (int i = bl[rb]; (i <= r); (i++)) {
        (ans += arr[i]);
      }
      for (int b = (lb + 1); (b <= (rb - 1)); (b++)) {
        (ans += sum[b]);
      }
    }
    return ans;
  }
  static i64 query(int l, int r) {
    i64 ans = Code04_Initialization1::querySum(l, r);
    {
      int x = 1;
      int lth = {};
      int rth = {};
      int num = {};
      for (; (x <= blen); (x++)) {
        (lth = (jdiv((l - 1), x) + 1));
        (rth = (jdiv((r - 1), x) + 1));
        (num = ((rth - lth) - 1));
        if ((lth == rth)) {
          (ans = ((ans + pre[x][(jrem((r - 1), x) + 1)]) -
                  pre[x][jrem((l - 1), x)]));
        } else {
          (ans = (((ans + suf[x][(jrem((l - 1), x) + 1)]) +
                   (jrem(pre[x][x], MOD) * num)) +
                  pre[x][(jrem((r - 1), x) + 1)]));
        }
      }
    }
    return jrem(ans, MOD);
  }
  static void prepare() {
    (blen = static_cast<int>(std::sqrt(n)));
    (bnum = jdiv(((n + blen) - 1), blen));
    for (int i = 1; (i <= n); (i++)) {
      (bi[i] = (jdiv((i - 1), blen) + 1));
    }
    for (int b = 1; (b <= bnum); (b++)) {
      (bl[b] = (((b - 1) * blen) + 1));
      (br[b] = jmin((b * blen), n));
      for (int i = bl[b]; (i <= br[b]); (i++)) {
        (sum[b] += arr[i]);
      }
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (m = in.nextInt());
    for (int i = 1; (i <= n); (i++)) {
      (arr[i] = in.nextInt());
    }
    Code04_Initialization1::prepare();
    {
      int i = 1;
      int op = {};
      int x = {};
      int y = {};
      int z = {};
      for (; (i <= m); (i++)) {
        (op = in.nextInt());
        (x = in.nextInt());
        (y = in.nextInt());
        if ((op == 1)) {
          (z = in.nextInt());
          Code04_Initialization1::add(x, y, z);
        } else {
          out.println(Code04_Initialization1::query(x, y));
        }
      }
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code04_Initialization1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 初始化，java版
// 给定一个长度为n的数组arr，接下来有m条操作，操作格式如下
// 操作 1 x y z : 从arr[y]开始，下标每次+x，所有相应位置的数都+z，题目保证 y <=
x
// 操作 2 x y   : 打印arr[x..y]的累加和，答案对1000000007取余
// 1 <= n、m <= 2 * 10^5
// 测试链接 : https://www.luogu.com.cn/problem/P5309
// 提交以下的code，提交时请把类名改成"Main"
// java实现的逻辑一定是正确的，但是本题卡常，无法通过所有测试用例
// 想通过用C++实现，本节课Code04_Initialization2文件就是C++的实现
// 两个版本的逻辑完全一样，C++版本可以通过所有测试
        // 读写工具类
*/

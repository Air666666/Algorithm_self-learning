// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P4135

// Source: src/class172/Code05_Poem1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code05_Poem1 {
  inline static int MAXN = 100001;
  inline static int MAXB = 401;
  inline static int n = {};
  inline static int c = {};
  inline static int m = {};
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static int blen = {};
  inline static int bnum = {};
  inline static Array<int> bi = make_array<int>(MAXN);
  inline static Array<int> bl = make_array<int>(MAXB);
  inline static Array<int> br = make_array<int>(MAXB);
  inline static Array<Array<int>> freq = make_array<int>(MAXB, MAXN);
  inline static Array<Array<int>> even = make_array<int>(MAXB, MAXB);
  inline static Array<int> numCnt = make_array<int>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code05_Poem1() {}
  static int getCnt(int l, int r, int v) {
    return (freq[r][v] - freq[(l - 1)][v]);
  }
  static int delta(int pre) {
    if ((pre == 0)) {
      return 0;
    }
    if (((pre & 1) == 0)) {
      return (-1);
    }
    return 1;
  }
  static void prepare() {
    (blen = static_cast<int>(std::sqrt(n)));
    (bnum = jdiv(((n + blen) - 1), blen));
    for (int i = 1; (i <= n); (i++)) {
      (bi[i] = (jdiv((i - 1), blen) + 1));
    }
    for (int i = 1; (i <= bnum); (i++)) {
      (bl[i] = (((i - 1) * blen) + 1));
      (br[i] = jmin((i * blen), n));
    }
    for (int i = 1; (i <= bnum); (i++)) {
      for (int j = bl[i]; (j <= br[i]); (j++)) {
        (freq[i][arr[j]]++);
      }
      for (int j = 1; (j <= c); (j++)) {
        (freq[i][j] += freq[(i - 1)][j]);
      }
    }
    for (int i = 1; (i <= bnum); (i++)) {
      for (int j = i; (j <= bnum); (j++)) {
        (even[i][j] = even[i][(j - 1)]);
        for (int k = bl[j]; (k <= br[j]); (k++)) {
          (even[i][j] += Code05_Poem1::delta(numCnt[arr[k]]));
          (numCnt[arr[k]]++);
        }
      }
      for (int j = 1; (j <= c); (j++)) {
        (numCnt[j] = 0);
      }
    }
  }
  static int query(int l, int r) {
    int ans = 0;
    if ((bi[l] == bi[r])) {
      for (int i = l; (i <= r); (i++)) {
        (ans += Code05_Poem1::delta(numCnt[arr[i]]));
        (numCnt[arr[i]]++);
      }
      for (int i = l; (i <= r); (i++)) {
        (numCnt[arr[i]] = 0);
      }
    } else {
      (ans = even[(bi[l] + 1)][(bi[r] - 1)]);
      for (int i = l; (i <= br[bi[l]]); (i++)) {
        (ans += Code05_Poem1::delta(
             (Code05_Poem1::getCnt((bi[l] + 1), (bi[r] - 1), arr[i]) +
              numCnt[arr[i]])));
        (numCnt[arr[i]]++);
      }
      for (int i = bl[bi[r]]; (i <= r); (i++)) {
        (ans += Code05_Poem1::delta(
             (Code05_Poem1::getCnt((bi[l] + 1), (bi[r] - 1), arr[i]) +
              numCnt[arr[i]])));
        (numCnt[arr[i]]++);
      }
      for (int i = l; (i <= br[bi[l]]); (i++)) {
        (numCnt[arr[i]] = 0);
      }
      for (int i = bl[bi[r]]; (i <= r); (i++)) {
        (numCnt[arr[i]] = 0);
      }
    }
    return ans;
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (c = in.nextInt());
    (m = in.nextInt());
    for (int i = 1; (i <= n); (i++)) {
      (arr[i] = in.nextInt());
    }
    Code05_Poem1::prepare();
    {
      int i = 1;
      int a = {};
      int b = {};
      int l = {};
      int r = {};
      int lastAns = 0;
      for (; (i <= m); (i++)) {
        (a = (jrem((in.nextInt() + lastAns), n) + 1));
        (b = (jrem((in.nextInt() + lastAns), n) + 1));
        (l = jmin(a, b));
        (r = jmax(a, b));
        (lastAns = Code05_Poem1::query(l, r));
        out.println(lastAns);
      }
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code05_Poem1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 作诗，java版
// 给定一个长度为n的数组arr，接下来有m条操作，每条操作格式如下
// 操作 l r : 打印arr[l..r]范围上，有多少个数出现正偶数次
// 1 <= 所有数值 <= 10^5
// 题目要求强制在线，具体规则可以打开测试链接查看
// 测试链接 : https://www.luogu.com.cn/problem/P4135
// 提交交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // freq[i][j]表示前i块中j出现的次数
        // even[i][j]表示从第i块到第j块，有多少个数出现正偶数次
        // 数字词频统计
        // 返回从l块到r块，数字v的次数
        // 某种数的之前词频是pre，现在如果词频加1
        // 返回 出现正偶数次的数字个数 的变化量
        // 读写工具类
*/

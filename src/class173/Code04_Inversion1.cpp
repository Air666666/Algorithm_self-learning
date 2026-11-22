// Source: src/class173/Code04_Inversion1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_Inversion1 {
  inline static int MAXN = 100001;
  inline static int MAXB = 701;
  inline static int n = {};
  inline static int m = {};
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static Array<Array<int>> sortv = make_array<int>(MAXN, 2);
  inline static int blen = {};
  inline static int bnum = {};
  inline static Array<int> bi = make_array<int>(MAXN);
  inline static Array<int> bl = make_array<int>(MAXB);
  inline static Array<int> br = make_array<int>(MAXB);
  inline static Array<int> tree = make_array<int>(MAXN);
  inline static Array<int> pre = make_array<int>(MAXN);
  inline static Array<int> suf = make_array<int>(MAXN);
  inline static Array<Array<int>> cnt = make_array<int>(MAXB, MAXN);
  inline static Array<Array<i64>> dp = make_array<i64>(MAXB, MAXB);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_Inversion1() {}
  static int lowbit(int i) { return (i & (-i)); }
  static void add(int i, int v) {
    while ((i <= n)) {
      (tree[i] += v);
      (i += Code04_Inversion1::lowbit(i));
    }
  }
  static int sum(int i) {
    int ret = 0;
    while ((i > 0)) {
      (ret += tree[i]);
      (i -= Code04_Inversion1::lowbit(i));
    }
    return ret;
  }
  static int f(int x, int xl, int xr, int y, int yl, int yr) {
    int ans = 0;
    {
      int p1 = bl[x];
      int p2 = (bl[y] - 1);
      int cnt = 0;
      for (; (p1 <= br[x]); (p1++)) {
        if (((xl <= sortv[p1][1]) && (sortv[p1][1] <= xr))) {
          while ((((p2 + 1) <= br[y]) && (sortv[p1][0] > sortv[(p2 + 1)][0]))) {
            (p2++);
            if (((yl <= sortv[p2][1]) && (sortv[p2][1] <= yr))) {
              (cnt++);
            }
          }
          (ans += cnt);
        }
      }
    }
    return ans;
  }
  static i64 query(int l, int r) {
    i64 ans = 0;
    int lb = bi[l];
    int rb = bi[r];
    if ((lb == rb)) {
      if ((l == bl[lb])) {
        (ans = pre[r]);
      } else {
        (ans = ((pre[r] - pre[(l - 1)]) -
                Code04_Inversion1::f(lb, bl[lb], (l - 1), lb, l, r)));
      }
    } else {
      (ans = ((suf[l] + pre[r]) +
              Code04_Inversion1::f(lb, l, br[lb], rb, bl[rb], r)));
      for (int i = l; (i <= br[lb]); (i++)) {
        (ans += (cnt[(rb - 1)][arr[i]] - cnt[lb][arr[i]]));
      }
      for (int i = bl[rb]; (i <= r); (i++)) {
        (ans += (((br[(rb - 1)] - bl[(lb + 1)]) + 1) -
                 (cnt[(rb - 1)][arr[i]] - cnt[lb][arr[i]])));
      }
      (ans += dp[(lb + 1)][(rb - 1)]);
    }
    return ans;
  }
  static void prepare() {
    (blen = static_cast<int>(std::sqrt(jdiv(n, 4))));
    (bnum = jdiv(((n + blen) - 1), blen));
    for (int i = 1; (i <= n); (i++)) {
      (bi[i] = (jdiv((i - 1), blen) + 1));
    }
    for (int i = 1; (i <= bnum); (i++)) {
      (bl[i] = (((i - 1) * blen) + 1));
      (br[i] = jmin((i * blen), n));
    }
    for (int i = 1; (i <= n); (i++)) {
      (sortv[i][0] = arr[i]);
      (sortv[i][1] = i);
    }
    for (int i = 1; (i <= bnum); (i++)) {
      j::sort(sortv, bl[i], (br[i] + 1), [=](Array<int> a, Array<int> b) {
        return ((a[0] != b[0]) ? (a[0] - b[0]) : (a[1] - b[1]));
      });
    }
    for (int i = 1; (i <= bnum); (i++)) {
      for (int j = bl[i]; (j <= br[i]); (j++)) {
        (cnt[i][arr[j]]++);
        if ((j != bl[i])) {
          (pre[j] = [&]() {
            auto jleft = (pre[(j - 1)] + Code04_Inversion1::sum(n));
            auto jright = Code04_Inversion1::sum(arr[j]);
            return (jleft - jright);
          }());
        }
        Code04_Inversion1::add(arr[j], 1);
      }
      for (int j = bl[i]; (j <= br[i]); (j++)) {
        Code04_Inversion1::add(arr[j], (-1));
      }
      for (int j = br[i]; (j >= bl[i]); (j--)) {
        if ((j != br[i])) {
          (suf[j] = (suf[(j + 1)] + Code04_Inversion1::sum(arr[j])));
        }
        Code04_Inversion1::add(arr[j], 1);
      }
      for (int j = bl[i]; (j <= br[i]); (j++)) {
        Code04_Inversion1::add(arr[j], (-1));
      }
      int tmp = 0;
      for (int j = 1; (j <= n); (j++)) {
        (tmp += cnt[i][j]);
        (cnt[i][j] = (tmp + cnt[(i - 1)][j]));
      }
    }
    for (int l = bnum; (l >= 1); (l--)) {
      (dp[l][l] = pre[br[l]]);
      for (int r = (l + 1); (r <= bnum); (r++)) {
        (dp[l][r] =
             (((dp[(l + 1)][r] + dp[l][(r - 1)]) - dp[(l + 1)][(r - 1)]) +
              Code04_Inversion1::f(l, bl[l], br[l], r, bl[r], br[r])));
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
    Code04_Inversion1::prepare();
    i64 lastAns = 0;
    {
      int i = 1;
      int l = {};
      int r = {};
      for (; (i <= m); (i++)) {
        (l = in.nextInt());
        (r = in.nextInt());
        (l = static_cast<int>((lastAns ^ l)));
        (r = static_cast<int>((lastAns ^ r)));
        (lastAns = Code04_Inversion1::query(l, r));
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
  Code04_Inversion1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 区间逆序对，java版
// 给定一个长度为n的排列，接下来有m条操作，每条操作格式如下
// 操作 l r : 打印arr[l..r]范围上的逆序对数量
// 1 <= n、m <= 10^5
// 题目要求强制在线，具体规则可以打开测试链接查看
// 测试链接 : https://www.luogu.com.cn/problem/P5046
// 提交以下的code，提交时请把类名改成"Main"
// java实现的逻辑一定是正确的，但是无法通过测试
// 因为这道题只考虑C++能通过的时间标准，根本没考虑java的用户
// 想通过用C++实现，本节课Code04_Inversion2文件就是C++的实现
// 两个版本的逻辑完全一样，C++版本可以通过所有测试
        // (数值、位置)
        // 树状数组，为了快速生成pre数组和suf数组
        // pre[i] : 从所在块最左位置到i位置，有多少逆序对
        // suf[i] : 从i位置到所在块最右位置，有多少逆序对
        // cnt[i][j] : 前i块里<=j的数字个数
        // dp[i][j] : 从第i块到第j块有多少逆序对
        // 更靠左的第x块，从xl到xr范围上，选第一个数
        // 更靠右的第y块，从yl到yr范围上，选第二个数
        // x和y可以相等，但是xl..xr需要在yl..yr的左侧
        // 返回逆序对数量
                        // 左散块[l..]内部逆序对 + 右散块[..r]内部逆序对 +
左散块 结合 右散块 的逆序对
                        // 左散块中的arr[i]，作为第一个数
                        // 中间整块中的某个数字，作为第二个数
                        // 计算这样的逆序对数量
                        // 注意因为题目给定的是排列！所以如下这么写没问题
                        // 中间整块中的某个数字，作为第一个数
                        // 右散块中的arr[i]，作为第二个数
                        // 计算这样的逆序对数量
                        // 中间整块的逆序对
        // 注意调整块长
        // 读写工具类
*/

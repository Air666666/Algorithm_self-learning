// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P5356

// Source: src/class173/Code01_Poker1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_Poker1 {
  inline static int MAXN = 100001;
  inline static int MAXB = 1001;
  inline static int n = {};
  inline static int m = {};
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static Array<int> sortv = make_array<int>(MAXN);
  inline static int blen = {};
  inline static int bnum = {};
  inline static Array<int> bi = make_array<int>(MAXN);
  inline static Array<int> bl = make_array<int>(MAXB);
  inline static Array<int> br = make_array<int>(MAXB);
  inline static Array<int> lazy = make_array<int>(MAXB);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_Poker1() {}
  static void innerAdd(int l, int r, int v) {
    for (int i = l; (i <= r); (i++)) {
      (arr[i] += v);
    }
    for (int i = bl[bi[l]]; (i <= br[bi[l]]); (i++)) {
      (sortv[i] = arr[i]);
    }
    j::sort(sortv, bl[bi[l]], (br[bi[l]] + 1));
  }
  static void add(int l, int r, int v) {
    if ((bi[l] == bi[r])) {
      Code01_Poker1::innerAdd(l, r, v);
    } else {
      Code01_Poker1::innerAdd(l, br[bi[l]], v);
      Code01_Poker1::innerAdd(bl[bi[r]], r, v);
      for (int i = (bi[l] + 1); (i <= (bi[r] - 1)); (i++)) {
        (lazy[i] += v);
      }
    }
  }
  static int getMin(int l, int r) {
    int lb = bi[l];
    int rb = bi[r];
    int ans = 10000000;
    if ((lb == rb)) {
      for (int i = l; (i <= r); (i++)) {
        (ans = jmin(ans, (arr[i] + lazy[lb])));
      }
    } else {
      for (int i = l; (i <= br[lb]); (i++)) {
        (ans = jmin(ans, (arr[i] + lazy[lb])));
      }
      for (int i = bl[rb]; (i <= r); (i++)) {
        (ans = jmin(ans, (arr[i] + lazy[rb])));
      }
      for (int i = (lb + 1); (i <= (rb - 1)); (i++)) {
        (ans = jmin(ans, (sortv[bl[i]] + lazy[i])));
      }
    }
    return ans;
  }
  static int getMax(int l, int r) {
    int lb = bi[l];
    int rb = bi[r];
    int ans = (-10000000);
    if ((lb == rb)) {
      for (int i = l; (i <= r); (i++)) {
        (ans = jmax(ans, (arr[i] + lazy[lb])));
      }
    } else {
      for (int i = l; (i <= br[lb]); (i++)) {
        (ans = jmax(ans, (arr[i] + lazy[lb])));
      }
      for (int i = bl[rb]; (i <= r); (i++)) {
        (ans = jmax(ans, (arr[i] + lazy[rb])));
      }
      for (int i = (lb + 1); (i <= (rb - 1)); (i++)) {
        (ans = jmax(ans, (sortv[br[i]] + lazy[i])));
      }
    }
    return ans;
  }
  static int blockCnt(int i, int v) {
    (v -= lazy[i]);
    int l = bl[i];
    int r = br[i];
    if ((sortv[l] > v)) {
      return 0;
    }
    if ((sortv[r] <= v)) {
      return ((r - l) + 1);
    }
    int m = {};
    int find = l;
    while ((l <= r)) {
      (m = jdiv((l + r), 2));
      if ((sortv[m] <= v)) {
        (find = m);
        (l = (m + 1));
      } else {
        (r = (m - 1));
      }
    }
    return ((find - bl[i]) + 1);
  }
  static int getCnt(int l, int r, int v) {
    int lb = bi[l];
    int rb = bi[r];
    int ans = 0;
    if ((lb == rb)) {
      for (int i = l; (i <= r); (i++)) {
        if (((arr[i] + lazy[lb]) <= v)) {
          (ans++);
        }
      }
    } else {
      for (int i = l; (i <= br[lb]); (i++)) {
        if (((arr[i] + lazy[lb]) <= v)) {
          (ans++);
        }
      }
      for (int i = bl[rb]; (i <= r); (i++)) {
        if (((arr[i] + lazy[rb]) <= v)) {
          (ans++);
        }
      }
      for (int i = (lb + 1); (i <= (rb - 1)); (i++)) {
        (ans += Code01_Poker1::blockCnt(i, v));
      }
    }
    return ans;
  }
  static int query(int l, int r, int k) {
    if (((k < 1) || (k > ((r - l) + 1)))) {
      return (-1);
    }
    int minv = Code01_Poker1::getMin(l, r);
    int maxv = Code01_Poker1::getMax(l, r);
    int midv = {};
    int ans = (-1);
    while ((minv <= maxv)) {
      (midv = (minv + jdiv((maxv - minv), 2)));
      if ((Code01_Poker1::getCnt(l, r, midv) >= k)) {
        (ans = midv);
        (maxv = (midv - 1));
      } else {
        (minv = (midv + 1));
      }
    }
    return ans;
  }
  static void prepare() {
    (blen = static_cast<int>(std::sqrt(jdiv(n, 2))));
    (bnum = jdiv(((n + blen) - 1), blen));
    for (int i = 1; (i <= n); (i++)) {
      (bi[i] = (jdiv((i - 1), blen) + 1));
    }
    for (int i = 1; (i <= bnum); (i++)) {
      (bl[i] = (((i - 1) * blen) + 1));
      (br[i] = jmin((i * blen), n));
    }
    for (int i = 1; (i <= n); (i++)) {
      (sortv[i] = arr[i]);
    }
    for (int i = 1; (i <= bnum); (i++)) {
      j::sort(sortv, bl[i], (br[i] + 1));
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
    Code01_Poker1::prepare();
    {
      int i = 1;
      int op = {};
      int l = {};
      int r = {};
      int v = {};
      for (; (i <= m); (i++)) {
        (op = in.nextInt());
        (l = in.nextInt());
        (r = in.nextInt());
        (v = in.nextInt());
        if ((op == 1)) {
          out.println(Code01_Poker1::query(l, r, v));
        } else {
          Code01_Poker1::add(l, r, v);
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
  Code01_Poker1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 由乃打扑克，java版
// 给定一个长度为n的数组arr，接下来有m条操作，操作类型如下
// 操作 1 l r v : 查询arr[l..r]范围上，第v小的数
// 操作 2 l r v : arr[l..r]范围上每个数加v，v可能是负数
// 1 <= n、m <= 10^5
// -2 * 10^4 <= 数组中的值 <= +2 * 10^4
// 测试链接 : https://www.luogu.com.cn/problem/P5356
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 返回第i块内<= v的数字个数
        // 返回arr[l..r]范围上<= v的数字个数
        // 注意调整块长
        // 读写工具类
*/

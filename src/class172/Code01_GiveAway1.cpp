// Source: src/class172/Code01_GiveAway1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_GiveAway1 {
  inline static int MAXN = 500001;
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
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_GiveAway1() {}
  static void build() {
    (blen = static_cast<int>(std::sqrt(n)));
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
  static int getCnt(int i, int v) {
    int l = bl[i];
    int r = br[i];
    int m = {};
    int ans = 0;
    while ((l <= r)) {
      (m = jshr((l + r), 1));
      if ((sortv[m] >= v)) {
        (ans += ((r - m) + 1));
        (r = (m - 1));
      } else {
        (l = (m + 1));
      }
    }
    return ans;
  }
  static int query(int l, int r, int v) {
    int ans = 0;
    if ((bi[l] == bi[r])) {
      for (int i = l; (i <= r); (i++)) {
        if ((arr[i] >= v)) {
          (ans++);
        }
      }
    } else {
      for (int i = l; (i <= br[bi[l]]); (i++)) {
        if ((arr[i] >= v)) {
          (ans++);
        }
      }
      for (int i = bl[bi[r]]; (i <= r); (i++)) {
        if ((arr[i] >= v)) {
          (ans++);
        }
      }
      for (int i = (bi[l] + 1); (i <= (bi[r] - 1)); (i++)) {
        (ans += Code01_GiveAway1::getCnt(i, v));
      }
    }
    return ans;
  }
  static void update(int i, int v) {
    int l = bl[bi[i]];
    int r = br[bi[i]];
    (arr[i] = v);
    for (int j = l; (j <= r); (j++)) {
      (sortv[j] = arr[j]);
    }
    j::sort(sortv, l, (r + 1));
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    for (int i = 1; (i <= n); (i++)) {
      (arr[i] = in.nextInt());
    }
    Code01_GiveAway1::build();
    (m = in.nextInt());
    {
      int i = 1;
      int op = {};
      int a = {};
      int b = {};
      int c = {};
      for (; (i <= m); (i++)) {
        (op = in.nextInt());
        (a = in.nextInt());
        (b = in.nextInt());
        if ((op == 0)) {
          (c = in.nextInt());
          out.println(Code01_GiveAway1::query(a, b, c));
        } else {
          Code01_GiveAway1::update(a, b);
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
  Code01_GiveAway1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// Give Away，java版
// 给定一个长度为n的数组arr，接下来有m条操作，每条操作是如下两种类型中的一种
// 操作 0 a b c : 打印arr[a..b]范围上>=c的数字个数
// 操作 1 a b   : 把arr[a]的值改成b
// 1 <= n <= 5 * 10^5
// 1 <= m <= 10^5
// 1 <= 数组中的值 <= 10^9
// 测试链接 : https://www.luogu.com.cn/problem/SP18185
// 测试链接 : https://www.spoj.com/problems/GIVEAWAY
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 读写工具类
*/

// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/CF786C
// https://codeforces.com/problemset/problem/786/C

// Source: src/class175/Code06_TillCollapse1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code06_TillCollapse1 {
  inline static int MAXN = 100001;
  inline static int n = {};
  inline static int blen = {};
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static Array<bool> vis = make_array<bool>(MAXN);
  inline static Array<int> ans = make_array<int>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code06_TillCollapse1() {}
  static int query(int limit) {
    int kind = 0;
    int cnt = 0;
    int start = 1;
    for (int i = 1; (i <= n); (i++)) {
      if ((!vis[arr[i]])) {
        (kind++);
        if ((kind > limit)) {
          (cnt++);
          for (int j = start; (j < i); (j++)) {
            (vis[arr[j]] = false);
          }
          (start = i);
          (kind = 1);
        }
        (vis[arr[i]] = true);
      }
    }
    if ((kind > 0)) {
      (cnt++);
      for (int j = start; (j <= n); (j++)) {
        (vis[arr[j]] = false);
      }
    }
    return cnt;
  }
  static int jump(int l, int r, int curAns) {
    int find = l;
    while ((l <= r)) {
      int mid = jshr((l + r), 1);
      int check = Code06_TillCollapse1::query(mid);
      if ((check < curAns)) {
        (r = (mid - 1));
      } else if ((check > curAns)) {
        (l = (mid + 1));
      } else {
        (find = mid);
        (l = (mid + 1));
      }
    }
    return (find + 1);
  }
  static void compute() {
    for (int i = 1; (i <= blen); (i++)) {
      (ans[i] = Code06_TillCollapse1::query(i));
    }
    for (int i = (blen + 1); (i <= n);
         (i = Code06_TillCollapse1::jump(i, n, ans[i]))) {
      (ans[i] = Code06_TillCollapse1::query(i));
    }
  }
  static void prepare() {
    int log2n = 0;
    while ((jshl(1, log2n) <= jshr(n, 1))) {
      (log2n++);
    }
    (blen = jmax(1, static_cast<int>(std::sqrt((n * log2n)))));
    j::fill(ans, 1, (n + 1), (-1));
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(jout);
    (n = in.nextInt());
    for (int i = 1; (i <= n); (i++)) {
      (arr[i] = in.nextInt());
    }
    Code06_TillCollapse1::prepare();
    Code06_TillCollapse1::compute();
    for (int i = 1; (i <= n); (i++)) {
      if ((ans[i] == (-1))) {
        (ans[i] = ans[(i - 1)]);
      }
      out.print((ans[i] + String(u" ")));
    }
    out.println();
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code06_TillCollapse1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 最少划分，java版
// 给定一个长度为n的数组arr，考虑如下问题的解
// 数组arr划分成若干段子数组，保证每段不同数字的种类 <= k，返回至少划分成几段
// 打印k = 1, 2, 3..n时，所有的答案
// 1 <= arr[i] <= n <= 10^5
// 测试链接 : https://www.luogu.com.cn/problem/CF786C
// 测试链接 : https://codeforces.com/problemset/problem/786/C
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 读写工具类
*/

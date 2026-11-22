// Source: src/class131/Code05_TheBakery.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code05_TheBakery {
  inline static int MAXN = 35001;
  inline static int n = {};
  inline static int k = {};
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static Array<int> dp = make_array<int>(MAXN);
  inline static Array<int> pre = make_array<int>(MAXN);
  inline static Array<int> max = make_array<int>(jshl(MAXN, 2));
  inline static Array<int> add = make_array<int>(jshl(MAXN, 2));
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code05_TheBakery() {}
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    (n = static_cast<int>(in.nval));
    in.nextToken();
    (k = static_cast<int>(in.nval));
    for (int i = 1; (i <= n); (i++)) {
      in.nextToken();
      (arr[i] = static_cast<int>(in.nval));
    }
    out.println(Code05_TheBakery::compute());
    out.flush();
    out.close();
    br.close();
  }
  static int compute() {
    j::fill(dp, 1, (n + 1), 0);
    for (int t = 1; (t <= k); (t++)) {
      Code05_TheBakery::build(0, n, 1);
      j::fill(pre, 1, (n + 1), 0);
      for (int i = 1; (i <= n); (i++)) {
        Code05_TheBakery::add_method(pre[arr[i]], (i - 1), 1, 0, n, 1);
        if ((i >= t)) {
          (dp[i] = Code05_TheBakery::query(0, (i - 1), 0, n, 1));
        }
        (pre[arr[i]] = i);
      }
    }
    return dp[n];
  }
  static void up(int i) {
    (max[i] = jmax(max[jshl(i, 1)], max[(jshl(i, 1) | 1)]));
  }
  static void down(int i) {
    if ((add[i] != 0)) {
      Code05_TheBakery::lazy(jshl(i, 1), add[i]);
      Code05_TheBakery::lazy((jshl(i, 1) | 1), add[i]);
      (add[i] = 0);
    }
  }
  static void lazy(int i, int v) {
    (max[i] += v);
    (add[i] += v);
  }
  static void build(int l, int r, int i) {
    if ((l == r)) {
      (max[i] = dp[l]);
    } else {
      int mid = jshr((l + r), 1);
      Code05_TheBakery::build(l, mid, jshl(i, 1));
      Code05_TheBakery::build((mid + 1), r, (jshl(i, 1) | 1));
      Code05_TheBakery::up(i);
    }
    (add[i] = 0);
  }
  static void add_method(int jobl, int jobr, int jobv, int l, int r, int i) {
    if (((jobl <= l) && (r <= jobr))) {
      Code05_TheBakery::lazy(i, jobv);
    } else {
      Code05_TheBakery::down(i);
      int mid = jshr((l + r), 1);
      if ((jobl <= mid)) {
        Code05_TheBakery::add_method(jobl, jobr, jobv, l, mid, jshl(i, 1));
      }
      if ((jobr > mid)) {
        Code05_TheBakery::add_method(jobl, jobr, jobv, (mid + 1), r,
                                     (jshl(i, 1) | 1));
      }
      Code05_TheBakery::up(i);
    }
  }
  static int query(int jobl, int jobr, int l, int r, int i) {
    if (((jobl <= l) && (r <= jobr))) {
      return max[i];
    }
    Code05_TheBakery::down(i);
    int mid = jshr((l + r), 1);
    int ans = std::numeric_limits<int>::min();
    if ((jobl <= mid)) {
      (ans =
           jmax(ans, Code05_TheBakery::query(jobl, jobr, l, mid, jshl(i, 1))));
    }
    if ((jobr > mid)) {
      (ans = jmax(ans, Code05_TheBakery::query(jobl, jobr, (mid + 1), r,
                                               (jshl(i, 1) | 1))));
    }
    return ans;
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code05_TheBakery::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 划分k段的最大得分
// 给定一个长度为n的数组，最多可以分成k段不重合的子数组
// 每个子数组获得的分值为内部不同数字的个数
// 返回能获得的最大分值
// 1 <= n <= 35000
// 1 <= k <= 50
// k <= n
// 1 <= arr[i] <= n
// 测试链接 : https://www.luogu.com.cn/problem/CF833B
// 测试链接 : https://codeforces.com/problemset/problem/833/B
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有用例
        // 注意本题的线段树范围不是1~n，而是0~n
        // 因为线段树需要维护0号~n号指标
        // 下面所有方法都是线段树维护最大值的模版，没有任何修改
                        // 用dp[0..n]来build线段树
*/

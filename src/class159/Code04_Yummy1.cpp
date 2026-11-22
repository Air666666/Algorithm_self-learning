// Source: src/class159/Code04_Yummy1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_Yummy1 {
  inline static int MAXN = 200001;
  inline static int MAXT = 4000001;
  inline static int BIT = 18;
  inline static int n = {};
  inline static int m = {};
  inline static int s = {};
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static Array<int> root = make_array<int>(MAXN);
  inline static Array<int> left = make_array<int>(MAXT);
  inline static Array<int> right = make_array<int>(MAXT);
  inline static Array<int> size = make_array<int>(MAXT);
  inline static int cnt = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_Yummy1() {}
  static int build(int l, int r) {
    int rt = (++cnt);
    (size[rt] = 0);
    if ((l < r)) {
      int mid = jdiv((l + r), 2);
      (left[rt] = Code04_Yummy1::build(l, mid));
      (right[rt] = Code04_Yummy1::build((mid + 1), r));
    }
    return rt;
  }
  static int insert(int jobi, int l, int r, int i) {
    int rt = (++cnt);
    (left[rt] = left[i]);
    (right[rt] = right[i]);
    (size[rt] = (size[i] + 1));
    if ((l < r)) {
      int mid = jdiv((l + r), 2);
      if ((jobi <= mid)) {
        (left[rt] = Code04_Yummy1::insert(jobi, l, mid, left[rt]));
      } else {
        (right[rt] = Code04_Yummy1::insert(jobi, (mid + 1), r, right[rt]));
      }
    }
    return rt;
  }
  static int query(int jobl, int jobr, int l, int r, int u, int v) {
    if (((jobr < l) || (jobl > r))) {
      return 0;
    }
    if (((jobl <= l) && (r <= jobr))) {
      return (size[v] - size[u]);
    }
    int mid = jdiv((l + r), 2);
    int ans = 0;
    if ((jobl <= mid)) {
      (ans += Code04_Yummy1::query(jobl, jobr, l, mid, left[u], left[v]));
    }
    if ((jobr > mid)) {
      (ans +=
       Code04_Yummy1::query(jobl, jobr, (mid + 1), r, right[u], right[v]));
    }
    return ans;
  }
  static void prepare() {
    (cnt = 0);
    (s = 0);
    for (int i = 1; (i <= n); (i++)) {
      (s = jmax(s, arr[i]));
    }
    (root[0] = Code04_Yummy1::build(0, s));
    for (int i = 1; (i <= n); (i++)) {
      (root[i] = Code04_Yummy1::insert(arr[i], 0, s, root[(i - 1)]));
    }
  }
  static int compute(int b, int x, int l, int r) {
    int best = 0;
    for (int i = BIT; (i >= 0); (i--)) {
      if (((jshr(b, i) & 1) == 1)) {
        if ((Code04_Yummy1::query((best - x), (((best + jshl(1, i)) - 1) - x),
                                  0, s, root[(l - 1)], root[r]) == 0)) {
          (best += jshl(1, i));
        }
      } else {
        if ((Code04_Yummy1::query(((best + jshl(1, i)) - x),
                                  (((best + jshl(1, (i + 1))) - 1) - x), 0, s,
                                  root[(l - 1)], root[r]) != 0)) {
          (best += jshl(1, i));
        }
      }
    }
    return (best ^ b);
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    (n = static_cast<int>(in.nval));
    in.nextToken();
    (m = static_cast<int>(in.nval));
    for (int i = 1; (i <= n); (i++)) {
      in.nextToken();
      (arr[i] = static_cast<int>(in.nval));
    }
    Code04_Yummy1::prepare();
    {
      int i = 1;
      int b = {};
      int x = {};
      int l = {};
      int r = {};
      for (; (i <= m); (i++)) {
        in.nextToken();
        (b = static_cast<int>(in.nval));
        in.nextToken();
        (x = static_cast<int>(in.nval));
        in.nextToken();
        (l = static_cast<int>(in.nval));
        in.nextToken();
        (r = static_cast<int>(in.nval));
        out.println(Code04_Yummy1::compute(b, x, l, r));
      }
    }
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code04_Yummy1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 美味，java版
// 给定一个长度为n的数组arr，一共有m条查询，查询格式如下
// b x l r : 从arr[l..r]中选一个数字，希望b ^ (该数字 + x)的值最大，打印这个值
// 1 <= n <= 2 * 10^5
// 1 <= m <= 10^5
// 0 <= arr[i]、b、x < 10^5
// 测试链接 : https://www.luogu.com.cn/problem/P3293
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 可持久化线段树需要
*/

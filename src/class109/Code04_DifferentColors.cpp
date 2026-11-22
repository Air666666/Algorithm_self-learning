// Source: src/class109/Code04_DifferentColors.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_DifferentColors {
  inline static int MAXN = 1000001;
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static Array<Array<int>> query = make_array<int>(MAXN, 3);
  inline static Array<int> ans = make_array<int>(MAXN);
  inline static Array<int> map = make_array<int>(MAXN);
  inline static Array<int> tree = make_array<int>(MAXN);
  inline static int n = {};
  inline static int m = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_DifferentColors() {}
  static int lowbit(int i) { return (i & (-i)); }
  static void add(int i, int v) {
    while ((i <= n)) {
      (tree[i] += v);
      (i += Code04_DifferentColors::lowbit(i));
    }
  }
  static int sum(int i) {
    int ans = 0;
    while ((i > 0)) {
      (ans += tree[i]);
      (i -= Code04_DifferentColors::lowbit(i));
    }
    return ans;
  }
  static int range(int l, int r) {
    return [&]() {
      auto jleft = Code04_DifferentColors::sum(r);
      auto jright = Code04_DifferentColors::sum((l - 1));
      return (jleft - jright);
    }();
  }
  static void compute() {
    j::sort(query, 1, (m + 1),
            [=](Array<int> a, Array<int> b) { return (a[1] - b[1]); });
    {
      int s = 1;
      int q = 1;
      int l = {};
      int r = {};
      int i = {};
      for (; (q <= m); (q++)) {
        (r = query[q][1]);
        for (; (s <= r); (s++)) {
          int color = arr[s];
          if ((map[color] != 0)) {
            Code04_DifferentColors::add(map[color], (-1));
          }
          Code04_DifferentColors::add(s, 1);
          (map[color] = s);
        }
        (l = query[q][0]);
        (i = query[q][2]);
        (ans[i] = Code04_DifferentColors::range(l, r));
      }
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO();
    IO out = IO(IO(jout));
    (n = in.nextInt());
    for (int i = 1; (i <= n); (i++)) {
      (arr[i] = in.nextInt());
    }
    (m = in.nextInt());
    for (int i = 1; (i <= m); (i++)) {
      (query[i][0] = in.nextInt());
      (query[i][1] = in.nextInt());
      (query[i][2] = i);
    }
    Code04_DifferentColors::compute();
    for (int i = 1; (i <= m); (i++)) {
      out.write((ans[i] + String(u"\n")));
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code04_DifferentColors::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// HH的项链
// 一共有n个位置，每个位置颜色给定，i位置的颜色是arr[i]
// 一共有m个查询，question[i] = {li, ri}
// 表示第i条查询想查arr[li..ri]范围上一共有多少种不同颜色
// 返回每条查询的答案
// 1 <= n、m、arr[i] <= 10^6
// 1 <= li <= ri <= n
// 测试链接 : https://www.luogu.com.cn/problem/P1972
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
// 代码逻辑和课上讲的完全一致，但是重写了读写工具类，增加了io效率
        // 读写工具类
*/

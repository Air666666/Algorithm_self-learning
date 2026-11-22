// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P2371

// Source: src/class143/Code04_MomoEquation2.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_MomoEquation2 {
  inline static int MAXN = 500001;
  inline static i64 inf = std::numeric_limits<i64>::max();
  inline static Array<int> v = make_array<int>(MAXN);
  inline static Array<i64> dist = make_array<i64>(MAXN);
  inline static int n = {};
  inline static int x = {};
  inline static i64 l = {};
  inline static i64 r = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_MomoEquation2() {}
  static int gcd(int a, int b) {
    return ((b == 0) ? a : Code04_MomoEquation2::gcd(b, jrem(a, b)));
  }
  static i64 compute() {
    j::sort(v, 1, (n + 1));
    int size = 0;
    for (int i = 1; (i <= n); (i++)) {
      if ((v[i] != 0)) {
        (v[(++size)] = v[i]);
      }
    }
    if ((size == 0)) {
      return 0;
    }
    (x = v[1]);
    j::fill(dist, 0, x, inf);
    (dist[0] = 0);
    {
      int i = 2;
      int d = {};
      for (; (i <= size); (i++)) {
        (d = Code04_MomoEquation2::gcd(v[i], x));
        for (int j = 0; (j < d); (j++)) {
          {
            int cur = j;
            int next = {};
            int circle = 0;
            for (; (circle < 2); (circle += ((cur == j) ? 1 : 0))) {
              (next = jrem((cur + v[i]), x));
              if ((dist[cur] != inf)) {
                (dist[next] = jmin(dist[next], (dist[cur] + v[i])));
              }
              (cur = next);
            }
          }
        }
      }
    }
    i64 ans = 0;
    for (int i = 0; (i < x); (i++)) {
      if ((r >= dist[i])) {
        (ans += jmax(0, (jdiv((r - dist[i]), x) + 1)));
      }
      if ((l >= dist[i])) {
        (ans -= jmax(0, (jdiv((l - dist[i]), x) + 1)));
      }
    }
    return ans;
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    (n = static_cast<int>(in.nval));
    in.nextToken();
    (l = (static_cast<i64>(in.nval) - 1));
    in.nextToken();
    (r = static_cast<i64>(in.nval));
    for (int i = 1; (i <= n); (i++)) {
      in.nextToken();
      (v[i] = static_cast<int>(in.nval));
    }
    out.println(Code04_MomoEquation2::compute());
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code04_MomoEquation2::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 墨墨的等式(两次转圈法)
// 一共有n种正数，每种数可以选择任意个，个数不能是负数
// 那么一定有某些数值可以由这些数字累加得到
// 请问在[l...r]范围上，有多少个数能被累加得到
// 0 <= n <= 12
// 0 <= 数值范围 <= 5 * 10^5
// 1 <= l <= r <= 10^12
// 测试链接 : https://www.luogu.com.cn/problem/P2371
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
*/

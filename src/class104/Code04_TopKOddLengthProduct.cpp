// Source: src/class104/Code04_TopKOddLengthProduct.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_TopKOddLengthProduct {
  inline static int MOD = 19930726;
  inline static int MAXN = 10000001;
  inline static Array<String> mk = {};
  inline static int m = {};
  inline static int n = {};
  inline static i64 k = {};
  inline static Array<jchar> ss = make_array<jchar>(jshl(MAXN, 1));
  inline static Array<int> p = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> cnt = make_array<int>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_TopKOddLengthProduct() {}
  static void java_main(Array<String> args) {
    IO in = IO(IO(jin));
    IO out = IO(IO(jout));
    (mk = in.readLine().split(String(u" ")));
    (m = std::stoi(text(mk[0])));
    (k = std::stoll(text(mk[1])));
    out.println(Code04_TopKOddLengthProduct::compute(in.readLine()));
    out.flush();
    out.close();
    in.close();
  }
  static int compute(String s) {
    Code04_TopKOddLengthProduct::manacher(s);
    for (int i = 1; (i < n); (i += 2)) {
      (cnt[(p[i] - 1)]++);
    }
    i64 ans = 1;
    i64 sum = 0;
    for (int len = (((m & 1) == 1) ? m : (m - 1)); ((len >= 1) && (k > 0));
         (len -= 2)) {
      (sum += cnt[len]);
      (ans = jrem((ans * Code04_TopKOddLengthProduct::power(len, jmin(k, sum))),
                  MOD));
      (k -= sum);
    }
    return ((k > 0) ? (-1) : static_cast<int>(ans));
  }
  static void manacher(String str) {
    Code04_TopKOddLengthProduct::manacherss(str.toCharArray());
    {
      int i = 0;
      int c = 0;
      int r = 0;
      int len = {};
      for (; (i < n); (i++)) {
        (len = ((r > i) ? jmin(p[((2 * c) - i)], (r - i)) : 1));
        while (((((i + len) < n) && ((i - len) >= 0)) &&
                (ss[(i + len)] == ss[(i - len)]))) {
          (len++);
        }
        if (((i + len) > r)) {
          (r = (i + len));
          (c = i);
        }
        (p[i] = len);
      }
    }
  }
  static void manacherss(Array<jchar> a) {
    (n = ((a.length * 2) + 1));
    {
      int i = 0;
      int j = 0;
      for (; (i < n); (i++)) {
        (ss[i] = (((i & 1) == 0) ? u'#' : a[(j++)]));
      }
    }
  }
  static i64 power(i64 x, i64 n) {
    i64 ans = 1;
    while ((n > 0)) {
      if (((n & 1) == 1)) {
        (ans = jrem((ans * x), MOD));
      }
      (x = jrem((x * x), MOD));
      (n = jshr(n, 1));
    }
    return ans;
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code04_TopKOddLengthProduct::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 长度前k名的奇数长度回文子串长度乘积
// 给定一个字符串s和数值k，只关心所有奇数长度的回文子串
// 返回其中长度前k名的回文子串的长度乘积是多少
// 如果奇数长度的回文子串个数不够k个，返回-1
// 测试链接 : https://www.luogu.com.cn/problem/P1659
// 答案对19930726取模
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下的code，提交时请把类名改成"Main"，可以直接通过
*/

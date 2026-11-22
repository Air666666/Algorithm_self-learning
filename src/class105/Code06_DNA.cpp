// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P3763

// Source: src/class105/Code06_DNA.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code06_DNA {
  inline static int MAXN = 100001;
  inline static int base = 499;
  inline static Array<i64> pow = make_array<i64>(MAXN);
  inline static Array<i64> hashs = make_array<i64>(MAXN);
  inline static Array<i64> hashp = make_array<i64>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code06_DNA() {}
  static void java_main(Array<String> args) {
    IO in = IO(IO(jin));
    IO out = IO(IO(jout));
    int n = std::stoi(text(in.readLine()));
    for (int i = 0; (i < n); (i++)) {
      String s = in.readLine();
      String p = in.readLine();
      out.println([&]() {
        auto jargument_0 = s.toCharArray();
        auto jargument_1 = p.toCharArray();
        auto jargument_2 = 3;
        return Code06_DNA::compute(jargument_0, jargument_1, jargument_2);
      }());
    }
    out.flush();
    out.close();
    in.close();
  }
  static int compute(Array<jchar> s, Array<jchar> p, int k) {
    int n = s.length;
    int m = p.length;
    if ((n < m)) {
      return 0;
    }
    Code06_DNA::build(s, n, p, m);
    int ans = 0;
    for (int i = 0; (i <= (n - m)); (i++)) {
      if (Code06_DNA::check(i, ((i + m) - 1), k)) {
        (ans++);
      }
    }
    return ans;
  }
  static bool check(int l1, int r1, int k) {
    int diff = 0;
    int l2 = 0;
    while (((l1 <= r1) && (diff <= k))) {
      int l = 1;
      int r = ((r1 - l1) + 1);
      int m = {};
      int len = 0;
      while ((l <= r)) {
        (m = jdiv((l + r), 2));
        if (Code06_DNA::same(l1, l2, m)) {
          (len = m);
          (l = (m + 1));
        } else {
          (r = (m - 1));
        }
      }
      if (((l1 + len) <= r1)) {
        (diff++);
      }
      (l1 += (len + 1));
      (l2 += (len + 1));
    }
    return (diff <= k);
  }
  static bool same(int l1, int l2, int len) {
    return [&]() {
      auto jleft = Code06_DNA::hash(hashs, l1, ((l1 + len) - 1));
      auto jright = Code06_DNA::hash(hashp, l2, ((l2 + len) - 1));
      return (jleft == jright);
    }();
  }
  static void build(Array<jchar> s, int n, Array<jchar> p, int m) {
    (pow[0] = 1);
    for (int j = 1; (j < MAXN); (j++)) {
      (pow[j] = (pow[(j - 1)] * base));
    }
    (hashs[0] = ((s[0] - u'a') + 1));
    for (int j = 1; (j < n); (j++)) {
      (hashs[j] = ((((hashs[(j - 1)] * base) + s[j]) - u'a') + 1));
    }
    (hashp[0] = ((p[0] - u'a') + 1));
    for (int j = 1; (j < m); (j++)) {
      (hashp[j] = ((((hashp[(j - 1)] * base) + p[j]) - u'a') + 1));
    }
  }
  static i64 hash(Array<i64> hash, int l, int r) {
    i64 ans = hash[r];
    (ans -= ((l == 0) ? 0 : (hash[(l - 1)] * pow[((r - l) + 1)])));
    return ans;
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code06_DNA::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 根据匹配定义求匹配子串的数量
// 给定长为n的字符串s，以及长度为m的字符串p，还有一个正数k
// s'与s匹配的定义为，s'与s长度相同，且最多有k个位置字符不同
// 要求查找字符串s中有多少子串与字符串p匹配
// 测试链接 : https://www.luogu.com.cn/problem/P3763
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下的code，提交时请把类名改成"Main"，可以直接通过
        // s中有多少子串修改最多k个位置的字符就可以变成p
        // s长度为n，p长度为m，时间复杂度O(n * k * logm)
                        // s[i...i+m-1] -> m
                        // p[0.....m-1]
        // s[l1...r1] 和 p[0...m-1] 取等长的两段
        // 返回这两段上字符不一样的位置是不是<=k个
*/

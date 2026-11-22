// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string/

// Source: src/class105/Code03_SubstringHash.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_SubstringHash {
  inline static int MAXN = 100005;
  inline static int base = 499;
  inline static Array<i64> pow = make_array<i64>(MAXN);
  inline static Array<i64> hash = make_array<i64>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_SubstringHash() {}
  static int strStr(String str1, String str2) {
    Array<jchar> s1 = str1.toCharArray();
    Array<jchar> s2 = str2.toCharArray();
    int n = s1.length;
    int m = s2.length;
    Code03_SubstringHash::build(s1, n);
    i64 h2 = ((s2[0] - u'a') + 1);
    for (int i = 1; (i < m); (i++)) {
      (h2 = ((((h2 * base) + s2[i]) - u'a') + 1));
    }
    {
      int l = 0;
      int r = (m - 1);
      for (; (r < n); (l++), (r++)) {
        if ((Code03_SubstringHash::hash_method(l, r) == h2)) {
          return l;
        }
      }
    }
    return (-1);
  }
  static void build(Array<jchar> s, int n) {
    (pow[0] = 1);
    for (int i = 1; (i < n); (i++)) {
      (pow[i] = (pow[(i - 1)] * base));
    }
    (hash[0] = ((s[0] - u'a') + 1));
    for (int i = 1; (i < n); (i++)) {
      (hash[i] = ((((hash[(i - 1)] * base) + s[i]) - u'a') + 1));
    }
  }
  static i64 hash_method(int l, int r) {
    i64 ans = hash[r];
    if ((l > 0)) {
      (ans -= (hash[(l - 1)] * pow[((r - l) + 1)]));
    }
    return ans;
  }
};

/* Original teaching comments:
// 字符串哈希得到子串哈希
// 利用字符串哈希的便利性替代KMP算法
// 测试链接 :
https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string/
        // 如下代码是字符串哈希的原理和模版
        // 比如，base = 499, 也就是课上说的选择的质数进制
        // 再比如字符串s如下
        // " c a b e f "
        //   0 1 2 3 4
        // hash[0] = 3 * base的0次方
        // hash[1] = 3 * base的1次方 + 1 * base的0次方
        // hash[2] = 3 * base的2次方 + 1 * base的1次方 + 2 * base的0次方
        // hash[3] = 3 * base的3次方 + 1 * base的2次方 + 2 * base的1次方 + 5 *
base的0次方
        // hash[4] = 3 * base的4次方 + 1 * base的3次方 + 2 * base的2次方 + 5 *
base的1次方 + 6 *
        // base的0次方
        // hash[i] = hash[i-1] * base + s[i] - 'a' + 1，就是上面说的意思
        // 想计算子串"be"的哈希值 -> 2 * base的1次方 + 5 * base的0次方
        // 子串"be"的哈希值 = hash[3] - hash[1] *
base的2次方(子串"be"的长度次方)
        // hash[1] = 3 * base的1次方 + 1 * base的0次方
        // hash[1] * base的2次方 = 3 * base的3次方 + 1 * base的2次方
        // hash[3] = 3 * base的3次方 + 1 * base的2次方 + 2 * base的1次方 + 5 *
base的0次方
        // hash[3] - hash[1] * base的2次方 = 2 * base的1次方 + 5 * base的0次方
        // 这样就得到子串"be"的哈希值了
        // 子串s[l...r]的哈希值 = hash[r] - hash[l-1] *
base的(r-l+1)次方，就是上面说的意思
        // 返回s[l...r]的哈希值
*/

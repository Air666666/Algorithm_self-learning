// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/substring-with-concatenation-of-all-words/

// Source: src/class105/Code05_ConcatenationAllWords.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code05_ConcatenationAllWords {
  inline static int MAXN = 10001;
  inline static int base = 499;
  inline static Array<i64> pow = make_array<i64>(MAXN);
  inline static Array<i64> hash = make_array<i64>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code05_ConcatenationAllWords() {}
  static JList<int> findSubstring(String s, Array<String> words) {
    JList<int> ans = JList<int>();
    if (((((s == nullptr) || (s.length() == 0)) || (words == nullptr)) ||
         (words.length == 0))) {
      return ans;
    }
    JMap<i64, int> map = JMap<i64, int>();
    for (String key : words) {
      i64 v = Code05_ConcatenationAllWords::hash_method(key);
      map.put(v, (map.getOrDefault(v, 0) + 1));
    }
    Code05_ConcatenationAllWords::build(s);
    int n = s.length();
    int wordLen = words[0].length();
    int wordNum = words.length;
    int allLen = (wordLen * wordNum);
    JMap<i64, int> window = JMap<i64, int>();
    for (int init = 0; ((init < wordLen) && ((init + allLen) <= n)); (init++)) {
      int debt = wordNum;
      {
        int l = init;
        int r = (init + wordLen);
        int part = 0;
        for (; (part < wordNum); (l += wordLen), (r += wordLen), (part++)) {
          i64 cur = Code05_ConcatenationAllWords::hash_method(l, r);
          window.put(cur, (window.getOrDefault(cur, 0) + 1));
          if ([&]() {
                auto jleft = window.get(cur);
                auto jright = map.getOrDefault(cur, 0);
                return (jleft <= jright);
              }()) {
            (debt--);
          }
        }
      }
      if ((debt == 0)) {
        ans.add(init);
      }
      {
        int l1 = init;
        int r1 = (init + wordLen);
        int l2 = (init + allLen);
        int r2 = ((init + allLen) + wordLen);
        for (; (r2 <= n); (l1 += wordLen), (r1 += wordLen), (l2 += wordLen),
                          (r2 += wordLen)) {
          i64 out = Code05_ConcatenationAllWords::hash_method(l1, r1);
          i64 in = Code05_ConcatenationAllWords::hash_method(l2, r2);
          window.put(out, (window.get(out) - 1));
          if ([&]() {
                auto jleft = window.get(out);
                auto jright = map.getOrDefault(out, 0);
                return (jleft < jright);
              }()) {
            (debt++);
          }
          window.put(in, (window.getOrDefault(in, 0) + 1));
          if ([&]() {
                auto jleft = window.get(in);
                auto jright = map.getOrDefault(in, 0);
                return (jleft <= jright);
              }()) {
            (debt--);
          }
          if ((debt == 0)) {
            ans.add(r1);
          }
        }
      }
      window.clear();
    }
    return ans;
  }
  static void build(String str) {
    (pow[0] = 1);
    for (int j = 1; (j < MAXN); (j++)) {
      (pow[j] = (pow[(j - 1)] * base));
    }
    (hash[0] = ((str.charAt(0) - u'a') + 1));
    for (int j = 1; (j < str.length()); (j++)) {
      (hash[j] = ((((hash[(j - 1)] * base) + str.charAt(j)) - u'a') + 1));
    }
  }
  static i64 hash_method(int l, int r) {
    i64 ans = hash[(r - 1)];
    (ans -= ((l == 0) ? 0 : (hash[(l - 1)] * pow[(r - l)])));
    return ans;
  }
  static i64 hash_method(String str) {
    if (str.equals(String(u""))) {
      return 0;
    }
    int n = str.length();
    i64 ans = ((str.charAt(0) - u'a') + 1);
    for (int j = 1; (j < n); (j++)) {
      (ans = ((((ans * base) + str.charAt(j)) - u'a') + 1));
    }
    return ans;
  }
};

/* Original teaching comments:
// 串联所有单词的子串
// 给定一个字符串s和一个字符串数组words
// words中所有字符串长度相同
// s中的串联子串是指一个包含 words中所有字符串以任意顺序排列连接起来的子串
// 例如words = { "ab","cd","ef" }
// 那么"abcdef"、"abefcd"、"cdabef"、"cdefab"、"efabcd"、"efcdab"都是串联子串。
// "acdbef"不是串联子串，因为他不是任何words排列的连接
// 返回所有串联子串在s中的开始索引
// 你可以以任意顺序返回答案
// 测试链接 :
https://leetcode.cn/problems/substring-with-concatenation-of-all-words/
        // 如果s的长度为n，words里所有单词的总长度为m
        // 时间复杂度O(n + m)，最优解的时间复杂度与单词个数、单词长度是无关的
        // 所有题解都没有做到这个复杂度的
        // 虽然这个做法打败比例没有到100%，但那是因为测试数据量不够大
        // 所以最优解的时间复杂度优势没有体现出来
        // 这个方法绝对是最优解，只有同余分组 + 字符串哈希，时间复杂度才能到最优
                // words的词频表
                // 窗口的词频表
                        // init是当前组的首个开头
                        // 建立起窗口
                        // 接下来窗口进一个、出一个
        // 范围是s[l,r)，左闭右开
        // 计算一个字符串的哈希值
*/

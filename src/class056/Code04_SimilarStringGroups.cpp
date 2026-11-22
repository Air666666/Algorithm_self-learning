// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/similar-string-groups/

// Source: src/class056/Code04_SimilarStringGroups.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_SimilarStringGroups {
  inline static int MAXN = 301;
  inline static Array<int> father = make_array<int>(MAXN);
  inline static int sets = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_SimilarStringGroups() {}
  static void build(int n) {
    for (int i = 0; (i < n); (i++)) {
      (father[i] = i);
    }
    (sets = n);
  }
  static int find(int i) {
    if ((i != father[i])) {
      (father[i] = Code04_SimilarStringGroups::find(father[i]));
    }
    return father[i];
  }
  static void union_method(int x, int y) {
    int fx = Code04_SimilarStringGroups::find(x);
    int fy = Code04_SimilarStringGroups::find(y);
    if ((fx != fy)) {
      (father[fx] = fy);
      (sets--);
    }
  }
  static int numSimilarGroups(Array<String> strs) {
    int n = strs.length;
    int m = strs[0].length();
    Code04_SimilarStringGroups::build(n);
    for (int i = 0; (i < n); (i++)) {
      for (int j = (i + 1); (j < n); (j++)) {
        if ([&]() {
              auto jleft = Code04_SimilarStringGroups::find(i);
              auto jright = Code04_SimilarStringGroups::find(j);
              return (jleft != jright);
            }()) {
          int diff = 0;
          for (int k = 0; ((k < m) && (diff < 3)); (k++)) {
            if ([&]() {
                  auto jleft = strs[i].charAt(k);
                  auto jright = strs[j].charAt(k);
                  return (jleft != jright);
                }()) {
              (diff++);
            }
          }
          if (((diff == 0) || (diff == 2))) {
            Code04_SimilarStringGroups::union_method(i, j);
          }
        }
      }
    }
    return sets;
  }
};

/* Original teaching comments:
// 相似字符串组
// 如果交换字符串 X 中的两个不同位置的字母，使得它和字符串 Y 相等
// 那么称 X 和 Y 两个字符串相似
// 如果这两个字符串本身是相等的，那它们也是相似的
// 例如，"tars" 和 "rats" 是相似的 (交换 0 与 2 的位置)；
// "rats" 和 "arts" 也是相似的，但是 "star" 不与 "tars"，"rats"，或 "arts" 相似
// 总之，它们通过相似性形成了两个关联组：{"tars", "rats", "arts"} 和 {"star"}
// 注意，"tars" 和 "arts" 是在同一组中，即使它们并不相似
//
形式上，对每个组而言，要确定一个单词在组中，只需要这个词和该组中至少一个单词相似。
// 给你一个字符串列表 strs列表中的每个字符串都是 strs
中其它所有字符串的一个字母异位词。
// 返回 strs 中有多少字符串组
// 测试链接 : https://leetcode.cn/problems/similar-string-groups/
*/

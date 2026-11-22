// Source: src/class038/Code01_Subsequences.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_Subsequences {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_Subsequences() {}
  static Array<String> generatePermutation1(String str) {
    Array<jchar> s = str.toCharArray();
    JHashSet<String> set = JHashSet<String>();
    Code01_Subsequences::f1(s, 0, StringBuilder(), set);
    int m = set.size();
    Array<String> ans = make_array<String>(m);
    int i = 0;
    for (String cur : set) {
      (ans[(i++)] = cur);
    }
    return ans;
  }
  static void f1(Array<jchar> s, int i, StringBuilder path,
                 JHashSet<String> set) {
    if ((i == s.length)) {
      set.add(path.toString());
    } else {
      path.append(s[i]);
      Code01_Subsequences::f1(s, (i + 1), path, set);
      path.deleteCharAt((path.length() - 1));
      Code01_Subsequences::f1(s, (i + 1), path, set);
    }
  }
  static Array<String> generatePermutation2(String str) {
    Array<jchar> s = str.toCharArray();
    JHashSet<String> set = JHashSet<String>();
    Code01_Subsequences::f2(s, 0, make_array<jchar>(s.length), 0, set);
    int m = set.size();
    Array<String> ans = make_array<String>(m);
    int i = 0;
    for (String cur : set) {
      (ans[(i++)] = cur);
    }
    return ans;
  }
  static void f2(Array<jchar> s, int i, Array<jchar> path, int size,
                 JHashSet<String> set) {
    if ((i == s.length)) {
      set.add(j::str(path, 0, size));
    } else {
      (path[size] = s[i]);
      Code01_Subsequences::f2(s, (i + 1), path, (size + 1), set);
      Code01_Subsequences::f2(s, (i + 1), path, size, set);
    }
  }
};

/* Original teaching comments:
// 字符串的全部子序列
// 子序列本身是可以有重复的，只是这个题目要求去重
// 测试链接 : https://www.nowcoder.com/practice/92e6247998294f2c933906fdedbc6e6a
        // s[i...]，之前决定的路径path，set收集结果时去重
*/

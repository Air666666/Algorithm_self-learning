// Source: src/class039/Code03_NumberOfAtoms.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_NumberOfAtoms {
  inline static int where = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_NumberOfAtoms() {}
  static String countOfAtoms(String str) {
    (where = 0);
    JTreeMap<String, int> map = Code03_NumberOfAtoms::f(str.toCharArray(), 0);
    StringBuilder ans = StringBuilder();
    for (String key : map.keySet()) {
      ans.append(key);
      int cnt = map.get(key);
      if ((cnt > 1)) {
        ans.append(cnt);
      }
    }
    return ans.toString();
  }
  static JTreeMap<String, int> f(Array<jchar> s, int i) {
    JTreeMap<String, int> ans = JTreeMap<String, int>();
    StringBuilder name = StringBuilder();
    JTreeMap<String, int> pre = nullptr;
    int cnt = 0;
    while (((i < s.length) && (s[i] != u')'))) {
      if ((((s[i] >= u'A') && (s[i] <= u'Z')) || (s[i] == u'('))) {
        Code03_NumberOfAtoms::fill(ans, name, pre, cnt);
        name.setLength(0);
        (pre = nullptr);
        (cnt = 0);
        if (((s[i] >= u'A') && (s[i] <= u'Z'))) {
          name.append(s[(i++)]);
        } else {
          (pre = Code03_NumberOfAtoms::f(s, (i + 1)));
          (i = (where + 1));
        }
      } else if (((s[i] >= u'a') && (s[i] <= u'z'))) {
        name.append(s[(i++)]);
      } else {
        (cnt = (((cnt * 10) + s[(i++)]) - u'0'));
      }
    }
    Code03_NumberOfAtoms::fill(ans, name, pre, cnt);
    (where = i);
    return ans;
  }
  static void fill(JTreeMap<String, int> ans, StringBuilder name,
                   JTreeMap<String, int> pre, int cnt) {
    if (((name.length() > 0) || (pre != nullptr))) {
      (cnt = ((cnt == 0) ? 1 : cnt));
      if ((name.length() > 0)) {
        String key = name.toString();
        ans.put(key, (ans.getOrDefault(key, 0) + cnt));
      } else {
        for (String key : pre.keySet()) {
          ans.put(key, [&]() {
            auto jleft = ans.getOrDefault(key, 0);
            auto jright = (pre.get(key) * cnt);
            return (jleft + jright);
          }());
        }
      }
    }
  }
};

/* Original teaching comments:
// 含有嵌套的分子式求原子数量
// 测试链接 : https://leetcode.cn/problems/number-of-atoms/
        // s[i....]开始计算，遇到字符串终止 或者 遇到 ) 停止
        // 返回 : 自己负责的这一段字符串的结果，有序表！
        // 返回之间，更新全局变量where，为了上游函数知道从哪继续！
                // ans是总表
                // 之前收集到的名字，历史一部分
                // 之前收集到的有序表，历史一部分
                // 历史翻几倍
                                        // 遇到 (
*/

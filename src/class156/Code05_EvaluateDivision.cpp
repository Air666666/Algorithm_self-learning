// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/evaluate-division/

// Source: src/class156/Code05_EvaluateDivision.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code05_EvaluateDivision {
  inline static JMap<String, String> father = JMap<String, String>();
  inline static JMap<String, double> dist = JMap<String, double>();
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code05_EvaluateDivision() {}
  static Array<double> calcEquation(JList<JList<String>> equations,
                                    Array<double> values,
                                    JList<JList<String>> queries) {
    Code05_EvaluateDivision::prepare(equations);
    for (int i = 0; (i < values.length); (i++)) {
      [&]() {
        auto jargument_0 = equations.get(i).get(0);
        auto jargument_1 = equations.get(i).get(1);
        auto jargument_2 = values[i];
        return Code05_EvaluateDivision::union_method(jargument_0, jargument_1,
                                                     jargument_2);
      }();
    }
    Array<double> ans = make_array<double>(queries.size());
    for (int i = 0; (i < queries.size()); (i++)) {
      (ans[i] = [&]() {
        auto jargument_0 = queries.get(i).get(0);
        auto jargument_1 = queries.get(i).get(1);
        return Code05_EvaluateDivision::query(jargument_0, jargument_1);
      }());
    }
    return ans;
  }
  static void prepare(JList<JList<String>> equations) {
    father.clear();
    dist.clear();
    for (JList<String> list : equations) {
      for (String key : list) {
        father.put(key, key);
        dist.put(key, 1.0);
      }
    }
  }
  static String find(String x) {
    if ((!father.containsKey(x))) {
      return nullptr;
    }
    String tmp = {};
    String fa = x;
    if ((!x.equals(father.get(x)))) {
      (tmp = father.get(x));
      (fa = Code05_EvaluateDivision::find(tmp));
      dist.put(x, [&]() {
        auto jleft = dist.get(x);
        auto jright = dist.get(tmp);
        return (jleft * jright);
      }());
      father.put(x, fa);
    }
    return fa;
  }
  static void union_method(String l, String r, double v) {
    String lf = Code05_EvaluateDivision::find(l);
    String rf = Code05_EvaluateDivision::find(r);
    if ((!lf.equals(rf))) {
      father.put(lf, rf);
      dist.put(lf, ([&]() {
                 auto jleft = dist.get(r);
                 auto jright = dist.get(l);
                 return jdiv(jleft, jright);
               }() * v));
    }
  }
  static double query(String l, String r) {
    String lf = Code05_EvaluateDivision::find(l);
    String rf = Code05_EvaluateDivision::find(r);
    if ((((lf == nullptr) || (rf == nullptr)) || (!lf.equals(rf)))) {
      return (-1.0);
    }
    return [&]() {
      auto jleft = dist.get(l);
      auto jright = dist.get(r);
      return jdiv(jleft, jright);
    }();
  }
};

/* Original teaching comments:
// 除法求值
// 所有变量都用字符串表示，并且给定若干组等式
// 比如等式
// ["ab", "ef"] = 8，代表ab / ef = 8
// ["ct", "ef"] = 2，代表ct / ef = 2
// 所有等式都是正确的并且可以进行推断，给定所有等式之后，会给你若干条查询
// 比如查询，["ab", "ct"]，根据上面的等式推断，ab / ct = 4
// 如果某条查询中的变量，从来没在等式中出现过，认为答案是-1.0
// 如果某条查询的答案根本推断不出来，认为答案是-1.0
// 返回所有查询的答案
// 测试链接 : https://leetcode.cn/problems/evaluate-division/
*/

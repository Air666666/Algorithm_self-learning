// Source: src/class039/Code01_BasicCalculatorIII.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_BasicCalculatorIII {
  inline static int where = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_BasicCalculatorIII() {}
  static int calculate(String str) {
    (where = 0);
    return Code01_BasicCalculatorIII::f(str.toCharArray(), 0);
  }
  static int f(Array<jchar> s, int i) {
    int cur = 0;
    JList<int> numbers = JList<int>();
    JList<jchar> ops = JList<jchar>();
    while (((i < s.length) && (s[i] != u')'))) {
      if (((s[i] >= u'0') && (s[i] <= u'9'))) {
        (cur = (((cur * 10) + s[(i++)]) - u'0'));
      } else if ((s[i] != u'(')) {
        Code01_BasicCalculatorIII::push(numbers, ops, cur, s[(i++)]);
        (cur = 0);
      } else {
        (cur = Code01_BasicCalculatorIII::f(s, (i + 1)));
        (i = (where + 1));
      }
    }
    Code01_BasicCalculatorIII::push(numbers, ops, cur, u'+');
    (where = i);
    return Code01_BasicCalculatorIII::compute(numbers, ops);
  }
  static void push(JList<int> numbers, JList<jchar> ops, int cur, jchar op) {
    int n = numbers.size();
    if ((((n == 0) || (ops.get((n - 1)) == u'+')) ||
         (ops.get((n - 1)) == u'-'))) {
      numbers.add(cur);
      ops.add(op);
    } else {
      int topNumber = numbers.get((n - 1));
      jchar topOp = ops.get((n - 1));
      if ((topOp == u'*')) {
        numbers.set((n - 1), (topNumber * cur));
      } else {
        numbers.set((n - 1), jdiv(topNumber, cur));
      }
      ops.set((n - 1), op);
    }
  }
  static int compute(JList<int> numbers, JList<jchar> ops) {
    int n = numbers.size();
    int ans = numbers.get(0);
    for (int i = 1; (i < n); (i++)) {
      (ans += ((ops.get((i - 1)) == u'+') ? unbox(numbers.get(i))
                                          : unbox((-numbers.get(i)))));
    }
    return ans;
  }
};

/* Original teaching comments:
// 含有嵌套的表达式求值
// 力扣上本题为会员题，所以额外提供了牛客网的测试链接
// 如果在牛客网上提交，请将函数名从calculate改为solve
// 测试链接 : https://leetcode.cn/problems/basic-calculator-iii/
// 测试链接 : https://www.nowcoder.com/practice/c215ba61c8b1443b996351df929dc4d4
        // s[i....]开始计算，遇到字符串终止 或者 遇到)停止
        // 返回 : 自己负责的这一段，计算的结果
        // 返回之间，更新全局变量where，为了上游函数知道从哪继续！
                                // 遇到了运算符 + - * /
                                // i (.....)
                                // 遇到了左括号！
*/

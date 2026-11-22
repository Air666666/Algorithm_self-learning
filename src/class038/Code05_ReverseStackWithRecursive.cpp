// Source: src/class038/Code05_ReverseStackWithRecursive.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code05_ReverseStackWithRecursive {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code05_ReverseStackWithRecursive() {}
  static void reverse(JList<int> stack) {
    if (stack.isEmpty()) {
      return;
    }
    int num = Code05_ReverseStackWithRecursive::bottomOut(stack);
    Code05_ReverseStackWithRecursive::reverse(stack);
    stack.push(num);
  }
  static int bottomOut(JList<int> stack) {
    int ans = stack.pop();
    if (stack.isEmpty()) {
      return ans;
    } else {
      int last = Code05_ReverseStackWithRecursive::bottomOut(stack);
      stack.push(ans);
      return last;
    }
  }
  static void java_main(Array<String> args) {
    JList<int> stack = JList<int>();
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    Code05_ReverseStackWithRecursive::reverse(stack);
    while ((!stack.isEmpty())) {
      jout.println(stack.pop());
    }
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code05_ReverseStackWithRecursive::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 用递归函数逆序栈
        // 栈底元素移除掉，上面的元素盖下来
        // 返回移除掉的栈底元素
*/

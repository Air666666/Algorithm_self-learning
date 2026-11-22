// Source: src/class038/Code06_SortStackWithRecursive.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code06_SortStackWithRecursive {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code06_SortStackWithRecursive() {}
  static void sort(JList<int> stack) {
    int deep = Code06_SortStackWithRecursive::deep(stack);
    while ((deep > 0)) {
      int max = Code06_SortStackWithRecursive::max(stack, deep);
      int k = Code06_SortStackWithRecursive::times(stack, deep, max);
      Code06_SortStackWithRecursive::down(stack, deep, max, k);
      (deep -= k);
    }
  }
  static int deep(JList<int> stack) {
    if (stack.isEmpty()) {
      return 0;
    }
    int num = stack.pop();
    int deep = (Code06_SortStackWithRecursive::deep(stack) + 1);
    stack.push(num);
    return deep;
  }
  static int max(JList<int> stack, int deep) {
    if ((deep == 0)) {
      return std::numeric_limits<int>::min();
    }
    int num = stack.pop();
    int restMax = Code06_SortStackWithRecursive::max(stack, (deep - 1));
    int max = jmax(num, restMax);
    stack.push(num);
    return max;
  }
  static int times(JList<int> stack, int deep, int max) {
    if ((deep == 0)) {
      return 0;
    }
    int num = stack.pop();
    int restTimes =
        Code06_SortStackWithRecursive::times(stack, (deep - 1), max);
    int times = (restTimes + ((num == max) ? 1 : 0));
    stack.push(num);
    return times;
  }
  static void down(JList<int> stack, int deep, int max, int k) {
    if ((deep == 0)) {
      for (int i = 0; (i < k); (i++)) {
        stack.push(max);
      }
    } else {
      int num = stack.pop();
      Code06_SortStackWithRecursive::down(stack, (deep - 1), max, k);
      if ((num != max)) {
        stack.push(num);
      }
    }
  }
  static JList<int> randomStack(int n, int v) {
    JList<int> ans = JList<int>();
    for (int i = 0; (i < n); (i++)) {
      ans.add(static_cast<int>((j::random() * v)));
    }
    return ans;
  }
  static bool isSorted(JList<int> stack) {
    int step = std::numeric_limits<int>::min();
    while ((!stack.isEmpty())) {
      if ((step > stack.peek())) {
        return false;
      }
      (step = stack.pop());
    }
    return true;
  }
  static void java_main(Array<String> args) {
    JList<int> test = JList<int>();
    test.add(1);
    test.add(5);
    test.add(4);
    test.add(5);
    test.add(3);
    test.add(2);
    test.add(3);
    test.add(1);
    test.add(4);
    test.add(2);
    Code06_SortStackWithRecursive::sort(test);
    while ((!test.isEmpty())) {
      jout.println(test.pop());
    }
    int N = 20;
    int V = 20;
    int testTimes = 20000;
    jout.println(String(u"测试开始"));
    for (int i = 0; (i < testTimes); (i++)) {
      int n = static_cast<int>((j::random() * N));
      JList<int> stack = Code06_SortStackWithRecursive::randomStack(n, V);
      Code06_SortStackWithRecursive::sort(stack);
      if ((!Code06_SortStackWithRecursive::isSorted(stack))) {
        jout.println(String(u"出错了!"));
        break;
      }
    }
    jout.println(String(u"测试结束"));
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code06_SortStackWithRecursive::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 用递归函数排序栈
// 栈只提供push、pop、isEmpty三个方法
// 请完成无序栈的排序，要求排完序之后，从栈顶到栈底从小到大
// 只能使用栈提供的push、pop、isEmpty三个方法、以及递归函数
// 除此之外不能使用任何的容器，数组也不行
// 就是排序过程中只能用：
// 1) 栈提供的push、pop、isEmpty三个方法
// 2) 递归函数，并且返回值最多为单个整数
        // 返回栈的深度
        // 不改变栈的数据状况
        // 从栈当前的顶部开始，往下数deep层
        // 返回这deep层里的最大值
        // 从栈当前的顶部开始，往下数deep层，已知最大值是max了
        // 返回，max出现了几次，不改变栈的数据状况
        // 从栈当前的顶部开始，往下数deep层，已知最大值是max，出现了k次
        // 请把这k个最大值沉底，剩下的数据状况不变
        // 为了测试
        // 生成随机栈
        // 为了测试
        // 检测栈是不是从顶到底依次有序
        // 为了测试
                // 随机测试
*/

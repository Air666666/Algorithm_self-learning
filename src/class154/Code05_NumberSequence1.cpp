// Source: src/class154/Code05_NumberSequence1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code05_NumberSequence1 {
  inline static int MAXN = 1000001;
  inline static int n = {};
  inline static Array<i64> arr = make_array<i64>(MAXN);
  inline static Array<int> left = make_array<int>(MAXN);
  inline static Array<int> right = make_array<int>(MAXN);
  inline static Array<int> dist = make_array<int>(MAXN);
  inline static Array<int> father = make_array<int>(MAXN);
  inline static Array<int> from = make_array<int>(MAXN);
  inline static Array<int> to = make_array<int>(MAXN);
  inline static Array<int> size = make_array<int>(MAXN);
  inline static Array<int> stack = make_array<int>(MAXN);
  inline static Array<i64> ans = make_array<i64>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code05_NumberSequence1() {}
  static void prepare() {
    (dist[0] = (-1));
    for (int i = 1; (i <= n); (i++)) {
      (left[i] = (right[i] = (dist[i] = 0)));
      (father[i] = (from[i] = (to[i] = i)));
      (size[i] = 1);
    }
  }
  static int find(int i) {
    (father[i] =
         ((father[i] == i) ? i : Code05_NumberSequence1::find(father[i])));
    return father[i];
  }
  static int merge(int i, int j) {
    if (((i == 0) || (j == 0))) {
      return (i + j);
    }
    int tmp = {};
    if ((arr[i] < arr[j])) {
      (tmp = i);
      (i = j);
      (j = tmp);
    }
    (right[i] = Code05_NumberSequence1::merge(right[i], j));
    if ((dist[left[i]] < dist[right[i]])) {
      (tmp = left[i]);
      (left[i] = right[i]);
      (right[i] = tmp);
    }
    (dist[i] = (dist[right[i]] + 1));
    (father[left[i]] = (father[right[i]] = i));
    return i;
  }
  static int pop(int i) {
    (father[left[i]] = left[i]);
    (father[right[i]] = right[i]);
    (father[i] = Code05_NumberSequence1::merge(left[i], right[i]));
    (left[i] = (right[i] = (dist[i] = 0)));
    return father[i];
  }
  static i64 compute() {
    int stackSize = 0;
    {
      int i = 1;
      int pre = {};
      int cur = {};
      int s = {};
      for (; (i <= n); (i++)) {
        while ((stackSize > 0)) {
          (pre = Code05_NumberSequence1::find(stack[stackSize]));
          (cur = Code05_NumberSequence1::find(i));
          if ((arr[pre] <= arr[cur])) {
            break;
          }
          (s = (size[pre] + size[cur]));
          (cur = Code05_NumberSequence1::merge(pre, cur));
          while ((s > jdiv((((i - from[pre]) + 1) + 1), 2))) {
            (cur = Code05_NumberSequence1::pop(cur));
            (s--);
          }
          (from[cur] = from[pre]);
          (to[cur] = i);
          (size[cur] = s);
          (stackSize--);
        }
        (stack[(++stackSize)] = i);
      }
    }
    i64 sum = 0;
    {
      int i = 1;
      int cur = {};
      for (; (i <= stackSize); (i++)) {
        (cur = Code05_NumberSequence1::find(stack[i]));
        for (int j = from[cur]; (j <= to[cur]); (j++)) {
          (ans[j] = arr[cur]);
          (sum += std::abs((ans[j] - arr[j])));
        }
      }
    }
    return sum;
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(jout);
    (n = in.readInt());
    Code05_NumberSequence1::prepare();
    for (int i = 1; (i <= n); (i++)) {
      (arr[i] = (in.readLong() - i));
    }
    out.println(Code05_NumberSequence1::compute());
    for (int i = 1; (i <= n); (i++)) {
      out.write((ans[i] + i));
      out.write(String(u" "));
    }
    out.writeln();
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code05_NumberSequence1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 数字序列，java版
// 给定一个长度为n的数组A，要求构造出一个长度为n的递增数组B
// 希望 |A[1] - B[1]| + |A[2] - B[2]| + ... + |A[n] - B[n]| 最小
// 打印这个最小值，然后打印数组B，如果有多个方案，只打印其中的一个
// 1 <= n <= 10^6
// 0 <= A[i] <= 2^32 - 1
// 测试链接 : https://www.luogu.com.cn/problem/P4331
// 提交以下的code，提交时请把类名改成"Main"，一些测试用例通过不了，空间超了
// 这是洛谷平台没有考虑其他语言导致的，同样的逻辑，C++实现就能完全通过
// C++实现的版本，就是Code05_NumberSequence2文件
        // 左偏树需要
        // 并查集向上的路径
        // 集合表达区域的左下标
        // 集合表达区域的右下标
        // 集合里有几个数字
        // 单调栈
        // 构造的数组
                // 维护大根堆
                                // 大根堆只保留到上中位数
        // 快读
        // 快写
*/

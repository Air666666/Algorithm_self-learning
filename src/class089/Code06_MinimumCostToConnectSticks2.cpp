// Source: src/class089/Code06_MinimumCostToConnectSticks2.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code06_MinimumCostToConnectSticks2 {
  inline static int MAXN = 10001;
  inline static Array<int> nums = make_array<int>(MAXN);
  inline static int n = {};
  inline static Array<int> heap = make_array<int>(MAXN);
  inline static int size = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code06_MinimumCostToConnectSticks2() {}
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    while ((in.nextToken() != -1)) {
      (n = static_cast<int>(in.nval));
      for (int i = 0; (i < n); (i++)) {
        in.nextToken();
        (nums[i] = static_cast<int>(in.nval));
      }
      out.println(Code06_MinimumCostToConnectSticks2::minCost());
      out.flush();
    }
    out.flush();
    out.close();
    br.close();
  }
  static int minCost() {
    (size = 0);
    for (int i = 0; (i < n); (i++)) {
      Code06_MinimumCostToConnectSticks2::add(nums[i]);
    }
    int sum = 0;
    int cur = 0;
    while ((size > 1)) {
      (cur = [&]() {
        auto jleft = Code06_MinimumCostToConnectSticks2::pop();
        auto jright = Code06_MinimumCostToConnectSticks2::pop();
        return (jleft + jright);
      }());
      (sum += cur);
      Code06_MinimumCostToConnectSticks2::add(cur);
    }
    return sum;
  }
  static void add(int x) {
    (heap[size] = x);
    int i = (size++);
    while ((heap[i] < heap[jdiv((i - 1), 2)])) {
      Code06_MinimumCostToConnectSticks2::swap(i, jdiv((i - 1), 2));
      (i = jdiv((i - 1), 2));
    }
  }
  static int pop() {
    int ans = heap[0];
    Code06_MinimumCostToConnectSticks2::swap(0, (--size));
    int i = 0;
    int l = 1;
    int best = {};
    while ((l < size)) {
      (best = ((((l + 1) < size) && (heap[(l + 1)] < heap[l])) ? (l + 1) : l));
      (best = ((heap[best] < heap[i]) ? best : i));
      if ((best == i)) {
        break;
      }
      Code06_MinimumCostToConnectSticks2::swap(i, best);
      (i = best);
      (l = ((i * 2) + 1));
    }
    return ans;
  }
  static void swap(int i, int j) {
    int tmp = heap[i];
    (heap[i] = heap[j]);
    (heap[j] = tmp);
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code06_MinimumCostToConnectSticks2::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 连接棒材的最低费用(洛谷测试)
// 你有一些长度为正整数的棍子
// 这些长度以数组sticks的形式给出
// sticks[i]是第i个木棍的长度
// 你可以通过支付x+y的成本将任意两个长度为x和y的棍子连接成一个棍子
// 你必须连接所有的棍子，直到剩下一个棍子
// 返回以这种方式将所有给定的棍子连接成一个棍子的最小成本
// 测试链接 : https://www.luogu.com.cn/problem/P1090
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下的code，提交时请把类名改成"Main"，可以直接通过
        // 手写小根堆
        // 堆的大小
*/

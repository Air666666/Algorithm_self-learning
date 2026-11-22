// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P5854

// Source: src/class151/Code01_DescartesTree1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_DescartesTree1 {
  inline static int MAXN = 10000001;
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static Array<int> left = make_array<int>(MAXN);
  inline static Array<int> right = make_array<int>(MAXN);
  inline static Array<int> stack = make_array<int>(MAXN);
  inline static int n = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_DescartesTree1() {}
  static void build() {
    {
      int i = 1;
      int top = 0;
      int pos = 0;
      for (; (i <= n); (i++)) {
        (pos = top);
        while (((pos > 0) && (arr[stack[pos]] > arr[i]))) {
          (pos--);
        }
        if ((pos > 0)) {
          (right[stack[pos]] = i);
        }
        if ((pos < top)) {
          (left[i] = stack[(pos + 1)]);
        }
        (stack[(++pos)] = i);
        (top = pos);
      }
    }
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    (n = static_cast<int>(in.nval));
    for (int i = 1; (i <= n); (i++)) {
      in.nextToken();
      (arr[i] = static_cast<int>(in.nval));
    }
    Code01_DescartesTree1::build();
    i64 ans1 = 0;
    i64 ans2 = 0;
    for (int i = 1; (i <= n); (i++)) {
      (ans1 ^= (static_cast<i64>(i) * (left[i] + 1)));
      (ans2 ^= (static_cast<i64>(i) * (right[i] + 1)));
    }
    out.println(((ans1 + String(u" ")) + ans2));
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code01_DescartesTree1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 笛卡尔树模版(java版)
// 给定一个长度为n的数组arr，下标从1开始
// 构建一棵二叉树，下标按照搜索二叉树组织，值按照小根堆组织
// 建树的过程要求时间复杂度O(n)
// 建树之后，为了验证
// 打印，i * (left[i] + 1)，所有信息异或起来的值
// 打印，i * (right[i] + 1)，所有信息异或起来的值
// 1 <= n <= 10^7
// 测试链接 : https://www.luogu.com.cn/problem/P5854
// 如下实现是正确的，但java的版本无法通过所有测试用例
// 这是洛谷平台没有照顾各种语言的实现所导致的
// C++版本是Code01_DescartesTree2文件
// C++版本和java版本逻辑完全一样，可以通过所有测试用例
// 在真正笔试、比赛时，一定是兼顾各种语言的，该实现是一定正确的
*/

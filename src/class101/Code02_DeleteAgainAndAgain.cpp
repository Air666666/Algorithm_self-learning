// Source: src/class101/Code02_DeleteAgainAndAgain.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_DeleteAgainAndAgain {
  inline static Array<jchar> s1 = {};
  inline static Array<jchar> s2 = {};
  inline static int MAXN = 1000001;
  inline static Array<int> next = make_array<int>(MAXN);
  inline static Array<int> stack1 = make_array<int>(MAXN);
  inline static Array<int> stack2 = make_array<int>(MAXN);
  inline static int size = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_DeleteAgainAndAgain() {}
  static void java_main(Array<String> args) {
    IO in = IO(IO(jin));
    IO out = IO(IO(jout));
    (s1 = in.readLine().toCharArray());
    (s2 = in.readLine().toCharArray());
    Code02_DeleteAgainAndAgain::compute();
    for (int i = 0; (i < size); (i++)) {
      out.print(s1[stack1[i]]);
    }
    out.println();
    out.flush();
    out.close();
    in.close();
  }
  static void compute() {
    (size = 0);
    int n = s1.length;
    int m = s2.length;
    int x = 0;
    int y = 0;
    Code02_DeleteAgainAndAgain::nextArray(m);
    while ((x < n)) {
      if ((s1[x] == s2[y])) {
        (stack1[size] = x);
        (stack2[size] = y);
        (size++);
        (x++);
        (y++);
      } else if ((y == 0)) {
        (stack1[size] = x);
        (stack2[size] = (-1));
        (size++);
        (x++);
      } else {
        (y = next[y]);
      }
      if ((y == m)) {
        (size -= m);
        (y = ((size > 0) ? (stack2[(size - 1)] + 1) : 0));
      }
    }
  }
  static void nextArray(int m) {
    (next[0] = (-1));
    (next[1] = 0);
    int i = 2;
    int cn = 0;
    while ((i < m)) {
      if ((s2[(i - 1)] == s2[cn])) {
        (next[(i++)] = (++cn));
      } else if ((cn > 0)) {
        (cn = next[cn]);
      } else {
        (next[(i++)] = 0);
      }
    }
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code02_DeleteAgainAndAgain::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 不停删除之后剩下的字符串
// 给定一个字符串s1，如果其中含有s2字符串，就删除最左出现的那个
// 删除之后s1剩下的字符重新拼接在一起，再删除最左出现的那个
// 如此周而复始，返回最终剩下的字符串
// 测试链接 : https://www.luogu.com.cn/problem/P4824
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下的code，提交时请把类名改成"Main"，可以直接通过
                                // 相当于栈直接弹出了m条记录
*/

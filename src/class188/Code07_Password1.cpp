// 原题测试 / 参考链接（保留上游原始地址）
// http://poj.org/problem?id=1780

// Source: src/class188/Code07_Password1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code07_Password1 {
  inline static int MAXN = 1000002;
  inline static int n = {};
  inline static int k = {};
  inline static int m = {};
  inline static Array<int> cur = make_array<int>(MAXN);
  inline static Array<int> path = make_array<int>(MAXN);
  inline static int cntp = {};
  inline static Array<Array<int>> sta = make_array<int>(MAXN, 2);
  inline static int u = {};
  inline static int e = {};
  inline static int stacksize = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code07_Password1() {}
  static void push(int u, int e) {
    (sta[stacksize][0] = u);
    (sta[stacksize][1] = e);
    (stacksize++);
  }
  static void pop() {
    (stacksize--);
    (u = sta[stacksize][0]);
    (e = sta[stacksize][1]);
  }
  static void prepare(int len, int num) {
    (n = len);
    (k = num);
    (m = 1);
    for (int i = 1; (i <= (n - 1)); (i++)) {
      (m *= k);
    }
    for (int i = 0; (i < m); (i++)) {
      (cur[i] = 0);
    }
    (cntp = 0);
  }
  static void euler(int node, int edge) {
    (stacksize = 0);
    Code07_Password1::push(node, edge);
    while ((stacksize > 0)) {
      Code07_Password1::pop();
      if ((cur[u] < k)) {
        int ne = (cur[u]++);
        Code07_Password1::push(u, e);
        Code07_Password1::push(jrem(((u * k) + ne), m), ne);
      } else {
        (path[(++cntp)] = e);
      }
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    int len = in.nextInt();
    int num = 10;
    while ((len != 0)) {
      Code07_Password1::prepare(len, num);
      Code07_Password1::euler(0, (-1));
      for (int i = 1; (i <= (n - 1)); (i++)) {
        out.print(String(u"0"));
      }
      for (int i = (cntp - 1); (i >= 1); (i--)) {
        out.print(path[i]);
      }
      out.println();
      (len = in.nextInt());
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code07_Password1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 所有可能的密码串，java版
// 给定正数n，表示密码有n位，每一位可能的数字是[0..9]
// 密码有(10^n)个可能性，构造一个字符串，其中的连续子串包含所有可能的密码
// 先保证字符串的长度最短，然后保证字典序尽量的小，返回这个字符串
// 1 <= n <= 6
// 测试链接 : http://poj.org/problem?id=1780
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 本题的递归深度很大，递归版会爆栈，java和C++都只有迭代版可以通过
        // 读写工具类
*/

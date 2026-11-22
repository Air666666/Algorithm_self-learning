// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P10950
// https://loj.ac/p/10110

// Source: src/class188/Code08_Taiko1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code08_Taiko1 {
  inline static int MAXN = 3001;
  inline static int n = {};
  inline static int k = {};
  inline static int m = {};
  inline static Array<int> cur = make_array<int>(MAXN);
  inline static Array<int> path = make_array<int>(MAXN);
  inline static int cntp = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code08_Taiko1() {}
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
  static void euler(int u, int e) {
    while ((cur[u] < k)) {
      int ne = (cur[u]++);
      Code08_Taiko1::euler(jrem(((u * k) + ne), m), ne);
    }
    (path[(++cntp)] = e);
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    int len = in.nextInt();
    int num = 2;
    Code08_Taiko1::prepare(len, num);
    Code08_Taiko1::euler(0, (-1));
    out.print(((m * k) + String(u" ")));
    for (int i = 1; (i <= (n - 1)); (i++)) {
      out.print(String(u"0"));
    }
    for (int i = (cntp - 1); (i >= n); (i--)) {
      out.print(path[i]);
    }
    out.println();
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code08_Taiko1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 太鼓达人，java版
// 给定一个正数n，所有长度为n的二进制状态一共有(2^n)个
// 构造一个字符串，字符串可以循环使用，其中的连续子串包含所有二进制状态
// 求出字符串的最小长度值，并且给出字典序最小的方案
// 比如n=3，字符串最小长度值为8，字典序最小的方案为00010111
// 注意到 000、001、010、101、011、111、110、100 都已包含
// 注意到 最后两个二进制状态 是字符串循环使用构造出来的
// 1 <= n <= 11
// 本题可以推广到k进制，代码就是按照推广来实现的
// 测试链接 : https://www.luogu.com.cn/problem/P10950
// 测试链接 : https://loj.ac/p/10110
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 读写工具类
*/

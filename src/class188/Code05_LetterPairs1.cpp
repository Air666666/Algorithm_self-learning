// Source: src/class188/Code05_LetterPairs1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code05_LetterPairs1 {
  inline static int MAXN = 53;
  inline static int MAXM = 2001;
  inline static int n = 52;
  inline static int m = {};
  inline static Array<Array<jchar>> arr = make_array<jchar>(MAXM, 2);
  inline static Array<Array<int>> graph = make_array<int>(MAXN, MAXN);
  inline static Array<int> deg = make_array<int>(MAXN);
  inline static Array<int> cur = make_array<int>(MAXN);
  inline static Array<int> path = make_array<int>(MAXM);
  inline static int cntp = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code05_LetterPairs1() {}
  static int getInt(jchar c) {
    return ((c <= u'Z') ? ((c - u'A') + 1) : ((c - u'a') + 27));
  }
  static jchar getChar(int v) {
    return static_cast<jchar>(
        ((v <= 26) ? ((u'A' + v) - 1) : ((u'a' + v) - 27)));
  }
  static void connect() {
    {
      int i = 1;
      int u = {};
      int v = {};
      for (; (i <= m); (i++)) {
        (u = Code05_LetterPairs1::getInt(arr[i][0]));
        (v = Code05_LetterPairs1::getInt(arr[i][1]));
        (graph[u][v]++);
        (graph[v][u]++);
        (deg[u]++);
        (deg[v]++);
      }
    }
    for (int i = 1; (i <= n); (i++)) {
      (cur[i] = 1);
    }
  }
  static int undirectedStart() {
    int odd = 0;
    for (int i = 1; (i <= n); (i++)) {
      if (((deg[i] & 1) == 1)) {
        (odd++);
      }
    }
    if (((odd != 0) && (odd != 2))) {
      return (-1);
    }
    for (int i = 1; (i <= n); (i++)) {
      if (((odd == 0) && (deg[i] > 0))) {
        return i;
      }
      if (((odd == 2) && ((deg[i] & 1) == 1))) {
        return i;
      }
    }
    return (-1);
  }
  static void euler(int u) {
    for (int v = cur[u]; (v <= n); (v = cur[u])) {
      (cur[u]++);
      if ((graph[u][v] > 0)) {
        (graph[u][v]--);
        (graph[v][u]--);
        Code05_LetterPairs1::euler(v);
      }
    }
    (path[(++cntp)] = u);
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (m = in.nextInt());
    for (int i = 1; (i <= m); (i++)) {
      (arr[i][0] = in.nextChar());
      (arr[i][1] = in.nextChar());
    }
    Code05_LetterPairs1::connect();
    int start = Code05_LetterPairs1::undirectedStart();
    if ((start == (-1))) {
      out.println(String(u"No Solution"));
    } else {
      Code05_LetterPairs1::euler(start);
      if ((cntp != (m + 1))) {
        out.println(String(u"No Solution"));
      } else {
        for (int i = cntp; (i >= 1); (i--)) {
          out.print(Code05_LetterPairs1::getChar(path[i]));
        }
        out.println();
      }
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code05_LetterPairs1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 无序字母对，java版
// 给定n个字母对，每个字母对有两个字母，字母只可能是A~Z、a~z
// 字母对内部不区分顺序，ab和ba是相同的，但是区分大小写，Ab和ab是不同的
// 题目不会给定重复的字母对，构造一个长度n+1的字符串，让每个字母对都出现
// 一个字母对的两个字母，在字符串中相邻出现即可，请输出字典序最小的方案
// 如果没有满足要求的方案，打印"No Solution"
// 1 <= n <= 1326
// 测试链接 : https://www.luogu.com.cn/problem/P1341
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 读写工具类
*/

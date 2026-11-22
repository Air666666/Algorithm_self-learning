// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P1127

// Source: src/class188/Code04_WordChain1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_WordChain1 {
  struct EdgeCmp;
  struct EdgeCmp {
    String toString() const { return j::str(static_cast<const void *>(this)); }
    EdgeCmp() {}
    int compare(Box<int> i, Box<int> j) {
      if ((a[i] != a[j])) {
        return (a[i] - a[j]);
      }
      return str[i].compareTo(str[j]);
    }
  };
  inline static int MAXN = 27;
  inline static int MAXM = 1002;
  inline static int n = 26;
  inline static int m = {};
  inline static Array<String> str = make_array<String>(MAXM);
  inline static Array<int> a = make_array<int>(MAXM);
  inline static Array<int> b = make_array<int>(MAXM);
  inline static Array<Box<int>> eidArr = make_array<Box<int>>(MAXM);
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> nxt = make_array<int>(MAXM);
  inline static Array<int> to = make_array<int>(MAXM);
  inline static Array<String> weight = make_array<String>(MAXM);
  inline static int cntg = {};
  inline static Array<int> cur = make_array<int>(MAXN);
  inline static Array<int> outDeg = make_array<int>(MAXN);
  inline static Array<int> inDeg = make_array<int>(MAXN);
  inline static Array<String> path = make_array<String>(MAXM);
  inline static int cntp = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_WordChain1() {}
  static void addEdge(int u, int v, String w) {
    (nxt[(++cntg)] = head[u]);
    (to[cntg] = v);
    (weight[cntg] = w);
    (head[u] = cntg);
  }
  static int startNode(String str) { return ((str.charAt(0) - u'a') + 1); }
  static int endNode(String str) {
    return ((str.charAt((str.length() - 1)) - u'a') + 1);
  }
  static void connect() {
    j::sort(eidArr, 1, (m + 1), new EdgeCmp());
    {
      int l = 1;
      int r = 1;
      for (; (l <= m); (l = (++r))) {
        while ((((r + 1) <= m) && (a[eidArr[l]] == a[eidArr[(r + 1)]]))) {
          (r++);
        }
        {
          int i = r;
          int u = {};
          int v = {};
          for (; (i >= l); (i--)) {
            (u = a[eidArr[i]]);
            (v = b[eidArr[i]]);
            (outDeg[u]++);
            (inDeg[v]++);
            Code04_WordChain1::addEdge(u, v, str[eidArr[i]]);
          }
        }
      }
    }
    for (int i = 1; (i <= n); (i++)) {
      (cur[i] = head[i]);
    }
  }
  static int directedStart() {
    int start = (-1);
    int end = (-1);
    for (int i = 1; (i <= n); (i++)) {
      int v = (outDeg[i] - inDeg[i]);
      if (((((v < (-1)) || (v > 1)) || ((v == 1) && (start != (-1)))) ||
           ((v == (-1)) && (end != (-1))))) {
        return (-1);
      }
      if ((v == 1)) {
        (start = i);
      }
      if ((v == (-1))) {
        (end = i);
      }
    }
    if (((start == (-1)) ^ (end == (-1)))) {
      return (-1);
    }
    if ((start != (-1))) {
      return start;
    }
    for (int i = 1; (i <= n); (i++)) {
      if ((outDeg[i] > 0)) {
        return i;
      }
    }
    return (-1);
  }
  static void euler(int u, String w) {
    for (int e = cur[u]; (e > 0); (e = cur[u])) {
      (cur[u] = nxt[e]);
      Code04_WordChain1::euler(to[e], weight[e]);
    }
    (path[(++cntp)] = w);
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (m = in.nextInt());
    for (int i = 1; (i <= m); (i++)) {
      (str[i] = in.nextString());
      (a[i] = Code04_WordChain1::startNode(str[i]));
      (b[i] = Code04_WordChain1::endNode(str[i]));
      (eidArr[i] = i);
    }
    Code04_WordChain1::connect();
    int start = Code04_WordChain1::directedStart();
    if ((start == (-1))) {
      out.println(String(u"***"));
    } else {
      Code04_WordChain1::euler(start, String(u""));
      if ((cntp != (m + 1))) {
        out.println(String(u"***"));
      } else {
        out.print(path[(cntp - 1)]);
        for (int i = (cntp - 2); (i >= 1); (i--)) {
          out.print((String(u".") + path[i]));
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
  Code04_WordChain1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 词链，java版
// 给定n个由小写字母组成的单词，想把所有单词串成一个词链
// 同时要求前一个单词的结尾字符 == 后一个单词的开头字符
// 比如词链，aloha.arachnid.dog.gopher.rat.tiger
// 需要使用每个输入的单词恰好一次，同一单词出现k次就要用k次
// 返回字典序最小的结果，注意 . 的字典序 < 小写字母的字典序
// 如果不存在合法词链，输出***
// 1 <= n <= 1000
// 测试链接 : https://www.luogu.com.cn/problem/P1127
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 读写工具类
*/

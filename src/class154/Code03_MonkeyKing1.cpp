// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P1456

// Source: src/class154/Code03_MonkeyKing1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_MonkeyKing1 {
  inline static int MAXN = 100001;
  inline static int n = {};
  inline static int m = {};
  inline static Array<int> num = make_array<int>(MAXN);
  inline static Array<int> left = make_array<int>(MAXN);
  inline static Array<int> right = make_array<int>(MAXN);
  inline static Array<int> dist = make_array<int>(MAXN);
  inline static Array<int> father = make_array<int>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_MonkeyKing1() {}
  static void prepare() {
    (dist[0] = (-1));
    for (int i = 1; (i <= n); (i++)) {
      (left[i] = (right[i] = (dist[i] = 0)));
      (father[i] = i);
    }
  }
  static int find(int i) {
    (father[i] = ((father[i] == i) ? i : Code03_MonkeyKing1::find(father[i])));
    return father[i];
  }
  static int merge(int i, int j) {
    if (((i == 0) || (j == 0))) {
      return (i + j);
    }
    int tmp = {};
    if ((num[i] < num[j])) {
      (tmp = i);
      (i = j);
      (j = tmp);
    }
    (right[i] = Code03_MonkeyKing1::merge(right[i], j));
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
    (father[i] = Code03_MonkeyKing1::merge(left[i], right[i]));
    (left[i] = (right[i] = (dist[i] = 0)));
    return father[i];
  }
  static int fight(int x, int y) {
    int a = Code03_MonkeyKing1::find(x);
    int b = Code03_MonkeyKing1::find(y);
    if ((a == b)) {
      return (-1);
    }
    int l = Code03_MonkeyKing1::pop(a);
    int r = Code03_MonkeyKing1::pop(b);
    (num[a] /= 2);
    (num[b] /= 2);
    (father[a] =
         (father[b] = (father[l] = (father[r] = [&]() {
                         auto jargument_0 = Code03_MonkeyKing1::merge(l, a);
                         auto jargument_1 = Code03_MonkeyKing1::merge(r, b);
                         return Code03_MonkeyKing1::merge(jargument_0,
                                                          jargument_1);
                       }()))));
    return num[father[a]];
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    while ((in.nextToken() != -1)) {
      (n = static_cast<int>(in.nval));
      Code03_MonkeyKing1::prepare();
      for (int i = 1; (i <= n); (i++)) {
        in.nextToken();
        (num[i] = static_cast<int>(in.nval));
      }
      in.nextToken();
      (m = static_cast<int>(in.nval));
      {
        int i = 1;
        int x = {};
        int y = {};
        for (; (i <= m); (i++)) {
          in.nextToken();
          (x = static_cast<int>(in.nval));
          in.nextToken();
          (y = static_cast<int>(in.nval));
          out.println(Code03_MonkeyKing1::fight(x, y));
        }
      }
    }
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code03_MonkeyKing1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 猴王，java版
// 给定n只猴子的战斗力，一开始每个猴子都是独立的阵营
// 一共有m次冲突，每次冲突给定两只猴子的编号x、y
// 如果x和y在同一阵营，这次冲突停止，打印-1
// 如果x和y在不同阵营，x所在阵营的最强猴子会和y所在阵营的最强猴子进行打斗
//
打斗的结果是，两个各自阵营的最强猴子，战斗力都减半，向下取整，其他猴子战力不变
// 然后两个阵营合并，打印合并后的阵营最大战斗力
// 题目可能有多组数据，需要监控输入流直到结束
// 1 <= n, m <= 10^5
// 0 <= 猴子战斗力 <= 32768
// 测试链接 : https://www.luogu.com.cn/problem/P1456
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
                // 维护大根堆
*/

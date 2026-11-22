// Source: src/class143/Code03_SmallMultiple.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_SmallMultiple {
  inline static int MAXK = 100001;
  inline static int k = {};
  inline static JDeque<Array<int>> deque = JDeque<Array<int>>();
  inline static Array<bool> visit = make_array<bool>(MAXK);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_SmallMultiple() {}
  static int bfs() {
    deque.clear();
    deque.add(Array<int>{1, 1});
    Array<int> cur = {};
    int mod = {};
    int cost = {};
    while ((!deque.isEmpty())) {
      (cur = deque.pollFirst());
      (mod = cur[0]);
      (cost = cur[1]);
      if ((!visit[mod])) {
        (visit[mod] = true);
        if ((mod == 0)) {
          return cost;
        }
        deque.addFirst(Array<int>{jrem((mod * 10), k), cost});
        deque.addLast(Array<int>{jrem((mod + 1), k), (cost + 1)});
      }
    }
    return (-1);
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    (k = static_cast<int>(in.nval));
    out.println(Code03_SmallMultiple::bfs());
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code03_SmallMultiple::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 正整数倍的最小数位和
// 给定一个整数k，求一个k的正整数倍s，使得在十进制下，s的数位累加和最小
// 2 <= k <= 10^5
// 测试链接 : https://www.luogu.com.cn/problem/AT_arc084_b
// 测试链接 : https://atcoder.jp/contests/abc077/tasks/arc084_b
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 01bfs需要
        // 来自讲解062，01bfs
*/

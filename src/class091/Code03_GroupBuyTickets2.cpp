// Source: src/class091/Code03_GroupBuyTickets2.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_GroupBuyTickets2 {
  struct Game;
  struct Game {
    i64 ki = {};
    i64 bi = {};
    int people = {};
    String toString() const { return j::str(static_cast<const void *>(this)); }
    Game(i64 k, i64 b) {
      (ki = k);
      (bi = b);
    }
    i64 earn() {
      return [&]() {
        auto jleft = Game::cost((people + 1));
        auto jright = Game::cost(people);
        return (jleft - jright);
      }();
    }
    i64 cost(i64 p) {
      i64 price = ((ki * p) + bi);
      if ((price < 0)) {
        (price = 0);
      }
      return (p * price);
    }
  };
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_GroupBuyTickets2() {}
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    int n = in.nextInt();
    int m = in.nextInt();
    JHeap<Game *> heap = JHeap<Game *>([=](Game *a, Game *b) {
      return [&]() {
        auto jargument_0 = b->earn();
        auto jargument_1 = a->earn();
        return jcompare(jargument_0, jargument_1);
      }();
    });
    for (int i = 0; (i < m); (i++)) {
      Game *cur = new Game(in.nextLong(), in.nextLong());
      if ((cur->earn() > 0)) {
        heap.add(cur);
      }
    }
    i64 ans = 0;
    for (int i = 0; ((i < n) && (!heap.isEmpty())); (i++)) {
      Game *cur = heap.poll();
      i64 money = cur->earn();
      if ((money <= 0)) {
        break;
      }
      (ans += money);
      (cur->people++);
      if ((cur->earn() > 0)) {
        heap.add(cur);
      }
    }
    out.println(ans);
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code03_GroupBuyTickets2::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 组团买票找到了在线测试
// 逻辑和课上讲的一样，但是测试中设定的ki为负数
// 实现做了一些小优化，具体可以看注释
// 测试链接 : https://www.luogu.com.cn/problem/P12331
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
                        // 初始增费<=0的项目直接忽略
                                // 没有正向增费，那么可以结束了
        // 读写工具类
*/

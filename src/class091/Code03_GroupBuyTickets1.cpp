// Source: src/class091/Code03_GroupBuyTickets1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_GroupBuyTickets1 {
  struct Game;
  struct Game {
    int ki = {};
    int bi = {};
    int people = {};
    String toString() const { return j::str(static_cast<const void *>(this)); }
    Game(int k, int b) {
      (ki = k);
      (bi = b);
      (people = 0);
    }
    int earn() { return ((bi - ((people + 1) * ki)) - (people * ki)); }
  };
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_GroupBuyTickets1() {}
  static int enough1(int n, Array<Array<int>> games) {
    int m = games.length;
    Array<int> cnts = make_array<int>(m);
    return Code03_GroupBuyTickets1::f(0, n, m, games, cnts);
  }
  static int f(int i, int n, int m, Array<Array<int>> games, Array<int> cnts) {
    if ((i == n)) {
      int ans = 0;
      {
        int j = 0;
        int k = {};
        int b = {};
        int x = {};
        for (; (j < m); (j++)) {
          (k = games[j][0]);
          (b = games[j][1]);
          (x = cnts[j]);
          (ans += jmax(((b - (k * x)) * x), 0));
        }
      }
      return ans;
    } else {
      int ans = Code03_GroupBuyTickets1::f((i + 1), n, m, games, cnts);
      for (int j = 0; (j < m); (j++)) {
        (cnts[j]++);
        (ans =
             jmax(ans, Code03_GroupBuyTickets1::f((i + 1), n, m, games, cnts)));
        (cnts[j]--);
      }
      return ans;
    }
  }
  static int enough2(int n, Array<Array<int>> games) {
    JHeap<Game *> heap = JHeap<Game *>([=](Game *a, Game *b) {
      return [&]() {
        auto jleft = b->earn();
        auto jright = a->earn();
        return (jleft - jright);
      }();
    });
    for (Array<int> g : games) {
      heap.add(new Game(g[0], g[1]));
    }
    int ans = 0;
    for (int i = 0; (i < n); (i++)) {
      if ((heap.peek()->earn() <= 0)) {
        break;
      }
      Game *cur = heap.poll();
      (ans += cur->earn());
      (cur->people++);
      heap.add(cur);
    }
    return ans;
  }
  static Array<Array<int>> randomGames(int m, int v) {
    Array<Array<int>> ans = make_array<int>(m, 2);
    for (int i = 0; (i < m); (i++)) {
      (ans[i][0] = (static_cast<int>((j::random() * v)) + 1));
      (ans[i][1] = (static_cast<int>((j::random() * v)) + 1));
    }
    return ans;
  }
  static void java_main(Array<String> args) {
    int N = 8;
    int M = 8;
    int V = 20;
    int testTimes = 2000;
    jout.println(String(u"测试开始"));
    for (int i = 1; (i <= testTimes); (i++)) {
      int n = (static_cast<int>((j::random() * N)) + 1);
      int m = (static_cast<int>((j::random() * M)) + 1);
      Array<Array<int>> games = Code03_GroupBuyTickets1::randomGames(m, V);
      int ans1 = Code03_GroupBuyTickets1::enough1(n, games);
      int ans2 = Code03_GroupBuyTickets1::enough2(n, games);
      if ((ans1 != ans2)) {
        jout.println(String(u"出错了！"));
      }
      if ((jrem(i, 100) == 0)) {
        jout.println(((String(u"测试到第") + i) + String(u"组")));
      }
    }
    jout.println(String(u"测试结束"));
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code03_GroupBuyTickets1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 组团买票
// 景区里一共有m个项目，景区的第i个项目有如下两个参数：
// game[i] = { Ki, Bi }，Ki、Bi一定是正数
// Ki代表折扣系数，Bi代表票价
// 举个例子 : Ki = 2, Bi = 10
// 如果只有1个人买票，单张门票的价格为 : Bi - Ki * 1 = 8
// 所以这1个人游玩该项目要花8元
// 如果有2个人买票，单张门票的价格为 : Bi - Ki * 2 = 6
// 所以这2个人游玩该项目要花6 * 2 = 12元
// 如果有5个人买票，单张门票的价格为 : Bi - Ki * 5 = 0
// 所以这5个人游玩该项目要花5 * 0 = 0元
// 如果有更多人买票，都认为花0元(因为让项目倒贴钱实在是太操蛋了)
// 于是可以认为，如果有x个人买票，单张门票的价格为 : Bi - Ki * x
// x个人游玩这个项目的总花费是 : max { x * (Bi - Ki * x), 0 }
// 单位一共有n个人，每个人最多可以选1个项目来游玩，也可以不选任何项目
// 所有员工将在明晚提交选择，然后由你去按照上面的规则，统一花钱购票
// 你想知道自己需要准备多少钱，就可以应付所有可能的情况，返回这个最保险的钱数
// 数据量描述 :
// 1 <= M、N、Ki、Bi <= 10^5
// 来自真实大厂笔试，没有在线测试，对数器验证
        // 暴力方法
        // 为了验证
        // 每个人做出所有可能的选择
        // 时间复杂度O((m+1)的n次方)
        // 正式方法
        // 时间复杂度O(n * logm)
                // 哪个项目，再来一人挣得最多
                // 大根堆
                        // 一个个的人，依次送到当前最挣钱的项目里去
                // 如果再来一人，这个项目得到多少钱
                        // bi - (people + 1) * ki :
当前的人，门票原价减少了，当前的门票价格
                        // people * ki :
当前人的到来，之前的所有人，门票价格都再减去ki
        // 为了验证
        // 为了验证
*/

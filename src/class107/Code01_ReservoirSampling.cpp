// Source: src/class107/Code01_ReservoirSampling.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_ReservoirSampling {
  struct Pool;
  struct Pool {
    int size = {};
    Array<int> bag = {};
    String toString() const { return j::str(static_cast<const void *>(this)); }
    Pool(int s) {
      (size = s);
      (bag = make_array<int>(s));
    }
    bool pick(int i) { return (static_cast<int>((j::random() * i)) < size); }
    int where() { return static_cast<int>((j::random() * size)); }
    void enter(int i) {
      if ((i <= size)) {
        (bag[(i - 1)] = i);
      } else {
        if (Pool::pick(i)) {
          (bag[Pool::where()] = i);
        }
      }
    }
    Array<int> getBag() { return bag; }
  };
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_ReservoirSampling() {}
  static void java_main(Array<String> args) {
    jout.println(String(u"测试开始"));
    int n = 41;
    int m = 10;
    int testTimes = 10000;
    Array<int> cnt = make_array<int>((n + 1));
    for (int k = 0; (k < testTimes); (k++)) {
      Pool *pool = new Pool(m);
      for (int i = 1; (i <= n); (i++)) {
        pool->enter(i);
      }
      Array<int> bag = pool->getBag();
      for (int num : bag) {
        (cnt[num]++);
      }
    }
    jout.println(((((String(u"机器吐出到") + n) + String(u"号球, ")) +
                   String(u"袋子大小为")) +
                  m));
    jout.println((String(u"每个球被选中的概率应该接近") +
                  jdiv(static_cast<double>(m), n)));
    jout.println(((String(u"一共测试") + testTimes) + String(u"次")));
    for (int i = 1; (i <= n); (i++)) {
      jout.println(((((i + String(u"被选中次数 : ")) + cnt[i]) +
                     String(u", 被选中概率 : ")) +
                    jdiv(static_cast<double>(cnt[i]), testTimes)));
    }
    jout.println(String(u"测试结束"));
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code01_ReservoirSampling::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 蓄水池采样
// 假设有一个不停吐出球的机器，每次吐出1号球、2号球、3号球...
// 有一个袋子只能装下10个球，每次机器吐出的球，要么放入袋子，要么永远扔掉
// 如何做到机器吐出每一个球之后，所有吐出的球都等概率被放进袋子里
                // 是否要i号球
                // size/i的几率决定要
                // 剩下的几率决定不要
                // 袋子里0...size-1个位置
                // 哪个空间的球扔掉，让i号球进来
*/

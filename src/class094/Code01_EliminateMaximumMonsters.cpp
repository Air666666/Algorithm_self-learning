// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/eliminate-maximum-number-of-monsters/

// Source: src/class094/Code01_EliminateMaximumMonsters.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_EliminateMaximumMonsters {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_EliminateMaximumMonsters() {}
  static int eliminateMaximum(Array<int> dist, Array<int> speed) {
    int n = dist.length;
    Array<int> time = make_array<int>(n);
    for (int i = 0; (i < n); (i++)) {
      (time[i] = jdiv(((dist[i] + speed[i]) - 1), speed[i]));
    }
    j::sort(time);
    for (int i = 0; (i < n); (i++)) {
      if ((time[i] <= i)) {
        return i;
      }
    }
    return n;
  }
};

/* Original teaching comments:
// 消灭怪物的最大数量
// 你正在玩一款电子游戏，在游戏中你需要保护城市免受怪物侵袭
// 给定两个大小为n的整数数组dist、speed
// 其中dist[i]是第i个怪物与城市的初始距离
// 其中speed[i]是第i个怪物的速度
//
你有一种武器，一旦充满电，就可以消灭一个怪物，但是，武器需要1的时间才能充电完成
//
武器在游戏开始时是充满电的状态，怪物从0时刻开始移动，一旦任何怪物到达城市，就输掉了这场游戏
// 如果某个怪物恰好在某一分钟开始时到达城市，这也会被视为输掉游戏
// 返回在你输掉游戏前可以消灭的怪物的最大数量，如果消灭所有怪兽了返回n
// 测试链接 : https://leetcode.cn/problems/eliminate-maximum-number-of-monsters/
                        // a / b 向上取整 -> (a + b - 1) / b
                        // 当前来到i的时刻
*/

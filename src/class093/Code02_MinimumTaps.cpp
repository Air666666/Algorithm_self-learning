// Source: src/class093/Code02_MinimumTaps.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_MinimumTaps {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_MinimumTaps() {}
  static int minTaps(int n, Array<int> ranges) {
    Array<int> right = make_array<int>((n + 1));
    {
      int i = 0;
      int start = {};
      for (; (i <= n); (i++)) {
        (start = jmax(0, (i - ranges[i])));
        (right[start] = jmax(right[start], (i + ranges[i])));
      }
    }
    int cur = 0;
    int next = 0;
    int ans = 0;
    for (int i = 0; (i < n); (i++)) {
      (next = jmax(next, right[i]));
      if ((i == cur)) {
        if ((next > i)) {
          (cur = next);
          (ans++);
        } else {
          return (-1);
        }
      }
    }
    return ans;
  }
};

/* Original teaching comments:
// 灌溉花园的最少水龙头数目
// 在x轴上有一个一维的花园，花园长度为n，从点0开始，到点n结束
// 花园里总共有 n + 1 个水龙头，分别位于[0, 1, ... n]
// 给你一个整数n和一个长度为n+1的整数数组ranges
// 其中ranges[i]表示
// 如果打开点i处的水龙头，可以灌溉的区域为[i-ranges[i], i+ranges[i]]
// 请你返回可以灌溉整个花园的最少水龙头数目
// 如果花园始终存在无法灌溉到的地方请你返回-1
// 测试链接 :
https://leetcode.cn/problems/minimum-number-of-taps-to-open-to-water-a-garden/
                // right[i] = j
                // 所有左边界在i的水龙头里，影响到的最右右边界是j
                // 当前ans数量的水龙头打开，影响到的最右右边界
                // 如果再多打开一个水龙头，影响到的最右边界
                // 打开水龙头的数量
                        // 来到i位置
                        // 先更新下一步的next
*/

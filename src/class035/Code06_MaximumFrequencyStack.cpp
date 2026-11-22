// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/maximum-frequency-stack/

// Source: src/class035/Code06_MaximumFrequencyStack.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code06_MaximumFrequencyStack {
  struct FreqStack;
  struct FreqStack {
    int topTimes = {};
    JMap<int, JList<int>> cntValues = JMap<int, JList<int>>();
    JMap<int, int> valueTimes = JMap<int, int>();
    String toString() const { return j::str(static_cast<const void *>(this)); }
    FreqStack() {}
    void push(int val) {
      valueTimes.put(val, (valueTimes.getOrDefault(val, 0) + 1));
      int curTopTimes = valueTimes.get(val);
      if ((!cntValues.containsKey(curTopTimes))) {
        cntValues.put(curTopTimes, JList<int>());
      }
      JList<int> curTimeValues = cntValues.get(curTopTimes);
      curTimeValues.add(val);
      (topTimes = jmax(topTimes, curTopTimes));
    }
    int pop() {
      JList<int> topTimeValues = cntValues.get(topTimes);
      int ans = topTimeValues.remove((topTimeValues.size() - 1));
      if ((topTimeValues.size() == 0)) {
        cntValues.remove((topTimes--));
      }
      int times = valueTimes.get(ans);
      if ((times == 1)) {
        valueTimes.remove(ans);
      } else {
        valueTimes.put(ans, (times - 1));
      }
      return ans;
    }
  };
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code06_MaximumFrequencyStack() {}
};

/* Original teaching comments:
// 最大频率栈
        // 测试链接 : https://leetcode.cn/problems/maximum-frequency-stack/
                // 出现的最大次数
                // 每层节点
                // 每一个数出现了几次
*/

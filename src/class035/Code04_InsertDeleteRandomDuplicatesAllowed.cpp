// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/insert-delete-getrandom-o1-duplicates-allowed/

// Source: src/class035/Code04_InsertDeleteRandomDuplicatesAllowed.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_InsertDeleteRandomDuplicatesAllowed {
  struct RandomizedCollection;
  struct RandomizedCollection {
    JMap<int, JHashSet<int>> map = {};
    JList<int> arr = {};
    String toString() const { return j::str(static_cast<const void *>(this)); }
    RandomizedCollection() {
      (map = JMap<int, JHashSet<int>>());
      (arr = JList<int>());
    }
    bool insert(int val) {
      arr.add(val);
      JHashSet<int> set = map.getOrDefault(val, JHashSet<int>());
      set.add((arr.size() - 1));
      map.put(val, set);
      return (set.size() == 1);
    }
    bool remove(int val) {
      if ((!map.containsKey(val))) {
        return false;
      }
      JHashSet<int> valSet = map.get(val);
      int valAnyIndex = valSet.iterator().next();
      int endValue = arr.get((arr.size() - 1));
      if ((val == endValue)) {
        valSet.remove((arr.size() - 1));
      } else {
        JHashSet<int> endValueSet = map.get(endValue);
        endValueSet.add(valAnyIndex);
        arr.set(valAnyIndex, endValue);
        endValueSet.remove((arr.size() - 1));
        valSet.remove(valAnyIndex);
      }
      arr.remove((arr.size() - 1));
      if (valSet.isEmpty()) {
        map.remove(val);
      }
      return true;
    }
    int getRandom() {
      return arr.get(static_cast<int>([&]() {
        auto jleft = j::random();
        auto jright = arr.size();
        return (jleft * jright);
      }()));
    }
  };
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_InsertDeleteRandomDuplicatesAllowed() {}
};

/* Original teaching comments:
// 插入、删除和获取随机元素O(1)时间且允许有重复数字的结构
        // 测试链接 :
        //
https://leetcode.cn/problems/insert-delete-getrandom-o1-duplicates-allowed/
*/

// Source: src/class035/Code03_InsertDeleteRandom.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_InsertDeleteRandom {
  struct RandomizedSet;
  struct RandomizedSet {
    JMap<int, int> map = {};
    JList<int> arr = {};
    String toString() const { return j::str(static_cast<const void *>(this)); }
    RandomizedSet() {
      (map = JMap<int, int>());
      (arr = JList<int>());
    }
    bool insert(int val) {
      if (map.containsKey(val)) {
        return false;
      }
      map.put(val, arr.size());
      arr.add(val);
      return true;
    }
    bool remove(int val) {
      if ((!map.containsKey(val))) {
        return false;
      }
      int valIndex = map.get(val);
      int endValue = arr.get((arr.size() - 1));
      map.put(endValue, valIndex);
      arr.set(valIndex, endValue);
      map.remove(val);
      arr.remove((arr.size() - 1));
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
  Code03_InsertDeleteRandom() {}
};

/* Original teaching comments:
// 插入、删除和获取随机元素O(1)时间的结构
        // 测试链接 : https://leetcode.cn/problems/insert-delete-getrandom-o1/
*/

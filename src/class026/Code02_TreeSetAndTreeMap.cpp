// Source: src/class026/Code02_TreeSetAndTreeMap.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_TreeSetAndTreeMap {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_TreeSetAndTreeMap() {}
  static void java_main(Array<String> args) {
    JTreeMap<int, String> treeMap = JTreeMap<int, String>();
    treeMap.put(5, String(u"这是5"));
    treeMap.put(7, String(u"这是7"));
    treeMap.put(1, String(u"这是1"));
    treeMap.put(2, String(u"这是2"));
    treeMap.put(3, String(u"这是3"));
    treeMap.put(4, String(u"这是4"));
    treeMap.put(8, String(u"这是8"));
    jout.println(treeMap.containsKey(1));
    jout.println(treeMap.containsKey(10));
    jout.println(treeMap.get(4));
    treeMap.put(4, String(u"张三是4"));
    jout.println(treeMap.get(4));
    treeMap.remove(4);
    jout.println((treeMap.get(4) == nullptr));
    jout.println(treeMap.firstKey());
    jout.println(treeMap.lastKey());
    jout.println(treeMap.floorKey(4));
    jout.println(treeMap.ceilingKey(4));
    jout.println(String(u"========"));
    JSet<int> set = JSet<int>();
    set.add(3);
    set.add(3);
    set.add(4);
    set.add(4);
    jout.println((String(u"有序表大小 : ") + set.size()));
    while ((!set.isEmpty())) {
      jout.println(set.pollFirst());
    }
    JHeap<int> heap1 = JHeap<int>();
    heap1.add(3);
    heap1.add(3);
    heap1.add(4);
    heap1.add(4);
    jout.println((String(u"堆大小 : ") + heap1.size()));
    while ((!heap1.isEmpty())) {
      jout.println(heap1.poll());
    }
    JHeap<int> heap2 =
        JHeap<int>([=](Box<int> a, Box<int> b) { return (b - a); });
    heap2.add(3);
    heap2.add(3);
    heap2.add(4);
    heap2.add(4);
    jout.println((String(u"堆大小 : ") + heap2.size()));
    while ((!heap2.isEmpty())) {
      jout.println(heap2.poll());
    }
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code02_TreeSetAndTreeMap::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
                // 底层红黑树
                // TreeMap中，所有的key，<= 4且最近的key是什么
                // TreeMap中，所有的key，>= 4且最近的key是什么
                        // System.out.println(set.pollLast());
                // 堆，默认小根堆、如果要大根堆，定制比较器！
                // 定制的大根堆，用比较器！
*/

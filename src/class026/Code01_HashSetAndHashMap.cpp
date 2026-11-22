// Source: src/class026/Code01_HashSetAndHashMap.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_HashSetAndHashMap {
  struct Student;
  struct Student {
    int age = {};
    String name = {};
    String toString() const { return j::str(static_cast<const void *>(this)); }
    Student(int a, String b) {
      (age = a);
      (name = b);
    }
  };
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_HashSetAndHashMap() {}
  static void java_main(Array<String> args) {
    String str1 = newString(String(u"Hello"));
    String str2 = newString(String(u"Hello"));
    jout.println((str1 == str2));
    jout.println(str1.equals(str2));
    JHashSet<String> set = JHashSet<String>();
    set.add(str1);
    jout.println(set.contains(String(u"Hello")));
    jout.println(set.contains(str2));
    set.add(str2);
    jout.println(set.size());
    set.remove(str1);
    set.clear();
    jout.println(set.isEmpty());
    jout.println(String(u"==========="));
    JMap<String, String> map1 = JMap<String, String>();
    map1.put(str1, String(u"World"));
    jout.println(map1.containsKey(String(u"Hello")));
    jout.println(map1.containsKey(str2));
    jout.println(map1.get(str2));
    jout.println((map1.get(String(u"你好")) == nullptr));
    map1.remove(String(u"Hello"));
    jout.println(map1.size());
    map1.clear();
    jout.println(map1.isEmpty());
    jout.println(String(u"==========="));
    JMap<int, int> map2 = JMap<int, int>();
    map2.put(56, 7285);
    map2.put(34, 3671263);
    map2.put(17, 716311);
    map2.put(24, 1263161);
    Array<int> arr = make_array<int>(100);
    (arr[56] = 7285);
    (arr[34] = 3671263);
    (arr[17] = 716311);
    (arr[24] = 1263161);
    jout.println(String(u"在笔试场合中哈希表往往会被数组替代"));
    jout.println(String(u"==========="));
    Student *s1 = new Student(17, String(u"张三"));
    Student *s2 = new Student(17, String(u"张三"));
    JMap<Student *, String> map3 = JMap<Student *, String>();
    map3.put(s1, String(u"这是张三"));
    jout.println(map3.containsKey(s1));
    jout.println(map3.containsKey(s2));
    map3.put(s2, String(u"这是另一个张三"));
    jout.println(map3.size());
    jout.println(map3.get(s1));
    jout.println(map3.get(s2));
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code01_HashSetAndHashMap::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
                // Integer、Long、Double、Float
                // Byte、Short、Character、Boolean
                // String等都有这个特征
                // false，因为不同的内存地址
                // true，因为它们的值是相同的
                // 一般在笔试中，未必需要申请哈希表
                // 上面的map2行为，可以被如下数组的行为替代
                //
   哈希表的增、删、改、查，都可以被数组替代，前提是key的范围是固定的、可控的
*/

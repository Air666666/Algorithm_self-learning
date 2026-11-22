// Source: src/class026/Code03_Comparator.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_Comparator {
  struct Employee;
  struct EmployeeComparator;
  struct Employee {
    int company = {};
    int age = {};
    String toString() const { return j::str(static_cast<const void *>(this)); }
    Employee(int c, int a) {
      (company = c);
      (age = a);
    }
  };
  struct EmployeeComparator {
    String toString() const { return j::str(static_cast<const void *>(this)); }
    EmployeeComparator() {}
    int compare(Employee *o1, Employee *o2) { return (o1->age - o2->age); }
  };
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_Comparator() {}
  static void java_main(Array<String> args) {
    Employee *s1 = new Employee(2, 27);
    Employee *s2 = new Employee(1, 60);
    Employee *s3 = new Employee(4, 19);
    Employee *s4 = new Employee(3, 23);
    Employee *s5 = new Employee(1, 35);
    Employee *s6 = new Employee(3, 55);
    Array<Employee *> arr = Array<Employee *>{s1, s2, s3, s4, s5, s6};
    j::sort(arr, new EmployeeComparator());
    for (Employee *e : arr) {
      jout.println(((e->company + String(u" , ")) + e->age));
    }
    jout.println(String(u"====="));
    j::sort(arr, [=](Employee *a, Employee *b) { return (b->age - a->age); });
    for (Employee *e : arr) {
      jout.println(((e->company + String(u" , ")) + e->age));
    }
    jout.println(String(u"====="));
    j::sort(arr, [=](Employee *a, Employee *b) {
      return ((a->company != b->company) ? (a->company - b->company)
                                         : (a->age - b->age));
    });
    for (Employee *e : arr) {
      jout.println(((e->company + String(u" , ")) + e->age));
    }
    JSet<Employee *> treeSet1 = JSet<Employee *>(new EmployeeComparator());
    for (Employee *e : arr) {
      treeSet1.add(e);
    }
    jout.println(treeSet1.size());
    treeSet1.add(new Employee(2, 27));
    jout.println(treeSet1.size());
    jout.println(String(u"==="));
    JSet<Employee *> treeSet2 = JSet<Employee *>([=](Employee *a, Employee *b) {
      return ((a->company != b->company)
                  ? (a->company - b->company)
                  : ((a->age != b->age)
                         ? (a->age - b->age)
                         : jcompare(a->toString(), b->toString())));
    });
    for (Employee *e : arr) {
      treeSet2.add(e);
    }
    jout.println(treeSet2.size());
    treeSet2.add(new Employee(2, 27));
    jout.println(treeSet2.size());
    jout.println(String(u"==="));
    String str1 = String(u"abcde");
    String str2 = String(u"ks");
    jout.println(str1.compareTo(str2));
    jout.println(str2.compareTo(str1));
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code03_Comparator::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
                        // 任何比较器都默认
                        // 如果返回负数认为o1的优先级更高
                        // 如果返回正数认为o2的优先级更高
                        //
   任何比较器都是这样，所以利用这个设定，可以定制优先级怎么确定，也就是怎么比较
                        // 不再有大小的概念，就是优先级的概念
                //
   所有员工，先按照谁的公司编号小，谁在前；如果公司编号一样，谁年龄小谁在前
                // 会去重
                // 如果不想去重，就需要增加更多的比较
                // 比如对象的内存地址、或者如果对象有数组下标之类的独特信息
                // 不会去重
                // PriorityQueue不会去重，不再展示了
                // 字典序
*/

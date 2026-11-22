// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P1486
// https://oi-wiki.org/lang/java-pro/

// Source: src/class153/Code02_FrustratedCashier1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_FrustratedCashier1 {
  inline static int MAXN = 300001;
  inline static int head = 0;
  inline static int cnt = 0;
  inline static Array<int> key = make_array<int>(MAXN);
  inline static Array<int> father = make_array<int>(MAXN);
  inline static Array<int> left = make_array<int>(MAXN);
  inline static Array<int> right = make_array<int>(MAXN);
  inline static Array<int> size = make_array<int>(MAXN);
  inline static int limit = {};
  inline static int change = 0;
  inline static int enter = 0;
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_FrustratedCashier1() {}
  static void up(int i) { (size[i] = ((size[left[i]] + size[right[i]]) + 1)); }
  static int lr(int i) { return ((right[father[i]] == i) ? 1 : 0); }
  static void rotate(int i) {
    int f = father[i];
    int g = father[f];
    int soni = Code02_FrustratedCashier1::lr(i);
    int sonf = Code02_FrustratedCashier1::lr(f);
    if ((soni == 1)) {
      (right[f] = left[i]);
      if ((right[f] != 0)) {
        (father[right[f]] = f);
      }
      (left[i] = f);
    } else {
      (left[f] = right[i]);
      if ((left[f] != 0)) {
        (father[left[f]] = f);
      }
      (right[i] = f);
    }
    if ((g != 0)) {
      if ((sonf == 1)) {
        (right[g] = i);
      } else {
        (left[g] = i);
      }
    }
    (father[f] = i);
    (father[i] = g);
    Code02_FrustratedCashier1::up(f);
    Code02_FrustratedCashier1::up(i);
  }
  static void splay(int i, int goal) {
    int f = father[i];
    int g = father[f];
    while ((f != goal)) {
      if ((g != goal)) {
        if ([&]() {
              auto jleft = Code02_FrustratedCashier1::lr(i);
              auto jright = Code02_FrustratedCashier1::lr(f);
              return (jleft == jright);
            }()) {
          Code02_FrustratedCashier1::rotate(f);
        } else {
          Code02_FrustratedCashier1::rotate(i);
        }
      }
      Code02_FrustratedCashier1::rotate(i);
      (f = father[i]);
      (g = father[f]);
    }
    if ((goal == 0)) {
      (head = i);
    }
  }
  static void add(int num) {
    (key[(++cnt)] = num);
    (size[cnt] = 1);
    if ((head == 0)) {
      (head = cnt);
    } else {
      int f = 0;
      int i = head;
      int son = 0;
      while ((i != 0)) {
        (f = i);
        if ((key[i] <= num)) {
          (son = 1);
          (i = right[i]);
        } else {
          (son = 0);
          (i = left[i]);
        }
      }
      if ((son == 1)) {
        (right[f] = cnt);
      } else {
        (left[f] = cnt);
      }
      (father[cnt] = f);
      Code02_FrustratedCashier1::splay(cnt, 0);
    }
  }
  static int index(int x) {
    int i = head;
    int last = head;
    while ((i != 0)) {
      (last = i);
      if ((size[left[i]] >= x)) {
        (i = left[i]);
      } else if (((size[left[i]] + 1) < x)) {
        (x -= (size[left[i]] + 1));
        (i = right[i]);
      } else {
        (i = 0);
      }
    }
    Code02_FrustratedCashier1::splay(last, 0);
    return key[last];
  }
  static void departure() {
    int num = ((limit - change) - 1);
    int i = head;
    int ans = 0;
    while ((i != 0)) {
      if ((key[i] > num)) {
        (ans = i);
        (i = left[i]);
      } else {
        (i = right[i]);
      }
    }
    if ((ans == 0)) {
      (head = 0);
    } else {
      Code02_FrustratedCashier1::splay(ans, 0);
      (left[head] = 0);
      Code02_FrustratedCashier1::up(head);
    }
  }
  static void java_main(Array<String> args) {
    IO io = IO();
    int n = io.nextInt();
    (limit = io.nextInt());
    String op = {};
    int x = {};
    for (int i = 1; (i <= n); (i++)) {
      (op = io.next());
      (x = io.nextInt());
      if (op.equals(String(u"I"))) {
        if ((x >= limit)) {
          (enter++);
          Code02_FrustratedCashier1::add((x - change));
        }
      } else if (op.equals(String(u"A"))) {
        (change += x);
      } else if (op.equals(String(u"S"))) {
        (change -= x);
        Code02_FrustratedCashier1::departure();
      } else {
        if ((x > size[head])) {
          io.println((-1));
        } else {
          io.println((Code02_FrustratedCashier1::index(((size[head] - x) + 1)) +
                      change));
        }
      }
    }
    io.println((enter - size[head]));
    io.flush();
    io.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code02_FrustratedCashier1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 郁闷的出纳员(java版)
// 最低薪水为limit，一旦员工薪水低于limit，员工会离职，实现如下四种操作
// I x : 新来员工初始薪水是x，如果x低于limit，该员工不会入职当然也不算离职
// A x : 所有员工的薪水都加上x
// S x : 所有员工的薪水都减去x，一旦有员工低于limit那么就会离职
// F x : 查询第x多的工资，如果x大于当前员工数量，打印-1
// 所有操作完成后，打印有多少员工在操作期间离开了公司
// 测试链接 : https://www.luogu.com.cn/problem/P1486
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // Kattio类IO效率很好，但还是不如StreamTokenizer
        // 只有StreamTokenizer无法正确处理时，才考虑使用这个类
        // 参考链接 : https://oi-wiki.org/lang/java-pro/
*/

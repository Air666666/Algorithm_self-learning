// Source: src/class153/Code01_Splay1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_Splay1 {
  inline static int MAXN = 100001;
  inline static int head = 0;
  inline static int cnt = 0;
  inline static Array<int> key = make_array<int>(MAXN);
  inline static Array<int> father = make_array<int>(MAXN);
  inline static Array<int> left = make_array<int>(MAXN);
  inline static Array<int> right = make_array<int>(MAXN);
  inline static Array<int> size = make_array<int>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_Splay1() {}
  static void up(int i) { (size[i] = ((size[left[i]] + size[right[i]]) + 1)); }
  static int lr(int i) { return ((right[father[i]] == i) ? 1 : 0); }
  static void rotate(int i) {
    int f = father[i];
    int g = father[f];
    int soni = Code01_Splay1::lr(i);
    int sonf = Code01_Splay1::lr(f);
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
    Code01_Splay1::up(f);
    Code01_Splay1::up(i);
  }
  static void splay(int i, int goal) {
    int f = father[i];
    int g = father[f];
    while ((f != goal)) {
      if ((g != goal)) {
        if ([&]() {
              auto jleft = Code01_Splay1::lr(i);
              auto jright = Code01_Splay1::lr(f);
              return (jleft == jright);
            }()) {
          Code01_Splay1::rotate(f);
        } else {
          Code01_Splay1::rotate(i);
        }
      }
      Code01_Splay1::rotate(i);
      (f = father[i]);
      (g = father[f]);
    }
    if ((goal == 0)) {
      (head = i);
    }
  }
  static int find(int rank) {
    int i = head;
    while ((i != 0)) {
      if (((size[left[i]] + 1) == rank)) {
        return i;
      } else if ((size[left[i]] >= rank)) {
        (i = left[i]);
      } else {
        (rank -= (size[left[i]] + 1));
        (i = right[i]);
      }
    }
    return 0;
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
      Code01_Splay1::splay(cnt, 0);
    }
  }
  static int rank(int num) {
    int i = head;
    int last = head;
    int ans = 0;
    while ((i != 0)) {
      (last = i);
      if ((key[i] >= num)) {
        (i = left[i]);
      } else {
        (ans += (size[left[i]] + 1));
        (i = right[i]);
      }
    }
    Code01_Splay1::splay(last, 0);
    return (ans + 1);
  }
  static int index(int x) {
    int i = Code01_Splay1::find(x);
    Code01_Splay1::splay(i, 0);
    return key[i];
  }
  static int pre(int num) {
    int i = head;
    int last = head;
    int ans = std::numeric_limits<int>::min();
    while ((i != 0)) {
      (last = i);
      if ((key[i] >= num)) {
        (i = left[i]);
      } else {
        (ans = jmax(ans, key[i]));
        (i = right[i]);
      }
    }
    Code01_Splay1::splay(last, 0);
    return ans;
  }
  static int post(int num) {
    int i = head;
    int last = head;
    int ans = std::numeric_limits<int>::max();
    while ((i != 0)) {
      (last = i);
      if ((key[i] <= num)) {
        (i = right[i]);
      } else {
        (ans = jmin(ans, key[i]));
        (i = left[i]);
      }
    }
    Code01_Splay1::splay(last, 0);
    return ans;
  }
  static void remove(int num) {
    int kth = Code01_Splay1::rank(num);
    if ((kth != Code01_Splay1::rank((num + 1)))) {
      int i = Code01_Splay1::find(kth);
      Code01_Splay1::splay(i, 0);
      if ((left[i] == 0)) {
        (head = right[i]);
      } else if ((right[i] == 0)) {
        (head = left[i]);
      } else {
        int j = Code01_Splay1::find((kth + 1));
        Code01_Splay1::splay(j, i);
        (left[j] = left[i]);
        (father[left[j]] = j);
        Code01_Splay1::up(j);
        (head = j);
      }
      (father[head] = 0);
    }
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    int n = static_cast<int>(in.nval);
    {
      int i = 1;
      int op = {};
      int x = {};
      for (; (i <= n); (i++)) {
        in.nextToken();
        (op = static_cast<int>(in.nval));
        in.nextToken();
        (x = static_cast<int>(in.nval));
        if ((op == 1)) {
          Code01_Splay1::add(x);
        } else if ((op == 2)) {
          Code01_Splay1::remove(x);
        } else if ((op == 3)) {
          out.println(Code01_Splay1::rank(x));
        } else if ((op == 4)) {
          out.println(Code01_Splay1::index(x));
        } else if ((op == 5)) {
          out.println(Code01_Splay1::pre(x));
        } else {
          out.println(Code01_Splay1::post(x));
        }
      }
    }
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code01_Splay1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// Splay树的实现，不用词频压缩，java版
// 实现一种结构，支持如下操作，要求单次调用的时间复杂度O(log n)
// 1，增加x，重复加入算多个词频
// 2，删除x，如果有多个，只删掉一个
// 3，查询x的排名，x的排名为，比x小的数的个数+1
// 4，查询数据中排名为x的数
// 5，查询x的前驱，x的前驱为，小于x的数中最大的数，不存在返回整数最小值
// 6，查询x的后继，x的后继为，大于x的数中最小的数，不存在返回整数最大值
// 所有操作的次数 <= 10^5
// -10^7 <= x <= +10^7
// 测试链接 : https://www.luogu.com.cn/problem/P3369
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 整棵树上找到中序排名为rank的节点，返回节点编号
        // 这个方法不是题目要求的查询操作，作为内部方法使用
        // 为什么该方法不进行提根操作？
        // 因为remove方法使用该方法时，要求find不能提根！
*/

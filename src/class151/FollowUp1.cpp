// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P6136

// Source: src/class151/FollowUp1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct FollowUp1 {
  inline static int MAXN = 2000001;
  inline static int head = 0;
  inline static int cnt = 0;
  inline static Array<int> key = make_array<int>(MAXN);
  inline static Array<int> count = make_array<int>(MAXN);
  inline static Array<int> left = make_array<int>(MAXN);
  inline static Array<int> right = make_array<int>(MAXN);
  inline static Array<int> size = make_array<int>(MAXN);
  inline static Array<double> priority = make_array<double>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  FollowUp1() {}
  static void up(int i) {
    (size[i] = ((size[left[i]] + size[right[i]]) + count[i]));
  }
  static int leftRotate(int i) {
    int r = right[i];
    (right[i] = left[r]);
    (left[r] = i);
    FollowUp1::up(i);
    FollowUp1::up(r);
    return r;
  }
  static int rightRotate(int i) {
    int l = left[i];
    (left[i] = right[l]);
    (right[l] = i);
    FollowUp1::up(i);
    FollowUp1::up(l);
    return l;
  }
  static int add(int i, int num) {
    if ((i == 0)) {
      (key[(++cnt)] = num);
      (count[cnt] = (size[cnt] = 1));
      (priority[cnt] = j::random());
      return cnt;
    }
    if ((key[i] == num)) {
      (count[i]++);
    } else if ((key[i] > num)) {
      (left[i] = FollowUp1::add(left[i], num));
    } else {
      (right[i] = FollowUp1::add(right[i], num));
    }
    FollowUp1::up(i);
    if (((left[i] != 0) && (priority[left[i]] > priority[i]))) {
      return FollowUp1::rightRotate(i);
    }
    if (((right[i] != 0) && (priority[right[i]] > priority[i]))) {
      return FollowUp1::leftRotate(i);
    }
    return i;
  }
  static void add(int num) { (head = FollowUp1::add(head, num)); }
  static int small(int i, int num) {
    if ((i == 0)) {
      return 0;
    }
    if ((key[i] >= num)) {
      return FollowUp1::small(left[i], num);
    } else {
      return ((size[left[i]] + count[i]) + FollowUp1::small(right[i], num));
    }
  }
  static int rank(int num) { return (FollowUp1::small(head, num) + 1); }
  static int index(int i, int x) {
    if ((size[left[i]] >= x)) {
      return FollowUp1::index(left[i], x);
    } else if (((size[left[i]] + count[i]) < x)) {
      return FollowUp1::index(right[i], ((x - size[left[i]]) - count[i]));
    }
    return key[i];
  }
  static int index(int x) { return FollowUp1::index(head, x); }
  static int pre(int i, int num) {
    if ((i == 0)) {
      return std::numeric_limits<int>::min();
    }
    if ((key[i] >= num)) {
      return FollowUp1::pre(left[i], num);
    } else {
      return jmax(key[i], FollowUp1::pre(right[i], num));
    }
  }
  static int pre(int num) { return FollowUp1::pre(head, num); }
  static int post(int i, int num) {
    if ((i == 0)) {
      return std::numeric_limits<int>::max();
    }
    if ((key[i] <= num)) {
      return FollowUp1::post(right[i], num);
    } else {
      return jmin(key[i], FollowUp1::post(left[i], num));
    }
  }
  static int post(int num) { return FollowUp1::post(head, num); }
  static int remove(int i, int num) {
    if ((key[i] < num)) {
      (right[i] = FollowUp1::remove(right[i], num));
    } else if ((key[i] > num)) {
      (left[i] = FollowUp1::remove(left[i], num));
    } else {
      if ((count[i] > 1)) {
        (count[i]--);
      } else {
        if (((left[i] == 0) && (right[i] == 0))) {
          return 0;
        } else if (((left[i] != 0) && (right[i] == 0))) {
          (i = left[i]);
        } else if (((left[i] == 0) && (right[i] != 0))) {
          (i = right[i]);
        } else {
          if ((priority[left[i]] >= priority[right[i]])) {
            (i = FollowUp1::rightRotate(i));
            (right[i] = FollowUp1::remove(right[i], num));
          } else {
            (i = FollowUp1::leftRotate(i));
            (left[i] = FollowUp1::remove(left[i], num));
          }
        }
      }
    }
    FollowUp1::up(i);
    return i;
  }
  static void remove(int num) {
    if ([&]() {
          auto jleft = FollowUp1::rank(num);
          auto jright = FollowUp1::rank((num + 1));
          return (jleft != jright);
        }()) {
      (head = FollowUp1::remove(head, num));
    }
  }
  static void clear() {
    j::fill(key, 1, (cnt + 1), 0);
    j::fill(count, 1, (cnt + 1), 0);
    j::fill(left, 1, (cnt + 1), 0);
    j::fill(right, 1, (cnt + 1), 0);
    j::fill(size, 1, (cnt + 1), 0);
    j::fill(priority, 1, (cnt + 1), 0);
    (cnt = 0);
    (head = 0);
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    int n = static_cast<int>(in.nval);
    in.nextToken();
    int m = static_cast<int>(in.nval);
    {
      int i = 1;
      int num = {};
      for (; (i <= n); (i++)) {
        in.nextToken();
        (num = static_cast<int>(in.nval));
        FollowUp1::add(num);
      }
    }
    int lastAns = 0;
    int ans = 0;
    {
      int i = 1;
      int op = {};
      int x = {};
      for (; (i <= m); (i++)) {
        in.nextToken();
        (op = static_cast<int>(in.nval));
        in.nextToken();
        (x = (static_cast<int>(in.nval) ^ lastAns));
        if ((op == 1)) {
          FollowUp1::add(x);
        } else if ((op == 2)) {
          FollowUp1::remove(x);
        } else if ((op == 3)) {
          (lastAns = FollowUp1::rank(x));
          (ans ^= lastAns);
        } else if ((op == 4)) {
          (lastAns = FollowUp1::index(x));
          (ans ^= lastAns);
        } else if ((op == 5)) {
          (lastAns = FollowUp1::pre(x));
          (ans ^= lastAns);
        } else {
          (lastAns = FollowUp1::post(x));
          (ans ^= lastAns);
        }
      }
    }
    out.println(ans);
    FollowUp1::clear();
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  FollowUp1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// Treap树实现普通有序表，数据加强的测试，java版
// 这个文件课上没有讲，测试数据加强了，而且有强制在线的要求
// 基本功能要求都是不变的，可以打开测试链接查看
// 测试链接 : https://www.luogu.com.cn/problem/P6136
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
*/

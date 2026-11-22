// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P6136

// Source: src/class152/FollowUp1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct FollowUp1 {
  inline static int MAXN = 2000001;
  inline static int head = 0;
  inline static int cnt = 0;
  inline static Array<int> key = make_array<int>(MAXN);
  inline static Array<int> left = make_array<int>(MAXN);
  inline static Array<int> right = make_array<int>(MAXN);
  inline static Array<int> size = make_array<int>(MAXN);
  inline static Array<double> priority = make_array<double>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  FollowUp1() {}
  static void up(int i) { (size[i] = ((size[left[i]] + size[right[i]]) + 1)); }
  static void split(int l, int r, int i, int num) {
    if ((i == 0)) {
      (right[l] = (left[r] = 0));
    } else {
      if ((key[i] <= num)) {
        (right[l] = i);
        FollowUp1::split(i, r, right[i], num);
      } else {
        (left[r] = i);
        FollowUp1::split(l, i, left[i], num);
      }
      FollowUp1::up(i);
    }
  }
  static int merge(int l, int r) {
    if (((l == 0) || (r == 0))) {
      return (l + r);
    }
    if ((priority[l] >= priority[r])) {
      (right[l] = FollowUp1::merge(right[l], r));
      FollowUp1::up(l);
      return l;
    } else {
      (left[r] = FollowUp1::merge(l, left[r]));
      FollowUp1::up(r);
      return r;
    }
  }
  static void add(int num) {
    FollowUp1::split(0, 0, head, num);
    (key[(++cnt)] = num);
    (size[cnt] = 1);
    (priority[cnt] = j::random());
    (head = FollowUp1::merge(FollowUp1::merge(right[0], cnt), left[0]));
  }
  static void remove(int num) {
    FollowUp1::split(0, 0, head, num);
    int lm = right[0];
    int r = left[0];
    FollowUp1::split(0, 0, lm, (num - 1));
    int l = right[0];
    int m = left[0];
    (head = FollowUp1::merge(
         FollowUp1::merge(l, FollowUp1::merge(left[m], right[m])), r));
  }
  static int rank(int num) {
    FollowUp1::split(0, 0, head, (num - 1));
    int ans = (size[right[0]] + 1);
    (head = FollowUp1::merge(right[0], left[0]));
    return ans;
  }
  static int index(int i, int x) {
    if ((size[left[i]] >= x)) {
      return FollowUp1::index(left[i], x);
    } else if (((size[left[i]] + 1) < x)) {
      return FollowUp1::index(right[i], ((x - size[left[i]]) - 1));
    } else {
      return key[i];
    }
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
// FHQ-Treap实现普通有序表，不用词频压缩，数据加强的测试，java版
// 这个文件课上没有讲，测试数据加强了，而且有强制在线的要求
// 基本功能要求都是不变的，可以打开测试链接查看
// 测试链接 : https://www.luogu.com.cn/problem/P6136
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
*/

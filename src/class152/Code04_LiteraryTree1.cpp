// Source: src/class152/Code04_LiteraryTree1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_LiteraryTree1 {
  inline static int MAXN = 100001;
  inline static int head = 0;
  inline static int cnt = 0;
  inline static Array<int> key = make_array<int>(MAXN);
  inline static Array<int> left = make_array<int>(MAXN);
  inline static Array<int> right = make_array<int>(MAXN);
  inline static Array<int> size = make_array<int>(MAXN);
  inline static Array<double> priority = make_array<double>(MAXN);
  inline static Array<bool> reverse = make_array<bool>(MAXN);
  inline static Array<int> ans = make_array<int>(MAXN);
  inline static int ansi = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_LiteraryTree1() {}
  static void up(int i) { (size[i] = ((size[left[i]] + size[right[i]]) + 1)); }
  static void down(int i) {
    if (reverse[i]) {
      int tmp = left[i];
      (left[i] = right[i]);
      (right[i] = tmp);
      (reverse[left[i]] = (!reverse[left[i]]));
      (reverse[right[i]] = (!reverse[right[i]]));
      (reverse[i] = false);
    }
  }
  static void split(int l, int r, int i, int rank) {
    if ((i == 0)) {
      (right[l] = (left[r] = 0));
    } else {
      Code04_LiteraryTree1::down(i);
      if (((size[left[i]] + 1) <= rank)) {
        (right[l] = i);
        Code04_LiteraryTree1::split(i, r, right[i],
                                    ((rank - size[left[i]]) - 1));
      } else {
        (left[r] = i);
        Code04_LiteraryTree1::split(l, i, left[i], rank);
      }
      Code04_LiteraryTree1::up(i);
    }
  }
  static int merge(int l, int r) {
    if (((l == 0) || (r == 0))) {
      return (l + r);
    }
    if ((priority[l] >= priority[r])) {
      Code04_LiteraryTree1::down(l);
      (right[l] = Code04_LiteraryTree1::merge(right[l], r));
      Code04_LiteraryTree1::up(l);
      return l;
    } else {
      Code04_LiteraryTree1::down(r);
      (left[r] = Code04_LiteraryTree1::merge(l, left[r]));
      Code04_LiteraryTree1::up(r);
      return r;
    }
  }
  static void inorder(int i) {
    if ((i != 0)) {
      Code04_LiteraryTree1::down(i);
      Code04_LiteraryTree1::inorder(left[i]);
      (ans[(++ansi)] = key[i]);
      Code04_LiteraryTree1::inorder(right[i]);
    }
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    int n = static_cast<int>(in.nval);
    in.nextToken();
    int k = static_cast<int>(in.nval);
    for (int i = 1; (i <= n); (i++)) {
      (key[(++cnt)] = i);
      (size[cnt] = 1);
      (priority[cnt] = j::random());
      (head = Code04_LiteraryTree1::merge(head, cnt));
    }
    {
      int i = 1;
      int x = {};
      int y = {};
      int l = {};
      int m = {};
      int lm = {};
      int r = {};
      for (; (i <= k); (i++)) {
        in.nextToken();
        (x = static_cast<int>(in.nval));
        in.nextToken();
        (y = static_cast<int>(in.nval));
        Code04_LiteraryTree1::split(0, 0, head, y);
        (lm = right[0]);
        (r = left[0]);
        Code04_LiteraryTree1::split(0, 0, lm, (x - 1));
        (l = right[0]);
        (m = left[0]);
        (reverse[m] = (!reverse[m]));
        (head =
             Code04_LiteraryTree1::merge(Code04_LiteraryTree1::merge(l, m), r));
      }
    }
    (ansi = 0);
    Code04_LiteraryTree1::inorder(head);
    for (int i = 1; (i <= ansi); (i++)) {
      out.print((ans[i] + String(u" ")));
    }
    out.println();
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code04_LiteraryTree1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 文艺平衡树，FHQ-Treap实现范围翻转，java版本
// 长度为n的序列，下标从1开始，一开始序列为1, 2, ..., n
// 接下来会有k个操作，每个操作给定l，r，表示从l到r范围上的所有数字翻转
// 做完k次操作后，从左到右打印所有数字
// 1 <= n, k <= 10^5
// 测试链接 : https://www.luogu.com.cn/problem/P3391
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
*/

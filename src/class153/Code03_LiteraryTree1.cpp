// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P3391

// Source: src/class153/Code03_LiteraryTree1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_LiteraryTree1 {
  inline static int MAXN = 100005;
  inline static int head = 0;
  inline static int cnt = 0;
  inline static Array<int> num = make_array<int>(MAXN);
  inline static Array<int> father = make_array<int>(MAXN);
  inline static Array<int> left = make_array<int>(MAXN);
  inline static Array<int> right = make_array<int>(MAXN);
  inline static Array<int> size = make_array<int>(MAXN);
  inline static Array<bool> reverse = make_array<bool>(MAXN);
  inline static Array<int> stack = make_array<int>(MAXN);
  inline static int si = {};
  inline static Array<int> ans = make_array<int>(MAXN);
  inline static int ai = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_LiteraryTree1() {}
  static void up(int i) { (size[i] = ((size[left[i]] + size[right[i]]) + 1)); }
  static int lr(int i) { return ((right[father[i]] == i) ? 1 : 0); }
  static void rotate(int i) {
    int f = father[i];
    int g = father[f];
    int soni = Code03_LiteraryTree1::lr(i);
    int sonf = Code03_LiteraryTree1::lr(f);
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
    Code03_LiteraryTree1::up(f);
    Code03_LiteraryTree1::up(i);
  }
  static void splay(int i, int goal) {
    int f = father[i];
    int g = father[f];
    while ((f != goal)) {
      if ((g != goal)) {
        if ([&]() {
              auto jleft = Code03_LiteraryTree1::lr(i);
              auto jright = Code03_LiteraryTree1::lr(f);
              return (jleft == jright);
            }()) {
          Code03_LiteraryTree1::rotate(f);
        } else {
          Code03_LiteraryTree1::rotate(i);
        }
      }
      Code03_LiteraryTree1::rotate(i);
      (f = father[i]);
      (g = father[f]);
    }
    if ((goal == 0)) {
      (head = i);
    }
  }
  static void down(int i) {
    if (reverse[i]) {
      (reverse[left[i]] = (!reverse[left[i]]));
      (reverse[right[i]] = (!reverse[right[i]]));
      int tmp = left[i];
      (left[i] = right[i]);
      (right[i] = tmp);
      (reverse[i] = false);
    }
  }
  static int find(int rank) {
    int i = head;
    while ((i != 0)) {
      Code03_LiteraryTree1::down(i);
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
  static void add(int x) {
    (num[(++cnt)] = x);
    (size[cnt] = 1);
    (father[cnt] = head);
    (right[head] = cnt);
    Code03_LiteraryTree1::splay(cnt, 0);
  }
  static void reverse_method(int l, int r) {
    int i = Code03_LiteraryTree1::find((l - 1));
    int j = Code03_LiteraryTree1::find((r + 1));
    Code03_LiteraryTree1::splay(i, 0);
    Code03_LiteraryTree1::splay(j, i);
    (reverse[left[right[head]]] = (!reverse[left[right[head]]]));
  }
  static void inorder(int i) {
    if ((i != 0)) {
      Code03_LiteraryTree1::down(i);
      Code03_LiteraryTree1::inorder(left[i]);
      (ans[(++ai)] = num[i]);
      Code03_LiteraryTree1::inorder(right[i]);
    }
  }
  static void inorder() {
    (si = 0);
    int i = head;
    while (((si != 0) || (i != 0))) {
      if ((i != 0)) {
        Code03_LiteraryTree1::down(i);
        (stack[(++si)] = i);
        (i = left[i]);
      } else {
        (i = stack[(si--)]);
        (ans[(++ai)] = num[i]);
        (i = right[i]);
      }
    }
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    int n = static_cast<int>(in.nval);
    in.nextToken();
    int m = static_cast<int>(in.nval);
    Code03_LiteraryTree1::add(0);
    for (int i = 1; (i <= n); (i++)) {
      Code03_LiteraryTree1::add(i);
    }
    Code03_LiteraryTree1::add(0);
    {
      int i = 1;
      int x = {};
      int y = {};
      for (; (i <= m); (i++)) {
        in.nextToken();
        (x = static_cast<int>(in.nval));
        in.nextToken();
        (y = static_cast<int>(in.nval));
        Code03_LiteraryTree1::reverse_method((x + 1), (y + 1));
      }
    }
    (ai = 0);
    Code03_LiteraryTree1::inorder();
    for (int i = 2; (i < ai); (i++)) {
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
  Code03_LiteraryTree1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 文艺平衡树，Splay实现范围翻转，java版本
// 长度为n的序列，下标从1开始，一开始序列为1, 2, ..., n
// 接下来会有k个操作，每个操作给定l，r，表示从l到r范围上的所有数字翻转
// 做完k次操作后，从左到右打印所有数字
// 1 <= n, k <= 10^5
// 测试链接 : https://www.luogu.com.cn/problem/P3391
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 注意l永远不会是最左位置，r永远不会是最右位置
        // 因为最左和最右位置提前加入了预备值，永远不会修改
        // 递归方式实现二叉树中序遍历
        // 对本题来说，递归不会爆栈，但其实是有风险的
        // 迭代方式实现二叉树中序遍历，防止递归爆栈
        // 不懂的话，看讲解018，迭代方式实现二叉树中序遍历
        // 遍历时候懒更新任务也要下发
//		inorder(head);
*/

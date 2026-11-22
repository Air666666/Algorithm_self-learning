// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/queue-reconstruction-by-height/

// Source: src/class148/Code02_ReconstructionQueue.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_ReconstructionQueue {
  inline static int MAXN = 2001;
  inline static int cnt = 0;
  inline static int head = 0;
  inline static Array<int> key = make_array<int>(MAXN);
  inline static Array<int> height = make_array<int>(MAXN);
  inline static Array<int> left = make_array<int>(MAXN);
  inline static Array<int> right = make_array<int>(MAXN);
  inline static Array<int> value = make_array<int>(MAXN);
  inline static Array<int> size = make_array<int>(MAXN);
  inline static int fi = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_ReconstructionQueue() {}
  static Array<Array<int>> reconstructQueue(Array<Array<int>> people) {
    j::sort(people, [=](Array<int> a, Array<int> b) {
      return ((a[0] != b[0]) ? (b[0] - a[0]) : (a[1] - b[1]));
    });
    for (Array<int> p : people) {
      Code02_ReconstructionQueue::add(p[0], p[1]);
    }
    Code02_ReconstructionQueue::fill(people);
    Code02_ReconstructionQueue::clear();
    return people;
  }
  static void up(int i) {
    (size[i] = ((size[left[i]] + size[right[i]]) + 1));
    (height[i] = (jmax(height[left[i]], height[right[i]]) + 1));
  }
  static int leftRotate(int i) {
    int r = right[i];
    (right[i] = left[r]);
    (left[r] = i);
    Code02_ReconstructionQueue::up(i);
    Code02_ReconstructionQueue::up(r);
    return r;
  }
  static int rightRotate(int i) {
    int l = left[i];
    (left[i] = right[l]);
    (right[l] = i);
    Code02_ReconstructionQueue::up(i);
    Code02_ReconstructionQueue::up(l);
    return l;
  }
  static int maintain(int i) {
    int lh = height[left[i]];
    int rh = height[right[i]];
    if (((lh - rh) > 1)) {
      if ((height[left[left[i]]] >= height[right[left[i]]])) {
        (i = Code02_ReconstructionQueue::rightRotate(i));
      } else {
        (left[i] = Code02_ReconstructionQueue::leftRotate(left[i]));
        (i = Code02_ReconstructionQueue::rightRotate(i));
      }
    } else if (((rh - lh) > 1)) {
      if ((height[right[right[i]]] >= height[left[right[i]]])) {
        (i = Code02_ReconstructionQueue::leftRotate(i));
      } else {
        (right[i] = Code02_ReconstructionQueue::rightRotate(right[i]));
        (i = Code02_ReconstructionQueue::leftRotate(i));
      }
    }
    return i;
  }
  static void add(int num, int index) {
    (head = Code02_ReconstructionQueue::add(head, index, num, index));
  }
  static int add(int i, int rank, int num, int index) {
    if ((i == 0)) {
      (key[(++cnt)] = num);
      (value[cnt] = index);
      (size[cnt] = (height[cnt] = 1));
      return cnt;
    }
    if ((size[left[i]] >= rank)) {
      (left[i] = Code02_ReconstructionQueue::add(left[i], rank, num, index));
    } else {
      (right[i] = Code02_ReconstructionQueue::add(
           right[i], ((rank - size[left[i]]) - 1), num, index));
    }
    Code02_ReconstructionQueue::up(i);
    return Code02_ReconstructionQueue::maintain(i);
  }
  static void fill(Array<Array<int>> ans) {
    (fi = 0);
    Code02_ReconstructionQueue::inOrder(ans, head);
  }
  static void inOrder(Array<Array<int>> ans, int i) {
    if ((i == 0)) {
      return;
    }
    Code02_ReconstructionQueue::inOrder(ans, left[i]);
    (ans[fi][0] = key[i]);
    (ans[(fi++)][1] = value[i]);
    Code02_ReconstructionQueue::inOrder(ans, right[i]);
  }
  static void clear() {
    j::fill(key, 1, (cnt + 1), 0);
    j::fill(height, 1, (cnt + 1), 0);
    j::fill(left, 1, (cnt + 1), 0);
    j::fill(right, 1, (cnt + 1), 0);
    j::fill(value, 1, (cnt + 1), 0);
    j::fill(size, 1, (cnt + 1), 0);
    (cnt = 0);
    (head = 0);
  }
};

/* Original teaching comments:
// 重建队列(做到最优时间复杂度)
// 一共n个人，每个人有(a, b)两个数据，数据a表示该人的身高
// 数据b表示该人的要求，站在自己左边的人中，正好有b个人的身高大于等于自己的身高
// 请你把n个人从左到右进行排列，要求每个人的要求都可以满足
// 返回其中一种排列即可，本题的数据保证一定存在这样的排列
// 题解中的绝大多数方法，时间复杂度O(n平方)，但是时间复杂度能做到O(n * log n)
// 测试链接 : https://leetcode.cn/problems/queue-reconstruction-by-height/
*/

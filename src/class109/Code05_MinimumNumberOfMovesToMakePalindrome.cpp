// Source: src/class109/Code05_MinimumNumberOfMovesToMakePalindrome.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code05_MinimumNumberOfMovesToMakePalindrome {
  inline static int MAXN = 2001;
  inline static int MAXV = 26;
  inline static int n = {};
  inline static Array<jchar> s = {};
  inline static Array<int> end = make_array<int>(MAXV);
  inline static Array<int> pre = make_array<int>(MAXN);
  inline static Array<int> tree = make_array<int>(MAXN);
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static Array<int> help = make_array<int>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code05_MinimumNumberOfMovesToMakePalindrome() {}
  static void build() {
    j::fill(end, 0, MAXV, 0);
    j::fill(arr, 1, (n + 1), 0);
    j::fill(tree, 1, (n + 1), 0);
    for (int i = 1; (i <= n); (i++)) {
      Code05_MinimumNumberOfMovesToMakePalindrome::add(i, 1);
    }
  }
  static void push(int v, int j) {
    (pre[j] = end[v]);
    (end[v] = j);
  }
  static int pop(int v) {
    int ans = end[v];
    (end[v] = pre[end[v]]);
    return ans;
  }
  static int lowbit(int i) { return (i & (-i)); }
  static void add(int i, int v) {
    while ((i <= n)) {
      (tree[i] += v);
      (i += Code05_MinimumNumberOfMovesToMakePalindrome::lowbit(i));
    }
  }
  static int sum(int i) {
    int ans = 0;
    while ((i > 0)) {
      (ans += tree[i]);
      (i -= Code05_MinimumNumberOfMovesToMakePalindrome::lowbit(i));
    }
    return ans;
  }
  static int minMovesToMakePalindrome(String str) {
    (s = str.toCharArray());
    (n = s.length);
    Code05_MinimumNumberOfMovesToMakePalindrome::build();
    {
      int i = 0;
      int j = 1;
      for (; (i < n); (i++), (j++)) {
        Code05_MinimumNumberOfMovesToMakePalindrome::push((s[i] - u'a'), j);
      }
    }
    {
      int i = 0;
      int l = 1;
      int r = {};
      int k = {};
      for (; (i < n); (i++), (l++)) {
        if ((arr[l] == 0)) {
          (r = Code05_MinimumNumberOfMovesToMakePalindrome::pop((s[i] - u'a')));
          if ((l < r)) {
            (k = Code05_MinimumNumberOfMovesToMakePalindrome::sum(l));
            (arr[l] = k);
            (arr[r] = ((n - k) + 1));
          } else {
            (arr[l] = jdiv((1 + n), 2));
          }
          Code05_MinimumNumberOfMovesToMakePalindrome::add(r, (-1));
        }
      }
    }
    return Code05_MinimumNumberOfMovesToMakePalindrome::number(1, n);
  }
  static int number(int l, int r) {
    if ((l >= r)) {
      return 0;
    }
    int m = jdiv((l + r), 2);
    return [&]() {
      auto jleft = [&]() {
        auto jleft = Code05_MinimumNumberOfMovesToMakePalindrome::number(l, m);
        auto jright =
            Code05_MinimumNumberOfMovesToMakePalindrome::number((m + 1), r);
        return (jleft + jright);
      }();
      auto jright = Code05_MinimumNumberOfMovesToMakePalindrome::merge(l, m, r);
      return (jleft + jright);
    }();
  }
  static int merge(int l, int m, int r) {
    int ans = 0;
    {
      int i = m;
      int j = r;
      for (; (i >= l); (i--)) {
        while (((j >= (m + 1)) && (arr[i] <= arr[j]))) {
          (j--);
        }
        (ans += (j - m));
      }
    }
    int i = l;
    int a = l;
    int b = (m + 1);
    while (((a <= m) && (b <= r))) {
      (help[(i++)] = ((arr[a] <= arr[b]) ? arr[(a++)] : arr[(b++)]));
    }
    while ((a <= m)) {
      (help[(i++)] = arr[(a++)]);
    }
    while ((b <= r)) {
      (help[(i++)] = arr[(b++)]);
    }
    for ((i = l); (i <= r); (i++)) {
      (arr[i] = help[i]);
    }
    return ans;
  }
};

/* Original teaching comments:
// 得到回文串的最少操作次数
// 给你一个只包含小写英文字母的字符串s
// 每一次操作可以选择s中两个相邻的字符进行交换
// 返回将s变成回文串的最少操作次数
// 输入数据会确保s一定能变成一个回文串
// 测试链接 :
https://leetcode.cn/problems/minimum-number-of-moves-to-make-palindrome/
        // 所有字符的位置列表
        // 树状数组
        // 归并分治
        // 字符v把下标j加入列表
        // 弹出当前v字符最后的下标
        // 时间复杂度O(n * logn)
                // arr[i]记录每个位置的字符最终要去哪
*/

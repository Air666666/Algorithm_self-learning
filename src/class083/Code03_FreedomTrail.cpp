// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/freedom-trail/

// Source: src/class083/Code03_FreedomTrail.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_FreedomTrail {
  inline static int MAXN = 101;
  inline static int MAXC = 26;
  inline static Array<int> ring = make_array<int>(MAXN);
  inline static Array<int> key = make_array<int>(MAXN);
  inline static Array<int> size = make_array<int>(MAXC);
  inline static Array<Array<int>> where = make_array<int>(MAXC, MAXN);
  inline static Array<Array<int>> dp = make_array<int>(MAXN, MAXN);
  inline static int n = {};
  inline static int m = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_FreedomTrail() {}
  static void build(String r, String k) {
    for (int i = 0; (i < MAXC); (i++)) {
      (size[i] = 0);
    }
    (n = r.length());
    (m = k.length());
    {
      int i = 0;
      int v = {};
      for (; (i < n); (i++)) {
        (v = (r.charAt(i) - u'a'));
        (where[v][(size[v]++)] = i);
        (ring[i] = v);
      }
    }
    for (int i = 0; (i < m); (i++)) {
      (key[i] = (k.charAt(i) - u'a'));
    }
    for (int i = 0; (i < n); (i++)) {
      for (int j = 0; (j < m); (j++)) {
        (dp[i][j] = (-1));
      }
    }
  }
  static int findRotateSteps(String r, String k) {
    Code03_FreedomTrail::build(r, k);
    return Code03_FreedomTrail::f(0, 0);
  }
  static int f(int i, int j) {
    if ((j == m)) {
      return 0;
    }
    if ((dp[i][j] != (-1))) {
      return dp[i][j];
    }
    int ans = {};
    if ((ring[i] == key[j])) {
      (ans = (1 + Code03_FreedomTrail::f(i, (j + 1))));
    } else {
      int jump1 = Code03_FreedomTrail::clock(i, key[j]);
      int distance1 = ((jump1 > i) ? (jump1 - i) : ((n - i) + jump1));
      int jump2 = Code03_FreedomTrail::counterClock(i, key[j]);
      int distance2 = ((i > jump2) ? (i - jump2) : ((i + n) - jump2));
      (ans = [&]() {
        auto jargument_0 = (distance1 + Code03_FreedomTrail::f(jump1, j));
        auto jargument_1 = (distance2 + Code03_FreedomTrail::f(jump2, j));
        return jmin(jargument_0, jargument_1);
      }());
    }
    (dp[i][j] = ans);
    return ans;
  }
  static int clock(int i, int v) {
    int l = 0;
    int r = (size[v] - 1);
    int m = {};
    Array<int> sorted = where[v];
    int find = (-1);
    while ((l <= r)) {
      (m = jdiv((l + r), 2));
      if ((sorted[m] > i)) {
        (find = m);
        (r = (m - 1));
      } else {
        (l = (m + 1));
      }
    }
    return ((find != (-1)) ? sorted[find] : sorted[0]);
  }
  static int counterClock(int i, int v) {
    int l = 0;
    int r = (size[v] - 1);
    int m = {};
    Array<int> sorted = where[v];
    int find = (-1);
    while ((l <= r)) {
      (m = jdiv((l + r), 2));
      if ((sorted[m] < i)) {
        (find = m);
        (l = (m + 1));
      } else {
        (r = (m - 1));
      }
    }
    return ((find != (-1)) ? sorted[find] : sorted[(size[v] - 1)]);
  }
};

/* Original teaching comments:
// 自由之路
// 题目描述比较多，打开链接查看
// 测试链接 : https://leetcode.cn/problems/freedom-trail/
        // 为了让所有语言的同学都可以理解
        // 不会使用任何java语言自带的数据结构
        // 只使用最简单的数组结构
        // 指针当前指着轮盘i位置的字符，要搞定key[j....]所有字符，最小代价返回
                        // key长度是m
                        // 都搞定
                        // ring b
                        //      i
                        // key  b
                        //      j
                        // 轮盘处在i位置，ring[i] != key[j]
                        // jump1 : 顺时针找到最近的key[j]字符在轮盘的什么位置
                        // distance1 : 从i顺时针走向jump1有多远
                        // jump2 : 逆时针找到最近的key[j]字符在轮盘的什么位置
                        // distance2 : 从i逆时针走向jump2有多远
        // 从i开始，顺时针找到最近的v在轮盘的什么位置
                // size[v] : 属于v这个字符的下标有几个
                // sorted[0...size[v]-1]收集了所有的下标，并且有序
                // 有序数组中，找>i尽量靠左的下标
                // 找到了就返回
                // 没找到，那i顺指针一定先走到最小的下标
                // 有序数组中，找<i尽量靠右的下标
                // 找到了就返回
                // 没找到，那i逆指针一定先走到最大的下标
*/

// Source: src/class111/Code01_FallingSquares.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_FallingSquares {
  inline static int MAXN = 2001;
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static Array<int> max = make_array<int>(jshl(MAXN, 2));
  inline static Array<int> change = make_array<int>(jshl(MAXN, 2));
  inline static Array<bool> update = make_array<bool>(jshl(MAXN, 2));
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_FallingSquares() {}
  static int collect(Array<Array<int>> poss) {
    int size = 1;
    for (Array<int> pos : poss) {
      (arr[(size++)] = pos[0]);
      (arr[(size++)] = ((pos[0] + pos[1]) - 1));
    }
    j::sort(arr, 1, size);
    int n = 1;
    for (int i = 2; (i < size); (i++)) {
      if ((arr[n] != arr[i])) {
        (arr[(++n)] = arr[i]);
      }
    }
    return n;
  }
  static int rank(int n, int v) {
    int ans = 0;
    int l = 1;
    int r = n;
    int m = {};
    while ((l <= r)) {
      (m = jshr((l + r), 1));
      if ((arr[m] >= v)) {
        (ans = m);
        (r = (m - 1));
      } else {
        (l = (m + 1));
      }
    }
    return ans;
  }
  static void up(int i) {
    (max[i] = jmax(max[jshl(i, 1)], max[(jshl(i, 1) | 1)]));
  }
  static void down(int i) {
    if (update[i]) {
      Code01_FallingSquares::lazy(jshl(i, 1), change[i]);
      Code01_FallingSquares::lazy((jshl(i, 1) | 1), change[i]);
      (update[i] = false);
    }
  }
  static void lazy(int i, int v) {
    (update[i] = true);
    (change[i] = v);
    (max[i] = v);
  }
  static void build(int l, int r, int i) {
    if ((l < r)) {
      int mid = jshr((l + r), 1);
      Code01_FallingSquares::build(l, mid, jshl(i, 1));
      Code01_FallingSquares::build((mid + 1), r, (jshl(i, 1) | 1));
    }
    (max[i] = 0);
    (change[i] = 0);
    (update[i] = false);
  }
  static void update_method(int jobl, int jobr, int jobv, int l, int r, int i) {
    if (((jobl <= l) && (r <= jobr))) {
      Code01_FallingSquares::lazy(i, jobv);
    } else {
      int mid = jshr((l + r), 1);
      Code01_FallingSquares::down(i);
      if ((jobl <= mid)) {
        Code01_FallingSquares::update_method(jobl, jobr, jobv, l, mid,
                                             jshl(i, 1));
      }
      if ((jobr > mid)) {
        Code01_FallingSquares::update_method(jobl, jobr, jobv, (mid + 1), r,
                                             (jshl(i, 1) | 1));
      }
      Code01_FallingSquares::up(i);
    }
  }
  static int query(int jobl, int jobr, int l, int r, int i) {
    if (((jobl <= l) && (r <= jobr))) {
      return max[i];
    }
    int mid = jshr((l + r), 1);
    Code01_FallingSquares::down(i);
    int ans = std::numeric_limits<int>::min();
    if ((jobl <= mid)) {
      (ans = jmax(
           ans, Code01_FallingSquares::query(jobl, jobr, l, mid, jshl(i, 1))));
    }
    if ((jobr > mid)) {
      (ans = jmax(ans, Code01_FallingSquares::query(jobl, jobr, (mid + 1), r,
                                                    (jshl(i, 1) | 1))));
    }
    return ans;
  }
  static JList<int> fallingSquares(Array<Array<int>> pos) {
    int n = Code01_FallingSquares::collect(pos);
    Code01_FallingSquares::build(1, n, 1);
    JList<int> ans = JList<int>();
    int max = 0;
    int l = {};
    int r = {};
    int h = {};
    for (Array<int> square : pos) {
      (l = Code01_FallingSquares::rank(n, square[0]));
      (r = Code01_FallingSquares::rank(n, ((square[0] + square[1]) - 1)));
      (h = (Code01_FallingSquares::query(l, r, 1, n, 1) + square[1]));
      (max = jmax(max, h));
      ans.add(max);
      Code01_FallingSquares::update_method(l, r, h, 1, n, 1);
    }
    return ans;
  }
};

/* Original teaching comments:
// 掉落的方块
// 有一个二维平面，x轴是最底的边界
// 给定二维整数数组pos，pos[i] = [ lefti, leni ]
// 表示第i个方块边长为leni，左侧边缘在x = lefti位置，所在高度非常高
// 所有方块都是正方形，依次从高处垂直掉落，也就是左边界顺着x = lefti往下
// 如果掉落的方块碰到已经掉落正方形的顶边或者x轴就停止掉落
// 如果方块掉落时仅仅是擦过已经掉落正方形的左侧边或右侧边，并不会停止掉落
// 一旦停止，它就会固定在那里，无法再移动，俄罗斯方块游戏和本题意思一样
// 返回一个整数数组ans ，其中ans[i]表示在第i块方块掉落后整体的最大高度
// 1 <= pos数组长度 <= 1000，1 <= lefti <= 10^8，1 <= leni <= 10^6
// 测试链接 : https://leetcode.cn/problems/falling-squares
*/

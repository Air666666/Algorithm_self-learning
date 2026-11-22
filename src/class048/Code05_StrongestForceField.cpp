// Source: src/class048/Code05_StrongestForceField.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code05_StrongestForceField {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code05_StrongestForceField() {}
  static int fieldOfGreatestBlessing(Array<Array<int>> fields) {
    int n = fields.length;
    Array<i64> xs = make_array<i64>(jshl(n, 1));
    Array<i64> ys = make_array<i64>(jshl(n, 1));
    {
      int i = 0;
      int k = 0;
      int p = 0;
      for (; (i < n); (i++)) {
        i64 x = fields[i][0];
        i64 y = fields[i][1];
        i64 r = fields[i][2];
        (xs[(k++)] = (jshl(x, 1) - r));
        (xs[(k++)] = (jshl(x, 1) + r));
        (ys[(p++)] = (jshl(y, 1) - r));
        (ys[(p++)] = (jshl(y, 1) + r));
      }
    }
    int sizex = Code05_StrongestForceField::sort(xs);
    int sizey = Code05_StrongestForceField::sort(ys);
    Array<Array<int>> diff = make_array<int>((sizex + 2), (sizey + 2));
    {
      int i = 0;
      int a = {};
      int b = {};
      int c = {};
      int d = {};
      for (; (i < n); (i++)) {
        i64 x = fields[i][0];
        i64 y = fields[i][1];
        i64 r = fields[i][2];
        (a = Code05_StrongestForceField::rank(xs, (jshl(x, 1) - r), sizex));
        (b = Code05_StrongestForceField::rank(ys, (jshl(y, 1) - r), sizey));
        (c = Code05_StrongestForceField::rank(xs, (jshl(x, 1) + r), sizex));
        (d = Code05_StrongestForceField::rank(ys, (jshl(y, 1) + r), sizey));
        Code05_StrongestForceField::add(diff, a, b, c, d);
      }
    }
    int ans = 0;
    for (int i = 1; (i < diff.length); (i++)) {
      for (int j = 1; (j < diff[0].length); (j++)) {
        (diff[i][j] +=
         ((diff[(i - 1)][j] + diff[i][(j - 1)]) - diff[(i - 1)][(j - 1)]));
        (ans = jmax(ans, diff[i][j]));
      }
    }
    return ans;
  }
  static int sort(Array<i64> nums) {
    j::sort(nums);
    int size = 1;
    for (int i = 1; (i < nums.length); (i++)) {
      if ((nums[i] != nums[(size - 1)])) {
        (nums[(size++)] = nums[i]);
      }
    }
    return size;
  }
  static int rank(Array<i64> nums, i64 v, int size) {
    int l = 0;
    int r = (size - 1);
    int m = {};
    int ans = 0;
    while ((l <= r)) {
      (m = jdiv((l + r), 2));
      if ((nums[m] >= v)) {
        (ans = m);
        (r = (m - 1));
      } else {
        (l = (m + 1));
      }
    }
    return (ans + 1);
  }
  static void add(Array<Array<int>> diff, int a, int b, int c, int d) {
    (diff[a][b] += 1);
    (diff[(c + 1)][(d + 1)] += 1);
    (diff[(c + 1)][b] -= 1);
    (diff[a][(d + 1)] -= 1);
  }
};

/* Original teaching comments:
// 最强祝福力场
// 小扣在探索丛林的过程中，无意间发现了传说中"落寞的黄金之都"
//
而在这片建筑废墟的地带中，小扣使用探测仪监测到了存在某种带有「祝福」效果的力场
// 经过不断的勘测记录，小扣将所有力场的分布都记录了下来
// forceField[i] = [x,y,side]
// 表示第 i 片力场将覆盖以坐标 (x,y) 为中心，边长为 side 的正方形区域。
// 若任意一点的 力场强度 等于覆盖该点的力场数量
// 请求出在这片地带中 力场强度 最强处的 力场强度
// 注意：力场范围的边缘同样被力场覆盖。
// 测试链接 : https://leetcode.cn/problems/xepqZ5/
        // 时间复杂度O(n^2)，额外空间复杂度O(n^2)，n是力场的个数
                // n : 矩形的个数，x 2*n个坐标
                // xs数组中，排序了且相同值只留一份，返回有效长度
                // ys数组中，排序了且相同值只留一份，返回有效长度
                // n个力场，sizex : 2 * n, sizey : 2 * n
                // O(n^2)
        // [50,70,30,70,30,60] 长度6
        // [30,30,50,60,70,70]
        // [30,50,60,70] 60 -> 3
        //  1  2  3  4
        // 长度4，
        // nums 有序数组，有效长度是size，0~size-1范围上无重复值
        // 已知v一定在nums[0~size-1]，返回v所对应的编号
        // 二维差分
*/

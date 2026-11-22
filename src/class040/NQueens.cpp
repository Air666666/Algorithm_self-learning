// Source: src/class040/NQueens.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct NQueens {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  NQueens() {}
  static int totalNQueens1(int n) {
    if ((n < 1)) {
      return 0;
    }
    return NQueens::f1(0, make_array<int>(n), n);
  }
  static int f1(int i, Array<int> path, int n) {
    if ((i == n)) {
      return 1;
    }
    int ans = 0;
    for (int j = 0; (j < n); (j++)) {
      if (NQueens::check(path, i, j)) {
        (path[i] = j);
        (ans += NQueens::f1((i + 1), path, n));
      }
    }
    return ans;
  }
  static bool check(Array<int> path, int i, int j) {
    for (int k = 0; (k < i); (k++)) {
      if (((j == path[k]) || [&]() {
            auto jleft = std::abs((i - k));
            auto jright = std::abs((j - path[k]));
            return (jleft == jright);
          }())) {
        return false;
      }
    }
    return true;
  }
  static int totalNQueens2(int n) {
    if ((n < 1)) {
      return 0;
    }
    int limit = (jshl(1, n) - 1);
    return NQueens::f2(limit, 0, 0, 0);
  }
  static int f2(int limit, int col, int left, int right) {
    if ((col == limit)) {
      return 1;
    }
    int ban = ((col | left) | right);
    int candidate = (limit & (~ban));
    int place = 0;
    int ans = 0;
    while ((candidate != 0)) {
      (place = (candidate & (-candidate)));
      (candidate ^= place);
      (ans += NQueens::f2(limit, (col | place), jshr((left | place), 1),
                          jshl((right | place), 1)));
    }
    return ans;
  }
  static void java_main(Array<String> args) {
    int n = 14;
    i64 start = {};
    i64 end = {};
    jout.println(String(u"测试开始"));
    jout.println(((String(u"解决") + n) + String(u"皇后问题")));
    (start = millis());
    jout.println((String(u"方法1答案 : ") + NQueens::totalNQueens1(n)));
    (end = millis());
    jout.println(
        ((String(u"方法1运行时间 : ") + (end - start)) + String(u" 毫秒")));
    (start = millis());
    jout.println((String(u"方法2答案 : ") + NQueens::totalNQueens2(n)));
    (end = millis());
    jout.println(
        ((String(u"方法2运行时间 : ") + (end - start)) + String(u" 毫秒")));
    jout.println(String(u"测试结束"));
    jout.println(String(u"======="));
    jout.println(
        String(u"只有位运算的版本，才能10秒内跑完16皇后问题的求解过程"));
    (start = millis());
    int ans = NQueens::totalNQueens2(16);
    (end = millis());
    jout.println((String(u"16皇后问题的答案 : ") + ans));
    jout.println(((String(u"运行时间 : ") + (end - start)) + String(u" 毫秒")));
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  NQueens::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// N皇后问题
// 测试链接 : https://leetcode.cn/problems/n-queens-ii/
        // 用数组表示路径实现的N皇后问题，不推荐
        // i : 当前来到的行
        // path : 0...i-1行的皇后，都摆在了哪些列
        // n : 是几皇后问题
        // 返回 :
0...i-1行已经摆完了，i....n-1行可以去尝试的情况下还能找到几种有效的方法
                // 0 1 2 3 .. n-1
                // i j
        // 当前在i行、j列的位置，摆了一个皇后
        // 0...i-1行的皇后状况，path[0...i-1]
        // 返回会不会冲突，不会冲突，有效！true
        // 会冲突，无效，返回false
                // 当前 i
                // 当列 j
                        // 0...i-1
                        // 之前行 : k
                        // 之前列 : path[k]
        // 用位信息表示路径实现的N皇后问题，推荐
                // n = 5
                // 1 << 5 = 0...100000 - 1
                // limit  = 0...011111;
                // n = 7
                // limit  = 0...01111111;
        // limit : 当前是几皇后问题
        // 之前皇后的列影响：col
        // 之前皇后的右上 -> 左下对角线影响：left
        // 之前皇后的左上 -> 右下对角线影响：right
                        // 所有皇后放完了！
                // 总限制
                // ~ban : 1可放皇后，0不能放
                // 放置皇后的尝试！
                // 一共有多少有效的方法
                        // 提取出最右侧的1
                        // 0 0 1 1 1 0
                        // 5 4 3 2 1 0
                        // place :
                        // 0 0 0 0 1 0
                        // candidate :
                        // 0 0 1 1 0 0
                        // 5 4 3 2 1 0
                        // place :
                        // 0 0 0 1 0 0
                        // candidate :
                        // 0 0 1 0 0 0
                        // 5 4 3 2 1 0
                        // place :
                        // 0 0 1 0 0 0
                        // candidate :
                        // 0 0 0 0 0 0
                        // 5 4 3 2 1 0
*/

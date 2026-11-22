// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/shortest-path-to-get-all-keys

// Source: src/class064/Code04_ShortestPathToGetAllKeys.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_ShortestPathToGetAllKeys {
  inline static int MAXN = 31;
  inline static int MAXM = 31;
  inline static int MAXK = 6;
  inline static Array<int> move = Array<int>{(-1), 0, 1, 0, (-1)};
  inline static Array<Array<jchar>> grid = make_array<Array<jchar>>(MAXN);
  inline static Array<Array<Array<bool>>> visited =
      make_array<bool>(MAXN, MAXM, jshl(1, MAXK));
  inline static Array<Array<int>> queue =
      make_array<int>(((MAXN * MAXM) * jshl(1, MAXK)), 3);
  inline static int l = {};
  inline static int r = {};
  inline static int n = {};
  inline static int m = {};
  inline static int key = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_ShortestPathToGetAllKeys() {}
  static void build(Array<String> g) {
    (l = (r = (key = 0)));
    (n = g.length);
    (m = g[0].length());
    for (int i = 0; (i < n); (i++)) {
      (grid[i] = g[i].toCharArray());
    }
    for (int i = 0; (i < n); (i++)) {
      for (int j = 0; (j < m); (j++)) {
        if ((grid[i][j] == u'@')) {
          (queue[r][0] = i);
          (queue[r][1] = j);
          (queue[(r++)][2] = 0);
        }
        if (((grid[i][j] >= u'a') && (grid[i][j] <= u'f'))) {
          (key |= jshl(1, (grid[i][j] - u'a')));
        }
      }
    }
    for (int i = 0; (i < n); (i++)) {
      for (int j = 0; (j < m); (j++)) {
        for (int s = 0; (s <= key); (s++)) {
          (visited[i][j][s] = false);
        }
      }
    }
  }
  static int shortestPathAllKeys(Array<String> g) {
    Code04_ShortestPathToGetAllKeys::build(g);
    int level = 1;
    while ((l < r)) {
      {
        int k = 0;
        int size = (r - l);
        int x = {};
        int y = {};
        int s = {};
        for (; (k < size); (k++)) {
          (x = queue[l][0]);
          (y = queue[l][1]);
          (s = queue[(l++)][2]);
          {
            int i = 0;
            int nx = {};
            int ny = {};
            int ns = {};
            for (; (i < 4); (i++)) {
              (nx = (x + move[i]));
              (ny = (y + move[(i + 1)]));
              (ns = s);
              if ((((((nx < 0) || (nx == n)) || (ny < 0)) || (ny == m)) ||
                   (grid[nx][ny] == u'#'))) {
                continue;
              }
              if ((((grid[nx][ny] >= u'A') && (grid[nx][ny] <= u'F')) &&
                   ((ns & jshl(1, (grid[nx][ny] - u'A'))) == 0))) {
                continue;
              }
              if (((grid[nx][ny] >= u'a') && (grid[nx][ny] <= u'f'))) {
                (ns |= jshl(1, (grid[nx][ny] - u'a')));
              }
              if ((ns == key)) {
                return level;
              }
              if ((!visited[nx][ny][ns])) {
                (visited[nx][ny][ns] = true);
                (queue[r][0] = nx);
                (queue[r][1] = ny);
                (queue[(r++)][2] = ns);
              }
            }
          }
        }
      }
      (level++);
    }
    return (-1);
  }
};

/* Original teaching comments:
// 获取所有钥匙的最短路径
// 给定一个二维网格 grid ，其中：
// '.' 代表一个空房间、'#' 代表一堵、'@' 是起点
// 小写字母代表钥匙、大写字母代表锁
// 从起点开始出发，一次移动是指向四个基本方向之一行走一个单位空间
// 不能在网格外面行走，也无法穿过一堵墙
//
如果途经一个钥匙，我们就把它捡起来。除非我们手里有对应的钥匙，否则无法通过锁。
// 假设 k 为 钥匙/锁 的个数，且满足 1 <= k <= 6，
// 字母表中的前 k 个字母在网格中都有自己对应的一个小写和一个大写字母
// 换言之，每个锁有唯一对应的钥匙，每个钥匙也有唯一对应的锁
// 另外，代表钥匙和锁的字母互为大小写并按字母顺序排列
// 返回获取所有钥匙所需要的移动的最少次数。如果无法获取所有钥匙，返回 -1 。
// 测试链接：https://leetcode.cn/problems/shortest-path-to-get-all-keys
        // 0:上，1:右，2:下，3:左
        // 0 : 行
        // 1 : 列
        // 2 : 收集钥匙的状态
                                        // 0 : 000000
                                                // 越界或者障碍
                                                // 是锁，又没有对应的钥匙
                                                // 是某一把钥匙
                                                // 常见剪枝
                                                // 发现终点直接返回
                                                // 不用等都结束
*/

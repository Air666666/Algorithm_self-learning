// Source: src/class065/Code01_AStarAlgorithm.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_AStarAlgorithm {
  inline static Array<int> move = Array<int>{(-1), 0, 1, 0, (-1)};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_AStarAlgorithm() {}
  static int minDistance1(Array<Array<int>> grid, int startX, int startY,
                          int targetX, int targetY) {
    if (((grid[startX][startY] == 0) || (grid[targetX][targetY] == 0))) {
      return (-1);
    }
    int n = grid.length;
    int m = grid[0].length;
    Array<Array<int>> distance = make_array<int>(n, m);
    for (int i = 0; (i < n); (i++)) {
      for (int j = 0; (j < m); (j++)) {
        (distance[i][j] = std::numeric_limits<int>::max());
      }
    }
    (distance[startX][startY] = 1);
    Array<Array<bool>> visited = make_array<bool>(n, m);
    JHeap<Array<int>> heap = JHeap<Array<int>>(
        [=](Array<int> a, Array<int> b) { return (a[2] - b[2]); });
    heap.add(Array<int>{startX, startY, 1});
    while ((!heap.isEmpty())) {
      Array<int> cur = heap.poll();
      int x = cur[0];
      int y = cur[1];
      if (visited[x][y]) {
        continue;
      }
      (visited[x][y] = true);
      if (((x == targetX) && (y == targetY))) {
        return distance[x][y];
      }
      {
        int i = 0;
        int nx = {};
        int ny = {};
        for (; (i < 4); (i++)) {
          (nx = (x + move[i]));
          (ny = (y + move[(i + 1)]));
          if ((((((((nx >= 0) && (nx < n)) && (ny >= 0)) && (ny < m)) &&
                 (grid[nx][ny] == 1)) &&
                (!visited[nx][ny])) &&
               ((distance[x][y] + 1) < distance[nx][ny]))) {
            (distance[nx][ny] = (distance[x][y] + 1));
            heap.add(Array<int>{nx, ny, (distance[x][y] + 1)});
          }
        }
      }
    }
    return (-1);
  }
  static int minDistance2(Array<Array<int>> grid, int startX, int startY,
                          int targetX, int targetY) {
    if (((grid[startX][startY] == 0) || (grid[targetX][targetY] == 0))) {
      return (-1);
    }
    int n = grid.length;
    int m = grid[0].length;
    Array<Array<int>> distance = make_array<int>(n, m);
    for (int i = 0; (i < n); (i++)) {
      for (int j = 0; (j < m); (j++)) {
        (distance[i][j] = std::numeric_limits<int>::max());
      }
    }
    (distance[startX][startY] = 1);
    Array<Array<bool>> visited = make_array<bool>(n, m);
    JHeap<Array<int>> heap = JHeap<Array<int>>(
        [=](Array<int> a, Array<int> b) { return (a[2] - b[2]); });
    heap.add(Array<int>{
        startX, startY,
        (1 + Code01_AStarAlgorithm::f1(startX, startY, targetX, targetY))});
    while ((!heap.isEmpty())) {
      Array<int> cur = heap.poll();
      int x = cur[0];
      int y = cur[1];
      if (visited[x][y]) {
        continue;
      }
      (visited[x][y] = true);
      if (((x == targetX) && (y == targetY))) {
        return distance[x][y];
      }
      {
        int i = 0;
        int nx = {};
        int ny = {};
        for (; (i < 4); (i++)) {
          (nx = (x + move[i]));
          (ny = (y + move[(i + 1)]));
          if ((((((((nx >= 0) && (nx < n)) && (ny >= 0)) && (ny < m)) &&
                 (grid[nx][ny] == 1)) &&
                (!visited[nx][ny])) &&
               ((distance[x][y] + 1) < distance[nx][ny]))) {
            (distance[nx][ny] = (distance[x][y] + 1));
            heap.add(Array<int>{
                nx, ny,
                ((distance[x][y] + 1) +
                 Code01_AStarAlgorithm::f1(nx, ny, targetX, targetY))});
          }
        }
      }
    }
    return (-1);
  }
  static int f1(int x, int y, int targetX, int targetY) {
    return [&]() {
      auto jleft = std::abs((targetX - x));
      auto jright = std::abs((targetY - y));
      return (jleft + jright);
    }();
  }
  static int f2(int x, int y, int targetX, int targetY) {
    return [&]() {
      auto jargument_0 = std::abs((targetX - x));
      auto jargument_1 = std::abs((targetY - y));
      return jmax(jargument_0, jargument_1);
    }();
  }
  static double f3(int x, int y, int targetX, int targetY) {
    return std::sqrt([&]() {
      auto jleft = std::pow((targetX - x), 2);
      auto jright = std::pow((targetY - y), 2);
      return (jleft + jright);
    }());
  }
  static Array<Array<int>> randomGrid(int n) {
    Array<Array<int>> grid = make_array<int>(n, n);
    for (int i = 0; (i < n); (i++)) {
      for (int j = 0; (j < n); (j++)) {
        if ((j::random() < 0.3)) {
          (grid[i][j] = 0);
        } else {
          (grid[i][j] = 1);
        }
      }
    }
    return grid;
  }
  static void java_main(Array<String> args) {
    int len = 100;
    int testTime = 10000;
    jout.println(String(u"功能测试开始"));
    for (int i = 0; (i < testTime); (i++)) {
      int n = (static_cast<int>((j::random() * len)) + 2);
      Array<Array<int>> grid = Code01_AStarAlgorithm::randomGrid(n);
      int startX = static_cast<int>((j::random() * n));
      int startY = static_cast<int>((j::random() * n));
      int targetX = static_cast<int>((j::random() * n));
      int targetY = static_cast<int>((j::random() * n));
      int ans1 = Code01_AStarAlgorithm::minDistance1(grid, startX, startY,
                                                     targetX, targetY);
      int ans2 = Code01_AStarAlgorithm::minDistance2(grid, startX, startY,
                                                     targetX, targetY);
      if ((ans1 != ans2)) {
        jout.println(String(u"出错了!"));
      }
    }
    jout.println(String(u"功能测试结束"));
    jout.println(String(u"性能测试开始"));
    Array<Array<int>> grid = Code01_AStarAlgorithm::randomGrid(4000);
    int startX = 0;
    int startY = 0;
    int targetX = 3900;
    int targetY = 3900;
    i64 start = {};
    i64 end = {};
    (start = millis());
    int ans1 = Code01_AStarAlgorithm::minDistance1(grid, startX, startY,
                                                   targetX, targetY);
    (end = millis());
    jout.println((((String(u"运行dijskra算法结果: ") + ans1) +
                   String(u", 运行时间(毫秒) : ")) +
                  (end - start)));
    (start = millis());
    int ans2 = Code01_AStarAlgorithm::minDistance2(grid, startX, startY,
                                                   targetX, targetY);
    (end = millis());
    jout.println((((String(u"运行A*算法结果: ") + ans2) +
                   String(u", 运行时间(毫秒) : ")) +
                  (end - start)));
    jout.println(String(u"性能测试结束"));
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code01_AStarAlgorithm::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// A*算法模版（对数器验证）
        // 0:上，1:右，2:下，3:左
        // Dijkstra算法
        // grid[i][j] == 0 代表障碍
        // grid[i][j] == 1 代表道路
        // 只能走上、下、左、右，不包括斜线方向
        // 返回从(startX, startY)到(targetX, targetY)的最短距离
                // 0 : 行
                // 1 : 列
                // 2 : 从源点出发到达当前点的距离
        // A*算法
        // grid[i][j] == 0 代表障碍
        // grid[i][j] == 1 代表道路
        // 只能走上、下、左、右，不包括斜线方向
        // 返回从(startX, startY)到(targetX, targetY)的最短距离
                // 0 : 行
                // 1 : 列
                // 2 : 从源点出发到达当前点的距离 + 当前点到终点的预估距离
        // 曼哈顿距离
        // 对角线距离
        // 欧式距离
        // 为了测试
                                        // 每个格子有30%概率是0
                                        // 每个格子有70%概率是1
        // 为了测试
*/

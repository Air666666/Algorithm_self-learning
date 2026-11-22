// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P10590
// https://codeforces.com/problemset/problem/198/E

// Source: src/class173/Code03_Magnet1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_Magnet1 {
  inline static int MAXN = 300001;
  inline static int MAXB = 601;
  inline static int n = {};
  inline static Array<int> x = make_array<int>(MAXN);
  inline static Array<int> y = make_array<int>(MAXN);
  inline static Array<int> m = make_array<int>(MAXN);
  inline static Array<int> p = make_array<int>(MAXN);
  inline static Array<i64> range = make_array<i64>(MAXN);
  inline static Array<i64> dist = make_array<i64>(MAXN);
  inline static int blen = {};
  inline static int bnum = {};
  inline static Array<int> bi = make_array<int>(MAXN);
  inline static Array<int> bl = make_array<int>(MAXB);
  inline static Array<int> br = make_array<int>(MAXB);
  inline static Array<int> maxm = make_array<int>(MAXB);
  inline static Array<int> que = make_array<int>(MAXN);
  inline static Array<bool> vis = make_array<bool>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_Magnet1() {}
  static void swap(int i, int j) {
    int tmp1 = {};
    (tmp1 = x[i]);
    (x[i] = x[j]);
    (x[j] = tmp1);
    (tmp1 = y[i]);
    (y[i] = y[j]);
    (y[j] = tmp1);
    (tmp1 = m[i]);
    (m[i] = m[j]);
    (m[j] = tmp1);
    (tmp1 = p[i]);
    (p[i] = p[j]);
    (p[j] = tmp1);
    i64 tmp2 = {};
    (tmp2 = range[i]);
    (range[i] = range[j]);
    (range[j] = tmp2);
    (tmp2 = dist[i]);
    (dist[i] = dist[j]);
    (dist[j] = tmp2);
  }
  static void sortByM(int l, int r) {
    if ((l >= r))
      return;
    int i = l;
    int j = r;
    int pivot = m[jshr((l + r), 1)];
    while ((i <= j)) {
      while ((m[i] < pivot))
        (i++);
      while ((m[j] > pivot))
        (j--);
      if ((i <= j))
        [&]() {
          auto jargument_0 = (i++);
          auto jargument_1 = (j--);
          return Code03_Magnet1::swap(jargument_0, jargument_1);
        }();
    }
    Code03_Magnet1::sortByM(l, j);
    Code03_Magnet1::sortByM(i, r);
  }
  static void sortByDist(int l, int r) {
    if ((l >= r))
      return;
    int i = l;
    int j = r;
    i64 pivot = dist[jshr((l + r), 1)];
    while ((i <= j)) {
      while ((dist[i] < pivot))
        (i++);
      while ((dist[j] > pivot))
        (j--);
      if ((i <= j))
        [&]() {
          auto jargument_0 = (i++);
          auto jargument_1 = (j--);
          return Code03_Magnet1::swap(jargument_0, jargument_1);
        }();
    }
    Code03_Magnet1::sortByDist(l, j);
    Code03_Magnet1::sortByDist(i, r);
  }
  static int bfs() {
    int ans = 0;
    (vis[0] = true);
    int l = 1;
    int r = 1;
    (que[(r++)] = 0);
    while ((l < r)) {
      int cur = que[(l++)];
      for (int b = 1; (b <= bnum); (b++)) {
        if ((maxm[b] <= p[cur])) {
          while (((bl[b] <= br[b]) && (dist[bl[b]] <= range[cur]))) {
            int i = bl[b];
            if ((!vis[i])) {
              (vis[i] = true);
              (que[(r++)] = i);
              (ans++);
            }
            (bl[b]++);
          }
        } else {
          for (int j = bl[b]; (j <= br[b]); (j++)) {
            if ((((dist[j] <= range[cur]) && (m[j] <= p[cur])) && (!vis[j]))) {
              (vis[j] = true);
              (que[(r++)] = j);
              (ans++);
            }
          }
          break;
        }
      }
    }
    return ans;
  }
  static void prepare() {
    (blen = static_cast<int>(std::sqrt(n)));
    (bnum = jdiv(((n + blen) - 1), blen));
    for (int i = 1; (i <= n); (i++)) {
      (bi[i] = (jdiv((i - 1), blen) + 1));
    }
    for (int i = 1; (i <= bnum); (i++)) {
      (bl[i] = (((i - 1) * blen) + 1));
      (br[i] = jmin((i * blen), n));
    }
    Code03_Magnet1::sortByM(1, n);
    for (int i = 1; (i <= bnum); (i++)) {
      (maxm[i] = m[br[i]]);
      Code03_Magnet1::sortByDist(bl[i], br[i]);
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (x[0] = in.nextInt());
    (y[0] = in.nextInt());
    (p[0] = in.nextInt());
    (range[0] = in.nextInt());
    (n = in.nextInt());
    for (int i = 1; (i <= n); (i++)) {
      (x[i] = in.nextInt());
      (y[i] = in.nextInt());
      (m[i] = in.nextInt());
      (p[i] = in.nextInt());
      (range[i] = in.nextInt());
    }
    for (int i = 0; (i <= n); (i++)) {
      (range[i] *= range[i]);
      i64 dx = (x[0] - x[i]);
      i64 dy = (y[0] - y[i]);
      (dist[i] = ((dx * dx) + (dy * dy)));
    }
    Code03_Magnet1::prepare();
    out.println(Code03_Magnet1::bfs());
    out.flush();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code03_Magnet1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 磁力块，java版
// 磁块有五个属性值，x、y、m、p、range，磁块在(x,
y)位置、质量为m、磁力为p、吸引半径range
// 磁块A可以把磁块B吸到磁块A的位置，需要满足如下的条件
// A与B的距离不大于A的吸引半径，并且B的质量不大于A的磁力
//
你有一个初始磁块，给定初始磁块的4个属性值(不给质量，因为没用)，你永远在初始磁块的位置
// 接下来给定n个磁块各自的5个属性值，你可以用初始磁块，吸过来其中的磁块
// 吸过来的磁块可以被你随意使用，返回你最多能吸过来多少磁块
// 1 <= n <= 3 * 10^5    -10^9 <= x、y <= +10^9    1 <= m、p、range <= 10^9
// 测试链接 : https://www.luogu.com.cn/problem/P10590
// 测试链接 : https://codeforces.com/problemset/problem/198/E
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
// 为了java的实现能通过，不把数据封装成一个磁块对象，然后去排序
// 手写了双指针快排优化常数时间，一般不需要这么做，正式比赛不卡常
        // 下标为i的磁块和下标为j的磁块交换
        // 所有磁块根据m值排序，手写双指针快排
        // 所有磁块根据dist值排序，手写双指针快排
        // 读写工具类
*/

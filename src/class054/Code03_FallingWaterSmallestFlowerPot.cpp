// Source: src/class054/Code03_FallingWaterSmallestFlowerPot.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_FallingWaterSmallestFlowerPot {
  inline static int MAXN = 100005;
  inline static Array<Array<int>> arr = make_array<int>(MAXN, 2);
  inline static int n = {};
  inline static int d = {};
  inline static Array<int> maxDeque = make_array<int>(MAXN);
  inline static Array<int> minDeque = make_array<int>(MAXN);
  inline static int maxh = {};
  inline static int maxt = {};
  inline static int minh = {};
  inline static int mint = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_FallingWaterSmallestFlowerPot() {}
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    while ((in.nextToken() != -1)) {
      (n = static_cast<int>(in.nval));
      in.nextToken();
      (d = static_cast<int>(in.nval));
      for (int i = 0; (i < n); (i++)) {
        in.nextToken();
        (arr[i][0] = static_cast<int>(in.nval));
        in.nextToken();
        (arr[i][1] = static_cast<int>(in.nval));
      }
      int ans = Code03_FallingWaterSmallestFlowerPot::compute();
      out.println(((ans == std::numeric_limits<int>::max()) ? (-1) : ans));
    }
    out.flush();
    out.close();
    br.close();
  }
  static int compute() {
    j::sort(arr, 0, n,
            [=](Array<int> a, Array<int> b) { return (a[0] - b[0]); });
    (maxh = (maxt = (minh = (mint = 0))));
    int ans = std::numeric_limits<int>::max();
    {
      int l = 0;
      int r = 0;
      for (; (l < n); (l++)) {
        while (((!Code03_FallingWaterSmallestFlowerPot::ok()) && (r < n))) {
          Code03_FallingWaterSmallestFlowerPot::push((r++));
        }
        if (Code03_FallingWaterSmallestFlowerPot::ok()) {
          (ans = jmin(ans, (arr[(r - 1)][0] - arr[l][0])));
        }
        Code03_FallingWaterSmallestFlowerPot::pop(l);
      }
    }
    return ans;
  }
  static bool ok() {
    int max = ((maxh < maxt) ? arr[maxDeque[maxh]][1] : 0);
    int min = ((minh < mint) ? arr[minDeque[minh]][1] : 0);
    return ((max - min) >= d);
  }
  static void push(int r) {
    while (((maxh < maxt) && (arr[maxDeque[(maxt - 1)]][1] <= arr[r][1]))) {
      (maxt--);
    }
    (maxDeque[(maxt++)] = r);
    while (((minh < mint) && (arr[minDeque[(mint - 1)]][1] >= arr[r][1]))) {
      (mint--);
    }
    (minDeque[(mint++)] = r);
  }
  static void pop(int l) {
    if (((maxh < maxt) && (maxDeque[maxh] == l))) {
      (maxh++);
    }
    if (((minh < mint) && (minDeque[minh] == l))) {
      (minh++);
    }
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code03_FallingWaterSmallestFlowerPot::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 接取落水的最小花盆
// 老板需要你帮忙浇花。给出 N 滴水的坐标，y 表示水滴的高度，x 表示它下落到 x
轴的位置
// 每滴水以每秒1个单位长度的速度下落。你需要把花盆放在 x 轴上的某个位置
// 使得从被花盆接着的第 1 滴水开始，到被花盆接着的最后 1
滴水结束，之间的时间差至少为 D
// 我们认为，只要水滴落到 x 轴上，与花盆的边沿对齐，就认为被接住
// 给出 N 滴水的坐标和 D 的大小，请算出最小的花盆的宽度 W
// 测试链接 : https://www.luogu.com.cn/problem/P2698
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下的code，提交时请把类名改成"Main"，可以直接通过
                // arr[0...n-1][2]: x(0), 高度(1)
                // 所有水滴根据x排序，谁小谁在前
                        // [l,r) : 水滴的编号
                        // l : 当前花盘的左边界，arr[l][0]
        // 当前窗口 最大值 - 最小值 是不是>=d
*/

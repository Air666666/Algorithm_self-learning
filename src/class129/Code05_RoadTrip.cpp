// Source: src/class129/Code05_RoadTrip.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code05_RoadTrip {
  inline static int MAXN = 100002;
  inline static int MAXP = 20;
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static Array<int> to1 = make_array<int>(MAXN);
  inline static Array<int> dist1 = make_array<int>(MAXN);
  inline static Array<int> to2 = make_array<int>(MAXN);
  inline static Array<int> dist2 = make_array<int>(MAXN);
  inline static Array<Array<int>> rank = make_array<int>(MAXN, 2);
  inline static Array<int> last = make_array<int>(MAXN);
  inline static Array<int> next = make_array<int>(MAXN);
  inline static Array<Array<int>> stto = make_array<int>(MAXN, (MAXP + 1));
  inline static Array<Array<int>> stdist = make_array<int>(MAXN, (MAXP + 1));
  inline static Array<Array<int>> sta = make_array<int>(MAXN, (MAXP + 1));
  inline static Array<Array<int>> stb = make_array<int>(MAXN, (MAXP + 1));
  inline static int n = {};
  inline static int m = {};
  inline static int a = {};
  inline static int b = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code05_RoadTrip() {}
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    (n = static_cast<int>(in.nval));
    for (int i = 1; (i <= n); (i++)) {
      in.nextToken();
      (arr[i] = static_cast<int>(in.nval));
    }
    Code05_RoadTrip::near();
    Code05_RoadTrip::st();
    in.nextToken();
    int x0 = static_cast<int>(in.nval);
    out.println(Code05_RoadTrip::best(x0));
    in.nextToken();
    (m = static_cast<int>(in.nval));
    for (int i = 1; (i <= m); (i++)) {
      in.nextToken();
      int s = static_cast<int>(in.nval);
      in.nextToken();
      int x = static_cast<int>(in.nval);
      Code05_RoadTrip::travel(s, x);
      out.println(((a + String(u" ")) + b));
    }
    out.flush();
    out.close();
    br.close();
  }
  static void near() {
    for (int i = 1; (i <= n); (i++)) {
      (rank[i][0] = i);
      (rank[i][1] = arr[i]);
    }
    j::sort(rank, 1, (n + 1),
            [=](Array<int> a, Array<int> b) { return (a[1] - b[1]); });
    (rank[0][0] = 0);
    (rank[(n + 1)][0] = 0);
    for (int i = 1; (i <= n); (i++)) {
      (last[rank[i][0]] = rank[(i - 1)][0]);
      (next[rank[i][0]] = rank[(i + 1)][0]);
    }
    for (int i = 1; (i <= n); (i++)) {
      (to1[i] = 0);
      (dist1[i] = 0);
      (to2[i] = 0);
      (dist2[i] = 0);
      Code05_RoadTrip::update(i, last[i]);
      Code05_RoadTrip::update(i, last[last[i]]);
      Code05_RoadTrip::update(i, next[i]);
      Code05_RoadTrip::update(i, next[next[i]]);
      Code05_RoadTrip::delete_method(i);
    }
  }
  static void update(int i, int j) {
    if ((j == 0)) {
      return;
    }
    int dist = std::abs((arr[i] - arr[j]));
    if ((((to1[i] == 0) || (dist < dist1[i])) ||
         ((dist == dist1[i]) && (arr[j] < arr[to1[i]])))) {
      (to2[i] = to1[i]);
      (dist2[i] = dist1[i]);
      (to1[i] = j);
      (dist1[i] = dist);
    } else if ((((to2[i] == 0) || (dist < dist2[i])) ||
                ((dist == dist2[i]) && (arr[j] < arr[to2[i]])))) {
      (to2[i] = j);
      (dist2[i] = dist);
    }
  }
  static void delete_method(int i) {
    int l = last[i];
    int r = next[i];
    if ((l != 0)) {
      (next[l] = r);
    }
    if ((r != 0)) {
      (last[r] = l);
    }
  }
  static void st() {
    for (int i = 1; (i <= n); (i++)) {
      (stto[i][0] = to1[to2[i]]);
      (stdist[i][0] = (dist2[i] + dist1[to2[i]]));
      (sta[i][0] = dist2[i]);
      (stb[i][0] = dist1[to2[i]]);
    }
    for (int p = 1; (p <= MAXP); (p++)) {
      for (int i = 1; (i <= n); (i++)) {
        (stto[i][p] = stto[stto[i][(p - 1)]][(p - 1)]);
        if ((stto[i][p] != 0)) {
          (stdist[i][p] =
               (stdist[i][(p - 1)] + stdist[stto[i][(p - 1)]][(p - 1)]));
          (sta[i][p] = (sta[i][(p - 1)] + sta[stto[i][(p - 1)]][(p - 1)]));
          (stb[i][p] = (stb[i][(p - 1)] + stb[stto[i][(p - 1)]][(p - 1)]));
        }
      }
    }
  }
  static int best(int x0) {
    int ans = 0;
    double min = std::numeric_limits<double>::max();
    double cur = {};
    for (int i = 1; (i < n); (i++)) {
      Code05_RoadTrip::travel(i, x0);
      (cur = ((b == 0) ? std::numeric_limits<double>::max()
                       : jdiv(static_cast<double>(a), static_cast<double>(b))));
      if ((((ans == 0) || (cur < min)) ||
           ((cur == min) && (arr[i] > arr[ans])))) {
        (ans = i);
        (min = cur);
      }
    }
    return ans;
  }
  static void travel(int s, int x) {
    (a = 0);
    (b = 0);
    for (int p = MAXP; (p >= 0); (p--)) {
      if (((stto[s][p] != 0) && (x >= stdist[s][p]))) {
        (x -= stdist[s][p]);
        (a += sta[s][p]);
        (b += stb[s][p]);
        (s = stto[s][p]);
      }
    }
    if ((dist2[s] <= x)) {
      (a += dist2[s]);
    }
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code05_RoadTrip::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 开车旅行
// 给定一个长度为n的数组arr，下标1 ~ n范围，数组无重复值
// 近的定义、距离的定义，和题目4一致
// a和b同坐一辆车开始往右旅行，a先开车，b后开车，此后每到达一点都换人驾驶
//
如果a在某点驾驶，那么车去往该点右侧第二近的点，如果b在某点驾驶，那么车去往该点右侧第一近的点
// a和b从s位置出发，如果开车总距离超过x，或轮到某人时右侧无点可选，那么旅行停止
// 问题1 : 给定距离x0，返回1 ~ n-1中从哪个点出发，a行驶距离 /
b行驶距离，比值最小
//         如果从多个点出发时，比值都为最小，那么返回arr中的值最大的点
// 问题2 : 给定s、x，返回旅行停止时，a开了多少距离、b开了多少距离
// 问题1只调用1次
// 问题2调用m次，每组有不同的s、x
// 1 <= n、m、s <= 10^5
// -10^9 <= arr[i] <= 10^9
// 1 <= x0、x <= 10^9
// 测试链接 : https://www.luogu.com.cn/problem/P1081
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有用例
        // stto[i][p] : 从i位置出发，a和b轮流开2^p轮之后，车到达了几号点
        // stdist[i][p] : 从i位置出发，a和b轮流开2^p轮之后，总距离是多少
        // sta[i][p] : 从i位置出发，a和b轮流开2^p轮之后，a行驶了多少距离
        // stb[i][p] : 从i位置出发，a和b轮流开2^p轮之后，b行驶了多少距离
                // 倍增初始化
                // 生成倍增表
                        // cur这么设置更安全一些
*/

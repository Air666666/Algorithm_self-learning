// Source: src/class155/Code01_CityCapture1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_CityCapture1 {
  inline static int MAXN = 300001;
  inline static int n = {};
  inline static int m = {};
  inline static Array<i64> defend = make_array<i64>(MAXN);
  inline static Array<int> belong = make_array<int>(MAXN);
  inline static Array<int> type = make_array<int>(MAXN);
  inline static Array<i64> gain = make_array<i64>(MAXN);
  inline static Array<i64> attack = make_array<i64>(MAXN);
  inline static Array<int> first = make_array<int>(MAXN);
  inline static Array<int> deep = make_array<int>(MAXN);
  inline static Array<int> top = make_array<int>(MAXN);
  inline static Array<int> sacrifice = make_array<int>(MAXN);
  inline static Array<int> die = make_array<int>(MAXN);
  inline static Array<int> left = make_array<int>(MAXN);
  inline static Array<int> right = make_array<int>(MAXN);
  inline static Array<int> dist = make_array<int>(MAXN);
  inline static Array<i64> mul = make_array<i64>(MAXN);
  inline static Array<i64> add = make_array<i64>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_CityCapture1() {}
  static void prepare() {
    (dist[0] = (-1));
    for (int i = 1; (i <= m); (i++)) {
      (left[i] = (right[i] = (dist[i] = 0)));
      (mul[i] = 1);
      (add[i] = 0);
    }
    for (int i = 1; (i <= n); (i++)) {
      (sacrifice[i] = (top[i] = 0));
    }
  }
  static void upgrade(int i, int t, i64 v) {
    if ((t == 0)) {
      (attack[i] += v);
      (add[i] += v);
    } else {
      (attack[i] *= v);
      (mul[i] *= v);
      (add[i] *= v);
    }
  }
  static void down(int i) {
    if (((mul[i] != 1) || (add[i] != 0))) {
      int l = left[i];
      int r = right[i];
      if ((l != 0)) {
        (attack[l] = ((attack[l] * mul[i]) + add[i]));
        (mul[l] = (mul[l] * mul[i]));
        (add[l] = ((add[l] * mul[i]) + add[i]));
      }
      if ((r != 0)) {
        (attack[r] = ((attack[r] * mul[i]) + add[i]));
        (mul[r] = (mul[r] * mul[i]));
        (add[r] = ((add[r] * mul[i]) + add[i]));
      }
      (mul[i] = 1);
      (add[i] = 0);
    }
  }
  static int merge(int i, int j) {
    if (((i == 0) || (j == 0))) {
      return (i + j);
    }
    int tmp = {};
    if ((attack[i] > attack[j])) {
      (tmp = i);
      (i = j);
      (j = tmp);
    }
    Code01_CityCapture1::down(i);
    (right[i] = Code01_CityCapture1::merge(right[i], j));
    if ((dist[left[i]] < dist[right[i]])) {
      (tmp = left[i]);
      (left[i] = right[i]);
      (right[i] = tmp);
    }
    (dist[i] = (dist[right[i]] + 1));
    return i;
  }
  static int pop(int i) {
    Code01_CityCapture1::down(i);
    int ans = Code01_CityCapture1::merge(left[i], right[i]);
    (left[i] = (right[i] = (dist[i] = 0)));
    return ans;
  }
  static void compute() {
    (deep[1] = 1);
    for (int i = 2; (i <= n); (i++)) {
      (deep[i] = (deep[belong[i]] + 1));
    }
    for (int i = 1; (i <= m); (i++)) {
      if ((top[first[i]] == 0)) {
        (top[first[i]] = i);
      } else {
        (top[first[i]] = Code01_CityCapture1::merge(top[first[i]], i));
      }
    }
    for (int i = n; (i >= 1); (i--)) {
      while (((top[i] != 0) && (attack[top[i]] < defend[i]))) {
        (die[top[i]] = i);
        (sacrifice[i]++);
        (top[i] = Code01_CityCapture1::pop(top[i]));
      }
      if ((top[i] != 0)) {
        Code01_CityCapture1::upgrade(top[i], type[i], gain[i]);
        if ((top[belong[i]] == 0)) {
          (top[belong[i]] = top[i]);
        } else {
          (top[belong[i]] = Code01_CityCapture1::merge(top[belong[i]], top[i]));
        }
      }
    }
  }
  static void java_main(Array<String> args) {
    IO io = IO();
    (n = io.nextInt());
    (m = io.nextInt());
    Code01_CityCapture1::prepare();
    for (int i = 1; (i <= n); (i++)) {
      (defend[i] = io.nextLong());
    }
    for (int i = 2; (i <= n); (i++)) {
      (belong[i] = io.nextInt());
      (type[i] = io.nextInt());
      (gain[i] = io.nextLong());
    }
    for (int i = 1; (i <= m); (i++)) {
      (attack[i] = io.nextLong());
      (first[i] = io.nextInt());
    }
    Code01_CityCapture1::compute();
    for (int i = 1; (i <= n); (i++)) {
      io.println(sacrifice[i]);
    }
    for (int i = 1; (i <= m); (i++)) {
      io.println((deep[first[i]] - deep[die[i]]));
    }
    io.flush();
    io.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code01_CityCapture1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 城池攻占，java版
//
一共有n个城市，1号城市是城市树的头，每个城市都有防御值、上级城市编号、奖励类型、奖励值
// 如果奖励类型为0，任何骑士攻克这个城市后，攻击力会加上奖励值
// 如果奖励类型为1，任何骑士攻克这个城市后，攻击力会乘以奖励值
// 任何城市的上级编号 <
这座城市的编号，1号城市没有上级城市编号、奖励类型、奖励值
// 一共有m个骑士，每个骑士都有攻击力、第一次攻击的城市
// 如果骑士攻击力 >=
城市防御值，当前城市会被攻占，骑士获得奖励，继续攻击上级城市
// 如果骑士攻击力  < 城市防御值，那么骑士会在该城市牺牲，没有后续动作了
// 所有骑士都是独立的，不会影响其他骑士攻击这座城池的结果
// 打印每个城市牺牲的骑士数量，打印每个骑士攻占的城市数量
// 1 <= n、m <= 3 * 10^5，攻击值的增加也不会超过long类型范围
// 测试链接 : https://www.luogu.com.cn/problem/P3261
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 城市防御值
        // 上级城市编号
        // 奖励类型
        // 奖励值
        // 骑士攻击力
        // 骑士第一次攻击的城市
        // 城市在城市树中的深度
        // 城市拥有的骑士列表，用小根堆左偏树组织，最弱的骑士是头
        // 每个城市牺牲人数统计
        // 每个骑士死在了什么城市
        // 左偏树需要
        // 懒更新信息，攻击力应该乘多少
        // 懒更新信息，攻击力应该加多少
        // 读写工具类
*/

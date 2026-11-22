// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P1196

// Source: src/class156/Code04_LegendOfHeroes.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_LegendOfHeroes {
  inline static int MAXN = 30001;
  inline static int n = 30000;
  inline static Array<int> father = make_array<int>(MAXN);
  inline static Array<int> dist = make_array<int>(MAXN);
  inline static Array<int> size = make_array<int>(MAXN);
  inline static Array<int> stack = make_array<int>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_LegendOfHeroes() {}
  static void prepare() {
    for (int i = 1; (i <= n); (i++)) {
      (father[i] = i);
      (dist[i] = 0);
      (size[i] = 1);
    }
  }
  static int find(int i) {
    int si = 0;
    while ((i != father[i])) {
      (stack[(++si)] = i);
      (i = father[i]);
    }
    (stack[(si + 1)] = i);
    for (int j = si; (j >= 1); (j--)) {
      (father[stack[j]] = i);
      (dist[stack[j]] += dist[stack[(j + 1)]]);
    }
    return i;
  }
  static void union_method(int l, int r) {
    int lf = Code04_LegendOfHeroes::find(l);
    int rf = Code04_LegendOfHeroes::find(r);
    if ((lf != rf)) {
      (father[lf] = rf);
      (dist[lf] += size[rf]);
      (size[rf] += size[lf]);
    }
  }
  static int query(int l, int r) {
    if ([&]() {
          auto jleft = Code04_LegendOfHeroes::find(l);
          auto jright = Code04_LegendOfHeroes::find(r);
          return (jleft != jright);
        }()) {
      return (-1);
    }
    return (std::abs((dist[l] - dist[r])) - 1);
  }
  static void java_main(Array<String> args) {
    Code04_LegendOfHeroes::prepare();
    IO io = IO();
    int t = io.nextInt();
    String op = {};
    {
      int i = 1;
      int l = {};
      int r = {};
      for (; (i <= t); (i++)) {
        (op = io.next());
        (l = io.nextInt());
        (r = io.nextInt());
        if (op.equals(String(u"M"))) {
          Code04_LegendOfHeroes::union_method(l, r);
        } else {
          io.println(Code04_LegendOfHeroes::query(l, r));
        }
      }
    }
    io.flush();
    io.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code04_LegendOfHeroes::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 银河英雄传说
// 一共有30000搜战舰，编号1~30000，一开始每艘战舰各自成一队
// 如果若干战舰变成一队，那么队伍里的所有战舰竖直地排成一列
// 实现如下两种操作，操作一共调用t次
// M l r : 合并l号战舰所在队伍和r号战舰所在队伍
//         l号战舰的队伍，整体移动到，r号战舰所在队伍的最末尾战舰的后面
//         如果l号战舰和r号战舰已经是一队，不进行任何操作
// C l r : 如果l号战舰和r号战舰不在一个队伍，打印-1
//         如果l号战舰和r号战舰在一个队伍，打印它俩中间隔着几艘战舰
// 1 <= t <= 5 * 10^5
// 测试链接 : https://www.luogu.com.cn/problem/P1196
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 递归会爆栈，所以用迭代来寻找并查集代表节点
        // 迭代的方式实现find，递归方式实现会爆栈
        // 读写工具类
*/

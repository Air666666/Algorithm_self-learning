// Source: src/class142/Code01_DifferenceConstraints1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_DifferenceConstraints1 {
  inline static int MAXN = 5001;
  inline static int MAXM = 10001;
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> next = make_array<int>(MAXM);
  inline static Array<int> to = make_array<int>(MAXM);
  inline static Array<int> weight = make_array<int>(MAXM);
  inline static int cnt = {};
  inline static Array<int> dist = make_array<int>(MAXN);
  inline static Array<int> update = make_array<int>(MAXN);
  inline static int MAXQ = 5000001;
  inline static Array<int> queue = make_array<int>(MAXQ);
  inline static int h = {};
  inline static int t = {};
  inline static Array<bool> enter = make_array<bool>(MAXN);
  inline static int n = {};
  inline static int m = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_DifferenceConstraints1() {}
  static void prepare() {
    (cnt = 1);
    (h = (t = 0));
    j::fill(head, 0, (n + 1), 0);
    j::fill(dist, 0, (n + 1), std::numeric_limits<int>::max());
    j::fill(update, 0, (n + 1), 0);
    j::fill(enter, 0, (n + 1), false);
  }
  static void addEdge(int u, int v, int w) {
    (next[cnt] = head[u]);
    (to[cnt] = v);
    (weight[cnt] = w);
    (head[u] = (cnt++));
  }
  static bool spfa(int s) {
    (dist[s] = 0);
    (update[s] = 1);
    (queue[(t++)] = s);
    (enter[s] = true);
    while ((h < t)) {
      int u = queue[(h++)];
      (enter[u] = false);
      {
        int ei = head[u];
        int v = {};
        int w = {};
        for (; (ei > 0); (ei = next[ei])) {
          (v = to[ei]);
          (w = weight[ei]);
          if ((dist[v] > (dist[u] + w))) {
            (dist[v] = (dist[u] + w));
            if ((!enter[v])) {
              if (((++update[v]) > n)) {
                return true;
              }
              (queue[(t++)] = v);
              (enter[v] = true);
            }
          }
        }
      }
    }
    return false;
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    (n = static_cast<int>(in.nval));
    in.nextToken();
    (m = static_cast<int>(in.nval));
    Code01_DifferenceConstraints1::prepare();
    for (int i = 1; (i <= n); (i++)) {
      Code01_DifferenceConstraints1::addEdge(0, i, 0);
    }
    {
      int i = 1;
      int u = {};
      int v = {};
      int w = {};
      for (; (i <= m); (i++)) {
        in.nextToken();
        (u = static_cast<int>(in.nval));
        in.nextToken();
        (v = static_cast<int>(in.nval));
        in.nextToken();
        (w = static_cast<int>(in.nval));
        Code01_DifferenceConstraints1::addEdge(v, u, w);
      }
    }
    if (Code01_DifferenceConstraints1::spfa(0)) {
      out.println(String(u"NO"));
    } else {
      for (int i = 1; (i <= n); (i++)) {
        out.print((dist[i] + String(u" ")));
      }
      out.println();
    }
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code01_DifferenceConstraints1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 负环和差分约束模版题(转化成形式1进而转化成判断负环)
// 一共有n个变量，编号1~n，给定m个不等式，每个不等式的形式为
// Xi - Xj <= Ci，其中Xi和Xj为变量，Ci为常量
// 如果不等式存在矛盾导致无解，打印"NO"
// 如果有解，打印满足所有不等式的其中一组解(X1, X2...)
// 1 <= n、m <= 5 * 10^3
// -10^4 <= Ci <= +10^4
// 测试链接 : https://www.luogu.com.cn/problem/P5960
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 链式前向星需要
        // spfa需要
                // 所有距离先设置成最大值
        // 来自讲解065，spfa判断负环，s是超级源点
                                                //
注意判断逻辑和讲解065的代码不一样
                                                // 因为节点0是额外增加的超级源点
                                                //
所以节点数量增加了1个，所以这么判断
                // 0号点是连通超级源点，保证图的连通性
                        // 形式1的连边方式
*/

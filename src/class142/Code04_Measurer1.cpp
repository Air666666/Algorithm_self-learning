// Source: src/class142/Code04_Measurer1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_Measurer1 {
  inline static int MAXN = 1002;
  inline static int MAXM = 3001;
  inline static double INF = 1e10;
  inline static double sml = 1e-6;
  inline static int n = {};
  inline static int m1 = {};
  inline static int m2 = {};
  inline static Array<Array<int>> vow = make_array<int>(MAXN, 4);
  inline static Array<Array<int>> score = make_array<int>(MAXN, 2);
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> next = make_array<int>(MAXM);
  inline static Array<int> to = make_array<int>(MAXM);
  inline static Array<double> weight = make_array<double>(MAXM);
  inline static int cnt = {};
  inline static Array<double> dist = make_array<double>(MAXN);
  inline static Array<int> update = make_array<int>(MAXN);
  inline static int MAXQ = 1000001;
  inline static Array<int> queue = make_array<int>(MAXQ);
  inline static int h = {};
  inline static int t = {};
  inline static Array<bool> enter = make_array<bool>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_Measurer1() {}
  static void prepare() {
    (cnt = 1);
    (h = (t = 0));
    j::fill(head, 0, (n + 2), 0);
    j::fill(dist, 0, (n + 2), INF);
    j::fill(update, 0, (n + 2), 0);
    j::fill(enter, 0, (n + 2), false);
  }
  static void addEdge(int u, int v, double w) {
    (next[cnt] = head[u]);
    (to[cnt] = v);
    (weight[cnt] = w);
    (head[u] = (cnt++));
  }
  static double compute() {
    double l = 0;
    double r = INF;
    double m = {};
    double ans = 0;
    while (((r - l) >= sml)) {
      (m = jdiv((l + r), 2));
      if (Code04_Measurer1::check(m)) {
        (ans = m);
        (l = (m + sml));
      } else {
        (r = (m - sml));
      }
    }
    return ans;
  }
  static bool check(double limit) {
    Code04_Measurer1::prepare();
    for (int i = 1; (i <= n); (i++)) {
      Code04_Measurer1::addEdge(0, i, 0);
    }
    for (int i = 1; (i <= m1); (i++)) {
      if ((vow[i][0] == 1)) {
        if ((((-limit) + vow[i][3]) >= 0)) {
          Code04_Measurer1::addEdge(vow[i][1], vow[i][2],
                                    (-std::log(((-limit) + vow[i][3]))));
        }
      } else {
        Code04_Measurer1::addEdge(vow[i][1], vow[i][2],
                                  std::log(((limit + vow[i][3]) - sml)));
      }
    }
    for (int i = 1; (i <= m2); (i++)) {
      Code04_Measurer1::addEdge((n + 1), score[i][0], std::log(score[i][1]));
      Code04_Measurer1::addEdge(score[i][0], (n + 1), (-std::log(score[i][1])));
    }
    return Code04_Measurer1::spfa(0);
  }
  static bool spfa(int s) {
    (dist[s] = 0);
    (update[s] = 1);
    (queue[(t++)] = s);
    (enter[s] = true);
    while ((h < t)) {
      int u = queue[(h++)];
      (enter[u] = false);
      for (int ei = head[u]; (ei > 0); (ei = next[ei])) {
        int v = to[ei];
        double w = weight[ei];
        if ((dist[v] > (dist[u] + w))) {
          (dist[v] = (dist[u] + w));
          if ((!enter[v])) {
            if (((++update[v]) > (n + 1))) {
              return true;
            }
            (queue[(t++)] = v);
            (enter[v] = true);
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
    (m1 = static_cast<int>(in.nval));
    in.nextToken();
    (m2 = static_cast<int>(in.nval));
    for (int i = 1; (i <= m1); (i++)) {
      in.nextToken();
      (vow[i][0] = static_cast<int>(in.nval));
      in.nextToken();
      (vow[i][1] = static_cast<int>(in.nval));
      in.nextToken();
      (vow[i][2] = static_cast<int>(in.nval));
      in.nextToken();
      (vow[i][3] = static_cast<int>(in.nval));
    }
    for (int i = 1; (i <= m2); (i++)) {
      in.nextToken();
      (score[i][0] = static_cast<int>(in.nval));
      in.nextToken();
      (score[i][1] = static_cast<int>(in.nval));
    }
    double ans = Code04_Measurer1::compute();
    if ((ans == 0)) {
      out.println(String(u"-1"));
    } else {
      out.println(ans);
    }
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code04_Measurer1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 倍杀测量者
// 如果 A的分数 >= B的分数 * k，k是正实数，就称 A k倍杀 B，或称 B被A k倍杀了
//
一场比赛中，一共有n个选手，有m1条誓言记录，有m2条选手得分记录，得分只可能是正实数
// 类型1的誓言 u v k : 选手u 没有k倍杀 选手v，那么选手u就穿女装
// 类型2的誓言 u v k : 选手u 被选手v k倍杀了，那么选手u就穿女装
// 选手的得分    u w :
选手u得了w分，如果某选手没有得分记录，按照尽量不穿女装的情况推测
//
你希望看到比赛后有人穿女装，但不想看到很多人穿女装，于是想制定正实数ans，效果如下
//
类型1的誓言，比例调整成(k-ans)，类型2的誓言，比例调整成(k+ans)，即提高了穿女装的条件
//
计算ans最大多少，依然有人穿女装，保留小数点后4位，如果不干预也没人穿女装，返回-1
// 1 <= n, m1, m2 <= 1000
// 1 <= k <= 10
// 1 <= w <= 10^9
// 测试链接 : https://www.luogu.com.cn/problem/P4926
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 誓言记录(誓言类型, u, v, k)
        // 得分记录(u, w)
        // 链式前向星需要
        // spfa需要
        // 是否有人穿女装
                // 0号点是连通超级源点，保证图的连通
                // 倍杀关系的建边
                                //
课上的代码没有这个判断，加上才是正确的，防止log里出现负数
                                //
因为类型2的誓言是<关系，所以减去最小精度后，就可以认为是<=关系
                // n+1号点是限制超级源点，保证确定得分的选手之间的关系
                // 本题测试数据有限，两个超级源点合并居然也能通过
                // 原理上两个超级源点一定要分开，课上进行了重点讲解
                                                //
0...n+1号点，一共n+2个点，所以这里判断 > n + 1
*/

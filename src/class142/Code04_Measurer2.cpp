// Source: src/class142/Code04_Measurer2.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_Measurer2 {
  inline static int MAXN = 1002;
  inline static int MAXM = 3001;
  inline static double INF = 1e10;
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
  Code04_Measurer2() {}
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
    for (int i = 1; (i <= 60); (i++)) {
      (m = jdiv((l + r), 2));
      if (Code04_Measurer2::check(m)) {
        (l = m);
      } else {
        (r = m);
      }
    }
    return l;
  }
  static bool check(double limit) {
    Code04_Measurer2::prepare();
    for (int i = 1; (i <= n); (i++)) {
      Code04_Measurer2::addEdge(0, i, 0);
    }
    for (int i = 1; (i <= m1); (i++)) {
      if ((vow[i][0] == 1)) {
        if ((((-limit) + vow[i][3]) >= 0)) {
          Code04_Measurer2::addEdge(vow[i][1], vow[i][2],
                                    (-std::log(((-limit) + vow[i][3]))));
        }
      } else {
        Code04_Measurer2::addEdge(vow[i][1], vow[i][2],
                                  std::log((limit + vow[i][3])));
      }
    }
    for (int i = 1; (i <= m2); (i++)) {
      Code04_Measurer2::addEdge((n + 1), score[i][0], std::log(score[i][1]));
      Code04_Measurer2::addEdge(score[i][0], (n + 1), (-std::log(score[i][1])));
    }
    return Code04_Measurer2::spfa(0);
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
    double ans = Code04_Measurer2::compute();
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
  Code04_Measurer2::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 题目4，倍杀测量者，另一种二分的写法
// 思路是不变的，二分的写法多种多样
// 代码中打注释的位置，就是更简单的二分逻辑，其他代码没有变化
// 测试链接 : https://www.luogu.com.cn/problem/P4926
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 另一种二分的写法
                // 二分进行60次，足够达到题目要求的精度
                // 二分完成后，l就是答案
                                //
课上的代码没有这个判断，加上才是正确的，防止log里出现负数
*/

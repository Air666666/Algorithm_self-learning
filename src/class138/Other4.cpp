// Source: src/class138/Other4.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Other4 {
  inline static int MAXN = 3001;
  inline static int MAXM = 10001;
  inline static double MAXE = 1e7;
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> next = make_array<int>(MAXM);
  inline static Array<int> to = make_array<int>(MAXM);
  inline static Array<double> weight = make_array<double>(MAXM);
  inline static int cnt = {};
  inline static Array<double> value = make_array<double>(MAXN);
  inline static Array<bool> path = make_array<bool>(MAXN);
  inline static int n = {};
  inline static int m = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Other4() {}
  static void prepare() {
    (cnt = 1);
    j::fill(head, 1, (n + 1), 0);
  }
  static void addEdge(int u, int v, double w) {
    (next[cnt] = head[u]);
    (to[cnt] = v);
    (weight[cnt] = w);
    (head[u] = (cnt++));
  }
  static bool check(double x) {
    j::fill(value, 1, (n + 1), 0);
    j::fill(path, 1, (n + 1), false);
    return Other4::dfs(0, x);
  }
  static bool dfs(int u, double x) {
    if ((u == 0)) {
      for (int i = 1; (i <= n); (i++)) {
        if (Other4::dfs(i, x)) {
          return true;
        }
      }
    } else {
      (path[u] = true);
      for (int e = head[u]; (e != 0); (e = next[e])) {
        int v = to[e];
        double w = (weight[e] - x);
        if ((value[v] > (value[u] + w))) {
          (value[v] = (value[u] + w));
          if ((path[v] || Other4::dfs(v, x))) {
            return true;
          }
        }
      }
      (path[u] = false);
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
    Other4::prepare();
    for (int i = 1; (i <= m); (i++)) {
      in.nextToken();
      int u = static_cast<int>(in.nval);
      in.nextToken();
      int v = static_cast<int>(in.nval);
      in.nextToken();
      double w = in.nval;
      Other4::addEdge(u, v, w);
    }
    double l = (-MAXE);
    double r = MAXE;
    double x = {};
    for (int i = 1; (i <= 60); (i++)) {
      (x = jdiv((l + r), 2));
      if (Other4::check(x)) {
        (r = x);
      } else {
        (l = x);
      }
    }
    out.printf(String(u"%.8f\n"), l);
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Other4::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 题目4，最小圈，另一种二分的写法
// 思路是不变的，二分的写法多种多样
// 代码中打注释的位置，就是更简单的二分逻辑，其他代码没有变化
// 测试链接 : https://www.luogu.com.cn/problem/P3199
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
                // 二分进行60次，足够达到题目要求的精度
                // 二分完成后，l就是答案
*/

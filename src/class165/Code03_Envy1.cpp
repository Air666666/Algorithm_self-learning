// Source: src/class165/Code03_Envy1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_Envy1 {
  inline static int MAXN = 500001;
  inline static int n = {};
  inline static int m = {};
  inline static int q = {};
  inline static int k = {};
  inline static Array<Array<int>> edge = make_array<int>(MAXN, 3);
  inline static Array<Array<int>> queries = make_array<int>(MAXN, 4);
  inline static Array<int> father = make_array<int>(MAXN);
  inline static Array<int> siz = make_array<int>(MAXN);
  inline static Array<Array<int>> rollback = make_array<int>(jshl(MAXN, 1), 2);
  inline static int opsize = {};
  inline static Array<bool> ans = make_array<bool>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_Envy1() {}
  static int find(int i) {
    while ((i != father[i])) {
      (i = father[i]);
    }
    return i;
  }
  static void union_method(int x, int y) {
    int fx = Code03_Envy1::find(x);
    int fy = Code03_Envy1::find(y);
    if ((siz[fx] < siz[fy])) {
      int tmp = fx;
      (fx = fy);
      (fy = tmp);
    }
    (father[fy] = fx);
    (siz[fx] += siz[fy]);
    (rollback[(++opsize)][0] = fx);
    (rollback[opsize][1] = fy);
  }
  static void undo() {
    int fx = rollback[opsize][0];
    int fy = rollback[(opsize--)][1];
    (father[fy] = fy);
    (siz[fx] -= siz[fy]);
  }
  static void prepare() {
    for (int i = 1; (i <= n); (i++)) {
      (father[i] = i);
      (siz[i] = 1);
    }
    j::sort(edge, 1, (m + 1),
            [=](Array<int> a, Array<int> b) { return (a[2] - b[2]); });
    j::sort(queries, 1, (k + 1), [=](Array<int> a, Array<int> b) {
      return ((a[2] != b[2]) ? (a[2] - b[2]) : (a[3] - b[3]));
    });
    j::fill(ans, 1, (q + 1), true);
  }
  static void compute() {
    int ei = 1;
    int queryId = {};
    int unionCnt = {};
    {
      int l = 1;
      int r = 1;
      for (; (l <= k); (l = (++r))) {
        while (((((r + 1) <= k) && (queries[l][2] == queries[(r + 1)][2])) &&
                (queries[l][3] == queries[(r + 1)][3]))) {
          (r++);
        }
        for (; ((ei <= m) && (edge[ei][2] < queries[l][2])); (ei++)) {
          if ([&]() {
                auto jleft = Code03_Envy1::find(edge[ei][0]);
                auto jright = Code03_Envy1::find(edge[ei][1]);
                return (jleft != jright);
              }()) {
            Code03_Envy1::union_method(edge[ei][0], edge[ei][1]);
          }
        }
        (queryId = queries[l][3]);
        if ((!ans[queryId])) {
          continue;
        }
        (unionCnt = 0);
        for (int i = l; (i <= r); (i++)) {
          if ([&]() {
                auto jleft = Code03_Envy1::find(queries[i][0]);
                auto jright = Code03_Envy1::find(queries[i][1]);
                return (jleft == jright);
              }()) {
            (ans[queryId] = false);
            break;
          } else {
            Code03_Envy1::union_method(queries[i][0], queries[i][1]);
            (unionCnt++);
          }
        }
        for (int i = 1; (i <= unionCnt); (i++)) {
          Code03_Envy1::undo();
        }
      }
    }
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    (n = static_cast<int>(in.nval));
    in.nextToken();
    (m = static_cast<int>(in.nval));
    for (int i = 1; (i <= m); (i++)) {
      in.nextToken();
      (edge[i][0] = static_cast<int>(in.nval));
      in.nextToken();
      (edge[i][1] = static_cast<int>(in.nval));
      in.nextToken();
      (edge[i][2] = static_cast<int>(in.nval));
    }
    in.nextToken();
    (q = static_cast<int>(in.nval));
    (k = 0);
    {
      int i = 1;
      int s = {};
      for (; (i <= q); (i++)) {
        in.nextToken();
        (s = static_cast<int>(in.nval));
        {
          int j = 1;
          int ei = {};
          for (; (j <= s); (j++)) {
            in.nextToken();
            (ei = static_cast<int>(in.nval));
            (queries[(++k)][0] = edge[ei][0]);
            (queries[k][1] = edge[ei][1]);
            (queries[k][2] = edge[ei][2]);
            (queries[k][3] = i);
          }
        }
      }
    }
    Code03_Envy1::prepare();
    Code03_Envy1::compute();
    for (int i = 1; (i <= q); (i++)) {
      if (ans[i]) {
        out.println(String(u"YES"));
      } else {
        out.println(String(u"NO"));
      }
    }
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code03_Envy1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 同在最小生成树里，java版
// 一共有n个点，m条无向边，每条边有边权，图保证是连通的
// 一共有q次查询，每条查询都给定参数k，表示该查询涉及k条边
// 然后依次给出k条边的编号，打印这k条边能否同时出现在一颗最小生成树上
// 1 <= n、m、q、所有查询涉及边的总量 <= 5 * 10^5
// 测试链接 : https://www.luogu.com.cn/problem/CF891C
// 测试链接 : https://codeforces.com/problemset/problem/891/C
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 节点u、节点v、边权w
        // 节点u、节点v、边权w、问题编号i
        // 可撤销并查集
        // 答案数组
                        //
添加小于当前边权的边，利用Kruskal算法增加连通性，ei是不回退的
*/

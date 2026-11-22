// Source: src/class174/Code05_Lcm1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code05_Lcm1 {
  inline static int MAXN = 50001;
  inline static int MAXM = 100001;
  inline static int MAXQ = 50001;
  inline static int n = {};
  inline static int m = {};
  inline static int q = {};
  inline static int blen = {};
  inline static int bnum = {};
  inline static Array<int> eu = make_array<int>(MAXM);
  inline static Array<int> ev = make_array<int>(MAXM);
  inline static Array<int> ea = make_array<int>(MAXM);
  inline static Array<int> eb = make_array<int>(MAXM);
  inline static Array<int> qu = make_array<int>(MAXQ);
  inline static Array<int> qv = make_array<int>(MAXQ);
  inline static Array<int> qa = make_array<int>(MAXQ);
  inline static Array<int> qb = make_array<int>(MAXQ);
  inline static Array<int> edge = make_array<int>(MAXM);
  inline static Array<int> query = make_array<int>(MAXQ);
  inline static Array<int> cur = make_array<int>(MAXQ);
  inline static int cursiz = 0;
  inline static Array<int> fa = make_array<int>(MAXN);
  inline static Array<int> siz = make_array<int>(MAXN);
  inline static Array<int> maxa = make_array<int>(MAXN);
  inline static Array<int> maxb = make_array<int>(MAXN);
  inline static Array<Array<int>> rollback = make_array<int>(MAXN, 5);
  inline static int opsize = 0;
  inline static Array<bool> ans = make_array<bool>(MAXQ);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code05_Lcm1() {}
  static void sort(Array<int> idx, Array<int> val, int l, int r) {
    if ((l >= r))
      return;
    int i = l;
    int j = r;
    int pivot = val[idx[jshr((l + r), 1)]];
    int tmp = {};
    while ((i <= j)) {
      while ((val[idx[i]] < pivot))
        (i++);
      while ((val[idx[j]] > pivot))
        (j--);
      if ((i <= j)) {
        (tmp = idx[i]);
        (idx[i] = idx[j]);
        (idx[j] = tmp);
        (i++);
        (j--);
      }
    }
    Code05_Lcm1::sort(idx, val, l, j);
    Code05_Lcm1::sort(idx, val, i, r);
  }
  static void build() {
    for (int i = 1; (i <= n); (i++)) {
      (fa[i] = i);
      (siz[i] = 1);
      (maxa[i] = (-1));
      (maxb[i] = (-1));
    }
  }
  static int find(int x) {
    while ((x != fa[x])) {
      (x = fa[x]);
    }
    return x;
  }
  static void union_method(int x, int y, int a, int b) {
    int fx = Code05_Lcm1::find(x);
    int fy = Code05_Lcm1::find(y);
    if ((siz[fx] < siz[fy])) {
      int tmp = fx;
      (fx = fy);
      (fy = tmp);
    }
    (rollback[(++opsize)][0] = fx);
    (rollback[opsize][1] = fy);
    (rollback[opsize][2] = siz[fx]);
    (rollback[opsize][3] = maxa[fx]);
    (rollback[opsize][4] = maxb[fx]);
    if ((fx != fy)) {
      (fa[fy] = fx);
      (siz[fx] += siz[fy]);
    }
    (maxa[fx] = jmax(jmax(maxa[fx], maxa[fy]), a));
    (maxb[fx] = jmax(jmax(maxb[fx], maxb[fy]), b));
  }
  static void undo() {
    {
      int fx = {};
      int fy = {};
      for (; (opsize > 0); (opsize--)) {
        (fx = rollback[opsize][0]);
        (fy = rollback[opsize][1]);
        (fa[fy] = fy);
        (siz[fx] = rollback[opsize][2]);
        (maxa[fx] = rollback[opsize][3]);
        (maxb[fx] = rollback[opsize][4]);
      }
    }
  }
  static bool check(int x, int y, int a, int b) {
    int fx = Code05_Lcm1::find(x);
    int fy = Code05_Lcm1::find(y);
    return (((fx == fy) && (maxa[fx] == a)) && (maxb[fx] == b));
  }
  static void compute(int l, int r) {
    (cursiz = 0);
    for (int i = 1; (i <= q); (i++)) {
      if (((ea[edge[l]] <= qa[query[i]]) &&
           (((r + 1) > m) || (qa[query[i]] < ea[edge[(r + 1)]])))) {
        (cur[(++cursiz)] = query[i]);
      }
    }
    if ((cursiz > 0)) {
      Code05_Lcm1::build();
      Code05_Lcm1::sort(edge, eb, 1, (l - 1));
      {
        int i = 1;
        int j = 1;
        for (; (i <= cursiz); (i++)) {
          while (((j < l) && (eb[edge[j]] <= qb[cur[i]]))) {
            Code05_Lcm1::union_method(eu[edge[j]], ev[edge[j]], ea[edge[j]],
                                      eb[edge[j]]);
            (j++);
          }
          (opsize = 0);
          for (int k = l; (k <= r); (k++)) {
            if (((ea[edge[k]] <= qa[cur[i]]) && (eb[edge[k]] <= qb[cur[i]]))) {
              Code05_Lcm1::union_method(eu[edge[k]], ev[edge[k]], ea[edge[k]],
                                        eb[edge[k]]);
            }
          }
          (ans[cur[i]] = Code05_Lcm1::check(qu[cur[i]], qv[cur[i]], qa[cur[i]],
                                            qb[cur[i]]));
          Code05_Lcm1::undo();
        }
      }
    }
  }
  static void prepare() {
    int log2n = 0;
    while ((jshl(1, log2n) <= jshr(n, 1))) {
      (log2n++);
    }
    (blen = jmax(1, static_cast<int>(std::sqrt((m * log2n)))));
    (bnum = jdiv(((m + blen) - 1), blen));
    Code05_Lcm1::sort(edge, ea, 1, m);
    Code05_Lcm1::sort(query, qb, 1, q);
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (m = in.nextInt());
    for (int i = 1; (i <= m); (i++)) {
      (eu[i] = in.nextInt());
      (ev[i] = in.nextInt());
      (ea[i] = in.nextInt());
      (eb[i] = in.nextInt());
      (edge[i] = i);
    }
    (q = in.nextInt());
    for (int i = 1; (i <= q); (i++)) {
      (qu[i] = in.nextInt());
      (qv[i] = in.nextInt());
      (qa[i] = in.nextInt());
      (qb[i] = in.nextInt());
      (query[i] = i);
    }
    Code05_Lcm1::prepare();
    {
      int i = 1;
      int l = {};
      int r = {};
      for (; (i <= bnum); (i++)) {
        (l = (((i - 1) * blen) + 1));
        (r = jmin((i * blen), m));
        Code05_Lcm1::compute(l, r);
      }
    }
    for (int i = 1; (i <= q); (i++)) {
      out.println((ans[i] ? String(u"Yes") : String(u"No")));
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code05_Lcm1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 最小公倍数，java版
// 有n个点组成的无向图，依次给出m条无向边，每条边都有边权，并且边权很特殊
// u v a b : u到v的边，边权 = 2的a次方 * 3的b次方
// 接下来有q条查询，每条查询的格式如下
// u v a b : 从u出发可以随意选择边到达v，打印是否存在一条路径，满足如下条件
//           路径上所有边权的最小公倍数 = 2的a次方 * 3的b次方
// 1 <= n、q <= 5 * 10^4
// 1 <= m <= 10^5
// 测试链接 : https://www.luogu.com.cn/problem/P3247
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
                // 重要剪枝
                // 保证每条查询只在一个边的序列块中处理
                        // 重建并查集，目前没有任何连通性
                        // 本题直接排序能通过，就不写归并了
        // 读写工具类
*/

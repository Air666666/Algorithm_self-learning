// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P5443

// Source: src/class174/Code04_Bridge1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_Bridge1 {
  inline static int MAXN = 50001;
  inline static int MAXM = 100001;
  inline static int MAXQ = 100001;
  inline static int n = {};
  inline static int m = {};
  inline static int q = {};
  inline static int blen = {};
  inline static int bnum = {};
  inline static Array<int> u = make_array<int>(MAXM);
  inline static Array<int> v = make_array<int>(MAXM);
  inline static Array<int> w = make_array<int>(MAXM);
  inline static Array<int> op = make_array<int>(MAXQ);
  inline static Array<int> eid = make_array<int>(MAXQ);
  inline static Array<int> tow = make_array<int>(MAXQ);
  inline static Array<int> nid = make_array<int>(MAXQ);
  inline static Array<int> car = make_array<int>(MAXQ);
  inline static Array<int> edge = make_array<int>(MAXM);
  inline static Array<bool> change = make_array<bool>(MAXM);
  inline static Array<int> curw = make_array<int>(MAXM);
  inline static Array<int> operate = make_array<int>(MAXQ);
  inline static Array<int> query = make_array<int>(MAXQ);
  inline static Array<int> update = make_array<int>(MAXQ);
  inline static Array<int> fa = make_array<int>(MAXN);
  inline static Array<int> siz = make_array<int>(MAXN);
  inline static Array<Array<int>> rollback = make_array<int>(MAXM, 2);
  inline static int opsize = 0;
  inline static Array<int> arr1 = make_array<int>(MAXM);
  inline static Array<int> arr2 = make_array<int>(MAXM);
  inline static Array<int> ans = make_array<int>(MAXQ);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_Bridge1() {}
  static void sort(Array<int> idx, Array<int> val, int l, int r) {
    if ((l >= r))
      return;
    int i = l;
    int j = r;
    int pivot = val[idx[jshr((l + r), 1)]];
    int tmp = {};
    while ((i <= j)) {
      while ((val[idx[i]] > pivot))
        (i++);
      while ((val[idx[j]] < pivot))
        (j--);
      if ((i <= j)) {
        (tmp = idx[i]);
        (idx[i] = idx[j]);
        (idx[j] = tmp);
        (i++);
        (j--);
      }
    }
    Code04_Bridge1::sort(idx, val, l, j);
    Code04_Bridge1::sort(idx, val, i, r);
  }
  static void build() {
    for (int i = 1; (i <= n); (i++)) {
      (fa[i] = i);
      (siz[i] = 1);
    }
  }
  static int find(int x) {
    while ((x != fa[x])) {
      (x = fa[x]);
    }
    return x;
  }
  static void union_method(int x, int y) {
    int fx = Code04_Bridge1::find(x);
    int fy = Code04_Bridge1::find(y);
    if ((fx == fy)) {
      return;
    }
    if ((siz[fx] < siz[fy])) {
      int tmp = fx;
      (fx = fy);
      (fy = tmp);
    }
    (fa[fy] = fx);
    (siz[fx] += siz[fy]);
    (rollback[(++opsize)][0] = fx);
    (rollback[opsize][1] = fy);
  }
  static void undo() {
    {
      int fx = {};
      int fy = {};
      for (; (opsize > 0); (opsize--)) {
        (fx = rollback[opsize][0]);
        (fy = rollback[opsize][1]);
        (fa[fy] = fy);
        (siz[fx] -= siz[fy]);
      }
    }
  }
  static void merge() {
    int siz1 = 0;
    int siz2 = 0;
    for (int i = 1; (i <= m); (i++)) {
      if (change[edge[i]]) {
        (arr1[(++siz1)] = edge[i]);
      } else {
        (arr2[(++siz2)] = edge[i]);
      }
    }
    Code04_Bridge1::sort(arr1, w, 1, siz1);
    int i = 0;
    int p1 = 1;
    int p2 = 1;
    while (((p1 <= siz1) && (p2 <= siz2))) {
      (edge[(++i)] =
           ((w[arr1[p1]] >= w[arr2[p2]]) ? arr1[(p1++)] : arr2[(p2++)]));
    }
    while ((p1 <= siz1)) {
      (edge[(++i)] = arr1[(p1++)]);
    }
    while ((p2 <= siz2)) {
      (edge[(++i)] = arr2[(p2++)]);
    }
  }
  static void compute(int l, int r) {
    Code04_Bridge1::build();
    j::fill(change, false);
    int cntu = 0;
    int cntq = 0;
    for (int i = l; (i <= r); (i++)) {
      if ((op[operate[i]] == 1)) {
        (change[eid[operate[i]]] = true);
        (update[(++cntu)] = operate[i]);
      } else {
        (query[(++cntq)] = operate[i]);
      }
    }
    Code04_Bridge1::sort(query, car, 1, cntq);
    {
      int i = 1;
      int j = 1;
      for (; (i <= cntq); (i++)) {
        while (((j <= m) && (w[edge[j]] >= car[query[i]]))) {
          if ((!change[edge[j]])) {
            Code04_Bridge1::union_method(u[edge[j]], v[edge[j]]);
          }
          (j++);
        }
        (opsize = 0);
        for (int k = 1; (k <= cntu); (k++)) {
          (curw[eid[update[k]]] = w[eid[update[k]]]);
        }
        for (int k = 1; ((k <= cntu) && (update[k] < query[i])); (k++)) {
          (curw[eid[update[k]]] = tow[update[k]]);
        }
        for (int k = 1; (k <= cntu); (k++)) {
          if ((curw[eid[update[k]]] >= car[query[i]])) {
            Code04_Bridge1::union_method(u[eid[update[k]]], v[eid[update[k]]]);
          }
        }
        (ans[query[i]] = siz[Code04_Bridge1::find(nid[query[i]])]);
        Code04_Bridge1::undo();
      }
    }
    for (int i = 1; (i <= cntu); (i++)) {
      (w[eid[update[i]]] = tow[update[i]]);
    }
    Code04_Bridge1::merge();
  }
  static void prepare() {
    int log2n = 0;
    while ((jshl(1, log2n) <= jshr(n, 1))) {
      (log2n++);
    }
    (blen = jmax(1, static_cast<int>(std::sqrt((q * log2n)))));
    (bnum = jdiv(((q + blen) - 1), blen));
    Code04_Bridge1::sort(edge, w, 1, m);
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (m = in.nextInt());
    for (int i = 1; (i <= m); (i++)) {
      (u[i] = in.nextInt());
      (v[i] = in.nextInt());
      (w[i] = in.nextInt());
      (edge[i] = i);
    }
    (q = in.nextInt());
    for (int i = 1; (i <= q); (i++)) {
      (op[i] = in.nextInt());
      if ((op[i] == 1)) {
        (eid[i] = in.nextInt());
        (tow[i] = in.nextInt());
      } else {
        (nid[i] = in.nextInt());
        (car[i] = in.nextInt());
      }
      (operate[i] = i);
    }
    Code04_Bridge1::prepare();
    {
      int i = 1;
      int l = {};
      int r = {};
      for (; (i <= bnum); (i++)) {
        (l = (((i - 1) * blen) + 1));
        (r = jmin((i * blen), q));
        Code04_Bridge1::compute(l, r);
      }
    }
    for (int i = 1; (i <= q); (i++)) {
      if ((op[i] == 2)) {
        out.println(ans[i]);
      }
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code04_Bridge1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 桥梁，java版
// 有n个点组成的无向图，依次给出m条无向边
// u v w : u到v的边，边权为w，边权同时代表限重
// 如果开车从边上经过，车的重量 <= 边的限重，车才能走过这条边
// 接下来有q条操作，每条操作的格式如下
// 操作 1 eid tow : 编号为eid的边，边权变成tow
// 操作 2 nid car : 编号为nid的点出发，车重为car，查询能到达几个不同的点
// 1 <= n <= 5 * 10^4    0 <= m <= 10^5
// 1 <= q <= 10^5        1 <= 其他数据 <= 10^9
// 测试链接 : https://www.luogu.com.cn/problem/P5443
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // edge是所有边的编号
        // change表示边的分类
        // curw表示边最新的权值
        // operate是所有操作的编号
        // query是当前操作块查询操作的编号
        // update是当前操作块修改操作的编号
        // 可撤销并查集
        // 归并的辅助数组
        // 所有查询的答案
        // idx[l..r]都是编号，编号根据val[编号]的值从大到小排序，手写双指针快排
        // 当前操作编号[l..r]，之前的所有修改操作都已生效
        // 所有边的编号edge[1..m]，按照边权从大到小排序
        // 处理当前操作块的所有操作
                // 重建并查集，目前没有任何连通性
                // 清空边的修改标记
                // 查询操作的所有编号，根据车重从大到小排序
                // 然后依次处理所有查询
                        // 边权 >= 当前车重 的边全部连上，注意这是不回退的
                        // 注意需要用可撤销并查集，撤销会改值的边
                        // 会改值的边，边权先继承改之前的值
                        // 修改操作的时序 <
当前查询操作的时序，那么相关边的边权改成最新值
                        // 会改值的边，其中 边权 >= 当前车重 的边全部连上
                        // 并查集修改完毕，查询答案
                        // 并查集的撤销
                // 所有会改值的边，边权修改，因为即将去下个操作块
                // 没改值的边和改了值的边，根据边权从大到小合并
        // 读写工具类
*/

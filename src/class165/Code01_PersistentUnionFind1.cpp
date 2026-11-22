// Source: src/class165/Code01_PersistentUnionFind1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_PersistentUnionFind1 {
  inline static int MAXM = 200001;
  inline static int MAXT = 8000001;
  inline static int n = {};
  inline static int m = {};
  inline static Array<int> rootfa = make_array<int>(MAXM);
  inline static Array<int> rootsiz = make_array<int>(MAXM);
  inline static Array<int> ls = make_array<int>(MAXT);
  inline static Array<int> rs = make_array<int>(MAXT);
  inline static Array<int> val = make_array<int>(MAXT);
  inline static int cnt = 0;
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_PersistentUnionFind1() {}
  static int buildfa(int l, int r) {
    int rt = (++cnt);
    if ((l == r)) {
      (val[rt] = l);
    } else {
      int mid = jdiv((l + r), 2);
      (ls[rt] = Code01_PersistentUnionFind1::buildfa(l, mid));
      (rs[rt] = Code01_PersistentUnionFind1::buildfa((mid + 1), r));
    }
    return rt;
  }
  static int buildsiz(int l, int r) {
    int rt = (++cnt);
    if ((l == r)) {
      (val[rt] = 1);
    } else {
      int mid = jdiv((l + r), 2);
      (ls[rt] = Code01_PersistentUnionFind1::buildsiz(l, mid));
      (rs[rt] = Code01_PersistentUnionFind1::buildsiz((mid + 1), r));
    }
    return rt;
  }
  static int update(int jobi, int jobv, int l, int r, int i) {
    int rt = (++cnt);
    (ls[rt] = ls[i]);
    (rs[rt] = rs[i]);
    if ((l == r)) {
      (val[rt] = jobv);
    } else {
      int mid = jdiv((l + r), 2);
      if ((jobi <= mid)) {
        (ls[rt] =
             Code01_PersistentUnionFind1::update(jobi, jobv, l, mid, ls[rt]));
      } else {
        (rs[rt] = Code01_PersistentUnionFind1::update(jobi, jobv, (mid + 1), r,
                                                      rs[rt]));
      }
    }
    return rt;
  }
  static int query(int jobi, int l, int r, int i) {
    if ((l == r)) {
      return val[i];
    }
    int mid = jdiv((l + r), 2);
    if ((jobi <= mid)) {
      return Code01_PersistentUnionFind1::query(jobi, l, mid, ls[i]);
    } else {
      return Code01_PersistentUnionFind1::query(jobi, (mid + 1), r, rs[i]);
    }
  }
  static int find(int x, int v) {
    int fa = Code01_PersistentUnionFind1::query(x, 1, n, rootfa[v]);
    while ((x != fa)) {
      (x = fa);
      (fa = Code01_PersistentUnionFind1::query(x, 1, n, rootfa[v]));
    }
    return x;
  }
  static void union_method(int x, int y, int v) {
    int fx = Code01_PersistentUnionFind1::find(x, v);
    int fy = Code01_PersistentUnionFind1::find(y, v);
    if ((fx != fy)) {
      int xsiz = Code01_PersistentUnionFind1::query(fx, 1, n, rootsiz[v]);
      int ysiz = Code01_PersistentUnionFind1::query(fy, 1, n, rootsiz[v]);
      if ((xsiz >= ysiz)) {
        (rootfa[v] =
             Code01_PersistentUnionFind1::update(fy, fx, 1, n, rootfa[v]));
        (rootsiz[v] = Code01_PersistentUnionFind1::update(fx, (xsiz + ysiz), 1,
                                                          n, rootsiz[v]));
      } else {
        (rootfa[v] =
             Code01_PersistentUnionFind1::update(fx, fy, 1, n, rootfa[v]));
        (rootsiz[v] = Code01_PersistentUnionFind1::update(fy, (xsiz + ysiz), 1,
                                                          n, rootsiz[v]));
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
    (rootfa[0] = Code01_PersistentUnionFind1::buildfa(1, n));
    (rootsiz[0] = Code01_PersistentUnionFind1::buildsiz(1, n));
    {
      int v = 1;
      int op = {};
      int x = {};
      int y = {};
      for (; (v <= m); (v++)) {
        in.nextToken();
        (op = static_cast<int>(in.nval));
        (rootfa[v] = rootfa[(v - 1)]);
        (rootsiz[v] = rootsiz[(v - 1)]);
        if ((op == 1)) {
          in.nextToken();
          (x = static_cast<int>(in.nval));
          in.nextToken();
          (y = static_cast<int>(in.nval));
          Code01_PersistentUnionFind1::union_method(x, y, v);
        } else if ((op == 2)) {
          in.nextToken();
          (x = static_cast<int>(in.nval));
          (rootfa[v] = rootfa[x]);
          (rootsiz[v] = rootsiz[x]);
        } else {
          in.nextToken();
          (x = static_cast<int>(in.nval));
          in.nextToken();
          (y = static_cast<int>(in.nval));
          if ([&]() {
                auto jleft = Code01_PersistentUnionFind1::find(x, v);
                auto jright = Code01_PersistentUnionFind1::find(y, v);
                return (jleft == jright);
              }()) {
            out.println(1);
          } else {
            out.println(0);
          }
        }
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
  Code01_PersistentUnionFind1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 可持久化并查集模版题，java版
// 数字从1到n，一开始每个数字所在的集合只有自己
// 实现如下三种操作，第i条操作发生后，所有数字的状况记为i版本，操作一共发生m次
// 操作 1 x y : 基于上个操作生成的版本，将x的集合与y的集合合并，生成当前的版本
// 操作 2 x   : 拷贝第x号版本的状况，生成当前的版本
// 操作 3 x y : 拷贝上个操作生成的版本，生成当前的版本，查询x和y是否属于一个集合
// 1 <= n <= 10^5
// 1 <= m <= 2 * 10^5
// 测试链接 : https://www.luogu.com.cn/problem/P3402
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // rootfa[i] = j，表示father数组，i版本的头节点编号为j
        // rootsiz[i] = j，表示siz数组，i版本的头节点编号为j
        // 可持久化father数组和可持久化siz数组，共用一个ls、rs、val
        // 因为可持久化时，分配的节点编号不同，所以可以共用
        // 建立可持久化的father数组
        // 建立可持久化的siz数组
        // 来自讲解157，题目1，修改数组中一个位置的值，生成新版本的数组
        // 如果i属于可持久化father数组的节点，那么修改的就是father数组
        // 如果i属于可持久化siz数组的节点，那么修改的就是siz数组
        // 来自讲解157，题目1，查询数组中一个位置的值
        // 如果i属于可持久化father数组的节点，那么查询的就是father数组
        // 如果i属于可持久化siz数组的节点，那么查询的就是siz数组
        // 基于v版本，查询x的集合头节点，不做扁平化
        // v版本已经拷贝了v-1版本，合并x所在的集合和y所在的集合，去更新v版本
*/

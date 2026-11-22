// Source: src/class120/Code04_LinkCutCentroids.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_LinkCutCentroids {
  inline static int MAXN = 100001;
  inline static int n = {};
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> next = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> to = make_array<int>(jshl(MAXN, 1));
  inline static int cnt = {};
  inline static Array<int> size = make_array<int>(MAXN);
  inline static Array<int> maxsub = make_array<int>(MAXN);
  inline static Array<int> centers = make_array<int>(2);
  inline static int leaf = {};
  inline static int leafFather = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_LinkCutCentroids() {}
  static void build() {
    (cnt = 1);
    j::fill(head, 1, (n + 1), 0);
  }
  static void addEdge(int u, int v) {
    (next[cnt] = head[u]);
    (to[cnt] = v);
    (head[u] = (cnt++));
  }
  static void dfs(int u, int f) {
    (size[u] = 1);
    (maxsub[u] = 0);
    {
      int e = head[u];
      int v = {};
      for (; (e != 0); (e = next[e])) {
        (v = to[e]);
        if ((v != f)) {
          Code04_LinkCutCentroids::dfs(v, u);
          (size[u] += size[v]);
          (maxsub[u] = jmax(maxsub[u], size[v]));
        }
      }
    }
    (maxsub[u] = jmax(maxsub[u], (n - size[u])));
  }
  static void find(int u, int f) {
    for (int e = head[u]; (e != 0); (e = next[e])) {
      if ((to[e] != f)) {
        Code04_LinkCutCentroids::find(to[e], u);
        return;
      }
    }
    (leaf = u);
    (leafFather = f);
  }
  static int centerCnt() {
    int m = 0;
    for (int i = 1; (i <= n); (i++)) {
      if ((maxsub[i] <= jdiv(n, 2))) {
        (centers[(m++)] = i);
      }
    }
    return m;
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    int testCase = static_cast<int>(in.nval);
    for (int t = 1; (t <= testCase); (t++)) {
      in.nextToken();
      (n = static_cast<int>(in.nval));
      Code04_LinkCutCentroids::build();
      {
        int i = 1;
        int u = {};
        int v = {};
        for (; (i < n); (i++)) {
          in.nextToken();
          (u = static_cast<int>(in.nval));
          in.nextToken();
          (v = static_cast<int>(in.nval));
          Code04_LinkCutCentroids::addEdge(u, v);
          Code04_LinkCutCentroids::addEdge(v, u);
        }
      }
      Code04_LinkCutCentroids::dfs(1, 0);
      if ((Code04_LinkCutCentroids::centerCnt() == 1)) {
        out.println(((centers[0] + String(u" ")) + to[head[centers[0]]]));
        out.println(((centers[0] + String(u" ")) + to[head[centers[0]]]));
      } else {
        Code04_LinkCutCentroids::find(centers[1], centers[0]);
        out.println(((leafFather + String(u" ")) + leaf));
        out.println(((centers[0] + String(u" ")) + leaf));
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
  Code04_LinkCutCentroids::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 删增边使其重心唯一
// 一共有n个节点，编号1~n，有n-1条边形成一棵树
// 现在希望重心是唯一的节点，调整的方式是先删除一条边、然后增加一条边
//
如果树上只有一个重心，需要删掉连接重心的任意一条边，再把这条边加上(否则无法通过已经实测)
// 如果树上有两个重心，调整的方式是先删除一条边、然后增加一条边，使重心是唯一的
// 如果方案有多种，打印其中一种即可
// 比如先删除节点3和节点4之间的边，再增加节点4和节点7之间的边，那么打印:
// "3 4"
// "4 7"
// 测试链接 : https://www.luogu.com.cn/problem/CF1406C
// 测试链接 : https://codeforces.com/problemset/problem/1406/C
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有用例
        // size[i] : 从1号节点开始dfs的过程中，以i为头的子树的节点数
        // maxsub[i] : 如果节点i做整棵树的根，最大子树的大小
        // 收集所有的重心
        // 最大子树上的叶节点
        // 叶节点的父亲节点
        // 随意找一个叶节点和该叶节点的父亲节点
        // 哪一组都可以
        // 返回重心的数量
*/

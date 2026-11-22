// Source: src/class163/Code05_BloodCousins1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code05_BloodCousins1 {
  inline static int MAXN = 100001;
  inline static int MAXP = 20;
  inline static int n = {};
  inline static int m = {};
  inline static Array<bool> root = make_array<bool>(MAXN);
  inline static Array<int> headg = make_array<int>(MAXN);
  inline static Array<int> nextg = make_array<int>(MAXN);
  inline static Array<int> tog = make_array<int>(MAXN);
  inline static int cntg = {};
  inline static Array<int> headq = make_array<int>(MAXN);
  inline static Array<int> nextq = make_array<int>(MAXN);
  inline static Array<int> ansiq = make_array<int>(MAXN);
  inline static Array<int> kq = make_array<int>(MAXN);
  inline static int cntq = {};
  inline static Array<int> siz = make_array<int>(MAXN);
  inline static Array<int> dep = make_array<int>(MAXN);
  inline static Array<int> son = make_array<int>(MAXN);
  inline static Array<Array<int>> stjump = make_array<int>(MAXN, MAXP);
  inline static Array<int> depCnt = make_array<int>(MAXN);
  inline static Array<int> ans = make_array<int>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code05_BloodCousins1() {}
  static void addEdge(int u, int v) {
    (nextg[(++cntg)] = headg[u]);
    (tog[cntg] = v);
    (headg[u] = cntg);
  }
  static void addQuestion(int u, int i, int k) {
    (nextq[(++cntq)] = headq[u]);
    (ansiq[cntq] = i);
    (kq[cntq] = k);
    (headq[u] = cntq);
  }
  static void dfs1(int u, int fa) {
    (siz[u] = 1);
    (dep[u] = (dep[fa] + 1));
    (stjump[u][0] = fa);
    for (int p = 1; (p < MAXP); (p++)) {
      (stjump[u][p] = stjump[stjump[u][(p - 1)]][(p - 1)]);
    }
    for (int e = headg[u]; (e > 0); (e = nextg[e])) {
      Code05_BloodCousins1::dfs1(tog[e], u);
    }
    {
      int e = headg[u];
      int v = {};
      for (; (e > 0); (e = nextg[e])) {
        (v = tog[e]);
        (siz[u] += siz[v]);
        if (((son[u] == 0) || (siz[son[u]] < siz[v]))) {
          (son[u] = v);
        }
      }
    }
  }
  static int kAncestor(int u, int k) {
    for (int p = (MAXP - 1); (p >= 0); (p--)) {
      if ((k >= jshl(1, p))) {
        (k -= jshl(1, p));
        (u = stjump[u][p]);
      }
    }
    return u;
  }
  static void effect(int u) {
    (depCnt[dep[u]]++);
    for (int e = headg[u]; (e > 0); (e = nextg[e])) {
      Code05_BloodCousins1::effect(tog[e]);
    }
  }
  static void cancel(int u) {
    (depCnt[dep[u]]--);
    for (int e = headg[u]; (e > 0); (e = nextg[e])) {
      Code05_BloodCousins1::cancel(tog[e]);
    }
  }
  static void dfs2(int u, int keep) {
    {
      int e = headg[u];
      int v = {};
      for (; (e > 0); (e = nextg[e])) {
        (v = tog[e]);
        if ((v != son[u])) {
          Code05_BloodCousins1::dfs2(v, 0);
        }
      }
    }
    if ((son[u] != 0)) {
      Code05_BloodCousins1::dfs2(son[u], 1);
    }
    (depCnt[dep[u]]++);
    {
      int e = headg[u];
      int v = {};
      for (; (e > 0); (e = nextg[e])) {
        (v = tog[e]);
        if ((v != son[u])) {
          Code05_BloodCousins1::effect(v);
        }
      }
    }
    for (int i = headq[u]; (i > 0); (i = nextq[i])) {
      (ans[ansiq[i]] = depCnt[(dep[u] + kq[i])]);
    }
    if ((keep == 0)) {
      Code05_BloodCousins1::cancel(u);
    }
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    (n = static_cast<int>(in.nval));
    {
      int i = 1;
      int father = {};
      for (; (i <= n); (i++)) {
        in.nextToken();
        (father = static_cast<int>(in.nval));
        if ((father == 0)) {
          (root[i] = true);
        } else {
          Code05_BloodCousins1::addEdge(father, i);
        }
      }
    }
    for (int i = 1; (i <= n); (i++)) {
      if (root[i]) {
        Code05_BloodCousins1::dfs1(i, 0);
      }
    }
    in.nextToken();
    (m = static_cast<int>(in.nval));
    {
      int i = 1;
      int u = {};
      int k = {};
      int kfather = {};
      for (; (i <= m); (i++)) {
        in.nextToken();
        (u = static_cast<int>(in.nval));
        in.nextToken();
        (k = static_cast<int>(in.nval));
        (kfather = Code05_BloodCousins1::kAncestor(u, k));
        if ((kfather != 0)) {
          Code05_BloodCousins1::addQuestion(kfather, i, k);
        }
      }
    }
    for (int i = 1; (i <= n); (i++)) {
      if (root[i]) {
        Code05_BloodCousins1::dfs2(i, 0);
      }
    }
    for (int i = 1; (i <= m); (i++)) {
      if ((ans[i] == 0)) {
        out.print(String(u"0 "));
      } else {
        out.print(((ans[i] - 1) + String(u" ")));
      }
    }
    out.println();
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code05_BloodCousins1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 表亲数量，java版
//
一共有n个节点，编号1~n，给定每个节点的父亲节点编号，父亲节点为0，说明当前节点是某棵树的头
// 注意，n个节点组成的是森林结构，可能有若干棵树
// 一共有m条查询，每条查询 x k，含义如下
// 如果x往上走k的距离，没有祖先节点，打印0
//
如果x往上走k的距离，能找到祖先节点a，那么从a往下走k的距离，除了x之外，可能还有其他节点
// 这些节点叫做x的k级表亲，打印这个表亲的数量
// 1 <= n、m <= 10^5
// 测试链接 : https://www.luogu.com.cn/problem/CF208E
// 测试链接 : https://codeforces.com/problemset/problem/208/E
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 链式前向星
        // 问题列表
        // 树链剖分
        // 树上启发式合并
*/

// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/CF246E
// https://codeforces.com/problemset/problem/246/E

// Source: src/class163/Code04_DifferntName1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_DifferntName1 {
  inline static int MAXN = 100001;
  inline static int n = {};
  inline static int m = {};
  inline static JMap<String, int> nameId = JMap<String, int>();
  inline static Array<bool> root = make_array<bool>(MAXN);
  inline static Array<int> id = make_array<int>(MAXN);
  inline static Array<int> headg = make_array<int>(MAXN);
  inline static Array<int> nextg = make_array<int>(MAXN);
  inline static Array<int> tog = make_array<int>(MAXN);
  inline static int cntg = {};
  inline static Array<int> headq = make_array<int>(MAXN);
  inline static Array<int> nextq = make_array<int>(MAXN);
  inline static Array<int> ansiq = make_array<int>(MAXN);
  inline static Array<int> kq = make_array<int>(MAXN);
  inline static int cntq = {};
  inline static Array<int> fa = make_array<int>(MAXN);
  inline static Array<int> siz = make_array<int>(MAXN);
  inline static Array<int> dep = make_array<int>(MAXN);
  inline static Array<int> son = make_array<int>(MAXN);
  inline static JList<JHashSet<int>> depSet = JList<JHashSet<int>>();
  inline static Array<int> ans = make_array<int>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_DifferntName1() {}
  static int getNameId(String name) {
    if (nameId.containsKey(name)) {
      return nameId.get(name);
    }
    nameId.put(name, (nameId.size() + 1));
    return nameId.size();
  }
  static void addId(int deep, int id) { depSet.get(deep).add(id); }
  static void removeId(int deep, int id) { depSet.get(deep).remove(id); }
  static int sizeOfDeep(int deep) {
    if ((deep > n)) {
      return 0;
    }
    return depSet.get(deep).size();
  }
  static void addEdge(int u, int v) {
    (nextg[(++cntg)] = headg[u]);
    (tog[cntg] = v);
    (headg[u] = cntg);
  }
  static void addQuestion(int u, int ansi, int k) {
    (nextq[(++cntq)] = headq[u]);
    (ansiq[cntq] = ansi);
    (kq[cntq] = k);
    (headq[u] = cntq);
  }
  static void dfs1(int u, int f) {
    (fa[u] = f);
    (siz[u] = 1);
    (dep[u] = (dep[f] + 1));
    for (int e = headg[u]; (e > 0); (e = nextg[e])) {
      Code04_DifferntName1::dfs1(tog[e], u);
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
  static void effect(int u) {
    Code04_DifferntName1::addId(dep[u], id[u]);
    for (int e = headg[u]; (e > 0); (e = nextg[e])) {
      Code04_DifferntName1::effect(tog[e]);
    }
  }
  static void cancel(int u) {
    Code04_DifferntName1::removeId(dep[u], id[u]);
    for (int e = headg[u]; (e > 0); (e = nextg[e])) {
      Code04_DifferntName1::cancel(tog[e]);
    }
  }
  static void dfs2(int u, int keep) {
    {
      int e = headg[u];
      int v = {};
      for (; (e > 0); (e = nextg[e])) {
        (v = tog[e]);
        if ((v != son[u])) {
          Code04_DifferntName1::dfs2(v, 0);
        }
      }
    }
    if ((son[u] != 0)) {
      Code04_DifferntName1::dfs2(son[u], 1);
    }
    Code04_DifferntName1::addId(dep[u], id[u]);
    {
      int e = headg[u];
      int v = {};
      for (; (e > 0); (e = nextg[e])) {
        (v = tog[e]);
        if ((v != son[u])) {
          Code04_DifferntName1::effect(v);
        }
      }
    }
    for (int i = headq[u]; (i > 0); (i = nextq[i])) {
      (ans[ansiq[i]] = Code04_DifferntName1::sizeOfDeep((dep[u] + kq[i])));
    }
    if ((keep == 0)) {
      Code04_DifferntName1::cancel(u);
    }
  }
  static void java_main(Array<String> args) {
    IO io = IO();
    (n = io.nextInt());
    String name = {};
    int father = {};
    for (int i = 1; (i <= n); (i++)) {
      (name = io.next());
      (father = io.nextInt());
      (id[i] = Code04_DifferntName1::getNameId(name));
      if ((father == 0)) {
        (root[i] = true);
      } else {
        Code04_DifferntName1::addEdge(father, i);
      }
    }
    for (int i = 1; (i <= n); (i++)) {
      if (root[i]) {
        Code04_DifferntName1::dfs1(i, 0);
      }
    }
    for (int i = 0; (i <= n); (i++)) {
      depSet.add(JHashSet<int>());
    }
    (m = io.nextInt());
    {
      int i = 1;
      int node = {};
      int k = {};
      for (; (i <= m); (i++)) {
        (node = io.nextInt());
        (k = io.nextInt());
        Code04_DifferntName1::addQuestion(node, i, k);
      }
    }
    for (int i = 1; (i <= n); (i++)) {
      if (root[i]) {
        Code04_DifferntName1::dfs2(i, 0);
      }
    }
    for (int i = 1; (i <= m); (i++)) {
      io.println(ans[i]);
    }
    io.flush();
    io.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code04_DifferntName1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 不同名字数量，java版
// 一共有n个节点，编号1~n，给定每个节点的名字和父亲节点编号
// 名字是string类型，如果父亲节点编号为0，说明当前节点是某棵树的头节点
// 注意，n个节点组成的是森林结构，可能有若干棵树
// 一共有m条查询，每条查询 x k，含义如下
// 以x为头的子树上，到x距离为k的所有节点中，打印不同名字的数量
// 1 <= n、m <= 10^5
// 测试链接 : https://www.luogu.com.cn/problem/CF246E
// 测试链接 : https://codeforces.com/problemset/problem/246/E
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 链式前向星
        // 问题列表
        // 树链剖分
        // 树上启发式合并
        // 读写工具类
*/

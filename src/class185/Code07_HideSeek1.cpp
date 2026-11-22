// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P2056

// Source: src/class185/Code07_HideSeek1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code07_HideSeek1 {
  struct Set;
  struct Set {
    JHeap<int> addHeap = {};
    JHeap<int> delHeap = {};
    String toString() const { return j::str(static_cast<const void *>(this)); }
    Set() {
      (addHeap =
           JHeap<int>([=](Box<int> a, Box<int> b) { return jcompare(b, a); }));
      (delHeap =
           JHeap<int>([=](Box<int> a, Box<int> b) { return jcompare(b, a); }));
    }
    void clean() {
      while (((!delHeap.isEmpty()) && (delHeap.peek() == addHeap.peek()))) {
        addHeap.poll();
        delHeap.poll();
      }
    }
    int popHead() {
      int ans = addHeap.poll();
      Set::clean();
      return ans;
    }
    int size() {
      return [&]() {
        auto jleft = addHeap.size();
        auto jright = delHeap.size();
        return (jleft - jright);
      }();
    }
    void add(int v) { addHeap.add(v); }
    void del(int v) {
      delHeap.add(v);
      Set::clean();
    }
    int first() { return addHeap.peek(); }
    int second() {
      int a = Set::popHead();
      int b = Set::first();
      Set::add(a);
      return b;
    }
  };
  inline static int MAXN = 100001;
  inline static int n = {};
  inline static int m = {};
  inline static Array<bool> black = make_array<bool>(MAXN);
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> nxt = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> to = make_array<int>(jshl(MAXN, 1));
  inline static int cntg = {};
  inline static Array<int> fa = make_array<int>(MAXN);
  inline static Array<int> dep = make_array<int>(MAXN);
  inline static Array<int> siz = make_array<int>(MAXN);
  inline static Array<int> son = make_array<int>(MAXN);
  inline static Array<int> top = make_array<int>(MAXN);
  inline static Array<bool> vis = make_array<bool>(MAXN);
  inline static Array<int> centfa = make_array<int>(MAXN);
  inline static Array<Set *> distFa = make_array<Set *>(MAXN);
  inline static Array<Set *> sonMax = make_array<Set *>(MAXN);
  inline static Set *maxDist = new Set();
  inline static Array<Array<int>> stack = make_array<int>(MAXN, 4);
  inline static int u = {};
  inline static int f = {};
  inline static int t = {};
  inline static int e = {};
  inline static int stacksize = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code07_HideSeek1() {}
  static void push(int u, int f, int t, int e) {
    (stack[stacksize][0] = u);
    (stack[stacksize][1] = f);
    (stack[stacksize][2] = t);
    (stack[stacksize][3] = e);
    (stacksize++);
  }
  static void pop() {
    (--stacksize);
    (u = stack[stacksize][0]);
    (f = stack[stacksize][1]);
    (t = stack[stacksize][2]);
    (e = stack[stacksize][3]);
  }
  static void addEdge(int u, int v) {
    (nxt[(++cntg)] = head[u]);
    (to[cntg] = v);
    (head[u] = cntg);
  }
  static void dfs1(int u, int f) {
    (fa[u] = f);
    (dep[u] = (dep[f] + 1));
    (siz[u] = 1);
    {
      int e = head[u];
      int v = {};
      for (; (e > 0); (e = nxt[e])) {
        (v = to[e]);
        if ((v != f)) {
          Code07_HideSeek1::dfs1(v, u);
        }
      }
    }
    {
      int ei = head[u];
      int v = {};
      for (; (ei > 0); (ei = nxt[ei])) {
        (v = to[ei]);
        if ((v != f)) {
          (siz[u] += siz[v]);
          if (((son[u] == 0) || (siz[son[u]] < siz[v]))) {
            (son[u] = v);
          }
        }
      }
    }
  }
  static void dfs2(int u, int t) {
    (top[u] = t);
    if ((son[u] == 0)) {
      return;
    }
    Code07_HideSeek1::dfs2(son[u], t);
    {
      int e = head[u];
      int v = {};
      for (; (e > 0); (e = nxt[e])) {
        (v = to[e]);
        if (((v != fa[u]) && (v != son[u]))) {
          Code07_HideSeek1::dfs2(v, v);
        }
      }
    }
  }
  static void dfs3(int cur, int father) {
    (stacksize = 0);
    Code07_HideSeek1::push(cur, father, 0, (-1));
    while ((stacksize > 0)) {
      Code07_HideSeek1::pop();
      if ((e == (-1))) {
        (fa[u] = f);
        (dep[u] = (dep[f] + 1));
        (siz[u] = 1);
        (e = head[u]);
      } else {
        (e = nxt[e]);
      }
      if ((e != 0)) {
        Code07_HideSeek1::push(u, f, 0, e);
        int v = to[e];
        if ((v != f)) {
          Code07_HideSeek1::push(v, u, 0, (-1));
        }
      } else {
        for (int ei = head[u]; (ei > 0); (ei = nxt[ei])) {
          int v = to[ei];
          if ((v != f)) {
            (siz[u] += siz[v]);
            if (((son[u] == 0) || (siz[son[u]] < siz[v]))) {
              (son[u] = v);
            }
          }
        }
      }
    }
  }
  static void dfs4(int cur, int tag) {
    (stacksize = 0);
    Code07_HideSeek1::push(cur, 0, tag, (-1));
    while ((stacksize > 0)) {
      Code07_HideSeek1::pop();
      if ((e == (-1))) {
        (top[u] = t);
        if ((son[u] == 0)) {
          continue;
        }
        Code07_HideSeek1::push(u, 0, t, (-2));
        Code07_HideSeek1::push(son[u], 0, t, (-1));
        continue;
      } else if ((e == (-2))) {
        (e = head[u]);
      } else {
        (e = nxt[e]);
      }
      if ((e != 0)) {
        Code07_HideSeek1::push(u, 0, t, e);
        int v = to[e];
        if (((v != fa[u]) && (v != son[u]))) {
          Code07_HideSeek1::push(v, 0, v, (-1));
        }
      }
    }
  }
  static void getSize1(int u, int fa) {
    (siz[u] = 1);
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      int v = to[e];
      if (((v != fa) && (!vis[v]))) {
        Code07_HideSeek1::getSize1(v, u);
        (siz[u] += siz[v]);
      }
    }
  }
  static void getSize2(int cur, int fa) {
    (stacksize = 0);
    Code07_HideSeek1::push(cur, fa, 0, (-1));
    while ((stacksize > 0)) {
      Code07_HideSeek1::pop();
      if ((e == (-1))) {
        (siz[u] = 1);
        (e = head[u]);
      } else {
        (e = nxt[e]);
      }
      if ((e != 0)) {
        Code07_HideSeek1::push(u, f, 0, e);
        int v = to[e];
        if (((v != f) && (!vis[v]))) {
          Code07_HideSeek1::push(v, u, 0, (-1));
        }
      } else {
        for (int ei = head[u]; (ei > 0); (ei = nxt[ei])) {
          int v = to[ei];
          if (((v != f) && (!vis[v]))) {
            (siz[u] += siz[v]);
          }
        }
      }
    }
  }
  static int getLca(int a, int b) {
    while ((top[a] != top[b])) {
      if ((dep[top[a]] <= dep[top[b]])) {
        (b = fa[top[b]]);
      } else {
        (a = fa[top[a]]);
      }
    }
    return ((dep[a] <= dep[b]) ? a : b);
  }
  static int getDist(int x, int y) {
    return ((dep[x] + dep[y]) - jshl(dep[Code07_HideSeek1::getLca(x, y)], 1));
  }
  static int getCentroid(int u, int fa) {
    Code07_HideSeek1::getSize2(u, fa);
    int half = jshr(siz[u], 1);
    bool find = false;
    while ((!find)) {
      (find = true);
      for (int e = head[u]; (e > 0); (e = nxt[e])) {
        int v = to[e];
        if ((((v != fa) && (!vis[v])) && (siz[v] > half))) {
          (fa = u);
          (u = v);
          (find = false);
          break;
        }
      }
    }
    return u;
  }
  static void centroidTree(int u, int fa) {
    (centfa[u] = fa);
    (vis[u] = true);
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      int v = to[e];
      if ((!vis[v])) {
        Code07_HideSeek1::centroidTree(Code07_HideSeek1::getCentroid(v, u), u);
      }
    }
  }
  static void addAns(int x) {
    if ((sonMax[x]->size() >= 2)) {
      maxDist->add([&]() {
        auto jleft = sonMax[x]->first();
        auto jright = sonMax[x]->second();
        return (jleft + jright);
      }());
    }
  }
  static void delAns(int x) {
    if ((sonMax[x]->size() >= 2)) {
      maxDist->del([&]() {
        auto jleft = sonMax[x]->first();
        auto jright = sonMax[x]->second();
        return (jleft + jright);
      }());
    }
  }
  static void on(int x) {
    Code07_HideSeek1::delAns(x);
    sonMax[x]->del(0);
    Code07_HideSeek1::addAns(x);
    {
      int u = x;
      int fa = centfa[u];
      for (; (fa > 0); (u = fa), (fa = centfa[u])) {
        Code07_HideSeek1::delAns(fa);
        sonMax[fa]->del(distFa[u]->first());
        distFa[u]->del(Code07_HideSeek1::getDist(x, fa));
        if ((distFa[u]->size() > 0)) {
          sonMax[fa]->add(distFa[u]->first());
        }
        Code07_HideSeek1::addAns(fa);
      }
    }
  }
  static void off(int x) {
    Code07_HideSeek1::delAns(x);
    sonMax[x]->add(0);
    Code07_HideSeek1::addAns(x);
    {
      int u = x;
      int fa = centfa[u];
      for (; (fa > 0); (u = fa), (fa = centfa[u])) {
        Code07_HideSeek1::delAns(fa);
        if ((distFa[u]->size() > 0)) {
          sonMax[fa]->del(distFa[u]->first());
        }
        distFa[u]->add(Code07_HideSeek1::getDist(x, fa));
        sonMax[fa]->add(distFa[u]->first());
        Code07_HideSeek1::addAns(fa);
      }
    }
  }
  static void prepare() {
    for (int i = 1; (i <= n); (i++)) {
      (black[i] = true);
    }
    for (int i = 1; (i <= n); (i++)) {
      (distFa[i] = new Set());
      (sonMax[i] = new Set());
    }
    for (int i = 1; (i <= n); (i++)) {
      {
        int u = i;
        int fa = centfa[u];
        for (; (fa > 0); (u = fa), (fa = centfa[u])) {
          distFa[u]->add(Code07_HideSeek1::getDist(i, fa));
        }
      }
    }
    for (int i = 1; (i <= n); (i++)) {
      sonMax[i]->add(0);
      if ((centfa[i] > 0)) {
        sonMax[centfa[i]]->add(distFa[i]->first());
      }
    }
    for (int i = 1; (i <= n); (i++)) {
      Code07_HideSeek1::addAns(i);
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO();
    IO out = IO(IO(jout));
    (n = in.nextInt());
    {
      int i = 1;
      int u = {};
      int v = {};
      for (; (i < n); (i++)) {
        (u = in.nextInt());
        (v = in.nextInt());
        Code07_HideSeek1::addEdge(u, v);
        Code07_HideSeek1::addEdge(v, u);
      }
    }
    Code07_HideSeek1::dfs3(1, 0);
    Code07_HideSeek1::dfs4(1, 1);
    Code07_HideSeek1::centroidTree(Code07_HideSeek1::getCentroid(1, 0), 0);
    Code07_HideSeek1::prepare();
    (m = in.nextInt());
    int blackCnt = n;
    jchar op = {};
    {
      int i = 1;
      int x = {};
      for (; (i <= m); (i++)) {
        (op = in.nextChar());
        if ((op == u'C')) {
          (x = in.nextInt());
          (black[x] = (!black[x]));
          if (black[x]) {
            Code07_HideSeek1::off(x);
            (blackCnt++);
          } else {
            Code07_HideSeek1::on(x);
            (blackCnt--);
          }
        } else {
          if ((blackCnt <= 1)) {
            out.println((blackCnt - 1));
          } else {
            out.println(maxDist->first());
          }
        }
      }
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code07_HideSeek1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 捉迷藏，点分树的解，java版
// 树上有n个点，点的初始颜色为黑，给定n-1条边，边权都是1
// 一共有m条操作，每条操作是如下两种类型中的一种
// 操作 C x : 改变点x的颜色，黑变成白，白变成黑
// 操作 G   : 打印最远的两个黑点的距离，只有一个黑点打印0，无黑点打印-1
// 1 <= n <= 10^5    1 <= m <= 5 * 10^5
// 测试链接 : https://www.luogu.com.cn/problem/P2056
// 提交以下的code，提交时请把类名改成"Main"，一个测试用例空间超标
// 本节课Code07_HideSeek3文件是最优解的实现，可以通过所有测试用例
        // distFa[u] : u的连通区里，每个黑点到上级重心的距离，组成的集合
        // sonMax[u] :
u的每个儿子连通区里，都选一个最远的黑点，到u的最大距离，组成的集合
        //             如果u自己是黑点，那么0要加入集合
        // maxDist   :
每个重心在连通区里，选两个最远黑点的最大距离，作为自己的答案，放入全局集合
        // 讲解118，递归函数改成迭代所需要的栈
        // 重链剖分收集信息递归版，java会爆栈，C++不会
        // 根据重儿子剖分的递归版，java会爆栈，C++不会
        // dfs1改成迭代版
        // dfs2改成迭代版
        // 找重心需要计算子树大小的递归版，java会爆栈，C++不会
        // getSize1的迭代版
                // getSize1(u, fa);
                // dfs1(1, 0);
                // dfs2(1, 1);
        // 读写工具类
*/

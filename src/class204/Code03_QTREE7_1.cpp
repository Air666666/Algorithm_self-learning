// Source: src/class204/Code03_QTREE7_1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_QTREE7_1 {
  inline static int MAXN = 200001;
  inline static int INF = 1000000001;
  inline static int n = {};
  inline static int q = {};
  inline static Array<int> color = make_array<int>(MAXN);
  inline static Array<int> weight = make_array<int>(MAXN);
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> nxt = make_array<int>(MAXN);
  inline static Array<int> to = make_array<int>(MAXN);
  inline static int cntg = {};
  inline static Array<int> fa = make_array<int>(MAXN);
  inline static Array<int> ls = make_array<int>(MAXN);
  inline static Array<int> rs = make_array<int>(MAXN);
  inline static Array<int> parent = make_array<int>(MAXN);
  inline static Array<int> val = make_array<int>(MAXN);
  inline static JMap<int, JTreeMap<int, int>> vir =
      JMap<int, JTreeMap<int, int>>();
  inline static Array<int> maxv = make_array<int>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_QTREE7_1() {}
  static void addEdge(int u, int v) {
    (nxt[(++cntg)] = head[u]);
    (to[cntg] = v);
    (head[u] = cntg);
  }
  static void insert(int x, int v) {
    if ((!vir.containsKey(x))) {
      vir.put(x, JTreeMap<int, int>());
    }
    JTreeMap<int, int> map = vir.get(x);
    map.put(v, (map.getOrDefault(v, 0) + 1));
  }
  static void remove(int x, int v) {
    JTreeMap<int, int> map = vir.get(x);
    int cnt = map.get(v);
    if ((cnt == 1)) {
      map.remove(v);
    } else {
      map.put(v, (cnt - 1));
    }
  }
  static int getmax(int x) {
    if (((!vir.containsKey(x)) || vir.get(x).isEmpty())) {
      return (-INF);
    }
    return vir.get(x).lastKey();
  }
  static void up(int x) {
    (maxv[x] = jmax(val[x], [&]() {
       auto jargument_0 = Code03_QTREE7_1::getmax(x);
       auto jargument_1 = jmax(maxv[ls[x]], maxv[rs[x]]);
       return jmax(jargument_0, jargument_1);
     }()));
  }
  static bool isroot(int x) { return ((ls[fa[x]] != x) && (rs[fa[x]] != x)); }
  static int lr(int x) { return ((ls[fa[x]] == x) ? 0 : 1); }
  static void rotate(int x) {
    int f = fa[x];
    int g = fa[f];
    if ((Code03_QTREE7_1::lr(x) == 0)) {
      (ls[f] = rs[x]);
      if ((ls[f] != 0)) {
        (fa[ls[f]] = f);
      }
      (rs[x] = f);
    } else {
      (rs[f] = ls[x]);
      if ((rs[f] != 0)) {
        (fa[rs[f]] = f);
      }
      (ls[x] = f);
    }
    if ((!Code03_QTREE7_1::isroot(f))) {
      if ((Code03_QTREE7_1::lr(f) == 0)) {
        (ls[g] = x);
      } else {
        (rs[g] = x);
      }
    }
    (fa[f] = x);
    (fa[x] = g);
    Code03_QTREE7_1::up(f);
    Code03_QTREE7_1::up(x);
  }
  static void splay(int x) {
    while ((!Code03_QTREE7_1::isroot(x))) {
      int f = fa[x];
      if ((!Code03_QTREE7_1::isroot(f))) {
        if ([&]() {
              auto jleft = Code03_QTREE7_1::lr(x);
              auto jright = Code03_QTREE7_1::lr(f);
              return (jleft == jright);
            }()) {
          Code03_QTREE7_1::rotate(f);
        } else {
          Code03_QTREE7_1::rotate(x);
        }
      }
      Code03_QTREE7_1::rotate(x);
    }
    Code03_QTREE7_1::up(x);
  }
  static void access(int x) {
    for (int y = 0; (x != 0); (y = x), (x = fa[x])) {
      Code03_QTREE7_1::splay(x);
      if ((rs[x] != 0)) {
        Code03_QTREE7_1::insert(x, maxv[rs[x]]);
      }
      if ((y != 0)) {
        Code03_QTREE7_1::remove(x, maxv[y]);
      }
      (rs[x] = y);
      Code03_QTREE7_1::up(x);
    }
  }
  static int findroot(int x) {
    Code03_QTREE7_1::access(x);
    Code03_QTREE7_1::splay(x);
    while ((ls[x] != 0)) {
      (x = ls[x]);
    }
    Code03_QTREE7_1::splay(x);
    return x;
  }
  static void link(int x, int f) {
    if ((f == 0)) {
      return;
    }
    Code03_QTREE7_1::access(f);
    Code03_QTREE7_1::splay(f);
    Code03_QTREE7_1::splay(x);
    (fa[x] = f);
    Code03_QTREE7_1::insert(f, maxv[x]);
    Code03_QTREE7_1::up(f);
  }
  static void cut(int x, int f) {
    Code03_QTREE7_1::access(x);
    Code03_QTREE7_1::splay(x);
    if ((f != 0)) {
      int left = ls[x];
      (fa[left] = 0);
      (ls[x] = 0);
      Code03_QTREE7_1::up(x);
    }
  }
  static int query(int x) {
    int xs = ((val[x] != (-INF)) ? x : (x + n));
    int ys = Code03_QTREE7_1::findroot(xs);
    return ((val[ys] != (-INF)) ? maxv[ys] : maxv[rs[ys]]);
  }
  static void reverseColor(int x) {
    int pre = ((val[x] != (-INF)) ? x : (x + n));
    int cur = ((pre <= n) ? (pre + n) : (pre - n));
    Code03_QTREE7_1::cut(pre, parent[pre]);
    (val[cur] = val[pre]);
    (val[pre] = (-INF));
    Code03_QTREE7_1::link(cur, parent[cur]);
  }
  static void updateValue(int x, int w) {
    int cur = ((val[x] != (-INF)) ? x : (x + n));
    Code03_QTREE7_1::access(cur);
    Code03_QTREE7_1::splay(cur);
    (val[cur] = w);
    Code03_QTREE7_1::up(cur);
  }
  static void dfs(int u, int f) {
    if ((f != 0)) {
      (parent[u] = f);
      (parent[(u + n)] = (f + n));
    }
    for (int e = head[u]; (e != 0); (e = nxt[e])) {
      int v = to[e];
      if ((v != f)) {
        Code03_QTREE7_1::dfs(v, u);
        int cur = ((color[v] == 0) ? v : (v + n));
        Code03_QTREE7_1::link(cur, parent[cur]);
      }
    }
  }
  static void prepare() {
    (maxv[0] = (-INF));
    for (int i = 1; (i <= n); (i++)) {
      if ((color[i] == 0)) {
        (val[i] = (maxv[i] = weight[i]));
        (val[(i + n)] = (maxv[(i + n)] = (-INF)));
      } else {
        (val[i] = (maxv[i] = (-INF)));
        (val[(i + n)] = (maxv[(i + n)] = weight[i]));
      }
    }
    Code03_QTREE7_1::dfs(1, 0);
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    {
      int i = 1;
      int u = {};
      int v = {};
      for (; (i < n); (i++)) {
        (u = in.nextInt());
        (v = in.nextInt());
        Code03_QTREE7_1::addEdge(u, v);
        Code03_QTREE7_1::addEdge(v, u);
      }
    }
    for (int i = 1; (i <= n); (i++)) {
      (color[i] = in.nextInt());
    }
    for (int i = 1; (i <= n); (i++)) {
      (weight[i] = in.nextInt());
    }
    Code03_QTREE7_1::prepare();
    (q = in.nextInt());
    {
      int i = 1;
      int op = {};
      int x = {};
      int w = {};
      for (; (i <= q); (i++)) {
        (op = in.nextInt());
        (x = in.nextInt());
        if ((op == 0)) {
          out.println(Code03_QTREE7_1::query(x));
        } else if ((op == 1)) {
          Code03_QTREE7_1::reverseColor(x);
        } else {
          (w = in.nextInt());
          Code03_QTREE7_1::updateValue(x, w);
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
  Code03_QTREE7_1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// QTREE7，java版
// 给定一棵n个节点的树，每个节点有黑白两种颜色，给定初始颜色和点权
// 接下来有q条操作，操作类型如下
// 操作 0 x   : 打印节点x所在的同色连通块中的最大点权
// 操作 1 x   : 翻转节点x的颜色
// 操作 2 x w : 节点x的点权修改为w
// 1 <= n、q <= 10^5
// 测试链接 : https://www.luogu.com.cn/problem/SP16580
// 测试链接 : https://www.spoj.com/problems/QTREE7/
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 节点的初始颜色、初始点权
        // 节点x有两个状态
        // val[x] != -INF，说明节点x为黑，此时黑色状态的权值就是点权
        // val[x + n] != -INF，说明节点x为白，此时白色状态的权值就是点权
        // 一定有一个状态是节点点权，另一个状态是-INF
        // 保存状态x每个直接虚儿子的完整子树最大值，以及出现次数
        // maxv[x]表示以状态节点x为根的辅助splay汇总的最大点权
        // 包括x自身、x的虚子树、splay中的左右儿子
        // 注意修正虚子树贡献
        // 连接固定父边(x, f)，x是子，f是父，连接后x作为f的虚儿子
        // 删除固定父边(x, f)，x是子，f是父
                // 根据初始颜色，设置黑白状态的贡献和最大值
        // 读写工具类
*/

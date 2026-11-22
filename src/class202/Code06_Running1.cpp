// Source: src/class202/Code06_Running1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code06_Running1 {
  inline static int MAXN = 200001;
  inline static int n = {};
  inline static int m = {};
  inline static Array<int> father = make_array<int>(MAXN);
  inline static Array<int> fa = make_array<int>(MAXN);
  inline static Array<int> ls = make_array<int>(MAXN);
  inline static Array<int> rs = make_array<int>(MAXN);
  inline static Array<bool> rev = make_array<bool>(MAXN);
  inline static Array<int> sta = make_array<int>(MAXN);
  inline static Array<i64> arr = make_array<i64>(MAXN);
  inline static Array<i64> sum = make_array<i64>(MAXN);
  inline static Array<i64> sumOfSum = make_array<i64>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code06_Running1() {}
  static int find(int x) {
    if ((x != father[x])) {
      (father[x] = Code06_Running1::find(father[x]));
    }
    return father[x];
  }
  static void up(int x) {
    (sumOfSum[x] = ((sumOfSum[ls[x]] + sumOfSum[rs[x]]) + sum[x]));
  }
  static bool isroot(int x) { return ((ls[fa[x]] != x) && (rs[fa[x]] != x)); }
  static int lr(int x) { return ((ls[fa[x]] == x) ? 0 : 1); }
  static void reverse(int x) {
    if ((x != 0)) {
      int tmp = ls[x];
      (ls[x] = rs[x]);
      (rs[x] = tmp);
      (rev[x] = (!rev[x]));
    }
  }
  static void down(int x) {
    if (rev[x]) {
      Code06_Running1::reverse(ls[x]);
      Code06_Running1::reverse(rs[x]);
      (rev[x] = false);
    }
  }
  static void rotate(int x) {
    int f = fa[x];
    int g = fa[f];
    if ((Code06_Running1::lr(x) == 0)) {
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
    if ((!Code06_Running1::isroot(f))) {
      if ((Code06_Running1::lr(f) == 0)) {
        (ls[g] = x);
      } else {
        (rs[g] = x);
      }
    }
    (fa[f] = x);
    (fa[x] = g);
    Code06_Running1::up(f);
    Code06_Running1::up(x);
  }
  static void splay(int x) {
    int siz = 0;
    (sta[(++siz)] = x);
    for (int y = x; (!Code06_Running1::isroot(y)); (y = fa[y])) {
      (sta[(++siz)] = fa[y]);
    }
    while ((siz != 0)) {
      Code06_Running1::down(sta[(siz--)]);
    }
    while ((!Code06_Running1::isroot(x))) {
      int f = fa[x];
      if ((!Code06_Running1::isroot(f))) {
        if ([&]() {
              auto jleft = Code06_Running1::lr(x);
              auto jright = Code06_Running1::lr(f);
              return (jleft == jright);
            }()) {
          Code06_Running1::rotate(f);
        } else {
          Code06_Running1::rotate(x);
        }
      }
      Code06_Running1::rotate(x);
    }
  }
  static void access(int x) {
    (x = Code06_Running1::find(x));
    for (int y = 0; (x != 0); (y = x), (x = fa[x])) {
      Code06_Running1::splay(x);
      (rs[x] = y);
      Code06_Running1::up(x);
      (fa[x] = Code06_Running1::find(fa[x]));
    }
  }
  static void makeroot(int x) {
    Code06_Running1::access(x);
    Code06_Running1::splay(x);
    Code06_Running1::reverse(x);
  }
  static int findroot(int x) {
    Code06_Running1::access(x);
    Code06_Running1::splay(x);
    Code06_Running1::down(x);
    while ((ls[x] != 0)) {
      (x = ls[x]);
      Code06_Running1::down(x);
    }
    Code06_Running1::splay(x);
    return x;
  }
  static void split(int x, int y) {
    Code06_Running1::makeroot(x);
    Code06_Running1::access(y);
    Code06_Running1::splay(y);
  }
  static void condense(int x, int root) {
    if ((x != 0)) {
      (father[x] = root);
      (sum[root] += sum[x]);
      Code06_Running1::condense(ls[x], root);
      Code06_Running1::condense(rs[x], root);
    }
  }
  static void link(int x, int y) {
    (x = Code06_Running1::find(x));
    (y = Code06_Running1::find(y));
    if ((x == y)) {
      return;
    }
    Code06_Running1::makeroot(x);
    if ((Code06_Running1::findroot(y) != x)) {
      (fa[x] = y);
    } else {
      Code06_Running1::condense(rs[x], x);
      (rs[x] = 0);
      Code06_Running1::up(x);
    }
  }
  static void update(int x, int y) {
    i64 delta = (y - arr[x]);
    (arr[x] = y);
    (x = Code06_Running1::find(x));
    Code06_Running1::makeroot(x);
    (sum[x] += delta);
    Code06_Running1::up(x);
  }
  static i64 query(int x, int y) {
    (x = Code06_Running1::find(x));
    (y = Code06_Running1::find(y));
    if ([&]() {
          auto jleft = Code06_Running1::findroot(x);
          auto jright = Code06_Running1::findroot(y);
          return (jleft != jright);
        }()) {
      return (-1);
    }
    Code06_Running1::split(x, y);
    return sumOfSum[y];
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (m = in.nextInt());
    for (int i = 1; (i <= n); (i++)) {
      (father[i] = i);
      (arr[i] = in.nextInt());
      (sum[i] = arr[i]);
      (sumOfSum[i] = arr[i]);
    }
    {
      int i = 1;
      int op = {};
      int x = {};
      int y = {};
      for (; (i <= m); (i++)) {
        (op = in.nextInt());
        (x = in.nextInt());
        (y = in.nextInt());
        if ((op == 1)) {
          Code06_Running1::link(x, y);
        } else if ((op == 2)) {
          Code06_Running1::update(x, y);
        } else {
          out.println(Code06_Running1::query(x, y));
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
  Code06_Running1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 长跑，java版
// 一共n个点，每个点有点权，初始没有边，接下来有m条操作，格式如下
// 操作 1 x y : 点x和点y之间增加无向边
// 操作 2 x y : 点x的点权变成y
// 操作 3 x y : 每条边需要指定方向变成单向边，希望点x到点y的过程中
//              获得最多的点权累加和，重复经过某点只获得一次点权
//              打印能获得的点权累加和最大值，如果不连通打印-1
//              指定边的方向仅影响本次操作，不会影响后续操作
// 1 <= n <= 1.5 * 10^5    1 <= m <= 5 * n
// 测试链接 : https://www.luogu.com.cn/problem/P10658
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 单点的点权
        // sum[x]表示x代表的边双连通分量中，点权累加和
        // sumOfSum[x]表示以x为根的辅助splay中，点权累加和
        // 也就是整条实链的点权累加和，实链上的每个点，可能是代表点
        // 如果两点不连通就连接，如果连通，说明形成环，缩成一个边双
        // 修改点权
        // 查询两点路径上，所有边双连通分量的权值和
        // 读写工具类
*/

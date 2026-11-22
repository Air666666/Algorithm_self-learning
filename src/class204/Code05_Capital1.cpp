// Source: src/class204/Code05_Capital1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code05_Capital1 {
  inline static int MAXN = 100001;
  inline static int n = {};
  inline static int m = {};
  inline static Array<int> fa = make_array<int>(MAXN);
  inline static Array<int> ls = make_array<int>(MAXN);
  inline static Array<int> rs = make_array<int>(MAXN);
  inline static Array<bool> rev = make_array<bool>(MAXN);
  inline static Array<int> sta = make_array<int>(MAXN);
  inline static Array<int> father = make_array<int>(MAXN);
  inline static Array<int> vir = make_array<int>(MAXN);
  inline static Array<int> sum = make_array<int>(MAXN);
  inline static int xorsum = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code05_Capital1() {}
  static int find(int x) {
    if ((x != father[x])) {
      (father[x] = Code05_Capital1::find(father[x]));
    }
    return father[x];
  }
  static void up(int x) {
    (sum[x] = (((sum[ls[x]] + sum[rs[x]]) + vir[x]) + 1));
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
      Code05_Capital1::reverse(ls[x]);
      Code05_Capital1::reverse(rs[x]);
      (rev[x] = false);
    }
  }
  static void rotate(int x) {
    int f = fa[x];
    int g = fa[f];
    if ((Code05_Capital1::lr(x) == 0)) {
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
    if ((!Code05_Capital1::isroot(f))) {
      if ((Code05_Capital1::lr(f) == 0)) {
        (ls[g] = x);
      } else {
        (rs[g] = x);
      }
    }
    (fa[f] = x);
    (fa[x] = g);
    Code05_Capital1::up(f);
    Code05_Capital1::up(x);
  }
  static void splay(int x) {
    int siz = 0;
    (sta[(++siz)] = x);
    for (int y = x; (!Code05_Capital1::isroot(y)); (y = fa[y])) {
      (sta[(++siz)] = fa[y]);
    }
    while ((siz != 0)) {
      Code05_Capital1::down(sta[(siz--)]);
    }
    while ((!Code05_Capital1::isroot(x))) {
      int f = fa[x];
      if ((!Code05_Capital1::isroot(f))) {
        if ([&]() {
              auto jleft = Code05_Capital1::lr(x);
              auto jright = Code05_Capital1::lr(f);
              return (jleft == jright);
            }()) {
          Code05_Capital1::rotate(f);
        } else {
          Code05_Capital1::rotate(x);
        }
      }
      Code05_Capital1::rotate(x);
    }
  }
  static void access(int x) {
    for (int y = 0; (x != 0); (y = x), (x = fa[x])) {
      Code05_Capital1::splay(x);
      (vir[x] += sum[rs[x]]);
      (vir[x] -= sum[y]);
      (rs[x] = y);
      Code05_Capital1::up(x);
    }
  }
  static void makeroot(int x) {
    Code05_Capital1::access(x);
    Code05_Capital1::splay(x);
    Code05_Capital1::reverse(x);
  }
  static int findroot(int x) {
    Code05_Capital1::access(x);
    Code05_Capital1::splay(x);
    Code05_Capital1::down(x);
    while ((ls[x] != 0)) {
      (x = ls[x]);
      Code05_Capital1::down(x);
    }
    Code05_Capital1::splay(x);
    return x;
  }
  static void split(int x, int y) {
    Code05_Capital1::makeroot(x);
    Code05_Capital1::access(y);
    Code05_Capital1::splay(y);
  }
  static void link(int x, int y) {
    Code05_Capital1::makeroot(x);
    if ((Code05_Capital1::findroot(y) != x)) {
      Code05_Capital1::access(y);
      Code05_Capital1::splay(y);
      (fa[x] = y);
      (vir[y] += sum[x]);
      Code05_Capital1::up(y);
    }
  }
  static int newCenter(int a, int b) {
    Code05_Capital1::split(a, b);
    int half = jshr(sum[b], 1);
    int lpass = 0;
    int rpass = 0;
    int ans = (n + 1);
    int cur = b;
    while ((cur != 0)) {
      Code05_Capital1::down(cur);
      int lsiz = (sum[ls[cur]] + lpass);
      int rsiz = (sum[rs[cur]] + rpass);
      if (((lsiz <= half) && (rsiz <= half))) {
        (ans = jmin(ans, cur));
      }
      if ((lsiz < rsiz)) {
        (lpass += ((sum[ls[cur]] + vir[cur]) + 1));
        (cur = rs[cur]);
      } else {
        (rpass += ((sum[rs[cur]] + vir[cur]) + 1));
        (cur = ls[cur]);
      }
    }
    Code05_Capital1::splay(ans);
    return ans;
  }
  static void road(int x, int y) {
    int a = Code05_Capital1::find(x);
    int b = Code05_Capital1::find(y);
    Code05_Capital1::link(x, y);
    int cur = Code05_Capital1::newCenter(a, b);
    (father[cur] = (father[a] = (father[b] = cur)));
    (xorsum ^= ((a ^ b) ^ cur));
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (m = in.nextInt());
    for (int i = 1; (i <= n); (i++)) {
      (sum[i] = 1);
      (father[i] = i);
      (xorsum ^= i);
    }
    String op = {};
    int x = {};
    int y = {};
    for (int i = 1; (i <= m); (i++)) {
      (op = in.nextString());
      if (op.equals(String(u"A"))) {
        (x = in.nextInt());
        (y = in.nextInt());
        Code05_Capital1::road(x, y);
      } else if (op.equals(String(u"Q"))) {
        (x = in.nextInt());
        out.println(Code05_Capital1::find(x));
      } else {
        out.println(xorsum);
      }
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code05_Capital1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 首都，java版
// 初始时有n个互不连通的点，然后有m条操作，操作类型如下
// 操作 A x y : 点x和点y之间连一条边，保证之前x和y是不连通的
// 操作 Q x   : 打印点x所在连通区的重心编号
// 操作 Xor   : 打印当前所有连通区，重心编号的异或和
// 本题的一个连通区就是一棵树，重心是到其他点的距离总和最小的点
// 为了保证重心唯一，本题规定，如果有多个重心，选择编号最小的点作为重心
// 1 <= n <= 10^5
// 1 <= m <= 2 * 10^5
// 测试链接 : https://www.luogu.com.cn/problem/P4299
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 并查集维护连通性，连通块的代表节点就是连通块的重心
        // 查询x所在连通块当前的重心
        // 根据两个旧重心a和b，寻找并返回新重心
                // 打通两个旧重心的路径，新重心一定在这条路径上
                        // 先要处理翻转标记，才能正确的向左或者向右移动
                        // 课上重点讲解了，只需要检查路径的两个方向的子树即可
                        // 向节点数量较多的一侧移动
                // 新重心旋转上去，保证平衡性
        // 读写工具类
*/

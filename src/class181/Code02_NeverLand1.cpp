// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P3224

// Source: src/class181/Code02_NeverLand1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_NeverLand1 {
  inline static int MAXN = 100001;
  inline static int MAXT = (MAXN * 40);
  inline static int n = {};
  inline static int m = {};
  inline static int q = {};
  inline static Array<int> pos = make_array<int>(MAXN);
  inline static Array<int> father = make_array<int>(MAXN);
  inline static Array<int> root = make_array<int>(MAXN);
  inline static Array<int> ls = make_array<int>(MAXT);
  inline static Array<int> rs = make_array<int>(MAXT);
  inline static Array<int> siz = make_array<int>(MAXT);
  inline static int cntt = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_NeverLand1() {}
  static void up(int i) { (siz[i] = (siz[ls[i]] + siz[rs[i]])); }
  static int add(int jobi, int l, int r, int i) {
    int rt = i;
    if ((rt == 0)) {
      (rt = (++cntt));
    }
    if ((l == r)) {
      (siz[rt]++);
    } else {
      int mid = jshr((l + r), 1);
      if ((jobi <= mid)) {
        (ls[rt] = Code02_NeverLand1::add(jobi, l, mid, ls[rt]));
      } else {
        (rs[rt] = Code02_NeverLand1::add(jobi, (mid + 1), r, rs[rt]));
      }
      Code02_NeverLand1::up(rt);
    }
    return rt;
  }
  static int merge(int l, int r, int t1, int t2) {
    if (((t1 == 0) || (t2 == 0))) {
      return (t1 + t2);
    }
    if ((l == r)) {
      (siz[t1] += siz[t2]);
    } else {
      int mid = jshr((l + r), 1);
      (ls[t1] = Code02_NeverLand1::merge(l, mid, ls[t1], ls[t2]));
      (rs[t1] = Code02_NeverLand1::merge((mid + 1), r, rs[t1], rs[t2]));
      Code02_NeverLand1::up(t1);
    }
    return t1;
  }
  static int query(int jobk, int l, int r, int i) {
    if (((i == 0) || (jobk > siz[i]))) {
      return (-1);
    }
    if ((l == r)) {
      return pos[l];
    }
    int mid = jshr((l + r), 1);
    if ((siz[ls[i]] >= jobk)) {
      return Code02_NeverLand1::query(jobk, l, mid, ls[i]);
    } else {
      return Code02_NeverLand1::query((jobk - siz[ls[i]]), (mid + 1), r, rs[i]);
    }
  }
  static int find(int i) {
    if ((i != father[i])) {
      (father[i] = Code02_NeverLand1::find(father[i]));
    }
    return father[i];
  }
  static void union_method(int x, int y) {
    int xfa = Code02_NeverLand1::find(x);
    int yfa = Code02_NeverLand1::find(y);
    if ((xfa != yfa)) {
      (father[xfa] = yfa);
      (root[yfa] = Code02_NeverLand1::merge(1, n, root[yfa], root[xfa]));
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO();
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (m = in.nextInt());
    int num = {};
    for (int i = 1; (i <= n); (i++)) {
      (num = in.nextInt());
      (pos[num] = i);
      (father[i] = i);
      (root[i] = Code02_NeverLand1::add(num, 1, n, root[i]));
    }
    {
      int i = 1;
      int x = {};
      int y = {};
      for (; (i <= m); (i++)) {
        (x = in.nextInt());
        (y = in.nextInt());
        Code02_NeverLand1::union_method(x, y);
      }
    }
    (q = in.nextInt());
    jchar op = {};
    int x = {};
    int y = {};
    int k = {};
    for (int i = 1; (i <= q); (i++)) {
      (op = in.nextTokenLastChar());
      if ((op == u'B')) {
        (x = in.nextInt());
        (y = in.nextInt());
        Code02_NeverLand1::union_method(x, y);
      } else {
        (x = in.nextInt());
        (k = in.nextInt());
        out.println(Code02_NeverLand1::query(k, 1, n,
                                             root[Code02_NeverLand1::find(x)]));
      }
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code02_NeverLand1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 永无乡，java版
// 一共有n个岛，每个岛分配到一个不同的数字，数字范围1~n
// 给定初始的m座桥梁，若干点会连通起来，接下来有q条操作，格式如下
// 操作 B x y : x号岛和y号岛之间新修建了一座桥
// 操作 Q x k : x号岛所在的连通区里，打印第k小的数字来自几号岛，不存在打印-1
// 1 <= n、m <= 10^5
// 测试链接 : https://www.luogu.com.cn/problem/P3224
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // pos[v] = i，表示数字v属于第i号岛
        // 并查集
        // 权值线段树
        // 读写工具类
*/

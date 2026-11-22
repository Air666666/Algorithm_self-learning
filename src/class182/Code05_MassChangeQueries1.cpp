// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/CF911G
// https://codeforces.com/problemset/problem/911/G

// Source: src/class182/Code05_MassChangeQueries1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code05_MassChangeQueries1 {
  inline static int MAXN = 200001;
  inline static int MAXT = (MAXN * 10);
  inline static int MAXV = 100;
  inline static int n = {};
  inline static int q = {};
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static Array<int> root = make_array<int>((MAXV + 1));
  inline static Array<int> ls = make_array<int>(MAXT);
  inline static Array<int> rs = make_array<int>(MAXT);
  inline static Array<bool> status = make_array<bool>(MAXT);
  inline static Array<int> pool = make_array<int>(MAXT);
  inline static int top = {};
  inline static int tree1 = {};
  inline static int tree2 = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code05_MassChangeQueries1() {}
  static void prepare() {
    (top = 0);
    for (int i = 1; (i < MAXT); (i++)) {
      (pool[(++top)] = i);
    }
  }
  static int newNode() { return pool[(top--)]; }
  static void del(int i) {
    (pool[(++top)] = i);
    (ls[i] = 0);
    (rs[i] = 0);
    (status[i] = false);
  }
  static void up(int i) { (status[i] = (status[ls[i]] | status[rs[i]])); }
  static int insert(int jobi, int l, int r, int i) {
    int rt = i;
    if ((rt == 0)) {
      (rt = Code05_MassChangeQueries1::newNode());
    }
    if ((l == r)) {
      (status[rt] = true);
    } else {
      int mid = jshr((l + r), 1);
      if ((jobi <= mid)) {
        (ls[rt] = Code05_MassChangeQueries1::insert(jobi, l, mid, ls[rt]));
      } else {
        (rs[rt] =
             Code05_MassChangeQueries1::insert(jobi, (mid + 1), r, rs[rt]));
      }
      Code05_MassChangeQueries1::up(rt);
    }
    return rt;
  }
  static int merge(int l, int r, int t1, int t2) {
    if (((t1 == 0) || (t2 == 0))) {
      return (t1 + t2);
    }
    if ((l == r)) {
      (status[t1] = (status[t1] | status[t2]));
    } else {
      int mid = jshr((l + r), 1);
      (ls[t1] = Code05_MassChangeQueries1::merge(l, mid, ls[t1], ls[t2]));
      (rs[t1] = Code05_MassChangeQueries1::merge((mid + 1), r, rs[t1], rs[t2]));
      Code05_MassChangeQueries1::up(t1);
    }
    Code05_MassChangeQueries1::del(t2);
    return t1;
  }
  static void split(int jobl, int jobr, int l, int r, int t1) {
    if ((t1 == 0)) {
      (tree1 = t1);
      (tree2 = 0);
      return;
    }
    if (((jobl <= l) && (r <= jobr))) {
      (tree1 = 0);
      (tree2 = t1);
      return;
    }
    int t2 = Code05_MassChangeQueries1::newNode();
    int mid = jshr((l + r), 1);
    if ((jobl <= mid)) {
      Code05_MassChangeQueries1::split(jobl, jobr, l, mid, ls[t1]);
      (ls[t1] = tree1);
      (ls[t2] = tree2);
    }
    if ((jobr > mid)) {
      Code05_MassChangeQueries1::split(jobl, jobr, (mid + 1), r, rs[t1]);
      (rs[t1] = tree1);
      (rs[t2] = tree2);
    }
    Code05_MassChangeQueries1::up(t1);
    Code05_MassChangeQueries1::up(t2);
    (tree1 = t1);
    (tree2 = t2);
  }
  static void dfs(int val, int l, int r, int i) {
    if (((i == 0) || (!status[i]))) {
      return;
    }
    if ((l == r)) {
      (arr[l] = val);
    } else {
      int mid = jshr((l + r), 1);
      Code05_MassChangeQueries1::dfs(val, l, mid, ls[i]);
      Code05_MassChangeQueries1::dfs(val, (mid + 1), r, rs[i]);
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    Code05_MassChangeQueries1::prepare();
    (n = in.nextInt());
    for (int i = 1; (i <= n); (i++)) {
      (arr[i] = in.nextInt());
    }
    for (int i = 1; (i <= n); (i++)) {
      (root[arr[i]] = Code05_MassChangeQueries1::insert(i, 1, n, root[arr[i]]));
    }
    (q = in.nextInt());
    {
      int i = 1;
      int l = {};
      int r = {};
      int x = {};
      int y = {};
      for (; (i <= q); (i++)) {
        (l = in.nextInt());
        (r = in.nextInt());
        (x = in.nextInt());
        (y = in.nextInt());
        Code05_MassChangeQueries1::split(l, r, 1, n, root[x]);
        (root[x] = tree1);
        (root[y] = Code05_MassChangeQueries1::merge(1, n, root[y], tree2));
      }
    }
    for (int v = 1; (v <= MAXV); (v++)) {
      Code05_MassChangeQueries1::dfs(v, 1, n, root[v]);
    }
    for (int i = 1; (i <= n); (i++)) {
      out.print((arr[i] + String(u" ")));
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code05_MassChangeQueries1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 值全改的操作，java版
// 给定一个长度为n的数组arr，接下来有q条操作，格式如下
// 操作 l r x y : arr[l..r]范围上，所有数字x改成数字y
// 所有操作做完之后，从左到右打印arr中的值
// 1 <= n、q <= 2 * 10^5
// 1 <= arr[i]、x、y <= 100
// 测试链接 : https://www.luogu.com.cn/problem/CF911G
// 测试链接 : https://codeforces.com/problemset/problem/911/G
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 读写工具类
*/

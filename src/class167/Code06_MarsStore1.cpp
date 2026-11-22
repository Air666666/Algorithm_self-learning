// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P4585

// Source: src/class167/Code06_MarsStore1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code06_MarsStore1 {
  inline static int MAXN = 100001;
  inline static int MAXT = 2000001;
  inline static int BIT = 16;
  inline static int n = {};
  inline static int m = {};
  inline static int t = {};
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static Array<int> op = make_array<int>(MAXN);
  inline static Array<int> s = make_array<int>(MAXN);
  inline static Array<int> v = make_array<int>(MAXN);
  inline static Array<int> sl = make_array<int>(MAXN);
  inline static Array<int> sr = make_array<int>(MAXN);
  inline static Array<int> x = make_array<int>(MAXN);
  inline static Array<int> d = make_array<int>(MAXN);
  inline static Array<int> tim = make_array<int>(MAXN);
  inline static Array<int> root = make_array<int>(MAXN);
  inline static Array<Array<int>> tree = make_array<int>(MAXT, 2);
  inline static Array<int> pass = make_array<int>(MAXT);
  inline static int cntt = 0;
  inline static Array<int> headp = make_array<int>(jshl(MAXN, 2));
  inline static Array<int> nextp = make_array<int>(MAXT);
  inline static Array<int> pid = make_array<int>(MAXT);
  inline static int cntp = 0;
  inline static Array<int> headb = make_array<int>(jshl(MAXN, 2));
  inline static Array<int> nextb = make_array<int>(MAXT);
  inline static Array<int> bid = make_array<int>(MAXT);
  inline static int cntb = 0;
  inline static Array<Array<int>> product = make_array<int>(MAXN, 2);
  inline static Array<int> ans = make_array<int>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code06_MarsStore1() {}
  static int insert(int num, int i) {
    int rt = (++cntt);
    (tree[rt][0] = tree[i][0]);
    (tree[rt][1] = tree[i][1]);
    (pass[rt] = (pass[i] + 1));
    {
      int b = BIT;
      int path = {};
      int pre = rt;
      int cur = {};
      for (; (b >= 0); (b--), (pre = cur)) {
        (path = (jshr(num, b) & 1));
        (i = tree[i][path]);
        (cur = (++cntt));
        (tree[cur][0] = tree[i][0]);
        (tree[cur][1] = tree[i][1]);
        (pass[cur] = (pass[i] + 1));
        (tree[pre][path] = cur);
      }
    }
    return rt;
  }
  static int query(int num, int u, int v) {
    int ans = 0;
    {
      int b = BIT;
      int path = {};
      int best = {};
      for (; (b >= 0); (b--)) {
        (path = (jshr(num, b) & 1));
        (best = (path ^ 1));
        if ((pass[tree[v][best]] > pass[tree[u][best]])) {
          (ans += jshl(1, b));
          (u = tree[u][best]);
          (v = tree[v][best]);
        } else {
          (u = tree[u][path]);
          (v = tree[v][path]);
        }
      }
    }
    return ans;
  }
  static void addInfoP(int i, int pi) {
    (nextp[(++cntp)] = headp[i]);
    (pid[cntp] = pi);
    (headp[i] = cntp);
  }
  static void addInfoB(int i, int bi) {
    (nextb[(++cntb)] = headb[i]);
    (bid[cntb] = bi);
    (headb[i] = cntb);
  }
  static void addProduct(int jobi, int pi, int l, int r, int i) {
    Code06_MarsStore1::addInfoP(i, pi);
    if ((l < r)) {
      int mid = jshr((l + r), 1);
      if ((jobi <= mid)) {
        Code06_MarsStore1::addProduct(jobi, pi, l, mid, jshl(i, 1));
      } else {
        Code06_MarsStore1::addProduct(jobi, pi, (mid + 1), r, (jshl(i, 1) | 1));
      }
    }
  }
  static void addBuy(int jobl, int jobr, int bi, int l, int r, int i) {
    if (((jobl <= l) && (r <= jobr))) {
      Code06_MarsStore1::addInfoB(i, bi);
    } else {
      int mid = jdiv((l + r), 2);
      if ((jobl <= mid)) {
        Code06_MarsStore1::addBuy(jobl, jobr, bi, l, mid, jshl(i, 1));
      }
      if ((jobr > mid)) {
        Code06_MarsStore1::addBuy(jobl, jobr, bi, (mid + 1), r,
                                  (jshl(i, 1) | 1));
      }
    }
  }
  static int lower(int size, int num) {
    int l = 1;
    int r = size;
    int ans = (size + 1);
    while ((l <= r)) {
      int mid = jshr((l + r), 1);
      if ((product[mid][0] >= num)) {
        (ans = mid);
        (r = (mid - 1));
      } else {
        (l = (mid + 1));
      }
    }
    return ans;
  }
  static int upper(int size, int num) {
    int l = 1;
    int r = size;
    int ans = 0;
    while ((l <= r)) {
      int mid = jshr((l + r), 1);
      if ((product[mid][0] <= num)) {
        (ans = mid);
        (l = (mid + 1));
      } else {
        (r = (mid - 1));
      }
    }
    return ans;
  }
  static void dfs(int l, int r, int i) {
    int pcnt = 0;
    for (int e = headp[i]; (e > 0); (e = nextp[e])) {
      (product[(++pcnt)][0] = s[pid[e]]);
      (product[pcnt][1] = v[pid[e]]);
    }
    j::sort(product, 1, (pcnt + 1),
            [=](Array<int> a, Array<int> b) { return (a[0] - b[0]); });
    (cntt = 0);
    for (int k = 1; (k <= pcnt); (k++)) {
      (root[k] = Code06_MarsStore1::insert(product[k][1], root[(k - 1)]));
    }
    {
      int e = headb[i];
      int id = {};
      int pre = {};
      int post = {};
      for (; (e > 0); (e = nextb[e])) {
        (id = bid[e]);
        (pre = (Code06_MarsStore1::lower(pcnt, sl[id]) - 1));
        (post = Code06_MarsStore1::upper(pcnt, sr[id]));
        (ans[id] = jmax(
             ans[id], Code06_MarsStore1::query(x[id], root[pre], root[post])));
      }
    }
    if ((l < r)) {
      int mid = jshr((l + r), 1);
      Code06_MarsStore1::dfs(l, mid, jshl(i, 1));
      Code06_MarsStore1::dfs((mid + 1), r, (jshl(i, 1) | 1));
    }
  }
  static void prepare() {
    for (int i = 1; (i <= n); (i++)) {
      (root[i] = Code06_MarsStore1::insert(arr[i], root[(i - 1)]));
    }
    for (int i = 1; (i <= m); (i++)) {
      if ((op[i] == 0)) {
        Code06_MarsStore1::addProduct(tim[i], i, 1, t, 1);
      } else {
        (ans[i] =
             Code06_MarsStore1::query(x[i], root[(sl[i] - 1)], root[sr[i]]));
        int start = jmax(((tim[i] - d[i]) + 1), 1);
        if ((start <= tim[i])) {
          Code06_MarsStore1::addBuy(start, tim[i], i, 1, t, 1);
        }
      }
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO();
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (m = in.nextInt());
    (t = 0);
    for (int i = 1; (i <= n); (i++)) {
      (arr[i] = in.nextInt());
    }
    for (int i = 1; (i <= m); (i++)) {
      (op[i] = in.nextInt());
      if ((op[i] == 0)) {
        (t++);
        (s[i] = in.nextInt());
        (v[i] = in.nextInt());
      } else {
        (sl[i] = in.nextInt());
        (sr[i] = in.nextInt());
        (x[i] = in.nextInt());
        (d[i] = in.nextInt());
      }
      (tim[i] = t);
    }
    Code06_MarsStore1::prepare();
    Code06_MarsStore1::dfs(1, t, 1);
    for (int i = 1; (i <= m); (i++)) {
      if ((op[i] == 1)) {
        out.println(ans[i]);
      }
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code06_MarsStore1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 火星商店，java版
// 有n个商店，每个商店只有一种初始商品，给出每个商店的初始商品价格
// 有m条操作，每种操作是如下两种类型中的一种
// 操作 0 s v     : 操作0会让天数+1，第s号商店，在这天增加了价格为v的新商品
// 操作 1 l r x d : 只能在商店[l..r]中挑选，只能挑选初始商品或d天内出现的新商品
//                  只能挑选一件商品，打印 商品的价格 ^ x 的最大值
// 注意，只有操作0能让天数+1，操作1不会
// 0 <= 所有数据 <= 10^5
// 测试链接 : https://www.luogu.com.cn/problem/P4585
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 每个商品(所属的商店编号，该商品的价格)
        // 可持久化前缀树
        // 基于i版本的树，添加num，返回新版本的编号
        // 可持久化前缀树
        // 根据(v版本 - u版本)的数据状况，看看哪个数字 ^ num能得到最大值并返回
        // 当前商品编号pi，沿途经过的所有区间，都把该商品加上
        // 当前购买行为编号bi，命中的线段树区间，把该购买行为加上
        // 读写工具类
*/

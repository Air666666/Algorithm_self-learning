// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P4219

// Source: src/class166/Code05_GreatIntegration1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code05_GreatIntegration1 {
  inline static int MAXN = 100001;
  inline static int MAXT = 3000001;
  inline static int n = {};
  inline static int q = {};
  inline static Array<int> op = make_array<int>(MAXN);
  inline static Array<int> u = make_array<int>(MAXN);
  inline static Array<int> v = make_array<int>(MAXN);
  inline static Array<Array<int>> event = make_array<int>(MAXN, 3);
  inline static Array<int> father = make_array<int>(MAXN);
  inline static Array<int> siz = make_array<int>(MAXN);
  inline static Array<Array<int>> rollback = make_array<int>(MAXN, 2);
  inline static int opsize = 0;
  inline static Array<int> head = make_array<int>(jshl(MAXN, 2));
  inline static Array<int> next = make_array<int>(MAXT);
  inline static Array<int> tox = make_array<int>(MAXT);
  inline static Array<int> toy = make_array<int>(MAXT);
  inline static int cnt = 0;
  inline static Array<i64> ans = make_array<i64>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code05_GreatIntegration1() {}
  static void addEdge(int i, int x, int y) {
    (next[(++cnt)] = head[i]);
    (tox[cnt] = x);
    (toy[cnt] = y);
    (head[i] = cnt);
  }
  static int find(int i) {
    while ((i != father[i])) {
      (i = father[i]);
    }
    return i;
  }
  static void union_method(int x, int y) {
    int fx = Code05_GreatIntegration1::find(x);
    int fy = Code05_GreatIntegration1::find(y);
    if ((siz[fx] < siz[fy])) {
      int tmp = fx;
      (fx = fy);
      (fy = tmp);
    }
    (father[fy] = fx);
    (siz[fx] += siz[fy]);
    (rollback[(++opsize)][0] = fx);
    (rollback[opsize][1] = fy);
  }
  static void undo() {
    int fx = rollback[opsize][0];
    int fy = rollback[(opsize--)][1];
    (father[fy] = fy);
    (siz[fx] -= siz[fy]);
  }
  static void add(int jobl, int jobr, int jobx, int joby, int l, int r, int i) {
    if (((jobl <= l) && (r <= jobr))) {
      Code05_GreatIntegration1::addEdge(i, jobx, joby);
    } else {
      int mid = jshr((l + r), 1);
      if ((jobl <= mid)) {
        Code05_GreatIntegration1::add(jobl, jobr, jobx, joby, l, mid,
                                      jshl(i, 1));
      }
      if ((jobr > mid)) {
        Code05_GreatIntegration1::add(jobl, jobr, jobx, joby, (mid + 1), r,
                                      (jshl(i, 1) | 1));
      }
    }
  }
  static void dfs(int l, int r, int i) {
    int unionCnt = 0;
    for (int ei = head[i]; (ei > 0); (ei = next[ei])) {
      Code05_GreatIntegration1::union_method(tox[ei], toy[ei]);
      (unionCnt++);
    }
    if ((l == r)) {
      if ((op[l] == 2)) {
        (ans[l] = [&]() {
          auto jleft =
              static_cast<i64>(siz[Code05_GreatIntegration1::find(u[l])]);
          auto jright = siz[Code05_GreatIntegration1::find(v[l])];
          return (jleft * jright);
        }());
      }
    } else {
      int mid = jshr((l + r), 1);
      Code05_GreatIntegration1::dfs(l, mid, jshl(i, 1));
      Code05_GreatIntegration1::dfs((mid + 1), r, (jshl(i, 1) | 1));
    }
    for (int k = 1; (k <= unionCnt); (k++)) {
      Code05_GreatIntegration1::undo();
    }
  }
  static void prepare() {
    for (int i = 1; (i <= n); (i++)) {
      (father[i] = i);
      (siz[i] = 1);
    }
    for (int i = 1; (i <= q); (i++)) {
      (event[i][0] = u[i]);
      (event[i][1] = v[i]);
      (event[i][2] = i);
    }
    j::sort(event, 1, (q + 1), [=](Array<int> a, Array<int> b) {
      return ((a[0] != b[0])
                  ? (a[0] - b[0])
                  : ((a[1] != b[1]) ? (a[1] - b[1]) : (a[2] - b[2])));
    });
    {
      int l = 1;
      int r = 1;
      for (; (l <= q); (l = (++r))) {
        int x = event[l][0];
        int y = event[l][1];
        int t = event[l][2];
        while (((((r + 1) <= q) && (event[(r + 1)][0] == x)) &&
                (event[(r + 1)][1] == y))) {
          (r++);
        }
        for (int i = (l + 1); (i <= r); (i++)) {
          Code05_GreatIntegration1::add(t, (event[i][2] - 1), x, y, 1, q, 1);
          (t = (event[i][2] + 1));
        }
        if ((t <= q)) {
          Code05_GreatIntegration1::add(t, q, x, y, 1, q, 1);
        }
      }
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO();
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (q = in.nextInt());
    jchar t = {};
    int x = {};
    int y = {};
    for (int i = 1; (i <= q); (i++)) {
      (t = in.nextTokenLastChar());
      (x = in.nextInt());
      (y = in.nextInt());
      (op[i] = ((t == u'A') ? 1 : 2));
      (u[i] = jmin(x, y));
      (v[i] = jmax(x, y));
    }
    Code05_GreatIntegration1::prepare();
    Code05_GreatIntegration1::dfs(1, q, 1);
    for (int i = 1; (i <= q); (i++)) {
      if ((op[i] == 2)) {
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
  Code05_GreatIntegration1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 大融合，java版
// 一共有n个点，一共有q条操作，每条操作是如下两种类型中的一种
// 操作 A x y : 点x和点y之间连一条边，保证之前x和y是不联通的
// 操作 Q x y : 打印点x和点y之间这条边的负载，保证x和y之间有一条边
// 边负载定义为，这条边两侧端点各自连通区大小的乘积
// 1 <= n、q <= 10^5
// 测试链接 : https://www.luogu.com.cn/problem/P4219
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 端点x、端点y、操作序号t
        // 读写工具类
*/

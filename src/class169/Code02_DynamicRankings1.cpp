// Source: src/class169/Code02_DynamicRankings1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_DynamicRankings1 {
  inline static int MAXN = 100001;
  inline static int MAXE = jshl(MAXN, 2);
  inline static int INF = 1000000001;
  inline static int n = {};
  inline static int m = {};
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static Array<int> eid = make_array<int>(MAXE);
  inline static Array<int> op = make_array<int>(MAXE);
  inline static Array<int> x = make_array<int>(MAXE);
  inline static Array<int> y = make_array<int>(MAXE);
  inline static Array<int> v = make_array<int>(MAXE);
  inline static Array<int> q = make_array<int>(MAXE);
  inline static int cnte = 0;
  inline static int cntq = 0;
  inline static Array<int> tree = make_array<int>(MAXN);
  inline static Array<int> lset = make_array<int>(MAXE);
  inline static Array<int> rset = make_array<int>(MAXE);
  inline static Array<int> ans = make_array<int>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_DynamicRankings1() {}
  static int lowbit(int i) { return (i & (-i)); }
  static void add(int i, int v) {
    while ((i <= n)) {
      (tree[i] += v);
      (i += Code02_DynamicRankings1::lowbit(i));
    }
  }
  static int sum(int i) {
    int ret = 0;
    while ((i > 0)) {
      (ret += tree[i]);
      (i -= Code02_DynamicRankings1::lowbit(i));
    }
    return ret;
  }
  static int query(int l, int r) {
    return [&]() {
      auto jleft = Code02_DynamicRankings1::sum(r);
      auto jright = Code02_DynamicRankings1::sum((l - 1));
      return (jleft - jright);
    }();
  }
  static void compute(int el, int er, int vl, int vr) {
    if ((el > er)) {
      return;
    }
    if ((vl == vr)) {
      for (int i = el; (i <= er); (i++)) {
        int id = eid[i];
        if ((op[id] == 2)) {
          (ans[q[id]] = vl);
        }
      }
    } else {
      int mid = jshr((vl + vr), 1);
      int lsiz = 0;
      int rsiz = 0;
      for (int i = el; (i <= er); (i++)) {
        int id = eid[i];
        if ((op[id] == 1)) {
          if ((y[id] <= mid)) {
            Code02_DynamicRankings1::add(x[id], v[id]);
            (lset[(++lsiz)] = id);
          } else {
            (rset[(++rsiz)] = id);
          }
        } else {
          int satisfy = Code02_DynamicRankings1::query(x[id], y[id]);
          if ((v[id] <= satisfy)) {
            (lset[(++lsiz)] = id);
          } else {
            (v[id] -= satisfy);
            (rset[(++rsiz)] = id);
          }
        }
      }
      for (int i = 1; (i <= lsiz); (i++)) {
        (eid[((el + i) - 1)] = lset[i]);
      }
      for (int i = 1; (i <= rsiz); (i++)) {
        (eid[(((el + lsiz) + i) - 1)] = rset[i]);
      }
      for (int i = 1; (i <= lsiz); (i++)) {
        int id = lset[i];
        if (((op[id] == 1) && (y[id] <= mid))) {
          Code02_DynamicRankings1::add(x[id], (-v[id]));
        }
      }
      Code02_DynamicRankings1::compute(el, ((el + lsiz) - 1), vl, mid);
      Code02_DynamicRankings1::compute((el + lsiz), er, (mid + 1), vr);
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO();
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (m = in.nextInt());
    for (int i = 1; (i <= n); (i++)) {
      (arr[i] = in.nextInt());
      (op[(++cnte)] = 1);
      (x[cnte] = i);
      (y[cnte] = arr[i]);
      (v[cnte] = 1);
    }
    jchar type = {};
    for (int i = 1; (i <= m); (i++)) {
      (type = in.nextChar());
      if ((type == u'C')) {
        int a = in.nextInt();
        int b = in.nextInt();
        (op[(++cnte)] = 1);
        (x[cnte] = a);
        (y[cnte] = arr[a]);
        (v[cnte] = (-1));
        (op[(++cnte)] = 1);
        (x[cnte] = a);
        (y[cnte] = b);
        (v[cnte] = 1);
        (arr[a] = b);
      } else {
        (op[(++cnte)] = 2);
        (x[cnte] = in.nextInt());
        (y[cnte] = in.nextInt());
        (v[cnte] = in.nextInt());
        (q[cnte] = (++cntq));
      }
    }
    for (int i = 1; (i <= cnte); (i++)) {
      (eid[i] = i);
    }
    Code02_DynamicRankings1::compute(1, cnte, 0, INF);
    for (int i = 1; (i <= cntq); (i++)) {
      out.println(ans[i]);
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code02_DynamicRankings1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 带修改的区间第k小，java版
// 给定一个长度为n的数组arr，接下来是m条操作，每种操作是如下两种类型的一种
// 操作 C x y   : 把x位置的值修改成y
// 操作 Q x y v : 查询arr[x..y]范围上第v小的值
// 1 <= n、m <= 10^5
// 1 <= 数组中的值 <= 10^9
// 测试链接 : https://www.luogu.com.cn/problem/P2617
// 本题是讲解160，树套树模版题，现在作为带修改的整体二分模版题
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 事件编号组成的数组
        // op == 1，代表修改事件，x处，值y，效果v
        // op == 2，代表查询事件，[x..y]范围上查询第v小，q表示问题的编号
        // 树状数组
        // 整体二分
        // 查询的答案
        // 读写工具类
*/

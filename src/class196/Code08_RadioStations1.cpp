// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/CF1215F
// https://codeforces.com/problemset/problem/1215/F

// Source: src/class196/Code08_RadioStations1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code08_RadioStations1 {
  inline static int MAXN = 400001;
  inline static int MAXT = 2000001;
  inline static int MAXM = 4000001;
  inline static int n = {};
  inline static int p = {};
  inline static int f = {};
  inline static int m = {};
  inline static int cntt = {};
  inline static Array<int> l = make_array<int>(MAXN);
  inline static Array<int> r = make_array<int>(MAXN);
  inline static Array<int> head = make_array<int>(MAXT);
  inline static Array<int> nxt = make_array<int>(MAXM);
  inline static Array<int> to = make_array<int>(MAXM);
  inline static int cntg = {};
  inline static Array<int> dfn = make_array<int>(MAXT);
  inline static Array<int> low = make_array<int>(MAXT);
  inline static int cntd = {};
  inline static Array<int> sta = make_array<int>(MAXT);
  inline static int top = {};
  inline static Array<int> belong = make_array<int>(MAXT);
  inline static int sccCnt = {};
  inline static Array<int> pre = make_array<int>(MAXN);
  inline static Array<int> suf = make_array<int>(MAXN);
  inline static int ansx = {};
  inline static Array<int> pick = make_array<int>(MAXN);
  inline static int siz = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code08_RadioStations1() {}
  static void addEdge(int u, int v) {
    (nxt[(++cntg)] = head[u]);
    (to[cntg] = v);
    (head[u] = cntg);
  }
  static void link() {
    (pre[1] = (++cntt));
    for (int i = 2; (i <= f); (i++)) {
      (pre[i] = (++cntt));
      Code08_RadioStations1::addEdge(pre[(i - 1)], pre[i]);
    }
    (suf[f] = (++cntt));
    for (int i = (f - 1); (i >= 1); (i--)) {
      (suf[i] = (++cntt));
      Code08_RadioStations1::addEdge(suf[(i + 1)], suf[i]);
    }
    for (int i = 1; (i <= p); (i++)) {
      Code08_RadioStations1::addEdge(i, pre[r[i]]);
      Code08_RadioStations1::addEdge(i, suf[l[i]]);
      if (((l[i] - 1) >= 1)) {
        Code08_RadioStations1::addEdge(pre[(l[i] - 1)], (i + p));
      }
      if (((r[i] + 1) <= f)) {
        Code08_RadioStations1::addEdge(suf[(r[i] + 1)], (i + p));
      }
    }
  }
  static void tarjan(int u) {
    (dfn[u] = (low[u] = (++cntd)));
    (sta[(++top)] = u);
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      int v = to[e];
      if ((dfn[v] == 0)) {
        Code08_RadioStations1::tarjan(v);
        (low[u] = jmin(low[u], low[v]));
      } else {
        if ((belong[v] == 0)) {
          (low[u] = jmin(low[u], dfn[v]));
        }
      }
    }
    if ((dfn[u] == low[u])) {
      (sccCnt++);
      int pop = {};
      do {
        (pop = sta[(top--)]);
        (belong[pop] = sccCnt);
      } while ((pop != u));
    }
  }
  static bool compute() {
    bool check = true;
    for (int i = 1; (i <= p); (i++)) {
      if ((belong[i] == belong[(i + p)])) {
        (check = false);
        break;
      } else if ((belong[i] < belong[(i + p)])) {
        (ansx = jmax(ansx, l[i]));
        (pick[(++siz)] = i);
      }
    }
    return check;
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (p = in.nextInt());
    (f = in.nextInt());
    (m = in.nextInt());
    (cntt = jshl(p, 1));
    {
      int i = 1;
      int u = {};
      int v = {};
      for (; (i <= n); (i++)) {
        (u = in.nextInt());
        (v = in.nextInt());
        Code08_RadioStations1::addEdge((u + p), v);
        Code08_RadioStations1::addEdge((v + p), u);
      }
    }
    for (int i = 1; (i <= p); (i++)) {
      (l[i] = in.nextInt());
      (r[i] = in.nextInt());
    }
    Code08_RadioStations1::link();
    {
      int i = 1;
      int u = {};
      int v = {};
      for (; (i <= m); (i++)) {
        (u = in.nextInt());
        (v = in.nextInt());
        Code08_RadioStations1::addEdge(u, (v + p));
        Code08_RadioStations1::addEdge(v, (u + p));
      }
    }
    for (int i = 1; (i <= cntt); (i++)) {
      if ((dfn[i] == 0)) {
        Code08_RadioStations1::tarjan(i);
      }
    }
    bool check = Code08_RadioStations1::compute();
    if (check) {
      out.println(((siz + String(u" ")) + ansx));
      for (int i = 1; (i <= siz); (i++)) {
        out.print((pick[i] + String(u" ")));
      }
    } else {
      out.println((-1));
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code08_RadioStations1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 电台，java版
// 给定数值f，范围[1, f]上，你要选一个数字ansx作为固定频率
// 一共p个电台，每个电台给定频率范围[l, r]，频率范围包含ansx的电台才能签约
// 签约电台还要满足n个要求和m个限制，具体格式如下
// 要求 u v : 必须签下电台u或者电台v
// 限制 u v : 电台u和电台v不能同时签下
//
如果存在签约方案，找到任何一种即可，依次打印，签约电台的数量、ansx、所有签约电台的编号
// 如果不存在签约方案，打印-1
// 2 <= n、p、f、m <= 4 * 10^5
// 测试链接 : https://www.luogu.com.cn/problem/CF1215F
// 测试链接 : https://codeforces.com/problemset/problem/1215/F
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 读写工具类
*/

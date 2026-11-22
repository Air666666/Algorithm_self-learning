// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/CF587D
// https://codeforces.com/problemset/problem/587/D

// Source: src/class197/Code01_Mafia1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_Mafia1 {
  inline static int MAXM = 50001;
  inline static int MAXT = 500001;
  inline static int MAXE = 1000001;
  inline static int n = {};
  inline static int m = {};
  inline static int k = {};
  inline static int maxt = {};
  inline static int cntt = {};
  inline static Array<Array<int>> arr = make_array<int>(jshl(MAXM, 1), 3);
  inline static Array<int> destroyTime = make_array<int>(MAXM);
  inline static Array<int> head = make_array<int>(MAXT);
  inline static Array<int> nxt = make_array<int>(MAXE);
  inline static Array<int> to = make_array<int>(MAXE);
  inline static int cntg = {};
  inline static Array<int> group = make_array<int>(MAXM);
  inline static int gsiz = {};
  inline static Array<int> dfn = make_array<int>(MAXT);
  inline static Array<int> low = make_array<int>(MAXT);
  inline static int cntd = {};
  inline static Array<int> sta = make_array<int>(MAXT);
  inline static int top = {};
  inline static Array<int> belong = make_array<int>(MAXT);
  inline static int sccCnt = {};
  inline static int ansTime = {};
  inline static int ansSize = {};
  inline static Array<int> ansArr = make_array<int>(MAXM);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_Mafia1() {}
  static void addEdge(int u, int v) {
    (nxt[(++cntg)] = head[u]);
    (to[cntg] = v);
    (head[u] = cntg);
  }
  static void tarjan(int u) {
    (dfn[u] = (low[u] = (++cntd)));
    (sta[(++top)] = u);
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      int v = to[e];
      if ((dfn[v] == 0)) {
        Code01_Mafia1::tarjan(v);
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
  static int other(int i) { return ((i <= m) ? (i + m) : (i - m)); }
  static void groupLink() {
    if ((gsiz > 1)) {
      (cntt++);
      Code01_Mafia1::addEdge(cntt, Code01_Mafia1::other(group[1]));
      for (int i = 2; (i <= gsiz); (i++)) {
        (cntt++);
        Code01_Mafia1::addEdge(cntt, Code01_Mafia1::other(group[i]));
        Code01_Mafia1::addEdge(group[i], (cntt - 1));
        Code01_Mafia1::addEdge(cntt, (cntt - 1));
      }
      (cntt++);
      Code01_Mafia1::addEdge(cntt, Code01_Mafia1::other(group[gsiz]));
      for (int i = (gsiz - 1); (i >= 1); (i--)) {
        (cntt++);
        Code01_Mafia1::addEdge(cntt, Code01_Mafia1::other(group[i]));
        Code01_Mafia1::addEdge(group[i], (cntt - 1));
        Code01_Mafia1::addEdge(cntt, (cntt - 1));
      }
    }
  }
  static void buildGraph(int limit) {
    (cntt = jshl(m, 1));
    for (int i = 1; (i <= m); (i++)) {
      if ((destroyTime[i] > limit)) {
        Code01_Mafia1::addEdge(i, (i + m));
      }
    }
    {
      int l = 1;
      int r = 1;
      for (; (l <= k); (l = (++r))) {
        int curx = arr[l][1];
        while ((((r + 1) <= k) && (curx == arr[(r + 1)][1]))) {
          (r++);
        }
        (gsiz = 0);
        for (int i = l; (i <= r); (i++)) {
          (group[(++gsiz)] = arr[i][0]);
        }
        Code01_Mafia1::groupLink();
      }
    }
    {
      int l = 1;
      int r = 1;
      for (; (l <= k); (l = (++r))) {
        int curx = arr[l][1];
        int curc = arr[l][2];
        while (((((r + 1) <= k) && (curx == arr[(r + 1)][1])) &&
                (curc == arr[(r + 1)][2]))) {
          (r++);
        }
        (gsiz = 0);
        for (int i = l; (i <= r); (i++)) {
          (group[(++gsiz)] = Code01_Mafia1::other(arr[i][0]));
        }
        Code01_Mafia1::groupLink();
      }
    }
  }
  static void clear() {
    for (int i = 1; (i <= cntt); (i++)) {
      (head[i] = (dfn[i] = (belong[i] = 0)));
    }
    (cntt = (cntg = (cntd = (top = (sccCnt = 0)))));
  }
  static bool getAns(int limit) {
    Code01_Mafia1::buildGraph(limit);
    for (int i = 1; (i <= jshl(m, 1)); (i++)) {
      if ((dfn[i] == 0)) {
        Code01_Mafia1::tarjan(i);
      }
    }
    bool check = true;
    for (int i = 1; (i <= m); (i++)) {
      if ((belong[i] == belong[(i + m)])) {
        (check = false);
        break;
      }
    }
    if (check) {
      (ansTime = (ansSize = 0));
      for (int i = 1; (i <= m); (i++)) {
        if ((belong[i] < belong[(i + m)])) {
          (ansTime = jmax(ansTime, destroyTime[i]));
          (ansArr[(++ansSize)] = i);
        }
      }
    }
    Code01_Mafia1::clear();
    return check;
  }
  static bool compute() {
    j::sort(arr, 1, (k + 1), [=](Array<int> a, Array<int> b) {
      return ((a[1] != b[1]) ? (a[1] - b[1]) : (a[2] - b[2]));
    });
    int l = 1;
    int r = maxt;
    int mid = {};
    bool hasAns = false;
    while ((l <= r)) {
      (mid = jshr((l + r), 1));
      if (Code01_Mafia1::getAns(mid)) {
        (hasAns = true);
        (r = (mid - 1));
      } else {
        (l = (mid + 1));
      }
    }
    return hasAns;
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (m = in.nextInt());
    (maxt = 0);
    {
      int i = 1;
      int x = {};
      int y = {};
      int c = {};
      int t = {};
      for (; (i <= m); (i++)) {
        (x = in.nextInt());
        (y = in.nextInt());
        (c = in.nextInt());
        (t = in.nextInt());
        (arr[(++k)][0] = i);
        (arr[k][1] = x);
        (arr[k][2] = c);
        (arr[(++k)][0] = i);
        (arr[k][1] = y);
        (arr[k][2] = c);
        (destroyTime[i] = t);
        (maxt = jmax(maxt, t));
      }
    }
    bool check = Code01_Mafia1::compute();
    if (check) {
      out.println(String(u"Yes"));
      out.println(((ansTime + String(u" ")) + ansSize));
      for (int i = 1; (i <= ansSize); (i++)) {
        out.print((ansArr[i] + String(u" ")));
      }
    } else {
      out.println(String(u"No"));
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code01_Mafia1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 黑手党，java版
// 一共n个点，m条无向边，每条边给定端点x、端点y、颜色c、破坏时间t
// 图中保证没有自环，你可以选择一些边作为摧毁边，剩下的边作为幸存边
// 摧毁的方式是并行的，所以摧毁耗时 = max(所有摧毁边的破坏时间)
// 要求任意两条摧毁边不能在图中相邻，任意两条同色的幸存边也不能相邻
// 满足要求的前提下，摧毁耗时想尽可能的小，请找到可行的摧毁边集
// 不存在方案打印"No"，存在方案打印"Yes"，然后依次打印如下内容
// 摧毁耗时、摧毁边集的大小、摧毁边集每条边的序号，任何一个方案皆可
// 1 <= n、m <= 5 * 10^4    1 <= c、t <= 10^9
// 测试链接 : https://www.luogu.com.cn/problem/CF587D
// 测试链接 : https://codeforces.com/problemset/problem/587/D
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 边的序号、所属节点、边的颜色
        // 边的破坏时间
        // 前后缀优化建图
        // 读写工具类
*/

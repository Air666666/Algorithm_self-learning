// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/AT_abc210_f
// https://atcoder.jp/contests/abc210/tasks/abc210_f

// Source: src/class196/Code07_Coprime1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code07_Coprime1 {
  inline static int MAXN = 1000001;
  inline static int MAXV = 2000001;
  inline static int MAXM = 3000001;
  inline static int n = {};
  inline static int cntt = {};
  inline static int maxv = {};
  inline static Array<int> ab = make_array<int>(MAXN);
  inline static Array<bool> vis = make_array<bool>(MAXV);
  inline static Array<int> prime = make_array<int>(MAXV);
  inline static Array<int> minp = make_array<int>(MAXV);
  inline static int cntp = {};
  inline static Array<Array<int>> arr = make_array<int>(MAXN, 2);
  inline static int cnta = {};
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> nxt = make_array<int>(MAXM);
  inline static Array<int> to = make_array<int>(MAXM);
  inline static int cntg = {};
  inline static Array<int> dfn = make_array<int>(MAXN);
  inline static Array<int> low = make_array<int>(MAXN);
  inline static int cntd = {};
  inline static Array<int> sta = make_array<int>(MAXN);
  inline static int top = {};
  inline static Array<int> belong = make_array<int>(MAXN);
  inline static int sccCnt = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code07_Coprime1() {}
  static void addEdge(int u, int v) {
    (nxt[(++cntg)] = head[u]);
    (to[cntg] = v);
    (head[u] = cntg);
  }
  static int other(int x) { return ((x <= n) ? (x + n) : (x - n)); }
  static void euler() {
    for (int i = 2; (i <= maxv); (i++)) {
      if ((!vis[i])) {
        (prime[(++cntp)] = i);
        (minp[i] = i);
      }
      {
        int j = 1;
        int p = {};
        int v = {};
        for (; (j <= cntp); (j++)) {
          (p = prime[j]);
          (v = (i * p));
          if ((v > maxv)) {
            break;
          }
          (vis[v] = true);
          (minp[v] = p);
          if ((jrem(i, p) == 0)) {
            break;
          }
        }
      }
    }
  }
  static void decompose() {
    for (int i = 1; (i <= jshl(n, 1)); (i++)) {
      {
        int v = ab[i];
        int p = minp[v];
        for (; (v > 1); (p = minp[v])) {
          (arr[(++cnta)][0] = p);
          (arr[cnta][1] = i);
          while ((jrem(v, p) == 0)) {
            (v /= p);
          }
        }
      }
    }
  }
  static void link() {
    j::sort(arr, 1, (cnta + 1), [=](Array<int> a, Array<int> b) {
      return ((a[0] != b[0]) ? (a[0] - b[0]) : (a[1] - b[1]));
    });
    {
      int l = 1;
      int r = 1;
      for (; (l <= cnta); (l = (++r))) {
        while ((((r + 1) <= cnta) && (arr[l][0] == arr[(r + 1)][0]))) {
          (r++);
        }
        (cntt++);
        Code07_Coprime1::addEdge(cntt, Code07_Coprime1::other(arr[l][1]));
        for (int i = (l + 1); (i <= r); (i++)) {
          (cntt++);
          Code07_Coprime1::addEdge(cntt, Code07_Coprime1::other(arr[i][1]));
          Code07_Coprime1::addEdge(arr[i][1], (cntt - 1));
          Code07_Coprime1::addEdge(cntt, (cntt - 1));
        }
        (cntt++);
        Code07_Coprime1::addEdge(cntt, Code07_Coprime1::other(arr[r][1]));
        for (int i = (r - 1); (i >= l); (i--)) {
          (cntt++);
          Code07_Coprime1::addEdge(cntt, Code07_Coprime1::other(arr[i][1]));
          Code07_Coprime1::addEdge(arr[i][1], (cntt - 1));
          Code07_Coprime1::addEdge(cntt, (cntt - 1));
        }
      }
    }
  }
  static void tarjan(int u) {
    (dfn[u] = (low[u] = (++cntd)));
    (sta[(++top)] = u);
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      int v = to[e];
      if ((dfn[v] == 0)) {
        Code07_Coprime1::tarjan(v);
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
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (cntt = jshl(n, 1));
    {
      int i = 1;
      int a = {};
      int b = {};
      for (; (i <= n); (i++)) {
        (a = in.nextInt());
        (b = in.nextInt());
        (ab[i] = a);
        (ab[(i + n)] = b);
        (maxv = jmax(maxv, jmax(a, b)));
      }
    }
    Code07_Coprime1::euler();
    Code07_Coprime1::decompose();
    Code07_Coprime1::link();
    for (int i = 1; (i <= cntt); (i++)) {
      if ((dfn[i] == 0)) {
        Code07_Coprime1::tarjan(i);
      }
    }
    bool check = true;
    for (int i = 1; (i <= n); (i++)) {
      if ((belong[i] == belong[(i + n)])) {
        (check = false);
        break;
      }
    }
    out.println((check ? String(u"Yes") : String(u"No")));
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code07_Coprime1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 互质，java版
// 一共n张卡片，每张卡片给定两个待选数字，选择其中一个数字作为卡片的值
// 确定每张卡片的值之后，如果任意两张卡片的值都是互质的，那么算作成功
// 存在成功的选值方案打印"Yes"，不存在打印"No"
// 1 <= n <= 3 * 10^4
// 1 <= 待选数字 <= 2 * 10^6
// 测试链接 : https://www.luogu.com.cn/problem/AT_abc210_f
// 测试链接 : https://atcoder.jp/contests/abc210/tasks/abc210_f
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 利用欧拉筛生成最小质因子表
        // 质因子、拥有这个质因子的数字编号
        // 排序后得到每个质因子的数字编号列表
        // 欧拉筛，讲解097
        // 利用欧拉筛的过程，生成最小质因子表
        // 质因子分解
        // 前后缀优化建图
        // 读写工具类
*/

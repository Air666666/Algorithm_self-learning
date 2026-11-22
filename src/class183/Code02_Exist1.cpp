// Source: src/class183/Code02_Exist1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_Exist1 {
  inline static int MAXN = 10001;
  inline static int MAXM = 101;
  inline static int MAXV = 10000001;
  inline static int n = {};
  inline static int m = {};
  inline static Array<int> query = make_array<int>(MAXM);
  inline static int maxk = {};
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> nxt = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> to = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> weight = make_array<int>(jshl(MAXN, 1));
  inline static int cntg = {};
  inline static Array<bool> vis = make_array<bool>(MAXN);
  inline static Array<int> siz = make_array<int>(MAXN);
  inline static Array<int> cur = make_array<int>(MAXN);
  inline static int cntc = {};
  inline static Array<int> all = make_array<int>(MAXN);
  inline static int cnta = {};
  inline static Array<bool> exist = make_array<bool>(MAXV);
  inline static Array<bool> ans = make_array<bool>(MAXM);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_Exist1() {}
  static void addEdge(int u, int v, int w) {
    (nxt[(++cntg)] = head[u]);
    (to[cntg] = v);
    (weight[cntg] = w);
    (head[u] = cntg);
  }
  static void getSize(int u, int fa) {
    (siz[u] = 1);
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      int v = to[e];
      if (((v != fa) && (!vis[v]))) {
        Code02_Exist1::getSize(v, u);
        (siz[u] += siz[v]);
      }
    }
  }
  static int getCentroid(int u, int fa) {
    Code02_Exist1::getSize(u, fa);
    int half = jshr(siz[u], 1);
    bool find = false;
    while ((!find)) {
      (find = true);
      for (int e = head[u]; (e > 0); (e = nxt[e])) {
        int v = to[e];
        if ((((v != fa) && (!vis[v])) && (siz[v] > half))) {
          (fa = u);
          (u = v);
          (find = false);
          break;
        }
      }
    }
    return u;
  }
  static void dfs(int u, int fa, int dis) {
    if ((dis > maxk)) {
      return;
    }
    (cur[(++cntc)] = dis);
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      int v = to[e];
      if (((v != fa) && (!vis[v]))) {
        Code02_Exist1::dfs(v, u, (dis + weight[e]));
      }
    }
  }
  static void calc(int u) {
    (cnta = 0);
    (exist[0] = true);
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      int v = to[e];
      if ((!vis[v])) {
        (cntc = 0);
        Code02_Exist1::dfs(v, u, weight[e]);
        for (int i = 1; (i <= m); (i++)) {
          for (int j = 1; ((!ans[i]) && (j <= cntc)); (j++)) {
            if (((query[i] - cur[j]) >= 0)) {
              (ans[i] = (ans[i] | exist[(query[i] - cur[j])]));
            }
          }
        }
        for (int i = 1; (i <= cntc); (i++)) {
          (all[(++cnta)] = cur[i]);
          (exist[cur[i]] = true);
        }
      }
    }
    for (int i = 1; (i <= cnta); (i++)) {
      (exist[all[i]] = false);
    }
  }
  static void solve(int u) {
    (vis[u] = true);
    Code02_Exist1::calc(u);
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      int v = to[e];
      if ((!vis[v])) {
        Code02_Exist1::solve(Code02_Exist1::getCentroid(v, u));
      }
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (m = in.nextInt());
    {
      int i = 1;
      int u = {};
      int v = {};
      int w = {};
      for (; (i < n); (i++)) {
        (u = in.nextInt());
        (v = in.nextInt());
        (w = in.nextInt());
        Code02_Exist1::addEdge(u, v, w);
        Code02_Exist1::addEdge(v, u, w);
      }
    }
    for (int i = 1; (i <= m); (i++)) {
      (query[i] = in.nextInt());
      (maxk = jmax(maxk, query[i]));
    }
    Code02_Exist1::solve(Code02_Exist1::getCentroid(1, 0));
    for (int i = 1; (i <= m); (i++)) {
      if (ans[i]) {
        out.println(String(u"AYE"));
      } else {
        out.println(String(u"NAY"));
      }
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code02_Exist1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 距离为k的点对是否存在，java版
// 一共有n个节点，给定n-1条边，每条边有边权，所有节点组成一棵树
// 一共有m条查询，每条查询给定数字k，打印树上距离为k的点对是否存在
// 1 <= n <= 10^4    1 <= 边权 <= 10^4
// 1 <= m <= 100     1 <= k <= 10^7
// 测试链接 : https://www.luogu.com.cn/problem/P3806
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 从u出发，到当前子树的每个节点，收集路径权值和
        // 从u出发，到之前所有子树的每个节点，收集路径权值和
        // 使用数组替代哈希表，因为哈希表常数时间大，会超时
        // 读写工具类
*/

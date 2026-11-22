// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P4075

// Source: src/class184/Code07_ModeString1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code07_ModeString1 {
  inline static int MAXN = 100001;
  inline static int BASE = 499;
  inline static int t = {};
  inline static int n = {};
  inline static int m = {};
  inline static Array<jchar> val = make_array<jchar>(MAXN);
  inline static Array<jchar> str = make_array<jchar>(MAXN);
  inline static Array<int> a = make_array<int>(MAXN);
  inline static Array<int> b = make_array<int>(MAXN);
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> nxt = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> to = make_array<int>(jshl(MAXN, 1));
  inline static int cntg = {};
  inline static Array<i64> pre = make_array<i64>(MAXN);
  inline static Array<i64> suf = make_array<i64>(MAXN);
  inline static Array<bool> vis = make_array<bool>(MAXN);
  inline static Array<int> siz = make_array<int>(MAXN);
  inline static Array<int> deep = make_array<int>(MAXN);
  inline static Array<i64> curp = make_array<i64>(MAXN);
  inline static Array<i64> curs = make_array<i64>(MAXN);
  inline static Array<i64> allp = make_array<i64>(MAXN);
  inline static Array<i64> alls = make_array<i64>(MAXN);
  inline static i64 ans = {};
  inline static Array<Array<int>> stack = make_array<int>(MAXN, 4);
  inline static Array<i64> hashst = make_array<i64>(MAXN);
  inline static int u = {};
  inline static int f = {};
  inline static int dep = {};
  inline static int e = {};
  inline static i64 hash = {};
  inline static int stacksize = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code07_ModeString1() {}
  static void push(int u, int f, int dep, i64 hash, int e) {
    (stack[stacksize][0] = u);
    (stack[stacksize][1] = f);
    (stack[stacksize][2] = dep);
    (stack[stacksize][3] = e);
    (hashst[stacksize] = hash);
    (stacksize++);
  }
  static void pop() {
    (--stacksize);
    (u = stack[stacksize][0]);
    (f = stack[stacksize][1]);
    (dep = stack[stacksize][2]);
    (e = stack[stacksize][3]);
    (hash = hashst[stacksize]);
  }
  static void addEdge(int u, int v) {
    (nxt[(++cntg)] = head[u]);
    (to[cntg] = v);
    (head[u] = cntg);
  }
  static void getSize1(int u, int fa) {
    (siz[u] = 1);
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      int v = to[e];
      if (((v != fa) && (!vis[v]))) {
        Code07_ModeString1::getSize1(v, u);
        (siz[u] += siz[v]);
      }
    }
  }
  static void getSize2(int cur, int fa) {
    (stacksize = 0);
    Code07_ModeString1::push(cur, fa, 0, 0, (-1));
    while ((stacksize > 0)) {
      Code07_ModeString1::pop();
      if ((e == (-1))) {
        (siz[u] = 1);
        (e = head[u]);
      } else {
        (e = nxt[e]);
      }
      if ((e != 0)) {
        Code07_ModeString1::push(u, f, 0, 0, e);
        int v = to[e];
        if (((v != f) && (!vis[v]))) {
          Code07_ModeString1::push(v, u, 0, 0, (-1));
        }
      } else {
        for (int ei = head[u]; (ei > 0); (ei = nxt[ei])) {
          int v = to[ei];
          if (((v != f) && (!vis[v]))) {
            (siz[u] += siz[v]);
          }
        }
      }
    }
  }
  static int getCentroid(int u, int fa) {
    Code07_ModeString1::getSize2(u, fa);
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
  static void dfs1(int u, int fa, int dep, i64 hash) {
    (deep[u] = dep);
    (hash = ((((hash * BASE) + val[u]) - u'A') + 1));
    if ((hash == pre[dep])) {
      (curp[(jrem((dep - 1), m) + 1)]++);
      (ans += alls[(m - jrem((dep - 1), m))]);
    }
    if ((hash == suf[dep])) {
      (curs[(jrem((dep - 1), m) + 1)]++);
      (ans += allp[(m - jrem((dep - 1), m))]);
    }
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      int v = to[e];
      if (((v != fa) && (!vis[v]))) {
        Code07_ModeString1::dfs1(v, u, (dep + 1), hash);
        (deep[u] = jmax(deep[u], deep[v]));
      }
    }
  }
  static void dfs2(int cur, int fa, int pdep, i64 phash) {
    (stacksize = 0);
    Code07_ModeString1::push(cur, fa, pdep, phash, (-1));
    while ((stacksize > 0)) {
      Code07_ModeString1::pop();
      if ((e == (-1))) {
        (deep[u] = dep);
        (hash = ((((hash * BASE) + val[u]) - u'A') + 1));
        if ((hash == pre[dep])) {
          (curp[(jrem((dep - 1), m) + 1)]++);
          (ans += alls[(m - jrem((dep - 1), m))]);
        }
        if ((hash == suf[dep])) {
          (curs[(jrem((dep - 1), m) + 1)]++);
          (ans += allp[(m - jrem((dep - 1), m))]);
        }
        (e = head[u]);
      } else {
        (e = nxt[e]);
      }
      if ((e != 0)) {
        Code07_ModeString1::push(u, f, dep, hash, e);
        int v = to[e];
        if (((v != f) && (!vis[v]))) {
          Code07_ModeString1::push(v, u, (dep + 1), hash, (-1));
        }
      } else {
        for (int ei = head[u]; (ei > 0); (ei = nxt[ei])) {
          int v = to[ei];
          if (((v != f) && (!vis[v]))) {
            (deep[u] = jmax(deep[u], deep[v]));
          }
        }
      }
    }
  }
  static void calc(int u) {
    int maxDep = 0;
    (allp[1] = (alls[1] = 1));
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      int v = to[e];
      if ((!vis[v])) {
        Code07_ModeString1::dfs2(v, u, 2, ((val[u] - u'A') + 1));
        int curDep = jmin(deep[v], m);
        for (int i = 1; (i <= curDep); (i++)) {
          (allp[i] += curp[i]);
          (alls[i] += curs[i]);
          (curp[i] = (curs[i] = 0));
        }
        (maxDep = jmax(maxDep, curDep));
      }
    }
    for (int i = 1; (i <= maxDep); (i++)) {
      (allp[i] = (alls[i] = 0));
    }
  }
  static void solve(int u) {
    (vis[u] = true);
    Code07_ModeString1::calc(u);
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      int v = to[e];
      if ((!vis[v])) {
        Code07_ModeString1::solve(Code07_ModeString1::getCentroid(v, u));
      }
    }
  }
  static void prepare() {
    (cntg = 0);
    (ans = 0);
    for (int i = 1; (i <= n); (i++)) {
      (head[i] = 0);
      (vis[i] = false);
    }
    for (int i = 1; (i < n); (i++)) {
      Code07_ModeString1::addEdge(a[i], b[i]);
      Code07_ModeString1::addEdge(b[i], a[i]);
    }
    i64 tmp = 1;
    for (int i = 1; (i <= n); (i++)) {
      (pre[i] =
           (pre[(i - 1)] + (tmp * ((str[(jrem((i - 1), m) + 1)] - u'A') + 1))));
      (suf[i] =
           (suf[(i - 1)] + (tmp * ((str[(m - jrem((i - 1), m))] - u'A') + 1))));
      (tmp = (tmp * BASE));
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (t = in.nextInt());
    for (int k = 1; (k <= t); (k++)) {
      (n = in.nextInt());
      (m = in.nextInt());
      for (int i = 1; (i <= n); (i++)) {
        (val[i] = in.nextUpperCase());
      }
      for (int i = 1; (i < n); (i++)) {
        (a[i] = in.nextInt());
        (b[i] = in.nextInt());
      }
      for (int i = 1; (i <= m); (i++)) {
        (str[i] = in.nextUpperCase());
      }
      Code07_ModeString1::prepare();
      Code07_ModeString1::solve(Code07_ModeString1::getCentroid(1, 0));
      out.println(ans);
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code07_ModeString1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 模式字符串，java版
// 一共有n个点，给定n-1条边，所有节点组成一棵树
// 每个点有点权，是一个大写字母，只考虑大写字母A到Z
// 给定一个长度为m的字符串s，也只由大写字母A到Z组成
// 考虑点对(u, v)的简单路径，把沿途节点的字母拼接起来
// 如果拼接字符串恰好是s重复正数次，那么该点对合法
// 打印合法点对的数量，注意(u, v)和(v, u)是不同的点对
// 1 <= m <= n <= 10^5
// 测试链接 : https://www.luogu.com.cn/problem/P4075
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 讲解118，递归函数改成迭代所需要的栈
        // 得到子树大小递归版，java会爆栈，C++可以通过
        // 得到子树大小迭代版
                // getSize1(u, fa);
        // 收集信息 + 结算答案递归版，java会爆栈，C++可以通过
        // 收集信息 + 结算答案迭代版
                                // dfs1(v, u, 2, arr[u] - 'A' + 1);
        // 读写工具类
*/

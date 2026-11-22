// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/CF833D
// https://codeforces.com/problemset/problem/833/D

// Source: src/class187/Code02_Cobweb1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_Cobweb1 {
  inline static int MAXN = 200001;
  inline static int MOD = 1000000007;
  inline static int n = {};
  inline static int cntn = {};
  inline static Array<int> head1 = make_array<int>(MAXN);
  inline static Array<int> next1 = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> to1 = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> weight1 = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> color1 = make_array<int>(jshl(MAXN, 1));
  inline static int cnt1 = {};
  inline static Array<int> head2 = make_array<int>(MAXN);
  inline static Array<int> next2 = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> to2 = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> weight2 = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> color2 = make_array<int>(jshl(MAXN, 1));
  inline static int cnt2 = {};
  inline static Array<bool> vis = make_array<bool>(MAXN);
  inline static Array<int> siz = make_array<int>(MAXN);
  inline static Array<int> redKey = make_array<int>(MAXN);
  inline static Array<i64> redPath = make_array<i64>(MAXN);
  inline static Array<int> blackKey = make_array<int>(MAXN);
  inline static Array<i64> blackPath = make_array<i64>(MAXN);
  inline static int cnta = {};
  inline static i64 ans1 = {};
  inline static i64 ans2 = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_Cobweb1() {}
  static i64 power(i64 x, i64 p) {
    i64 ans = 1;
    while ((p != 0)) {
      if (((p & 1) != 0)) {
        (ans = jrem((ans * x), MOD));
      }
      (p = jshr(p, 1));
      (x = jrem((x * x), MOD));
    }
    return ans;
  }
  static void addEdge1(int u, int v, int w, int c) {
    (next1[(++cnt1)] = head1[u]);
    (to1[cnt1] = v);
    (weight1[cnt1] = w);
    (color1[cnt1] = c);
    (head1[u] = cnt1);
  }
  static void addEdge2(int u, int v, int w, int c) {
    (next2[(++cnt2)] = head2[u]);
    (to2[cnt2] = v);
    (weight2[cnt2] = w);
    (color2[cnt2] = c);
    (head2[u] = cnt2);
  }
  static void rebuild(int u, int fa) {
    int last = 0;
    for (int e = head1[u]; (e > 0); (e = next1[e])) {
      int v = to1[e];
      int w = weight1[e];
      int c = color1[e];
      if ((v != fa)) {
        if ((last == 0)) {
          (last = u);
          Code02_Cobweb1::addEdge2(u, v, w, c);
          Code02_Cobweb1::addEdge2(v, u, w, c);
        } else {
          int add = (++cntn);
          Code02_Cobweb1::addEdge2(last, add, 1, (-1));
          Code02_Cobweb1::addEdge2(add, last, 1, (-1));
          Code02_Cobweb1::addEdge2(add, v, w, c);
          Code02_Cobweb1::addEdge2(v, add, w, c);
          (last = add);
        }
        Code02_Cobweb1::rebuild(v, u);
      }
    }
  }
  static void getSize(int u, int fa) {
    (siz[u] = 1);
    for (int e = head2[u]; (e > 0); (e = next2[e])) {
      int v = to2[e];
      if (((v != fa) && (!vis[jshr(e, 1)]))) {
        Code02_Cobweb1::getSize(v, u);
        (siz[u] += siz[v]);
      }
    }
  }
  static int getCentroidEdge(int u, int fa) {
    Code02_Cobweb1::getSize(u, fa);
    int total = siz[u];
    int half = jshr(total, 1);
    bool find = false;
    while ((!find)) {
      (find = true);
      for (int e = head2[u]; (e > 0); (e = next2[e])) {
        int v = to2[e];
        if ((((v != fa) && (!vis[jshr(e, 1)])) && (siz[v] > half))) {
          (fa = u);
          (u = v);
          (find = false);
          break;
        }
      }
    }
    int best = 0;
    int edge = 0;
    for (int e = head2[u]; (e > 0); (e = next2[e])) {
      if ((!vis[jshr(e, 1)])) {
        int v = to2[e];
        int sub = ((v == fa) ? (total - siz[u]) : siz[v]);
        if ((sub > best)) {
          (best = sub);
          (edge = e);
        }
      }
    }
    return edge;
  }
  static void sort(Array<int> key, Array<i64> path, int l, int r) {
    if ((l >= r))
      return;
    int i = l;
    int j = r;
    int pivot = key[jshr((l + r), 1)];
    while ((i <= j)) {
      while ((key[i] < pivot))
        (i++);
      while ((key[j] > pivot))
        (j--);
      if ((i <= j)) {
        int tmp1 = key[i];
        (key[i] = key[j]);
        (key[j] = tmp1);
        i64 tmp2 = path[i];
        (path[i] = path[j]);
        (path[j] = tmp2);
        (i++);
        (j--);
      }
    }
    Code02_Cobweb1::sort(key, path, l, j);
    Code02_Cobweb1::sort(key, path, i, r);
  }
  static int lessThan(Array<int> arr, int len, int num) {
    int l = 1;
    int r = len;
    int mid = {};
    int ans = 0;
    while ((l <= r)) {
      (mid = jshr((l + r), 1));
      if ((arr[mid] < num)) {
        (ans = mid);
        (l = (mid + 1));
      } else {
        (r = (mid - 1));
      }
    }
    return ans;
  }
  static void dfsLeft(int u, int fa, int red, int black, i64 path) {
    if ((u <= n)) {
      (redKey[(++cnta)] = ((2 * red) - black));
      (redPath[cnta] = path);
      (blackKey[cnta] = ((2 * black) - red));
      (blackPath[cnta] = path);
    }
    for (int e = head2[u]; (e > 0); (e = next2[e])) {
      int v = to2[e];
      if (((v != fa) && (!vis[jshr(e, 1)]))) {
        int nextRed = (red + ((color2[e] == 0) ? 1 : 0));
        int nextBlack = (black + ((color2[e] == 1) ? 1 : 0));
        Code02_Cobweb1::dfsLeft(v, u, nextRed, nextBlack,
                                jrem((path * weight2[e]), MOD));
      }
    }
  }
  static void dfsRight(int u, int fa, int red, int black, i64 path) {
    if ((u <= n)) {
      int r = Code02_Cobweb1::lessThan(redKey, cnta, (black - (2 * red)));
      int b = Code02_Cobweb1::lessThan(blackKey, cnta, (red - (2 * black)));
      if ((r > 0)) {
        (ans2 = jrem(
             (jrem((ans2 * Code02_Cobweb1::power(path, r)), MOD) * redPath[r]),
             MOD));
      }
      if ((b > 0)) {
        (ans2 = jrem((jrem((ans2 * Code02_Cobweb1::power(path, b)), MOD) *
                      blackPath[b]),
                     MOD));
      }
    }
    for (int e = head2[u]; (e > 0); (e = next2[e])) {
      int v = to2[e];
      if (((v != fa) && (!vis[jshr(e, 1)]))) {
        int nextRed = (red + ((color2[e] == 0) ? 1 : 0));
        int nextBlack = (black + ((color2[e] == 1) ? 1 : 0));
        Code02_Cobweb1::dfsRight(v, u, nextRed, nextBlack,
                                 jrem((path * weight2[e]), MOD));
      }
    }
  }
  static void calc(int edge) {
    (cnta = 0);
    int v1 = to2[edge];
    Code02_Cobweb1::dfsLeft(v1, 0, 0, 0, 1);
    Code02_Cobweb1::sort(redKey, redPath, 1, cnta);
    Code02_Cobweb1::sort(blackKey, blackPath, 1, cnta);
    for (int i = 2; (i <= cnta); (i++)) {
      (redPath[i] = jrem((redPath[(i - 1)] * redPath[i]), MOD));
      (blackPath[i] = jrem((blackPath[(i - 1)] * blackPath[i]), MOD));
    }
    int v2 = to2[(edge ^ 1)];
    int red = ((color2[edge] == 0) ? 1 : 0);
    int black = ((color2[edge] == 1) ? 1 : 0);
    Code02_Cobweb1::dfsRight(v2, 0, red, black, jrem(weight2[edge], MOD));
  }
  static void getAns2(int u) {
    int edge = Code02_Cobweb1::getCentroidEdge(u, 0);
    if ((edge > 0)) {
      (vis[jshr(edge, 1)] = true);
      Code02_Cobweb1::calc(edge);
      Code02_Cobweb1::getAns2(to2[edge]);
      Code02_Cobweb1::getAns2(to2[(edge ^ 1)]);
    }
  }
  static void getAns1(int u, int fa) {
    (siz[u] = 1);
    for (int e = head1[u]; (e > 0); (e = next1[e])) {
      int v = to1[e];
      if ((v != fa)) {
        Code02_Cobweb1::getAns1(v, u);
        (siz[u] += siz[v]);
        (ans1 = jrem((ans1 * Code02_Cobweb1::power(
                                 weight1[e],
                                 (static_cast<i64>(siz[v]) * (n - siz[v])))),
                     MOD));
      }
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    {
      int i = 1;
      int u = {};
      int v = {};
      int w = {};
      int c = {};
      for (; (i < n); (i++)) {
        (u = in.nextInt());
        (v = in.nextInt());
        (w = in.nextInt());
        (c = in.nextInt());
        Code02_Cobweb1::addEdge1(u, v, w, c);
        Code02_Cobweb1::addEdge1(v, u, w, c);
      }
    }
    (cntn = n);
    (cnt2 = 1);
    (ans1 = (ans2 = 1));
    Code02_Cobweb1::getAns1(1, 0);
    Code02_Cobweb1::rebuild(1, 0);
    Code02_Cobweb1::getAns2(1);
    i64 ans = jrem((ans1 * Code02_Cobweb1::power(ans2, (MOD - 2))), MOD);
    out.println(ans);
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code02_Cobweb1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 红黑蛛网，java版
// 一共n个节点，给定n-1条边，所有节点组成一棵树
// 每条边有两种边权，w为重量，c为颜色，颜色只有红和黑
// 考虑点对(x, y)的简单路径，x和y必须不同，假设红边数量r、黑边数量b
// 如果 2 * min(r, b) >= max(r, b)，那么路径是合法的
// 合法路径的收益 = 路径所有边的重量乘积，(x, y)和(y, x)的路径只算一次收益
// 打印所有合法路径的收益总乘积，结果对 1000000007 取余，不存在任何合法路径打印1
// 2 <= n <= 10^5
// 1 <= w <= 10^9 + 6
// 测试链接 : https://www.luogu.com.cn/problem/CF833D
// 测试链接 : https://codeforces.com/problemset/problem/833/D
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 读写工具类
*/

// Source: src/class119/Code05_PathPalindrome.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code05_PathPalindrome {
  inline static int MAXN = 100001;
  inline static int LIMIT = 17;
  inline static int power = {};
  inline static Array<int> s = make_array<int>(MAXN);
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> to = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> next = make_array<int>(jshl(MAXN, 1));
  inline static int cnt = {};
  inline static Array<int> deep = make_array<int>(MAXN);
  inline static Array<Array<int>> jump = make_array<int>(MAXN, LIMIT);
  inline static i64 K = 499;
  inline static Array<i64> kpow = make_array<i64>(MAXN);
  inline static Array<Array<i64>> stup = make_array<i64>(MAXN, LIMIT);
  inline static Array<Array<i64>> stdown = make_array<i64>(MAXN, LIMIT);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code05_PathPalindrome() {}
  static void build(int n) {
    (power = Code05_PathPalindrome::log2(n));
    (cnt = 1);
    j::fill(head, 1, (n + 1), 0);
    (kpow[0] = 1);
    for (int i = 1; (i <= n); (i++)) {
      (kpow[i] = (kpow[(i - 1)] * K));
    }
  }
  static int log2(int n) {
    int ans = 0;
    while ((jshl(1, ans) <= jshr(n, 1))) {
      (ans++);
    }
    return ans;
  }
  static void addEdge(int u, int v) {
    (next[cnt] = head[u]);
    (to[cnt] = v);
    (head[u] = (cnt++));
  }
  static void dfs(int u, int f) {
    (deep[u] = (deep[f] + 1));
    (jump[u][0] = f);
    (stup[u][0] = (stdown[u][0] = s[f]));
    {
      int p = 1;
      int v = {};
      for (; (p <= power); (p++)) {
        (v = jump[u][(p - 1)]);
        (jump[u][p] = jump[v][(p - 1)]);
        (stup[u][p] =
             ((stup[u][(p - 1)] * kpow[jshl(1, (p - 1))]) + stup[v][(p - 1)]));
        (stdown[u][p] = ((stdown[v][(p - 1)] * kpow[jshl(1, (p - 1))]) +
                         stdown[u][(p - 1)]));
      }
    }
    {
      int e = head[u];
      int v = {};
      for (; (e != 0); (e = next[e])) {
        (v = to[e]);
        if ((v != f)) {
          Code05_PathPalindrome::dfs(v, u);
        }
      }
    }
  }
  static bool isPalindrome(int a, int b) {
    int lca = Code05_PathPalindrome::lca(a, b);
    i64 hash1 = Code05_PathPalindrome::hash(a, lca, b);
    i64 hash2 = Code05_PathPalindrome::hash(b, lca, a);
    return (hash1 == hash2);
  }
  static int lca(int a, int b) {
    if ((deep[a] < deep[b])) {
      int tmp = a;
      (a = b);
      (b = tmp);
    }
    for (int p = power; (p >= 0); (p--)) {
      if ((deep[jump[a][p]] >= deep[b])) {
        (a = jump[a][p]);
      }
    }
    if ((a == b)) {
      return a;
    }
    for (int p = power; (p >= 0); (p--)) {
      if ((jump[a][p] != jump[b][p])) {
        (a = jump[a][p]);
        (b = jump[b][p]);
      }
    }
    return jump[a][0];
  }
  static i64 hash(int from, int lca, int to) {
    i64 up = s[from];
    for (int p = power; (p >= 0); (p--)) {
      if ((deep[jump[from][p]] >= deep[lca])) {
        (up = ((up * kpow[jshl(1, p)]) + stup[from][p]));
        (from = jump[from][p]);
      }
    }
    if ((to == lca)) {
      return up;
    }
    i64 down = s[to];
    int height = 1;
    for (int p = power; (p >= 0); (p--)) {
      if ((deep[jump[to][p]] > deep[lca])) {
        (down = ((stdown[to][p] * kpow[height]) + down));
        (height += jshl(1, p));
        (to = jump[to][p]);
      }
    }
    return ((up * kpow[height]) + down);
  }
  static void java_main(Array<String> args) {
    IO io = IO();
    int n = io.nextInt();
    Code05_PathPalindrome::build(n);
    int si = 1;
    for (jchar c : io.next().toCharArray()) {
      (s[(si++)] = ((c - u'a') + 1));
    }
    {
      int u = 1;
      int v = {};
      for (; (u <= n); (u++)) {
        (v = io.nextInt());
        Code05_PathPalindrome::addEdge(u, v);
        Code05_PathPalindrome::addEdge(v, u);
      }
    }
    Code05_PathPalindrome::dfs(1, 0);
    int m = io.nextInt();
    {
      int i = 1;
      int a = {};
      int b = {};
      for (; (i <= m); (i++)) {
        (a = io.nextInt());
        (b = io.nextInt());
        io.println((Code05_PathPalindrome::isPalindrome(a, b) ? String(u"YES")
                                                              : String(u"NO")));
      }
    }
    io.flush();
    io.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code05_PathPalindrome::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 检查树上两节点间的路径是否是回文
// 一颗树上有n个节点，编号1~n
// 给定长度为n的数组parent, parent[i]表示节点i的父节点编号
// 给定长度为n的数组s, s[i]表示节点i上是什么字符
// 从节点a到节点b经过节点最少的路，叫做a和b的路径
// 一共有m条查询，每条查询(a,b)，a和b的路径字符串是否是回文
// 是回文打印"YES"，不是回文打印"NO"
// 1 <= n <= 10^5
// 1 <= m <= 10^5
// parent[1] = 0，即整棵树的头节点一定是1号节点
// 每个节点上的字符一定是小写字母a~z
// 测试链接 : https://ac.nowcoder.com/acm/contest/78807/G
// 提交以下的code，提交时请把类名改成"Main"，可以直接通过
        // kpow[i] = k的i次方
                // up是上坡hash值
                // down是下坡hash值
                // height是目前下坡的总高度
        // Kattio类IO效率很好，但还是不如StreamTokenizer
        // 只有StreamTokenizer无法正确处理时，才考虑使用这个类
        // 参考链接 : https://oi-wiki.org/lang/java-pro/
*/

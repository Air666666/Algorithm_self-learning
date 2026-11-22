// Source: src/class119/Code01_EmergencyAssembly1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_EmergencyAssembly1 {
  inline static int MAXN = 500001;
  inline static int LIMIT = 19;
  inline static int power = {};
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> next = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> to = make_array<int>(jshl(MAXN, 1));
  inline static int cnt = {};
  inline static Array<int> deep = make_array<int>(MAXN);
  inline static Array<Array<int>> stjump = make_array<int>(MAXN, LIMIT);
  inline static int togather = {};
  inline static i64 cost = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_EmergencyAssembly1() {}
  static void build(int n) {
    (power = Code01_EmergencyAssembly1::log2(n));
    (cnt = 1);
    j::fill(head, 1, (n + 1), 0);
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
    (stjump[u][0] = f);
    for (int p = 1; (p <= power); (p++)) {
      (stjump[u][p] = stjump[stjump[u][(p - 1)]][(p - 1)]);
    }
    for (int e = head[u]; (e != 0); (e = next[e])) {
      if ((to[e] != f)) {
        Code01_EmergencyAssembly1::dfs(to[e], u);
      }
    }
  }
  static int lca(int a, int b) {
    if ((deep[a] < deep[b])) {
      int tmp = a;
      (a = b);
      (b = tmp);
    }
    for (int p = power; (p >= 0); (p--)) {
      if ((deep[stjump[a][p]] >= deep[b])) {
        (a = stjump[a][p]);
      }
    }
    if ((a == b)) {
      return a;
    }
    for (int p = power; (p >= 0); (p--)) {
      if ((stjump[a][p] != stjump[b][p])) {
        (a = stjump[a][p]);
        (b = stjump[b][p]);
      }
    }
    return stjump[a][0];
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    int n = static_cast<int>(in.nval);
    in.nextToken();
    int m = static_cast<int>(in.nval);
    Code01_EmergencyAssembly1::build(n);
    {
      int i = 1;
      int u = {};
      int v = {};
      for (; (i < n); (i++)) {
        in.nextToken();
        (u = static_cast<int>(in.nval));
        in.nextToken();
        (v = static_cast<int>(in.nval));
        Code01_EmergencyAssembly1::addEdge(u, v);
        Code01_EmergencyAssembly1::addEdge(v, u);
      }
    }
    Code01_EmergencyAssembly1::dfs(1, 0);
    {
      int i = 1;
      int a = {};
      int b = {};
      int c = {};
      for (; (i <= m); (i++)) {
        in.nextToken();
        (a = static_cast<int>(in.nval));
        in.nextToken();
        (b = static_cast<int>(in.nval));
        in.nextToken();
        (c = static_cast<int>(in.nval));
        Code01_EmergencyAssembly1::compute(a, b, c);
        out.println(((togather + String(u" ")) + cost));
      }
    }
    out.flush();
    out.close();
    br.close();
  }
  static void compute(int a, int b, int c) {
    int h1 = Code01_EmergencyAssembly1::lca(a, b);
    int h2 = Code01_EmergencyAssembly1::lca(a, c);
    int h3 = Code01_EmergencyAssembly1::lca(b, c);
    int high = ((h1 != h2) ? ((deep[h1] < deep[h2]) ? h1 : h2) : h1);
    int low = ((h1 != h2) ? ((deep[h1] > deep[h2]) ? h1 : h2) : h3);
    (togather = low);
    (cost = ((((static_cast<i64>(deep[a]) + deep[b]) + deep[c]) -
              (deep[high] * 2)) -
             deep[low]));
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code01_EmergencyAssembly1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 紧急集合
// 一共有n个节点，编号1 ~ n，一定有n-1条边连接形成一颗树
// 从一个点到另一个点的路径上有几条边，就需要耗费几个金币
// 每条查询(a, b, c)表示有三个人分别站在a、b、c点上
// 他们想集合在树上的某个点，并且想花费的金币总数最少
// 一共有m条查询，打印m个答案
// 1 <= n <= 5 * 10^5
// 1 <= m <= 5 * 10^5
// 测试链接 : https://www.luogu.com.cn/problem/P4281
// 如下实现是正确的，但是洛谷平台对空间卡的很严，只有使用C++能全部通过
// C++版本就是本节代码中的Code01_EmergencyAssembly2文件
// C++版本和java版本逻辑完全一样，但只有C++版本可以通过所有测试用例
// 这是洛谷平台没有照顾各种语言的实现所导致的
// 在真正笔试、比赛时，一定是兼顾各种语言的，该实现是一定正确的
// 提交以下的code，提交时请把类名改成"Main"
        // deep[i] : i节点在第几层，算距离用
        // 利用stjump求最低公共祖先
                // 来自对结构关系的深入分析，课上重点解释
*/

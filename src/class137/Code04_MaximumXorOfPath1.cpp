// Source: src/class137/Code04_MaximumXorOfPath1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_MaximumXorOfPath1 {
  inline static int MAXN = 50001;
  inline static int MAXM = 200002;
  inline static int BIT = 60;
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> next = make_array<int>(MAXM);
  inline static Array<int> to = make_array<int>(MAXM);
  inline static Array<i64> weight = make_array<i64>(MAXM);
  inline static int cnt = {};
  inline static Array<i64> basis = make_array<i64>((BIT + 1));
  inline static Array<bool> visited = make_array<bool>(MAXN);
  inline static Array<i64> path = make_array<i64>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_MaximumXorOfPath1() {}
  static void prepare(int n) {
    (cnt = 1);
    j::fill(head, 1, (n + 1), 0);
    j::fill(basis, 0);
  }
  static void addEdge(int u, int v, i64 w) {
    (next[cnt] = head[u]);
    (to[cnt] = v);
    (weight[cnt] = w);
    (head[u] = (cnt++));
  }
  static bool insert(i64 num) {
    for (int i = BIT; (i >= 0); (i--))
      if ((jshr(num, i) == 1)) {
        if ((basis[i] == 0)) {
          (basis[i] = num);
          return true;
        }
        (num ^= basis[i]);
      }
    return false;
  }
  static void dfs(int u, int f, i64 p) {
    (path[u] = p);
    (visited[u] = true);
    for (int e = head[u]; (e != 0); (e = next[e])) {
      int v = to[e];
      if ((v != f)) {
        i64 xor_java = (p ^ weight[e]);
        if (visited[v]) {
          Code04_MaximumXorOfPath1::insert((xor_java ^ path[v]));
        } else {
          Code04_MaximumXorOfPath1::dfs(v, u, xor_java);
        }
      }
    }
  }
  static i64 query(i64 init) {
    for (int i = BIT; (i >= 0); (i--)) {
      (init = jmax(init, (init ^ basis[i])));
    }
    return init;
  }
  static void java_main(Array<String> args) {
    IO io = IO();
    int n = io.nextInt();
    int m = io.nextInt();
    Code04_MaximumXorOfPath1::prepare(n);
    for (int i = 1; (i <= m); (i++)) {
      int u = io.nextInt();
      int v = io.nextInt();
      i64 w = io.nextLong();
      Code04_MaximumXorOfPath1::addEdge(u, v, w);
      Code04_MaximumXorOfPath1::addEdge(v, u, w);
    }
    Code04_MaximumXorOfPath1::dfs(1, 0, 0);
    io.println(Code04_MaximumXorOfPath1::query(path[n]));
    io.flush();
    io.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code04_MaximumXorOfPath1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 路径最大异或和(递归版)
// 一共有n个点，编号1~n，由m条无向边连接
// 每条边有权值，输入保证图是连通的，可能有环
// 找到1到n的一条路径，路径可以重复经过某些点或边
// 当一条边在路径中出现了多次时，异或的时候也要算多次
// 希望找到一条从1到n的路径，所有边权异或和尽量大，返回这个最大异或和
// 1 <= n <= 50000
// 1 <= m <= 100000
// 0 <= 边权 <= 10^18
// 测试链接 : https://www.luogu.com.cn/problem/P4151
// 提交以下的code，提交时请把类名改成"Main"
// C++这么写能通过，java会因为递归层数太多而爆栈
// java能通过的写法参考本节课Code04_MaximumXorOfPath2文件
        // 链式前向星
        // 所有环的异或和构建的线性基
        // 某个节点在dfs过程中是否被访问过
        // 从头结点到当前节点的异或和
        // Kattio类IO效率很好，但还是不如StreamTokenizer
        // 只有StreamTokenizer无法正确处理时，才考虑使用这个类
        // 参考链接 : https://oi-wiki.org/lang/java-pro/
*/

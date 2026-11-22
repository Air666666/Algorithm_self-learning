// Source: src/class137/Code04_MaximumXorOfPath2.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_MaximumXorOfPath2 {
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
  inline static Array<Array<int>> ufe = make_array<int>(MAXN, 3);
  inline static Array<i64> pstack = make_array<i64>(MAXN);
  inline static int u = {};
  inline static int f = {};
  inline static int e = {};
  inline static i64 p = {};
  inline static int stackSize = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_MaximumXorOfPath2() {}
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
  static void push(int u, int f, int e, i64 p) {
    (ufe[stackSize][0] = u);
    (ufe[stackSize][1] = f);
    (ufe[stackSize][2] = e);
    (pstack[stackSize] = p);
    (stackSize++);
  }
  static void pop() {
    (--stackSize);
    (u = ufe[stackSize][0]);
    (f = ufe[stackSize][1]);
    (e = ufe[stackSize][2]);
    (p = pstack[stackSize]);
  }
  static void dfs(int root) {
    (stackSize = 0);
    Code04_MaximumXorOfPath2::push(root, 0, (-1), 0);
    while ((stackSize > 0)) {
      Code04_MaximumXorOfPath2::pop();
      if ((e == (-1))) {
        (path[u] = p);
        (visited[u] = true);
        (e = head[u]);
      } else {
        (e = next[e]);
      }
      if ((e != 0)) {
        Code04_MaximumXorOfPath2::push(u, f, e, p);
        int v = to[e];
        i64 xor_java = (p ^ weight[e]);
        if (visited[v]) {
          Code04_MaximumXorOfPath2::insert((xor_java ^ path[v]));
        } else {
          Code04_MaximumXorOfPath2::push(v, u, (-1), xor_java);
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
    Code04_MaximumXorOfPath2::prepare(n);
    for (int i = 1; (i <= m); (i++)) {
      int u = io.nextInt();
      int v = io.nextInt();
      i64 w = io.nextLong();
      Code04_MaximumXorOfPath2::addEdge(u, v, w);
      Code04_MaximumXorOfPath2::addEdge(v, u, w);
    }
    Code04_MaximumXorOfPath2::dfs(1);
    io.println(Code04_MaximumXorOfPath2::query(path[n]));
    io.flush();
    io.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code04_MaximumXorOfPath2::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 路径最大异或和(迭代版)
// 一共有n个点，编号1~n，由m条无向边连接
// 每条边有权值，输入保证图是连通的，可能有环
// 找到1到n的一条路径，路径可以重复经过某些点或边
// 当一条边在路径中出现了多次时，异或的时候也要算多次
// 希望找到一条从1到n的路径，所有边权异或和尽量大，返回这个最大异或和
// 1 <= n <= 50000
// 1 <= m <= 100000
// 0 <= 边权 <= 10^18
// 测试链接 : https://www.luogu.com.cn/problem/P4151
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // dfs迭代版
        // 不懂去看讲解118，递归改迭代的部分
        // Kattio类IO效率很好，但还是不如StreamTokenizer
        // 只有StreamTokenizer无法正确处理时，才考虑使用这个类
        // 参考链接 : https://oi-wiki.org/lang/java-pro/
*/

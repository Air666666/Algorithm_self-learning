// Source: src/class137/Code03_LuckyNumber2.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_LuckyNumber2 {
  inline static int MAXN = 20002;
  inline static int LIMIT = 16;
  inline static int BIT = 60;
  inline static Array<i64> arr = make_array<i64>(MAXN);
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> next = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> to = make_array<int>(jshl(MAXN, 1));
  inline static int cnt = {};
  inline static Array<int> deep = make_array<int>(MAXN);
  inline static Array<Array<int>> stjump = make_array<int>(MAXN, LIMIT);
  inline static int power = {};
  inline static Array<Array<i64>> bases = make_array<i64>(MAXN, (BIT + 1));
  inline static Array<Array<int>> levels = make_array<int>(MAXN, (BIT + 1));
  inline static Array<Array<int>> ufe = make_array<int>(MAXN, 3);
  inline static int stackSize = {};
  inline static int u = {};
  inline static int f = {};
  inline static int e = {};
  inline static Array<i64> basis = make_array<i64>((BIT + 1));
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_LuckyNumber2() {}
  static void prepare(int n) {
    (cnt = 1);
    j::fill(head, 1, (n + 1), 0);
    (power = Code03_LuckyNumber2::log2(n));
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
  static void push(int u, int f, int e) {
    (ufe[stackSize][0] = u);
    (ufe[stackSize][1] = f);
    (ufe[stackSize][2] = e);
    (stackSize++);
  }
  static void pop() {
    (--stackSize);
    (u = ufe[stackSize][0]);
    (f = ufe[stackSize][1]);
    (e = ufe[stackSize][2]);
  }
  static void dfs(int root) {
    (stackSize = 0);
    Code03_LuckyNumber2::push(root, 0, (-1));
    while ((stackSize > 0)) {
      Code03_LuckyNumber2::pop();
      if ((e == (-1))) {
        (deep[u] = (deep[f] + 1));
        (stjump[u][0] = f);
        for (int p = 1; (p <= power); (p++)) {
          (stjump[u][p] = stjump[stjump[u][(p - 1)]][(p - 1)]);
        }
        for (int i = 0; (i <= BIT); (i++)) {
          (bases[u][i] = bases[f][i]);
          (levels[u][i] = levels[f][i]);
        }
        Code03_LuckyNumber2::insertReplace(arr[u], deep[u], bases[u],
                                           levels[u]);
        (e = head[u]);
      } else {
        (e = next[e]);
      }
      if ((e != 0)) {
        Code03_LuckyNumber2::push(u, f, e);
        if ((to[e] != f)) {
          Code03_LuckyNumber2::push(to[e], u, (-1));
        }
      }
    }
  }
  static bool insertReplace(i64 curv, int curl, Array<i64> basis,
                            Array<int> level) {
    for (int i = BIT; (i >= 0); (i--)) {
      if ((jshr(curv, i) == 1)) {
        if ((basis[i] == 0)) {
          (basis[i] = curv);
          (level[i] = curl);
          return true;
        }
        if ((curl > level[i])) {
          i64 tmp1 = curv;
          (curv = basis[i]);
          (basis[i] = tmp1);
          int tmp2 = level[i];
          (level[i] = curl);
          (curl = tmp2);
        }
        (curv ^= basis[i]);
      }
    }
    return false;
  }
  static int lca(int x, int y) {
    if ((deep[x] < deep[y])) {
      int tmp = x;
      (x = y);
      (y = tmp);
    }
    for (int p = power; (p >= 0); (p--)) {
      if ((deep[stjump[x][p]] >= deep[y])) {
        (x = stjump[x][p]);
      }
    }
    if ((x == y)) {
      return x;
    }
    for (int p = power; (p >= 0); (p--)) {
      if ((stjump[x][p] != stjump[y][p])) {
        (x = stjump[x][p]);
        (y = stjump[y][p]);
      }
    }
    return stjump[x][0];
  }
  static i64 query(int x, int y) {
    int lca = Code03_LuckyNumber2::lca(x, y);
    Array<i64> basisx = bases[x];
    Array<int> levelx = levels[x];
    Array<i64> basisy = bases[y];
    Array<int> levely = levels[y];
    j::fill(basis, 0);
    for (int i = BIT; (i >= 0); (i--)) {
      i64 num = basisx[i];
      if (((levelx[i] >= deep[lca]) && (num != 0))) {
        (basis[i] = num);
      }
    }
    for (int i = BIT; (i >= 0); (i--)) {
      i64 num = basisy[i];
      if (((levely[i] >= deep[lca]) && (num != 0))) {
        for (int j = i; (j >= 0); (j--)) {
          if ((jshr(num, j) == 1)) {
            if ((basis[j] == 0)) {
              (basis[j] = num);
              break;
            }
            (num ^= basis[j]);
          }
        }
      }
    }
    i64 ans = 0;
    for (int i = BIT; (i >= 0); (i--)) {
      (ans = jmax(ans, (ans ^ basis[i])));
    }
    return ans;
  }
  static void java_main(Array<String> args) {
    IO io = IO();
    int n = io.nextInt();
    int q = io.nextInt();
    Code03_LuckyNumber2::prepare(n);
    for (int i = 1; (i <= n); (i++)) {
      (arr[i] = io.nextLong());
    }
    {
      int i = 1;
      int u = {};
      int v = {};
      for (; (i < n); (i++)) {
        (u = io.nextInt());
        (v = io.nextInt());
        Code03_LuckyNumber2::addEdge(u, v);
        Code03_LuckyNumber2::addEdge(v, u);
      }
    }
    Code03_LuckyNumber2::dfs(1);
    {
      int i = 1;
      int x = {};
      int y = {};
      for (; (i <= q); (i++)) {
        (x = io.nextInt());
        (y = io.nextInt());
        io.println(Code03_LuckyNumber2::query(x, y));
      }
    }
    io.flush();
    io.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code03_LuckyNumber2::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 幸运数字(迭代版)
// 一共有n个点，编号1~n，由n-1条无向边连成一棵树，每个点上有数字
// 一共有q条查询，每次返回a到b的路径上，可以随意选择数字，能得到的最大异或和
// 1 <= n <= 2 * 10^4
// 1 <= q <= 2 * 10^5
// 0 <= 点上的数字 <= 2^60
// 测试链接 : https://www.luogu.com.cn/problem/P3292
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // dfs迭代版
        // 不懂去看讲解118，递归改迭代的部分
        // Kattio类IO效率很好，但还是不如StreamTokenizer
        // 只有StreamTokenizer无法正确处理时，才考虑使用这个类
        // 参考链接 : https://oi-wiki.org/lang/java-pro/
*/

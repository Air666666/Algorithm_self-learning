// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P4175

// Source: src/class160/Code07_NetworkManagement1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code07_NetworkManagement1 {
  inline static int MAXN = 80001;
  inline static int MAXT = (MAXN * 110);
  inline static int MAXP = 18;
  inline static int n = {};
  inline static int m = {};
  inline static int s = {};
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static Array<Array<int>> ques = make_array<int>(MAXN, 3);
  inline static Array<int> sorted = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> next = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> to = make_array<int>(jshl(MAXN, 1));
  inline static int cntg = 0;
  inline static Array<int> root = make_array<int>(MAXN);
  inline static Array<int> left = make_array<int>(MAXT);
  inline static Array<int> right = make_array<int>(MAXT);
  inline static Array<int> sum = make_array<int>(MAXT);
  inline static int cntt = 0;
  inline static Array<int> deep = make_array<int>(MAXN);
  inline static Array<int> size = make_array<int>(MAXN);
  inline static Array<int> dfn = make_array<int>(MAXN);
  inline static Array<Array<int>> stjump = make_array<int>(MAXN, MAXP);
  inline static int cntd = 0;
  inline static Array<int> addTree = make_array<int>(MAXN);
  inline static Array<int> minusTree = make_array<int>(MAXN);
  inline static int cntadd = {};
  inline static int cntminus = {};
  inline static Array<Array<int>> ufe = make_array<int>(MAXN, 3);
  inline static int stackSize = {};
  inline static int u = {};
  inline static int f = {};
  inline static int e = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code07_NetworkManagement1() {}
  static void addEdge(int u, int v) {
    (next[(++cntg)] = head[u]);
    (to[cntg] = v);
    (head[u] = cntg);
  }
  static int kth(int num) {
    int left = 1;
    int right = s;
    int mid = {};
    while ((left <= right)) {
      (mid = jdiv((left + right), 2));
      if ((sorted[mid] == num)) {
        return mid;
      } else if ((sorted[mid] < num)) {
        (left = (mid + 1));
      } else {
        (right = (mid - 1));
      }
    }
    return (-1);
  }
  static int lowbit(int i) { return (i & (-i)); }
  static void dfs1(int u, int fa) {
    (deep[u] = (deep[fa] + 1));
    (size[u] = 1);
    (dfn[u] = (++cntd));
    (stjump[u][0] = fa);
    for (int p = 1; (p < MAXP); (p++)) {
      (stjump[u][p] = stjump[stjump[u][(p - 1)]][(p - 1)]);
    }
    for (int e = head[u]; (e > 0); (e = next[e])) {
      if ((to[e] != fa)) {
        Code07_NetworkManagement1::dfs1(to[e], u);
      }
    }
    for (int e = head[u]; (e > 0); (e = next[e])) {
      if ((to[e] != fa)) {
        (size[u] += size[to[e]]);
      }
    }
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
  static void dfs2() {
    (stackSize = 0);
    Code07_NetworkManagement1::push(1, 0, (-1));
    while ((stackSize > 0)) {
      Code07_NetworkManagement1::pop();
      if ((e == (-1))) {
        (deep[u] = (deep[f] + 1));
        (size[u] = 1);
        (dfn[u] = (++cntd));
        (stjump[u][0] = f);
        for (int p = 1; (p < MAXP); (p++)) {
          (stjump[u][p] = stjump[stjump[u][(p - 1)]][(p - 1)]);
        }
        (e = head[u]);
      } else {
        (e = next[e]);
      }
      if ((e != 0)) {
        Code07_NetworkManagement1::push(u, f, e);
        if ((to[e] != f)) {
          Code07_NetworkManagement1::push(to[e], u, (-1));
        }
      } else {
        for (int e = head[u]; (e > 0); (e = next[e])) {
          if ((to[e] != f)) {
            (size[u] += size[to[e]]);
          }
        }
      }
    }
  }
  static int lca(int a, int b) {
    if ((deep[a] < deep[b])) {
      int tmp = a;
      (a = b);
      (b = tmp);
    }
    for (int p = (MAXP - 1); (p >= 0); (p--)) {
      if ((deep[stjump[a][p]] >= deep[b])) {
        (a = stjump[a][p]);
      }
    }
    if ((a == b)) {
      return a;
    }
    for (int p = (MAXP - 1); (p >= 0); (p--)) {
      if ((stjump[a][p] != stjump[b][p])) {
        (a = stjump[a][p]);
        (b = stjump[b][p]);
      }
    }
    return stjump[a][0];
  }
  static int innerAdd(int jobi, int jobv, int l, int r, int i) {
    if ((i == 0)) {
      (i = (++cntt));
    }
    if ((l == r)) {
      (sum[i] += jobv);
    } else {
      int mid = jdiv((l + r), 2);
      if ((jobi <= mid)) {
        (left[i] =
             Code07_NetworkManagement1::innerAdd(jobi, jobv, l, mid, left[i]));
      } else {
        (right[i] = Code07_NetworkManagement1::innerAdd(jobi, jobv, (mid + 1),
                                                        r, right[i]));
      }
      (sum[i] = (sum[left[i]] + sum[right[i]]));
    }
    return i;
  }
  static int innerQuery(int jobk, int l, int r) {
    if ((l == r)) {
      return l;
    }
    int mid = jdiv((l + r), 2);
    int leftsum = 0;
    for (int i = 1; (i <= cntadd); (i++)) {
      (leftsum += sum[left[addTree[i]]]);
    }
    for (int i = 1; (i <= cntminus); (i++)) {
      (leftsum -= sum[left[minusTree[i]]]);
    }
    if ((jobk <= leftsum)) {
      for (int i = 1; (i <= cntadd); (i++)) {
        (addTree[i] = left[addTree[i]]);
      }
      for (int i = 1; (i <= cntminus); (i++)) {
        (minusTree[i] = left[minusTree[i]]);
      }
      return Code07_NetworkManagement1::innerQuery(jobk, l, mid);
    } else {
      for (int i = 1; (i <= cntadd); (i++)) {
        (addTree[i] = right[addTree[i]]);
      }
      for (int i = 1; (i <= cntminus); (i++)) {
        (minusTree[i] = right[minusTree[i]]);
      }
      return Code07_NetworkManagement1::innerQuery((jobk - leftsum), (mid + 1),
                                                   r);
    }
  }
  static void add(int i, int val, int cnt) {
    for (; (i <= n); (i += Code07_NetworkManagement1::lowbit(i))) {
      (root[i] = Code07_NetworkManagement1::innerAdd(val, cnt, 1, s, root[i]));
    }
  }
  static void update(int i, int v) {
    Code07_NetworkManagement1::add(dfn[i], arr[i], (-1));
    Code07_NetworkManagement1::add((dfn[i] + size[i]), arr[i], 1);
    (arr[i] = Code07_NetworkManagement1::kth(v));
    Code07_NetworkManagement1::add(dfn[i], arr[i], 1);
    Code07_NetworkManagement1::add((dfn[i] + size[i]), arr[i], (-1));
  }
  static int query(int x, int y, int k) {
    int lca = Code07_NetworkManagement1::lca(x, y);
    int lcafa = stjump[lca][0];
    int num = (((deep[x] + deep[y]) - deep[lca]) - deep[lcafa]);
    if ((num < k)) {
      return (-1);
    }
    (cntadd = (cntminus = 0));
    for (int i = dfn[x]; (i > 0); (i -= Code07_NetworkManagement1::lowbit(i))) {
      (addTree[(++cntadd)] = root[i]);
    }
    for (int i = dfn[y]; (i > 0); (i -= Code07_NetworkManagement1::lowbit(i))) {
      (addTree[(++cntadd)] = root[i]);
    }
    for (int i = dfn[lca]; (i > 0);
         (i -= Code07_NetworkManagement1::lowbit(i))) {
      (minusTree[(++cntminus)] = root[i]);
    }
    for (int i = dfn[lcafa]; (i > 0);
         (i -= Code07_NetworkManagement1::lowbit(i))) {
      (minusTree[(++cntminus)] = root[i]);
    }
    return sorted[Code07_NetworkManagement1::innerQuery(((num - k) + 1), 1, s)];
  }
  static void prepare() {
    (s = 0);
    for (int i = 1; (i <= n); (i++)) {
      (sorted[(++s)] = arr[i]);
    }
    for (int i = 1; (i <= m); (i++)) {
      if ((ques[i][0] == 0)) {
        (sorted[(++s)] = ques[i][2]);
      }
    }
    j::sort(sorted, 1, (s + 1));
    int len = 1;
    for (int i = 2; (i <= s); (i++)) {
      if ((sorted[len] != sorted[i])) {
        (sorted[(++len)] = sorted[i]);
      }
    }
    (s = len);
    for (int i = 1; (i <= n); (i++)) {
      (arr[i] = Code07_NetworkManagement1::kth(arr[i]));
    }
    Code07_NetworkManagement1::dfs2();
    for (int i = 1; (i <= n); (i++)) {
      Code07_NetworkManagement1::add(dfn[i], arr[i], 1);
      Code07_NetworkManagement1::add((dfn[i] + size[i]), arr[i], (-1));
    }
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    (n = static_cast<int>(in.nval));
    in.nextToken();
    (m = static_cast<int>(in.nval));
    for (int i = 1; (i <= n); (i++)) {
      in.nextToken();
      (arr[i] = static_cast<int>(in.nval));
    }
    {
      int i = 1;
      int u = {};
      int v = {};
      for (; (i < n); (i++)) {
        in.nextToken();
        (u = static_cast<int>(in.nval));
        in.nextToken();
        (v = static_cast<int>(in.nval));
        Code07_NetworkManagement1::addEdge(u, v);
        Code07_NetworkManagement1::addEdge(v, u);
      }
    }
    for (int i = 1; (i <= m); (i++)) {
      in.nextToken();
      (ques[i][0] = static_cast<int>(in.nval));
      in.nextToken();
      (ques[i][1] = static_cast<int>(in.nval));
      in.nextToken();
      (ques[i][2] = static_cast<int>(in.nval));
    }
    Code07_NetworkManagement1::prepare();
    {
      int i = 1;
      int k = {};
      int x = {};
      int y = {};
      for (; (i <= m); (i++)) {
        (k = ques[i][0]);
        (x = ques[i][1]);
        (y = ques[i][2]);
        if ((k == 0)) {
          Code07_NetworkManagement1::update(x, y);
        } else {
          int ans = Code07_NetworkManagement1::query(x, y, k);
          if ((ans == (-1))) {
            out.println(String(u"invalid request!"));
          } else {
            out.println(ans);
          }
        }
      }
    }
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code07_NetworkManagement1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 网络管理，java版
// 一共有n个点，编号1~n，每个点给定点权，给定n-1条边，所有点连成一棵树
// 实现如下类型的操作，操作一共发生m次
// 操作 0 x y : x号点的点权变成y
// 操作 k x y : 保证k > 0，点x到点y的路径上，打印第k大的值
//              如果路径上不够k个点，打印"invalid request!"
// 1 <= n、m <= 8 * 10^4
// 点权 <= 10^8
// 测试链接 : https://www.luogu.com.cn/problem/P4175
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 链式前向星需要
        // 外层的树状数组
        // 树上倍增需要
        // dfs1是递归版，java版本提交会爆栈，C++版本不会爆栈
        // dfs迭代版，都可以通过
        // 讲解118，详解了从递归版改迭代版
        // dfs1的迭代版
        // i是dfn序号，val这是值，增加cnt的计数
*/

// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P3302

// Source: src/class163/Code07_Forest1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code07_Forest1 {
  inline static int MAXN = 80001;
  inline static int MAXT = (MAXN * 110);
  inline static int MAXP = 20;
  inline static int testcase = {};
  inline static int n = {};
  inline static int m = {};
  inline static int t = {};
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static Array<int> sorted = make_array<int>(MAXN);
  inline static int diff = {};
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> next = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> to = make_array<int>(jshl(MAXN, 1));
  inline static int cntg = 0;
  inline static Array<int> root = make_array<int>(MAXN);
  inline static Array<int> left = make_array<int>(MAXT);
  inline static Array<int> right = make_array<int>(MAXT);
  inline static Array<int> siz = make_array<int>(MAXT);
  inline static int cntt = 0;
  inline static Array<int> dep = make_array<int>(MAXN);
  inline static Array<Array<int>> stjump = make_array<int>(MAXN, MAXP);
  inline static Array<int> treeHead = make_array<int>(MAXN);
  inline static Array<int> setSiz = make_array<int>(MAXN);
  inline static Array<Array<int>> stack = make_array<int>(MAXN, 4);
  inline static int stackSize = {};
  inline static int cur = {};
  inline static int father = {};
  inline static int treehead = {};
  inline static int edge = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code07_Forest1() {}
  static int kth(int num) {
    int left = 1;
    int right = diff;
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
  static void addEdge(int u, int v) {
    (next[(++cntg)] = head[u]);
    (to[cntg] = v);
    (head[u] = cntg);
  }
  static int insert(int jobi, int l, int r, int i) {
    int rt = (++cntt);
    (left[rt] = left[i]);
    (right[rt] = right[i]);
    (siz[rt] = (siz[i] + 1));
    if ((l < r)) {
      int mid = jdiv((l + r), 2);
      if ((jobi <= mid)) {
        (left[rt] = Code07_Forest1::insert(jobi, l, mid, left[rt]));
      } else {
        (right[rt] = Code07_Forest1::insert(jobi, (mid + 1), r, right[rt]));
      }
    }
    return rt;
  }
  static int query(int jobk, int l, int r, int u, int v, int lca, int lcafa) {
    if ((l == r)) {
      return l;
    }
    int lsize =
        (((siz[left[u]] + siz[left[v]]) - siz[left[lca]]) - siz[left[lcafa]]);
    int mid = jdiv((l + r), 2);
    if ((lsize >= jobk)) {
      return Code07_Forest1::query(jobk, l, mid, left[u], left[v], left[lca],
                                   left[lcafa]);
    } else {
      return Code07_Forest1::query((jobk - lsize), (mid + 1), r, right[u],
                                   right[v], right[lca], right[lcafa]);
    }
  }
  static int lca(int a, int b) {
    if ((dep[a] < dep[b])) {
      int tmp = a;
      (a = b);
      (b = tmp);
    }
    for (int p = (MAXP - 1); (p >= 0); (p--)) {
      if ((dep[stjump[a][p]] >= dep[b])) {
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
  static int queryKth(int x, int y, int k) {
    int xylca = Code07_Forest1::lca(x, y);
    int lcafa = stjump[xylca][0];
    int i = Code07_Forest1::query(k, 1, diff, root[x], root[y], root[xylca],
                                  root[lcafa]);
    return sorted[i];
  }
  static void dfs1(int u, int fa, int treeh) {
    (root[u] = Code07_Forest1::insert(arr[u], 1, diff, root[fa]));
    (dep[u] = (dep[fa] + 1));
    (treeHead[u] = treeh);
    (setSiz[treeh]++);
    (stjump[u][0] = fa);
    for (int p = 1; (p < MAXP); (p++)) {
      (stjump[u][p] = stjump[stjump[u][(p - 1)]][(p - 1)]);
    }
    for (int e = head[u]; (e > 0); (e = next[e])) {
      if ((to[e] != fa)) {
        Code07_Forest1::dfs1(to[e], u, treeh);
      }
    }
  }
  static void push(int cur, int father, int treehead, int edge) {
    (stack[stackSize][0] = cur);
    (stack[stackSize][1] = father);
    (stack[stackSize][2] = treehead);
    (stack[stackSize][3] = edge);
    (stackSize++);
  }
  static void pop() {
    (--stackSize);
    (cur = stack[stackSize][0]);
    (father = stack[stackSize][1]);
    (treehead = stack[stackSize][2]);
    (edge = stack[stackSize][3]);
  }
  static void dfs2(int i, int fa, int treeh) {
    (stackSize = 0);
    Code07_Forest1::push(i, fa, treeh, (-1));
    while ((stackSize > 0)) {
      Code07_Forest1::pop();
      if ((edge == (-1))) {
        (root[cur] = Code07_Forest1::insert(arr[cur], 1, diff, root[father]));
        (dep[cur] = (dep[father] + 1));
        (treeHead[cur] = treehead);
        (setSiz[treehead]++);
        (stjump[cur][0] = father);
        for (int p = 1; (p < MAXP); (p++)) {
          (stjump[cur][p] = stjump[stjump[cur][(p - 1)]][(p - 1)]);
        }
        (edge = head[cur]);
      } else {
        (edge = next[edge]);
      }
      if ((edge != 0)) {
        Code07_Forest1::push(cur, father, treehead, edge);
        if ((to[edge] != father)) {
          Code07_Forest1::push(to[edge], cur, treehead, (-1));
        }
      }
    }
  }
  static void connect(int x, int y) {
    Code07_Forest1::addEdge(x, y);
    Code07_Forest1::addEdge(y, x);
    int fx = treeHead[x];
    int fy = treeHead[y];
    if ((setSiz[fx] >= setSiz[fy])) {
      Code07_Forest1::dfs2(y, x, fx);
    } else {
      Code07_Forest1::dfs2(x, y, fy);
    }
  }
  static void prepare() {
    for (int i = 1; (i <= n); (i++)) {
      (sorted[i] = arr[i]);
    }
    j::sort(sorted, 1, (n + 1));
    (diff = 1);
    for (int i = 2; (i <= n); (i++)) {
      if ((sorted[diff] != sorted[i])) {
        (sorted[(++diff)] = sorted[i]);
      }
    }
    for (int i = 1; (i <= n); (i++)) {
      (arr[i] = Code07_Forest1::kth(arr[i]));
    }
    for (int i = 1; (i <= n); (i++)) {
      if ((treeHead[i] == 0)) {
        Code07_Forest1::dfs2(i, 0, i);
      }
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO();
    IO out = IO(IO(jout));
    (testcase = in.nextInt());
    (n = in.nextInt());
    (m = in.nextInt());
    (t = in.nextInt());
    for (int i = 1; (i <= n); (i++)) {
      (arr[i] = in.nextInt());
    }
    {
      int i = 1;
      int u = {};
      int v = {};
      for (; (i <= m); (i++)) {
        (u = in.nextInt());
        (v = in.nextInt());
        Code07_Forest1::addEdge(u, v);
        Code07_Forest1::addEdge(v, u);
      }
    }
    Code07_Forest1::prepare();
    jchar op = {};
    int x = {};
    int y = {};
    int k = {};
    int lastAns = 0;
    for (int i = 1; (i <= t); (i++)) {
      (op = in.nextTokenLastChar());
      (x = (in.nextInt() ^ lastAns));
      (y = (in.nextInt() ^ lastAns));
      if ((op == u'Q')) {
        (k = (in.nextInt() ^ lastAns));
        (lastAns = Code07_Forest1::queryKth(x, y, k));
        out.println(lastAns);
      } else {
        Code07_Forest1::connect(x, y);
      }
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code07_Forest1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 森林，java版
// 一共有n个节点，编号1~n，初始时给定m条边，所有节点可能组成森林结构
// 每个节点都给定非负的点权，一共有t条操作，每条操作是如下两种类型中的一种
// 操作 Q x y k : 点x到点y路径上所有的权值中，打印第k小的权值是多少
//                题目保证x和y联通，并且路径上至少有k个点
// 操作 L x y   : 点x和点y之间连接一条边
//                题目保证操作后，所有节点仍然是森林
// 题目要求强制在线，请不要使用离线算法
// 1 <= n、m、t <= 8 * 10^4    点权 <= 10^9
// 测试链接 : https://www.luogu.com.cn/problem/P3302
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 来自讲解158，题目4
        // 来自讲解158，题目4
        // 来自讲解158，题目4
        // 来自讲解158，题目4
        // 来自讲解158，题目4
        // 来自讲解158，题目4
        // 递归版，C++可以通过，java无法通过，递归会爆栈
        // 迭代版，都可以通过
        // 讲解118，详解了从递归版改迭代版
        // dfs1的迭代版
        // x所在的树和y所在的树，合并成一棵树
        // 离散化
        // 每棵子树建立可持久化线段树
        // 记录每个节点的所在子树的头节点
        // 记录每棵子树的大小
        // 读写工具类
*/

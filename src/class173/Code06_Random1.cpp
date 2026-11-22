// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P3603

// Source: src/class173/Code06_Random1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code06_Random1 {
  struct BitSet;
  struct BitSet {
    int len = {};
    Array<int> set = {};
    String toString() const { return j::str(static_cast<const void *>(this)); }
    BitSet() {
      (len = jdiv((MAXV + 31), 32));
      (set = make_array<int>(len));
    }
    void clear() {
      for (int i = 0; (i < len); (i++)) {
        (set[i] = 0);
      }
    }
    void setOne(int v) { (set[jdiv(v, 32)] |= jshl(1, jrem(v, 32))); }
    void or_method(BitSet *obj) {
      for (int i = 0; (i < len); (i++)) {
        (set[i] |= obj->set[i]);
      }
    }
    int countOnes() {
      int ans = 0;
      for (int x : set) {
        (ans += __builtin_popcount(x));
      }
      return ans;
    }
    int mex() {
      {
        int i = 0;
        int inv = {};
        for (; (i < len); (i++)) {
          (inv = (~set[i]));
          if ((inv != 0)) {
            return (
                (i * 32) +
                (inv == 0 ? 32 : __builtin_ctz(static_cast<unsigned>(inv))));
          }
        }
      }
      return (-1);
    }
  };
  inline static int MAXN = 100001;
  inline static int MAXB = 401;
  inline static int MAXV = 30001;
  inline static int MAXP = 17;
  inline static int n = {};
  inline static int m = {};
  inline static int f = {};
  inline static int k = {};
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> next = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> to = make_array<int>(jshl(MAXN, 1));
  inline static int cntg = 0;
  inline static Array<int> dep = make_array<int>(MAXN);
  inline static Array<Array<int>> stjump = make_array<int>(MAXN, MAXP);
  inline static int markNum = {};
  inline static Array<bool> vis = make_array<bool>(MAXN);
  inline static Array<int> markNode = make_array<int>(MAXB);
  inline static Array<int> kthMark = make_array<int>(MAXN);
  inline static Array<int> up = make_array<int>(MAXN);
  inline static Array<BitSet *> downSet = make_array<BitSet *>(MAXB);
  inline static BitSet *ans = new BitSet();
  inline static Array<Array<int>> ufe = make_array<int>(MAXN, 3);
  inline static int stacksize = {};
  inline static int cur = {};
  inline static int fath = {};
  inline static int edge = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code06_Random1() {}
  static void addEdge(int u, int v) {
    (next[(++cntg)] = head[u]);
    (to[cntg] = v);
    (head[u] = cntg);
  }
  static void dfs1(int u, int fa) {
    (dep[u] = (dep[fa] + 1));
    (stjump[u][0] = fa);
    for (int p = 1; (p < MAXP); (p++)) {
      (stjump[u][p] = stjump[stjump[u][(p - 1)]][(p - 1)]);
    }
    for (int e = head[u]; (e != 0); (e = next[e])) {
      if ((to[e] != fa)) {
        Code06_Random1::dfs1(to[e], u);
      }
    }
  }
  static void push(int u, int f, int e) {
    (ufe[stacksize][0] = u);
    (ufe[stacksize][1] = f);
    (ufe[stacksize][2] = e);
    (stacksize++);
  }
  static void pop() {
    (--stacksize);
    (cur = ufe[stacksize][0]);
    (fath = ufe[stacksize][1]);
    (edge = ufe[stacksize][2]);
  }
  static void dfs2() {
    (stacksize = 0);
    Code06_Random1::push(1, 0, (-1));
    while ((stacksize > 0)) {
      Code06_Random1::pop();
      if ((edge == (-1))) {
        (dep[cur] = (dep[fath] + 1));
        (stjump[cur][0] = fath);
        for (int p = 1; (p < MAXP); (p++)) {
          (stjump[cur][p] = stjump[stjump[cur][(p - 1)]][(p - 1)]);
        }
        (edge = head[cur]);
      } else {
        (edge = next[edge]);
      }
      if ((edge != 0)) {
        Code06_Random1::push(cur, fath, edge);
        if ((to[edge] != fath)) {
          Code06_Random1::push(to[edge], cur, (-1));
        }
      }
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
  static void query(int x, int xylca) {
    while (((kthMark[x] == 0) && (x != xylca))) {
      ans->setOne(arr[x]);
      (x = stjump[x][0]);
    }
    while (((up[x] > 0) && (dep[up[x]] > dep[xylca]))) {
      ans->or_method(downSet[kthMark[x]]);
      (x = up[x]);
    }
    while ((x != xylca)) {
      ans->setOne(arr[x]);
      (x = stjump[x][0]);
    }
  }
  static void updateAns(int x, int y) {
    int xylca = Code06_Random1::lca(x, y);
    Code06_Random1::query(x, xylca);
    Code06_Random1::query(y, xylca);
    ans->setOne(arr[xylca]);
  }
  static void prepare() {
    Code06_Random1::dfs2();
    int len = static_cast<int>(std::sqrt((n * 10)));
    (markNum = jdiv(((n + len) - 1), len));
    {
      int b = 1;
      int pick = {};
      for (; (b <= markNum); (b++)) {
        do {
          (pick = (static_cast<int>((j::random() * n)) + 1));
        } while (vis[pick]);
        (vis[pick] = true);
        (markNode[b] = pick);
        (kthMark[pick] = b);
      }
    }
    {
      int b = 1;
      int cur = {};
      for (; (b <= markNum); (b++)) {
        (downSet[b] = new BitSet());
        downSet[b]->setOne(arr[markNode[b]]);
        (cur = stjump[markNode[b]][0]);
        while ((cur != 0)) {
          if ((kthMark[cur] > 0)) {
            (up[markNode[b]] = cur);
            break;
          } else {
            downSet[b]->setOne(arr[cur]);
            (cur = stjump[cur][0]);
          }
        }
      }
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (m = in.nextInt());
    (f = in.nextInt());
    for (int i = 1; (i <= n); (i++)) {
      (arr[i] = in.nextInt());
    }
    {
      int i = 1;
      int u = {};
      int v = {};
      for (; (i < n); (i++)) {
        (u = in.nextInt());
        (v = in.nextInt());
        Code06_Random1::addEdge(u, v);
        Code06_Random1::addEdge(v, u);
      }
    }
    Code06_Random1::prepare();
    {
      int i = 1;
      int lastAns = 0;
      for (; (i <= m); (i++)) {
        ans->clear();
        (k = in.nextInt());
        {
          int j = 1;
          int x = {};
          int y = {};
          for (; (j <= k); (j++)) {
            (x = in.nextInt());
            (y = in.nextInt());
            if ((f > 0)) {
              (x = (x ^ lastAns));
              (y = (y ^ lastAns));
            }
            Code06_Random1::updateAns(x, y);
          }
        }
        int ans1 = ans->countOnes();
        int ans2 = ans->mex();
        out.println(((ans1 + String(u" ")) + ans2));
        (lastAns = (ans1 + ans2));
      }
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code06_Random1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 树上分块模版题，随机撒点，java版
// 一共有n个节点，每个节点有点权，给定n-1条边，所有节点连成一棵树
// 接下来有m条操作，每条操作都要打印两个答案，描述如下
// 操作 k x1 y1 x2 y2 .. (一共k个点对)
// 每个点对(x, y)，在树上都有从x到y的路径，那么k个点对就有k条路径
// 先打印k条路径上不同点权的数量，再打印点权集合中没有出现的最小非负数(mex)
// 1 <= n、点对总数 <= 10^5    点权 <= 30000
// 题目要求强制在线，具体规则可以打开测试链接查看
// 测试链接 : https://www.luogu.com.cn/problem/P3603
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 链式前向星
        // 树上倍增，就只是为了快速求出LCA
        // 随机撒点
        // markNum表示关键点数量
        // vis[i]表示i号节点是否已经是关键点
        // markNode[k] = i 表示第k个关键点是编号为i的节点
        // kthMark[i] = k 表示i号节点是第k个关键点，kthMark[i] = 0
表示i号节点是非关键点
        // up[i] = j，表示i号节点是关键点，它往上跳到最近的关键点是j号节点
        // downSet[k]的含义，路径是[第k个的关键点 ..
最近的上方关键点)，沿途所有节点值组成的位图
        // 树上倍增递归版
        // 树上倍增迭代版，讲解118进行了详细讲述
        // 读写工具类
*/

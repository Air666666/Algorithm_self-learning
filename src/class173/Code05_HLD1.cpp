// Source: src/class173/Code05_HLD1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code05_HLD1 {
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
    int getOnes() {
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
  inline static int n = {};
  inline static int m = {};
  inline static int f = {};
  inline static int k = {};
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> next = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> to = make_array<int>(jshl(MAXN, 1));
  inline static int cntg = 0;
  inline static Array<int> fa = make_array<int>(MAXN);
  inline static Array<int> dep = make_array<int>(MAXN);
  inline static Array<int> siz = make_array<int>(MAXN);
  inline static Array<int> son = make_array<int>(MAXN);
  inline static Array<int> top = make_array<int>(MAXN);
  inline static Array<int> dfn = make_array<int>(MAXN);
  inline static Array<int> val = make_array<int>(MAXN);
  inline static int cntd = 0;
  inline static int blen = {};
  inline static int bnum = {};
  inline static Array<int> bi = make_array<int>(MAXN);
  inline static Array<int> bl = make_array<int>(MAXB);
  inline static Array<int> br = make_array<int>(MAXB);
  inline static Array<BitSet *> bitSet = make_array<BitSet *>(MAXB);
  inline static BitSet *ans = new BitSet();
  inline static Array<Array<int>> fse = make_array<int>(MAXN, 3);
  inline static int stacksize = {};
  inline static int first = {};
  inline static int second = {};
  inline static int edge = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code05_HLD1() {}
  static void addEdge(int u, int v) {
    (next[(++cntg)] = head[u]);
    (to[cntg] = v);
    (head[u] = cntg);
  }
  static void dfs1(int u, int f) {
    (fa[u] = f);
    (dep[u] = (dep[f] + 1));
    (siz[u] = 1);
    {
      int e = head[u];
      int v = {};
      for (; (e > 0); (e = next[e])) {
        (v = to[e]);
        if ((v != f)) {
          Code05_HLD1::dfs1(v, u);
        }
      }
    }
    {
      int e = head[u];
      int v = {};
      for (; (e > 0); (e = next[e])) {
        (v = to[e]);
        if ((v != f)) {
          (siz[u] += siz[v]);
          if (((son[u] == 0) || (siz[son[u]] < siz[v]))) {
            (son[u] = v);
          }
        }
      }
    }
  }
  static void dfs2(int u, int t) {
    (top[u] = t);
    (dfn[u] = (++cntd));
    (val[cntd] = arr[u]);
    if ((son[u] == 0)) {
      return;
    }
    Code05_HLD1::dfs2(son[u], t);
    {
      int e = head[u];
      int v = {};
      for (; (e > 0); (e = next[e])) {
        (v = to[e]);
        if (((v != fa[u]) && (v != son[u]))) {
          Code05_HLD1::dfs2(v, v);
        }
      }
    }
  }
  static void push(int fir, int sec, int edg) {
    (fse[stacksize][0] = fir);
    (fse[stacksize][1] = sec);
    (fse[stacksize][2] = edg);
    (stacksize++);
  }
  static void pop() {
    (--stacksize);
    (first = fse[stacksize][0]);
    (second = fse[stacksize][1]);
    (edge = fse[stacksize][2]);
  }
  static void dfs3() {
    (stacksize = 0);
    Code05_HLD1::push(1, 0, (-1));
    while ((stacksize > 0)) {
      Code05_HLD1::pop();
      if ((edge == (-1))) {
        (fa[first] = second);
        (dep[first] = (dep[second] + 1));
        (siz[first] = 1);
        (edge = head[first]);
      } else {
        (edge = next[edge]);
      }
      if ((edge != 0)) {
        Code05_HLD1::push(first, second, edge);
        if ((to[edge] != second)) {
          Code05_HLD1::push(to[edge], first, (-1));
        }
      } else {
        {
          int e = head[first];
          int v = {};
          for (; (e > 0); (e = next[e])) {
            (v = to[e]);
            if ((v != second)) {
              (siz[first] += siz[v]);
              if (((son[first] == 0) || (siz[son[first]] < siz[v]))) {
                (son[first] = v);
              }
            }
          }
        }
      }
    }
  }
  static void dfs4() {
    (stacksize = 0);
    Code05_HLD1::push(1, 1, (-1));
    while ((stacksize > 0)) {
      Code05_HLD1::pop();
      if ((edge == (-1))) {
        (top[first] = second);
        (dfn[first] = (++cntd));
        (val[cntd] = arr[first]);
        if ((son[first] == 0)) {
          continue;
        }
        Code05_HLD1::push(first, second, (-2));
        Code05_HLD1::push(son[first], second, (-1));
        continue;
      } else if ((edge == (-2))) {
        (edge = head[first]);
      } else {
        (edge = next[edge]);
      }
      if ((edge != 0)) {
        Code05_HLD1::push(first, second, edge);
        if (((to[edge] != fa[first]) && (to[edge] != son[first]))) {
          Code05_HLD1::push(to[edge], to[edge], (-1));
        }
      }
    }
  }
  static void query(int l, int r) {
    if ((bi[l] == bi[r])) {
      for (int i = l; (i <= r); (i++)) {
        ans->setOne(val[i]);
      }
    } else {
      for (int i = l; (i <= br[bi[l]]); (i++)) {
        ans->setOne(val[i]);
      }
      for (int i = bl[bi[r]]; (i <= r); (i++)) {
        ans->setOne(val[i]);
      }
      for (int i = (bi[l] + 1); (i <= (bi[r] - 1)); (i++)) {
        ans->or_method(bitSet[i]);
      }
    }
  }
  static void updateAns(int x, int y) {
    while ((top[x] != top[y])) {
      if ((dep[top[x]] < dep[top[y]])) {
        int tmp = x;
        (x = y);
        (y = tmp);
      }
      Code05_HLD1::query(dfn[top[x]], dfn[x]);
      (x = fa[top[x]]);
    }
    [&]() {
      auto jargument_0 = jmin(dfn[x], dfn[y]);
      auto jargument_1 = jmax(dfn[x], dfn[y]);
      return Code05_HLD1::query(jargument_0, jargument_1);
    }();
  }
  static void prepare() {
    Code05_HLD1::dfs3();
    Code05_HLD1::dfs4();
    (blen = static_cast<int>(std::sqrt((n * 20))));
    (bnum = jdiv(((n + blen) - 1), blen));
    for (int i = 1; (i <= n); (i++)) {
      (bi[i] = (jdiv((i - 1), blen) + 1));
    }
    for (int i = 1; (i <= bnum); (i++)) {
      (bl[i] = (((i - 1) * blen) + 1));
      (br[i] = jmin((i * blen), n));
      (bitSet[i] = new BitSet());
      for (int j = bl[i]; (j <= br[i]); (j++)) {
        bitSet[i]->setOne(val[j]);
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
        Code05_HLD1::addEdge(u, v);
        Code05_HLD1::addEdge(v, u);
      }
    }
    Code05_HLD1::prepare();
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
            Code05_HLD1::updateAns(x, y);
          }
        }
        int ans1 = ans->getOnes();
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
  Code05_HLD1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 树上分块模版题，重链序列分块，java版
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
        // 重链剖分
        // 分块
        // 不会改迭代版，去看讲解118，详解了从递归版改迭代版
        // dfs1的迭代版
        // dfs2的迭代版
        // 读写工具类
*/

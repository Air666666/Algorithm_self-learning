// Source: src/class185/Code06_ChengDu1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code06_ChengDu1 {
  inline static int MAXN = 100001;
  inline static int n = {};
  inline static int m = {};
  inline static Array<int> color = make_array<int>(MAXN);
  inline static Array<int> headg = make_array<int>(MAXN);
  inline static Array<int> nxtg = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> tog = make_array<int>(jshl(MAXN, 1));
  inline static int cntg = {};
  inline static Array<int> headq = make_array<int>(MAXN);
  inline static Array<int> nxtq = make_array<int>(MAXN);
  inline static Array<int> ql = make_array<int>(MAXN);
  inline static Array<int> qr = make_array<int>(MAXN);
  inline static Array<int> qid = make_array<int>(MAXN);
  inline static int cntq = {};
  inline static Array<bool> vis = make_array<bool>(MAXN);
  inline static Array<int> siz = make_array<int>(MAXN);
  inline static Array<int> nodel = make_array<int>(MAXN);
  inline static Array<int> noder = make_array<int>(MAXN);
  inline static Array<int> ncolor = make_array<int>(MAXN);
  inline static int cntNode = {};
  inline static Array<int> quesl = make_array<int>(MAXN);
  inline static Array<int> quesr = make_array<int>(MAXN);
  inline static Array<int> quesid = make_array<int>(MAXN);
  inline static int cntQues = {};
  inline static Array<int> pos = make_array<int>(MAXN);
  inline static Array<int> tree = make_array<int>(MAXN);
  inline static Array<int> ans = make_array<int>(MAXN);
  inline static Array<Array<int>> stack = make_array<int>(MAXN, 5);
  inline static int u = {};
  inline static int f = {};
  inline static int nl = {};
  inline static int nr = {};
  inline static int e = {};
  inline static int stacksize = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code06_ChengDu1() {}
  static void push(int u, int f, int nl, int nr, int e) {
    (stack[stacksize][0] = u);
    (stack[stacksize][1] = f);
    (stack[stacksize][2] = nl);
    (stack[stacksize][3] = nr);
    (stack[stacksize][4] = e);
    (stacksize++);
  }
  static void pop() {
    (--stacksize);
    (u = stack[stacksize][0]);
    (f = stack[stacksize][1]);
    (nl = stack[stacksize][2]);
    (nr = stack[stacksize][3]);
    (e = stack[stacksize][4]);
  }
  static void addEdge(int u, int v) {
    (nxtg[(++cntg)] = headg[u]);
    (tog[cntg] = v);
    (headg[u] = cntg);
  }
  static void addQuery(int u, int l, int r, int id) {
    (nxtq[(++cntq)] = headq[u]);
    (ql[cntq] = l);
    (qr[cntq] = r);
    (qid[cntq] = id);
    (headq[u] = cntq);
  }
  static int lowbit(int i) { return (i & (-i)); }
  static void add(int i, int v) {
    if ((i <= 0)) {
      return;
    }
    while ((i <= n)) {
      (tree[i] += v);
      (i += Code06_ChengDu1::lowbit(i));
    }
  }
  static int sum(int i) {
    int ret = 0;
    while ((i > 0)) {
      (ret += tree[i]);
      (i -= Code06_ChengDu1::lowbit(i));
    }
    return ret;
  }
  static int query(int l, int r) {
    return [&]() {
      auto jleft = Code06_ChengDu1::sum(r);
      auto jright = Code06_ChengDu1::sum((l - 1));
      return (jleft - jright);
    }();
  }
  static void getSize1(int u, int fa) {
    (siz[u] = 1);
    for (int e = headg[u]; (e > 0); (e = nxtg[e])) {
      int v = tog[e];
      if (((v != fa) && (!vis[v]))) {
        Code06_ChengDu1::getSize1(v, u);
        (siz[u] += siz[v]);
      }
    }
  }
  static void getSize2(int cur, int fa) {
    (stacksize = 0);
    Code06_ChengDu1::push(cur, fa, 0, 0, (-1));
    while ((stacksize > 0)) {
      Code06_ChengDu1::pop();
      if ((e == (-1))) {
        (siz[u] = 1);
        (e = headg[u]);
      } else {
        (e = nxtg[e]);
      }
      if ((e != 0)) {
        Code06_ChengDu1::push(u, f, 0, 0, e);
        int v = tog[e];
        if (((v != f) && (!vis[v]))) {
          Code06_ChengDu1::push(v, u, 0, 0, (-1));
        }
      } else {
        for (int ei = headg[u]; (ei > 0); (ei = nxtg[ei])) {
          int v = tog[ei];
          if (((v != f) && (!vis[v]))) {
            (siz[u] += siz[v]);
          }
        }
      }
    }
  }
  static int getCentroid(int u, int fa) {
    Code06_ChengDu1::getSize2(u, fa);
    int half = jshr(siz[u], 1);
    bool find = false;
    while ((!find)) {
      (find = true);
      for (int e = headg[u]; (e > 0); (e = nxtg[e])) {
        int v = tog[e];
        if ((((v != fa) && (!vis[v])) && (siz[v] > half))) {
          (fa = u);
          (u = v);
          (find = false);
          break;
        }
      }
    }
    return u;
  }
  static void dfs1(int u, int fa, int nl, int nr) {
    (nodel[(++cntNode)] = nl);
    (noder[cntNode] = nr);
    (ncolor[cntNode] = color[u]);
    for (int ei = headq[u]; (ei > 0); (ei = nxtq[ei])) {
      if (((ql[ei] <= nl) && (nr <= qr[ei]))) {
        (quesl[(++cntQues)] = ql[ei]);
        (quesr[cntQues] = qr[ei]);
        (quesid[cntQues] = qid[ei]);
      }
    }
    for (int e = headg[u]; (e > 0); (e = nxtg[e])) {
      int v = tog[e];
      if (((v != fa) && (!vis[v]))) {
        [&]() {
          auto jargument_0 = v;
          auto jargument_1 = u;
          auto jargument_2 = jmin(v, nl);
          auto jargument_3 = jmax(v, nr);
          return Code06_ChengDu1::dfs1(jargument_0, jargument_1, jargument_2,
                                       jargument_3);
        }();
      }
    }
  }
  static void dfs2(int cur, int fa, int nodeMin, int nodeMax) {
    (stacksize = 0);
    Code06_ChengDu1::push(cur, fa, nodeMin, nodeMax, (-1));
    while ((stacksize > 0)) {
      Code06_ChengDu1::pop();
      if ((e == (-1))) {
        (nodel[(++cntNode)] = nl);
        (noder[cntNode] = nr);
        (ncolor[cntNode] = color[u]);
        for (int ei = headq[u]; (ei > 0); (ei = nxtq[ei])) {
          if (((ql[ei] <= nl) && (nr <= qr[ei]))) {
            (quesl[(++cntQues)] = ql[ei]);
            (quesr[cntQues] = qr[ei]);
            (quesid[cntQues] = qid[ei]);
          }
        }
        (e = headg[u]);
      } else {
        (e = nxtg[e]);
      }
      if ((e != 0)) {
        Code06_ChengDu1::push(u, f, nl, nr, e);
        int v = tog[e];
        if (((v != f) && (!vis[v]))) {
          [&]() {
            auto jargument_0 = v;
            auto jargument_1 = u;
            auto jargument_2 = jmin(v, nl);
            auto jargument_3 = jmax(v, nr);
            auto jargument_4 = (-1);
            return Code06_ChengDu1::push(jargument_0, jargument_1, jargument_2,
                                         jargument_3, jargument_4);
          }();
        }
      }
    }
  }
  static void sort(Array<int> al, Array<int> ar, Array<int> ai, int l, int r) {
    if ((l >= r))
      return;
    int i = l;
    int j = r;
    int pivot = ar[jshr((l + r), 1)];
    int tmp = {};
    while ((i <= j)) {
      while ((ar[i] < pivot))
        (i++);
      while ((ar[j] > pivot))
        (j--);
      if ((i <= j)) {
        (tmp = al[i]);
        (al[i] = al[j]);
        (al[j] = tmp);
        (tmp = ar[i]);
        (ar[i] = ar[j]);
        (ar[j] = tmp);
        (tmp = ai[i]);
        (ai[i] = ai[j]);
        (ai[j] = tmp);
        (i++);
        (j--);
      }
    }
    Code06_ChengDu1::sort(al, ar, ai, l, j);
    Code06_ChengDu1::sort(al, ar, ai, i, r);
  }
  static void calc(int u) {
    (cntNode = 0);
    (cntQues = 0);
    Code06_ChengDu1::dfs2(u, 0, u, u);
    Code06_ChengDu1::sort(nodel, noder, ncolor, 1, cntNode);
    Code06_ChengDu1::sort(quesl, quesr, quesid, 1, cntQues);
    {
      int i = 1;
      int j = 1;
      for (; (i <= cntQues); (i++)) {
        while (((j <= cntNode) && (noder[j] <= quesr[i]))) {
          if ((nodel[j] > pos[ncolor[j]])) {
            Code06_ChengDu1::add(pos[ncolor[j]], (-1));
            (pos[ncolor[j]] = nodel[j]);
            Code06_ChengDu1::add(pos[ncolor[j]], 1);
          }
          (j++);
        }
        (ans[quesid[i]] =
             jmax(ans[quesid[i]], Code06_ChengDu1::query(quesl[i], n)));
      }
    }
    for (int i = 1; (i <= cntNode); (i++)) {
      Code06_ChengDu1::add(pos[ncolor[i]], (-1));
      (pos[ncolor[i]] = 0);
    }
  }
  static void solve(int u) {
    (vis[u] = true);
    Code06_ChengDu1::calc(u);
    for (int e = headg[u]; (e > 0); (e = nxtg[e])) {
      int v = tog[e];
      if ((!vis[v])) {
        Code06_ChengDu1::solve(Code06_ChengDu1::getCentroid(v, u));
      }
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (m = in.nextInt());
    for (int i = 1; (i <= n); (i++)) {
      (color[i] = in.nextInt());
    }
    {
      int i = 1;
      int u = {};
      int v = {};
      for (; (i < n); (i++)) {
        (u = in.nextInt());
        (v = in.nextInt());
        Code06_ChengDu1::addEdge(u, v);
        Code06_ChengDu1::addEdge(v, u);
      }
    }
    {
      int i = 1;
      int l = {};
      int r = {};
      int x = {};
      for (; (i <= m); (i++)) {
        (l = in.nextInt());
        (r = in.nextInt());
        (x = in.nextInt());
        Code06_ChengDu1::addQuery(x, l, r, i);
      }
    }
    Code06_ChengDu1::solve(Code06_ChengDu1::getCentroid(1, 0));
    for (int i = 1; (i <= m); (i++)) {
      out.println(ans[i]);
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code06_ChengDu1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 成都七中，java版
// 树上有n个点，每个点给定颜色，给定n-1条边
// 一共m条查询，查询之间不会相互影响，格式如下
// 查询 l r x : 只保留编号在[l, r]的节点，打印点x所在连通块的颜色数量
// 1 <= 所有数据 <= 10^5
// 测试链接 : https://www.luogu.com.cn/problem/P5311
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 建树
        // 每个节点的问题列表
        // 点分治
        //
每来到一个重心，收集节点列表，nodel和noder是解锁条件，ncolor是节点颜色
        // 每来到一个重心，收集问题列表，只收集值得讨论的问题
        // pos[v] = i，表示颜色v的左边界，最右位置出现在i
        // 树状数组
        // 问题答案
        // 讲解118，递归函数改成迭代所需要的栈
        // 找重心需要计算子树大小的递归版，java会爆栈，C++不会
        // getSize1的迭代版
                // getSize1(u, fa);
        // dfs1的迭代版
                // dfs1(u, 0, u, u);
        // 读写工具类
*/

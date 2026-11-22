// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P7477

// Source: src/class198/Code05_Partition_Multiset_java_1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code05_Partition_Multiset_java_1 {
  inline static int MAXN = 20001;
  inline static int MAXM = 20001;
  inline static int MAXT = 1000001;
  inline static int MAXE = 2000001;
  inline static int n = {};
  inline static int m = {};
  inline static int cntt = {};
  inline static Array<int> v = make_array<int>(MAXN);
  inline static Array<int> x = make_array<int>(MAXM);
  inline static Array<int> y = make_array<int>(MAXM);
  inline static Array<int> rak = make_array<int>(MAXN);
  inline static Array<Array<int>> arr = make_array<int>(MAXN, 2);
  inline static Array<int> head = make_array<int>(MAXT);
  inline static Array<int> nxt = make_array<int>(MAXE);
  inline static Array<int> to = make_array<int>(MAXE);
  inline static int cntg = {};
  inline static Array<int> dfn = make_array<int>(MAXT);
  inline static Array<int> low = make_array<int>(MAXT);
  inline static int cntd = {};
  inline static Array<int> sta = make_array<int>(MAXT);
  inline static int top = {};
  inline static Array<int> belong = make_array<int>(MAXT);
  inline static int sccCnt = {};
  inline static Array<int> outTree1 = make_array<int>(MAXN);
  inline static Array<int> inTree1 = make_array<int>(MAXN);
  inline static Array<int> outTree2 = make_array<int>(MAXN);
  inline static Array<int> inTree2 = make_array<int>(MAXN);
  inline static Array<int> stau = make_array<int>(MAXT);
  inline static Array<int> stas = make_array<int>(MAXT);
  inline static Array<int> stae = make_array<int>(MAXT);
  inline static int u = {};
  inline static int status = {};
  inline static int e = {};
  inline static int stacksize = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code05_Partition_Multiset_java_1() {}
  static void push(int u, int status, int e) {
    (stau[stacksize] = u);
    (stas[stacksize] = status);
    (stae[stacksize] = e);
    (stacksize++);
  }
  static void pop() {
    (stacksize--);
    (u = stau[stacksize]);
    (status = stas[stacksize]);
    (e = stae[stacksize]);
  }
  static int small(int num) {
    int l = 1;
    int r = n;
    int mid = {};
    int ans = 0;
    while ((l <= r)) {
      (mid = jshr((l + r), 1));
      if ((arr[mid][0] <= num)) {
        (ans = mid);
        (l = (mid + 1));
      } else {
        (r = (mid - 1));
      }
    }
    return ans;
  }
  static int big(int num) {
    int l = 1;
    int r = n;
    int mid = {};
    int ans = (n + 1);
    while ((l <= r)) {
      (mid = jshr((l + r), 1));
      if ((arr[mid][0] >= num)) {
        (ans = mid);
        (r = (mid - 1));
      } else {
        (l = (mid + 1));
      }
    }
    return ((n - ans) + 1);
  }
  static void addEdge(int u, int v) {
    (nxt[(++cntg)] = head[u]);
    (to[cntg] = v);
    (head[u] = cntg);
  }
  static void tarjan1(int u) {
    (dfn[u] = (low[u] = (++cntd)));
    (sta[(++top)] = u);
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      int v = to[e];
      if ((dfn[v] == 0)) {
        Code05_Partition_Multiset_java_1::tarjan1(v);
        (low[u] = jmin(low[u], low[v]));
      } else {
        if ((belong[v] == 0)) {
          (low[u] = jmin(low[u], dfn[v]));
        }
      }
    }
    if ((dfn[u] == low[u])) {
      (sccCnt++);
      int pop = {};
      do {
        (pop = sta[(top--)]);
        (belong[pop] = sccCnt);
      } while ((pop != u));
    }
  }
  static void tarjan2(int node) {
    (stacksize = 0);
    Code05_Partition_Multiset_java_1::push(node, (-1), (-1));
    int v = {};
    while ((stacksize > 0)) {
      Code05_Partition_Multiset_java_1::pop();
      if ((status == (-1))) {
        (dfn[u] = (low[u] = (++cntd)));
        (sta[(++top)] = u);
        (e = head[u]);
      } else {
        (v = to[e]);
        if ((status == 0)) {
          (low[u] = jmin(low[u], low[v]));
        }
        if (((status == 1) && (belong[v] == 0))) {
          (low[u] = jmin(low[u], dfn[v]));
        }
        (e = nxt[e]);
      }
      if ((e != 0)) {
        (v = to[e]);
        if ((dfn[v] == 0)) {
          Code05_Partition_Multiset_java_1::push(u, 0, e);
          Code05_Partition_Multiset_java_1::push(v, (-1), (-1));
        } else {
          Code05_Partition_Multiset_java_1::push(u, 1, e);
        }
      } else {
        if ((dfn[u] == low[u])) {
          (sccCnt++);
          int pop = {};
          do {
            (pop = sta[(top--)]);
            (belong[pop] = sccCnt);
          } while ((pop != u));
        }
      }
    }
  }
  static int lowbit(int i) { return (i & (-i)); }
  static void addOut(Array<int> outTree, int i, int x) {
    while ((i <= n)) {
      int preo = outTree[i];
      int curo = (++cntt);
      if ((preo > 0)) {
        Code05_Partition_Multiset_java_1::addEdge(preo, curo);
      }
      Code05_Partition_Multiset_java_1::addEdge(x, curo);
      (outTree[i] = curo);
      (i += Code05_Partition_Multiset_java_1::lowbit(i));
    }
  }
  static void addIn(Array<int> inTree, int i, int x) {
    while ((i <= n)) {
      int prei = inTree[i];
      int curi = (++cntt);
      if ((prei > 0)) {
        Code05_Partition_Multiset_java_1::addEdge(curi, prei);
      }
      Code05_Partition_Multiset_java_1::addEdge(curi, x);
      (inTree[i] = curi);
      (i += Code05_Partition_Multiset_java_1::lowbit(i));
    }
  }
  static void rangeToX(Array<int> outTree, int i, int x) {
    while ((i > 0)) {
      if ((outTree[i] > 0)) {
        Code05_Partition_Multiset_java_1::addEdge(outTree[i], x);
      }
      (i -= Code05_Partition_Multiset_java_1::lowbit(i));
    }
  }
  static void xToRange(Array<int> inTree, int x, int i) {
    while ((i > 0)) {
      if ((inTree[i] > 0)) {
        Code05_Partition_Multiset_java_1::addEdge(x, inTree[i]);
      }
      (i -= Code05_Partition_Multiset_java_1::lowbit(i));
    }
  }
  static void add(int x, int otherx, int si, int bi) {
    Code05_Partition_Multiset_java_1::addOut(outTree1, si, x);
    Code05_Partition_Multiset_java_1::addIn(inTree1, si, otherx);
    Code05_Partition_Multiset_java_1::addOut(outTree2, bi, otherx);
    Code05_Partition_Multiset_java_1::addIn(inTree2, bi, x);
  }
  static void link(int x, int otherx, int lowCnt, int highCnt) {
    Code05_Partition_Multiset_java_1::xToRange(inTree1, x, lowCnt);
    Code05_Partition_Multiset_java_1::rangeToX(outTree1, lowCnt, otherx);
    Code05_Partition_Multiset_java_1::xToRange(inTree2, otherx, highCnt);
    Code05_Partition_Multiset_java_1::rangeToX(outTree2, highCnt, x);
  }
  static int other(int x) { return ((x <= n) ? (x + n) : (x - n)); }
  static void buildGraph(int k) {
    (cntt = jshl(n, 1));
    for (int i = 1; (i <= m); (i++)) {
      Code05_Partition_Multiset_java_1::addEdge(
          x[i], Code05_Partition_Multiset_java_1::other(y[i]));
      Code05_Partition_Multiset_java_1::addEdge(
          y[i], Code05_Partition_Multiset_java_1::other(x[i]));
      Code05_Partition_Multiset_java_1::addEdge(
          Code05_Partition_Multiset_java_1::other(x[i]), y[i]);
      Code05_Partition_Multiset_java_1::addEdge(
          Code05_Partition_Multiset_java_1::other(y[i]), x[i]);
    }
    for (int i = 1; (i <= n); (i++)) {
      [&]() {
        auto jargument_0 = i;
        auto jargument_1 = Code05_Partition_Multiset_java_1::other(i);
        auto jargument_2 = Code05_Partition_Multiset_java_1::small((v[i] - k));
        auto jargument_3 = Code05_Partition_Multiset_java_1::big((v[i] + k));
        return Code05_Partition_Multiset_java_1::link(jargument_0, jargument_1,
                                                      jargument_2, jargument_3);
      }();
      Code05_Partition_Multiset_java_1::add(
          i, Code05_Partition_Multiset_java_1::other(i), rak[i],
          ((n - rak[i]) + 1));
    }
  }
  static void clear() {
    for (int i = 1; (i <= cntt); (i++)) {
      (head[i] = (dfn[i] = (belong[i] = 0)));
    }
    for (int i = 1; (i <= n); (i++)) {
      (inTree1[i] = (outTree1[i] = (inTree2[i] = (outTree2[i] = 0))));
    }
    (cntt = (cntg = (cntd = (top = (sccCnt = 0)))));
  }
  static bool check(int k) {
    Code05_Partition_Multiset_java_1::buildGraph(k);
    for (int i = 1; (i <= jshl(n, 1)); (i++)) {
      if ((dfn[i] == 0)) {
        Code05_Partition_Multiset_java_1::tarjan2(i);
      }
    }
    bool check = true;
    for (int i = 1; (i <= n); (i++)) {
      if ((belong[i] == belong[(i + n)])) {
        (check = false);
        break;
      }
    }
    Code05_Partition_Multiset_java_1::clear();
    return check;
  }
  static int compute() {
    for (int i = 1; (i <= n); (i++)) {
      (arr[i][0] = v[i]);
      (arr[i][1] = i);
    }
    j::sort(arr, 1, (n + 1), [=](Array<int> a, Array<int> b) {
      return ((a[0] != b[0]) ? (a[0] - b[0]) : (a[1] - b[1]));
    });
    for (int i = 1; (i <= n); (i++)) {
      (rak[arr[i][1]] = i);
    }
    int l = 0;
    int r = arr[n][0];
    int mid = {};
    int ans = (-1);
    while ((l <= r)) {
      (mid = jshr((l + r), 1));
      if (Code05_Partition_Multiset_java_1::check(mid)) {
        (ans = mid);
        (r = (mid - 1));
      } else {
        (l = (mid + 1));
      }
    }
    return ans;
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (m = in.nextInt());
    for (int i = 1; (i <= n); (i++)) {
      (v[i] = in.nextInt());
    }
    for (int i = 1; (i <= m); (i++)) {
      (x[i] = in.nextInt());
      (y[i] = in.nextInt());
    }
    int ans = Code05_Partition_Multiset_java_1::compute();
    out.println(ans);
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code05_Partition_Multiset_java_1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 划分可重集，树状数组优化建图，java版
// 给定长度为n的数组arr，从左到右把每个数划分进可重集a、b
// 每个数至少要进入a或b中的一个
// arr[i]能进集合a的条件为，i左侧任何 <= arr[i] - k的数字，都没进集合a
// arr[i]能进集合b的条件为，i左侧任何 >= arr[i] + k的数字，都没进集合b
// 然后有m组关系，每组 x y，保证 x < y，表示两个位置的数不能进入同一个集合
// 如果不存在合法划分，打印-1，如果存在方案，打印能划分成功的最小k值
// n、m <= 2 * 10^4
// arr[i] <= 10^9
// 测试链接 : https://www.luogu.com.cn/problem/P7477
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 树状数组
        // 迭代版需要的栈，讲解118讲了递归改迭代的技巧
        // <= num的范围长度
        // >= num的范围长度
        // 递归版
        // 迭代版
                                // tarjan1(i);
        // 读写工具类
*/

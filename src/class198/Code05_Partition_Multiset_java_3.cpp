// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P7477

// Source: src/class198/Code05_Partition_Multiset_java_3.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code05_Partition_Multiset_java_3 {
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
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static Array<int> tmp = make_array<int>(MAXN);
  inline static Array<int> stau = make_array<int>(MAXT);
  inline static Array<int> stas = make_array<int>(MAXT);
  inline static Array<int> stae = make_array<int>(MAXT);
  inline static int u = {};
  inline static int status = {};
  inline static int e = {};
  inline static int stacksize = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code05_Partition_Multiset_java_3() {}
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
        Code05_Partition_Multiset_java_3::tarjan1(v);
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
    Code05_Partition_Multiset_java_3::push(node, (-1), (-1));
    int v = {};
    while ((stacksize > 0)) {
      Code05_Partition_Multiset_java_3::pop();
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
          Code05_Partition_Multiset_java_3::push(u, 0, e);
          Code05_Partition_Multiset_java_3::push(v, (-1), (-1));
        } else {
          Code05_Partition_Multiset_java_3::push(u, 1, e);
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
  static int other(int x) { return ((x <= n) ? (x + n) : (x - n)); }
  static void merge(int l, int mid, int r, int k) {
    int preOut = 0;
    int curOut = 0;
    int preIn = 0;
    int curIn = 0;
    {
      int p1 = (l - 1);
      int p2 = (mid + 1);
      for (; (p2 <= r); (p2++)) {
        (curOut = (++cntt));
        (curIn = (++cntt));
        while ((((p1 + 1) <= mid) && (v[arr[(p1 + 1)]] <= (v[arr[p2]] - k)))) {
          (p1++);
          Code05_Partition_Multiset_java_3::addEdge(arr[p1], curOut);
          Code05_Partition_Multiset_java_3::addEdge(
              curIn, Code05_Partition_Multiset_java_3::other(arr[p1]));
        }
        if ((preOut > 0)) {
          Code05_Partition_Multiset_java_3::addEdge(preOut, curOut);
          Code05_Partition_Multiset_java_3::addEdge(curIn, preIn);
        }
        Code05_Partition_Multiset_java_3::addEdge(
            curOut, Code05_Partition_Multiset_java_3::other(arr[p2]));
        Code05_Partition_Multiset_java_3::addEdge(arr[p2], curIn);
        (preOut = curOut);
        (preIn = curIn);
      }
    }
    (preOut = (curOut = (preIn = (curIn = 0))));
    {
      int p1 = (mid + 1);
      int p2 = r;
      for (; (p2 >= (mid + 1)); (p2--)) {
        (curOut = (++cntt));
        (curIn = (++cntt));
        while ((((p1 - 1) >= l) && (v[arr[(p1 - 1)]] >= (v[arr[p2]] + k)))) {
          (p1--);
          Code05_Partition_Multiset_java_3::addEdge(
              Code05_Partition_Multiset_java_3::other(arr[p1]), curOut);
          Code05_Partition_Multiset_java_3::addEdge(curIn, arr[p1]);
        }
        if ((preOut > 0)) {
          Code05_Partition_Multiset_java_3::addEdge(preOut, curOut);
          Code05_Partition_Multiset_java_3::addEdge(curIn, preIn);
        }
        Code05_Partition_Multiset_java_3::addEdge(curOut, arr[p2]);
        Code05_Partition_Multiset_java_3::addEdge(
            Code05_Partition_Multiset_java_3::other(arr[p2]), curIn);
        (preOut = curOut);
        (preIn = curIn);
      }
    }
    int p1 = l;
    int p2 = (mid + 1);
    int ti = 0;
    while (((p1 <= mid) && (p2 <= r))) {
      if ((v[arr[p1]] <= v[arr[p2]])) {
        (tmp[(++ti)] = arr[(p1++)]);
      } else {
        (tmp[(++ti)] = arr[(p2++)]);
      }
    }
    while ((p1 <= mid)) {
      (tmp[(++ti)] = arr[(p1++)]);
    }
    while ((p2 <= r)) {
      (tmp[(++ti)] = arr[(p2++)]);
    }
    {
      int i = l;
      int j = 1;
      for (; (i <= r); (i++), (j++)) {
        (arr[i] = tmp[j]);
      }
    }
  }
  static void cdq(int l, int r, int k) {
    if ((l == r)) {
      return;
    }
    int mid = jdiv((l + r), 2);
    Code05_Partition_Multiset_java_3::cdq(l, mid, k);
    Code05_Partition_Multiset_java_3::cdq((mid + 1), r, k);
    Code05_Partition_Multiset_java_3::merge(l, mid, r, k);
  }
  static void buildGraph(int k) {
    (cntt = jshl(n, 1));
    for (int i = 1; (i <= m); (i++)) {
      Code05_Partition_Multiset_java_3::addEdge(
          x[i], Code05_Partition_Multiset_java_3::other(y[i]));
      Code05_Partition_Multiset_java_3::addEdge(
          y[i], Code05_Partition_Multiset_java_3::other(x[i]));
      Code05_Partition_Multiset_java_3::addEdge(
          Code05_Partition_Multiset_java_3::other(x[i]), y[i]);
      Code05_Partition_Multiset_java_3::addEdge(
          Code05_Partition_Multiset_java_3::other(y[i]), x[i]);
    }
    for (int i = 1; (i <= n); (i++)) {
      (arr[i] = i);
    }
    Code05_Partition_Multiset_java_3::cdq(1, n, k);
  }
  static void clear() {
    for (int i = 1; (i <= cntt); (i++)) {
      (head[i] = (dfn[i] = (belong[i] = 0)));
    }
    (cntt = (cntg = (cntd = (top = (sccCnt = 0)))));
  }
  static bool check(int k) {
    Code05_Partition_Multiset_java_3::buildGraph(k);
    for (int i = 1; (i <= jshl(n, 1)); (i++)) {
      if ((dfn[i] == 0)) {
        Code05_Partition_Multiset_java_3::tarjan2(i);
      }
    }
    bool check = true;
    for (int i = 1; (i <= n); (i++)) {
      if ((belong[i] == belong[(i + n)])) {
        (check = false);
        break;
      }
    }
    Code05_Partition_Multiset_java_3::clear();
    return check;
  }
  static int compute() {
    int maxv = v[1];
    for (int i = 2; (i <= n); (i++)) {
      (maxv = jmax(maxv, v[i]));
    }
    int l = 0;
    int r = maxv;
    int mid = {};
    int ans = (-1);
    while ((l <= r)) {
      (mid = jshr((l + r), 1));
      if (Code05_Partition_Multiset_java_3::check(mid)) {
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
    int ans = Code05_Partition_Multiset_java_3::compute();
    out.println(ans);
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code05_Partition_Multiset_java_3::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 划分可重集，cdq优化建图，java版
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
        // cdq
        // 迭代版需要的栈，讲解118讲了递归改迭代的技巧
        // 递归版
        // 迭代版
                                // tarjan1(i);
        // 读写工具类
*/

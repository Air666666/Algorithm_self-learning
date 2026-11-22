// Source: src/class175/Code07_GivenTree1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code07_GivenTree1 {
  inline static int MAXN = 200001;
  inline static int n = {};
  inline static int blen = {};
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> next = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> to = make_array<int>(jshl(MAXN, 1));
  inline static int cntg = 0;
  inline static Array<int> fa = make_array<int>(MAXN);
  inline static Array<int> dfnOrder = make_array<int>(MAXN);
  inline static int cntd = 0;
  inline static Array<int> len = make_array<int>(MAXN);
  inline static Array<int> max1 = make_array<int>(MAXN);
  inline static Array<int> max2 = make_array<int>(MAXN);
  inline static Array<int> ans = make_array<int>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code07_GivenTree1() {}
  static void addEdge(int u, int v) {
    (next[(++cntg)] = head[u]);
    (to[cntg] = v);
    (head[u] = cntg);
  }
  static void dfs(int u, int f) {
    (fa[u] = f);
    (dfnOrder[(++cntd)] = u);
    for (int e = head[u]; (e > 0); (e = next[e])) {
      if ((to[e] != f)) {
        Code07_GivenTree1::dfs(to[e], u);
      }
    }
  }
  static int query(int k) {
    int cnt = 0;
    {
      int i = n;
      int cur = {};
      int father = {};
      for (; (i >= 1); (i--)) {
        (cur = dfnOrder[i]);
        (father = fa[cur]);
        if ((((max1[cur] + max2[cur]) + 1) >= k)) {
          (cnt++);
          (len[cur] = 0);
        } else {
          (len[cur] = (max1[cur] + 1));
        }
        if ((len[cur] > max1[father])) {
          (max2[father] = max1[father]);
          (max1[father] = len[cur]);
        } else if ((len[cur] > max2[father])) {
          (max2[father] = len[cur]);
        }
      }
    }
    for (int i = 1; (i <= n); (i++)) {
      (len[i] = (max1[i] = (max2[i] = 0)));
    }
    return cnt;
  }
  static int jump(int l, int r, int curAns) {
    int find = l;
    while ((l <= r)) {
      int mid = jshr((l + r), 1);
      int check = Code07_GivenTree1::query(mid);
      if ((check < curAns)) {
        (r = (mid - 1));
      } else if ((check > curAns)) {
        (l = (mid + 1));
      } else {
        (find = mid);
        (l = (mid + 1));
      }
    }
    return (find + 1);
  }
  static void compute() {
    for (int i = 1; (i <= blen); (i++)) {
      (ans[i] = Code07_GivenTree1::query(i));
    }
    for (int i = (blen + 1); (i <= n);
         (i = Code07_GivenTree1::jump(i, n, ans[i]))) {
      (ans[i] = Code07_GivenTree1::query(i));
    }
  }
  static void prepare() {
    int log2n = 0;
    while ((jshl(1, log2n) <= jshr(n, 1))) {
      (log2n++);
    }
    (blen = jmax(1, static_cast<int>(std::sqrt((n * log2n)))));
    j::fill(ans, 1, (n + 1), (-1));
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(jout);
    (n = in.nextInt());
    {
      int i = 1;
      int u = {};
      int v = {};
      for (; (i < n); (i++)) {
        (u = in.nextInt());
        (v = in.nextInt());
        Code07_GivenTree1::addEdge(u, v);
        Code07_GivenTree1::addEdge(v, u);
      }
    }
    Code07_GivenTree1::dfs(1, 0);
    Code07_GivenTree1::prepare();
    Code07_GivenTree1::compute();
    for (int i = 1; (i <= n); (i++)) {
      if ((ans[i] == (-1))) {
        (ans[i] = ans[(i - 1)]);
      }
      out.println(ans[i]);
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code07_GivenTree1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 给你一棵树，java版
// 一共有n个节点，给定n-1条边，所有节点连成一棵树
// 树的路径是指，从端点x到端点y的简单路径，k路径是指，路径的节点数正好为k
// 整棵树希望分解成尽量多的k路径，k路径的节点不能复用，所有k路径不要求包含所有点
// 打印k = 1, 2, 3..n时，k路径有最多有几条
// 测试链接 : https://www.luogu.com.cn/problem/CF1039D
// 测试链接 : https://codeforces.com/problemset/problem/1039/D
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // fa[i]表示，i节点的父节点编号
        // dfnOrder是根据dfn序，依次收集上来的节点编号
        // len[i]表示，当前i号节点只能往下走，没分配成路径的最长链的长度
        // max1[i]表示，最大值 { len[a], len[b], len[c] ...
}，其中a、b、c..是i的子节点
        // max2[i]表示，次大值 { len[a], len[b], len[c] ...
}，其中a、b、c..是i的子节点
        // 读写工具类
*/

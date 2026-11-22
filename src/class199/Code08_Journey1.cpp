// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P5022
// https://www.luogu.com.cn/problem/P5049

// Source: src/class199/Code08_Journey1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code08_Journey1 {
  inline static int MAXN = 500001;
  inline static int n = {};
  inline static int m = {};
  inline static Array<Array<int>> arr = make_array<int>(jshl(MAXN, 1), 2);
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> nxt = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> to = make_array<int>(jshl(MAXN, 1));
  inline static int cntg = {};
  inline static Array<int> dfn = make_array<int>(MAXN);
  inline static int cntd = {};
  inline static Array<int> from = make_array<int>(MAXN);
  inline static Array<bool> cycle = make_array<bool>(MAXN);
  inline static bool turn = {};
  inline static Array<bool> vis = make_array<bool>(MAXN);
  inline static Array<int> ans = make_array<int>(MAXN);
  inline static int cnta = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code08_Journey1() {}
  static void addEdge(int u, int v) {
    (nxt[(++cntg)] = head[u]);
    (to[cntg] = v);
    (head[u] = cntg);
  }
  static void dfs(int u) {
    (dfn[u] = (++cntd));
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      int v = to[e];
      if ((dfn[v] == 0)) {
        (from[v] = u);
        Code08_Journey1::dfs(v);
      } else if ((dfn[u] < dfn[v])) {
        (cycle[u] = true);
        for (int i = v; (i != u); (i = from[i])) {
          (cycle[i] = true);
        }
      }
    }
  }
  static void path(int u, int back) {
    (vis[u] = true);
    (ans[(++cnta)] = u);
    if (((!cycle[u]) || turn)) {
      for (int e = head[u]; (e > 0); (e = nxt[e])) {
        int v = to[e];
        if ((!vis[v])) {
          Code08_Journey1::path(v, (n + 1));
        }
      }
      return;
    }
    int end = 0;
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      int v = to[e];
      if ((!vis[v])) {
        (end = v);
      }
    }
    (turn = (cycle[end] && (end > back)));
    if (turn) {
      for (int e = head[u]; (e > 0); (e = nxt[e])) {
        int v = to[e];
        if (((!vis[v]) && (v != end))) {
          Code08_Journey1::path(v, (n + 1));
        }
      }
      return;
    }
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      int v = to[e];
      if ((!vis[v])) {
        if ((!cycle[v])) {
          Code08_Journey1::path(v, (n + 1));
        } else {
          int next = back;
          for (int ne = nxt[e]; (ne > 0); (ne = nxt[ne])) {
            int nv = to[ne];
            if ((!vis[nv])) {
              (next = nv);
              break;
            }
          }
          Code08_Journey1::path(v, next);
        }
      }
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (m = in.nextInt());
    {
      int i = 1;
      int u = {};
      int v = {};
      for (; (i <= m); (i++)) {
        (u = in.nextInt());
        (v = in.nextInt());
        (arr[i][0] = u);
        (arr[i][1] = v);
        (arr[(i + m)][0] = v);
        (arr[(i + m)][1] = u);
      }
    }
    j::sort(arr, 1, ((m * 2) + 1), [=](Array<int> a, Array<int> b) {
      return ((a[0] != b[0]) ? (a[0] - b[0]) : (b[1] - a[1]));
    });
    for (int i = 1; (i <= (m * 2)); (i++)) {
      Code08_Journey1::addEdge(arr[i][0], arr[i][1]);
    }
    Code08_Journey1::dfs(1);
    Code08_Journey1::path(1, (n + 1));
    for (int i = 1; (i <= n); (i++)) {
      out.print((ans[i] + String(u" ")));
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code08_Journey1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 旅行，java版
// 图中有n个点、m条无向边，节点编号1~n，图是普通树或者基环树
// 对于普通树，从1号节点开始，选择不同的遍历顺序，会形成不同的dfs序列
// 其中字典序最小的dfs序列，叫做普通树的答案
// 对于基环树，可以删掉环上的任何一条边，让基环树变成某棵普通树
// 众多普通树的答案中，字典序最小的结果，叫做基环树的答案
// 图如果是普通树，打印普通树的答案，图如果是基环树，打印基环树的答案
// 1 <= n <= 5 * 10^5
// 普通版测试 : https://www.luogu.com.cn/problem/P5022
// 加强版测试 : https://www.luogu.com.cn/problem/P5049
// 提交以下的code，提交时请把类名改成"Main"，可以通过普通版测试
// 加强版测试卡常数时间，java实现无法通过，索性递归函数也不改迭代了
// 想通过用C++实现，本节课Code08_Journey2文件就是C++的实现
// 两个版本的逻辑完全一样，C++版本可以通过所有测试
                        // u不在环上 或者 已经回过头了
                        // 那么像在树上遍历即可
                // u在环上 并且 还没回过头
                // 考察最后一个儿子是否符合回头需要
                        // 回头成功
                        // 无视最后一个儿子
                        // 因为会从环的另一侧到达
                        // 其他儿子像在树上遍历即可
                // 回头不成功
                                        // 当前儿子v不在环上
                                        // 像在树上遍历即可
                                        // 当前儿子v在环上
                                        // 设置好后续的back
                                        // 回头可能发生在后续的环上
                                        // 因为节点u最多两个环上的孩子
                                        // 所以如下for循环最多发生两次
                                        // 所以时间复杂度不会变高
        // 读写工具类
*/

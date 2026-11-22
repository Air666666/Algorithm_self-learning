// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P4878

// Source: src/class142/Code03_LayoutCow.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_LayoutCow {
  inline static int MAXN = 1001;
  inline static int MAXM = 20001;
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> next = make_array<int>(MAXM);
  inline static Array<int> to = make_array<int>(MAXM);
  inline static Array<int> weight = make_array<int>(MAXM);
  inline static int cnt = {};
  inline static Array<int> dist = make_array<int>(MAXN);
  inline static Array<int> update = make_array<int>(MAXN);
  inline static int MAXQ = 1000001;
  inline static Array<int> queue = make_array<int>(MAXQ);
  inline static int h = {};
  inline static int t = {};
  inline static Array<bool> enter = make_array<bool>(MAXN);
  inline static int n = {};
  inline static int m1 = {};
  inline static int m2 = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_LayoutCow() {}
  static void prepare() {
    (cnt = 1);
    j::fill(head, 0, (n + 1), 0);
  }
  static void addEdge(int u, int v, int w) {
    (next[cnt] = head[u]);
    (to[cnt] = v);
    (weight[cnt] = w);
    (head[u] = (cnt++));
  }
  static int spfa(int s) {
    (h = (t = 0));
    j::fill(dist, 0, (n + 1), std::numeric_limits<int>::max());
    j::fill(update, 0, (n + 1), 0);
    j::fill(enter, 0, (n + 1), false);
    (dist[s] = 0);
    (update[s] = 1);
    (queue[(t++)] = s);
    (enter[s] = true);
    while ((h < t)) {
      int u = queue[(h++)];
      (enter[u] = false);
      {
        int ei = head[u];
        int v = {};
        int w = {};
        for (; (ei > 0); (ei = next[ei])) {
          (v = to[ei]);
          (w = weight[ei]);
          if ((dist[v] > (dist[u] + w))) {
            (dist[v] = (dist[u] + w));
            if ((!enter[v])) {
              if (((++update[v]) > n)) {
                return (-1);
              }
              (queue[(t++)] = v);
              (enter[v] = true);
            }
          }
        }
      }
    }
    if ((dist[n] == std::numeric_limits<int>::max())) {
      return (-2);
    }
    return dist[n];
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    (n = static_cast<int>(in.nval));
    in.nextToken();
    (m1 = static_cast<int>(in.nval));
    in.nextToken();
    (m2 = static_cast<int>(in.nval));
    Code03_LayoutCow::prepare();
    for (int i = 1; (i <= n); (i++)) {
      Code03_LayoutCow::addEdge(0, i, 0);
    }
    {
      int i = 1;
      int u = {};
      int v = {};
      int w = {};
      for (; (i <= m1); (i++)) {
        in.nextToken();
        (u = static_cast<int>(in.nval));
        in.nextToken();
        (v = static_cast<int>(in.nval));
        in.nextToken();
        (w = static_cast<int>(in.nval));
        Code03_LayoutCow::addEdge(u, v, w);
      }
    }
    {
      int i = 1;
      int u = {};
      int v = {};
      int w = {};
      for (; (i <= m2); (i++)) {
        in.nextToken();
        (u = static_cast<int>(in.nval));
        in.nextToken();
        (v = static_cast<int>(in.nval));
        in.nextToken();
        (w = static_cast<int>(in.nval));
        Code03_LayoutCow::addEdge(v, u, (-w));
      }
    }
    for (int i = 1; (i < n); (i++)) {
      Code03_LayoutCow::addEdge((i + 1), i, 0);
    }
    int ans = Code03_LayoutCow::spfa(0);
    if ((ans == (-1))) {
      out.println(ans);
    } else {
      (ans = Code03_LayoutCow::spfa(1));
      out.println(ans);
    }
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code03_LayoutCow::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 布局奶牛
// 编号1到编号n的奶牛从左往右站成一排，你可以决定任意相邻奶牛之间的距离
// 有m1条好友信息，有m2条情敌信息，好友间希望距离更近，情敌间希望距离更远
// 每条好友信息为 : u v w，表示希望u和v之间的距离 <= w，输入保证u < v
// 每条情敌信息为 : u v w，表示希望u和v之间的距离 >= w，输入保证u < v
// 你需要安排奶牛的布局，满足所有的好友信息和情敌信息
// 如果不存在合法方案，返回-1
// 如果存在合法方案，返回1号奶牛和n号奶牛之间的最大距离
// 如果存在合法方案，并且1号奶牛和n号奶牛之间的距离可以无穷远，返回-2
// 测试链接 : https://www.luogu.com.cn/problem/P4878
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 链式前向星需要
        // spfa需要
                // 0号点是连通超级源点，保证图的连通性
                // 好友关系连边
                // 情敌关系连边
                // 根据本题的模型，一定要增加如下的边，不然会出错
*/

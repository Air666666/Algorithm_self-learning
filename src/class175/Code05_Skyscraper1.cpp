// Source: src/class175/Code05_Skyscraper1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code05_Skyscraper1 {
  struct Node;
  struct Node {
    int idx = {};
    int jump = {};
    int time = {};
    String toString() const { return j::str(static_cast<const void *>(this)); }
    Node(int i, int j, int t) {
      (idx = i);
      (jump = j);
      (time = t);
    }
  };
  inline static int MAXN = 30001;
  inline static int n = {};
  inline static int m = {};
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> next = make_array<int>(MAXN);
  inline static Array<int> to = make_array<int>(MAXN);
  inline static int cnt = {};
  inline static JDeque<Node *> que = JDeque<Node *>();
  inline static Array<BitSet> vis = make_array<BitSet>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code05_Skyscraper1() {}
  static void add(int idx, int jump) {
    (next[(++cnt)] = head[idx]);
    (to[cnt] = jump);
    (head[idx] = cnt);
  }
  static void trigger(int idx, int time) {
    {
      int e = head[idx];
      int jump = {};
      for (; (e > 0); (e = next[e])) {
        (jump = to[e]);
        if ((!vis[idx].get(jump))) {
          vis[idx].set(jump);
          que.addLast(new Node(idx, jump, time));
        }
      }
    }
    (head[idx] = 0);
  }
  static void extend(int idx, int jump, int time) {
    Code05_Skyscraper1::trigger(idx, time);
    if ((!vis[idx].get(jump))) {
      vis[idx].set(jump);
      que.addLast(new Node(idx, jump, time));
    }
  }
  static int bfs(int s, int t) {
    if ((s == t)) {
      return 0;
    }
    for (int i = 0; (i < MAXN); (i++)) {
      (vis[i] = BitSet());
    }
    Code05_Skyscraper1::trigger(s, 0);
    while ((!que.isEmpty())) {
      Node *cur = que.pollFirst();
      int idx = cur->idx;
      int jump = cur->jump;
      int time = cur->time;
      if ((((idx - jump) == t) || ((idx + jump) == t))) {
        return (time + 1);
      }
      if (((idx - jump) >= 0)) {
        Code05_Skyscraper1::extend((idx - jump), jump, (time + 1));
      }
      if (((idx + jump) < n)) {
        Code05_Skyscraper1::extend((idx + jump), jump, (time + 1));
      }
    }
    return (-1);
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(jout);
    (n = in.nextInt());
    (m = in.nextInt());
    int s = in.nextInt();
    int sjump = in.nextInt();
    int t = in.nextInt();
    int tjump = in.nextInt();
    Code05_Skyscraper1::add(s, sjump);
    Code05_Skyscraper1::add(t, tjump);
    {
      int i = 2;
      int idx = {};
      int jump = {};
      for (; (i < m); (i++)) {
        (idx = in.nextInt());
        (jump = in.nextInt());
        Code05_Skyscraper1::add(idx, jump);
      }
    }
    out.println(Code05_Skyscraper1::bfs(s, t));
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code05_Skyscraper1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 雅加达的摩天楼，java版
// 有n个大楼，编号0~n-1，有m个狗子，编号0~m-1
// 每只狗子有两个参数，idx表示狗子的初始大楼，jump表示狗子的跳跃能力
// 狗子在i位置，可以来到 i - jump 或 i + jump，向左向右自由跳跃，但不能越界
//
0号狗子有消息希望传给1号狗子，所有狗子都可帮忙，返回至少传送几次，无法送达打印-1
// 1 <= n、m <= 30000
// 测试链接 : https://www.luogu.com.cn/problem/P3645
// 测试链接 : https://uoj.ac/problem/111
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 每个大楼拥有的狗子列表
        // bfs过程
        // vis[idx]是个位图，可以表示vis[idx][jump]是否出现过
        // 读写工具类
*/

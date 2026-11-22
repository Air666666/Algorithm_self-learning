// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P1993

// Source: src/class142/Code02_KsFarm.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_KsFarm {
  inline static int MAXN = 5001;
  inline static int MAXM = 20001;
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> next = make_array<int>(MAXM);
  inline static Array<int> to = make_array<int>(MAXM);
  inline static Array<int> weight = make_array<int>(MAXM);
  inline static int cnt = {};
  inline static Array<int> dist = make_array<int>(MAXN);
  inline static Array<int> update = make_array<int>(MAXN);
  inline static int MAXQ = 20000001;
  inline static Array<int> queue = make_array<int>(MAXQ);
  inline static int h = {};
  inline static int t = {};
  inline static Array<bool> enter = make_array<bool>(MAXN);
  inline static int n = {};
  inline static int m = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_KsFarm() {}
  static void prepare() {
    (cnt = 1);
    (h = (t = 0));
    j::fill(head, 0, (n + 1), 0);
    j::fill(dist, 0, (n + 1), std::numeric_limits<int>::max());
    j::fill(update, 0, (n + 1), 0);
    j::fill(enter, 0, (n + 1), false);
  }
  static void addEdge(int u, int v, int w) {
    (next[cnt] = head[u]);
    (to[cnt] = v);
    (weight[cnt] = w);
    (head[u] = (cnt++));
  }
  static bool spfa(int s) {
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
                return true;
              }
              (queue[(t++)] = v);
              (enter[v] = true);
            }
          }
        }
      }
    }
    return false;
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    (n = static_cast<int>(in.nval));
    in.nextToken();
    (m = static_cast<int>(in.nval));
    Code02_KsFarm::prepare();
    for (int i = 1; (i <= n); (i++)) {
      Code02_KsFarm::addEdge(0, i, 0);
    }
    {
      int i = 1;
      int type = {};
      int u = {};
      int v = {};
      int w = {};
      for (; (i <= m); (i++)) {
        in.nextToken();
        (type = static_cast<int>(in.nval));
        in.nextToken();
        (u = static_cast<int>(in.nval));
        in.nextToken();
        (v = static_cast<int>(in.nval));
        if ((type == 1)) {
          in.nextToken();
          (w = static_cast<int>(in.nval));
          Code02_KsFarm::addEdge(u, v, (-w));
        } else if ((type == 2)) {
          in.nextToken();
          (w = static_cast<int>(in.nval));
          Code02_KsFarm::addEdge(v, u, w);
        } else {
          Code02_KsFarm::addEdge(u, v, 0);
          Code02_KsFarm::addEdge(v, u, 0);
        }
      }
    }
    if (Code02_KsFarm::spfa(0)) {
      out.println(String(u"No"));
    } else {
      out.println(String(u"Yes"));
    }
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code02_KsFarm::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 小k的农场
// 一共有n个农场，编号1~n，给定m条关系，每条关系是如下三种形式中的一种
// 关系1 a b c : 表示农场a比农场b至少多种植了c个作物
// 关系2 a b c : 表示农场a比农场b至多多种植了c个作物
// 关系3 a b   : 表示农场a和农场b种植了一样多的作物
// 如果关系之间能推出矛盾，打印"No"，不存在矛盾，打印"Yes"
// 1 <= n、m <= 5 * 10^3
// 1 <= c <= 5 * 10^3
// 测试链接 : https://www.luogu.com.cn/problem/P1993
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 链式前向星需要
        // spfa需要
*/

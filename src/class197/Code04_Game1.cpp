// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P3825

// Source: src/class197/Code04_Game1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_Game1 {
  inline static int MAXN = 200001;
  inline static int n = {};
  inline static int d = {};
  inline static int m = {};
  inline static Array<jchar> ban = make_array<jchar>(128);
  inline static Array<jchar> first = make_array<jchar>(128);
  inline static Array<jchar> second = make_array<jchar>(128);
  inline static Array<jchar> groundType = make_array<jchar>(MAXN);
  inline static Array<int> pos1 = make_array<int>(MAXN);
  inline static Array<jchar> car1 = make_array<jchar>(MAXN);
  inline static Array<int> pos2 = make_array<int>(MAXN);
  inline static Array<jchar> car2 = make_array<jchar>(MAXN);
  inline static Array<int> posx = make_array<int>(MAXN);
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> nxt = make_array<int>(MAXN);
  inline static Array<int> to = make_array<int>(MAXN);
  inline static int cntg = {};
  inline static Array<int> dfn = make_array<int>(MAXN);
  inline static Array<int> low = make_array<int>(MAXN);
  inline static int cntd = {};
  inline static Array<int> sta = make_array<int>(MAXN);
  inline static int top = {};
  inline static Array<int> belong = make_array<int>(MAXN);
  inline static int sccCnt = {};
  inline static Array<jchar> ans = make_array<jchar>(MAXN);
  inline static Array<int> stau = make_array<int>(MAXN);
  inline static Array<int> stas = make_array<int>(MAXN);
  inline static Array<int> stae = make_array<int>(MAXN);
  inline static int u = {};
  inline static int status = {};
  inline static int e = {};
  inline static int stacksize = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_Game1() {}
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
  static void prepare() {
    (ban[u'a'] = u'A');
    (ban[u'b'] = u'B');
    (ban[u'c'] = u'C');
    (first[u'a'] = u'B');
    (first[u'b'] = u'A');
    (first[u'c'] = u'A');
    (second[u'a'] = u'C');
    (second[u'b'] = u'C');
    (second[u'c'] = u'B');
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
        Code04_Game1::tarjan1(v);
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
    Code04_Game1::push(node, (-1), (-1));
    int v = {};
    while ((stacksize > 0)) {
      Code04_Game1::pop();
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
          Code04_Game1::push(u, 0, e);
          Code04_Game1::push(v, (-1), (-1));
        } else {
          Code04_Game1::push(u, 1, e);
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
  static int other(int i) { return ((i <= n) ? (i + n) : (i - n)); }
  static void buildGraph(int stax) {
    {
      int bit = 0;
      int idx = 1;
      for (; (bit < d); (bit++), (idx++)) {
        if (((jshr(stax, bit) & 1) == 1)) {
          (groundType[posx[idx]] = u'a');
        } else {
          (groundType[posx[idx]] = u'b');
        }
      }
    }
    for (int i = 1; (i <= m); (i++)) {
      int p1 = pos1[i];
      jchar g1 = groundType[p1];
      jchar c1 = car1[i];
      if ((ban[g1] == c1)) {
        continue;
      }
      int id1 = ((c1 == first[g1]) ? p1 : (p1 + n));
      int p2 = pos2[i];
      jchar g2 = groundType[p2];
      jchar c2 = car2[i];
      if ((ban[g2] == c2)) {
        Code04_Game1::addEdge(id1, Code04_Game1::other(id1));
      } else {
        int id2 = ((c2 == first[g2]) ? p2 : (p2 + n));
        Code04_Game1::addEdge(id1, id2);
        [&]() {
          auto jargument_0 = Code04_Game1::other(id2);
          auto jargument_1 = Code04_Game1::other(id1);
          return Code04_Game1::addEdge(jargument_0, jargument_1);
        }();
      }
    }
  }
  static void clear() {
    for (int i = 1; (i <= jshl(n, 1)); (i++)) {
      (head[i] = (dfn[i] = (belong[i] = 0)));
    }
    (cntg = (cntd = (top = (sccCnt = 0))));
  }
  static bool compute() {
    {
      int i = 1;
      int sizx = 0;
      for (; (i <= n); (i++)) {
        if ((groundType[i] == u'x')) {
          (posx[(++sizx)] = i);
        }
      }
    }
    for (int stax = 0; (stax < jshl(1, d)); (stax++)) {
      Code04_Game1::buildGraph(stax);
      for (int i = 1; (i <= jshl(n, 1)); (i++)) {
        if ((dfn[i] == 0)) {
          if ((head[i] == 0)) {
            (dfn[i] = (low[i] = (++cntd)));
            (belong[i] = (++sccCnt));
          } else {
            Code04_Game1::tarjan2(i);
          }
        }
      }
      bool check = true;
      for (int i = 1; (i <= n); (i++)) {
        if ((belong[i] == belong[(i + n)])) {
          (check = false);
          break;
        }
      }
      if (check) {
        for (int i = 1; (i <= n); (i++)) {
          jchar ground = groundType[i];
          if ((belong[i] < belong[(i + n)])) {
            (ans[i] = first[ground]);
          } else {
            (ans[i] = second[ground]);
          }
        }
        return true;
      }
      Code04_Game1::clear();
    }
    return false;
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    Code04_Game1::prepare();
    (n = in.nextInt());
    (d = in.nextInt());
    for (int i = 1; (i <= n); (i++)) {
      (groundType[i] = in.nextChar());
    }
    (m = in.nextInt());
    for (int i = 1; (i <= m); (i++)) {
      (pos1[i] = in.nextInt());
      (car1[i] = in.nextChar());
      (pos2[i] = in.nextInt());
      (car2[i] = in.nextChar());
    }
    bool check = Code04_Game1::compute();
    if (check) {
      for (int i = 1; (i <= n); (i++)) {
        out.print(ans[i]);
      }
    } else {
      out.println((-1));
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code04_Game1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 游戏，java版
// 地面有x、a、b、c四种类型，赛车有A、B、C三辆
// 类型a不能跑车A，类型b不能跑车B、类型c不能跑车C，类型x没有限制
// 一共有n个地点，给定每个地点的地面类型，其中x类型的地面有d个
// 一共有m个限制，格式 pos1 car1 pos2 car2，含义如下
// 如果pos1号地点使用car1赛车，那么pos2号地点一定要使用car2赛车
// 每辆赛车可以使用无限次，需要满足以上的规则和限制来安排比赛
// 如果有方案，找到任意一种方案，打印每个地点用什么车，无方案打印-1
// 1 <= n <= 5 * 10^4    1 <= m <= 10^5    0 <= d <= 8
// 测试链接 : https://www.luogu.com.cn/problem/P3825
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 迭代版需要的栈，讲解118讲了递归改迭代的技巧
        // 递归版
        // 迭代版
                                                // 孤立点直接分配强联通分量
                                                //
优化一下常数，java需要，c++不需要
                                                // tarjan1(i);
        // 读写工具类
*/

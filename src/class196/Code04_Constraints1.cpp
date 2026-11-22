// Source: src/class196/Code04_Constraints1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_Constraints1 {
  inline static int MAXN = 20001;
  inline static int MAXM = 2000001;
  inline static int MAXK = 12;
  inline static int MAXT = ((MAXN * MAXK) * 2);
  inline static int t = {};
  inline static int n = {};
  inline static int m = {};
  inline static int k = {};
  inline static Array<Array<Array<int>>> id = make_array<int>(MAXN, MAXK, 2);
  inline static int cntt = {};
  inline static Array<int> head = make_array<int>(MAXT);
  inline static Array<int> nxt = make_array<int>(MAXM);
  inline static Array<int> to = make_array<int>(MAXM);
  inline static int cntg = {};
  inline static Array<int> dfn = make_array<int>(MAXT);
  inline static Array<int> low = make_array<int>(MAXT);
  inline static int cntd = {};
  inline static Array<int> sta = make_array<int>(MAXT);
  inline static int top = {};
  inline static Array<int> belong = make_array<int>(MAXT);
  inline static int sccCnt = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_Constraints1() {}
  static void addEdge(int u, int v) {
    (nxt[(++cntg)] = head[u]);
    (to[cntg] = v);
    (head[u] = cntg);
  }
  static void tarjan(int u) {
    (dfn[u] = (low[u] = (++cntd)));
    (sta[(++top)] = u);
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      int v = to[e];
      if ((dfn[v] == 0)) {
        Code04_Constraints1::tarjan(v);
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
  static void prepare() {
    (cntg = (cntd = (sccCnt = 0)));
    for (int i = 1; (i <= cntt); (i++)) {
      (head[i] = (dfn[i] = (low[i] = (belong[i] = 0))));
    }
    (cntt = 0);
    for (int i = 1; (i <= n); (i++)) {
      for (int v = 1; (v <= (k + 1)); (v++)) {
        (id[i][v][0] = (++cntt));
        (id[i][v][1] = (++cntt));
      }
    }
    for (int i = 1; (i <= n); (i++)) {
      for (int v = 1; (v <= k); (v++)) {
        Code04_Constraints1::addEdge(id[i][v][0], id[i][(v + 1)][0]);
        Code04_Constraints1::addEdge(id[i][(v + 1)][1], id[i][v][1]);
      }
    }
    for (int i = 1; (i < n); (i++)) {
      for (int v = 1; (v <= k); (v++)) {
        Code04_Constraints1::addEdge(id[(i + 1)][v][0], id[i][v][0]);
        Code04_Constraints1::addEdge(id[i][v][1], id[(i + 1)][v][1]);
      }
    }
    for (int i = 1; (i <= n); (i++)) {
      Code04_Constraints1::addEdge(id[i][1][0], id[i][1][1]);
      Code04_Constraints1::addEdge(id[i][(k + 1)][1], id[i][(k + 1)][0]);
    }
  }
  static void notEqual(int i, int x) {
    Code04_Constraints1::addEdge(id[i][x][1], id[i][(x + 1)][1]);
    Code04_Constraints1::addEdge(id[i][(x + 1)][0], id[i][x][0]);
  }
  static void lessEqual(int i, int j, int x) {
    for (int w = 1; (w <= k); (w++)) {
      if ((w >= x)) {
        Code04_Constraints1::notEqual(i, w);
      } else {
        if ((((x - w) + 1) <= k)) {
          Code04_Constraints1::addEdge(id[i][w][1], id[j][((x - w) + 1)][0]);
          Code04_Constraints1::addEdge(id[j][((x - w) + 1)][1], id[i][w][0]);
        }
      }
    }
  }
  static void moreEqual(int i, int j, int x) {
    for (int w = 1; (w <= k); (w++)) {
      if ((w <= ((x - k) - 1))) {
        Code04_Constraints1::notEqual(i, w);
      } else {
        if (((x - w) > 1)) {
          Code04_Constraints1::addEdge(id[i][(w + 1)][0], id[j][(x - w)][1]);
          Code04_Constraints1::addEdge(id[j][(x - w)][0], id[i][(w + 1)][1]);
        }
      }
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (t = in.nextInt());
    for (int c = 1; (c <= t); (c++)) {
      (n = in.nextInt());
      (m = in.nextInt());
      (k = in.nextInt());
      Code04_Constraints1::prepare();
      {
        int i = 1;
        int op = {};
        int x = {};
        int y = {};
        int v = {};
        for (; (i <= m); (i++)) {
          (op = in.nextInt());
          if ((op == 1)) {
            (x = in.nextInt());
            (v = in.nextInt());
            Code04_Constraints1::notEqual(x, v);
          } else if ((op == 2)) {
            (x = in.nextInt());
            (y = in.nextInt());
            (v = in.nextInt());
            Code04_Constraints1::lessEqual(x, y, v);
            int tmp = x;
            (x = y);
            (y = tmp);
            Code04_Constraints1::lessEqual(x, y, v);
          } else {
            (x = in.nextInt());
            (y = in.nextInt());
            (v = in.nextInt());
            Code04_Constraints1::moreEqual(x, y, v);
            int tmp = x;
            (x = y);
            (y = tmp);
            Code04_Constraints1::moreEqual(x, y, v);
          }
        }
      }
      for (int i = 1; (i <= cntt); (i++)) {
        if ((dfn[i] == 0)) {
          Code04_Constraints1::tarjan(i);
        }
      }
      bool check = true;
      for (int i = 1; (i <= n); (i++)) {
        for (int v = 1; (v <= (k + 1)); (v++)) {
          if ((belong[id[i][v][0]] == belong[id[i][v][1]])) {
            (check = false);
            break;
          }
        }
        if ((!check)) {
          break;
        }
      }
      if (check) {
        for (int i = 1; (i <= n); (i++)) {
          for (int v = k; (v >= 1); (v--)) {
            if ((belong[id[i][v][1]] < belong[id[i][v][0]])) {
              out.print((v + String(u" ")));
              break;
            }
          }
        }
        out.println();
      } else {
        out.println((-1));
      }
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code04_Constraints1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 约束条件，java版
// 你需要构造长度为n的数组arr，每个元素的值在1~k之间，数组是非递减的
// 接下来给定m个约束条件，构造方案要满足所有约束条件，约束的格式如下
// 约束 1 i x   : arr[i] != x
// 约束 2 i j x : arr[i] + arr[j] <= x
// 约束 3 i j x : arr[i] + arr[j] >= x
// 如果不存在构造方案打印-1，存在方案就打印arr，任何一种方案都可以
// n、m <= 2 * 10^4
// 2 <= k <= 10
// 测试链接 : https://www.luogu.com.cn/problem/CF1697F
// 测试链接 : https://codeforces.com/problemset/problem/1697/F
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
                // 每个假设分配节点编号
                // 天然成立
                // 数组非递减
                // 每个位置的值在[1, k]范围
                // 规避错误假设
                // 强连通分量解决2-SAT问题的特性，永远选择拓扑序靠后的假设
                // (值 < 1) -> (值 >=
1)，推出矛盾固然不可行，如果无矛盾，会以后者为准
                // (值 >= k+1) -> (值 <
k+1)，推出矛盾固然不可行，如果无矛盾，会以后者为准
        // 读写工具类
*/

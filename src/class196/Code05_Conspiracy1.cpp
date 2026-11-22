// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P3513
// https://loj.ac/p/2155

// Source: src/class196/Code05_Conspiracy1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code05_Conspiracy1 {
  inline static int MAXN = 5001;
  inline static int MAXT = jshl(MAXN, 1);
  inline static int MAXM = (MAXN * MAXN);
  inline static int n = {};
  inline static int k = {};
  inline static int x = {};
  inline static Array<Array<bool>> know = make_array<bool>(MAXN, MAXN);
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
  inline static Array<int> team1 = make_array<int>(MAXN);
  inline static Array<int> team2 = make_array<int>(MAXN);
  inline static int cnt1 = {};
  inline static int cnt2 = {};
  inline static Array<int> other = make_array<int>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code05_Conspiracy1() {}
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
        Code05_Conspiracy1::tarjan(v);
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
  static int compute() {
    for (int i = 1; (i <= n); (i++)) {
      if ((belong[i] == belong[(i + n)])) {
        return 0;
      }
    }
    for (int i = 1; (i <= n); (i++)) {
      if ((belong[i] < belong[(i + n)])) {
        (team1[(++cnt1)] = i);
      } else {
        (team2[(++cnt2)] = i);
      }
    }
    int ans = (((cnt1 > 0) && (cnt2 > 0)) ? 1 : 0);
    {
      int i = 1;
      int a = {};
      int b = {};
      for (; (i <= cnt1); (i++)) {
        (a = team1[i]);
        for (int j = 1; (j <= cnt2); (j++)) {
          (b = team2[j]);
          if (know[a][b]) {
            (other[a] = ((other[a] == 0) ? b : (-1)));
          } else {
            (other[b] = ((other[b] == 0) ? a : (-1)));
          }
        }
      }
    }
    if ((cnt1 > 1)) {
      for (int i = 1; (i <= cnt1); (i++)) {
        if ((other[team1[i]] == 0)) {
          (ans++);
        }
      }
    }
    if ((cnt2 > 1)) {
      for (int i = 1; (i <= cnt2); (i++)) {
        if ((other[team2[i]] == 0)) {
          (ans++);
        }
      }
    }
    {
      int i = 1;
      int a = {};
      int b = {};
      for (; (i <= cnt1); (i++)) {
        (a = team1[i]);
        for (int j = 1; (j <= cnt2); (j++)) {
          (b = team2[j]);
          if (know[a][b]) {
            if (((other[a] == b) && (other[b] == 0))) {
              (ans++);
            }
          } else {
            if (((other[b] == a) && (other[a] == 0))) {
              (ans++);
            }
          }
        }
      }
    }
    return ans;
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    for (int i = 1; (i <= n); (i++)) {
      (k = in.nextInt());
      for (int j = 1; (j <= k); (j++)) {
        (x = in.nextInt());
        (know[i][x] = true);
      }
    }
    for (int i = 1; (i <= n); (i++)) {
      for (int j = (i + 1); (j <= n); (j++)) {
        if (know[i][j]) {
          Code05_Conspiracy1::addEdge((i + n), j);
          Code05_Conspiracy1::addEdge((j + n), i);
        } else {
          Code05_Conspiracy1::addEdge(i, (j + n));
          Code05_Conspiracy1::addEdge(j, (i + n));
        }
      }
    }
    for (int i = 1; (i <= jshl(n, 1)); (i++)) {
      if ((dfn[i] == 0)) {
        Code05_Conspiracy1::tarjan(i);
      }
    }
    int ans = Code05_Conspiracy1::compute();
    out.println(ans);
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code05_Conspiracy1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 同谋者，java版
// 一共n个人，编号1~n，分配每个人进入交流队或者保密队中的一个
// 交流队要求内部任意两人都认识，保密队要求内部任意两人都不认识
// 给定每人的认识列表，如果x的认识列表里有y，那么y的认识列表里有x
// 分配还要求交流队和保密队都不能为空，计算n个人分成两组的方法数
// 如果不存在任何方法，打印0
// 2 <= n <= 5000
// 所有认识列表的总人数 <= n * (n - 1)
// 测试链接 : https://www.luogu.com.cn/problem/P3513
// 测试链接 : https://loj.ac/p/2155
// 提交以下的code，提交时请把类名改成"Main"
// 本题给的使用空间很小，java的实现无法通过
// 想通过用C++实现，本节课Code05_Conspiracy2文件就是C++的实现
// 两个版本的逻辑完全一样，C++版本可以通过所有测试
        // 如果i在交流队
        // other[i] >= 1，表示i认识保密队中的人的编号
        // other[i] == 0，表示i不认识保密队中的所有人
        // other[i] == -1，表示i认识保密队中的人数，不止一个
        //
        // 如果i在保密队
        // other[i] >= 1，表示i不认识交流队中的人的编号
        // other[i] == 0，表示i认识交流队中的所有人
        // other[i] == -1，表示i不认识交流队中的人数，不止一个
        // 读写工具类
*/

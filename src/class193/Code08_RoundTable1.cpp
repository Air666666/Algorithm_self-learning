// Source: src/class193/Code08_RoundTable1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code08_RoundTable1 {
  inline static int MAXN = 1001;
  inline static int MAXM = 1000001;
  inline static int n = {};
  inline static int m = {};
  inline static Array<Array<bool>> hate = make_array<bool>(MAXN, MAXN);
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> nxt = make_array<int>(jshl(MAXM, 1));
  inline static Array<int> to = make_array<int>(jshl(MAXM, 1));
  inline static int cntg = {};
  inline static Array<int> dfn = make_array<int>(MAXN);
  inline static Array<int> low = make_array<int>(MAXN);
  inline static int cntd = {};
  inline static Array<int> sta = make_array<int>(MAXN);
  inline static int top = {};
  inline static Array<int> vbccArr = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> vbccl = make_array<int>(MAXN);
  inline static Array<int> vbccr = make_array<int>(MAXN);
  inline static int idx = {};
  inline static int vbccCnt = {};
  inline static Array<bool> curVbcc = make_array<bool>(MAXN);
  inline static Array<int> color = make_array<int>(MAXN);
  inline static Array<bool> ok = make_array<bool>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code08_RoundTable1() {}
  static void prepare() {
    (cntg = (cntd = (top = (idx = (vbccCnt = 0)))));
    for (int i = 1; (i <= n); (i++)) {
      (head[i] = (dfn[i] = (low[i] = 0)));
      (ok[i] = false);
      for (int j = 1; (j <= n); (j++)) {
        (hate[i][j] = false);
      }
    }
  }
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
        Code08_RoundTable1::tarjan(v);
        (low[u] = jmin(low[u], low[v]));
        if ((low[v] >= dfn[u])) {
          (vbccCnt++);
          (vbccArr[(++idx)] = u);
          (vbccl[vbccCnt] = idx);
          int pop = {};
          do {
            (pop = sta[(top--)]);
            (vbccArr[(++idx)] = pop);
          } while ((pop != v));
          (vbccr[vbccCnt] = idx);
        }
      } else {
        (low[u] = jmin(low[u], dfn[v]));
      }
    }
  }
  static bool oddLoop(int u, int c) {
    (color[u] = c);
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      int v = to[e];
      if (curVbcc[v]) {
        if ((color[v] == c)) {
          return true;
        }
        if (((color[v] == 0) &&
             Code08_RoundTable1::oddLoop(v, ((c == 1) ? 2 : 1)))) {
          return true;
        }
      }
    }
    return false;
  }
  static int compute() {
    for (int i = 1; (i <= vbccCnt); (i++)) {
      for (int j = vbccl[i]; (j <= vbccr[i]); (j++)) {
        (curVbcc[vbccArr[j]] = true);
        (color[vbccArr[j]] = 0);
      }
      bool check = Code08_RoundTable1::oddLoop(vbccArr[vbccl[i]], 1);
      for (int j = vbccl[i]; (j <= vbccr[i]); (j++)) {
        (curVbcc[vbccArr[j]] = false);
        (ok[vbccArr[j]] = (ok[vbccArr[j]] | check));
      }
    }
    int ans = 0;
    for (int i = 1; (i <= n); (i++)) {
      if ((!ok[i])) {
        (ans++);
      }
    }
    return ans;
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (m = in.nextInt());
    while (((n != 0) || (m != 0))) {
      Code08_RoundTable1::prepare();
      {
        int i = 1;
        int u = {};
        int v = {};
        for (; (i <= m); (i++)) {
          (u = in.nextInt());
          (v = in.nextInt());
          (hate[u][v] = true);
          (hate[v][u] = true);
        }
      }
      for (int u = 1; (u <= n); (u++)) {
        for (int v = (u + 1); (v <= n); (v++)) {
          if ((!hate[u][v])) {
            Code08_RoundTable1::addEdge(u, v);
            Code08_RoundTable1::addEdge(v, u);
          }
        }
      }
      for (int i = 1; (i <= n); (i++)) {
        if ((dfn[i] == 0)) {
          Code08_RoundTable1::tarjan(i);
        }
      }
      int ans = Code08_RoundTable1::compute();
      out.println(ans);
      (n = in.nextInt());
      (m = in.nextInt());
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code08_RoundTable1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 圆桌骑士，java版
// 一共n个骑士，有m条厌恶关系，每条厌恶关系代表两个骑士互相讨厌对方
// 你可以任选骑士参加圆桌会议，但是厌恶关系的骑士无法在圆桌中相邻
// 圆桌会议的骑士数量必须是大于1的奇数，以防止赞同票和反对票一样多
// 也许有的骑士，不管怎么安排都无法参加圆桌会议，打印这个数量
// 1 <= n <= 10^3
// 1 <= m <= 10^6
// 测试链接 : https://www.luogu.com.cn/problem/SP2878
// 测试链接 : https://www.spoj.com/problems/KNIGHTS/
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // u表示当前节点，c表示当前分配给u节点的颜色，只有1和2两种颜色
        // 返回是否发现了节点数量为奇数的环
        // 读写工具类
*/

// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P3225

// Source: src/class193/Code07_MiningFarm1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code07_MiningFarm1 {
  inline static int MAXN = 1001;
  inline static int MAXM = 1001;
  inline static int t = {};
  inline static int n = {};
  inline static int m = {};
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> nxt = make_array<int>(jshl(MAXM, 1));
  inline static Array<int> to = make_array<int>(jshl(MAXM, 1));
  inline static int cntg = {};
  inline static Array<int> dfn = make_array<int>(MAXN);
  inline static Array<int> low = make_array<int>(MAXN);
  inline static int cntd = {};
  inline static Array<int> sta = make_array<int>(MAXN);
  inline static int top = {};
  inline static Array<bool> cutVertex = make_array<bool>(MAXN);
  inline static Array<int> vbccSiz = make_array<int>(MAXN);
  inline static Array<int> vbccArr = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> vbccl = make_array<int>(MAXN);
  inline static Array<int> vbccr = make_array<int>(MAXN);
  inline static int idx = {};
  inline static int vbccCnt = {};
  inline static i64 ans1 = {};
  inline static i64 ans2 = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code07_MiningFarm1() {}
  static void prepare() {
    (cntg = (cntd = (top = (idx = (vbccCnt = 0)))));
    for (int i = 1; (i < MAXN); (i++)) {
      (head[i] = (dfn[i] = (low[i] = 0)));
      (cutVertex[i] = false);
    }
    (n = 0);
  }
  static void addEdge(int u, int v) {
    (nxt[(++cntg)] = head[u]);
    (to[cntg] = v);
    (head[u] = cntg);
  }
  static void tarjan(int u, bool root) {
    (dfn[u] = (low[u] = (++cntd)));
    (sta[(++top)] = u);
    int son = 0;
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      int v = to[e];
      if ((dfn[v] == 0)) {
        (son++);
        Code07_MiningFarm1::tarjan(v, false);
        (low[u] = jmin(low[u], low[v]));
        if ((low[v] >= dfn[u])) {
          if (((!root) || (son >= 2))) {
            (cutVertex[u] = true);
          }
          (vbccCnt++);
          (vbccSiz[vbccCnt] = 1);
          (vbccArr[(++idx)] = u);
          (vbccl[vbccCnt] = idx);
          int pop = {};
          do {
            (pop = sta[(top--)]);
            (vbccSiz[vbccCnt]++);
            (vbccArr[(++idx)] = pop);
          } while ((pop != v));
          (vbccr[vbccCnt] = idx);
        }
      } else {
        (low[u] = jmin(low[u], dfn[v]));
      }
    }
  }
  static void compute() {
    if ((vbccCnt == 1)) {
      (ans1 = 2);
      (ans2 = jdiv((n * (n - 1)), 2));
    } else {
      (ans1 = 0);
      (ans2 = 1);
      for (int i = 1; (i <= vbccCnt); (i++)) {
        int siz = vbccSiz[i];
        int cut = 0;
        for (int j = vbccl[i]; (j <= vbccr[i]); (j++)) {
          if (cutVertex[vbccArr[j]]) {
            (cut++);
          }
        }
        if ((cut == 1)) {
          (ans1 += 1);
          (ans2 = (ans2 * (siz - 1)));
        }
      }
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (t = 0);
    (m = in.nextInt());
    while ((m != 0)) {
      Code07_MiningFarm1::prepare();
      {
        int i = 1;
        int u = {};
        int v = {};
        for (; (i <= m); (i++)) {
          (u = in.nextInt());
          (v = in.nextInt());
          (n = jmax(n, u));
          (n = jmax(n, v));
          Code07_MiningFarm1::addEdge(u, v);
          Code07_MiningFarm1::addEdge(v, u);
        }
      }
      Code07_MiningFarm1::tarjan(1, true);
      Code07_MiningFarm1::compute();
      out.println((((((String(u"Case ") + (++t)) + String(u": ")) + ans1) +
                    String(u" ")) +
                   ans2));
      (m = in.nextInt());
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code07_MiningFarm1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 矿场搭建，java版
// 一共n个地点，地点至少2个，每个地点都有人，m条双向道路连通所有地点
// 地震会发生在任何一个地点，地震发生时，其他地点的人都要去往救援点
// 你可以在任何地点设立救援点，但是发生地震的地点，道路和救援点都会失效
// 打印至少需要几个救援点，打印设立救援点的方案总数，方案认为是无序集合
// 1 <= n <= 1000
// 1 <= m <= 1000
// 测试链接 : https://www.luogu.com.cn/problem/P3225
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 读写工具类
*/

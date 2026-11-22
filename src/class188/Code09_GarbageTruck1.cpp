// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P3520

// Source: src/class188/Code09_GarbageTruck1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code09_GarbageTruck1 {
  inline static int MAXN = 100001;
  inline static int MAXM = 2000001;
  inline static int n = {};
  inline static int m = {};
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> nxt = make_array<int>(MAXM);
  inline static Array<int> to = make_array<int>(MAXM);
  inline static Array<int> eid = make_array<int>(MAXM);
  inline static int cntg = {};
  inline static Array<int> deg = make_array<int>(MAXN);
  inline static Array<int> cur = make_array<int>(MAXN);
  inline static Array<bool> visNode = make_array<bool>(MAXN);
  inline static Array<bool> visEdge = make_array<bool>(MAXM);
  inline static Array<bool> inpath = make_array<bool>(MAXN);
  inline static Array<int> path = make_array<int>(MAXM);
  inline static int cntp = {};
  inline static Array<int> ansArr = make_array<int>(MAXM);
  inline static Array<int> ansl = make_array<int>(MAXM);
  inline static Array<int> ansr = make_array<int>(MAXM);
  inline static int idx = {};
  inline static int cnta = {};
  inline static Array<int> sta = make_array<int>(MAXM);
  inline static int top = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code09_GarbageTruck1() {}
  static void addEdge(int u, int v, int id) {
    (nxt[(++cntg)] = head[u]);
    (to[cntg] = v);
    (eid[cntg] = id);
    (head[u] = cntg);
  }
  static void popCircle(int u) {
    (cnta++);
    (ansArr[(++idx)] = u);
    (ansl[cnta] = idx);
    for (int pop = path[(cntp--)]; (pop != u); (pop = path[(cntp--)])) {
      (inpath[pop] = false);
      (ansArr[(++idx)] = pop);
    }
    (inpath[u] = false);
    (ansArr[(++idx)] = u);
    (ansr[cnta] = idx);
  }
  static void euler1(int u) {
    (visNode[u] = true);
    for (int e = cur[u]; (e > 0); (e = cur[u])) {
      (cur[u] = nxt[e]);
      if ((!visEdge[eid[e]])) {
        (visEdge[eid[e]] = true);
        Code09_GarbageTruck1::euler1(to[e]);
      }
    }
    if (inpath[u]) {
      Code09_GarbageTruck1::popCircle(u);
    }
    (inpath[u] = true);
    (path[(++cntp)] = u);
  }
  static void euler2(int node) {
    (top = 0);
    (sta[(++top)] = node);
    while ((top > 0)) {
      int u = sta[(top--)];
      (visNode[u] = true);
      int e = cur[u];
      if ((e != 0)) {
        (cur[u] = nxt[e]);
        if ((!visEdge[eid[e]])) {
          (visEdge[eid[e]] = true);
          (sta[(++top)] = u);
          (sta[(++top)] = to[e]);
        } else {
          (sta[(++top)] = u);
        }
      } else {
        if (inpath[u]) {
          Code09_GarbageTruck1::popCircle(u);
        }
        (inpath[u] = true);
        (path[(++cntp)] = u);
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
      int s = {};
      int t = {};
      for (; (i <= m); (i++)) {
        (u = in.nextInt());
        (v = in.nextInt());
        (s = in.nextInt());
        (t = in.nextInt());
        if ((s != t)) {
          (deg[u]++);
          (deg[v]++);
          Code09_GarbageTruck1::addEdge(u, v, i);
          Code09_GarbageTruck1::addEdge(v, u, i);
        }
      }
    }
    for (int i = 1; (i <= n); (i++)) {
      (cur[i] = head[i]);
    }
    bool check = true;
    for (int i = 1; (i <= n); (i++)) {
      if (((deg[i] & 1) == 1)) {
        (check = false);
        break;
      }
    }
    if ((!check)) {
      out.println(String(u"NIE"));
    } else {
      for (int i = 1; (i <= n); (i++)) {
        if ((!visNode[i])) {
          Code09_GarbageTruck1::euler2(i);
        }
      }
      out.println(cnta);
      for (int i = 1; (i <= cnta); (i++)) {
        out.print(((ansr[i] - ansl[i]) + String(u" ")));
        for (int j = ansl[i]; (j <= ansr[i]); (j++)) {
          out.print((ansArr[j] + String(u" ")));
        }
        out.println();
      }
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code09_GarbageTruck1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 垃圾车，java版
// 一共有n个点，m条无向边，所有点不保证连通
// 每条边的属性为 u v s t : u和v是端点，s是初始状态，t是最终状态
// 状态的数值只有0和1两种，当一辆车通过一条无向边，那么状态会翻转
// 一辆车的路线中，可以指定一个起点，最终回到起点，沿途的其他点不能重复经过
// 所有的边都要达成最终状态，所以需要若干辆车来完成这个目标
// 如果存在方案，提供任何一种方案即可，首先打印需要几辆车
// 然后对每辆车，先打印通过的边数，再打印依次到达了哪些点
// 如果不存在方案，打印"NIE"
// 1 <= n <= 10^5    1 <= m <= 10^6
// 测试链接 : https://www.luogu.com.cn/problem/P3520
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 区分多个连通区
        // 标记无向边是否已经使用
                                        // euler1(i);
        // 读写工具类
*/

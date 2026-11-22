// Source: src/class165/Code04_TeamBuilding1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_TeamBuilding1 {
  inline static int MAXN = 500001;
  inline static int n = {};
  inline static int m = {};
  inline static int k = {};
  inline static Array<int> team = make_array<int>(MAXN);
  inline static Array<Array<int>> edge = make_array<int>(MAXN, 2);
  inline static Array<Array<int>> crossEdge = make_array<int>(MAXN, 4);
  inline static int cnt = 0;
  inline static Array<bool> conflict = make_array<bool>(MAXN);
  inline static Array<int> father = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> siz = make_array<int>(jshl(MAXN, 1));
  inline static Array<Array<int>> rollback = make_array<int>(jshl(MAXN, 1), 2);
  inline static int opsize = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_TeamBuilding1() {}
  static int find(int i) {
    while ((i != father[i])) {
      (i = father[i]);
    }
    return i;
  }
  static void union_method(int x, int y) {
    int fx = Code04_TeamBuilding1::find(x);
    int fy = Code04_TeamBuilding1::find(y);
    if ((siz[fx] < siz[fy])) {
      int tmp = fx;
      (fx = fy);
      (fy = tmp);
    }
    (father[fy] = fx);
    (siz[fx] += siz[fy]);
    (rollback[(++opsize)][0] = fx);
    (rollback[opsize][1] = fy);
  }
  static void undo() {
    int fx = rollback[opsize][0];
    int fy = rollback[(opsize--)][1];
    (father[fy] = fy);
    (siz[fx] -= siz[fy]);
  }
  static void filter() {
    for (int i = 1; (i <= (2 * n)); (i++)) {
      (father[i] = i);
      (siz[i] = 1);
    }
    {
      int i = 1;
      int u = {};
      int v = {};
      for (; (i <= m); (i++)) {
        (u = edge[i][0]);
        (v = edge[i][1]);
        if ((team[u] < team[v])) {
          (crossEdge[(++cnt)][0] = u);
          (crossEdge[cnt][1] = team[u]);
          (crossEdge[cnt][2] = v);
          (crossEdge[cnt][3] = team[v]);
        } else if ((team[u] > team[v])) {
          (crossEdge[(++cnt)][0] = v);
          (crossEdge[cnt][1] = team[v]);
          (crossEdge[cnt][2] = u);
          (crossEdge[cnt][3] = team[u]);
        } else {
          if (conflict[team[u]]) {
            continue;
          }
          if ([&]() {
                auto jleft = Code04_TeamBuilding1::find(u);
                auto jright = Code04_TeamBuilding1::find(v);
                return (jleft == jright);
              }()) {
            (k--);
            (conflict[team[u]] = true);
          } else {
            Code04_TeamBuilding1::union_method(u, (v + n));
            Code04_TeamBuilding1::union_method(v, (u + n));
          }
        }
      }
    }
  }
  static i64 compute() {
    j::sort(crossEdge, 1, (cnt + 1), [=](Array<int> a, Array<int> b) {
      return ((a[1] != b[1]) ? (a[1] - b[1]) : (a[3] - b[3]));
    });
    i64 ans = jdiv((static_cast<i64>(k) * (k - 1)), 2);
    int u = {};
    int uteam = {};
    int v = {};
    int vteam = {};
    int unionCnt = {};
    {
      int l = 1;
      int r = 1;
      for (; (l <= cnt); (l = (++r))) {
        (uteam = crossEdge[l][1]);
        (vteam = crossEdge[l][3]);
        while (((((r + 1) <= cnt) && (crossEdge[(r + 1)][1] == uteam)) &&
                (crossEdge[(r + 1)][3] == vteam))) {
          (r++);
        }
        if ((conflict[uteam] || conflict[vteam])) {
          continue;
        }
        (unionCnt = 0);
        for (int i = l; (i <= r); (i++)) {
          (u = crossEdge[i][0]);
          (v = crossEdge[i][2]);
          if ([&]() {
                auto jleft = Code04_TeamBuilding1::find(u);
                auto jright = Code04_TeamBuilding1::find(v);
                return (jleft == jright);
              }()) {
            (ans--);
            break;
          } else {
            Code04_TeamBuilding1::union_method(u, (v + n));
            Code04_TeamBuilding1::union_method(v, (u + n));
            (unionCnt += 2);
          }
        }
        for (int i = 1; (i <= unionCnt); (i++)) {
          Code04_TeamBuilding1::undo();
        }
      }
    }
    return ans;
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    (n = static_cast<int>(in.nval));
    in.nextToken();
    (m = static_cast<int>(in.nval));
    in.nextToken();
    (k = static_cast<int>(in.nval));
    for (int i = 1; (i <= n); (i++)) {
      in.nextToken();
      (team[i] = static_cast<int>(in.nval));
    }
    for (int i = 1; (i <= m); (i++)) {
      in.nextToken();
      (edge[i][0] = static_cast<int>(in.nval));
      in.nextToken();
      (edge[i][1] = static_cast<int>(in.nval));
    }
    Code04_TeamBuilding1::filter();
    out.println(Code04_TeamBuilding1::compute());
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code04_TeamBuilding1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 团建，java版
// 一共有n个人，每个人给定组号，一共有m条边，代表两人之间有矛盾
// 一共有k个小组，可能有的组没人，但是组依然存在
// 假设组a和组b，两个组的人一起去团建，组a和组b的所有人，可以重新打乱
// 如果所有人最多分成两个集团，每人都要参加划分，并且每个集团的内部不存在矛盾
// 那么组a和组b就叫做一个"合法组对"，注意，组b和组a就不用重复计算了
// 一共有k个组，随意选两个组的情况很多，计算一共有多少个"合法组对"
// 1 <= n、m、k <= 5 * 10^5
// 测试链接 : https://www.luogu.com.cn/problem/CF1444C
// 测试链接 : https://codeforces.com/problemset/problem/1444/C
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 每个节点的组号
        // 每条边有两个端点
        // 两个端点为不同组的边，u、uteam、v、vteam
        // 两个端点为不同组的边的数量
        // conflict[i] = true，表示i号组自己去划分二分图，依然有冲突
        // conflict[i] = false，表示i号组自己去划分二分图，没有冲突
        // 可撤销并查集
*/

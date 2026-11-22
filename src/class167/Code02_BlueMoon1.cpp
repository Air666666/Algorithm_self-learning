// 原题测试 / 参考链接（保留上游原始地址）
// https://loj.ac/p/6515

// Source: src/class167/Code02_BlueMoon1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_BlueMoon1 {
  inline static int MAXM = 50001;
  inline static int MAXP = 501;
  inline static int MAXT = 1000001;
  inline static int DEEP = 20;
  inline static int m = {};
  inline static int p = {};
  inline static Array<int> op = make_array<int>(MAXM);
  inline static Array<int> x = make_array<int>(MAXM);
  inline static Array<int> y = make_array<int>(MAXM);
  inline static JDeque<Array<int>> knapsack = JDeque<Array<int>>();
  inline static Array<int> head = make_array<int>(jshl(MAXM, 2));
  inline static Array<int> next = make_array<int>(MAXT);
  inline static Array<int> tow = make_array<int>(MAXT);
  inline static Array<int> tov = make_array<int>(MAXT);
  inline static int cnt = 0;
  inline static Array<i64> pre = make_array<i64>(MAXP);
  inline static Array<i64> dp = make_array<i64>(MAXP);
  inline static Array<Array<i64>> backup = make_array<i64>(DEEP, MAXP);
  inline static Array<i64> ans = make_array<i64>(MAXM);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_BlueMoon1() {}
  static void clone(Array<i64> a, Array<i64> b) {
    for (int i = 0; (i < p); (i++)) {
      (a[i] = b[i]);
    }
  }
  static void addEdge(int i, int w, int v) {
    (next[(++cnt)] = head[i]);
    (tow[cnt] = w);
    (tov[cnt] = v);
    (head[i] = cnt);
  }
  static void add(int jobl, int jobr, int jobw, int jobv, int l, int r, int i) {
    if (((jobl <= l) && (r <= jobr))) {
      Code02_BlueMoon1::addEdge(i, jobw, jobv);
    } else {
      int mid = jshr((l + r), 1);
      if ((jobl <= mid)) {
        Code02_BlueMoon1::add(jobl, jobr, jobw, jobv, l, mid, jshl(i, 1));
      }
      if ((jobr > mid)) {
        Code02_BlueMoon1::add(jobl, jobr, jobw, jobv, (mid + 1), r,
                              (jshl(i, 1) | 1));
      }
    }
  }
  static void dfs(int l, int r, int i, int dep) {
    Code02_BlueMoon1::clone(backup[dep], dp);
    {
      int e = head[i];
      int w = {};
      int v = {};
      for (; (e > 0); (e = next[e])) {
        (w = tow[e]);
        (v = tov[e]);
        Code02_BlueMoon1::clone(pre, dp);
        for (int j = 0; (j < p); (j++)) {
          if ((pre[j] != (-1))) {
            (dp[jrem((j + w), p)] = jmax(dp[jrem((j + w), p)], (pre[j] + v)));
          }
        }
      }
    }
    if ((l == r)) {
      if ((op[l] == 5)) {
        i64 ret = (-1);
        for (int j = x[l]; (j <= y[l]); (j++)) {
          (ret = jmax(ret, dp[j]));
        }
        (ans[l] = ret);
      }
    } else {
      int mid = jshr((l + r), 1);
      Code02_BlueMoon1::dfs(l, mid, jshl(i, 1), (dep + 1));
      Code02_BlueMoon1::dfs((mid + 1), r, (jshl(i, 1) | 1), (dep + 1));
    }
    Code02_BlueMoon1::clone(dp, backup[dep]);
  }
  static void prepare() {
    Array<int> equip = {};
    for (int i = 1; (i <= m); (i++)) {
      if ((op[i] == 1)) {
        knapsack.addFirst(Array<int>{jrem(x[i], p), y[i], i});
      } else if ((op[i] == 2)) {
        knapsack.addLast(Array<int>{jrem(x[i], p), y[i], i});
      } else if ((op[i] == 3)) {
        (equip = knapsack.pollFirst());
        Code02_BlueMoon1::add(equip[2], (i - 1), equip[0], equip[1], 1, m, 1);
      } else if ((op[i] == 4)) {
        (equip = knapsack.pollLast());
        Code02_BlueMoon1::add(equip[2], (i - 1), equip[0], equip[1], 1, m, 1);
      }
    }
    while ((!knapsack.isEmpty())) {
      (equip = knapsack.pollFirst());
      Code02_BlueMoon1::add(equip[2], m, equip[0], equip[1], 1, m, 1);
    }
    for (int i = 0; (i < p); (i++)) {
      (dp[i] = (-1));
    }
    (dp[0] = 0);
  }
  static void java_main(Array<String> args) {
    IO in = IO();
    IO out = IO(IO(jout));
    in.nextInt();
    (m = in.nextInt());
    (p = in.nextInt());
    String t = {};
    for (int i = 1; (i <= m); (i++)) {
      (t = in.nextString());
      if (t.equals(String(u"IF"))) {
        (op[i] = 1);
        (x[i] = in.nextInt());
        (y[i] = in.nextInt());
      } else if (t.equals(String(u"IG"))) {
        (op[i] = 2);
        (x[i] = in.nextInt());
        (y[i] = in.nextInt());
      } else if (t.equals(String(u"DF"))) {
        (op[i] = 3);
      } else if (t.equals(String(u"DG"))) {
        (op[i] = 4);
      } else {
        (op[i] = 5);
        (x[i] = in.nextInt());
        (y[i] = in.nextInt());
      }
    }
    Code02_BlueMoon1::prepare();
    Code02_BlueMoon1::dfs(1, m, 1, 1);
    for (int i = 1; (i <= m); (i++)) {
      if ((op[i] == 5)) {
        out.println(ans[i]);
      }
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code02_BlueMoon1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 贪玩蓝月，java版
//
每件装备都有特征值w和战斗力v，放装备的背包是一个双端队列，只有背包中的装备是可选的
// 给定数值p，接下来有m条操作，每种操作是如下五种类型中的一种
// 操作 IF x y : 背包前端加入一件特征值x、战斗力y的装备
// 操作 IG x y : 背包后端加入一件特征值x、战斗力y的装备
// 操作 DF     : 删除背包前端的装备
// 操作 DG     : 删除背包后端的装备
// 操作 QU x y : 选择装备的特征值累加和 % p，必须在[x,
y]范围，打印最大战斗力，无方案打印-1
// 1 <= m <= 5 * 10^4    1 <= p <= 500
// 0 <= 每件装备特征值、每件装备战斗力 <= 10^9
// 测试链接 : https://loj.ac/p/6515
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 背包<装备特征值%p、装备战斗力、装备出现时间点>
        // 时间轴线段树的区间上挂上生效的装备，(特征值 % p)记为w，战斗力记为v
        // 动态规划表不考虑当前装备的状态，上一行的状态
        // 动态规划表考虑当前装备的状态，本行的状态，需要更新
        // 动态规划表的备份
        // 答案
        // 读写工具类
*/

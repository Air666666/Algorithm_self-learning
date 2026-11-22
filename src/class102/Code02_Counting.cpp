// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P3311

// Source: src/class102/Code02_Counting.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_Counting {
  inline static int MOD = 1000000007;
  inline static int MAXN = 1301;
  inline static int MAXS = 2001;
  inline static Array<jchar> num = {};
  inline static int n = {};
  inline static Array<Array<int>> tree = make_array<int>(MAXS, 10);
  inline static Array<int> fail = make_array<int>(MAXS);
  inline static int cnt = 0;
  inline static Array<bool> alert = make_array<bool>(MAXS);
  inline static Array<int> queue = make_array<int>(MAXS);
  inline static Array<Array<Array<Array<int>>>> dp =
      make_array<int>(MAXN, MAXS, 2, 2);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_Counting() {}
  static void clear() {
    for (int i = 0; (i <= n); (i++)) {
      for (int j = 0; (j <= cnt); (j++)) {
        (dp[i][j][0][0] = (-1));
        (dp[i][j][0][1] = (-1));
        (dp[i][j][1][0] = (-1));
        (dp[i][j][1][1] = (-1));
      }
    }
  }
  static void insert(String word) {
    Array<jchar> w = word.toCharArray();
    int u = 0;
    {
      int j = 0;
      int c = {};
      for (; (j < w.length); (j++)) {
        (c = (w[j] - u'0'));
        if ((tree[u][c] == 0)) {
          (tree[u][c] = (++cnt));
        }
        (u = tree[u][c]);
      }
    }
    (alert[u] = true);
  }
  static void setFail() {
    int l = 0;
    int r = 0;
    for (int i = 0; (i <= 9); (i++)) {
      if ((tree[0][i] > 0)) {
        (queue[(r++)] = tree[0][i]);
      }
    }
    while ((l < r)) {
      int u = queue[(l++)];
      for (int i = 0; (i <= 9); (i++)) {
        if ((tree[u][i] == 0)) {
          (tree[u][i] = tree[fail[u]][i]);
        } else {
          (fail[tree[u][i]] = tree[fail[u]][i]);
          (queue[(r++)] = tree[u][i]);
        }
      }
      (alert[u] = (alert[u] | alert[fail[u]]));
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO(IO(jin));
    IO out = IO(IO(jout));
    (num = in.readLine().toCharArray());
    (n = num.length);
    int m = std::stoi(text(in.readLine()));
    for (int i = 1; (i <= m); (i++)) {
      Code02_Counting::insert(in.readLine());
    }
    Code02_Counting::setFail();
    Code02_Counting::clear();
    out.println(Code02_Counting::f1(0, 0, 0, 0));
    out.flush();
    out.close();
    in.close();
  }
  static int f1(int i, int j, int free, int has) {
    if (alert[j]) {
      return 0;
    }
    if ((i == n)) {
      return has;
    }
    if ((dp[i][j][free][has] != (-1))) {
      return dp[i][j][free][has];
    }
    int ans = 0;
    int cur = (num[i] - u'0');
    if ((has == 0)) {
      if ((free == 0)) {
        (ans = jrem((ans + Code02_Counting::f1((i + 1), 0, 1, 0)), MOD));
        for (int pick = 1; (pick < cur); (pick++)) {
          (ans = jrem((ans + Code02_Counting::f1((i + 1), tree[j][pick], 1, 1)),
                      MOD));
        }
        (ans = jrem((ans + Code02_Counting::f1((i + 1), tree[j][cur], 0, 1)),
                    MOD));
      } else {
        (ans = jrem((ans + Code02_Counting::f1((i + 1), 0, 1, 0)), MOD));
        for (int pick = 1; (pick <= 9); (pick++)) {
          (ans = jrem((ans + Code02_Counting::f1((i + 1), tree[j][pick], 1, 1)),
                      MOD));
        }
      }
    } else {
      if ((free == 0)) {
        for (int pick = 0; (pick < cur); (pick++)) {
          (ans = jrem((ans + Code02_Counting::f1((i + 1), tree[j][pick], 1, 1)),
                      MOD));
        }
        (ans = jrem((ans + Code02_Counting::f1((i + 1), tree[j][cur], 0, 1)),
                    MOD));
      } else {
        for (int pick = 0; (pick <= 9); (pick++)) {
          (ans = jrem((ans + Code02_Counting::f1((i + 1), tree[j][pick], 1, 1)),
                      MOD));
        }
      }
    }
    (dp[i][j][free][has] = ans);
    return ans;
  }
  static int f2(int i, int u, int free, int has) {
    if (alert[u]) {
      return 0;
    }
    if ((i == n)) {
      return has;
    }
    if ((dp[i][u][free][has] != (-1))) {
      return dp[i][u][free][has];
    }
    int limit = ((free == 0) ? (num[i] - u'0') : 9);
    int ans = 0;
    for (int pick = 0; (pick <= limit); (pick++)) {
      (ans = jrem((ans + Code02_Counting::f2(
                             (i + 1),
                             (((has == 0) && (pick == 0)) ? 0 : tree[u][pick]),
                             (((free == 0) && (pick == limit)) ? 0 : 1),
                             (((has == 0) && (pick == 0)) ? 0 : 1))),
                  MOD));
    }
    (dp[i][u][free][has] = ans);
    return ans;
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code02_Counting::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 数数(利用AC自动机检查命中)
// 我们称一个正整数x为幸运数字的条件为
// x的十进制中不包含数字串集合s中任意一个元素作为子串
// 例如s = { 22, 333, 0233 }
// 233是幸运数字，2333、20233、3223不是幸运数字
// 给定n和s，计算不大于n的幸运数字的个数
// 答案对1000000007取模
// 测试链接 : https://www.luogu.com.cn/problem/P3311
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下的code，提交时请把类名改成"Main"，可以直接通过
        // 目标字符串的数量
        // 所有目标字符串的总字符数量
        // 读入的数字
        // 读入数字的长度
        // AC自动机
        // 具体题目相关，本题为命中任何目标串就直接报警
        // 所以每个节点记录是否触发警报
        // 动态规划表
        // AC自动机加入目标字符串
        // 加入所有目标字符串之后
        // 设置fail指针 以及 设置直接跳转支路
        // 做了AC自动机固定的优化
        // 做了命中标记前移防止绕圈的优化
                        // 命中标记前移
                // AC自动机建树
                // 清空动态规划表
                // 执行记忆化搜索
                // out.println(f2(0, 0, 0, 0));
        // 逻辑分支都详细列出来的版本
        // i来到的位置
        // j : AC自动机里来到的节点编号
        // free : 是不是可以随意选择了
        // free = 0，不能随意选择数字，要考虑当前数字的大小
        // free = 1，能随意选择数字
        // has : 之前有没有选择过数字
        // has = 0，之前没选择过数字
        // has = 1，之前选择过数字
        // 返回i....幸运数字的个数
                                // 分支1 : 之前没有选择过数字 且
之前的决策等于num的前缀
                                // 能来到这里说明i一定是0位置, 那么cur必然不是0
                                // 当前选择不要数字
                                // 当前选择的数字比cur小
                                // 当前选择的数字为cur
                                // 分支2 : 之前没有选择过数字 且
之前的决策小于num的前缀
                                // 当前选择不要数字
                                // 当前可以选择1~9
                                // 分支3 : 之前已经选择过数字 且
之前的决策等于num的前缀
                                // 当前选择的数字比cur小
                                // 当前选择的数字为cur
                                // 分支4 : 之前已经选择过数字 且
之前的决策小于num的前缀
                                // 当前可以选择0~9
        // 逻辑合并版
        // 其实和f1方法完全一个意思
*/

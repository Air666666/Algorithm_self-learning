// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P6478
// https://oi-wiki.org/lang/java-pro/

// Source: src/class145/Code05_Game1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code05_Game1 {
  inline static int MAXN = 5001;
  inline static int MOD = 998244353;
  inline static int n = {};
  inline static int m = {};
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static Array<i64> fac = make_array<i64>(MAXN);
  inline static Array<Array<i64>> c = make_array<i64>(MAXN, MAXN);
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> next = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> to = make_array<int>(jshl(MAXN, 1));
  inline static int cnt = {};
  inline static Array<int> size = make_array<int>(MAXN);
  inline static Array<Array<int>> belong = make_array<int>(MAXN, 2);
  inline static Array<Array<i64>> dp = make_array<i64>(MAXN, MAXN);
  inline static Array<i64> backup = make_array<i64>(MAXN);
  inline static Array<i64> g = make_array<i64>(MAXN);
  inline static Array<i64> f = make_array<i64>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code05_Game1() {}
  static void build() {
    (cnt = 1);
    (fac[0] = 1);
    for (int i = 1; (i <= n); (i++)) {
      (head[i] = 0);
      (fac[i] = jrem((fac[(i - 1)] * i), MOD));
    }
    for (int i = 0; (i <= n); (i++)) {
      (c[i][0] = 1);
      for (int j = 1; (j <= i); (j++)) {
        (c[i][j] = jrem((c[(i - 1)][j] + c[(i - 1)][(j - 1)]), MOD));
      }
    }
  }
  static void addEdge(int u, int v) {
    (next[cnt] = head[u]);
    (to[cnt] = v);
    (head[u] = (cnt++));
  }
  static void dfs(int u, int fa) {
    (size[u] = 1);
    (belong[u][arr[u]] = 1);
    (dp[u][0] = 1);
    {
      int e = head[u];
      int v = {};
      for (; (e > 0); (e = next[e])) {
        (v = to[e]);
        if ((v != fa)) {
          Code05_Game1::dfs(v, u);
          for (int i = 0; (i <= jmin(jdiv(size[u], 2), m)); (i++)) {
            (backup[i] = dp[u][i]);
            (dp[u][i] = 0);
          }
          for (int l = 0; (l <= jmin(jdiv(size[u], 2), m)); (l++)) {
            for (int r = 0; (r <= jmin(jdiv(size[v], 2), (m - l))); (r++)) {
              (dp[u][(l + r)] = jrem(
                   (dp[u][(l + r)] + jrem((backup[l] * dp[v][r]), MOD)), MOD));
            }
          }
          (size[u] += size[v]);
          (belong[u][0] += belong[v][0]);
          (belong[u][1] += belong[v][1]);
        }
      }
    }
    int num = belong[u][(arr[u] ^ 1)];
    for (int i = 1; (i <= jmin(num, m)); (i++)) {
      (backup[i] = dp[u][i]);
    }
    for (int i = 1; (i <= jmin(num, m)); (i++)) {
      (dp[u][i] = jrem(
           (dp[u][i] + jrem((backup[(i - 1)] * ((num - i) + 1)), MOD)), MOD));
    }
  }
  static void compute() {
    Code05_Game1::dfs(1, 0);
    for (int i = 0; (i <= m); (i++)) {
      (g[i] = jrem((dp[1][i] * fac[(m - i)]), MOD));
    }
    for (int k = 0; (k <= m); (k++)) {
      for (int i = k; (i <= m); (i++)) {
        if ((((i - k) & 1) == 0)) {
          (f[k] = jrem((f[k] + jrem((c[i][k] * g[i]), MOD)), MOD));
        } else {
          (f[k] = jrem(
               (f[k] + jrem((jrem((c[i][k] * g[i]), MOD) * (MOD - 1)), MOD)),
               MOD));
        }
      }
    }
  }
  static void java_main(Array<String> args) {
    IO io = IO();
    (n = io.nextInt());
    (m = jshr(n, 1));
    Code05_Game1::build();
    String str = io.next();
    for (int i = 1; (i <= n); (i++)) {
      (arr[i] = (str.charAt((i - 1)) - u'0'));
    }
    {
      int i = 1;
      int u = {};
      int v = {};
      for (; (i < n); (i++)) {
        (u = io.nextInt());
        (v = io.nextInt());
        Code05_Game1::addEdge(u, v);
        Code05_Game1::addEdge(v, u);
      }
    }
    Code05_Game1::compute();
    for (int k = 0; (k <= m); (k++)) {
      io.println(f[k]);
    }
    io.flush();
    io.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code05_Game1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 游戏(递归版)
// 一共有n个节点，n <=
5000，n为偶数，其中有m个点属于小A，有m个点属于小B，m为n的一半
// 给定n-1条边，节点之间组成一颗树，1号节点是根节点
// 给定长度为n的数组arr，arr[i]的值表示i号节点由谁拥有，0为小A拥有，1为小B拥有
//
游戏有m回合，每回合都有胜负，两人需要选择一个自己拥有、但之前没选过的点，作为本回合当前点
//
小A当前点的子树里有小B当前点，则小A胜；小B当前点的子树里有小A当前点，则小B胜；否则平局
// 返回m回合里能出现k次非平局的游戏方法数，打印k=0..m时的所有答案，对 998244353
取模
//
两场游戏视为不同的定义：当且仅当存在小A拥有的点x，小B在小A选择x的那个回合所选择的点不同
// 测试链接 : https://www.luogu.com.cn/problem/P6478
// 提交以下的code，提交时请把类名改成"Main"，注意dfs是递归函数
// C++的同学可以全部通过，java的同学有时可以全部通过，有时因为递归展开太深而爆栈
// dfs从递归版改迭代版的实现，请看Code05_Game2文件
        // 链式前向星需要
        // dfs需要
        // 反演需要
        // 最后答案
        // 递归版
                // 首先计算不包含头节点的方法数
                                // 之前所有子树结合的计算结果，拷贝进backup
                                //
树型dp的枚举行为利用子树的节点数做上限进行复杂度优化
                // 最后计算包含头节点的方法数
                // 更新dp[u][i]，i可以把上限定为min(对手拥有的节点数，m)
                // u为头的子树中，对手有几个节点
                // 不包含头节点的方法数，拷贝到backup
                // 计算包含头节点的方法数，累加上
                                        // -1 和 (MOD-1) 同余
        // Kattio类IO效率很好，但还是不如StreamTokenizer
        // 只有StreamTokenizer无法正确处理时，才考虑使用这个类
        // 参考链接 : https://oi-wiki.org/lang/java-pro/
*/

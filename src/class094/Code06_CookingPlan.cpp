// Source: src/class094/Code06_CookingPlan.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code06_CookingPlan {
  struct Food;
  struct FoodCmp;
  struct Food {
    int a = {};
    int b = {};
    int c = {};
    String toString() const { return j::str(static_cast<const void *>(this)); }
    Food(int x, int y, int z) {
      (a = x);
      (b = y);
      (c = z);
    }
  };
  struct FoodCmp {
    String toString() const { return j::str(static_cast<const void *>(this)); }
    FoodCmp() {}
    int compare(Food *x, Food *y) {
      if (((static_cast<i64>(x->c) * static_cast<i64>(y->b)) <=
           (static_cast<i64>(y->c) * static_cast<i64>(x->b)))) {
        return (-1);
      } else {
        return 1;
      }
    }
  };
  inline static int MAXN = 51;
  inline static int MAXM = 100001;
  inline static int n = {};
  inline static int m = {};
  inline static Array<Food *> food = make_array<Food *>(MAXN);
  inline static Array<i64> dp = make_array<i64>(MAXM);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code06_CookingPlan() {}
  static i64 compute() {
    j::sort(food, 1, (n + 1), new FoodCmp());
    (dp[0] = 0);
    for (int i = 1; (i <= m); (i++)) {
      (dp[i] = (-1));
    }
    for (int i = 1; (i <= n); (i++)) {
      {
        int j = m;
        int p = (j - food[i]->c);
        for (; (p >= 0); (j--), (p--)) {
          if ((dp[p] != (-1))) {
            (dp[j] = jmax(dp[j], ((dp[p] + food[i]->a) -
                                  (static_cast<i64>(j) * food[i]->b))));
          }
        }
      }
    }
    i64 ans = 0;
    for (int i = 1; (i <= m); (i++)) {
      (ans = jmax(ans, dp[i]));
    }
    return ans;
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (m = in.nextInt());
    (n = in.nextInt());
    for (int i = 1; (i <= n); (i++)) {
      (food[i] = new Food(0, 0, 0));
    }
    for (int i = 1; (i <= n); (i++)) {
      (food[i]->a = in.nextInt());
    }
    for (int i = 1; (i <= n); (i++)) {
      (food[i]->b = in.nextInt());
    }
    for (int i = 1; (i <= n); (i++)) {
      (food[i]->c = in.nextInt());
    }
    i64 ans = Code06_CookingPlan::compute();
    out.println(ans);
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code06_CookingPlan::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 烹调方案
// 课上没有讲这个题，本节课的题目5，砍树问题，现在验证已经很困难了
// 所以找到这个题作为平替，因为贪心的思路是非常类似的
//
// 一共有n个食材，一共有m秒可以加工食材，你只能串行加工食材
// 每个食材的初始美味度为a[i]，美味衰减速度b[i]，加工花费c[i]秒
// 第i个食材美味度 = a[i] - t * b[i]，t是加工食材的时刻
// 计算m秒内，你能获得的最大美味度总和
// 1 <= n <= 50
// 其他数据 <= 10^5
// 测试链接 : https://www.luogu.com.cn/problem/P1417
// 提交以下的code，提交时请把类名改成"Main"，可以直接通过
//
// 本题的分析过程
// 假设当前来到s时刻，食材x和食材y，必须选择一个先加工
// 选择1，先加工x，后加工y，获得食材x的美味时刻是s，y的时刻是s + c[x]
// 选择1的美味度 = a[x] - s * b[x] + a[y] - (s + c[x]) * b[y]
//             = a[x] - s * b[x] + a[y] - s * b[y] - c[x] * b[y]
//
// 选择2，先加工y，后加工x，获得食材y的美味时刻是s，x的时刻是s + c[y]
// 选择2的美味度 = a[y] - s * b[y] + a[x] - (s + c[y]) * b[x]
//             = a[y] - s * b[y] + a[x] - s * b[x] - c[y] * b[x]
//
// 选择1和选择2的公共部分 = a[x] + a[y] - s * b[x] - s * b[y]，记为common
// 选择1 = common - c[x] * b[y]
// 选择2 = common - c[y] * b[x]
// 也就是说，如果c[x] * b[y] <= c[y] * b[x]，先选食材x，否则先选食材y
// 于是排序策略搞定了，剩下就和题目5一样了，01背包的解法，并且可以空间压缩
// 代码如下
        // 读写工具类
*/

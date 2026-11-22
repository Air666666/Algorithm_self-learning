// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P1776

// Source: src/class075/Code04_BoundedKnapsackWithMonotonicQueue.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_BoundedKnapsackWithMonotonicQueue {
  inline static int MAXN = 101;
  inline static int MAXW = 40001;
  inline static Array<int> v = make_array<int>(MAXN);
  inline static Array<int> w = make_array<int>(MAXN);
  inline static Array<int> c = make_array<int>(MAXN);
  inline static Array<int> dp = make_array<int>(MAXW);
  inline static Array<int> queue = make_array<int>(MAXW);
  inline static int l = {};
  inline static int r = {};
  inline static int n = {};
  inline static int t = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_BoundedKnapsackWithMonotonicQueue() {}
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    while ((in.nextToken() != -1)) {
      (n = static_cast<int>(in.nval));
      in.nextToken();
      (t = static_cast<int>(in.nval));
      for (int i = 1; (i <= n); (i++)) {
        in.nextToken();
        (v[i] = static_cast<int>(in.nval));
        in.nextToken();
        (w[i] = static_cast<int>(in.nval));
        in.nextToken();
        (c[i] = static_cast<int>(in.nval));
      }
      out.println(Code04_BoundedKnapsackWithMonotonicQueue::compute2());
    }
    out.flush();
    out.close();
    br.close();
  }
  static int compute1() {
    Array<Array<int>> dp = make_array<int>((n + 1), (t + 1));
    for (int i = 1; (i <= n); (i++)) {
      for (int mod = 0; (mod <= jmin(t, (w[i] - 1))); (mod++)) {
        (l = (r = 0));
        for (int j = mod; (j <= t); (j += w[i])) {
          while (((l < r) && [&]() {
            auto jleft = Code04_BoundedKnapsackWithMonotonicQueue::value1(
                dp, i, queue[(r - 1)]);
            auto jright =
                Code04_BoundedKnapsackWithMonotonicQueue::value1(dp, i, j);
            return (jleft <= jright);
          }())) {
            (r--);
          }
          (queue[(r++)] = j);
          if ((queue[l] == (j - (w[i] * (c[i] + 1))))) {
            (l++);
          }
          (dp[i][j] = (Code04_BoundedKnapsackWithMonotonicQueue::value1(
                           dp, i, queue[l]) +
                       (jdiv(j, w[i]) * v[i])));
        }
      }
    }
    return dp[n][t];
  }
  static int value1(Array<Array<int>> dp, int i, int j) {
    return (dp[(i - 1)][j] - (jdiv(j, w[i]) * v[i]));
  }
  static int compute2() {
    for (int i = 1; (i <= n); (i++)) {
      for (int mod = 0; (mod <= jmin(t, (w[i] - 1))); (mod++)) {
        (l = (r = 0));
        {
          int j = (t - mod);
          int cnt = 1;
          for (; ((j >= 0) && (cnt <= c[i])); (j -= w[i]), (cnt++)) {
            while (((l < r) && [&]() {
              auto jleft = Code04_BoundedKnapsackWithMonotonicQueue::value2(
                  i, queue[(r - 1)]);
              auto jright =
                  Code04_BoundedKnapsackWithMonotonicQueue::value2(i, j);
              return (jleft <= jright);
            }())) {
              (r--);
            }
            (queue[(r++)] = j);
          }
        }
        {
          int j = (t - mod);
          int enter = (j - (w[i] * c[i]));
          for (; (j >= 0); (j -= w[i]), (enter -= w[i])) {
            if ((enter >= 0)) {
              while (((l < r) && [&]() {
                auto jleft = Code04_BoundedKnapsackWithMonotonicQueue::value2(
                    i, queue[(r - 1)]);
                auto jright =
                    Code04_BoundedKnapsackWithMonotonicQueue::value2(i, enter);
                return (jleft <= jright);
              }())) {
                (r--);
              }
              (queue[(r++)] = enter);
            }
            (dp[j] = (Code04_BoundedKnapsackWithMonotonicQueue::value2(
                          i, queue[l]) +
                      (jdiv(j, w[i]) * v[i])));
            if ((queue[l] == j)) {
              (l++);
            }
          }
        }
      }
    }
    return dp[t];
  }
  static int value2(int i, int j) { return (dp[j] - (jdiv(j, w[i]) * v[i])); }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code04_BoundedKnapsackWithMonotonicQueue::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 多重背包单调队列优化
// 宝物筛选
// 一共有n种货物, 背包容量为t
// 每种货物的价值(v[i])、重量(w[i])、数量(c[i])都给出
// 请返回选择货物不超过背包容量的情况下，能得到的最大的价值
// 测试链接 : https://www.luogu.com.cn/problem/P1776
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下的code，提交时请把类名改成"Main"，可以直接通过
        // 严格位置依赖的动态规划 + 单调队列优化枚举
                        // 同余分组
        // 当前来到i号货物，需要j位置的指标，返回指标值
        // 空间压缩的动态规划 + 单调队列优化枚举
        // 因为求dp[i][j]时需要上一行左侧的若干格子
        // 所以做空间压缩时，每一行需要从右往左求
        // 以此来保证左侧的格子还没有更新，还是"上一行"的状况
                                // 先把c[i]个的指标进入单调队列
                                        // 窗口进入enter位置的指标
                                        // 计算dp[i][j]
                                        // 窗口弹出j位置的指标
        // 当前来到i号货物，需要j位置的指标，返回指标值
*/

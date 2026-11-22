// Source: src/class127/Code06_FrogCrossRiver.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code06_FrogCrossRiver {
  inline static int MAXN = 101;
  inline static int MAXL = 100001;
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static Array<int> where = make_array<int>(MAXN);
  inline static Array<int> dp = make_array<int>(MAXL);
  inline static Array<bool> stone = make_array<bool>(MAXL);
  inline static int n = {};
  inline static int s = {};
  inline static int t = {};
  inline static int m = {};
  inline static int safe = {};
  inline static int MAXK = 201;
  inline static Array<bool> reach = make_array<bool>(MAXK);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code06_FrogCrossRiver() {}
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    (n = static_cast<int>(in.nval));
    in.nextToken();
    (s = static_cast<int>(in.nval));
    in.nextToken();
    (t = static_cast<int>(in.nval));
    in.nextToken();
    (m = static_cast<int>(in.nval));
    for (int i = 1; (i <= m); (i++)) {
      in.nextToken();
      (arr[i] = static_cast<int>(in.nval));
    }
    out.println(Code06_FrogCrossRiver::compute());
    out.flush();
    out.close();
    br.close();
  }
  static int compute() {
    j::sort(arr, 1, (m + 1));
    if ((s == t)) {
      int ans = 0;
      for (int i = 1; (i <= m); (i++)) {
        if ((jrem(arr[i], s) == 0)) {
          (ans++);
        }
      }
      return ans;
    } else {
      (safe = Code06_FrogCrossRiver::reduce(s, t));
      for (int i = 1; (i <= m); (i++)) {
        (where[i] = (where[(i - 1)] + jmin((arr[i] - arr[(i - 1)]), safe)));
        (stone[where[i]] = true);
      }
      (n = (where[m] + safe));
      j::fill(dp, 1, (n + 1), MAXN);
      for (int i = 1; (i <= n); (i++)) {
        for (int j = jmax((i - t), 0); (j <= (i - s)); (j++)) {
          (dp[i] = jmin(dp[i], (dp[j] + (stone[i] ? 1 : 0))));
        }
      }
      int ans = MAXN;
      for (int i = (where[m] + 1); (i <= n); (i++)) {
        (ans = jmin(ans, dp[i]));
      }
      return ans;
    }
  }
  static int reduce(int s, int t) {
    j::fill(reach, false);
    int cnt = 0;
    int ans = 0;
    for (int i = 0; (i < MAXK); (i++)) {
      for (int j = (i + s); (j < jmin(((i + t) + 1), MAXK)); (j++)) {
        (reach[j] = true);
      }
      if ((!reach[i])) {
        (cnt = 0);
      } else {
        (cnt++);
      }
      if ((cnt == t)) {
        (ans = i);
        break;
      }
    }
    return ans;
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code06_FrogCrossRiver::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 过河踩过的最少石子数
// 在河上有一座独木桥，一只青蛙想沿着独木桥从河的一侧跳到另一侧
// 在桥上有一些石子，青蛙很讨厌踩在这些石子上
// 我们可以把独木桥上青蛙可能到达的点看成数轴上的一串整点0...n
// 其中n是桥的长度，坐标为0的点表示桥的起点，坐标为n的点表示桥的终点
//
青蛙从桥的起点开始，不停的向终点方向跳跃，一次跳跃的距离是[s,t]之间的任意正整数
// 当青蛙跳到或跳过坐标为n的点时，就算青蛙已经跳出了独木桥
// 题目给出独木桥的长度n，青蛙跳跃的距离范围s、t，题目还给定m个桥上石子的位置
// 你的任务是确定青蛙要想过河，最少需要踩到的石子数
// 1 <= n <= 10^7
// 1 <= s <= t <= 10
// 1 <= m <= 100
// 测试链接 : https://www.luogu.com.cn/problem/P1052
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有用例
                        // 可以直接给一个足够安全的距离，不需要算
                        // 因为s和t不大，都<= 10
                        // safe = 201;
                        // where[m] + safe : 最后一颗石子 + 安全距离
                        //
过了这个安全距离之后，dp值不会再有变化，也不会再遇到石子
        // 一旦s和t定了，那么距离多远就可以缩减呢？
        // 做实验！
*/

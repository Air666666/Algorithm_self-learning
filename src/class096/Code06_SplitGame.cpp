// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P3185

// Source: src/class096/Code06_SplitGame.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code06_SplitGame {
  inline static int MAXN = 21;
  inline static Array<int> nums = make_array<int>(MAXN);
  inline static Array<int> sg = make_array<int>(MAXN);
  inline static int MAXV = 101;
  inline static Array<bool> appear = make_array<bool>(MAXV);
  inline static int t = {};
  inline static int n = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code06_SplitGame() {}
  static void build() {
    for (int i = 1; (i < MAXN); (i++)) {
      j::fill(appear, false);
      for (int j = (i - 1); (j >= 0); (j--)) {
        for (int k = j; (k >= 0); (k--)) {
          (appear[(sg[j] ^ sg[k])] = true);
        }
      }
      for (int s = 0; (s < MAXV); (s++)) {
        if ((!appear[s])) {
          (sg[i] = s);
          break;
        }
      }
    }
  }
  static void java_main(Array<String> args) {
    Code06_SplitGame::build();
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    (t = static_cast<int>(in.nval));
    for (int i = 0; (i < t); (i++)) {
      in.nextToken();
      (n = static_cast<int>(in.nval));
      for (int j = (n - 1); (j >= 0); (j--)) {
        in.nextToken();
        (nums[j] = static_cast<int>(in.nval));
      }
      out.println(Code06_SplitGame::compute());
    }
    out.flush();
    out.close();
    br.close();
  }
  static String compute() {
    int eor = 0;
    for (int i = (n - 1); (i >= 0); (i--)) {
      if ((jrem(nums[i], 2) == 1)) {
        (eor ^= sg[i]);
      }
    }
    if ((eor == 0)) {
      return (String(u"-1 -1 -1\n") + String(u"0"));
    }
    int cnt = 0;
    int a = (-1);
    int b = (-1);
    int c = (-1);
    int pos = {};
    for (int i = (n - 1); (i >= 1); (i--)) {
      if ((nums[i] > 0)) {
        for (int j = (i - 1); (j >= 0); (j--)) {
          for (int k = j; (k >= 0); (k--)) {
            (pos = (((eor ^ sg[i]) ^ sg[j]) ^ sg[k]));
            if ((pos == 0)) {
              (cnt++);
              if ((a == (-1))) {
                (a = i);
                (b = j);
                (c = k);
              }
            }
          }
        }
      }
    }
    return j::str(
        ((((((((n - 1) - a) + String(u" ")) + ((n - 1) - b)) + String(u" ")) +
           ((n - 1) - c)) +
          String(u"\n")) +
         cnt));
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code06_SplitGame::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 分裂游戏
// 一共有n个瓶子，编号为0 ~ n-1，第i瓶里装有nums[i]个糖豆，每个糖豆认为无差别
// 有两个玩家轮流取糖豆，每一轮的玩家必须选i、j、k三个编号，并且满足i < j <= k
//
当前玩家从i号瓶中拿出一颗糖豆，分裂成两颗糖豆，并且往j、k瓶子中各放入一颗，分裂的糖豆继续无差别
// 要求i号瓶一定要有糖豆，如果j ==
k，那么相当于从i号瓶中拿出一颗，向另一个瓶子放入了两颗
// 如果轮到某个玩家发现所有糖豆都在n-1号瓶里，导致无法行动，那么该玩家输掉比赛
// 先手希望知道，第一步如何行动可以保证自己获胜，要求返回字典序最小的行动
// 第一步从0号瓶拿出一颗糖豆，并且往2、3号瓶中各放入一颗，可以确保最终自己获胜
// 第一步从0号瓶拿出一颗糖豆，并且往11、13号瓶中各放入一颗，也可以确保自己获胜
// 本题要求每个瓶子的编号看做是一个字符的情况下，最小的字典序，所以返回"0 2 3"
// 如果先手怎么行动都无法获胜，返回"-1 -1 -1"
// 先手还希望知道自己有多少种第一步取糖的行动，可以确保自己获胜，返回方法数
// 测试链接 : https://www.luogu.com.cn/problem/P3185
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下的code，提交时请把类名改成"Main"，可以直接通过
        // 20 -> 0
        // 左    右
                                                // i j k
*/

// Source: src/class096/Code02_NimGameSG.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_NimGameSG {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_NimGameSG() {}
  static String nim1(Array<int> arr) {
    int eor = 0;
    for (int num : arr) {
      (eor ^= num);
    }
    return ((eor != 0) ? String(u"先手") : String(u"后手"));
  }
  static String nim2(Array<int> arr) {
    int max = 0;
    for (int num : arr) {
      (max = jmax(max, num));
    }
    Array<int> sg = make_array<int>((max + 1));
    Array<bool> appear = make_array<bool>((max + 1));
    for (int i = 1; (i <= max); (i++)) {
      j::fill(appear, false);
      for (int j = 0; (j < i); (j++)) {
        (appear[j] = true);
      }
      for (int s = 0; (s <= max); (s++)) {
        if ((!appear[s])) {
          (sg[i] = s);
          break;
        }
      }
    }
    int eor = 0;
    for (int num : arr) {
      (eor ^= sg[num]);
    }
    return ((eor != 0) ? String(u"先手") : String(u"后手"));
  }
  static Array<int> randomArray(int n, int v) {
    Array<int> ans = make_array<int>(n);
    for (int i = 0; (i < n); (i++)) {
      (ans[i] = static_cast<int>((j::random() * v)));
    }
    return ans;
  }
  static void java_main(Array<String> args) {
    int N = 200;
    int V = 1000;
    int testTimes = 10000;
    jout.println(String(u"测试开始"));
    for (int i = 0; (i < testTimes); (i++)) {
      int n = (static_cast<int>((j::random() * N)) + 1);
      Array<int> arr = Code02_NimGameSG::randomArray(n, V);
      String ans1 = Code02_NimGameSG::nim1(arr);
      String ans2 = Code02_NimGameSG::nim2(arr);
      if ((!ans1.equals(ans2))) {
        jout.println(String(u"出错了!"));
      }
    }
    jout.println(String(u"测试结束"));
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code02_NimGameSG::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 尼姆博弈(SG定理简单用法展示)
// 一共有 n 堆石头，两人轮流进行游戏
// 在每个玩家的回合中，玩家需要 选择任一 非空 石头堆，从中移除任意 非零
数量的石头
// 如果不能移除任意的石头，就输掉游戏
// 返回先手是否一定获胜
// 对数器验证
        // 时间复杂度O(n)
        // 充分研究了性质
        // sg函数去求解
        // 过程时间复杂度高，但是可以轻易发现规律，进而优化成最优解
        // 证明不好想，但是从sg表出发，去观察最终的解，要好做很多
                // 打印sg表之后，可以发现，sg[x] = x
                // 那么eor ^= sg[num] 等同于 eor ^= num
                // 从sg定理发现了最优解
        // 为了验证
*/

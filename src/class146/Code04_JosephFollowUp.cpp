// Source: src/class146/Code04_JosephFollowUp.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_JosephFollowUp {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_JosephFollowUp() {}
  static int joseph1(int n, Array<int> arr) {
    if ((n == 1)) {
      return 1;
    }
    Array<int> next = make_array<int>((n + 1));
    for (int i = 1; (i < n); (i++)) {
      (next[i] = (i + 1));
    }
    (next[n] = 1);
    int pre = n;
    int cur = 1;
    for (int i = 1; (i < n); (i++)) {
      for (int cnt = 1; (cnt < arr[i]); (cnt++)) {
        (pre = cur);
        (cur = next[cur]);
      }
      (next[pre] = next[cur]);
      (cur = next[cur]);
    }
    return cur;
  }
  static int joseph2(int n, Array<int> arr) {
    if ((n == 1)) {
      return 1;
    }
    int ans = 1;
    {
      int c = 2;
      int i = (n - 1);
      for (; (c <= n); (c++), (i--)) {
        (ans = (jrem(((ans + arr[i]) - 1), c) + 1));
      }
    }
    return ans;
  }
  static Array<int> randomArray(int n, int v) {
    Array<int> arr = make_array<int>(n);
    for (int i = 1; (i < n); (i++)) {
      (arr[i] = (static_cast<int>((j::random() * v)) + 1));
    }
    return arr;
  }
  static void java_main(Array<String> args) {
    int N = 100;
    int V = 500;
    int test = 10000;
    jout.println(String(u"测试开始"));
    for (int i = 1; (i <= test); (i++)) {
      int n = (static_cast<int>((j::random() * N)) + 1);
      Array<int> arr = Code04_JosephFollowUp::randomArray(n, V);
      int ans1 = Code04_JosephFollowUp::joseph1(n, arr);
      int ans2 = Code04_JosephFollowUp::joseph2(n, arr);
      if ((ans1 != ans2)) {
        jout.println(String(u"出错了!"));
      }
    }
    jout.println(String(u"测试结束"));
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code04_JosephFollowUp::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 约瑟夫环问题加强
// 一共有1~n这些点，组成首尾相接的环，游戏一共有n-1轮，每轮给定一个数字arr[i]
// 第一轮游戏中，1号点从数字1开始报数，哪个节点报到数字arr[1]，就删除该节点
// 然后下一个节点从数字1开始重新报数，游戏进入第二轮
// 第i轮游戏中，哪个节点报到数字arr[i]，就删除该节点
// 然后下一个节点从数字1开始重新报数，游戏进入第i+1轮
// 最终环上会剩下一个节点, 返回该节点的编号
// 1 <= n, arr[i] <= 10^6
// 来自真实大厂笔试，对数器验证
        // 暴力模拟
        // 为了测试
        // 正式方法
        // 时间复杂度O(n)
        // 随机生成每轮报数
        // 为了测试
        // 对数器
        // 为了测试
*/

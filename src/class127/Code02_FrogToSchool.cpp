// Source: src/class127/Code02_FrogToSchool.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_FrogToSchool {
  inline static int MAXN = 100001;
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static int n = {};
  inline static int x = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_FrogToSchool() {}
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    (n = static_cast<int>(in.nval));
    in.nextToken();
    (x = static_cast<int>(in.nval));
    for (int i = 1; (i < n); (i++)) {
      in.nextToken();
      (arr[i] = static_cast<int>(in.nval));
    }
    (arr[n] = (2 * x));
    out.println(Code02_FrogToSchool::compute());
    out.flush();
    out.close();
    br.close();
  }
  static int compute() {
    int ans = 0;
    i64 sum = arr[1];
    {
      int l = 1;
      int r = 2;
      for (; (l <= n); (l++)) {
        while ((sum < (x * 2))) {
          (sum += arr[(r++)]);
        }
        (ans = jmax(ans, (r - l)));
        (sum -= arr[l]);
      }
    }
    return ans;
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code02_FrogToSchool::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 上学需要的最少跳跃能力
// 青蛙住在一条河边，家在0位置, 每天到河对岸的上学，学校在n位置
// 河里的石头排成了一条直线，青蛙每次跳跃必须落在一块石头或者岸上
// 给定一个长度为n-1的数组arr，表示1~n-1位置每块石头的高度数值
// 每次青蛙从一块石头起跳，这块石头的高度就会下降1
//
当石头的高度下降到0时，青蛙不能再跳到这块石头上，跳跃后使石头高度下降到0是允许的
// 青蛙一共需要去学校上x天课, 所以它需要往返x次，青蛙具有跳跃能力y,
它可以跳跃不超过y的距离
// 请问青蛙的跳跃能力至少是多少，才能用这些石头往返x次
// 1 <= n <= 10^5
// 1 <= arr[i] <= 10^4
// 1 <= x <= 10^9
// 测试链接 : https://www.luogu.com.cn/problem/P8775
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有用例
                // 认为学校所在的位置n，有足够的高度
                // 窗口[l,r)，左闭右开！左闭右开！左闭右开！
                // 窗口内的累加和是sum
                //
当r来到n+1位置，那么窗口一定无法继续右扩了，因为n位置有足够的高度
*/

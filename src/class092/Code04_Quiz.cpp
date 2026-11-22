// 原题测试 / 参考链接（保留上游原始地址）
// https://www.nowcoder.com/practice/2a9089ea7e5b474fa8f688eae76bc050

// Source: src/class092/Code04_Quiz.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_Quiz {
  inline static int MAXN = 200001;
  inline static Array<Array<int>> nums = make_array<int>(MAXN, 2);
  inline static int n = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_Quiz() {}
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    while ((in.nextToken() != -1)) {
      (n = static_cast<int>(in.nval));
      for (int i = 0; (i < n); (i++)) {
        in.nextToken();
        (nums[i][0] = static_cast<int>(in.nval));
        in.nextToken();
        (nums[i][1] = static_cast<int>(in.nval));
      }
      int ans = Code04_Quiz::compute();
      out.println(jdiv(static_cast<double>(ans), 2));
    }
    out.flush();
    out.close();
    br.close();
  }
  static int compute() {
    j::sort(nums, 0, n, [=](Array<int> a, Array<int> b) {
      return [&]() {
        auto jleft = std::abs((a[0] - a[1]));
        auto jright = std::abs((b[0] - b[1]));
        return (jleft - jright);
      }();
    });
    int maxA = nums[0][0];
    int maxB = nums[0][1];
    int ans = 0;
    for (int i = 1; (i < n); (i++)) {
      if ((nums[i][0] <= nums[i][1])) {
        (ans = jmax(ans, (maxA + nums[i][0])));
      } else {
        (ans = jmax(ans, (maxB + nums[i][1])));
      }
      (maxA = jmax(maxA, nums[i][0]));
      (maxB = jmax(maxB, nums[i][1]));
    }
    return ans;
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code04_Quiz::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 知识竞赛
// 最近部门要选两个员工去参加一个需要合作的知识竞赛，
// 每个员工均有一个推理能力值ai，以及一个阅读能力值bi
// 如果选择第i个人和第j个人去参加竞赛，
// 两人在推理方面的能力为X = (ai + aj)/2
// 两人在阅读方面的能力为Y = (bi + bj)/2
// 现在需要最大化他们表现较差一方面的能力
// 即让min(X,Y) 尽可能大，问这个值最大是多少
// 测试链接 : https://www.nowcoder.com/practice/2a9089ea7e5b474fa8f688eae76bc050
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下的code，提交时请把类名改成"Main"，可以直接通过
*/

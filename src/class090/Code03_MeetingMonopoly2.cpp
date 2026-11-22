// Source: src/class090/Code03_MeetingMonopoly2.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_MeetingMonopoly2 {
  inline static int MAXN = 1000001;
  inline static Array<int> latest = make_array<int>(MAXN);
  inline static int n = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_MeetingMonopoly2() {}
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    while ((in.nextToken() != -1)) {
      (n = static_cast<int>(in.nval));
      for (int i = 0; (i < MAXN); (i++)) {
        (latest[i] = (-1));
      }
      {
        int i = 0;
        int start = {};
        int end = {};
        for (; (i < n); (i++)) {
          in.nextToken();
          (start = static_cast<int>(in.nval));
          in.nextToken();
          (end = static_cast<int>(in.nval));
          if ((latest[end] == (-1))) {
            (latest[end] = start);
          } else {
            (latest[end] = jmax(latest[end], start));
          }
        }
      }
      out.println(Code03_MeetingMonopoly2::compute());
    }
    out.flush();
    out.close();
    br.close();
  }
  static int compute() {
    int ans = 0;
    {
      int cur = 0;
      int end = 0;
      for (; (end < MAXN); (end++)) {
        if ((cur <= latest[end])) {
          (ans++);
          (cur = end);
        }
      }
    }
    return ans;
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code03_MeetingMonopoly2::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 同学找到了洛谷的在线测试，看似是题目3，其实不是
// 区别在于数据量，如下测试链接中的题目
// 会议的数量10^6，会议的开始、结束时间也是10^6
// 排序会超时，C++的同学可能不会，但是java的同学会
// 而且根据这个数据量，最优解一定不是排序！
// 会议开始、结束时间也是10^6规模，所以不排序也可以做，具体看如下代码和注释
// 并不是课上讲错了，而是这个数据状况太特殊
// 测试链接 : https://www.luogu.com.cn/problem/P1803
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下的code，提交时请把类名改成"Main"，可以直接通过
        // 既是会议的规模，也是开始、结束时间的规模
        // latest[60] == 40
        // 表示 : 结束时间是60的所有会议中，最晚开始的会议是40的时候开始
        // 比如会议[1, 60]、[30, 60]、[40, 60]
        // 这些会议都在60结束，但是最晚开始的会议是40开始
        // 如果latest[60] == -1
        // 表示没有任何会议在60结束
                                        // 如果结束时间在end的会议之前没发现过
                                        // 现在发现了
                                        // 如果结束时间在end的会议之前发现过
                                        // 记录最晚的开始时间
                // 不排序
                // 根据时间遍历
                        // cur :
cur之前不能再安排会议，因为安排会议的人来到了cur时刻
                        // end是当前的结束时间
                        // 所有以end结束的会议，最晚的开始时间是latest[end]
                        // 如果cur <=
latest[end]，那么说明可以安排当前以end结束的会议
*/

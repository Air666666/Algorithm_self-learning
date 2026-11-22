// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P3374

// Source: src/class108/Code01_IndexTreeSingleAddIntervalQuery.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_IndexTreeSingleAddIntervalQuery {
  inline static int MAXN = 500001;
  inline static Array<int> tree = make_array<int>(MAXN);
  inline static int n = {};
  inline static int m = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_IndexTreeSingleAddIntervalQuery() {}
  static int lowbit(int i) { return (i & (-i)); }
  static void add(int i, int v) {
    while ((i <= n)) {
      (tree[i] += v);
      (i += Code01_IndexTreeSingleAddIntervalQuery::lowbit(i));
    }
  }
  static int sum(int i) {
    int ans = 0;
    while ((i > 0)) {
      (ans += tree[i]);
      (i -= Code01_IndexTreeSingleAddIntervalQuery::lowbit(i));
    }
    return ans;
  }
  static int range(int l, int r) {
    return [&]() {
      auto jleft = Code01_IndexTreeSingleAddIntervalQuery::sum(r);
      auto jright = Code01_IndexTreeSingleAddIntervalQuery::sum((l - 1));
      return (jleft - jright);
    }();
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    (n = static_cast<int>(in.nval));
    in.nextToken();
    (m = static_cast<int>(in.nval));
    {
      int i = 1;
      int v = {};
      for (; (i <= n); (i++)) {
        in.nextToken();
        (v = static_cast<int>(in.nval));
        Code01_IndexTreeSingleAddIntervalQuery::add(i, v);
      }
    }
    {
      int i = 1;
      int a = {};
      int b = {};
      int c = {};
      for (; (i <= m); (i++)) {
        in.nextToken();
        (a = static_cast<int>(in.nval));
        in.nextToken();
        (b = static_cast<int>(in.nval));
        in.nextToken();
        (c = static_cast<int>(in.nval));
        if ((a == 1)) {
          Code01_IndexTreeSingleAddIntervalQuery::add(b, c);
        } else {
          out.println(Code01_IndexTreeSingleAddIntervalQuery::range(b, c));
        }
      }
    }
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code01_IndexTreeSingleAddIntervalQuery::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 树状数组单点增加、范围查询模版
// 测试链接 : https://www.luogu.com.cn/problem/P3374
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下的code，提交时请把类名改成"Main"，可以直接通过
        // 原始数组的信息，根据课上说的关系，维护在树状数组中
        // 注意下标一定从1开始，不从0开始
        // 得到i最右侧的1的状态
        // 其他位都是0
        // 返回1~i范围累加和
*/

// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P3368

// Source: src/class108/Code02_IndexTreeIntervalAddSingleQuery.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_IndexTreeIntervalAddSingleQuery {
  inline static int MAXN = 500002;
  inline static Array<int> tree = make_array<int>(MAXN);
  inline static int n = {};
  inline static int m = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_IndexTreeIntervalAddSingleQuery() {}
  static int lowbit(int i) { return (i & (-i)); }
  static void add(int i, int v) {
    while ((i <= n)) {
      (tree[i] += v);
      (i += Code02_IndexTreeIntervalAddSingleQuery::lowbit(i));
    }
  }
  static int sum(int i) {
    int ans = 0;
    while ((i > 0)) {
      (ans += tree[i]);
      (i -= Code02_IndexTreeIntervalAddSingleQuery::lowbit(i));
    }
    return ans;
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
        Code02_IndexTreeIntervalAddSingleQuery::add(i, v);
        Code02_IndexTreeIntervalAddSingleQuery::add((i + 1), (-v));
      }
    }
    for (int i = 1; (i <= m); (i++)) {
      in.nextToken();
      int op = static_cast<int>(in.nval);
      if ((op == 1)) {
        in.nextToken();
        int l = static_cast<int>(in.nval);
        in.nextToken();
        int r = static_cast<int>(in.nval);
        in.nextToken();
        int v = static_cast<int>(in.nval);
        Code02_IndexTreeIntervalAddSingleQuery::add(l, v);
        Code02_IndexTreeIntervalAddSingleQuery::add((r + 1), (-v));
      } else {
        in.nextToken();
        int index = static_cast<int>(in.nval);
        out.println(Code02_IndexTreeIntervalAddSingleQuery::sum(index));
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
  Code02_IndexTreeIntervalAddSingleQuery::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 树状数组范围增加、单点查询模版
// 测试链接 : https://www.luogu.com.cn/problem/P3368
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下的code，提交时请把类名改成"Main"，可以直接通过
        // 树状数组不维护原数组的信息，维护原数组的差分信息
        // 注意下标一定从1开始，不从0开始
        // 返回1~i范围累加和
*/

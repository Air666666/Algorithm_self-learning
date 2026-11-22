// Source: src/class108/Code03_IndexTreeIntervalAddIntervalQuery.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_IndexTreeIntervalAddIntervalQuery {
  inline static int MAXN = 100001;
  inline static Array<i64> info1 = make_array<i64>(MAXN);
  inline static Array<i64> info2 = make_array<i64>(MAXN);
  inline static int n = {};
  inline static int m = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_IndexTreeIntervalAddIntervalQuery() {}
  static int lowbit(int i) { return (i & (-i)); }
  static void add(Array<i64> tree, int i, i64 v) {
    while ((i <= n)) {
      (tree[i] += v);
      (i += Code03_IndexTreeIntervalAddIntervalQuery::lowbit(i));
    }
  }
  static i64 sum(Array<i64> tree, int i) {
    i64 ans = 0;
    while ((i > 0)) {
      (ans += tree[i]);
      (i -= Code03_IndexTreeIntervalAddIntervalQuery::lowbit(i));
    }
    return ans;
  }
  static void add(int l, int r, i64 v) {
    Code03_IndexTreeIntervalAddIntervalQuery::add(info1, l, v);
    Code03_IndexTreeIntervalAddIntervalQuery::add(info1, (r + 1), (-v));
    Code03_IndexTreeIntervalAddIntervalQuery::add(info2, l, ((l - 1) * v));
    Code03_IndexTreeIntervalAddIntervalQuery::add(info2, (r + 1), (-(r * v)));
  }
  static i64 range(int l, int r) {
    return [&]() {
      auto jleft = [&]() {
        auto jleft = [&]() {
          auto jleft =
              (Code03_IndexTreeIntervalAddIntervalQuery::sum(info1, r) * r);
          auto jright = Code03_IndexTreeIntervalAddIntervalQuery::sum(info2, r);
          return (jleft - jright);
        }();
        auto jright =
            (Code03_IndexTreeIntervalAddIntervalQuery::sum(info1, (l - 1)) *
             (l - 1));
        return (jleft - jright);
      }();
      auto jright =
          Code03_IndexTreeIntervalAddIntervalQuery::sum(info2, (l - 1));
      return (jleft + jright);
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
    i64 cur = {};
    for (int i = 1; (i <= n); (i++)) {
      in.nextToken();
      (cur = static_cast<i64>(in.nval));
      Code03_IndexTreeIntervalAddIntervalQuery::add(i, i, cur);
    }
    i64 v = {};
    {
      int i = 1;
      int op = {};
      int l = {};
      int r = {};
      for (; (i <= m); (i++)) {
        in.nextToken();
        (op = static_cast<int>(in.nval));
        if ((op == 1)) {
          in.nextToken();
          (l = static_cast<int>(in.nval));
          in.nextToken();
          (r = static_cast<int>(in.nval));
          in.nextToken();
          (v = static_cast<i64>(in.nval));
          Code03_IndexTreeIntervalAddIntervalQuery::add(l, r, v);
        } else {
          in.nextToken();
          (l = static_cast<int>(in.nval));
          in.nextToken();
          (r = static_cast<int>(in.nval));
          out.println(Code03_IndexTreeIntervalAddIntervalQuery::range(l, r));
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
  Code03_IndexTreeIntervalAddIntervalQuery::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 树状数组范围增加、范围查询模版
// 测试链接 : https://www.luogu.com.cn/problem/P3372
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下的code，提交时请把类名改成"Main"，可以直接通过
        // 维护原始数组的差分信息：Di
        // 维护原始数组的差分加工信息：(i-1) * Di
        // 原始数组中[l..r]每个数值+v
        // 原始数组中[l..r]范围上的累加和
*/

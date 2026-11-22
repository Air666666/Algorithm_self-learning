// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P1347

// Source: src/class207/Code07_Sorting1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code07_Sorting1 {
  inline static int MAXN = 27;
  inline static int MAXM = 601;
  inline static int n = {};
  inline static int m = {};
  inline static Array<int> a = make_array<int>(MAXM);
  inline static Array<int> b = make_array<int>(MAXM);
  inline static Array<BitSet> dp = make_array<BitSet>(MAXN);
  inline static int ans = {};
  inline static int kth = {};
  inline static Array<jchar> order = make_array<jchar>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code07_Sorting1() {}
  static void floyd() {
    for (int bridge = 1; (bridge <= n); (bridge++)) {
      for (int i = 1; (i <= n); (i++)) {
        if (dp[i].get(bridge)) {
          dp[i].or_java(dp[bridge]);
        }
      }
    }
  }
  static int check() {
    for (int i = 1; (i <= n); (i++)) {
      if (dp[i].get(i)) {
        return 2;
      }
    }
    for (int i = 1; (i <= n); (i++)) {
      for (int j = (i + 1); (j <= n); (j++)) {
        if (((!dp[i].get(j)) && (!dp[j].get(i)))) {
          return 0;
        }
      }
    }
    return 1;
  }
  static void compute() {
    (ans = 0);
    for (int i = 1; (i <= m); (i++)) {
      dp[a[i]].set(b[i]);
      Code07_Sorting1::floyd();
      (ans = Code07_Sorting1::check());
      if (((ans == 1) || (ans == 2))) {
        (kth = i);
        break;
      }
    }
    if ((ans == 1)) {
      for (int i = 1; (i <= n); (i++)) {
        (order[(n - dp[i].cardinality())] =
             static_cast<jchar>(((u'A' + i) - 1)));
      }
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (m = in.nextInt());
    for (int i = 1; (i <= n); (i++)) {
      (dp[i] = BitSet((n + 1)));
    }
    jchar s1 = {};
    jchar s2 = {};
    for (int i = 1; (i <= m); (i++)) {
      (s1 = in.nextChar());
      in.nextChar();
      (s2 = in.nextChar());
      (a[i] = ((s1 - u'A') + 1));
      (b[i] = ((s2 - u'A') + 1));
    }
    Code07_Sorting1::compute();
    if ((ans == 0)) {
      out.println(String(u"Sorted sequence cannot be determined."));
    } else if ((ans == 1)) {
      out.print(((String(u"Sorted sequence determined after ") + kth) +
                 String(u" relations: ")));
      for (int i = 1; (i <= n); (i++)) {
        out.print(order[i]);
      }
      out.println(String(u"."));
    } else {
      out.println(((String(u"Inconsistency found after ") + kth) +
                   String(u" relations.")));
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code07_Sorting1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 排序，java版
// 一共n个元素，用大写字母 A、B、C... 表示，元素的值互不相同
// 给定m条大小关系，格式为 A<B，表示A的值小于B，大小关系具有传递性
// 按输入顺序逐条考虑这些关系，判断以下情况
// 如果首次在前k条关系后，已经能唯一确定完整排名，输出k和升序序列，然后结束
// 输出 Sorted sequence determined after {k} relations: {升序序列}.
// 如果首次在前k条关系后，发现了矛盾，那么停止判断，不再考虑后续的关系
// 输出 Inconsistency found after {k} relations.
// 如果考察完所有m条关系，仍然没有矛盾，但无法唯一确定完整排名
// 输出 Sorted sequence cannot be determined.
// 2 <= n <= 26    1 <= m <= 600
// 测试链接 : https://www.luogu.com.cn/problem/P1347
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 顺序未确定返回0，顺序确定返回1，出现矛盾返回2
        // 读写工具类
*/

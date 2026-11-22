// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P2709

// Source: src/class176/Code02_QueryFromB1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_QueryFromB1 {
  struct QueryCmp;
  struct QueryCmp {
    String toString() const { return j::str(static_cast<const void *>(this)); }
    QueryCmp() {}
    int compare(Array<int> a, Array<int> b) {
      if ((bi[a[0]] != bi[b[0]])) {
        return (bi[a[0]] - bi[b[0]]);
      }
      return (a[1] - b[1]);
    }
  };
  inline static int MAXN = 50001;
  inline static int n = {};
  inline static int m = {};
  inline static int k = {};
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static Array<Array<int>> query = make_array<int>(MAXN, 3);
  inline static Array<int> bi = make_array<int>(MAXN);
  inline static Array<int> cnt = make_array<int>(MAXN);
  inline static int sum = 0;
  inline static Array<int> ans = make_array<int>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_QueryFromB1() {}
  static void del(int num) {
    (sum -= (cnt[num] * cnt[num]));
    (cnt[num]--);
    (sum += (cnt[num] * cnt[num]));
  }
  static void add(int num) {
    (sum -= (cnt[num] * cnt[num]));
    (cnt[num]++);
    (sum += (cnt[num] * cnt[num]));
  }
  static void prepare() {
    int blen = static_cast<int>(std::sqrt(n));
    for (int i = 1; (i <= n); (i++)) {
      (bi[i] = (jdiv((i - 1), blen) + 1));
    }
    j::sort(query, 1, (m + 1), new QueryCmp());
  }
  static void compute() {
    int winl = 1;
    int winr = 0;
    for (int i = 1; (i <= m); (i++)) {
      int jobl = query[i][0];
      int jobr = query[i][1];
      while ((winl > jobl)) {
        Code02_QueryFromB1::add(arr[(--winl)]);
      }
      while ((winr < jobr)) {
        Code02_QueryFromB1::add(arr[(++winr)]);
      }
      while ((winl < jobl)) {
        Code02_QueryFromB1::del(arr[(winl++)]);
      }
      while ((winr > jobr)) {
        Code02_QueryFromB1::del(arr[(winr--)]);
      }
      (ans[query[i][2]] = sum);
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (m = in.nextInt());
    (k = in.nextInt());
    for (int i = 1; (i <= n); (i++)) {
      (arr[i] = in.nextInt());
    }
    for (int i = 1; (i <= m); (i++)) {
      (query[i][0] = in.nextInt());
      (query[i][1] = in.nextInt());
      (query[i][2] = i);
    }
    Code02_QueryFromB1::prepare();
    Code02_QueryFromB1::compute();
    for (int i = 1; (i <= m); (i++)) {
      out.println(ans[i]);
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code02_QueryFromB1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 小B的询问，java版
// 给定一个长度为n的数组arr，所有数字在[1..k]范围上
// 定义f(i) = i这种数的出现次数的平方
// 一共有m条查询，格式如下
// 查询 l r : arr[l..r]范围上，打印 f(1) + f(2) + .. + f(k) 的值
// 1 <= n、m、k <= 5 * 10^4
// 测试链接 : https://www.luogu.com.cn/problem/P2709
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // jobl, jobr, 问题id
        // 读写工具类
*/

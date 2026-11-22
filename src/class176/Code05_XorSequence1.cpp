// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P4462

// Source: src/class176/Code05_XorSequence1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code05_XorSequence1 {
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
  inline static int MAXN = 100001;
  inline static int MAXS = jshl(1, 20);
  inline static int n = {};
  inline static int m = {};
  inline static int k = {};
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static Array<Array<int>> query = make_array<int>(MAXN, 3);
  inline static Array<int> bi = make_array<int>(MAXN);
  inline static Array<int> pre = make_array<int>(MAXN);
  inline static Array<i64> cnt = make_array<i64>(MAXS);
  inline static i64 num = {};
  inline static Array<i64> ans = make_array<i64>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code05_XorSequence1() {}
  static void del(int x) {
    if ((k != 0)) {
      (num -= (cnt[x] * cnt[(x ^ k)]));
    } else {
      (num -= jshr((cnt[x] * (cnt[x] - 1)), 1));
    }
    (cnt[x]--);
    if ((k != 0)) {
      (num += (cnt[x] * cnt[(x ^ k)]));
    } else {
      (num += jshr((cnt[x] * (cnt[x] - 1)), 1));
    }
  }
  static void add(int x) {
    if ((k != 0)) {
      (num -= (cnt[x] * cnt[(x ^ k)]));
    } else {
      (num -= jshr((cnt[x] * (cnt[x] - 1)), 1));
    }
    (cnt[x]++);
    if ((k != 0)) {
      (num += (cnt[x] * cnt[(x ^ k)]));
    } else {
      (num += jshr((cnt[x] * (cnt[x] - 1)), 1));
    }
  }
  static void prepare() {
    for (int i = 1; (i <= n); (i++)) {
      (pre[i] = (pre[(i - 1)] ^ arr[i]));
    }
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
      int jobl = (query[i][0] - 1);
      int jobr = query[i][1];
      while ((winl > jobl)) {
        Code05_XorSequence1::add(pre[(--winl)]);
      }
      while ((winr < jobr)) {
        Code05_XorSequence1::add(pre[(++winr)]);
      }
      while ((winl < jobl)) {
        Code05_XorSequence1::del(pre[(winl++)]);
      }
      while ((winr > jobr)) {
        Code05_XorSequence1::del(pre[(winr--)]);
      }
      (ans[query[i][2]] = num);
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
    Code05_XorSequence1::prepare();
    Code05_XorSequence1::compute();
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
  Code05_XorSequence1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 异或序列，java版
// 给定一个长度为n的数组arr，给定一个数字k，一共有m条查询，格式如下
// 查询 l r : arr[l..r]范围上，有多少子数组的异或和为k，打印其数量
// 0 <= n、m、k、arr[i] <= 10^5
// 测试链接 : https://www.luogu.com.cn/problem/P4462
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // pre[i] == x，表示前i个数字的前缀异或和为x
        // cnt[x] = a，表示窗口内，前缀异或和x，一共有a个
        // num表示窗口内，异或和为k的子数组数量
        // 前缀异或和x要删除一次
        // 前缀异或和x要增加一次
                        // 任务范围[jobl, jobr]，但是前缀可能性会多一种
                        // 所以左边界-1
        // 读写工具类
*/

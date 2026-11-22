// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/SP3267
// https://www.spoj.com/problems/DQUERY/

// Source: src/class176/Code01_MoAlgorithm1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_MoAlgorithm1 {
  struct QueryCmp1;
  struct QueryCmp2;
  struct QueryCmp1 {
    String toString() const { return j::str(static_cast<const void *>(this)); }
    QueryCmp1() {}
    int compare(Array<int> a, Array<int> b) {
      if ((bi[a[0]] != bi[b[0]])) {
        return (bi[a[0]] - bi[b[0]]);
      }
      return (a[1] - b[1]);
    }
  };
  struct QueryCmp2 {
    String toString() const { return j::str(static_cast<const void *>(this)); }
    QueryCmp2() {}
    int compare(Array<int> a, Array<int> b) {
      if ((bi[a[0]] != bi[b[0]])) {
        return (bi[a[0]] - bi[b[0]]);
      }
      if (((bi[a[0]] & 1) == 1)) {
        return (a[1] - b[1]);
      } else {
        return (b[1] - a[1]);
      }
    }
  };
  inline static int MAXN = 30001;
  inline static int MAXV = 1000001;
  inline static int MAXQ = 200001;
  inline static int n = {};
  inline static int q = {};
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static Array<Array<int>> query = make_array<int>(MAXQ, 3);
  inline static Array<int> bi = make_array<int>(MAXN);
  inline static Array<int> cnt = make_array<int>(MAXV);
  inline static int kind = 0;
  inline static Array<int> ans = make_array<int>(MAXQ);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_MoAlgorithm1() {}
  static void del(int num) {
    if (((--cnt[num]) == 0)) {
      (kind--);
    }
  }
  static void add(int num) {
    if (((++cnt[num]) == 1)) {
      (kind++);
    }
  }
  static void prepare() {
    int blen = static_cast<int>(std::sqrt(n));
    for (int i = 1; (i <= n); (i++)) {
      (bi[i] = (jdiv((i - 1), blen) + 1));
    }
    j::sort(query, 1, (q + 1), new QueryCmp2());
  }
  static void compute() {
    int winl = 1;
    int winr = 0;
    for (int i = 1; (i <= q); (i++)) {
      int jobl = query[i][0];
      int jobr = query[i][1];
      while ((winl > jobl)) {
        Code01_MoAlgorithm1::add(arr[(--winl)]);
      }
      while ((winr < jobr)) {
        Code01_MoAlgorithm1::add(arr[(++winr)]);
      }
      while ((winl < jobl)) {
        Code01_MoAlgorithm1::del(arr[(winl++)]);
      }
      while ((winr > jobr)) {
        Code01_MoAlgorithm1::del(arr[(winr--)]);
      }
      (ans[query[i][2]] = kind);
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    for (int i = 1; (i <= n); (i++)) {
      (arr[i] = in.nextInt());
    }
    (q = in.nextInt());
    for (int i = 1; (i <= q); (i++)) {
      (query[i][0] = in.nextInt());
      (query[i][1] = in.nextInt());
      (query[i][2] = i);
    }
    Code01_MoAlgorithm1::prepare();
    Code01_MoAlgorithm1::compute();
    for (int i = 1; (i <= q); (i++)) {
      out.println(ans[i]);
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code01_MoAlgorithm1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 普通莫队入门题，java版
// 给定一个长度为n的数组arr，一共有q条查询，格式如下
// 查询 l r : 打印arr[l..r]范围上有几种不同的数字
// 1 <= n <= 3 * 10^4
// 1 <= arr[i] <= 10^6
// 1 <= q <= 2 * 10^5
// 测试链接 : https://www.luogu.com.cn/problem/SP3267
// 测试链接 : https://www.spoj.com/problems/DQUERY/
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // jobl, jobr, 问题id
        // 普通莫队经典排序
        // 普通莫队奇偶排序
                // Arrays.sort(query, 1, q + 1, new QueryCmp1());
        // 读写工具类
*/

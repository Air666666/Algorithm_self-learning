// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P5112

// Source: src/class179/Code03_LCP1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_LCP1 {
  struct QueryCmp;
  struct QueryCmp {
    String toString() const { return j::str(static_cast<const void *>(this)); }
    QueryCmp() {}
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
  inline static int MAXN = 3000001;
  inline static int MAXM = 100001;
  inline static int n = {};
  inline static int m = {};
  inline static int k = {};
  inline static int len = {};
  inline static int cntq = {};
  inline static int cntv = {};
  inline static Array<jchar> str = make_array<jchar>(MAXN);
  inline static Array<Array<int>> query = make_array<int>(MAXM, 3);
  inline static int base = 499;
  inline static Array<i64> basePower = make_array<i64>(MAXN);
  inline static Array<i64> hashValue = make_array<i64>(MAXN);
  inline static Array<i64> val = make_array<i64>(MAXN);
  inline static Array<i64> sorted = make_array<i64>(MAXN);
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static Array<int> bi = make_array<int>(MAXN);
  inline static Array<int> cnt = make_array<int>(MAXN);
  inline static i64 curAns = {};
  inline static Array<i64> ans = make_array<i64>(MAXM);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_LCP1() {}
  static int kth(i64 num) {
    int left = 1;
    int right = cntv;
    int mid = {};
    int ret = 0;
    while ((left <= right)) {
      (mid = jshr((left + right), 1));
      if ((sorted[mid] <= num)) {
        (ret = mid);
        (left = (mid + 1));
      } else {
        (right = (mid - 1));
      }
    }
    return ret;
  }
  static void add(int x) {
    (curAns += cnt[x]);
    (cnt[x]++);
  }
  static void del(int x) {
    (cnt[x]--);
    (curAns -= cnt[x]);
  }
  static void compute() {
    int winl = 1;
    int winr = 0;
    for (int i = 1; (i <= cntq); (i++)) {
      int jobl = query[i][0];
      int jobr = query[i][1];
      int id = query[i][2];
      while ((winl > jobl)) {
        Code03_LCP1::add(arr[(--winl)]);
      }
      while ((winr < jobr)) {
        Code03_LCP1::add(arr[(++winr)]);
      }
      while ((winl < jobl)) {
        Code03_LCP1::del(arr[(winl++)]);
      }
      while ((winr > jobr)) {
        Code03_LCP1::del(arr[(winr--)]);
      }
      (ans[id] = curAns);
    }
  }
  static void prepare() {
    (basePower[0] = 1);
    for (int i = 1; (i <= n); (i++)) {
      (basePower[i] = (basePower[(i - 1)] * base));
      (hashValue[i] = ((hashValue[(i - 1)] * base) + ((str[i] - u'a') + 1)));
    }
    {
      int l = 1;
      int r = k;
      for (; (r <= n); (l++), (r++)) {
        (val[l] =
             (hashValue[r] - (hashValue[(l - 1)] * basePower[((r - l) + 1)])));
      }
    }
    for (int i = 1; (i <= len); (i++)) {
      (sorted[i] = val[i]);
    }
    j::sort(sorted, 1, (len + 1));
    (cntv = 1);
    for (int i = 2; (i <= len); (i++)) {
      if ((sorted[cntv] != sorted[i])) {
        (sorted[(++cntv)] = sorted[i]);
      }
    }
    for (int i = 1; (i <= len); (i++)) {
      (arr[i] = Code03_LCP1::kth(val[i]));
    }
    int blen =
        jmax(1, static_cast<int>(jdiv(static_cast<double>(n), std::sqrt(m))));
    for (int i = 1; (i <= n); (i++)) {
      (bi[i] = (jdiv((i - 1), blen) + 1));
    }
    j::sort(query, 1, (cntq + 1), new QueryCmp());
  }
  static void java_main(Array<String> args) {
    IO in = IO();
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (m = in.nextInt());
    (k = in.nextInt());
    for (int i = 1; (i <= n); (i++)) {
      (str[i] = in.nextLowerCase());
    }
    (len = ((n - k) + 1));
    (cntq = 0);
    {
      int i = 1;
      int l = {};
      int r = {};
      for (; (i <= m); (i++)) {
        (l = in.nextInt());
        (r = in.nextInt());
        if ((l <= len)) {
          (query[(++cntq)][0] = l);
          (query[cntq][1] = jmin(r, len));
          (query[cntq][2] = i);
        }
      }
    }
    Code03_LCP1::prepare();
    Code03_LCP1::compute();
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
  Code03_LCP1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 区间lcp达标对，java版
// 给定一个长度为n的字符串str，还有一个参数k
// 位置a开头和位置b开头的字符串，如果最长公共前缀的长度 >= k，那么(a,
b)构成lcp达标对
// 构成lcp达标对，必须是不同的位置，并且(a, b)和(b,
a)只算一个达标对，不要重复统计
// 接下来有m条查询，格式为 l r :
str[l..r]范围上，可以任选开头位置，打印lcp达标对的数量
// 1 <= n、k <= 3 * 10^6       1 <= m <= 10^5
// 1 <= n * n * m <= 10^15    字符集为 f z o u t s y
// 测试链接 : https://www.luogu.com.cn/problem/P5112
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 字符串哈希
        // 哈希值离散化，用哈希值替代字符串，再用排名替代哈希值
                // 优化块长
                // 有效开头的个数，剩下的开头舍弃
                        // 过滤查询并调整查询参数
        // 读写工具类
*/

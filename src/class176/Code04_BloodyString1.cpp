// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P3709

// Source: src/class176/Code04_BloodyString1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_BloodyString1 {
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
  inline static int MAXN = 200001;
  inline static int n = {};
  inline static int m = {};
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static Array<int> sorted = make_array<int>(MAXN);
  inline static Array<Array<int>> query = make_array<int>(MAXN, 3);
  inline static Array<int> bi = make_array<int>(MAXN);
  inline static Array<int> cnt1 = make_array<int>(MAXN);
  inline static Array<int> cnt2 = make_array<int>(MAXN);
  inline static int maxCnt = 0;
  inline static Array<int> ans = make_array<int>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_BloodyString1() {}
  static int kth(int len, int num) {
    int left = 1;
    int right = len;
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
  static void del(int num) {
    if (((cnt1[num] == maxCnt) && (cnt2[cnt1[num]] == 1))) {
      (maxCnt--);
    }
    (cnt2[cnt1[num]]--);
    (cnt1[num]--);
    (cnt2[cnt1[num]]++);
  }
  static void add(int num) {
    (cnt2[cnt1[num]]--);
    (cnt1[num]++);
    (cnt2[cnt1[num]]++);
    (maxCnt = jmax(maxCnt, cnt1[num]));
  }
  static void prepare() {
    for (int i = 1; (i <= n); (i++)) {
      (sorted[i] = arr[i]);
    }
    j::sort(sorted, 1, (n + 1));
    int len = 1;
    for (int i = 2; (i <= n); (i++)) {
      if ((sorted[len] != sorted[i])) {
        (sorted[(++len)] = sorted[i]);
      }
    }
    for (int i = 1; (i <= n); (i++)) {
      (arr[i] = Code04_BloodyString1::kth(len, arr[i]));
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
      int jobl = query[i][0];
      int jobr = query[i][1];
      while ((winl > jobl)) {
        Code04_BloodyString1::add(arr[(--winl)]);
      }
      while ((winr < jobr)) {
        Code04_BloodyString1::add(arr[(++winr)]);
      }
      while ((winl < jobl)) {
        Code04_BloodyString1::del(arr[(winl++)]);
      }
      while ((winr > jobr)) {
        Code04_BloodyString1::del(arr[(winr--)]);
      }
      (ans[query[i][2]] = maxCnt);
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (m = in.nextInt());
    for (int i = 1; (i <= n); (i++)) {
      (arr[i] = in.nextInt());
    }
    for (int i = 1; (i <= m); (i++)) {
      (query[i][0] = in.nextInt());
      (query[i][1] = in.nextInt());
      (query[i][2] = i);
    }
    Code04_BloodyString1::prepare();
    Code04_BloodyString1::compute();
    for (int i = 1; (i <= m); (i++)) {
      out.println((-ans[i]));
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code04_BloodyString1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 大爷的字符串题，java版
// 给定一个长度为n的数组arr，一共有m条查询，格式如下
// 查询 l r : arr[l..r]范围上，众数出现了几次，打印次数的相反数
// 1 <= n、m <= 2 * 10^5
// 1 <= arr[i] <= 10^9
// 测试链接 : https://www.luogu.com.cn/problem/P3709
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // cnt1[i] = j，表示窗口内，数字i出现了j次
        // cnt2[i] = j，表示窗口内，出现了i次的数，有j种
        // maxCnt，表示窗口内，众数的次数
        // 读写工具类
*/

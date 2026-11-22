// Source: src/class179/Code01_NiceDay1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_NiceDay1 {
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
  inline static int MAXN = 60002;
  inline static int MAXV = jshl(1, 26);
  inline static int n = {};
  inline static int m = {};
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static Array<Array<int>> query = make_array<int>(MAXN, 3);
  inline static Array<int> bi = make_array<int>(MAXN);
  inline static Array<int> cnt = make_array<int>(MAXV);
  inline static i64 curAns = 0;
  inline static Array<i64> ans = make_array<i64>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_NiceDay1() {}
  static void add(int s) {
    (curAns += cnt[s]);
    (cnt[s]++);
    for (int i = 0; (i < 26); (i++)) {
      (curAns += cnt[(s ^ jshl(1, i))]);
    }
  }
  static void del(int s) {
    (cnt[s]--);
    (curAns -= cnt[s]);
    for (int i = 0; (i < 26); (i++)) {
      (curAns -= cnt[(s ^ jshl(1, i))]);
    }
  }
  static void compute() {
    int winl = 1;
    int winr = 0;
    for (int i = 1; (i <= m); (i++)) {
      int jobl = query[i][0];
      int jobr = query[i][1];
      int id = query[i][2];
      while ((winl > jobl)) {
        Code01_NiceDay1::add(arr[(--winl)]);
      }
      while ((winr < jobr)) {
        Code01_NiceDay1::add(arr[(++winr)]);
      }
      while ((winl < jobl)) {
        Code01_NiceDay1::del(arr[(winl++)]);
      }
      while ((winr > jobr)) {
        Code01_NiceDay1::del(arr[(winr--)]);
      }
      (ans[id] = curAns);
    }
  }
  static void prepare() {
    for (int i = 1; (i <= n); (i++)) {
      (arr[i] ^= arr[(i - 1)]);
    }
    for (int i = n; (i >= 0); (i--)) {
      (arr[(i + 1)] = arr[i]);
    }
    (n++);
    int blen = static_cast<int>(std::sqrt(n));
    for (int i = 1; (i <= n); (i++)) {
      (bi[i] = (jdiv((i - 1), blen) + 1));
    }
    for (int i = 1; (i <= m); (i++)) {
      (query[i][1]++);
    }
    j::sort(query, 1, (m + 1), new QueryCmp());
  }
  static void java_main(Array<String> args) {
    IO in = IO();
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (m = in.nextInt());
    jchar c = {};
    for (int i = 1; (i <= n); (i++)) {
      (c = in.nextLowerCase());
      (arr[i] = jshl(1, (c - u'a')));
    }
    for (int i = 1; (i <= m); (i++)) {
      (query[i][0] = in.nextInt());
      (query[i][1] = in.nextInt());
      (query[i][2] = i);
    }
    Code01_NiceDay1::prepare();
    Code01_NiceDay1::compute();
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
  Code01_NiceDay1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 美好的每一天，java版
// 给定一个长度为n的字符串str，其中都是小写字母
// 如果一个子串重新排列字符之后能成为回文串，那么该子串叫做达标子串
// 接下来有m条查询，格式为 l r : 打印str[l..r]范围上有多少达标子串
// 1 <= n、m <= 6 * 10^4
// 测试链接 : https://www.luogu.com.cn/problem/P3604
// 提交以下的code，提交时请把类名改成"Main"
// java实现的逻辑一定是正确的，但是本题卡常，无法通过所有测试用例
// 想通过用C++实现，本节课Code01_NiceDay2文件就是C++的实现
// 两个版本的逻辑完全一样，C++版本可以通过所有测试
        // 读写工具类
*/

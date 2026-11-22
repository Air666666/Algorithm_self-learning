// Source: src/class176/Code03_SockFromZ1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_SockFromZ1 {
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
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static Array<Array<int>> query = make_array<int>(MAXN, 3);
  inline static Array<int> bi = make_array<int>(MAXN);
  inline static Array<int> cnt = make_array<int>(MAXN);
  inline static i64 sum = 0;
  inline static Array<i64> ans1 = make_array<i64>(MAXN);
  inline static Array<i64> ans2 = make_array<i64>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_SockFromZ1() {}
  static i64 gcd(i64 a, i64 b) {
    return ((b == 0) ? a : Code03_SockFromZ1::gcd(b, jrem(a, b)));
  }
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
      int id = query[i][2];
      while ((winl > jobl)) {
        Code03_SockFromZ1::add(arr[(--winl)]);
      }
      while ((winr < jobr)) {
        Code03_SockFromZ1::add(arr[(++winr)]);
      }
      while ((winl < jobl)) {
        Code03_SockFromZ1::del(arr[(winl++)]);
      }
      while ((winr > jobr)) {
        Code03_SockFromZ1::del(arr[(winr--)]);
      }
      if ((jobl == jobr)) {
        (ans1[id] = 0);
        (ans2[id] = 1);
      } else {
        (ans1[id] = (sum - ((jobr - jobl) + 1)));
        (ans2[id] = ((1LL * ((jobr - jobl) + 1)) * (jobr - jobl)));
        i64 g = Code03_SockFromZ1::gcd(ans1[id], ans2[id]);
        (ans1[id] /= g);
        (ans2[id] /= g);
      }
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
    Code03_SockFromZ1::prepare();
    Code03_SockFromZ1::compute();
    for (int i = 1; (i <= m); (i++)) {
      out.println(((ans1[i] + String(u"/")) + ans2[i]));
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code03_SockFromZ1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 小Z的袜子，java版
// 给定一个长度为n的数组arr，一共有m条查询，格式如下
// 查询 l r : arr[l..r]范围上，随机选不同位置的两个数，打印数值相同的概率
//            概率用分数的形式表达，并且约分到最简的形式
// 1 <= n、m、arr[i] <= 5 * 10^4
// 测试链接 : https://www.luogu.com.cn/problem/P1494
// 提交以下的code，提交时请把类名改成"Main"
// java实现的逻辑一定是正确的，但是本题卡常，无法通过所有测试用例
// 想通过用C++实现，本节课Code03_SockFromZ2文件就是C++的实现
// 两个版本的逻辑完全一样，C++版本可以通过所有测试
        // 每个查询的分子的值
        // 每个查询的分母的值
        // 读写工具类
*/

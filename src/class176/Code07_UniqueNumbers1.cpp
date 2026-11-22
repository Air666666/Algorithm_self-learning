// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/SP30906
// https://www.spoj.com/problems/ADAUNIQ/

// Source: src/class176/Code07_UniqueNumbers1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code07_UniqueNumbers1 {
  struct QueryCmp;
  struct QueryCmp {
    String toString() const { return j::str(static_cast<const void *>(this)); }
    QueryCmp() {}
    int compare(Array<int> a, Array<int> b) {
      if ((bi[a[0]] != bi[b[0]])) {
        return (bi[a[0]] - bi[b[0]]);
      }
      if ((bi[a[1]] != bi[b[1]])) {
        return (bi[a[1]] - bi[b[1]]);
      }
      return (a[2] - b[2]);
    }
  };
  inline static int MAXN = 200001;
  inline static int n = {};
  inline static int m = {};
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static Array<int> bi = make_array<int>(MAXN);
  inline static Array<Array<int>> query = make_array<int>(MAXN, 4);
  inline static Array<Array<int>> update = make_array<int>(MAXN, 2);
  inline static int cntq = {};
  inline static int cntu = {};
  inline static Array<int> cnt = make_array<int>(MAXN);
  inline static int curCnt = 0;
  inline static Array<int> ans = make_array<int>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code07_UniqueNumbers1() {}
  static void del(int num) {
    if ((cnt[num] == 1)) {
      (curCnt--);
    }
    if ((cnt[num] == 2)) {
      (curCnt++);
    }
    (cnt[num]--);
  }
  static void add(int num) {
    if ((cnt[num] == 0)) {
      (curCnt++);
    }
    if ((cnt[num] == 1)) {
      (curCnt--);
    }
    (cnt[num]++);
  }
  static void moveTime(int jobl, int jobr, int tim) {
    int pos = update[tim][0];
    int val = update[tim][1];
    if (((jobl <= pos) && (pos <= jobr))) {
      Code07_UniqueNumbers1::del(arr[pos]);
      Code07_UniqueNumbers1::add(val);
    }
    int tmp = arr[pos];
    (arr[pos] = val);
    (update[tim][1] = tmp);
  }
  static void compute() {
    int winl = 1;
    int winr = 0;
    int wint = 0;
    for (int i = 1; (i <= cntq); (i++)) {
      int jobl = query[i][0];
      int jobr = query[i][1];
      int jobt = query[i][2];
      int id = query[i][3];
      while ((winl > jobl)) {
        Code07_UniqueNumbers1::add(arr[(--winl)]);
      }
      while ((winr < jobr)) {
        Code07_UniqueNumbers1::add(arr[(++winr)]);
      }
      while ((winl < jobl)) {
        Code07_UniqueNumbers1::del(arr[(winl++)]);
      }
      while ((winr > jobr)) {
        Code07_UniqueNumbers1::del(arr[(winr--)]);
      }
      while ((wint < jobt)) {
        Code07_UniqueNumbers1::moveTime(jobl, jobr, (++wint));
      }
      while ((wint > jobt)) {
        Code07_UniqueNumbers1::moveTime(jobl, jobr, (wint--));
      }
      (ans[id] = curCnt);
    }
  }
  static void prepare() {
    int blen = jmax(1, static_cast<int>(std::pow(n, jdiv(2.0, 3))));
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
    for (int i = 1; (i <= n); (i++)) {
      (arr[i] = in.nextInt());
    }
    {
      int i = 1;
      int op = {};
      int l = {};
      int r = {};
      int pos = {};
      int val = {};
      for (; (i <= m); (i++)) {
        (op = in.nextInt());
        if ((op == 1)) {
          (pos = in.nextInt());
          (val = in.nextInt());
          (cntu++);
          (update[cntu][0] = (pos + 1));
          (update[cntu][1] = val);
        } else {
          (l = in.nextInt());
          (r = in.nextInt());
          (cntq++);
          (query[cntq][0] = (l + 1));
          (query[cntq][1] = (r + 1));
          (query[cntq][2] = cntu);
          (query[cntq][3] = cntq);
        }
      }
    }
    Code07_UniqueNumbers1::prepare();
    Code07_UniqueNumbers1::compute();
    for (int i = 1; (i <= cntq); (i++)) {
      out.println(ans[i]);
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code07_UniqueNumbers1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 统计出现1次的数，java版
// 给定一个长度为n的数组arr，下标0~n-1，一共有m条操作，格式如下
// 操作 1 pos val : 把arr[pos]的值设置成val
// 操作 2 l r     : 查询arr[l..r]范围上，有多少种数出现了1次
// 0 <= n、m、arr[i] <= 2 * 10^5
// 测试链接 : https://www.luogu.com.cn/problem/SP30906
// 测试链接 : https://www.spoj.com/problems/ADAUNIQ/
// 提交以下的code，提交时请把类名改成"Main"
// java实现的逻辑一定是正确的，但是本题卡常，无法通过所有测试用例
// 想通过用C++实现，本节课Code07_UniqueNumbers2文件就是C++的实现
// 两个版本的逻辑完全一样，C++版本可以通过所有测试
        // 每种数字的词频统计
        // curCnt代表出现次数1次的数有几种
        // 读写工具类
*/

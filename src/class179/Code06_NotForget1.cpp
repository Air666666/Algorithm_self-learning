// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P5072

// Source: src/class179/Code06_NotForget1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code06_NotForget1 {
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
  inline static int MAXN = 100001;
  inline static int MAXB = 401;
  inline static int n = {};
  inline static int m = {};
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static Array<Array<int>> query = make_array<int>(MAXN, 4);
  inline static Array<int> bi = make_array<int>(MAXN);
  inline static int head = {};
  inline static Array<int> last = make_array<int>(MAXN);
  inline static Array<int> next = make_array<int>(MAXN);
  inline static Array<int> cnt = make_array<int>(MAXN);
  inline static Array<i64> sum = make_array<i64>(MAXN);
  inline static Array<i64> smlPower = make_array<i64>(MAXB);
  inline static Array<i64> bigPower = make_array<i64>(MAXB);
  inline static Array<i64> ans = make_array<i64>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code06_NotForget1() {}
  static void addNode(int x) {
    (last[head] = x);
    (next[x] = head);
    (head = x);
  }
  static void delNode(int x) {
    if ((x == head)) {
      (head = next[head]);
      (last[head] = (next[x] = 0));
    } else {
      (next[last[x]] = next[x]);
      (last[next[x]] = last[x]);
      (last[x] = (next[x] = 0));
    }
  }
  static void add(int num) {
    if ((cnt[num] > 0)) {
      (sum[cnt[num]] -= num);
    }
    if (((cnt[num] > 0) && (sum[cnt[num]] == 0))) {
      Code06_NotForget1::delNode(cnt[num]);
    }
    (cnt[num]++);
    if (((cnt[num] > 0) && (sum[cnt[num]] == 0))) {
      Code06_NotForget1::addNode(cnt[num]);
    }
    if ((cnt[num] > 0)) {
      (sum[cnt[num]] += num);
    }
  }
  static void del(int num) {
    if ((cnt[num] > 0)) {
      (sum[cnt[num]] -= num);
    }
    if (((cnt[num] > 0) && (sum[cnt[num]] == 0))) {
      Code06_NotForget1::delNode(cnt[num]);
    }
    (cnt[num]--);
    if (((cnt[num] > 0) && (sum[cnt[num]] == 0))) {
      Code06_NotForget1::addNode(cnt[num]);
    }
    if ((cnt[num] > 0)) {
      (sum[cnt[num]] += num);
    }
  }
  static void setAns(int len, int p, int id) {
    int blockLen = static_cast<int>(std::sqrt(len));
    int blockNum = jdiv(((len + blockLen) - 1), blockLen);
    (smlPower[0] = 1);
    for (int i = 1; (i <= blockLen); (i++)) {
      (smlPower[i] = jrem(jshl(smlPower[(i - 1)], 1), p));
    }
    (bigPower[0] = 1);
    for (int i = 1; (i <= blockNum); (i++)) {
      (bigPower[i] = jrem((bigPower[(i - 1)] * smlPower[blockLen]), p));
    }
    i64 res = 0;
    i64 p1 = {};
    i64 p2 = {};
    i64 tmp = {};
    (p1 = jrem((bigPower[jdiv(len, blockLen)] * smlPower[jrem(len, blockLen)]),
               p));
    for (int t = head; (t > 0); (t = next[t])) {
      (p2 = jrem((bigPower[jdiv((len - t), blockLen)] *
                  smlPower[jrem((len - t), blockLen)]),
                 p));
      (tmp = jrem(((p1 - p2) * sum[t]), p));
      (res = jrem((jrem((res + tmp), p) + p), p));
    }
    (ans[id] = res);
  }
  static void compute() {
    int winl = 1;
    int winr = 0;
    for (int i = 1; (i <= m); (i++)) {
      int jobl = query[i][0];
      int jobr = query[i][1];
      int jobp = query[i][2];
      int id = query[i][3];
      while ((winl > jobl)) {
        Code06_NotForget1::add(arr[(--winl)]);
      }
      while ((winr < jobr)) {
        Code06_NotForget1::add(arr[(++winr)]);
      }
      while ((winl < jobl)) {
        Code06_NotForget1::del(arr[(winl++)]);
      }
      while ((winr > jobr)) {
        Code06_NotForget1::del(arr[(winr--)]);
      }
      Code06_NotForget1::setAns(((jobr - jobl) + 1), jobp, id);
    }
  }
  static void prepare() {
    int blen = static_cast<int>(std::sqrt(n));
    for (int i = 1; (i <= n); (i++)) {
      (bi[i] = (jdiv((i - 1), blen) + 1));
    }
    j::sort(query, 1, (m + 1), new QueryCmp());
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
      (query[i][2] = in.nextInt());
      (query[i][3] = i);
    }
    Code06_NotForget1::prepare();
    Code06_NotForget1::compute();
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
  Code06_NotForget1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 盼君勿忘，java版
// 一个序列中每种数字只保留一个，得到的累加和，叫做去重累加和
// 给定一个长度为n的数组arr，接下来是m条查询，查询格式如下
// 查询 l r p : arr[l..r]范围上，每个子序列的去重累加和，都累加起来 % p
的结果打印
// 1 <= n、m、arr[i] <= 10^5
// 1 <= p <= 10^9
// 测试链接 : https://www.luogu.com.cn/problem/P5072
// 提交以下的code，提交时请把类名改成"Main"
// java实现的逻辑一定是正确的，但是本题卡常，无法通过所有测试用例
// 想通过用C++实现，本节课Code06_NotForget2文件就是C++的实现
// 两个版本的逻辑完全一样，C++版本可以通过所有测试
        // 查询任务，l、r、p、id
        // 有效次数桶组成的双向链表
        // 有数字进入次数桶，该次数桶才进入链表，链表内部不需要有序组织
        // cnt[v] = c，表示v这个数出现了c次，也可以说v在c次桶里
        // sum[c] = x，表示c次桶内的数字，每种数字只统计一次，累加和为x
        // 光速幂
        // 假设[l..r]范围长度len，blockLen为块的长度，blockNum为块的数量
        // smlPower[i]，表示p的i次方的值，i <= blockLen
        // bigPower[i]，表示p的(i * blockLen)次方的值，i <= blockNum
                // 光速幂
                // 构建smlPower和bigPower
                // t次桶的贡献 = [2的len次方 - 2的(len-t)次方] * sum[t]
        // 读写工具类
*/

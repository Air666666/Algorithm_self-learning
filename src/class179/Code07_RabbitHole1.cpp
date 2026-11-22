// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P4688

// Source: src/class179/Code07_RabbitHole1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code07_RabbitHole1 {
  struct BitSet;
  struct QueryCmp;
  struct BitSet {
    int len = {};
    Array<i64> status = {};
    String toString() const { return j::str(static_cast<const void *>(this)); }
    BitSet(int siz) {
      (len = jshr((siz + 63), 6));
      (status = make_array<i64>(len));
    }
    void clear() {
      for (int i = 0; (i < len); (i++)) {
        (status[i] = 0);
      }
    }
    void copy(BitSet *obj) {
      for (int i = 0; (i < len); (i++)) {
        (status[i] = obj->status[i]);
      }
    }
    void and_method(BitSet *obj) {
      for (int i = 0; (i < len); (i++)) {
        (status[i] &= obj->status[i]);
      }
    }
    void setOne(int bit) { (status[jshr(bit, 6)] |= jshl(1LL, (bit & 63))); }
    void setZero(int bit) {
      (status[jshr(bit, 6)] &= (~jshl(1LL, (bit & 63))));
    }
    int getOnes() {
      int ret = 0;
      for (int i = 0; (i < len); (i++)) {
        (ret += __builtin_popcountll(status[i]));
      }
      return ret;
    }
  };
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
  inline static int MAXT = 30001;
  inline static int n = {};
  inline static int m = {};
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static Array<Array<int>> query = make_array<int>((MAXT * 3), 3);
  inline static Array<int> sorted = make_array<int>(MAXN);
  inline static Array<int> bi = make_array<int>(MAXN);
  inline static Array<int> cnt = make_array<int>(MAXN);
  inline static BitSet *curSet = {};
  inline static Array<bool> hasSet = make_array<bool>(MAXT);
  inline static Array<BitSet *> bitSet = make_array<BitSet *>(MAXT);
  inline static Array<int> ans = make_array<int>(MAXT);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code07_RabbitHole1() {}
  static int kth(int num) {
    int left = 1;
    int right = n;
    int mid = {};
    int ret = (-1);
    while ((left <= right)) {
      (mid = jshr((left + right), 1));
      if ((sorted[mid] >= num)) {
        (ret = mid);
        (right = (mid - 1));
      } else {
        (left = (mid + 1));
      }
    }
    return ret;
  }
  static void add(int x) {
    (cnt[x]++);
    curSet->setOne(((x + cnt[x]) - 1));
  }
  static void del(int x) {
    (cnt[x]--);
    curSet->setZero((x + cnt[x]));
  }
  static void compute(int q) {
    int winl = 1;
    int winr = 0;
    for (int i = 1; (i <= q); (i++)) {
      int jobl = query[i][0];
      int jobr = query[i][1];
      int id = query[i][2];
      while ((winl > jobl)) {
        Code07_RabbitHole1::add(arr[(--winl)]);
      }
      while ((winr < jobr)) {
        Code07_RabbitHole1::add(arr[(++winr)]);
      }
      while ((winl < jobl)) {
        Code07_RabbitHole1::del(arr[(winl++)]);
      }
      while ((winr > jobr)) {
        Code07_RabbitHole1::del(arr[(winr--)]);
      }
      if ((!hasSet[id])) {
        (hasSet[id] = true);
        bitSet[id]->copy(curSet);
      } else {
        bitSet[id]->and_method(curSet);
      }
    }
  }
  static void prepare() {
    for (int i = 1; (i <= n); (i++)) {
      (sorted[i] = arr[i]);
    }
    j::sort(sorted, 1, (n + 1));
    for (int i = 1; (i <= n); (i++)) {
      (arr[i] = Code07_RabbitHole1::kth(arr[i]));
    }
    int blen = static_cast<int>(std::sqrt(n));
    for (int i = 1; (i <= n); (i++)) {
      (bi[i] = (jdiv((i - 1), blen) + 1));
    }
    for (int i = 1; (i < MAXT); (i++)) {
      (bitSet[i] = new BitSet((n + 1)));
    }
    (curSet = new BitSet((n + 1)));
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (m = in.nextInt());
    for (int i = 1; (i <= n); (i++)) {
      (arr[i] = in.nextInt());
    }
    Code07_RabbitHole1::prepare();
    for (int t = (MAXT - 1); (m > 0); (m -= t)) {
      int k = jmin(m, t);
      j::fill(cnt, 1, (n + 1), 0);
      j::fill(hasSet, 1, (k + 1), false);
      j::fill(ans, 1, (k + 1), 0);
      curSet->clear();
      int cntq = 0;
      for (int i = 1; (i <= k); (i++)) {
        for (int j = 1; (j <= 3); (j++)) {
          (query[(++cntq)][0] = in.nextInt());
          (query[cntq][1] = in.nextInt());
          (query[cntq][2] = i);
          (ans[i] += ((query[cntq][1] - query[cntq][0]) + 1));
        }
      }
      j::sort(query, 1, (cntq + 1), new QueryCmp());
      Code07_RabbitHole1::compute(cntq);
      for (int i = 1; (i <= k); (i++)) {
        (ans[i] -= (bitSet[i]->getOnes() * 3));
      }
      for (int i = 1; (i <= k); (i++)) {
        out.println(ans[i]);
      }
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code07_RabbitHole1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 掉进兔子洞，java版
// 三个区间同时出现的数，一个一个删掉，直到无法再删，剩下数字的个数叫做 剩余个数
// A = [1 2 2 3 3 3]    B = [1 2 2 3 3 3]    C = [1 1 2 3 3]
// 删除的过程为，一起删掉一个1、一起删掉一个2、一起删掉2个3，然后状况为
// A = [2 3]    B = [2 3]    C = [1]    剩余个数为5
// 给定一个长度为n的数组arr，下来有m条查询，格式如下
// 查询 l1 r1 l2 r2 l3 r3 : 给定了三个区间，打印剩余个数
// 1 <= n、m <= 10^5
// 1 <= arr[i] <= 10^9
// 测试链接 : https://www.luogu.com.cn/problem/P4688
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 排序之后不去重
        // 得到每个数字的排名
        // cnt[v] = c，表示窗口中数字v出现c次
        // 当前窗口的位图
        // 问题从来没获得位图就拷贝，问题获得过位图就做&运算
        // 每个问题的位图
        // 读写工具类
*/

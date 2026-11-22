// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P5501

// Source: src/class178/Code03_Abbi1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_Abbi1 {
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
  inline static int MAXN = 500001;
  inline static int MAXV = 100000;
  inline static int MAXB = 401;
  inline static int n = {};
  inline static int m = {};
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static Array<i64> preSum = make_array<i64>(MAXN);
  inline static Array<int> bi = make_array<int>(MAXN);
  inline static Array<int> bl = make_array<int>(MAXB);
  inline static Array<int> br = make_array<int>(MAXB);
  inline static Array<Array<int>> query = make_array<int>(MAXN, 3);
  inline static Array<int> headq = make_array<int>(MAXN);
  inline static Array<int> nextq = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> ql = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> qr = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> qop = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> qid = make_array<int>(jshl(MAXN, 1));
  inline static int cntq = {};
  inline static Array<i64> treeCnt = make_array<i64>((MAXV + 1));
  inline static Array<i64> treeSum = make_array<i64>((MAXV + 1));
  inline static Array<i64> pre = make_array<i64>(MAXN);
  inline static Array<int> blockLessCnt = make_array<int>(MAXB);
  inline static Array<int> numLessCnt = make_array<int>(MAXN);
  inline static Array<i64> blockMoreSum = make_array<i64>(MAXB);
  inline static Array<i64> numMoreSum = make_array<i64>(MAXN);
  inline static Array<i64> ans = make_array<i64>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_Abbi1() {}
  static void addOffline(int x, int l, int r, int op, int id) {
    (nextq[(++cntq)] = headq[x]);
    (headq[x] = cntq);
    (ql[cntq] = l);
    (qr[cntq] = r);
    (qop[cntq] = op);
    (qid[cntq] = id);
  }
  static int lowbit(int x) { return (x & (-x)); }
  static void add(Array<i64> tree, int x, int v) {
    while ((x <= MAXV)) {
      (tree[x] += v);
      (x += Code03_Abbi1::lowbit(x));
    }
  }
  static i64 sum(Array<i64> tree, int x) {
    i64 ret = 0;
    while ((x > 0)) {
      (ret += tree[x]);
      (x -= Code03_Abbi1::lowbit(x));
    }
    return ret;
  }
  static void addVal(int val) {
    for (int b = (bi[val] + 1); (b <= bi[MAXV]); (b++)) {
      (blockLessCnt[b]++);
    }
    for (int i = (val + 1); (i <= br[bi[val]]); (i++)) {
      (numLessCnt[i]++);
    }
    for (int b = 1; (b <= (bi[val] - 1)); (b++)) {
      (blockMoreSum[b] += val);
    }
    for (int i = bl[bi[val]]; (i < val); (i++)) {
      (numMoreSum[i] += val);
    }
  }
  static int lessCnt(int x) { return (blockLessCnt[bi[x]] + numLessCnt[x]); }
  static i64 moreSum(int x) { return (blockMoreSum[bi[x]] + numMoreSum[x]); }
  static void prepare() {
    for (int i = 1; (i <= n); (i++)) {
      (preSum[i] = (preSum[(i - 1)] + arr[i]));
    }
    int blen = static_cast<int>(std::sqrt(MAXV));
    int bnum = jdiv(((MAXV + blen) - 1), blen);
    for (int i = 1; (i <= MAXV); (i++)) {
      (bi[i] = (jdiv((i - 1), blen) + 1));
    }
    for (int i = 1; (i <= bnum); (i++)) {
      (bl[i] = (((i - 1) * blen) + 1));
      (br[i] = jmin((i * blen), MAXV));
    }
    j::sort(query, 1, (m + 1), new QueryCmp());
  }
  static void compute() {
    for (int i = 1; (i <= n); (i++)) {
      (pre[i] = [&]() {
        auto jleft = [&]() {
          auto jleft = (pre[(i - 1)] +
                        (Code03_Abbi1::sum(treeCnt, (arr[i] - 1)) * arr[i]));
          auto jright = Code03_Abbi1::sum(treeSum, MAXV);
          return (jleft + jright);
        }();
        auto jright = Code03_Abbi1::sum(treeSum, arr[i]);
        return (jleft - jright);
      }());
      Code03_Abbi1::add(treeCnt, arr[i], 1);
      Code03_Abbi1::add(treeSum, arr[i], arr[i]);
    }
    int winl = 1;
    int winr = 0;
    for (int i = 1; (i <= m); (i++)) {
      int jobl = query[i][0];
      int jobr = query[i][1];
      int id = query[i][2];
      if ((winr < jobr)) {
        Code03_Abbi1::addOffline((winl - 1), (winr + 1), jobr, (-1), id);
        (ans[id] += (pre[jobr] - pre[winr]));
      }
      if ((winr > jobr)) {
        Code03_Abbi1::addOffline((winl - 1), (jobr + 1), winr, 1, id);
        (ans[id] -= (pre[winr] - pre[jobr]));
      }
      (winr = jobr);
      if ((winl > jobl)) {
        Code03_Abbi1::addOffline(winr, jobl, (winl - 1), 1, id);
        (ans[id] -= (pre[(winl - 1)] - pre[(jobl - 1)]));
      }
      if ((winl < jobl)) {
        Code03_Abbi1::addOffline(winr, winl, (jobl - 1), (-1), id);
        (ans[id] += (pre[(jobl - 1)] - pre[(winl - 1)]));
      }
      (winl = jobl);
    }
    i64 tmp = {};
    for (int x = 0; (x <= n); (x++)) {
      if ((x >= 1)) {
        Code03_Abbi1::addVal(arr[x]);
      }
      for (int q = headq[x]; (q > 0); (q = nextq[q])) {
        int l = ql[q];
        int r = qr[q];
        int op = qop[q];
        int id = qid[q];
        for (int j = l; (j <= r); (j++)) {
          (tmp = [&]() {
            auto jleft =
                (static_cast<i64>(Code03_Abbi1::lessCnt(arr[j])) * arr[j]);
            auto jright = Code03_Abbi1::moreSum(arr[j]);
            return (jleft + jright);
          }());
          if ((op == 1)) {
            (ans[id] += tmp);
          } else {
            (ans[id] -= tmp);
          }
        }
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
    Code03_Abbi1::prepare();
    Code03_Abbi1::compute();
    for (int i = 2; (i <= m); (i++)) {
      (ans[query[i][2]] += ans[query[(i - 1)][2]]);
    }
    for (int i = 1; (i <= m); (i++)) {
      (ans[query[i][2]] += (preSum[query[i][1]] - preSum[(query[i][0] - 1)]));
    }
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
  Code03_Abbi1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 区间Abbi值，java版
// 给定一个长度为n的数组arr，区间Abbi值的定义如下
// 如果arr[l..r]包含数字v，并且v是第k小，那么这个数字的Abbi值 = v * k
// 区间Abbi值 = 区间内所有数字Abbi值的累加和
// 比如[1, 2, 2, 3]的Abbi值 = 1 * 1 + 2 * 2 + 2 * 2 + 3 * 4 = 21
// 一共有m条查询，格式为 l r : 打印arr[l..r]的区间Abbi值
// 1 <= n、m <= 5 * 10^5
// 1 <= arr[i] <= 10^5
// 测试链接 : https://www.luogu.com.cn/problem/P5501
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 序列分块 + 值域分块
        // 莫队任务 + 二次离线任务(x, l, r, op)
        // 值域树状数组，统计<x的个数
        // 值域树状数组，统计>x所有数的累加和
        // 前缀信息
        // 值域分块，统计<x的个数
        // 值域分块，统计>x所有数的累加和
        // 执行二次离线的过程中，加入数字val，修改相关信息
        // 查询<x的个数
        // 查询>x的所有数累加和
                // 加工前缀和
                // 贡献是修正过的概念，现在补偿回来
        // 读写工具类
*/

// Source: src/class178/Code02_OfflineInversion1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_OfflineInversion1 {
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
  inline static int MAXN = 100002;
  inline static int MAXB = 401;
  inline static int n = {};
  inline static int m = {};
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static Array<int> sorted = make_array<int>(MAXN);
  inline static int cntv = {};
  inline static Array<Array<int>> query = make_array<int>(MAXN, 3);
  inline static Array<int> headl = make_array<int>(MAXN);
  inline static Array<int> headr = make_array<int>(MAXN);
  inline static Array<int> nextq = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> ql = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> qr = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> qop = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> qid = make_array<int>(jshl(MAXN, 1));
  inline static int cntq = {};
  inline static Array<int> bi = make_array<int>(MAXN);
  inline static Array<int> bl = make_array<int>(MAXB);
  inline static Array<int> br = make_array<int>(MAXB);
  inline static Array<int> tree = make_array<int>(MAXN);
  inline static Array<i64> pre = make_array<i64>(MAXN);
  inline static Array<i64> suf = make_array<i64>(MAXN);
  inline static Array<i64> blockCnt = make_array<i64>(MAXB);
  inline static Array<i64> numCnt = make_array<i64>(MAXN);
  inline static Array<i64> ans = make_array<i64>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_OfflineInversion1() {}
  static int kth(int num) {
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
  static int lowbit(int i) { return (i & (-i)); }
  static void add(int i, int v) {
    while ((i <= cntv)) {
      (tree[i] += v);
      (i += Code02_OfflineInversion1::lowbit(i));
    }
  }
  static int sum(int i) {
    int ret = 0;
    while ((i > 0)) {
      (ret += tree[i]);
      (i -= Code02_OfflineInversion1::lowbit(i));
    }
    return ret;
  }
  static void addLeftOffline(int x, int l, int r, int op, int id) {
    (nextq[(++cntq)] = headl[x]);
    (headl[x] = cntq);
    (ql[cntq] = l);
    (qr[cntq] = r);
    (qop[cntq] = op);
    (qid[cntq] = id);
  }
  static void addRightOffline(int x, int l, int r, int op, int id) {
    (nextq[(++cntq)] = headr[x]);
    (headr[x] = cntq);
    (ql[cntq] = l);
    (qr[cntq] = r);
    (qop[cntq] = op);
    (qid[cntq] = id);
  }
  static void addLeftCnt(int val) {
    for (int b = 1; (b <= (bi[val] - 1)); (b++)) {
      (blockCnt[b]++);
    }
    for (int i = bl[bi[val]]; (i < val); (i++)) {
      (numCnt[i]++);
    }
  }
  static void addRightCnt(int val) {
    for (int b = (bi[val] + 1); (b <= bi[cntv]); (b++)) {
      (blockCnt[b]++);
    }
    for (int i = (val + 1); (i <= br[bi[val]]); (i++)) {
      (numCnt[i]++);
    }
  }
  static i64 getCnt(int val) { return (blockCnt[bi[val]] + numCnt[val]); }
  static void prepare() {
    for (int i = 1; (i <= n); (i++)) {
      (sorted[i] = arr[i]);
    }
    j::sort(sorted, 1, (n + 1));
    (cntv = 1);
    for (int i = 2; (i <= n); (i++)) {
      if ((sorted[cntv] != sorted[i])) {
        (sorted[(++cntv)] = sorted[i]);
      }
    }
    for (int i = 1; (i <= n); (i++)) {
      (arr[i] = Code02_OfflineInversion1::kth(arr[i]));
    }
    int blen = static_cast<int>(std::sqrt(n));
    int bnum = jdiv(((n + blen) - 1), blen);
    for (int i = 1; (i <= n); (i++)) {
      (bi[i] = (jdiv((i - 1), blen) + 1));
    }
    for (int i = 1; (i <= bnum); (i++)) {
      (bl[i] = (((i - 1) * blen) + 1));
      (br[i] = jmin((i * blen), cntv));
    }
    j::sort(query, 1, (m + 1), new QueryCmp());
  }
  static void compute() {
    for (int i = 1; (i <= n); (i++)) {
      (pre[i] = [&]() {
        auto jleft = (pre[(i - 1)] + Code02_OfflineInversion1::sum(cntv));
        auto jright = Code02_OfflineInversion1::sum(arr[i]);
        return (jleft - jright);
      }());
      Code02_OfflineInversion1::add(arr[i], 1);
    }
    j::fill(tree, 1, (cntv + 1), 0);
    for (int i = n; (i >= 1); (i--)) {
      (suf[i] = (suf[(i + 1)] + Code02_OfflineInversion1::sum((arr[i] - 1))));
      Code02_OfflineInversion1::add(arr[i], 1);
    }
    int winl = 1;
    int winr = 0;
    for (int i = 1; (i <= m); (i++)) {
      int jobl = query[i][0];
      int jobr = query[i][1];
      int id = query[i][2];
      if ((winr < jobr)) {
        Code02_OfflineInversion1::addLeftOffline((winl - 1), (winr + 1), jobr,
                                                 (-1), id);
        (ans[id] += (pre[jobr] - pre[winr]));
      }
      if ((winr > jobr)) {
        Code02_OfflineInversion1::addLeftOffline((winl - 1), (jobr + 1), winr,
                                                 1, id);
        (ans[id] -= (pre[winr] - pre[jobr]));
      }
      (winr = jobr);
      if ((winl > jobl)) {
        Code02_OfflineInversion1::addRightOffline((winr + 1), jobl, (winl - 1),
                                                  (-1), id);
        (ans[id] += (suf[jobl] - suf[winl]));
      }
      if ((winl < jobl)) {
        Code02_OfflineInversion1::addRightOffline((winr + 1), winl, (jobl - 1),
                                                  1, id);
        (ans[id] -= (suf[winl] - suf[jobl]));
      }
      (winl = jobl);
    }
    for (int x = 0; (x <= n); (x++)) {
      if ((x >= 1)) {
        Code02_OfflineInversion1::addLeftCnt(arr[x]);
      }
      for (int q = headl[x]; (q > 0); (q = nextq[q])) {
        int l = ql[q];
        int r = qr[q];
        int op = qop[q];
        int id = qid[q];
        i64 ret = 0;
        for (int j = l; (j <= r); (j++)) {
          (ret += Code02_OfflineInversion1::getCnt(arr[j]));
        }
        (ans[id] += (ret * op));
      }
    }
    j::fill(blockCnt, 0);
    j::fill(numCnt, 0);
    for (int x = (n + 1); (x >= 1); (x--)) {
      if ((x <= n)) {
        Code02_OfflineInversion1::addRightCnt(arr[x]);
      }
      for (int q = headr[x]; (q > 0); (q = nextq[q])) {
        int l = ql[q];
        int r = qr[q];
        int op = qop[q];
        int id = qid[q];
        i64 ret = 0;
        for (int j = l; (j <= r); (j++)) {
          (ret += Code02_OfflineInversion1::getCnt(arr[j]));
        }
        (ans[id] += (ret * op));
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
    Code02_OfflineInversion1::prepare();
    Code02_OfflineInversion1::compute();
    for (int i = 2; (i <= m); (i++)) {
      (ans[query[i][2]] += ans[query[(i - 1)][2]]);
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
  Code02_OfflineInversion1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 区间逆序对，java版
// 给定一个长度为n的数组arr，如果i < j，并且arr[i] > arr[j]，那么(i,j)就是逆序对
// 一共有m条查询，格式为 l r : 打印arr[l..r]范围上，逆序对的数量
// 1 <= n、m <= 10^5
// 0 <= arr[i] <= 10^9
// 本题允许离线，讲解173，题目4，讲了在线查询区间逆序对，但是给定的数组为排列
// 测试链接 : https://www.luogu.com.cn/problem/P5047
// 提交以下的code，提交时请把类名改成"Main"
// java实现的逻辑一定是正确的，但是本题卡常，无法通过所有测试用例
// 想通过用C++实现，本节课Code02_OfflineInversion2文件就是C++的实现
// 两个版本的逻辑完全一样，C++版本可以通过所有测试
        // bi用于序列分块、值域分块，bl和br用于值域分块
        // 树状数组
        // 前缀信息
        // 后缀信息
        // 整块增加的词频
        // 单个数值的词频
        // 增加1 ~ val-1，这些数字的词频
        // 增加val+1 ~ cntv，这些数字的词频
        // 读写工具类
*/

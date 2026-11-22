// Source: src/class178/Code01_MoOfflineTwice1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_MoOfflineTwice1 {
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
  inline static int MAXV = jshl(1, 14);
  inline static int n = {};
  inline static int m = {};
  inline static int k = {};
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static Array<int> bi = make_array<int>(MAXN);
  inline static Array<int> kOneArr = make_array<int>(MAXV);
  inline static int cntk = {};
  inline static Array<Array<int>> query = make_array<int>(MAXN, 3);
  inline static Array<int> headl = make_array<int>(MAXN);
  inline static Array<int> headr = make_array<int>(MAXN);
  inline static Array<int> nextq = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> ql = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> qr = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> qop = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> qid = make_array<int>(jshl(MAXN, 1));
  inline static int cntq = {};
  inline static Array<int> cnt = make_array<int>(MAXV);
  inline static Array<i64> pre = make_array<i64>(MAXN);
  inline static Array<i64> suf = make_array<i64>(MAXN);
  inline static Array<i64> ans = make_array<i64>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_MoOfflineTwice1() {}
  static int lowbit(int i) { return (i & (-i)); }
  static int countOne(int num) {
    int ret = 0;
    while ((num > 0)) {
      (ret++);
      (num -= Code01_MoOfflineTwice1::lowbit(num));
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
  static void prepare() {
    int blen = static_cast<int>(std::sqrt(n));
    for (int i = 1; (i <= n); (i++)) {
      (bi[i] = (jdiv((i - 1), blen) + 1));
    }
    j::sort(query, 1, (m + 1), new QueryCmp());
    for (int v = 0; (v < MAXV); (v++)) {
      if ((Code01_MoOfflineTwice1::countOne(v) == k)) {
        (kOneArr[(++cntk)] = v);
      }
    }
  }
  static void compute() {
    for (int i = 1; (i <= n); (i++)) {
      (pre[i] = (pre[(i - 1)] + cnt[arr[i]]));
      for (int j = 1; (j <= cntk); (j++)) {
        (cnt[(arr[i] ^ kOneArr[j])]++);
      }
    }
    j::fill(cnt, 0);
    for (int i = n; (i >= 1); (i--)) {
      (suf[i] = (suf[(i + 1)] + cnt[arr[i]]));
      for (int j = 1; (j <= cntk); (j++)) {
        (cnt[(arr[i] ^ kOneArr[j])]++);
      }
    }
    int winl = 1;
    int winr = 0;
    for (int i = 1; (i <= m); (i++)) {
      int jobl = query[i][0];
      int jobr = query[i][1];
      int id = query[i][2];
      if ((winr < jobr)) {
        Code01_MoOfflineTwice1::addLeftOffline((winl - 1), (winr + 1), jobr,
                                               (-1), id);
        (ans[id] += (pre[jobr] - pre[winr]));
      }
      if ((winr > jobr)) {
        Code01_MoOfflineTwice1::addLeftOffline((winl - 1), (jobr + 1), winr, 1,
                                               id);
        (ans[id] -= (pre[winr] - pre[jobr]));
      }
      (winr = jobr);
      if ((winl > jobl)) {
        Code01_MoOfflineTwice1::addRightOffline((winr + 1), jobl, (winl - 1),
                                                (-1), id);
        (ans[id] += (suf[jobl] - suf[winl]));
      }
      if ((winl < jobl)) {
        Code01_MoOfflineTwice1::addRightOffline((winr + 1), winl, (jobl - 1), 1,
                                                id);
        (ans[id] -= (suf[winl] - suf[jobl]));
      }
      (winl = jobl);
    }
    j::fill(cnt, 0);
    for (int x = 0; (x <= n); (x++)) {
      if ((x >= 1)) {
        for (int j = 1; (j <= cntk); (j++)) {
          (cnt[(arr[x] ^ kOneArr[j])]++);
        }
      }
      for (int q = headl[x]; (q > 0); (q = nextq[q])) {
        int l = ql[q];
        int r = qr[q];
        int op = qop[q];
        int id = qid[q];
        for (int j = l; (j <= r); (j++)) {
          (ans[id] += (static_cast<i64>(op) * cnt[arr[j]]));
        }
      }
    }
    j::fill(cnt, 0);
    for (int x = (n + 1); (x >= 1); (x--)) {
      if ((x <= n)) {
        for (int j = 1; (j <= cntk); (j++)) {
          (cnt[(arr[x] ^ kOneArr[j])]++);
        }
      }
      for (int q = headr[x]; (q > 0); (q = nextq[q])) {
        int l = ql[q];
        int r = qr[q];
        int op = qop[q];
        int id = qid[q];
        for (int j = l; (j <= r); (j++)) {
          (ans[id] += (static_cast<i64>(op) * cnt[arr[j]]));
        }
      }
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (m = in.nextInt());
    (k = in.nextInt());
    for (int i = 1; (i <= n); (i++)) {
      (arr[i] = in.nextInt());
    }
    for (int i = 1; (i <= m); (i++)) {
      (query[i][0] = in.nextInt());
      (query[i][1] = in.nextInt());
      (query[i][2] = i);
    }
    Code01_MoOfflineTwice1::prepare();
    Code01_MoOfflineTwice1::compute();
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
  Code01_MoOfflineTwice1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 莫队二次离线入门题，java版
// 给定一个长度为n的数组arr，给定一个非负整数k，下面给出k1二元组的定义
// 位置二元组(i, j)，i和j必须是不同的，并且 arr[i]异或arr[j]
的二进制状态里有k个1
// 当i != j时，(i, j)和(j, i)认为是相同的二元组
// 一共有m条查询，格式为 l r : 打印arr[l..r]范围上，有多少k1二元组
// 1 <= n、m <= 10^5
// 0 <= arr[i]、k < 16384(2的14次方)
// 测试链接 : https://www.luogu.com.cn/problem/P4887
// 提交以下的code，提交时请把类名改成"Main"
// java实现的逻辑一定是正确的，但是本题卡常，无法通过所有测试用例
// 想通过用C++实现，本节课Code01_MoOfflineTwice2文件就是C++的实现
// 两个版本的逻辑完全一样，C++版本可以通过所有测试
        // 莫队任务，l、r、id
        // 离线任务，x、l、r、op、id
        // 位置x的任务列表用链式前向星表示
        // headl[x]，x在l~r左侧的离线任务列表
        // headr[x]，x在l~r右侧的离线任务列表
        // cnt[v] :
当前的数字v作为第二个数，之前出现的数字作为第一个数，产生多少k1二元组
        // 前缀和
        // 后缀和
                // 执行莫队
                // ans[i]代表答案变化量
                // 所以加工出前缀和才是每个查询的答案
                // 注意在普通莫队的顺序下，去生成前缀和
        // 读写工具类
*/

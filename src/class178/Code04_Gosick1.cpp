// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P5398

// Source: src/class178/Code04_Gosick1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_Gosick1 {
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
  inline static int MAXF = 5000001;
  inline static int LIMIT = 100;
  inline static int n = {};
  inline static int m = {};
  inline static int maxv = {};
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static Array<int> bi = make_array<int>(MAXN);
  inline static Array<int> headf = make_array<int>(MAXN);
  inline static Array<int> nextf = make_array<int>(MAXF);
  inline static Array<int> fac = make_array<int>(MAXF);
  inline static int cntf = {};
  inline static Array<Array<int>> query = make_array<int>(MAXN, 3);
  inline static Array<int> headq = make_array<int>(MAXN);
  inline static Array<int> nextq = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> qx = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> ql = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> qr = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> qop = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> qid = make_array<int>(jshl(MAXN, 1));
  inline static int cntq = {};
  inline static Array<int> xcnt = make_array<int>(MAXN);
  inline static Array<int> vcnt = make_array<int>(MAXN);
  inline static Array<i64> pre = make_array<i64>(MAXN);
  inline static Array<i64> ans = make_array<i64>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_Gosick1() {}
  static void addFactors(int num) {
    if ((headf[num] == 0)) {
      for (int f = 1; ((f * f) <= num); (f++)) {
        if ((jrem(num, f) == 0)) {
          (nextf[(++cntf)] = headf[num]);
          (fac[cntf] = f);
          (headf[num] = cntf);
        }
      }
    }
  }
  static void addOffline(int x, int l, int r, int op, int id) {
    (nextq[(++cntq)] = headq[x]);
    (headq[x] = cntq);
    (qx[cntq] = x);
    (ql[cntq] = l);
    (qr[cntq] = r);
    (qop[cntq] = op);
    (qid[cntq] = id);
  }
  static void compute() {
    for (int i = 1; (i <= n); (i++)) {
      int num = arr[i];
      (pre[i] = pre[(i - 1)]);
      (pre[i] += xcnt[num]);
      {
        int e = headf[num];
        int f = {};
        int other = {};
        for (; (e > 0); (e = nextf[e])) {
          (f = fac[e]);
          (other = jdiv(num, f));
          (xcnt[f]++);
          (pre[i] += vcnt[f]);
          if ((other != f)) {
            (xcnt[other]++);
            (pre[i] += vcnt[other]);
          }
        }
      }
      (vcnt[num]++);
    }
    int winl = 1;
    int winr = 0;
    for (int i = 1; (i <= m); (i++)) {
      int jobl = query[i][0];
      int jobr = query[i][1];
      int id = query[i][2];
      if ((winr < jobr)) {
        Code04_Gosick1::addOffline((winl - 1), (winr + 1), jobr, (-1), id);
        (ans[id] += (pre[jobr] - pre[winr]));
      }
      if ((winr > jobr)) {
        Code04_Gosick1::addOffline((winl - 1), (jobr + 1), winr, 1, id);
        (ans[id] -= (pre[winr] - pre[jobr]));
      }
      (winr = jobr);
      if ((winl > jobl)) {
        Code04_Gosick1::addOffline(winr, jobl, (winl - 1), 1, id);
        (ans[id] -=
         ((pre[(winl - 1)] - pre[(jobl - 1)]) + (2 * (winl - jobl))));
      }
      if ((winl < jobl)) {
        Code04_Gosick1::addOffline(winr, winl, (jobl - 1), (-1), id);
        (ans[id] +=
         ((pre[(jobl - 1)] - pre[(winl - 1)]) + (2 * (jobl - winl))));
      }
      (winl = jobl);
    }
    j::fill(xcnt, 0);
    for (int x = 0; (x <= n); (x++)) {
      if ((x >= 1)) {
        int num = arr[x];
        {
          int e = headf[num];
          int f = {};
          int other = {};
          for (; (e > 0); (e = nextf[e])) {
            (f = fac[e]);
            (other = jdiv(num, f));
            (xcnt[f]++);
            if ((other != f)) {
              (xcnt[other]++);
            }
          }
        }
        if ((num > LIMIT)) {
          for (int v = num; (v <= maxv); (v += num)) {
            (xcnt[v]++);
          }
        }
      }
      for (int q = headq[x]; (q > 0); (q = nextq[q])) {
        int l = ql[q];
        int r = qr[q];
        int op = qop[q];
        int id = qid[q];
        for (int j = l; (j <= r); (j++)) {
          (ans[id] += (static_cast<i64>(op) * xcnt[arr[j]]));
        }
      }
    }
    for (int v = 1; (v <= LIMIT); (v++)) {
      (vcnt[0] = (xcnt[0] = 0));
      for (int i = 1; (i <= n); (i++)) {
        (vcnt[i] = (vcnt[(i - 1)] + ((arr[i] == v) ? 1 : 0)));
        (xcnt[i] = (xcnt[(i - 1)] + ((jrem(arr[i], v) == 0) ? 1 : 0)));
      }
      for (int i = 1; (i <= cntq); (i++)) {
        int x = qx[i];
        int l = ql[i];
        int r = qr[i];
        int op = qop[i];
        int id = qid[i];
        (ans[id] +=
         ((static_cast<i64>(op) * vcnt[x]) * (xcnt[r] - xcnt[(l - 1)])));
      }
    }
  }
  static void prepare() {
    int blen = static_cast<int>(std::sqrt(n));
    for (int i = 1; (i <= n); (i++)) {
      (bi[i] = (jdiv((i - 1), blen) + 1));
      (maxv = jmax(maxv, arr[i]));
      Code04_Gosick1::addFactors(arr[i]);
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
      (query[i][2] = i);
    }
    Code04_Gosick1::prepare();
    Code04_Gosick1::compute();
    for (int i = 2; (i <= m); (i++)) {
      (ans[query[i][2]] += ans[query[(i - 1)][2]]);
    }
    for (int i = 1; (i <= m); (i++)) {
      (ans[query[i][2]] += ((query[i][1] - query[i][0]) + 1));
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
  Code04_Gosick1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 区间倍数二元组，java版
// 给定一个长度为n的数组arr，下面给出倍数二元组的定义
// 如果arr[i]是arr[j]的倍数(>=1倍)，那么(i, j)就是一个倍数二元组
// 当i != j时，(i, j)和(j, i)认为是不同的二元组，不要漏算
// 当i == j时，(i, j)和(j, i)认为是相同的二元组，不要多算
// 比如[2, 4, 2, 6]，有10个倍数二元组
// 一共有m条查询，格式为 l r : 打印arr[l..r]范围上，有多少倍数二元组
// 1 <= n、m、arr[i] <= 5 * 10^5
// 测试链接 : https://www.luogu.com.cn/problem/P5398
// 提交以下的code，提交时请把类名改成"Main"
// java实现的逻辑一定是正确的，但是本题卡常，无法通过所有测试用例
// 想通过用C++实现，本节课Code04_Gosick2文件就是C++的实现
// 两个版本的逻辑完全一样，C++版本可以通过所有测试
        // 每个数的因子表，用链式前向星表达
        // 莫队任务
        // 二次离线的任务，也是链式前向星
        // xcnt[v] = 之前出现的数中，有多少数是此时数字v的倍数
        // vcnt[v] = 之前出现的数中，数字v出现了多少次
        // 前缀信息
                // 第一次离线，执行莫队
                        // 接下来是winl滑动
                        // 课上重点图解了，需要考虑 (2 * 滑动长度) 的修正
                // 第二次离线，num倍数的数量 +
num一部分因子的数量，都计入xcnt[num]
                                // 只处理大于LIMIT值的num
                // 第三次离线，1 ~ LIMIT 这些因子是少算了的，如今补回来
                        // 复用vcnt和xcnt
                        // vcnt[i]，当前表示，1~i范围上，v出现的次数
                        // xcnt[i]，当前表示，1~i范围上，v的倍数出现的次数
                // 答案变化量生成前缀和
                // 贡献是重新定义的，答案需要补偿回来
        // 读写工具类
*/

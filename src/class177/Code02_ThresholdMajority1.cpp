// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/threshold-majority-queries/

// Source: src/class177/Code02_ThresholdMajority1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_ThresholdMajority1 {
  struct Solution;
  struct Solution {
    struct QueryCmp;
    struct QueryCmp {
      String toString() const {
        return j::str(static_cast<const void *>(this));
      }
      QueryCmp() {}
      int compare(Array<int> a, Array<int> b) {
        if ((bi[a[0]] != bi[b[0]])) {
          return (bi[a[0]] - bi[b[0]]);
        }
        return (a[1] - b[1]);
      }
    };
    inline static int MAXN = 10001;
    inline static int MAXM = 50001;
    inline static int MAXB = 301;
    inline static int n = {};
    inline static int m = {};
    inline static Array<int> arr = make_array<int>(MAXN);
    inline static Array<Array<int>> query = make_array<int>(MAXM, 4);
    inline static Array<int> sorted = make_array<int>(MAXN);
    inline static int cntv = {};
    inline static int blen = {};
    inline static int bnum = {};
    inline static Array<int> bi = make_array<int>(MAXN);
    inline static Array<int> br = make_array<int>(MAXB);
    inline static Array<int> cnt = make_array<int>(MAXN);
    inline static int maxCnt = {};
    inline static int minMode = {};
    inline static Array<int> ans = make_array<int>(MAXM);
    String toString() const { return j::str(static_cast<const void *>(this)); }
    Solution() {}
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
    static int force(int l, int r, int k) {
      int mx = 0;
      int who = 0;
      for (int i = l; (i <= r); (i++)) {
        (cnt[arr[i]]++);
      }
      for (int i = l; (i <= r); (i++)) {
        int num = arr[i];
        if (((cnt[num] > mx) || ((cnt[num] == mx) && (num < who)))) {
          (mx = cnt[num]);
          (who = num);
        }
      }
      for (int i = l; (i <= r); (i++)) {
        (cnt[arr[i]]--);
      }
      return ((mx >= k) ? sorted[who] : (-1));
    }
    static void add(int num) {
      (cnt[num]++);
      if (((cnt[num] > maxCnt) || ((cnt[num] == maxCnt) && (num < minMode)))) {
        (maxCnt = cnt[num]);
        (minMode = num);
      }
    }
    static void del(int num) { (cnt[num]--); }
    static void compute() {
      {
        int block = 1;
        int qi = 1;
        for (; ((block <= bnum) && (qi <= m)); (block++)) {
          (maxCnt = 0);
          (minMode = 0);
          j::fill(cnt, 1, (cntv + 1), 0);
          int winl = (br[block] + 1);
          int winr = br[block];
          for (; ((qi <= m) && (bi[query[qi][0]] == block)); (qi++)) {
            int jobl = query[qi][0];
            int jobr = query[qi][1];
            int jobk = query[qi][2];
            int id = query[qi][3];
            if ((jobr <= br[block])) {
              (ans[id] = Solution::force(jobl, jobr, jobk));
            } else {
              while ((winr < jobr)) {
                Solution::add(arr[(++winr)]);
              }
              int backupCnt = maxCnt;
              int backupNum = minMode;
              while ((winl > jobl)) {
                Solution::add(arr[(--winl)]);
              }
              if ((maxCnt >= jobk)) {
                (ans[id] = sorted[minMode]);
              } else {
                (ans[id] = (-1));
              }
              (maxCnt = backupCnt);
              (minMode = backupNum);
              while ((winl <= br[block])) {
                Solution::del(arr[(winl++)]);
              }
            }
          }
        }
      }
    }
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
        (arr[i] = Solution::kth(arr[i]));
      }
      (blen = static_cast<int>(std::sqrt(n)));
      (bnum = jdiv(((n + blen) - 1), blen));
      for (int i = 1; (i <= n); (i++)) {
        (bi[i] = (jdiv((i - 1), blen) + 1));
      }
      for (int i = 1; (i <= bnum); (i++)) {
        (br[i] = jmin((i * blen), n));
      }
      j::sort(query, 1, (m + 1), new QueryCmp());
    }
    static Array<int> subarrayMajority(Array<int> nums,
                                       Array<Array<int>> queries) {
      (n = nums.length);
      (m = queries.length);
      {
        int i = 1;
        int j = 0;
        for (; (i <= n); (i++), (j++)) {
          (arr[i] = nums[j]);
        }
      }
      {
        int i = 1;
        int j = 0;
        for (; (i <= m); (i++), (j++)) {
          (query[i][0] = (queries[j][0] + 1));
          (query[i][1] = (queries[j][1] + 1));
          (query[i][2] = queries[j][2]);
          (query[i][3] = i);
        }
      }
      Solution::prepare();
      Solution::compute();
      Array<int> ret = make_array<int>(m);
      {
        int i = 1;
        int j = 0;
        for (; (i <= m); (i++), (j++)) {
          (ret[j] = ans[i]);
        }
      }
      return ret;
    }
  };
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_ThresholdMajority1() {}
};

/* Original teaching comments:
// 达到阈值的最小众数，java版
// 给定一个长度为n的数组arr，一共有m条查询，格式如下
// 查询 l r k : arr[l..r]范围上，如果所有数字的出现次数 < k，打印-1
//              如果有些数字的出现次数 >= k，打印其中的最小众数
// 1 <= n <= 10^4
// 1 <= m <= 5 * 10^4
// 1 <= arr[i] <= 10^9
// 测试链接 : https://leetcode.cn/problems/threshold-majority-queries/
// 提交以下代码中的Solution类，可以通过所有测试用例
*/

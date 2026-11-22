// Source: src/class177/Code01_MoAddUndo1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_MoAddUndo1 {
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
  inline static int MAXN = 100001;
  inline static int MAXB = 401;
  inline static int n = {};
  inline static int m = {};
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static Array<Array<int>> query = make_array<int>(MAXN, 3);
  inline static Array<int> sorted = make_array<int>(MAXN);
  inline static int cntv = {};
  inline static int blen = {};
  inline static int bnum = {};
  inline static Array<int> bi = make_array<int>(MAXN);
  inline static Array<int> br = make_array<int>(MAXB);
  inline static Array<int> cnt = make_array<int>(MAXN);
  inline static i64 curAns = 0;
  inline static Array<i64> ans = make_array<i64>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_MoAddUndo1() {}
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
  static i64 force(int l, int r) {
    i64 ret = 0;
    for (int i = l; (i <= r); (i++)) {
      (cnt[arr[i]]++);
    }
    for (int i = l; (i <= r); (i++)) {
      (ret = jmax(ret, (static_cast<i64>(cnt[arr[i]]) * sorted[arr[i]])));
    }
    for (int i = l; (i <= r); (i++)) {
      (cnt[arr[i]]--);
    }
    return ret;
  }
  static void add(int num) {
    (cnt[num]++);
    (curAns = jmax(curAns, (static_cast<i64>(cnt[num]) * sorted[num])));
  }
  static void del(int num) { (cnt[num]--); }
  static void compute() {
    {
      int block = 1;
      int qi = 1;
      for (; ((block <= bnum) && (qi <= m)); (block++)) {
        (curAns = 0);
        j::fill(cnt, 1, (cntv + 1), 0);
        int winl = (br[block] + 1);
        int winr = br[block];
        for (; ((qi <= m) && (bi[query[qi][0]] == block)); (qi++)) {
          int jobl = query[qi][0];
          int jobr = query[qi][1];
          int id = query[qi][2];
          if ((jobr <= br[block])) {
            (ans[id] = Code01_MoAddUndo1::force(jobl, jobr));
          } else {
            while ((winr < jobr)) {
              Code01_MoAddUndo1::add(arr[(++winr)]);
            }
            i64 backup = curAns;
            while ((winl > jobl)) {
              Code01_MoAddUndo1::add(arr[(--winl)]);
            }
            (ans[id] = curAns);
            (curAns = backup);
            while ((winl <= br[block])) {
              Code01_MoAddUndo1::del(arr[(winl++)]);
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
      (arr[i] = Code01_MoAddUndo1::kth(arr[i]));
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
    Code01_MoAddUndo1::prepare();
    Code01_MoAddUndo1::compute();
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
  Code01_MoAddUndo1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 只增回滚莫队入门题，java版
// 给定一个长度为n的数组arr，下面定义重要度的概念
// 如果一段范围上，数字x出现c次，那么这个数字的重要度为x * c
// 范围上的最大重要度，就是该范围上，每种数字的重要度，取最大值
// 一共有m条查询，格式 l r : 打印arr[l..r]范围上的最大重要度
// 1 <= n、m <= 10^5
// 1 <= arr[i] <= 10^9
// 测试链接 : https://www.luogu.com.cn/problem/AT_joisc2014_c
// 测试链接 : https://atcoder.jp/contests/joisc2014/tasks/joisc2014_c
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 词频表
        // 当前窗口的最大重要度
        // 收集所有答案
        // 只增回滚莫队经典排序
        // 暴力遍历arr[l..r]得到答案
        // 窗口增加num，词频和答案都更新
        // 窗口减少num，词频更新、答案不更新
        // 读写工具类
*/

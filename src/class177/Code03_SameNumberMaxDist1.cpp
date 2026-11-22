// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P5906

// Source: src/class177/Code03_SameNumberMaxDist1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_SameNumberMaxDist1 {
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
  inline static int MAXN = 200001;
  inline static int MAXB = 501;
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
  inline static Array<int> first = make_array<int>(MAXN);
  inline static Array<int> mostRight = make_array<int>(MAXN);
  inline static int maxDist = {};
  inline static Array<int> ans = make_array<int>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_SameNumberMaxDist1() {}
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
  static int force(int l, int r) {
    int ret = 0;
    for (int i = l; (i <= r); (i++)) {
      if ((first[arr[i]] == 0)) {
        (first[arr[i]] = i);
      } else {
        (ret = jmax(ret, (i - first[arr[i]])));
      }
    }
    for (int i = l; (i <= r); (i++)) {
      (first[arr[i]] = 0);
    }
    return ret;
  }
  static void addRight(int idx) {
    int num = arr[idx];
    (mostRight[num] = idx);
    if ((first[num] == 0)) {
      (first[num] = idx);
    }
    (maxDist = jmax(maxDist, (idx - first[num])));
  }
  static void addLeft(int idx) {
    int num = arr[idx];
    if ((mostRight[num] == 0)) {
      (mostRight[num] = idx);
    } else {
      (maxDist = jmax(maxDist, (mostRight[num] - idx)));
    }
  }
  static void delLeft(int idx) {
    int num = arr[idx];
    if ((mostRight[num] == idx)) {
      (mostRight[num] = 0);
    }
  }
  static void compute() {
    {
      int block = 1;
      int qi = 1;
      for (; ((block <= bnum) && (qi <= m)); (block++)) {
        (maxDist = 0);
        j::fill(first, 1, (cntv + 1), 0);
        j::fill(mostRight, 1, (cntv + 1), 0);
        int winl = (br[block] + 1);
        int winr = br[block];
        for (; ((qi <= m) && (bi[query[qi][0]] == block)); (qi++)) {
          int jobl = query[qi][0];
          int jobr = query[qi][1];
          int id = query[qi][2];
          if ((jobr <= br[block])) {
            (ans[id] = Code03_SameNumberMaxDist1::force(jobl, jobr));
          } else {
            while ((winr < jobr)) {
              Code03_SameNumberMaxDist1::addRight((++winr));
            }
            int backup = maxDist;
            while ((winl > jobl)) {
              Code03_SameNumberMaxDist1::addLeft((--winl));
            }
            (ans[id] = maxDist);
            (maxDist = backup);
            while ((winl <= br[block])) {
              Code03_SameNumberMaxDist1::delLeft((winl++));
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
      (arr[i] = Code03_SameNumberMaxDist1::kth(arr[i]));
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
    for (int i = 1; (i <= n); (i++)) {
      (arr[i] = in.nextInt());
    }
    (m = in.nextInt());
    for (int i = 1; (i <= m); (i++)) {
      (query[i][0] = in.nextInt());
      (query[i][1] = in.nextInt());
      (query[i][2] = i);
    }
    Code03_SameNumberMaxDist1::prepare();
    Code03_SameNumberMaxDist1::compute();
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
  Code03_SameNumberMaxDist1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 相同数的最远距离，java版
// 给定一个长度为n的数组arr，一共有m条查询，格式如下
// 查询 l r : 打印arr[l..r]范围上，相同的数的最远间隔距离
//            序列中两个元素的间隔距离指的是两个元素下标差的绝对值
// 1 <= n、m <= 2 * 10^5
// 1 <= arr[i] <= 2 * 10^9
// 测试链接 : https://www.luogu.com.cn/problem/P5906
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // first[x]表示只考虑窗口右扩阶段，数字x首次出现的位置
        // mostRight[x]表示窗口中数字x最右出现的位置
        // 答案信息，相同的数的最远间隔距离
        // 读写工具类
*/

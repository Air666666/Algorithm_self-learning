// Source: src/class177/Code05_MoDelUndo1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code05_MoDelUndo1 {
  struct QueryCmp;
  struct QueryCmp {
    String toString() const { return j::str(static_cast<const void *>(this)); }
    QueryCmp() {}
    int compare(Array<int> a, Array<int> b) {
      if ((bi[a[0]] != bi[b[0]])) {
        return (bi[a[0]] - bi[b[0]]);
      }
      return (b[1] - a[1]);
    }
  };
  inline static int MAXN = 200001;
  inline static int MAXB = 501;
  inline static int n = {};
  inline static int m = {};
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static Array<Array<int>> query = make_array<int>(MAXN, 3);
  inline static int blen = {};
  inline static int bnum = {};
  inline static Array<int> bi = make_array<int>(MAXN);
  inline static Array<int> bl = make_array<int>(MAXB);
  inline static Array<int> cnt = make_array<int>(MAXN);
  inline static int mex = {};
  inline static Array<int> ans = make_array<int>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code05_MoDelUndo1() {}
  static void del(int num) {
    if (((--cnt[num]) == 0)) {
      (mex = jmin(mex, num));
    }
  }
  static void add(int num) { (cnt[num]++); }
  static void compute() {
    for (int i = 1; (i <= n); (i++)) {
      (cnt[arr[i]]++);
    }
    (mex = 0);
    while ((cnt[mex] != 0)) {
      (mex++);
    }
    int winl = 1;
    int winr = n;
    {
      int block = 1;
      int qi = 1;
      for (; ((block <= bnum) && (qi <= m)); (block++)) {
        while ((winl < bl[block])) {
          Code05_MoDelUndo1::del(arr[(winl++)]);
        }
        int beforeJob = mex;
        for (; ((qi <= m) && (bi[query[qi][0]] == block)); (qi++)) {
          int jobl = query[qi][0];
          int jobr = query[qi][1];
          int id = query[qi][2];
          while ((winr > jobr)) {
            Code05_MoDelUndo1::del(arr[(winr--)]);
          }
          int backup = mex;
          while ((winl < jobl)) {
            Code05_MoDelUndo1::del(arr[(winl++)]);
          }
          (ans[id] = mex);
          (mex = backup);
          while ((winl > bl[block])) {
            Code05_MoDelUndo1::add(arr[(--winl)]);
          }
        }
        while ((winr < n)) {
          Code05_MoDelUndo1::add(arr[(++winr)]);
        }
        (mex = beforeJob);
      }
    }
  }
  static void prepare() {
    (blen = static_cast<int>(std::sqrt(n)));
    (bnum = jdiv(((n + blen) - 1), blen));
    for (int i = 1; (i <= n); (i++)) {
      (bi[i] = (jdiv((i - 1), blen) + 1));
    }
    for (int i = 1; (i <= bnum); (i++)) {
      (bl[i] = (((i - 1) * blen) + 1));
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
    Code05_MoDelUndo1::prepare();
    Code05_MoDelUndo1::compute();
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
  Code05_MoDelUndo1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 只删回滚莫队入门题，java版
// 本题最优解为主席树，讲解158，题目2，已经讲述
// 给定一个长度为n的数组arr，一共有m条查询，格式如下
// 查询 l r : 打印arr[l..r]内没有出现过的最小自然数，注意0是自然数
// 0 <= n、m、arr[i] <= 2 * 10^5
// 测试链接 : https://www.luogu.com.cn/problem/P4137
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 只删回滚莫队经典排序
        // 读写工具类
*/

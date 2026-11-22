// Source: src/class179/Code02_SimpleQuery1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_SimpleQuery1 {
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
  inline static int MAXN = 50001;
  inline static int n = {};
  inline static int q = {};
  inline static int cntq = {};
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static Array<Array<int>> query = make_array<int>(jshl(MAXN, 2), 4);
  inline static Array<int> bi = make_array<int>(MAXN);
  inline static Array<int> cnt1 = make_array<int>(MAXN);
  inline static Array<int> cnt2 = make_array<int>(MAXN);
  inline static i64 curAns = 0;
  inline static Array<i64> ans = make_array<i64>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_SimpleQuery1() {}
  static void addQuery(int siz1, int siz2, int op, int id) {
    (query[(++cntq)][0] = siz1);
    (query[cntq][1] = siz2);
    (query[cntq][2] = op);
    (query[cntq][3] = id);
  }
  static void compute() {
    int win1 = 0;
    int win2 = 0;
    for (int i = 1; (i <= cntq); (i++)) {
      int job1 = query[i][0];
      int job2 = query[i][1];
      int op = query[i][2];
      int id = query[i][3];
      while ((win1 < job1)) {
        (win1++);
        (cnt1[arr[win1]]++);
        (curAns += cnt2[arr[win1]]);
      }
      while ((win1 > job1)) {
        (cnt1[arr[win1]]--);
        (curAns -= cnt2[arr[win1]]);
        (win1--);
      }
      while ((win2 < job2)) {
        (win2++);
        (cnt2[arr[win2]]++);
        (curAns += cnt1[arr[win2]]);
      }
      while ((win2 > job2)) {
        (cnt2[arr[win2]]--);
        (curAns -= cnt1[arr[win2]]);
        (win2--);
      }
      (ans[id] += (curAns * op));
    }
  }
  static void prepare() {
    int blen = static_cast<int>(std::sqrt(n));
    for (int i = 1; (i <= n); (i++)) {
      (bi[i] = (jdiv((i - 1), blen) + 1));
    }
    for (int i = 1; (i <= cntq); (i++)) {
      if ((query[i][0] > query[i][1])) {
        int tmp = query[i][0];
        (query[i][0] = query[i][1]);
        (query[i][1] = tmp);
      }
    }
    j::sort(query, 1, (cntq + 1), new QueryCmp());
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    for (int i = 1; (i <= n); (i++)) {
      (arr[i] = in.nextInt());
    }
    (q = in.nextInt());
    {
      int i = 1;
      int l1 = {};
      int r1 = {};
      int l2 = {};
      int r2 = {};
      for (; (i <= q); (i++)) {
        (l1 = in.nextInt());
        (r1 = in.nextInt());
        (l2 = in.nextInt());
        (r2 = in.nextInt());
        Code02_SimpleQuery1::addQuery(r1, r2, 1, i);
        Code02_SimpleQuery1::addQuery(r1, (l2 - 1), (-1), i);
        Code02_SimpleQuery1::addQuery((l1 - 1), r2, (-1), i);
        Code02_SimpleQuery1::addQuery((l1 - 1), (l2 - 1), 1, i);
      }
    }
    Code02_SimpleQuery1::prepare();
    Code02_SimpleQuery1::compute();
    for (int i = 1; (i <= q); (i++)) {
      out.println(ans[i]);
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code02_SimpleQuery1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 简单的询问，java版
// 给定一个长度为n的数组arr，下标从1到n
// 函数get(l, r, x) = arr[l..r]范围上，数组x出现的次数
// 接下来有q条查询，格式如下
// 查询 l1 r1 l2 r2 : 每种x都算，打印 get(l1, r1, x) * get(l2, r2, x) 的累加和
// 1 <= n、q <= 5 * 10^4
// 1 <= arr[i] <= n
// 测试链接 : https://www.luogu.com.cn/problem/P5268
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 查询任务，siz1、siz2、op、id
        // cnt1 : arr[1..siz1]范围内每种数字出现的次数
        // cnt2 : arr[1..siz2]范围内每种数字出现的次数
        // win1和win2不代表一段区间，而是代表两个独立区域各自去覆盖arr
        // win1 = 0，win2 = 0，表示两个覆盖区域一开始都没有数字
        // job1和job2也不代表区间，而是代表两个区域各自要覆盖多大
        // 读写工具类
*/

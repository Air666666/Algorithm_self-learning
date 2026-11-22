// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P4477

// Source: src/class179/Code04_MaximumMatch1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_MaximumMatch1 {
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
  inline static int MAXN = 152502;
  inline static int MAXM = 52502;
  inline static int MAXQ = 52502;
  inline static int n = {};
  inline static int m = {};
  inline static int z = {};
  inline static int q = {};
  inline static Array<int> a = make_array<int>(MAXN);
  inline static Array<int> b = make_array<int>(MAXM);
  inline static Array<Array<int>> query = make_array<int>(MAXQ, 3);
  inline static Array<int> bi = make_array<int>(MAXM);
  inline static Array<int> match = make_array<int>(jshl(MAXN, 2));
  inline static Array<int> resta = make_array<int>(jshl(MAXN, 2));
  inline static Array<int> overb = make_array<int>(jshl(MAXN, 2));
  inline static Array<int> ans = make_array<int>(MAXQ);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_MaximumMatch1() {}
  static void up(int i) {
    int l = jshl(i, 1);
    int r = (jshl(i, 1) | 1);
    int newMatch = jmin(resta[l], overb[r]);
    (resta[i] = ((resta[l] + resta[r]) - newMatch));
    (overb[i] = ((overb[l] + overb[r]) - newMatch));
    (match[i] = ((match[l] + match[r]) + newMatch));
  }
  static void build(int l, int r, int i) {
    if ((l == r)) {
      (match[i] = 0);
      (resta[i] = 1);
      (overb[i] = 0);
    } else {
      int mid = jshr((l + r), 1);
      Code04_MaximumMatch1::build(l, mid, jshl(i, 1));
      Code04_MaximumMatch1::build((mid + 1), r, (jshl(i, 1) | 1));
      Code04_MaximumMatch1::up(i);
    }
  }
  static void add(int jobv, int l, int r, int i) {
    if ((l == r)) {
      if ((resta[i] == 1)) {
        (match[i] = 1);
        (resta[i] = 0);
      } else {
        (overb[i]++);
      }
    } else {
      int mid = jshr((l + r), 1);
      if (((jobv + a[(mid + 1)]) <= z)) {
        Code04_MaximumMatch1::add(jobv, (mid + 1), r, (jshl(i, 1) | 1));
      } else if (((jobv + a[l]) <= z)) {
        Code04_MaximumMatch1::add(jobv, l, mid, jshl(i, 1));
      }
      Code04_MaximumMatch1::up(i);
    }
  }
  static void del(int jobv, int l, int r, int i) {
    if ((l == r)) {
      if ((overb[i] > 0)) {
        (overb[i]--);
      } else {
        (match[i] = 0);
        (resta[i] = 1);
      }
    } else {
      int mid = jshr((l + r), 1);
      if (((jobv + a[(mid + 1)]) <= z)) {
        Code04_MaximumMatch1::del(jobv, (mid + 1), r, (jshl(i, 1) | 1));
      } else if (((jobv + a[l]) <= z)) {
        Code04_MaximumMatch1::del(jobv, l, mid, jshl(i, 1));
      }
      Code04_MaximumMatch1::up(i);
    }
  }
  static void prepare() {
    j::sort(a, 1, (n + 1));
    int blen = static_cast<int>(std::sqrt(m));
    for (int i = 1; (i <= m); (i++)) {
      (bi[i] = (jdiv((i - 1), blen) + 1));
    }
    j::sort(query, 1, (q + 1), new QueryCmp());
    Code04_MaximumMatch1::build(1, n, 1);
  }
  static void compute() {
    int winl = 1;
    int winr = 0;
    for (int i = 1; (i <= q); (i++)) {
      int jobl = query[i][0];
      int jobr = query[i][1];
      int id = query[i][2];
      while ((winl > jobl)) {
        Code04_MaximumMatch1::add(b[(--winl)], 1, n, 1);
      }
      while ((winr < jobr)) {
        Code04_MaximumMatch1::add(b[(++winr)], 1, n, 1);
      }
      while ((winl < jobl)) {
        Code04_MaximumMatch1::del(b[(winl++)], 1, n, 1);
      }
      while ((winr > jobr)) {
        Code04_MaximumMatch1::del(b[(winr--)], 1, n, 1);
      }
      (ans[id] = match[1]);
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (m = in.nextInt());
    (z = in.nextInt());
    for (int i = 1; (i <= n); (i++)) {
      (a[i] = in.nextInt());
    }
    for (int i = 1; (i <= m); (i++)) {
      (b[i] = in.nextInt());
    }
    (q = in.nextInt());
    for (int i = 1; (i <= q); (i++)) {
      (query[i][0] = in.nextInt());
      (query[i][1] = in.nextInt());
      (query[i][2] = i);
    }
    Code04_MaximumMatch1::prepare();
    Code04_MaximumMatch1::compute();
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
  Code04_MaximumMatch1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 区间最大匹配，java版
// 给定长度为n的数组a、长度为m的数组b、一个正数z
// 数组a中数字x、数组b中数字y，如果x + y <= z，那么构成一个匹配
// 已经匹配的数字，不可以重复使用，一共有q条查询，格式如下
// 查询 l r : 数组b[l..r]范围上的数字，随意选择数组a中的数字，打印最多匹配数
// 1 <= n <= 152501
// 1 <= m、q <= 52501
// 1 <= a[i]、b[i]、z <= 10^9
// 测试链接 : https://www.luogu.com.cn/problem/P4477
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        //
线段树维护匹配信息，a[l..r]和b数组的数字进行匹配，l..r对应的信息在i位置
        // match[i] = v，a[l..r]和b数组的数字，一共匹配了v对
        // resta[i] = v，a[l..r]中还有v个数，可用于匹配b数组的数字
        // overb[i] = v，a[l..r]已经耗尽，但是还有v个b数组的数字没有满足
        // 读写工具类
*/

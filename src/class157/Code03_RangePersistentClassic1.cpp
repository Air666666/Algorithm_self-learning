// Source: src/class157/Code03_RangePersistentClassic1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_RangePersistentClassic1 {
  inline static int MAXN = 100001;
  inline static int MAXT = (MAXN * 70);
  inline static int n = {};
  inline static int m = {};
  inline static int t = 0;
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static Array<int> root = make_array<int>(MAXN);
  inline static Array<int> left = make_array<int>(MAXT);
  inline static Array<int> right = make_array<int>(MAXT);
  inline static Array<i64> sum = make_array<i64>(MAXT);
  inline static Array<i64> add = make_array<i64>(MAXT);
  inline static int cnt = 0;
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_RangePersistentClassic1() {}
  static int clone(int i) {
    int rt = (++cnt);
    (left[rt] = left[i]);
    (right[rt] = right[i]);
    (sum[rt] = sum[i]);
    (add[rt] = add[i]);
    return rt;
  }
  static void up(int i) { (sum[i] = (sum[left[i]] + sum[right[i]])); }
  static void lazy(int i, i64 v, int n) {
    (sum[i] += (v * n));
    (add[i] += v);
  }
  static void down(int i, int ln, int rn) {
    if ((add[i] != 0)) {
      (left[i] = Code03_RangePersistentClassic1::clone(left[i]));
      (right[i] = Code03_RangePersistentClassic1::clone(right[i]));
      Code03_RangePersistentClassic1::lazy(left[i], add[i], ln);
      Code03_RangePersistentClassic1::lazy(right[i], add[i], rn);
      (add[i] = 0);
    }
  }
  static int build(int l, int r) {
    int rt = (++cnt);
    (add[rt] = 0);
    if ((l == r)) {
      (sum[rt] = arr[l]);
    } else {
      int mid = jdiv((l + r), 2);
      (left[rt] = Code03_RangePersistentClassic1::build(l, mid));
      (right[rt] = Code03_RangePersistentClassic1::build((mid + 1), r));
      Code03_RangePersistentClassic1::up(rt);
    }
    return rt;
  }
  static int add_method(int jobl, int jobr, i64 jobv, int l, int r, int i) {
    int rt = Code03_RangePersistentClassic1::clone(i);
    if (((jobl <= l) && (r <= jobr))) {
      Code03_RangePersistentClassic1::lazy(rt, jobv, ((r - l) + 1));
    } else {
      int mid = jdiv((l + r), 2);
      Code03_RangePersistentClassic1::down(rt, ((mid - l) + 1), (r - mid));
      if ((jobl <= mid)) {
        (left[rt] = Code03_RangePersistentClassic1::add_method(
             jobl, jobr, jobv, l, mid, left[rt]));
      }
      if ((jobr > mid)) {
        (right[rt] = Code03_RangePersistentClassic1::add_method(
             jobl, jobr, jobv, (mid + 1), r, right[rt]));
      }
      Code03_RangePersistentClassic1::up(rt);
    }
    return rt;
  }
  static i64 query(int jobl, int jobr, int l, int r, int i) {
    if (((jobl <= l) && (r <= jobr))) {
      return sum[i];
    }
    int mid = jdiv((l + r), 2);
    Code03_RangePersistentClassic1::down(i, ((mid - l) + 1), (r - mid));
    i64 ans = 0;
    if ((jobl <= mid)) {
      (ans +=
       Code03_RangePersistentClassic1::query(jobl, jobr, l, mid, left[i]));
    }
    if ((jobr > mid)) {
      (ans += Code03_RangePersistentClassic1::query(jobl, jobr, (mid + 1), r,
                                                    right[i]));
    }
    return ans;
  }
  static void java_main(Array<String> args) {
    IO in = IO();
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (m = in.nextInt());
    for (int i = 1; (i <= n); (i++)) {
      (arr[i] = in.nextInt());
    }
    (root[0] = Code03_RangePersistentClassic1::build(1, n));
    String op = {};
    {
      int i = 1;
      int x = {};
      int y = {};
      int z = {};
      for (; (i <= m); (i++)) {
        (op = in.next());
        if (op.equals(String(u"C"))) {
          (x = in.nextInt());
          (y = in.nextInt());
          (z = in.nextInt());
          (root[(t + 1)] = Code03_RangePersistentClassic1::add_method(
               x, y, z, 1, n, root[t]));
          (t++);
        } else if (op.equals(String(u"Q"))) {
          (x = in.nextInt());
          (y = in.nextInt());
          out.write(
              (Code03_RangePersistentClassic1::query(x, y, 1, n, root[t]) +
               String(u"\n")));
        } else if (op.equals(String(u"H"))) {
          (x = in.nextInt());
          (y = in.nextInt());
          (z = in.nextInt());
          out.write(
              (Code03_RangePersistentClassic1::query(x, y, 1, n, root[z]) +
               String(u"\n")));
        } else {
          (x = in.nextInt());
          (t = x);
        }
      }
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code03_RangePersistentClassic1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 范围修改的可持久化线段树，经典的方式，java版
// 给定一个长度为n的数组arr，下标1~n，时间戳t=0，arr认为是0版本的数组
// 一共有m条操作，每条操作为如下四种类型中的一种
// C x y z :
当前时间戳t版本的数组，[x..y]范围每个数字增加z，得到t+1版本数组，并且t++
// Q x y   : 当前时间戳t版本的数组，打印[x..y]范围累加和
// H x y z : z版本的数组，打印[x..y]范围的累加和
// B x     : 当前时间戳t设置成x
// 1 <= n、m <= 10^5
// -10^9 <= arr[i] <= +10^9
// 测试链接 : https://www.luogu.com.cn/problem/SP11470
// 测试链接 : https://www.spoj.com/problems/TTM
// 提交以下的code，提交时请把类名改成"Main"
// java实现的逻辑一定是正确的，但是通过不了
// 因为这道题根据C++的运行时间，制定通过标准，根本没考虑java的用户
// 想通过用C++实现，本节课Code03_RangePersistentClassic2文件就是C++的实现
// 两个版本的逻辑完全一样，C++版本可以通过所有测试
        // 累加和信息
        // 懒更新信息，范围增加的懒更新
        // 读写工具类
*/

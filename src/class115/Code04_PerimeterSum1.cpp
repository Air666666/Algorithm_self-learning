// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P1856

// Source: src/class115/Code04_PerimeterSum1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_PerimeterSum1 {
  inline static int MAXN = 10001;
  inline static Array<Array<int>> rec = make_array<int>(MAXN, 4);
  inline static Array<Array<int>> line = make_array<int>(MAXN, 4);
  inline static Array<int> vsort = make_array<int>(MAXN);
  inline static Array<int> length = make_array<int>(jshl(MAXN, 2));
  inline static Array<int> cover = make_array<int>(jshl(MAXN, 2));
  inline static Array<int> times = make_array<int>(jshl(MAXN, 2));
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_PerimeterSum1() {}
  static int prepare(int n) {
    j::sort(vsort, 1, (n + 1));
    int m = 1;
    for (int i = 2; (i <= n); (i++)) {
      if ((vsort[m] != vsort[i])) {
        (vsort[(++m)] = vsort[i]);
      }
    }
    (vsort[(m + 1)] = vsort[m]);
    return m;
  }
  static int rank(int n, int num) {
    int ans = 0;
    int l = 1;
    int r = n;
    int mid = {};
    while ((l <= r)) {
      (mid = jshr((l + r), 1));
      if ((vsort[mid] >= num)) {
        (ans = mid);
        (r = (mid - 1));
      } else {
        (l = (mid + 1));
      }
    }
    return ans;
  }
  static void build(int l, int r, int i) {
    if ((l < r)) {
      int mid = jshr((l + r), 1);
      Code04_PerimeterSum1::build(l, mid, jshl(i, 1));
      Code04_PerimeterSum1::build((mid + 1), r, (jshl(i, 1) | 1));
    }
    (length[i] = (vsort[(r + 1)] - vsort[l]));
    (times[i] = 0);
    (cover[i] = 0);
  }
  static void up(int l, int r, int i) {
    if ((times[i] > 0)) {
      (cover[i] = length[i]);
    } else if ((l == r)) {
      (cover[i] = 0);
    } else {
      (cover[i] = (cover[jshl(i, 1)] + cover[(jshl(i, 1) | 1)]));
    }
  }
  static void add(int jobl, int jobr, int jobv, int l, int r, int i) {
    if (((jobl <= l) && (r <= jobr))) {
      (times[i] += jobv);
    } else {
      int mid = jshr((l + r), 1);
      if ((jobl <= mid)) {
        Code04_PerimeterSum1::add(jobl, jobr, jobv, l, mid, jshl(i, 1));
      }
      if ((jobr > mid)) {
        Code04_PerimeterSum1::add(jobl, jobr, jobv, (mid + 1), r,
                                  (jshl(i, 1) | 1));
      }
    }
    Code04_PerimeterSum1::up(l, r, i);
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    int n = static_cast<int>(in.nval);
    for (int i = 1; (i <= n); (i++)) {
      in.nextToken();
      (rec[i][0] = static_cast<int>(in.nval));
      in.nextToken();
      (rec[i][1] = static_cast<int>(in.nval));
      in.nextToken();
      (rec[i][2] = static_cast<int>(in.nval));
      in.nextToken();
      (rec[i][3] = static_cast<int>(in.nval));
    }
    out.println(Code04_PerimeterSum1::compute(n));
    out.flush();
    out.close();
    br.close();
  }
  static i64 compute(int n) {
    return [&]() {
      auto jleft = Code04_PerimeterSum1::scanY(n);
      auto jright = Code04_PerimeterSum1::scanX(n);
      return (jleft + jright);
    }();
  }
  static i64 scanY(int n) {
    {
      int i = 1;
      int j = (1 + n);
      int x1 = {};
      int y1 = {};
      int x2 = {};
      int y2 = {};
      for (; (i <= n); (i++), (j++)) {
        (x1 = rec[i][0]);
        (y1 = rec[i][1]);
        (x2 = rec[i][2]);
        (y2 = rec[i][3]);
        (vsort[i] = y1);
        (vsort[j] = y2);
        (line[i][0] = x1);
        (line[i][1] = y1);
        (line[i][2] = y2);
        (line[i][3] = 1);
        (line[j][0] = x2);
        (line[j][1] = y1);
        (line[j][2] = y2);
        (line[j][3] = (-1));
      }
    }
    return Code04_PerimeterSum1::scan(jshl(n, 1));
  }
  static i64 scanX(int n) {
    {
      int i = 1;
      int j = (1 + n);
      int x1 = {};
      int y1 = {};
      int x2 = {};
      int y2 = {};
      for (; (i <= n); (i++), (j++)) {
        (x1 = rec[i][0]);
        (y1 = rec[i][1]);
        (x2 = rec[i][2]);
        (y2 = rec[i][3]);
        (vsort[i] = x1);
        (vsort[j] = x2);
        (line[i][0] = y1);
        (line[i][1] = x1);
        (line[i][2] = x2);
        (line[i][3] = 1);
        (line[j][0] = y2);
        (line[j][1] = x1);
        (line[j][2] = x2);
        (line[j][3] = (-1));
      }
    }
    return Code04_PerimeterSum1::scan(jshl(n, 1));
  }
  static i64 scan(int n) {
    int m = Code04_PerimeterSum1::prepare(n);
    Code04_PerimeterSum1::build(1, m, 1);
    j::sort(line, 1, (n + 1), [=](Array<int> a, Array<int> b) {
      return ((a[0] != b[0]) ? (a[0] - b[0]) : (b[3] - a[3]));
    });
    i64 ans = 0;
    {
      int i = 1;
      int pre = {};
      for (; (i <= n); (i++)) {
        (pre = cover[1]);
        [&]() {
          auto jargument_0 = Code04_PerimeterSum1::rank(m, line[i][1]);
          auto jargument_1 = (Code04_PerimeterSum1::rank(m, line[i][2]) - 1);
          auto jargument_2 = line[i][3];
          auto jargument_3 = 1;
          auto jargument_4 = m;
          auto jargument_5 = 1;
          return Code04_PerimeterSum1::add(jargument_0, jargument_1,
                                           jargument_2, jargument_3,
                                           jargument_4, jargument_5);
        }();
        (ans += std::abs((cover[1] - pre)));
      }
    }
    return ans;
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code04_PerimeterSum1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 矩形周长并(洛谷测试)
// 测试链接 : https://www.luogu.com.cn/problem/P1856
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下的code，提交时请把类名改成"Main"，可以直接通过
        // 线段树某范围总长度
        // 线段树某范围覆盖长度
        // 线段树某范围覆盖次数
                        // 叶节点直接设置cover不需要下层信息
                        // 左下角下标
                        // 右上角下标
                // 这里有个坑
                // 在排序时，如果同一个位置的扫描线有多条，也就是a[0] == b[0]时
                // 应该先处理区间覆盖+1的扫描线，然后再处理区间覆盖-1的扫描线
                // 不然投影长度会频繁变化，导致答案错误
                // 不过测试数据并没有安排这方面的测试
*/

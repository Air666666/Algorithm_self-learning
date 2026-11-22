// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P5490

// Source: src/class115/Code03_AreaSum.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_AreaSum {
  inline static int MAXN = 200001;
  inline static Array<Array<int>> rec = make_array<int>(MAXN, 4);
  inline static Array<Array<int>> line = make_array<int>(MAXN, 4);
  inline static Array<int> ysort = make_array<int>(MAXN);
  inline static Array<int> length = make_array<int>(jshl(MAXN, 2));
  inline static Array<int> cover = make_array<int>(jshl(MAXN, 2));
  inline static Array<int> times = make_array<int>(jshl(MAXN, 2));
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_AreaSum() {}
  static int prepare(int n) {
    j::sort(ysort, 1, (n + 1));
    int m = 1;
    for (int i = 2; (i <= n); (i++)) {
      if ((ysort[m] != ysort[i])) {
        (ysort[(++m)] = ysort[i]);
      }
    }
    (ysort[(m + 1)] = ysort[m]);
    return m;
  }
  static int rank(int n, int num) {
    int ans = 0;
    int l = 1;
    int r = n;
    int mid = {};
    while ((l <= r)) {
      (mid = jshr((l + r), 1));
      if ((ysort[mid] >= num)) {
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
      Code03_AreaSum::build(l, mid, jshl(i, 1));
      Code03_AreaSum::build((mid + 1), r, (jshl(i, 1) | 1));
    }
    (length[i] = (ysort[(r + 1)] - ysort[l]));
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
        Code03_AreaSum::add(jobl, jobr, jobv, l, mid, jshl(i, 1));
      }
      if ((jobr > mid)) {
        Code03_AreaSum::add(jobl, jobr, jobv, (mid + 1), r, (jshl(i, 1) | 1));
      }
    }
    Code03_AreaSum::up(l, r, i);
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
    out.println(Code03_AreaSum::compute(n));
    out.flush();
    out.close();
    br.close();
  }
  static i64 compute(int n) {
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
        (ysort[i] = y1);
        (ysort[j] = y2);
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
    (n = jshl(n, 1));
    int m = Code03_AreaSum::prepare(n);
    Code03_AreaSum::build(1, m, 1);
    j::sort(line, 1, (n + 1),
            [=](Array<int> a, Array<int> b) { return (a[0] - b[0]); });
    i64 ans = 0;
    {
      int i = 1;
      int pre = 0;
      for (; (i <= n); (i++)) {
        (ans += (static_cast<i64>(cover[1]) * (line[i][0] - pre)));
        (pre = line[i][0]);
        [&]() {
          auto jargument_0 = Code03_AreaSum::rank(m, line[i][1]);
          auto jargument_1 = (Code03_AreaSum::rank(m, line[i][2]) - 1);
          auto jargument_2 = line[i][3];
          auto jargument_3 = 1;
          auto jargument_4 = m;
          auto jargument_5 = 1;
          return Code03_AreaSum::add(jargument_0, jargument_1, jargument_2,
                                     jargument_3, jargument_4, jargument_5);
        }();
      }
    }
    return ans;
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code03_AreaSum::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 矩形面积并
// 测试链接 : https://www.luogu.com.cn/problem/P5490
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下的code，提交时请把类名改成"Main"，可以直接通过
        // 线段树某范围总长度
        // 线段树某范围覆盖长度
        // 线段树某范围覆盖次数
                        // 叶节点直接设置cover不需要下层信息
        // 这个题的特殊性在于
        // 1) 查询操作永远查的是整个范围，不会有小范围的查询，每次都返回cover[1]
        // 2) 增加操作之后，后续一定会有等规模的减少操作
        // 根据以上两点分析出不需要懒更新机制
        //
首先当一次修改完成从下往上返回时，up方法能保证最上方的cover[1]是修改正确的
        //
同时任何一次增加操作所涉及的线段树范围，后续一定能被等规模的减少操作取消掉
        // 课上重点图解这个特殊性
                        // 左下角下标
                        // 右上角下标
*/

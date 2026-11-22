// Source: src/class110/Code01_SegmentTreeAddQuerySum.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_SegmentTreeAddQuerySum {
  inline static int MAXN = 100001;
  inline static Array<i64> arr = make_array<i64>(MAXN);
  inline static Array<i64> sum = make_array<i64>(jshl(MAXN, 2));
  inline static Array<i64> add = make_array<i64>(jshl(MAXN, 2));
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_SegmentTreeAddQuerySum() {}
  static void up(int i) {
    (sum[i] = (sum[jshl(i, 1)] + sum[(jshl(i, 1) | 1)]));
  }
  static void down(int i, int ln, int rn) {
    if ((add[i] != 0)) {
      Code01_SegmentTreeAddQuerySum::lazy(jshl(i, 1), add[i], ln);
      Code01_SegmentTreeAddQuerySum::lazy((jshl(i, 1) | 1), add[i], rn);
      (add[i] = 0);
    }
  }
  static void lazy(int i, i64 v, int n) {
    (sum[i] += (v * n));
    (add[i] += v);
  }
  static void build(int l, int r, int i) {
    if ((l == r)) {
      (sum[i] = arr[l]);
    } else {
      int mid = jshr((l + r), 1);
      Code01_SegmentTreeAddQuerySum::build(l, mid, jshl(i, 1));
      Code01_SegmentTreeAddQuerySum::build((mid + 1), r, (jshl(i, 1) | 1));
      Code01_SegmentTreeAddQuerySum::up(i);
    }
    (add[i] = 0);
  }
  static void add_method(int jobl, int jobr, i64 jobv, int l, int r, int i) {
    if (((jobl <= l) && (r <= jobr))) {
      Code01_SegmentTreeAddQuerySum::lazy(i, jobv, ((r - l) + 1));
    } else {
      int mid = jshr((l + r), 1);
      Code01_SegmentTreeAddQuerySum::down(i, ((mid - l) + 1), (r - mid));
      if ((jobl <= mid)) {
        Code01_SegmentTreeAddQuerySum::add_method(jobl, jobr, jobv, l, mid,
                                                  jshl(i, 1));
      }
      if ((jobr > mid)) {
        Code01_SegmentTreeAddQuerySum::add_method(jobl, jobr, jobv, (mid + 1),
                                                  r, (jshl(i, 1) | 1));
      }
      Code01_SegmentTreeAddQuerySum::up(i);
    }
  }
  static i64 query(int jobl, int jobr, int l, int r, int i) {
    if (((jobl <= l) && (r <= jobr))) {
      return sum[i];
    }
    int mid = jshr((l + r), 1);
    Code01_SegmentTreeAddQuerySum::down(i, ((mid - l) + 1), (r - mid));
    i64 ans = 0;
    if ((jobl <= mid)) {
      (ans +=
       Code01_SegmentTreeAddQuerySum::query(jobl, jobr, l, mid, jshl(i, 1)));
    }
    if ((jobr > mid)) {
      (ans += Code01_SegmentTreeAddQuerySum::query(jobl, jobr, (mid + 1), r,
                                                   (jshl(i, 1) | 1)));
    }
    return ans;
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    int n = static_cast<int>(in.nval);
    in.nextToken();
    int m = static_cast<int>(in.nval);
    for (int i = 1; (i <= n); (i++)) {
      in.nextToken();
      (arr[i] = static_cast<i64>(in.nval));
    }
    Code01_SegmentTreeAddQuerySum::build(1, n, 1);
    i64 jobv = {};
    {
      int i = 1;
      int op = {};
      int jobl = {};
      int jobr = {};
      for (; (i <= m); (i++)) {
        in.nextToken();
        (op = static_cast<int>(in.nval));
        if ((op == 1)) {
          in.nextToken();
          (jobl = static_cast<int>(in.nval));
          in.nextToken();
          (jobr = static_cast<int>(in.nval));
          in.nextToken();
          (jobv = static_cast<i64>(in.nval));
          Code01_SegmentTreeAddQuerySum::add_method(jobl, jobr, jobv, 1, n, 1);
        } else {
          in.nextToken();
          (jobl = static_cast<int>(in.nval));
          in.nextToken();
          (jobr = static_cast<int>(in.nval));
          out.println(
              Code01_SegmentTreeAddQuerySum::query(jobl, jobr, 1, n, 1));
        }
      }
    }
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code01_SegmentTreeAddQuerySum::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 线段树支持范围增加、范围查询
// 维护累加和
// 测试链接 : https://www.luogu.com.cn/problem/P3372
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下的code，提交时请把类名改成"Main"，可以直接通过
        // 累加和信息的汇总
                // 父范围的累加和 = 左范围累加和 + 右范围累加和
        // 懒信息的下发
                        // 发左
                        // 发右
                        // 父范围懒信息清空
        // 当前来到l~r范围，对应的信息下标是i，范围上数字的个数是n = r-l+1
        // 现在收到一个懒更新任务 : l~r范围上每个数字增加v
        // 这个懒更新任务有可能是任务范围把当前线段树范围全覆盖导致的
        // 也有可能是父范围的懒信息下发下来的
        // 总之把线段树当前范围的sum数组和add数组调整好
        // 就不再继续往下下发了，懒住了
        // 建树
        // 范围修改
        // jobl ~ jobr范围上每个数字增加jobv
        // 查询累加和
*/

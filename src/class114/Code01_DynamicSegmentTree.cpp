// Source: src/class114/Code01_DynamicSegmentTree.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_DynamicSegmentTree {
  inline static int LIMIT = 80001;
  inline static int cnt = {};
  inline static Array<int> left = make_array<int>(LIMIT);
  inline static Array<int> right = make_array<int>(LIMIT);
  inline static Array<i64> sum = make_array<i64>(LIMIT);
  inline static Array<i64> add = make_array<i64>(LIMIT);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_DynamicSegmentTree() {}
  static void up(int h, int l, int r) { (sum[h] = (sum[l] + sum[r])); }
  static void down(int i, int ln, int rn) {
    if ((add[i] != 0)) {
      if ((left[i] == 0)) {
        (left[i] = (++cnt));
      }
      if ((right[i] == 0)) {
        (right[i] = (++cnt));
      }
      Code01_DynamicSegmentTree::lazy(left[i], add[i], ln);
      Code01_DynamicSegmentTree::lazy(right[i], add[i], rn);
      (add[i] = 0);
    }
  }
  static void lazy(int i, i64 v, int n) {
    (sum[i] += (v * n));
    (add[i] += v);
  }
  static void add_method(int jobl, int jobr, i64 jobv, int l, int r, int i) {
    if (((jobl <= l) && (r <= jobr))) {
      Code01_DynamicSegmentTree::lazy(i, jobv, ((r - l) + 1));
    } else {
      int mid = jshr((l + r), 1);
      Code01_DynamicSegmentTree::down(i, ((mid - l) + 1), (r - mid));
      if ((jobl <= mid)) {
        if ((left[i] == 0)) {
          (left[i] = (++cnt));
        }
        Code01_DynamicSegmentTree::add_method(jobl, jobr, jobv, l, mid,
                                              left[i]);
      }
      if ((jobr > mid)) {
        if ((right[i] == 0)) {
          (right[i] = (++cnt));
        }
        Code01_DynamicSegmentTree::add_method(jobl, jobr, jobv, (mid + 1), r,
                                              right[i]);
      }
      Code01_DynamicSegmentTree::up(i, left[i], right[i]);
    }
  }
  static i64 query(int jobl, int jobr, int l, int r, int i) {
    if (((jobl <= l) && (r <= jobr))) {
      return sum[i];
    }
    int mid = jshr((l + r), 1);
    Code01_DynamicSegmentTree::down(i, ((mid - l) + 1), (r - mid));
    i64 ans = 0;
    if ((jobl <= mid)) {
      if ((left[i] != 0)) {
        (ans += Code01_DynamicSegmentTree::query(jobl, jobr, l, mid, left[i]));
      }
    }
    if ((jobr > mid)) {
      if ((right[i] != 0)) {
        (ans +=
         Code01_DynamicSegmentTree::query(jobl, jobr, (mid + 1), r, right[i]));
      }
    }
    return ans;
  }
  static void clear() {
    j::fill(left, 1, (cnt + 1), 0);
    j::fill(right, 1, (cnt + 1), 0);
    j::fill(sum, 1, (cnt + 1), 0);
    j::fill(add, 1, (cnt + 1), 0);
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    int n = static_cast<int>(in.nval);
    in.nextToken();
    int m = static_cast<int>(in.nval);
    (cnt = 1);
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
          Code01_DynamicSegmentTree::add_method(jobl, jobr, jobv, 1, n, 1);
        } else {
          in.nextToken();
          (jobl = static_cast<int>(in.nval));
          in.nextToken();
          (jobr = static_cast<int>(in.nval));
          out.println(Code01_DynamicSegmentTree::query(jobl, jobr, 1, n, 1));
        }
      }
    }
    Code01_DynamicSegmentTree::clear();
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code01_DynamicSegmentTree::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 动态开点线段树
// 一共有n个位置，编号从1~n，一开始所有位置的值为0
// 实现如下两个操作，一共会调用m次
// 操作 1 l r v : 把l~r范围的每个数增加v
// 操作 2 l r   : 返回l~r范围的累加和
// 1 <= n <= 10^9
// 1 <= m <= 10^3
// 测试链接 : https://www.luogu.com.cn/problem/P2781
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下的code，提交时请把类名改成"Main"，可以直接通过
        // 范围1 ~ 10^9，线段树高度差不多30
        // 查询次数1000，每次查询都有左右两条边线
        // 所以空间占用差不多1000 * 30 * 2 = 60000
        // 适当调大即可
                        // 懒更新任务下发
                        // 那左右两侧的空间需要准备好
                                // 不得不去左侧才会申请
                                // 不得不去右侧才会申请
                        // 发现左侧申请过空间才有必要去查询
                        // 如果左侧从来没有申请过空间那查询结果就是0
                        // 发现右侧申请过空间才有必要去查询
                        // 如果右侧从来没有申请过空间那查询结果就是0
        // 如果一次会执行多组测试数组
        // 那么每组测试完成后要clear空间
                // 本题每组测试数据都单独运行
                // 可以不写clear方法
                // 但是如果多组测试数据串行调用
                // 就需要加上清空逻辑
*/

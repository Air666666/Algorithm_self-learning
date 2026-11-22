// 原题测试 / 参考链接（保留上游原始地址）
// https://acm.hdu.edu.cn/showproblem.php?pid=4614

// Source: src/class111/Code02_VasesAndFlowers.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_VasesAndFlowers {
  inline static int MAXN = 50001;
  inline static Array<int> sum = make_array<int>(jshl(MAXN, 2));
  inline static Array<int> change = make_array<int>(jshl(MAXN, 2));
  inline static Array<bool> update = make_array<bool>(jshl(MAXN, 2));
  inline static int n = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_VasesAndFlowers() {}
  static void up(int i) {
    (sum[i] = (sum[jshl(i, 1)] + sum[(jshl(i, 1) | 1)]));
  }
  static void down(int i, int ln, int rn) {
    if (update[i]) {
      Code02_VasesAndFlowers::lazy(jshl(i, 1), change[i], ln);
      Code02_VasesAndFlowers::lazy((jshl(i, 1) | 1), change[i], rn);
      (update[i] = false);
    }
  }
  static void lazy(int i, int v, int n) {
    (sum[i] = (v * n));
    (change[i] = v);
    (update[i] = true);
  }
  static void build(int l, int r, int i) {
    if ((l < r)) {
      int mid = jshr((l + r), 1);
      Code02_VasesAndFlowers::build(l, mid, jshl(i, 1));
      Code02_VasesAndFlowers::build((mid + 1), r, (jshl(i, 1) | 1));
    }
    (sum[i] = 0);
    (update[i] = false);
  }
  static void update_method(int jobl, int jobr, int jobv, int l, int r, int i) {
    if (((jobl <= l) && (r <= jobr))) {
      Code02_VasesAndFlowers::lazy(i, jobv, ((r - l) + 1));
    } else {
      int mid = jshr((l + r), 1);
      Code02_VasesAndFlowers::down(i, ((mid - l) + 1), (r - mid));
      if ((jobl <= mid)) {
        Code02_VasesAndFlowers::update_method(jobl, jobr, jobv, l, mid,
                                              jshl(i, 1));
      }
      if ((jobr > mid)) {
        Code02_VasesAndFlowers::update_method(jobl, jobr, jobv, (mid + 1), r,
                                              (jshl(i, 1) | 1));
      }
      Code02_VasesAndFlowers::up(i);
    }
  }
  static int query(int jobl, int jobr, int l, int r, int i) {
    if (((jobl <= l) && (r <= jobr))) {
      return sum[i];
    }
    int mid = jshr((l + r), 1);
    Code02_VasesAndFlowers::down(i, ((mid - l) + 1), (r - mid));
    int ans = 0;
    if ((jobl <= mid)) {
      (ans += Code02_VasesAndFlowers::query(jobl, jobr, l, mid, jshl(i, 1)));
    }
    if ((jobr > mid)) {
      (ans += Code02_VasesAndFlowers::query(jobl, jobr, (mid + 1), r,
                                            (jshl(i, 1) | 1)));
    }
    return ans;
  }
  static Array<int> insert(int from, int flowers) {
    (from++);
    int start = {};
    int end = {};
    int zeros =
        (((n - from) + 1) - Code02_VasesAndFlowers::query(from, n, 1, n, 1));
    if ((zeros == 0)) {
      (start = 0);
      (end = 0);
    } else {
      (start = Code02_VasesAndFlowers::findZero(from, 1));
      (end = Code02_VasesAndFlowers::findZero(from, jmin(zeros, flowers)));
      Code02_VasesAndFlowers::update_method(start, end, 1, 1, n, 1);
    }
    (start--);
    (end--);
    return Array<int>{start, end};
  }
  static int findZero(int s, int k) {
    int l = s;
    int r = n;
    int mid = {};
    int ans = 0;
    while ((l <= r)) {
      (mid = jshr((l + r), 1));
      if (((((mid - s) + 1) - Code02_VasesAndFlowers::query(s, mid, 1, n, 1)) >=
           k)) {
        (ans = mid);
        (r = (mid - 1));
      } else {
        (l = (mid + 1));
      }
    }
    return ans;
  }
  static int clear(int left, int right) {
    (left++);
    (right++);
    int ans = Code02_VasesAndFlowers::query(left, right, 1, n, 1);
    Code02_VasesAndFlowers::update_method(left, right, 0, 1, n, 1);
    return ans;
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    int t = static_cast<int>(in.nval);
    for (int i = 1; (i <= t); (i++)) {
      in.nextToken();
      (n = static_cast<int>(in.nval));
      in.nextToken();
      int m = static_cast<int>(in.nval);
      Code02_VasesAndFlowers::build(1, n, 1);
      for (int j = 1; (j <= m); (j++)) {
        in.nextToken();
        int op = static_cast<int>(in.nval);
        if ((op == 1)) {
          in.nextToken();
          int from = static_cast<int>(in.nval);
          in.nextToken();
          int flowers = static_cast<int>(in.nval);
          Array<int> ans = Code02_VasesAndFlowers::insert(from, flowers);
          if ((ans[0] == (-1))) {
            out.println(String(u"Can not_java put any one."));
          } else {
            out.println(((ans[0] + String(u" ")) + ans[1]));
          }
        } else {
          in.nextToken();
          int left = static_cast<int>(in.nval);
          in.nextToken();
          int right = static_cast<int>(in.nval);
          out.println(Code02_VasesAndFlowers::clear(left, right));
        }
      }
      out.println();
    }
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code02_VasesAndFlowers::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 瓶子里的花朵
// 给定n个瓶子，编号从0~n-1，一开始所有瓶子都是空的
// 每个瓶子最多插入一朵花，实现以下两种类型的操作
// 操作 1 from flower :
一共有flower朵花，从from位置开始依次插入花朵，已经有花的瓶子跳过
//                     如果一直到最后的瓶子，花也没有用完，就丢弃剩下的花朵
//                     返回这次操作插入的首个空瓶的位置 和 最后空瓶的位置
//                     如果从from开始所有瓶子都有花，打印"Can not put any one."
// 操作 2 left right  :
从left位置开始到right位置的瓶子，变回空瓶，返回清理花朵的数量
// 测试链接 : https://acm.hdu.edu.cn/showproblem.php?pid=4614
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下的code，提交时请把类名改成"Main"，可以直接通过
                // 题目给的位置从0开始
                // 线段树下标从1开始
                // 题目需要从0开始的下标
        // s~n范围上
        // 返回第k个0的位置
        // 注意题目给的下标从0开始
        // 线段树下标从1开始
*/

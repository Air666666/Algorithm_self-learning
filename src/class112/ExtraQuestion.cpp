// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P1558

// Source: src/class112/ExtraQuestion.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct ExtraQuestion {
  inline static int MAXN = 100001;
  inline static Array<int> color = make_array<int>(jshl(MAXN, 2));
  inline static Array<int> change = make_array<int>(jshl(MAXN, 2));
  inline static Array<bool> update = make_array<bool>(jshl(MAXN, 2));
  String toString() const { return j::str(static_cast<const void *>(this)); }
  ExtraQuestion() {}
  static void up(int i) {
    (color[i] = (color[jshl(i, 1)] | color[(jshl(i, 1) | 1)]));
  }
  static void down(int i) {
    if (update[i]) {
      ExtraQuestion::lazy(jshl(i, 1), change[i]);
      ExtraQuestion::lazy((jshl(i, 1) | 1), change[i]);
      (update[i] = false);
    }
  }
  static void lazy(int i, int v) {
    (color[i] = jshl(1, v));
    (change[i] = v);
    (update[i] = true);
  }
  static void build(int l, int r, int i) {
    if ((l < r)) {
      int mid = jshr((l + r), 1);
      ExtraQuestion::build(l, mid, jshl(i, 1));
      ExtraQuestion::build((mid + 1), r, (jshl(i, 1) | 1));
    }
    (color[i] = 2);
    (change[i] = 0);
    (update[i] = false);
  }
  static void update_method(int jobl, int jobr, int jobv, int l, int r, int i) {
    if (((jobl <= l) && (r <= jobr))) {
      ExtraQuestion::lazy(i, jobv);
    } else {
      ExtraQuestion::down(i);
      int mid = jshr((l + r), 1);
      if ((jobl <= mid)) {
        ExtraQuestion::update_method(jobl, jobr, jobv, l, mid, jshl(i, 1));
      }
      if ((jobr > mid)) {
        ExtraQuestion::update_method(jobl, jobr, jobv, (mid + 1), r,
                                     (jshl(i, 1) | 1));
      }
      ExtraQuestion::up(i);
    }
  }
  static int query(int l, int r, int n) {
    int status = ExtraQuestion::query(l, r, 1, n, 1);
    return ExtraQuestion::cntOnes(status);
  }
  static int query(int jobl, int jobr, int l, int r, int i) {
    if (((jobl <= l) && (r <= jobr))) {
      return color[i];
    }
    ExtraQuestion::down(i);
    int mid = jshr((l + r), 1);
    int status = 0;
    if ((jobl <= mid)) {
      (status |= ExtraQuestion::query(jobl, jobr, l, mid, jshl(i, 1)));
    }
    if ((jobr > mid)) {
      (status |=
       ExtraQuestion::query(jobl, jobr, (mid + 1), r, (jshl(i, 1) | 1)));
    }
    return status;
  }
  static int cntOnes(int n) {
    (n = ((n & 0x55555555) + (jushr(n, 1) & 0x55555555)));
    (n = ((n & 0x33333333) + (jushr(n, 2) & 0x33333333)));
    (n = ((n & 0x0f0f0f0f) + (jushr(n, 4) & 0x0f0f0f0f)));
    (n = ((n & 0x00ff00ff) + (jushr(n, 8) & 0x00ff00ff)));
    (n = ((n & 0x0000ffff) + (jushr(n, 16) & 0x0000ffff)));
    return n;
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    int n = static_cast<int>(in.nval);
    in.nextToken();
    in.nextToken();
    int m = static_cast<int>(in.nval);
    ExtraQuestion::build(1, n, 1);
    String op = {};
    {
      int i = 1;
      int a = {};
      int b = {};
      int c = {};
      int tmp = {};
      for (; (i <= m); (i++)) {
        in.nextToken();
        (op = in.sval);
        in.nextToken();
        (a = static_cast<int>(in.nval));
        in.nextToken();
        (b = static_cast<int>(in.nval));
        if ((a > b)) {
          (tmp = a);
          (a = b);
          (b = tmp);
        }
        if (op.equals(String(u"C"))) {
          in.nextToken();
          (c = static_cast<int>(in.nval));
          ExtraQuestion::update_method(a, b, c, 1, n, 1);
        } else {
          out.println(ExtraQuestion::query(a, b, n));
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
  ExtraQuestion::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 赠送一道课上没有讲的附加练习题
// 色板游戏
// 一共有L个色板，编号1~L，一开始所有色板都是1号颜色
// 一共有T种颜色，编号1~T，可以往色板上涂色
// 一共有O次操作，操作类型有如下两种
// 操作 C A B C : A~B范围的色板都涂上C颜色
// 操作 P A B   : 查询A~B范围的色板一共有几种颜色
// L <= 10^5, T <= 30, O <= 10^5
// 测试链接 : https://www.luogu.com.cn/problem/P1558
// 解法 :
// 数据很特殊，颜色种类不超过30
// 可以用位信息来表示线段树范围上的颜色状况
// 那么，父范围的颜色状况 = 左范围的颜色状况 | 右范围的颜色状况
// 除此之外没啥难点了，提交时把类名改成"Main"，可以直接通过
        // 线段树范围上的颜色状况
        // 懒更新信息，范围上重置成了什么颜色
        // 懒更新信息，范围上是否有重置任务
        // 整个范围的色板重置成v颜色的懒更新处理
                // 一开始所有色板都是1号颜色
                // 所以状态为0...0010 = 2
        // 范围重置颜色
        // 返回l..r范围上的颜色种类
        // 返回l..r范围上的颜色状况
        // 返回n的二进制中有几个1
        // 该实现讲解031的题目6讲过了
        // 你也可以用更简单的写法
                        // 注意题目可能有a>b的情况需要交换
*/

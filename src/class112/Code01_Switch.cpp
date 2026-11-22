// Source: src/class112/Code01_Switch.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_Switch {
  inline static int MAXN = 100001;
  inline static Array<int> light = make_array<int>(jshl(MAXN, 2));
  inline static Array<bool> reverse = make_array<bool>(jshl(MAXN, 2));
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_Switch() {}
  static void up(int i) {
    (light[i] = (light[jshl(i, 1)] + light[(jshl(i, 1) | 1)]));
  }
  static void down(int i, int ln, int rn) {
    if (reverse[i]) {
      Code01_Switch::lazy(jshl(i, 1), ln);
      Code01_Switch::lazy((jshl(i, 1) | 1), rn);
      (reverse[i] = false);
    }
  }
  static void lazy(int i, int n) {
    (light[i] = (n - light[i]));
    (reverse[i] = (!reverse[i]));
  }
  static void build(int l, int r, int i) {
    if ((l == r)) {
      (light[i] = 0);
    } else {
      int mid = jshr((l + r), 1);
      Code01_Switch::build(l, mid, jshl(i, 1));
      Code01_Switch::build((mid + 1), r, (jshl(i, 1) | 1));
      Code01_Switch::up(i);
    }
    (reverse[i] = false);
  }
  static void reverse_method(int jobl, int jobr, int l, int r, int i) {
    if (((jobl <= l) && (r <= jobr))) {
      Code01_Switch::lazy(i, ((r - l) + 1));
    } else {
      int mid = jshr((l + r), 1);
      Code01_Switch::down(i, ((mid - l) + 1), (r - mid));
      if ((jobl <= mid)) {
        Code01_Switch::reverse_method(jobl, jobr, l, mid, jshl(i, 1));
      }
      if ((jobr > mid)) {
        Code01_Switch::reverse_method(jobl, jobr, (mid + 1), r,
                                      (jshl(i, 1) | 1));
      }
      Code01_Switch::up(i);
    }
  }
  static int query(int jobl, int jobr, int l, int r, int i) {
    if (((jobl <= l) && (r <= jobr))) {
      return light[i];
    }
    int mid = jshr((l + r), 1);
    Code01_Switch::down(i, ((mid - l) + 1), (r - mid));
    int ans = 0;
    if ((jobl <= mid)) {
      (ans += Code01_Switch::query(jobl, jobr, l, mid, jshl(i, 1)));
    }
    if ((jobr > mid)) {
      (ans += Code01_Switch::query(jobl, jobr, (mid + 1), r, (jshl(i, 1) | 1)));
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
    Code01_Switch::build(1, n, 1);
    {
      int i = 1;
      int op = {};
      int jobl = {};
      int jobr = {};
      for (; (i <= m); (i++)) {
        in.nextToken();
        (op = static_cast<int>(in.nval));
        in.nextToken();
        (jobl = static_cast<int>(in.nval));
        in.nextToken();
        (jobr = static_cast<int>(in.nval));
        if ((op == 0)) {
          Code01_Switch::reverse_method(jobl, jobr, 1, n, 1);
        } else {
          out.println(Code01_Switch::query(jobl, jobr, 1, n, 1));
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
  Code01_Switch::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 开关
// 现有n盏灯排成一排，从左到右依次编号为1~n，一开始所有的灯都是关着的
// 操作分两种
// 操作 0 l r : 改变l~r范围上所有灯的状态，开着的灯关上、关着的灯打开
// 操作 1 l r : 查询l~r范围上有多少灯是打开的
// 测试链接 : https://www.luogu.com.cn/problem/P3870
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下的code，提交时请把类名改成"Main"，可以直接通过
*/

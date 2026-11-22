// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P13085

// Source: src/class085/FollowUpWindy.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct FollowUpWindy {
  inline static int MAXLEN = 21;
  inline static Array<Array<Array<i64>>> dp = make_array<i64>(MAXLEN, 11, 2);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  FollowUpWindy() {}
  static void build(int len) {
    for (int i = 0; (i <= len); (i++)) {
      for (int j = 0; (j <= 10); (j++)) {
        (dp[i][j][0] = (-1));
        (dp[i][j][1] = (-1));
      }
    }
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    while ((in.nextToken() != -1)) {
      i64 a = static_cast<i64>(in.nval);
      in.nextToken();
      i64 b = static_cast<i64>(in.nval);
      out.println(FollowUpWindy::compute(a, b));
    }
    out.flush();
    out.close();
    br.close();
  }
  static i64 compute(i64 a, i64 b) {
    return [&]() {
      auto jleft = FollowUpWindy::cnt(b);
      auto jright = FollowUpWindy::cnt((a - 1));
      return (jleft - jright);
    }();
  }
  static i64 cnt(i64 num) {
    if ((num == 0)) {
      return 1;
    }
    int len = 1;
    i64 offset = 1;
    i64 tmp = jdiv(num, 10);
    while ((tmp > 0)) {
      (len++);
      (offset *= 10);
      (tmp /= 10);
    }
    FollowUpWindy::build(len);
    return FollowUpWindy::f(num, offset, len, 10, 0);
  }
  static i64 f(i64 num, i64 offset, int len, int pre, int free) {
    if ((len == 0)) {
      return 1;
    }
    if ((dp[len][pre][free] != (-1))) {
      return dp[len][pre][free];
    }
    int cur = static_cast<int>(jrem(jdiv(num, offset), 10));
    i64 ans = 0;
    if ((free == 0)) {
      if ((pre == 10)) {
        (ans += FollowUpWindy::f(num, jdiv(offset, 10), (len - 1), 10, 1));
        for (int i = 1; (i < cur); (i++)) {
          (ans += FollowUpWindy::f(num, jdiv(offset, 10), (len - 1), i, 1));
        }
        (ans += FollowUpWindy::f(num, jdiv(offset, 10), (len - 1), cur, 0));
      } else {
        for (int i = 0; (i <= 9); (i++)) {
          if (((i <= (pre - 2)) || (i >= (pre + 2)))) {
            if ((i < cur)) {
              (ans += FollowUpWindy::f(num, jdiv(offset, 10), (len - 1), i, 1));
            } else if ((i == cur)) {
              (ans +=
               FollowUpWindy::f(num, jdiv(offset, 10), (len - 1), cur, 0));
            }
          }
        }
      }
    } else {
      if ((pre == 10)) {
        (ans += FollowUpWindy::f(num, jdiv(offset, 10), (len - 1), 10, 1));
        for (int i = 1; (i <= 9); (i++)) {
          (ans += FollowUpWindy::f(num, jdiv(offset, 10), (len - 1), i, 1));
        }
      } else {
        for (int i = 0; (i <= 9); (i++)) {
          if (((i <= (pre - 2)) || (i >= (pre + 2)))) {
            (ans += FollowUpWindy::f(num, jdiv(offset, 10), (len - 1), i, 1));
          }
        }
      }
    }
    (dp[len][pre][free] = ans);
    return ans;
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  FollowUpWindy::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// windy数，加强版
// 课上没有讲这个文件，这是windy数的加强版测试
// 需要改成long类型，除此之外和课上讲的完全一样
// 测试链接 : https://www.luogu.com.cn/problem/P13085
// 提交以下的code，提交时请把类名改成"Main"，可以直接通过
*/

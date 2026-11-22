// 原题测试 / 参考链接（保留上游原始地址）
// https://acm.hdu.edu.cn/showproblem.php?pid=3038
// https://vjudge.net/problem/HDU-3038

// Source: src/class156/Code03_WrongAnswers.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_WrongAnswers {
  inline static int MAXN = 200002;
  inline static int n = {};
  inline static int m = {};
  inline static int ans = {};
  inline static Array<int> father = make_array<int>(MAXN);
  inline static Array<int> dist = make_array<int>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_WrongAnswers() {}
  static void prepare() {
    (ans = 0);
    for (int i = 0; (i <= n); (i++)) {
      (father[i] = i);
      (dist[i] = 0);
    }
  }
  static int find(int i) {
    if ((i != father[i])) {
      int tmp = father[i];
      (father[i] = Code03_WrongAnswers::find(tmp));
      (dist[i] += dist[tmp]);
    }
    return father[i];
  }
  static void union_method(int l, int r, int v) {
    int lf = Code03_WrongAnswers::find(l);
    int rf = Code03_WrongAnswers::find(r);
    if ((lf != rf)) {
      (father[lf] = rf);
      (dist[lf] = ((v + dist[r]) - dist[l]));
    }
  }
  static bool check(int l, int r, int v) {
    if ([&]() {
          auto jleft = Code03_WrongAnswers::find(l);
          auto jright = Code03_WrongAnswers::find(r);
          return (jleft == jright);
        }()) {
      if (((dist[l] - dist[r]) != v)) {
        return false;
      }
    }
    return true;
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    while ((in.nextToken() != -1)) {
      (n = (static_cast<int>(in.nval) + 1));
      in.nextToken();
      (m = static_cast<int>(in.nval));
      Code03_WrongAnswers::prepare();
      {
        int i = 1;
        int l = {};
        int r = {};
        int v = {};
        for (; (i <= m); (i++)) {
          in.nextToken();
          (l = static_cast<int>(in.nval));
          in.nextToken();
          (r = (static_cast<int>(in.nval) + 1));
          in.nextToken();
          (v = static_cast<int>(in.nval));
          if ((!Code03_WrongAnswers::check(l, r, v))) {
            (ans++);
          } else {
            Code03_WrongAnswers::union_method(l, r, v);
          }
        }
      }
      out.println(ans);
    }
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code03_WrongAnswers::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 错误答案数量，带权并查集模版题3
// 有n个数字，下标1 ~ n，但是并不知道每个数字是多少
// 操作 l r v，代表l~r范围上累加和为v
//
一共m个操作，如果某个操作和之前的操作信息自相矛盾，认为当前操作是错误的，不进行这个操作
// 最后打印错误操作的数量
// 1 <= n <= 200000    1 <= m <= 40000
// 累加和不会超过int类型范围
// 测试链接 : https://acm.hdu.edu.cn/showproblem.php?pid=3038
// 测试链接 : https://vjudge.net/problem/HDU-3038
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
*/

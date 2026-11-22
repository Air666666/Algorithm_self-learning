// Source: src/class156/Code06_JudgeFoodChain.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code06_JudgeFoodChain {
  inline static int MAXN = 50001;
  inline static int n = {};
  inline static int k = {};
  inline static int ans = {};
  inline static Array<int> father = make_array<int>(MAXN);
  inline static Array<int> dist = make_array<int>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code06_JudgeFoodChain() {}
  static void prepare() {
    (ans = 0);
    for (int i = 1; (i <= n); (i++)) {
      (father[i] = i);
      (dist[i] = 0);
    }
  }
  static int find(int i) {
    if ((i != father[i])) {
      int tmp = father[i];
      (father[i] = Code06_JudgeFoodChain::find(tmp));
      (dist[i] = jrem((dist[i] + dist[tmp]), 3));
    }
    return father[i];
  }
  static void union_method(int op, int l, int r) {
    int lf = Code06_JudgeFoodChain::find(l);
    int rf = Code06_JudgeFoodChain::find(r);
    int v = ((op == 1) ? 0 : 1);
    if ((lf != rf)) {
      (father[lf] = rf);
      (dist[lf] = jrem((((dist[r] - dist[l]) + v) + 3), 3));
    }
  }
  static bool check(int op, int l, int r) {
    if ((((l > n) || (r > n)) || ((op == 2) && (l == r)))) {
      return false;
    }
    if ([&]() {
          auto jleft = Code06_JudgeFoodChain::find(l);
          auto jright = Code06_JudgeFoodChain::find(r);
          return (jleft == jright);
        }()) {
      if ((op == 1)) {
        if ((dist[l] != dist[r])) {
          return false;
        }
      } else {
        if ((jrem(((dist[l] - dist[r]) + 3), 3) != 1)) {
          return false;
        }
      }
    }
    return true;
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    (n = static_cast<int>(in.nval));
    in.nextToken();
    (k = static_cast<int>(in.nval));
    Code06_JudgeFoodChain::prepare();
    {
      int i = 1;
      int op = {};
      int l = {};
      int r = {};
      for (; (i <= k); (i++)) {
        in.nextToken();
        (op = static_cast<int>(in.nval));
        in.nextToken();
        (l = static_cast<int>(in.nval));
        in.nextToken();
        (r = static_cast<int>(in.nval));
        if ((!Code06_JudgeFoodChain::check(op, l, r))) {
          (ans++);
        } else {
          Code06_JudgeFoodChain::union_method(op, l, r);
        }
      }
    }
    out.println(ans);
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code06_JudgeFoodChain::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 甄别食物链
// 一共有n只动物，编号1 ~ n，每只动物都是A、B、C中的一种，A吃B、B吃C、C吃A
// 一共有k句话，希望你判断哪些话是假话，每句话是如下两类句子中的一类
// 1 X Y : 第X只动物和第Y只动物是同类
// 2 X Y : 第X只动物吃第Y只动物
// 当前的话与前面的某些真话冲突，视为假话
// 当前的话提到的X和Y，有任何一个大于n，视为假话
// 当前的话如果关于吃，又有X==Y，视为假话
// 返回k句话中，假话的数量
// 1 <= n <= 5 * 10^4    1 <= k <= 10^5
// 测试链接 : https://www.luogu.com.cn/problem/P2024
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // dist[i] = 0，代表i和头是同类
        // dist[i] = 1，代表i吃头
        // dist[i] = 2，代表i被头吃
        // op == 1, 1 l r，l和r是同类
        // op == 2, 2 l r，l吃r
*/

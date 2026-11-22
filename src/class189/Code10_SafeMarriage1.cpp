// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P1407

// Source: src/class189/Code10_SafeMarriage1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code10_SafeMarriage1 {
  inline static int MAXN = 10001;
  inline static int MAXM = 30001;
  inline static int n = {};
  inline static int m = {};
  inline static Array<int> a = make_array<int>(MAXN);
  inline static Array<int> b = make_array<int>(MAXN);
  inline static int cntn = {};
  inline static JMap<String, int> nameId = JMap<String, int>();
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> nxt = make_array<int>(MAXM);
  inline static Array<int> to = make_array<int>(MAXM);
  inline static int cntg = {};
  inline static Array<int> dfn = make_array<int>(MAXN);
  inline static Array<int> low = make_array<int>(MAXN);
  inline static int cntd = {};
  inline static Array<int> sta = make_array<int>(MAXN);
  inline static int top = {};
  inline static Array<int> belong = make_array<int>(MAXN);
  inline static int sccCnt = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code10_SafeMarriage1() {}
  static void addEdge(int u, int v) {
    (nxt[(++cntg)] = head[u]);
    (to[cntg] = v);
    (head[u] = cntg);
  }
  static void tarjan(int u) {
    (dfn[u] = (low[u] = (++cntd)));
    (sta[(++top)] = u);
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      int v = to[e];
      if ((dfn[v] == 0)) {
        Code10_SafeMarriage1::tarjan(v);
        (low[u] = jmin(low[u], low[v]));
      } else {
        if ((belong[v] == 0)) {
          (low[u] = jmin(low[u], dfn[v]));
        }
      }
    }
    if ((dfn[u] == low[u])) {
      (sccCnt++);
      int pop = {};
      do {
        (pop = sta[(top--)]);
        (belong[pop] = sccCnt);
      } while ((pop != u));
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    String girl = {};
    String boy = {};
    for (int i = 1; (i <= n); (i++)) {
      (girl = in.nextString());
      (boy = in.nextString());
      (a[i] = (++cntn));
      (b[i] = (++cntn));
      nameId.put(girl, a[i]);
      nameId.put(boy, b[i]);
      Code10_SafeMarriage1::addEdge(a[i], b[i]);
    }
    (m = in.nextInt());
    for (int i = 1; (i <= m); (i++)) {
      (girl = in.nextString());
      (boy = in.nextString());
      [&]() {
        auto jargument_0 = nameId.get(boy);
        auto jargument_1 = nameId.get(girl);
        return Code10_SafeMarriage1::addEdge(jargument_0, jargument_1);
      }();
    }
    for (int i = 1; (i <= cntn); (i++)) {
      if ((dfn[i] == 0)) {
        Code10_SafeMarriage1::tarjan(i);
      }
    }
    for (int i = 1; (i <= n); (i++)) {
      if ((belong[a[i]] == belong[b[i]])) {
        out.println(String(u"Unsafe"));
      } else {
        out.println(String(u"Safe"));
      }
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code10_SafeMarriage1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 稳定婚姻，java版
// 一共有n对婚姻关系，每对婚姻关系给定(女方名, 男方名)，一共2n个名字
// 一共有m对暧昧关系，每对暧昧关系给定(女方名, 男方名)，不会出现新名字
// 如果一对婚姻关系破裂，那么女方或者男方，可能会找暧昧关系的对象私奔
// 私奔会制造更多的婚姻破裂，并且产生进一步的私奔，事情好像多米诺骨牌一样展开
//
如果所有涉事男女都能重新搭配，只要存在这种可能性，那么这对婚姻关系就是不稳定的
// 比如A为女，B为男，婚姻关系(A1, B1)、(A2, B2)，同时暧昧关系(A1, B2)、(A2, B1)
//
A1和B1婚姻破裂，导致B1和A2私奔了，导致A2和B2婚姻破裂，导致B2和A1私奔了，这就是重新搭配
// 检查每对婚姻关系，如果不稳定打印"Unsafe"，如果稳定打印"Safe"
// 1 <= n <= 4000    0 <= m <= 20000
// 测试链接 : https://www.luogu.com.cn/problem/P1407
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 读写工具类
*/

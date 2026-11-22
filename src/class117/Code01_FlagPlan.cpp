// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P4155

// Source: src/class117/Code01_FlagPlan.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_FlagPlan {
  inline static int MAXN = 200001;
  inline static int LIMIT = 18;
  inline static int power = {};
  inline static Array<Array<int>> line = make_array<int>(jshl(MAXN, 1), 3);
  inline static Array<Array<int>> stjump =
      make_array<int>(jshl(MAXN, 1), LIMIT);
  inline static Array<int> ans = make_array<int>(MAXN);
  inline static int n = {};
  inline static int m = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_FlagPlan() {}
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    (n = static_cast<int>(in.nval));
    in.nextToken();
    (m = static_cast<int>(in.nval));
    for (int i = 1; (i <= n); (i++)) {
      (line[i][0] = i);
      in.nextToken();
      (line[i][1] = static_cast<int>(in.nval));
      in.nextToken();
      (line[i][2] = static_cast<int>(in.nval));
    }
    Code01_FlagPlan::compute();
    out.print(ans[1]);
    for (int i = 2; (i <= n); (i++)) {
      out.print((String(u" ") + ans[i]));
    }
    out.println();
    out.flush();
    out.close();
    br.close();
  }
  static void compute() {
    (power = Code01_FlagPlan::log2(n));
    Code01_FlagPlan::build();
    for (int i = 1; (i <= n); (i++)) {
      (ans[line[i][0]] = Code01_FlagPlan::jump(i));
    }
  }
  static int log2(int n) {
    int ans = 0;
    while ((jshl(1, ans) <= jshr(n, 1))) {
      (ans++);
    }
    return ans;
  }
  static void build() {
    for (int i = 1; (i <= n); (i++)) {
      if ((line[i][1] > line[i][2])) {
        (line[i][2] += m);
      }
    }
    j::sort(line, 1, (n + 1),
            [=](Array<int> a, Array<int> b) { return (a[1] - b[1]); });
    for (int i = 1; (i <= n); (i++)) {
      (line[(i + n)][0] = line[i][0]);
      (line[(i + n)][1] = (line[i][1] + m));
      (line[(i + n)][2] = (line[i][2] + m));
    }
    int e = jshl(n, 1);
    {
      int i = 1;
      int arrive = 1;
      for (; (i <= e); (i++)) {
        while ((((arrive + 1) <= e) && (line[(arrive + 1)][1] <= line[i][2]))) {
          (arrive++);
        }
        (stjump[i][0] = arrive);
      }
    }
    for (int p = 1; (p <= power); (p++)) {
      for (int i = 1; (i <= e); (i++)) {
        (stjump[i][p] = stjump[stjump[i][(p - 1)]][(p - 1)]);
      }
    }
  }
  static int jump(int i) {
    int aim = (line[i][1] + m);
    int cur = i;
    int next = {};
    int ans = 0;
    for (int p = power; (p >= 0); (p--)) {
      (next = stjump[cur][p]);
      if (((next != 0) && (line[next][2] < aim))) {
        (ans += jshl(1, p));
        (cur = next);
      }
    }
    return ((ans + 1) + 1);
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code01_FlagPlan::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 国旗计划
// 给定点的数量m，点的编号1~m，所有点围成一个环
// i号点一定顺时针到达i+1号点，最终m号点顺指针回到1号点
// 给定n条线段，每条线段(a, b)，表示线段从点a顺时针到点b
// 输入数据保证所有线段可以把整个环覆盖
// 输入数据保证每条线段不会完全在另一条线段的内部
// 也就是线段之间可能有重合但一定互不包含
// 返回一个长度为n的结果数组ans，ans[x]表示一定选x号线段的情况下
// 至少选几条线段能覆盖整个环
// 测试链接 : https://www.luogu.com.cn/problem/P4155
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下的code，提交时请把类名改成"Main"，可以直接通过
        // 每条线段3个信息 : 线段编号、线段左边界、线段右边界
        // stjump[i][p] :
从i号线段出发，跳的次数是2的p次方，能到达的最右线段的编号
        // <=n最接近的2的幂，是2的几次方
*/

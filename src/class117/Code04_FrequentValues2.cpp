// Source: src/class117/Code04_FrequentValues2.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_FrequentValues2 {
  inline static int MAXN = 100001;
  inline static int LIMIT = 17;
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static Array<int> log2 = make_array<int>(MAXN);
  inline static Array<int> bucket = make_array<int>(MAXN);
  inline static Array<int> left = make_array<int>(MAXN);
  inline static Array<int> right = make_array<int>(MAXN);
  inline static Array<Array<int>> stmax = make_array<int>(MAXN, LIMIT);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_FrequentValues2() {}
  static void build(int n) {
    (arr[0] = (-23333333));
    int cnt = 0;
    for (int i = 1; (i <= n); (i++)) {
      if ((arr[(i - 1)] != arr[i])) {
        (right[cnt] = (i - 1));
        (left[(++cnt)] = i);
      }
      (bucket[i] = cnt);
    }
    (right[cnt] = n);
    (log2[0] = (-1));
    for (int i = 1; (i <= cnt); (i++)) {
      (log2[i] = (log2[jshr(i, 1)] + 1));
      (stmax[i][0] = ((right[i] - left[i]) + 1));
    }
    for (int p = 1; (p <= log2[cnt]); (p++)) {
      for (int i = 1; (((i + jshl(1, p)) - 1) <= cnt); (i++)) {
        (stmax[i][p] =
             jmax(stmax[i][(p - 1)], stmax[(i + jshl(1, (p - 1)))][(p - 1)]));
      }
    }
  }
  static int query(int l, int r) {
    if ((l > r)) {
      int tmp = l;
      (l = r);
      (r = tmp);
    }
    int lbucket = bucket[l];
    int rbucket = bucket[r];
    if ((lbucket == rbucket)) {
      return ((r - l) + 1);
    }
    int a = ((right[lbucket] - l) + 1);
    int b = ((r - left[rbucket]) + 1);
    int c = 0;
    if (((lbucket + 1) < rbucket)) {
      int from = (lbucket + 1);
      int to = (rbucket - 1);
      int p = log2[((to - from) + 1)];
      (c = jmax(stmax[from][p], stmax[((to - jshl(1, p)) + 1)][p]));
    }
    return jmax(jmax(a, b), c);
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    while ((in.nextToken() != -1)) {
      int n = static_cast<int>(in.nval);
      if ((n == 0)) {
        break;
      }
      in.nextToken();
      int m = static_cast<int>(in.nval);
      for (int i = 1; (i <= n); (i++)) {
        in.nextToken();
        (arr[i] = static_cast<int>(in.nval));
      }
      Code04_FrequentValues2::build(n);
      {
        int i = 1;
        int l = {};
        int r = {};
        for (; (i <= m); (i++)) {
          in.nextToken();
          (l = static_cast<int>(in.nval));
          in.nextToken();
          (r = static_cast<int>(in.nval));
          out.println(Code04_FrequentValues2::query(l, r));
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
  Code04_FrequentValues2::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 出现次数最多的数有几个
// 给定一个长度为n的数组arr，该数组一定是有序的
// 一共有m次查询，每次查询arr[l~r]上出现次数最多的数有几个
// 题目查看 : https://www.luogu.com.cn/problem/UVA11235
// 题目提交 : https://vjudge.net/problem/UVA-11235
// 洛谷上提交会发生远程连接错误，需要绑定一个UVA账号再提交
// 也可以注册一个vjudge账号来提交，不过如果UVA链接不上就需要等
// 其实用对数器验证即可，我肯定是提交通过测试了的
// 提交以下的code，提交时请把类名改成"Main"
                // 题目给定的数值范围-100000 ~ +100000
                // 把arr[0]设置成不会到达的数字即可
*/

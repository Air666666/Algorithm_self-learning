// Source: src/class156/Code02_CunningMerchant.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_CunningMerchant {
  inline static int MAXN = 102;
  inline static int t = {};
  inline static int n = {};
  inline static int m = {};
  inline static bool ans = {};
  inline static Array<int> father = make_array<int>(MAXN);
  inline static Array<int> dist = make_array<int>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_CunningMerchant() {}
  static void prepare() {
    (ans = true);
    for (int i = 1; (i <= n); (i++)) {
      (father[i] = i);
      (dist[i] = 0);
    }
  }
  static int find(int i) {
    if ((i != father[i])) {
      int tmp = father[i];
      (father[i] = Code02_CunningMerchant::find(tmp));
      (dist[i] += dist[tmp]);
    }
    return father[i];
  }
  static void union_method(int l, int r, int v) {
    int lf = Code02_CunningMerchant::find(l);
    int rf = Code02_CunningMerchant::find(r);
    if ((lf != rf)) {
      (father[lf] = rf);
      (dist[lf] = ((v + dist[r]) - dist[l]));
    }
  }
  static bool check(int l, int r, int v) {
    if ([&]() {
          auto jleft = Code02_CunningMerchant::find(l);
          auto jright = Code02_CunningMerchant::find(r);
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
    in.nextToken();
    (t = static_cast<int>(in.nval));
    for (int c = 1; (c <= t); (c++)) {
      in.nextToken();
      (n = (static_cast<int>(in.nval) + 1));
      in.nextToken();
      (m = static_cast<int>(in.nval));
      Code02_CunningMerchant::prepare();
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
          if ((!Code02_CunningMerchant::check(l, r, v))) {
            (ans = false);
          } else {
            Code02_CunningMerchant::union_method(l, r, v);
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
  Code02_CunningMerchant::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 狡猾的商人，带权并查集模版题2
// 有n个月的收入，下标1 ~ n，但是并不知道每个月收入是多少
// 操作 l r v，代表从第l个月到第r个月，总收入为v
// 一共给你m个操作，请判断给定的数据是自洽还是自相矛盾
// 自洽打印true，自相矛盾打印false
// 1 <= n <= 100    1 <= m <= 1000
// 总收入不会超过int类型范围
// 测试链接 : https://www.luogu.com.cn/problem/P2294
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
*/

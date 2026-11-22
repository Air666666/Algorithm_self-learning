// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P8779

// Source: src/class156/Code01_DerivePartialSums.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_DerivePartialSums {
  inline static int MAXN = 100002;
  inline static i64 INF = std::numeric_limits<i64>::max();
  inline static int n = {};
  inline static int m = {};
  inline static int q = {};
  inline static Array<int> father = make_array<int>(MAXN);
  inline static Array<i64> dist = make_array<i64>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_DerivePartialSums() {}
  static void prepare() {
    for (int i = 0; (i <= n); (i++)) {
      (father[i] = i);
      (dist[i] = 0);
    }
  }
  static int find(int i) {
    if ((i != father[i])) {
      int tmp = father[i];
      (father[i] = Code01_DerivePartialSums::find(tmp));
      (dist[i] += dist[tmp]);
    }
    return father[i];
  }
  static void union_method(int l, int r, i64 v) {
    int lf = Code01_DerivePartialSums::find(l);
    int rf = Code01_DerivePartialSums::find(r);
    if ((lf != rf)) {
      (father[lf] = rf);
      (dist[lf] = ((v + dist[r]) - dist[l]));
    }
  }
  static i64 query(int l, int r) {
    if ([&]() {
          auto jleft = Code01_DerivePartialSums::find(l);
          auto jright = Code01_DerivePartialSums::find(r);
          return (jleft != jright);
        }()) {
      return INF;
    }
    return (dist[l] - dist[r]);
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    (n = (static_cast<int>(in.nval) + 1));
    in.nextToken();
    (m = static_cast<int>(in.nval));
    in.nextToken();
    (q = static_cast<int>(in.nval));
    Code01_DerivePartialSums::prepare();
    int l = {};
    int r = {};
    i64 v = {};
    for (int i = 1; (i <= m); (i++)) {
      in.nextToken();
      (l = static_cast<int>(in.nval));
      in.nextToken();
      (r = (static_cast<int>(in.nval) + 1));
      in.nextToken();
      (v = static_cast<i64>(in.nval));
      Code01_DerivePartialSums::union_method(l, r, v);
    }
    for (int i = 1; (i <= q); (i++)) {
      in.nextToken();
      (l = static_cast<int>(in.nval));
      in.nextToken();
      (r = (static_cast<int>(in.nval) + 1));
      (v = Code01_DerivePartialSums::query(l, r));
      if ((v == INF)) {
        out.println(String(u"UNKNOWN"));
      } else {
        out.println(v);
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
  Code01_DerivePartialSums::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 推导部分和，带权并查集模版题1
// 有n个数字，下标1 ~ n，但是并不知道每个数字是多少
// 先给出m个数字段的累加和，再查询q个数字段的累加和
// 给出数字段累加和的操作 l r v，代表l~r范围上的数字，累加和为v
// 查询数字段累加和的操作 l r，代表查询l~r范围上的数字累加和
// 请根据m个给定，完成q个查询，如果某个查询无法给出答案，打印"UNKNOWN"
// 1 <= n, m, q <= 10^5
// 累加和不会超过long类型范围
// 测试链接 : https://www.luogu.com.cn/problem/P8779
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
*/

// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P1525

// Source: src/class156/Code07_DetainCriminals.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code07_DetainCriminals {
  inline static int MAXN = 20002;
  inline static int MAXM = 100001;
  inline static int n = {};
  inline static int m = {};
  inline static Array<int> father = make_array<int>(MAXN);
  inline static Array<int> enemy = make_array<int>(MAXN);
  inline static Array<Array<int>> arr = make_array<int>(MAXM, 3);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code07_DetainCriminals() {}
  static void prepare() {
    for (int i = 1; (i <= n); (i++)) {
      (father[i] = i);
      (enemy[i] = 0);
    }
  }
  static int find(int i) {
    (father[i] =
         ((father[i] == i) ? i : Code07_DetainCriminals::find(father[i])));
    return father[i];
  }
  static void union_method(int l, int r) {
    (father[Code07_DetainCriminals::find(l)] = Code07_DetainCriminals::find(r));
  }
  static bool same(int l, int r) {
    return [&]() {
      auto jleft = Code07_DetainCriminals::find(l);
      auto jright = Code07_DetainCriminals::find(r);
      return (jleft == jright);
    }();
  }
  static int compute() {
    j::sort(arr, 1, (m + 1),
            [=](Array<int> a, Array<int> b) { return (b[2] - a[2]); });
    int ans = 0;
    {
      int i = 1;
      int l = {};
      int r = {};
      int v = {};
      for (; (i <= m); (i++)) {
        (l = arr[i][0]);
        (r = arr[i][1]);
        (v = arr[i][2]);
        if (Code07_DetainCriminals::same(l, r)) {
          (ans = v);
          break;
        } else {
          if ((enemy[l] == 0)) {
            (enemy[l] = r);
          } else {
            Code07_DetainCriminals::union_method(enemy[l], r);
          }
          if ((enemy[r] == 0)) {
            (enemy[r] = l);
          } else {
            Code07_DetainCriminals::union_method(l, enemy[r]);
          }
        }
      }
    }
    return ans;
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    (n = static_cast<int>(in.nval));
    in.nextToken();
    (m = static_cast<int>(in.nval));
    Code07_DetainCriminals::prepare();
    for (int i = 1; (i <= m); (i++)) {
      in.nextToken();
      (arr[i][0] = static_cast<int>(in.nval));
      in.nextToken();
      (arr[i][1] = static_cast<int>(in.nval));
      in.nextToken();
      (arr[i][2] = static_cast<int>(in.nval));
    }
    out.println(Code07_DetainCriminals::compute());
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code07_DetainCriminals::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 关押罪犯
// 一共有n个犯人，编号1 ~ n，一共有两个监狱，你可以决定每个犯人去哪个监狱
// 给定m条记录，每条记录 l r v，表示l号犯人和r号犯人的仇恨值
// 每个监狱的暴力值 = 该监狱中仇恨最深的犯人之间的仇恨值
// 冲突值 = max(第一座监狱的暴力值，第二座监狱的暴力值)
// 犯人的分配方案需要让这个冲突值最小，返回最小能是多少
// 1 <= n <= 20000    1 <= m <= 100000    1 <= 仇恨值 <= 10^9
// 测试链接 : https://www.luogu.com.cn/problem/P1525
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
*/

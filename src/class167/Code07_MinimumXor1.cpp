// Source: src/class167/Code07_MinimumXor1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code07_MinimumXor1 {
  inline static int MAXN = 10000001;
  inline static int BIT = 29;
  inline static int INF = jshl(1, 30);
  inline static Array<int> fa = make_array<int>(MAXN);
  inline static Array<Array<int>> tree = make_array<int>(MAXN, 2);
  inline static Array<int> pass = make_array<int>(MAXN);
  inline static int cnt = 1;
  inline static Array<int> mineor = make_array<int>(MAXN);
  inline static Array<int> only = make_array<int>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code07_MinimumXor1() {}
  static int change(int x, int changeCnt) {
    int cur = 1;
    (pass[cur] += changeCnt);
    {
      int b = BIT;
      int path = {};
      for (; (b >= 0); (b--)) {
        (path = (jshr(x, b) & 1));
        if ((tree[cur][path] == 0)) {
          (tree[cur][path] = (++cnt));
          (fa[tree[cur][path]] = cur);
        }
        (cur = tree[cur][path]);
        (pass[cur] += changeCnt);
      }
    }
    return cur;
  }
  static void compute(int x, int changeCnt) {
    int bottom = Code07_MinimumXor1::change(x, changeCnt);
    (mineor[bottom] = ((pass[bottom] >= 2) ? 0 : INF));
    (only[bottom] = ((pass[bottom] == 1) ? x : 0));
    {
      int i = fa[bottom];
      int l = {};
      int r = {};
      for (; (i > 0); (i = fa[i])) {
        (l = tree[i][0]);
        (r = tree[i][1]);
        if ((pass[i] < 2)) {
          (mineor[i] = INF);
        } else if (((pass[l] == 1) && (pass[r] == 1))) {
          (mineor[i] = (only[l] ^ only[r]));
        } else if (((pass[l] == 0) ^ (pass[r] == 0))) {
          (mineor[i] = ((pass[l] == 0) ? mineor[r] : mineor[l]));
        } else {
          (mineor[i] = jmin(mineor[l], mineor[r]));
        }
        if (((pass[l] + pass[r]) == 1)) {
          (only[i] = ((pass[l] == 1) ? only[l] : only[r]));
        } else {
          (only[i] = 0);
        }
      }
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    int q = in.nextInt();
    {
      int i = 1;
      int op = {};
      int x = {};
      for (; (i <= q); (i++)) {
        (op = in.nextInt());
        if ((op == 3)) {
          out.println(mineor[1]);
        } else {
          (x = in.nextInt());
          if ((op == 1)) {
            Code07_MinimumXor1::compute(x, 1);
          } else {
            Code07_MinimumXor1::compute(x, (-1));
          }
        }
      }
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code07_MinimumXor1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 最小异或查询，java版
// 一共有q条操作，每种操作是如下三种类型中的一种
// 操作 1 x : 黑板上写上一个数字x，同一种数字可以出现多次
// 操作 2 x : 将一个x从黑板上擦掉，操作时保证至少有一个x在黑板上
// 操作 3   : 打印黑板上任意两数的最小异或值，操作时保证黑板上至少有两个数
// 1 <= q <= 3 * 10^5
// 0 <= x <= 2^30
// 测试链接 : https://www.luogu.com.cn/problem/AT_abc308_g
// 测试链接 : https://atcoder.jp/contests/abc308/tasks/abc308_g
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 整棵树上最小异或值
        // 整棵树上如果只有一个数x，才有记录，否则记录是0
        // 读写工具类
*/

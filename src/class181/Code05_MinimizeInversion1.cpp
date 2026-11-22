// Source: src/class181/Code05_MinimizeInversion1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code05_MinimizeInversion1 {
  inline static int MAXT = 5000001;
  inline static int n = {};
  inline static Array<int> ls = make_array<int>(MAXT);
  inline static Array<int> rs = make_array<int>(MAXT);
  inline static Array<int> siz = make_array<int>(MAXT);
  inline static int cntt = {};
  inline static i64 ans = {};
  inline static int no = {};
  inline static int yes = {};
  inline static IO in = IO(jin);
  inline static IO out = IO(IO(jout));
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code05_MinimizeInversion1() {}
  static void up(int i) { (siz[i] = (siz[ls[i]] + siz[rs[i]])); }
  static int build(int jobi, int l, int r) {
    int rt = (++cntt);
    if ((l == r)) {
      (siz[rt]++);
    } else {
      int mid = jshr((l + r), 1);
      if ((jobi <= mid)) {
        (ls[rt] = Code05_MinimizeInversion1::build(jobi, l, mid));
      } else {
        (rs[rt] = Code05_MinimizeInversion1::build(jobi, (mid + 1), r));
      }
      Code05_MinimizeInversion1::up(rt);
    }
    return rt;
  }
  static int merge(int l, int r, int t1, int t2) {
    if (((t1 == 0) || (t2 == 0))) {
      return (t1 + t2);
    }
    if ((l == r)) {
      (siz[t1] += siz[t2]);
    } else {
      (no += (static_cast<i64>(siz[rs[t1]]) * siz[ls[t2]]));
      (yes += (static_cast<i64>(siz[rs[t2]]) * siz[ls[t1]]));
      int mid = jshr((l + r), 1);
      (ls[t1] = Code05_MinimizeInversion1::merge(l, mid, ls[t1], ls[t2]));
      (rs[t1] = Code05_MinimizeInversion1::merge((mid + 1), r, rs[t1], rs[t2]));
      Code05_MinimizeInversion1::up(t1);
    }
    return t1;
  }
  static int dfs() {
    int rt = {};
    int val = in.nextInt();
    if ((val == 0)) {
      int left = Code05_MinimizeInversion1::dfs();
      int right = Code05_MinimizeInversion1::dfs();
      (no = (yes = 0));
      (rt = Code05_MinimizeInversion1::merge(1, n, left, right));
      (ans += jmin(no, yes));
    } else {
      (rt = Code05_MinimizeInversion1::build(val, 1, n));
    }
    return rt;
  }
  static void java_main(Array<String> args) {
    (n = in.nextInt());
    Code05_MinimizeInversion1::dfs();
    out.println(ans);
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code05_MinimizeInversion1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 最小化逆序对，java版
// 给定数字n，表示一棵二叉树有n个叶节点，叶节点的权值都不同并且都是1~n范围的数字
//
树上的任何节点，要么是叶节点，要么一定有两个孩子，请从输入流中不断读取数字x来建树
// 如果 x != 0，表示当前来到叶节点并且权值为x，注意只有叶节点有权值
// 如果 x == 0，表示当前来到非叶节点，先递归建立左树，再递归建立右树
//
输入流保证根据规则可以建好这棵二叉树，你可以任选一些节点，交换这些节点的左右子树
//
目的是先序遍历整棵树之后，所有叶节点权值组成的序列中，逆序对数量尽可能小，打印这个最小值
// 2 <= n <= 2 * 10^5
// 测试链接 : https://www.luogu.com.cn/problem/P3521
// 提交以下的code，提交时请把类名改成"Main"
// java实现的逻辑一定是正确的，但是本题卡常，无法通过所有测试用例
// 想通过用C++实现，本节课Code05_MinimizeInversion2文件就是C++的实现
// 两个版本的逻辑完全一样，C++版本可以通过所有测试
        // 读写工具类
*/

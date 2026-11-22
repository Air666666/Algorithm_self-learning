// Source: src/class160/Code03_SegmentWithBalanced1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_SegmentWithBalanced1 {
  inline static int MAXN = 200001;
  inline static int MAXT = (MAXN * 40);
  inline static int INF = std::numeric_limits<int>::max();
  inline static int n = {};
  inline static int m = {};
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static int cntn = {};
  inline static Array<int> root = make_array<int>(jshl(MAXN, 2));
  inline static Array<int> key = make_array<int>(MAXT);
  inline static Array<int> ls = make_array<int>(MAXT);
  inline static Array<int> rs = make_array<int>(MAXT);
  inline static Array<bool> alive = make_array<bool>(MAXT);
  inline static Array<int> aliveSiz = make_array<int>(MAXT);
  inline static double ALPHA = 0.7;
  inline static int top = {};
  inline static int father = {};
  inline static int side = {};
  inline static Array<int> collect = make_array<int>(MAXN);
  inline static int collectSiz = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_SegmentWithBalanced1() {}
  static int init(int num) {
    (key[(++cntn)] = num);
    (ls[cntn] = (rs[cntn] = 0));
    (alive[cntn] = true);
    (aliveSiz[cntn] = 1);
    return cntn;
  }
  static void up(int i) {
    (aliveSiz[i] = (((alive[i] ? 1 : 0) + aliveSiz[ls[i]]) + aliveSiz[rs[i]]));
  }
  static bool balance(int i) {
    return ((ALPHA * aliveSiz[i]) >= jmax(aliveSiz[ls[i]], aliveSiz[rs[i]]));
  }
  static void inorder(int i) {
    if (((i != 0) && (aliveSiz[i] != 0))) {
      Code03_SegmentWithBalanced1::inorder(ls[i]);
      if (alive[i]) {
        (collect[(++collectSiz)] = i);
      }
      Code03_SegmentWithBalanced1::inorder(rs[i]);
    }
  }
  static int build(int l, int r) {
    if ((l > r)) {
      return 0;
    }
    int mid = jdiv((l + r), 2);
    int h = collect[mid];
    (ls[h] = Code03_SegmentWithBalanced1::build(l, (mid - 1)));
    (rs[h] = Code03_SegmentWithBalanced1::build((mid + 1), r));
    Code03_SegmentWithBalanced1::up(h);
    return h;
  }
  static int treeAdd(int i, int f, int s, int num) {
    if (((i == 0) || (aliveSiz[i] == 0))) {
      return Code03_SegmentWithBalanced1::init(num);
    }
    if ((num <= key[i])) {
      (ls[i] = Code03_SegmentWithBalanced1::treeAdd(ls[i], i, 1, num));
    } else {
      (rs[i] = Code03_SegmentWithBalanced1::treeAdd(rs[i], i, 2, num));
    }
    Code03_SegmentWithBalanced1::up(i);
    if ((!Code03_SegmentWithBalanced1::balance(i))) {
      (top = i);
      (father = f);
      (side = s);
    }
    return i;
  }
  static int treeSmall(int i, int num) {
    if (((i == 0) || (aliveSiz[i] == 0))) {
      return 0;
    }
    if ((num <= key[i])) {
      return Code03_SegmentWithBalanced1::treeSmall(ls[i], num);
    } else {
      return ((aliveSiz[ls[i]] + (alive[i] ? 1 : 0)) +
              Code03_SegmentWithBalanced1::treeSmall(rs[i], num));
    }
  }
  static int treeIndex(int i, int x) {
    if ((x <= aliveSiz[ls[i]])) {
      return Code03_SegmentWithBalanced1::treeIndex(ls[i], x);
    } else {
      int less = (aliveSiz[ls[i]] + (alive[i] ? 1 : 0));
      if ((less < x)) {
        return Code03_SegmentWithBalanced1::treeIndex(rs[i], (x - less));
      }
    }
    return key[i];
  }
  static void treeRemove(int i, int f, int s, int rank) {
    int lsiz = aliveSiz[ls[i]];
    if ((rank <= lsiz)) {
      Code03_SegmentWithBalanced1::treeRemove(ls[i], i, 1, rank);
    } else {
      int cur = (alive[i] ? 1 : 0);
      if ((alive[i] && (rank == (lsiz + cur)))) {
        (alive[i] = false);
      } else {
        Code03_SegmentWithBalanced1::treeRemove(rs[i], i, 2,
                                                ((rank - lsiz) - cur));
      }
    }
    Code03_SegmentWithBalanced1::up(i);
    if ((!Code03_SegmentWithBalanced1::balance(i))) {
      (top = i);
      (father = f);
      (side = s);
    }
  }
  static void rebuild(int version) {
    if ((top != 0)) {
      (collectSiz = 0);
      Code03_SegmentWithBalanced1::inorder(top);
      int newRoot = Code03_SegmentWithBalanced1::build(1, collectSiz);
      if ((father == 0)) {
        (root[version] = newRoot);
      } else if ((side == 1)) {
        (ls[father] = newRoot);
      } else {
        (rs[father] = newRoot);
      }
    }
  }
  static void innerAdd(int version, int num) {
    (top = (father = (side = 0)));
    (root[version] =
         Code03_SegmentWithBalanced1::treeAdd(root[version], 0, 0, num));
    Code03_SegmentWithBalanced1::rebuild(version);
  }
  static int innerRank(int version, int num) {
    return (Code03_SegmentWithBalanced1::treeSmall(root[version], num) + 1);
  }
  static void innerRemove(int version, int num) {
    int rank1 = Code03_SegmentWithBalanced1::innerRank(version, num);
    int rank2 = Code03_SegmentWithBalanced1::innerRank(version, (num + 1));
    if ((rank1 != rank2)) {
      (top = (father = (side = 0)));
      Code03_SegmentWithBalanced1::treeRemove(root[version], 0, 0, rank1);
      Code03_SegmentWithBalanced1::rebuild(version);
    }
  }
  static int innerPre(int version, int num) {
    int rank = Code03_SegmentWithBalanced1::innerRank(version, num);
    if ((rank == 1)) {
      return (-INF);
    } else {
      return Code03_SegmentWithBalanced1::treeIndex(root[version], (rank - 1));
    }
  }
  static int innerPost(int version, int num) {
    int rank = Code03_SegmentWithBalanced1::innerRank(version, (num + 1));
    if ((rank == (aliveSiz[root[version]] + 1))) {
      return INF;
    } else {
      return Code03_SegmentWithBalanced1::treeIndex(root[version], rank);
    }
  }
  static void add(int jobi, int jobv, int l, int r, int i) {
    Code03_SegmentWithBalanced1::innerAdd(i, jobv);
    if ((l < r)) {
      int mid = jshr((l + r), 1);
      if ((jobi <= mid)) {
        Code03_SegmentWithBalanced1::add(jobi, jobv, l, mid, jshl(i, 1));
      } else {
        Code03_SegmentWithBalanced1::add(jobi, jobv, (mid + 1), r,
                                         (jshl(i, 1) | 1));
      }
    }
  }
  static void update(int jobi, int jobv, int l, int r, int i) {
    Code03_SegmentWithBalanced1::innerRemove(i, arr[jobi]);
    Code03_SegmentWithBalanced1::innerAdd(i, jobv);
    if ((l < r)) {
      int mid = jshr((l + r), 1);
      if ((jobi <= mid)) {
        Code03_SegmentWithBalanced1::update(jobi, jobv, l, mid, jshl(i, 1));
      } else {
        Code03_SegmentWithBalanced1::update(jobi, jobv, (mid + 1), r,
                                            (jshl(i, 1) | 1));
      }
    }
  }
  static int small(int jobl, int jobr, int jobv, int l, int r, int i) {
    if (((jobl <= l) && (r <= jobr))) {
      return Code03_SegmentWithBalanced1::treeSmall(root[i], jobv);
    }
    int mid = jshr((l + r), 1);
    int ans = 0;
    if ((jobl <= mid)) {
      (ans += Code03_SegmentWithBalanced1::small(jobl, jobr, jobv, l, mid,
                                                 jshl(i, 1)));
    }
    if ((jobr > mid)) {
      (ans += Code03_SegmentWithBalanced1::small(jobl, jobr, jobv, (mid + 1), r,
                                                 (jshl(i, 1) | 1)));
    }
    return ans;
  }
  static int number(int jobl, int jobr, int jobk) {
    int l = 0;
    int r = 100000000;
    int mid = {};
    int ans = 0;
    while ((l <= r)) {
      (mid = jshr((l + r), 1));
      if (((Code03_SegmentWithBalanced1::small(jobl, jobr, (mid + 1), 1, n, 1) +
            1) > jobk)) {
        (ans = mid);
        (r = (mid - 1));
      } else {
        (l = (mid + 1));
      }
    }
    return ans;
  }
  static int pre(int jobl, int jobr, int jobv, int l, int r, int i) {
    if (((jobl <= l) && (r <= jobr))) {
      return Code03_SegmentWithBalanced1::innerPre(i, jobv);
    }
    int mid = jshr((l + r), 1);
    int ans = (-INF);
    if ((jobl <= mid)) {
      (ans = jmax(ans, Code03_SegmentWithBalanced1::pre(jobl, jobr, jobv, l,
                                                        mid, jshl(i, 1))));
    }
    if ((jobr > mid)) {
      (ans = jmax(ans, Code03_SegmentWithBalanced1::pre(
                           jobl, jobr, jobv, (mid + 1), r, (jshl(i, 1) | 1))));
    }
    return ans;
  }
  static int post(int jobl, int jobr, int jobv, int l, int r, int i) {
    if (((jobl <= l) && (r <= jobr))) {
      return Code03_SegmentWithBalanced1::innerPost(i, jobv);
    }
    int mid = jshr((l + r), 1);
    int ans = INF;
    if ((jobl <= mid)) {
      (ans = jmin(ans, Code03_SegmentWithBalanced1::post(jobl, jobr, jobv, l,
                                                         mid, jshl(i, 1))));
    }
    if ((jobr > mid)) {
      (ans = jmin(ans, Code03_SegmentWithBalanced1::post(
                           jobl, jobr, jobv, (mid + 1), r, (jshl(i, 1) | 1))));
    }
    return ans;
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (m = in.nextInt());
    for (int i = 1; (i <= n); (i++)) {
      (arr[i] = in.nextInt());
    }
    for (int i = 1; (i <= n); (i++)) {
      Code03_SegmentWithBalanced1::add(i, arr[i], 1, n, 1);
    }
    {
      int i = 1;
      int op = {};
      int x = {};
      int y = {};
      int z = {};
      for (; (i <= m); (i++)) {
        (op = in.nextInt());
        (x = in.nextInt());
        (y = in.nextInt());
        if ((op == 3)) {
          Code03_SegmentWithBalanced1::update(x, y, 1, n, 1);
          (arr[x] = y);
        } else {
          (z = in.nextInt());
          if ((op == 1)) {
            out.println(
                (Code03_SegmentWithBalanced1::small(x, y, z, 1, n, 1) + 1));
          } else if ((op == 2)) {
            out.println(Code03_SegmentWithBalanced1::number(x, y, z));
          } else if ((op == 4)) {
            out.println(Code03_SegmentWithBalanced1::pre(x, y, z, 1, n, 1));
          } else {
            out.println(Code03_SegmentWithBalanced1::post(x, y, z, 1, n, 1));
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
  Code03_SegmentWithBalanced1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 线段树套平衡树，java版
//
给定一个长度为n的数组arr，下标1~n，每条操作都是如下5种类型中的一种，一共进行m次操作
// 操作 1 x y z : 查询数字z在arr[x..y]中的排名
// 操作 2 x y z : 查询arr[x..y]中排第z名的数字
// 操作 3 x y   : arr中x位置的数字改成y
// 操作 4 x y z : 查询数字z在arr[x..y]中的前驱，不存在返回-2147483647
// 操作 5 x y z : 查询数字z在arr[x..y]中的后继，不存在返回+2147483647
// 1 <= n、m <= 2 * 10^5
// 数组中的值永远在[0, 10^8]范围内
// 测试链接 : https://www.luogu.com.cn/problem/P3380
// 提交以下的code，提交时请把类名改成"Main"
// 线段树套平衡树不是正解，操作2的复杂度较高，正解是题目4的实现
// 加上是java实现，常数较大，无法通过
// 想通过用C++实现，本节课Code03_SegmentWithBalanced2文件就是C++的实现
// 两个版本的逻辑完全一样，C++版本可以通过所有测试
        // 替罪羊树的节点计数
        // 线段树维护的替罪羊树根节点编号
        // 替罪羊树，讲解150
        // 初始化替罪羊树的节点，返回节点编号
        // 汇总存活节点信息
        // 替罪羊树判断平衡
        // 中序遍历收集不平衡子树的存活节点
        // 替罪羊树建树
        // 替罪羊树上，加入数字num，返回头节点编号
        // 替罪羊树上，查询<num的数字个数
        // 替罪羊树上，查询第x小的数字
        // 替罪羊树上，删除排名是rank的数字
        // 替罪羊树的局部重构，如果整棵树换头，则修改root[version]
        // 内层替罪羊树，版本是version，头节点是root[version]，加入数字num
        // 内层替罪羊树，版本是version，头节点是root[version]，查询num的排名
        // 内层替罪羊树，版本是version，头节点是root[version]，删除数字num
        // 内层替罪羊树，版本是version，头节点是root[version]，查询num的前驱
        // 内层替罪羊树，版本是version，头节点是root[version]，查询num的后继
        // 外层线段树
        // 外层线段树
        // 外层线段树
        // 外层线段树
        // 外层线段树
        // 外层线段树
        // 读写工具类
*/

// Source: src/class150/Better1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Better1 {
  inline static int MAXN = 2000001;
  inline static int cntn = {};
  inline static int root = {};
  inline static Array<int> key = make_array<int>(MAXN);
  inline static Array<int> ls = make_array<int>(MAXN);
  inline static Array<int> rs = make_array<int>(MAXN);
  inline static Array<bool> alive = make_array<bool>(MAXN);
  inline static Array<int> aliveSiz = make_array<int>(MAXN);
  inline static double ALPHA = 0.7;
  inline static int top = {};
  inline static int father = {};
  inline static int side = {};
  inline static Array<int> collect = make_array<int>(MAXN);
  inline static int collectSiz = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Better1() {}
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
  static void inorder(int i) {
    if (((i != 0) && (aliveSiz[i] != 0))) {
      Better1::inorder(ls[i]);
      if (alive[i]) {
        (collect[(++collectSiz)] = i);
      }
      Better1::inorder(rs[i]);
    }
  }
  static int build(int l, int r) {
    if ((l > r)) {
      return 0;
    }
    int m = jdiv((l + r), 2);
    int h = collect[m];
    (ls[h] = Better1::build(l, (m - 1)));
    (rs[h] = Better1::build((m + 1), r));
    Better1::up(h);
    return h;
  }
  static void rebuild() {
    if ((top != 0)) {
      (collectSiz = 0);
      Better1::inorder(top);
      int newRoot = Better1::build(1, collectSiz);
      if ((father == 0)) {
        (root = newRoot);
      } else if ((side == 1)) {
        (ls[father] = newRoot);
      } else {
        (rs[father] = newRoot);
      }
    }
  }
  static bool balance(int i) {
    return ((ALPHA * aliveSiz[i]) >= jmax(aliveSiz[ls[i]], aliveSiz[rs[i]]));
  }
  static int add(int i, int f, int s, int num) {
    if (((i == 0) || (aliveSiz[i] == 0))) {
      return Better1::init(num);
    }
    if ((num <= key[i])) {
      (ls[i] = Better1::add(ls[i], i, 1, num));
    } else {
      (rs[i] = Better1::add(rs[i], i, 2, num));
    }
    Better1::up(i);
    if ((!Better1::balance(i))) {
      (top = i);
      (father = f);
      (side = s);
    }
    return i;
  }
  static void add(int num) {
    (top = (father = (side = 0)));
    (root = Better1::add(root, 0, 0, num));
    Better1::rebuild();
  }
  static int small(int i, int num) {
    if (((i == 0) || (aliveSiz[i] == 0))) {
      return 0;
    }
    if ((num <= key[i])) {
      return Better1::small(ls[i], num);
    } else {
      return ((aliveSiz[ls[i]] + (alive[i] ? 1 : 0)) +
              Better1::small(rs[i], num));
    }
  }
  static int rank(int num) { return (Better1::small(root, num) + 1); }
  static int index(int i, int x) {
    if ((x <= aliveSiz[ls[i]])) {
      return Better1::index(ls[i], x);
    } else {
      int less = (aliveSiz[ls[i]] + (alive[i] ? 1 : 0));
      if ((less < x)) {
        return Better1::index(rs[i], (x - less));
      }
    }
    return key[i];
  }
  static int index(int x) { return Better1::index(root, x); }
  static int pre(int num) {
    int kth = Better1::rank(num);
    if ((kth == 1)) {
      return std::numeric_limits<int>::min();
    } else {
      return Better1::index((kth - 1));
    }
  }
  static int post(int num) {
    int kth = Better1::rank((num + 1));
    if ((kth == (aliveSiz[root] + 1))) {
      return std::numeric_limits<int>::max();
    } else {
      return Better1::index(kth);
    }
  }
  static void remove(int i, int f, int s, int rank) {
    int lsiz = aliveSiz[ls[i]];
    if ((rank <= lsiz)) {
      Better1::remove(ls[i], i, 1, rank);
    } else {
      int cur = (alive[i] ? 1 : 0);
      if ((alive[i] && (rank == (lsiz + cur)))) {
        (alive[i] = false);
      } else {
        Better1::remove(rs[i], i, 2, ((rank - lsiz) - cur));
      }
    }
    Better1::up(i);
    if ((!Better1::balance(i))) {
      (top = i);
      (father = f);
      (side = s);
    }
  }
  static void remove(int num) {
    int rank1 = Better1::rank(num);
    int rank2 = Better1::rank((num + 1));
    if ((rank1 != rank2)) {
      (top = (father = (side = 0)));
      Better1::remove(root, 0, 0, rank1);
      Better1::rebuild();
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    int n = in.nextInt();
    int m = in.nextInt();
    {
      int i = 1;
      int num = {};
      for (; (i <= n); (i++)) {
        (num = in.nextInt());
        Better1::add(num);
      }
    }
    int lastAns = 0;
    int ans = 0;
    {
      int i = 1;
      int op = {};
      int x = {};
      for (; (i <= m); (i++)) {
        (op = in.nextInt());
        (x = in.nextInt());
        (x ^= lastAns);
        if ((op == 1)) {
          Better1::add(x);
        } else if ((op == 2)) {
          Better1::remove(x);
        } else if ((op == 3)) {
          (lastAns = Better1::rank(x));
          (ans ^= lastAns);
        } else if ((op == 4)) {
          (lastAns = Better1::index(x));
          (ans ^= lastAns);
        } else if ((op == 5)) {
          (lastAns = Better1::pre(x));
          (ans ^= lastAns);
        } else {
          (lastAns = Better1::post(x));
          (ans ^= lastAns);
        }
      }
    }
    out.println(ans);
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Better1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 替罪羊树的更好实现，java版
// 本文件是不做词频压缩的替罪羊树实现，并且数据经过了加强
// 本节课的视频，做了重要更新，补充了很多说明
// 介绍了我设计的替罪羊树，对比经典的替罪羊树，有哪些独特性和便利性
// 说明了我设计的替罪羊树和经典替罪羊树，复杂度是一样的
// 注意如下实现中的注释文字
// 测试链接 : https://www.luogu.com.cn/problem/P6136
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 节点是否存活，删掉就算死亡
        // 子树的存活节点数量
        // 汇总存活节点数量
                // 增加剪枝：整棵树上没有存活节点也跳过
        // 返回头节点编号
                // 增加剪枝：整棵树上没有存活节点就算空树
                // 增加剪枝：整棵树上没有存活节点，就算空树
        // 注意remove方法
        // 因为替罪羊树会重构，所以值相同的一批节点，重构时假设选出的头为h
        // 那么这批节点，有可能在h的左侧，也有可能在h的右侧
        // 所以删除时，如果h已经被删，还要继续寻找其他key值相同的节点
        // 此时只根据key值的大小关系，方向无法确定是左还是右
        // 所以先求出目标的排名，再按排名删除，这样移动方向是确定的
        // 读写工具类
*/

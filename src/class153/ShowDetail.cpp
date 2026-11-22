// Source: src/class153/ShowDetail.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct ShowDetail {
  inline static int MAXN = 100001;
  inline static int head = 0;
  inline static int cnt = 0;
  inline static Array<int> key = make_array<int>(MAXN);
  inline static Array<int> father = make_array<int>(MAXN);
  inline static Array<int> left = make_array<int>(MAXN);
  inline static Array<int> right = make_array<int>(MAXN);
  inline static Array<int> size = make_array<int>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  ShowDetail() {}
  static void up(int i) { (size[i] = ((size[left[i]] + size[right[i]]) + 1)); }
  static int lr(int i) { return ((right[father[i]] == i) ? 1 : 0); }
  static void rotate(int i) {
    int f = father[i];
    int g = father[f];
    int soni = ShowDetail::lr(i);
    int sonf = ShowDetail::lr(f);
    if ((soni == 1)) {
      (right[f] = left[i]);
      if ((right[f] != 0)) {
        (father[right[f]] = f);
      }
      (left[i] = f);
    } else {
      (left[f] = right[i]);
      if ((left[f] != 0)) {
        (father[left[f]] = f);
      }
      (right[i] = f);
    }
    if ((g != 0)) {
      if ((sonf == 1)) {
        (right[g] = i);
      } else {
        (left[g] = i);
      }
    }
    (father[f] = i);
    (father[i] = g);
    ShowDetail::up(f);
    ShowDetail::up(i);
  }
  static void splay(int i, int goal) {
    int f = father[i];
    int g = father[f];
    while ((f != goal)) {
      if ((g != goal)) {
        if ([&]() {
              auto jleft = ShowDetail::lr(i);
              auto jright = ShowDetail::lr(f);
              return (jleft == jright);
            }()) {
          ShowDetail::rotate(f);
        } else {
          ShowDetail::rotate(i);
        }
      }
      ShowDetail::rotate(i);
      (f = father[i]);
      (g = father[f]);
    }
    if ((goal == 0)) {
      (head = i);
    }
  }
  static int build1(int l, int r) {
    int h = (cnt + 1);
    {
      int i = l;
      int last = 0;
      for (; (i <= r); (i++), (last = cnt)) {
        (key[(++cnt)] = i);
        (father[cnt] = last);
        (left[cnt] = (right[cnt] = 0));
        (size[cnt] = ((r - i) + 1));
        if ((last != 0)) {
          (right[last] = cnt);
        }
      }
    }
    return h;
  }
  static int build2(int l, int r, int fa) {
    if ((l > r)) {
      return 0;
    }
    (key[(++cnt)] = l);
    (father[cnt] = fa);
    (left[cnt] = (right[cnt] = 0));
    int h = cnt;
    if ((l < r)) {
      (key[(++cnt)] = r);
      (father[cnt] = h);
      (left[cnt] = (right[cnt] = 0));
      int c = cnt;
      (right[h] = c);
      (left[c] = ShowDetail::build2((l + 1), (r - 1), c));
      ShowDetail::up(c);
    }
    ShowDetail::up(h);
    return h;
  }
  static int height(int i) {
    if ((i == 0)) {
      return 0;
    }
    return ([&]() {
      auto jargument_0 = ShowDetail::height(left[i]);
      auto jargument_1 = ShowDetail::height(right[i]);
      return jmax(jargument_0, jargument_1);
    }() + 1);
  }
  static void java_main(Array<String> args) {
    jout.println(String(u"构建一字型长链"));
    jout.println(String(u"最下方节点执行splay，观察高度变化"));
    (head = ShowDetail::build1(1, 1000));
    jout.println((String(u"splay之前的链长度 : ") + ShowDetail::height(head)));
    ShowDetail::splay(cnt, 0);
    jout.println((String(u"splay之后的链长度 : ") + ShowDetail::height(head)));
    jout.println(String(u"=================="));
    jout.println(String(u"构建之字型长链"));
    jout.println(String(u"最下方节点执行splay，观察高度变化"));
    (head = ShowDetail::build2(1, 1000, 0));
    jout.println((String(u"splay之前的链长度 : ") + ShowDetail::height(head)));
    ShowDetail::splay(cnt, 0);
    jout.println((String(u"splay之后的链长度 : ") + ShowDetail::height(head)));
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  ShowDetail::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 提根操作的代码 + 长链高度变化的实验
// 分别去生成一字型长链和之字型长链
// 每一种长链都让最下方节点提根上去
// 然后看看长链的高度变化
        // 整棵树的头节点编号
        // 分配了多少节点编号
        // key[i]    : 编号为i的节点的key
        // father[i] : 编号为i的节点的父节点编号
        // left[i]   : 编号为i的节点的左孩子编号
        // right[i]  : 编号为i的节点的右孩子编号
        // size[i]   : 以编号为i的节点做头的子树，一共有多少个节点
        //             这个数组和具体要实现的功能有关，属于常用信息
        // 判断编号为i的节点，是其父亲的什么儿子
        // 0代表左儿子，1代表右儿子
        // 编号为i的节点上升一步，在结构上做调整
        // 编号为i的节点提根，变成编号为goal的节点的儿子
        // 如果goal == 0，表示把编号为i的节点变成整棵树的头
        // 构建一字型长链
        // 构建之字形长链
        // 返回以i为头的树的高度
*/

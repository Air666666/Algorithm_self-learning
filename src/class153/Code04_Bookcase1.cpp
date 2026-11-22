// Source: src/class153/Code04_Bookcase1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_Bookcase1 {
  inline static int MAXN = 80005;
  inline static int head = 0;
  inline static int cnt = 0;
  inline static Array<int> num = make_array<int>(MAXN);
  inline static Array<int> father = make_array<int>(MAXN);
  inline static Array<int> left = make_array<int>(MAXN);
  inline static Array<int> right = make_array<int>(MAXN);
  inline static Array<int> size = make_array<int>(MAXN);
  inline static Array<int> pos = make_array<int>(MAXN);
  inline static int n = {};
  inline static int m = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_Bookcase1() {}
  static void up(int i) { (size[i] = ((size[left[i]] + size[right[i]]) + 1)); }
  static int lr(int i) { return ((right[father[i]] == i) ? 1 : 0); }
  static void rotate(int i) {
    int f = father[i];
    int g = father[f];
    int soni = Code04_Bookcase1::lr(i);
    int sonf = Code04_Bookcase1::lr(f);
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
    Code04_Bookcase1::up(f);
    Code04_Bookcase1::up(i);
  }
  static void splay(int i, int goal) {
    int f = father[i];
    int g = father[f];
    while ((f != goal)) {
      if ((g != goal)) {
        if ([&]() {
              auto jleft = Code04_Bookcase1::lr(i);
              auto jright = Code04_Bookcase1::lr(f);
              return (jleft == jright);
            }()) {
          Code04_Bookcase1::rotate(f);
        } else {
          Code04_Bookcase1::rotate(i);
        }
      }
      Code04_Bookcase1::rotate(i);
      (f = father[i]);
      (g = father[f]);
    }
    if ((goal == 0)) {
      (head = i);
    }
  }
  static int find(int rank) {
    int i = head;
    while ((i != 0)) {
      if (((size[left[i]] + 1) == rank)) {
        return i;
      } else if ((size[left[i]] >= rank)) {
        (i = left[i]);
      } else {
        (rank -= (size[left[i]] + 1));
        (i = right[i]);
      }
    }
    return 0;
  }
  static void add(int s) {
    (num[(++cnt)] = s);
    (pos[s] = cnt);
    (size[cnt] = 1);
    (father[cnt] = head);
    (right[head] = cnt);
    Code04_Bookcase1::splay(cnt, 0);
  }
  static int ask(int s) {
    int i = pos[s];
    Code04_Bookcase1::splay(i, 0);
    return size[left[i]];
  }
  static int query(int s) {
    int i = Code04_Bookcase1::find(s);
    Code04_Bookcase1::splay(i, 0);
    return num[i];
  }
  static void move(int a, int b) {
    int l = Code04_Bookcase1::find((a - 1));
    int r = Code04_Bookcase1::find((a + 1));
    Code04_Bookcase1::splay(l, 0);
    Code04_Bookcase1::splay(r, l);
    int i = left[r];
    (left[r] = 0);
    Code04_Bookcase1::up(r);
    Code04_Bookcase1::up(l);
    (l = Code04_Bookcase1::find((b - 1)));
    (r = Code04_Bookcase1::find(b));
    Code04_Bookcase1::splay(l, 0);
    Code04_Bookcase1::splay(r, l);
    (left[r] = i);
    (father[i] = r);
    Code04_Bookcase1::up(r);
    Code04_Bookcase1::up(l);
  }
  static void java_main(Array<String> args) {
    IO io = IO();
    (n = io.nextInt());
    (m = io.nextInt());
    Code04_Bookcase1::add(0);
    for (int i = 1; (i <= n); (i++)) {
      Code04_Bookcase1::add(io.nextInt());
    }
    Code04_Bookcase1::add((n + 1));
    (n = (n + 2));
    String op = {};
    {
      int i = 1;
      int s = {};
      int t = {};
      int rank = {};
      for (; (i <= m); (i++)) {
        (op = io.next());
        (s = io.nextInt());
        (rank = (Code04_Bookcase1::ask(s) + 1));
        if (op.equals(String(u"Top"))) {
          Code04_Bookcase1::move(rank, 2);
        } else if (op.equals(String(u"Bottom"))) {
          Code04_Bookcase1::move(rank, (n - 1));
        } else if (op.equals(String(u"Insert"))) {
          (t = io.nextInt());
          Code04_Bookcase1::move(rank, (rank + t));
        } else if (op.equals(String(u"Ask"))) {
          io.println((rank - 2));
        } else {
          io.println(Code04_Bookcase1::query((s + 1)));
        }
      }
    }
    io.flush();
    io.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code04_Bookcase1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 书架(java版)
// 给定一个长度为n的排列，由数字1、2、3...n组成，实现如下五种操作
// Top s      : 数字s移动到最左边
// Bottom s   : 数字s移动到最右边
// Insert s t : 数字s位置假设为rank，现在移动到rank+t位置
// Ask s      : 查询数字s左边有多少数字
// Query s    : 查询从左往右第s位的数字
// 所有操作保证都是合法的
// 测试链接 : https://www.luogu.com.cn/problem/P2596
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // pos[num] : 数字num所在节点的编号
        // 返回中序排名为rank的节点编号
        // 中序排名为a的节点，移动到中序排名为b的位置
        // 注意a不会是1和n位置，b也如此
        // 因为1位置和n位置提前加入了预备值，永远不会修改
                // 注意在最左插入了0，最右插入了n+1，作为准备值，所以一共n+2个数
                // 下面操作时，不要忘了最左是0，最右是n+1，并且永远不修改
                                //
因为有最左侧的准备值，所以开头是中序排名2的位置
                                //
因为有最右侧的准备值，所以结尾是中序排名n-1的位置
                                // rank代表当前数字的排名，因为有最左侧的准备值
                                //
所以排名其实是rank-1，题目要返回小于的数量，所以是rank - 2
                                // 因为有最左侧的准备值，所以查s+1名的数字
        // Kattio类IO效率很好，但还是不如StreamTokenizer
        // 只有StreamTokenizer无法正确处理时，才考虑使用这个类
        // 参考链接 : https://oi-wiki.org/lang/java-pro/
*/

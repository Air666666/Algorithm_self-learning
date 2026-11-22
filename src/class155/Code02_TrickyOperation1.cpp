// Source: src/class155/Code02_TrickyOperation1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_TrickyOperation1 {
  inline static int MAXN = 300001;
  inline static int n = {};
  inline static int m = {};
  inline static Array<int> num = make_array<int>(MAXN);
  inline static Array<int> up = make_array<int>(MAXN);
  inline static Array<int> left = make_array<int>(MAXN);
  inline static Array<int> right = make_array<int>(MAXN);
  inline static Array<int> dist = make_array<int>(MAXN);
  inline static Array<int> father = make_array<int>(MAXN);
  inline static Array<int> size = make_array<int>(MAXN);
  inline static Array<int> add = make_array<int>(MAXN);
  inline static JTreeMap<int, int> heads = JTreeMap<int, int>();
  inline static int addAll = 0;
  inline static Array<int> stack = make_array<int>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_TrickyOperation1() {}
  static void minusHead(int h) {
    if ((h != 0)) {
      int hnum = (num[h] + add[h]);
      if ((heads.get(hnum) == 1)) {
        heads.remove(hnum);
      } else {
        heads.put(hnum, (heads.get(hnum) - 1));
      }
    }
  }
  static void addHead(int h) {
    if ((h != 0)) {
      int hnum = (num[h] + add[h]);
      heads.put(hnum, (heads.getOrDefault(hnum, 0) + 1));
    }
  }
  static void prepare() {
    (dist[0] = (-1));
    heads.clear();
    for (int i = 1; (i <= n); (i++)) {
      (up[i] = (left[i] = (right[i] = (dist[i] = 0))));
      (father[i] = i);
      (size[i] = 1);
      (add[i] = 0);
      Code02_TrickyOperation1::addHead(i);
    }
    (addAll = 0);
  }
  static int find(int i) {
    (father[i] =
         ((father[i] == i) ? i : Code02_TrickyOperation1::find(father[i])));
    return father[i];
  }
  static int merge(int i, int j) {
    if (((i == 0) || (j == 0))) {
      return (i + j);
    }
    int tmp = {};
    if ((num[i] < num[j])) {
      (tmp = i);
      (i = j);
      (j = tmp);
    }
    (right[i] = Code02_TrickyOperation1::merge(right[i], j));
    (up[right[i]] = i);
    if ((dist[left[i]] < dist[right[i]])) {
      (tmp = left[i]);
      (left[i] = right[i]);
      (right[i] = tmp);
    }
    (dist[i] = (dist[right[i]] + 1));
    (father[left[i]] = (father[right[i]] = i));
    return i;
  }
  static int remove(int i) {
    int h = Code02_TrickyOperation1::find(i);
    (father[left[i]] = left[i]);
    (father[right[i]] = right[i]);
    int s = Code02_TrickyOperation1::merge(left[i], right[i]);
    int f = up[i];
    (father[i] = s);
    (up[s] = f);
    if ((h != i)) {
      (father[s] = h);
      if ((left[f] == i)) {
        (left[f] = s);
      } else {
        (right[f] = s);
      }
      {
        int d = dist[s];
        int tmp = {};
        for (; (dist[f] > (d + 1)); (f = up[f]), (d++)) {
          (dist[f] = (d + 1));
          if ((dist[left[f]] < dist[right[f]])) {
            (tmp = left[f]);
            (left[f] = right[f]);
            (right[f] = tmp);
          }
        }
      }
    }
    (up[i] = (left[i] = (right[i] = (dist[i] = 0))));
    return father[s];
  }
  static void down(int i, int v) {
    if ((i != 0)) {
      (add[i] = 0);
      int size = 0;
      (stack[(++size)] = i);
      while ((size > 0)) {
        (i = stack[(size--)]);
        (num[i] += v);
        if ((right[i] != 0)) {
          (stack[(++size)] = right[i]);
        }
        if ((left[i] != 0)) {
          (stack[(++size)] = left[i]);
        }
      }
    }
  }
  static void u(int i, int j) {
    int l = Code02_TrickyOperation1::find(i);
    int r = Code02_TrickyOperation1::find(j);
    if ((l == r)) {
      return;
    }
    int lsize = size[l];
    Code02_TrickyOperation1::minusHead(l);
    int rsize = size[r];
    Code02_TrickyOperation1::minusHead(r);
    int addTag = {};
    if ((lsize <= rsize)) {
      Code02_TrickyOperation1::down(l, (add[l] - add[r]));
      (addTag = add[r]);
    } else {
      Code02_TrickyOperation1::down(r, (add[r] - add[l]));
      (addTag = add[l]);
    }
    int h = Code02_TrickyOperation1::merge(l, r);
    (size[h] = (lsize + rsize));
    (add[h] = addTag);
    Code02_TrickyOperation1::addHead(h);
  }
  static void a1(int i, int v) {
    int h = Code02_TrickyOperation1::find(i);
    Code02_TrickyOperation1::minusHead(h);
    int l = Code02_TrickyOperation1::remove(i);
    if ((l != 0)) {
      (size[l] = (size[h] - 1));
      (add[l] = add[h]);
      Code02_TrickyOperation1::addHead(l);
    }
    (num[i] = ((num[i] + add[h]) + v));
    (father[i] = i);
    (size[i] = 1);
    (add[i] = 0);
    Code02_TrickyOperation1::addHead(i);
    Code02_TrickyOperation1::u(l, i);
  }
  static void a2(int i, int v) {
    int h = Code02_TrickyOperation1::find(i);
    Code02_TrickyOperation1::minusHead(h);
    (add[h] += v);
    Code02_TrickyOperation1::addHead(h);
  }
  static void a3(int v) { (addAll += v); }
  static int f1(int i) {
    return ((num[i] + add[Code02_TrickyOperation1::find(i)]) + addAll);
  }
  static int f2(int i) {
    int h = Code02_TrickyOperation1::find(i);
    return ((num[h] + add[h]) + addAll);
  }
  static int f3() { return (heads.lastKey() + addAll); }
  static void java_main(Array<String> args) {
    IO io = IO();
    (n = io.nextInt());
    for (int i = 1; (i <= n); (i++)) {
      (num[i] = io.nextInt());
    }
    Code02_TrickyOperation1::prepare();
    (m = io.nextInt());
    String op = {};
    {
      int i = 1;
      int x = {};
      int y = {};
      for (; (i <= m); (i++)) {
        (op = io.next());
        if (op.equals(String(u"F3"))) {
          io.println(Code02_TrickyOperation1::f3());
        } else {
          (x = io.nextInt());
          if (op.equals(String(u"U"))) {
            (y = io.nextInt());
            Code02_TrickyOperation1::u(x, y);
          } else if (op.equals(String(u"A1"))) {
            (y = io.nextInt());
            Code02_TrickyOperation1::a1(x, y);
          } else if (op.equals(String(u"A2"))) {
            (y = io.nextInt());
            Code02_TrickyOperation1::a2(x, y);
          } else if (op.equals(String(u"A3"))) {
            Code02_TrickyOperation1::a3(x);
          } else if (op.equals(String(u"F1"))) {
            io.println(Code02_TrickyOperation1::f1(x));
          } else {
            io.println(Code02_TrickyOperation1::f2(x));
          }
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
  Code02_TrickyOperation1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 棘手的操作，java版
// 编号1~n个节点，每个节点独立且有自己的权值，实现如下7种操作，操作一共调用m次
// U x y  : x所在的集合和y所在的集合合并
// A1 x v : x节点的权值增加v
// A2 x v : x所在的集合所有节点的权值增加v
// A3 v   : 所有节点的权值增加v
// F1 x   : 打印x节点的权值
// F2 x   : 打印x所在的集合中，权值最大的节点的权值
// F3     : 打印所有节点中，权值最大的节点的权值
// 1 <= n、m <= 3 * 10^5，权值不会超过int类型的范围
// 测试链接 : https://www.luogu.com.cn/problem/P3273
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 左偏树需要
        // 并查集的路径信息
        // 集合的大小信息
        // 集合内所有数字应该加多少值
        // 所有集合头节点的值，进入这个有序表，头节点有序表
        // 所有数字应该加多少
        // 准备好一个栈，用迭代方式实现先序遍历，不用递归方式
        // 编号为h的节点不再是左偏树的头，在头节点有序表里删掉一份h节点的值
        // 编号为h的节点当前是左偏树的头，在头节点有序表里增加一份h节点的值
        // 返回i节点所在左偏树的树头
        // 合并两棵左偏树
        // 节点i是所在左偏树的任意节点，删除节点i，返回整棵树的头节点编号
        // 以i为头的左偏树，遭遇了更大的左偏树
        // i的标签信息取消，以i为头的整棵树所有节点的值增加v
        // 不用递归实现先序遍历，容易爆栈，所以用迭代实现先序遍历
        // 读写工具类
*/

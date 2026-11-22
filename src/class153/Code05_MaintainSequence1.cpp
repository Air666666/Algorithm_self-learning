// Source: src/class153/Code05_MaintainSequence1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code05_MaintainSequence1 {
  inline static int MAXN = 500005;
  inline static int INF = 1000000001;
  inline static int head = 0;
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static Array<int> num = make_array<int>(MAXN);
  inline static Array<int> father = make_array<int>(MAXN);
  inline static Array<int> left = make_array<int>(MAXN);
  inline static Array<int> right = make_array<int>(MAXN);
  inline static Array<int> size = make_array<int>(MAXN);
  inline static Array<int> space = make_array<int>(MAXN);
  inline static int si = {};
  inline static Array<int> sum = make_array<int>(MAXN);
  inline static Array<int> all = make_array<int>(MAXN);
  inline static Array<int> pre = make_array<int>(MAXN);
  inline static Array<int> suf = make_array<int>(MAXN);
  inline static Array<bool> update = make_array<bool>(MAXN);
  inline static Array<int> change = make_array<int>(MAXN);
  inline static Array<bool> reverse = make_array<bool>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code05_MaintainSequence1() {}
  static void up(int i) {
    int l = left[i];
    int r = right[i];
    (size[i] = ((size[l] + size[r]) + 1));
    (sum[i] = ((sum[l] + sum[r]) + num[i]));
    (all[i] = jmax(jmax(all[l], all[r]), ((suf[l] + num[i]) + pre[r])));
    (pre[i] = jmax(pre[l], ((sum[l] + num[i]) + pre[r])));
    (suf[i] = jmax(suf[r], ((suf[l] + num[i]) + sum[r])));
  }
  static int lr(int i) { return ((right[father[i]] == i) ? 1 : 0); }
  static void rotate(int i) {
    int f = father[i];
    int g = father[f];
    int soni = Code05_MaintainSequence1::lr(i);
    int sonf = Code05_MaintainSequence1::lr(f);
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
    Code05_MaintainSequence1::up(f);
    Code05_MaintainSequence1::up(i);
  }
  static void splay(int i, int goal) {
    int f = father[i];
    int g = father[f];
    while ((f != goal)) {
      if ((g != goal)) {
        if ([&]() {
              auto jleft = Code05_MaintainSequence1::lr(i);
              auto jright = Code05_MaintainSequence1::lr(f);
              return (jleft == jright);
            }()) {
          Code05_MaintainSequence1::rotate(f);
        } else {
          Code05_MaintainSequence1::rotate(i);
        }
      }
      Code05_MaintainSequence1::rotate(i);
      (f = father[i]);
      (g = father[f]);
    }
    if ((goal == 0)) {
      (head = i);
    }
  }
  static void setValue(int i, int val) {
    if ((i != 0)) {
      (update[i] = true);
      (change[i] = val);
      (num[i] = val);
      (sum[i] = (size[i] * val));
      (all[i] = jmax(sum[i], val));
      (pre[i] = jmax(sum[i], 0));
      (suf[i] = jmax(sum[i], 0));
    }
  }
  static void setReverse(int i) {
    if ((i != 0)) {
      int tmp = pre[i];
      (pre[i] = suf[i]);
      (suf[i] = tmp);
      (reverse[i] = (!reverse[i]));
    }
  }
  static void down(int i) {
    if (update[i]) {
      Code05_MaintainSequence1::setValue(left[i], change[i]);
      Code05_MaintainSequence1::setValue(right[i], change[i]);
      (update[i] = false);
    }
    if (reverse[i]) {
      int tmp = left[i];
      (left[i] = right[i]);
      (right[i] = tmp);
      Code05_MaintainSequence1::setReverse(left[i]);
      Code05_MaintainSequence1::setReverse(right[i]);
      (reverse[i] = false);
    }
  }
  static int init(int val) {
    int i = space[(si--)];
    (size[i] = 1);
    (num[i] = (sum[i] = (all[i] = val)));
    (pre[i] = (suf[i] = jmax(val, 0)));
    (father[i] = (left[i] = (right[i] = 0)));
    (update[i] = (reverse[i] = false));
    return i;
  }
  static int build(int l, int r) {
    int mid = jdiv((l + r), 2);
    int root = Code05_MaintainSequence1::init(arr[mid]);
    if ((l < mid)) {
      (left[root] = Code05_MaintainSequence1::build(l, (mid - 1)));
      (father[left[root]] = root);
    }
    if ((mid < r)) {
      (right[root] = Code05_MaintainSequence1::build((mid + 1), r));
      (father[right[root]] = root);
    }
    Code05_MaintainSequence1::up(root);
    return root;
  }
  static int find(int rank) {
    int i = head;
    while ((i != 0)) {
      Code05_MaintainSequence1::down(i);
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
  static void insert(int rank, int n) {
    if ((rank == 0)) {
      (head = Code05_MaintainSequence1::build(1, n));
    } else {
      int l = Code05_MaintainSequence1::find(rank);
      int r = Code05_MaintainSequence1::find((rank + 1));
      Code05_MaintainSequence1::splay(l, 0);
      Code05_MaintainSequence1::splay(r, l);
      (left[r] = Code05_MaintainSequence1::build(1, n));
      (father[left[r]] = r);
      Code05_MaintainSequence1::up(r);
      Code05_MaintainSequence1::up(l);
    }
  }
  static void recycle(int i) {
    if ((i != 0)) {
      (space[(++si)] = i);
      Code05_MaintainSequence1::recycle(left[i]);
      Code05_MaintainSequence1::recycle(right[i]);
    }
  }
  static void delete_method(int rank, int n) {
    int l = Code05_MaintainSequence1::find((rank - 1));
    int r = Code05_MaintainSequence1::find((rank + n));
    Code05_MaintainSequence1::splay(l, 0);
    Code05_MaintainSequence1::splay(r, l);
    Code05_MaintainSequence1::recycle(left[r]);
    (left[r] = 0);
    Code05_MaintainSequence1::up(r);
    Code05_MaintainSequence1::up(l);
  }
  static void reset(int rank, int n, int val) {
    int l = Code05_MaintainSequence1::find((rank - 1));
    int r = Code05_MaintainSequence1::find((rank + n));
    Code05_MaintainSequence1::splay(l, 0);
    Code05_MaintainSequence1::splay(r, l);
    Code05_MaintainSequence1::setValue(left[r], val);
    Code05_MaintainSequence1::up(r);
    Code05_MaintainSequence1::up(l);
  }
  static void reverse_method(int rank, int n) {
    int l = Code05_MaintainSequence1::find((rank - 1));
    int r = Code05_MaintainSequence1::find((rank + n));
    Code05_MaintainSequence1::splay(l, 0);
    Code05_MaintainSequence1::splay(r, l);
    Code05_MaintainSequence1::setReverse(left[r]);
    Code05_MaintainSequence1::up(r);
    Code05_MaintainSequence1::up(l);
  }
  static int querySum(int rank, int n) {
    int l = Code05_MaintainSequence1::find((rank - 1));
    int r = Code05_MaintainSequence1::find((rank + n));
    Code05_MaintainSequence1::splay(l, 0);
    Code05_MaintainSequence1::splay(r, l);
    return sum[left[r]];
  }
  static int queryMax() { return all[head]; }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(jout);
    int n = in.readInt();
    int m = in.readInt();
    (si = (MAXN - 1));
    for (int i = 1; (i <= si); (i++)) {
      (space[i] = i);
    }
    (arr[1] = (arr[(n + 2)] = (all[0] = (-INF))));
    {
      int i = 1;
      int j = 2;
      for (; (i <= n); (i++), (j++)) {
        (arr[j] = in.readInt());
      }
    }
    Code05_MaintainSequence1::insert(0, (n + 2));
    String op = {};
    {
      int i = 1;
      int posi = {};
      int tot = {};
      int c = {};
      for (; (i <= m); (i++)) {
        (op = in.readString());
        if (op.equals(String(u"MAX-SUM"))) {
          out.println(Code05_MaintainSequence1::queryMax());
        } else {
          (posi = (in.readInt() + 1));
          (tot = in.readInt());
          if (op.equals(String(u"INSERT"))) {
            for (int j = 1; (j <= tot); (j++)) {
              (arr[j] = in.readInt());
            }
            Code05_MaintainSequence1::insert(posi, tot);
          } else if (op.equals(String(u"DELETE"))) {
            Code05_MaintainSequence1::delete_method(posi, tot);
          } else if (op.equals(String(u"MAKE-SAME"))) {
            (c = in.readInt());
            Code05_MaintainSequence1::reset(posi, tot, c);
          } else if (op.equals(String(u"REVERSE"))) {
            Code05_MaintainSequence1::reverse_method(posi, tot);
          } else {
            out.println(Code05_MaintainSequence1::querySum(posi, tot));
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
  Code05_MaintainSequence1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 维护数列(java版)
// 初始时给定一个数列，实现如下六种操作
// INSERT posi tot ...  : 在第posi个数字之后，插入长度为tot的数组，由...代表
// DELETE posi tot      : 从第posi个数字开始，删除长度为tot的部分
// MAKE-SAME posi tot c : 从第posi个数字开始，长度为tot的部分，值都设置成c
// REVERSE posi tot     : 从第posi个数字开始，翻转长度为tot的部分
// GET-SUM posi tot     : 从第posi个数字开始，查询长度为tot的部分的累加和
// MAX-SUM              : 查询整个数列中，非空子数组的最大累加和
// 任何时刻输入保证至少有一个数字在数列中，并且所有操作都合法
// 插入数字总数很多，但是任何时刻数列中最多有5 *
10^5个数，使用总空间要和该数量有关
// 测试链接 : https://www.luogu.com.cn/problem/P2042
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 这个数组里拿空间编号
        // 维护区间累加和信息
        // 维护区间子数组最大累加和信息，要求不能为空
        // 维护区间前缀最大累加和信息，可以空
        // 维护区间后缀最大累加和信息，可以空
        // 懒更新信息，区间是否重新设了值
        // 懒更新信息，如果区间重新设了值，设置成了什么
        // 懒更新信息，区间是否发生了翻转
                // 所有可用空间编号，进入space数组
                // 这里很重要，一方面准备好最左和最右的准备值
                // 另一方面设置all[0] = 极小值
                // 表示没有范围时，子数组最大累加和为极小值，因为不能为空
                // 建立初始树
                                // 因为有最左的准备值，所以位置要后移一位
        // 快读
        // 快写
*/

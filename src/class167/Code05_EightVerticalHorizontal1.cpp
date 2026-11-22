// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P3733

// Source: src/class167/Code05_EightVerticalHorizontal1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code05_EightVerticalHorizontal1 {
  struct BitSet;
  struct BitSet {
    int len = {};
    Array<int> arr = {};
    String toString() const { return j::str(static_cast<const void *>(this)); }
    BitSet() {
      (len = (jdiv(BIT, INT_BIT) + 1));
      (arr = make_array<int>(len));
    }
    BitSet(String s) {
      (len = (jdiv(BIT, INT_BIT) + 1));
      (arr = make_array<int>(len));
      {
        int i = 0;
        int j = (s.length() - 1);
        for (; (i < s.length()); (i++), (j--)) {
          BitSet::set(i, (s.charAt(j) - u'0'));
        }
      }
    }
    int get(int i) {
      return (jshr(arr[jdiv(i, INT_BIT)], jrem(i, INT_BIT)) & 1);
    }
    void set(int i, int v) {
      if ((v == 0)) {
        (arr[jdiv(i, INT_BIT)] &= (~jshl(1, jrem(i, INT_BIT))));
      } else {
        (arr[jdiv(i, INT_BIT)] |= jshl(1, jrem(i, INT_BIT)));
      }
    }
    void eor(BitSet *other) {
      for (int i = 0; (i < len); (i++)) {
        (arr[i] ^= other->arr[i]);
      }
    }
    void clear() {
      for (int i = 0; (i < len); (i++)) {
        (arr[i] = 0);
      }
    }
  };
  inline static int MAXN = 501;
  inline static int MAXQ = 1001;
  inline static int MAXT = 10001;
  inline static int BIT = 999;
  inline static int INT_BIT = 32;
  inline static int n = {};
  inline static int m = {};
  inline static int q = {};
  inline static Array<int> x = make_array<int>(MAXQ);
  inline static Array<int> y = make_array<int>(MAXQ);
  inline static Array<BitSet *> w = make_array<BitSet *>(MAXQ);
  inline static int edgeCnt = 0;
  inline static Array<int> last = make_array<int>(MAXQ);
  inline static Array<BitSet *> basis = make_array<BitSet *>((BIT + 1));
  inline static Array<int> inspos = make_array<int>((BIT + 1));
  inline static int basiz = 0;
  inline static Array<int> father = make_array<int>(MAXN);
  inline static Array<BitSet *> eor = make_array<BitSet *>(MAXN);
  inline static Array<int> head = make_array<int>(jshl(MAXQ, 2));
  inline static Array<int> next = make_array<int>(MAXT);
  inline static Array<int> tox = make_array<int>(MAXT);
  inline static Array<int> toy = make_array<int>(MAXT);
  inline static Array<BitSet *> tow = make_array<BitSet *>(MAXT);
  inline static int cnt = 0;
  inline static Array<BitSet *> ans = make_array<BitSet *>(MAXQ);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code05_EightVerticalHorizontal1() {}
  static void insert(BitSet *num) {
    for (int i = BIT; (i >= 0); (i--)) {
      if ((num->get(i) == 1)) {
        if ((basis[i]->get(i) == 0)) {
          (basis[i] = num);
          (inspos[(basiz++)] = i);
          return;
        }
        num->eor(basis[i]);
      }
    }
  }
  static BitSet *maxEor() {
    BitSet *ans = new BitSet();
    for (int i = BIT; (i >= 0); (i--)) {
      if (((ans->get(i) == 0) && (basis[i]->get(i) == 1))) {
        ans->eor(basis[i]);
      }
    }
    return ans;
  }
  static void cancel(int oldsiz) {
    while ((basiz > oldsiz)) {
      basis[inspos[(--basiz)]]->clear();
    }
  }
  static int find(int i) {
    if ((i != father[i])) {
      int tmp = father[i];
      (father[i] = Code05_EightVerticalHorizontal1::find(tmp));
      eor[i]->eor(eor[tmp]);
    }
    return father[i];
  }
  static BitSet *getEor(int i) {
    Code05_EightVerticalHorizontal1::find(i);
    return eor[i];
  }
  static void union_method(int u, int v, BitSet *w) {
    int fu = Code05_EightVerticalHorizontal1::find(u);
    int fv = Code05_EightVerticalHorizontal1::find(v);
    BitSet *weight = new BitSet();
    weight->eor(Code05_EightVerticalHorizontal1::getEor(u));
    weight->eor(Code05_EightVerticalHorizontal1::getEor(v));
    weight->eor(w);
    if ((fu == fv)) {
      Code05_EightVerticalHorizontal1::insert(weight);
    } else {
      (father[fv] = fu);
      (eor[fv] = weight);
    }
  }
  static void addEdge(int i, int x, int y, BitSet *w) {
    (next[(++cnt)] = head[i]);
    (tox[cnt] = x);
    (toy[cnt] = y);
    (tow[cnt] = w);
    (head[i] = cnt);
  }
  static void add(int jobl, int jobr, int jobx, int joby, BitSet *jobw, int l,
                  int r, int i) {
    if (((jobl <= l) && (r <= jobr))) {
      Code05_EightVerticalHorizontal1::addEdge(i, jobx, joby, jobw);
    } else {
      int mid = jshr((l + r), 1);
      if ((jobl <= mid)) {
        Code05_EightVerticalHorizontal1::add(jobl, jobr, jobx, joby, jobw, l,
                                             mid, jshl(i, 1));
      }
      if ((jobr > mid)) {
        Code05_EightVerticalHorizontal1::add(jobl, jobr, jobx, joby, jobw,
                                             (mid + 1), r, (jshl(i, 1) | 1));
      }
    }
  }
  static void dfs(int l, int r, int i) {
    int oldsiz = basiz;
    for (int e = head[i]; (e > 0); (e = next[e])) {
      Code05_EightVerticalHorizontal1::union_method(tox[e], toy[e], tow[e]);
    }
    if ((l == r)) {
      (ans[l] = Code05_EightVerticalHorizontal1::maxEor());
    } else {
      int mid = jdiv((l + r), 2);
      Code05_EightVerticalHorizontal1::dfs(l, mid, jshl(i, 1));
      Code05_EightVerticalHorizontal1::dfs((mid + 1), r, (jshl(i, 1) | 1));
    }
    Code05_EightVerticalHorizontal1::cancel(oldsiz);
  }
  static void print(BitSet *bs, IO out) {
    bool flag = false;
    {
      int i = BIT;
      int s = {};
      for (; (i >= 0); (i--)) {
        (s = bs->get(i));
        if ((s == 1)) {
          (flag = true);
        }
        if (flag) {
          out.print(s);
        }
      }
    }
    if ((!flag)) {
      out.print(0);
    }
    out.println();
  }
  static void java_main(Array<String> args) {
    IO in = IO();
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (m = in.nextInt());
    (q = in.nextInt());
    for (int i = 0; (i <= BIT); (i++)) {
      (basis[i] = new BitSet());
    }
    for (int i = 1; (i <= n); (i++)) {
      (father[i] = i);
      (eor[i] = new BitSet());
    }
    for (int i = 1; (i <= m); (i++)) {
      int u = in.nextInt();
      int v = in.nextInt();
      BitSet *w = new BitSet(in.nextString());
      Code05_EightVerticalHorizontal1::union_method(u, v, w);
    }
    (ans[0] = Code05_EightVerticalHorizontal1::maxEor());
    String op = {};
    for (int i = 1; (i <= q); (i++)) {
      (op = in.nextString());
      if (op.equals(String(u"Add"))) {
        (edgeCnt++);
        (x[edgeCnt] = in.nextInt());
        (y[edgeCnt] = in.nextInt());
        (w[edgeCnt] = new BitSet(in.nextString()));
        (last[edgeCnt] = i);
      } else if (op.equals(String(u"Cancel"))) {
        int k = in.nextInt();
        Code05_EightVerticalHorizontal1::add(last[k], (i - 1), x[k], y[k], w[k],
                                             1, q, 1);
        (last[k] = 0);
      } else {
        int k = in.nextInt();
        Code05_EightVerticalHorizontal1::add(last[k], (i - 1), x[k], y[k], w[k],
                                             1, q, 1);
        (w[k] = new BitSet(in.nextString()));
        (last[k] = i);
      }
    }
    for (int i = 1; (i <= edgeCnt); (i++)) {
      if ((last[i] != 0)) {
        Code05_EightVerticalHorizontal1::add(last[i], q, x[i], y[i], w[i], 1, q,
                                             1);
      }
    }
    if ((q > 0)) {
      Code05_EightVerticalHorizontal1::dfs(1, q, 1);
    }
    for (int i = 0; (i <= q); (i++)) {
      Code05_EightVerticalHorizontal1::print(ans[i], out);
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code05_EightVerticalHorizontal1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 八纵八横，java版
// 一共有n个点，给定m条边，每条边的边权，用01字符串表达，初始时就保证图连通
// 初始的m条边永不删除，接下来有q条操作，每种操作是如下三种类型中的一种
// 操作 Add x y z  :
加入点x到点y的边，边权是z，z为01字符串，第k条添加操作，边的编号为k
// 操作 Cancel k   : 删除编号为k的边
// 操作 Change k z : 编号为k的边，边权修改成z，z为01字符串
// 从1号点出发，最后回到1号点，边随便走，沿途所有边的边权异或起来
//
打印只有初始m条边的情况下，异或最大值为多少，每一条操作结束后，都打印异或最大值为多少
// 1 <= n、m <= 500    0 <= q <= 1000    1 <= 边权字符串长度 <= 1000
// 测试链接 : https://www.luogu.com.cn/problem/P3733
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 位图
                // 返回第i位的状态
                // 设置第i位的状态
                // 异或other每一位
                // 清空每一位
        // 可撤销线性基
        // 经典带权并查集，只做扁平化，不做小挂大
        // 时间轴线段树上的区间任务列表
        // 每一步的最大异或值
        // num插入线性基
        // 0这个数字结合线性基，得到的最大异或值返回
        // 线性基的撤销
        // 扁平化优化，find的同时修改eor，就是经典的带权并查集
        // 读写工具类
*/

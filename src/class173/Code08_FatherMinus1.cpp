// Source: src/class173/Code08_FatherMinus1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code08_FatherMinus1 {
  inline static int MAXN = 100001;
  inline static int MAXB = 501;
  inline static int n = {};
  inline static int m = {};
  inline static Array<int> fa = make_array<int>(MAXN);
  inline static Array<int> out = make_array<int>(MAXN);
  inline static int blen = {};
  inline static int bnum = {};
  inline static Array<int> bi = make_array<int>(MAXN);
  inline static Array<int> bl = make_array<int>(MAXB);
  inline static Array<int> br = make_array<int>(MAXB);
  inline static Array<int> lazy = make_array<int>(MAXB);
  inline static Array<int> minusCnt = make_array<int>(MAXB);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code08_FatherMinus1() {}
  static void innerUpdate(int b) {
    for (int i = bl[b]; (i <= br[b]); (i++)) {
      (fa[i] = jmax(1, (fa[i] - lazy[b])));
    }
    (lazy[b] = 0);
    for (int i = bl[b]; (i <= br[b]); (i++)) {
      if ((fa[i] < bl[b])) {
        (out[i] = fa[i]);
      } else {
        (out[i] = out[fa[i]]);
      }
    }
  }
  static void update(int l, int r, int v) {
    if ((bi[l] == bi[r])) {
      for (int i = l; (i <= r); (i++)) {
        (fa[i] = jmax(1, (fa[i] - v)));
      }
      Code08_FatherMinus1::innerUpdate(bi[l]);
    } else {
      for (int i = l; (i <= br[bi[l]]); (i++)) {
        (fa[i] = jmax(1, (fa[i] - v)));
      }
      Code08_FatherMinus1::innerUpdate(bi[l]);
      for (int i = bl[bi[r]]; (i <= r); (i++)) {
        (fa[i] = jmax(1, (fa[i] - v)));
      }
      Code08_FatherMinus1::innerUpdate(bi[r]);
      for (int b = (bi[l] + 1); (b <= (bi[r] - 1)); (b++)) {
        (lazy[b] = jmin(n, (lazy[b] + v)));
        if (((++minusCnt[b]) <= blen)) {
          Code08_FatherMinus1::innerUpdate(b);
        }
      }
    }
  }
  static int jumpFa(int i) { return jmax(1, (fa[i] - lazy[bi[i]])); }
  static int jumpOut(int i) { return jmax(1, (out[i] - lazy[bi[i]])); }
  static int lca(int x, int y) {
    while (((bi[x] != bi[y]) || [&]() {
      auto jleft = Code08_FatherMinus1::jumpOut(x);
      auto jright = Code08_FatherMinus1::jumpOut(y);
      return (jleft != jright);
    }())) {
      if ((bi[x] != bi[y])) {
        if ((bi[x] < bi[y])) {
          int tmp = x;
          (x = y);
          (y = tmp);
        }
        (x = Code08_FatherMinus1::jumpOut(x));
      } else {
        (x = Code08_FatherMinus1::jumpOut(x));
        (y = Code08_FatherMinus1::jumpOut(y));
      }
    }
    while ((x != y)) {
      if ((x < y)) {
        int tmp = x;
        (x = y);
        (y = tmp);
      }
      (x = Code08_FatherMinus1::jumpFa(x));
    }
    return x;
  }
  static void prepare() {
    (blen = static_cast<int>(std::sqrt(n)));
    (bnum = jdiv(((n + blen) - 1), blen));
    for (int i = 1; (i <= n); (i++)) {
      (bi[i] = (jdiv((i - 1), blen) + 1));
    }
    for (int i = 1; (i <= bnum); (i++)) {
      (bl[i] = (((i - 1) * blen) + 1));
      (br[i] = jmin((i * blen), n));
      Code08_FatherMinus1::innerUpdate(i);
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (m = in.nextInt());
    for (int i = 2; (i <= n); (i++)) {
      (fa[i] = in.nextInt());
    }
    Code08_FatherMinus1::prepare();
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
        if ((op == 1)) {
          (z = in.nextInt());
          Code08_FatherMinus1::update(x, y, z);
        } else {
          out.println(Code08_FatherMinus1::lca(x, y));
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
  Code08_FatherMinus1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 区间父变小，java版
// 一棵大小为n树，节点1是树头，给定fa[2..n]表示父亲节点编号
// 对于每个i > 1，都有fa[i] < i，下来有m条操作，操作类型如下
// 操作 1 x y z : [x..y]范围上任何一点i，fa[i] = max(1, fa[i] - z)
// 操作 2 x y   : 查询点x和点y的最低公共祖先
// 2 <= n、m <= 10^5
// 测试链接 : https://www.luogu.com.cn/problem/CF1491H
// 测试链接 : https://codeforces.com/problemset/problem/1491/H
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 节点的父亲节点
        // 节点如果从所在块出去，会去往的最近节点
        // 块内所有节点的父亲编号，统一减少的幅度
        // 块内所有节点的父亲编号，统一削减的次数
                                // 减少的幅度最多到n，不会更大
                                // 这样还可以让lazy保持int类型并且不溢出
        // 读写工具类
*/

// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P2801

// Source: src/class172/Code02_Magic1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_Magic1 {
  inline static int MAXN = 1000001;
  inline static int MAXB = 1001;
  inline static int n = {};
  inline static int m = {};
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static Array<int> sortv = make_array<int>(MAXN);
  inline static int blen = {};
  inline static int bnum = {};
  inline static Array<int> bi = make_array<int>(MAXN);
  inline static Array<int> bl = make_array<int>(MAXB);
  inline static Array<int> br = make_array<int>(MAXB);
  inline static Array<int> lazy = make_array<int>(MAXB);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_Magic1() {}
  static void build() {
    (blen = static_cast<int>(std::sqrt(n)));
    (bnum = jdiv(((n + blen) - 1), blen));
    for (int i = 1; (i <= n); (i++)) {
      (bi[i] = (jdiv((i - 1), blen) + 1));
    }
    for (int i = 1; (i <= bnum); (i++)) {
      (bl[i] = (((i - 1) * blen) + 1));
      (br[i] = jmin((i * blen), n));
    }
    for (int i = 1; (i <= n); (i++)) {
      (sortv[i] = arr[i]);
    }
    for (int i = 1; (i <= bnum); (i++)) {
      j::sort(sortv, bl[i], (br[i] + 1));
    }
  }
  static int getCnt(int i, int v) {
    (v -= lazy[i]);
    int l = bl[i];
    int r = br[i];
    int m = {};
    int ans = 0;
    while ((l <= r)) {
      (m = jshr((l + r), 1));
      if ((sortv[m] >= v)) {
        (ans += ((r - m) + 1));
        (r = (m - 1));
      } else {
        (l = (m + 1));
      }
    }
    return ans;
  }
  static int innerQuery(int l, int r, int v) {
    (v -= lazy[bi[l]]);
    int ans = 0;
    for (int i = l; (i <= r); (i++)) {
      if ((arr[i] >= v)) {
        (ans++);
      }
    }
    return ans;
  }
  static int query(int l, int r, int v) {
    int ans = 0;
    if ((bi[l] == bi[r])) {
      (ans = Code02_Magic1::innerQuery(l, r, v));
    } else {
      (ans += Code02_Magic1::innerQuery(l, br[bi[l]], v));
      (ans += Code02_Magic1::innerQuery(bl[bi[r]], r, v));
      for (int i = (bi[l] + 1); (i <= (bi[r] - 1)); (i++)) {
        (ans += Code02_Magic1::getCnt(i, v));
      }
    }
    return ans;
  }
  static void innerAdd(int l, int r, int v) {
    for (int i = l; (i <= r); (i++)) {
      (arr[i] += v);
    }
    for (int i = bl[bi[l]]; (i <= br[bi[l]]); (i++)) {
      (sortv[i] = arr[i]);
    }
    j::sort(sortv, bl[bi[l]], (br[bi[l]] + 1));
  }
  static void add(int l, int r, int v) {
    if ((bi[l] == bi[r])) {
      Code02_Magic1::innerAdd(l, r, v);
    } else {
      Code02_Magic1::innerAdd(l, br[bi[l]], v);
      Code02_Magic1::innerAdd(bl[bi[r]], r, v);
      for (int i = (bi[l] + 1); (i <= (bi[r] - 1)); (i++)) {
        (lazy[i] += v);
      }
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO();
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (m = in.nextInt());
    for (int i = 1; (i <= n); (i++)) {
      (arr[i] = in.nextInt());
    }
    Code02_Magic1::build();
    jchar op = {};
    int l = {};
    int r = {};
    int v = {};
    for (int i = 1; (i <= m); (i++)) {
      (op = in.nextChar());
      (l = in.nextInt());
      (r = in.nextInt());
      (v = in.nextInt());
      if ((op == u'A')) {
        out.println(Code02_Magic1::query(l, r, v));
      } else {
        Code02_Magic1::add(l, r, v);
      }
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code02_Magic1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 教主的魔法，java版
// 给定一个长度为n的数组arr，接下来有m条操作，每条操作是如下两种类型中的一种
// 操作 A l r v : 打印arr[l..r]范围上>=v的数字个数
// 操作 M l r v : 把arr[l..r]范围上每个值都加上v
// 1 <= n <= 10^6
// 1 <= m <= 3000
// 1 <= 数组中的值 <= 10^9
// 测试链接 : https://www.luogu.com.cn/problem/P2801
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 读写工具类
*/

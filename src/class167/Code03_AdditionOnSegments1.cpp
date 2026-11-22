// Source: src/class167/Code03_AdditionOnSegments1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_AdditionOnSegments1 {
  inline static int MAXN = 10001;
  inline static int MAXT = 500001;
  inline static int BIT = 10000;
  inline static int DEEP = 20;
  inline static int INT_BIT = 32;
  inline static int LEN = (jdiv(BIT, INT_BIT) + 1);
  inline static int n = {};
  inline static int q = {};
  inline static Array<int> head = make_array<int>(jshl(MAXN, 2));
  inline static Array<int> next = make_array<int>(MAXT);
  inline static Array<int> to = make_array<int>(MAXT);
  inline static int cnt = 0;
  inline static Array<int> tmp = make_array<int>(LEN);
  inline static Array<int> dp = make_array<int>(LEN);
  inline static Array<Array<int>> backup = make_array<int>(DEEP, LEN);
  inline static Array<int> ans = make_array<int>(LEN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_AdditionOnSegments1() {}
  static void clear(Array<int> bitset) {
    for (int i = 0; (i < LEN); (i++)) {
      (bitset[i] = 0);
    }
  }
  static void clone(Array<int> set1, Array<int> set2) {
    for (int i = 0; (i < LEN); (i++)) {
      (set1[i] = set2[i]);
    }
  }
  static int getBit(Array<int> bitset, int i) {
    return (jshr(bitset[jdiv(i, INT_BIT)], jrem(i, INT_BIT)) & 1);
  }
  static void setBit(Array<int> bitset, int i, int v) {
    if ((v == 0)) {
      (bitset[jdiv(i, INT_BIT)] &= (~jshl(1, jrem(i, INT_BIT))));
    } else {
      (bitset[jdiv(i, INT_BIT)] |= jshl(1, jrem(i, INT_BIT)));
    }
  }
  static void bitOr(Array<int> set1, Array<int> set2) {
    for (int i = 0; (i < LEN); (i++)) {
      (set1[i] |= set2[i]);
    }
  }
  static void bitLeft(Array<int> ret, Array<int> bitset, int move) {
    Code03_AdditionOnSegments1::clear(ret);
    if ((move > BIT)) {
      return;
    }
    if ((move <= 0)) {
      Code03_AdditionOnSegments1::clone(ret, bitset);
      return;
    }
    int shift = jdiv(move, INT_BIT);
    int offset = jrem(move, INT_BIT);
    if ((offset == 0)) {
      {
        int i = (LEN - 1);
        int j = (i - shift);
        for (; (j >= 0); (i--), (j--)) {
          (ret[i] = bitset[j]);
        }
      }
    } else {
      int carry = (INT_BIT - offset);
      int high = {};
      int low = {};
      for (int i = (LEN - 1); (i > shift); (i--)) {
        (high = jshl(bitset[(i - shift)], offset));
        (low = jushr(bitset[((i - shift) - 1)], carry));
        (ret[i] = (high | low));
      }
      (ret[shift] = jshl(bitset[0], offset));
    }
    int rest = ((LEN * INT_BIT) - (BIT + 1));
    if ((rest > 0)) {
      (ret[(LEN - 1)] &= (jshl(1, (INT_BIT - rest)) - 1));
    }
  }
  static void addEdge(int i, int v) {
    (next[(++cnt)] = head[i]);
    (to[cnt] = v);
    (head[i] = cnt);
  }
  static void add(int jobl, int jobr, int jobv, int l, int r, int i) {
    if (((jobl <= l) && (r <= jobr))) {
      Code03_AdditionOnSegments1::addEdge(i, jobv);
    } else {
      int mid = jshr((l + r), 1);
      if ((jobl <= mid)) {
        Code03_AdditionOnSegments1::add(jobl, jobr, jobv, l, mid, jshl(i, 1));
      }
      if ((jobr > mid)) {
        Code03_AdditionOnSegments1::add(jobl, jobr, jobv, (mid + 1), r,
                                        (jshl(i, 1) | 1));
      }
    }
  }
  static void dfs(int l, int r, int i, int dep) {
    Code03_AdditionOnSegments1::clone(backup[dep], dp);
    for (int e = head[i]; (e > 0); (e = next[e])) {
      Code03_AdditionOnSegments1::bitLeft(tmp, dp, to[e]);
      Code03_AdditionOnSegments1::bitOr(dp, tmp);
    }
    if ((l == r)) {
      Code03_AdditionOnSegments1::bitOr(ans, dp);
    } else {
      int mid = jshr((l + r), 1);
      Code03_AdditionOnSegments1::dfs(l, mid, jshl(i, 1), (dep + 1));
      Code03_AdditionOnSegments1::dfs((mid + 1), r, (jshl(i, 1) | 1),
                                      (dep + 1));
    }
    Code03_AdditionOnSegments1::clone(dp, backup[dep]);
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (q = in.nextInt());
    {
      int i = 1;
      int l = {};
      int r = {};
      int k = {};
      for (; (i <= q); (i++)) {
        (l = in.nextInt());
        (r = in.nextInt());
        (k = in.nextInt());
        Code03_AdditionOnSegments1::add(l, r, k, 1, n, 1);
      }
    }
    Code03_AdditionOnSegments1::setBit(dp, 0, 1);
    Code03_AdditionOnSegments1::dfs(1, n, 1, 1);
    int ansCnt = 0;
    for (int i = 1; (i <= n); (i++)) {
      if ((Code03_AdditionOnSegments1::getBit(ans, i) == 1)) {
        (ansCnt++);
      }
    }
    out.println(ansCnt);
    for (int i = 1; (i <= n); (i++)) {
      if ((Code03_AdditionOnSegments1::getBit(ans, i) == 1)) {
        out.print((i + String(u" ")));
      }
    }
    out.println();
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code03_AdditionOnSegments1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 打印所有合法数，java版
// 一个长度为n的序列，一开始所有值都是0
// 一共有q条操作，每条操作为 l r k : 序列[l..r]范围上，每个数字加k
// 你可以随意选择操作来执行，但是每条操作只能执行一次
// 如果你能让序列中的最大值正好为v，那么v就算一个合法数
// 打印1~n范围内有多少合法数，并且从小到大打印所有的合法数
// 1 <= k <= n、q <= 10^4
// 测试链接 : https://www.luogu.com.cn/problem/CF981E
// 测试链接 : https://codeforces.com/problemset/problem/981/E
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 清空
        // 位图set1 拷贝 位图set2
        // 返回位图第i位的状态
        // 第i位的状态设置成v
        // 位图set1 或 位图set2
        // 位图ret 变成 位图bitset左移move位的状态
        // 不使用一位一位拷贝的方式，因为太慢了
        // 采用整块左移的方式，这样比较快
                // 最高位BIT到最低位0，一共BIT+1个有效位
                // 其他更高位信息需要清空，rest就是有多少无效的更高位
        // 读写工具类
*/

// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P5355

// Source: src/class179/Code08_YnoiCornfield1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code08_YnoiCornfield1 {
  struct BitSet;
  struct QueryCmp;
  struct BitSet {
    int len = {};
    Array<i64> status = {};
    String toString() const { return j::str(static_cast<const void *>(this)); }
    BitSet(int siz) {
      (len = jshr((siz + 63), 6));
      (status = make_array<i64>(len));
    }
    void setOne(int bit) { (status[jshr(bit, 6)] |= jshl(1LL, (bit & 63))); }
    void setZero(int bit) {
      (status[jshr(bit, 6)] &= (~jshl(1LL, (bit & 63))));
    }
    bool getStatus(int bit) {
      return ((jshr(status[jshr(bit, 6)], (bit & 63)) & 1LL) != 0LL);
    }
    bool andOtherMoveRight(BitSet *other, int move) {
      int ws = jshr(move, 6);
      int bs = (move & 63);
      for (int i = 0; (i < len); (i++)) {
        int src = (i + ws);
        if ((src >= len)) {
          break;
        }
        i64 shifted = jushr(other->status[src], bs);
        if (((bs != 0) && ((src + 1) < len))) {
          (shifted |= jshl(other->status[(src + 1)], (64 - bs)));
        }
        if (((status[i] & shifted) != 0LL)) {
          return true;
        }
      }
      return false;
    }
  };
  struct QueryCmp {
    String toString() const { return j::str(static_cast<const void *>(this)); }
    QueryCmp() {}
    int compare(Array<int> a, Array<int> b) {
      if ((bi[a[0]] != bi[b[0]])) {
        return (bi[a[0]] - bi[b[0]]);
      }
      if (((bi[a[0]] & 1) == 1)) {
        return (a[1] - b[1]);
      } else {
        return (b[1] - a[1]);
      }
    }
  };
  inline static int MAXN = 100001;
  inline static int MAXV = 100000;
  inline static int MAXB = 401;
  inline static int n = {};
  inline static int m = {};
  inline static int blen = {};
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static Array<int> bi = make_array<int>(MAXN);
  inline static Array<Array<int>> query = make_array<int>(MAXN, 5);
  inline static int cntq = {};
  inline static Array<int> headq = make_array<int>(MAXB);
  inline static Array<int> nextq = make_array<int>(MAXN);
  inline static Array<int> ql = make_array<int>(MAXN);
  inline static Array<int> qr = make_array<int>(MAXN);
  inline static Array<int> qid = make_array<int>(MAXN);
  inline static int cnts = {};
  inline static Array<int> cnt = make_array<int>(MAXN);
  inline static BitSet *bitSet1 = new BitSet(MAXN);
  inline static BitSet *bitSet2 = new BitSet(MAXN);
  inline static Array<int> pre = make_array<int>(MAXN);
  inline static Array<int> dp = make_array<int>(MAXN);
  inline static Array<bool> ans = make_array<bool>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code08_YnoiCornfield1() {}
  static void addSpecial(int x, int l, int r, int id) {
    (nextq[(++cnts)] = headq[x]);
    (headq[x] = cnts);
    (ql[cnts] = l);
    (qr[cnts] = r);
    (qid[cnts] = id);
  }
  static void add(int x) {
    (cnt[x]++);
    if ((cnt[x] == 1)) {
      bitSet1->setOne(x);
      bitSet2->setOne((MAXV - x));
    }
  }
  static void del(int x) {
    (cnt[x]--);
    if ((cnt[x] == 0)) {
      bitSet1->setZero(x);
      bitSet2->setZero((MAXV - x));
    }
  }
  static bool calc(int op, int x) {
    if ((op == 1)) {
      return bitSet1->andOtherMoveRight(bitSet1, x);
    } else if ((op == 2)) {
      return bitSet1->andOtherMoveRight(bitSet2, (MAXV - x));
    } else if ((op == 3)) {
      for (int f = 1; ((f * f) <= x); (f++)) {
        if ((((jrem(x, f) == 0) && bitSet1->getStatus(f)) &&
             bitSet1->getStatus(jdiv(x, f)))) {
          return true;
        }
      }
      return false;
    } else {
      if ((x >= 1)) {
        for (int i = 1; ((i * x) <= MAXV); (i++)) {
          if ((bitSet1->getStatus(i) && bitSet1->getStatus((i * x)))) {
            return true;
          }
        }
      }
      return false;
    }
  }
  static void compute() {
    int winl = 1;
    int winr = 0;
    for (int i = 1; (i <= cntq); (i++)) {
      int jobl = query[i][0];
      int jobr = query[i][1];
      int jobx = query[i][2];
      int op = query[i][3];
      int id = query[i][4];
      while ((winl > jobl)) {
        Code08_YnoiCornfield1::add(arr[(--winl)]);
      }
      while ((winr < jobr)) {
        Code08_YnoiCornfield1::add(arr[(++winr)]);
      }
      while ((winl < jobl)) {
        Code08_YnoiCornfield1::del(arr[(winl++)]);
      }
      while ((winr > jobr)) {
        Code08_YnoiCornfield1::del(arr[(winr--)]);
      }
      (ans[id] = Code08_YnoiCornfield1::calc(op, jobx));
    }
  }
  static void special() {
    for (int x = 1; (x < blen); (x++)) {
      if ((headq[x] != 0)) {
        j::fill(pre, 0);
        j::fill(dp, 0);
        for (int i = 1; (i <= n); (i++)) {
          int v = arr[i];
          (pre[v] = i);
          (dp[i] = dp[(i - 1)]);
          if (((v * x) <= MAXV)) {
            (dp[i] = jmax(dp[i], pre[(v * x)]));
          }
          if ((jrem(v, x) == 0)) {
            (dp[i] = jmax(dp[i], pre[jdiv(v, x)]));
          }
        }
        for (int q = headq[x]; (q > 0); (q = nextq[q])) {
          int l = ql[q];
          int r = qr[q];
          int id = qid[q];
          (ans[id] = (l <= dp[r]));
        }
      }
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (m = in.nextInt());
    (blen = static_cast<int>(std::sqrt(MAXV)));
    for (int i = 1; (i <= n); (i++)) {
      (bi[i] = (jdiv((i - 1), blen) + 1));
    }
    for (int i = 1; (i <= n); (i++)) {
      (arr[i] = in.nextInt());
    }
    {
      int i = 1;
      int op = {};
      int l = {};
      int r = {};
      int x = {};
      for (; (i <= m); (i++)) {
        (op = in.nextInt());
        (l = in.nextInt());
        (r = in.nextInt());
        (x = in.nextInt());
        if (((op == 4) && (x < blen))) {
          Code08_YnoiCornfield1::addSpecial(x, l, r, i);
        } else {
          (query[(++cntq)][0] = l);
          (query[cntq][1] = r);
          (query[cntq][2] = x);
          (query[cntq][3] = op);
          (query[cntq][4] = i);
        }
      }
    }
    j::sort(query, 1, (cntq + 1), new QueryCmp());
    Code08_YnoiCornfield1::compute();
    Code08_YnoiCornfield1::special();
    for (int i = 1; (i <= m); (i++)) {
      if (ans[i]) {
        out.println(String(u"yuno"));
      } else {
        out.println(String(u"yumi"));
      }
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code08_YnoiCornfield1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 由乃的玉米田，java版
// 给定一个长度为n的数组arr，接下来有m条查询，查询格式如下
// 查询 1 l r x : 打印arr[l..r]范围上能否选出两个数，减的结果为x
// 查询 2 l r x : 打印arr[l..r]范围上能否选出两个数，加的结果为x
// 查询 3 l r x : 打印arr[l..r]范围上能否选出两个数，乘的结果为x
// 查询 4 l r x : 打印arr[l..r]范围上能否选出两个数，除的结果为x，并且没有余数
// 选出的这两个数可以是同一个位置的数，答案如果为是，打印 "yuno"，否则打印
"yumi"
// 1 <= 所有数据 <= 10^5
// 测试链接 : https://www.luogu.com.cn/problem/P5355
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
                // 检查 自己 & other右移k位 是否有1存在
        // 普通查询，l、r、x、op、id
        // 特别查询，x的问题列表 : l、r、id
        // 数字出现的词频
        // 特别查询的dp过程
        // 读写工具类
*/

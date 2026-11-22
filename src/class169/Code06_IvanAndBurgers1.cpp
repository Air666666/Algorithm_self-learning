// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/CF1100F
// https://codeforces.com/problemset/problem/1100/F

// Source: src/class169/Code06_IvanAndBurgers1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code06_IvanAndBurgers1 {
  inline static int MAXN = 500001;
  inline static int BIT = 21;
  inline static int n = {};
  inline static int q = {};
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static Array<int> qid = make_array<int>(MAXN);
  inline static Array<int> l = make_array<int>(MAXN);
  inline static Array<int> r = make_array<int>(MAXN);
  inline static Array<Array<int>> baset = make_array<int>(MAXN, (BIT + 1));
  inline static Array<int> tmp = make_array<int>((BIT + 1));
  inline static Array<int> lset = make_array<int>(MAXN);
  inline static Array<int> rset = make_array<int>(MAXN);
  inline static Array<int> ans = make_array<int>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code06_IvanAndBurgers1() {}
  static void insert(Array<int> basis, int num) {
    for (int i = BIT; (i >= 0); (i--)) {
      if ((jshr(num, i) == 1)) {
        if ((basis[i] == 0)) {
          (basis[i] = num);
          return;
        }
        (num ^= basis[i]);
      }
    }
  }
  static void clear(Array<int> basis) {
    for (int i = 0; (i <= BIT); (i++)) {
      (basis[i] = 0);
    }
  }
  static int maxEor(Array<int> basis) {
    int ret = 0;
    for (int i = BIT; (i >= 0); (i--)) {
      (ret = jmax(ret, (ret ^ basis[i])));
    }
    return ret;
  }
  static void clone(Array<int> b1, Array<int> b2) {
    for (int i = 0; (i <= BIT); (i++)) {
      (b1[i] = b2[i]);
    }
  }
  static void merge(Array<int> b1, Array<int> b2) {
    Code06_IvanAndBurgers1::clone(tmp, b1);
    for (int i = 0; (i <= BIT); (i++)) {
      Code06_IvanAndBurgers1::insert(tmp, b2[i]);
    }
  }
  static void compute(int ql, int qr, int vl, int vr) {
    if ((ql > qr)) {
      return;
    }
    if ((vl == vr)) {
      for (int i = ql; (i <= qr); (i++)) {
        (ans[qid[i]] = arr[vl]);
      }
    } else {
      int mid = jshr((vl + vr), 1);
      Code06_IvanAndBurgers1::clear(baset[mid]);
      Code06_IvanAndBurgers1::insert(baset[mid], arr[mid]);
      for (int i = (mid - 1); (i >= vl); (i--)) {
        Code06_IvanAndBurgers1::clone(baset[i], baset[(i + 1)]);
        Code06_IvanAndBurgers1::insert(baset[i], arr[i]);
      }
      for (int i = (mid + 1); (i <= vr); (i++)) {
        Code06_IvanAndBurgers1::clone(baset[i], baset[(i - 1)]);
        Code06_IvanAndBurgers1::insert(baset[i], arr[i]);
      }
      int lsiz = 0;
      int rsiz = 0;
      int id = {};
      for (int i = ql; (i <= qr); (i++)) {
        (id = qid[i]);
        if ((r[id] < mid)) {
          (lset[(++lsiz)] = id);
        } else if ((l[id] > mid)) {
          (rset[(++rsiz)] = id);
        } else {
          Code06_IvanAndBurgers1::merge(baset[l[id]], baset[r[id]]);
          (ans[id] = Code06_IvanAndBurgers1::maxEor(tmp));
        }
      }
      for (int i = 1; (i <= lsiz); (i++)) {
        (qid[((ql + i) - 1)] = lset[i]);
      }
      for (int i = 1; (i <= rsiz); (i++)) {
        (qid[(((ql + lsiz) + i) - 1)] = rset[i]);
      }
      Code06_IvanAndBurgers1::compute(ql, ((ql + lsiz) - 1), vl, mid);
      Code06_IvanAndBurgers1::compute((ql + lsiz), (((ql + lsiz) + rsiz) - 1),
                                      (mid + 1), vr);
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    for (int i = 1; (i <= n); (i++)) {
      (arr[i] = in.nextInt());
    }
    (q = in.nextInt());
    for (int i = 1; (i <= q); (i++)) {
      (qid[i] = i);
      (l[i] = in.nextInt());
      (r[i] = in.nextInt());
    }
    Code06_IvanAndBurgers1::compute(1, q, 1, n);
    for (int i = 1; (i <= q); (i++)) {
      out.println(ans[i]);
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code06_IvanAndBurgers1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 范围最大异或和，java版
// 给定一个长度为n的数组arr，下标1~n，接下来有q条查询，格式如下
// 查询 l r : arr[l..r]中选若干个数，打印最大的异或和
// 1 <= n、q <= 5 * 10^5
// 0 <= arr[i] <= 10^6
// 测试链接 : https://www.luogu.com.cn/problem/CF1100F
// 测试链接 : https://codeforces.com/problemset/problem/1100/F
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 读写工具类
*/

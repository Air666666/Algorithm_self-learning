// Source: src/class137/Code02_BucketMaximumXor.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_BucketMaximumXor {
  inline static int MAXN = 50001;
  inline static int BIT = 30;
  inline static Array<Array<int>> treeBasis =
      make_array<int>(jshl(MAXN, 2), (BIT + 1));
  inline static Array<int> basis = make_array<int>((BIT + 1));
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_BucketMaximumXor() {}
  static void add(int jobi, int jobv, int l, int r, int i) {
    Code02_BucketMaximumXor::insert(treeBasis[i], jobv);
    if ((l < r)) {
      int mid = jshr((l + r), 1);
      if ((jobi <= mid)) {
        Code02_BucketMaximumXor::add(jobi, jobv, l, mid, jshl(i, 1));
      } else {
        Code02_BucketMaximumXor::add(jobi, jobv, (mid + 1), r,
                                     (jshl(i, 1) | 1));
      }
    }
  }
  static bool insert(Array<int> basis, int num) {
    for (int i = BIT; (i >= 0); (i--)) {
      if ((jshr(num, i) == 1)) {
        if ((basis[i] == 0)) {
          (basis[i] = num);
          return true;
        }
        (num ^= basis[i]);
      }
    }
    return false;
  }
  static int query(int jobl, int jobr, int m) {
    j::fill(basis, 0);
    Code02_BucketMaximumXor::merge(jobl, jobr, 1, m, 1);
    int ans = 0;
    for (int j = BIT; (j >= 0); (j--)) {
      (ans = jmax(ans, (ans ^ basis[j])));
    }
    return ans;
  }
  static void merge(int jobl, int jobr, int l, int r, int i) {
    if (((jobl <= l) && (r <= jobr))) {
      for (int j = BIT; (j >= 0); (j--)) {
        if ((treeBasis[i][j] != 0)) {
          Code02_BucketMaximumXor::insert(basis, treeBasis[i][j]);
        }
      }
    } else {
      int mid = jshr((l + r), 1);
      if ((jobl <= mid)) {
        Code02_BucketMaximumXor::merge(jobl, jobr, l, mid, jshl(i, 1));
      }
      if ((jobr > mid)) {
        Code02_BucketMaximumXor::merge(jobl, jobr, (mid + 1), r,
                                       (jshl(i, 1) | 1));
      }
    }
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    int n = static_cast<int>(in.nval);
    in.nextToken();
    int m = static_cast<int>(in.nval);
    for (int i = 1; (i <= n); (i++)) {
      in.nextToken();
      int op = static_cast<int>(in.nval);
      if ((op == 1)) {
        in.nextToken();
        int jobi = static_cast<int>(in.nval);
        in.nextToken();
        int jobv = static_cast<int>(in.nval);
        Code02_BucketMaximumXor::add(jobi, jobv, 1, m, 1);
      } else {
        in.nextToken();
        int jobl = static_cast<int>(in.nval);
        in.nextToken();
        int jobr = static_cast<int>(in.nval);
        out.println(Code02_BucketMaximumXor::query(jobl, jobr, m));
      }
    }
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code02_BucketMaximumXor::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// P哥的桶
// 一共有n个桶，排成一排，编号1~n，每个桶可以装下任意个数字
// 高效的实现如下两个操作
// 操作 1 k v : 把数字v放入k号桶中
// 操作 2 l r : 可以从l..r号桶中随意拿数字，返回异或和最大的结果
// 1 <= n、m <= 5 * 10^4
// 0 <= v <= 2^31 - 1
// 测试链接 : https://www.luogu.com.cn/problem/P4839
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 线段树的每个范围上维护线性基
*/

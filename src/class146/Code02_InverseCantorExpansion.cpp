// Source: src/class146/Code02_InverseCantorExpansion.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_InverseCantorExpansion {
  inline static int MAXN = 100001;
  inline static Array<i64> arr = make_array<i64>(MAXN);
  inline static Array<int> sum = make_array<int>(jshl(MAXN, 2));
  inline static int n = {};
  inline static i64 m = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_InverseCantorExpansion() {}
  static void build(int l, int r, int i) {
    if ((l == r)) {
      (sum[i] = 1);
    } else {
      int mid = jshr((l + r), 1);
      Code02_InverseCantorExpansion::build(l, mid, jshl(i, 1));
      Code02_InverseCantorExpansion::build((mid + 1), r, (jshl(i, 1) | 1));
      (sum[i] = (sum[jshl(i, 1)] + sum[(jshl(i, 1) | 1)]));
    }
  }
  static void add(int jobi, int jobv, int l, int r, int i) {
    if ((l == r)) {
      (sum[i] += jobv);
    } else {
      int mid = jshr((l + r), 1);
      if ((jobi <= mid)) {
        Code02_InverseCantorExpansion::add(jobi, jobv, l, mid, jshl(i, 1));
      } else {
        Code02_InverseCantorExpansion::add(jobi, jobv, (mid + 1), r,
                                           (jshl(i, 1) | 1));
      }
      (sum[i] = (sum[jshl(i, 1)] + sum[(jshl(i, 1) | 1)]));
    }
  }
  static int sum_method(int jobl, int jobr, int l, int r, int i) {
    if (((jobl <= l) && (r <= jobr))) {
      return sum[i];
    }
    int mid = jshr((l + r), 1);
    int ans = 0;
    if ((jobl <= mid)) {
      (ans += Code02_InverseCantorExpansion::sum_method(jobl, jobr, l, mid,
                                                        jshl(i, 1)));
    }
    if ((jobr > mid)) {
      (ans += Code02_InverseCantorExpansion::sum_method(jobl, jobr, (mid + 1),
                                                        r, (jshl(i, 1) | 1)));
    }
    return ans;
  }
  static int getAndDelete(int k, int l, int r, int i) {
    int ans = {};
    if ((l == r)) {
      (sum[i]--);
      (ans = l);
    } else {
      int mid = jshr((l + r), 1);
      if ((sum[jshl(i, 1)] >= k)) {
        (ans = Code02_InverseCantorExpansion::getAndDelete(k, l, mid,
                                                           jshl(i, 1)));
      } else {
        (ans = Code02_InverseCantorExpansion::getAndDelete(
             (k - sum[jshl(i, 1)]), (mid + 1), r, (jshl(i, 1) | 1)));
      }
      (sum[i] = (sum[jshl(i, 1)] + sum[(jshl(i, 1) | 1)]));
    }
    return ans;
  }
  static void compute() {
    Code02_InverseCantorExpansion::build(1, n, 1);
    {
      int i = 1;
      int x = {};
      for (; (i <= n); (i++)) {
        (x = static_cast<int>(arr[i]));
        if ((x == 1)) {
          (arr[i] = 0);
        } else {
          (arr[i] =
               Code02_InverseCantorExpansion::sum_method(1, (x - 1), 1, n, 1));
        }
        Code02_InverseCantorExpansion::add(x, (-1), 1, n, 1);
      }
    }
    (arr[n] += m);
    for (int i = n; (i >= 1); (i--)) {
      (arr[(i - 1)] += jdiv(arr[i], ((n - i) + 1)));
      (arr[i] %= ((n - i) + 1));
    }
    Code02_InverseCantorExpansion::build(1, n, 1);
    for (int i = 1; (i <= n); (i++)) {
      (arr[i] = Code02_InverseCantorExpansion::getAndDelete(
           (static_cast<int>(arr[i]) + 1), 1, n, 1));
    }
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    (n = static_cast<int>(in.nval));
    in.nextToken();
    (m = static_cast<i64>(in.nval));
    for (int i = 1; (i <= n); (i++)) {
      in.nextToken();
      (arr[i] = static_cast<int>(in.nval));
    }
    Code02_InverseCantorExpansion::compute();
    for (int i = 1; (i <= n); (i++)) {
      out.print((arr[i] + String(u" ")));
    }
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code02_InverseCantorExpansion::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 逆康托展开
// 数字从1到n，可以有很多排列，给定一个长度为n的数组s，表示具体的一个排列
// 求出这个排列的排名假设为x，打印第x+m名的排列是什么
// 1 <= n <= 10^5
// 1 <= m <= 10^15
// 题目保证s是一个由1~n数字组成的正确排列，题目保证x+m不会超过排列的总数
// 测试链接 : https://www.luogu.com.cn/problem/U72177
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 线段树
        // 这种使用线段树的方式叫线段树二分
        // 讲解169的题目1，也涉及线段树二分
        // 初始化线段树，单点范围的初始累加和为1，认为所有数字都可用
        // 单点jobi上，增加jobv，因为是单点更新，所以不需要建立懒更新机制
        // 查询jobl~jobr范围的累加和
        // 线段树上找到第k名的是什么，找到后删掉词频，返回的过程修改累加和
                // 当前排列转化为阶乘进制的排名
                // 当前排名加上m之后，得到新的排名，用阶乘进制表示
                        // 往上进位多少
                        // 当前位是多少
                // 根据阶乘进制转化为具体的排列
*/

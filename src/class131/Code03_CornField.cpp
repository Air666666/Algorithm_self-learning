// Source: src/class131/Code03_CornField.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_CornField {
  inline static int MAXN = 10001;
  inline static int MAXK = 501;
  inline static int MAXH = 5500;
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static Array<Array<int>> tree =
      make_array<int>((MAXH + 1), (MAXK + 1));
  inline static int n = {};
  inline static int k = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_CornField() {}
  static void update(int x, int y, int v) {
    for (int i = x; (i <= MAXH); (i += (i & (-i)))) {
      for (int j = y; (j <= (k + 1)); (j += (j & (-j)))) {
        (tree[i][j] = jmax(tree[i][j], v));
      }
    }
  }
  static int max(int x, int y) {
    int ans = 0;
    for (int i = x; (i > 0); (i -= (i & (-i)))) {
      for (int j = y; (j > 0); (j -= (j & (-j)))) {
        (ans = jmax(ans, tree[i][j]));
      }
    }
    return ans;
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    (n = static_cast<int>(in.nval));
    in.nextToken();
    (k = static_cast<int>(in.nval));
    for (int i = 1; (i <= n); (i++)) {
      in.nextToken();
      (arr[i] = static_cast<int>(in.nval));
    }
    out.println(Code03_CornField::compute());
    out.flush();
    out.close();
    br.close();
  }
  static int compute() {
    int v = {};
    int dp = {};
    for (int i = 1; (i <= n); (i++)) {
      for (int j = k; (j >= 0); (j--)) {
        (v = (arr[i] + j));
        (dp = (Code03_CornField::max(v, (j + 1)) + 1));
        Code03_CornField::update(v, (j + 1), dp);
      }
    }
    return Code03_CornField::max(MAXH, (k + 1));
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code03_CornField::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 方伯伯的玉米田
// 给定一个长度为n的数组arr
// 每次可以选择一个区间[l,r]，区间内的数字都+1，最多执行k次
// 返回执行完成后，最长的不下降子序列长度
// 1 <= n <= 10^4
// 1 <= arr[i] <= 5000
// 2 <= k <= 500
// 测试链接 : https://www.luogu.com.cn/problem/P3287
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有用例
                // 注意这里第二层for循环，j一定是从k~0的枚举
                // 课上进行了重点图解，防止同一个i产生的记录之间相互影响
                                // 修改次数j，树状数组中对应的下标是j+1
                // 修改次数k，树状数组中对应的下标是k+1
*/

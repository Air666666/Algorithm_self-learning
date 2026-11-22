// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P1908

// Source: src/class109/Code01_NumberOfReversePair2.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_NumberOfReversePair2 {
  inline static int MAXN = 500001;
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static Array<int> sort = make_array<int>(MAXN);
  inline static Array<int> tree = make_array<int>(MAXN);
  inline static int n = {};
  inline static int m = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_NumberOfReversePair2() {}
  static int lowbit(int i) { return (i & (-i)); }
  static void add(int i, int v) {
    while ((i <= m)) {
      (tree[i] += v);
      (i += Code01_NumberOfReversePair2::lowbit(i));
    }
  }
  static i64 sum(int i) {
    i64 ans = 0;
    while ((i > 0)) {
      (ans += tree[i]);
      (i -= Code01_NumberOfReversePair2::lowbit(i));
    }
    return ans;
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    (n = static_cast<int>(in.nval));
    for (int i = 1; (i <= n); (i++)) {
      in.nextToken();
      (arr[i] = static_cast<int>(in.nval));
      (sort[i] = arr[i]);
    }
    out.println(Code01_NumberOfReversePair2::compute());
    out.flush();
    out.close();
    br.close();
  }
  static i64 compute() {
    j::sort(sort, 1, (n + 1));
    (m = 1);
    for (int i = 2; (i <= n); (i++)) {
      if ((sort[m] != sort[i])) {
        (sort[(++m)] = sort[i]);
      }
    }
    for (int i = 1; (i <= n); (i++)) {
      (arr[i] = Code01_NumberOfReversePair2::rank(arr[i]));
    }
    i64 ans = 0;
    for (int i = n; (i >= 1); (i--)) {
      (ans += Code01_NumberOfReversePair2::sum((arr[i] - 1)));
      Code01_NumberOfReversePair2::add(arr[i], 1);
    }
    return ans;
  }
  static int rank(int v) {
    int l = 1;
    int r = m;
    int mid = {};
    int ans = 0;
    while ((l <= r)) {
      (mid = jdiv((l + r), 2));
      if ((sort[mid] >= v)) {
        (ans = mid);
        (r = (mid - 1));
      } else {
        (l = (mid + 1));
      }
    }
    return ans;
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code01_NumberOfReversePair2::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 逆序对数量(值域树状数组)
// 给定一个长度为n的数组arr
// 如果 i < j 且 arr[i] > arr[j]
// 那么(i,j)就是一个逆序对
// 求arr中逆序对的数量
// 1 <= n <= 5 * 10^5
// 1 <= arr[i] <= 10^9
// 测试链接 : https://www.luogu.com.cn/problem/P1908
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下的code，提交时请把类名改成"Main"，可以直接通过
        // 1~i范围的累加和
                        // 右边有多少数字是 <= 当前数值 - 1
                        // 增加当前数字的词频
        // 给定原始值v
        // 返回排名值(排序部分1~m中的下标)
*/

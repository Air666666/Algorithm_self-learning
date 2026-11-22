// Source: src/class109/Code02_IncreasingTriples.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_IncreasingTriples {
  inline static int MAXN = 30001;
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static Array<int> sort = make_array<int>(MAXN);
  inline static Array<i64> tree1 = make_array<i64>(MAXN);
  inline static Array<i64> tree2 = make_array<i64>(MAXN);
  inline static int n = {};
  inline static int m = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_IncreasingTriples() {}
  static int lowbit(int i) { return (i & (-i)); }
  static void add(Array<i64> tree, int i, i64 c) {
    while ((i <= m)) {
      (tree[i] += c);
      (i += Code02_IncreasingTriples::lowbit(i));
    }
  }
  static i64 sum(Array<i64> tree, int i) {
    i64 ans = 0;
    while ((i > 0)) {
      (ans += tree[i]);
      (i -= Code02_IncreasingTriples::lowbit(i));
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
    out.println(Code02_IncreasingTriples::compute());
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
      (arr[i] = Code02_IncreasingTriples::rank(arr[i]));
    }
    i64 ans = 0;
    for (int i = 1; (i <= n); (i++)) {
      (ans += Code02_IncreasingTriples::sum(tree2, (arr[i] - 1)));
      Code02_IncreasingTriples::add(tree1, arr[i], 1);
      Code02_IncreasingTriples::add(
          tree2, arr[i], Code02_IncreasingTriples::sum(tree1, (arr[i] - 1)));
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
  Code02_IncreasingTriples::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 升序三元组数量
// 给定一个数组arr，如果i < j < k且arr[i] < arr[j] < arr[k]
// 那么称(i, j, k)为一个升序三元组
// 返回arr中升序三元组的数量
// 测试链接 : https://www.luogu.com.cn/problem/P1637
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下的code，提交时请把类名改成"Main"，可以直接通过
        // 维护信息 : 课上讲的up1数组
        // tree1不是up1数组，是up1数组的树状数组
        // 维护信息 : 课上讲的up2数组
        // tree2不是up2数组，是up2数组的树状数组
        // 时间复杂度O(n * logn)
                        // 查询以当前值做结尾的升序三元组数量
                        // 更新以当前值做结尾的升序一元组数量
                        // 更新以当前值做结尾的升序二元组数量
*/

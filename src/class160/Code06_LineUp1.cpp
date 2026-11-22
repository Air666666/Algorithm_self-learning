// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P1975

// Source: src/class160/Code06_LineUp1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code06_LineUp1 {
  inline static int MAXN = 20001;
  inline static int MAXT = (MAXN * 80);
  inline static int INF = 1000000001;
  inline static int n = {};
  inline static int m = {};
  inline static int s = {};
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static Array<int> sorted = make_array<int>((MAXN + 2));
  inline static Array<int> root = make_array<int>(MAXN);
  inline static Array<int> left = make_array<int>(MAXT);
  inline static Array<int> right = make_array<int>(MAXT);
  inline static Array<int> sum = make_array<int>(MAXT);
  inline static int cnt = 0;
  inline static int ans = 0;
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code06_LineUp1() {}
  static int kth(int num) {
    int left = 1;
    int right = s;
    int mid = {};
    while ((left <= right)) {
      (mid = jdiv((left + right), 2));
      if ((sorted[mid] == num)) {
        return mid;
      } else if ((sorted[mid] < num)) {
        (left = (mid + 1));
      } else {
        (right = (mid - 1));
      }
    }
    return (-1);
  }
  static int lowbit(int i) { return (i & (-i)); }
  static int innerAdd(int jobi, int jobv, int l, int r, int i) {
    if ((i == 0)) {
      (i = (++cnt));
    }
    if ((l == r)) {
      (sum[i] += jobv);
    } else {
      int mid = jdiv((l + r), 2);
      if ((jobi <= mid)) {
        (left[i] = Code06_LineUp1::innerAdd(jobi, jobv, l, mid, left[i]));
      } else {
        (right[i] =
             Code06_LineUp1::innerAdd(jobi, jobv, (mid + 1), r, right[i]));
      }
      (sum[i] = (sum[left[i]] + sum[right[i]]));
    }
    return i;
  }
  static int innerQuery(int jobl, int jobr, int l, int r, int i) {
    if ((i == 0)) {
      return 0;
    }
    if (((jobl <= l) && (r <= jobr))) {
      return sum[i];
    }
    int mid = jdiv((l + r), 2);
    int ans = 0;
    if ((jobl <= mid)) {
      (ans += Code06_LineUp1::innerQuery(jobl, jobr, l, mid, left[i]));
    }
    if ((jobr > mid)) {
      (ans += Code06_LineUp1::innerQuery(jobl, jobr, (mid + 1), r, right[i]));
    }
    return ans;
  }
  static void add(int i, int v) {
    for (int j = i; (j <= n); (j += Code06_LineUp1::lowbit(j))) {
      (root[j] = Code06_LineUp1::innerAdd(arr[i], v, 1, s, root[j]));
    }
  }
  static int query(int al, int ar, int numl, int numr) {
    int ans = 0;
    for (int i = ar; (i > 0); (i -= Code06_LineUp1::lowbit(i))) {
      (ans += Code06_LineUp1::innerQuery(numl, numr, 1, s, root[i]));
    }
    for (int i = (al - 1); (i > 0); (i -= Code06_LineUp1::lowbit(i))) {
      (ans -= Code06_LineUp1::innerQuery(numl, numr, 1, s, root[i]));
    }
    return ans;
  }
  static void compute(int a, int b) {
    (ans -= Code06_LineUp1::query((a + 1), (b - 1), 1, (arr[a] - 1)));
    (ans += Code06_LineUp1::query((a + 1), (b - 1), (arr[a] + 1), s));
    (ans -= Code06_LineUp1::query((a + 1), (b - 1), (arr[b] + 1), s));
    (ans += Code06_LineUp1::query((a + 1), (b - 1), 1, (arr[b] - 1)));
    if ((arr[a] < arr[b])) {
      (ans++);
    } else if ((arr[a] > arr[b])) {
      (ans--);
    }
    Code06_LineUp1::add(a, (-1));
    Code06_LineUp1::add(b, (-1));
    int tmp = arr[a];
    (arr[a] = arr[b]);
    (arr[b] = tmp);
    Code06_LineUp1::add(a, 1);
    Code06_LineUp1::add(b, 1);
  }
  static void prepare() {
    (s = 0);
    for (int i = 1; (i <= n); (i++)) {
      (sorted[(++s)] = arr[i]);
    }
    (sorted[(++s)] = (-INF));
    (sorted[(++s)] = INF);
    j::sort(sorted, 1, (s + 1));
    int len = 1;
    for (int i = 2; (i <= s); (i++)) {
      if ((sorted[len] != sorted[i])) {
        (sorted[(++len)] = sorted[i]);
      }
    }
    (s = len);
    for (int i = 1; (i <= n); (i++)) {
      (arr[i] = Code06_LineUp1::kth(arr[i]));
      Code06_LineUp1::add(i, 1);
    }
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
    }
    Code06_LineUp1::prepare();
    for (int i = 2; (i <= n); (i++)) {
      (ans += Code06_LineUp1::query(1, (i - 1), (arr[i] + 1), s));
    }
    out.println(ans);
    in.nextToken();
    (m = static_cast<int>(in.nval));
    {
      int i = 1;
      int a = {};
      int b = {};
      for (; (i <= m); (i++)) {
        in.nextToken();
        (a = static_cast<int>(in.nval));
        in.nextToken();
        (b = static_cast<int>(in.nval));
        if ((a > b)) {
          int tmp = a;
          (a = b);
          (b = tmp);
        }
        Code06_LineUp1::compute(a, b);
        out.println(ans);
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
  Code06_LineUp1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 排队，java版
// 给定一个长度为n的数组arr，下标1~n
// 如果有i < j，并且arr[i] > arr[j]，那么(i,j)就叫做一个逆序对
// 首先打印原始arr中有多少逆序对，然后进行如下类型的操作，一共发生m次
// 操作 a b : 交换arr中a位置的数和b位置的数，打印数组中逆序对的数量
// 1 <= n <= 2 * 10^4
// 1 <= m <= 2 * 10^3
// 1 <= arr[i] <= 10^9
// 测试链接 : https://www.luogu.com.cn/problem/P1975
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 线段树单点修改，jobi这个数字词频增加jobv
        // 查询的数字范围[jobl...jobr]，线段树的数字范围[l..r]，节点编号i
        // 返回有多少词频
        // arr的i位置的数字，词频增加v
        // arr[al..ar]范围上，有多少数字在[numl..numr]范围上
        // 交换a和b位置的数字，保证a在前，b在后
        // 修正好逆序对的数量ans
*/

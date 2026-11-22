// Source: src/class158/Code03_LargestUpMedian1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_LargestUpMedian1 {
  inline static int MAXN = 20001;
  inline static int MAXT = (MAXN * 20);
  inline static int INF = 10000001;
  inline static int n = {};
  inline static int m = {};
  inline static Array<Array<int>> arr = make_array<int>(MAXN, 2);
  inline static Array<int> root = make_array<int>(MAXN);
  inline static Array<int> left = make_array<int>(MAXT);
  inline static Array<int> right = make_array<int>(MAXT);
  inline static Array<int> pre = make_array<int>(MAXT);
  inline static Array<int> suf = make_array<int>(MAXT);
  inline static Array<int> sum = make_array<int>(MAXT);
  inline static int cnt = {};
  inline static Array<int> ques = make_array<int>(4);
  inline static Array<int> info = make_array<int>(3);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_LargestUpMedian1() {}
  static int build(int l, int r) {
    int rt = (++cnt);
    (pre[rt] = (suf[rt] = (sum[rt] = ((r - l) + 1))));
    if ((l < r)) {
      int mid = jdiv((l + r), 2);
      (left[rt] = Code03_LargestUpMedian1::build(l, mid));
      (right[rt] = Code03_LargestUpMedian1::build((mid + 1), r));
    }
    return rt;
  }
  static void up(int i) {
    (pre[i] = jmax(pre[left[i]], (sum[left[i]] + pre[right[i]])));
    (suf[i] = jmax(suf[right[i]], (suf[left[i]] + sum[right[i]])));
    (sum[i] = (sum[left[i]] + sum[right[i]]));
  }
  static int update(int jobi, int l, int r, int i) {
    int rt = (++cnt);
    (left[rt] = left[i]);
    (right[rt] = right[i]);
    (pre[rt] = pre[i]);
    (suf[rt] = suf[i]);
    (sum[rt] = sum[i]);
    if ((l == r)) {
      (pre[rt] = (suf[rt] = (sum[rt] = (-1))));
    } else {
      int mid = jdiv((l + r), 2);
      if ((jobi <= mid)) {
        (left[rt] = Code03_LargestUpMedian1::update(jobi, l, mid, left[rt]));
      } else {
        (right[rt] =
             Code03_LargestUpMedian1::update(jobi, (mid + 1), r, right[rt]));
      }
      Code03_LargestUpMedian1::up(rt);
    }
    return rt;
  }
  static void initInfo() {
    (info[0] = (info[1] = (-INF)));
    (info[2] = 0);
  }
  static void mergeRight(int r) {
    (info[0] = jmax(info[0], (info[2] + pre[r])));
    (info[1] = jmax(suf[r], (info[1] + sum[r])));
    (info[2] += sum[r]);
  }
  static void query(int jobl, int jobr, int l, int r, int i) {
    if (((jobl <= l) && (r <= jobr))) {
      Code03_LargestUpMedian1::mergeRight(i);
    } else {
      int mid = jdiv((l + r), 2);
      if ((jobl <= mid)) {
        Code03_LargestUpMedian1::query(jobl, jobr, l, mid, left[i]);
      }
      if ((jobr > mid)) {
        Code03_LargestUpMedian1::query(jobl, jobr, (mid + 1), r, right[i]);
      }
    }
  }
  static void prepare() {
    j::sort(arr, 1, (n + 1),
            [=](Array<int> a, Array<int> b) { return (a[1] - b[1]); });
    (cnt = 0);
    (root[1] = Code03_LargestUpMedian1::build(1, n));
    for (int i = 2; (i <= n); (i++)) {
      (root[i] = Code03_LargestUpMedian1::update(arr[(i - 1)][0], 1, n,
                                                 root[(i - 1)]));
    }
  }
  static bool check(int a, int b, int c, int d, int v) {
    Code03_LargestUpMedian1::initInfo();
    Code03_LargestUpMedian1::query(a, b, 1, n, root[v]);
    int best = info[1];
    Code03_LargestUpMedian1::initInfo();
    Code03_LargestUpMedian1::query(c, d, 1, n, root[v]);
    (best += info[0]);
    if (((b + 1) <= (c - 1))) {
      Code03_LargestUpMedian1::initInfo();
      Code03_LargestUpMedian1::query((b + 1), (c - 1), 1, n, root[v]);
      (best += info[2]);
    }
    return (best >= 0);
  }
  static int compute(int a, int b, int c, int d) {
    int left = 1;
    int right = n;
    int mid = {};
    int ans = 0;
    while ((left <= right)) {
      (mid = jdiv((left + right), 2));
      if (Code03_LargestUpMedian1::check(a, b, c, d, mid)) {
        (ans = arr[mid][1]);
        (left = (mid + 1));
      } else {
        (right = (mid - 1));
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
    for (int i = 1; (i <= n); (i++)) {
      (arr[i][0] = i);
      in.nextToken();
      (arr[i][1] = static_cast<int>(in.nval));
    }
    Code03_LargestUpMedian1::prepare();
    in.nextToken();
    (m = static_cast<int>(in.nval));
    {
      int i = 1;
      int lastAns = 0;
      for (; (i <= m); (i++)) {
        in.nextToken();
        (ques[0] = (jrem((static_cast<int>(in.nval) + lastAns), n) + 1));
        in.nextToken();
        (ques[1] = (jrem((static_cast<int>(in.nval) + lastAns), n) + 1));
        in.nextToken();
        (ques[2] = (jrem((static_cast<int>(in.nval) + lastAns), n) + 1));
        in.nextToken();
        (ques[3] = (jrem((static_cast<int>(in.nval) + lastAns), n) + 1));
        j::sort(ques);
        (lastAns = Code03_LargestUpMedian1::compute(ques[0], ques[1], ques[2],
                                                    ques[3]));
        out.println(lastAns);
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
  Code03_LargestUpMedian1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 浮动区间的最大上中位数，java版
// 为了方便理解，我改写了题意，但是改写的题意和原始题意等效
// 给定一个长度为n的数组arr，下标1~n，一共有m条查询
// 每条查询 a b c d : 左端点在[a,b]之间、右端点在[c,d]之间，保证a<b<c<d
//                   哪个区间有最大的上中位数，打印最大的上中位数
// 题目有强制在线的要求，上一次打印的答案为lastAns，初始时lastAns = 0
// 每次给定四个参数，按照如下方式得到a、b、c、d，查询完成后更新lastAns
// (给定的每个参数 + lastAns) % n + 1，得到四个值，从小到大对应a、b、c、d
// 1 <= n <= 20000
// 1 <= m <= 25000
// 1 <= arr[i] <= 10^9
// 测试链接 : https://www.luogu.com.cn/problem/P2839
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 原始位置、数值
        // 可持久化线段树需要
        // 区间内最大前缀和，前缀不能为空
        // 区间内最大后缀和，后缀不能为空
        // 区间内累加和
        // 查询的问题，a、b、c、d
        // 收集区间信息，pre、suf、sum
        // jobi位置，原来是1，现在改为-1
*/

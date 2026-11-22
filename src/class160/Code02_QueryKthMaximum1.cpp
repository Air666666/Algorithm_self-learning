// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P3332

// Source: src/class160/Code02_QueryKthMaximum1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_QueryKthMaximum1 {
  inline static int MAXM = 50001;
  inline static int MAXT = (MAXM * 230);
  inline static int n = {};
  inline static int m = {};
  inline static int s = {};
  inline static Array<Array<int>> ques = make_array<int>(MAXM, 4);
  inline static Array<int> sorted = make_array<int>(MAXM);
  inline static Array<int> root = make_array<int>(jshl(MAXM, 2));
  inline static Array<int> left = make_array<int>(MAXT);
  inline static Array<int> right = make_array<int>(MAXT);
  inline static Array<i64> sum = make_array<i64>(MAXT);
  inline static Array<int> lazy = make_array<int>(MAXT);
  inline static int cnt = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_QueryKthMaximum1() {}
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
  static void up(int i) { (sum[i] = (sum[left[i]] + sum[right[i]])); }
  static void down(int i, int ln, int rn) {
    if ((lazy[i] != 0)) {
      if ((left[i] == 0)) {
        (left[i] = (++cnt));
      }
      if ((right[i] == 0)) {
        (right[i] = (++cnt));
      }
      (sum[left[i]] += (lazy[i] * ln));
      (lazy[left[i]] += lazy[i]);
      (sum[right[i]] += (lazy[i] * rn));
      (lazy[right[i]] += lazy[i]);
      (lazy[i] = 0);
    }
  }
  static int innerAdd(int jobl, int jobr, int l, int r, int i) {
    if ((i == 0)) {
      (i = (++cnt));
    }
    if (((jobl <= l) && (r <= jobr))) {
      (sum[i] += ((r - l) + 1));
      (lazy[i]++);
    } else {
      int mid = jdiv((l + r), 2);
      Code02_QueryKthMaximum1::down(i, ((mid - l) + 1), (r - mid));
      if ((jobl <= mid)) {
        (left[i] =
             Code02_QueryKthMaximum1::innerAdd(jobl, jobr, l, mid, left[i]));
      }
      if ((jobr > mid)) {
        (right[i] = Code02_QueryKthMaximum1::innerAdd(jobl, jobr, (mid + 1), r,
                                                      right[i]));
      }
      Code02_QueryKthMaximum1::up(i);
    }
    return i;
  }
  static i64 innerQuery(int jobl, int jobr, int l, int r, int i) {
    if ((i == 0)) {
      return 0;
    }
    if (((jobl <= l) && (r <= jobr))) {
      return sum[i];
    }
    int mid = jdiv((l + r), 2);
    Code02_QueryKthMaximum1::down(i, ((mid - l) + 1), (r - mid));
    i64 ans = 0;
    if ((jobl <= mid)) {
      (ans += Code02_QueryKthMaximum1::innerQuery(jobl, jobr, l, mid, left[i]));
    }
    if ((jobr > mid)) {
      (ans +=
       Code02_QueryKthMaximum1::innerQuery(jobl, jobr, (mid + 1), r, right[i]));
    }
    return ans;
  }
  static void outerAdd(int jobl, int jobr, int jobv, int l, int r, int i) {
    (root[i] = Code02_QueryKthMaximum1::innerAdd(jobl, jobr, 1, n, root[i]));
    if ((l < r)) {
      int mid = jdiv((l + r), 2);
      if ((jobv <= mid)) {
        Code02_QueryKthMaximum1::outerAdd(jobl, jobr, jobv, l, mid, jshl(i, 1));
      } else {
        Code02_QueryKthMaximum1::outerAdd(jobl, jobr, jobv, (mid + 1), r,
                                          (jshl(i, 1) | 1));
      }
    }
  }
  static int outerQuery(int jobl, int jobr, i64 jobk, int l, int r, int i) {
    if ((l == r)) {
      return l;
    }
    int mid = jdiv((l + r), 2);
    i64 rightsum = Code02_QueryKthMaximum1::innerQuery(jobl, jobr, 1, n,
                                                       root[(jshl(i, 1) | 1)]);
    if ((jobk > rightsum)) {
      return Code02_QueryKthMaximum1::outerQuery(jobl, jobr, (jobk - rightsum),
                                                 l, mid, jshl(i, 1));
    } else {
      return Code02_QueryKthMaximum1::outerQuery(jobl, jobr, jobk, (mid + 1), r,
                                                 (jshl(i, 1) | 1));
    }
  }
  static void prepare() {
    (s = 0);
    for (int i = 1; (i <= m); (i++)) {
      if ((ques[i][0] == 1)) {
        (sorted[(++s)] = ques[i][3]);
      }
    }
    j::sort(sorted, 1, (s + 1));
    int len = 1;
    for (int i = 2; (i <= s); (i++)) {
      if ((sorted[len] != sorted[i])) {
        (sorted[(++len)] = sorted[i]);
      }
    }
    (s = len);
    for (int i = 1; (i <= m); (i++)) {
      if ((ques[i][0] == 1)) {
        (ques[i][3] = Code02_QueryKthMaximum1::kth(ques[i][3]));
      }
    }
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    (n = static_cast<int>(in.nval));
    in.nextToken();
    (m = static_cast<int>(in.nval));
    for (int i = 1; (i <= m); (i++)) {
      in.nextToken();
      (ques[i][0] = static_cast<int>(in.nval));
      in.nextToken();
      (ques[i][1] = static_cast<int>(in.nval));
      in.nextToken();
      (ques[i][2] = static_cast<int>(in.nval));
      in.nextToken();
      (ques[i][3] = static_cast<int>(in.nval));
    }
    Code02_QueryKthMaximum1::prepare();
    for (int i = 1; (i <= m); (i++)) {
      if ((ques[i][0] == 1)) {
        Code02_QueryKthMaximum1::outerAdd(ques[i][1], ques[i][2], ques[i][3], 1,
                                          s, 1);
      } else {
        int idx = Code02_QueryKthMaximum1::outerQuery(ques[i][1], ques[i][2],
                                                      ques[i][3], 1, s, 1);
        out.println(sorted[idx]);
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
  Code02_QueryKthMaximum1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// k大数查询，java版
// 初始时有n个空集合，编号1~n，实现如下两种类型的操作，操作一共发生m次
// 操作 1 l r v : 数字v放入编号范围[l,r]的每一个集合中
// 操作 2 l r k : 编号范围[l,r]的所有集合，如果生成不去重的并集，返回第k大的数字
// 1 <= n、m <= 5 * 10^4
// -n <= v <= +n
// 1 <= k < 2^63，题目保证第k大的数字一定存在
// 测试链接 : https://www.luogu.com.cn/problem/P3332
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 外部线段树的范围，一共只有m个操作，所以最多有m种数字
        // 内部线段树的节点数上限
        // 所有操作收集起来，因为牵扯到数字离散化
        // 所有可能的数字，收集起来去重，方便得到数字排名
        // 外部(a~b) + 内部(c~d)表示：数字排名范围a~b，集合范围c~d，数字的个数
        // 外部线段树的下标表示数字的排名
        //
外部(a~b)，假设对应的节点编号为i，那么root[i]就是内部线段树的头节点编号
        // 内部线段树是开点线段树，所以需要cnt来获得节点计数
        // 内部线段树的下标表示集合的编号
        // 内部(c~d)，假设对应的节点编号为i
        // sum[i]表示集合范围c~d，一共收集了多少数字
        // lazy[i]懒更新信息，集合范围c~d，增加了几个数字，等待懒更新的下发
*/

// 原题测试 / 参考链接（保留上游原始地址）
// https://acm.hdu.edu.cn/showproblem.php?pid=5919

// Source: src/class158/Code01_FirstTimeSequence1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_FirstTimeSequence1 {
  inline static int MAXN = 200002;
  inline static int MAXT = (MAXN * 37);
  inline static int cases = {};
  inline static int n = {};
  inline static int m = {};
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static Array<int> pos = make_array<int>(MAXN);
  inline static Array<int> root = make_array<int>(MAXN);
  inline static Array<int> left = make_array<int>(MAXT);
  inline static Array<int> right = make_array<int>(MAXT);
  inline static Array<int> firstSize = make_array<int>(MAXT);
  inline static int cnt = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_FirstTimeSequence1() {}
  static int build(int l, int r) {
    int rt = (++cnt);
    if ((l < r)) {
      int mid = jdiv((l + r), 2);
      (left[rt] = Code01_FirstTimeSequence1::build(l, mid));
      (right[rt] = Code01_FirstTimeSequence1::build((mid + 1), r));
    }
    (firstSize[rt] = 0);
    return rt;
  }
  static int update(int jobi, int jobv, int l, int r, int i) {
    int rt = (++cnt);
    (left[rt] = left[i]);
    (right[rt] = right[i]);
    (firstSize[rt] = (firstSize[i] + jobv));
    if ((l == r)) {
      return rt;
    }
    int mid = jdiv((l + r), 2);
    if ((jobi <= mid)) {
      (left[rt] =
           Code01_FirstTimeSequence1::update(jobi, jobv, l, mid, left[rt]));
    } else {
      (right[rt] = Code01_FirstTimeSequence1::update(jobi, jobv, (mid + 1), r,
                                                     right[rt]));
    }
    return rt;
  }
  static int querySize(int jobl, int jobr, int l, int r, int i) {
    if (((jobl <= l) && (r <= jobr))) {
      return firstSize[i];
    }
    int mid = jdiv((l + r), 2);
    int ans = 0;
    if ((jobl <= mid)) {
      (ans +=
       Code01_FirstTimeSequence1::querySize(jobl, jobr, l, mid, left[i]));
    }
    if ((jobr > mid)) {
      (ans += Code01_FirstTimeSequence1::querySize(jobl, jobr, (mid + 1), r,
                                                   right[i]));
    }
    return ans;
  }
  static int queryKth(int jobk, int l, int r, int i) {
    if ((l == r)) {
      return l;
    }
    int mid = jdiv((l + r), 2);
    int lsize = firstSize[left[i]];
    if ((lsize >= jobk)) {
      return Code01_FirstTimeSequence1::queryKth(jobk, l, mid, left[i]);
    } else {
      return Code01_FirstTimeSequence1::queryKth((jobk - lsize), (mid + 1), r,
                                                 right[i]);
    }
  }
  static void prepare() {
    (cnt = 0);
    j::fill(pos, 0);
    (root[(n + 1)] = Code01_FirstTimeSequence1::build(1, n));
    for (int i = n; (i >= 1); (i--)) {
      if ((pos[arr[i]] == 0)) {
        (root[i] =
             Code01_FirstTimeSequence1::update(i, 1, 1, n, root[(i + 1)]));
      } else {
        (root[i] = Code01_FirstTimeSequence1::update(pos[arr[i]], (-1), 1, n,
                                                     root[(i + 1)]));
        (root[i] = Code01_FirstTimeSequence1::update(i, 1, 1, n, root[i]));
      }
      (pos[arr[i]] = i);
    }
  }
  static void java_main(Array<String> args) {
    IO io = IO();
    (cases = io.nextInt());
    for (int t = 1; (t <= cases); (t++)) {
      (n = io.nextInt());
      (m = io.nextInt());
      for (int i = 1; (i <= n); (i++)) {
        (arr[i] = io.nextInt());
      }
      Code01_FirstTimeSequence1::prepare();
      io.write(String(u"Case #"));
      io.writeInt(t);
      io.write(String(u":"));
      {
        int i = 1;
        int a = {};
        int b = {};
        int l = {};
        int r = {};
        int k = {};
        int lastAns = 0;
        for (; (i <= m); (i++)) {
          (a = (jrem((io.nextInt() + lastAns), n) + 1));
          (b = (jrem((io.nextInt() + lastAns), n) + 1));
          (l = jmin(a, b));
          (r = jmax(a, b));
          (k = jdiv(
               (Code01_FirstTimeSequence1::querySize(l, r, 1, n, root[l]) + 1),
               2));
          (lastAns = Code01_FirstTimeSequence1::queryKth(k, 1, n, root[l]));
          io.write(String(u" "));
          io.writeInt(lastAns);
        }
      }
      io.write(String(u"\n"));
    }
    io.flush();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code01_FirstTimeSequence1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 第一次出现位置的序列，java版
// 给定一个长度为n的数组arr，下标1~n，一共有m条查询，每条查询格式如下
// l r : arr[l..r]范围上，每个数第一次出现的位置，把这些位置组成一个序列
//       假设该范围有s种不同的数，那么序列长度为s
//       打印该序列第s/2个位置(向上取整)，对应arr的什么位置
// 题目有强制在线的要求，上一次打印的答案为lastAns，初始时lastAns = 0
// 每次给定的l和r，按照如下方式得到真实的l和r，查询完成后更新lastAns
// a = (给定l + lastAns) % n + 1
// b = (给定r + lastAns) % n + 1
// 真实l = min(a, b)
// 真实r = max(a, b)
// 1 <= n、m <= 2 * 10^5    0 <= arr[i] <= 2 * 10^5
// 测试链接 : https://acm.hdu.edu.cn/showproblem.php?pid=5919
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // pos[v] : v这个数字上次出现的位置
        // 可持久化线段树需要
        // 数组范围上只记录每种数第一次出现的位置，这样的位置有多少个
        // 数组范围l~r，信息在i号节点
        // 如果jobv = -1，意味着jobi位置减少一个计数
        // 如果jobv = +1，意味着jobi位置增加一个计数
        // 返回新的头节点编号
        // 数组范围l~r，信息在i号节点
        // jobl ~
jobr范围上，一共有几种不同的数字，也就是这个范围上，有多少个位置有1
        // 数组范围l~r，信息在i号节点
        // 查询这个范围上，第jobk个1在哪
        // 从右往左建立各个版本的线段树
        // 读写工具类
*/

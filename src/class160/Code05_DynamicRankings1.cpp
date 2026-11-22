// Source: src/class160/Code05_DynamicRankings1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code05_DynamicRankings1 {
  inline static int MAXN = 100001;
  inline static int MAXT = (MAXN * 130);
  inline static int n = {};
  inline static int m = {};
  inline static int s = {};
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static Array<Array<int>> ques = make_array<int>(MAXN, 4);
  inline static Array<int> sorted = make_array<int>((MAXN * 2));
  inline static Array<int> root = make_array<int>(MAXN);
  inline static Array<int> sum = make_array<int>(MAXT);
  inline static Array<int> left = make_array<int>(MAXT);
  inline static Array<int> right = make_array<int>(MAXT);
  inline static int cntt = 0;
  inline static Array<int> addTree = make_array<int>(MAXN);
  inline static Array<int> minusTree = make_array<int>(MAXN);
  inline static int cntadd = {};
  inline static int cntminus = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code05_DynamicRankings1() {}
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
      (i = (++cntt));
    }
    if ((l == r)) {
      (sum[i] += jobv);
    } else {
      int mid = jdiv((l + r), 2);
      if ((jobi <= mid)) {
        (left[i] =
             Code05_DynamicRankings1::innerAdd(jobi, jobv, l, mid, left[i]));
      } else {
        (right[i] = Code05_DynamicRankings1::innerAdd(jobi, jobv, (mid + 1), r,
                                                      right[i]));
      }
      (sum[i] = (sum[left[i]] + sum[right[i]]));
    }
    return i;
  }
  static int innerQuery(int jobk, int l, int r) {
    if ((l == r)) {
      return l;
    }
    int mid = jdiv((l + r), 2);
    int leftsum = 0;
    for (int i = 1; (i <= cntadd); (i++)) {
      (leftsum += sum[left[addTree[i]]]);
    }
    for (int i = 1; (i <= cntminus); (i++)) {
      (leftsum -= sum[left[minusTree[i]]]);
    }
    if ((jobk <= leftsum)) {
      for (int i = 1; (i <= cntadd); (i++)) {
        (addTree[i] = left[addTree[i]]);
      }
      for (int i = 1; (i <= cntminus); (i++)) {
        (minusTree[i] = left[minusTree[i]]);
      }
      return Code05_DynamicRankings1::innerQuery(jobk, l, mid);
    } else {
      for (int i = 1; (i <= cntadd); (i++)) {
        (addTree[i] = right[addTree[i]]);
      }
      for (int i = 1; (i <= cntminus); (i++)) {
        (minusTree[i] = right[minusTree[i]]);
      }
      return Code05_DynamicRankings1::innerQuery((jobk - leftsum), (mid + 1),
                                                 r);
    }
  }
  static void add(int i, int cnt) {
    for (int j = i; (j <= n); (j += Code05_DynamicRankings1::lowbit(j))) {
      (root[j] = Code05_DynamicRankings1::innerAdd(arr[i], cnt, 1, s, root[j]));
    }
  }
  static void update(int i, int v) {
    Code05_DynamicRankings1::add(i, (-1));
    (arr[i] = Code05_DynamicRankings1::kth(v));
    Code05_DynamicRankings1::add(i, 1);
  }
  static int number(int l, int r, int k) {
    (cntadd = (cntminus = 0));
    for (int i = r; (i > 0); (i -= Code05_DynamicRankings1::lowbit(i))) {
      (addTree[(++cntadd)] = root[i]);
    }
    for (int i = (l - 1); (i > 0); (i -= Code05_DynamicRankings1::lowbit(i))) {
      (minusTree[(++cntminus)] = root[i]);
    }
    return sorted[Code05_DynamicRankings1::innerQuery(k, 1, s)];
  }
  static void prepare() {
    (s = 0);
    for (int i = 1; (i <= n); (i++)) {
      (sorted[(++s)] = arr[i]);
    }
    for (int i = 1; (i <= m); (i++)) {
      if ((ques[i][0] == 2)) {
        (sorted[(++s)] = ques[i][2]);
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
    for (int i = 1; (i <= n); (i++)) {
      (arr[i] = Code05_DynamicRankings1::kth(arr[i]));
      Code05_DynamicRankings1::add(i, 1);
    }
  }
  static void java_main(Array<String> args) {
    IO io = IO();
    (n = io.nextInt());
    (m = io.nextInt());
    for (int i = 1; (i <= n); (i++)) {
      (arr[i] = io.nextInt());
    }
    for (int i = 1; (i <= m); (i++)) {
      (ques[i][0] = (io.next().equals(String(u"Q")) ? 1 : 2));
      (ques[i][1] = io.nextInt());
      (ques[i][2] = io.nextInt());
      if ((ques[i][0] == 1)) {
        (ques[i][3] = io.nextInt());
      }
    }
    Code05_DynamicRankings1::prepare();
    {
      int i = 1;
      int op = {};
      int x = {};
      int y = {};
      int z = {};
      for (; (i <= m); (i++)) {
        (op = ques[i][0]);
        (x = ques[i][1]);
        (y = ques[i][2]);
        if ((op == 1)) {
          (z = ques[i][3]);
          io.println(Code05_DynamicRankings1::number(x, y, z));
        } else {
          Code05_DynamicRankings1::update(x, y);
        }
      }
    }
    io.flush();
    io.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code05_DynamicRankings1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 动态排名，java版
//
给定一个长度为n的数组arr，下标1~n，每条操作都是如下2种类型中的一种，一共进行m次操作
// 操作 Q x y z : 查询arr[x..y]中排第z名的数字
// 操作 C x y   : arr中x位置的数字改成y
// 1 <= n、m <= 10^5
// 数组中的值永远在[0, 10^9]范围内
// 测试链接 : https://www.luogu.com.cn/problem/P2617
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 读写工具类
*/

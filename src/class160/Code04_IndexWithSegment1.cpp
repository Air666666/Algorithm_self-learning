// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P3380

// Source: src/class160/Code04_IndexWithSegment1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_IndexWithSegment1 {
  inline static int MAXN = 200001;
  inline static int MAXT = (MAXN * 160);
  inline static int INF = std::numeric_limits<int>::max();
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
  Code04_IndexWithSegment1() {}
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
             Code04_IndexWithSegment1::innerAdd(jobi, jobv, l, mid, left[i]));
      } else {
        (right[i] = Code04_IndexWithSegment1::innerAdd(jobi, jobv, (mid + 1), r,
                                                       right[i]));
      }
      (sum[i] = (sum[left[i]] + sum[right[i]]));
    }
    return i;
  }
  static int innerSmall(int jobi, int l, int r) {
    if ((l == r)) {
      return 0;
    }
    int mid = jdiv((l + r), 2);
    if ((jobi <= mid)) {
      for (int i = 1; (i <= cntadd); (i++)) {
        (addTree[i] = left[addTree[i]]);
      }
      for (int i = 1; (i <= cntminus); (i++)) {
        (minusTree[i] = left[minusTree[i]]);
      }
      return Code04_IndexWithSegment1::innerSmall(jobi, l, mid);
    } else {
      int leftsum = 0;
      for (int i = 1; (i <= cntadd); (i++)) {
        (leftsum += sum[left[addTree[i]]]);
        (addTree[i] = right[addTree[i]]);
      }
      for (int i = 1; (i <= cntminus); (i++)) {
        (leftsum -= sum[left[minusTree[i]]]);
        (minusTree[i] = right[minusTree[i]]);
      }
      return (leftsum +
              Code04_IndexWithSegment1::innerSmall(jobi, (mid + 1), r));
    }
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
      return Code04_IndexWithSegment1::innerQuery(jobk, l, mid);
    } else {
      for (int i = 1; (i <= cntadd); (i++)) {
        (addTree[i] = right[addTree[i]]);
      }
      for (int i = 1; (i <= cntminus); (i++)) {
        (minusTree[i] = right[minusTree[i]]);
      }
      return Code04_IndexWithSegment1::innerQuery((jobk - leftsum), (mid + 1),
                                                  r);
    }
  }
  static void add(int i, int cnt) {
    for (int j = i; (j <= n); (j += Code04_IndexWithSegment1::lowbit(j))) {
      (root[j] =
           Code04_IndexWithSegment1::innerAdd(arr[i], cnt, 1, s, root[j]));
    }
  }
  static void update(int i, int v) {
    Code04_IndexWithSegment1::add(i, (-1));
    (arr[i] = Code04_IndexWithSegment1::kth(v));
    Code04_IndexWithSegment1::add(i, 1);
  }
  static int small(int l, int r, int v) {
    (cntadd = (cntminus = 0));
    for (int i = r; (i > 0); (i -= Code04_IndexWithSegment1::lowbit(i))) {
      (addTree[(++cntadd)] = root[i]);
    }
    for (int i = (l - 1); (i > 0); (i -= Code04_IndexWithSegment1::lowbit(i))) {
      (minusTree[(++cntminus)] = root[i]);
    }
    return Code04_IndexWithSegment1::innerSmall(v, 1, s);
  }
  static int number(int l, int r, int k) {
    (cntadd = (cntminus = 0));
    for (int i = r; (i > 0); (i -= Code04_IndexWithSegment1::lowbit(i))) {
      (addTree[(++cntadd)] = root[i]);
    }
    for (int i = (l - 1); (i > 0); (i -= Code04_IndexWithSegment1::lowbit(i))) {
      (minusTree[(++cntminus)] = root[i]);
    }
    return sorted[Code04_IndexWithSegment1::innerQuery(k, 1, s)];
  }
  static int pre(int l, int r, int v) {
    int rank = (Code04_IndexWithSegment1::small(l, r, v) + 1);
    if ((rank == 1)) {
      return (-INF);
    }
    return Code04_IndexWithSegment1::number(l, r, (rank - 1));
  }
  static int post(int l, int r, int v) {
    if ((v == s)) {
      return INF;
    }
    int sml = Code04_IndexWithSegment1::small(l, r, (v + 1));
    if ((sml == ((r - l) + 1))) {
      return INF;
    }
    return Code04_IndexWithSegment1::number(l, r, (sml + 1));
  }
  static void prepare() {
    (s = 0);
    for (int i = 1; (i <= n); (i++)) {
      (sorted[(++s)] = arr[i]);
    }
    for (int i = 1; (i <= m); (i++)) {
      if ((ques[i][0] == 3)) {
        (sorted[(++s)] = ques[i][2]);
      } else if ((ques[i][0] != 2)) {
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
    for (int i = 1; (i <= n); (i++)) {
      (arr[i] = Code04_IndexWithSegment1::kth(arr[i]));
      Code04_IndexWithSegment1::add(i, 1);
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
    for (int i = 1; (i <= n); (i++)) {
      in.nextToken();
      (arr[i] = static_cast<int>(in.nval));
    }
    for (int i = 1; (i <= m); (i++)) {
      in.nextToken();
      (ques[i][0] = static_cast<int>(in.nval));
      in.nextToken();
      (ques[i][1] = static_cast<int>(in.nval));
      in.nextToken();
      (ques[i][2] = static_cast<int>(in.nval));
      if ((ques[i][0] != 3)) {
        in.nextToken();
        (ques[i][3] = static_cast<int>(in.nval));
      }
    }
    Code04_IndexWithSegment1::prepare();
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
        if ((op == 3)) {
          Code04_IndexWithSegment1::update(x, y);
        } else {
          (z = ques[i][3]);
          if ((op == 1)) {
            out.println((Code04_IndexWithSegment1::small(
                             x, y, Code04_IndexWithSegment1::kth(z)) +
                         1));
          } else if ((op == 2)) {
            out.println(Code04_IndexWithSegment1::number(x, y, z));
          } else if ((op == 4)) {
            out.println(Code04_IndexWithSegment1::pre(
                x, y, Code04_IndexWithSegment1::kth(z)));
          } else {
            out.println(Code04_IndexWithSegment1::post(
                x, y, Code04_IndexWithSegment1::kth(z)));
          }
        }
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
  Code04_IndexWithSegment1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 树状数组套线段树，java版
//
给定一个长度为n的数组arr，下标1~n，每条操作都是如下5种类型中的一种，一共进行m次操作
// 操作 1 x y z : 查询数字z在arr[x..y]中的排名
// 操作 2 x y z : 查询arr[x..y]中排第z名的数字
// 操作 3 x y   : arr中x位置的数字改成y
// 操作 4 x y z : 查询数字z在arr[x..y]中的前驱，不存在返回-2147483647
// 操作 5 x y z : 查询数字z在arr[x..y]中的后继，不存在返回+2147483647
// 1 <= n、m <= 2 * 10^5
// 数组中的值永远在[0, 10^8]范围内
// 测试链接 : https://www.luogu.com.cn/problem/P3380
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
// 本题之后增加了测试用例，数据范围放大到 2 * 10^5
// 树状数组套线段树的java实现和C++实现都能通过
        //
第jobi小的数字，增加jobv的计数，数字范围l~r，节点编号i，返回头节点编号
        // 查询比jobi小的数字个数，数字范围l~r
        // 不需要头节点编号，因为有多棵树，所有的头节点记录在addTree、minusTree
        // 查询第jobk小的数字，数字范围l~r
        // 不需要头节点编号，因为有多棵树，所有的头节点记录在addTree、minusTree
        // arr中i下标的数字，增加cnt的计数
        // arr中i下标的数字，改成v
        // arr[l..r]范围上，比v小的数字个数
        // arr[l..r]范围上，查询第k小的数字是什么
        // arr[l..r]范围上，查询v的前驱
        // arr[l..r]范围上，查询v的后继
*/

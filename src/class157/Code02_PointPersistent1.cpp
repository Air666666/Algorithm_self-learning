// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P3834

// Source: src/class157/Code02_PointPersistent1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_PointPersistent1 {
  inline static int MAXN = 200001;
  inline static int MAXT = (MAXN * 22);
  inline static int n = {};
  inline static int m = {};
  inline static int s = {};
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static Array<int> sorted = make_array<int>(MAXN);
  inline static Array<int> root = make_array<int>(MAXN);
  inline static Array<int> left = make_array<int>(MAXT);
  inline static Array<int> right = make_array<int>(MAXT);
  inline static Array<int> size = make_array<int>(MAXT);
  inline static int cnt = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_PointPersistent1() {}
  static int kth(int num) {
    int left = 1;
    int right = s;
    int mid = {};
    int ans = 0;
    while ((left <= right)) {
      (mid = jdiv((left + right), 2));
      if ((sorted[mid] <= num)) {
        (ans = mid);
        (left = (mid + 1));
      } else {
        (right = (mid - 1));
      }
    }
    return ans;
  }
  static int build(int l, int r) {
    int rt = (++cnt);
    (size[rt] = 0);
    if ((l < r)) {
      int mid = jdiv((l + r), 2);
      (left[rt] = Code02_PointPersistent1::build(l, mid));
      (right[rt] = Code02_PointPersistent1::build((mid + 1), r));
    }
    return rt;
  }
  static int insert(int jobi, int l, int r, int i) {
    int rt = (++cnt);
    (left[rt] = left[i]);
    (right[rt] = right[i]);
    (size[rt] = (size[i] + 1));
    if ((l < r)) {
      int mid = jdiv((l + r), 2);
      if ((jobi <= mid)) {
        (left[rt] = Code02_PointPersistent1::insert(jobi, l, mid, left[rt]));
      } else {
        (right[rt] =
             Code02_PointPersistent1::insert(jobi, (mid + 1), r, right[rt]));
      }
    }
    return rt;
  }
  static int query(int jobk, int l, int r, int u, int v) {
    if ((l == r)) {
      return l;
    }
    int lsize = (size[left[v]] - size[left[u]]);
    int mid = jdiv((l + r), 2);
    if ((lsize >= jobk)) {
      return Code02_PointPersistent1::query(jobk, l, mid, left[u], left[v]);
    } else {
      return Code02_PointPersistent1::query((jobk - lsize), (mid + 1), r,
                                            right[u], right[v]);
    }
  }
  static void prepare() {
    (cnt = 0);
    for (int i = 1; (i <= n); (i++)) {
      (sorted[i] = arr[i]);
    }
    j::sort(sorted, 1, (n + 1));
    (s = 1);
    for (int i = 2; (i <= n); (i++)) {
      if ((sorted[s] != sorted[i])) {
        (sorted[(++s)] = sorted[i]);
      }
    }
    (root[0] = Code02_PointPersistent1::build(1, s));
    {
      int i = 1;
      int x = {};
      for (; (i <= n); (i++)) {
        (x = Code02_PointPersistent1::kth(arr[i]));
        (root[i] = Code02_PointPersistent1::insert(x, 1, s, root[(i - 1)]));
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
    for (int i = 1; (i <= n); (i++)) {
      in.nextToken();
      (arr[i] = static_cast<int>(in.nval));
    }
    Code02_PointPersistent1::prepare();
    {
      int i = 1;
      int l = {};
      int r = {};
      int k = {};
      int rank = {};
      for (; (i <= m); (i++)) {
        in.nextToken();
        (l = static_cast<int>(in.nval));
        in.nextToken();
        (r = static_cast<int>(in.nval));
        in.nextToken();
        (k = static_cast<int>(in.nval));
        (rank =
             Code02_PointPersistent1::query(k, 1, s, root[(l - 1)], root[r]));
        out.println(sorted[rank]);
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
  Code02_PointPersistent1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 单点修改的可持久化线段树模版题2，java版
// 给定一个长度为n的数组arr，下标1~n，一共有m条查询
// 每条查询 l r k : 打印arr[l..r]中第k小的数字
// 1 <= n、m <= 2 * 10^5
// 0 <= arr[i] <= 10^9
// 测试链接 : https://www.luogu.com.cn/problem/P3834
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 原始数组
        // 收集权值排序并且去重做离散化
        // 可持久化线段树需要
        // root[i] : 插入arr[i]之后形成新版本的线段树，记录头节点编号
        // 0号版本的线段树代表一个数字也没有时，每种名次的数字出现的次数
        // i号版本的线段树代表arr[1..i]范围内，每种名次的数字出现的次数
        // 排名范围内收集了多少个数字
        // 返回num在所有值中排名多少
        // 排名范围l~r，建立线段树，返回头节点编号
        // 排名范围l~r，信息在i号节点，增加一个排名为jobi的数字
        // 返回新的头节点编号
        // 排名范围l~r，老版本信息在u号节点，新版本信息在v号节点
        // 返回，第jobk小的数字，排名多少
        // 权值做离散化并且去重 + 生成各版本的线段树
*/

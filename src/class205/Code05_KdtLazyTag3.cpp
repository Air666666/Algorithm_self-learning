// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P14312

// Source: src/class205/Code05_KdtLazyTag3.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code05_KdtLazyTag3 {
  inline static int MAXN = 200001;
  inline static int MAXP = 19;
  inline static int MAXK = 3;
  inline static i64 INF = jshl(1LL, 60);
  inline static int k = {};
  inline static int m = {};
  inline static Array<Array<i64>> pos = make_array<i64>(MAXN, MAXK);
  inline static Array<i64> val = make_array<i64>(MAXN);
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static Array<i64> qx = make_array<i64>(MAXK);
  inline static Array<i64> qy = make_array<i64>(MAXK);
  inline static i64 qv = {};
  inline static int cntkdt = {};
  inline static Array<int> root = make_array<int>(MAXP);
  inline static Array<int> ls = make_array<int>(MAXN);
  inline static Array<int> rs = make_array<int>(MAXN);
  inline static Array<int> siz = make_array<int>(MAXN);
  inline static Array<i64> sum = make_array<i64>(MAXN);
  inline static Array<Array<i64>> minv = make_array<i64>(MAXN, MAXK);
  inline static Array<Array<i64>> maxv = make_array<i64>(MAXN, MAXK);
  inline static Array<i64> addTag = make_array<i64>(MAXN);
  inline static int first = {};
  inline static int last = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code05_KdtLazyTag3() {}
  static void maintain(int i) {
    (siz[i] = ((1 + siz[ls[i]]) + siz[rs[i]]));
    (sum[i] = ((val[i] + sum[ls[i]]) + sum[rs[i]]));
    for (int d = 0; (d < k); (d++)) {
      (minv[i][d] = jmin(pos[i][d], jmin(minv[ls[i]][d], minv[rs[i]][d])));
      (maxv[i][d] = jmax(pos[i][d], jmax(maxv[ls[i]][d], maxv[rs[i]][d])));
    }
  }
  static void lazy(int i, i64 v) {
    if ((i != 0)) {
      (val[i] += v);
      (sum[i] += (v * siz[i]));
      (addTag[i] += v);
    }
  }
  static void down(int i) {
    if ((addTag[i] != 0)) {
      Code05_KdtLazyTag3::lazy(ls[i], addTag[i]);
      Code05_KdtLazyTag3::lazy(rs[i], addTag[i]);
      (addTag[i] = 0);
    }
  }
  static int compareNode(int i, int j, int dimension) {
    i64 v1 = pos[i][dimension];
    i64 v2 = pos[j][dimension];
    return ((v1 == v2) ? 0 : ((v1 < v2) ? (-1) : 1));
  }
  static void swap(int i, int j) {
    int tmp = arr[i];
    (arr[i] = arr[j]);
    (arr[j] = tmp);
  }
  static void partition(int l, int r, int pidx, int dimension) {
    (first = l);
    (last = r);
    int i = l;
    while ((i <= last)) {
      int cmp = Code05_KdtLazyTag3::compareNode(arr[i], pidx, dimension);
      if ((cmp == 0)) {
        (i++);
      } else if ((cmp < 0)) {
        [&]() {
          auto jargument_0 = (first++);
          auto jargument_1 = (i++);
          return Code05_KdtLazyTag3::swap(jargument_0, jargument_1);
        }();
      } else {
        Code05_KdtLazyTag3::swap(i, (last--));
      }
    }
  }
  static void randSelect(int l, int r, int i, int dimension) {
    while ((l <= r)) {
      int pidx = arr[(l + static_cast<int>((j::random() * ((r - l) + 1))))];
      Code05_KdtLazyTag3::partition(l, r, pidx, dimension);
      if ((i < first)) {
        (r = (first - 1));
      } else if ((i > last)) {
        (l = (last + 1));
      } else {
        break;
      }
    }
  }
  static int build(int l, int r, int dimension) {
    if ((l > r)) {
      return 0;
    }
    int mid = jshr((l + r), 1);
    Code05_KdtLazyTag3::randSelect(l, r, mid, dimension);
    int rt = arr[mid];
    (ls[rt] =
         Code05_KdtLazyTag3::build(l, (mid - 1), jrem((dimension + 1), k)));
    (rs[rt] =
         Code05_KdtLazyTag3::build((mid + 1), r, jrem((dimension + 1), k)));
    Code05_KdtLazyTag3::maintain(rt);
    return rt;
  }
  static void dfs(int i) {
    if ((i != 0)) {
      Code05_KdtLazyTag3::down(i);
      Code05_KdtLazyTag3::dfs(ls[i]);
      Code05_KdtLazyTag3::dfs(rs[i]);
    }
  }
  static void addNode() {
    (cntkdt++);
    for (int d = 0; (d < k); (d++)) {
      (pos[cntkdt][d] = qx[d]);
    }
    (val[cntkdt] = qv);
    (arr[cntkdt] = cntkdt);
    int p = 0;
    while ((root[p] != 0)) {
      Code05_KdtLazyTag3::dfs(root[p]);
      (root[(p++)] = 0);
    }
    (root[p] =
         Code05_KdtLazyTag3::build(((cntkdt - jshl(1, p)) + 1), cntkdt, 0));
  }
  static bool outside(int i) {
    for (int d = 0; (d < k); (d++)) {
      if (((maxv[i][d] < qx[d]) || (qy[d] < minv[i][d]))) {
        return true;
      }
    }
    return false;
  }
  static bool covered(int i) {
    for (int d = 0; (d < k); (d++)) {
      if (((qx[d] > minv[i][d]) || (qy[d] < maxv[i][d]))) {
        return false;
      }
    }
    return true;
  }
  static bool pointIn(int i) {
    for (int d = 0; (d < k); (d++)) {
      if (((qx[d] > pos[i][d]) || (qy[d] < pos[i][d]))) {
        return false;
      }
    }
    return true;
  }
  static void addValue(int i) {
    if ((i == 0)) {
      return;
    }
    if (Code05_KdtLazyTag3::outside(i)) {
      return;
    }
    if (Code05_KdtLazyTag3::covered(i)) {
      Code05_KdtLazyTag3::lazy(i, qv);
      return;
    }
    if (Code05_KdtLazyTag3::pointIn(i)) {
      (val[i] += qv);
    }
    Code05_KdtLazyTag3::down(i);
    Code05_KdtLazyTag3::addValue(ls[i]);
    Code05_KdtLazyTag3::addValue(rs[i]);
    Code05_KdtLazyTag3::maintain(i);
  }
  static void addValue() {
    for (int p = 0; (p < MAXP); (p++)) {
      Code05_KdtLazyTag3::addValue(root[p]);
    }
  }
  static i64 querySum(int i) {
    if ((i == 0)) {
      return 0;
    }
    if (Code05_KdtLazyTag3::outside(i)) {
      return 0;
    }
    if (Code05_KdtLazyTag3::covered(i)) {
      return sum[i];
    }
    i64 ans = 0;
    if (Code05_KdtLazyTag3::pointIn(i)) {
      (ans += val[i]);
    }
    Code05_KdtLazyTag3::down(i);
    (ans += Code05_KdtLazyTag3::querySum(ls[i]));
    (ans += Code05_KdtLazyTag3::querySum(rs[i]));
    return ans;
  }
  static i64 querySum() {
    i64 ans = 0;
    for (int p = 0; (p < MAXP); (p++)) {
      (ans += Code05_KdtLazyTag3::querySum(root[p]));
    }
    return ans;
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (k = in.nextInt());
    (m = in.nextInt());
    for (int d = 0; (d < k); (d++)) {
      (minv[0][d] = INF);
      (maxv[0][d] = (-INF));
    }
    i64 lastAns = 0;
    {
      int i = 1;
      int op = {};
      for (; (i <= m); (i++)) {
        (op = in.nextInt());
        if ((op == 1)) {
          for (int d = 0; (d < k); (d++)) {
            (qx[d] = in.nextLong());
            (qx[d] ^= lastAns);
          }
          (qv = in.nextLong());
          (qv ^= lastAns);
          Code05_KdtLazyTag3::addNode();
        } else {
          for (int d = 0; (d < k); (d++)) {
            (qx[d] = in.nextLong());
            (qx[d] ^= lastAns);
          }
          for (int d = 0; (d < k); (d++)) {
            (qy[d] = in.nextLong());
            (qy[d] ^= lastAns);
          }
          if ((op == 2)) {
            (qv = in.nextLong());
            (qv ^= lastAns);
            Code05_KdtLazyTag3::addValue();
          } else {
            (lastAns = Code05_KdtLazyTag3::querySum());
            out.println(lastAns);
          }
        }
      }
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code05_KdtLazyTag3::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// K-D树结合懒更新，二进制分组的方式，java版
// 点的坐标有k维，点还有点权，k维空间中的轴对齐区域，可以用两个对角点表示
// 一共有m条操作，类型如下
// 操作 1 qx qv    : 空间里增加一个点，qx是k个值表示点的坐标，qv表示点权
// 操作 2 qx qy qv :
区域的两个对角点qx和qy，各自有k个值的坐标，该区域所有点的点权增加qv
// 操作 3 qx qy    :
区域的两个对角点qx和qy，各自有k个值的坐标，打印该区域所有点的点权和
// 本题要求强制在线，得到操作参数的规则，打开测试链接查看
// 2 <= k <= 3
// 1 <= m <= 10^5
// 坐标、点权、答案都需要long类型
// 测试链接 : https://www.luogu.com.cn/problem/P14312
// 提交以下的code，提交时请把类名改成"Main"，本题卡空间，java实现无法通过
// 想通过用C++实现，本节课Code05_KdtLazyTag4文件就是C++的实现
// 两个版本的逻辑完全一样，C++版本可以通过所有测试
        // 分组的树中，懒更新全部下发到底
        // 二进制分组的方式加入节点
                        // 合并更大的分组之前，需要先处理懒更新
        // 每棵分树都要修改
        // 每棵分树都要查询
        // 读写工具类
*/

// Source: src/class182/Code02_Minimax1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_Minimax1 {
  inline static int MAXN = 300001;
  inline static int MAXT = (MAXN * 40);
  inline static int MOD = 998244353;
  inline static int n = {};
  inline static Array<int> fa = make_array<int>(MAXN);
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static Array<int> sorted = make_array<int>(MAXN);
  inline static int cntv = {};
  inline static Array<int> sonCnt = make_array<int>(MAXN);
  inline static Array<Array<int>> son = make_array<int>(MAXN, 2);
  inline static Array<int> root = make_array<int>(MAXN);
  inline static Array<int> ls = make_array<int>(MAXT);
  inline static Array<int> rs = make_array<int>(MAXT);
  inline static Array<i64> sum = make_array<i64>(MAXT);
  inline static Array<i64> mulLazy = make_array<i64>(MAXT);
  inline static int cntt = {};
  inline static Array<i64> D = make_array<i64>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_Minimax1() {}
  static i64 power(i64 x, int p) {
    i64 ans = 1;
    while ((p != 0)) {
      if (((p & 1) != 0)) {
        (ans = jrem((ans * x), MOD));
      }
      (p = jshr(p, 1));
      (x = jrem((x * x), MOD));
    }
    return ans;
  }
  static int kth(int num) {
    int left = 1;
    int right = cntv;
    int mid = {};
    int ret = 0;
    while ((left <= right)) {
      (mid = jshr((left + right), 1));
      if ((sorted[mid] <= num)) {
        (ret = mid);
        (left = (mid + 1));
      } else {
        (right = (mid - 1));
      }
    }
    return ret;
  }
  static void up(int i) { (sum[i] = jrem((sum[ls[i]] + sum[rs[i]]), MOD)); }
  static void lazy(int i, i64 v) {
    if ((i != 0)) {
      (sum[i] = jrem((sum[i] * v), MOD));
      (mulLazy[i] = jrem((mulLazy[i] * v), MOD));
    }
  }
  static void down(int i) {
    if ((mulLazy[i] != 1)) {
      Code02_Minimax1::lazy(ls[i], mulLazy[i]);
      Code02_Minimax1::lazy(rs[i], mulLazy[i]);
      (mulLazy[i] = 1);
    }
  }
  static int insert(int jobi, int l, int r, int i) {
    int rt = i;
    if ((rt == 0)) {
      (rt = (++cntt));
      (mulLazy[rt] = 1);
    }
    if ((l == r)) {
      (sum[rt] = 1);
    } else {
      Code02_Minimax1::down(rt);
      int mid = jshr((l + r), 1);
      if ((jobi <= mid)) {
        (ls[rt] = Code02_Minimax1::insert(jobi, l, mid, ls[rt]));
      } else {
        (rs[rt] = Code02_Minimax1::insert(jobi, (mid + 1), r, rs[rt]));
      }
      Code02_Minimax1::up(rt);
    }
    return rt;
  }
  static int merge(int l, int r, int t1, int t2, int p, i64 sum1, i64 sum2) {
    if (((t1 == 0) || (t2 == 0))) {
      if ((t1 != 0)) {
        Code02_Minimax1::lazy(t1, sum2);
      }
      if ((t2 != 0)) {
        Code02_Minimax1::lazy(t2, sum1);
      }
      return (t1 + t2);
    }
    if ((l == r)) {
      (sum[t1] = jrem(
           (jrem((sum[t1] * sum2), MOD) + jrem((sum[t2] * sum1), MOD)), MOD));
    } else {
      Code02_Minimax1::down(t1);
      Code02_Minimax1::down(t2);
      int mid = jshr((l + r), 1);
      i64 lsum1 = jrem((sum1 + (sum[rs[t1]] * ((1 - p) + MOD))), MOD);
      i64 lsum2 = jrem((sum2 + (sum[rs[t2]] * ((1 - p) + MOD))), MOD);
      i64 rsum1 = jrem((sum1 + (sum[ls[t1]] * p)), MOD);
      i64 rsum2 = jrem((sum2 + (sum[ls[t2]] * p)), MOD);
      (ls[t1] =
           Code02_Minimax1::merge(l, mid, ls[t1], ls[t2], p, lsum1, lsum2));
      (rs[t1] = Code02_Minimax1::merge((mid + 1), r, rs[t1], rs[t2], p, rsum1,
                                       rsum2));
      Code02_Minimax1::up(t1);
    }
    return t1;
  }
  static void dp1(int u) {
    if ((sonCnt[u] == 0)) {
      (root[u] = Code02_Minimax1::insert(arr[u], 1, cntv, root[u]));
    } else if ((sonCnt[u] == 1)) {
      Code02_Minimax1::dp1(son[u][0]);
      (root[u] = root[son[u][0]]);
    } else {
      Code02_Minimax1::dp1(son[u][0]);
      Code02_Minimax1::dp1(son[u][1]);
      (root[u] = Code02_Minimax1::merge(1, cntv, root[son[u][0]],
                                        root[son[u][1]], arr[u], 0, 0));
    }
  }
  static void dp2() {
    Array<Array<int>> stack = make_array<int>((n + 1), 2);
    int siz = 0;
    (stack[(++siz)][0] = 1);
    (stack[siz][1] = 0);
    while ((siz > 0)) {
      int u = stack[siz][0];
      int s = stack[(siz--)][1];
      if ((sonCnt[u] == 0)) {
        (root[u] = Code02_Minimax1::insert(arr[u], 1, cntv, root[u]));
      } else if ((sonCnt[u] == 1)) {
        if ((s == 0)) {
          (stack[(++siz)][0] = u);
          (stack[siz][1] = 1);
          (stack[(++siz)][0] = son[u][0]);
          (stack[siz][1] = 0);
        } else {
          (root[u] = root[son[u][0]]);
        }
      } else {
        if ((s == 0)) {
          (stack[(++siz)][0] = u);
          (stack[siz][1] = 1);
          (stack[(++siz)][0] = son[u][1]);
          (stack[siz][1] = 0);
          (stack[(++siz)][0] = son[u][0]);
          (stack[siz][1] = 0);
        } else {
          (root[u] = Code02_Minimax1::merge(1, cntv, root[son[u][0]],
                                            root[son[u][1]], arr[u], 0, 0));
        }
      }
    }
  }
  static void getd(int l, int r, int i) {
    if ((i == 0)) {
      return;
    }
    if ((l == r)) {
      (D[l] = jrem(sum[i], MOD));
    } else {
      Code02_Minimax1::down(i);
      int mid = jshr((l + r), 1);
      Code02_Minimax1::getd(l, mid, ls[i]);
      Code02_Minimax1::getd((mid + 1), r, rs[i]);
    }
  }
  static void prepare() {
    for (int i = 1; (i <= n); (i++)) {
      if ((fa[i] != 0)) {
        (son[fa[i]][(sonCnt[fa[i]]++)] = i);
      }
    }
    i64 inv = Code02_Minimax1::power(10000, (MOD - 2));
    for (int i = 1; (i <= n); (i++)) {
      if ((sonCnt[i] == 0)) {
        (sorted[(++cntv)] = arr[i]);
      } else {
        (arr[i] = static_cast<int>(jrem((inv * arr[i]), MOD)));
      }
    }
    j::sort(sorted, 1, (cntv + 1));
    int len = 1;
    for (int i = 2; (i <= cntv); (i++)) {
      if ((sorted[len] != sorted[i])) {
        (sorted[(++len)] = sorted[i]);
      }
    }
    (cntv = len);
    for (int i = 1; (i <= n); (i++)) {
      if ((sonCnt[i] == 0)) {
        (arr[i] = Code02_Minimax1::kth(arr[i]));
      }
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    for (int i = 1; (i <= n); (i++)) {
      (fa[i] = in.nextInt());
    }
    for (int i = 1; (i <= n); (i++)) {
      (arr[i] = in.nextInt());
    }
    Code02_Minimax1::prepare();
    Code02_Minimax1::dp2();
    Code02_Minimax1::getd(1, cntv, root[1]);
    i64 ans = 0;
    for (int i = 1; (i <= cntv); (i++)) {
      (ans =
           jrem((ans + (jrem((jrem(((1LL * i) * sorted[i]), MOD) * D[i]), MOD) *
                        D[i])),
                MOD));
    }
    out.println(ans);
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code02_Minimax1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 根节点的取值，java版
// 一共有n个节点，1号节点是整棵树的头，所有节点组成一棵树
//
给定一个长度为n的数组arr，如果节点x是叶，那么arr[x]表示点权，所有叶节点的点权都不同
//
如果节点x不是叶，那么它最多有两个孩子，此时arr[x]代表概率，节点x按照以下规则取得点权
// 以arr[x]的概率是所有儿子的点权最大值，以1 -
arr[x]的概率是所有儿子的点权最小值
// 表示概率时，arr[x]的范围是[1, 9999]，表示概率 0.0001 ~ 0.9999
// 假设1号结点的权值有m种可能性，第i小的权值是Vi，取得概率为Di
// 计算 i = 1..m 时，每一项 (i * Vi * Di * Di) 的累加和，答案对 998244353 取模
// 1 <= n <= 3 * 10^5    1 <= 叶节点权值 <= 10^9    1 <= 概率 <= 9999
// 测试链接 : https://www.luogu.com.cn/problem/P5298
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 迭代版，java会爆栈，C++可以通过
        // dp1改成迭代版
                // dp1(1);
        // 读写工具类
*/

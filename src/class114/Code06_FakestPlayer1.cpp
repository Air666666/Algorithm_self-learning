// Source: src/class114/Code06_FakestPlayer1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code06_FakestPlayer1 {
  inline static int MAXN = 500001;
  inline static int INF = 1000000001;
  inline static int n = {};
  inline static int m = {};
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static Array<i64> sum = make_array<i64>(jshl(MAXN, 2));
  inline static Array<int> max = make_array<int>(jshl(MAXN, 2));
  inline static Array<int> cntMax = make_array<int>(jshl(MAXN, 2));
  inline static Array<int> sem = make_array<int>(jshl(MAXN, 2));
  inline static Array<int> min = make_array<int>(jshl(MAXN, 2));
  inline static Array<int> cntMin = make_array<int>(jshl(MAXN, 2));
  inline static Array<int> sim = make_array<int>(jshl(MAXN, 2));
  inline static Array<int> addTag = make_array<int>(jshl(MAXN, 2));
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code06_FakestPlayer1() {}
  static void up(int i) {
    int l = jshl(i, 1);
    int r = (jshl(i, 1) | 1);
    (sum[i] = (sum[l] + sum[r]));
    if ((max[l] > max[r])) {
      (max[i] = max[l]);
      (cntMax[i] = cntMax[l]);
      (sem[i] = jmax(sem[l], max[r]));
    } else if ((max[l] < max[r])) {
      (max[i] = max[r]);
      (cntMax[i] = cntMax[r]);
      (sem[i] = jmax(max[l], sem[r]));
    } else {
      (max[i] = max[l]);
      (cntMax[i] = (cntMax[l] + cntMax[r]));
      (sem[i] = jmax(sem[l], sem[r]));
    }
    if ((min[l] < min[r])) {
      (min[i] = min[l]);
      (cntMin[i] = cntMin[l]);
      (sim[i] = jmin(sim[l], min[r]));
    } else if ((min[l] > min[r])) {
      (min[i] = min[r]);
      (cntMin[i] = cntMin[r]);
      (sim[i] = jmin(min[l], sim[r]));
    } else {
      (min[i] = min[l]);
      (cntMin[i] = (cntMin[l] + cntMin[r]));
      (sim[i] = jmin(sim[l], sim[r]));
    }
  }
  static void lazyAdd(int i, int n, int v) {
    (sum[i] += ((1LL * v) * n));
    (max[i] += v);
    (sem[i] += ((sem[i] == (-INF)) ? 0 : v));
    (min[i] += v);
    (sim[i] += ((sim[i] == INF) ? 0 : v));
    (addTag[i] += v);
  }
  static void lazySetMin(int i, int v) {
    (sum[i] += ((1LL * (v - max[i])) * cntMax[i]));
    if ((min[i] == max[i])) {
      (min[i] = v);
    } else if ((sim[i] == max[i])) {
      (sim[i] = v);
    }
    (max[i] = v);
  }
  static void lazySetMax(int i, int v) {
    (sum[i] += ((1LL * (v - min[i])) * cntMin[i]));
    if ((max[i] == min[i])) {
      (max[i] = v);
    } else if ((sem[i] == min[i])) {
      (sem[i] = v);
    }
    (min[i] = v);
  }
  static void down(int i, int ln, int rn) {
    int l = jshl(i, 1);
    int r = (jshl(i, 1) | 1);
    if ((addTag[i] != 0)) {
      Code06_FakestPlayer1::lazyAdd(l, ln, addTag[i]);
      Code06_FakestPlayer1::lazyAdd(r, rn, addTag[i]);
      (addTag[i] = 0);
    }
    if ((max[l] > max[i])) {
      Code06_FakestPlayer1::lazySetMin(l, max[i]);
    }
    if ((min[l] < min[i])) {
      Code06_FakestPlayer1::lazySetMax(l, min[i]);
    }
    if ((max[r] > max[i])) {
      Code06_FakestPlayer1::lazySetMin(r, max[i]);
    }
    if ((min[r] < min[i])) {
      Code06_FakestPlayer1::lazySetMax(r, min[i]);
    }
  }
  static void build(int l, int r, int i) {
    if ((l == r)) {
      (sum[i] = (max[i] = (min[i] = arr[l])));
      (sem[i] = (-INF));
      (sim[i] = INF);
      (cntMax[i] = (cntMin[i] = 1));
    } else {
      int mid = jshr((l + r), 1);
      Code06_FakestPlayer1::build(l, mid, jshl(i, 1));
      Code06_FakestPlayer1::build((mid + 1), r, (jshl(i, 1) | 1));
      Code06_FakestPlayer1::up(i);
    }
    (addTag[i] = 0);
  }
  static void add(int jobl, int jobr, int jobv, int l, int r, int i) {
    if (((jobl <= l) && (r <= jobr))) {
      Code06_FakestPlayer1::lazyAdd(i, ((r - l) + 1), jobv);
    } else {
      int mid = jshr((l + r), 1);
      Code06_FakestPlayer1::down(i, ((mid - l) + 1), (r - mid));
      if ((jobl <= mid)) {
        Code06_FakestPlayer1::add(jobl, jobr, jobv, l, mid, jshl(i, 1));
      }
      if ((jobr > mid)) {
        Code06_FakestPlayer1::add(jobl, jobr, jobv, (mid + 1), r,
                                  (jshl(i, 1) | 1));
      }
      Code06_FakestPlayer1::up(i);
    }
  }
  static void setMax(int jobl, int jobr, int jobv, int l, int r, int i) {
    if ((jobv <= min[i])) {
      return;
    }
    if ((((jobl <= l) && (r <= jobr)) && (jobv < sim[i]))) {
      Code06_FakestPlayer1::lazySetMax(i, jobv);
    } else {
      int mid = jshr((l + r), 1);
      Code06_FakestPlayer1::down(i, ((mid - l) + 1), (r - mid));
      if ((jobl <= mid)) {
        Code06_FakestPlayer1::setMax(jobl, jobr, jobv, l, mid, jshl(i, 1));
      }
      if ((jobr > mid)) {
        Code06_FakestPlayer1::setMax(jobl, jobr, jobv, (mid + 1), r,
                                     (jshl(i, 1) | 1));
      }
      Code06_FakestPlayer1::up(i);
    }
  }
  static void setMin(int jobl, int jobr, int jobv, int l, int r, int i) {
    if ((jobv >= max[i])) {
      return;
    }
    if ((((jobl <= l) && (r <= jobr)) && (sem[i] < jobv))) {
      Code06_FakestPlayer1::lazySetMin(i, jobv);
    } else {
      int mid = jshr((l + r), 1);
      Code06_FakestPlayer1::down(i, ((mid - l) + 1), (r - mid));
      if ((jobl <= mid)) {
        Code06_FakestPlayer1::setMin(jobl, jobr, jobv, l, mid, jshl(i, 1));
      }
      if ((jobr > mid)) {
        Code06_FakestPlayer1::setMin(jobl, jobr, jobv, (mid + 1), r,
                                     (jshl(i, 1) | 1));
      }
      Code06_FakestPlayer1::up(i);
    }
  }
  static i64 querySum(int jobl, int jobr, int l, int r, int i) {
    if (((jobl <= l) && (r <= jobr))) {
      return sum[i];
    } else {
      int mid = jshr((l + r), 1);
      Code06_FakestPlayer1::down(i, ((mid - l) + 1), (r - mid));
      i64 ans = 0;
      if ((jobl <= mid)) {
        (ans += Code06_FakestPlayer1::querySum(jobl, jobr, l, mid, jshl(i, 1)));
      }
      if ((jobr > mid)) {
        (ans += Code06_FakestPlayer1::querySum(jobl, jobr, (mid + 1), r,
                                               (jshl(i, 1) | 1)));
      }
      return ans;
    }
  }
  static int queryMax(int jobl, int jobr, int l, int r, int i) {
    if (((jobl <= l) && (r <= jobr))) {
      return max[i];
    } else {
      int mid = jshr((l + r), 1);
      Code06_FakestPlayer1::down(i, ((mid - l) + 1), (r - mid));
      int ans = (-INF);
      if ((jobl <= mid)) {
        (ans = jmax(ans, Code06_FakestPlayer1::queryMax(jobl, jobr, l, mid,
                                                        jshl(i, 1))));
      }
      if ((jobr > mid)) {
        (ans = jmax(ans, Code06_FakestPlayer1::queryMax(jobl, jobr, (mid + 1),
                                                        r, (jshl(i, 1) | 1))));
      }
      return ans;
    }
  }
  static int queryMin(int jobl, int jobr, int l, int r, int i) {
    if (((jobl <= l) && (r <= jobr))) {
      return min[i];
    } else {
      int mid = jshr((l + r), 1);
      Code06_FakestPlayer1::down(i, ((mid - l) + 1), (r - mid));
      int ans = INF;
      if ((jobl <= mid)) {
        (ans = jmin(ans, Code06_FakestPlayer1::queryMin(jobl, jobr, l, mid,
                                                        jshl(i, 1))));
      }
      if ((jobr > mid)) {
        (ans = jmin(ans, Code06_FakestPlayer1::queryMin(jobl, jobr, (mid + 1),
                                                        r, (jshl(i, 1) | 1))));
      }
      return ans;
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    for (int i = 1; (i <= n); (i++)) {
      (arr[i] = in.nextInt());
    }
    Code06_FakestPlayer1::build(1, n, 1);
    (m = in.nextInt());
    {
      int i = 1;
      int op = {};
      int l = {};
      int r = {};
      int x = {};
      for (; (i <= m); (i++)) {
        (op = in.nextInt());
        (l = in.nextInt());
        (r = in.nextInt());
        if ((op == 1)) {
          (x = in.nextInt());
          Code06_FakestPlayer1::add(l, r, x, 1, n, 1);
        } else if ((op == 2)) {
          (x = in.nextInt());
          Code06_FakestPlayer1::setMax(l, r, x, 1, n, 1);
        } else if ((op == 3)) {
          (x = in.nextInt());
          Code06_FakestPlayer1::setMin(l, r, x, 1, n, 1);
        } else if ((op == 4)) {
          out.println(Code06_FakestPlayer1::querySum(l, r, 1, n, 1));
        } else if ((op == 5)) {
          out.println(Code06_FakestPlayer1::queryMax(l, r, 1, n, 1));
        } else {
          out.println(Code06_FakestPlayer1::queryMin(l, r, 1, n, 1));
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
  Code06_FakestPlayer1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 最假女选手，java版
// 这道题课上没讲，也是吉司机线段树的经典模版题
// 这道题不涉及历史最值，所以比题目5简单
// 如果理解了题目5，完全可以看懂如下的代码，重点的地方我加了注释
// 给定一个长度为n的数组arr，然后是m条操作，类型如下
// 操作 1 l r x : arr[l..r]范围内，每个数都加上x
// 操作 2 l r x : arr[l..r]范围内，小于x的数都变成x
// 操作 3 l r x : arr[l..r]范围内，大于x的数都变成x
// 操作 4 l r   : 查询arr[l..r]累加和
// 操作 5 l r   : 查询arr[l..r]最大值
// 操作 6 l r   : 查询arr[l..r]最小值
// 1 <= n、m <= 5 * 10^5    累加和需要long类型
// 测试链接 : https://loj.ac/p/6565
// 测试链接 : https://www.luogu.com.cn/problem/P10639
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 区间最小值
        // 区间最小值的个数
        // 区间严格次小值
        // 整个区间统一增加的懒信息
        // 只把当前区间中的最大值压到v，要求sem[i] < v < max[i]
        // 只把当前区间中的最小值抬到v，要求min[i] < v < sim[i]
        // 读写工具类
*/

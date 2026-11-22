// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P4602

// Source: src/class169/Code01_Juice1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_Juice1 {
  inline static int MAXN = 100001;
  inline static int n = {};
  inline static int m = {};
  inline static Array<Array<int>> juice = make_array<int>(MAXN, 3);
  inline static Array<int> qid = make_array<int>(MAXN);
  inline static Array<i64> money = make_array<i64>(MAXN);
  inline static Array<i64> least = make_array<i64>(MAXN);
  inline static int maxp = 0;
  inline static Array<i64> suml = make_array<i64>(jshl(MAXN, 2));
  inline static Array<i64> cost = make_array<i64>(jshl(MAXN, 2));
  inline static int used = 0;
  inline static Array<int> lset = make_array<int>(MAXN);
  inline static Array<int> rset = make_array<int>(MAXN);
  inline static Array<int> ans = make_array<int>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_Juice1() {}
  static void up(int i) {
    (suml[i] = (suml[jshl(i, 1)] + suml[(jshl(i, 1) | 1)]));
    (cost[i] = (cost[jshl(i, 1)] + cost[(jshl(i, 1) | 1)]));
  }
  static void add(int jobi, int jobv, int l, int r, int i) {
    if ((l == r)) {
      (suml[i] += jobv);
      (cost[i] = (suml[i] * l));
    } else {
      int mid = jshr((l + r), 1);
      if ((jobi <= mid)) {
        Code01_Juice1::add(jobi, jobv, l, mid, jshl(i, 1));
      } else {
        Code01_Juice1::add(jobi, jobv, (mid + 1), r, (jshl(i, 1) | 1));
      }
      Code01_Juice1::up(i);
    }
  }
  static i64 query(i64 volume, int l, int r, int i) {
    if ((l == r)) {
      return (volume * l);
    }
    int mid = jshr((l + r), 1);
    if ((suml[jshl(i, 1)] >= volume)) {
      return Code01_Juice1::query(volume, l, mid, jshl(i, 1));
    } else {
      return (cost[jshl(i, 1)] +
              Code01_Juice1::query((volume - suml[jshl(i, 1)]), (mid + 1), r,
                                   (jshl(i, 1) | 1)));
    }
  }
  static void compute(int ql, int qr, int vl, int vr) {
    if ((ql > qr)) {
      return;
    }
    if ((vl == vr)) {
      for (int i = ql; (i <= qr); (i++)) {
        (ans[qid[i]] = vl);
      }
    } else {
      int mid = jshr((vl + vr), 1);
      while ((used < mid)) {
        (used++);
        Code01_Juice1::add(juice[used][1], juice[used][2], 1, maxp, 1);
      }
      while ((used > mid)) {
        Code01_Juice1::add(juice[used][1], (-juice[used][2]), 1, maxp, 1);
        (used--);
      }
      int lsiz = 0;
      int rsiz = 0;
      {
        int i = ql;
        int id = {};
        for (; (i <= qr); (i++)) {
          (id = qid[i]);
          if (((suml[1] >= least[id]) &&
               (Code01_Juice1::query(least[id], 1, maxp, 1) <= money[id]))) {
            (lset[(++lsiz)] = id);
          } else {
            (rset[(++rsiz)] = id);
          }
        }
      }
      for (int i = 1; (i <= lsiz); (i++)) {
        (qid[((ql + i) - 1)] = lset[i]);
      }
      for (int i = 1; (i <= rsiz); (i++)) {
        (qid[(((ql + lsiz) + i) - 1)] = rset[i]);
      }
      Code01_Juice1::compute(ql, ((ql + lsiz) - 1), vl, mid);
      Code01_Juice1::compute((ql + lsiz), qr, (mid + 1), vr);
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (m = in.nextInt());
    for (int i = 1; (i <= n); (i++)) {
      (juice[i][0] = in.nextInt());
      (juice[i][1] = in.nextInt());
      (juice[i][2] = in.nextInt());
      (maxp = jmax(maxp, juice[i][1]));
    }
    for (int i = 1; (i <= m); (i++)) {
      (qid[i] = i);
      (money[i] = in.nextLong());
      (least[i] = in.nextLong());
    }
    j::sort(juice, 1, (n + 1),
            [=](Array<int> a, Array<int> b) { return (b[0] - a[0]); });
    Code01_Juice1::compute(1, m, 1, (n + 1));
    for (int i = 1; (i <= m); (i++)) {
      if ((ans[i] == (n + 1))) {
        out.println((-1));
      } else {
        out.println(juice[ans[i]][0]);
      }
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code01_Juice1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 混合果汁，java版
// 一共有n种果汁，每种果汁给定，美味度d、每升价格p、添加上限l
//
制作混合果汁时每种果汁不能超过添加上限，其中美味度最低的果汁，决定混合果汁的美味度
// 一共有m个小朋友，给每位制作混合果汁时，钱数不超过money[i]，体积不少于least[i]
// 打印每个小朋友能得到的混合果汁最大美味度，如果无法满足，打印-1
// 1 <= n、m、d、p、l <= 10^5
// 1 <= money[i]、least[i] <= 10^18
// 测试链接 : https://www.luogu.com.cn/problem/P4602
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 果汁有三个参数，美味度d、每升价格p、添加上限l
        // 记录所有小朋友的编号
        // 小朋友能花的钱数
        // 小朋友至少的果汁量
        // 这种使用线段树的方式叫线段树二分
        // 讲解146的题目2，也涉及线段树二分
        // 果汁单价作为下标的线段树
        // maxp为最大的果汁单价
        // suml[i] : 线段树某单价区间上，允许添加的总量
        // cost[i] : 线段树某单价区间上，如果允许添加的总量全要，花费多少钱
        // 多少种果汁加入了线段树
        // 整体二分的过程需要
        // 每个小朋友的答案，是第几号果汁的美味度
        // 单价为jobi，现在允许添加的量增加了jobv
        // 总体积一共volume，已知总体积一定能耗尽
        // 返回总体积耗尽的情况下，能花的最少钱数
                        // 线段树包含果汁的种类少就添加
                        // 线段树包含果汁的种类多就撤销
                // 所有果汁按照美味度排序，美味度大的在前，美味度小的在后
                // 答案范围就是美味度范围，从最美味的第1名，到最难喝的第n名
                // 如果小朋友答案为n+1，说明无法满足这个小朋友
        // 读写工具类
*/

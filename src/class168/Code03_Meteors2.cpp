// Source: src/class168/Code03_Meteors2.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_Meteors2 {
  inline static int MAXN = 300001;
  inline static int n = {};
  inline static int m = {};
  inline static int k = {};
  inline static Array<int> qid = make_array<int>(MAXN);
  inline static Array<int> need = make_array<int>(MAXN);
  inline static Array<int> rainl = make_array<int>(MAXN);
  inline static Array<int> rainr = make_array<int>(MAXN);
  inline static Array<int> num = make_array<int>(MAXN);
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> next = make_array<int>(MAXN);
  inline static Array<int> to = make_array<int>(MAXN);
  inline static int cnt = 0;
  inline static Array<i64> tree = make_array<i64>(jshl(MAXN, 1));
  inline static int used = 0;
  inline static Array<int> lset = make_array<int>(MAXN);
  inline static Array<int> rset = make_array<int>(MAXN);
  inline static Array<int> ans = make_array<int>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_Meteors2() {}
  static void addEdge(int i, int v) {
    (next[(++cnt)] = head[i]);
    (to[cnt] = v);
    (head[i] = cnt);
  }
  static int lowbit(int i) { return (i & (-i)); }
  static void add(int i, int v) {
    int siz = (m * 2);
    while ((i <= siz)) {
      (tree[i] += v);
      (i += Code03_Meteors2::lowbit(i));
    }
  }
  static void add(int l, int r, int v) {
    Code03_Meteors2::add(l, v);
    Code03_Meteors2::add((r + 1), (-v));
  }
  static i64 query(int i) {
    i64 ret = 0;
    while ((i > 0)) {
      (ret += tree[i]);
      (i -= Code03_Meteors2::lowbit(i));
    }
    return ret;
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
      int lsiz = 0;
      int rsiz = 0;
      while ((used < mid)) {
        (used++);
        Code03_Meteors2::add(rainl[used], rainr[used], num[used]);
      }
      while ((used > mid)) {
        Code03_Meteors2::add(rainl[used], rainr[used], (-num[used]));
        (used--);
      }
      for (int i = ql; (i <= qr); (i++)) {
        int id = qid[i];
        i64 satisfy = 0;
        for (int e = head[id]; (e > 0); (e = next[e])) {
          (satisfy += [&]() {
            auto jleft = Code03_Meteors2::query(to[e]);
            auto jright = Code03_Meteors2::query((to[e] + m));
            return (jleft + jright);
          }());
          if ((satisfy >= need[id])) {
            break;
          }
        }
        if ((satisfy >= need[id])) {
          (lset[(++lsiz)] = id);
        } else {
          (rset[(++rsiz)] = id);
        }
      }
      for (int i = 1; (i <= lsiz); (i++)) {
        (qid[((ql + i) - 1)] = lset[i]);
      }
      for (int i = 1; (i <= rsiz); (i++)) {
        (qid[(((ql + lsiz) + i) - 1)] = rset[i]);
      }
      Code03_Meteors2::compute(ql, ((ql + lsiz) - 1), vl, mid);
      Code03_Meteors2::compute((ql + lsiz), qr, (mid + 1), vr);
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (m = in.nextInt());
    {
      int i = 1;
      int nation = {};
      for (; (i <= m); (i++)) {
        (nation = in.nextInt());
        Code03_Meteors2::addEdge(nation, i);
      }
    }
    for (int i = 1; (i <= n); (i++)) {
      (qid[i] = i);
      (need[i] = in.nextInt());
    }
    (k = in.nextInt());
    for (int i = 1; (i <= k); (i++)) {
      (rainl[i] = in.nextInt());
      (rainr[i] = in.nextInt());
      if ((rainr[i] < rainl[i])) {
        (rainr[i] += m);
      }
      (num[i] = in.nextInt());
    }
    Code03_Meteors2::compute(1, n, 1, (k + 1));
    for (int i = 1; (i <= n); (i++)) {
      if ((ans[i] == (k + 1))) {
        out.println(String(u"NIE"));
      } else {
        out.println(ans[i]);
      }
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code03_Meteors2::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 陨石雨，第二种写法，java版
// 一共有n个国家，给定n个数字，表示每个国家希望收集到的陨石数量
// 一共有m个区域，1号区顺时针到2号区...m号区顺时针到1号区，即环形相连
// 每个区域只属于某一个国家，给定m个数字，表示每个区域归属给哪个国家
// 接下来会依次发生k场陨石雨，陨石雨格式 l r num，含义如下
// 从l号区顺时针到r号区发生了陨石雨，每个区域都增加num个陨石
// 打印每个国家经历前几场陨石雨，可以达到收集要求，如果无法满足，打印"NIE"
// 1 <= n、m、k <= 3 * 10^5    1 <= 陨石数量 <= 10^9
// 测试链接 : https://www.luogu.com.cn/problem/P3527
// 提交以下的code，提交时请把类名改成"Main"
// java实现的逻辑一定是正确的，但无法通过所有测试用例，内存使用过大
// 因为这道题只考虑C++能通过的空间极限，根本没考虑java的用户
// 想通过用C++实现，本节课Code03_Meteors4文件就是C++的实现
// 两个版本的逻辑完全一样，C++版本可以通过所有测试
        // 下了多少场陨石雨
        // 读写工具类
*/

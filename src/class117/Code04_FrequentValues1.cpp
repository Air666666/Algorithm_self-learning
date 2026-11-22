// Source: src/class117/Code04_FrequentValues1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_FrequentValues1 {
  inline static int MAXN = 100001;
  inline static int LIMIT = 17;
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static Array<int> log2 = make_array<int>(MAXN);
  inline static Array<int> bucket = make_array<int>(MAXN);
  inline static Array<int> left = make_array<int>(MAXN);
  inline static Array<int> right = make_array<int>(MAXN);
  inline static Array<Array<int>> stmax = make_array<int>(MAXN, LIMIT);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_FrequentValues1() {}
  static void build(int n) {
    (arr[0] = (-23333333));
    int cnt = 0;
    for (int i = 1; (i <= n); (i++)) {
      if ((arr[(i - 1)] != arr[i])) {
        (right[cnt] = (i - 1));
        (left[(++cnt)] = i);
      }
      (bucket[i] = cnt);
    }
    (right[cnt] = n);
    (log2[0] = (-1));
    for (int i = 1; (i <= cnt); (i++)) {
      (log2[i] = (log2[jshr(i, 1)] + 1));
      (stmax[i][0] = ((right[i] - left[i]) + 1));
    }
    for (int p = 1; (p <= log2[cnt]); (p++)) {
      for (int i = 1; (((i + jshl(1, p)) - 1) <= cnt); (i++)) {
        (stmax[i][p] =
             jmax(stmax[i][(p - 1)], stmax[(i + jshl(1, (p - 1)))][(p - 1)]));
      }
    }
  }
  static int query(int l, int r) {
    if ((l > r)) {
      int tmp = l;
      (l = r);
      (r = tmp);
    }
    int lbucket = bucket[l];
    int rbucket = bucket[r];
    if ((lbucket == rbucket)) {
      return ((r - l) + 1);
    }
    int a = ((right[lbucket] - l) + 1);
    int b = ((r - left[rbucket]) + 1);
    int c = 0;
    if (((lbucket + 1) < rbucket)) {
      int from = (lbucket + 1);
      int to = (rbucket - 1);
      int p = log2[((to - from) + 1)];
      (c = jmax(stmax[from][p], stmax[((to - jshl(1, p)) + 1)][p]));
    }
    return jmax(jmax(a, b), c);
  }
  static void java_main(Array<String> args) {
    jout.println(String(u"测试开始"));
    int n = 10000;
    int v = 100;
    int m = 5000;
    Code04_FrequentValues1::randomArray(n, v);
    Code04_FrequentValues1::build(n);
    {
      int i = 1;
      int l = {};
      int r = {};
      for (; (i <= m); (i++)) {
        (l = (static_cast<int>((j::random() * n)) + 1));
        (r = (static_cast<int>((j::random() * n)) + 1));
        if ([&]() {
              auto jleft = Code04_FrequentValues1::query(l, r);
              auto jright = Code04_FrequentValues1::checkQuery(l, r);
              return (jleft != jright);
            }()) {
          jout.println(String(u"出错了!"));
        }
      }
    }
    jout.println(String(u"测试结束"));
  }
  static void randomArray(int n, int v) {
    for (int i = 1; (i <= n); (i++)) {
      (arr[i] = (static_cast<int>(((j::random() * 2) * v)) - v));
    }
    j::sort(arr, 1, (n + 1));
  }
  static int checkQuery(int l, int r) {
    if ((l > r)) {
      int tmp = l;
      (l = r);
      (r = tmp);
    }
    JMap<int, int> map = JMap<int, int>();
    for (int i = l; (i <= r); (i++)) {
      map.put(arr[i], (map.getOrDefault(arr[i], 0) + 1));
    }
    int ans = 0;
    for (int v : map.values()) {
      (ans = jmax(ans, v));
    }
    return ans;
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code04_FrequentValues1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 出现次数最多的数有几个
// 给定一个长度为n的数组arr，该数组一定是有序的
// 一共有m次查询，每次查询arr[l~r]上出现次数最多的数有几个
// 对数器验证
                // 题目给定的数值范围-100000 ~ +100000
                // 把arr[0]设置成不会到达的数字即可
                // a : 最左侧桶在此时l~r范围上的数字有几个
                // b : 最右侧桶在此时l~r范围上的数字有几个
        // 对数器
        // 为了验证
        // 得到随机数组
        // 为了验证
        // 暴力方法
        // 直接遍历统计词频
        // 为了验证
*/

// Source: src/class129/Code04_FindNear.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_FindNear {
  inline static int MAXN = 10001;
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static int n = {};
  inline static Array<int> to1 = make_array<int>(MAXN);
  inline static Array<int> dist1 = make_array<int>(MAXN);
  inline static Array<int> to2 = make_array<int>(MAXN);
  inline static Array<int> dist2 = make_array<int>(MAXN);
  inline static Array<Array<int>> rank = make_array<int>(MAXN, 2);
  inline static Array<int> last = make_array<int>(MAXN);
  inline static Array<int> next = make_array<int>(MAXN);
  inline static Array<int> a = make_array<int>(MAXN);
  inline static Array<int> b = make_array<int>(MAXN);
  inline static Array<int> c = make_array<int>(MAXN);
  inline static Array<int> d = make_array<int>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_FindNear() {}
  static void near1() {
    JSet<Array<int>> set = JSet<Array<int>>(
        [=](Array<int> a, Array<int> b) { return (a[1] - b[1]); });
    for (int i = n; (i >= 1); (i--)) {
      (to1[i] = 0);
      (dist1[i] = 0);
      (to2[i] = 0);
      (dist2[i] = 0);
      Array<int> cur = Array<int>{i, arr[i]};
      Array<int> p1 = set.floor(cur);
      Array<int> p2 =
          ((p1 != nullptr) ? set.floor(Array<int>{p1[0], (p1[1] - 1)})
                           : nullptr);
      Array<int> p3 = set.ceiling(cur);
      Array<int> p4 =
          ((p3 != nullptr) ? set.ceiling(Array<int>{p3[0], (p3[1] + 1)})
                           : nullptr);
      Code04_FindNear::update(i, ((p1 != nullptr) ? p1[0] : 0));
      Code04_FindNear::update(i, ((p2 != nullptr) ? p2[0] : 0));
      Code04_FindNear::update(i, ((p3 != nullptr) ? p3[0] : 0));
      Code04_FindNear::update(i, ((p4 != nullptr) ? p4[0] : 0));
      set.add(cur);
    }
  }
  static void near2() {
    for (int i = 1; (i <= n); (i++)) {
      (rank[i][0] = i);
      (rank[i][1] = arr[i]);
    }
    j::sort(rank, 1, (n + 1),
            [=](Array<int> a, Array<int> b) { return (a[1] - b[1]); });
    (rank[0][0] = 0);
    (rank[(n + 1)][0] = 0);
    for (int i = 1; (i <= n); (i++)) {
      (last[rank[i][0]] = rank[(i - 1)][0]);
      (next[rank[i][0]] = rank[(i + 1)][0]);
    }
    for (int i = 1; (i <= n); (i++)) {
      (to1[i] = 0);
      (dist1[i] = 0);
      (to2[i] = 0);
      (dist2[i] = 0);
      Code04_FindNear::update(i, last[i]);
      Code04_FindNear::update(i, last[last[i]]);
      Code04_FindNear::update(i, next[i]);
      Code04_FindNear::update(i, next[next[i]]);
      Code04_FindNear::delete_method(i);
    }
  }
  static void update(int i, int j) {
    if ((j == 0)) {
      return;
    }
    int dist = std::abs((arr[i] - arr[j]));
    if ((((to1[i] == 0) || (dist < dist1[i])) ||
         ((dist == dist1[i]) && (arr[j] < arr[to1[i]])))) {
      (to2[i] = to1[i]);
      (dist2[i] = dist1[i]);
      (to1[i] = j);
      (dist1[i] = dist);
    } else if ((((to2[i] == 0) || (dist < dist2[i])) ||
                ((dist == dist2[i]) && (arr[j] < arr[to2[i]])))) {
      (to2[i] = j);
      (dist2[i] = dist);
    }
  }
  static void delete_method(int i) {
    int l = last[i];
    int r = next[i];
    if ((l != 0)) {
      (next[l] = r);
    }
    if ((r != 0)) {
      (last[r] = l);
    }
  }
  static void random(int v) {
    JHashSet<int> set = JHashSet<int>();
    {
      int i = 1;
      int cur = {};
      for (; (i <= n); (i++)) {
        do {
          (cur = (static_cast<int>(((j::random() * v) * 2)) - v));
        } while (set.contains(cur));
        set.add(cur);
        (arr[i] = cur);
      }
    }
  }
  static bool check() {
    Code04_FindNear::near1();
    for (int i = 1; (i <= n); (i++)) {
      (a[i] = to1[i]);
      (b[i] = dist1[i]);
      (c[i] = to2[i]);
      (d[i] = dist2[i]);
    }
    Code04_FindNear::near2();
    for (int i = 1; (i <= n); (i++)) {
      if (((a[i] != to1[i]) || (b[i] != dist1[i]))) {
        return false;
      }
    }
    for (int i = 1; (i <= n); (i++)) {
      if (((c[i] != to2[i]) || (d[i] != dist2[i]))) {
        return false;
      }
    }
    return true;
  }
  static void java_main(Array<String> args) {
    (n = 100);
    int v = 500;
    int testTime = 10000;
    jout.println(String(u"测试开始"));
    for (int i = 1; (i <= testTime); (i++)) {
      Code04_FindNear::random(v);
      if ((!Code04_FindNear::check())) {
        jout.println(String(u"出错了!"));
      }
    }
    jout.println(String(u"测试结束"));
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code04_FindNear::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 寻找最近和次近
// 给定一个长度为n的数组arr，下标1 ~ n范围，数组无重复值
// 关于近的定义，距离的定义如下:
// 对i位置的数字x来说，只关注右侧的数字，和x的差值绝对值越小就越近
// 距离为差值绝对值，如果距离一样，数值越小的越近
// 数值 : 3 5 7 1
// 下标 : 1 2 3 4
// 对1位置的数字3来说，第一近是4位置的1，距离为2；第二近是2位置的5，距离为2
// 每个位置的数字都求第一近的位置及其距离、第二近的位置及其距离
// 分别用to1、dist1、to2、dist2数组表示，0表示不存在
// 有序表的实现 + 数组手搓双向链表的实现
// 对数器验证
        // 如下三个数组只有near2方法需要
        // 有序表的实现
        // 数组手搓双向链表的实现
        // i位置右侧的j位置
        // 看看能不能更新i右侧的最近或者次近
        // 如果j==0则不更新
        // 双向链表中删掉i位置
        // 随机生成arr[1...n]确保没有重复数值
        // 为了测试
        // 如下四个数组用来做备份
        // 验证的过程
        // 为了测试
                // near1方法会设置to1、dist1、to2、dist2
                // 把near1方法的结果备份
                // near2方法会再次设置to1、dist1、to2、dist2
                // a、b、c、d，是near1生成的结果
                // to1、dist1、to2、dist2，是near2生成的结果
        // 对数器
        // 为了测试
                // 一定要确保arr中的数字无重复，所以让v大于n
*/

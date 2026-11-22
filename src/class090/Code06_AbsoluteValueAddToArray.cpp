// Source: src/class090/Code06_AbsoluteValueAddToArray.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code06_AbsoluteValueAddToArray {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code06_AbsoluteValueAddToArray() {}
  static int len1(Array<int> arr) {
    JList<int> list = JList<int>();
    JHashSet<int> set = JHashSet<int>();
    for (int num : arr) {
      list.add(num);
      set.add(num);
    }
    while ((!Code06_AbsoluteValueAddToArray::finish(list, set)))
      ;
    return list.size();
  }
  static bool finish(JList<int> list, JHashSet<int> set) {
    int len = list.size();
    for (int i = 0; (i < len); (i++)) {
      for (int j = (i + 1); (j < len); (j++)) {
        int abs = std::abs([&]() {
          auto jleft = list.get(i);
          auto jright = list.get(j);
          return (jleft - jright);
        }());
        if ((!set.contains(abs))) {
          list.add(abs);
          set.add(abs);
        }
      }
    }
    return (len == list.size());
  }
  static int len2(Array<int> arr) {
    int max = 0;
    int gcd = 0;
    for (int num : arr) {
      (max = jmax(max, num));
      if ((num != 0)) {
        (gcd = num);
      }
    }
    if ((gcd == 0)) {
      return arr.length;
    }
    JMap<int, int> cnts = JMap<int, int>();
    for (int num : arr) {
      if ((num != 0)) {
        (gcd = Code06_AbsoluteValueAddToArray::gcd(gcd, num));
      }
      cnts.put(num, (cnts.getOrDefault(num, 0) + 1));
    }
    int ans = jdiv(max, gcd);
    int maxCnt = 0;
    for (int key : cnts.keySet()) {
      if ((key != 0)) {
        (ans += (cnts.get(key) - 1));
      }
      (maxCnt = jmax(maxCnt, cnts.get(key)));
    }
    (ans += cnts.getOrDefault(0, ((maxCnt > 1) ? 1 : 0)));
    return ans;
  }
  static int gcd(int m, int n) {
    return ((n == 0) ? m : Code06_AbsoluteValueAddToArray::gcd(n, jrem(m, n)));
  }
  static Array<int> randomArray(int n, int v) {
    Array<int> ans = make_array<int>(n);
    for (int i = 0; (i < n); (i++)) {
      (ans[i] = static_cast<int>((j::random() * v)));
    }
    return ans;
  }
  static void java_main(Array<String> args) {
    int N = 50;
    int V = 100;
    int testTimes = 20000;
    jout.println(String(u"测试开始"));
    for (int i = 0; (i < testTimes); (i++)) {
      int n = (static_cast<int>((j::random() * N)) + 1);
      Array<int> nums = Code06_AbsoluteValueAddToArray::randomArray(n, V);
      int ans1 = Code06_AbsoluteValueAddToArray::len1(nums);
      int ans2 = Code06_AbsoluteValueAddToArray::len2(nums);
      if ((ans1 != ans2)) {
        jout.println(String(u"出错了！"));
      }
    }
    jout.println(String(u"测试结束"));
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code06_AbsoluteValueAddToArray::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 加入差值绝对值直到长度固定
// 给定一个非负数组arr，计算任何两个数差值的绝对值
// 如果arr中没有，都要加入到arr里，但是只加一份
// 然后新的arr继续计算任何两个数差值的绝对值，
// 如果arr中没有，都要加入到arr里，但是只加一份
// 一直到arr大小固定，返回arr最终的长度
// 来自真实大厂笔试，没有在线测试，对数器验证
        // 暴力方法
        // 为了验证
        // 正式方法
        // 时间复杂度O(n)
                // 找到任意一个非0的值
                // 不都是0
                // 0 7次
                // 5 5次
        // 为了测试
        // 为了测试
*/

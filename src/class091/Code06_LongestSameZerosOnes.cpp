// Source: src/class091/Code06_LongestSameZerosOnes.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code06_LongestSameZerosOnes {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code06_LongestSameZerosOnes() {}
  static int len1(Array<int> arr) {
    JMap<int, JMap<int, int>> map = JMap<int, JMap<int, int>>();
    for (int i = 0; (i < arr.length); (i++)) {
      int zero = 0;
      int one = 0;
      for (int j = i; (j < arr.length); (j++)) {
        (zero += ((arr[j] == 0) ? 1 : 0));
        (one += ((arr[j] == 1) ? 1 : 0));
        map.putIfAbsent(zero, JMap<int, int>());
        map.get(zero).put(one, (map.get(zero).getOrDefault(one, 0) + 1));
      }
    }
    int ans = 0;
    for (int zeros : map.keySet()) {
      for (int ones : map.get(zeros).keySet()) {
        int num = map.get(zeros).get(ones);
        if ((num > 1)) {
          (ans = jmax(ans, (zeros + ones)));
        }
      }
    }
    return ans;
  }
  static int len2(Array<int> arr) {
    int leftZero = (-1);
    int rightZero = (-1);
    int leftOne = (-1);
    int rightOne = (-1);
    for (int i = 0; (i < arr.length); (i++)) {
      if ((arr[i] == 0)) {
        (leftZero = i);
        break;
      }
    }
    for (int i = 0; (i < arr.length); (i++)) {
      if ((arr[i] == 1)) {
        (leftOne = i);
        break;
      }
    }
    for (int i = (arr.length - 1); (i >= 0); (i--)) {
      if ((arr[i] == 0)) {
        (rightZero = i);
        break;
      }
    }
    for (int i = (arr.length - 1); (i >= 0); (i--)) {
      if ((arr[i] == 1)) {
        (rightOne = i);
        break;
      }
    }
    int p1 = (rightZero - leftZero);
    int p2 = (rightOne - leftOne);
    return jmax(p1, p2);
  }
  static Array<int> randomArray(int len) {
    Array<int> ans = make_array<int>(len);
    for (int i = 0; (i < len); (i++)) {
      (ans[i] = static_cast<int>((j::random() * 2)));
    }
    return ans;
  }
  static void java_main(Array<String> args) {
    int N = 500;
    int testTimes = 2000;
    jout.println(String(u"测试开始"));
    for (int i = 1; (i <= testTimes); (i++)) {
      int n = (static_cast<int>((j::random() * N)) + 2);
      Array<int> arr = Code06_LongestSameZerosOnes::randomArray(n);
      int ans1 = Code06_LongestSameZerosOnes::len1(arr);
      int ans2 = Code06_LongestSameZerosOnes::len2(arr);
      if ((ans1 != ans2)) {
        jout.println(String(u"出错了!"));
      }
      if ((jrem(i, 100) == 0)) {
        jout.println(((String(u"测试到第") + i) + String(u"组")));
      }
    }
    jout.println(String(u"测试结束"));
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code06_LongestSameZerosOnes::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 两个0和1数量相等区间的最大长度
// 给出一个长度为n的01串，现在请你找到两个区间
// 使得这两个区间中，1的个数相等，0的个数也相等
// 这两个区间可以相交，但是不可以完全重叠，即两个区间的左右端点不可以完全一样
// 现在请你找到两个最长的区间，满足以上要求
// 返回区间最大长度
// 来自真实大厂笔试，没有在线测试，对数器验证
        // 暴力方法
        // 为了验证
        // 正式方法
        // 时间复杂度O(n)
        // 为了验证
        // 为了验证
*/

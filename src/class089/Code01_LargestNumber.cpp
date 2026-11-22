// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/largest-number/

// Source: src/class089/Code01_LargestNumber.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_LargestNumber {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_LargestNumber() {}
  static String way1(Array<String> strs) {
    JList<String> ans = JList<String>();
    Code01_LargestNumber::f(strs, 0, ans);
    ans.sort([=](String a, String b) { return a.compareTo(b); });
    return ans.get(0);
  }
  static void f(Array<String> strs, int i, JList<String> ans) {
    if ((i == strs.length)) {
      StringBuilder path = StringBuilder();
      for (String s : strs) {
        path.append(s);
      }
      ans.add(path.toString());
    } else {
      for (int j = i; (j < strs.length); (j++)) {
        Code01_LargestNumber::swap(strs, i, j);
        Code01_LargestNumber::f(strs, (i + 1), ans);
        Code01_LargestNumber::swap(strs, i, j);
      }
    }
  }
  static void swap(Array<String> strs, int i, int j) {
    String tmp = strs[i];
    (strs[i] = strs[j]);
    (strs[j] = tmp);
  }
  static String way2(Array<String> strs) {
    j::sort(strs,
            [=](String a, String b) { return (a + b).compareTo((b + a)); });
    StringBuilder path = StringBuilder();
    for (int i = 0; (i < strs.length); (i++)) {
      path.append(strs[i]);
    }
    return path.toString();
  }
  static Array<String> randomStringArray(int n, int m, int v) {
    Array<String> ans =
        make_array<String>((static_cast<int>((j::random() * n)) + 1));
    for (int i = 0; (i < ans.length); (i++)) {
      (ans[i] = Code01_LargestNumber::randomString(m, v));
    }
    return ans;
  }
  static String randomString(int m, int v) {
    int len = (static_cast<int>((j::random() * m)) + 1);
    Array<jchar> ans = make_array<jchar>(len);
    for (int i = 0; (i < len); (i++)) {
      (ans[i] =
           static_cast<jchar>((u'a' + static_cast<int>((j::random() * v)))));
    }
    return j::str(ans);
  }
  static void java_main(Array<String> args) {
    int n = 8;
    int m = 5;
    int v = 4;
    int testTimes = 2000;
    jout.println(String(u"测试开始"));
    for (int i = 1; (i <= testTimes); (i++)) {
      Array<String> strs = Code01_LargestNumber::randomStringArray(n, m, v);
      String ans1 = Code01_LargestNumber::way1(strs);
      String ans2 = Code01_LargestNumber::way2(strs);
      if ((!ans1.equals(ans2))) {
        jout.println(String(u"出错了！"));
      }
      if ((jrem(i, 100) == 0)) {
        jout.println(((String(u"测试到第") + i) + String(u"组")));
      }
    }
    jout.println(String(u"测试结束"));
  }
  static String largestNumber(Array<int> nums) {
    int n = nums.length;
    Array<String> strs = make_array<String>(n);
    for (int i = 0; (i < n); (i++)) {
      (strs[i] = j::str(nums[i]));
    }
    j::sort(strs,
            [=](String a, String b) { return (b + a).compareTo((a + b)); });
    if (strs[0].equals(String(u"0"))) {
      return String(u"0");
    }
    StringBuilder path = StringBuilder();
    for (String s : strs) {
      path.append(s);
    }
    return path.toString();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code01_LargestNumber::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 最大数
// 给定一组非负整数nums
// 重新排列每个数的顺序（每个数不可拆分）使之组成一个最大的整数
// 测试链接 : https://leetcode.cn/problems/largest-number/
        // strs中全是非空字符串，要把所有字符串拼接起来，形成字典序最小的结果
        // 暴力方法
        // 为了验证
        // 生成所有可能的排列
        // 其中选出字典序最小的结果
        // 全排列代码，讲解038，常见经典递归过程解析
        // strs中全是非空字符串，要把所有字符串拼接起来，形成字典序最小的结果
        // 正式方法
        // 时间复杂度O(n*logn)
        // 为了验证
        // 生成长度1~n的随机字符串数组
        // 为了验证
        // 生成长度1~m，字符种类有v种，随机字符串
        // 为了验证
        // 对数器
                                // 如果出错了
                                // 可以增加打印行为找到一组出错的例子
                                // 然后去debug
        // 测试链接 : https://leetcode.cn/problems/largest-number/
*/

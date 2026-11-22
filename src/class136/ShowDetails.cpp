// Source: src/class136/ShowDetails.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct ShowDetails {
  inline static int MAXN = 101;
  inline static int BIT = 60;
  inline static Array<i64> arr = make_array<i64>(MAXN);
  inline static int n = {};
  inline static Array<i64> basis1 = make_array<i64>((BIT + 1));
  inline static bool zero1 = {};
  inline static Array<i64> basis2 = make_array<i64>(MAXN);
  inline static int len = {};
  inline static bool zero2 = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  ShowDetails() {}
  static void compute1() {
    (zero1 = false);
    for (int i = 1; (i <= n); (i++)) {
      if ((!ShowDetails::insert(arr[i]))) {
        (zero1 = true);
      }
    }
  }
  static bool insert(i64 num) {
    for (int i = BIT; (i >= 0); (i--)) {
      if ((jshr(num, i) == 1)) {
        if ((basis1[i] == 0)) {
          (basis1[i] = num);
          return true;
        }
        (num ^= basis1[i]);
      }
    }
    return false;
  }
  static void compute2() {
    (len = 1);
    for (i64 i = BIT; (i >= 0); (i--)) {
      for (int j = len; (j <= n); (j++)) {
        if (((basis2[j] & jshl(1LL, i)) != 0)) {
          ShowDetails::swap(j, len);
          break;
        }
      }
      if (((basis2[len] & jshl(1LL, i)) != 0)) {
        for (int j = 1; (j <= n); (j++)) {
          if (((j != len) && ((basis2[j] & jshl(1LL, i)) != 0))) {
            (basis2[j] ^= basis2[len]);
          }
        }
        (len++);
      }
    }
    (len--);
    (zero2 = (len != n));
  }
  static void swap(int a, int b) {
    i64 tmp = basis2[a];
    (basis2[a] = basis2[b]);
    (basis2[b] = tmp);
  }
  static void java_main(Array<String> args) {
    jout.println(String(u"例子1"));
    j::fill(basis1, 0);
    (arr[1] = 12);
    (arr[2] = 9);
    (arr[3] = 14);
    (arr[4] = 11);
    (n = 4);
    jout.println(String(u"原始数组得到的异或结果如下"));
    ShowDetails::printXor(arr, n);
    jout.println(String(u"==========================="));
    jout.println(String(u"普通消元得到的线性基 : "));
    ShowDetails::compute1();
    Array<i64> b1 = make_array<i64>(MAXN);
    int s1 = 0;
    for (int i = BIT; (i >= 0); (i--)) {
      if ((basis1[i] != 0)) {
        jout.print((basis1[i] + String(u" ")));
        (b1[(++s1)] = basis1[i]);
      }
    }
    jout.println();
    jout.println((String(u"是否能异或出0 : ") + zero1));
    jout.println(String(u"普通消元得到的异或结果如下"));
    ShowDetails::printXor(b1, s1);
    jout.println(String(u"==========================="));
    jout.println();
    jout.println();
    jout.println(String(u"例子2"));
    j::fill(basis1, 0);
    (arr[1] = 2);
    (arr[2] = 5);
    (arr[3] = 11);
    (arr[4] = 6);
    (n = 4);
    jout.println(String(u"原始数组得到的异或结果如下"));
    ShowDetails::printXor(arr, n);
    jout.println(String(u"==========================="));
    jout.println(String(u"普通消元得到的线性基 : "));
    ShowDetails::compute1();
    Array<i64> b2 = make_array<i64>(MAXN);
    int s2 = 0;
    for (int i = BIT; (i >= 0); (i--)) {
      if ((basis1[i] != 0)) {
        jout.print((basis1[i] + String(u" ")));
        (b2[(++s2)] = basis1[i]);
      }
    }
    jout.println();
    jout.println((String(u"是否能异或出0 : ") + zero1));
    jout.println(String(u"普通消元得到的异或结果如下"));
    ShowDetails::printXor(b2, s2);
    jout.println(String(u"==========================="));
    jout.println();
    jout.println();
    jout.println(String(u"例子3"));
    j::fill(basis2, 0);
    (arr[1] = (basis2[1] = 6));
    (arr[2] = (basis2[2] = 37));
    (arr[3] = (basis2[3] = 35));
    (arr[4] = (basis2[4] = 33));
    (n = 4);
    jout.println(String(u"原始数组得到的异或结果如下"));
    ShowDetails::printXor(arr, n);
    jout.println(String(u"==========================="));
    jout.println(String(u"高斯消元得到的线性基 : "));
    ShowDetails::compute2();
    for (int i = 1; (i <= len); (i++)) {
      jout.print((basis2[i] + String(u" ")));
    }
    jout.println();
    jout.println((String(u"是否能异或出0 : ") + zero2));
    jout.println(String(u"高斯消元得到的异或结果如下"));
    ShowDetails::printXor(basis2, len);
    jout.println(String(u"==========================="));
    jout.println();
    jout.println();
    jout.println(String(u"例子4"));
    j::fill(basis1, 0);
    j::fill(basis2, 0);
    (arr[1] = (basis2[1] = 7));
    (arr[2] = (basis2[2] = 10));
    (arr[3] = (basis2[3] = 4));
    (n = 3);
    jout.println(String(u"原始数组得到的异或结果如下"));
    ShowDetails::printXor(arr, n);
    jout.println(String(u"==========================="));
    jout.println(String(u"普通消元"));
    ShowDetails::compute1();
    for (int i = BIT; (i >= 0); (i--)) {
      if ((basis1[i] != 0)) {
        jout.print((basis1[i] + String(u" ")));
      }
    }
    jout.println();
    jout.println((String(u"是否能异或出0 : ") + zero1));
    jout.println(String(u"==========================="));
    jout.println(String(u"高斯消元"));
    ShowDetails::compute2();
    for (int i = 1; (i <= len); (i++)) {
      jout.print((basis2[i] + String(u" ")));
    }
    jout.println();
    jout.println((String(u"是否能异或出0 : ") + zero2));
  }
  static void printXor(Array<i64> nums, int n) {
    JHashSet<i64> set = JHashSet<i64>();
    ShowDetails::dfs(nums, n, 1, false, 0, set);
    jout.println(String(u"至少选择一个数字所有可能的异或和:"));
    for (Box<i64> s : set) {
      jout.print((s + String(u", ")));
    }
    jout.println();
  }
  static void dfs(Array<i64> nums, int n, int i, bool pick, i64 path,
                  JHashSet<i64> set) {
    if ((i > n)) {
      if (pick) {
        set.add(path);
      }
    } else {
      ShowDetails::dfs(nums, n, (i + 1), pick, path, set);
      ShowDetails::dfs(nums, n, (i + 1), true, (path ^ nums[i]), set);
    }
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  ShowDetails::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 课上讲述普通消元、高斯消元构建异或空间线性基的例子
        // 最高位从哪开始
        // 普通消元
        // 线性基里插入num，如果线性基增加了返回true，否则返回false
        // 高斯消元
        // 因为不需要维护主元和自由元的依赖关系
        // 所以高斯消元的写法可以得到简化
                // 课上讲的普通消元，例子1
                // 12, 9, 14, 11
                // 课上讲的普通消元，例子2
                // 2, 5, 11, 6
                // 课上讲的高斯消元的例子，例子3
                // 6, 37, 35, 33
                // 课上讲的高斯消元的例子，例子4
                // 如果想得到第k小的非0异或和
                // 必须用高斯消元，不能用普通消元，比如
                // arr = { 7, 10, 4 }
                // 普通消元得到的异或空间线性基是 : 10 7 3
                // 第三小异或和是4，第四小异或和是10，这是错误的
                // 高斯消元可以得到正确结果
                // 高斯消元得到的异或空间线性基是 : 9 4 3
                // 第三小异或和是7，第四小异或和是9，这是正确的
        // nums中1~n的范围
        // 所有可能的异或和打印出来
        // 要求去重并且至少选择一个数字
        // 当前来到i位置
        // 之前是否选择过数字用pick表示
        // 之前做的决定形成的异或和是path
        // 当前i位置的数字要或者不要全决策
        // 收集所有可能的异或和
*/

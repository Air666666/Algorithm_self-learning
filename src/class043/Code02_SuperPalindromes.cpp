// Source: src/class043/Code02_SuperPalindromes.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_SuperPalindromes {
  inline static Array<i64> record = Array<i64>{1LL,
                                               4LL,
                                               9LL,
                                               121LL,
                                               484LL,
                                               10201LL,
                                               12321LL,
                                               14641LL,
                                               40804LL,
                                               44944LL,
                                               1002001LL,
                                               1234321LL,
                                               4008004LL,
                                               100020001LL,
                                               102030201LL,
                                               104060401LL,
                                               121242121LL,
                                               123454321LL,
                                               125686521LL,
                                               400080004LL,
                                               404090404LL,
                                               10000200001LL,
                                               10221412201LL,
                                               12102420121LL,
                                               12345654321LL,
                                               40000800004LL,
                                               1000002000001LL,
                                               1002003002001LL,
                                               1004006004001LL,
                                               1020304030201LL,
                                               1022325232201LL,
                                               1024348434201LL,
                                               1210024200121LL,
                                               1212225222121LL,
                                               1214428244121LL,
                                               1232346432321LL,
                                               1234567654321LL,
                                               4000008000004LL,
                                               4004009004004LL,
                                               100000020000001LL,
                                               100220141022001LL,
                                               102012040210201LL,
                                               102234363432201LL,
                                               121000242000121LL,
                                               121242363242121LL,
                                               123212464212321LL,
                                               123456787654321LL,
                                               400000080000004LL,
                                               10000000200000001LL,
                                               10002000300020001LL,
                                               10004000600040001LL,
                                               10020210401202001LL,
                                               10022212521222001LL,
                                               10024214841242001LL,
                                               10201020402010201LL,
                                               10203040504030201LL,
                                               10205060806050201LL,
                                               10221432623412201LL,
                                               10223454745432201LL,
                                               12100002420000121LL,
                                               12102202520220121LL,
                                               12104402820440121LL,
                                               12122232623222121LL,
                                               12124434743442121LL,
                                               12321024642012321LL,
                                               12323244744232321LL,
                                               12343456865434321LL,
                                               12345678987654321LL,
                                               40000000800000004LL,
                                               40004000900040004LL,
                                               1000000002000000001LL,
                                               1000220014100220001LL,
                                               1002003004003002001LL,
                                               1002223236323222001LL,
                                               1020100204020010201LL,
                                               1020322416142230201LL,
                                               1022123226223212201LL,
                                               1022345658565432201LL,
                                               1210000024200000121LL,
                                               1210242036302420121LL,
                                               1212203226223022121LL,
                                               1212445458545442121LL,
                                               1232100246420012321LL,
                                               1232344458544432321LL,
                                               1234323468643234321LL,
                                               4000000008000000004LL};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_SuperPalindromes() {}
  static int superpalindromesInRange1(String left, String right) {
    i64 l = std::stoll(text(left));
    i64 r = std::stoll(text(right));
    i64 limit = static_cast<i64>(std::sqrt(static_cast<double>(r)));
    i64 seed = 1;
    i64 num = 0;
    int ans = 0;
    do {
      (num = Code02_SuperPalindromes::evenEnlarge(seed));
      if (Code02_SuperPalindromes::check((num * num), l, r)) {
        (ans++);
      }
      (num = Code02_SuperPalindromes::oddEnlarge(seed));
      if (Code02_SuperPalindromes::check((num * num), l, r)) {
        (ans++);
      }
      (seed++);
    } while ((num < limit));
    return ans;
  }
  static i64 evenEnlarge(i64 seed) {
    i64 ans = seed;
    while ((seed != 0)) {
      (ans = ((ans * 10) + jrem(seed, 10)));
      (seed /= 10);
    }
    return ans;
  }
  static i64 oddEnlarge(i64 seed) {
    i64 ans = seed;
    (seed /= 10);
    while ((seed != 0)) {
      (ans = ((ans * 10) + jrem(seed, 10)));
      (seed /= 10);
    }
    return ans;
  }
  static bool check(i64 ans, i64 l, i64 r) {
    return (((ans >= l) && (ans <= r)) &&
            Code02_SuperPalindromes::isPalindrome(ans));
  }
  static bool isPalindrome(i64 num) {
    i64 offset = 1;
    while ((jdiv(num, offset) >= 10)) {
      (offset *= 10);
    }
    while ((num != 0)) {
      if ((jdiv(num, offset) != jrem(num, 10))) {
        return false;
      }
      (num = jdiv(jrem(num, offset), 10));
      (offset /= 100);
    }
    return true;
  }
  static int superpalindromesInRange2(String left, String right) {
    i64 l = std::stoll(text(left));
    i64 r = std::stoll(text(right));
    int i = 0;
    for (; (i < record.length); (i++)) {
      if ((record[i] >= l)) {
        break;
      }
    }
    int j = (record.length - 1);
    for (; (j >= 0); (j--)) {
      if ((record[j] <= r)) {
        break;
      }
    }
    return ((j - i) + 1);
  }
  static JList<i64> collect() {
    i64 l = 1;
    i64 r = std::numeric_limits<i64>::max();
    i64 limit = static_cast<i64>(std::sqrt(static_cast<double>(r)));
    i64 seed = 1;
    i64 enlarge = 0;
    JList<i64> ans = JList<i64>();
    do {
      (enlarge = Code02_SuperPalindromes::evenEnlarge(seed));
      if (Code02_SuperPalindromes::check((enlarge * enlarge), l, r)) {
        ans.add((enlarge * enlarge));
      }
      (enlarge = Code02_SuperPalindromes::oddEnlarge(seed));
      if (Code02_SuperPalindromes::check((enlarge * enlarge), l, r)) {
        ans.add((enlarge * enlarge));
      }
      (seed++);
    } while ((enlarge < limit));
    ans.sort([=](Box<i64> a, Box<i64> b) { return jcompare(a, b); });
    return ans;
  }
  static void java_main(Array<String> args) {
    JList<i64> ans = Code02_SuperPalindromes::collect();
    for (i64 p : ans) {
      jout.println((p + String(u"L,")));
    }
    jout.println((String(u"size : ") + ans.size()));
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code02_SuperPalindromes::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 超级回文数(java版)
//
如果一个正整数自身是回文数，而且它也是一个回文数的平方，那么我们称这个数为超级回文数。
// 现在，给定两个正整数 L 和 R （以字符串形式表示），
// 返回包含在范围 [L, R] 中的超级回文数的数目。
// 1 <= len(L) <= 18
// 1 <= len(R) <= 18
// L 和 R 是表示 [1, 10^18) 范围的整数的字符串
//测试链接 : https://leetcode.cn/problems/super-palindromes/
        // [left, right]有多少超级回文数
        // 返回数量
                // l....r  long
                // x根号，范围limit
                // seed : 枚举量很小，10^18 -> 10^9 -> 10^5
                // seed : 奇数长度回文、偶数长度回文
                // num : 根号x，num^2 -> x
                        //  seed生成偶数长度回文数字
                        // 123 -> 123321
                        //  seed生成奇数长度回文数字
                        // 123 -> 12321
                        // 123 -> 124 -> 125
        // 根据种子扩充到偶数长度的回文数字并返回
        // 根据种子扩充到奇数长度的回文数字并返回
        // 判断ans是不是属于[l,r]范围的回文数
        // 验证long类型的数字num，是不是回文数字
                // 注意这么写是为了防止溢出
                // num    : 52725
                // offset : 10000
                // 首尾判断
        // 打表的方法
        // 必然最优解
        // 连二分都懒得用
*/

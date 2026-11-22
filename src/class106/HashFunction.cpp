// Source: src/class106/HashFunction.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct HashFunction {
  struct Hash;
  struct Hash {
    MessageDigest md = {};
    String toString() const { return j::str(static_cast<const void *>(this)); }
    static void showAlgorithms() {
      for (String algorithm :
           Security::getAlgorithms(String(u"MessageDigest"))) {
        jout.println(algorithm);
      }
    }
    Hash(String algorithm) {
      try {
        (md = MessageDigest::getInstance(algorithm));
      } catch (Exception &e) {
        e.printStackTrace();
      }
    }
    String hashValue(String input) {
      Array<signed char> hashInBytes =
          md.digest(input.getBytes(StandardCharsets::UTF_8));
      BigInteger bigInt = BigInteger(1, hashInBytes);
      String hashText = bigInt.toString(16);
      return hashText;
    }
  };
  String toString() const { return j::str(static_cast<const void *>(this)); }
  HashFunction() {}
  static JList<String> generateStrings(Array<jchar> arr, int n) {
    Array<jchar> path = make_array<jchar>(n);
    JList<String> ans = JList<String>();
    HashFunction::f(arr, 0, n, path, ans);
    return ans;
  }
  static void f(Array<jchar> arr, int i, int n, Array<jchar> path,
                JList<String> ans) {
    if ((i == n)) {
      ans.add(j::str(path));
    } else {
      for (jchar cha : arr) {
        (path[i] = cha);
        HashFunction::f(arr, (i + 1), n, path, ans);
      }
    }
  }
  static void java_main(Array<String> args) {
    jout.println(String(u"支持的哈希算法 : "));
    Hash::showAlgorithms();
    jout.println();
    String algorithm = String(u"MD5");
    Hash *hash = new Hash(algorithm);
    String str1 = String(u"zuochengyunzuochengyunzuochengyun1");
    String str2 = String(u"zuochengyunzuochengyunzuochengyun2");
    String str3 = String(u"zuochengyunzuochengyunzuochengyun3");
    String str4 = String(u"zuochengyunzuochengyunZuochengyun1");
    String str5 = String(u"zuochengyunzuoChengyunzuochengyun2");
    String str6 = String(u"zuochengyunzuochengyunzuochengyUn3");
    String str7 = String(u"zuochengyunzuochengyunzuochengyun1");
    jout.println(String(u"7个字符串得到的哈希值 : "));
    jout.println(hash->hashValue(str1));
    jout.println(hash->hashValue(str2));
    jout.println(hash->hashValue(str3));
    jout.println(hash->hashValue(str4));
    jout.println(hash->hashValue(str5));
    jout.println(hash->hashValue(str6));
    jout.println(hash->hashValue(str7));
    jout.println();
    Array<jchar> arr = Array<jchar>{u'a', u'b'};
    int n = 20;
    jout.println(String(u"生成长度为n，字符来自arr，所有可能的字符串"));
    JList<String> strs = HashFunction::generateStrings(arr, n);
    jout.println((String(u"不同字符串的数量 : ") + strs.size()));
    JHashSet<String> set = JHashSet<String>();
    for (String str : strs) {
      set.add(hash->hashValue(str));
    }
    jout.println((String(u"不同哈希值的数量 : ") + set.size()));
    jout.println();
    int m = 13;
    Array<int> cnts = make_array<int>(m);
    jout.println(((String(u"现在看看这些哈希值，% ") + m) +
                  String(u" 之后的余数分布情况")));
    BigInteger mod = BigInteger(j::str(m));
    for (String hashCode : set) {
      BigInteger bigInt = BigInteger(hashCode, 16);
      int ans = bigInt.mod(mod).intValue();
      (cnts[ans]++);
    }
    for (int i = 0; (i < m); (i++)) {
      jout.println(((((String(u"余数 ") + i) + String(u" 出现了 ")) + cnts[i]) +
                    String(u" 次")));
    }
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  HashFunction::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
        // 哈希函数实例
                // 打印支持哪些哈希算法
                // 用具体算法名字构造实例
                // 输入字符串返回哈希值
//		for (String str : strs) {
//			System.out.println(str);
//		}
//		for (String str : set) {
//			System.out.println(str);
//		}
*/

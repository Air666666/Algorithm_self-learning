// 原题测试 / 参考链接（保留上游原始地址）
// https://www.nowcoder.com/practice/c552d3b4dfda49ccb883a6371d9a6932

// Source: src/class045/Code01_CountConsistentKeys.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_CountConsistentKeys {
  inline static int MAXN = 2000001;
  inline static Array<Array<int>> tree = make_array<int>(MAXN, 12);
  inline static Array<int> pass = make_array<int>(MAXN);
  inline static int cnt = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_CountConsistentKeys() {}
  static Array<int> countConsistentKeys(Array<Array<int>> b,
                                        Array<Array<int>> a) {
    Code01_CountConsistentKeys::build();
    StringBuilder builder = StringBuilder();
    for (Array<int> nums : a) {
      builder.setLength(0);
      for (int i = 1; (i < nums.length); (i++)) {
        builder.append((j::str((nums[i] - nums[(i - 1)])) + String(u"#")));
      }
      Code01_CountConsistentKeys::insert(builder.toString());
    }
    Array<int> ans = make_array<int>(b.length);
    for (int i = 0; (i < b.length); (i++)) {
      builder.setLength(0);
      Array<int> nums = b[i];
      for (int j = 1; (j < nums.length); (j++)) {
        builder.append((j::str((nums[j] - nums[(j - 1)])) + String(u"#")));
      }
      (ans[i] = Code01_CountConsistentKeys::count(builder.toString()));
    }
    Code01_CountConsistentKeys::clear();
    return ans;
  }
  static void build() { (cnt = 1); }
  static int path(jchar cha) {
    if ((cha == u'#')) {
      return 10;
    } else if ((cha == u'-')) {
      return 11;
    } else {
      return (cha - u'0');
    }
  }
  static void insert(String word) {
    int cur = 1;
    (pass[cur]++);
    {
      int i = 0;
      int path = {};
      for (; (i < word.length()); (i++)) {
        (path = Code01_CountConsistentKeys::path(word.charAt(i)));
        if ((tree[cur][path] == 0)) {
          (tree[cur][path] = (++cnt));
        }
        (cur = tree[cur][path]);
        (pass[cur]++);
      }
    }
  }
  static int count(String pre) {
    int cur = 1;
    {
      int i = 0;
      int path = {};
      for (; (i < pre.length()); (i++)) {
        (path = Code01_CountConsistentKeys::path(pre.charAt(i)));
        if ((tree[cur][path] == 0)) {
          return 0;
        }
        (cur = tree[cur][path]);
      }
    }
    return pass[cur];
  }
  static void clear() {
    for (int i = 1; (i <= cnt); (i++)) {
      j::fill(tree[i], 0);
      (pass[i] = 0);
    }
  }
};

/* Original teaching comments:
// 牛牛和他的朋友们约定了一套接头密匙系统，用于确认彼此身份
// 密匙由一组数字序列表示，两个密匙被认为是一致的，如果满足以下条件：
// 密匙 b 的长度不超过密匙 a 的长度。
// 对于任意 0 <= i < length(b)，有b[i+1] - b[i] == a[i+1] - a[i]
// 现在给定了m个密匙 b 的数组，以及n个密匙 a 的数组
// 请你返回一个长度为 m 的结果数组 ans，表示每个密匙b都有多少一致的密匙
// 数组 a 和数组 b 中的元素个数均不超过 10^5
// 1 <= m, n <= 1000
// 测试链接 : https://www.nowcoder.com/practice/c552d3b4dfda49ccb883a6371d9a6932
                // [3,6,50,10] -> "3#44#-40#"
        // 如果将来增加了数据量，就改大这个值
        // '0' ~ '9' 10个 0~9
        // '#' 10
        // '-' 11
*/

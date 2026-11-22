// 原题测试 / 参考链接（保留上游原始地址）
// https://www.nowcoder.com/practice/7f8a8553ddbf4eaab749ec988726702b

// Source: src/class044/Code02_TrieTree.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_TrieTree {
  inline static int MAXN = 150001;
  inline static Array<Array<int>> tree = make_array<int>(MAXN, 26);
  inline static Array<int> end = make_array<int>(MAXN);
  inline static Array<int> pass = make_array<int>(MAXN);
  inline static int cnt = {};
  inline static int m = {};
  inline static int op = {};
  inline static Array<String> splits = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_TrieTree() {}
  static void build() { (cnt = 1); }
  static void insert(String word) {
    int cur = 1;
    (pass[cur]++);
    {
      int i = 0;
      int path = {};
      for (; (i < word.length()); (i++)) {
        (path = (word.charAt(i) - u'a'));
        if ((tree[cur][path] == 0)) {
          (tree[cur][path] = (++cnt));
        }
        (cur = tree[cur][path]);
        (pass[cur]++);
      }
    }
    (end[cur]++);
  }
  static int search(String word) {
    int cur = 1;
    {
      int i = 0;
      int path = {};
      for (; (i < word.length()); (i++)) {
        (path = (word.charAt(i) - u'a'));
        if ((tree[cur][path] == 0)) {
          return 0;
        }
        (cur = tree[cur][path]);
      }
    }
    return end[cur];
  }
  static int prefixNumber(String pre) {
    int cur = 1;
    {
      int i = 0;
      int path = {};
      for (; (i < pre.length()); (i++)) {
        (path = (pre.charAt(i) - u'a'));
        if ((tree[cur][path] == 0)) {
          return 0;
        }
        (cur = tree[cur][path]);
      }
    }
    return pass[cur];
  }
  static void delete_method(String word) {
    if ((Code02_TrieTree::search(word) > 0)) {
      int cur = 1;
      (pass[cur]--);
      {
        int i = 0;
        int path = {};
        for (; (i < word.length()); (i++)) {
          (path = (word.charAt(i) - u'a'));
          if (((--pass[tree[cur][path]]) == 0)) {
            (tree[cur][path] = 0);
            return;
          }
          (cur = tree[cur][path]);
        }
      }
      (end[cur]--);
    }
  }
  static void clear() {
    for (int i = 1; (i <= cnt); (i++)) {
      j::fill(tree[i], 0);
      (end[i] = 0);
      (pass[i] = 0);
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO(IO(jin));
    IO out = IO(IO(jout));
    String line = nullptr;
    while (((line = in.readLine()) != nullptr)) {
      Code02_TrieTree::build();
      (m = std::stoi(text(line)));
      for (int i = 1; (i <= m); (i++)) {
        (splits = in.readLine().split(String(u" ")));
        (op = std::stoi(text(splits[0])));
        if ((op == 1)) {
          Code02_TrieTree::insert(splits[1]);
        } else if ((op == 2)) {
          Code02_TrieTree::delete_method(splits[1]);
        } else if ((op == 3)) {
          out.println(((Code02_TrieTree::search(splits[1]) > 0)
                           ? String(u"YES")
                           : String(u"NO")));
        } else if ((op == 4)) {
          out.println(Code02_TrieTree::prefixNumber(splits[1]));
        }
      }
      Code02_TrieTree::clear();
    }
    out.flush();
    in.close();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code02_TrieTree::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 用固定数组实现前缀树，空间使用是静态的。推荐！
// 测试链接 : https://www.nowcoder.com/practice/7f8a8553ddbf4eaab749ec988726702b
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下的code，提交时请把类名改成"Main"，可以直接通过
        // 如果将来增加了数据量，就改大这个值
                        // 下面这一行代码，讲课的时候没加
                        //
本题不会用到pass[1]的信息，所以加不加都可以，不过正确的写法是加上
*/

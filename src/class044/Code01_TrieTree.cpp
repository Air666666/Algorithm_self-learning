// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/implement-trie-ii-prefix-tree/

// Source: src/class044/Code01_TrieTree.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_TrieTree {
  struct Trie1;
  struct Trie2;
  struct Trie1 {
    struct Trie1_TrieNode;
    struct Trie1_TrieNode {
      int pass = {};
      int end = {};
      Array<Trie1_TrieNode *> nexts = {};
      String toString() const {
        return j::str(static_cast<const void *>(this));
      }
      Trie1_TrieNode() {
        (pass = 0);
        (end = 0);
        (nexts = make_array<Trie1_TrieNode *>(26));
      }
    };
    Trie1_TrieNode *root = {};
    String toString() const { return j::str(static_cast<const void *>(this)); }
    Trie1() { (root = new Trie1_TrieNode()); }
    void insert(String word) {
      Trie1_TrieNode *node = root;
      (node->pass++);
      {
        int i = 0;
        int path = {};
        for (; (i < word.length()); (i++)) {
          (path = (word.charAt(i) - u'a'));
          if ((node->nexts[path] == nullptr)) {
            (node->nexts[path] = new Trie1_TrieNode());
          }
          (node = node->nexts[path]);
          (node->pass++);
        }
      }
      (node->end++);
    }
    void erase(String word) {
      if ((Trie1::countWordsEqualTo(word) > 0)) {
        Trie1_TrieNode *node = root;
        (node->pass--);
        {
          int i = 0;
          int path = {};
          for (; (i < word.length()); (i++)) {
            (path = (word.charAt(i) - u'a'));
            if (((--node->nexts[path]->pass) == 0)) {
              (node->nexts[path] = nullptr);
              return;
            }
            (node = node->nexts[path]);
          }
        }
        (node->end--);
      }
    }
    int countWordsEqualTo(String word) {
      Trie1_TrieNode *node = root;
      {
        int i = 0;
        int path = {};
        for (; (i < word.length()); (i++)) {
          (path = (word.charAt(i) - u'a'));
          if ((node->nexts[path] == nullptr)) {
            return 0;
          }
          (node = node->nexts[path]);
        }
      }
      return node->end;
    }
    int countWordsStartingWith(String pre) {
      Trie1_TrieNode *node = root;
      {
        int i = 0;
        int path = {};
        for (; (i < pre.length()); (i++)) {
          (path = (pre.charAt(i) - u'a'));
          if ((node->nexts[path] == nullptr)) {
            return 0;
          }
          (node = node->nexts[path]);
        }
      }
      return node->pass;
    }
  };
  struct Trie2 {
    struct Trie2_TrieNode;
    struct Trie2_TrieNode {
      int pass = {};
      int end = {};
      JMap<int, Trie2_TrieNode *> nexts = {};
      String toString() const {
        return j::str(static_cast<const void *>(this));
      }
      Trie2_TrieNode() {
        (pass = 0);
        (end = 0);
        (nexts = JMap<int, Trie2_TrieNode *>());
      }
    };
    Trie2_TrieNode *root = {};
    String toString() const { return j::str(static_cast<const void *>(this)); }
    Trie2() { (root = new Trie2_TrieNode()); }
    void insert(String word) {
      Trie2_TrieNode *node = root;
      (node->pass++);
      {
        int i = 0;
        int path = {};
        for (; (i < word.length()); (i++)) {
          (path = word.charAt(i));
          if ((!node->nexts.containsKey(path))) {
            node->nexts.put(path, new Trie2_TrieNode());
          }
          (node = node->nexts.get(path));
          (node->pass++);
        }
      }
      (node->end++);
    }
    void erase(String word) {
      if ((Trie2::countWordsEqualTo(word) > 0)) {
        Trie2_TrieNode *node = root;
        Trie2_TrieNode *next = {};
        (node->pass--);
        {
          int i = 0;
          int path = {};
          for (; (i < word.length()); (i++)) {
            (path = word.charAt(i));
            (next = node->nexts.get(path));
            if (((--next->pass) == 0)) {
              node->nexts.remove(path);
              return;
            }
            (node = next);
          }
        }
        (node->end--);
      }
    }
    int countWordsEqualTo(String word) {
      Trie2_TrieNode *node = root;
      {
        int i = 0;
        int path = {};
        for (; (i < word.length()); (i++)) {
          (path = word.charAt(i));
          if ((!node->nexts.containsKey(path))) {
            return 0;
          }
          (node = node->nexts.get(path));
        }
      }
      return node->end;
    }
    int countWordsStartingWith(String pre) {
      Trie2_TrieNode *node = root;
      {
        int i = 0;
        int path = {};
        for (; (i < pre.length()); (i++)) {
          (path = pre.charAt(i));
          if ((!node->nexts.containsKey(path))) {
            return 0;
          }
          (node = node->nexts.get(path));
        }
      }
      return node->pass;
    }
  };
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_TrieTree() {}
};

/* Original teaching comments:
// 用类描述实现前缀树。不推荐！
// 测试链接 : https://leetcode.cn/problems/implement-trie-ii-prefix-tree/
        // 路是数组实现的
        // 提交时把类名、构造方法改为Trie
                // 如果之前word插入过前缀树，那么此时删掉一次
                // 如果之前word没有插入过前缀树，那么什么也不做
                // 查询前缀树里，word单词出现了几次
                // 查询前缀树里，有多少单词以pre做前缀
        // 路是哈希表实现的
        // 提交时把类名、构造方法改为Trie
*/

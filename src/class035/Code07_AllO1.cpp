// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/all-oone-data-structure/

// Source: src/class035/Code07_AllO1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code07_AllO1 {
  struct AllOne;
  struct AllOne {
    struct Bucket;
    struct Bucket {
      JHashSet<String> set = {};
      int cnt = {};
      Bucket *last = {};
      Bucket *next = {};
      String toString() const {
        return j::str(static_cast<const void *>(this));
      }
      Bucket(String s, int c) {
        (set = JHashSet<String>());
        set.add(s);
        (cnt = c);
      }
    };
    Bucket *head = {};
    Bucket *tail = {};
    JMap<String, Bucket *> map = {};
    String toString() const { return j::str(static_cast<const void *>(this)); }
    void insert(Bucket *cur, Bucket *pos) {
      (cur->next->last = pos);
      (pos->next = cur->next);
      (cur->next = pos);
      (pos->last = cur);
    }
    void remove(Bucket *cur) {
      (cur->last->next = cur->next);
      (cur->next->last = cur->last);
    }
    AllOne() {
      (head = new Bucket(String(u""), 0));
      (tail = new Bucket(String(u""), std::numeric_limits<int>::max()));
      (head->next = tail);
      (tail->last = head);
      (map = JMap<String, Bucket *>());
    }
    void inc(String key) {
      if ((!map.containsKey(key))) {
        if ((head->next->cnt == 1)) {
          map.put(key, head->next);
          head->next->set.add(key);
        } else {
          Bucket *newBucket = new Bucket(key, 1);
          map.put(key, newBucket);
          AllOne::insert(head, newBucket);
        }
      } else {
        Bucket *bucket = map.get(key);
        if ((bucket->next->cnt == (bucket->cnt + 1))) {
          map.put(key, bucket->next);
          bucket->next->set.add(key);
        } else {
          Bucket *newBucket = new Bucket(key, (bucket->cnt + 1));
          map.put(key, newBucket);
          AllOne::insert(bucket, newBucket);
        }
        bucket->set.remove(key);
        if (bucket->set.isEmpty()) {
          AllOne::remove(bucket);
        }
      }
    }
    void dec(String key) {
      Bucket *bucket = map.get(key);
      if ((bucket->cnt == 1)) {
        map.remove(key);
      } else {
        if ((bucket->last->cnt == (bucket->cnt - 1))) {
          map.put(key, bucket->last);
          bucket->last->set.add(key);
        } else {
          Bucket *newBucket = new Bucket(key, (bucket->cnt - 1));
          map.put(key, newBucket);
          AllOne::insert(bucket->last, newBucket);
        }
      }
      bucket->set.remove(key);
      if (bucket->set.isEmpty()) {
        AllOne::remove(bucket);
      }
    }
    String getMaxKey() { return tail->last->set.iterator().next(); }
    String getMinKey() { return head->next->set.iterator().next(); }
  };
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code07_AllO1() {}
};

/* Original teaching comments:
// 全O(1)的数据结构
        // 测试链接 : https://leetcode.cn/problems/all-oone-data-structure/
*/

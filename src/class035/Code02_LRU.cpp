// Source: src/class035/Code02_LRU.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_LRU {
  struct LRUCache;
  struct LRUCache {
    struct DoubleNode;
    struct DoubleList;
    struct DoubleNode {
      int key = {};
      int val = {};
      DoubleNode *last = {};
      DoubleNode *next = {};
      String toString() const {
        return j::str(static_cast<const void *>(this));
      }
      DoubleNode(int k, int v) {
        (key = k);
        (val = v);
      }
    };
    struct DoubleList {
      DoubleNode *head = {};
      DoubleNode *tail = {};
      String toString() const {
        return j::str(static_cast<const void *>(this));
      }
      DoubleList() {
        (head = nullptr);
        (tail = nullptr);
      }
      void addNode(DoubleNode *newNode) {
        if ((newNode == nullptr)) {
          return;
        }
        if ((head == nullptr)) {
          (head = newNode);
          (tail = newNode);
        } else {
          (tail->next = newNode);
          (newNode->last = tail);
          (tail = newNode);
        }
      }
      void moveNodeToTail(DoubleNode *node) {
        if ((tail == node)) {
          return;
        }
        if ((head == node)) {
          (head = node->next);
          (head->last = nullptr);
        } else {
          (node->last->next = node->next);
          (node->next->last = node->last);
        }
        (node->last = tail);
        (node->next = nullptr);
        (tail->next = node);
        (tail = node);
      }
      DoubleNode *removeHead() {
        if ((head == nullptr)) {
          return nullptr;
        }
        DoubleNode *ans = head;
        if ((head == tail)) {
          (head = nullptr);
          (tail = nullptr);
        } else {
          (head = ans->next);
          (ans->next = nullptr);
          (head->last = nullptr);
        }
        return ans;
      }
    };
    JMap<int, DoubleNode *> keyNodeMap = {};
    DoubleList *nodeList = {};
    int capacity = {};
    String toString() const { return j::str(static_cast<const void *>(this)); }
    LRUCache(int cap) {
      (keyNodeMap = JMap<int, DoubleNode *>());
      (nodeList = new DoubleList());
      (capacity = cap);
    }
    int get(int key) {
      if (keyNodeMap.containsKey(key)) {
        DoubleNode *ans = keyNodeMap.get(key);
        nodeList->moveNodeToTail(ans);
        return ans->val;
      }
      return (-1);
    }
    void put(int key, int value) {
      if (keyNodeMap.containsKey(key)) {
        DoubleNode *node = keyNodeMap.get(key);
        (node->val = value);
        nodeList->moveNodeToTail(node);
      } else {
        if ((keyNodeMap.size() == capacity)) {
          keyNodeMap.remove(nodeList->removeHead()->key);
        }
        DoubleNode *newNode = new DoubleNode(key, value);
        keyNodeMap.put(key, newNode);
        nodeList->addNode(newNode);
      }
    }
  };
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_LRU() {}
};

/* Original teaching comments:
// 实现LRU结构
        // 测试链接 : https://leetcode.cn/problems/lru-cache/
*/

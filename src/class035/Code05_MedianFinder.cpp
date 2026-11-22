// Source: src/class035/Code05_MedianFinder.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code05_MedianFinder {
  struct MedianFinder;
  struct MedianFinder {
    JHeap<int> maxHeap = {};
    JHeap<int> minHeap = {};
    String toString() const { return j::str(static_cast<const void *>(this)); }
    MedianFinder() {
      (maxHeap = JHeap<int>([=](Box<int> a, Box<int> b) { return (b - a); }));
      (minHeap = JHeap<int>([=](Box<int> a, Box<int> b) { return (a - b); }));
    }
    void addNum(int num) {
      if ((maxHeap.isEmpty() || (maxHeap.peek() >= num))) {
        maxHeap.add(num);
      } else {
        minHeap.add(num);
      }
      MedianFinder::balance();
    }
    double findMedian() {
      if ([&]() {
            auto jleft = maxHeap.size();
            auto jright = minHeap.size();
            return (jleft == jright);
          }()) {
        return jdiv(static_cast<double>([&]() {
                      auto jleft = maxHeap.peek();
                      auto jright = minHeap.peek();
                      return (jleft + jright);
                    }()),
                    2);
      } else {
        return ([&]() {
          auto jleft = maxHeap.size();
          auto jright = minHeap.size();
          return (jleft > jright);
        }()
                    ? unbox(maxHeap.peek())
                    : unbox(minHeap.peek()));
      }
    }
    void balance() {
      if ((std::abs([&]() {
             auto jleft = maxHeap.size();
             auto jright = minHeap.size();
             return (jleft - jright);
           }()) == 2)) {
        if ([&]() {
              auto jleft = maxHeap.size();
              auto jright = minHeap.size();
              return (jleft > jright);
            }()) {
          minHeap.add(maxHeap.poll());
        } else {
          maxHeap.add(minHeap.poll());
        }
      }
    }
  };
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code05_MedianFinder() {}
};

/* Original teaching comments:
// 快速获得数据流的中位数的结构
        // 测试链接 : https://leetcode.cn/problems/find-median-from-data-stream/
*/

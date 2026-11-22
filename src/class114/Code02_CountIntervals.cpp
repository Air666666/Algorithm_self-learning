// Source: src/class114/Code02_CountIntervals.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_CountIntervals {
  struct CountIntervals;
  struct CountIntervals {
    inline static int n = 1000000000;
    inline static int LIMIT = 700001;
    inline static Array<int> left = make_array<int>(LIMIT);
    inline static Array<int> right = make_array<int>(LIMIT);
    inline static Array<int> sum = make_array<int>(LIMIT);
    inline static int cnt = 1;
    String toString() const { return j::str(static_cast<const void *>(this)); }
    CountIntervals() {
      j::fill(left, 1, (cnt + 1), 0);
      j::fill(right, 1, (cnt + 1), 0);
      j::fill(sum, 1, (cnt + 1), 0);
      (cnt = 1);
    }
    static void up(int h, int l, int r) { (sum[h] = (sum[l] + sum[r])); }
    static void setOne(int jobl, int jobr, int l, int r, int i) {
      if ((sum[i] == ((r - l) + 1))) {
        return;
      }
      if (((jobl <= l) && (r <= jobr))) {
        (sum[i] = ((r - l) + 1));
      } else {
        int mid = jshr((l + r), 1);
        if ((jobl <= mid)) {
          if ((left[i] == 0)) {
            (left[i] = (++cnt));
          }
          CountIntervals::setOne(jobl, jobr, l, mid, left[i]);
        }
        if ((jobr > mid)) {
          if ((right[i] == 0)) {
            (right[i] = (++cnt));
          }
          CountIntervals::setOne(jobl, jobr, (mid + 1), r, right[i]);
        }
        CountIntervals::up(i, left[i], right[i]);
      }
    }
    void add(int left, int right) {
      CountIntervals::setOne(left, right, 1, n, 1);
    }
    int count() { return sum[1]; }
  };
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_CountIntervals() {}
};

/* Original teaching comments:
// 统计区间中的整数数目
// 实现CountIntervals类的如下三个方法
// 1) CountIntervals() : 初始化
// 2) void add(int l, int r) : 把[l, r]范围上的数字都设置成1
// 3) int count() : 返回整个区间有多少个1
// CountIntervals类需要支持1 ~ 10^9范围
// 调用add和count方法总共10^5次
// 测试链接 : https://leetcode.cn/problems/count-integers-in-intervals/
        // 开点线段树的实现
        // 为了所有语言的同学都容易改出来
        // 选择用静态空间的方式实现
        // 该方法的打败比例不高但是非常好想
        // 有兴趣的同学可以研究其他做法
                // 支持的最大范围
                // 空间大小定成这个值是实验的结果
                // 这个题的特殊性在于，只有改1的操作，没有改0的操作
                // 理解这个就可以分析出不需要懒更新机制，原因有两个
                // 1)
查询操作永远查的是整个范围1的数量，不会有小范围的查询，每次都返回sum[1]
                //    这意味着只要能把sum[1]更新正确即可，up函数可以保证这一点
                // 2)
一个范围已经全是1，那以后都会是1，没有必要把全是1的懒更新信息向下传递
                // 这个函数的功能比线段树能做到的范围修改功能简单很多
                // 功能有阉割就意味着存在优化的点
*/

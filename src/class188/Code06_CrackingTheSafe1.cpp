// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/cracking-the-safe/

// Source: src/class188/Code06_CrackingTheSafe1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code06_CrackingTheSafe1 {
  struct Solution;
  struct Solution {
    int MAXN = 5001;
    int n = {};
    int k = {};
    int m = {};
    Array<int> cur = make_array<int>(MAXN);
    Array<int> path = make_array<int>(MAXN);
    int cntp = {};
    Array<Array<int>> sta = make_array<int>(MAXN, 2);
    int u = {};
    int e = {};
    int stacksize = {};
    String toString() const { return j::str(static_cast<const void *>(this)); }
    Solution() {}
    void push(int u, int e) {
      (sta[stacksize][0] = u);
      (sta[stacksize][1] = e);
      (stacksize++);
    }
    void pop() {
      (stacksize--);
      (u = sta[stacksize][0]);
      (e = sta[stacksize][1]);
    }
    void prepare(int len, int num) {
      (n = len);
      (k = num);
      (m = 1);
      for (int i = 1; (i <= (n - 1)); (i++)) {
        (m *= k);
      }
      for (int i = 0; (i < m); (i++)) {
        (cur[i] = 0);
      }
      (cntp = 0);
    }
    void euler1(int u, int e) {
      while ((cur[u] < k)) {
        int ne = (cur[u]++);
        Solution::euler1(jrem(((u * k) + ne), m), ne);
      }
      (path[(++cntp)] = e);
    }
    void euler2(int node, int edge) {
      (stacksize = 0);
      Solution::push(node, edge);
      while ((stacksize > 0)) {
        Solution::pop();
        if ((cur[u] < k)) {
          int ne = (cur[u]++);
          Solution::push(u, e);
          Solution::push(jrem(((u * k) + ne), m), ne);
        } else {
          (path[(++cntp)] = e);
        }
      }
    }
    String crackSafe(int len, int num) {
      Solution::prepare(len, num);
      Solution::euler1(0, (-1));
      StringBuilder str = StringBuilder();
      for (int i = 1; (i <= (n - 1)); (i++)) {
        str.append(String(u"0"));
      }
      for (int i = (cntp - 1); (i >= 1); (i--)) {
        str.append(path[i]);
      }
      return str.toString();
    }
  };
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code06_CrackingTheSafe1() {}
};

/* Original teaching comments:
// 破解保险箱，java版
// 给定正数n，表示密码有n位，给定正数k，表示每一位可能的数字是[0..k-1]
// 密码有(k^n)个可能性，构造一个字符串，其中的连续子串包含所有可能的密码
// 先保证字符串的长度最短，作为加强要求，保证字典序尽量的小，返回字符串
// 1 <= n <= 4    1 <= k <= 10
// 测试链接 : https://leetcode.cn/problems/cracking-the-safe/
// 提交以下代码中的Solution类，可以通过所有测试用例
                // 递归版
                // 迭代版
                        // euler2(0, -1);
*/

// Source: src/class188/Code03_Arrangement1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_Arrangement1 {
  struct Solution;
  struct Solution {
    inline static int MAXN = 200001;
    inline static int n = {};
    inline static int m = {};
    inline static Array<Array<int>> pair = {};
    inline static Array<int> sortv = make_array<int>(MAXN);
    inline static Array<int> head = make_array<int>(MAXN);
    inline static Array<int> nxt = make_array<int>(MAXN);
    inline static Array<int> to = make_array<int>(MAXN);
    inline static int cntg = {};
    inline static Array<int> cur = make_array<int>(MAXN);
    inline static Array<int> outDeg = make_array<int>(MAXN);
    inline static Array<int> inDeg = make_array<int>(MAXN);
    inline static Array<int> path = make_array<int>(MAXN);
    inline static int cntp = {};
    String toString() const { return j::str(static_cast<const void *>(this)); }
    Solution() {}
    static void addEdge(int u, int v) {
      (nxt[(++cntg)] = head[u]);
      (to[cntg] = v);
      (head[u] = cntg);
    }
    static int kth(int num) {
      int l = 1;
      int r = n;
      int ans = 0;
      while ((l <= r)) {
        int mid = jushr((l + r), 1);
        if ((sortv[mid] >= num)) {
          (ans = mid);
          (r = (mid - 1));
        } else {
          (l = (mid + 1));
        }
      }
      return ans;
    }
    static void prepare() {
      int len = 0;
      for (int i = 0; (i < m); (i++)) {
        (sortv[(++len)] = pair[i][0]);
        (sortv[(++len)] = pair[i][1]);
      }
      j::sort(sortv, 1, (len + 1));
      (n = 1);
      for (int i = 2; (i <= len); (i++)) {
        if ((sortv[n] != sortv[i])) {
          (sortv[(++n)] = sortv[i]);
        }
      }
      (cntg = (cntp = 0));
      for (int i = 1; (i <= n); (i++)) {
        (head[i] = (outDeg[i] = (inDeg[i] = 0)));
      }
    }
    static void connect() {
      {
        int i = 0;
        int u = {};
        int v = {};
        for (; (i < m); (i++)) {
          (u = Solution::kth(pair[i][0]));
          (v = Solution::kth(pair[i][1]));
          (outDeg[u]++);
          (inDeg[v]++);
          Solution::addEdge(u, v);
        }
      }
      for (int i = 1; (i <= n); (i++)) {
        (cur[i] = head[i]);
      }
    }
    static int directedStart() {
      int start = (-1);
      int end = (-1);
      for (int i = 1; (i <= n); (i++)) {
        int v = (outDeg[i] - inDeg[i]);
        if (((((v < (-1)) || (v > 1)) || ((v == 1) && (start != (-1)))) ||
             ((v == (-1)) && (end != (-1))))) {
          return (-1);
        }
        if ((v == 1)) {
          (start = i);
        }
        if ((v == (-1))) {
          (end = i);
        }
      }
      if (((start == (-1)) ^ (end == (-1)))) {
        return (-1);
      }
      if ((start != (-1))) {
        return start;
      }
      for (int i = 1; (i <= n); (i++)) {
        if ((outDeg[i] > 0)) {
          return i;
        }
      }
      return (-1);
    }
    static void euler(int u) {
      for (int e = cur[u]; (e > 0); (e = cur[u])) {
        (cur[u] = nxt[e]);
        Solution::euler(to[e]);
      }
      (path[(++cntp)] = u);
    }
    Array<Array<int>> validArrangement(Array<Array<int>> pairs) {
      (m = pairs.length);
      (pair = pairs);
      Solution::prepare();
      Solution::connect();
      int start = Solution::directedStart();
      if ((start == (-1))) {
        return nullptr;
      }
      Solution::euler(start);
      if ((cntp != (m + 1))) {
        return nullptr;
      }
      Array<Array<int>> ans = make_array<int>(m, 2);
      {
        int i = 0;
        int j = cntp;
        for (; (i < m); (i++), (j--)) {
          (ans[i][0] = sortv[path[j]]);
          (ans[i][1] = sortv[path[(j - 1)]]);
        }
      }
      return ans;
    }
  };
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_Arrangement1() {}
};

/* Original teaching comments:
// 合法排列数对，java版
// 给定n个数对，每个数对(a, b)，其中 a != b，并且不存在相同的数对
// 希望所有数对形成首尾相接的样子，叫做合法排列，比如以下的数对
// [5,1] [4,5] [11,9] [9,4] 合法排列为 [11,9] [9,4] [4,5] [5,1]
// 注意每个数对必须使用且仅用1次，数据保证存在合法排列，返回任何一个都可以
// 1 <= n <= 10^5
// 0 <= 数字 <= 10^9
// 测试链接 : https://leetcode.cn/problems/valid-arrangement-of-pairs/
// 提交以下代码中的Solution类，可以通过所有测试用例
*/

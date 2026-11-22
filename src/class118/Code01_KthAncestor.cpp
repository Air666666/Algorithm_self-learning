// Source: src/class118/Code01_KthAncestor.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_KthAncestor {
  struct TreeAncestor;
  struct TreeAncestor {
    inline static int MAXN = 50001;
    inline static int LIMIT = 16;
    inline static int power = {};
    inline static Array<int> head = make_array<int>(MAXN);
    inline static Array<int> next = make_array<int>(MAXN);
    inline static Array<int> to = make_array<int>(MAXN);
    inline static int cnt = {};
    inline static Array<int> deep = make_array<int>(MAXN);
    inline static Array<Array<int>> stjump = make_array<int>(MAXN, LIMIT);
    String toString() const { return j::str(static_cast<const void *>(this)); }
    static int log2(int n) {
      int ans = 0;
      while ((jshl(1, ans) <= jshr(n, 1))) {
        (ans++);
      }
      return ans;
    }
    TreeAncestor(int n, Array<int> parent) {
      (power = TreeAncestor::log2(n));
      (cnt = 1);
      j::fill(head, 0, n, 0);
      for (int i = 1; (i < parent.length); (i++)) {
        TreeAncestor::addEdge(parent[i], i);
      }
      TreeAncestor::dfs(0, 0);
    }
    static void addEdge(int u, int v) {
      (next[cnt] = head[u]);
      (to[cnt] = v);
      (head[u] = (cnt++));
    }
    static void dfs(int i, int f) {
      if ((i == 0)) {
        (deep[i] = 1);
      } else {
        (deep[i] = (deep[f] + 1));
      }
      (stjump[i][0] = f);
      for (int p = 1; (p <= power); (p++)) {
        (stjump[i][p] = stjump[stjump[i][(p - 1)]][(p - 1)]);
      }
      for (int e = head[i]; (e != 0); (e = next[e])) {
        TreeAncestor::dfs(to[e], i);
      }
    }
    int getKthAncestor(int i, int k) {
      if ((deep[i] <= k)) {
        return (-1);
      }
      int s = (deep[i] - k);
      for (int p = power; (p >= 0); (p--)) {
        if ((deep[stjump[i][p]] >= s)) {
          (i = stjump[i][p]);
        }
      }
      return i;
    }
  };
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_KthAncestor() {}
};

/* Original teaching comments:
// 树节点的第K个祖先
// 树上有n个节点，编号0 ~ n-1，树的结构用parent数组代表
// 其中parent[i]是节点i的父节点，树的根节点是编号为0
// 树节点i的第k个祖先节点，是从节点i开始往上跳k步所来到的节点
// 实现TreeAncestor类
// TreeAncestor(int n, int[] parent) : 初始化
// getKthAncestor(int i, int k) : 返回节点i的第k个祖先节点，不存在返回-1
// 测试链接 : https://leetcode.cn/problems/kth-ancestor-of-a-tree-node/
                // 根据节点个数n，计算出2的几次方就够用了
                // 链式前向星建图
                // deep[i] : 节点i在第几层
                // stjump[i][p] : 节点i往上跳2的p次方步，到达的节点编号
                // 当前来到i节点，i节点父亲节点是f
                        // s是想要去往的层数
*/

// Source: src/class162/Code06_DominantIndices1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code06_DominantIndices1 {
  inline static int MAXN = 1000001;
  inline static int n = {};
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> next = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> to = make_array<int>(jshl(MAXN, 1));
  inline static int cntg = 0;
  inline static Array<int> len = make_array<int>(MAXN);
  inline static Array<int> son = make_array<int>(MAXN);
  inline static Array<int> dfn = make_array<int>(MAXN);
  inline static int cntd = 0;
  inline static Array<int> dp = make_array<int>(MAXN);
  inline static Array<int> ansx = make_array<int>(MAXN);
  inline static Array<Array<int>> ufe = make_array<int>(MAXN, 3);
  inline static int stacksize = {};
  inline static int u = {};
  inline static int f = {};
  inline static int e = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code06_DominantIndices1() {}
  static void setdp(int u, int i, int v) { (dp[(dfn[u] + i)] = v); }
  static int getdp(int u, int i) { return dp[(dfn[u] + i)]; }
  static void addEdge(int u, int v) {
    (next[(++cntg)] = head[u]);
    (to[cntg] = v);
    (head[u] = cntg);
  }
  static void dfs1(int u, int fa) {
    {
      int e = head[u];
      int v = {};
      for (; (e > 0); (e = next[e])) {
        (v = to[e]);
        if ((v != fa)) {
          Code06_DominantIndices1::dfs1(v, u);
        }
      }
    }
    {
      int e = head[u];
      int v = {};
      for (; (e > 0); (e = next[e])) {
        (v = to[e]);
        if ((v != fa)) {
          if (((son[u] == 0) || (len[son[u]] < len[v]))) {
            (son[u] = v);
          }
        }
      }
    }
    (len[u] = (len[son[u]] + 1));
  }
  static void dfs2(int u, int fa) {
    (dfn[u] = (++cntd));
    Code06_DominantIndices1::setdp(u, 0, 1);
    (ansx[u] = 0);
    if ((son[u] == 0)) {
      return;
    }
    Code06_DominantIndices1::dfs2(son[u], u);
    {
      int e = head[u];
      int v = {};
      for (; (e > 0); (e = next[e])) {
        (v = to[e]);
        if (((v != fa) && (v != son[u]))) {
          Code06_DominantIndices1::dfs2(v, u);
        }
      }
    }
    (ansx[u] = (ansx[son[u]] + 1));
    {
      int e = head[u];
      int v = {};
      for (; (e > 0); (e = next[e])) {
        (v = to[e]);
        if (((v != fa) && (v != son[u]))) {
          for (int i = 1; (i <= len[v]); (i++)) {
            Code06_DominantIndices1::setdp(u, i, [&]() {
              auto jleft = Code06_DominantIndices1::getdp(u, i);
              auto jright = Code06_DominantIndices1::getdp(v, (i - 1));
              return (jleft + jright);
            }());
            if (([&]() {
                  auto jleft = Code06_DominantIndices1::getdp(u, i);
                  auto jright = Code06_DominantIndices1::getdp(u, ansx[u]);
                  return (jleft > jright);
                }() ||
                 ([&]() {
                   auto jleft = Code06_DominantIndices1::getdp(u, i);
                   auto jright = Code06_DominantIndices1::getdp(u, ansx[u]);
                   return (jleft == jright);
                 }() &&
                  (i < ansx[u])))) {
              (ansx[u] = i);
            }
          }
        }
      }
    }
    if ((Code06_DominantIndices1::getdp(u, ansx[u]) == 1)) {
      (ansx[u] = 0);
    }
  }
  static void push(int a, int b, int c) {
    (ufe[stacksize][0] = a);
    (ufe[stacksize][1] = b);
    (ufe[stacksize][2] = c);
    (stacksize++);
  }
  static void pop() {
    (--stacksize);
    (u = ufe[stacksize][0]);
    (f = ufe[stacksize][1]);
    (e = ufe[stacksize][2]);
  }
  static void dfs3() {
    (stacksize = 0);
    Code06_DominantIndices1::push(1, 0, (-1));
    int v = {};
    while ((stacksize > 0)) {
      Code06_DominantIndices1::pop();
      if ((e == (-1))) {
        (e = head[u]);
      } else {
        (e = next[e]);
      }
      if ((e != 0)) {
        Code06_DominantIndices1::push(u, f, e);
        (v = to[e]);
        if ((v != f)) {
          Code06_DominantIndices1::push(v, u, (-1));
        }
      } else {
        for (int ei = head[u]; (ei > 0); (ei = next[ei])) {
          (v = to[ei]);
          if ((v != f)) {
            if (((son[u] == 0) || (len[son[u]] < len[v]))) {
              (son[u] = v);
            }
          }
        }
        (len[u] = (len[son[u]] + 1));
      }
    }
  }
  static void dfs4() {
    (stacksize = 0);
    Code06_DominantIndices1::push(1, 0, (-1));
    int v = {};
    while ((stacksize > 0)) {
      Code06_DominantIndices1::pop();
      if ((e == (-1))) {
        (dfn[u] = (++cntd));
        Code06_DominantIndices1::setdp(u, 0, 1);
        (ansx[u] = 0);
        if ((son[u] == 0)) {
          continue;
        }
        Code06_DominantIndices1::push(u, f, (-2));
        Code06_DominantIndices1::push(son[u], u, (-1));
        continue;
      } else if ((e == (-2))) {
        (e = head[u]);
      } else {
        (e = next[e]);
      }
      if ((e != 0)) {
        Code06_DominantIndices1::push(u, f, e);
        (v = to[e]);
        if (((v != f) && (v != son[u]))) {
          Code06_DominantIndices1::push(v, u, (-1));
        }
      } else {
        (ansx[u] = (ansx[son[u]] + 1));
        for (int e = head[u]; (e > 0); (e = next[e])) {
          (v = to[e]);
          if (((v != f) && (v != son[u]))) {
            for (int i = 1; (i <= len[v]); (i++)) {
              Code06_DominantIndices1::setdp(u, i, [&]() {
                auto jleft = Code06_DominantIndices1::getdp(u, i);
                auto jright = Code06_DominantIndices1::getdp(v, (i - 1));
                return (jleft + jright);
              }());
              if (([&]() {
                    auto jleft = Code06_DominantIndices1::getdp(u, i);
                    auto jright = Code06_DominantIndices1::getdp(u, ansx[u]);
                    return (jleft > jright);
                  }() ||
                   ([&]() {
                     auto jleft = Code06_DominantIndices1::getdp(u, i);
                     auto jright = Code06_DominantIndices1::getdp(u, ansx[u]);
                     return (jleft == jright);
                   }() &&
                    (i < ansx[u])))) {
                (ansx[u] = i);
              }
            }
          }
        }
        if ((Code06_DominantIndices1::getdp(u, ansx[u]) == 1)) {
          (ansx[u] = 0);
        }
      }
    }
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    (n = static_cast<int>(in.nval));
    {
      int i = 1;
      int u = {};
      int v = {};
      for (; (i < n); (i++)) {
        in.nextToken();
        (u = static_cast<int>(in.nval));
        in.nextToken();
        (v = static_cast<int>(in.nval));
        Code06_DominantIndices1::addEdge(u, v);
        Code06_DominantIndices1::addEdge(v, u);
      }
    }
    Code06_DominantIndices1::dfs3();
    Code06_DominantIndices1::dfs4();
    for (int i = 1; (i <= n); (i++)) {
      out.println(ansx[i]);
    }
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code06_DominantIndices1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 长链剖分优化动态规划模版题，java版
// 一共有n个节点，给定n-1条边，所有节点连成一棵树，规定1号节点是头
// 规定任何点到自己的距离为0
// 定义d(u, x)，以u为头的子树中，到u的距离为x的节点数
// 对于每个点u，想知道哪个尽量小的x，能取得最大的d(u, x)值
// 打印每个点的答案x
// 1 <= n <= 10^6
// 测试链接 : https://www.luogu.com.cn/problem/CF1009F
// 测试链接 : https://codeforces.com/problemset/problem/1009/F
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 链式前向星
        // 长链剖分
        // 动态规划
        // 答案数组
        // 递归版，C++可以通过，java会爆栈，迭代版是dfs3方法
        // 递归版，C++可以通过，java会爆栈，迭代版是dfs4方法
                // 注意一定要在合并其他儿子dp信息的过程中，去更新ansx
                // 千万不要，最后再遍历一遍u的dp信息，然后更新ansx
                // 因为任何for循环，都不能是长链的规模！
                //
如果for循环是长链的规模，那么u遍历下去，u的重儿子又遍历下去，长链上每个节点都遍历下去
                //
时间复杂度必然不再是O(n)，而是O(n^2)，长链剖分的优势就不存在了！
                //
所以长链信息会被u直接继承，绝对不要有任何与长链的长度等规模的循环出现！
                // 如果u的某个距离，获得的最大节点数为1
                // 那么u答案就是0距离，因为u到u自己的距离是0，也有1个节点了
                // 根据题目要求，返回尽量小的距离
        // 不会改迭代版，去看讲解118，详解了从递归版改迭代版
        // dfs1的迭代版
        // dfs2的迭代版
*/

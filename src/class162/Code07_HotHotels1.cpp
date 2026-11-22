// Source: src/class162/Code07_HotHotels1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code07_HotHotels1 {
  inline static int MAXN = 100001;
  inline static int n = {};
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> next = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> to = make_array<int>(jshl(MAXN, 1));
  inline static int cntg = 0;
  inline static Array<int> fa = make_array<int>(MAXN);
  inline static Array<int> son = make_array<int>(MAXN);
  inline static Array<int> len = make_array<int>(MAXN);
  inline static int cntd = 0;
  inline static Array<int> fid = make_array<int>(MAXN);
  inline static Array<int> gid = make_array<int>(MAXN);
  inline static Array<i64> f = make_array<i64>(MAXN);
  inline static Array<i64> g = make_array<i64>(jshl(MAXN, 1));
  inline static i64 ans = 0;
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code07_HotHotels1() {}
  static void setf(int u, int i, i64 v) { (f[(fid[u] + i)] = v); }
  static i64 getf(int u, int i) { return f[(fid[u] + i)]; }
  static void setg(int u, int i, i64 v) { (g[(gid[u] + i)] = v); }
  static i64 getg(int u, int i) { return g[(gid[u] + i)]; }
  static void addEdge(int u, int v) {
    (next[(++cntg)] = head[u]);
    (to[cntg] = v);
    (head[u] = cntg);
  }
  static void dfs1(int u, int f) {
    (fa[u] = f);
    {
      int e = head[u];
      int v = {};
      for (; (e > 0); (e = next[e])) {
        (v = to[e]);
        if ((v != f)) {
          Code07_HotHotels1::dfs1(v, u);
        }
      }
    }
    {
      int e = head[u];
      int v = {};
      for (; (e > 0); (e = next[e])) {
        (v = to[e]);
        if ((v != f)) {
          if (((son[u] == 0) || (len[son[u]] < len[v]))) {
            (son[u] = v);
          }
        }
      }
    }
    (len[u] = (len[son[u]] + 1));
  }
  static void dfs2(int u, int top) {
    (fid[u] = (cntd++));
    if ((son[u] == 0)) {
      (gid[u] = (fid[top] * 2));
      return;
    }
    Code07_HotHotels1::dfs2(son[u], top);
    {
      int e = head[u];
      int v = {};
      for (; (e > 0); (e = next[e])) {
        (v = to[e]);
        if (((v != son[u]) && (v != fa[u]))) {
          Code07_HotHotels1::dfs2(v, v);
        }
      }
    }
    (gid[u] = (gid[son[u]] + 1));
  }
  static void dfs3(int u) {
    Code07_HotHotels1::setf(u, 0, 1);
    if ((son[u] == 0)) {
      return;
    }
    Code07_HotHotels1::dfs3(son[u]);
    {
      int e = head[u];
      int v = {};
      for (; (e > 0); (e = next[e])) {
        (v = to[e]);
        if (((v != son[u]) && (v != fa[u]))) {
          Code07_HotHotels1::dfs3(v);
        }
      }
    }
    {
      int e = head[u];
      int v = {};
      for (; (e > 0); (e = next[e])) {
        (v = to[e]);
        if (((v != son[u]) && (v != fa[u]))) {
          for (int i = 0; (i <= len[v]); (i++)) {
            if (((i < len[u]) && ((i - 1) >= 0))) {
              (ans += [&]() {
                auto jleft = Code07_HotHotels1::getg(u, i);
                auto jright = Code07_HotHotels1::getf(v, (i - 1));
                return (jleft * jright);
              }());
            }
            if (((i > 0) && ((i + 1) < len[v]))) {
              (ans += [&]() {
                auto jleft = Code07_HotHotels1::getf(u, i);
                auto jright = Code07_HotHotels1::getg(v, (i + 1));
                return (jleft * jright);
              }());
            }
          }
          for (int i = 0; (i <= len[v]); (i++)) {
            if (((i + 1) < len[v])) {
              Code07_HotHotels1::setg(u, i, [&]() {
                auto jleft = Code07_HotHotels1::getg(u, i);
                auto jright = Code07_HotHotels1::getg(v, (i + 1));
                return (jleft + jright);
              }());
            }
            if (((i - 1) >= 0)) {
              Code07_HotHotels1::setg(u, i, [&]() {
                auto jleft = Code07_HotHotels1::getg(u, i);
                auto jright = [&]() {
                  auto jleft = Code07_HotHotels1::getf(u, i);
                  auto jright = Code07_HotHotels1::getf(v, (i - 1));
                  return (jleft * jright);
                }();
                return (jleft + jright);
              }());
            }
          }
          for (int i = 0; (i <= len[v]); (i++)) {
            if (((i - 1) >= 0)) {
              Code07_HotHotels1::setf(u, i, [&]() {
                auto jleft = Code07_HotHotels1::getf(u, i);
                auto jright = Code07_HotHotels1::getf(v, (i - 1));
                return (jleft + jright);
              }());
            }
          }
        }
      }
    }
    (ans += Code07_HotHotels1::getg(u, 0));
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
        Code07_HotHotels1::addEdge(u, v);
        Code07_HotHotels1::addEdge(v, u);
      }
    }
    Code07_HotHotels1::dfs1(1, 0);
    Code07_HotHotels1::dfs2(1, 1);
    Code07_HotHotels1::dfs3(1);
    out.println(ans);
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code07_HotHotels1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 火热旅馆，java版
// 一共有n个节点，给定n-1条边，所有节点连成一棵树
// 三个点构成一个点组(a, b, c)，打乱顺序认为是同一个点组
// 求树上有多少点组，内部任意两个节点之间的距离是一样的
// 1 <= n <= 10^5
// 答案一定在long类型范围内
// 测试链接 : https://www.luogu.com.cn/problem/P5904
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 链式前向星
        // 长链剖分
        // 动态规划
        // 递归版，居然不改迭代版也能通过，那就不改了
        // 递归版，居然不改迭代版也能通过，那就不改了
        // 给每个节点分配fid和gid
        // 递归版，居然不改迭代版也能通过，那就不改了
        // 计算每个节点的f信息和g信息，同时统计答案
                                //
情况2，u树上，选择三个点，u没被选中，但跨u选点
                                        //
情况2的分支一，之前遍历的子树里选两个点，当前子树里选一个点
                                        //
情况2的分支二，之前遍历的子树里选一个点，当前子树里选两个点
                // 情况1，u树上，选择三个点，u被选中
*/

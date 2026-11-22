// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P2986

// Source: src/class120/Code03_GreatCowGathering2.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_GreatCowGathering2 {
  inline static int MAXN = 100001;
  inline static int n = {};
  inline static Array<int> cow = make_array<int>(MAXN);
  inline static int cowSum = {};
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> next = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> to = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> weight = make_array<int>(jshl(MAXN, 1));
  inline static int cnt = {};
  inline static int best = {};
  inline static int center = {};
  inline static Array<int> size = make_array<int>(MAXN);
  inline static Array<int> path = make_array<int>(MAXN);
  inline static Array<Array<int>> ufe = make_array<int>(MAXN, 3);
  inline static int stackSize = {};
  inline static int u = {};
  inline static int f = {};
  inline static int e = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_GreatCowGathering2() {}
  static void build() {
    (cnt = 1);
    j::fill(head, 1, (n + 1), 0);
    (cowSum = 0);
    (best = std::numeric_limits<int>::max());
  }
  static void addEdge(int u, int v, int w) {
    (next[cnt] = head[u]);
    (to[cnt] = v);
    (weight[cnt] = w);
    (head[u] = (cnt++));
  }
  static void push(int u, int f, int e) {
    (ufe[stackSize][0] = u);
    (ufe[stackSize][1] = f);
    (ufe[stackSize][2] = e);
    (stackSize++);
  }
  static void pop() {
    (--stackSize);
    (u = ufe[stackSize][0]);
    (f = ufe[stackSize][1]);
    (e = ufe[stackSize][2]);
  }
  static void findCenter(int root) {
    (stackSize = 0);
    Code03_GreatCowGathering2::push(root, 0, (-1));
    while ((stackSize > 0)) {
      Code03_GreatCowGathering2::pop();
      if ((e == (-1))) {
        (size[u] = cow[u]);
        (e = head[u]);
      } else {
        (e = next[e]);
      }
      if ((e != 0)) {
        Code03_GreatCowGathering2::push(u, f, e);
        if ((to[e] != f)) {
          Code03_GreatCowGathering2::push(to[e], u, (-1));
        }
      } else {
        int maxsub = 0;
        {
          int i = head[u];
          int v = {};
          for (; (i != 0); (i = next[i])) {
            (v = to[i]);
            if ((v != f)) {
              (size[u] += size[v]);
              (maxsub = jmax(maxsub, size[v]));
            }
          }
        }
        (maxsub = jmax(maxsub, (cowSum - size[u])));
        if ((maxsub < best)) {
          (best = maxsub);
          (center = u);
        }
      }
    }
  }
  static void setPath(int root) {
    (stackSize = 0);
    Code03_GreatCowGathering2::push(root, 0, (-1));
    while ((stackSize > 0)) {
      Code03_GreatCowGathering2::pop();
      if ((e == (-1))) {
        (e = head[u]);
      } else {
        (e = next[e]);
      }
      if ((e != 0)) {
        Code03_GreatCowGathering2::push(u, f, e);
        int v = to[e];
        if ((v != f)) {
          (path[v] = (path[u] + weight[e]));
          Code03_GreatCowGathering2::push(v, u, (-1));
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
    Code03_GreatCowGathering2::build();
    for (int i = 1; (i <= n); (i++)) {
      in.nextToken();
      (cow[i] = static_cast<int>(in.nval));
    }
    {
      int i = 1;
      int u = {};
      int v = {};
      int w = {};
      for (; (i < n); (i++)) {
        in.nextToken();
        (u = static_cast<int>(in.nval));
        in.nextToken();
        (v = static_cast<int>(in.nval));
        in.nextToken();
        (w = static_cast<int>(in.nval));
        Code03_GreatCowGathering2::addEdge(u, v, w);
        Code03_GreatCowGathering2::addEdge(v, u, w);
      }
    }
    out.println(Code03_GreatCowGathering2::compute());
    out.flush();
    out.close();
    br.close();
  }
  static i64 compute() {
    for (int i = 1; (i <= n); (i++)) {
      (cowSum += cow[i]);
    }
    Code03_GreatCowGathering2::findCenter(1);
    (path[center] = 0);
    Code03_GreatCowGathering2::setPath(center);
    i64 ans = 0;
    for (int i = 1; (i <= n); (i++)) {
      (ans += (static_cast<i64>(cow[i]) * path[i]));
    }
    return ans;
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code03_GreatCowGathering2::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 牛群聚集(迭代版)
// 一共有n个节点，编号1~n，每个点有牛的数量
// 一共有n-1条边把所有点连通起来形成一棵树，每条边有权值
// 想把所有的牛汇聚在一点，希望走过的总距离最小
// 返回总距离最小是多少
// 利用重心的性质：
// 树上的边权如果都>=0，不管边权怎么分布，所有节点都走向重心的总距离和最小
// 测试链接 : https://www.luogu.com.cn/problem/P2986
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有用例
        // ufe是为了实现迭代版而准备的栈
        // 迭代版
        // 不会改，看讲解118，讲了怎么从递归版改成迭代版
        // 迭代版
        // 不会改，看讲解118，讲了怎么从递归版改成迭代版
*/

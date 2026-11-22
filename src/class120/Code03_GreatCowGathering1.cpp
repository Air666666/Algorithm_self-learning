// Source: src/class120/Code03_GreatCowGathering1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_GreatCowGathering1 {
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
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_GreatCowGathering1() {}
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
  static void findCenter(int u, int f) {
    (size[u] = cow[u]);
    {
      int e = head[u];
      int v = {};
      for (; (e != 0); (e = next[e])) {
        (v = to[e]);
        if ((v != f)) {
          Code03_GreatCowGathering1::findCenter(v, u);
        }
      }
    }
    int maxsub = 0;
    {
      int e = head[u];
      int v = {};
      for (; (e != 0); (e = next[e])) {
        (v = to[e]);
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
  static void setPath(int u, int f) {
    {
      int e = head[u];
      int v = {};
      for (; (e != 0); (e = next[e])) {
        (v = to[e]);
        if ((v != f)) {
          (path[v] = (path[u] + weight[e]));
          Code03_GreatCowGathering1::setPath(v, u);
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
    Code03_GreatCowGathering1::build();
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
        Code03_GreatCowGathering1::addEdge(u, v, w);
        Code03_GreatCowGathering1::addEdge(v, u, w);
      }
    }
    out.println(Code03_GreatCowGathering1::compute());
    out.flush();
    out.close();
    br.close();
  }
  static i64 compute() {
    for (int i = 1; (i <= n); (i++)) {
      (cowSum += cow[i]);
    }
    Code03_GreatCowGathering1::findCenter(1, 0);
    (path[center] = 0);
    Code03_GreatCowGathering1::setPath(center, 0);
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
  Code03_GreatCowGathering1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 牛群聚集(递归版)
// 一共有n个节点，编号1~n，每个点有牛的数量
// 一共有n-1条边把所有点连通起来形成一棵树，每条边有权值
// 想把所有的牛汇聚在一点，希望走过的总距离最小
// 返回总距离最小是多少
// 利用重心的性质：
// 树上的边权如果都>=0，不管边权怎么分布，所有节点都走向重心的总距离和最小
// 测试链接 : https://www.luogu.com.cn/problem/P2986
// 提交以下的code，提交时请把类名改成"Main"
// C++这么写能通过，java会因为递归层数太多而爆栈
// java能通过的写法参考本节课Code03_GreatCowGathering2文件
        // cow[i] : i号农场牛的数量
        // 牛的总数
        // size[i] : 从1号节点开始dfs的过程中，以i为头的子树，牛的总量
        // path[i] : 从重心节点开始dfs的过程中，从重心到达i节点，距离是多少
                // 如下代码是遍历完成后再做统计工作
                // 这个写法和之前的逻辑是一样的，为什么要拆开写？
                // 为了后续改迭代版方便
*/

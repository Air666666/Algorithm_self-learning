// Source: src/class155/Code05_KShortestPath1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code05_KShortestPath1 {
  inline static int MAXN = 5001;
  inline static int MAXM = 200001;
  inline static int MAXT = 1000001;
  inline static int MAXH = 4200001;
  inline static double INF = 1e18;
  inline static int n = {};
  inline static int m = {};
  inline static double money = {};
  inline static Array<int> headg = make_array<int>(MAXN);
  inline static Array<int> tog = make_array<int>(MAXM);
  inline static Array<int> nextg = make_array<int>(MAXM);
  inline static Array<double> weightg = make_array<double>(MAXM);
  inline static int cntg = 0;
  inline static Array<int> headr = make_array<int>(MAXN);
  inline static Array<int> tor = make_array<int>(MAXM);
  inline static Array<int> nextr = make_array<int>(MAXM);
  inline static Array<double> weightr = make_array<double>(MAXM);
  inline static int cntr = 0;
  inline static Array<int> to = make_array<int>(MAXT);
  inline static Array<double> cost = make_array<double>(MAXT);
  inline static Array<int> left = make_array<int>(MAXT);
  inline static Array<int> right = make_array<int>(MAXT);
  inline static Array<int> dist = make_array<int>(MAXT);
  inline static int cntt = 0;
  inline static Array<int> rt = make_array<int>(MAXN);
  inline static Array<int> key = make_array<int>(MAXH);
  inline static Array<double> val = make_array<double>(MAXH);
  inline static Array<int> heap = make_array<int>(MAXH);
  inline static int cntd = {};
  inline static int cnth = {};
  inline static Array<bool> vis = make_array<bool>(MAXN);
  inline static Array<int> path = make_array<int>(MAXN);
  inline static Array<double> dis = make_array<double>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code05_KShortestPath1() {}
  static void addEdgeG(int u, int v, double w) {
    (nextg[(++cntg)] = headg[u]);
    (tog[cntg] = v);
    (weightg[cntg] = w);
    (headg[u] = cntg);
  }
  static void addEdgeR(int u, int v, double w) {
    (nextr[(++cntr)] = headr[u]);
    (tor[cntr] = v);
    (weightr[cntr] = w);
    (headr[u] = cntr);
  }
  static int init(int t, double c) {
    (to[(++cntt)] = t);
    (cost[cntt] = c);
    (left[cntt] = (right[cntt] = (dist[cntt] = 0)));
    return cntt;
  }
  static int clone(int i) {
    (to[(++cntt)] = to[i]);
    (cost[cntt] = cost[i]);
    (left[cntt] = left[i]);
    (right[cntt] = right[i]);
    (dist[cntt] = dist[i]);
    return cntt;
  }
  static int merge(int i, int j) {
    if (((i == 0) || (j == 0))) {
      return (i + j);
    }
    int tmp = {};
    if ((cost[i] > cost[j])) {
      (tmp = i);
      (i = j);
      (j = tmp);
    }
    int h = Code05_KShortestPath1::clone(i);
    (right[h] = Code05_KShortestPath1::merge(right[h], j));
    if ((dist[left[h]] < dist[right[h]])) {
      (tmp = left[h]);
      (left[h] = right[h]);
      (right[h] = tmp);
    }
    (dist[h] = (dist[right[h]] + 1));
    return h;
  }
  static void heapAdd(int k, double v) {
    (key[(++cntd)] = k);
    (val[cntd] = v);
    (heap[(++cnth)] = cntd);
    int cur = cnth;
    int father = jdiv(cur, 2);
    int tmp = {};
    while (((cur > 1) && (val[heap[father]] > val[heap[cur]]))) {
      (tmp = heap[father]);
      (heap[father] = heap[cur]);
      (heap[cur] = tmp);
      (cur = father);
      (father = jdiv(cur, 2));
    }
  }
  static int heapPop() {
    int ans = heap[1];
    (heap[1] = heap[(cnth--)]);
    int cur = 1;
    int l = (cur * 2);
    int r = (l + 1);
    int best = {};
    int tmp = {};
    while ((l <= cnth)) {
      (best = (((r <= cnth) && (val[heap[r]] < val[heap[l]])) ? r : l));
      (best = ((val[heap[best]] < val[heap[cur]]) ? best : cur));
      if ((best == cur)) {
        break;
      }
      (tmp = heap[best]);
      (heap[best] = heap[cur]);
      (heap[cur] = tmp);
      (cur = best);
      (l = (cur * 2));
      (r = (l + 1));
    }
    return ans;
  }
  static bool heapEmpty() { return (cnth == 0); }
  static void dijkstra() {
    (dis[n] = 0);
    j::fill(dis, 1, n, INF);
    (cntd = (cnth = 0));
    Code05_KShortestPath1::heapAdd(n, 0);
    while ((!Code05_KShortestPath1::heapEmpty())) {
      int top = Code05_KShortestPath1::heapPop();
      int u = key[top];
      double w = val[top];
      if ((!vis[u])) {
        (vis[u] = true);
        {
          int e = headr[u];
          int v = {};
          for (; (e > 0); (e = nextr[e])) {
            (v = tor[e]);
            if ((dis[v] > (w + weightr[e]))) {
              (dis[v] = (w + weightr[e]));
              (path[v] = e);
              Code05_KShortestPath1::heapAdd(v, dis[v]);
            }
          }
        }
      }
    }
  }
  static void mergeRoad() {
    (cntd = (cnth = 0));
    for (int i = 1; (i <= n); (i++)) {
      Code05_KShortestPath1::heapAdd(i, dis[i]);
    }
    (dist[0] = (-1));
    while ((!Code05_KShortestPath1::heapEmpty())) {
      int top = Code05_KShortestPath1::heapPop();
      int u = key[top];
      {
        int e = headg[u];
        int v = {};
        for (; (e > 0); (e = nextg[e])) {
          (v = tog[e]);
          if ((e != path[u])) {
            (rt[u] = Code05_KShortestPath1::merge(
                 rt[u], Code05_KShortestPath1::init(
                            v, ((weightg[e] + dis[v]) - dis[u]))));
          }
        }
      }
      if ((path[u] != 0)) {
        (rt[u] = Code05_KShortestPath1::merge(rt[u], rt[tog[path[u]]]));
      }
    }
  }
  static int expand() {
    int ans = 0;
    (money -= dis[1]);
    if ((money >= 0)) {
      (ans++);
      (cntd = (cnth = 0));
      if ((rt[1] != 0)) {
        Code05_KShortestPath1::heapAdd(rt[1], (dis[1] + cost[rt[1]]));
      }
      while ((!Code05_KShortestPath1::heapEmpty())) {
        int top = Code05_KShortestPath1::heapPop();
        int h = key[top];
        double w = val[top];
        (money -= w);
        if ((money < 0)) {
          break;
        }
        (ans++);
        if ((left[h] != 0)) {
          Code05_KShortestPath1::heapAdd(left[h],
                                         ((w - cost[h]) + cost[left[h]]));
        }
        if ((right[h] != 0)) {
          Code05_KShortestPath1::heapAdd(right[h],
                                         ((w - cost[h]) + cost[right[h]]));
        }
        if (((to[h] != 0) && (rt[to[h]] != 0))) {
          Code05_KShortestPath1::heapAdd(rt[to[h]], (w + cost[rt[to[h]]]));
        }
      }
    }
    return ans;
  }
  static void java_main(Array<String> args) {
    IO in = IO();
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (m = in.nextInt());
    (money = in.nextDouble());
    int u = {};
    int v = {};
    double w = {};
    for (int i = 1; (i <= m); (i++)) {
      (u = in.nextInt());
      (v = in.nextInt());
      (w = in.nextDouble());
      if ((u != n)) {
        Code05_KShortestPath1::addEdgeG(u, v, w);
        Code05_KShortestPath1::addEdgeR(v, u, w);
      }
    }
    Code05_KShortestPath1::dijkstra();
    Code05_KShortestPath1::mergeRoad();
    int ans = Code05_KShortestPath1::expand();
    out.println(ans);
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code05_KShortestPath1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// k短路问题，可持久化左偏树实现最优解，java版
// 有n个点编号1~n，有m条边，每条边都是正数边权，组成有向带权图
// 从1号点走到n号点，就认为是一次旅行
// 一次旅行中，边不能重复选，点可以重复经过，如果到达了n号点，那么旅行立刻停止
// 从1号点走到n号点，会有很多通路方案，通路方案的路费为选择边的边权累加和
// 虽然每次旅行都是从1号点到n号点，但是你希望每次旅行的通路方案都是不同的
// 任何两次旅行，只要选择的边稍有不同，就认为是不同的通路方案
// 你的钱数为money，用来支付路费，打印你一共能进行几次旅行
// 测试链接 : https://www.luogu.com.cn/problem/P2483
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 关于正反图有一个非常值得注意的地方
        // 如果正图中，a到b的边，编号为x
        // 那么反图中，b到a的边，编号也是x
        // 因为每一条边，正图建立的同时，反图也同步建立
        // 所以正反图中这条边分配的编号也是一样的
        // 正图
        // 反图
        // 左偏树代表基于之前的通路方案，选择非树边的可能性
        // 左偏树的头就代表最优的选择，假设编号为h的节点是头
        // to[h] : 选择最优非树边，这个非树边在正图里指向哪个节点
        // cost[h] : 基于之前的通路方案，最优选择会让路费增加多少
        // rt[u] :
在最短路树上，节点u及其所有祖先节点，所拥有的全部非树边，组成的左偏树
        // heap是经典的小根堆，放着很多(key, val)数据，根据val来组织小根堆
        // dijkstra算法需要，根据反图跑dijkstra，生成从节点n开始的最短路树
        // vis[u] : 节点u到节点n的最短距离，是否已经计算过了
        // path[u] :
最短路树上，到达节点u的树边，编号是什么，也代表正图上，所对应的边
        // dis[u] : 最短路树上，节点n到节点u的最短距离
        // (k, v)组成一个数据，放到堆上，根据v来组织小根堆
        // 小根堆上，堆顶的数据(k, v)弹出，并返回数据所在的下标ans
        // 根据返回值ans，key[ans]得到k，val[ans]得到v
        // 根据反图跑dijkstra算法
        // 得到从节点n出发的最短路树、每个节点到节点n的最短距离信息
        // 最短路树如果有多个，找到任何一个即可
        // 在最短路树上的每个节点，生成自己的左偏树
        // 节点u的左偏树 = 节点u自己的非树边左偏树 +
节点u在最短路树上的父亲的左偏树
        // 课上重点解释了这么做的意义
                                //
path[u]既是边在反图中的编号，也是边在正图中的编号
                                // 因为正反图同步建立，边的正图编号 ==
边的反图编号
        // 从路费第1小的方案开始，逐渐找到第2小、第3小...
        // 看看money能够覆盖几次旅行，返回旅行的次数
                                // 开始阶段
                                //
1号节点左偏树的堆顶，代表增加代价最小的非树边，放入决策堆
                                // 目前路通方案的路费，同步放入
                                // 当前选择的非树边，被左偏树上的左儿子替换
                                // 当前选择的非树边，被左偏树上的右儿子替换
                                //
当前选择的非树边，指向节点to[h]，那么从to[h]的左偏树里，新增一个最优的非树边
                        // 题目说了，一旦到达节点n，旅行立刻停止
                        // 所以从节点n出发的边，一律忽略
        // 读写工具类
*/

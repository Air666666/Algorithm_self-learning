// Source: src/class064/Code06_FlightPath2.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code06_FlightPath2 {
  inline static int MAXN = 10001;
  inline static int MAXM = 100001;
  inline static int MAXK = 11;
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> next = make_array<int>(MAXM);
  inline static Array<int> to = make_array<int>(MAXM);
  inline static Array<int> weight = make_array<int>(MAXM);
  inline static int cnt = {};
  inline static Array<Array<int>> distance = make_array<int>(MAXN, MAXK);
  inline static Array<Array<bool>> visited = make_array<bool>(MAXN, MAXK);
  inline static Array<Array<int>> heap = make_array<int>((MAXM * MAXK), 3);
  inline static int heapSize = {};
  inline static int n = {};
  inline static int m = {};
  inline static int k = {};
  inline static int s = {};
  inline static int t = {};
  inline static int u = {};
  inline static int use = {};
  inline static int cost = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code06_FlightPath2() {}
  static void build() {
    (cnt = 1);
    (heapSize = 0);
    for (int i = 0; (i < n); (i++)) {
      (head[i] = 0);
      for (int j = 0; (j <= k); (j++)) {
        (distance[i][j] = std::numeric_limits<int>::max());
        (visited[i][j] = false);
      }
    }
  }
  static void addEdge(int u, int v, int w) {
    (next[cnt] = head[u]);
    (to[cnt] = v);
    (weight[cnt] = w);
    (head[u] = (cnt++));
  }
  static void push(int u, int t, int c) {
    (heap[heapSize][0] = u);
    (heap[heapSize][1] = t);
    (heap[heapSize][2] = c);
    int i = (heapSize++);
    while ((heap[i][2] < heap[jdiv((i - 1), 2)][2])) {
      Code06_FlightPath2::swap(i, jdiv((i - 1), 2));
      (i = jdiv((i - 1), 2));
    }
  }
  static void pop() {
    (u = heap[0][0]);
    (use = heap[0][1]);
    (cost = heap[0][2]);
    Code06_FlightPath2::swap(0, (--heapSize));
    Code06_FlightPath2::heapify(0);
  }
  static void heapify(int i) {
    int l = ((i * 2) + 1);
    while ((l < heapSize)) {
      int best =
          ((((l + 1) < heapSize) && (heap[(l + 1)][2] < heap[l][2])) ? (l + 1)
                                                                     : l);
      (best = ((heap[best][2] < heap[i][2]) ? best : i));
      if ((best == i)) {
        break;
      }
      Code06_FlightPath2::swap(best, i);
      (i = best);
      (l = ((i * 2) + 1));
    }
  }
  static void swap(int i, int j) {
    Array<int> tmp = heap[i];
    (heap[i] = heap[j]);
    (heap[j] = tmp);
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    while ((in.nextToken() != -1)) {
      (n = static_cast<int>(in.nval));
      in.nextToken();
      (m = static_cast<int>(in.nval));
      in.nextToken();
      (k = static_cast<int>(in.nval));
      in.nextToken();
      (s = static_cast<int>(in.nval));
      in.nextToken();
      (t = static_cast<int>(in.nval));
      Code06_FlightPath2::build();
      {
        int i = 0;
        int a = {};
        int b = {};
        int c = {};
        for (; (i < m); (i++)) {
          in.nextToken();
          (a = static_cast<int>(in.nval));
          in.nextToken();
          (b = static_cast<int>(in.nval));
          in.nextToken();
          (c = static_cast<int>(in.nval));
          Code06_FlightPath2::addEdge(a, b, c);
          Code06_FlightPath2::addEdge(b, a, c);
        }
      }
      out.println(Code06_FlightPath2::dijkstra());
    }
    out.flush();
    out.close();
    br.close();
  }
  static int dijkstra() {
    (distance[s][0] = 0);
    Code06_FlightPath2::push(s, 0, 0);
    while ((heapSize > 0)) {
      Code06_FlightPath2::pop();
      if (visited[u][use]) {
        continue;
      }
      (visited[u][use] = true);
      if ((u == t)) {
        return cost;
      }
      {
        int ei = head[u];
        int v = {};
        int w = {};
        for (; (ei > 0); (ei = next[ei])) {
          (v = to[ei]);
          (w = weight[ei]);
          if (((use < k) && (distance[v][(use + 1)] > distance[u][use]))) {
            (distance[v][(use + 1)] = distance[u][use]);
            Code06_FlightPath2::push(v, (use + 1), distance[v][(use + 1)]);
          }
          if ((distance[v][use] > (distance[u][use] + w))) {
            (distance[v][use] = (distance[u][use] + w));
            Code06_FlightPath2::push(v, use, distance[v][use]);
          }
        }
      }
    }
    return (-1);
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code06_FlightPath2::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 飞行路线（自己手撸的堆）
// Alice和Bob现在要乘飞机旅行，他们选择了一家相对便宜的航空公司
// 该航空公司一共在n个城市设有业务，设这些城市分别标记为0 ~ n−1
// 一共有m种航线，每种航线连接两个城市，并且航线有一定的价格
// Alice 和 Bob 现在要从一个城市沿着航线到达另一个城市，途中可以进行转机
// 航空公司对他们这次旅行也推出优惠，他们可以免费在最多k种航线上搭乘飞机
// 那么 Alice 和 Bob 这次出行最少花费多少
// 测试链接 : https://www.luogu.com.cn/problem/P4568
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下所有代码，把主类名改成Main，可以直接通过
        // 链式前向星建图需要
        // Dijkstra需要
        // 自己写的普通堆，静态结构，推荐
        // 注意是自己写的普通堆，不是反向索引堆
        // 因为(点编号，使用免费路线的次数)，两个参数的组合才是图中的点
        // 两个参数的组合对应一个点(一个堆的下标)，所以反向索引堆不好写
        // 其实也能实现，二维点变成一维下标即可
        // 但是会造成很多困惑，索性算了，就手写普通堆吧
                                // 常见剪枝
                                // 发现终点直接返回
                                // 不用等都结束
                                        // 使用免费
                                        // 不用免费
*/

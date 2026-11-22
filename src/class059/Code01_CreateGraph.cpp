// Source: src/class059/Code01_CreateGraph.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_CreateGraph {
  inline static int MAXN = 11;
  inline static int MAXM = 21;
  inline static Array<Array<int>> graph1 = make_array<int>(MAXN, MAXN);
  inline static JList<JList<Array<int>>> graph2 = JList<JList<Array<int>>>();
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> next = make_array<int>(MAXM);
  inline static Array<int> to = make_array<int>(MAXM);
  inline static Array<int> weight = make_array<int>(MAXM);
  inline static int cnt = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_CreateGraph() {}
  static void build(int n) {
    for (int i = 1; (i <= n); (i++)) {
      for (int j = 1; (j <= n); (j++)) {
        (graph1[i][j] = 0);
      }
    }
    graph2.clear();
    for (int i = 0; (i <= n); (i++)) {
      graph2.add(JList<Array<int>>());
    }
    (cnt = 1);
    j::fill(head, 1, (n + 1), 0);
  }
  static void addEdge(int u, int v, int w) {
    (next[cnt] = head[u]);
    (to[cnt] = v);
    (weight[cnt] = w);
    (head[u] = (cnt++));
  }
  static void directGraph(Array<Array<int>> edges) {
    for (Array<int> edge : edges) {
      (graph1[edge[0]][edge[1]] = edge[2]);
    }
    for (Array<int> edge : edges) {
      graph2.get(edge[0]).add(Array<int>{edge[1], edge[2]});
    }
    for (Array<int> edge : edges) {
      Code01_CreateGraph::addEdge(edge[0], edge[1], edge[2]);
    }
  }
  static void undirectGraph(Array<Array<int>> edges) {
    for (Array<int> edge : edges) {
      (graph1[edge[0]][edge[1]] = edge[2]);
      (graph1[edge[1]][edge[0]] = edge[2]);
    }
    for (Array<int> edge : edges) {
      graph2.get(edge[0]).add(Array<int>{edge[1], edge[2]});
      graph2.get(edge[1]).add(Array<int>{edge[0], edge[2]});
    }
    for (Array<int> edge : edges) {
      Code01_CreateGraph::addEdge(edge[0], edge[1], edge[2]);
      Code01_CreateGraph::addEdge(edge[1], edge[0], edge[2]);
    }
  }
  static void traversal(int n) {
    jout.println(String(u"邻接矩阵遍历 :"));
    for (int i = 1; (i <= n); (i++)) {
      for (int j = 1; (j <= n); (j++)) {
        jout.print((graph1[i][j] + String(u" ")));
      }
      jout.println();
    }
    jout.println(String(u"邻接表遍历 :"));
    for (int i = 1; (i <= n); (i++)) {
      jout.print((i + String(u"(邻居、边权) : ")));
      for (Array<int> edge : graph2.get(i)) {
        jout.print(((((String(u"(") + edge[0]) + String(u",")) + edge[1]) +
                    String(u") ")));
      }
      jout.println();
    }
    jout.println(String(u"链式前向星 :"));
    for (int i = 1; (i <= n); (i++)) {
      jout.print((i + String(u"(邻居、边权) : ")));
      for (int ei = head[i]; (ei > 0); (ei = next[ei])) {
        jout.print(((((String(u"(") + to[ei]) + String(u",")) + weight[ei]) +
                    String(u") ")));
      }
      jout.println();
    }
  }
  static void java_main(Array<String> args) {
    int n1 = 4;
    Array<Array<int>> edges1 = Array<Array<int>>{
        Array<int>{1, 3, 6}, Array<int>{4, 3, 4}, Array<int>{2, 4, 2},
        Array<int>{1, 2, 7}, Array<int>{2, 3, 5}, Array<int>{3, 1, 1}};
    Code01_CreateGraph::build(n1);
    Code01_CreateGraph::directGraph(edges1);
    Code01_CreateGraph::traversal(n1);
    jout.println(String(u"=============================="));
    int n2 = 5;
    Array<Array<int>> edges2 = Array<Array<int>>{
        Array<int>{3, 5, 4}, Array<int>{4, 1, 1}, Array<int>{3, 4, 2},
        Array<int>{5, 2, 4}, Array<int>{2, 3, 7}, Array<int>{1, 5, 5},
        Array<int>{4, 2, 6}};
    Code01_CreateGraph::build(n2);
    Code01_CreateGraph::undirectGraph(edges2);
    Code01_CreateGraph::traversal(n2);
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code01_CreateGraph::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
        // 点的最大数量
        // 边的最大数量
        // 只有链式前向星方式建图需要这个数量
        // 注意如果无向图的最大数量是m条边，数量要准备m*2
        // 因为一条无向边要加两条有向边
        // 邻接矩阵方式建图
        // 邻接表方式建图
        // public static ArrayList<ArrayList<Integer>> graph2 = new
   ArrayList<>();
        // 链式前向星方式建图
        // 如果边有权重，那么需要这个数组
                // 邻接矩阵清空
                // 邻接表清空和准备
                // 下标需要支持1~n，所以加入n+1个列表，0下标准备但不用
                // 链式前向星清空
        // 链式前向星加边
                // u -> v , 边权重是w
        // 三种方式建立有向图带权图
                // 邻接矩阵建图
                // 邻接表建图
                        // graph2.get(edge[0]).add(edge[1]);
                // 链式前向星建图
        // 三种方式建立无向图带权图
                // 邻接矩阵建图
                // 邻接表建图
                        // graph2.get(edge[0]).add(edge[1]);
                        // graph2.get(edge[1]).add(edge[0]);
                // 链式前向星建图
                        // 注意这个for循环，链式前向星的方式遍历
                // 理解了带权图的建立过程，也就理解了不带权图
                // 点的编号为1...n
                // 例子1自己画一下图，有向带权图，然后打印结果
                // 例子2自己画一下图，无向带权图，然后打印结果
*/

// Source: src/class061/Code01_Kruskal.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_Kruskal {
  inline static int MAXN = 5001;
  inline static int MAXM = 200001;
  inline static Array<int> father = make_array<int>(MAXN);
  inline static Array<Array<int>> edges = make_array<int>(MAXM, 3);
  inline static int n = {};
  inline static int m = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_Kruskal() {}
  static void build() {
    for (int i = 1; (i <= n); (i++)) {
      (father[i] = i);
    }
  }
  static int find(int i) {
    if ((i != father[i])) {
      (father[i] = Code01_Kruskal::find(father[i]));
    }
    return father[i];
  }
  static bool union_method(int x, int y) {
    int fx = Code01_Kruskal::find(x);
    int fy = Code01_Kruskal::find(y);
    if ((fx != fy)) {
      (father[fx] = fy);
      return true;
    } else {
      return false;
    }
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    while ((in.nextToken() != -1)) {
      (n = static_cast<int>(in.nval));
      in.nextToken();
      (m = static_cast<int>(in.nval));
      Code01_Kruskal::build();
      for (int i = 0; (i < m); (i++)) {
        in.nextToken();
        (edges[i][0] = static_cast<int>(in.nval));
        in.nextToken();
        (edges[i][1] = static_cast<int>(in.nval));
        in.nextToken();
        (edges[i][2] = static_cast<int>(in.nval));
      }
      j::sort(edges, 0, m,
              [=](Array<int> a, Array<int> b) { return (a[2] - b[2]); });
      int ans = 0;
      int edgeCnt = 0;
      for (Array<int> edge : edges) {
        if (Code01_Kruskal::union_method(edge[0], edge[1])) {
          (edgeCnt++);
          (ans += edge[2]);
        }
      }
      out.println(((edgeCnt == (n - 1)) ? j::str(ans) : String(u"orz")));
    }
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code01_Kruskal::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// Kruskal算法模版（洛谷）
// 静态空间实现
// 测试链接 : https://www.luogu.com.cn/problem/P3366
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下所有代码，把主类名改成Main，可以直接通过
// 时间复杂度O(m * log m) + O(n + m)
        // u, v, w
        // 如果x和y本来就是一个集合，返回false
        // 如果x和y不是一个集合，合并之后返回true
*/

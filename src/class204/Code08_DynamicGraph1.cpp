// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P5489

// Source: src/class204/Code08_DynamicGraph1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code08_DynamicGraph1 {
  inline static int MAXN = 100001;
  inline static int MAXT = 400001;
  inline static int n = {};
  inline static int q = {};
  inline static Array<int> father = make_array<int>(MAXN);
  inline static Array<int> fa = make_array<int>(MAXT);
  inline static Array<int> ls = make_array<int>(MAXT);
  inline static Array<int> rs = make_array<int>(MAXT);
  inline static Array<bool> rev = make_array<bool>(MAXT);
  inline static Array<int> sta = make_array<int>(MAXT);
  inline static int cnt = {};
  inline static Array<int> val = make_array<int>(MAXT);
  inline static Array<int> sum = make_array<int>(MAXT);
  inline static Array<bool> zeroTag = make_array<bool>(MAXT);
  inline static Array<int> road = make_array<int>(MAXT);
  inline static int roadLen = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code08_DynamicGraph1() {}
  static int find(int x) {
    if ((father[x] != x)) {
      (father[x] = Code08_DynamicGraph1::find(father[x]));
    }
    return father[x];
  }
  static void up(int x) { (sum[x] = ((sum[ls[x]] + sum[rs[x]]) + val[x])); }
  static bool isroot(int x) { return ((ls[fa[x]] != x) && (rs[fa[x]] != x)); }
  static int lr(int x) { return ((ls[fa[x]] == x) ? 0 : 1); }
  static void reverse(int x) {
    if ((x != 0)) {
      int tmp = ls[x];
      (ls[x] = rs[x]);
      (rs[x] = tmp);
      (rev[x] = (!rev[x]));
    }
  }
  static void setZero(int x) {
    if ((x != 0)) {
      (val[x] = 0);
      (sum[x] = 0);
      (zeroTag[x] = true);
    }
  }
  static void down(int x) {
    if (rev[x]) {
      Code08_DynamicGraph1::reverse(ls[x]);
      Code08_DynamicGraph1::reverse(rs[x]);
      (rev[x] = false);
    }
    if (zeroTag[x]) {
      Code08_DynamicGraph1::setZero(ls[x]);
      Code08_DynamicGraph1::setZero(rs[x]);
      (zeroTag[x] = false);
    }
  }
  static void rotate(int x) {
    int f = fa[x];
    int g = fa[f];
    if ((Code08_DynamicGraph1::lr(x) == 0)) {
      (ls[f] = rs[x]);
      if ((ls[f] != 0)) {
        (fa[ls[f]] = f);
      }
      (rs[x] = f);
    } else {
      (rs[f] = ls[x]);
      if ((rs[f] != 0)) {
        (fa[rs[f]] = f);
      }
      (ls[x] = f);
    }
    if ((!Code08_DynamicGraph1::isroot(f))) {
      if ((Code08_DynamicGraph1::lr(f) == 0)) {
        (ls[g] = x);
      } else {
        (rs[g] = x);
      }
    }
    (fa[f] = x);
    (fa[x] = g);
    Code08_DynamicGraph1::up(f);
    Code08_DynamicGraph1::up(x);
  }
  static void splay(int x) {
    int size = 0;
    (sta[(++size)] = x);
    for (int y = x; (!Code08_DynamicGraph1::isroot(y)); (y = fa[y])) {
      (sta[(++size)] = fa[y]);
    }
    while ((size != 0)) {
      Code08_DynamicGraph1::down(sta[(size--)]);
    }
    while ((!Code08_DynamicGraph1::isroot(x))) {
      int f = fa[x];
      if ((!Code08_DynamicGraph1::isroot(f))) {
        if ([&]() {
              auto jleft = Code08_DynamicGraph1::lr(x);
              auto jright = Code08_DynamicGraph1::lr(f);
              return (jleft == jright);
            }()) {
          Code08_DynamicGraph1::rotate(f);
        } else {
          Code08_DynamicGraph1::rotate(x);
        }
      }
      Code08_DynamicGraph1::rotate(x);
    }
    Code08_DynamicGraph1::up(x);
  }
  static void access(int x) {
    for (int y = 0; (x != 0); (y = x), (x = fa[x])) {
      Code08_DynamicGraph1::splay(x);
      (rs[x] = y);
      Code08_DynamicGraph1::up(x);
    }
  }
  static void makeroot(int x) {
    Code08_DynamicGraph1::access(x);
    Code08_DynamicGraph1::splay(x);
    Code08_DynamicGraph1::reverse(x);
  }
  static void split(int x, int y) {
    Code08_DynamicGraph1::makeroot(x);
    Code08_DynamicGraph1::access(y);
    Code08_DynamicGraph1::splay(y);
  }
  static void link(int x, int y) {
    Code08_DynamicGraph1::makeroot(x);
    (fa[x] = y);
  }
  static void cut(int x, int y) {
    Code08_DynamicGraph1::split(x, y);
    (fa[x] = 0);
    (ls[y] = 0);
    Code08_DynamicGraph1::up(y);
  }
  static void inOrder(int x) {
    if ((x != 0)) {
      Code08_DynamicGraph1::down(x);
      Code08_DynamicGraph1::inOrder(ls[x]);
      (road[(++roadLen)] = x);
      Code08_DynamicGraph1::inOrder(rs[x]);
    }
  }
  static void addEdge(int x, int y) {
    int fx = Code08_DynamicGraph1::find(x);
    int fy = Code08_DynamicGraph1::find(y);
    if ((fx != fy)) {
      (father[fy] = fx);
      int edge = (++cnt);
      (val[edge] = 1);
      (sum[edge] = 1);
      Code08_DynamicGraph1::link(x, edge);
      Code08_DynamicGraph1::link(y, edge);
      Code08_DynamicGraph1::link((x + n), (y + n));
    } else {
      Code08_DynamicGraph1::split(x, y);
      Code08_DynamicGraph1::setZero(y);
      (x = (x + n));
      (y = (y + n));
      Code08_DynamicGraph1::split(x, y);
      if ((sum[y] > 2)) {
        (roadLen = 0);
        Code08_DynamicGraph1::inOrder(y);
        for (int i = 2; (i <= roadLen); (i++)) {
          Code08_DynamicGraph1::cut(road[(i - 1)], road[i]);
        }
        int square = (++cnt);
        for (int i = 1; (i <= roadLen); (i++)) {
          Code08_DynamicGraph1::link(road[i], square);
        }
      }
    }
  }
  static int queryCute(int x, int y) {
    if ([&]() {
          auto jleft = Code08_DynamicGraph1::find(x);
          auto jright = Code08_DynamicGraph1::find(y);
          return (jleft != jright);
        }()) {
      return (-1);
    }
    Code08_DynamicGraph1::split(x, y);
    return sum[y];
  }
  static int queryCutv(int x, int y) {
    if ([&]() {
          auto jleft = Code08_DynamicGraph1::find(x);
          auto jright = Code08_DynamicGraph1::find(y);
          return (jleft != jright);
        }()) {
      return (-1);
    }
    (x = (x + n));
    (y = (y + n));
    Code08_DynamicGraph1::split(x, y);
    return sum[y];
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (q = in.nextInt());
    (cnt = jshl(n, 1));
    for (int i = 1; (i <= n); (i++)) {
      (father[i] = i);
      (val[(i + n)] = 1);
      (sum[(i + n)] = 1);
    }
    {
      int i = 1;
      int lastAns = 0;
      int curAns = {};
      int op = {};
      int x = {};
      int y = {};
      for (; (i <= q); (i++)) {
        (op = in.nextInt());
        (x = in.nextInt());
        (y = in.nextInt());
        (x ^= lastAns);
        (y ^= lastAns);
        if ((op == 1)) {
          Code08_DynamicGraph1::addEdge(x, y);
        } else {
          if ((op == 2)) {
            (curAns = Code08_DynamicGraph1::queryCute(x, y));
          } else {
            (curAns = Code08_DynamicGraph1::queryCutv(x, y));
          }
          out.println(curAns);
          if ((curAns != (-1))) {
            (lastAns = curAns);
          }
        }
      }
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code08_DynamicGraph1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// LCT与动态图，java版
// 初始有n个孤立节点，接下来有q条操作，操作类型如下
// 操作 1 x y : 点x和点y之间增加一条无向边，两点之前可能连通
// 操作 2 x y : 打印点x到点y的路径中，必经边的数量，不连通打印-1
// 操作 3 x y : 打印点x到点y的路径中，必经点的数量，不连通打印-1
// 必经点包括节点x和节点y本身
// 本题要求强制在线，得到操作参数的规则，打开测试链接查看
// 1 <= n <= 10^5
// 1 <= q <= 3 * 10^5
// 测试链接 : https://www.luogu.com.cn/problem/P5489
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 并查集维护连通性，因为本题卡常，用LCT判断连通性会超时
        // 节点x参与割边LCT和割点LCT，两套LCT共用一套数组，但彼此独立
        // x表示割边LCT中的点，x+n表示割点LCT中的点
        // 割边LCT需要给边分配编号，割点LCT需要给方点分配编号
        // 都用cnt进行分配，初始值2*n，然后(++cnt)产生新编号
        // 两套LCT都有单点贡献和贡献汇总，并且汇总函数up都是一样的
        //
只给割边LCT使用，zeroTag[x]表示以x为根的辅助splay中，所有边节点的贡献变成0
        // 收集割点LCT中的路径
        // 只对割边LCT生效，整棵辅助splay的贡献变成0
                // zeroTag只对割边LCT生效
        // 保证x和y当前不连通，所以化简了写法
        // 保证x和y之间存在直接边，所以化简了写法
        // 中序遍历收集节点，相当于实链中，从上到下依次收集节点
                        // 先处理翻转的懒更新，左右儿子确保更新正确
                        // 割边LCT中，新边变成LCT中的点，新边是割边，贡献是1
                        // 割点LCT中，此时是割边，两个圆点直接连接，不建立方点
                        // 如果x和y已经连通，那么此时形成环
                        // 割边LCT中，x到y路径上的所有边都进入环
                        // 从此不再是割边，贡献都变成0
                        // 切换到割点LCT中对应的两个状态节点
                        // 暴露当前动态圆方树中x到y的路径
                                // 辅助splay中，按照中序遍历收集节点，核心是中序
                                // 等同于按照当前实链从x到y的顺序收集所有节点
                                // 删除原来路径中的边
                                // 新建方点，形成更大的点双连通分量
                                // 原路径上的所有圆点和旧方点，连接到新方点
                // 并查集初始化
                // 割边LCT中的原节点贡献为0，无需设置
                // 割点LCT中的原节点是圆点，设置贡献是1
        // 读写工具类
*/

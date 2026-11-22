// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P3242

// Source: src/class169/Code04_Fruit1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_Fruit1 {
  inline static int MAXN = 40001;
  inline static int MAXP = 16;
  inline static int INF = 1000000001;
  inline static int n = {};
  inline static int p = {};
  inline static int q = {};
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> next = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> to = make_array<int>(jshl(MAXN, 1));
  inline static int cntg = 0;
  inline static Array<int> dep = make_array<int>(MAXN);
  inline static Array<int> ldfn = make_array<int>(MAXN);
  inline static Array<int> rdfn = make_array<int>(MAXN);
  inline static Array<Array<int>> stjump = make_array<int>(MAXN, MAXP);
  inline static int cntd = 0;
  inline static Array<int> tree = make_array<int>(MAXN);
  inline static Array<int> eid = make_array<int>(jshl(MAXN, 3));
  inline static Array<Array<int>> event = make_array<int>(jshl(MAXN, 3), 8);
  inline static int cnte = 0;
  inline static Array<int> lset = make_array<int>(jshl(MAXN, 3));
  inline static Array<int> rset = make_array<int>(jshl(MAXN, 3));
  inline static Array<int> ans = make_array<int>(MAXN);
  inline static Array<Array<int>> ufe = make_array<int>(MAXN, 3);
  inline static int stacksize = {};
  inline static int u = {};
  inline static int f = {};
  inline static int e = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_Fruit1() {}
  static void addEdge(int u, int v) {
    (next[(++cntg)] = head[u]);
    (to[cntg] = v);
    (head[u] = cntg);
  }
  static void dfs1(int u, int fa) {
    (dep[u] = (dep[fa] + 1));
    (ldfn[u] = (++cntd));
    (stjump[u][0] = fa);
    for (int p = 1; (p < MAXP); (p++)) {
      (stjump[u][p] = stjump[stjump[u][(p - 1)]][(p - 1)]);
    }
    for (int e = head[u]; (e > 0); (e = next[e])) {
      if ((to[e] != fa)) {
        Code04_Fruit1::dfs1(to[e], u);
      }
    }
    (rdfn[u] = cntd);
  }
  static void push(int u, int f, int e) {
    (ufe[stacksize][0] = u);
    (ufe[stacksize][1] = f);
    (ufe[stacksize][2] = e);
    (stacksize++);
  }
  static void pop() {
    (--stacksize);
    (u = ufe[stacksize][0]);
    (f = ufe[stacksize][1]);
    (e = ufe[stacksize][2]);
  }
  static void dfs2() {
    (stacksize = 0);
    Code04_Fruit1::push(1, 0, (-1));
    while ((stacksize > 0)) {
      Code04_Fruit1::pop();
      if ((e == (-1))) {
        (dep[u] = (dep[f] + 1));
        (ldfn[u] = (++cntd));
        (stjump[u][0] = f);
        for (int p = 1; (p < MAXP); (p++)) {
          (stjump[u][p] = stjump[stjump[u][(p - 1)]][(p - 1)]);
        }
        (e = head[u]);
      } else {
        (e = next[e]);
      }
      if ((e != 0)) {
        Code04_Fruit1::push(u, f, e);
        if ((to[e] != f)) {
          Code04_Fruit1::push(to[e], u, (-1));
        }
      } else {
        (rdfn[u] = cntd);
      }
    }
  }
  static int lca(int a, int b) {
    if ((dep[a] < dep[b])) {
      int tmp = a;
      (a = b);
      (b = tmp);
    }
    for (int p = (MAXP - 1); (p >= 0); (p--)) {
      if ((dep[stjump[a][p]] >= dep[b])) {
        (a = stjump[a][p]);
      }
    }
    if ((a == b)) {
      return a;
    }
    for (int p = (MAXP - 1); (p >= 0); (p--)) {
      if ((stjump[a][p] != stjump[b][p])) {
        (a = stjump[a][p]);
        (b = stjump[b][p]);
      }
    }
    return stjump[a][0];
  }
  static int lcaSon(int a, int b) {
    if ((dep[a] < dep[b])) {
      int tmp = a;
      (a = b);
      (b = tmp);
    }
    for (int p = (MAXP - 1); (p >= 0); (p--)) {
      if ((dep[stjump[a][p]] > dep[b])) {
        (a = stjump[a][p]);
      }
    }
    return a;
  }
  static int lowbit(int i) { return (i & (-i)); }
  static void add(int i, int v) {
    while ((i <= n)) {
      (tree[i] += v);
      (i += Code04_Fruit1::lowbit(i));
    }
  }
  static void add(int l, int r, int v) {
    Code04_Fruit1::add(l, v);
    Code04_Fruit1::add((r + 1), (-v));
  }
  static int query(int i) {
    int ret = 0;
    while ((i > 0)) {
      (ret += tree[i]);
      (i -= Code04_Fruit1::lowbit(i));
    }
    return ret;
  }
  static void addPlate(int x, int yl, int yr, int v) {
    (event[(++cnte)][0] = 1);
    (event[cnte][1] = x);
    (event[cnte][2] = yl);
    (event[cnte][3] = yr);
    (event[cnte][4] = v);
  }
  static void delPlate(int x, int yl, int yr, int v) {
    (event[(++cnte)][0] = 2);
    (event[cnte][1] = x);
    (event[cnte][2] = yl);
    (event[cnte][3] = yr);
    (event[cnte][4] = v);
  }
  static void addFruit(int x, int y, int k, int i) {
    (event[(++cnte)][0] = 3);
    (event[cnte][1] = x);
    (event[cnte][5] = y);
    (event[cnte][6] = k);
    (event[cnte][7] = i);
  }
  static void compute(int el, int er, int vl, int vr) {
    if ((el > er)) {
      return;
    }
    if ((vl == vr)) {
      for (int i = el; (i <= er); (i++)) {
        int id = eid[i];
        if ((event[id][0] == 3)) {
          (ans[event[id][7]] = vl);
        }
      }
    } else {
      int mid = jshr((vl + vr), 1);
      int lsiz = 0;
      int rsiz = 0;
      for (int i = el; (i <= er); (i++)) {
        int id = eid[i];
        if ((event[id][0] == 1)) {
          if ((event[id][4] <= mid)) {
            Code04_Fruit1::add(event[id][2], event[id][3], 1);
            (lset[(++lsiz)] = id);
          } else {
            (rset[(++rsiz)] = id);
          }
        } else if ((event[id][0] == 2)) {
          if ((event[id][4] <= mid)) {
            Code04_Fruit1::add(event[id][2], event[id][3], (-1));
            (lset[(++lsiz)] = id);
          } else {
            (rset[(++rsiz)] = id);
          }
        } else {
          int satisfy = Code04_Fruit1::query(event[id][5]);
          if ((satisfy >= event[id][6])) {
            (lset[(++lsiz)] = id);
          } else {
            (event[id][6] -= satisfy);
            (rset[(++rsiz)] = id);
          }
        }
      }
      for (int i = 1; (i <= lsiz); (i++)) {
        (eid[((el + i) - 1)] = lset[i]);
      }
      for (int i = 1; (i <= rsiz); (i++)) {
        (eid[(((el + lsiz) + i) - 1)] = rset[i]);
      }
      Code04_Fruit1::compute(el, ((el + lsiz) - 1), vl, mid);
      Code04_Fruit1::compute((el + lsiz), er, (mid + 1), vr);
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (p = in.nextInt());
    (q = in.nextInt());
    {
      int i = 1;
      int u = {};
      int v = {};
      for (; (i < n); (i++)) {
        (u = in.nextInt());
        (v = in.nextInt());
        Code04_Fruit1::addEdge(u, v);
        Code04_Fruit1::addEdge(v, u);
      }
    }
    Code04_Fruit1::dfs2();
    for (int i = 1; (i <= p); (i++)) {
      int a = in.nextInt();
      int b = in.nextInt();
      int c = in.nextInt();
      if ((ldfn[a] > ldfn[b])) {
        int tmp = a;
        (a = b);
        (b = tmp);
      }
      int ablca = Code04_Fruit1::lca(a, b);
      if (((ablca == a) || (ablca == b))) {
        int son = Code04_Fruit1::lcaSon(a, b);
        Code04_Fruit1::addPlate(1, ldfn[b], rdfn[b], c);
        Code04_Fruit1::delPlate(ldfn[son], ldfn[b], rdfn[b], c);
        Code04_Fruit1::addPlate(ldfn[b], (rdfn[son] + 1), n, c);
        Code04_Fruit1::delPlate((rdfn[b] + 1), (rdfn[son] + 1), n, c);
      } else {
        Code04_Fruit1::addPlate(ldfn[a], ldfn[b], rdfn[b], c);
        Code04_Fruit1::delPlate((rdfn[a] + 1), ldfn[b], rdfn[b], c);
      }
    }
    for (int i = 1; (i <= q); (i++)) {
      int u = in.nextInt();
      int v = in.nextInt();
      int k = in.nextInt();
      [&]() {
        auto jargument_0 = jmin(ldfn[u], ldfn[v]);
        auto jargument_1 = jmax(ldfn[u], ldfn[v]);
        auto jargument_2 = k;
        auto jargument_3 = i;
        return Code04_Fruit1::addFruit(jargument_0, jargument_1, jargument_2,
                                       jargument_3);
      }();
    }
    j::sort(event, 1, (cnte + 1), [=](Array<int> a, Array<int> b) {
      return ((a[1] != b[1]) ? (a[1] - b[1]) : (a[0] - b[0]));
    });
    for (int i = 1; (i <= cnte); (i++)) {
      (eid[i] = i);
    }
    Code04_Fruit1::compute(1, cnte, 0, INF);
    for (int i = 1; (i <= q); (i++)) {
      out.println(ans[i]);
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code04_Fruit1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 接水果，java版
// 一共有n个点，给定n-1条无向边，所有点连成一棵树
// 一共有p个盘子，每个盘子格式 a b c : 盘子是点a到点b的路径，盘子权值为c
// 一共有q个水果，每个水果格式 u v k : 水果是点u到点v的路径，k含义如下
// 如果一个盘子路径完全在一个水果路径的内部，那么该盘子可以接住该水果
// 那么对于每个水果，可能有很多盘子都可以将其接住，打印其中第k小的权值
// 1 <= n、p、q <= 4 * 10^4
// 0 <= 盘子权值 <= 10^9
// 内存可用空间500MB
// 测试链接 : https://www.luogu.com.cn/problem/P3242
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 链式前向星
        // 树上倍增 + 每棵子树上的ldfn和rdfn
        // 只有y维度的树状数组
        // 所有事件排完序之后，依次把下标放入eid数组
        // 每个事件有8个属性值
        // op==1加盘子，x处加、yl、yr，盘子权值v、空缺、空缺、空缺
        // op==2删盘子，x处删、yl、yr，盘子权值v、空缺、空缺、空缺
        // op==3为水果，x、空缺、空缺、空缺、y、要求k、问题编号i
        // 事件的总数
        // 整体二分
        // 每个水果的答案
        // 递归版，C++可以通过，java会爆栈
        // 不会改迭代版，去看讲解118，详解了从递归版改迭代版
        // dfs1的迭代版
        // 已知a和b的最低公共祖先一定是a或b
        // 假设祖先为x，后代为y，返回x的哪个儿子的子树里有y
        // 树状数组中[l..r]范围上的每个数增加v
        // 树状数组中查询单点的值
                // 2、3、4位空缺
                        // 这里为什么不用做撤销？
                        // 因为任何一个盘子，一定有两条扫描线
                        // 一条扫描线会增加yl..yr的计数
                        // 一条扫描线会减少yl..yr的计数
                        // 同一个盘子的两条扫描线，一定会在一起，是不可能分开的
                        // 所以此时树状数组就是清空的，不需要再做撤销操作
                        // 类型1，a和b的lca是a或b，2个区域，4个事件产生
                        // 类型2，a和b的lca不是a或b，1个区域，2个事件产生
                                // (1 ~ dfn[son]-1) (b子树上的dfn范围)
                                // (b子树上的dfn范围) (son子树上最大的dfn序号+1
~ n)
                                // (a子树上的dfn范围) (b子树上的dfn范围)
                // 根据x排序，如果x一样，加盘子排最前、删盘子其次、水果最后
        // 读写工具类
*/

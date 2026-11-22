// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P3241

// Source: src/class185/Code05_OpenStore1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code05_OpenStore1 {
  inline static int MAXN = 200001;
  inline static int MAXK = 4000001;
  inline static int n = {};
  inline static int m = {};
  inline static int A = {};
  inline static Array<int> age = make_array<int>(MAXN);
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> nxt = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> to = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> weight = make_array<int>(jshl(MAXN, 1));
  inline static int cntg = {};
  inline static Array<int> fa = make_array<int>(MAXN);
  inline static Array<int> dep = make_array<int>(MAXN);
  inline static Array<int> siz = make_array<int>(MAXN);
  inline static Array<int> son = make_array<int>(MAXN);
  inline static Array<int> top = make_array<int>(MAXN);
  inline static Array<int> dist = make_array<int>(MAXN);
  inline static Array<bool> vis = make_array<bool>(MAXN);
  inline static Array<int> centfa = make_array<int>(MAXN);
  inline static Array<int> curl = make_array<int>(MAXN);
  inline static Array<int> curr = make_array<int>(MAXN);
  inline static Array<int> curAge = make_array<int>(MAXK);
  inline static Array<i64> curSum = make_array<i64>(MAXK);
  inline static int cntc = {};
  inline static Array<int> fal = make_array<int>(MAXN);
  inline static Array<int> far = make_array<int>(MAXN);
  inline static Array<int> faAge = make_array<int>(MAXK);
  inline static Array<i64> faSum = make_array<i64>(MAXK);
  inline static int cntf = {};
  inline static Array<Array<int>> stack = make_array<int>(MAXN, 5);
  inline static int u = {};
  inline static int f = {};
  inline static int a = {};
  inline static int b = {};
  inline static int e = {};
  inline static int stacksize = {};
  inline static i64 nodeCnt = {};
  inline static i64 pathSum = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code05_OpenStore1() {}
  static void push(int u, int f, int a, int b, int e) {
    (stack[stacksize][0] = u);
    (stack[stacksize][1] = f);
    (stack[stacksize][2] = a);
    (stack[stacksize][3] = b);
    (stack[stacksize][4] = e);
    (stacksize++);
  }
  static void pop() {
    (--stacksize);
    (u = stack[stacksize][0]);
    (f = stack[stacksize][1]);
    (a = stack[stacksize][2]);
    (b = stack[stacksize][3]);
    (e = stack[stacksize][4]);
  }
  static void addEdge(int u, int v, int w) {
    (nxt[(++cntg)] = head[u]);
    (to[cntg] = v);
    (weight[cntg] = w);
    (head[u] = cntg);
  }
  static void dfs1(int u, int f, int dis) {
    (fa[u] = f);
    (dep[u] = (dep[f] + 1));
    (dist[u] = dis);
    (siz[u] = 1);
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      int v = to[e];
      int w = weight[e];
      if ((v != f)) {
        Code05_OpenStore1::dfs1(v, u, (dis + w));
      }
    }
    {
      int ei = head[u];
      int v = {};
      for (; (ei > 0); (ei = nxt[ei])) {
        (v = to[ei]);
        if ((v != f)) {
          (siz[u] += siz[v]);
          if (((son[u] == 0) || (siz[son[u]] < siz[v]))) {
            (son[u] = v);
          }
        }
      }
    }
  }
  static void dfs2(int u, int t) {
    (top[u] = t);
    if ((son[u] == 0)) {
      return;
    }
    Code05_OpenStore1::dfs2(son[u], t);
    {
      int e = head[u];
      int v = {};
      for (; (e > 0); (e = nxt[e])) {
        (v = to[e]);
        if (((v != fa[u]) && (v != son[u]))) {
          Code05_OpenStore1::dfs2(v, v);
        }
      }
    }
  }
  static void dfs3(int cur, int father, int distance) {
    (stacksize = 0);
    Code05_OpenStore1::push(cur, father, distance, 0, (-1));
    while ((stacksize > 0)) {
      Code05_OpenStore1::pop();
      if ((e == (-1))) {
        (fa[u] = f);
        (dep[u] = (dep[f] + 1));
        (dist[u] = a);
        (siz[u] = 1);
        (e = head[u]);
      } else {
        (e = nxt[e]);
      }
      if ((e != 0)) {
        Code05_OpenStore1::push(u, f, a, 0, e);
        int v = to[e];
        int w = weight[e];
        if ((v != f)) {
          Code05_OpenStore1::push(v, u, (a + w), 0, (-1));
        }
      } else {
        for (int ei = head[u]; (ei > 0); (ei = nxt[ei])) {
          int v = to[ei];
          if ((v != f)) {
            (siz[u] += siz[v]);
            if (((son[u] == 0) || (siz[son[u]] < siz[v]))) {
              (son[u] = v);
            }
          }
        }
      }
    }
  }
  static void dfs4(int cur, int tag) {
    (stacksize = 0);
    Code05_OpenStore1::push(cur, 0, 0, tag, (-1));
    while ((stacksize > 0)) {
      Code05_OpenStore1::pop();
      if ((e == (-1))) {
        (top[u] = b);
        if ((son[u] == 0)) {
          continue;
        }
        Code05_OpenStore1::push(u, 0, 0, b, (-2));
        Code05_OpenStore1::push(son[u], 0, 0, b, (-1));
        continue;
      } else if ((e == (-2))) {
        (e = head[u]);
      } else {
        (e = nxt[e]);
      }
      if ((e != 0)) {
        Code05_OpenStore1::push(u, 0, 0, b, e);
        int v = to[e];
        if (((v != fa[u]) && (v != son[u]))) {
          Code05_OpenStore1::push(v, 0, 0, v, (-1));
        }
      }
    }
  }
  static int getLca(int a, int b) {
    while ((top[a] != top[b])) {
      if ((dep[top[a]] <= dep[top[b]])) {
        (b = fa[top[b]]);
      } else {
        (a = fa[top[a]]);
      }
    }
    return ((dep[a] <= dep[b]) ? a : b);
  }
  static int getDist(int x, int y) {
    return ((dist[x] + dist[y]) -
            jshl(dist[Code05_OpenStore1::getLca(x, y)], 1));
  }
  static void getSize1(int u, int fa) {
    (siz[u] = 1);
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      int v = to[e];
      if (((v != fa) && (!vis[v]))) {
        Code05_OpenStore1::getSize1(v, u);
        (siz[u] += siz[v]);
      }
    }
  }
  static void getSize2(int cur, int fa) {
    (stacksize = 0);
    Code05_OpenStore1::push(cur, fa, 0, 0, (-1));
    while ((stacksize > 0)) {
      Code05_OpenStore1::pop();
      if ((e == (-1))) {
        (siz[u] = 1);
        (e = head[u]);
      } else {
        (e = nxt[e]);
      }
      if ((e != 0)) {
        Code05_OpenStore1::push(u, f, 0, 0, e);
        int v = to[e];
        if (((v != f) && (!vis[v]))) {
          Code05_OpenStore1::push(v, u, 0, 0, (-1));
        }
      } else {
        for (int ei = head[u]; (ei > 0); (ei = nxt[ei])) {
          int v = to[ei];
          if (((v != f) && (!vis[v]))) {
            (siz[u] += siz[v]);
          }
        }
      }
    }
  }
  static int getCentroid(int u, int fa) {
    Code05_OpenStore1::getSize2(u, fa);
    int half = jshr(siz[u], 1);
    bool find = false;
    while ((!find)) {
      (find = true);
      for (int e = head[u]; (e > 0); (e = nxt[e])) {
        int v = to[e];
        if ((((v != fa) && (!vis[v])) && (siz[v] > half))) {
          (fa = u);
          (u = v);
          (find = false);
          break;
        }
      }
    }
    return u;
  }
  static void getList1(int u, int fa, int sum, int rt) {
    (curAge[(++cntc)] = age[u]);
    (curSum[cntc] = sum);
    if ((centfa[rt] > 0)) {
      (faAge[(++cntf)] = age[u]);
      (faSum[cntf] = Code05_OpenStore1::getDist(u, centfa[rt]));
    }
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      int v = to[e];
      int w = weight[e];
      if (((v != fa) && (!vis[v]))) {
        Code05_OpenStore1::getList1(v, u, (sum + w), rt);
      }
    }
  }
  static void getList2(int cur, int father, int psum, int cen) {
    (stacksize = 0);
    Code05_OpenStore1::push(cur, father, psum, cen, (-1));
    while ((stacksize > 0)) {
      Code05_OpenStore1::pop();
      if ((e == (-1))) {
        (curAge[(++cntc)] = age[u]);
        (curSum[cntc] = a);
        if ((centfa[b] > 0)) {
          (faAge[(++cntf)] = age[u]);
          (faSum[cntf] = Code05_OpenStore1::getDist(u, centfa[b]));
        }
        (e = head[u]);
      } else {
        (e = nxt[e]);
      }
      if ((e != 0)) {
        Code05_OpenStore1::push(u, f, a, b, e);
        int v = to[e];
        int w = weight[e];
        if (((v != f) && (!vis[v]))) {
          Code05_OpenStore1::push(v, u, (a + w), b, (-1));
        }
      }
    }
  }
  static void centroidTree(int u, int fa) {
    (centfa[u] = fa);
    (vis[u] = true);
    (curl[u] = (cntc + 1));
    (fal[u] = (cntf + 1));
    Code05_OpenStore1::getList2(u, 0, 0, u);
    (curr[u] = cntc);
    (far[u] = cntf);
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      int v = to[e];
      if ((!vis[v])) {
        Code05_OpenStore1::centroidTree(Code05_OpenStore1::getCentroid(v, u),
                                        u);
      }
    }
  }
  static int kth(Array<int> arr, int l, int r, int x) {
    int ans = (r + 1);
    while ((l <= r)) {
      int mid = jshr((l + r), 1);
      if ((arr[mid] >= x)) {
        (ans = mid);
        (r = (mid - 1));
      } else {
        (l = (mid + 1));
      }
    }
    return ans;
  }
  static void sort(Array<int> age, Array<i64> sum, int l, int r) {
    if ((l >= r))
      return;
    int i = l;
    int j = r;
    int pivot = age[jshr((l + r), 1)];
    int tmp1 = {};
    i64 tmp2 = {};
    while ((i <= j)) {
      while ((age[i] < pivot))
        (i++);
      while ((age[j] > pivot))
        (j--);
      if ((i <= j)) {
        (tmp1 = age[i]);
        (age[i] = age[j]);
        (age[j] = tmp1);
        (tmp2 = sum[i]);
        (sum[i] = sum[j]);
        (sum[j] = tmp2);
        (i++);
        (j--);
      }
    }
    Code05_OpenStore1::sort(age, sum, l, j);
    Code05_OpenStore1::sort(age, sum, i, r);
  }
  static void query(Array<int> age, Array<i64> sum, int l, int r, int agel,
                    int ager) {
    (nodeCnt = (pathSum = 0));
    if ((l <= r)) {
      int a = Code05_OpenStore1::kth(age, l, r, agel);
      int b = (Code05_OpenStore1::kth(age, l, r, (ager + 1)) - 1);
      if ((a <= b)) {
        (nodeCnt = ((b - a) + 1));
        (pathSum = (sum[b] - ((a == l) ? 0 : sum[(a - 1)])));
      }
    }
  }
  static i64 compute(int x, int agel, int ager) {
    Code05_OpenStore1::query(curAge, curSum, curl[x], curr[x], agel, ager);
    i64 ans = pathSum;
    i64 cnt1 = {};
    i64 sum1 = {};
    i64 cnt2 = {};
    i64 sum2 = {};
    {
      int cur = x;
      int fa = centfa[cur];
      for (; (fa > 0); (cur = fa), (fa = centfa[cur])) {
        Code05_OpenStore1::query(curAge, curSum, curl[fa], curr[fa], agel,
                                 ager);
        (cnt1 = nodeCnt);
        (sum1 = pathSum);
        Code05_OpenStore1::query(faAge, faSum, fal[cur], far[cur], agel, ager);
        (cnt2 = nodeCnt);
        (sum2 = pathSum);
        (ans += sum1);
        (ans -= sum2);
        (ans += ((cnt1 - cnt2) * Code05_OpenStore1::getDist(x, fa)));
      }
    }
    return ans;
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (m = in.nextInt());
    (A = in.nextInt());
    for (int i = 1; (i <= n); (i++)) {
      (age[i] = in.nextInt());
    }
    {
      int i = 1;
      int u = {};
      int v = {};
      int w = {};
      for (; (i < n); (i++)) {
        (u = in.nextInt());
        (v = in.nextInt());
        (w = in.nextInt());
        Code05_OpenStore1::addEdge(u, v, w);
        Code05_OpenStore1::addEdge(v, u, w);
      }
    }
    Code05_OpenStore1::dfs3(1, 0, 0);
    Code05_OpenStore1::dfs4(1, 1);
    Code05_OpenStore1::centroidTree(Code05_OpenStore1::getCentroid(1, 0), 0);
    for (int i = 1; (i <= n); (i++)) {
      Code05_OpenStore1::sort(curAge, curSum, curl[i], curr[i]);
      for (int j = (curl[i] + 1); (j <= curr[i]); (j++)) {
        (curSum[j] += curSum[(j - 1)]);
      }
      Code05_OpenStore1::sort(faAge, faSum, fal[i], far[i]);
      for (int j = (fal[i] + 1); (j <= far[i]); (j++)) {
        (faSum[j] += faSum[(j - 1)]);
      }
    }
    i64 lastAns = 0;
    {
      int i = 1;
      int u = {};
      int l = {};
      int r = {};
      for (; (i <= m); (i++)) {
        (u = in.nextInt());
        (l = in.nextInt());
        (r = in.nextInt());
        (l = static_cast<int>(jrem((lastAns + l), A)));
        (r = static_cast<int>(jrem((lastAns + r), A)));
        if ((l > r)) {
          int tmp = l;
          (l = r);
          (r = tmp);
        }
        (lastAns = Code05_OpenStore1::compute(u, l, r));
        out.println(lastAns);
      }
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code05_OpenStore1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 开店，java版
// 一共n个人，每个人有年龄，给定n-1条路，每条路有距离，路把人连成一棵树
// 一共m条查询，格式 u l r : 查询年龄范围[l, r]的所有人，到第u号人的距离总和
// 1 <= n <= 1.5 * 10^5    1 <= m <= 2 * 10^5
// 0 <= 年龄值 <= 10^9      1 <= 距离值 <= 1000
// 本题要求强制在线，得到操作参数的规则，打开测试链接查看
// 测试链接 : https://www.luogu.com.cn/problem/P3241
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // cur列表(年龄，到当前重心距离)
        // fa列表(年龄，到上级重心距离)
        // 讲解118，递归函数改成迭代所需要的栈
                // getSize1(u, fa);
        // 递归版，java会爆栈，C++可以通过
        // 来到了一片连通区，当前重心是rt，上级重心是centfa[rt]
        // 生成两个列表，距离到当前重心的列表，距离到上级重心的列表
        // getList1的迭代版
                // getList1(u, 0, 0, u);
        // 查询x在有序数组arr中的排名
        // 每个对象两个属性(age, sum)，所有对象根据年龄排序
        // java自带的排序慢，手撸双指针快排，C++实现时可以用自带的排序
        // 下标范围[l...r]代表当前节点的列表，找到年龄范围[agel, ager]的人
        // 查到的人数设置给nodeCnt，查到的距离总和设置给pathSum
                // dfs1(1, 0, 0);
                // dfs2(1, 1);
        // 读写工具类
*/

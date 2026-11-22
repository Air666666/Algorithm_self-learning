// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/CF1320E
// https://codeforces.com/problemset/problem/1320/E

// Source: src/class180/Code05_TreelandAndViruses1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code05_TreelandAndViruses1 {
  struct Node;
  struct NodeCmp;
  struct Node {
    int id = {};
    int dist = {};
    int time = {};
    int virus = {};
    String toString() const { return j::str(static_cast<const void *>(this)); }
    Node(int id_, int dist_, int time_, int virus_) {
      (id = id_);
      (dist = dist_);
      (time = time_);
      (virus = virus_);
    }
  };
  struct NodeCmp {
    String toString() const { return j::str(static_cast<const void *>(this)); }
    NodeCmp() {}
    int compare(Node *o1, Node *o2) {
      if ((o1->time != o2->time)) {
        return (o1->time - o2->time);
      }
      return (o1->virus - o2->virus);
    }
  };
  inline static int MAXN = 200001;
  inline static int MAXP = 20;
  inline static int n = {};
  inline static int q = {};
  inline static int k = {};
  inline static int m = {};
  inline static Array<int> headg = make_array<int>(MAXN);
  inline static Array<int> nextg = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> tog = make_array<int>(jshl(MAXN, 1));
  inline static int cntg = {};
  inline static Array<int> headv = make_array<int>(MAXN);
  inline static Array<int> nextv = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> tov = make_array<int>(jshl(MAXN, 1));
  inline static int cntv = {};
  inline static Array<int> dep = make_array<int>(MAXN);
  inline static Array<int> dfn = make_array<int>(MAXN);
  inline static Array<Array<int>> stjump = make_array<int>(MAXN, MAXP);
  inline static int cntd = {};
  inline static Array<int> start = make_array<int>(MAXN);
  inline static Array<int> speed = make_array<int>(MAXN);
  inline static Array<int> query = make_array<int>(MAXN);
  inline static Array<int> arr = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> tmp = make_array<int>(jshl(MAXN, 2));
  inline static int len = {};
  inline static JHeap<Node *> heap = JHeap<Node *>(new NodeCmp());
  inline static Array<bool> vis = make_array<bool>(MAXN);
  inline static Array<int> minTime = make_array<int>(MAXN);
  inline static Array<int> findVirus = make_array<int>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code05_TreelandAndViruses1() {}
  static void addEdgeG(int u, int v) {
    (nextg[(++cntg)] = headg[u]);
    (tog[cntg] = v);
    (headg[u] = cntg);
  }
  static void addEdgeV(int u, int v) {
    (nextv[(++cntv)] = headv[u]);
    (tov[cntv] = v);
    (headv[u] = cntv);
  }
  static void sortByDfn(Array<int> nums, int l, int r) {
    if ((l >= r))
      return;
    int i = l;
    int j = r;
    int pivot = nums[jshr((l + r), 1)];
    while ((i <= j)) {
      while ((dfn[nums[i]] < dfn[pivot]))
        (i++);
      while ((dfn[nums[j]] > dfn[pivot]))
        (j--);
      if ((i <= j)) {
        int tmp = nums[i];
        (nums[i] = nums[j]);
        (nums[j] = tmp);
        (i++);
        (j--);
      }
    }
    Code05_TreelandAndViruses1::sortByDfn(nums, l, j);
    Code05_TreelandAndViruses1::sortByDfn(nums, i, r);
  }
  static void dfs(int u, int fa) {
    (dep[u] = (dep[fa] + 1));
    (dfn[u] = (++cntd));
    (stjump[u][0] = fa);
    for (int p = 1; (p < MAXP); (p++)) {
      (stjump[u][p] = stjump[stjump[u][(p - 1)]][(p - 1)]);
    }
    for (int e = headg[u]; (e > 0); (e = nextg[e])) {
      if ((tog[e] != fa)) {
        Code05_TreelandAndViruses1::dfs(tog[e], u);
      }
    }
  }
  static int getLca(int a, int b) {
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
  static int buildVirtualTree() {
    int tot = 0;
    for (int i = 1; (i <= k); (i++)) {
      (arr[(++tot)] = start[i]);
    }
    for (int i = 1; (i <= m); (i++)) {
      (arr[(++tot)] = query[i]);
    }
    Code05_TreelandAndViruses1::sortByDfn(arr, 1, tot);
    (len = 0);
    for (int i = 1; (i < tot); (i++)) {
      (tmp[(++len)] = arr[i]);
      (tmp[(++len)] = Code05_TreelandAndViruses1::getLca(arr[i], arr[(i + 1)]));
    }
    (tmp[(++len)] = arr[tot]);
    Code05_TreelandAndViruses1::sortByDfn(tmp, 1, len);
    int unique = 1;
    for (int i = 2; (i <= len); (i++)) {
      if ((tmp[unique] != tmp[i])) {
        (tmp[(++unique)] = tmp[i]);
      }
    }
    (cntv = 0);
    for (int i = 1; (i <= unique); (i++)) {
      (headv[tmp[i]] = 0);
    }
    for (int i = 1; (i < unique); (i++)) {
      int lca = Code05_TreelandAndViruses1::getLca(tmp[i], tmp[(i + 1)]);
      Code05_TreelandAndViruses1::addEdgeV(lca, tmp[(i + 1)]);
      Code05_TreelandAndViruses1::addEdgeV(tmp[(i + 1)], lca);
    }
    (len = unique);
    return tmp[1];
  }
  static void dijkstra() {
    for (int i = 1; (i <= len); (i++)) {
      int u = tmp[i];
      (minTime[u] = (n + 1));
      (findVirus[u] = (k + 1));
      (vis[u] = false);
    }
    for (int i = 1; (i <= k); (i++)) {
      int s = start[i];
      (minTime[s] = 0);
      (findVirus[s] = i);
      heap.add(new Node(s, 0, 0, i));
    }
    while ((!heap.isEmpty())) {
      Node *cur = heap.poll();
      int u = cur->id;
      int udist = cur->dist;
      int uvirus = cur->virus;
      if ((!vis[u])) {
        (vis[u] = true);
        for (int e = headv[u]; (e > 0); (e = nextv[e])) {
          int v = tov[e];
          if ((!vis[v])) {
            int vdist = (udist + std::abs((dep[u] - dep[v])));
            int vtime = jdiv(((vdist + speed[uvirus]) - 1), speed[uvirus]);
            if (((vtime < minTime[v]) ||
                 ((vtime == minTime[v]) && (uvirus < findVirus[v])))) {
              (minTime[v] = vtime);
              (findVirus[v] = uvirus);
              heap.add(new Node(v, vdist, vtime, uvirus));
            }
          }
        }
      }
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    for (int i = 1; (i < n); (i++)) {
      int x = in.nextInt();
      int y = in.nextInt();
      Code05_TreelandAndViruses1::addEdgeG(x, y);
      Code05_TreelandAndViruses1::addEdgeG(y, x);
    }
    Code05_TreelandAndViruses1::dfs(1, 0);
    (q = in.nextInt());
    for (int t = 1; (t <= q); (t++)) {
      (k = in.nextInt());
      (m = in.nextInt());
      for (int i = 1; (i <= k); (i++)) {
        (start[i] = in.nextInt());
        (speed[i] = in.nextInt());
      }
      for (int i = 1; (i <= m); (i++)) {
        (query[i] = in.nextInt());
      }
      Code05_TreelandAndViruses1::buildVirtualTree();
      Code05_TreelandAndViruses1::dijkstra();
      for (int i = 1; (i <= m); (i++)) {
        out.print((findVirus[query[i]] + String(u" ")));
      }
      out.println();
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code05_TreelandAndViruses1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 树上病毒传播，java版
//
一共有n个城市，有n-1条无向边，所有城市组成一棵树，一共有q条查询，每条查询数据如下
// 首先给定k种病毒，每种病毒有初次感染的城市start[i]，还有传播速度speed[i]
// 然后给定m个关键城市，打印每个城市被第几号病毒感染，病毒传播的规则如下
// 病毒的传播按轮次进行，每一轮病毒1先传播，然后是病毒2 ..
直到病毒k，下一轮又从病毒1开始
// 如果第i种病毒已经感染了城市x，当自己传播时，想要感染城市y的条件如下
//
城市x到城市y的路径包含的边数<=speed[i]，城市x到城市y的路径上，除了x所有城市都未被感染
//
一旦城市被某种病毒感染就永久保持，不会再被其他病毒感染，传播一直持续，直到所有城市都被感染
// 1 <= n、q、所有查询病毒总数、所有查询关键城市总数 <= 2 * 10^5
// 测试链接 : https://www.luogu.com.cn/problem/CF1320E
// 测试链接 : https://codeforces.com/problemset/problem/1320/E
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
                        // 虚树的边不是单向的，是双向的
                        // 因为病毒感染既可以向上也可以向下
        // 读写工具类
*/

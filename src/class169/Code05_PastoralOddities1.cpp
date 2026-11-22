// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/CF603E
// https://codeforces.com/problemset/problem/603/E

// Source: src/class169/Code05_PastoralOddities1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code05_PastoralOddities1 {
  inline static int MAXN = 100001;
  inline static int MAXM = 300001;
  inline static int n = {};
  inline static int m = {};
  inline static Array<Array<int>> edge = make_array<int>(MAXM, 5);
  inline static Array<Array<int>> wsort = make_array<int>(MAXM, 5);
  inline static int oddnum = {};
  inline static Array<int> father = make_array<int>(MAXN);
  inline static Array<int> siz = make_array<int>(MAXN);
  inline static Array<Array<int>> rollback = make_array<int>(MAXN, 2);
  inline static int opsize = 0;
  inline static Array<int> ans = make_array<int>(MAXM);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code05_PastoralOddities1() {}
  static int find(int i) {
    while ((i != father[i])) {
      (i = father[i]);
    }
    return i;
  }
  static bool union_method(int x, int y) {
    int fx = Code05_PastoralOddities1::find(x);
    int fy = Code05_PastoralOddities1::find(y);
    if ((fx == fy)) {
      return false;
    }
    if ((((siz[fx] & 1) == 1) && ((siz[fy] & 1) == 1))) {
      (oddnum -= 2);
    }
    if ((siz[fx] < siz[fy])) {
      int tmp = fx;
      (fx = fy);
      (fy = tmp);
    }
    (father[fy] = fx);
    (siz[fx] += siz[fy]);
    (rollback[(++opsize)][0] = fx);
    (rollback[opsize][1] = fy);
    return true;
  }
  static void undo() {
    int fx = rollback[opsize][0];
    int fy = rollback[(opsize--)][1];
    (father[fy] = fy);
    (siz[fx] -= siz[fy]);
    if ((((siz[fx] & 1) == 1) && ((siz[fy] & 1) == 1))) {
      (oddnum += 2);
    }
  }
  static void compute(int el, int er, int vl, int vr) {
    if ((el > er)) {
      return;
    }
    if ((vl == vr)) {
      for (int i = el; (i <= er); (i++)) {
        (ans[i] = vl);
      }
    } else {
      int mid = jshr((vl + vr), 1);
      int unionCnt1 = 0;
      for (int i = vl; (i <= mid); (i++)) {
        if ((wsort[i][3] < el)) {
          if (Code05_PastoralOddities1::union_method(wsort[i][0],
                                                     wsort[i][1])) {
            (unionCnt1++);
          }
        }
      }
      int unionCnt2 = 0;
      int split = (er + 1);
      for (int i = el; (i <= er); (i++)) {
        if ((edge[i][4] <= mid)) {
          if (Code05_PastoralOddities1::union_method(edge[i][0], edge[i][1])) {
            (unionCnt2++);
          }
        }
        if ((oddnum == 0)) {
          (split = i);
          break;
        }
      }
      for (int i = 1; (i <= unionCnt2); (i++)) {
        Code05_PastoralOddities1::undo();
      }
      Code05_PastoralOddities1::compute(el, (split - 1), (mid + 1), vr);
      for (int i = 1; (i <= unionCnt1); (i++)) {
        Code05_PastoralOddities1::undo();
      }
      int unionCnt3 = 0;
      for (int i = el; (i <= (split - 1)); (i++)) {
        if ((edge[i][4] < vl)) {
          if (Code05_PastoralOddities1::union_method(edge[i][0], edge[i][1])) {
            (unionCnt3++);
          }
        }
      }
      Code05_PastoralOddities1::compute(split, er, vl, mid);
      for (int i = 1; (i <= unionCnt3); (i++)) {
        Code05_PastoralOddities1::undo();
      }
    }
  }
  static void prepare() {
    (oddnum = n);
    for (int i = 1; (i <= n); (i++)) {
      (father[i] = i);
      (siz[i] = 1);
    }
    for (int i = 1; (i <= m); (i++)) {
      (wsort[i][0] = edge[i][0]);
      (wsort[i][1] = edge[i][1]);
      (wsort[i][2] = edge[i][2]);
      (wsort[i][3] = edge[i][3]);
    }
    j::sort(wsort, 1, (m + 1),
            [=](Array<int> a, Array<int> b) { return (a[2] - b[2]); });
    for (int i = 1; (i <= m); (i++)) {
      (wsort[i][4] = i);
      (edge[wsort[i][3]][4] = i);
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (m = in.nextInt());
    for (int i = 1; (i <= m); (i++)) {
      (edge[i][0] = in.nextInt());
      (edge[i][1] = in.nextInt());
      (edge[i][2] = in.nextInt());
      (edge[i][3] = i);
    }
    Code05_PastoralOddities1::prepare();
    Code05_PastoralOddities1::compute(1, m, 1, (m + 1));
    for (int i = 1; (i <= m); (i++)) {
      if ((ans[i] == (m + 1))) {
        out.println((-1));
      } else {
        out.println(wsort[ans[i]][2]);
      }
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code05_PastoralOddities1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 点的度都是奇数的最小瓶颈，java版
// 一共有n个点，初始没有边，依次加入m条无向边，每条边有边权
// 每次加入后，询问是否存在一个边集，满足每个点连接的边的数量都是奇数
// 如果存在，希望边集的最大边权，尽可能小，如果不存在打印-1
// 2 <= n <= 10^5
// 1 <= m <= 3 * 10^5
// 1 <= 边权 <= 10^9
// 测试链接 : https://www.luogu.com.cn/problem/CF603E
// 测试链接 : https://codeforces.com/problemset/problem/603/E
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // edge代表所有边依次出现
        // wsort代表所有边按边权排序
        // 每条边有：端点x、端点y、边权w、时序tim、边权排名rak
        // 可撤销并查集 + 节点数为奇数的连通区数量为oddnum
        // 依次出现的边在edge里，当前来到[el..er]范围
        // 权值排序后的边在wsort里，答案范围[vl..vr]，同时也是排名范围
        // 调用递归的前提 : el之前，边权排名<vl的边，已经加到图里了
        // 利用整体二分得到所有边的答案
                        // 1)
el之前，边权排名在[vl..mid]之间的边，加到图里，通过遍历wsort[vl..mid]来加速
                        // 2)
从el开始遍历，边权排名<=mid的边，加到图里，找到第一个达标的边split
                        // 3) 撤销2)的效果，el之前，边权排名<=mid的边，都在图中
                        // 4) 执行 compute(el, split - 1, mid + 1,
vr)，此时满足子递归的前提
                        // 5)
撤销1)的效果，此时只剩下前提了，el之前，边权排名<vl的边，都在图中
                        // 6) 从el开始到split之前，边权排名<vl的边，加到图里
                        // 7) 执行 compute(split, er, vl,
mid)，此时满足子递归的前提
                        // 8) 撤销6)的效果，回到了前提
                // edge数组、wsort数组，每条边设置排名信息
        // 读写工具类
*/

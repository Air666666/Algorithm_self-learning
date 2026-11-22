// Source: src/class154/FollowUp1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct FollowUp1 {
  inline static int MAXN = 1000001;
  inline static int n = {};
  inline static int m = {};
  inline static Array<int> num = make_array<int>(MAXN);
  inline static Array<int> up = make_array<int>(MAXN);
  inline static Array<int> ls = make_array<int>(MAXN);
  inline static Array<int> rs = make_array<int>(MAXN);
  inline static Array<int> dist = make_array<int>(MAXN);
  inline static Array<int> father = make_array<int>(MAXN);
  inline static Array<int> root = make_array<int>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  FollowUp1() {}
  static void prepare() {
    (dist[0] = (-1));
    for (int i = 1; (i <= n); (i++)) {
      (up[i] = (ls[i] = (rs[i] = (dist[i] = 0))));
      (father[i] = i);
      (root[i] = i);
    }
  }
  static int find(int i) {
    (father[i] = ((father[i] == i) ? i : FollowUp1::find(father[i])));
    return father[i];
  }
  static int merge(int i, int j) {
    if (((i == 0) || (j == 0))) {
      return (i + j);
    }
    int tmp = {};
    if (((num[i] > num[j]) || ((num[i] == num[j]) && (i > j)))) {
      (tmp = i);
      (i = j);
      (j = tmp);
    }
    (rs[i] = FollowUp1::merge(rs[i], j));
    (up[rs[i]] = i);
    if ((dist[ls[i]] < dist[rs[i]])) {
      (tmp = ls[i]);
      (ls[i] = rs[i]);
      (rs[i] = tmp);
    }
    (dist[i] = (dist[rs[i]] + 1));
    (father[ls[i]] = (father[rs[i]] = i));
    return i;
  }
  static int remove(int i) {
    int h = FollowUp1::find(i);
    (father[ls[i]] = ls[i]);
    (father[rs[i]] = rs[i]);
    int s = FollowUp1::merge(ls[i], rs[i]);
    int f = up[i];
    (father[i] = s);
    (up[s] = f);
    if ((h != i)) {
      (father[s] = h);
      if ((ls[f] == i)) {
        (ls[f] = s);
      } else {
        (rs[f] = s);
      }
      {
        int d = dist[s];
        int tmp = {};
        for (; (dist[f] > (d + 1)); (f = up[f]), (d++)) {
          (dist[f] = (d + 1));
          if ((dist[ls[f]] < dist[rs[f]])) {
            (tmp = ls[f]);
            (ls[f] = rs[f]);
            (rs[f] = tmp);
          }
        }
      }
    }
    (up[i] = (ls[i] = (rs[i] = (dist[i] = 0))));
    return father[s];
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (m = in.nextInt());
    FollowUp1::prepare();
    for (int i = 1; (i <= n); (i++)) {
      (num[i] = in.nextInt());
    }
    {
      int i = 1;
      int op = {};
      int x = {};
      int y = {};
      int z = {};
      for (; (i <= m); (i++)) {
        (op = in.nextInt());
        if ((op == 0)) {
          (x = in.nextInt());
          (y = in.nextInt());
          (root[x] = FollowUp1::remove(y));
          if ((root[x] != 0)) {
            (father[root[x]] = root[x]);
            (up[root[x]] = 0);
          }
        } else if ((op == 1)) {
          (x = in.nextInt());
          out.println(num[root[x]]);
        } else if ((op == 2)) {
          (x = in.nextInt());
          (y = in.nextInt());
          (root[x] = FollowUp1::merge(root[x], root[y]));
          if ((root[x] != 0)) {
            (father[root[x]] = root[x]);
            (up[root[x]] = 0);
          }
        } else {
          (x = in.nextInt());
          (y = in.nextInt());
          (z = in.nextInt());
          int h = FollowUp1::remove(y);
          (num[y] = z);
          (father[y] = y);
          (root[x] = FollowUp1::merge(h, y));
          if ((root[x] != 0)) {
            (father[root[x]] = root[x]);
            (up[root[x]] = 0);
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
  FollowUp1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 可并堆2，java版
// 这道题课上没有讲，一个值得实现的左偏树模版题
// 完全是课上讲过的代码，看懂课就能看懂如下实现
// 给定n个元素，编号为1到n，给定每个元素的值num[i]
// 初始时每个元素单独组成一个集合，接下来有m次操作，类型有四种，格式如下
// 操作 0 x y   : 集合x中删除元素y，题目保证y一定在集合x中
// 操作 1 x     : 查询集合x中的最小值，这是唯一需要打印的操作
// 操作 2 x y   : 集合y合并到集合x，题目保证以后不会再有以y做集合编号的操作
// 操作 3 x y z : 集合x中元素y的权值修改为z，题目保证修改操作值只可能变小
// 测试链接 : https://www.luogu.com.cn/problem/P11266
// 注意打注释位置的代码即可
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // root[x]表示集合x的堆头节点编号
                        // 初始每个集合i只有元素i
                // 小根堆
                // 值越小越优先
                // 值一样，按照编号越小越优先
                                // 删除后需要更新集合x的堆头
                                // 合并集合x和集合y
                                // y改值后重新作为单点堆
                                // 合并到集合x
        // 读写工具类
*/

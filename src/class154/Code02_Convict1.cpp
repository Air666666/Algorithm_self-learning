// Source: src/class154/Code02_Convict1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_Convict1 {
  inline static int MAXN = 2000001;
  inline static int t = {};
  inline static int w = {};
  inline static int n = {};
  inline static int m = {};
  inline static i64 k = {};
  inline static Array<i64> num = make_array<i64>(MAXN);
  inline static Array<int> up = make_array<int>(MAXN);
  inline static Array<int> left = make_array<int>(MAXN);
  inline static Array<int> right = make_array<int>(MAXN);
  inline static Array<int> dist = make_array<int>(MAXN);
  inline static Array<int> father = make_array<int>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_Convict1() {}
  static void prepare() {
    (dist[0] = (-1));
    for (int i = 1; (i <= n); (i++)) {
      (up[i] = (left[i] = (right[i] = (dist[i] = 0))));
      (father[i] = i);
    }
  }
  static int find(int i) {
    (father[i] = ((father[i] == i) ? i : Code02_Convict1::find(father[i])));
    return father[i];
  }
  static int merge(int i, int j) {
    if (((i == 0) || (j == 0))) {
      return (i + j);
    }
    int tmp = {};
    if (((num[i] < num[j]) || ((num[i] == num[j]) && (i > j)))) {
      (tmp = i);
      (i = j);
      (j = tmp);
    }
    (right[i] = Code02_Convict1::merge(right[i], j));
    (up[right[i]] = i);
    if ((dist[left[i]] < dist[right[i]])) {
      (tmp = left[i]);
      (left[i] = right[i]);
      (right[i] = tmp);
    }
    (dist[i] = (dist[right[i]] + 1));
    (father[left[i]] = (father[right[i]] = i));
    return i;
  }
  static int remove(int i) {
    int h = Code02_Convict1::find(i);
    (father[left[i]] = left[i]);
    (father[right[i]] = right[i]);
    int s = Code02_Convict1::merge(left[i], right[i]);
    int f = up[i];
    (father[i] = s);
    (up[s] = f);
    if ((h != i)) {
      (father[s] = h);
      if ((left[f] == i)) {
        (left[f] = s);
      } else {
        (right[f] = s);
      }
      {
        int d = dist[s];
        int tmp = {};
        for (; (dist[f] > (d + 1)); (f = up[f]), (d++)) {
          (dist[f] = (d + 1));
          if ((dist[left[f]] < dist[right[f]])) {
            (tmp = left[f]);
            (left[f] = right[f]);
            (right[f] = tmp);
          }
        }
      }
    }
    (up[i] = (left[i] = (right[i] = (dist[i] = 0))));
    return father[s];
  }
  static void reduce(int i, i64 v) {
    int h = Code02_Convict1::remove(i);
    (num[i] = jmax((num[i] - v), 0));
    (father[h] = (father[i] = Code02_Convict1::merge(h, i)));
  }
  static i64 compute() {
    i64 ans = 0;
    i64 max = 0;
    for (int i = 1; (i <= n); (i++)) {
      if ((father[i] == i)) {
        (ans += num[i]);
        (max = jmax(max, num[i]));
      }
    }
    if ((w == 2)) {
      (ans -= max);
    } else if ((w == 3)) {
      (ans += max);
    }
    return ans;
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(jout);
    (t = in.readInt());
    (w = in.readInt());
    (k = in.readLong());
    for (int i = 1; (i <= t); (i++)) {
      (n = in.readInt());
      (m = in.readInt());
      Code02_Convict1::prepare();
      for (int j = 1; (j <= n); (j++)) {
        (num[j] = in.readLong());
      }
      {
        int j = 1;
        int op = {};
        int a = {};
        int b = {};
        for (; (j <= m); (j++)) {
          (op = in.readInt());
          (a = in.readInt());
          if ((op == 2)) {
            Code02_Convict1::reduce(a, num[a]);
          } else if ((op == 3)) {
            (b = in.readInt());
            Code02_Convict1::reduce(Code02_Convict1::find(a), b);
          } else {
            (b = in.readInt());
            int l = Code02_Convict1::find(a);
            int r = Code02_Convict1::find(b);
            if ((l != r)) {
              Code02_Convict1::merge(l, r);
            }
          }
        }
      }
      i64 ans = Code02_Convict1::compute();
      if ((ans == 0)) {
        out.write(String(u"Gensokyo "));
      } else if ((ans > k)) {
        out.write(String(u"Hell "));
      } else {
        out.write(String(u"Heaven "));
      }
      out.println(ans);
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code02_Convict1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 断罪者，删除任意编号节点，java版
// 给定t，w，k，表示一共有t个人，死亡方式都为w，地狱阈值都为k，w和k含义稍后解释
// 每个人都给定n和m，表示这人一生有n件错事，有m次领悟
// 这个人的n件错事，给定对应的n个罪恶值，然后给定m次领悟，领悟类型如下
// 2 a   : 第a件错事的罪恶值变成0
// 3 a b : 第a件错事所在的集合中，最大罪恶值的错事，罪恶值减少b
//         如果减少后罪恶值变成负数，认为这件错事的罪恶值变为0
//         如果集合中，两件错事都是最大的罪恶值，取编号较小的错事
// 4 a b : 第a件错事所在的集合与第b件错事所在的集合合并
// 一个错事集合的罪恶值 = 这个集合中的最大罪恶值，只取一个
// 一个人的罪恶值 = 这个人所有错事集合的罪恶值累加起来
// 然后根据死亡方式w，对每个人的罪恶值做最后调整，然后打印这个人的下场
// 如果w==1，不调整
// 如果w==2，人的罪恶值 -= 错事集合的罪恶值中的最大值
// 如果w==3，人的罪恶值 += 错事集合的罪恶值中的最大值
// 如果一个人的罪恶值 == 0，打印"Gensokyo 0"
// 如果一个人的罪恶值  > k，打印"Hell "，然后打印罪恶值
// 如果一个人的罪恶值 <= k，打印"Heaven "，然后打印罪恶值
// 一共有t个人，所以最终会有t次打印
// 1 <= t <= 30
// 1 <= n <= 2 * 10^6
// 错事罪恶值可能很大，输入保证每个人的罪恶值用long类型不溢出
// 测试链接 : https://www.luogu.com.cn/problem/P4971
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // up[i]表示节点i在左偏树结构上的父亲节点
        // father[i]表示并查集里节点i的路径信息
                // 维护大根堆，如果值一样，编号小的节点做头
                // 设置up信息
        // 节点i是所在左偏树的任意节点，删除节点i，返回整棵树的头节点编号
        // 快读
        // 快写
*/

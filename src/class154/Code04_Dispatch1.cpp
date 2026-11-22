// Source: src/class154/Code04_Dispatch1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_Dispatch1 {
  inline static int MAXN = 100001;
  inline static int n = {};
  inline static int m = {};
  inline static Array<int> leader = make_array<int>(MAXN);
  inline static Array<i64> cost = make_array<i64>(MAXN);
  inline static Array<i64> ability = make_array<i64>(MAXN);
  inline static Array<int> left = make_array<int>(MAXN);
  inline static Array<int> right = make_array<int>(MAXN);
  inline static Array<int> dist = make_array<int>(MAXN);
  inline static Array<int> father = make_array<int>(MAXN);
  inline static Array<int> size = make_array<int>(MAXN);
  inline static Array<i64> sum = make_array<i64>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_Dispatch1() {}
  static void prepare() {
    (dist[0] = (-1));
    for (int i = 1; (i <= n); (i++)) {
      (left[i] = (right[i] = (dist[i] = 0)));
      (size[i] = 1);
      (sum[i] = cost[i]);
      (father[i] = i);
    }
  }
  static int find(int i) {
    (father[i] = ((father[i] == i) ? i : Code04_Dispatch1::find(father[i])));
    return father[i];
  }
  static int merge(int i, int j) {
    if (((i == 0) || (j == 0))) {
      return (i + j);
    }
    int tmp = {};
    if ((cost[i] < cost[j])) {
      (tmp = i);
      (i = j);
      (j = tmp);
    }
    (right[i] = Code04_Dispatch1::merge(right[i], j));
    if ((dist[left[i]] < dist[right[i]])) {
      (tmp = left[i]);
      (left[i] = right[i]);
      (right[i] = tmp);
    }
    (dist[i] = (dist[right[i]] + 1));
    (father[left[i]] = (father[right[i]] = i));
    return i;
  }
  static int pop(int i) {
    (father[left[i]] = left[i]);
    (father[right[i]] = right[i]);
    (father[i] = Code04_Dispatch1::merge(left[i], right[i]));
    (left[i] = (right[i] = (dist[i] = 0)));
    return father[i];
  }
  static i64 compute() {
    i64 ans = 0;
    int p = {};
    int psize = {};
    int h = {};
    int hsize = {};
    i64 hsum = {};
    i64 psum = {};
    for (int i = n; (i >= 1); (i--)) {
      (h = Code04_Dispatch1::find(i));
      (hsize = size[h]);
      (hsum = sum[h]);
      while ((hsum > m)) {
        Code04_Dispatch1::pop(h);
        (hsize--);
        (hsum -= cost[h]);
        (h = Code04_Dispatch1::find(i));
      }
      (ans = jmax(ans, (static_cast<i64>(hsize) * ability[i])));
      if ((i > 1)) {
        (p = Code04_Dispatch1::find(leader[i]));
        (psize = size[p]);
        (psum = sum[p]);
        (father[p] = (father[h] = Code04_Dispatch1::merge(p, h)));
        (size[father[p]] = (psize + hsize));
        (sum[father[p]] = (psum + hsum));
      }
    }
    return ans;
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    (n = static_cast<int>(in.nval));
    in.nextToken();
    (m = static_cast<int>(in.nval));
    for (int i = 1; (i <= n); (i++)) {
      in.nextToken();
      (leader[i] = static_cast<int>(in.nval));
      in.nextToken();
      (cost[i] = static_cast<int>(in.nval));
      in.nextToken();
      (ability[i] = static_cast<int>(in.nval));
    }
    Code04_Dispatch1::prepare();
    out.println(Code04_Dispatch1::compute());
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code04_Dispatch1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 派遣，java版
// 一共有n个忍者，每个忍者有上级编号、工资、能力，三个属性
// 输入保证，任何忍者的上级编号 < 这名忍者的编号，1号忍者是整棵忍者树的头
// 你一共有m的预算，可以在忍者树上随意选一棵子树，然后在这棵子树上挑选忍者
//
你选择某棵子树之后，不一定要选子树头的忍者，只要不超过m的预算，可以随意选择子树上的忍者
// 最终收益 = 雇佣人数 * 子树头忍者的能力，返回能取得的最大收益是多少
// 1 <= n <= 10^5           1 <= m <= 10^9
// 1 <= 每个忍者工资 <= m     1 <= 每个忍者领导力 <= 10^9
// 测试链接 : https://www.luogu.com.cn/problem/P1552
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 上级
        // 薪水
        // 能力
        // 左孩子
        // 右孩子
        // 距离
        // 寻找堆顶需要
        // 堆的大小
        // 堆的费用和
                // 维护大根堆
*/

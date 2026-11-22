// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P3377

// Source: src/class154/Code01_LeftistTree1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_LeftistTree1 {
  inline static int MAXN = 100001;
  inline static int n = {};
  inline static int m = {};
  inline static Array<int> num = make_array<int>(MAXN);
  inline static Array<int> left = make_array<int>(MAXN);
  inline static Array<int> right = make_array<int>(MAXN);
  inline static Array<int> dist = make_array<int>(MAXN);
  inline static Array<int> father = make_array<int>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_LeftistTree1() {}
  static void prepare() {
    (dist[0] = (-1));
    for (int i = 1; (i <= n); (i++)) {
      (left[i] = (right[i] = (dist[i] = 0)));
      (father[i] = i);
    }
  }
  static int find(int i) {
    (father[i] = ((father[i] == i) ? i : Code01_LeftistTree1::find(father[i])));
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
    (right[i] = Code01_LeftistTree1::merge(right[i], j));
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
    (father[i] = Code01_LeftistTree1::merge(left[i], right[i]));
    (left[i] = (right[i] = (dist[i] = 0)));
    return father[i];
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    (n = static_cast<int>(in.nval));
    in.nextToken();
    (m = static_cast<int>(in.nval));
    Code01_LeftistTree1::prepare();
    for (int i = 1; (i <= n); (i++)) {
      in.nextToken();
      (num[i] = static_cast<int>(in.nval));
    }
    {
      int i = 1;
      int op = {};
      int x = {};
      int y = {};
      for (; (i <= m); (i++)) {
        in.nextToken();
        (op = static_cast<int>(in.nval));
        if ((op == 1)) {
          in.nextToken();
          (x = static_cast<int>(in.nval));
          in.nextToken();
          (y = static_cast<int>(in.nval));
          if (((num[x] != (-1)) && (num[y] != (-1)))) {
            int l = Code01_LeftistTree1::find(x);
            int r = Code01_LeftistTree1::find(y);
            if ((l != r)) {
              Code01_LeftistTree1::merge(l, r);
            }
          }
        } else {
          in.nextToken();
          (x = static_cast<int>(in.nval));
          if ((num[x] == (-1))) {
            out.println((-1));
          } else {
            int ans = Code01_LeftistTree1::find(x);
            out.println(num[ans]);
            Code01_LeftistTree1::pop(ans);
            (num[ans] = (-1));
          }
        }
      }
    }
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code01_LeftistTree1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 左偏树模版题1，java版
// 依次给定n个非负数字，表示有n个小根堆，每个堆只有一个数
// 实现如下两种操作，操作一共调用m次
// 1 x y : 第x个数字所在的堆和第y个数字所在的堆合并
//         如果两个数字已经在一个堆或者某个数字已经删除，不进行合并
// 2 x   : 打印第x个数字所在堆的最小值，并且在堆里删掉这个最小值
//         如果第x个数字已经被删除，也就是找不到所在的堆，打印-1
//         若有多个最小值，优先删除编号小的
// 1 <= n, m <= 10^5
// 测试链接 : https://www.luogu.com.cn/problem/P3377
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 左偏树需要
        // 并查集需要father数组，方便快速找到树的头
        // father[i]不代表i在树上的父亲节点
        // father是并查集找代表节点的路径信息
        // 需要保证，并查集最上方的代表节点 = 树的头节点
        // 编号为i的左偏树 与 编号为j的左偏树合并，返回新树的头节点编号
                // 维护小根堆，如果值一样，编号小的节点做头
        // 节点i一定是左偏树的头，在左偏树上删掉节点i，返回新树的头节点编号
                // 并查集有路径压缩，所以i下方的某个节点x，可能有father[x] = i
                // 现在要删掉i了，所以x往上会找不到正确的头节点
                // 为了任何节点往上都能找到正确的头，所以要有下面这句
*/

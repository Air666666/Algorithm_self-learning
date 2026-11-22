// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P2713

// Source: src/class154/Code01_LeftistTree3.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_LeftistTree3 {
  inline static int MAXN = 1000001;
  inline static int n = {};
  inline static int m = {};
  inline static Array<int> num = make_array<int>(MAXN);
  inline static Array<int> left = make_array<int>(MAXN);
  inline static Array<int> right = make_array<int>(MAXN);
  inline static Array<int> dist = make_array<int>(MAXN);
  inline static Array<int> father = make_array<int>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_LeftistTree3() {}
  static void prepare() {
    (dist[0] = (-1));
    for (int i = 1; (i <= n); (i++)) {
      (left[i] = (right[i] = (dist[i] = 0)));
      (father[i] = i);
    }
  }
  static int find(int i) {
    (father[i] = ((father[i] == i) ? i : Code01_LeftistTree3::find(father[i])));
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
    (right[i] = Code01_LeftistTree3::merge(right[i], j));
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
    (father[i] = Code01_LeftistTree3::merge(left[i], right[i]));
    (left[i] = (right[i] = (dist[i] = 0)));
    return father[i];
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(jout);
    (n = in.readInt());
    Code01_LeftistTree3::prepare();
    for (int i = 1; (i <= n); (i++)) {
      (num[i] = in.readInt());
    }
    (m = in.readInt());
    String op = {};
    {
      int i = 1;
      int x = {};
      int y = {};
      for (; (i <= m); (i++)) {
        (op = in.readString());
        if (op.equals(String(u"M"))) {
          (x = in.readInt());
          (y = in.readInt());
          if (((num[x] != (-1)) && (num[y] != (-1)))) {
            int l = Code01_LeftistTree3::find(x);
            int r = Code01_LeftistTree3::find(y);
            if ((l != r)) {
              Code01_LeftistTree3::merge(l, r);
            }
          }
        } else {
          (x = in.readInt());
          if ((num[x] == (-1))) {
            out.println(0);
          } else {
            int ans = Code01_LeftistTree3::find(x);
            out.println(num[ans]);
            Code01_LeftistTree3::pop(ans);
            (num[ans] = (-1));
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
  Code01_LeftistTree3::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 左偏树模版题2，数据量增强，java版
// 依次给定n个非负数字，表示有n个小根堆，每个堆只有一个数
// 实现如下两种操作，操作一共调用m次
// M x y : 第x个数字所在的堆和第y个数字所在的堆合并
//         如果两个数字已经在一个堆或者某个数字已经删除，不进行合并
// K x   : 打印第x个数字所在堆的最小值，并且在堆里删掉这个最小值
//         如果第x个数字已经被删除，也就是找不到所在的堆，打印0
//         若有多个最小值，优先删除编号小的
// 1 <= n <= 10^6
// 1 <= m <= 10^5
// 测试链接 : https://www.luogu.com.cn/problem/P2713
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 快读
        // 快写
*/

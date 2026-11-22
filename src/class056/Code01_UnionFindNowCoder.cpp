// Source: src/class056/Code01_UnionFindNowCoder.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_UnionFindNowCoder {
  inline static int MAXN = 1000001;
  inline static Array<int> father = make_array<int>(MAXN);
  inline static Array<int> size = make_array<int>(MAXN);
  inline static Array<int> stack = make_array<int>(MAXN);
  inline static int n = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_UnionFindNowCoder() {}
  static void build() {
    for (int i = 0; (i <= n); (i++)) {
      (father[i] = i);
      (size[i] = 1);
    }
  }
  static int find(int i) {
    int size = 0;
    while ((i != father[i])) {
      (stack[(size++)] = i);
      (i = father[i]);
    }
    while ((size > 0)) {
      (father[stack[(--size)]] = i);
    }
    return i;
  }
  static bool isSameSet(int x, int y) {
    return [&]() {
      auto jleft = Code01_UnionFindNowCoder::find(x);
      auto jright = Code01_UnionFindNowCoder::find(y);
      return (jleft == jright);
    }();
  }
  static void union_method(int x, int y) {
    int fx = Code01_UnionFindNowCoder::find(x);
    int fy = Code01_UnionFindNowCoder::find(y);
    if ((fx != fy)) {
      if ((size[fx] >= size[fy])) {
        (size[fx] += size[fy]);
        (father[fy] = fx);
      } else {
        (size[fy] += size[fx]);
        (father[fx] = fy);
      }
    }
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    while ((in.nextToken() != -1)) {
      (n = static_cast<int>(in.nval));
      Code01_UnionFindNowCoder::build();
      in.nextToken();
      int m = static_cast<int>(in.nval);
      for (int i = 0; (i < m); (i++)) {
        in.nextToken();
        int op = static_cast<int>(in.nval);
        in.nextToken();
        int x = static_cast<int>(in.nval);
        in.nextToken();
        int y = static_cast<int>(in.nval);
        if ((op == 1)) {
          out.println((Code01_UnionFindNowCoder::isSameSet(x, y)
                           ? String(u"Yes")
                           : String(u"No")));
        } else {
          Code01_UnionFindNowCoder::union_method(x, y);
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
  Code01_UnionFindNowCoder::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 并查集模版(牛客)
// 路径压缩 + 小挂大
// 测试链接 : https://www.nowcoder.com/practice/e7ed657974934a30b2010046536a5372
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下的code，提交时请把类名改成"Main"，可以直接通过
        // i号节点，往上一直找，找到代表节点返回！
                // 沿途收集了几个点
                // 沿途节点收集好了，i已经跳到代表节点了
                        // fx是集合的代表：拿大小
                        // fy是集合的代表：拿大小
*/

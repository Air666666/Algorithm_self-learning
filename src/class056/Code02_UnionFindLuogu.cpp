// Source: src/class056/Code02_UnionFindLuogu.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_UnionFindLuogu {
  inline static int MAXN = 200001;
  inline static Array<int> father = make_array<int>(MAXN);
  inline static int n = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_UnionFindLuogu() {}
  static void build() {
    for (int i = 0; (i <= n); (i++)) {
      (father[i] = i);
    }
  }
  static int find(int i) {
    if ((i != father[i])) {
      (father[i] = Code02_UnionFindLuogu::find(father[i]));
    }
    return father[i];
  }
  static bool isSameSet(int x, int y) {
    return [&]() {
      auto jleft = Code02_UnionFindLuogu::find(x);
      auto jright = Code02_UnionFindLuogu::find(y);
      return (jleft == jright);
    }();
  }
  static void union_method(int x, int y) {
    (father[Code02_UnionFindLuogu::find(x)] = Code02_UnionFindLuogu::find(y));
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    while ((in.nextToken() != -1)) {
      (n = static_cast<int>(in.nval));
      Code02_UnionFindLuogu::build();
      in.nextToken();
      int m = static_cast<int>(in.nval);
      for (int i = 0; (i < m); (i++)) {
        in.nextToken();
        int z = static_cast<int>(in.nval);
        in.nextToken();
        int x = static_cast<int>(in.nval);
        in.nextToken();
        int y = static_cast<int>(in.nval);
        if ((z == 1)) {
          Code02_UnionFindLuogu::union_method(x, y);
        } else {
          out.println((Code02_UnionFindLuogu::isSameSet(x, y) ? String(u"Y")
                                                              : String(u"N")));
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
  Code02_UnionFindLuogu::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 并查集模版(洛谷)
// 本实现用递归函数实现路径压缩，而且省掉了小挂大的优化，一般情况下可以省略
// 测试链接 : https://www.luogu.com.cn/problem/P3367
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下的code，提交时请把类名改成"Main"，可以直接通过
*/

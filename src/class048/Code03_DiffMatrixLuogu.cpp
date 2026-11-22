// Source: src/class048/Code03_DiffMatrixLuogu.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_DiffMatrixLuogu {
  inline static int MAXN = 1002;
  inline static Array<Array<int>> diff = make_array<int>(MAXN, MAXN);
  inline static int n = {};
  inline static int q = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_DiffMatrixLuogu() {}
  static void add(int a, int b, int c, int d, int k) {
    (diff[a][b] += k);
    (diff[(c + 1)][b] -= k);
    (diff[a][(d + 1)] -= k);
    (diff[(c + 1)][(d + 1)] += k);
  }
  static void build() {
    for (int i = 1; (i <= n); (i++)) {
      for (int j = 1; (j <= n); (j++)) {
        (diff[i][j] +=
         ((diff[(i - 1)][j] + diff[i][(j - 1)]) - diff[(i - 1)][(j - 1)]));
      }
    }
  }
  static void clear() {
    for (int i = 1; (i <= (n + 1)); (i++)) {
      for (int j = 1; (j <= (n + 1)); (j++)) {
        (diff[i][j] = 0);
      }
    }
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    while ((in.nextToken() != -1)) {
      (n = static_cast<int>(in.nval));
      in.nextToken();
      (q = static_cast<int>(in.nval));
      {
        int i = 1;
        int a = {};
        int b = {};
        int c = {};
        int d = {};
        for (; (i <= q); (i++)) {
          in.nextToken();
          (a = static_cast<int>(in.nval));
          in.nextToken();
          (b = static_cast<int>(in.nval));
          in.nextToken();
          (c = static_cast<int>(in.nval));
          in.nextToken();
          (d = static_cast<int>(in.nval));
          Code03_DiffMatrixLuogu::add(a, b, c, d, 1);
        }
      }
      Code03_DiffMatrixLuogu::build();
      for (int i = 1; (i <= n); (i++)) {
        out.print(diff[i][1]);
        for (int j = 2; (j <= n); (j++)) {
          out.print((String(u" ") + diff[i][j]));
        }
        out.println();
      }
      Code03_DiffMatrixLuogu::clear();
    }
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code03_DiffMatrixLuogu::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 二维差分模版(洛谷)
// 测试链接 : https://www.luogu.com.cn/problem/P3397
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下的code，提交时请把类名改成"Main"，可以直接通过
*/

// 原题测试 / 参考链接（保留上游原始地址）
// https://www.nowcoder.com/practice/50e1a93989df42efb0b1dec386fb4ccc

// Source: src/class048/Code03_DiffMatrixNowcoder.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_DiffMatrixNowcoder {
  inline static int MAXN = 1005;
  inline static int MAXM = 1005;
  inline static Array<Array<i64>> diff = make_array<i64>(MAXN, MAXM);
  inline static int n = {};
  inline static int m = {};
  inline static int q = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_DiffMatrixNowcoder() {}
  static void add(int a, int b, int c, int d, int k) {
    (diff[a][b] += k);
    (diff[(c + 1)][b] -= k);
    (diff[a][(d + 1)] -= k);
    (diff[(c + 1)][(d + 1)] += k);
  }
  static void build() {
    for (int i = 1; (i <= n); (i++)) {
      for (int j = 1; (j <= m); (j++)) {
        (diff[i][j] +=
         ((diff[(i - 1)][j] + diff[i][(j - 1)]) - diff[(i - 1)][(j - 1)]));
      }
    }
  }
  static void clear() {
    for (int i = 1; (i <= (n + 1)); (i++)) {
      for (int j = 1; (j <= (m + 1)); (j++)) {
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
      (m = static_cast<int>(in.nval));
      in.nextToken();
      (q = static_cast<int>(in.nval));
      for (int i = 1; (i <= n); (i++)) {
        for (int j = 1; (j <= m); (j++)) {
          in.nextToken();
          Code03_DiffMatrixNowcoder::add(i, j, i, j, static_cast<int>(in.nval));
        }
      }
      {
        int i = 1;
        int a = {};
        int b = {};
        int c = {};
        int d = {};
        int k = {};
        for (; (i <= q); (i++)) {
          in.nextToken();
          (a = static_cast<int>(in.nval));
          in.nextToken();
          (b = static_cast<int>(in.nval));
          in.nextToken();
          (c = static_cast<int>(in.nval));
          in.nextToken();
          (d = static_cast<int>(in.nval));
          in.nextToken();
          (k = static_cast<int>(in.nval));
          Code03_DiffMatrixNowcoder::add(a, b, c, d, k);
        }
      }
      Code03_DiffMatrixNowcoder::build();
      for (int i = 1; (i <= n); (i++)) {
        out.print(diff[i][1]);
        for (int j = 2; (j <= m); (j++)) {
          out.print((String(u" ") + diff[i][j]));
        }
        out.println();
      }
      Code03_DiffMatrixNowcoder::clear();
    }
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code03_DiffMatrixNowcoder::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 二维差分模版(牛客)
// 测试链接 : https://www.nowcoder.com/practice/50e1a93989df42efb0b1dec386fb4ccc
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下的code，提交时请把类名改成"Main"，可以直接通过
*/

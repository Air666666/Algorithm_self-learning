// Source: src/class159/Code06_XorOperation1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code06_XorOperation1 {
  inline static int MAXN = 300001;
  inline static int MAXT = (MAXN * 32);
  inline static int BIT = 30;
  inline static int n = {};
  inline static int m = {};
  inline static int p = {};
  inline static Array<int> x = make_array<int>(MAXN);
  inline static Array<int> root = make_array<int>(MAXN);
  inline static Array<Array<int>> tree = make_array<int>(MAXT, 2);
  inline static Array<int> pass = make_array<int>(MAXT);
  inline static int cnt = 0;
  inline static Array<Array<int>> xroad = make_array<int>(MAXN, 2);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code06_XorOperation1() {}
  static int insert(int num, int i) {
    int rt = (++cnt);
    (tree[rt][0] = tree[i][0]);
    (tree[rt][1] = tree[i][1]);
    (pass[rt] = (pass[i] + 1));
    {
      int b = BIT;
      int path = {};
      int pre = rt;
      int cur = {};
      for (; (b >= 0); (b--), (pre = cur)) {
        (path = (jshr(num, b) & 1));
        (i = tree[i][path]);
        (cur = (++cnt));
        (tree[cur][0] = tree[i][0]);
        (tree[cur][1] = tree[i][1]);
        (pass[cur] = (pass[i] + 1));
        (tree[pre][path] = cur);
      }
    }
    return rt;
  }
  static int maxKth(int xl, int xr, int yl, int yr, int k) {
    for (int i = xl; (i <= xr); (i++)) {
      (xroad[i][0] = root[(yl - 1)]);
      (xroad[i][1] = root[yr]);
    }
    int ans = 0;
    {
      int b = BIT;
      int path = {};
      int best = {};
      int sum = {};
      for (; (b >= 0); (b--)) {
        (sum = 0);
        for (int i = xl; (i <= xr); (i++)) {
          (path = (jshr(x[i], b) & 1));
          (best = (path ^ 1));
          (sum +=
           (pass[tree[xroad[i][1]][best]] - pass[tree[xroad[i][0]][best]]));
        }
        for (int i = xl; (i <= xr); (i++)) {
          (path = (jshr(x[i], b) & 1));
          (best = (path ^ 1));
          if ((sum >= k)) {
            (xroad[i][0] = tree[xroad[i][0]][best]);
            (xroad[i][1] = tree[xroad[i][1]][best]);
          } else {
            (xroad[i][0] = tree[xroad[i][0]][path]);
            (xroad[i][1] = tree[xroad[i][1]][path]);
          }
        }
        if ((sum >= k)) {
          (ans += jshl(1, b));
        } else {
          (k -= sum);
        }
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
      (x[i] = static_cast<int>(in.nval));
    }
    {
      int i = 1;
      int yi = {};
      for (; (i <= m); (i++)) {
        in.nextToken();
        (yi = static_cast<int>(in.nval));
        (root[i] = Code06_XorOperation1::insert(yi, root[(i - 1)]));
      }
    }
    in.nextToken();
    (p = static_cast<int>(in.nval));
    {
      int i = 1;
      int xl = {};
      int xr = {};
      int yl = {};
      int yr = {};
      int k = {};
      for (; (i <= p); (i++)) {
        in.nextToken();
        (xl = static_cast<int>(in.nval));
        in.nextToken();
        (xr = static_cast<int>(in.nval));
        in.nextToken();
        (yl = static_cast<int>(in.nval));
        in.nextToken();
        (yr = static_cast<int>(in.nval));
        in.nextToken();
        (k = static_cast<int>(in.nval));
        out.println(Code06_XorOperation1::maxKth(xl, xr, yl, yr, k));
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
  Code06_XorOperation1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 异或运算，java版
// 给定一个长度n的数组x，还有一个长度为m的数组y
// 想象一个二维矩阵mat，数组x作为行，数组y作为列，mat[i][j] = x[i] ^ y[j]
// 一共有p条查询，每条查询格式如下
// xl xr yl yr k : 划定mat的范围是，行从xl~xr，列从yl~yr，打印其中第k大的值
// 1 <= n <= 1000
// 1 <= m <= 3 * 10^5
// 1 <= p <= 500
// 0 <= x[i]、y[i] < 2^31
// 测试链接 : https://www.luogu.com.cn/problem/P5795
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
                //
基于哪两个节点的pass值查询，一开始x[xl...xr]每个数字，都是一样的
                        // 统计x[xl...xr]范围上
                        // 每个数字 ^
y[yl...yr]任意一个数字，在第b位上能取得1的结果，有多少个
                        // 结果数量累加起来
                        // 如果sum >= k
                        //
说明x[xl...xr]对应y[yl...yr]，第k大的异或结果，在第b位上能是1
                        // 如果sum < k
                        //
说明x[xl...xr]对应y[yl...yr]，第k大的异或结果，在第b位上只能是0
                        // x[xl...xr]每个数字，都有自己专属的跳转，要记录好！
*/

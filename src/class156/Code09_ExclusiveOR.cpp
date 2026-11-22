// 原题测试 / 参考链接（保留上游原始地址）
// https://acm.hdu.edu.cn/showproblem.php?pid=3234
// https://www.luogu.com.cn/problem/UVA12232
// https://vjudge.net/problem/UVA-12232

// Source: src/class156/Code09_ExclusiveOR.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code09_ExclusiveOR {
  inline static int MAXN = 20002;
  inline static int MAXK = 21;
  inline static int t = {};
  inline static int n = {};
  inline static int m = {};
  inline static bool conflict = {};
  inline static int cnti = {};
  inline static Array<int> father = make_array<int>(MAXN);
  inline static Array<int> exclu = make_array<int>(MAXN);
  inline static Array<int> nums = make_array<int>(MAXK);
  inline static Array<int> fas = make_array<int>(MAXK);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code09_ExclusiveOR() {}
  static void prepare() {
    (conflict = false);
    (cnti = 0);
    for (int i = 0; (i <= n); (i++)) {
      (father[i] = i);
      (exclu[i] = 0);
    }
  }
  static int find(int i) {
    if ((i != father[i])) {
      int tmp = father[i];
      (father[i] = Code09_ExclusiveOR::find(tmp));
      (exclu[i] ^= exclu[tmp]);
    }
    return father[i];
  }
  static bool opi(int l, int r, int v) {
    (cnti++);
    int lf = Code09_ExclusiveOR::find(l);
    int rf = Code09_ExclusiveOR::find(r);
    if ((lf == rf)) {
      if (((exclu[l] ^ exclu[r]) != v)) {
        (conflict = true);
        return false;
      }
    } else {
      if ((lf == n)) {
        (lf = rf);
        (rf = n);
      }
      (father[lf] = rf);
      (exclu[lf] = ((exclu[r] ^ exclu[l]) ^ v));
    }
    return true;
  }
  static int opq(int k) {
    int ans = 0;
    {
      int i = 1;
      int fa = {};
      for (; (i <= k); (i++)) {
        (fa = Code09_ExclusiveOR::find(nums[i]));
        (ans ^= exclu[nums[i]]);
        (fas[i] = fa);
      }
    }
    j::sort(fas, 1, (k + 1));
    {
      int l = 1;
      int r = 1;
      for (; (l <= k); (l = (++r))) {
        while ((((r + 1) <= k) && (fas[(r + 1)] == fas[l]))) {
          (r++);
        }
        if (((jrem(((r - l) + 1), 2) != 0) && (fas[l] != n))) {
          return (-1);
        }
      }
    }
    return ans;
  }
  static void java_main(Array<String> args) {
    IO in = IO();
    IO out = IO(IO(jout));
    (t = 0);
    (n = in.nextInt());
    (m = in.nextInt());
    while (((n != 0) || (m != 0))) {
      Code09_ExclusiveOR::prepare();
      out.println(((String(u"Case ") + (++t)) + String(u":")));
      for (int i = 1; (i <= m); (i++)) {
        String op = in.next();
        if (op.equals(String(u"I"))) {
          int l = {};
          int r = {};
          int v = {};
          in.numbers();
          if ((!conflict)) {
            if ((in.size == 2)) {
              (l = in.a);
              (r = n);
              (v = in.b);
            } else {
              (l = in.a);
              (r = in.b);
              (v = in.c);
            }
            if ((!Code09_ExclusiveOR::opi(l, r, v))) {
              out.println(((String(u"The first ") + cnti) +
                           String(u" facts are conflicting.")));
            }
          }
        } else {
          int k = in.nextInt();
          for (int j = 1; (j <= k); (j++)) {
            (nums[j] = in.nextInt());
          }
          if ((!conflict)) {
            int ans = Code09_ExclusiveOR::opq(k);
            if ((ans == (-1))) {
              out.println(String(u"I don't know."));
            } else {
              out.println(ans);
            }
          }
        }
      }
      out.println();
      (n = in.nextInt());
      (m = in.nextInt());
    }
    out.flush();
    out.close();
    in.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code09_ExclusiveOR::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 异或关系
// 一共n个数，编号0 ~ n-1，实现如下三种类型的操作，一共调用m次
// I x v        : 声明 第x个数 = v
// I x y v      : 声明 第x个数 ^ 第y个数 = v
// Q k a1 .. ak : 查询 一共k个数，编号为a1 .. ak，这些数字异或起来的值是多少
// 对每个Q的操作打印答案，如果根据之前的声明无法推出答案，打印"I don't know."
// 如果处理到第s条声明，发现了矛盾，打印"The first s facts are conflicting."
// 注意只有声明操作出现，s才会增加，查询操作不占用声明操作的计数
// 发现矛盾之后，所有的操作都不再处理，更多的细节可以打开测试链接查看题目
// 1 <= n <= 20000    1 <= m <= 40000    1 <= k <= 15
// 测试链接 : https://acm.hdu.edu.cn/showproblem.php?pid=3234
// 测试链接 : https://www.luogu.com.cn/problem/UVA12232
// 测试链接 : https://vjudge.net/problem/UVA-12232
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 读写工具类
*/

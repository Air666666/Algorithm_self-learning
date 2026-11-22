// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P4735

// Source: src/class159/Code01_MaxXor1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_MaxXor1 {
  inline static int MAXN = 600001;
  inline static int MAXT = (MAXN * 22);
  inline static int BIT = 25;
  inline static int n = {};
  inline static int m = {};
  inline static int eor = {};
  inline static Array<int> root = make_array<int>(MAXN);
  inline static Array<Array<int>> tree = make_array<int>(MAXT, 2);
  inline static Array<int> pass = make_array<int>(MAXT);
  inline static int cnt = 0;
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_MaxXor1() {}
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
  static int query(int num, int u, int v) {
    int ans = 0;
    {
      int b = BIT;
      int path = {};
      int best = {};
      for (; (b >= 0); (b--)) {
        (path = (jshr(num, b) & 1));
        (best = (path ^ 1));
        if ((pass[tree[v][best]] > pass[tree[u][best]])) {
          (ans += jshl(1, b));
          (u = tree[u][best]);
          (v = tree[v][best]);
        } else {
          (u = tree[u][path]);
          (v = tree[v][path]);
        }
      }
    }
    return ans;
  }
  static void java_main(Array<String> args) {
    IO in = IO();
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (m = in.nextInt());
    (eor = 0);
    (root[0] = Code01_MaxXor1::insert(eor, 0));
    {
      int i = 1;
      int num = {};
      for (; (i <= n); (i++)) {
        (num = in.nextInt());
        (eor ^= num);
        (root[i] = Code01_MaxXor1::insert(eor, root[(i - 1)]));
      }
    }
    String op = {};
    int x = {};
    int y = {};
    int z = {};
    for (int i = 1; (i <= m); (i++)) {
      (op = in.next());
      if (op.equals(String(u"A"))) {
        (x = in.nextInt());
        (eor ^= x);
        (n++);
        (root[n] = Code01_MaxXor1::insert(eor, root[(n - 1)]));
      } else {
        (x = in.nextInt());
        (y = in.nextInt());
        (z = in.nextInt());
        if ((x == 1)) {
          out.println(Code01_MaxXor1::query((eor ^ z), 0, root[(y - 1)]));
        } else {
          out.println(
              Code01_MaxXor1::query((eor ^ z), root[(x - 2)], root[(y - 1)]));
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
  Code01_MaxXor1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 最大异或和，java版
// 非负序列arr的初始长度为n，一共有m条操作，每条操作是如下两种类型中的一种
// A x     : arr的末尾增加数字x，arr的长度n也增加1
// Q l r x : l~r这些位置中，选一个位置p，现在希望
//           arr[p] ^ arr[p+1] ^ .. ^ arr[n] ^ x 这个值最大
//           打印这个最大值
// 1 <= n、m <= 3 * 10^5
// 0 <= arr[i]、x <= 10^7
// 因为练的就是可持久化前缀树，所以就用在线算法，不要使用离线算法
// 测试链接 : https://www.luogu.com.cn/problem/P4735
// 提交以下的code，提交时请把类名改成"Main"
// java实现的逻辑一定是正确的，但是有一些测试用例通过不了
// 因为这道题根据C++的运行时间，制定通过标准，根本没考虑java的用户
// 想通过用C++实现，本节课Code01_MaxXor2文件就是C++的实现
// 两个版本的逻辑完全一样，C++版本可以通过所有测试
                // 其实有空版本，空版本的头节点编号是0
        // 读写工具类
*/

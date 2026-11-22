// Source: src/class159/Code05_ALO1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code05_ALO1 {
  inline static int MAXN = 50002;
  inline static int MAXT = (MAXN * 32);
  inline static int BIT = 30;
  inline static int n = {};
  inline static Array<Array<int>> arr = make_array<int>(MAXN, 2);
  inline static Array<int> root = make_array<int>(MAXN);
  inline static Array<Array<int>> tree = make_array<int>(MAXT, 2);
  inline static Array<int> pass = make_array<int>(MAXT);
  inline static int cnt = {};
  inline static Array<int> last = make_array<int>(MAXN);
  inline static Array<int> next = make_array<int>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code05_ALO1() {}
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
  static void prepare() {
    (last[0] = 0);
    (next[0] = 1);
    (last[(n + 1)] = n);
    (next[(n + 1)] = (n + 1));
    for (int i = 1; (i <= n); (i++)) {
      (root[i] = Code05_ALO1::insert(arr[i][1], root[(i - 1)]));
      (last[i] = (i - 1));
      (next[i] = (i + 1));
    }
    j::sort(arr, 1, (n + 1),
            [=](Array<int> a, Array<int> b) { return (a[1] - b[1]); });
  }
  static int compute() {
    int ans = 0;
    {
      int i = 1;
      int index = {};
      int value = {};
      int l1 = {};
      int l2 = {};
      int r1 = {};
      int r2 = {};
      for (; (i <= n); (i++)) {
        (index = arr[i][0]);
        (value = arr[i][1]);
        (l1 = last[index]);
        (l2 = last[l1]);
        (r1 = next[index]);
        (r2 = next[r1]);
        if ((l1 != 0)) {
          (ans =
               jmax(ans, Code05_ALO1::query(value, root[l2], root[(r1 - 1)])));
        }
        if ((r1 != (n + 1))) {
          (ans =
               jmax(ans, Code05_ALO1::query(value, root[l1], root[(r2 - 1)])));
        }
        (next[l1] = r1);
        (last[r1] = l1);
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
    for (int i = 1; (i <= n); (i++)) {
      (arr[i][0] = i);
      in.nextToken();
      (arr[i][1] = static_cast<int>(in.nval));
    }
    Code05_ALO1::prepare();
    out.println(Code05_ALO1::compute());
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code05_ALO1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 生成能量密度最大的宝石，java版
// 给定一个长度为n的数组arr，数组中没有重复数字
// 你可以随意选择一个子数组，长度要求大于等于2，因为这样一来，子数组必存在次大值
// 子数组的次大值 ^ 子数组中除了次大值之外随意选一个数字
// 所能得到的最大结果，叫做子数组的能量密度
// 那么必有某个子数组，拥有最大的能量密度，打印这个最大的能量密度
// 2 <= n <= 5 * 10^4
// 0 <= arr[i] <= 10^9
// 测试链接 : https://www.luogu.com.cn/problem/P4098
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
*/

// Source: src/class159/Code07_Friends1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code07_Friends1 {
  inline static int MAXN = 50001;
  inline static int MAXT = (MAXN * 20);
  inline static int BIT = 30;
  inline static int MOD = 1000000007;
  inline static int INV2 = 500000004;
  inline static int n = {};
  inline static int k = {};
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static Array<Array<int>> tree = make_array<int>(MAXT, 2);
  inline static Array<int> pass = make_array<int>(MAXT);
  inline static int cnt = 1;
  inline static Array<Array<int>> sum = make_array<int>(MAXT, (BIT + 1));
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code07_Friends1() {}
  static void insert(int num) {
    int cur = 1;
    (pass[1]++);
    {
      int b = BIT;
      int path = {};
      for (; (b >= 0); (b--)) {
        (path = (jshr(num, b) & 1));
        if ((tree[cur][path] == 0)) {
          (tree[cur][path] = (++cnt));
        }
        (cur = tree[cur][path]);
        (pass[cur]++);
      }
    }
  }
  static void dfs(int i, int h, int s) {
    if ((i == 0)) {
      return;
    }
    if ((h == 0)) {
      for (int j = 0; (j <= BIT); (j++)) {
        if (((jshr(s, j) & 1) == 1)) {
          (sum[i][j] = pass[i]);
        }
      }
    } else {
      Code07_Friends1::dfs(tree[i][0], (h - 1), s);
      Code07_Friends1::dfs(tree[i][1], (h - 1), (s | jshl(1, (h - 1))));
      for (int j = 0; (j <= BIT); (j++)) {
        (sum[i][j] = (sum[tree[i][0]][j] + sum[tree[i][1]][j]));
      }
    }
  }
  static i64 moreEqual(int x) {
    i64 ans = 0;
    {
      int i = 1;
      int num = {};
      int cur = {};
      for (; (i <= n); (i++)) {
        (num = arr[i]);
        (cur = 1);
        {
          int b = BIT;
          int path = {};
          int best = {};
          int xpath = {};
          for (; (b >= 0); (b--)) {
            (path = (jshr(num, b) & 1));
            (best = (path ^ 1));
            (xpath = (jshr(x, b) & 1));
            if ((xpath == 0)) {
              (ans += pass[tree[cur][best]]);
              (cur = tree[cur][path]);
            } else {
              (cur = tree[cur][best]);
            }
            if ((cur == 0)) {
              break;
            }
          }
        }
        (ans += pass[cur]);
      }
    }
    if ((x == 0)) {
      (ans -= n);
    }
    return jdiv(ans, 2);
  }
  static int maxKth() {
    int l = 0;
    int r = jshl(1, BIT);
    int m = {};
    int ans = 0;
    while ((l <= r)) {
      (m = jdiv((l + r), 2));
      if ((Code07_Friends1::moreEqual(m) >= k)) {
        (ans = m);
        (l = (m + 1));
      } else {
        (r = (m - 1));
      }
    }
    return ans;
  }
  static i64 compute() {
    int kth = Code07_Friends1::maxKth();
    i64 ans = 0;
    {
      int i = 1;
      int cur = {};
      for (; (i <= n); (i++)) {
        (cur = 1);
        {
          int b = BIT;
          int path = {};
          int best = {};
          int kpath = {};
          for (; (b >= 0); (b--)) {
            (path = (jshr(arr[i], b) & 1));
            (best = (path ^ 1));
            (kpath = (jshr(kth, b) & 1));
            if ((kpath == 0)) {
              for (int j = 0; (j <= BIT); (j++)) {
                if (((jshr(arr[i], j) & 1) == 1)) {
                  (ans = jrem((ans + ((static_cast<i64>(pass[tree[cur][best]]) -
                                       sum[tree[cur][best]][j]) *
                                      jshl(1LL, j))),
                              MOD));
                } else {
                  (ans =
                       jrem((ans + (static_cast<i64>(sum[tree[cur][best]][j]) *
                                    jshl(1LL, j))),
                            MOD));
                }
              }
              (cur = tree[cur][path]);
            } else {
              (cur = tree[cur][best]);
            }
            if ((cur == 0)) {
              break;
            }
          }
        }
        (ans = jrem((ans + (static_cast<i64>(pass[cur]) * kth)), MOD));
      }
    }
    (ans = jrem((ans * INV2), MOD));
    (ans = jrem(
         (jrem((ans - jrem(((Code07_Friends1::moreEqual(kth) - k) * kth), MOD)),
               MOD) +
          MOD),
         MOD));
    return ans;
  }
  static void prepare() {
    for (int i = 1; (i <= n); (i++)) {
      Code07_Friends1::insert(arr[i]);
    }
    Code07_Friends1::dfs(tree[1][0], BIT, 0);
    Code07_Friends1::dfs(tree[1][1], BIT, jshl(1, BIT));
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    (n = static_cast<int>(in.nval));
    in.nextToken();
    (k = static_cast<int>(in.nval));
    for (int i = 1; (i <= n); (i++)) {
      in.nextToken();
      (arr[i] = static_cast<int>(in.nval));
    }
    if ((k == 0)) {
      out.println(0);
    } else {
      Code07_Friends1::prepare();
      out.println(Code07_Friends1::compute());
    }
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code07_Friends1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 前m大两两异或值的和，java版
// 本题只用到了经典前缀树，没有用到可持久化前缀树
// 给定一个长度为n的数组arr，下标1~n
//
你可以随意选两个不同位置的数字进行异或，得到两两异或值，顺序不同的话，算做一个两两异或值
// 那么，两两异或值，就有第1大、第2大...
// 返回前k大两两异或值的累加和，答案对1000000007取模
// 1 <= n <= 5 * 10^4
// 0 <= k <= n * (n-1) / 2
// 0 <= arr[i] <= 10^9
// 测试链接 : https://www.luogu.com.cn/problem/CF241B
// 测试链接 : https://codeforces.com/problemset/problem/241/B
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
*/

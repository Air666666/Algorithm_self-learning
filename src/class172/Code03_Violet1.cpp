// Source: src/class172/Code03_Violet1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_Violet1 {
  inline static int MAXN = 40001;
  inline static int MAXB = 201;
  inline static int n = {};
  inline static int m = {};
  inline static int s = {};
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static Array<int> sortv = make_array<int>(MAXN);
  inline static int blen = {};
  inline static int bnum = {};
  inline static Array<int> bi = make_array<int>(MAXN);
  inline static Array<int> bl = make_array<int>(MAXB);
  inline static Array<int> br = make_array<int>(MAXB);
  inline static Array<Array<int>> freq = make_array<int>(MAXB, MAXN);
  inline static Array<Array<int>> mode = make_array<int>(MAXB, MAXB);
  inline static Array<int> numCnt = make_array<int>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_Violet1() {}
  static int lower(int num) {
    int l = 1;
    int r = s;
    int m = {};
    int ans = 0;
    while ((l <= r)) {
      (m = jshr((l + r), 1));
      if ((sortv[m] >= num)) {
        (ans = m);
        (r = (m - 1));
      } else {
        (l = (m + 1));
      }
    }
    return ans;
  }
  static int getCnt(int l, int r, int v) {
    return (freq[r][v] - freq[(l - 1)][v]);
  }
  static void prepare() {
    (blen = static_cast<int>(std::sqrt(n)));
    (bnum = jdiv(((n + blen) - 1), blen));
    for (int i = 1; (i <= n); (i++)) {
      (bi[i] = (jdiv((i - 1), blen) + 1));
    }
    for (int i = 1; (i <= bnum); (i++)) {
      (bl[i] = (((i - 1) * blen) + 1));
      (br[i] = jmin((i * blen), n));
    }
    for (int i = 1; (i <= n); (i++)) {
      (sortv[i] = arr[i]);
    }
    j::sort(sortv, 1, (n + 1));
    (s = 1);
    for (int i = 2; (i <= n); (i++)) {
      if ((sortv[s] != sortv[i])) {
        (sortv[(++s)] = sortv[i]);
      }
    }
    for (int i = 1; (i <= n); (i++)) {
      (arr[i] = Code03_Violet1::lower(arr[i]));
    }
    for (int i = 1; (i <= bnum); (i++)) {
      for (int j = bl[i]; (j <= br[i]); (j++)) {
        (freq[i][arr[j]]++);
      }
      for (int j = 1; (j <= s); (j++)) {
        (freq[i][j] += freq[(i - 1)][j]);
      }
    }
    for (int i = 1; (i <= bnum); (i++)) {
      for (int j = i; (j <= bnum); (j++)) {
        int most = mode[i][(j - 1)];
        int mostCnt = Code03_Violet1::getCnt(i, j, most);
        for (int k = bl[j]; (k <= br[j]); (k++)) {
          int cur = arr[k];
          int curCnt = Code03_Violet1::getCnt(i, j, cur);
          if (((curCnt > mostCnt) || ((curCnt == mostCnt) && (cur < most)))) {
            (most = cur);
            (mostCnt = curCnt);
          }
        }
        (mode[i][j] = most);
      }
    }
  }
  static int query(int l, int r) {
    int most = 0;
    if ((bi[l] == bi[r])) {
      for (int i = l; (i <= r); (i++)) {
        (numCnt[arr[i]]++);
      }
      for (int i = l; (i <= r); (i++)) {
        if (((numCnt[arr[i]] > numCnt[most]) ||
             ((numCnt[arr[i]] == numCnt[most]) && (arr[i] < most)))) {
          (most = arr[i]);
        }
      }
      for (int i = l; (i <= r); (i++)) {
        (numCnt[arr[i]] = 0);
      }
    } else {
      for (int i = l; (i <= br[bi[l]]); (i++)) {
        (numCnt[arr[i]]++);
      }
      for (int i = bl[bi[r]]; (i <= r); (i++)) {
        (numCnt[arr[i]]++);
      }
      (most = mode[(bi[l] + 1)][(bi[r] - 1)]);
      int mostCnt = (Code03_Violet1::getCnt((bi[l] + 1), (bi[r] - 1), most) +
                     numCnt[most]);
      for (int i = l; (i <= br[bi[l]]); (i++)) {
        int cur = arr[i];
        int curCnt = (Code03_Violet1::getCnt((bi[l] + 1), (bi[r] - 1), cur) +
                      numCnt[cur]);
        if (((curCnt > mostCnt) || ((curCnt == mostCnt) && (cur < most)))) {
          (most = cur);
          (mostCnt = curCnt);
        }
      }
      for (int i = bl[bi[r]]; (i <= r); (i++)) {
        int cur = arr[i];
        int curCnt = (Code03_Violet1::getCnt((bi[l] + 1), (bi[r] - 1), cur) +
                      numCnt[cur]);
        if (((curCnt > mostCnt) || ((curCnt == mostCnt) && (cur < most)))) {
          (most = cur);
          (mostCnt = curCnt);
        }
      }
      for (int i = l; (i <= br[bi[l]]); (i++)) {
        (numCnt[arr[i]] = 0);
      }
      for (int i = bl[bi[r]]; (i <= r); (i++)) {
        (numCnt[arr[i]] = 0);
      }
    }
    return sortv[most];
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (m = in.nextInt());
    for (int i = 1; (i <= n); (i++)) {
      (arr[i] = in.nextInt());
    }
    Code03_Violet1::prepare();
    {
      int i = 1;
      int a = {};
      int b = {};
      int l = {};
      int r = {};
      int lastAns = 0;
      for (; (i <= m); (i++)) {
        (a = (jrem(((in.nextInt() + lastAns) - 1), n) + 1));
        (b = (jrem(((in.nextInt() + lastAns) - 1), n) + 1));
        (l = jmin(a, b));
        (r = jmax(a, b));
        (lastAns = Code03_Violet1::query(l, r));
        out.println(lastAns);
      }
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code03_Violet1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 蒲公英，java版
// 给定一个长度为n的数组arr，接下来有m条操作，每条操作格式如下
// 操作 l r : 打印arr[l..r]范围上的众数，如果有多个众数，打印值最小的
// 1 <= n <= 4 * 10^4
// 1 <= m <= 5 * 10^4
// 1 <= 数组中的值 <= 10^9
// 题目要求强制在线，具体规则可以打开测试链接查看
// 测试链接 : https://www.luogu.com.cn/problem/P4168
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 数字做离散化
        // freq[i][j]表示前i块中j出现的次数
        // mode[i][j]表示从i块到j块中的众数(最小)
        // 数字的词频统计
                // 建块
                // 离散化
                // 填好freq
                // 填好mode
        // 读写工具类
*/

// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P3863

// Source: src/class173/Code02_Sequence1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_Sequence1 {
  inline static int MAXN = 100001;
  inline static int MAXB = 501;
  inline static int n = {};
  inline static int m = {};
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static Array<Array<int>> event = make_array<int>(jshl(MAXN, 2), 5);
  inline static int cnte = 0;
  inline static int cntq = 0;
  inline static Array<i64> tim = make_array<i64>(MAXN);
  inline static Array<i64> sortv = make_array<i64>(MAXN);
  inline static int blen = {};
  inline static int bnum = {};
  inline static Array<int> bi = make_array<int>(MAXN);
  inline static Array<int> bl = make_array<int>(MAXB);
  inline static Array<int> br = make_array<int>(MAXB);
  inline static Array<i64> lazy = make_array<i64>(MAXB);
  inline static Array<int> ans = make_array<int>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_Sequence1() {}
  static void innerAdd(int l, int r, i64 v) {
    for (int i = l; (i <= r); (i++)) {
      (tim[i] += v);
    }
    for (int i = bl[bi[l]]; (i <= br[bi[l]]); (i++)) {
      (sortv[i] = tim[i]);
    }
    j::sort(sortv, bl[bi[l]], (br[bi[l]] + 1));
  }
  static void add(int l, int r, i64 v) {
    if ((l > r)) {
      return;
    }
    if ((bi[l] == bi[r])) {
      Code02_Sequence1::innerAdd(l, r, v);
    } else {
      Code02_Sequence1::innerAdd(l, br[bi[l]], v);
      Code02_Sequence1::innerAdd(bl[bi[r]], r, v);
      for (int i = (bi[l] + 1); (i <= (bi[r] - 1)); (i++)) {
        (lazy[i] += v);
      }
    }
  }
  static int innerQuery(int l, int r, i64 v) {
    (v -= lazy[bi[l]]);
    int ans = 0;
    for (int i = l; (i <= r); (i++)) {
      if ((tim[i] >= v)) {
        (ans++);
      }
    }
    return ans;
  }
  static int getCnt(int i, i64 v) {
    (v -= lazy[i]);
    int l = bl[i];
    int r = br[i];
    int m = {};
    int pos = (br[i] + 1);
    while ((l <= r)) {
      (m = jshr((l + r), 1));
      if ((sortv[m] >= v)) {
        (pos = m);
        (r = (m - 1));
      } else {
        (l = (m + 1));
      }
    }
    return ((br[i] - pos) + 1);
  }
  static int query(int l, int r, i64 v) {
    if ((l > r)) {
      return 0;
    }
    int ans = 0;
    if ((bi[l] == bi[r])) {
      (ans += Code02_Sequence1::innerQuery(l, r, v));
    } else {
      (ans += Code02_Sequence1::innerQuery(l, br[bi[l]], v));
      (ans += Code02_Sequence1::innerQuery(bl[bi[r]], r, v));
      for (int i = (bi[l] + 1); (i <= (bi[r] - 1)); (i++)) {
        (ans += Code02_Sequence1::getCnt(i, v));
      }
    }
    return ans;
  }
  static void addChange(int x, int t, int v) {
    (event[(++cnte)][0] = 1);
    (event[cnte][1] = x);
    (event[cnte][2] = t);
    (event[cnte][3] = v);
  }
  static void addQuery(int x, int t, int v) {
    (event[(++cnte)][0] = 2);
    (event[cnte][1] = x);
    (event[cnte][2] = t);
    (event[cnte][3] = v);
    (event[cnte][4] = (++cntq));
  }
  static void prepare() {
    (blen = static_cast<int>(std::sqrt(m)));
    (bnum = jdiv(((m + blen) - 1), blen));
    for (int i = 1; (i <= m); (i++)) {
      (bi[i] = (jdiv((i - 1), blen) + 1));
    }
    for (int i = 1; (i <= bnum); (i++)) {
      (bl[i] = (((i - 1) * blen) + 1));
      (br[i] = jmin((i * blen), m));
    }
    j::sort(event, 1, (cnte + 1), [=](Array<int> a, Array<int> b) {
      return ((a[1] != b[1]) ? (a[1] - b[1]) : (a[2] - b[2]));
    });
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (m = in.nextInt());
    for (int i = 1; (i <= n); (i++)) {
      (arr[i] = in.nextInt());
    }
    (m++);
    {
      int t = 2;
      int op = {};
      int l = {};
      int r = {};
      int v = {};
      int x = {};
      for (; (t <= m); (t++)) {
        (op = in.nextInt());
        if ((op == 1)) {
          (l = in.nextInt());
          (r = in.nextInt());
          (v = in.nextInt());
          Code02_Sequence1::addChange(l, t, v);
          Code02_Sequence1::addChange((r + 1), t, (-v));
        } else {
          (x = in.nextInt());
          (v = in.nextInt());
          Code02_Sequence1::addQuery(x, t, v);
        }
      }
    }
    Code02_Sequence1::prepare();
    {
      int i = 1;
      int op = {};
      int x = {};
      int t = {};
      int v = {};
      int q = {};
      for (; (i <= cnte); (i++)) {
        (op = event[i][0]);
        (x = event[i][1]);
        (t = event[i][2]);
        (v = event[i][3]);
        (q = event[i][4]);
        if ((op == 1)) {
          Code02_Sequence1::add(t, m, v);
        } else {
          (ans[q] = Code02_Sequence1::query(1, (t - 1), (v - arr[x])));
        }
      }
    }
    for (int i = 1; (i <= cntq); (i++)) {
      out.println(ans[i]);
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code02_Sequence1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 序列，java版
// 给定一个长度为n的数组arr，初始时刻认为是第0秒
// 接下来发生m条操作，第i条操作发生在第i秒，操作类型如下
// 操作 1 l r v : arr[l..r]范围上每个数加v，v可能是负数
// 操作 2 x v   : 不包括当前这一秒，查询过去多少秒内，arr[x] >= v
// 2 <= n、m <= 10^5
// -10^9 <= 数组中的值 <= +10^9
// 测试链接 : https://www.luogu.com.cn/problem/P3863
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // op == 1 表示修改事件、位置x、时刻t、修改效果v、空缺
        // op == 2 表示查询事件、位置x、时刻t、查询标准v、问题编号q
        // tim[i] = v，表示在i号时间点，所有数字都增加v
        // 时间块内的所有值要排序，方便查询 >= v的数字个数
        // 时间分块
        // 每个查询的答案
        // 第i块内>= v的数字个数
                //
所有事件根据位置x排序，位置一样的事件，修改事件先执行，查询事件后执行
        // 读写工具类
*/

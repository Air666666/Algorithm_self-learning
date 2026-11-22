// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P4119

// Source: src/class174/Code01_FutureDiary1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_FutureDiary1 {
  inline static int MAXN = 100001;
  inline static int MAXB = 401;
  inline static int n = {};
  inline static int m = {};
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static int blen = {};
  inline static int bnum = {};
  inline static Array<int> bi = make_array<int>(MAXN);
  inline static Array<int> bl = make_array<int>(MAXB);
  inline static Array<int> br = make_array<int>(MAXB);
  inline static Array<int> idxset = make_array<int>(MAXN);
  inline static Array<Array<int>> valset = make_array<int>(MAXB, MAXN);
  inline static Array<Array<int>> setval = make_array<int>(MAXB, MAXN);
  inline static Array<Array<int>> sum1 = make_array<int>(MAXB, MAXB);
  inline static Array<Array<int>> sum2 = make_array<int>(MAXB, MAXN);
  inline static Array<int> cnt1 = make_array<int>(MAXB);
  inline static Array<int> cnt2 = make_array<int>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_FutureDiary1() {}
  static void build(int b) {
    for (int i = 1; (i <= blen); (i++)) {
      (valset[b][setval[b][i]] = 0);
    }
    {
      int i = bl[b];
      int s = 0;
      for (; (i <= br[b]); (i++)) {
        if ((valset[b][arr[i]] == 0)) {
          (s++);
          (valset[b][arr[i]] = s);
          (setval[b][s] = arr[i]);
        }
        (idxset[i] = valset[b][arr[i]]);
      }
    }
  }
  static void lazy(int b, int x, int y) {
    (valset[b][y] = valset[b][x]);
    (setval[b][valset[b][x]] = y);
    (valset[b][x] = 0);
  }
  static void down(int b) {
    for (int i = bl[b]; (i <= br[b]); (i++)) {
      (arr[i] = setval[b][idxset[i]]);
    }
  }
  static void innerUpdate(int l, int r, int x, int y) {
    Code01_FutureDiary1::down(bi[l]);
    for (int i = l; (i <= r); (i++)) {
      if ((arr[i] == x)) {
        (sum1[bi[i]][bi[x]]--);
        (sum1[bi[i]][bi[y]]++);
        (sum2[bi[i]][x]--);
        (sum2[bi[i]][y]++);
        (arr[i] = y);
      }
    }
    Code01_FutureDiary1::build(bi[l]);
  }
  static void update(int l, int r, int x, int y) {
    if (((x == y) || ((sum2[bi[r]][x] - sum2[(bi[l] - 1)][x]) == 0))) {
      return;
    }
    for (int b = bi[n]; (b >= bi[l]); (b--)) {
      (sum1[b][bi[x]] -= sum1[(b - 1)][bi[x]]);
      (sum1[b][bi[y]] -= sum1[(b - 1)][bi[y]]);
      (sum2[b][x] -= sum2[(b - 1)][x]);
      (sum2[b][y] -= sum2[(b - 1)][y]);
    }
    if ((bi[l] == bi[r])) {
      Code01_FutureDiary1::innerUpdate(l, r, x, y);
    } else {
      Code01_FutureDiary1::innerUpdate(l, br[bi[l]], x, y);
      Code01_FutureDiary1::innerUpdate(bl[bi[r]], r, x, y);
      for (int b = (bi[l] + 1); (b <= (bi[r] - 1)); (b++)) {
        if ((sum2[b][x] != 0)) {
          if ((sum2[b][y] != 0)) {
            Code01_FutureDiary1::innerUpdate(bl[b], br[b], x, y);
          } else {
            (sum1[b][bi[y]] += sum2[b][x]);
            (sum1[b][bi[x]] -= sum2[b][x]);
            (sum2[b][y] += sum2[b][x]);
            (sum2[b][x] = 0);
            Code01_FutureDiary1::lazy(b, x, y);
          }
        }
      }
    }
    for (int b = bi[l]; (b <= bi[n]); (b++)) {
      (sum1[b][bi[x]] += sum1[(b - 1)][bi[x]]);
      (sum1[b][bi[y]] += sum1[(b - 1)][bi[y]]);
      (sum2[b][x] += sum2[(b - 1)][x]);
      (sum2[b][y] += sum2[(b - 1)][y]);
    }
  }
  static void addCnt(int l, int r) {
    for (int i = l; (i <= r); (i++)) {
      (cnt1[bi[arr[i]]]++);
      (cnt2[arr[i]]++);
    }
  }
  static void clearCnt(int l, int r) {
    for (int i = l; (i <= r); (i++)) {
      (cnt1[bi[arr[i]]] = (cnt2[arr[i]] = 0));
    }
  }
  static int query(int l, int r, int k) {
    int ans = 0;
    bool inner = (bi[l] == bi[r]);
    if (inner) {
      Code01_FutureDiary1::down(bi[l]);
      Code01_FutureDiary1::addCnt(l, r);
    } else {
      Code01_FutureDiary1::down(bi[l]);
      Code01_FutureDiary1::down(bi[r]);
      Code01_FutureDiary1::addCnt(l, br[bi[l]]);
      Code01_FutureDiary1::addCnt(bl[bi[r]], r);
    }
    int sumCnt = 0;
    int vblock = 0;
    for (int b = 1; (b <= bi[(MAXN - 1)]); (b++)) {
      int cnt =
          (cnt1[b] + (inner ? 0 : (sum1[(bi[r] - 1)][b] - sum1[bi[l]][b])));
      if (((sumCnt + cnt) >= k)) {
        (vblock = b);
        break;
      } else {
        (sumCnt += cnt);
      }
    }
    for (int v = (((vblock - 1) * blen) + 1); (v <= (vblock * blen)); (v++)) {
      int cnt =
          (cnt2[v] + (inner ? 0 : (sum2[(bi[r] - 1)][v] - sum2[bi[l]][v])));
      if (((sumCnt + cnt) >= k)) {
        (ans = v);
        break;
      } else {
        (sumCnt += cnt);
      }
    }
    if (inner) {
      Code01_FutureDiary1::clearCnt(l, r);
    } else {
      Code01_FutureDiary1::clearCnt(l, br[bi[l]]);
      Code01_FutureDiary1::clearCnt(bl[bi[r]], r);
    }
    return ans;
  }
  static void prepare() {
    (blen = 300);
    (bnum = jdiv(((n + blen) - 1), blen));
    for (int i = 1; (i < MAXN); (i++)) {
      (bi[i] = (jdiv((i - 1), blen) + 1));
    }
    for (int i = 1; (i <= bnum); (i++)) {
      (bl[i] = (((i - 1) * blen) + 1));
      (br[i] = jmin((i * blen), n));
      Code01_FutureDiary1::build(i);
    }
    for (int i = 1; (i <= bnum); (i++)) {
      for (int j = 1; (j < MAXB); (j++)) {
        (sum1[i][j] = sum1[(i - 1)][j]);
      }
      for (int j = 1; (j < MAXN); (j++)) {
        (sum2[i][j] = sum2[(i - 1)][j]);
      }
      for (int j = bl[i]; (j <= br[i]); (j++)) {
        (sum1[i][bi[arr[j]]]++);
        (sum2[i][arr[j]]++);
      }
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (m = in.nextInt());
    for (int i = 1; (i <= n); (i++)) {
      (arr[i] = in.nextInt());
    }
    Code01_FutureDiary1::prepare();
    {
      int i = 1;
      int op = {};
      int l = {};
      int r = {};
      int x = {};
      int y = {};
      int k = {};
      for (; (i <= m); (i++)) {
        (op = in.nextInt());
        (l = in.nextInt());
        (r = in.nextInt());
        if ((op == 1)) {
          (x = in.nextInt());
          (y = in.nextInt());
          Code01_FutureDiary1::update(l, r, x, y);
        } else {
          (k = in.nextInt());
          out.println(Code01_FutureDiary1::query(l, r, k));
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
  Code01_FutureDiary1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 未来日记，java版
// 给定一个长度为n的数组arr，一共有m条操作，每条操作类型如下
// 操作 1 l r x y : arr[l..r]范围上，所有值x变成值y
// 操作 2 l r k   : arr[l..r]范围上，查询第k小的值
// 1 <= n、m、arr[i] <= 10^5
// 测试链接 : https://www.luogu.com.cn/problem/P4119
// 提交以下的code，提交时请把类名改成"Main"
// java实现的逻辑一定是正确的，但是本题卡常，无法通过所有测试用例
// 想通过用C++实现，本节课Code01_FutureDiary2文件就是C++的实现
// 两个版本的逻辑完全一样，C++版本可以通过所有测试
        // blen既表示序列块长，也表示值域块长
        // bnum只表示序列块的数量
        // bi[i]可以查询下标i来自哪个序列块
        // bi[v]也可查询数字v来自哪个值域块
        // bl[i]表示下标第i块的左边界
        // br[i]表示下标第i块的右边界
        // idxset[i]表示下标i，在归属的块中，来自哪个集合
        // valset[b][v]表示序列块b中的数值v，来自哪个集合
        // setval[b][s]表示序列块b中的集合s，对应的数值
        // sum1[k][b]表示前k个序列块中，第b块个值域块的数字有几个
        // sum2[k][v]表示前k个序列块中，数字v有几个
        // cnt1[b]表示遍历散块之后，第b块个值域块的数字有几个
        // cnt2[v]表示遍历散块之后，数字v有几个
        // 序列第b块中，根据当前arr中的值，重建集合
                // 根据arr中的值重建集合，需要放弃之前的信息
                // 可是数值范围很大，不能枚举数值去清空 valset
                // 注意到，一个块里集合的数量 <= 块长
                // 所以根据 setval[b][s]，可以得到每个集合之前的对应值v
                // 然后 valset[b][v] = 0，让块内之前的每个值，不再挂靠任何集合
                // 这样可以避免数值的枚举，做到快速清空 valset
                // 重建集合的过程
        // 命中了整块修改，有x无y的情况，序列第b块中所有x改成y
        //
之前命中了整块修改，有x无y的情况，导致序列第b块中有些值改动了，把改动写入arr
        // 序列[l..r]范围上，有x有y，把所有x改成y
                // 必要的剪枝
                // 前缀统计变成当前块统计
                                                //
整块更新时，调用innerUpdate的次数 <= 块长
                // 当前块统计变回前缀统计
                // 建立散块的词频统计
                // 定位第k小的数字，来自哪个值域块
                        // 如果不存在中间的整块，词频 = 散块词频，否则 词频 =
散块词频 + 整块词频
                // 定位第k小的数字，来自值域块的具体数字
                        // 如果不存在中间的整块，词频 = 散块词频，否则 词频 =
散块词频 + 整块词频
                // 清空散块的词频统计
                // i一定要枚举[1, MAXN)
                // 因为不仅序列要分块，值域也要分块
                // bl、br 仅用于序列分块
                // 初始建立sum1、sum2，都表示前缀信息
        // 读写工具类
*/

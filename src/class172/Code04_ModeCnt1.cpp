// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P5048

// Source: src/class172/Code04_ModeCnt1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_ModeCnt1 {
  inline static int MAXN = 500001;
  inline static int MAXB = 801;
  inline static int n = {};
  inline static int m = {};
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static int blen = {};
  inline static int bnum = {};
  inline static Array<int> bi = make_array<int>(MAXN);
  inline static Array<int> bl = make_array<int>(MAXB);
  inline static Array<int> br = make_array<int>(MAXB);
  inline static Array<Array<int>> sortList = make_array<int>(MAXN, 2);
  inline static Array<int> listIdx = make_array<int>(MAXN);
  inline static Array<Array<int>> modeCnt = make_array<int>(MAXB, MAXB);
  inline static Array<int> numCnt = make_array<int>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_ModeCnt1() {}
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
      (sortList[i][0] = arr[i]);
      (sortList[i][1] = i);
    }
    j::sort(sortList, 1, (n + 1), [=](Array<int> a, Array<int> b) {
      return ((a[0] != b[0]) ? (a[0] - b[0]) : (a[1] - b[1]));
    });
    for (int i = 1; (i <= n); (i++)) {
      (listIdx[sortList[i][1]] = i);
    }
    for (int i = 1; (i <= bnum); (i++)) {
      for (int j = i; (j <= bnum); (j++)) {
        int cnt = modeCnt[i][(j - 1)];
        for (int k = bl[j]; (k <= br[j]); (k++)) {
          (cnt = jmax(cnt, (++numCnt[arr[k]])));
        }
        (modeCnt[i][j] = cnt);
      }
      for (int j = 1; (j <= n); (j++)) {
        (numCnt[j] = 0);
      }
    }
  }
  static int query(int l, int r) {
    int ans = 0;
    if ((bi[l] == bi[r])) {
      for (int i = l; (i <= r); (i++)) {
        (ans = jmax(ans, (++numCnt[arr[i]])));
      }
      for (int i = l; (i <= r); (i++)) {
        (numCnt[arr[i]] = 0);
      }
    } else {
      (ans = modeCnt[(bi[l] + 1)][(bi[r] - 1)]);
      {
        int i = l;
        int idx = {};
        for (; (i <= br[bi[l]]); (i++)) {
          (idx = listIdx[i]);
          while (
              ((((idx + ans) <= n) && (sortList[(idx + ans)][0] == arr[i])) &&
               (sortList[(idx + ans)][1] <= r))) {
            (ans++);
          }
        }
      }
      {
        int i = bl[bi[r]];
        int idx = {};
        for (; (i <= r); (i++)) {
          (idx = listIdx[i]);
          while (
              ((((idx - ans) >= 1) && (sortList[(idx - ans)][0] == arr[i])) &&
               (sortList[(idx - ans)][1] >= l))) {
            (ans++);
          }
        }
      }
    }
    return ans;
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (m = in.nextInt());
    for (int i = 1; (i <= n); (i++)) {
      (arr[i] = in.nextInt());
    }
    Code04_ModeCnt1::prepare();
    {
      int i = 1;
      int l = {};
      int r = {};
      int lastAns = 0;
      for (; (i <= m); (i++)) {
        (l = (in.nextInt() ^ lastAns));
        (r = (in.nextInt() ^ lastAns));
        (lastAns = Code04_ModeCnt1::query(l, r));
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
  Code04_ModeCnt1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 空间少求众数的次数，java版
// 给定一个长度为n的数组arr，接下来有m条操作，每条操作格式如下
// 操作 l r : 打印arr[l..r]范围上，众数到底出现了几次
// 1 <= 所有数值 <= 5 * 10^5
// 内存空间只有64MB，题目要求强制在线，具体规则可以打开测试链接查看
// 测试链接 : https://www.luogu.com.cn/problem/P5048
// 提交以下的code，提交时请把类名改成"Main"
// java实现的逻辑一定是正确的，但是内存占用过大，无法通过测试用例
// 因为这道题只考虑C++能通过的空间标准，根本没考虑java的用户
// 想通过用C++实现，本节课Code04_ModeCnt2文件就是C++的实现
// 两个版本的逻辑完全一样，C++版本可以通过所有测试
        // (值、下标)，用来收集同一种数的下标列表
        // listIdx[i] = j，表示arr[i]这个元素在sortList里的j位置
        // modeCnt[i][j]表示从i块到j块中众数的出现次数
        // 数字词频统计
        // 读写工具类
*/

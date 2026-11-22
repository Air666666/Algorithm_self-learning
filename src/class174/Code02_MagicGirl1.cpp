// Source: src/class174/Code02_MagicGirl1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_MagicGirl1 {
  inline static int MAXN = 300002;
  inline static int MAXB = 601;
  inline static int POW = 9;
  inline static int OFFSET = (jshl(1, POW) - 1);
  inline static int n = {};
  inline static int m = {};
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static Array<int> op = make_array<int>(MAXN);
  inline static Array<int> x = make_array<int>(MAXN);
  inline static Array<int> y = make_array<int>(MAXN);
  inline static Array<int> v = make_array<int>(MAXN);
  inline static Array<int> pos = make_array<int>(MAXN);
  inline static Array<int> qid = make_array<int>(MAXN);
  inline static int cntp = {};
  inline static int cntq = {};
  inline static Array<int> cntv = make_array<int>(MAXB);
  inline static Array<int> help = make_array<int>(MAXN);
  inline static Array<int> last = make_array<int>(MAXN);
  inline static Array<int> next = make_array<int>(MAXN);
  inline static Array<int> pre = make_array<int>(MAXN);
  inline static Array<int> suf = make_array<int>(MAXN);
  inline static Array<int> len = make_array<int>(MAXN);
  inline static Array<i64> ans = make_array<i64>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_MagicGirl1() {}
  static void radix(Array<int> idx, Array<int> val, int siz) {
    j::fill(cntv, 0);
    for (int i = 1; (i <= siz); (i++))
      (cntv[(val[idx[i]] & OFFSET)]++);
    for (int i = 1; (i < MAXB); (i++))
      (cntv[i] += cntv[(i - 1)]);
    for (int i = siz; (i >= 1); (i--))
      (help[(cntv[(val[idx[i]] & OFFSET)]--)] = idx[i]);
    for (int i = 1; (i <= siz); (i++))
      (idx[i] = help[i]);
    j::fill(cntv, 0);
    for (int i = 1; (i <= siz); (i++))
      (cntv[jshr(val[idx[i]], POW)]++);
    for (int i = 1; (i < MAXB); (i++))
      (cntv[i] += cntv[(i - 1)]);
    for (int i = siz; (i >= 1); (i--))
      (help[(cntv[jshr(val[idx[i]], POW)]--)] = idx[i]);
    for (int i = 1; (i <= siz); (i++))
      (idx[i] = help[i]);
  }
  static void merge(int i, int curPre, int curSuf, int curLen, int curAns) {
    (ans[i] += (((1LL * suf[i]) * curPre) + curAns));
    (pre[i] = (pre[i] + ((pre[i] == len[i]) ? curPre : 0)));
    (suf[i] = (curSuf + ((curSuf == curLen) ? suf[i] : 0)));
    (len[i] += curLen);
  }
  static void calc(int l, int r) {
    for (int i = l; (i <= r); (i++)) {
      (pos[(++cntp)] = i);
      (last[i] = (i - 1));
      (next[i] = (i + 1));
    }
    Code02_MagicGirl1::radix(pos, arr, cntp);
    Code02_MagicGirl1::radix(qid, v, cntq);
    int curPre = 0;
    int curSuf = 0;
    int curLen = ((r - l) + 1);
    int curAns = 0;
    {
      int i = 1;
      int j = 1;
      int idx = {};
      for (; (i <= cntq); (i++)) {
        while (((j <= cntp) && (arr[pos[j]] <= v[qid[i]]))) {
          (idx = pos[j]);
          if ((last[idx] == (l - 1))) {
            (curPre += (next[idx] - idx));
          }
          if ((next[idx] == (r + 1))) {
            (curSuf += (idx - last[idx]));
          }
          (curAns += ((1LL * (idx - last[idx])) * (next[idx] - idx)));
          (last[next[idx]] = last[idx]);
          (next[last[idx]] = next[idx]);
          (j++);
        }
        Code02_MagicGirl1::merge(qid[i], curPre, curSuf, curLen, curAns);
      }
    }
    (cntp = (cntq = 0));
  }
  static void compute(int l, int r) {
    for (int qi = 1; (qi <= m); (qi++)) {
      if ((op[qi] == 1)) {
        if (((l <= x[qi]) && (x[qi] <= r))) {
          Code02_MagicGirl1::calc(l, r);
          (arr[x[qi]] = v[qi]);
        }
      } else {
        if (((x[qi] <= l) && (r <= y[qi]))) {
          (qid[(++cntq)] = qi);
        } else {
          for (int i = jmax(x[qi], l); (i <= jmin(y[qi], r)); (i++)) {
            if ((arr[i] <= v[qi])) {
              Code02_MagicGirl1::merge(qi, 1, 1, 1, 1);
            } else {
              Code02_MagicGirl1::merge(qi, 0, 0, 1, 0);
            }
          }
        }
      }
    }
    Code02_MagicGirl1::calc(l, r);
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (m = in.nextInt());
    for (int i = 1; (i <= n); (i++)) {
      (arr[i] = in.nextInt());
    }
    for (int i = 1; (i <= m); (i++)) {
      (op[i] = in.nextInt());
      (x[i] = in.nextInt());
      if ((op[i] == 1)) {
        (v[i] = in.nextInt());
      } else {
        (y[i] = in.nextInt());
        (v[i] = in.nextInt());
      }
    }
    int blen = jshl(1, POW);
    int bnum = jdiv(((n + blen) - 1), blen);
    {
      int i = 1;
      int l = {};
      int r = {};
      for (; (i <= bnum); (i++)) {
        (l = (((i - 1) * blen) + 1));
        (r = jmin((i * blen), n));
        Code02_MagicGirl1::compute(l, r);
      }
    }
    for (int i = 1; (i <= m); (i++)) {
      if ((op[i] == 2)) {
        out.println(ans[i]);
      }
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code02_MagicGirl1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 魔法少女网站，java版
// 给定一个长度为n的数组arr，一共有m条操作，每条操作类型如下
// 操作 1 x v   : arr[x]的值变成v
// 操作 2 x y v : arr[x..y]范围上，查询有多少连续子数组的最大值 <= v
// 1 <= n、m <= 3 * 10^5
// 1 <= arr[i] <= n
// 测试链接 : https://www.luogu.com.cn/problem/P6578
// 提交以下的code，提交时请把类名改成"Main"
// java实现的逻辑一定是正确的，但是本题卡常，无法通过所有测试用例
// 想通过用C++实现，本节课Code02_MagicGirl2文件就是C++的实现
// 两个版本的逻辑完全一样，C++版本可以通过所有测试
        // pos[1..cntp]是当前序列块的下标
        // qid[1..cntq]是整包结算的查询编号
        // 基数排序
        // 双链表
        // 每条查询的答案信息
        // 讲解028 - 基数排序，不会的话去看课
        // idx[1..siz]都是编号，编号根据val[编号]的值排序
        // val[编号]的高位 = val[编号] >> POW
        // val[编号]的低位 = val[编号] & OFFSET
        // 查询的答案信息 pre[i]、suf[i]、len[i]、ans[i]
        // 当前块答案信息 curPre、curSuf、curLen、curAns
        // 查询的答案信息 合并 当前块答案信息
        // 整包结算
        // qid[1..cntq]是查询编号，每条查询整包[l..r]
        // 根据序列块的数字状况，更新每个查询的答案信息
        // 序列块[l..r]，处理一遍所有的操作(单改 + 查询)
        // 读写工具类
*/

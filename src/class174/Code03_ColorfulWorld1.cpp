// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P4117

// Source: src/class174/Code03_ColorfulWorld1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_ColorfulWorld1 {
  inline static int MAXN = 1000001;
  inline static int MAXM = 500001;
  inline static int MAXV = 100002;
  inline static int n = {};
  inline static int m = {};
  inline static int blen = {};
  inline static int bnum = {};
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static Array<int> op = make_array<int>(MAXM);
  inline static Array<int> ql = make_array<int>(MAXM);
  inline static Array<int> qr = make_array<int>(MAXM);
  inline static Array<int> qx = make_array<int>(MAXM);
  inline static int maxv = {};
  inline static int lazy = {};
  inline static Array<int> fa = make_array<int>(MAXV);
  inline static Array<int> pre0 = make_array<int>(MAXN);
  inline static Array<int> cntv = make_array<int>(MAXV);
  inline static Array<int> ans = make_array<int>(MAXM);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_ColorfulWorld1() {}
  static int find(int x) {
    if ((x != fa[x])) {
      (fa[x] = Code03_ColorfulWorld1::find(fa[x]));
    }
    return fa[x];
  }
  static void change(int x, int y) { (fa[x] = y); }
  static void down(int l, int r) {
    for (int i = l; (i <= r); (i++)) {
      (arr[i] = Code03_ColorfulWorld1::find(arr[i]));
    }
  }
  static void update(int qi, int l, int r) {
    int jobl = ql[qi];
    int jobr = qr[qi];
    int jobx = qx[qi];
    if ((((jobx >= (maxv - lazy)) || (jobl > r)) || (jobr < l))) {
      return;
    }
    if (((jobl <= l) && (r <= jobr))) {
      if ((jshl(jobx, 1) <= (maxv - lazy))) {
        for (int v = (lazy + 1); (v <= (lazy + jobx)); (v++)) {
          (cntv[(v + jobx)] += cntv[v]);
          (cntv[v] = 0);
          Code03_ColorfulWorld1::change(v, (v + jobx));
        }
        (lazy += jobx);
      } else {
        for (int v = ((lazy + jobx) + 1); (v <= maxv); (v++)) {
          (cntv[(v - jobx)] += cntv[v]);
          (cntv[v] = 0);
          Code03_ColorfulWorld1::change(v, (v - jobx));
        }
        for (int v = maxv; (v >= 0); (v--)) {
          if ((cntv[v] != 0)) {
            (maxv = v);
            break;
          }
        }
      }
    } else {
      Code03_ColorfulWorld1::down(l, r);
      for (int i = jmax(l, jobl); (i <= jmin(r, jobr)); (i++)) {
        if (((arr[i] - lazy) > jobx)) {
          (cntv[arr[i]]--);
          (arr[i] -= jobx);
          (cntv[arr[i]]++);
        }
      }
      for (int v = maxv; (v >= 0); (v--)) {
        if ((cntv[v] != 0)) {
          (maxv = v);
          break;
        }
      }
    }
  }
  static void query(int qi, int l, int r) {
    int jobl = ql[qi];
    int jobr = qr[qi];
    int jobx = qx[qi];
    if (((((jobx == 0) || (jobx > (maxv - lazy))) || (jobl > r)) ||
         (jobr < l))) {
      return;
    }
    if (((jobl <= l) && (r <= jobr))) {
      (ans[qi] += cntv[(jobx + lazy)]);
    } else {
      Code03_ColorfulWorld1::down(l, r);
      for (int i = jmax(l, jobl); (i <= jmin(r, jobr)); (i++)) {
        if (((arr[i] - lazy) == jobx)) {
          (ans[qi]++);
        }
      }
    }
  }
  static void compute(int l, int r) {
    j::fill(cntv, 0);
    (maxv = (lazy = 0));
    for (int i = l; (i <= r); (i++)) {
      (maxv = jmax(maxv, arr[i]));
      (cntv[arr[i]]++);
    }
    for (int v = 0; (v <= maxv); (v++)) {
      (fa[v] = v);
    }
    for (int i = 1; (i <= m); (i++)) {
      if ((op[i] == 1)) {
        Code03_ColorfulWorld1::update(i, l, r);
      } else {
        Code03_ColorfulWorld1::query(i, l, r);
      }
    }
  }
  static void prepare() {
    (blen = static_cast<int>(std::sqrt(n)));
    (bnum = jdiv(((n + blen) - 1), blen));
    for (int i = 1; (i <= n); (i++)) {
      (pre0[i] = (pre0[(i - 1)] + ((arr[i] == 0) ? 1 : 0)));
    }
    for (int i = 1; (i <= m); (i++)) {
      if (((op[i] == 2) && (qx[i] == 0))) {
        (ans[i] = (pre0[qr[i]] - pre0[(ql[i] - 1)]));
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
    for (int i = 1; (i <= m); (i++)) {
      (op[i] = in.nextInt());
      (ql[i] = in.nextInt());
      (qr[i] = in.nextInt());
      (qx[i] = in.nextInt());
    }
    Code03_ColorfulWorld1::prepare();
    {
      int i = 1;
      int l = {};
      int r = {};
      for (; (i <= bnum); (i++)) {
        (l = (((i - 1) * blen) + 1));
        (r = jmin((i * blen), n));
        Code03_ColorfulWorld1::compute(l, r);
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
  Code03_ColorfulWorld1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 五彩斑斓的世界，java版
// 给定一个长度为n的数组arr，一共有m条操作，每条操作类型如下
// 操作 1 l r x : arr[l..r]范围上，所有大于x的数减去x
// 操作 2 l r x : arr[l..r]范围上，查询x出现的次数
// 1 <= n <= 10^6
// 1 <= m <= 5 * 10^5
// 0 <= arr[i]、x <= 10^5
// 测试链接 : https://www.luogu.com.cn/problem/P4117
// 提交以下的code，提交时请把类名改成"Main"
// java实现的逻辑一定是正确的，但是本题卡常，无法通过所有测试用例
// 想通过用C++实现，本节课Code03_ColorfulWorld2文件就是C++的实现
// 两个版本的逻辑完全一样，C++版本可以通过所有测试
        // maxv代表一个序列块中的最大值
        // lazy代表一个序列块中，所有数字需要统计减去多少
        // fa代表值域并查集
        // pre0代表数组前缀上0的词频统计
        // cntv代表一个序列块中每种值的词频统计
        // 查询的答案
        // 查询x值变成了什么
        // 所有x值变成y值
        // 修改保留在值域并查集，把修改写入arr[l..r]
        // 读写工具类
*/

// Source: src/class113/Code03_TunnelWarfare.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_TunnelWarfare {
  inline static int MAXN = 50001;
  inline static Array<int> pre = make_array<int>(jshl(MAXN, 2));
  inline static Array<int> suf = make_array<int>(jshl(MAXN, 2));
  inline static Array<int> stack = make_array<int>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_TunnelWarfare() {}
  static void up(int l, int r, int i) {
    (pre[i] = pre[jshl(i, 1)]);
    (suf[i] = suf[(jshl(i, 1) | 1)]);
    int mid = jshr((l + r), 1);
    if ((pre[jshl(i, 1)] == ((mid - l) + 1))) {
      (pre[i] += pre[(jshl(i, 1) | 1)]);
    }
    if ((suf[(jshl(i, 1) | 1)] == (r - mid))) {
      (suf[i] += suf[jshl(i, 1)]);
    }
  }
  static void build(int l, int r, int i) {
    if ((l == r)) {
      (pre[i] = (suf[i] = 1));
    } else {
      int mid = jshr((l + r), 1);
      Code03_TunnelWarfare::build(l, mid, jshl(i, 1));
      Code03_TunnelWarfare::build((mid + 1), r, (jshl(i, 1) | 1));
      Code03_TunnelWarfare::up(l, r, i);
    }
  }
  static void update(int jobi, int jobv, int l, int r, int i) {
    if ((l == r)) {
      (pre[i] = (suf[i] = jobv));
    } else {
      int mid = jshr((l + r), 1);
      if ((jobi <= mid)) {
        Code03_TunnelWarfare::update(jobi, jobv, l, mid, jshl(i, 1));
      } else {
        Code03_TunnelWarfare::update(jobi, jobv, (mid + 1), r,
                                     (jshl(i, 1) | 1));
      }
      Code03_TunnelWarfare::up(l, r, i);
    }
  }
  static int query(int jobi, int l, int r, int i) {
    if ((l == r)) {
      return pre[i];
    } else {
      int mid = jshr((l + r), 1);
      if ((jobi <= mid)) {
        if ((jobi > (mid - suf[jshl(i, 1)]))) {
          return (suf[jshl(i, 1)] + pre[(jshl(i, 1) | 1)]);
        } else {
          return Code03_TunnelWarfare::query(jobi, l, mid, jshl(i, 1));
        }
      } else {
        if (((mid + pre[(jshl(i, 1) | 1)]) >= jobi)) {
          return (suf[jshl(i, 1)] + pre[(jshl(i, 1) | 1)]);
        } else {
          return Code03_TunnelWarfare::query(jobi, (mid + 1), r,
                                             (jshl(i, 1) | 1));
        }
      }
    }
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    while ((in.nextToken() != -1)) {
      int n = static_cast<int>(in.nval);
      in.nextToken();
      int m = static_cast<int>(in.nval);
      Code03_TunnelWarfare::build(1, n, 1);
      String op = {};
      int stackSize = 0;
      {
        int i = 1;
        int x = {};
        for (; (i <= m); (i++)) {
          in.nextToken();
          (op = in.sval);
          if (op.equals(String(u"D"))) {
            in.nextToken();
            (x = static_cast<int>(in.nval));
            Code03_TunnelWarfare::update(x, 0, 1, n, 1);
            (stack[(stackSize++)] = x);
          } else if (op.equals(String(u"R"))) {
            Code03_TunnelWarfare::update(stack[(--stackSize)], 1, 1, n, 1);
          } else {
            in.nextToken();
            (x = static_cast<int>(in.nval));
            out.println(Code03_TunnelWarfare::query(x, 1, n, 1));
          }
        }
      }
    }
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code03_TunnelWarfare::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 地道相连的房子
// 有n个房子排成一排，编号1~n，一开始每相邻的两个房子之间都有地道
// 实现如下三个操作
// 操作 D x : 把x号房子摧毁，该房子附近的地道也一并摧毁
// 操作 R   : 恢复上次摧毁的房子，该房子附近的地道一并恢复
// 操作 Q x : 查询x号房子能到达的房子数量，包括x号房子自身
// 测试链接 : https://www.luogu.com.cn/problem/P1503
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下的code，提交时请把类名改成"Main"，可以直接通过
        // 连续1的最长前缀长度
        // 连续1的最长后缀长度
        // 摧毁的房屋编号入栈，以便执行恢复操作
        // 已知jobi在l...r范围上
        // 返回jobi往两侧扩展出的最大长度
        // 递归需要遵循的潜台词 :
从jobi往两侧扩展，一定无法扩展到l...r范围之外！
*/

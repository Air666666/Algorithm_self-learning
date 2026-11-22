// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P2894

// Source: src/class113/Code04_Hotel.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_Hotel {
  inline static int MAXN = 50001;
  inline static Array<int> len = make_array<int>(jshl(MAXN, 2));
  inline static Array<int> pre = make_array<int>(jshl(MAXN, 2));
  inline static Array<int> suf = make_array<int>(jshl(MAXN, 2));
  inline static Array<int> change = make_array<int>(jshl(MAXN, 2));
  inline static Array<bool> update = make_array<bool>(jshl(MAXN, 2));
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_Hotel() {}
  static void up(int i, int ln, int rn) {
    int l = jshl(i, 1);
    int r = (jshl(i, 1) | 1);
    (len[i] = jmax(jmax(len[l], len[r]), (suf[l] + pre[r])));
    (pre[i] = ((len[l] < ln) ? pre[l] : (pre[l] + pre[r])));
    (suf[i] = ((len[r] < rn) ? suf[r] : (suf[l] + suf[r])));
  }
  static void down(int i, int ln, int rn) {
    if (update[i]) {
      Code04_Hotel::lazy(jshl(i, 1), change[i], ln);
      Code04_Hotel::lazy((jshl(i, 1) | 1), change[i], rn);
      (update[i] = false);
    }
  }
  static void lazy(int i, int v, int n) {
    (len[i] = (pre[i] = (suf[i] = ((v == 0) ? n : 0))));
    (change[i] = v);
    (update[i] = true);
  }
  static void build(int l, int r, int i) {
    if ((l == r)) {
      (len[i] = (pre[i] = (suf[i] = 1)));
    } else {
      int mid = jshr((l + r), 1);
      Code04_Hotel::build(l, mid, jshl(i, 1));
      Code04_Hotel::build((mid + 1), r, (jshl(i, 1) | 1));
      Code04_Hotel::up(i, ((mid - l) + 1), (r - mid));
    }
    (update[i] = false);
  }
  static void update_method(int jobl, int jobr, int jobv, int l, int r, int i) {
    if (((jobl <= l) && (r <= jobr))) {
      Code04_Hotel::lazy(i, jobv, ((r - l) + 1));
    } else {
      int mid = jshr((l + r), 1);
      Code04_Hotel::down(i, ((mid - l) + 1), (r - mid));
      if ((jobl <= mid)) {
        Code04_Hotel::update_method(jobl, jobr, jobv, l, mid, jshl(i, 1));
      }
      if ((jobr > mid)) {
        Code04_Hotel::update_method(jobl, jobr, jobv, (mid + 1), r,
                                    (jshl(i, 1) | 1));
      }
      Code04_Hotel::up(i, ((mid - l) + 1), (r - mid));
    }
  }
  static int queryLeft(int x, int l, int r, int i) {
    if ((l == r)) {
      return l;
    } else {
      int mid = jshr((l + r), 1);
      Code04_Hotel::down(i, ((mid - l) + 1), (r - mid));
      if ((len[jshl(i, 1)] >= x)) {
        return Code04_Hotel::queryLeft(x, l, mid, jshl(i, 1));
      }
      if (((suf[jshl(i, 1)] + pre[(jshl(i, 1) | 1)]) >= x)) {
        return ((mid - suf[jshl(i, 1)]) + 1);
      }
      return Code04_Hotel::queryLeft(x, (mid + 1), r, (jshl(i, 1) | 1));
    }
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    int n = static_cast<int>(in.nval);
    Code04_Hotel::build(1, n, 1);
    in.nextToken();
    int m = static_cast<int>(in.nval);
    {
      int i = 1;
      int op = {};
      int x = {};
      int y = {};
      int left = {};
      for (; (i <= m); (i++)) {
        in.nextToken();
        (op = static_cast<int>(in.nval));
        if ((op == 1)) {
          in.nextToken();
          (x = static_cast<int>(in.nval));
          if ((len[1] < x)) {
            (left = 0);
          } else {
            (left = Code04_Hotel::queryLeft(x, 1, n, 1));
            Code04_Hotel::update_method(left, ((left + x) - 1), 1, 1, n, 1);
          }
          out.println(left);
        } else {
          in.nextToken();
          (x = static_cast<int>(in.nval));
          in.nextToken();
          (y = static_cast<int>(in.nval));
          Code04_Hotel::update_method(x, jmin(((x + y) - 1), n), 0, 1, n, 1);
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
  Code04_Hotel::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 旅馆
// 一共有n个房间，编号1~n，一开始都是空房
// 实现如下两种操作，会一共调用m次
// 操作 1 x   : 找到至少有连续x个空房间的区域，返回最左编号
//              如果有多个满足条件的区域，返回其中最左区域的最左编号
//              如果找不到打印0，并且不办理入住
//              如果找到了打印最左编号，并且从最左编号开始办理x个人的入住
// 操作 2 x y : 从x号房间开始往下数y个房间，一律清空
// 操作1有打印操作，操作2没有
// 1 <= n 、m <= 50000
// 测试链接 : https://www.luogu.com.cn/problem/P2894
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下的code，提交时请把类名改成"Main"，可以直接通过
        // 连续空房最长子串长度
        // 连续空房最长前缀长度
        // 连续空房最长后缀长度
        // 懒更新信息，范围上所有数字被重置成了什么
        // 懒更新信息，范围上有没有重置任务
        // 在l..r范围上，在满足空房长度>=x的情况下，返回尽量靠左的开头位置
        // 递归需要遵循的潜台词 : l..r范围上一定存在连续空房长度>=x的区域
                        // 最先查左边
                        // 然后查中间向两边扩展的可能区域
                        // 前面都没有再最后查右边
*/

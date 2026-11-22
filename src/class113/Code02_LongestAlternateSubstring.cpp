// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P6492

// Source: src/class113/Code02_LongestAlternateSubstring.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_LongestAlternateSubstring {
  inline static int MAXN = 200001;
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static Array<int> len = make_array<int>(jshl(MAXN, 2));
  inline static Array<int> pre = make_array<int>(jshl(MAXN, 2));
  inline static Array<int> suf = make_array<int>(jshl(MAXN, 2));
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_LongestAlternateSubstring() {}
  static void up(int l, int r, int i) {
    (len[i] = jmax(len[jshl(i, 1)], len[(jshl(i, 1) | 1)]));
    (pre[i] = pre[jshl(i, 1)]);
    (suf[i] = suf[(jshl(i, 1) | 1)]);
    int mid = jshr((l + r), 1);
    int ln = ((mid - l) + 1);
    int rn = (r - mid);
    if ((arr[mid] != arr[(mid + 1)])) {
      (len[i] = jmax(len[i], (suf[jshl(i, 1)] + pre[(jshl(i, 1) | 1)])));
      if ((len[jshl(i, 1)] == ln)) {
        (pre[i] = (ln + pre[(jshl(i, 1) | 1)]));
      }
      if ((len[(jshl(i, 1) | 1)] == rn)) {
        (suf[i] = (rn + suf[jshl(i, 1)]));
      }
    }
  }
  static void build(int l, int r, int i) {
    if ((l == r)) {
      (len[i] = 1);
      (pre[i] = 1);
      (suf[i] = 1);
    } else {
      int mid = jshr((l + r), 1);
      Code02_LongestAlternateSubstring::build(l, mid, jshl(i, 1));
      Code02_LongestAlternateSubstring::build((mid + 1), r, (jshl(i, 1) | 1));
      Code02_LongestAlternateSubstring::up(l, r, i);
    }
  }
  static void reverse(int jobi, int l, int r, int i) {
    if ((l == r)) {
      (arr[jobi] ^= 1);
    } else {
      int mid = jshr((l + r), 1);
      if ((jobi <= mid)) {
        Code02_LongestAlternateSubstring::reverse(jobi, l, mid, jshl(i, 1));
      } else {
        Code02_LongestAlternateSubstring::reverse(jobi, (mid + 1), r,
                                                  (jshl(i, 1) | 1));
      }
      Code02_LongestAlternateSubstring::up(l, r, i);
    }
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    int n = static_cast<int>(in.nval);
    in.nextToken();
    int q = static_cast<int>(in.nval);
    Code02_LongestAlternateSubstring::build(1, n, 1);
    {
      int i = 1;
      int index = {};
      for (; (i <= q); (i++)) {
        in.nextToken();
        (index = static_cast<int>(in.nval));
        Code02_LongestAlternateSubstring::reverse(index, 1, n, 1);
        out.println(len[1]);
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
  Code02_LongestAlternateSubstring::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 最长LR交替子串
// 给定一个长度为n的字符串，一开始字符串中全是'L'字符
// 有q次修改，每次指定一个位置i
// 如果i位置是'L'字符那么改成'R'字符
// 如果i位置是'R'字符那么改成'L'字符
// 如果一个子串是两种字符不停交替出现的样子，也就是LRLR... 或者RLRL...
// 那么说这个子串是有效子串
// 每次修改后，都打印当前整个字符串中最长交替子串的长度
// 测试链接 : https://www.luogu.com.cn/problem/P6492
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下的code，提交时请把类名改成"Main"，可以直接通过
        // 原始数组
        // 交替最长子串长度
        // 交替最长前缀长度
        // 交替最长后缀长度
*/

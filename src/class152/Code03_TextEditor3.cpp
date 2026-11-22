// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P4008

// Source: src/class152/Code03_TextEditor3.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_TextEditor3 {
  inline static IO is = jin;
  inline static Array<signed char> inbuf = make_array<signed char>(1024);
  inline static Array<jchar> str = make_array<jchar>(16);
  inline static int lenbuf = {};
  inline static int ptrbuf = {};
  inline static int b = {};
  inline static IO out = IO();
  inline static Array<signed char> key = {};
  inline static Array<int> lc = {};
  inline static Array<int> rc = {};
  inline static Array<int> sz = {};
  inline static Array<double> priority = {};
  inline static int head = {};
  inline static int no = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_TextEditor3() {}
  static int create(signed char k) {
    if (((++no) == key.length)) {
      (key = j::copyOf(key, jshl(no, 1)));
      (lc = j::copyOf(lc, jshl(no, 1)));
      (rc = j::copyOf(rc, jshl(no, 1)));
      (sz = j::copyOf(sz, jshl(no, 1)));
      (priority = j::copyOf(priority, jshl(no, 1)));
    }
    (key[no] = k);
    (sz[no] = 1);
    (priority[no] = j::random());
    return no;
  }
  static void up(int i) { (sz[i] = ((sz[lc[i]] + sz[rc[i]]) + 1)); }
  static void split(int l, int r, int i, int rk) {
    if ((i == 0)) {
      (rc[l] = (lc[r] = 0));
      return;
    }
    if (((sz[lc[i]] + 1) <= rk)) {
      (rc[l] = i);
      Code03_TextEditor3::split(i, r, rc[i], ((rk - sz[lc[i]]) - 1));
    } else {
      (lc[r] = i);
      Code03_TextEditor3::split(l, i, lc[i], rk);
    }
    Code03_TextEditor3::up(i);
  }
  static int merge(int l, int r) {
    if (((l == 0) || (r == 0))) {
      return (l + r);
    }
    if ((priority[l] >= priority[r])) {
      (rc[l] = Code03_TextEditor3::merge(rc[l], r));
      Code03_TextEditor3::up(l);
      return l;
    } else {
      (lc[r] = Code03_TextEditor3::merge(l, lc[r]));
      Code03_TextEditor3::up(r);
      return r;
    }
  }
  static void inorder(int i) {
    if ((i == 0)) {
      return;
    }
    Code03_TextEditor3::inorder(lc[i]);
    out.write(key[i]);
    Code03_TextEditor3::inorder(rc[i]);
  }
  static void java_main(Array<String> args) {
    (key = make_array<signed char>(1));
    (lc = make_array<int>(1));
    (rc = make_array<int>(1));
    (sz = make_array<int>(1));
    (priority = make_array<double>(1));
    int i = 0;
    int n = {};
    int l = {};
    int r = {};
    int lx = {};
    int mx = {};
    int rx = {};
    signed char c = {};
    int op = Code03_TextEditor3::nextInt();
    while (((op--) > 0)) {
      switch (Code03_TextEditor3::next()) {
      case u'M':
        (i = Code03_TextEditor3::nextInt());
        break;
      case u'I':
        Code03_TextEditor3::split(0, 0, head, i);
        (l = rc[0]);
        (r = lc[0]);
        (n = Code03_TextEditor3::nextInt());
        while ((n > 0)) {
          (c = Code03_TextEditor3::readByte());
          if ((c < 32)) {
            continue;
          }
          (l = Code03_TextEditor3::merge(l, Code03_TextEditor3::create(c)));
          (n--);
        }
        (head = Code03_TextEditor3::merge(l, r));
        break;
      case u'D':
        (n = Code03_TextEditor3::nextInt());
        (l = (i + 1));
        (r = (i + n));
        Code03_TextEditor3::split(0, 0, head, i);
        (lx = rc[0]);
        (mx = lc[0]);
        Code03_TextEditor3::split(0, 0, mx, n);
        (mx = rc[0]);
        (rx = lc[0]);
        (head = Code03_TextEditor3::merge(lx, rx));
        break;
      case u'G':
        (n = Code03_TextEditor3::nextInt());
        (l = (i + 1));
        (r = (i + n));
        Code03_TextEditor3::split(0, 0, head, i);
        (lx = rc[0]);
        (mx = lc[0]);
        Code03_TextEditor3::split(0, 0, mx, n);
        (mx = rc[0]);
        (rx = lc[0]);
        Code03_TextEditor3::inorder(mx);
        out.writeln();
        (head =
             Code03_TextEditor3::merge(Code03_TextEditor3::merge(lx, mx), rx));
        break;
      case u'P':
        (i--);
        break;
      default:
        (i++);
        break;
      }
    }
    out.flush();
  }
  static signed char readByte() {
    if ((ptrbuf == lenbuf)) {
      (ptrbuf = 0);
      try {
        (lenbuf = is.read(inbuf));
      } catch (Exception &e) {
      }
      if ((lenbuf <= 0))
        return (-1);
    }
    return inbuf[(ptrbuf++)];
  }
  static jchar next() {
    while (((b = Code03_TextEditor3::readByte()) < 33))
      ;
    int i = 0;
    while ((b > 32)) {
      (str[(i++)] = static_cast<jchar>(b));
      (b = Code03_TextEditor3::readByte());
    }
    return str[0];
  }
  static int nextInt() {
    while (((b = Code03_TextEditor3::readByte()) < 33))
      ;
    int num = (b - u'0');
    while (((b = Code03_TextEditor3::readByte()) > 32))
      (num = ((num * 10) + (b - u'0')));
    return num;
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code03_TextEditor3::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 文本编辑器，能通过的java版本
// 一开始文本为空，光标在文本开头，也就是1位置，请实现如下6种操作
// Move k     : 将光标移动到第k个字符之后，操作保证光标不会到非法位置
// Insert n s : 在光标处插入长度为n的字符串s，光标位置不变
// Delete n   : 删除光标后的n个字符，光标位置不变，操作保证有足够字符
// Get n      : 输出光标后的n个字符，光标位置不变，操作保证有足够字符
// Prev       : 光标前移一个字符，操作保证光标不会到非法位置
// Next       : 光标后移一个字符，操作保证光标不会到非法位置
//
Insert操作时，字符串s中ASCII码在[32,126]范围上的字符一定有n个，其他字符请过滤掉
// 测试链接 : https://www.luogu.com.cn/problem/P4008
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
// 一个能通过的版本，连数组都自己写扩容逻辑，IO彻底重写，看看就好
//
讲解172，讲解块状链表时，本题又讲了一遍，分块的方法，可以通过所有测试用例，更有学习意义
*/

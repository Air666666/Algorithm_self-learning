// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P4008

// Source: src/class172/Code06_TextEditor1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code06_TextEditor1 {
  inline static int MAXN = 3000001;
  inline static int BLEN = 3001;
  inline static int BNUM = jshl(jdiv(MAXN, BLEN), 1);
  inline static Array<Array<jchar>> space = make_array<jchar>(BNUM, BLEN);
  inline static Array<int> pool = make_array<int>(BNUM);
  inline static int top = 0;
  inline static Array<int> nxt = make_array<int>(BNUM);
  inline static Array<int> siz = make_array<int>(BNUM);
  inline static Array<jchar> str = make_array<jchar>(MAXN);
  inline static int bi = {};
  inline static int pi = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code06_TextEditor1() {}
  static void prepare() {
    {
      int i = 1;
      int id = (BNUM - 1);
      for (; (i < BNUM); (i++), (id--)) {
        (pool[i] = id);
      }
    }
    (top = (BNUM - 1));
    (siz[0] = 0);
    (nxt[0] = (-1));
  }
  static int assign() { return pool[(top--)]; }
  static void recycle(int id) { (pool[(++top)] = id); }
  static void find(int pos) {
    int curb = 0;
    while (((curb != (-1)) && (pos > siz[curb]))) {
      (pos -= siz[curb]);
      (curb = nxt[curb]);
    }
    (bi = curb);
    (pi = pos);
  }
  static void linkAndWrite(int curb, int nextb, Array<jchar> src, int pos,
                           int len) {
    (nxt[nextb] = nxt[curb]);
    (nxt[curb] = nextb);
    j::arraycopy(src, pos, space[nextb], 0, len);
    (siz[nextb] = len);
  }
  static void merge(int curb, int nextb) {
    j::arraycopy(space[nextb], 0, space[curb], siz[curb], siz[nextb]);
    (siz[curb] += siz[nextb]);
    (nxt[curb] = nxt[nextb]);
    Code06_TextEditor1::recycle(nextb);
  }
  static void split(int curb, int pos) {
    if (((curb == (-1)) || (pos == siz[curb]))) {
      return;
    }
    int nextb = Code06_TextEditor1::assign();
    Code06_TextEditor1::linkAndWrite(curb, nextb, space[curb], pos,
                                     (siz[curb] - pos));
    (siz[curb] = pos);
  }
  static void maintain() {
    {
      int curb = 0;
      int nextb = {};
      for (; (curb != (-1)); (curb = nxt[curb])) {
        (nextb = nxt[curb]);
        while (((nextb != (-1)) && ((siz[curb] + siz[nextb]) <= BLEN))) {
          Code06_TextEditor1::merge(curb, nextb);
          (nextb = nxt[curb]);
        }
      }
    }
  }
  static void insert(int pos, int len) {
    Code06_TextEditor1::find(pos);
    Code06_TextEditor1::split(bi, pi);
    int curb = bi;
    int newb = {};
    int done = 0;
    while (((done + BLEN) <= len)) {
      (newb = Code06_TextEditor1::assign());
      Code06_TextEditor1::linkAndWrite(curb, newb, str, done, BLEN);
      (done += BLEN);
      (curb = newb);
    }
    if ((len > done)) {
      (newb = Code06_TextEditor1::assign());
      Code06_TextEditor1::linkAndWrite(curb, newb, str, done, (len - done));
    }
    Code06_TextEditor1::maintain();
  }
  static void erase(int pos, int len) {
    Code06_TextEditor1::find(pos);
    Code06_TextEditor1::split(bi, pi);
    int curb = bi;
    int nextb = nxt[curb];
    while (((nextb != (-1)) && (len > siz[nextb]))) {
      (len -= siz[nextb]);
      Code06_TextEditor1::recycle(nextb);
      (nextb = nxt[nextb]);
    }
    if ((nextb != (-1))) {
      Code06_TextEditor1::split(nextb, len);
      Code06_TextEditor1::recycle(nextb);
      (nxt[curb] = nxt[nextb]);
    } else {
      (nxt[curb] = (-1));
    }
    Code06_TextEditor1::maintain();
  }
  static void get(int pos, int len) {
    Code06_TextEditor1::find(pos);
    int curb = bi;
    (pos = pi);
    int done = ((len < (siz[curb] - pos)) ? len : (siz[curb] - pos));
    j::arraycopy(space[curb], pos, str, 0, done);
    (curb = nxt[curb]);
    while (((curb != (-1)) && ((done + siz[curb]) <= len))) {
      j::arraycopy(space[curb], 0, str, done, siz[curb]);
      (done += siz[curb]);
      (curb = nxt[curb]);
    }
    if (((curb != (-1)) && (done < len))) {
      j::arraycopy(space[curb], 0, str, done, (len - done));
    }
  }
  static void java_main(Array<String> args) {
    TextEditorIO in;
    IO out = IO(IO(jout));
    int n = in.nextInt();
    int pos = 0;
    int len = {};
    String op = {};
    Code06_TextEditor1::prepare();
    for (int i = 1; (i <= n); (i++)) {
      (op = in.nextString());
      if (op.equals(String(u"Prev"))) {
        (pos--);
      } else if (op.equals(String(u"Next"))) {
        (pos++);
      } else if (op.equals(String(u"Move"))) {
        (pos = in.nextInt());
      } else if (op.equals(String(u"Insert"))) {
        (len = in.nextInt());
        for (int j = 0; (j < len); (j++)) {
          (str[j] = in.nextChar());
        }
        Code06_TextEditor1::insert(pos, len);
      } else if (op.equals(String(u"Delete"))) {
        (len = in.nextInt());
        Code06_TextEditor1::erase(pos, len);
      } else {
        (len = in.nextInt());
        Code06_TextEditor1::get(pos, len);
        out.write(str, 0, len);
        out.write(u'\n');
      }
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code06_TextEditor1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 文本编辑器，块状链表实现，java版
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
        // 整个文章能到达的最大长度
        // 块内容量，近似等于 2 * 根号n，每块内容大小不会超过容量
        // 块的数量上限
        // 写入内容的空间，编号为i的块，内容写入到space[i]
        // 编号分配池，其实是一个栈，分配编号从栈顶弹出，回收编号从栈顶压入
        // 分配池的栈顶
        // nxt[i]表示编号为i的块，下一块的编号
        // siz[i]表示编号为i的块，写入了多少长度的内容
        // 插入字符串时，先读入进str，然后写入到块
        // 获取字符串时，先从块里取出内容保留在str，然后打印str
        // 准备好分配池，从栈顶到栈底，依次是1、2、... BNUM - 1
        // 准备好头块的配置
        // 分配编号
        // 回收编号
        // 寻找整个文章中的pos位置
        // 找到所在块的编号 和 块内位置
        // 块编号设置给bi，块内位置设置给pi
        //
链表中让curb块和nextb块，连在一起，然后让nextb块从0位置开始，写入如下的内容
        // 从src[pos]开始，拿取长度为len的字符串
        // curb块里，在内容的后面，追加nextb块的内容，然后nextb块从链表中删掉
        // curb块的pos位置往后的内容，写入到新分裂出的块里
        // 从头到尾遍历所有的块，检查任意相邻块，内容大小的累加和 <=
块内容量，就合并
        // 插入的字符串在str中，长度为len，从整个文章的pos位置插入
        // 从整个文章的pos位置，往后len的长度，这些内容删掉
        // 从整个文章的pos位置，往后len的长度，这些内容找到，写入进str
        // 读写工具类
                // 读取下一个ASCII码范围在[32,126]的字符
*/

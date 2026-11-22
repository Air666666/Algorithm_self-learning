// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P3919

// Source: src/class157/Code01_PointPersistent1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_PointPersistent1 {
  struct FastIO;
  struct FastIO {
    IO is = {};
    IO os = {};
    Array<signed char> inbuf = make_array<signed char>(jshl(1, 16));
    int lenbuf = 0;
    int ptrbuf = 0;
    StringBuilder outBuf = StringBuilder();
    String toString() const { return j::str(static_cast<const void *>(this)); }
    FastIO(IO is, IO os) {
      (this->is = is);
      (this->os = os);
    }
    int readByte() {
      if ((ptrbuf >= lenbuf)) {
        (ptrbuf = 0);
        try {
          (lenbuf = is.read(inbuf));
        } catch (Exception &e) {
          throw Exception(e);
        }
        if ((lenbuf == (-1))) {
          return (-1);
        }
      }
      return (inbuf[(ptrbuf++)] & 0xff);
    }
    int skip() {
      int b = {};
      while (((b = FastIO::readByte()) != (-1))) {
        if ((b > u' ')) {
          return b;
        }
      }
      return (-1);
    }
    int nextInt() {
      int b = FastIO::skip();
      if ((b == (-1))) {
        throw Exception(String(u"No more integers (EOF)"));
      }
      bool negative = false;
      if ((b == u'-')) {
        (negative = true);
        (b = FastIO::readByte());
      }
      int val = 0;
      while (((b >= u'0') && (b <= u'9'))) {
        (val = ((val * 10) + (b - u'0')));
        (b = FastIO::readByte());
      }
      return (negative ? (-val) : val);
    }
    void write(String s) { outBuf.append(s); }
    void writeInt(int x) { outBuf.append(x); }
    void writelnInt(int x) { outBuf.append(x).append(u'\n'); }
    void flush() {
      try {
        os.write(outBuf.toString().getBytes());
        os.flush();
        outBuf.setLength(0);
      } catch (Exception &e) {
        throw Exception(e);
      }
    }
  };
  inline static int MAXN = 1000001;
  inline static int MAXT = (MAXN * 23);
  inline static int n = {};
  inline static int m = {};
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static Array<int> root = make_array<int>(MAXN);
  inline static Array<int> left = make_array<int>(MAXT);
  inline static Array<int> right = make_array<int>(MAXT);
  inline static Array<int> value = make_array<int>(MAXT);
  inline static int cnt = 0;
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_PointPersistent1() {}
  static int build(int l, int r) {
    int rt = (++cnt);
    if ((l == r)) {
      (value[rt] = arr[l]);
    } else {
      int mid = jshr((l + r), 1);
      (left[rt] = Code01_PointPersistent1::build(l, mid));
      (right[rt] = Code01_PointPersistent1::build((mid + 1), r));
    }
    return rt;
  }
  static int update(int jobi, int jobv, int l, int r, int i) {
    int rt = (++cnt);
    (left[rt] = left[i]);
    (right[rt] = right[i]);
    (value[rt] = value[i]);
    if ((l == r)) {
      (value[rt] = jobv);
    } else {
      int mid = jshr((l + r), 1);
      if ((jobi <= mid)) {
        (left[rt] =
             Code01_PointPersistent1::update(jobi, jobv, l, mid, left[rt]));
      } else {
        (right[rt] = Code01_PointPersistent1::update(jobi, jobv, (mid + 1), r,
                                                     right[rt]));
      }
    }
    return rt;
  }
  static int query(int jobi, int l, int r, int i) {
    if ((l == r)) {
      return value[i];
    }
    int mid = jshr((l + r), 1);
    if ((jobi <= mid)) {
      return Code01_PointPersistent1::query(jobi, l, mid, left[i]);
    } else {
      return Code01_PointPersistent1::query(jobi, (mid + 1), r, right[i]);
    }
  }
  static void java_main(Array<String> args) {
    FastIO *io = new FastIO(jin, jout);
    (n = io->nextInt());
    (m = io->nextInt());
    for (int i = 1; (i <= n); (i++)) {
      (arr[i] = io->nextInt());
    }
    (root[0] = Code01_PointPersistent1::build(1, n));
    {
      int i = 1;
      int version = {};
      int op = {};
      int x = {};
      int y = {};
      for (; (i <= m); (i++)) {
        (version = io->nextInt());
        (op = io->nextInt());
        (x = io->nextInt());
        if ((op == 1)) {
          (y = io->nextInt());
          (root[i] =
               Code01_PointPersistent1::update(x, y, 1, n, root[version]));
        } else {
          (root[i] = root[version]);
          io->writelnInt(Code01_PointPersistent1::query(x, 1, n, root[i]));
        }
      }
    }
    io->flush();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code01_PointPersistent1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 单点修改的可持久化线段树模版题1，java版
// 给定一个长度为n的数组arr，下标1~n，原始数组认为是0号版本
// 一共有m条操作，每条操作是如下两种类型中的一种
// v 1 x y : 基于v号版本的数组，把x位置的值设置成y，生成新版本的数组
// v 2 x   : 基于v号版本的数组，打印x位置的值，生成新版本的数组和v版本一致
// 每条操作后得到的新版本数组，版本编号为操作的计数
// 1 <= n, m <= 10^6
// 测试链接 : https://www.luogu.com.cn/problem/P3919
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 原始数组
        // 可持久化线段树需要
        // root[i] : i号版本线段树的头节点编号
        // value[i] : 节点i的值信息，只有叶节点有这个信息
        // 可持久化线段树的节点空间计数
        // 建树，返回头节点编号
        // 线段树范围l~r，信息在i号节点里
        // 在l~r范围上，jobi位置的值，设置成jobv
        // 生成的新节点编号返回
        // 线段树范围l~r，信息在i号节点里
        // 返回l~r范围上jobi位置的值
        // 读写工具类
*/

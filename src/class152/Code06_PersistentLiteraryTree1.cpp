// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P5055

// Source: src/class152/Code06_PersistentLiteraryTree1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code06_PersistentLiteraryTree1 {
  inline static int MAXN = 200001;
  inline static int MAXM = (MAXN * 100);
  inline static int cnt = 0;
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> key = make_array<int>(MAXM);
  inline static Array<int> left = make_array<int>(MAXM);
  inline static Array<int> right = make_array<int>(MAXM);
  inline static Array<int> size = make_array<int>(MAXM);
  inline static Array<bool> reverse = make_array<bool>(MAXM);
  inline static Array<i64> sum = make_array<i64>(MAXM);
  inline static Array<double> priority = make_array<double>(MAXM);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code06_PersistentLiteraryTree1() {}
  static int copy(int i) {
    (key[(++cnt)] = key[i]);
    (left[cnt] = left[i]);
    (right[cnt] = right[i]);
    (size[cnt] = size[i]);
    (reverse[cnt] = reverse[i]);
    (sum[cnt] = sum[i]);
    (priority[cnt] = priority[i]);
    return cnt;
  }
  static void up(int i) {
    (size[i] = ((size[left[i]] + size[right[i]]) + 1));
    (sum[i] = ((sum[left[i]] + sum[right[i]]) + key[i]));
  }
  static void down(int i) {
    if (reverse[i]) {
      if ((left[i] != 0)) {
        (left[i] = Code06_PersistentLiteraryTree1::copy(left[i]));
        (reverse[left[i]] = (!reverse[left[i]]));
      }
      if ((right[i] != 0)) {
        (right[i] = Code06_PersistentLiteraryTree1::copy(right[i]));
        (reverse[right[i]] = (!reverse[right[i]]));
      }
      int tmp = left[i];
      (left[i] = right[i]);
      (right[i] = tmp);
      (reverse[i] = false);
    }
  }
  static void split(int l, int r, int i, int rank) {
    if ((i == 0)) {
      (right[l] = (left[r] = 0));
    } else {
      (i = Code06_PersistentLiteraryTree1::copy(i));
      Code06_PersistentLiteraryTree1::down(i);
      if (((size[left[i]] + 1) <= rank)) {
        (right[l] = i);
        Code06_PersistentLiteraryTree1::split(i, r, right[i],
                                              ((rank - size[left[i]]) - 1));
      } else {
        (left[r] = i);
        Code06_PersistentLiteraryTree1::split(l, i, left[i], rank);
      }
      Code06_PersistentLiteraryTree1::up(i);
    }
  }
  static int merge(int l, int r) {
    if (((l == 0) || (r == 0))) {
      return (l + r);
    }
    if ((priority[l] >= priority[r])) {
      (l = Code06_PersistentLiteraryTree1::copy(l));
      Code06_PersistentLiteraryTree1::down(l);
      (right[l] = Code06_PersistentLiteraryTree1::merge(right[l], r));
      Code06_PersistentLiteraryTree1::up(l);
      return l;
    } else {
      (r = Code06_PersistentLiteraryTree1::copy(r));
      Code06_PersistentLiteraryTree1::down(r);
      (left[r] = Code06_PersistentLiteraryTree1::merge(l, left[r]));
      Code06_PersistentLiteraryTree1::up(r);
      return r;
    }
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    int n = static_cast<int>(in.nval);
    i64 lastAns = 0;
    {
      int i = 1;
      int version = {};
      int op = {};
      int x = 0;
      int y = 0;
      int l = {};
      int m = {};
      int lm = {};
      int r = {};
      for (; (i <= n); (i++)) {
        in.nextToken();
        (version = static_cast<int>(in.nval));
        in.nextToken();
        (op = static_cast<int>(in.nval));
        in.nextToken();
        (x = static_cast<int>((static_cast<i64>(in.nval) ^ lastAns)));
        if ((op != 2)) {
          in.nextToken();
          (y = static_cast<int>((static_cast<i64>(in.nval) ^ lastAns)));
        }
        if ((op == 1)) {
          Code06_PersistentLiteraryTree1::split(0, 0, head[version], x);
          (l = right[0]);
          (r = left[0]);
          (left[0] = (right[0] = 0));
          (key[(++cnt)] = static_cast<int>(y));
          (size[cnt] = 1);
          (sum[cnt] = y);
          (priority[cnt] = j::random());
          (head[i] = Code06_PersistentLiteraryTree1::merge(
               Code06_PersistentLiteraryTree1::merge(l, cnt), r));
        } else if ((op == 2)) {
          Code06_PersistentLiteraryTree1::split(0, 0, head[version], x);
          (lm = right[0]);
          (r = left[0]);
          Code06_PersistentLiteraryTree1::split(0, 0, lm, (x - 1));
          (l = right[0]);
          (m = left[0]);
          (left[0] = (right[0] = 0));
          (head[i] = Code06_PersistentLiteraryTree1::merge(l, r));
        } else if ((op == 3)) {
          Code06_PersistentLiteraryTree1::split(0, 0, head[version], y);
          (lm = right[0]);
          (r = left[0]);
          Code06_PersistentLiteraryTree1::split(0, 0, lm, (x - 1));
          (l = right[0]);
          (m = left[0]);
          (left[0] = (right[0] = 0));
          (reverse[m] = (!reverse[m]));
          (head[i] = Code06_PersistentLiteraryTree1::merge(
               Code06_PersistentLiteraryTree1::merge(l, m), r));
        } else {
          Code06_PersistentLiteraryTree1::split(0, 0, head[version], y);
          (lm = right[0]);
          (r = left[0]);
          Code06_PersistentLiteraryTree1::split(0, 0, lm, (x - 1));
          (l = right[0]);
          (m = left[0]);
          (left[0] = (right[0] = 0));
          (lastAns = sum[m]);
          out.println(lastAns);
          (head[i] = Code06_PersistentLiteraryTree1::merge(
               Code06_PersistentLiteraryTree1::merge(l, m), r));
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
  Code06_PersistentLiteraryTree1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 可持久化文艺平衡树，FHQ-Treap实现，java版
// 一开始序列为空，实现如下操作，操作一共发生n次
// v 1 x y : 基于v版本的序列，在第x个数后插入y，生成新版本的序列
// v 2 x   : 基于v版本的序列，删除第x个数，生成新版本的序列
// v 3 x y : 基于v版本的序列，范围[x,y]所有数字翻转，生成新版本的序列
// v 4 x y :
基于v版本的序列，查询范围[x,y]所有数字的和，生成新版本的序列状况=v版本状况
// 不管什么操作，都基于某个v版本，操作完成后得到新版本的序列，但v版本不会变化
// 每种操作给定的参数都是有效的，插入数字的范围[-10^6, +10^6]
// 1 <= n <= 2 * 10^5
// 本题目要求强制在线，具体规则可以打开测试链接查看
// 测试链接 : https://www.luogu.com.cn/problem/P5055
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
*/

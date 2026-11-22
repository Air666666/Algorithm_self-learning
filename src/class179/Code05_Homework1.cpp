// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P4396

// Source: src/class179/Code05_Homework1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code05_Homework1 {
  struct QueryCmp;
  struct QueryCmp {
    String toString() const { return j::str(static_cast<const void *>(this)); }
    QueryCmp() {}
    int compare(Array<int> a, Array<int> b) {
      if ((bi[a[0]] != bi[b[0]])) {
        return (bi[a[0]] - bi[b[0]]);
      }
      if (((bi[a[0]] & 1) == 1)) {
        return (a[1] - b[1]);
      } else {
        return (b[1] - a[1]);
      }
    }
  };
  inline static int MAXN = 100001;
  inline static int MAXV = 100000;
  inline static int MAXB = 401;
  inline static int n = {};
  inline static int m = {};
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static Array<Array<int>> query = make_array<int>(MAXN, 5);
  inline static Array<int> bi = make_array<int>(MAXN);
  inline static Array<int> bl = make_array<int>(MAXB);
  inline static Array<int> br = make_array<int>(MAXB);
  inline static Array<int> numCnt = make_array<int>(MAXN);
  inline static Array<int> blockCnt = make_array<int>(MAXB);
  inline static Array<int> blockKind = make_array<int>(MAXB);
  inline static Array<int> ans1 = make_array<int>(MAXN);
  inline static Array<int> ans2 = make_array<int>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code05_Homework1() {}
  static void add(int x) {
    (numCnt[x]++);
    (blockCnt[bi[x]]++);
    if ((numCnt[x] == 1)) {
      (blockKind[bi[x]]++);
    }
  }
  static void del(int x) {
    (numCnt[x]--);
    (blockCnt[bi[x]]--);
    if ((numCnt[x] == 0)) {
      (blockKind[bi[x]]--);
    }
  }
  static void setAns(int a, int b, int id) {
    if ((bi[a] == bi[b])) {
      for (int i = a; (i <= b); (i++)) {
        if ((numCnt[i] > 0)) {
          (ans1[id] += numCnt[i]);
          (ans2[id]++);
        }
      }
    } else {
      for (int i = a; (i <= br[bi[a]]); (i++)) {
        if ((numCnt[i] > 0)) {
          (ans1[id] += numCnt[i]);
          (ans2[id]++);
        }
      }
      for (int i = bl[bi[b]]; (i <= b); (i++)) {
        if ((numCnt[i] > 0)) {
          (ans1[id] += numCnt[i]);
          (ans2[id]++);
        }
      }
      for (int i = (bi[a] + 1); (i <= (bi[b] - 1)); (i++)) {
        (ans1[id] += blockCnt[i]);
        (ans2[id] += blockKind[i]);
      }
    }
  }
  static void compute() {
    int winl = 1;
    int winr = 0;
    for (int i = 1; (i <= m); (i++)) {
      int jobl = query[i][0];
      int jobr = query[i][1];
      int joba = query[i][2];
      int jobb = query[i][3];
      int id = query[i][4];
      while ((winl > jobl)) {
        Code05_Homework1::add(arr[(--winl)]);
      }
      while ((winr < jobr)) {
        Code05_Homework1::add(arr[(++winr)]);
      }
      while ((winl < jobl)) {
        Code05_Homework1::del(arr[(winl++)]);
      }
      while ((winr > jobr)) {
        Code05_Homework1::del(arr[(winr--)]);
      }
      Code05_Homework1::setAns(joba, jobb, id);
    }
  }
  static void prepare() {
    int blen = static_cast<int>(std::sqrt(MAXV));
    int bnum = jdiv(((MAXV + blen) - 1), blen);
    for (int i = 1; (i <= MAXV); (i++)) {
      (bi[i] = (jdiv((i - 1), blen) + 1));
    }
    for (int i = 1; (i <= bnum); (i++)) {
      (bl[i] = (((i - 1) * blen) + 1));
      (br[i] = jmin((i * blen), MAXV));
    }
    j::sort(query, 1, (m + 1), new QueryCmp());
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
      (query[i][0] = in.nextInt());
      (query[i][1] = in.nextInt());
      (query[i][2] = in.nextInt());
      (query[i][3] = in.nextInt());
      (query[i][4] = i);
    }
    Code05_Homework1::prepare();
    Code05_Homework1::compute();
    for (int i = 1; (i <= m); (i++)) {
      out.println(((ans1[i] + String(u" ")) + ans2[i]));
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code05_Homework1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 作业，java版
// 给定一个长度为n的数组arr，接下来有m条查询，格式如下
// 查询 l r a b : 打印arr[l..r]范围上的两个答案
//                答案1，数值范围在[a, b]的数字个数
//                答案2，数值范围在[a, b]的数字种数
// 1 <= 所有数据 <= 10^5
// 测试链接 : https://www.luogu.com.cn/problem/P4396
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 查询任务，l、r、a、b、id
        // 读写工具类
*/

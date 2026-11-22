// Source: src/class176/Code06_MoWithModify1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code06_MoWithModify1 {
  struct QueryCmp;
  struct QueryCmp {
    String toString() const { return j::str(static_cast<const void *>(this)); }
    QueryCmp() {}
    int compare(Array<int> a, Array<int> b) {
      if ((bi[a[0]] != bi[b[0]])) {
        return (bi[a[0]] - bi[b[0]]);
      }
      if ((bi[a[1]] != bi[b[1]])) {
        return (bi[a[1]] - bi[b[1]]);
      }
      return (a[2] - b[2]);
    }
  };
  inline static int MAXN = 200001;
  inline static int MAXV = 1000001;
  inline static int n = {};
  inline static int m = {};
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static Array<int> bi = make_array<int>(MAXN);
  inline static Array<Array<int>> query = make_array<int>(MAXN, 4);
  inline static Array<Array<int>> update = make_array<int>(MAXN, 2);
  inline static int cntq = {};
  inline static int cntu = {};
  inline static Array<int> cnt = make_array<int>(MAXV);
  inline static int kind = {};
  inline static Array<int> ans = make_array<int>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code06_MoWithModify1() {}
  static void del(int num) {
    if (((--cnt[num]) == 0)) {
      (kind--);
    }
  }
  static void add(int num) {
    if (((++cnt[num]) == 1)) {
      (kind++);
    }
  }
  static void moveTime(int jobl, int jobr, int tim) {
    int pos = update[tim][0];
    int val = update[tim][1];
    if (((jobl <= pos) && (pos <= jobr))) {
      Code06_MoWithModify1::del(arr[pos]);
      Code06_MoWithModify1::add(val);
    }
    int tmp = arr[pos];
    (arr[pos] = val);
    (update[tim][1] = tmp);
  }
  static void compute() {
    int winl = 1;
    int winr = 0;
    int wint = 0;
    for (int i = 1; (i <= cntq); (i++)) {
      int jobl = query[i][0];
      int jobr = query[i][1];
      int jobt = query[i][2];
      int id = query[i][3];
      while ((winl > jobl)) {
        Code06_MoWithModify1::add(arr[(--winl)]);
      }
      while ((winr < jobr)) {
        Code06_MoWithModify1::add(arr[(++winr)]);
      }
      while ((winl < jobl)) {
        Code06_MoWithModify1::del(arr[(winl++)]);
      }
      while ((winr > jobr)) {
        Code06_MoWithModify1::del(arr[(winr--)]);
      }
      while ((wint < jobt)) {
        Code06_MoWithModify1::moveTime(jobl, jobr, (++wint));
      }
      while ((wint > jobt)) {
        Code06_MoWithModify1::moveTime(jobl, jobr, (wint--));
      }
      (ans[id] = kind);
    }
  }
  static void prepare() {
    int blen = jmax(1, static_cast<int>(std::pow(n, jdiv(2.0, 3))));
    for (int i = 1; (i <= n); (i++)) {
      (bi[i] = (jdiv((i - 1), blen) + 1));
    }
    j::sort(query, 1, (cntq + 1), new QueryCmp());
  }
  static void java_main(Array<String> args) {
    IO in = IO();
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (m = in.nextInt());
    for (int i = 1; (i <= n); (i++)) {
      (arr[i] = in.nextInt());
    }
    jchar op = {};
    int l = {};
    int r = {};
    int pos = {};
    int val = {};
    for (int i = 1; (i <= m); (i++)) {
      (op = in.nextChar());
      if ((op == u'Q')) {
        (l = in.nextInt());
        (r = in.nextInt());
        (cntq++);
        (query[cntq][0] = l);
        (query[cntq][1] = r);
        (query[cntq][2] = cntu);
        (query[cntq][3] = cntq);
      } else {
        (pos = in.nextInt());
        (val = in.nextInt());
        (cntu++);
        (update[cntu][0] = pos);
        (update[cntu][1] = val);
      }
    }
    Code06_MoWithModify1::prepare();
    Code06_MoWithModify1::compute();
    for (int i = 1; (i <= cntq); (i++)) {
      out.println(ans[i]);
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code06_MoWithModify1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 带修莫队入门题，java版
// 给定一个长度为n的数组arr，一共有m条操作，操作格式如下
// 操作 Q l r     : 打印arr[l..r]范围上有几种不同的数
// 操作 R pos val : 把arr[pos]的值设置成val
// 1 <= n、m <= 2 * 10^5
// 1 <= arr[i]、val <= 10^6
// 测试链接 : https://www.luogu.com.cn/problem/P1903
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 每条查询 : jobl、jobr、jobt、id
        // 每条修改 : pos、val
        // 带修莫队的任务排序
        // jobl..jobr 数组范围
        // tim : 生效或者撤销的修改时间点
                // 不管生效还是撤销，数据只要在arr和update之间交换即可
        // 读写工具类
*/

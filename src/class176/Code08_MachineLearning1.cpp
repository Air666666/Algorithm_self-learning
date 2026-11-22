// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/CF940F
// https://codeforces.com/problemset/problem/940/F

// Source: src/class176/Code08_MachineLearning1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code08_MachineLearning1 {
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
  inline static int MAXN = 100001;
  inline static int n = {};
  inline static int m = {};
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static Array<int> sorted = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> bi = make_array<int>(MAXN);
  inline static Array<Array<int>> query = make_array<int>(MAXN, 4);
  inline static Array<Array<int>> update = make_array<int>(MAXN, 2);
  inline static int cntq = {};
  inline static int cntu = {};
  inline static Array<int> cnt1 = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> cnt2 = make_array<int>(MAXN);
  inline static Array<int> ans = make_array<int>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code08_MachineLearning1() {}
  static int kth(int len, int num) {
    int left = 1;
    int right = len;
    int mid = {};
    int ret = 0;
    while ((left <= right)) {
      (mid = jshr((left + right), 1));
      if ((sorted[mid] <= num)) {
        (ret = mid);
        (left = (mid + 1));
      } else {
        (right = (mid - 1));
      }
    }
    return ret;
  }
  static void del(int num) {
    (cnt2[cnt1[num]]--);
    (cnt1[num]--);
    (cnt2[cnt1[num]]++);
  }
  static void add(int num) {
    (cnt2[cnt1[num]]--);
    (cnt1[num]++);
    (cnt2[cnt1[num]]++);
  }
  static void moveTime(int jobl, int jobr, int tim) {
    int pos = update[tim][0];
    int val = update[tim][1];
    if (((jobl <= pos) && (pos <= jobr))) {
      Code08_MachineLearning1::del(arr[pos]);
      Code08_MachineLearning1::add(val);
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
        Code08_MachineLearning1::add(arr[(--winl)]);
      }
      while ((winr < jobr)) {
        Code08_MachineLearning1::add(arr[(++winr)]);
      }
      while ((winl < jobl)) {
        Code08_MachineLearning1::del(arr[(winl++)]);
      }
      while ((winr > jobr)) {
        Code08_MachineLearning1::del(arr[(winr--)]);
      }
      while ((wint < jobt)) {
        Code08_MachineLearning1::moveTime(jobl, jobr, (++wint));
      }
      while ((wint > jobt)) {
        Code08_MachineLearning1::moveTime(jobl, jobr, (wint--));
      }
      int ret = 1;
      while (((ret <= n) && (cnt2[ret] > 0))) {
        (ret++);
      }
      (ans[id] = ret);
    }
  }
  static void prepare() {
    int len = 0;
    for (int i = 1; (i <= n); (i++)) {
      (sorted[(++len)] = arr[i]);
    }
    for (int i = 1; (i <= cntu); (i++)) {
      (sorted[(++len)] = update[i][1]);
    }
    j::sort(sorted, 1, (len + 1));
    int tmp = 1;
    for (int i = 2; (i <= len); (i++)) {
      if ((sorted[tmp] != sorted[i])) {
        (sorted[(++tmp)] = sorted[i]);
      }
    }
    (len = tmp);
    for (int i = 1; (i <= n); (i++)) {
      (arr[i] = Code08_MachineLearning1::kth(len, arr[i]));
    }
    for (int i = 1; (i <= cntu); (i++)) {
      (update[i][1] = Code08_MachineLearning1::kth(len, update[i][1]));
    }
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
    {
      int i = 1;
      int op = {};
      int l = {};
      int r = {};
      int pos = {};
      int val = {};
      for (; (i <= m); (i++)) {
        (op = in.nextInt());
        if ((op == 1)) {
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
    }
    Code08_MachineLearning1::prepare();
    Code08_MachineLearning1::compute();
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
  Code08_MachineLearning1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 机器学习，java版
// 给定一个长度为n的数组arr，一共有m条操作，操作格式如下
// 操作 1 l r     : arr[l..r]范围上，每种数字出现的次数，假设构成一个集合
//                  打印这个集合中，没出现过的最小正数
// 操作 2 pos val : 把arr[pos]的值设置成val
// 1 <= n、m <= 10^5
// 1 <= arr[i]、val <= 10^9
// 测试链接 : https://www.luogu.com.cn/problem/CF940F
// 测试链接 : https://codeforces.com/problemset/problem/940/F
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // cnt1[i] = j，表示i这种数出现了j次
        // cnt2[i] = j，表示出现次数为i的数有j种
                        // 如下枚举看似暴力，其实O(根号n)的复杂度
        // 读写工具类
*/

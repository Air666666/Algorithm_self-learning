// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P8078

// Source: src/class177/Code06_BaldChief1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code06_BaldChief1 {
  struct QueryCmp;
  struct QueryCmp {
    String toString() const { return j::str(static_cast<const void *>(this)); }
    QueryCmp() {}
    int compare(Array<int> a, Array<int> b) {
      if ((bi[a[0]] != bi[b[0]])) {
        return (bi[a[0]] - bi[b[0]]);
      }
      return (b[1] - a[1]);
    }
  };
  inline static int MAXN = 500001;
  inline static int n = {};
  inline static int m = {};
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static Array<Array<int>> query = make_array<int>(MAXN, 3);
  inline static Array<int> pos = make_array<int>(MAXN);
  inline static int blen = {};
  inline static int bnum = {};
  inline static Array<int> bi = make_array<int>(MAXN);
  inline static Array<int> bl = make_array<int>(MAXN);
  inline static Array<int> last = make_array<int>((MAXN + 1));
  inline static Array<int> next = make_array<int>((MAXN + 1));
  inline static i64 sum = {};
  inline static Array<i64> ans = make_array<i64>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code06_BaldChief1() {}
  static void del(int num) {
    int less = last[num];
    int more = next[num];
    if ((less != 0)) {
      (sum -= std::abs((pos[num] - pos[less])));
    }
    if ((more != (n + 1))) {
      (sum -= std::abs((pos[more] - pos[num])));
    }
    if (((less != 0) && (more != (n + 1)))) {
      (sum += std::abs((pos[more] - pos[less])));
    }
    (next[less] = more);
    (last[more] = less);
  }
  static void add(int num) {
    (next[last[num]] = num);
    (last[next[num]] = num);
  }
  static void compute() {
    for (int v = 1; (v <= n); (v++)) {
      (last[v] = (v - 1));
      (next[v] = (v + 1));
    }
    (next[0] = 1);
    (last[(n + 1)] = n);
    for (int v = 2; (v <= n); (v++)) {
      (sum += std::abs((pos[v] - pos[(v - 1)])));
    }
    int winl = 1;
    int winr = n;
    {
      int block = 1;
      int qi = 1;
      for (; ((block <= bnum) && (qi <= m)); (block++)) {
        while ((winl < bl[block])) {
          Code06_BaldChief1::del(arr[(winl++)]);
        }
        i64 beforeJob = sum;
        for (; ((qi <= m) && (bi[query[qi][0]] == block)); (qi++)) {
          int jobl = query[qi][0];
          int jobr = query[qi][1];
          int id = query[qi][2];
          while ((winr > jobr)) {
            Code06_BaldChief1::del(arr[(winr--)]);
          }
          i64 backup = sum;
          while ((winl < jobl)) {
            Code06_BaldChief1::del(arr[(winl++)]);
          }
          (ans[id] = sum);
          (sum = backup);
          while ((winl > bl[block])) {
            Code06_BaldChief1::add(arr[(--winl)]);
          }
        }
        while ((winr < n)) {
          Code06_BaldChief1::add(arr[(++winr)]);
        }
        (sum = beforeJob);
      }
    }
  }
  static void prepare() {
    for (int i = 1; (i <= n); (i++)) {
      (pos[arr[i]] = i);
    }
    (blen = static_cast<int>(std::sqrt(n)));
    (bnum = jdiv(((n + blen) - 1), blen));
    for (int i = 1; (i <= n); (i++)) {
      (bi[i] = (jdiv((i - 1), blen) + 1));
    }
    for (int i = 1; (i <= bnum); (i++)) {
      (bl[i] = (((i - 1) * blen) + 1));
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
      (query[i][2] = i);
    }
    Code06_BaldChief1::prepare();
    Code06_BaldChief1::compute();
    for (int i = 1; (i <= m); (i++)) {
      out.println(ans[i]);
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code06_BaldChief1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 秃子酋长，java版
// 给定一个长度为n的数组arr，一共有m条查询，格式如下
// 查询 l r : 打印arr[l..r]范围上，如果所有数排序后，
//            相邻的数在原序列中的位置的差的绝对值之和
// 注意arr很特殊，1~n这些数字在arr中都只出现1次
// 1 <= n、m <= 5 * 10^5
// 测试链接 : https://www.luogu.com.cn/problem/P8078
// 提交以下的code，提交时请把类名改成"Main"
// java实现的逻辑一定是正确的，但是本题卡常，无法通过所有测试用例
// 想通过用C++实现，本节课Code06_BaldChief2文件就是C++的实现
// 两个版本的逻辑完全一样，C++版本可以通过所有测试
        // 加数字的顺序，就是删数字顺序的回滚，才能这么方便的更新
        // 读写工具类
*/

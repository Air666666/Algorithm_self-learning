// Source: src/class111/Code05_Posters2.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code05_Posters2 {
  inline static int MAXN = 10001;
  inline static Array<int> pl = make_array<int>(MAXN);
  inline static Array<int> pr = make_array<int>(MAXN);
  inline static Array<int> num = make_array<int>(jshl(MAXN, 2));
  inline static Array<int> poster = make_array<int>(jshl(MAXN, 4));
  inline static Array<bool> visited = make_array<bool>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code05_Posters2() {}
  static int collect(int m) {
    j::sort(num, 1, (m + 1));
    int size = 1;
    for (int i = 2; (i <= m); (i++)) {
      if ((num[size] != num[i])) {
        (num[(++size)] = num[i]);
      }
    }
    int cnt = size;
    for (int i = 2; (i <= size); (i++)) {
      if (((num[(i - 1)] + 1) < num[i])) {
        (num[(++cnt)] = (num[(i - 1)] + 1));
      }
    }
    j::sort(num, 1, (cnt + 1));
    return cnt;
  }
  static int rank(int l, int r, int v) {
    int m = {};
    int ans = 0;
    while ((l <= r)) {
      (m = jshr((l + r), 1));
      if ((num[m] >= v)) {
        (ans = m);
        (r = (m - 1));
      } else {
        (l = (m + 1));
      }
    }
    return ans;
  }
  static void down(int i) {
    if ((poster[i] != 0)) {
      (poster[jshl(i, 1)] = poster[i]);
      (poster[(jshl(i, 1) | 1)] = poster[i]);
      (poster[i] = 0);
    }
  }
  static void build(int l, int r, int i) {
    if ((l < r)) {
      int mid = jshr((l + r), 1);
      Code05_Posters2::build(l, mid, jshl(i, 1));
      Code05_Posters2::build((mid + 1), r, (jshl(i, 1) | 1));
    }
    (poster[i] = 0);
  }
  static void update(int jobl, int jobr, int jobv, int l, int r, int i) {
    if (((jobl <= l) && (r <= jobr))) {
      (poster[i] = jobv);
    } else {
      Code05_Posters2::down(i);
      int mid = jshr((l + r), 1);
      if ((jobl <= mid)) {
        Code05_Posters2::update(jobl, jobr, jobv, l, mid, jshl(i, 1));
      }
      if ((jobr > mid)) {
        Code05_Posters2::update(jobl, jobr, jobv, (mid + 1), r,
                                (jshl(i, 1) | 1));
      }
    }
  }
  static int query(int jobl, int jobr, int l, int r, int i) {
    if ((l == r)) {
      if (((poster[i] != 0) && (!visited[poster[i]]))) {
        (visited[poster[i]] = true);
        return 1;
      } else {
        return 0;
      }
    } else {
      Code05_Posters2::down(i);
      int mid = jshr((l + r), 1);
      int ans = 0;
      if ((jobl <= mid)) {
        (ans += Code05_Posters2::query(jobl, jobr, l, mid, jshl(i, 1)));
      }
      if ((jobr > mid)) {
        (ans +=
         Code05_Posters2::query(jobl, jobr, (mid + 1), r, (jshl(i, 1) | 1)));
      }
      return ans;
    }
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    int cases = static_cast<int>(in.nval);
    for (int t = 1; (t <= cases); (t++)) {
      in.nextToken();
      int n = static_cast<int>(in.nval);
      int m = 0;
      for (int i = 1; (i <= n); (i++)) {
        in.nextToken();
        (pl[i] = static_cast<int>(in.nval));
        in.nextToken();
        (pr[i] = static_cast<int>(in.nval));
        (num[(++m)] = pl[i]);
        (num[(++m)] = pr[i]);
      }
      (m = Code05_Posters2::collect(m));
      Code05_Posters2::build(1, m, 1);
      {
        int i = 1;
        int jobl = {};
        int jobr = {};
        for (; (i <= n); (i++)) {
          (jobl = Code05_Posters2::rank(1, m, pl[i]));
          (jobr = Code05_Posters2::rank(1, m, pr[i]));
          Code05_Posters2::update(jobl, jobr, i, 1, m, 1);
        }
      }
      out.println(Code05_Posters2::query(1, m, 1, m, 1));
      j::fill(visited, 1, (n + 1), false);
    }
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code05_Posters2::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 贴海报(数据加强版)
// 有一面墙，有固定高度，无限的宽度，有n张海报，所有海报的高度都和墙的高度相同
// 从第1张海报开始，一张一张往墙上贴，直到n张海报贴完
// 每张海报都给出张贴位置(xi, yi)，表示第i张海报从墙的左边界xi一直延伸到右边界yi
// 有可能发生后面的海报把前面的海报完全覆盖，导致看不到的情况
// 当所有海报贴完，返回能看到海报的数量，哪怕只漏出一点的海报都算
// 1 <= n <= 10^5，1 <= xi、yi <= 10^7
// 测试链接 : http://poj.org/problem?id=2528
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下的code，提交时请把类名改成"Main"，可以直接通过
        // 线段树的某个范围上是否被设置成了统一的海报
        // 如果poster[i] != 0，poster[i]表示统一海报的编号
        // 如果poster[i] == 0，表示该范围上没有海报或者海报编号没统一
        // 某种海报编号是否已经被统计过了
        // 只在最后一次查询，最后统计海报数量的阶段时候使用
*/

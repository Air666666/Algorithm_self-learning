// Source: src/class131/Code06_StationLocation.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code06_StationLocation {
  inline static int n = {};
  inline static int k = {};
  inline static int MAXN = 20002;
  inline static Array<int> dist = make_array<int>(MAXN);
  inline static Array<int> fix = make_array<int>(MAXN);
  inline static Array<int> range = make_array<int>(MAXN);
  inline static Array<int> warranty = make_array<int>(MAXN);
  inline static Array<int> left = make_array<int>(MAXN);
  inline static Array<int> right = make_array<int>(MAXN);
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> next = make_array<int>(MAXN);
  inline static Array<int> to = make_array<int>(MAXN);
  inline static int cnt = {};
  inline static Array<int> min = make_array<int>(jshl(MAXN, 2));
  inline static Array<int> add = make_array<int>(jshl(MAXN, 2));
  inline static Array<int> dp = make_array<int>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code06_StationLocation() {}
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    (n = static_cast<int>(in.nval));
    in.nextToken();
    (k = static_cast<int>(in.nval));
    for (int i = 2; (i <= n); (i++)) {
      in.nextToken();
      (dist[i] = static_cast<int>(in.nval));
    }
    for (int i = 1; (i <= n); (i++)) {
      in.nextToken();
      (fix[i] = static_cast<int>(in.nval));
    }
    for (int i = 1; (i <= n); (i++)) {
      in.nextToken();
      (range[i] = static_cast<int>(in.nval));
    }
    for (int i = 1; (i <= n); (i++)) {
      in.nextToken();
      (warranty[i] = static_cast<int>(in.nval));
    }
    (dist[(++n)] = std::numeric_limits<int>::max());
    (fix[n] = (range[n] = (warranty[n] = 0)));
    Code06_StationLocation::prepare();
    out.println(Code06_StationLocation::compute());
    out.flush();
    out.close();
    br.close();
  }
  static int compute() {
    {
      int i = 1;
      int w = 0;
      for (; (i <= n); (i++)) {
        (dp[i] = (w + fix[i]));
        for (int ei = head[i]; (ei != 0); (ei = next[ei])) {
          (w += warranty[to[ei]]);
        }
      }
    }
    for (int t = 2; (t <= (k + 1)); (t++)) {
      Code06_StationLocation::build(1, n, 1);
      for (int i = 1; (i <= n); (i++)) {
        if ((i >= t)) {
          (dp[i] =
               jmin(dp[i], (Code06_StationLocation::query(1, (i - 1), 1, n, 1) +
                            fix[i])));
        }
        {
          int ei = head[i];
          int uncover = {};
          for (; (ei != 0); (ei = next[ei])) {
            (uncover = to[ei]);
            if ((left[uncover] > 1)) {
              Code06_StationLocation::add_method(1, (left[uncover] - 1),
                                                 warranty[uncover], 1, n, 1);
            }
          }
        }
      }
    }
    return dp[n];
  }
  static void prepare() {
    (cnt = 1);
    for (int i = 1; (i <= n); (i++)) {
      (left[i] = Code06_StationLocation::search((dist[i] - range[i])));
      (right[i] = Code06_StationLocation::search((dist[i] + range[i])));
      if ((dist[right[i]] > (dist[i] + range[i]))) {
        (right[i]--);
      }
      Code06_StationLocation::addEdge(right[i], i);
    }
  }
  static int search(int d) {
    int l = 1;
    int r = n;
    int m = {};
    int ans = 0;
    while ((l <= r)) {
      (m = jdiv((l + r), 2));
      if ((dist[m] >= d)) {
        (ans = m);
        (r = (m - 1));
      } else {
        (l = (m + 1));
      }
    }
    return ans;
  }
  static void addEdge(int u, int v) {
    (next[cnt] = head[u]);
    (to[cnt] = v);
    (head[u] = (cnt++));
  }
  static void up(int i) {
    (min[i] = jmin(min[jshl(i, 1)], min[(jshl(i, 1) | 1)]));
  }
  static void down(int i) {
    if ((add[i] != 0)) {
      Code06_StationLocation::lazy(jshl(i, 1), add[i]);
      Code06_StationLocation::lazy((jshl(i, 1) | 1), add[i]);
      (add[i] = 0);
    }
  }
  static void lazy(int i, int v) {
    (min[i] += v);
    (add[i] += v);
  }
  static void build(int l, int r, int i) {
    if ((l == r)) {
      (min[i] = dp[l]);
    } else {
      int mid = jshr((l + r), 1);
      Code06_StationLocation::build(l, mid, jshl(i, 1));
      Code06_StationLocation::build((mid + 1), r, (jshl(i, 1) | 1));
      Code06_StationLocation::up(i);
    }
    (add[i] = 0);
  }
  static void add_method(int jobl, int jobr, int jobv, int l, int r, int i) {
    if (((jobl <= l) && (r <= jobr))) {
      Code06_StationLocation::lazy(i, jobv);
    } else {
      Code06_StationLocation::down(i);
      int mid = jshr((l + r), 1);
      if ((jobl <= mid)) {
        Code06_StationLocation::add_method(jobl, jobr, jobv, l, mid,
                                           jshl(i, 1));
      }
      if ((jobr > mid)) {
        Code06_StationLocation::add_method(jobl, jobr, jobv, (mid + 1), r,
                                           (jshl(i, 1) | 1));
      }
      Code06_StationLocation::up(i);
    }
  }
  static int query(int jobl, int jobr, int l, int r, int i) {
    if (((jobl <= l) && (r <= jobr))) {
      return min[i];
    }
    Code06_StationLocation::down(i);
    int mid = jshr((l + r), 1);
    int ans = std::numeric_limits<int>::max();
    if ((jobl <= mid)) {
      (ans = jmin(
           ans, Code06_StationLocation::query(jobl, jobr, l, mid, jshl(i, 1))));
    }
    if ((jobr > mid)) {
      (ans = jmin(ans, Code06_StationLocation::query(jobl, jobr, (mid + 1), r,
                                                     (jshl(i, 1) | 1))));
    }
    return ans;
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code06_StationLocation::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 基站选址
// 一共有n个村庄排成一排，从左往右依次出现1号、2号、3号..n号村庄
// dist[i]表示i号村庄到1号村庄的距离，该数组一定有序且无重复值
// fix[i]表示i号村庄建立基站的安装费用
//
range[i]表示i号村庄的接收范围，任何基站和i号村庄的距离不超过这个数字，i号村庄就能得到服务
// warranty[i]表示如果i号村庄最终没有得到任何基站的服务，需要给多少赔偿费用
//
最多可以选择k个村庄安装基站，返回总花费最少是多少，总花费包括安装费用和赔偿费用
// 1 <= n <= 20000
// 1 <= k <= 100
// k <= n
// 1 <= dist[i] <= 10^9
// 1 <= fix[i] <= 10^4
// 1 <= range[i] <= 10^9
// 1 <= warranty[i] <= 10^4
// 测试链接 : https://www.luogu.com.cn/problem/P2605
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有用例
        // 因为要补充一个村庄(无穷远处)，所以村庄编号1~20001，那么空间为20002
        // 和1号村庄之间的距离
        // 安装费用
        // 接收范围
        // 赔偿费用
        // left[i]表示最左在第几号村庄建基站，i号村庄依然能获得服务
        // right[i]表示最右在第几号村庄建基站，i号村庄依然能获得服务
        // 链式前向星
        // 保存每个村庄的预警列表，i号村庄的预警列表是指
        // 如果只有一个基站建在i号村庄，现在这个基站要移动到i+1号村庄
        // 哪些村庄会从有服务变成无服务的状态
        // 线段树维护最小值信息
        // 线段树维护加的懒更新
        // 动态规划表
        //
dp[t][i]表示最多建t个基站，并且最右的基站一定要建在i号村庄，1..i号村庄的最少花费
        // 因为dp[t][i]，只依赖dp[t-1][..]，所以能空间压缩变成一维数组
                // 补充了一个村庄，认为在无穷远的位置，其他数据都是0
        // n是加上补充村庄(无穷远处)之后的村子数量
        // 所以dp[t][n]的值代表
        // 最右有一个单独的基站，去负责补充村庄，这一部分的花费是0
        // 剩余有最多t-1个基站，去负责真实出现的村庄，最少的总费用
        // 所以t一定要从1枚举到k+1，对应真实村子最多分到0个~k个基站的情况
        // 这么做可以减少边界讨论，课上进行了图解
                // 最多建t=1个基站的情况
                // 最多建t>=2个基站的情况
        // 生成left[0..n]
        // 生成right[0..n]
        // 生成预警[0..n]
                                // 如果if逻辑命中
                                //
说明此时right[i]上建基站，其实i号村庄是收不到信号的
                                // 此时right[i]要减1
                        // 生成预警列表
                        // 比如right[3] = 17
                        // 那么17号村庄的预警列表里有3
        // 在dist数组中二分查找>=d的最左位置
        // 链式前向星加边
        // 其实就是u的预警列表里增加v
        // 下面所有方法都是线段树维护最小值的模版，没有任何修改
*/

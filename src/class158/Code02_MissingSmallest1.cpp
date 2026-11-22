// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P4137

// Source: src/class158/Code02_MissingSmallest1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_MissingSmallest1 {
  inline static int MAXN = 200001;
  inline static int MAXT = (MAXN * 22);
  inline static int n = {};
  inline static int m = {};
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static Array<int> root = make_array<int>(MAXN);
  inline static Array<int> left = make_array<int>(MAXT);
  inline static Array<int> right = make_array<int>(MAXT);
  inline static Array<int> lateLeft = make_array<int>(MAXT);
  inline static int cnt = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_MissingSmallest1() {}
  static int build(int l, int r) {
    int rt = (++cnt);
    (lateLeft[rt] = 0);
    if ((l < r)) {
      int mid = jdiv((l + r), 2);
      (left[rt] = Code02_MissingSmallest1::build(l, mid));
      (right[rt] = Code02_MissingSmallest1::build((mid + 1), r));
    }
    return rt;
  }
  static int update(int jobi, int jobv, int l, int r, int i) {
    int rt = (++cnt);
    (left[rt] = left[i]);
    (right[rt] = right[i]);
    (lateLeft[rt] = lateLeft[i]);
    if ((l == r)) {
      (lateLeft[rt] = jobv);
    } else {
      int mid = jdiv((l + r), 2);
      if ((jobi <= mid)) {
        (left[rt] =
             Code02_MissingSmallest1::update(jobi, jobv, l, mid, left[rt]));
      } else {
        (right[rt] = Code02_MissingSmallest1::update(jobi, jobv, (mid + 1), r,
                                                     right[rt]));
      }
      (lateLeft[rt] = jmin(lateLeft[left[rt]], lateLeft[right[rt]]));
    }
    return rt;
  }
  static int query(int pos, int l, int r, int i) {
    if ((l == r)) {
      return l;
    }
    int mid = jdiv((l + r), 2);
    if ((lateLeft[left[i]] < pos)) {
      return Code02_MissingSmallest1::query(pos, l, mid, left[i]);
    } else {
      return Code02_MissingSmallest1::query(pos, (mid + 1), r, right[i]);
    }
  }
  static void prepare() {
    (cnt = 0);
    (root[0] = Code02_MissingSmallest1::build(0, n));
    for (int i = 1; (i <= n); (i++)) {
      if (((arr[i] > n) || (arr[i] < 0))) {
        (root[i] = root[(i - 1)]);
      } else {
        (root[i] =
             Code02_MissingSmallest1::update(arr[i], i, 0, n, root[(i - 1)]));
      }
    }
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    (n = static_cast<int>(in.nval));
    in.nextToken();
    (m = static_cast<int>(in.nval));
    for (int i = 1; (i <= n); (i++)) {
      in.nextToken();
      (arr[i] = static_cast<int>(in.nval));
    }
    Code02_MissingSmallest1::prepare();
    {
      int i = 1;
      int l = {};
      int r = {};
      for (; (i <= m); (i++)) {
        in.nextToken();
        (l = static_cast<int>(in.nval));
        in.nextToken();
        (r = static_cast<int>(in.nval));
        out.println(Code02_MissingSmallest1::query(l, 0, n, root[r]));
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
  Code02_MissingSmallest1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 区间内没有出现的最小自然数，java版
// 给定一个长度为n的数组arr，下标1~n，一共有m条查询
// 每条查询 l r : 打印arr[l..r]内没有出现过的最小自然数，注意0是自然数
// 请用在线算法解决该问题，因为可以设计强制在线的要求，让离线算法失效
// 1 <= n、m <= 2 * 10^5
// 0 <= arr[i] <= 2 * 10^5
// 测试链接 : https://www.luogu.com.cn/problem/P4137
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 数字范围中，每个数字出现的最晚位置中，最左的位置在哪
        // 数字范围l~r，信息在i号节点
        // 数字范围上，jobi这个数字，最晚出现的位置更新为jobv
        // 返回新的头节点编号
        // 数字在l~r范围上，没有出现的最小自然数，课上重点图解
                        // l...mid范围上，每个数字最晚出现的位置中
                        //
最左的位置如果在pos以左，说明l...mid范围上，一定有缺失的数字
                        // 缺失的数字一定在mid+1....r范围
                        // 因为l...r一定有缺失的数字才会来到这个范围的
                        // 如果左侧不缺失，那缺失的数字一定在右侧范围上
*/

// Source: src/class151/Code03_TreeOrder.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_TreeOrder {
  inline static int MAXN = 100001;
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static Array<int> left = make_array<int>(MAXN);
  inline static Array<int> right = make_array<int>(MAXN);
  inline static Array<int> stack = make_array<int>(MAXN);
  inline static int n = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_TreeOrder() {}
  static void build() {
    {
      int i = 1;
      int top = 0;
      int pos = 0;
      for (; (i <= n); (i++)) {
        (pos = top);
        while (((pos > 0) && (arr[stack[pos]] > arr[i]))) {
          (pos--);
        }
        if ((pos > 0)) {
          (right[stack[pos]] = i);
        }
        if ((pos < top)) {
          (left[i] = stack[(pos + 1)]);
        }
        (stack[(++pos)] = i);
        (top = pos);
      }
    }
  }
  static void pre() {
    int size = 1;
    int i = 0;
    int cur = {};
    while ((size > 0)) {
      (cur = stack[(size--)]);
      (arr[(++i)] = cur);
      if ((right[cur] != 0)) {
        (stack[(++size)] = right[cur]);
      }
      if ((left[cur] != 0)) {
        (stack[(++size)] = left[cur]);
      }
    }
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    (n = static_cast<int>(in.nval));
    for (int i = 1; (i <= n); (i++)) {
      in.nextToken();
      (arr[static_cast<int>(in.nval)] = i);
    }
    Code03_TreeOrder::build();
    Code03_TreeOrder::pre();
    for (int i = 1; (i <= n); (i++)) {
      out.print((arr[i] + String(u" ")));
    }
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code03_TreeOrder::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 树的序
// 给定一个长度为n的数组arr，表示依次插入数字，会形成一棵搜索二叉树
// 也许同样的一个序列，依次插入数字后，也能形成同样形态的搜索二叉树
// 请返回字典序尽量小的结果
// 1 <= n <= 10^5
// 测试链接 : https://www.luogu.com.cn/problem/P1377
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 防止递归爆栈用迭代的方式实现先序遍历
*/

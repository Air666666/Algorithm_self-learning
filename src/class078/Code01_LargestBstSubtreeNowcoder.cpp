// Source: src/class078/Code01_LargestBstSubtreeNowcoder.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_LargestBstSubtreeNowcoder {
  struct TreeNode;
  struct Info;
  struct TreeNode {
    int val = {};
    TreeNode *left = {};
    TreeNode *right = {};
    String toString() const { return j::str(static_cast<const void *>(this)); }
    TreeNode(int v) { (val = v); }
  };
  struct Info {
    i64 max = {};
    i64 min = {};
    bool isBst = {};
    int maxBstSize = {};
    String toString() const { return j::str(static_cast<const void *>(this)); }
    Info(i64 a, i64 b, bool c, int d) {
      (max = a);
      (min = b);
      (isBst = c);
      (maxBstSize = d);
    }
  };
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_LargestBstSubtreeNowcoder() {}
  static int largestBSTSubtree(TreeNode *root) {
    return Code01_LargestBstSubtreeNowcoder::f(root)->maxBstSize;
  }
  static Info *f(TreeNode *x) {
    if ((x == nullptr)) {
      return new Info(std::numeric_limits<i64>::min(),
                      std::numeric_limits<i64>::max(), true, 0);
    }
    Info *infol = Code01_LargestBstSubtreeNowcoder::f(x->left);
    Info *infor = Code01_LargestBstSubtreeNowcoder::f(x->right);
    i64 max = jmax(x->val, jmax(infol->max, infor->max));
    i64 min = jmin(x->val, jmin(infol->min, infor->min));
    bool isBst = (((infol->isBst && infor->isBst) && (infol->max < x->val)) &&
                  (x->val < infor->min));
    int maxBSTSize = {};
    if (isBst) {
      (maxBSTSize = ((infol->maxBstSize + infor->maxBstSize) + 1));
    } else {
      (maxBSTSize = jmax(infol->maxBstSize, infor->maxBstSize));
    }
    return new Info(max, min, isBst, maxBSTSize);
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    int n = in.nextInt();
    int root = in.nextInt();
    Array<TreeNode *> arr = make_array<TreeNode *>((n + 1));
    for (int i = 1; (i <= n); (i++)) {
      (arr[i] = new TreeNode(i));
    }
    {
      int i = 1;
      int fa = {};
      int l = {};
      int r = {};
      for (; (i <= n); (i++)) {
        (fa = in.nextInt());
        (l = in.nextInt());
        (r = in.nextInt());
        if ((l != 0)) {
          (arr[fa]->left = arr[l]);
        }
        if ((r != 0)) {
          (arr[fa]->right = arr[r]);
        }
      }
    }
    out.println(Code01_LargestBstSubtreeNowcoder::largestBSTSubtree(arr[root]));
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code01_LargestBstSubtreeNowcoder::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 最大BST子树，牛客测试
// 因为题目1是leetcode收费题，所以补充一个牛客的测试链接
// 题意完全一样，但是需要根据牛客给的数据格式，建立二叉树
// 测试链接 : https://www.nowcoder.com/practice/380d49d7f99242709ab4b91c36bf2acc
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 根据牛客的题目描述，读入数据、建二叉树、调用方法、打印答案
        // 读写工具类
*/

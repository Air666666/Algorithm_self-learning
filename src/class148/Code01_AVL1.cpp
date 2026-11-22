// Source: src/class148/Code01_AVL1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_AVL1 {
  inline static int MAXN = 100001;
  inline static int cnt = 0;
  inline static int head = 0;
  inline static Array<int> key = make_array<int>(MAXN);
  inline static Array<int> height = make_array<int>(MAXN);
  inline static Array<int> left = make_array<int>(MAXN);
  inline static Array<int> right = make_array<int>(MAXN);
  inline static Array<int> count = make_array<int>(MAXN);
  inline static Array<int> size = make_array<int>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_AVL1() {}
  static void up(int i) {
    (size[i] = ((size[left[i]] + size[right[i]]) + count[i]));
    (height[i] = (jmax(height[left[i]], height[right[i]]) + 1));
  }
  static int leftRotate(int i) {
    int r = right[i];
    (right[i] = left[r]);
    (left[r] = i);
    Code01_AVL1::up(i);
    Code01_AVL1::up(r);
    return r;
  }
  static int rightRotate(int i) {
    int l = left[i];
    (left[i] = right[l]);
    (right[l] = i);
    Code01_AVL1::up(i);
    Code01_AVL1::up(l);
    return l;
  }
  static int maintain(int i) {
    int lh = height[left[i]];
    int rh = height[right[i]];
    if (((lh - rh) > 1)) {
      if ((height[left[left[i]]] >= height[right[left[i]]])) {
        (i = Code01_AVL1::rightRotate(i));
      } else {
        (left[i] = Code01_AVL1::leftRotate(left[i]));
        (i = Code01_AVL1::rightRotate(i));
      }
    } else if (((rh - lh) > 1)) {
      if ((height[right[right[i]]] >= height[left[right[i]]])) {
        (i = Code01_AVL1::leftRotate(i));
      } else {
        (right[i] = Code01_AVL1::rightRotate(right[i]));
        (i = Code01_AVL1::leftRotate(i));
      }
    }
    return i;
  }
  static void add(int num) { (head = Code01_AVL1::add(head, num)); }
  static int add(int i, int num) {
    if ((i == 0)) {
      (key[(++cnt)] = num);
      (count[cnt] = (size[cnt] = (height[cnt] = 1)));
      return cnt;
    }
    if ((key[i] == num)) {
      (count[i]++);
    } else if ((key[i] > num)) {
      (left[i] = Code01_AVL1::add(left[i], num));
    } else {
      (right[i] = Code01_AVL1::add(right[i], num));
    }
    Code01_AVL1::up(i);
    return Code01_AVL1::maintain(i);
  }
  static void remove(int num) {
    if ([&]() {
          auto jleft = Code01_AVL1::rank(num);
          auto jright = Code01_AVL1::rank((num + 1));
          return (jleft != jright);
        }()) {
      (head = Code01_AVL1::remove(head, num));
    }
  }
  static int remove(int i, int num) {
    if ((key[i] < num)) {
      (right[i] = Code01_AVL1::remove(right[i], num));
    } else if ((key[i] > num)) {
      (left[i] = Code01_AVL1::remove(left[i], num));
    } else {
      if ((count[i] > 1)) {
        (count[i]--);
      } else {
        if (((left[i] == 0) && (right[i] == 0))) {
          return 0;
        } else if (((left[i] != 0) && (right[i] == 0))) {
          (i = left[i]);
        } else if (((left[i] == 0) && (right[i] != 0))) {
          (i = right[i]);
        } else {
          int mostLeft = right[i];
          while ((left[mostLeft] != 0)) {
            (mostLeft = left[mostLeft]);
          }
          (right[i] = Code01_AVL1::removeMostLeft(right[i], mostLeft));
          (left[mostLeft] = left[i]);
          (right[mostLeft] = right[i]);
          (i = mostLeft);
        }
      }
    }
    Code01_AVL1::up(i);
    return Code01_AVL1::maintain(i);
  }
  static int removeMostLeft(int i, int mostLeft) {
    if ((i == mostLeft)) {
      return right[i];
    } else {
      (left[i] = Code01_AVL1::removeMostLeft(left[i], mostLeft));
      Code01_AVL1::up(i);
      return Code01_AVL1::maintain(i);
    }
  }
  static int rank(int num) { return (Code01_AVL1::small(head, num) + 1); }
  static int small(int i, int num) {
    if ((i == 0)) {
      return 0;
    }
    if ((key[i] >= num)) {
      return Code01_AVL1::small(left[i], num);
    } else {
      return ((size[left[i]] + count[i]) + Code01_AVL1::small(right[i], num));
    }
  }
  static int index(int x) { return Code01_AVL1::index(head, x); }
  static int index(int i, int x) {
    if ((size[left[i]] >= x)) {
      return Code01_AVL1::index(left[i], x);
    } else if (((size[left[i]] + count[i]) < x)) {
      return Code01_AVL1::index(right[i], ((x - size[left[i]]) - count[i]));
    }
    return key[i];
  }
  static int pre(int num) { return Code01_AVL1::pre(head, num); }
  static int pre(int i, int num) {
    if ((i == 0)) {
      return std::numeric_limits<int>::min();
    }
    if ((key[i] >= num)) {
      return Code01_AVL1::pre(left[i], num);
    } else {
      return jmax(key[i], Code01_AVL1::pre(right[i], num));
    }
  }
  static int post(int num) { return Code01_AVL1::post(head, num); }
  static int post(int i, int num) {
    if ((i == 0)) {
      return std::numeric_limits<int>::max();
    }
    if ((key[i] <= num)) {
      return Code01_AVL1::post(right[i], num);
    } else {
      return jmin(key[i], Code01_AVL1::post(left[i], num));
    }
  }
  static void clear() {
    j::fill(key, 1, (cnt + 1), 0);
    j::fill(height, 1, (cnt + 1), 0);
    j::fill(left, 1, (cnt + 1), 0);
    j::fill(right, 1, (cnt + 1), 0);
    j::fill(count, 1, (cnt + 1), 0);
    j::fill(size, 1, (cnt + 1), 0);
    (cnt = 0);
    (head = 0);
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    int n = static_cast<int>(in.nval);
    {
      int i = 1;
      int op = {};
      int x = {};
      for (; (i <= n); (i++)) {
        in.nextToken();
        (op = static_cast<int>(in.nval));
        in.nextToken();
        (x = static_cast<int>(in.nval));
        if ((op == 1)) {
          Code01_AVL1::add(x);
        } else if ((op == 2)) {
          Code01_AVL1::remove(x);
        } else if ((op == 3)) {
          out.println(Code01_AVL1::rank(x));
        } else if ((op == 4)) {
          out.println(Code01_AVL1::index(x));
        } else if ((op == 5)) {
          out.println(Code01_AVL1::pre(x));
        } else {
          out.println(Code01_AVL1::post(x));
        }
      }
    }
    Code01_AVL1::clear();
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code01_AVL1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// AVL树的实现(java版)
// 实现一种结构，支持如下操作，要求单次调用的时间复杂度O(log n)
// 1，增加x，重复加入算多个词频
// 2，删除x，如果有多个，只删掉一个
// 3，查询x的排名，x的排名为，比x小的数的个数+1
// 4，查询数据中排名为x的数
// 5，查询x的前驱，x的前驱为，小于x的数中最大的数，不存在返回整数最小值
// 6，查询x的后继，x的后继为，大于x的数中最小的数，不存在返回整数最大值
// 所有操作的次数 <= 10^5
// -10^7 <= x <= +10^7
// 测试链接 : https://www.luogu.com.cn/problem/P3369
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 空间使用计数
        // 整棵树的头节点编号
        // 节点的key
        // 子树高度
        // 左孩子
        // 右孩子
        // 节点key的计数
        // 子树的数字总数
        // 修正信息
        // i节点为头的树左旋，返回左旋后头节点的空间编号
        // i节点为头的树右旋，返回右旋后头节点的空间编号
        // 检查i节点为头的树是否违规
        // 如果命中了某种违规情况，就进行相应调整
        // 返回树的头节点的空间编号
        // 增加数字num，重复加入算多个词频
        // 当前来到i号节点，num这个数字一定会加入以i为头的树
        // 树结构有可能变化，返回头节点编号
        // 删除数字num，如果有多个，只删掉一个
        // 当前来到i号节点，以i为头的树一定会减少1个num
        // 树结构有可能变化，返回头节点编号
        // 以i号节点为头的树上，最左节点的编号一定是mostLeft
        // 删掉这个节点，并保证树的平衡性，返回头节点的编号
        // 查询num的排名，比num小的数字个数+1，就是num的排名
        // 以i为头的树上，比num小的数字有几个
*/

// Source: src/class155/Code03_PersistentLeftistTree1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_PersistentLeftistTree1 {
  inline static int MAXN = 10000;
  inline static int MAXV = 100000;
  inline static int MAXT = 2000001;
  inline static Array<int> rt = make_array<int>(MAXN);
  inline static Array<int> num = make_array<int>(MAXT);
  inline static Array<int> left = make_array<int>(MAXT);
  inline static Array<int> right = make_array<int>(MAXT);
  inline static Array<int> dist = make_array<int>(MAXT);
  inline static Array<int> size = make_array<int>(MAXT);
  inline static int cnt = 0;
  inline static JList<JHeap<int>> verify = JList<JHeap<int>>();
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_PersistentLeftistTree1() {}
  static int init(int v) {
    (num[(++cnt)] = v);
    (left[cnt] = (right[cnt] = (dist[cnt] = 0)));
    return cnt;
  }
  static int clone(int i) {
    (num[(++cnt)] = num[i]);
    (left[cnt] = left[i]);
    (right[cnt] = right[i]);
    (dist[cnt] = dist[i]);
    return cnt;
  }
  static int merge(int i, int j) {
    if (((i == 0) || (j == 0))) {
      return (i + j);
    }
    int tmp = {};
    if ((num[i] > num[j])) {
      (tmp = i);
      (i = j);
      (j = tmp);
    }
    int h = Code03_PersistentLeftistTree1::clone(i);
    (right[h] = Code03_PersistentLeftistTree1::merge(right[h], j));
    if ((dist[left[h]] < dist[right[h]])) {
      (tmp = left[h]);
      (left[h] = right[h]);
      (right[h] = tmp);
    }
    (dist[h] = (dist[right[h]] + 1));
    return h;
  }
  static int pop(int i) {
    if (((left[i] == 0) && (right[i] == 0))) {
      return 0;
    }
    if (((left[i] == 0) || (right[i] == 0))) {
      return Code03_PersistentLeftistTree1::clone((left[i] + right[i]));
    }
    return Code03_PersistentLeftistTree1::merge(left[i], right[i]);
  }
  static void treeAdd(int x, int y, int i) {
    (rt[i] = Code03_PersistentLeftistTree1::merge(
         rt[x], Code03_PersistentLeftistTree1::init(y)));
    (size[rt[i]] = (size[rt[x]] + 1));
  }
  static void treeMerge(int x, int y, int i) {
    if (((rt[x] == 0) && (rt[y] == 0))) {
      (rt[i] = 0);
    } else if (((rt[x] == 0) || (rt[y] == 0))) {
      (rt[i] = Code03_PersistentLeftistTree1::clone((rt[x] + rt[y])));
    } else {
      (rt[i] = Code03_PersistentLeftistTree1::merge(rt[x], rt[y]));
    }
    (size[rt[i]] = (size[rt[x]] + size[rt[y]]));
  }
  static void treePop(int x, int i) {
    if ((size[rt[x]] == 0)) {
      (rt[i] = 0);
    } else {
      (rt[i] = Code03_PersistentLeftistTree1::pop(rt[x]));
      (size[rt[i]] = (size[rt[x]] - 1));
    }
  }
  static void verifyAdd(int x, int y) {
    JHeap<int> pre = verify.get(x);
    JList<int> tmp = JList<int>();
    while ((!pre.isEmpty())) {
      tmp.add(pre.poll());
    }
    JHeap<int> cur = JHeap<int>();
    for (int number : tmp) {
      pre.add(number);
      cur.add(number);
    }
    cur.add(y);
    verify.add(cur);
  }
  static void verifyMerge(int x, int y) {
    JHeap<int> h1 = verify.get(x);
    JHeap<int> h2 = verify.get(y);
    JList<int> tmp = JList<int>();
    JHeap<int> cur = JHeap<int>();
    while ((!h1.isEmpty())) {
      int number = h1.poll();
      tmp.add(number);
      cur.add(number);
    }
    for (int number : tmp) {
      h1.add(number);
    }
    tmp.clear();
    while ((!h2.isEmpty())) {
      int number = h2.poll();
      tmp.add(number);
      cur.add(number);
    }
    for (int number : tmp) {
      h2.add(number);
    }
    verify.add(cur);
  }
  static void verifyPop(int x) {
    JHeap<int> pre = verify.get(x);
    JHeap<int> cur = JHeap<int>();
    if ((pre.size() == 0)) {
      verify.add(cur);
    } else {
      int top = pre.poll();
      JList<int> tmp = JList<int>();
      while ((!pre.isEmpty())) {
        tmp.add(pre.poll());
      }
      for (int number : tmp) {
        pre.add(number);
        cur.add(number);
      }
      pre.add(top);
      verify.add(cur);
    }
  }
  static bool check(int i) {
    int h1 = rt[i];
    JHeap<int> h2 = verify.get(i);
    if ((size[h1] != h2.size())) {
      return false;
    }
    bool ans = true;
    JList<int> tmp = JList<int>();
    while ((!h2.isEmpty())) {
      int o1 = num[h1];
      (h1 = Code03_PersistentLeftistTree1::pop(h1));
      int o2 = h2.poll();
      tmp.add(o2);
      if ((o1 != o2)) {
        (ans = false);
        break;
      }
    }
    for (int v : tmp) {
      h2.add(v);
    }
    return ans;
  }
  static void java_main(Array<String> args) {
    jout.println(String(u"测试开始"));
    (dist[0] = (-1));
    (rt[0] = (size[0] = 0));
    verify.add(JHeap<int>());
    {
      int i = 1;
      int op = {};
      int x = {};
      int y = {};
      for (; (i < MAXN); (i++)) {
        (op = ((i == 1) ? 1 : (static_cast<int>((j::random() * 3)) + 1)));
        (x = static_cast<int>((j::random() * i)));
        if ((op == 1)) {
          (y = static_cast<int>((j::random() * MAXV)));
          Code03_PersistentLeftistTree1::treeAdd(x, y, i);
          Code03_PersistentLeftistTree1::verifyAdd(x, y);
        } else if ((op == 2)) {
          (y = x);
          do {
            (y = static_cast<int>((j::random() * i)));
          } while ((y == x));
          Code03_PersistentLeftistTree1::treeMerge(x, y, i);
          Code03_PersistentLeftistTree1::verifyMerge(x, y);
        } else {
          Code03_PersistentLeftistTree1::treePop(x, i);
          Code03_PersistentLeftistTree1::verifyPop(x);
        }
        if ((!Code03_PersistentLeftistTree1::check(i))) {
          jout.println(String(u"出错了！"));
        }
      }
    }
    for (int i = 1; (i < MAXN); (i++)) {
      if ((!Code03_PersistentLeftistTree1::check(i))) {
        jout.println(String(u"出错了！"));
      }
    }
    jout.println(String(u"测试结束"));
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code03_PersistentLeftistTree1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 可持久化左偏树的实现，利用对数器验证正确性，java版
        // 可持久化左偏树，x版本加入数字y，生成最新的i版本
        // 可持久化左偏树，x版本与y版本合并，生成最新的i版本
        // 可持久化左偏树，x版本弹出顶部，生成最新的i版本
        // 验证结构
        // 验证结构，x版本加入数字y，生成最新版本
        // 验证结构，x版本与y版本合并，生成最新版本
        // 验证结构，x版本弹出顶部，生成最新版本
        // 可持久化左偏树i版本的堆
        // 是否等于
        // 验证结构i版本的堆
                        // op == 1，x版本的堆里加入数字y，形成i号版本的堆
                        // op == 2，x版本的堆和y版本的堆合并，形成i号版本的堆
                        // op == 3，x版本的堆弹出堆顶，形成i号版本的堆
                                // 保证x != y
                        // 检查最新版本的堆是否一样
                // 最后验证是否所有版本的堆都一样
*/

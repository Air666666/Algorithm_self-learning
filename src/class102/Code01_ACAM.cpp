// Source: src/class102/Code01_ACAM.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_ACAM {
  inline static int MAXN = 200001;
  inline static int MAXS = 200001;
  inline static Array<int> end = make_array<int>(MAXN);
  inline static Array<Array<int>> tree = make_array<int>(MAXS, 26);
  inline static Array<int> fail = make_array<int>(MAXS);
  inline static int cnt = 0;
  inline static Array<int> times = make_array<int>(MAXS);
  inline static Array<int> box = make_array<int>(MAXS);
  inline static Array<int> head = make_array<int>(MAXS);
  inline static Array<int> next = make_array<int>(MAXS);
  inline static Array<int> to = make_array<int>(MAXS);
  inline static int edge = 0;
  inline static Array<bool> visited = make_array<bool>(MAXS);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_ACAM() {}
  static void insert(int i, String str) {
    Array<jchar> s = str.toCharArray();
    int u = 0;
    {
      int j = 0;
      int c = {};
      for (; (j < s.length); (j++)) {
        (c = (s[j] - u'a'));
        if ((tree[u][c] == 0)) {
          (tree[u][c] = (++cnt));
        }
        (u = tree[u][c]);
      }
    }
    (end[i] = u);
  }
  static void setFail() {
    int l = 0;
    int r = 0;
    for (int i = 0; (i <= 25); (i++)) {
      if ((tree[0][i] > 0)) {
        (box[(r++)] = tree[0][i]);
      }
    }
    while ((l < r)) {
      int u = box[(l++)];
      for (int i = 0; (i <= 25); (i++)) {
        if ((tree[u][i] == 0)) {
          (tree[u][i] = tree[fail[u]][i]);
        } else {
          (fail[tree[u][i]] = tree[fail[u]][i]);
          (box[(r++)] = tree[u][i]);
        }
      }
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO(IO(jin));
    IO out = IO(IO(jout));
    int n = std::stoi(text(in.readLine()));
    for (int i = 1; (i <= n); (i++)) {
      Code01_ACAM::insert(i, in.readLine());
    }
    Code01_ACAM::setFail();
    Array<jchar> s = in.readLine().toCharArray();
    {
      int u = 0;
      int i = 0;
      for (; (i < s.length); (i++)) {
        (u = tree[u][(s[i] - u'a')]);
        (times[u]++);
      }
    }
    for (int i = 1; (i <= cnt); (i++)) {
      Code01_ACAM::addEdge(fail[i], i);
    }
    Code01_ACAM::f2(0);
    for (int i = 1; (i <= n); (i++)) {
      out.println(times[end[i]]);
    }
    out.flush();
    out.close();
    in.close();
  }
  static void addEdge(int u, int v) {
    (next[(++edge)] = head[u]);
    (head[u] = edge);
    (to[edge] = v);
  }
  static void f1(int u) {
    for (int i = head[u]; (i > 0); (i = next[i])) {
      Code01_ACAM::f1(to[i]);
      (times[u] += times[to[i]]);
    }
  }
  static void f2(int u) {
    int r = 0;
    (box[(r++)] = u);
    int cur = {};
    while ((r > 0)) {
      (cur = box[(r - 1)]);
      if ((!visited[cur])) {
        (visited[cur] = true);
        for (int i = head[cur]; (i > 0); (i = next[i])) {
          (box[(r++)] = to[i]);
        }
      } else {
        (r--);
        for (int i = head[cur]; (i > 0); (i = next[i])) {
          (times[cur] += times[to[i]]);
        }
      }
    }
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code01_ACAM::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// AC自动机模版(优化版)
// 给你若干目标字符串，还有一篇文章
// 返回每个目标字符串在文章中出现了几次
// 测试链接 : https://www.luogu.com.cn/problem/P5357
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下的code，提交时请把类名改成"Main"，可以直接通过
        // 目标字符串的数量
        // 所有目标字符串的总字符数量
        // 记录每个目标串的结尾节点编号
        // AC自动机
        // 具体题目相关，本题为收集词频
        // 所以每个节点记录词频
        // 可以用作队列或者栈，一个容器而已
        // 链式前向星，为了建立fail指针的反图
        // 遍历fail反图，递归方法会爆栈，所以用非递归替代
        // AC自动机加入目标字符串
                // 每个目标字符串的结尾节点编号
        // 加入所有目标字符串之后
        // 设置fail指针 以及 设置直接直通表
        // 做了AC自动机固定的优化
                // box当做队列来使用
                // AC自动机建树
                // 读入大文章
                        // 增加匹配次数
                        // 根据fail指针建反图
                        // 其实是一颗树
                // 遍历fail指针建的树
                // 汇总每个节点的词频
        // 逻辑是对的
        // 但是递归开太多层了会爆栈
        // C++这道题不会爆栈
        // java会
        // 改成非递归才能通过
        // 因为是用栈来模拟递归
        // 只消耗内存空间(box和visited)
        // 不消耗系统栈的空间
        // 所以很安全
                // box当做栈来使用
*/

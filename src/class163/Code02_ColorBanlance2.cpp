// Source: src/class163/Code02_ColorBanlance2.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_ColorBanlance2 {
  inline static int MAXN = 200001;
  inline static int n = {};
  inline static Array<int> color = make_array<int>(MAXN);
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> next = make_array<int>(MAXN);
  inline static Array<int> to = make_array<int>(MAXN);
  inline static int cnt = 0;
  inline static Array<int> siz = make_array<int>(MAXN);
  inline static Array<int> son = make_array<int>(MAXN);
  inline static Array<int> colorCnt = make_array<int>(MAXN);
  inline static Array<int> colorNum = make_array<int>(MAXN);
  inline static int ans = 0;
  inline static Array<Array<int>> stack1 = make_array<int>(MAXN, 2);
  inline static int size1 = {};
  inline static int cur1 = {};
  inline static int edge1 = {};
  inline static Array<Array<int>> stack2 = make_array<int>(MAXN, 3);
  inline static int size2 = {};
  inline static int cur2 = {};
  inline static int keep2 = {};
  inline static int edge2 = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_ColorBanlance2() {}
  static void addEdge(int u, int v) {
    (next[(++cnt)] = head[u]);
    (to[cnt] = v);
    (head[u] = cnt);
  }
  static void push1(int u, int e) {
    (stack1[size1][0] = u);
    (stack1[size1][1] = e);
    (size1++);
  }
  static void pop1() {
    (--size1);
    (cur1 = stack1[size1][0]);
    (edge1 = stack1[size1][1]);
  }
  static void push2(int u, int k, int e) {
    (stack2[size2][0] = u);
    (stack2[size2][1] = k);
    (stack2[size2][2] = e);
    (size2++);
  }
  static void pop2() {
    (--size2);
    (cur2 = stack2[size2][0]);
    (keep2 = stack2[size2][1]);
    (edge2 = stack2[size2][2]);
  }
  static void dfs1(int u) {
    (size1 = 0);
    Code02_ColorBanlance2::push1(u, (-1));
    while ((size1 > 0)) {
      Code02_ColorBanlance2::pop1();
      if ((edge1 == (-1))) {
        (siz[cur1] = 1);
        (edge1 = head[cur1]);
      } else {
        (edge1 = next[edge1]);
      }
      if ((edge1 != 0)) {
        Code02_ColorBanlance2::push1(cur1, edge1);
        Code02_ColorBanlance2::push1(to[edge1], (-1));
      } else {
        {
          int e = head[cur1];
          int v = {};
          for (; (e > 0); (e = next[e])) {
            (v = to[e]);
            (siz[cur1] += siz[v]);
            if (((son[cur1] == 0) || (siz[son[cur1]] < siz[v]))) {
              (son[cur1] = v);
            }
          }
        }
      }
    }
  }
  static void effect(int root) {
    (size1 = 0);
    Code02_ColorBanlance2::push1(root, (-1));
    while ((size1 > 0)) {
      Code02_ColorBanlance2::pop1();
      if ((edge1 == (-1))) {
        (colorCnt[color[cur1]]++);
        (colorNum[(colorCnt[color[cur1]] - 1)]--);
        (colorNum[colorCnt[color[cur1]]]++);
        (edge1 = head[cur1]);
      } else {
        (edge1 = next[edge1]);
      }
      if ((edge1 != 0)) {
        Code02_ColorBanlance2::push1(cur1, edge1);
        Code02_ColorBanlance2::push1(to[edge1], (-1));
      }
    }
  }
  static void cancel(int root) {
    (size1 = 0);
    Code02_ColorBanlance2::push1(root, (-1));
    while ((size1 > 0)) {
      Code02_ColorBanlance2::pop1();
      if ((edge1 == (-1))) {
        (colorCnt[color[cur1]]--);
        (colorNum[(colorCnt[color[cur1]] + 1)]--);
        (colorNum[colorCnt[color[cur1]]]++);
        (edge1 = head[cur1]);
      } else {
        (edge1 = next[edge1]);
      }
      if ((edge1 != 0)) {
        Code02_ColorBanlance2::push1(cur1, edge1);
        Code02_ColorBanlance2::push1(to[edge1], (-1));
      }
    }
  }
  static void dfs2(int u, int keep) {
    (size2 = 0);
    Code02_ColorBanlance2::push2(u, keep, (-1));
    while ((size2 > 0)) {
      Code02_ColorBanlance2::pop2();
      if ((edge2 != (-2))) {
        if ((edge2 == (-1))) {
          (edge2 = head[cur2]);
        } else {
          (edge2 = next[edge2]);
        }
        if ((edge2 > 0)) {
          Code02_ColorBanlance2::push2(cur2, keep2, edge2);
          if ((to[edge2] != son[cur2])) {
            Code02_ColorBanlance2::push2(to[edge2], 0, (-1));
          }
        } else {
          Code02_ColorBanlance2::push2(cur2, keep2, (-2));
          if ((son[cur2] != 0)) {
            Code02_ColorBanlance2::push2(son[cur2], 1, (-1));
          }
        }
      } else {
        (colorCnt[color[cur2]]++);
        (colorNum[(colorCnt[color[cur2]] - 1)]--);
        (colorNum[colorCnt[color[cur2]]]++);
        {
          int e = head[cur2];
          int v = {};
          for (; (e > 0); (e = next[e])) {
            (v = to[e]);
            if ((v != son[cur2])) {
              Code02_ColorBanlance2::effect(v);
            }
          }
        }
        if (((colorCnt[color[cur2]] * colorNum[colorCnt[color[cur2]]]) ==
             siz[cur2])) {
          (ans++);
        }
        if ((keep2 == 0)) {
          Code02_ColorBanlance2::cancel(cur2);
        }
      }
    }
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    (n = static_cast<int>(in.nval));
    {
      int i = 1;
      int father = {};
      for (; (i <= n); (i++)) {
        in.nextToken();
        (color[i] = static_cast<int>(in.nval));
        in.nextToken();
        (father = static_cast<int>(in.nval));
        if ((i != 1)) {
          Code02_ColorBanlance2::addEdge(father, i);
        }
      }
    }
    Code02_ColorBanlance2::dfs1(1);
    Code02_ColorBanlance2::dfs2(1, 0);
    out.println(ans);
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code02_ColorBanlance2::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 颜色平衡的子树，java实现迭代版
// 不会改迭代版，去看讲解118，详解了dfs从递归版改迭代版
// 测试链接 : https://www.luogu.com.cn/problem/P9233
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // stack1、size1、cur1、edge1
        // 用于把effect、cancel、dfs1改成迭代版
        // stack2、size2、cur2、keep2、edge2
        // 用于把dfs2改成迭代版
        // 迭代版的dfs2，用edge2变量标记一个节点的不同阶段
        // edge2 == -1，表示第一次来到当前节点，接下来依次处理轻儿子的子树
        // edge2 > 0，表示正在依次处理轻儿子的子树
        // edge2 == 0，表示处理完了所有轻儿子的子树，接下来处理重儿子的子树
        // edge2 == -2，表示处理完了重儿子的子树，轮到启发式合并了
*/

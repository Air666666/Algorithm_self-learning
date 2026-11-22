// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P3369

// Source: src/class149/SkipList1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct SkipList1 {
  inline static int MAXL = 20;
  inline static int MAXN = 100001;
  inline static int cnt = {};
  inline static Array<int> key = make_array<int>(MAXN);
  inline static Array<int> count = make_array<int>(MAXN);
  inline static Array<int> level = make_array<int>(MAXN);
  inline static Array<Array<int>> next = make_array<int>(MAXN, (MAXL + 1));
  inline static Array<Array<int>> len = make_array<int>(MAXN, (MAXL + 1));
  String toString() const { return j::str(static_cast<const void *>(this)); }
  SkipList1() {}
  static void build() {
    (cnt = 1);
    (key[cnt] = std::numeric_limits<int>::min());
    (level[cnt] = MAXL);
  }
  static void clear() {
    j::fill(key, 1, (cnt + 1), 0);
    j::fill(count, 1, (cnt + 1), 0);
    j::fill(level, 1, (cnt + 1), 0);
    for (int i = 1; (i <= cnt); (i++)) {
      j::fill(next[i], 0);
      j::fill(len[i], 0);
    }
    (cnt = 0);
  }
  static int random() {
    int ans = 1;
    while ((j::random() < 0.5)) {
      (ans++);
    }
    return jmin(ans, MAXL);
  }
  static int find(int i, int h, int num) {
    while (((next[i][h] != 0) && (key[next[i][h]] < num))) {
      (i = next[i][h]);
    }
    if ((h == 1)) {
      if (((next[i][h] != 0) && (key[next[i][h]] == num))) {
        return next[i][h];
      } else {
        return 0;
      }
    }
    return SkipList1::find(i, (h - 1), num);
  }
  static void add(int num) {
    if ((SkipList1::find(1, MAXL, num) != 0)) {
      SkipList1::addCount(1, MAXL, num);
    } else {
      (key[(++cnt)] = num);
      (count[cnt] = 1);
      (level[cnt] = SkipList1::random());
      SkipList1::addNode(1, MAXL, cnt);
    }
  }
  static void addCount(int i, int h, int num) {
    while (((next[i][h] != 0) && (key[next[i][h]] < num))) {
      (i = next[i][h]);
    }
    if ((h == 1)) {
      (count[next[i][h]]++);
    } else {
      SkipList1::addCount(i, (h - 1), num);
    }
    (len[i][h]++);
  }
  static int addNode(int i, int h, int j) {
    int rightCnt = 0;
    while (((next[i][h] != 0) && (key[next[i][h]] < key[j]))) {
      (rightCnt += len[i][h]);
      (i = next[i][h]);
    }
    if ((h == 1)) {
      (next[j][h] = next[i][h]);
      (next[i][h] = j);
      (len[j][h] = count[next[j][h]]);
      (len[i][h] = count[next[i][h]]);
      return rightCnt;
    } else {
      int downCnt = SkipList1::addNode(i, (h - 1), j);
      if ((h > level[j])) {
        (len[i][h]++);
      } else {
        (next[j][h] = next[i][h]);
        (next[i][h] = j);
        (len[j][h] = (((len[i][h] + 1) - downCnt) - count[j]));
        (len[i][h] = (downCnt + count[j]));
      }
      return (rightCnt + downCnt);
    }
  }
  static void remove(int num) {
    int j = SkipList1::find(1, MAXL, num);
    if ((j != 0)) {
      if ((count[j] > 1)) {
        SkipList1::removeCount(1, MAXL, num);
      } else {
        SkipList1::removeNode(1, MAXL, j);
      }
    }
  }
  static void removeCount(int i, int h, int num) {
    while (((next[i][h] != 0) && (key[next[i][h]] < num))) {
      (i = next[i][h]);
    }
    if ((h == 1)) {
      (count[next[i][h]]--);
    } else {
      SkipList1::removeCount(i, (h - 1), num);
    }
    (len[i][h]--);
  }
  static void removeNode(int i, int h, int j) {
    if ((h < 1)) {
      return;
    }
    while (((next[i][h] != 0) && (key[next[i][h]] < key[j]))) {
      (i = next[i][h]);
    }
    if ((h > level[j])) {
      (len[i][h]--);
    } else {
      (next[i][h] = next[j][h]);
      (len[i][h] += (len[j][h] - 1));
    }
    SkipList1::removeNode(i, (h - 1), j);
  }
  static int rank(int num) { return (SkipList1::small(1, MAXL, num) + 1); }
  static int small(int i, int h, int num) {
    int rightCnt = 0;
    while (((next[i][h] != 0) && (key[next[i][h]] < num))) {
      (rightCnt += len[i][h]);
      (i = next[i][h]);
    }
    if ((h == 1)) {
      return rightCnt;
    } else {
      return (rightCnt + SkipList1::small(i, (h - 1), num));
    }
  }
  static int index(int x) { return SkipList1::index(1, MAXL, x); }
  static int index(int i, int h, int x) {
    int c = 0;
    while (((next[i][h] != 0) && ((c + len[i][h]) < x))) {
      (c += len[i][h]);
      (i = next[i][h]);
    }
    if ((h == 1)) {
      return key[next[i][h]];
    } else {
      return SkipList1::index(i, (h - 1), (x - c));
    }
  }
  static int pre(int num) { return SkipList1::pre(1, MAXL, num); }
  static int pre(int i, int h, int num) {
    while (((next[i][h] != 0) && (key[next[i][h]] < num))) {
      (i = next[i][h]);
    }
    if ((h == 1)) {
      return ((i == 1) ? std::numeric_limits<int>::min() : key[i]);
    } else {
      return SkipList1::pre(i, (h - 1), num);
    }
  }
  static int post(int num) { return SkipList1::post(1, MAXL, num); }
  static int post(int i, int h, int num) {
    while (((next[i][h] != 0) && (key[next[i][h]] < num))) {
      (i = next[i][h]);
    }
    if ((h == 1)) {
      if ((next[i][h] == 0)) {
        return std::numeric_limits<int>::max();
      }
      if ((key[next[i][h]] > num)) {
        return key[next[i][h]];
      }
      (i = next[i][h]);
      if ((next[i][h] == 0)) {
        return std::numeric_limits<int>::max();
      } else {
        return key[next[i][h]];
      }
    } else {
      return SkipList1::post(i, (h - 1), num);
    }
  }
  static void java_main(Array<String> args) {
    SkipList1::build();
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
          SkipList1::add(x);
        } else if ((op == 2)) {
          SkipList1::remove(x);
        } else if ((op == 3)) {
          out.println(SkipList1::rank(x));
        } else if ((op == 4)) {
          out.println(SkipList1::index(x));
        } else if ((op == 5)) {
          out.println(SkipList1::pre(x));
        } else {
          out.println(SkipList1::post(x));
        }
      }
    }
    SkipList1::clear();
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  SkipList1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 跳表的实现(java版)
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
        // 跳表最大层的限制
        // 空间使用计数
        // 节点的key
        // 节点key的计数
        // 节点拥有多少层指针
        // 节点每一层指针指向哪个节点
        // 节点每一层指针的长度(底层跨过多少数，左开右闭)
        // 建立跳表
        // 使用多少空间一律清空
        // 扔骰子决定节点的层数
        // 当前在i号节点的h层，返回key为num的节点，空间编号是多少
        // 增加num，重复加入算多个词频
        // 当前在i号节点的h层，num增加一个词频
        // 当前在i号节点的h层，插入空间编号为j的节点
        //
返回值：从i号节点出发，直到把空间编号为j的节点插入，底层总共有多少数字比key[j]小
        // 返回值很重要，因为上游需要这个信息来改动指针的长度信息
        // 删除x，如果有多个，只删掉一个
        // 当前在i号节点的h层，num减少一个词频
        // 当前在i号节点的h层，删除空间编号为j的节点
        // 查询num的排名
        // 当前在i号节点的h层，查询有多少个数字比num小
        // 查询排名第x的key是什么
        // 当前在i号节点的h层，查询排名第x的key是什么
        // 查询num的前驱
        // 查询num的后继
*/

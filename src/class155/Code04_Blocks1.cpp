// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P2409

// Source: src/class155/Code04_Blocks1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_Blocks1 {
  inline static int MAXN = 101;
  inline static int MAXM = 10001;
  inline static int MAXK = 10001;
  inline static int MAXT = 1000001;
  inline static int INF = 10000001;
  inline static int n = {};
  inline static int k = {};
  inline static Array<int> arr = make_array<int>(MAXM);
  inline static Array<int> start = make_array<int>(MAXN);
  inline static Array<int> boundary = make_array<int>(MAXN);
  inline static Array<int> idx = make_array<int>(MAXT);
  inline static Array<int> jdx = make_array<int>(MAXT);
  inline static Array<int> cost = make_array<int>(MAXT);
  inline static Array<int> left = make_array<int>(MAXT);
  inline static Array<int> right = make_array<int>(MAXT);
  inline static Array<int> dist = make_array<int>(MAXT);
  inline static Array<int> pre = make_array<int>(MAXT);
  inline static int cnt = 0;
  inline static Array<int> heap = make_array<int>(MAXK);
  inline static int heapSize = 0;
  inline static Array<int> ans = make_array<int>(MAXK);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_Blocks1() {}
  static int init(int i, int j) {
    (idx[(++cnt)] = i);
    (jdx[cnt] = j);
    (cost[cnt] = (((j + 1) < boundary[i]) ? (arr[(j + 1)] - arr[j]) : INF));
    (left[cnt] = (right[cnt] = (dist[cnt] = 0)));
    return cnt;
  }
  static int clone(int i) {
    (idx[(++cnt)] = idx[i]);
    (jdx[cnt] = jdx[i]);
    (cost[cnt] = cost[i]);
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
    if ((cost[i] > cost[j])) {
      (tmp = i);
      (i = j);
      (j = tmp);
    }
    int h = Code04_Blocks1::clone(i);
    (right[h] = Code04_Blocks1::merge(right[h], j));
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
      return Code04_Blocks1::clone((left[i] + right[i]));
    }
    return Code04_Blocks1::merge(left[i], right[i]);
  }
  static bool compare(int i, int j) {
    return ((pre[i] + cost[i]) < (pre[j] + cost[j]));
  }
  static void heapAdd(int i) {
    (heap[(++heapSize)] = i);
    int cur = heapSize;
    int up = jdiv(cur, 2);
    int tmp = {};
    while (((cur > 1) && Code04_Blocks1::compare(heap[cur], heap[up]))) {
      (tmp = heap[up]);
      (heap[up] = heap[cur]);
      (heap[cur] = tmp);
      (cur = up);
      (up = jdiv(cur, 2));
    }
  }
  static int heapPop() {
    int ans = heap[1];
    (heap[1] = heap[(heapSize--)]);
    int cur = 1;
    int l = (cur * 2);
    int r = (l + 1);
    int best = {};
    int tmp = {};
    while ((l <= heapSize)) {
      (best = (((r <= heapSize) && Code04_Blocks1::compare(heap[r], heap[l]))
                   ? r
                   : l));
      (best = (Code04_Blocks1::compare(heap[best], heap[cur]) ? best : cur));
      if ((best == cur)) {
        break;
      }
      (tmp = heap[best]);
      (heap[best] = heap[cur]);
      (heap[cur] = tmp);
      (cur = best);
      (l = (cur * 2));
      (r = (l + 1));
    }
    return ans;
  }
  static void compute() {
    int first = 0;
    for (int i = 1; (i <= n); (i++)) {
      j::sort(arr, start[i], boundary[i]);
      (first += arr[start[i]]);
    }
    (dist[0] = (-1));
    int head = 0;
    for (int i = 1; (i <= n); (i++)) {
      (head = Code04_Blocks1::merge(head, Code04_Blocks1::init(i, start[i])));
    }
    (pre[head] = first);
    (ans[1] = first);
    Code04_Blocks1::heapAdd(head);
    {
      int ansi = 2;
      int h1 = {};
      int h2 = {};
      for (; (ansi <= k); (ansi++)) {
        (head = Code04_Blocks1::heapPop());
        (ans[ansi] = (pre[head] + cost[head]));
        (h1 = Code04_Blocks1::pop(head));
        if ((h1 != 0)) {
          (pre[h1] = pre[head]);
          Code04_Blocks1::heapAdd(h1);
        }
        if (((jdx[head] + 1) < boundary[idx[head]])) {
          (h2 = Code04_Blocks1::merge(
               h1, Code04_Blocks1::init(idx[head], (jdx[head] + 1))));
          (pre[h2] = ans[ansi]);
          Code04_Blocks1::heapAdd(h2);
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
    in.nextToken();
    (k = static_cast<int>(in.nval));
    {
      int i = 1;
      int m = {};
      int ai = 0;
      for (; (i <= n); (i++)) {
        in.nextToken();
        (m = static_cast<int>(in.nval));
        (start[i] = (ai + 1));
        for (int j = 1; (j <= m); (j++)) {
          in.nextToken();
          (arr[(++ai)] = static_cast<int>(in.nval));
        }
        (boundary[i] = (start[i] + m));
      }
    }
    Code04_Blocks1::compute();
    for (int i = 1; (i <= k); (i++)) {
      out.print((ans[i] + String(u" ")));
    }
    out.println();
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code04_Blocks1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// Y的积木，可持久化左偏树实现最优解，java版
// 一共有n个正数数组，给定每个数组的大小mi，以及每个数组的数字
// 每个数组必须选且只能选一个数字，就可以形成n个数字的挑选方案
// 所有这些方案中，有数字累加和第1小的方案、第2小的方案、第3小的方案...
// 打印，累加和前k小的方案，各自的累加和，要求实现O(k * log k)的解
// 1 <= n、mi <= 100
// 1 <= k <= 10^4
// 1 <= 数字 <= 100
// 测试链接 : https://www.luogu.com.cn/problem/P2409
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 所有数组的所有数字放在arr中
        // start[i] : 第i个数组的第一个数字在arr中的什么位置
        // boundary[i] : 第i个数组的越界位置在arr中的什么位置
        // 左偏树代表基于之前的某个方案，做出行动的可能性
        // 左偏树的头就代表这个最优行动，假设编号为h的节点是头
        // idx[h] : 最优行动来自哪个数组
        // jdx[h] : 最优行动要替换掉idx[h]数组中什么位置的数
        // cost[h] : 基于之前的某个方案，最优行动会让累加和增加多少
        // pre[h] : 基于之前的某个方案，这个方案的累加和，标签信息
        // heap是经典的小根堆，放着所有版本左偏树的头
        // 哪个左偏树的头节点，所代表方案的累加和最小，谁就放在heap的顶部
        // 收集答案
*/

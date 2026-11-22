// Source: src/class115/Code02_SkylineLuogu.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_SkylineLuogu {
  inline static int MAXN = 20001;
  inline static Array<Array<int>> arr = make_array<int>(MAXN, 3);
  inline static Array<int> xsort = make_array<int>(MAXN);
  inline static Array<int> height = make_array<int>(MAXN);
  inline static Array<Array<int>> heap = make_array<int>(MAXN, 2);
  inline static int heapSize = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_SkylineLuogu() {}
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    int n = 0;
    while ((in.nextToken() != -1)) {
      (arr[n][0] = static_cast<int>(in.nval));
      in.nextToken();
      (arr[n][2] = static_cast<int>(in.nval));
      in.nextToken();
      (arr[n][1] = static_cast<int>(in.nval));
      (n++);
    }
    int m = Code02_SkylineLuogu::prepare(n);
    Code02_SkylineLuogu::compute(n, m);
    out.print(((xsort[1] + String(u" ")) + height[1]));
    {
      int i = 2;
      int pre = height[1];
      for (; (i <= m); (i++)) {
        if ((pre != height[i])) {
          out.print((((String(u" ") + xsort[i]) + String(u" ")) + height[i]));
        }
        (pre = height[i]);
      }
    }
    out.println();
    out.flush();
    out.close();
    br.close();
  }
  static void compute(int n, int m) {
    {
      int i = 1;
      int j = 0;
      for (; (i <= m); (i++)) {
        for (; ((j < n) && (arr[j][0] <= i)); (j++)) {
          Code02_SkylineLuogu::push(arr[j][2], arr[j][1]);
        }
        while (((!Code02_SkylineLuogu::isEmpty()) &&
                (Code02_SkylineLuogu::peekEnd() < i))) {
          Code02_SkylineLuogu::poll();
        }
        if ((!Code02_SkylineLuogu::isEmpty())) {
          (height[i] = Code02_SkylineLuogu::peekHeight());
        }
      }
    }
  }
  static int prepare(int n) {
    int size = 0;
    for (int i = 0; (i < n); (i++)) {
      (xsort[(++size)] = arr[i][0]);
      (xsort[(++size)] = (arr[i][1] - 1));
      (xsort[(++size)] = arr[i][1]);
    }
    j::sort(xsort, 1, (size + 1));
    int m = 1;
    for (int i = 1; (i <= size); (i++)) {
      if ((xsort[m] != xsort[i])) {
        (xsort[(++m)] = xsort[i]);
      }
    }
    for (int i = 0; (i < n); (i++)) {
      (arr[i][0] = Code02_SkylineLuogu::rank(m, arr[i][0]));
      (arr[i][1] = Code02_SkylineLuogu::rank(m, (arr[i][1] - 1)));
    }
    j::sort(arr, 0, n,
            [=](Array<int> a, Array<int> b) { return (a[0] - b[0]); });
    j::fill(height, 1, (m + 1), 0);
    return m;
  }
  static int rank(int n, int v) {
    int ans = 0;
    int l = 1;
    int r = n;
    int mid = {};
    while ((l <= r)) {
      (mid = jshr((l + r), 1));
      if ((xsort[mid] >= v)) {
        (ans = mid);
        (r = (mid - 1));
      } else {
        (l = (mid + 1));
      }
    }
    return ans;
  }
  static bool isEmpty() { return (heapSize == 0); }
  static int peekHeight() { return heap[0][0]; }
  static int peekEnd() { return heap[0][1]; }
  static void push(int h, int e) {
    (heap[heapSize][0] = h);
    (heap[heapSize][1] = e);
    Code02_SkylineLuogu::heapInsert((heapSize++));
  }
  static void poll() {
    Code02_SkylineLuogu::swap(0, (--heapSize));
    Code02_SkylineLuogu::heapify(0);
  }
  static void heapInsert(int i) {
    while ((heap[i][0] > heap[jdiv((i - 1), 2)][0])) {
      Code02_SkylineLuogu::swap(i, jdiv((i - 1), 2));
      (i = jdiv((i - 1), 2));
    }
  }
  static void heapify(int i) {
    int l = ((i * 2) + 1);
    while ((l < heapSize)) {
      int best =
          ((((l + 1) < heapSize) && (heap[(l + 1)][0] > heap[l][0])) ? (l + 1)
                                                                     : l);
      (best = ((heap[best][0] > heap[i][0]) ? best : i));
      if ((best == i)) {
        break;
      }
      Code02_SkylineLuogu::swap(best, i);
      (i = best);
      (l = ((i * 2) + 1));
    }
  }
  static void swap(int i, int j) {
    Array<int> tmp = heap[i];
    (heap[i] = heap[j]);
    (heap[j] = tmp);
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code02_SkylineLuogu::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 天际线问题(洛谷测试)
// 测试链接 : https://www.luogu.com.cn/problem/P1904
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下的code，提交时请把类名改成"Main"，可以直接通过
// 堆结构由自己实现
*/

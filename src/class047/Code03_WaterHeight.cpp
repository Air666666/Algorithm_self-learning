// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P5026

// Source: src/class047/Code03_WaterHeight.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_WaterHeight {
  inline static int MAXN = 1000001;
  inline static int OFFSET = 30001;
  inline static Array<int> arr = make_array<int>(((OFFSET + MAXN) + OFFSET));
  inline static int n = {};
  inline static int m = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_WaterHeight() {}
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    while ((in.nextToken() != -1)) {
      (n = static_cast<int>(in.nval));
      in.nextToken();
      (m = static_cast<int>(in.nval));
      {
        int i = 0;
        int v = {};
        int x = {};
        for (; (i < n); (i++)) {
          in.nextToken();
          (v = static_cast<int>(in.nval));
          in.nextToken();
          (x = static_cast<int>(in.nval));
          Code03_WaterHeight::fall(v, x);
        }
      }
      Code03_WaterHeight::build();
      int start = (OFFSET + 1);
      out.print(arr[(start++)]);
      for (int i = 2; (i <= m); (i++)) {
        out.print((String(u" ") + arr[(start++)]));
      }
      out.println();
    }
    out.flush();
    out.close();
    br.close();
  }
  static void fall(int v, int x) {
    Code03_WaterHeight::set(((x - (3 * v)) + 1), (x - (2 * v)), 1, v, 1);
    Code03_WaterHeight::set(((x - (2 * v)) + 1), x, (v - 1), (-v), (-1));
    Code03_WaterHeight::set((x + 1), (x + (2 * v)), ((-v) + 1), v, 1);
    Code03_WaterHeight::set(((x + (2 * v)) + 1), ((x + (3 * v)) - 1), (v - 1),
                            1, (-1));
  }
  static void set(int l, int r, int s, int e, int d) {
    (arr[(l + OFFSET)] += s);
    (arr[((l + 1) + OFFSET)] += (d - s));
    (arr[((r + 1) + OFFSET)] -= (d + e));
    (arr[((r + 2) + OFFSET)] += e);
  }
  static void build() {
    for (int i = 1; (i <= (m + OFFSET)); (i++)) {
      (arr[i] += arr[(i - 1)]);
    }
    for (int i = 1; (i <= (m + OFFSET)); (i++)) {
      (arr[i] += arr[(i - 1)]);
    }
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code03_WaterHeight::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 一群人落水后求每个位置的水位高度
// 问题描述比较复杂，见测试链接
// 测试链接 : https://www.luogu.com.cn/problem/P5026
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下的code，提交时请把类名改成"Main"，可以直接通过
        // 题目说了m <= 10^6，代表湖泊宽度
        // 这就是MAXN的含义，湖泊最大宽度的极限
        // 数值保护，因为题目中v最大是10000
        // 所以左侧影响最远的位置到达了x - 3 * v + 1
        // 所以右侧影响最远的位置到达了x + 3 * v - 1
        // x如果是正式的位置(1~m)，那么左、右侧可能超过正式位置差不多30000的规模
        // 这就是OFFSET的含义
        // 湖泊宽度是MAXN，是正式位置的范围
        // 左、右侧可能超过正式位置差不多OFFSET的规模
        // 所以准备一个长度为OFFSET + MAXN + OFFSET的数组
        // 这样一来，左侧影响最远的位置...右侧影响最远的位置，
        // 都可以被arr中的下标表示出来，就省去了很多越界讨论
        // 详细解释看set方法的注释
                        // n有多少个人落水，每个人落水意味着四个等差数列操作
                        // 一共有多少位置，1~m个位置，最终要打印每个位置的水位
                                // v体积的朋友，在x处落水，修改差分数组
                        // 生成最终的水位数组
                        // 开始收集答案
                        // 0...OFFSET这些位置是辅助位置，为了防止越界设计的
                        // 从OFFSET+1开始往下数m个，才是正式的位置1...m
                        // 打印这些位置，就是返回正式位置1...m的水位
                // 为了防止x - 3 * v + 1出现负数下标，进而有很多很烦的边界讨论
                // 所以任何位置，都加上一个较大的数字(OFFSET)
                // 这样一来，所有下标就都在0以上了，省去了大量边界讨论
                // 这就是为什么arr在初始化的时候要准备OFFSET + MAXN +
OFFSET这么多的空间
*/

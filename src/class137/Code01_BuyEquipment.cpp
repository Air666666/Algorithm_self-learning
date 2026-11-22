// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P3265

// Source: src/class137/Code01_BuyEquipment.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_BuyEquipment {
  inline static int MAXN = 502;
  inline static int MAXM = 502;
  inline static double sml = 1e-5;
  inline static Array<Array<double>> mat = make_array<double>(MAXN, MAXM);
  inline static Array<int> basis = make_array<int>(MAXN);
  inline static int n = {};
  inline static int m = {};
  inline static int cnt = {};
  inline static int cost = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_BuyEquipment() {}
  static void compute() {
    (cnt = (cost = 0));
    j::sort(mat, 1, (n + 1), [=](Array<double> a, Array<double> b) {
      return jcompare(a[(m + 1)], b[(m + 1)]);
    });
    for (int i = 1; (i <= n); (i++)) {
      if (Code01_BuyEquipment::insert(i)) {
        (cnt++);
        (cost += static_cast<int>(mat[i][(m + 1)]));
      }
    }
  }
  static bool insert(int i) {
    for (int j = 1; (j <= m); (j++)) {
      if ((std::abs(mat[i][j]) >= sml)) {
        if ((basis[j] == 0)) {
          (basis[j] = i);
          return true;
        }
        double rate = jdiv(mat[i][j], mat[basis[j]][j]);
        for (int k = j; (k <= m); (k++)) {
          (mat[i][k] -= (rate * mat[basis[j]][k]));
        }
      }
    }
    return false;
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    (n = static_cast<int>(in.nval));
    in.nextToken();
    (m = static_cast<int>(in.nval));
    for (int i = 1; (i <= n); (i++)) {
      for (int j = 1; (j <= m); (j++)) {
        in.nextToken();
        (mat[i][j] = static_cast<double>(in.nval));
      }
    }
    for (int i = 1; (i <= n); (i++)) {
      in.nextToken();
      (mat[i][(m + 1)] = static_cast<double>(in.nval));
    }
    Code01_BuyEquipment::compute();
    out.println(((cnt + String(u" ")) + cost));
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code01_BuyEquipment::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 装备购买
// 一共有n个物品，每个物品都有m个属性值
// 下面定义什么是不必要的物品：如果已经选择了k个物品，此时又有一件当前物品
// 如果给已经选择的物品分配一组相乘的系数，并把属性值相加，就能得到当前物品
// 那么就说当前物品是不必要的，比如下面的例子
// a = { 4, 6, 2 }, b = { 2, 8, 4 }, c = { 6, 19, 9 }
// a * 0.5 + b * 2 = c，那么c物品是不必要的
// 每个物品都有价格，现在希望尽量多的购买物品，但不能出现不必要的物品
// 返回最多能买几件物品和最少的花费
// 1 <= n、m <= 500
// 0 <= 属性值 <= 1000
// 测试链接 : https://www.luogu.com.cn/problem/P3265
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 记录的是物品编号
*/

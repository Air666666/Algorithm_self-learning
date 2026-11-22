// Source: src/class156/Code08_Gangster.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code08_Gangster {
  inline static int MAXN = 1001;
  inline static int n = {};
  inline static int m = {};
  inline static Array<int> father = make_array<int>(MAXN);
  inline static Array<int> enemy = make_array<int>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code08_Gangster() {}
  static void prepare() {
    for (int i = 1; (i <= n); (i++)) {
      (father[i] = i);
      (enemy[i] = 0);
    }
  }
  static int find(int i) {
    (father[i] = ((father[i] == i) ? i : Code08_Gangster::find(father[i])));
    return father[i];
  }
  static void union_method(int l, int r) {
    (father[Code08_Gangster::find(l)] = Code08_Gangster::find(r));
  }
  static void java_main(Array<String> args) {
    IO io = IO();
    (n = io.nextInt());
    (m = io.nextInt());
    Code08_Gangster::prepare();
    String op = {};
    int l = {};
    int r = {};
    for (int i = 1; (i <= m); (i++)) {
      (op = io.next());
      (l = io.nextInt());
      (r = io.nextInt());
      if (op.equals(String(u"F"))) {
        Code08_Gangster::union_method(l, r);
      } else {
        if ((enemy[l] == 0)) {
          (enemy[l] = r);
        } else {
          Code08_Gangster::union_method(enemy[l], r);
        }
        if ((enemy[r] == 0)) {
          (enemy[r] = l);
        } else {
          Code08_Gangster::union_method(l, enemy[r]);
        }
      }
    }
    int ans = 0;
    for (int i = 1; (i <= n); (i++)) {
      if ((i == father[i])) {
        (ans++);
      }
    }
    io.println(ans);
    io.flush();
    io.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code08_Gangster::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 团伙
// 注意洛谷关于本题的描述有问题，请按照如下的描述来理解题意
// 一共有n个黑帮成员，编号1 ~
n，发现了m条事实，每条事实一定属于如下两种类型中的一种
// F l r : l号成员和r号成员是朋友
// E l r : l号成员和r号成员是敌人
//
黑帮遵守如下的约定，敌人的敌人一定是朋友，朋友都来自同一个黑帮，敌人一定不是同一个黑帮
// 如果根据事实无法推断出一个成员有哪些朋友，那么该成员自己是一个黑帮
// 输入数据不存在矛盾，也就是任何两人不会推出既是朋友又是敌人的结论
// 遵守上面的约定，根据m条事实，计算黑帮有多少个
// 1 <= n <= 1000    1 <= m <= 5000
// 测试链接 : https://www.luogu.com.cn/problem/P1892
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 读写工具类
*/

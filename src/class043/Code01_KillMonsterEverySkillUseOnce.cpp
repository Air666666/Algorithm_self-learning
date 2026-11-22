// Source: src/class043/Code01_KillMonsterEverySkillUseOnce.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_KillMonsterEverySkillUseOnce {
  inline static int MAXN = 11;
  inline static Array<int> kill = make_array<int>(MAXN);
  inline static Array<int> blood = make_array<int>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_KillMonsterEverySkillUseOnce() {}
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    while ((in.nextToken() != -1)) {
      int t = static_cast<int>(in.nval);
      for (int i = 0; (i < t); (i++)) {
        in.nextToken();
        int n = static_cast<int>(in.nval);
        in.nextToken();
        int m = static_cast<int>(in.nval);
        for (int j = 0; (j < n); (j++)) {
          in.nextToken();
          (kill[j] = static_cast<int>(in.nval));
          in.nextToken();
          (blood[j] = static_cast<int>(in.nval));
        }
        int ans = Code01_KillMonsterEverySkillUseOnce::f(n, 0, m);
        out.println(((ans == std::numeric_limits<int>::max()) ? (-1) : ans));
      }
    }
    out.flush();
    br.close();
    out.close();
  }
  static int f(int n, int i, int r) {
    if ((r <= 0)) {
      return i;
    }
    if ((i == n)) {
      return std::numeric_limits<int>::max();
    }
    int ans = std::numeric_limits<int>::max();
    for (int j = i; (j < n); (j++)) {
      Code01_KillMonsterEverySkillUseOnce::swap(i, j);
      (ans = jmin(ans, Code01_KillMonsterEverySkillUseOnce::f(
                           n, (i + 1),
                           (r - ((r > blood[i]) ? kill[i] : (kill[i] * 2))))));
      Code01_KillMonsterEverySkillUseOnce::swap(i, j);
    }
    return ans;
  }
  static void swap(int i, int j) {
    int tmp = kill[i];
    (kill[i] = kill[j]);
    (kill[j] = tmp);
    (tmp = blood[i]);
    (blood[i] = blood[j]);
    (blood[j] = tmp);
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code01_KillMonsterEverySkillUseOnce::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 现在有一个打怪类型的游戏，这个游戏是这样的，你有n个技能
// 每一个技能会有一个伤害，
// 同时若怪物小于等于一定的血量，则该技能可能造成双倍伤害
// 每一个技能最多只能释放一次，已知怪物有m点血量
// 现在想问你最少用几个技能能消灭掉他(血量小于等于0)
// 技能的数量是n，怪物的血量是m
// i号技能的伤害是x[i]，i号技能触发双倍伤害的血量最小值是y[i]
// 1 <= n <= 10
// 1 <= m、x[i]、y[i] <= 10^6
// 测试链接 : https://www.nowcoder.com/practice/d88ef50f8dab4850be8cd4b95514bbbd
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下的所有代码，并把主类名改成"Main"
// 可以直接通过
        // kill[i]、blood[i]
        // n : 一共几个技能
        // i : 当前来到了第几号技能
        // r : 怪兽目前的剩余血量
                        // 之前的决策已经让怪兽挂了！返回使用了多少个节能
                // r > 0
                        // 无效，之前的决策无效
                // 返回至少需要几个技能可以将怪兽杀死
        // i号技能和j号技能，参数交换
        // j号技能要来到i位置，试一下
*/

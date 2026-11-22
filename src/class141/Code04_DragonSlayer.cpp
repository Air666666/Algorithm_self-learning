// Source: src/class141/Code04_DragonSlayer.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_DragonSlayer {
  inline static int MAXN = 100001;
  inline static Array<i64> hp = make_array<i64>(MAXN);
  inline static Array<i64> recovery = make_array<i64>(MAXN);
  inline static Array<i64> reward = make_array<i64>(MAXN);
  inline static Array<i64> init = make_array<i64>(MAXN);
  inline static Array<i64> attack = make_array<i64>(MAXN);
  inline static JTreeMap<i64, int> sorted = JTreeMap<i64, int>();
  inline static i64 d = {};
  inline static i64 x = {};
  inline static i64 y = {};
  inline static i64 px = {};
  inline static i64 py = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_DragonSlayer() {}
  static void exgcd(i64 a, i64 b) {
    if ((b == 0)) {
      (d = a);
      (x = 1);
      (y = 0);
    } else {
      Code04_DragonSlayer::exgcd(b, jrem(a, b));
      (px = x);
      (py = y);
      (x = py);
      (y = (px - (py * jdiv(a, b))));
    }
  }
  static i64 multiply(i64 a, i64 b, i64 mod) {
    (a = jrem((jrem(a, mod) + mod), mod));
    (b = jrem((jrem(b, mod) + mod), mod));
    i64 ans = 0;
    while ((b != 0)) {
      if (((b & 1) != 0)) {
        (ans = jrem((ans + a), mod));
      }
      (a = jrem((a + a), mod));
      (b = jshr(b, 1));
    }
    return ans;
  }
  static i64 allocate(int n, int m) {
    sorted.clear();
    for (int i = 1; (i <= m); (i++)) {
      sorted.put(init[i], (sorted.getOrDefault(init[i], 0) + 1));
    }
    i64 max = 0;
    for (int i = 1; (i <= n); (i++)) {
      Box<i64> sword = sorted.floorKey(hp[i]);
      if ((sword == nullptr)) {
        (sword = sorted.firstKey());
      }
      (attack[i] = sword);
      sorted.put(sword, (sorted.get(sword) - 1));
      if ((sorted.get(sword) == 0)) {
        sorted.remove(sword);
      }
      sorted.put(reward[i], (sorted.getOrDefault(reward[i], 0) + 1));
      (max = jmax(max, jdiv(((hp[i] + attack[i]) - 1), attack[i])));
      (hp[i] %= recovery[i]);
    }
    return max;
  }
  static i64 compute(int n, int m) {
    i64 max = Code04_DragonSlayer::allocate(n, m);
    i64 tail = 0;
    i64 lcm = 1;
    i64 tmp = {};
    i64 a = {};
    i64 b = {};
    i64 c = {};
    i64 x0 = {};
    for (int i = 1; (i <= n); (i++)) {
      (a = Code04_DragonSlayer::multiply(attack[i], lcm, recovery[i]));
      (b = recovery[i]);
      (c = jrem((jrem((hp[i] - (attack[i] * tail)), b) + b), b));
      Code04_DragonSlayer::exgcd(a, b);
      if ((jrem(c, d) != 0)) {
        return (-1);
      }
      (x0 = Code04_DragonSlayer::multiply(x, jdiv(c, d), jdiv(b, d)));
      (tmp = (lcm * jdiv(b, d)));
      (tail = jrem((tail + Code04_DragonSlayer::multiply(x0, lcm, tmp)), tmp));
      (lcm = tmp);
    }
    i64 ans = {};
    if ((tail >= max)) {
      (ans = tail);
    } else {
      (ans = ((jdiv((((max - tail) + lcm) - 1), lcm) * lcm) + tail));
    }
    return ans;
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    int cases = static_cast<int>(in.nval);
    for (int t = 1; (t <= cases); (t++)) {
      in.nextToken();
      int n = static_cast<int>(in.nval);
      in.nextToken();
      int m = static_cast<int>(in.nval);
      for (int i = 1; (i <= n); (i++)) {
        in.nextToken();
        (hp[i] = static_cast<i64>(in.nval));
      }
      for (int i = 1; (i <= n); (i++)) {
        in.nextToken();
        (recovery[i] = static_cast<i64>(in.nval));
      }
      for (int i = 1; (i <= n); (i++)) {
        in.nextToken();
        (reward[i] = static_cast<i64>(in.nval));
      }
      for (int i = 1; (i <= m); (i++)) {
        in.nextToken();
        (init[i] = static_cast<i64>(in.nval));
      }
      out.println(Code04_DragonSlayer::compute(n, m));
    }
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code04_DragonSlayer::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 屠龙勇士
// 一共n只巨龙，每只巨龙都有初始血量hp[i]，每只巨龙都有恢复能力recovery[i]
// 每只巨龙都会在攻击结束后开始恢复，初始一共m把剑，每把剑攻击力init[i]
//
每只巨龙只有当血量恰好为0时，才能被杀死。面对某只具体的龙，只能用固定的剑来攻击，规定如下：
//
攻击力不高于当前巨龙的血量，并且攻击力最大的一把剑，如果没有这样的剑，就选择攻击力最低的一把剑
//
需要按1~n的顺序依次讨伐巨龙，i号巨龙被杀后，那把攻击的剑会消失，同时奖励攻击力reward[i]的剑
//
勇士制定的策略如下，不管面对什么巨龙，攻击过程只打击ans下，让当前巨龙的血量<=0
//
然后在当前巨龙恢复的过程中，如果血量恰好为0，那么当前巨龙被杀死，勇士继续讨伐下一只
// 你的任务是算出最小的ans，让勇士可以在该策略下杀死所有巨龙
// 如果在固定打击次数的策略下，就是无法杀死所有巨龙，返回-1
// 查看数据范围可以打开测试链接 : https://www.luogu.com.cn/problem/P4774
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 讲解139 - 扩展欧几里得算法
        // 讲解033 - 位运算实现乘法
        // a*b过程每一步都%mod，这么写是防止溢出，也叫龟速乘
        // 每只怪物根据血量找到攻击的剑
        // 哪只龙需要砍最多次，才能让其血量<=0，返回最多的次数
                        // 血量 = 血量 % 恢复力，变成余数形式
        // bi * ans ≡ ri(% mi)方程组求解 + 本题对解的特殊处理
                // max变量很关键，最后的逻辑需要用到
                // 哪只龙需要砍最多次，才能让其血量<=0，这个最多的次数就是max
                // ans = lcm * x + tail
                        // ai * ans = ai * lcm * x + tail * ai  1号方程
                        // ai * ans = ri * y + hi               2号方程
                        // ai * lcm * x + ri * y = hi - tail * ai
                // 通解 ans = ? * lcm + tail
                // 下面属于本题的特殊处理，注意max变量的含义
                // 上面的大思路是，对每只怪兽，根据如下的公式，整理出同余式
                // ans * a[i] = h[i] + 每只怪兽若干恢复次数 * r[i]
                // 同余式为，ans * a[i] ≡ h[i] (% r[i])
                //
注意！能建立起的同余式，需要默认"每只怪兽若干恢复次数"的范围是整数
                // 最终解出，ans = k * lcm + tail，tail是最小正数解
                //
但实际情况是，"每只怪兽若干恢复次数"毫无疑问是非负的，并不是整个整数域
                //
也就是说，需要确保把每只怪兽的血量砍到<=0，然后才能保证，每只怪兽若干恢复次数>=0
                // 也就是说，ans = k * lcm + tail，需要确保，ans >=
max，注意max变量的含义！
                // 如果tail >= max，那么答案就是tail，此时k==0
                // 如果tail < max，想保证ans >= max，其实就是tail + k * lcm >=
max
                // k = (max - tail) / lcm，向上取整，也就是k = (max - tail + lcm
- 1) / lcm
                // 所以，ans = (max - tail + lcm - 1) / lcm * lcm + tail
*/

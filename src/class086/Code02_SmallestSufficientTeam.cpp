// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/smallest-sufficient-team/

// Source: src/class086/Code02_SmallestSufficientTeam.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_SmallestSufficientTeam {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_SmallestSufficientTeam() {}
  static Array<int> smallestSufficientTeam(Array<String> skills,
                                           JList<JList<String>> people) {
    int n = skills.length;
    int m = people.size();
    JMap<String, int> map = JMap<String, int>();
    int cnt = 0;
    for (String s : skills) {
      map.put(s, (cnt++));
    }
    Array<int> arr = make_array<int>(m);
    {
      int i = 0;
      int status = {};
      for (; (i < m); (i++)) {
        (status = 0);
        for (String skill : people.get(i)) {
          if (map.containsKey(skill)) {
            (status |= jshl(1, map.get(skill)));
          }
        }
        (arr[i] = status);
      }
    }
    Array<Array<int>> dp = make_array<int>(m, jshl(1, n));
    for (int i = 0; (i < m); (i++)) {
      j::fill(dp[i], (-1));
    }
    int size = Code02_SmallestSufficientTeam::f(arr, m, n, 0, 0, dp);
    Array<int> ans = make_array<int>(size);
    {
      int j = 0;
      int i = 0;
      int s = 0;
      for (; (s != (jshl(1, n) - 1)); (i++)) {
        if (((i == (m - 1)) || (dp[i][s] != dp[(i + 1)][s]))) {
          (ans[(j++)] = i);
          (s |= arr[i]);
        }
      }
    }
    return ans;
  }
  static int f(Array<int> arr, int m, int n, int i, int s,
               Array<Array<int>> dp) {
    if ((s == (jshl(1, n) - 1))) {
      return 0;
    }
    if ((i == m)) {
      return std::numeric_limits<int>::max();
    }
    if ((dp[i][s] != (-1))) {
      return dp[i][s];
    }
    int p1 = Code02_SmallestSufficientTeam::f(arr, m, n, (i + 1), s, dp);
    int p2 = std::numeric_limits<int>::max();
    int next2 =
        Code02_SmallestSufficientTeam::f(arr, m, n, (i + 1), (s | arr[i]), dp);
    if ((next2 != std::numeric_limits<int>::max())) {
      (p2 = (1 + next2));
    }
    int ans = jmin(p1, p2);
    (dp[i][s] = ans);
    return ans;
  }
};

/* Original teaching comments:
// 最小的必要团队
// 作为项目经理，你规划了一份需求的技能清单req_skills
// 并打算从备选人员名单people中选出些人组成必要团队
// 编号为i的备选人员people[i]含有一份该备选人员掌握的技能列表
// 所谓必要团队，就是在这个团队中
// 对于所需求的技能列表req_skills中列出的每项技能，团队中至少有一名成员已经掌握
// 请你返回规模最小的必要团队，团队成员用人员编号表示
// 你可以按 任意顺序 返回答案，题目数据保证答案存在
// 测试链接 : https://leetcode.cn/problems/smallest-sufficient-team/
                        // 把所有必要技能依次编号
                // arr[i] : 第i号人掌握必要技能的状况，用位信息表示
                                        // 如果当前技能是必要的
                                        // 才设置status
                        // s还没凑齐
                                // 当初的决策是选择了i号人
        // arr : 每个人所掌握的必要技能的状态
        // m : 人的总数
        // n : 必要技能的数量
        // i : 当前来到第几号人
        // s : 必要技能覆盖的状态
        // 返回 : i....这些人，把必要技能都凑齐，至少需要几个人
                        // 所有技能已经凑齐了
                // 没凑齐
                        // 人已经没了，技能也没凑齐
                        // 无效
                // 可能性1 : 不要i号人
                // 可能性2 : 要i号人
                        // 后续有效
*/

// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/number-of-music-playlists/

// Source: src/class099/Code06_NumberOfMusicPlaylists.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code06_NumberOfMusicPlaylists {
  inline static int MOD = 1000000007;
  inline static int LIMIT = 100;
  inline static Array<i64> fac = make_array<i64>((LIMIT + 1));
  inline static Array<i64> inv = make_array<i64>((LIMIT + 1));
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code06_NumberOfMusicPlaylists() {}
  static i64 power(i64 x, int n) {
    i64 ans = 1;
    while ((n > 0)) {
      if (((n & 1) == 1)) {
        (ans = jrem((ans * x), MOD));
      }
      (x = jrem((x * x), MOD));
      (n = jshr(n, 1));
    }
    return ans;
  }
  static int numMusicPlaylists(int n, int l, int k) {
    i64 cur = {};
    i64 ans = 0;
    i64 sign = 1;
    for (int i = 0; (i < (n - k));
         (i++), (sign = ((sign == 1) ? (MOD - 1) : 1))) {
      (cur = jrem((sign * Code06_NumberOfMusicPlaylists::power(((n - i) - k),
                                                               (l - k))),
                  MOD));
      (cur = jrem((cur * fac[n]), MOD));
      (cur = jrem((cur * inv[i]), MOD));
      (cur = jrem((cur * inv[((n - i) - k)]), MOD));
      (ans = jrem((ans + cur), MOD));
    }
    return static_cast<int>(ans);
  }
};

/* Original teaching comments:
// 播放列表的数量
// 给定三个参数，n、l、k
// 你的音乐播放器里有n首不同的歌
// 在旅途中你的旅伴想要听l首歌
// 听得歌曲不一定不同，即允许歌曲重复
// 请你为她按如下两条规则创建一个播放列表
// 1) 每首歌至少播放一次
// 2) 一首歌只有在其他k首歌播放完之后才能再次播放
// 返回可以满足要求的播放列表的数量
// 结果可能很大对1000000007取模
// 测试链接 : https://leetcode.cn/problems/number-of-music-playlists/
*/

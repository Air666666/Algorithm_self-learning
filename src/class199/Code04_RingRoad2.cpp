// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P1453

// Source: https://github.com/algorithmzuo/algorithm-journey/blob/8a7aa9993c3f5a8752c328831a5ddf9028ca18a1/src/class199/Code04_RingRoad2.java
// Restored from the upstream author's commented C++ implementation.
// 城市环路，C++版
// 图中有n个点、n条无向边，每个点有点权，图是一棵基环树
// 图中任意相邻两点不能同时选择，先得到最大的点权累加和
// 然后乘以题目给定的系数k，打印结果
// 1 <= n <= 10^5
// 测试链接 : https://www.luogu.com.cn/problem/P1453
// 如下实现是C++的版本，C++版本和java版本逻辑完全一样
// 提交如下代码，可以通过所有测试用例
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <exception>
#include <functional>
#include <iomanip>
#include <ios>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <string>
#include <tuple>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

using ll = long long;

const int MAXN = 100001;
int n;
double k;
int arr[MAXN];

int head[MAXN];
int nxt[MAXN << 1];
int to[MAXN << 1];
int cntg;

int dfn[MAXN];
int cntd;

int x, y, skip;

int dp[MAXN][2];

void addEdge(int u, int v) {
    nxt[++cntg] = head[u];
    to[cntg] = v;
    head[u] = cntg;
}

void dfs(int u) {
    dfn[u] = ++cntd;
    for (int e = head[u]; e > 0; e = nxt[e]) {
        int v = to[e];
        if (dfn[v] == 0) {
            dfs(v);
        } else if (dfn[u] < dfn[v]) {
            x = u;
            y = v;
            skip = (e + 1) >> 1;
        }
    }
}

void dpOnTree(int u, int fa) {
    dp[u][0] = 0;
    dp[u][1] = arr[u];
    for (int e = head[u]; e > 0; e = nxt[e]) {
        int v = to[e];
        if (v != fa && (e + 1) >> 1 != skip) {
            dpOnTree(v, u);
            dp[u][0] += max(dp[v][0], dp[v][1]);
            dp[u][1] += dp[v][0];
        }
    }
}

ll compute() {
    x = y = 0;
    dfs(1);
    dpOnTree(x, 0);
    ll ans = dp[x][0];
    dpOnTree(y, 0);
    ans = max(ans, 1ll * dp[y][0]);
    return ans;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 1, u, v; i <= n; i++) {
        scanf("%d%d", &u, &v);
        u++;
        v++;
        addEdge(u, v);
        addEdge(v, u);
    }
    scanf("%lf", &k);
    ll ans = compute();
    printf("%.1f\n", k * ans);
    return 0;
}

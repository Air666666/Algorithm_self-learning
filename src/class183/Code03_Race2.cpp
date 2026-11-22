// Source: https://github.com/algorithmzuo/algorithm-journey/blob/8a7aa9993c3f5a8752c328831a5ddf9028ca18a1/src/class183/Code03_Race2.java
// Restored from the upstream author's commented C++ implementation.
// 路径权值和为k的最少边数，C++版
// 一共有n个节点，给定n-1条边，每条边有边权，所有节点组成一棵树
// 给定数字k，要求找到路径权值和等于k的简单路径，并且边的数量最小
// 打印这个最小的边数，如果不存在路径权值和等于k的简单路径，那么打印-1
// 注意，本题给定的点的编号从0开始
// 1 <= n <= 2 * 10^5
// 0 <= 边权、k <= 10^6
// 测试链接 : https://www.luogu.com.cn/problem/P4149
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

struct Node {
    int dis, edge;
};

const int MAXN = 200001;
const int MAXK = 1000001;
const int INF = 1000000001;
int n, k;

int head[MAXN];
int nxt[MAXN << 1];
int to[MAXN << 1];
int weight[MAXN << 1];
int cntg;

bool vis[MAXN];
int siz[MAXN];

Node cur[MAXN];
int cntc;

int allDis[MAXN];
int cnta;

int dp[MAXK];

void addEdge(int u, int v, int w) {
    nxt[++cntg] = head[u];
    to[cntg] = v;
    weight[cntg] = w;
    head[u] = cntg;
}

void getSize(int u, int fa) {
    siz[u] = 1;
    for (int e = head[u]; e; e = nxt[e]) {
        int v = to[e];
        if (v != fa && !vis[v]) {
            getSize(v, u);
            siz[u] += siz[v];
        }
    }
}

int getCentroid(int u, int fa) {
    getSize(u, fa);
    int half = siz[u] >> 1;
    bool find = false;
    while (!find) {
        find = true;
        for (int e = head[u]; e; e = nxt[e]) {
            int v = to[e];
            if (v != fa && !vis[v] && siz[v] > half) {
                fa = u;
                u = v;
                find = false;
                break;
            }
        }
    }
    return u;
}

void dfs(int u, int fa, int dis, int edge) {
    if (dis > k) {
        return;
    }
    cur[++cntc] = { dis, edge };
    for (int e = head[u]; e; e = nxt[e]) {
        int v = to[e];
        if (v != fa && !vis[v]) {
            dfs(v, u, dis + weight[e], edge + 1);
        }
    }
}

int calc(int u) {
    int ans = INF;
    cnta = 0;
    dp[0] = 0;
    for (int e = head[u]; e; e = nxt[e]) {
        int v = to[e];
        if (!vis[v]) {
            cntc = 0;
            dfs(v, u, weight[e], 1);
            for (int i = 1; i <= cntc; i++) {
                ans = min(ans, dp[k - cur[i].dis] + cur[i].edge);
            }
            for (int i = 1; i <= cntc; i++) {
                allDis[++cnta] = cur[i].dis;
                dp[cur[i].dis] = min(dp[cur[i].dis], cur[i].edge);
            }
        }
    }
    for (int i = 1; i <= cnta; i++) {
        dp[allDis[i]] = INF;
    }
    return ans;
}

int solve(int u) {
    vis[u] = true;
    int ans = calc(u);
    for (int e = head[u]; e; e = nxt[e]) {
        int v = to[e];
        if (!vis[v]) {
            ans = min(ans, solve(getCentroid(v, u)));
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    for (int i = 1, u, v, w; i < n; i++) {
        cin >> u >> v >> w;
        u++;
        v++;
        addEdge(u, v, w);
        addEdge(v, u, w);
    }
    fill(dp, dp + MAXK, INF);
    int ans = solve(getCentroid(1, 0));
    if (ans == INF) {
        ans = -1;
    }
    cout << ans << '\n';
    return 0;
}

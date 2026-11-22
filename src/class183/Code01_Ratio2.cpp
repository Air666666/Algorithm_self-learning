// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P2634

// Source: https://github.com/algorithmzuo/algorithm-journey/blob/8a7aa9993c3f5a8752c328831a5ddf9028ca18a1/src/class183/Code01_Ratio2.java
// Restored from the upstream author's commented C++ implementation.
// 聪聪可可，C++版
// 一共有n个节点，给定n-1条边，每条边有边权，所有节点组成一棵树
// 如果点对(u, v)的简单路径权值和能被3整除，则称这个点对是合法的
// 认为点对(x, x)的简单路径权值和是0，并且认为(x, y)和(y, x)是不同的点对
// 打印(合法点对的数量 / 点对的总数量)的最简分数形式
// 1 <= n、边权 <= 2 * 10^4
// 测试链接 : https://www.luogu.com.cn/problem/P2634
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

const int MAXN = 20001;
int n;

int head[MAXN];
int nxt[MAXN << 1];
int to[MAXN << 1];
int weight[MAXN << 1];
int cntg;

bool vis[MAXN];
int siz[MAXN];

int cur[3];
int all[3];

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

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

void dfs(int u, int fa, int dis) {
    cur[dis % 3]++;
    for (int e = head[u]; e; e = nxt[e]) {
        int v = to[e];
        if (v != fa && !vis[v]) {
            dfs(v, u, dis + weight[e]);
        }
    }
}

int calc(int u) {
    int ans = 1;
    all[0] = all[1] = all[2] = 0;
    for (int e = head[u]; e; e = nxt[e]) {
        int v = to[e];
        int w = weight[e];
        if (!vis[v]) {
            cur[0] = cur[1] = cur[2] = 0;
            dfs(v, u, w);
            ans += all[0] * cur[0] * 2 + all[1] * cur[2] * 2 + all[2] * cur[1] * 2 + cur[0] * 2;
            all[0] += cur[0];
            all[1] += cur[1];
            all[2] += cur[2];
        }
    }
    return ans;
}

int solve(int u) {
    int ans = 0;
    vis[u] = true;
    ans += calc(u);
    for (int e = head[u]; e; e = nxt[e]) {
        int v = to[e];
        if (!vis[v]) {
            ans += solve(getCentroid(v, u));
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1, u, v, w; i < n; i++) {
        cin >> u >> v >> w;
        addEdge(u, v, w);
        addEdge(v, u, w);
    }
    int centroid = getCentroid(1, 0);
    int a = solve(centroid);
    int b = n * n;
    int c = gcd(a, b);
    a /= c;
    b /= c;
    cout << a << "/" << b << '\n';
    return 0;
}

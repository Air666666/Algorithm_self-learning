// Source: https://github.com/algorithmzuo/algorithm-journey/blob/8a7aa9993c3f5a8752c328831a5ddf9028ca18a1/src/class183/Code02_Exist2.java
// Restored from the upstream author's commented C++ implementation.
// 距离为k的点对是否存在，C++版
// 一共有n个节点，给定n-1条边，每条边有边权，所有节点组成一棵树
// 一共有m条查询，每条查询给定数字k，打印树上距离为k的点对是否存在
// 1 <= n <= 10^4    1 <= 边权 <= 10^4
// 1 <= m <= 100     1 <= k <= 10^7
// 测试链接 : https://www.luogu.com.cn/problem/P3806
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

const int MAXN = 10001;
const int MAXM = 101;
const int MAXV = 10000001;
int n, m;

int query[MAXM];
int maxk;

int head[MAXN];
int nxt[MAXN << 1];
int to[MAXN << 1];
int weight[MAXN << 1];
int cntg;

bool vis[MAXN];
int siz[MAXN];

int cur[MAXN];
int cntc;
int all[MAXN];
int cnta;
bool exist[MAXV];

bool ans[MAXM];

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
    if (dis > maxk) {
        return;
    }
    cur[++cntc] = dis;
    for (int e = head[u]; e; e = nxt[e]) {
        int v = to[e];
        if (v != fa && !vis[v]) {
            dfs(v, u, dis + weight[e]);
        }
    }
}

void calc(int u) {
    cnta = 0;
    exist[0] = true;
    for (int e = head[u]; e; e = nxt[e]) {
        int v = to[e];
        if (!vis[v]) {
            cntc = 0;
            dfs(v, u, weight[e]);
            for (int i = 1; i <= m; i++) {
                for (int j = 1; !ans[i] && j <= cntc; j++) {
                    if (query[i] - cur[j] >= 0) {
                        ans[i] |= exist[query[i] - cur[j]];
                    }
                }
            }
            for (int i = 1; i <= cntc; i++) {
                all[++cnta] = cur[i];
                exist[cur[i]] = true;
            }
        }
    }
    for (int i = 1; i <= cnta; i++) {
        exist[all[i]] = false;
    }
}

void solve(int u) {
    vis[u] = true;
    calc(u);
    for (int e = head[u]; e; e = nxt[e]) {
        int v = to[e];
        if (!vis[v]) {
            solve(getCentroid(v, u));
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1, u, v, w; i < n; i++) {
        cin >> u >> v >> w;
        addEdge(u, v, w);
        addEdge(v, u, w);
    }
    for (int i = 1; i <= m; i++) {
        cin >> query[i];
        maxk = max(maxk, query[i]);
    }
    solve(getCentroid(1, 0));
    for (int i = 1; i <= m; i++) {
        if (ans[i]) {
            cout << "AYE" << '\n';
        } else {
            cout << "NAY" << '\n';
        }
    }
    return 0;
}

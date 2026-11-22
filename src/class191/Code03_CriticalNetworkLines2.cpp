// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P7687

// Source: https://github.com/algorithmzuo/algorithm-journey/blob/8a7aa9993c3f5a8752c328831a5ddf9028ca18a1/src/class191/Code03_CriticalNetworkLines2.java
// Restored from the upstream author's commented C++ implementation.
// 关键网络线路，C++版
// 给定一张无向图，一共n个点、m条边，保证所有点连通
// 给定k个提供A服务的节点，给定l个提供B服务的节点，保证k和l都是正数
// 一个节点可能不提供服务，也可能提供A服务或者B服务或者两种都有
// 每个节点可以通过边，获得任何节点提供的服务，但是必须同时获得两种服务
// 如果断开某一条边，使得某些节点无法同时获得两种服务，这样的边叫关键边
// 打印关键边的数量，打印每条关键边的两个端点
// 1 <= n <= 10^5
// 1 <= m <= 10^6
// 测试链接 : https://www.luogu.com.cn/problem/P7687
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

const int MAXN = 100001;
const int MAXM = 1000001;
int n, m, k, l;
int acnt[MAXN];
int bcnt[MAXN];

int head[MAXN];
int nxt[MAXM << 1];
int to[MAXM << 1];
int cntg;

int dfn[MAXN];
int low[MAXN];
int cntd;

int ans1[MAXN];
int ans2[MAXN];
int cnta;

void addEdge(int u, int v) {
    nxt[++cntg] = head[u];
    to[cntg] = v;
    head[u] = cntg;
}

void tarjan(int u, int preEdge) {
    dfn[u] = low[u] = ++cntd;
    for (int e = head[u]; e > 0; e = nxt[e]) {
        if ((e ^ 1) == preEdge) {
            continue;
        }
        int v = to[e];
        if (dfn[v] == 0) {
            tarjan(v, e);
            low[u] = min(low[u], low[v]);
            if (low[v] > dfn[u]) {
                if (acnt[v] == 0 || acnt[v] == k || bcnt[v] == 0 || bcnt[v] == l) {
                    cnta++;
                    ans1[cnta] = v;
                    ans2[cnta] = u;
                }
            }
            acnt[u] += acnt[v];
            bcnt[u] += bcnt[v];
        } else {
            low[u] = min(low[u], dfn[v]);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cntg = 1;
    cin >> n >> m >> k >> l;
    for (int i = 1, x; i <= k; i++) {
        cin >> x;
        acnt[x] = 1;
    }
    for (int i = 1, x; i <= l; i++) {
        cin >> x;
        bcnt[x] = 1;
    }
    for (int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        addEdge(u, v);
        addEdge(v, u);
    }
    tarjan(1, 0);
    cout << cnta << "\n";
    for (int i = 1; i <= cnta; i++) {
        cout << ans1[i] << " " << ans2[i] << "\n";
    }
    return 0;
}

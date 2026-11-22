// Source: https://github.com/algorithmzuo/algorithm-journey/blob/8a7aa9993c3f5a8752c328831a5ddf9028ca18a1/src/class208/Code01_EdmondsKarp2.java
// Restored from the upstream author's commented C++ implementation.
// Edmonds-Karp算法，C++版
// 图中一共n个点，m条有向边，给定源点s和汇点t
// 给定每条有向边的起点、终点、容量
// 计算源点s到汇点t的网络最大流
// 1 <= n <= 200
// 1 <= m <= 5000
// 边的容量为非负整数
// 测试链接 : https://www.luogu.com.cn/problem/P3376
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

const int MAXN = 201;
const int MAXM = 5001;
ll INF = 1LL << 60;
int n, m;

int head[MAXN];
int nxt[MAXM << 1];
int to[MAXM << 1];
int limit[MAXM << 1];
int cntg;

ll flow[MAXN];
int pre[MAXN];
int que[MAXN];

void addEdge(int u, int v, int w) {
    nxt[++cntg] = head[u];
    to[cntg] = v;
    limit[cntg] = w;
    head[u] = cntg;
}

void bfs(int s, int t) {
    fill(flow + 1, flow + n + 1, -1);
    flow[s] = INF;
    int l = 1, r = 0;
    que[++r] = s;
    while (l <= r) {
        int u = que[l++];
        for (int e = head[u]; e > 0; e = nxt[e]) {
            int v = to[e];
            int lim = limit[e];
            if (lim > 0 && flow[v] == -1) {
                flow[v] = min(flow[u], (ll) lim);
                pre[v] = e;
                if (v == t) {
                    return;
                }
                que[++r] = v;
            }
        }
    }
}

ll maxflow(int s, int t) {
    ll ans = 0;
    bfs(s, t);
    while (flow[t] != -1) {
        ans += flow[t];
        for (int u = t; u != s; u = to[pre[u] ^ 1]) {
            limit[pre[u]] -= flow[t];
            limit[pre[u] ^ 1] += flow[t];
        }
        bfs(s, t);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int s, t;
    cin >> n >> m >> s >> t;
    cntg = 1;
    for (int i = 1, u, v, w; i <= m; i++) {
        cin >> u >> v >> w;
        addEdge(u, v, w);
        addEdge(v, u, 0);
    }
    ll ans = maxflow(s, t);
    cout << ans << '\n';
    return 0;
}

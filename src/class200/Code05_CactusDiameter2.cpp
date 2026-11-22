// Source: https://github.com/algorithmzuo/algorithm-journey/blob/8a7aa9993c3f5a8752c328831a5ddf9028ca18a1/src/class200/Code05_CactusDiameter2.java
// Restored from the upstream author's commented C++ implementation.
// 仙人掌直径，C++版
// 给定n个点、m条路径表示无向图，每条路径的相邻两点之间都有边
// 点x到点y的距离，是指x到y的最短路径中的边数
// 仙人掌直径，是指任意两点距离的最大值
// 输入保证图是仙人掌，计算仙人掌直径
// 1 <= n <= 5 * 10^4
// 1 <= 边总数 <= 10^6
// 测试链接 : https://www.luogu.com.cn/problem/P4244
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

const int MAXN = 50001;
const int MAXM = 1000001;
int n, m;

int head[MAXN];
int nxt[MAXM << 1];
int to[MAXM << 1];
int cntg;

int dfn[MAXN];
int low[MAXN];
int cntd;
int sta[MAXN];
int top;

int dist[MAXN];
int arr[MAXN << 1];
int que[MAXN << 1];
int diameter;

void addEdge(int u, int v) {
    nxt[++cntg] = head[u];
    to[cntg] = v;
    head[u] = cntg;
}

void dpOnCycle(int u, int v) {
    int siz = 0;
    arr[++siz] = dist[u];
    int pop;
    do {
        pop = sta[top--];
        arr[++siz] = dist[pop];
    } while (pop != v);
    for (int i = 1; i <= siz; i++) {
        arr[i + siz] = arr[i];
    }
    int l = 1, r = 0;
    que[++r] = 1;
    for (int i = 2; i <= siz << 1; i++) {
        while (l <= r && (i - que[l]) * 2 > siz) {
            l++;
        }
        diameter = max(diameter, arr[i] + i + arr[que[l]] - que[l]);
        while (l <= r && arr[que[r]] - que[r] <= arr[i] - i) {
            r--;
        }
        que[++r] = i;
    }
    for (int i = 2; i <= siz; i++) {
        dist[u] = max(dist[u], arr[i] + min(i - 1, siz - (i - 1)));
    }
}

void tarjan(int u, int preEdge) {
    dfn[u] = low[u] = ++cntd;
    sta[++top] = u;
    for (int e = head[u]; e > 0; e = nxt[e]) {
        if ((e ^ 1) == preEdge) {
            continue;
        }
        int v = to[e];
        if (dfn[v] == 0) {
            tarjan(v, e);
            if (low[v] < dfn[u]) {
                low[u] = min(low[u], low[v]);
            } else if (low[v] > dfn[u]) {
                top--;
                diameter = max(diameter, dist[u] + dist[v] + 1);
                dist[u] = max(dist[u], dist[v] + 1);
            } else {
                dpOnCycle(u, v);
            }
        } else if (dfn[v] < dfn[u]) {
            low[u] = min(low[u], dfn[v]);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    cntg = 1;
    for (int i = 1, k, x, y; i <= m; i++) {
        cin >> k >> x;
        for (int j = 2; j <= k; j++) {
            cin >> y;
            addEdge(x, y);
            addEdge(y, x);
            x = y;
        }
    }
    tarjan(1, 0);
    cout << diameter << "\n";
    return 0;
}

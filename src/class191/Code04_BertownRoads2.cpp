// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/CF118E
// https://codeforces.com/problemset/problem/118/E

// Source: https://github.com/algorithmzuo/algorithm-journey/blob/8a7aa9993c3f5a8752c328831a5ddf9028ca18a1/src/class191/Code04_BertownRoads2.java
// Restored from the upstream author's commented C++ implementation.
// 贝尔敦道路，C++版
// 给定一张无向图，一共n个点、m条边，保证所有点连通
// 每条无向边需要指定一个方向，变成有向边，还要保证任意两点互相可达
// 如果不存在方案打印0，如果存在方案，打印m条有向边
// 可以任意次序打印有向边，如果方案不只一种，打印其中一种即可
// 1 <= n <= 10^5
// 1 <= m <= 3 * 10^5
// 测试链接 : https://www.luogu.com.cn/problem/CF118E
// 测试链接 : https://codeforces.com/problemset/problem/118/E
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
const int MAXM = 300001;
int n, m;

int head[MAXN];
int nxt[MAXM << 1];
int to[MAXM << 1];
int cntg;

int dfn[MAXN];
int low[MAXN];
int cntd;

bool check;
int ans1[MAXM];
int ans2[MAXM];
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
        if (dfn[v] == 0 || dfn[v] < dfn[u]) {
            cnta++;
            ans1[cnta] = u;
            ans2[cnta] = v;
        }
        if (dfn[v] == 0) {
            tarjan(v, e);
            low[u] = min(low[u], low[v]);
            if (low[v] > dfn[u]) {
                check = false;
            }
        } else {
            low[u] = min(low[u], dfn[v]);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cntg = 1;
    cin >> n >> m;
    for (int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        addEdge(u, v);
        addEdge(v, u);
    }
    check = true;
    tarjan(1, 0);
    if (!check) {
        cout << 0 << "\n";
    } else {
        for (int i = 1; i <= m; i++) {
            cout << ans1[i] << " " << ans2[i] << "\n";
        }
    }
    return 0;
}

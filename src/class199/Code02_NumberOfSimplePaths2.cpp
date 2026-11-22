// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/CF1454E
// https://codeforces.com/problemset/problem/1454/E

// Source: https://github.com/algorithmzuo/algorithm-journey/blob/8a7aa9993c3f5a8752c328831a5ddf9028ca18a1/src/class199/Code02_NumberOfSimplePaths2.java
// Restored from the upstream author's commented C++ implementation.
// 简单路径数量，C++版
// 图中有n个点、n条无向边，图是一棵基环树，图中没有重边和自环
// 点x到点y的简单路径，要求没有重复节点，要求边的数量 >= 1
// 如果两条简单路径只有方向相反，那么认为是同一条简单路径，不要重复统计
// 比如(a, b, c)和(c, b, a)，就是同一条简单路径
// 计算图中简单路径的数量
// 3 <= n <= 2 * 10^5
// 测试链接 : https://www.luogu.com.cn/problem/CF1454E
// 测试链接 : https://codeforces.com/problemset/problem/1454/E
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

const int MAXN = 200001;
int t, n;

int head[MAXN];
int nxt[MAXN << 1];
int to[MAXN << 1];
int cntg;

int dfn[MAXN];
int cntd;

int from[MAXN];
bool cycle[MAXN];

ll siz[MAXN];

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
            from[v] = u;
            dfs(v);
        } else if (dfn[u] < dfn[v]) {
            cycle[u] = true;
            for (int i = v; i != u; i = from[i]) {
                cycle[i] = true;
            }
        }
    }
}

void dpOnTree(int u, int fa) {
    siz[u] = 1;
    for (int e = head[u]; e > 0; e = nxt[e]) {
        int v = to[e];
        if (v != fa && !cycle[v]) {
            dpOnTree(v, u);
            siz[u] += siz[v];
        }
    }
}

ll compute() {
    dfs(1);
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        if (cycle[i]) {
            dpOnTree(i, 0);
            ans += siz[i] * (siz[i] - 1) / 2 + siz[i] * (n - siz[i]);
        }
    }
    return ans;
}

void prepare() {
    cntg = cntd = 0;
    for (int i = 1; i <= n; i++) {
        head[i] = dfn[i] = 0;
        cycle[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    for (int c = 1; c <= t; c++) {
        cin >> n;
        prepare();
        for (int i = 1, u, v; i <= n; i++) {
            cin >> u >> v;
            addEdge(u, v);
            addEdge(v, u);
        }
        ll ans = compute();
        cout << ans << "\n";
    }
    return 0;
}

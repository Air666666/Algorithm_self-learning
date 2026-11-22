// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/CF427C
// https://codeforces.com/problemset/problem/427/C

// Source: https://github.com/algorithmzuo/algorithm-journey/blob/8a7aa9993c3f5a8752c328831a5ddf9028ca18a1/src/class189/Code08_Checkposts2.java
// Restored from the upstream author's commented C++ implementation.
// 检查站，C++版
// 给定一张n个点，m条边的有向图，每个点有点权
// 一个强连通分量内部，选点权最小的点，就能控制该连通分量里的所有点
// 你的目的是选择若干点之后，图上所有的点都能控制，打印最小点权和
// 打印选择点的方案数，方案数可能较大，对 1000000007 取余
// 1 <= n <= 10^5
// 1 <= m <= 3 * 10^5
// 测试链接 : https://www.luogu.com.cn/problem/CF427C
// 测试链接 : https://codeforces.com/problemset/problem/427/C
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
const int MOD = 1000000007;
int n, m;
int val[MAXN];

int head[MAXN];
int nxt[MAXM];
int to[MAXM];
int cntg;

int dfn[MAXN];
int low[MAXN];
int cntd;

int sta[MAXN];
int top;

int belong[MAXN];
int minVal[MAXN];
int minCnt[MAXN];
int sccCnt;

void addEdge(int u, int v) {
    nxt[++cntg] = head[u];
    to[cntg] = v;
    head[u] = cntg;
}

void tarjan(int u) {
    dfn[u] = low[u] = ++cntd;
    sta[++top] = u;
    for (int e = head[u]; e > 0; e = nxt[e]) {
        int v = to[e];
        if (dfn[v] == 0) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else {
            if (belong[v] == 0) {
                low[u] = min(low[u], dfn[v]);
            }
        }
    }
    if (dfn[u] == low[u]) {
        sccCnt++;
        minVal[sccCnt] = 1000000001;
        minCnt[sccCnt] = 0;
        int pop;
        do {
            pop = sta[top--];
            belong[pop] = sccCnt;
            if (minVal[sccCnt] > val[pop]) {
                minVal[sccCnt] = val[pop];
                minCnt[sccCnt] = 1;
            } else if (minVal[sccCnt] == val[pop]) {
                minCnt[sccCnt]++;
            }
        } while (pop != u);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> val[i];
    }
    cin >> m;
    for (int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        addEdge(u, v);
    }
    for (int i = 1; i <= n; i++) {
        if (dfn[i] == 0) {
            tarjan(i);
        }
    }
    long long ans1 = 0, ans2 = 1;
    for (int i = 1; i <= sccCnt; i++) {
        ans1 += minVal[i];
        ans2 = (ans2 * minCnt[i]) % MOD;
    }
    cout << ans1 << " " << ans2 << "\n";
    return 0;
}

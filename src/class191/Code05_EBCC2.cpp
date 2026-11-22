// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P8436

// Source: https://github.com/algorithmzuo/algorithm-journey/blob/8a7aa9993c3f5a8752c328831a5ddf9028ca18a1/src/class191/Code05_EBCC2.java
// Restored from the upstream author's commented C++ implementation.
// 边双连通分量模版题，C++版
// 给定一张无向图，一共n个点、m条边
// 图中可能存在多个连通区，对每个连通区求边双连通分量
// 先打印边双连通分量的总数量，然后对每个边双连通分量
// 打印节点个数，然后任意顺序打印该边双连通分量的节点
// 请保证原图即使有重边和自环，答案依然正确
// 1 <= n <= 5 * 10^5
// 1 <= m <= 2 * 10^6
// 测试链接 : https://www.luogu.com.cn/problem/P8436
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

const int MAXN = 500001;
const int MAXM = 2000001;
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

int ebccSiz[MAXN];
int ebccArr[MAXN];
int ebccl[MAXN];
int ebccr[MAXN];
int idx;
int ebccCnt;

void addEdge(int u, int v) {
    nxt[++cntg] = head[u];
    to[cntg] = v;
    head[u] = cntg;
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
            low[u] = min(low[u], low[v]);
        } else {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (dfn[u] == low[u]) {
        ebccCnt++;
        ebccSiz[ebccCnt] = 0;
        ebccl[ebccCnt] = idx + 1;
        int pop;
        do {
            pop = sta[top--];
            ebccSiz[ebccCnt]++;
            ebccArr[++idx] = pop;
        } while (pop != u);
        ebccr[ebccCnt] = idx;
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
    for (int i = 1; i <= n; i++) {
        if (dfn[i] == 0) {
            tarjan(i, 0);
        }
    }
    cout << ebccCnt << "\n";
    for (int i = 1; i <= ebccCnt; i++) {
        cout << ebccSiz[i] << "\n";
        for (int j = ebccl[i]; j <= ebccr[i]; j++) {
            cout << ebccArr[j] << " ";
        }
        cout << "\n";
    }
    return 0;
}

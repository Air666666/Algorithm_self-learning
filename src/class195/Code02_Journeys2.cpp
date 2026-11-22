// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P6348

// Source: https://github.com/algorithmzuo/algorithm-journey/blob/8a7aa9993c3f5a8752c328831a5ddf9028ca18a1/src/class195/Code02_Journeys2.java
// Restored from the upstream author's commented C++ implementation.
// 旅程，C++版
// 一共n个点，给定起点p，一共m次操作，格式如下
// 操作 a b c d : a~b范围每个点与c~d范围每个点之间，都增加一条无向边
// 所有操作完成后，计算起点p到每个点经过的最少边数，题目保证整体连通
// 1 <= n <= 5 * 10^5
// 1 <= m <= 10^5
// 测试链接 : https://www.luogu.com.cn/problem/P6348
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
const int MAXT = MAXN * 10;
const int MAXE = MAXN * 20;
const int INF = 1 << 30;
int n, m, p;

int head[MAXT];
int nxt[MAXE];
int to[MAXE];
int weight[MAXE];
int cntg;

int ls[MAXT];
int rs[MAXT];
int rootOut, rootIn;
int cntt;

int dist[MAXT];
deque<int> deq;

void addEdge(int u, int v, int w) {
    nxt[++cntg] = head[u];
    to[cntg] = v;
    weight[cntg] = w;
    head[u] = cntg;
}

int buildOut(int l, int r) {
    int rt;
    if (l == r) {
        rt = l;
    } else {
        rt = ++cntt;
        int mid = (l + r) >> 1;
        ls[rt] = buildOut(l, mid);
        rs[rt] = buildOut(mid + 1, r);
        addEdge(ls[rt], rt, 0);
        addEdge(rs[rt], rt, 0);
    }
    return rt;
}

int buildIn(int l, int r) {
    int rt;
    if (l == r) {
        rt = l;
    } else {
        rt = ++cntt;
        int mid = (l + r) >> 1;
        ls[rt] = buildIn(l, mid);
        rs[rt] = buildIn(mid + 1, r);
        addEdge(rt, ls[rt], 0);
        addEdge(rt, rs[rt], 0);
    }
    return rt;
}

void xToRange(int jobx, int jobl, int jobr, int l, int r, int i) {
    if (jobl <= l && r <= jobr) {
        addEdge(jobx, i, 0);
    } else {
        int mid = (l + r) >> 1;
        if (jobl <= mid) {
            xToRange(jobx, jobl, jobr, l, mid, ls[i]);
        }
        if (jobr > mid) {
            xToRange(jobx, jobl, jobr, mid + 1, r, rs[i]);
        }
    }
}

void rangeToX(int jobl, int jobr, int jobx, int l, int r, int i) {
    if (jobl <= l && r <= jobr) {
        addEdge(i, jobx, 0);
    } else {
        int mid = (l + r) >> 1;
        if (jobl <= mid) {
            rangeToX(jobl, jobr, jobx, l, mid, ls[i]);
        }
        if (jobr > mid) {
            rangeToX(jobl, jobr, jobx, mid + 1, r, rs[i]);
        }
    }
}

void rangeToRange(int a, int b, int c, int d) {
    int x = ++cntt;
    int y = ++cntt;
    rangeToX(a, b, x, 1, n, rootOut);
    xToRange(y, c, d, 1, n, rootIn);
    addEdge(x, y, 1);
}

void bfs01() {
    for (int i = 1; i <= cntt; i++) {
        dist[i] = INF;
    }
    dist[p] = 0;
    deq.clear();
    deq.push_front(p);
    while (!deq.empty()) {
        int u = deq.front();
        deq.pop_front();
        for (int e = head[u]; e > 0; e = nxt[e]) {
            int v = to[e];
            int w = weight[e];
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                if (w == 0) {
                    deq.push_front(v);
                } else {
                    deq.push_back(v);
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> p;
    cntt = n;
    rootOut = buildOut(1, n);
    rootIn = buildIn(1, n);
    for (int i = 1, a, b, c, d; i <= m; i++) {
        cin >> a >> b >> c >> d;
        rangeToRange(a, b, c, d);
        rangeToRange(c, d, a, b);
    }
    bfs01();
    for (int i = 1; i <= n; i++) {
        cout << dist[i] << "\n";
    }
    return 0;
}

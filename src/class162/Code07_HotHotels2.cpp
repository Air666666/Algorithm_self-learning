// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P5904

// Source: https://github.com/algorithmzuo/algorithm-journey/blob/8a7aa9993c3f5a8752c328831a5ddf9028ca18a1/src/class162/Code07_HotHotels2.java
// Restored from the upstream author's commented C++ implementation.
// 火热旅馆，C++版
// 一共有n个节点，给定n-1条边，所有节点连成一棵树
// 三个点构成一个点组(a, b, c)，打乱顺序认为是同一个点组
// 求树上有多少点组，内部任意两个节点之间的距离是一样的
// 1 <= n <= 10^5
// 答案一定在long类型范围内
// 测试链接 : https://www.luogu.com.cn/problem/P5904
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
int n;

int head[MAXN];
int nxt[MAXN << 1];
int to[MAXN << 1];
int cntg;

int fa[MAXN];
int son[MAXN];
int len[MAXN];
int cntd;

int fid[MAXN];
int gid[MAXN];
long long f[MAXN];
long long g[MAXN << 1];
long long ans;

void setf(int u, int i, long long v) {
    f[fid[u] + i] = v;
}

long long getf(int u, int i) {
    return f[fid[u] + i];
}

void setg(int u, int i, long long v) {
    g[gid[u] + i] = v;
}

long long getg(int u, int i) {
    return g[gid[u] + i];
}

void addEdge(int u, int v) {
    nxt[++cntg] = head[u];
    to[cntg] = v;
    head[u] = cntg;
}

void dfs1(int u, int f) {
    fa[u] = f;
    for (int e = head[u], v; e > 0; e = nxt[e]) {
        v = to[e];
        if (v != f) {
            dfs1(v, u);
        }
    }
    for (int e = head[u], v; e > 0; e = nxt[e]) {
        v = to[e];
        if (v != f) {
            if (son[u] == 0 || len[son[u]] < len[v]) {
                son[u] = v;
            }
        }
    }
    len[u] = len[son[u]] + 1;
}

void dfs2(int u, int top) {
    fid[u] = cntd++;
    if (son[u] == 0) {
        gid[u] = fid[top] * 2;
        return;
    }
    dfs2(son[u], top);
    for (int e = head[u], v; e > 0; e = nxt[e]) {
        v = to[e];
        if (v != son[u] && v != fa[u]) {
            dfs2(v, v);
        }
    }
    gid[u] = gid[son[u]] + 1;
}

void dfs3(int u) {
    setf(u, 0, 1);
    if (son[u] == 0) {
        return;
    }
    dfs3(son[u]);
    for (int e = head[u], v; e > 0; e = nxt[e]) {
        v = to[e];
        if (v != son[u] && v != fa[u]) {
            dfs3(v);
        }
    }
    for (int e = head[u], v; e > 0; e = nxt[e]) {
        v = to[e];
        if (v != son[u] && v != fa[u]) {
            for (int i = 0; i <= len[v]; i++) {
                if (i < len[u] && i - 1 >= 0) {
                    ans += getg(u, i) * getf(v, i - 1);
                }
                if (i > 0 && i + 1 < len[v]) {
                    ans += getf(u, i) * getg(v, i + 1);
                }
            }
            for (int i = 0; i <= len[v]; i++) {
                if (i + 1 < len[v]) {
                    setg(u, i, getg(u, i) + getg(v, i + 1));
                }
                if (i - 1 >= 0) {
                    setg(u, i, getg(u, i) + getf(u, i) * getf(v, i - 1));
                }
            }
            for (int i = 0; i <= len[v]; i++) {
                if (i - 1 >= 0) {
                    setf(u, i, getf(u, i) + getf(v, i - 1));
                }
            }
        }
    }
    ans += getg(u, 0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        addEdge(u, v);
        addEdge(v, u);
    }
    dfs1(1, 0);
    dfs2(1, 1);
    dfs3(1);
    cout << ans << "\n";
    return 0;
}

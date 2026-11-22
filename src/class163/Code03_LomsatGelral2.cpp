// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/CF600E
// https://codeforces.com/problemset/problem/600/E

// Source: https://github.com/algorithmzuo/algorithm-journey/blob/8a7aa9993c3f5a8752c328831a5ddf9028ca18a1/src/class163/Code03_LomsatGelral2.java
// Restored from the upstream author's commented C++ implementation.
// 主导颜色累加和，C++版
// 一共有n个节点，编号1~n，给定n-1条边，所有节点连成一棵树，1号节点为树头
// 每个节点给定一种颜色值，主导颜色累加和定义如下
// 以x为头的子树上，哪种颜色出现最多，那种颜色就是主导颜色，主导颜色可能不止一种
// 所有主导颜色的值累加起来，每个主导颜色只累加一次，就是该子树的主导颜色累加和
// 打印1~n每个节点为头的子树的主导颜色累加和
// 1 <= n、颜色值 <= 10^5
// 测试链接 : https://www.luogu.com.cn/problem/CF600E
// 测试链接 : https://codeforces.com/problemset/problem/600/E
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
int color[MAXN];

int head[MAXN];
int nxt[MAXN << 1];
int to[MAXN << 1];
int cnt = 0;

int fa[MAXN];
int siz[MAXN];
int son[MAXN];

int colorCnt[MAXN];
int maxCnt[MAXN];
long long ans[MAXN];

void addEdge(int u, int v) {
    nxt[++cnt] = head[u];
    to[cnt] = v;
    head[u] = cnt;
}

void dfs1(int u, int f) {
    fa[u] = f;
    siz[u] = 1;
    for (int e = head[u], v; e > 0; e = nxt[e]) {
        v = to[e];
        if (v != f) {
            dfs1(v, u);
        }
    }
    for (int e = head[u], v; e > 0; e = nxt[e]) {
        v = to[e];
        if (v != f) {
            siz[u] += siz[v];
            if (son[u] == 0 || siz[son[u]] < siz[v]) {
                son[u] = v;
            }
        }
    }
}

void effect(int u, int h) {
    colorCnt[color[u]]++;
    if (colorCnt[color[u]] == maxCnt[h]) {
        ans[h] += color[u];
    } else if (colorCnt[color[u]] > maxCnt[h]) {
        maxCnt[h] = colorCnt[color[u]];
        ans[h] = color[u];
    }
    for (int e = head[u], v; e > 0; e = nxt[e]) {
        v = to[e];
        if (v != fa[u]) {
            effect(v, h);
        }
    }
}

void cancel(int u) {
    colorCnt[color[u]] = 0;
    maxCnt[u] = 0;
    for (int e = head[u], v; e > 0; e = nxt[e]) {
        v = to[e];
        if (v != fa[u]) {
            cancel(v);
        }
    }
}

void dfs2(int u, int keep) {
    for (int e = head[u], v; e > 0; e = nxt[e]) {
        v = to[e];
        if (v != fa[u] && v != son[u]) {
            dfs2(v, 0);
        }
    }
    if (son[u] != 0) {
        dfs2(son[u], 1);
    }
    maxCnt[u] = maxCnt[son[u]];
    ans[u] = ans[son[u]];
    colorCnt[color[u]]++;
    if (colorCnt[color[u]] == maxCnt[u]) {
        ans[u] += color[u];
    } else if (colorCnt[color[u]] > maxCnt[u]) {
        maxCnt[u] = colorCnt[color[u]];
        ans[u] = color[u];
    }
    for (int e = head[u], v; e > 0; e = nxt[e]) {
        v = to[e];
        if (v != fa[u] && v != son[u]) {
            effect(v, u);
        }
    }
    if (keep == 0) {
        cancel(u);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> color[i];
    }
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        addEdge(u, v);
        addEdge(v, u);
    }
    dfs1(1, 0);
    dfs2(1, 0);
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
    return 0;
}

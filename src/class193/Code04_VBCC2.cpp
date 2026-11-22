// Source: https://github.com/algorithmzuo/algorithm-journey/blob/8a7aa9993c3f5a8752c328831a5ddf9028ca18a1/src/class193/Code04_VBCC2.java
// Restored from the upstream author's commented C++ implementation.
// 点双连通分量模版题1，C++版
// 给定一张无向图，一共n个点、m条边，建图时忽略自环
// 打印点双连通分量的个数
// 打印每个点双连通分量的大小和节点编号
// 打印顺序随意
// 每个孤立点分配一个点双连通分量
// 1 <= n <= 5 * 10^5
// 1 <= m <= 2 * 10^6
// 测试链接 : https://www.luogu.com.cn/problem/P8435
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

int vbccSiz[MAXN];
int vbccArr[MAXN << 1];
int vbccl[MAXN];
int vbccr[MAXN];
int idx;
int vbccCnt;

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
            if (low[v] >= dfn[u]) {
                vbccCnt++;
                vbccSiz[vbccCnt] = 1;
                vbccArr[++idx] = u;
                vbccl[vbccCnt] = idx;
                int pop;
                do {
                    pop = sta[top--];
                    vbccSiz[vbccCnt]++;
                    vbccArr[++idx] = pop;
                } while (pop != v);
                vbccr[vbccCnt] = idx;
            }
        } else {
            low[u] = min(low[u], dfn[v]);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        if (u != v) {
            addEdge(u, v);
            addEdge(v, u);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (dfn[i] == 0) {
            if (head[i] == 0) {
                vbccCnt++;
                vbccSiz[vbccCnt] = 1;
                vbccArr[++idx] = i;
                vbccl[vbccCnt] = vbccr[vbccCnt] = idx;
            } else {
                tarjan(i);
            }
        }
    }
    cout << vbccCnt << "\n";
    for (int i = 1; i <= vbccCnt; i++) {
        cout << vbccSiz[i] << "\n";
        for (int j = vbccl[i]; j <= vbccr[i]; j++) {
            cout << vbccArr[j] << " ";
        }
        cout << "\n";
    }
    return 0;
}

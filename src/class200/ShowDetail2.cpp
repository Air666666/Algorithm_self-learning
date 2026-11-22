// Source: https://github.com/algorithmzuo/algorithm-journey/blob/8a7aa9993c3f5a8752c328831a5ddf9028ca18a1/src/class200/ShowDetail2.java
// Restored from the upstream author's commented C++ implementation.
// 仙人掌遍历和找环的过程，C++版
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
const int MAXM = 200001;

int head[MAXN];
int nxt[MAXM];
int to[MAXM];
int weight[MAXM];
int cntg;

int dfn[MAXN];
int low[MAXN];
int cntd;
int sta[MAXN];
int top;

int fromWeight[MAXN];

void tarjan(int u, int preEdge) {
    dfn[u] = low[u] = ++cntd;
    sta[++top] = u;
    for (int e = head[u]; e > 0; e = nxt[e]) {
        if ((e ^ 1) == preEdge) continue;
        int v = to[e], w = weight[e];
        if (dfn[v] == 0) {
            tarjan(v, e);
            fromWeight[v] = w; // 设置v的from信息
            if (low[v] < dfn[u]) { // 没有扎起口袋
                low[u] = min(low[u], low[v]);
            } else if (low[v] > dfn[u]) {
                // 发现割边，实现有关割边的处理
                top--;
            } else {
                // 发现了环，实现有关环的处理
            }
        } else {
            if (dfn[v] < dfn[u]) { // 发现回边
                fromWeight[v] = w; // 闭合边的信息给入环节点
                low[u] = min(low[u], dfn[v]);
            }
            // 如果发现弃边，一般什么也不做
        }
    }
}

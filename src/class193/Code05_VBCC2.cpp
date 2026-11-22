// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/B3610

// Source: https://github.com/algorithmzuo/algorithm-journey/blob/8a7aa9993c3f5a8752c328831a5ddf9028ca18a1/src/class193/Code05_VBCC2.java
// Restored from the upstream author's commented C++ implementation.
// 点双连通分量模版题2，C++版
// 给定一张无向图，一共n个点、m条边
// 忽略所有孤立点，打印点双连通分量的个数
// 打印每个点双连通分量内部的节点编号，编号按照从小到大组织
// 内部节点编号是一个序列，序列字典序小的点双连通分量先打印
// 1 <= n <= 5 * 10^4
// 1 <= m <= 3 * 10^5
// 测试链接 : https://www.luogu.com.cn/problem/B3610
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
const int MAXM = 300001;
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

vector<vector<int>> vbccArr;

bool VbccCmp(const vector<int> &o1, const vector<int> &o2) {
    int size = min(o1.size(), o2.size());
    for (int i = 0; i < size; i++) {
        if (o1[i] != o2[i]) {
            return o1[i] < o2[i];
        }
    }
    return o1.size() < o2.size();
}

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
            if (low[v] == dfn[u]) {
                vector<int> list;
                list.push_back(u);
                int pop;
                do {
                    pop = sta[top--];
                    list.push_back(pop);
                } while (pop != v);
                vbccArr.push_back(list);
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
        addEdge(u, v);
        addEdge(v, u);
    }
    for (int i = 1; i <= n; i++) {
        if (dfn[i] == 0 && head[i] > 0) {
            tarjan(i);
        }
    }
    cout << vbccArr.size() << "\n";
    for (int i = 0; i < vbccArr.size(); i++) {
        sort(vbccArr[i].begin(), vbccArr[i].end());
    }
    sort(vbccArr.begin(), vbccArr.end(), VbccCmp);
    for (int i = 0; i < vbccArr.size(); i++) {
        for (int node : vbccArr[i]) {
            cout << node << " ";
        }
        cout << "\n";
    }
    return 0;
}

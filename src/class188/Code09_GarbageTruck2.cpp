// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P3520

// Source: https://github.com/algorithmzuo/algorithm-journey/blob/8a7aa9993c3f5a8752c328831a5ddf9028ca18a1/src/class188/Code09_GarbageTruck2.java
// Restored from the upstream author's commented C++ implementation.
// 垃圾车，C++版
// 一共有n个点，m条无向边，所有点不保证连通
// 每条边的属性为 u v s t : u和v是端点，s是初始状态，t是最终状态
// 状态的数值只有0和1两种，当一辆车通过一条无向边，那么状态会翻转
// 一辆车的路线中，可以指定一个起点，最终回到起点，沿途的其他点不能重复经过
// 所有的边都要达成最终状态，所以需要若干辆车来完成这个目标
// 如果存在方案，提供任何一种方案即可，首先打印需要几辆车
// 然后对每辆车，先打印通过的边数，再打印依次到达了哪些点
// 如果不存在方案，打印"NIE"
// 1 <= n <= 10^5    1 <= m <= 10^6
// 测试链接 : https://www.luogu.com.cn/problem/P3520
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
const int MAXM = 2000001;
int n, m;

int head[MAXN];
int nxt[MAXM];
int to[MAXM];
int eid[MAXM];
int cntg;

bool visNode[MAXN];
bool visEdge[MAXM];

int deg[MAXN];
int cur[MAXN];

bool inpath[MAXN];
int path[MAXM];
int cntp;

int ansArr[MAXM];
int ansl[MAXM];
int ansr[MAXM];
int idx;
int cnta;

void addEdge(int u, int v, int id) {
    nxt[++cntg] = head[u];
    to[cntg] = v;
    eid[cntg] = id;
    head[u] = cntg;
}

void popCircle(int u) {
    cnta++;
    ansArr[++idx] = u;
    ansl[cnta] = idx;
    for (int pop = path[cntp--]; pop != u; pop = path[cntp--]) {
        inpath[pop] = false;
        ansArr[++idx] = pop;
    }
    inpath[u] = false;
    ansArr[++idx] = u;
    ansr[cnta] = idx;
}

void euler(int u) {
    visNode[u] = true;
    for (int e = cur[u]; e > 0; e = cur[u]) {
        cur[u] = nxt[e];
        if (!visEdge[eid[e]]) {
            visEdge[eid[e]] = true;
            euler(to[e]);
        }
    }
    if (inpath[u]) {
        popCircle(u);
    }
    inpath[u] = true;
    path[++cntp] = u;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1, u, v, s, t; i <= m; i++) {
        cin >> u >> v >> s >> t;
        if (s != t) {
            deg[u]++;
            deg[v]++;
            addEdge(u, v, i);
            addEdge(v, u, i);
        }
    }
    for (int i = 1; i <= n; i++) {
        cur[i] = head[i];
    }
    bool check = true;
    for (int i = 1; i <= n; i++) {
        if ((deg[i] & 1) == 1) {
            check = false;
            break;
        }
    }
    if (!check) {
        cout << "NIE\n";
    } else {
        for (int i = 1; i <= n; i++) {
            if (!visNode[i]) {
                euler(i);
            }
        }
        cout << cnta << "\n";
        for (int i = 1; i <= cnta; i++) {
            cout << (ansr[i] - ansl[i]) << " ";
            for (int j = ansl[i]; j <= ansr[i]; j++) {
                cout << ansArr[j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}

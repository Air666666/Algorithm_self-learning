// Source: https://github.com/algorithmzuo/algorithm-journey/blob/8a7aa9993c3f5a8752c328831a5ddf9028ca18a1/src/class167/Code03_AdditionOnSegments2.java
// Restored from the upstream author's commented C++ implementation.
// 打印所有合法数，C++版
// 一个长度为n的序列，一开始所有值都是0
// 一共有q条操作，每条操作为 l r k : 序列[l..r]范围上，每个数字加k
// 你可以随意选择操作来执行，但是每条操作只能执行一次
// 如果你能让序列中的最大值正好为v，那么v就算一个合法数
// 打印1~n范围内有多少合法数，并且从小到大打印所有的合法数
// 1 <= k <= n、q <= 10^4
// 测试链接 : https://www.luogu.com.cn/problem/CF981E
// 测试链接 : https://codeforces.com/problemset/problem/981/E
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

const int MAXN = 10001;
const int MAXT = 500001;
const int BIT = 10000;
const int DEEP = 20;

typedef bitset<BIT + 1> bs;

int n, q;
int head[MAXN << 2];
int nxt[MAXT];
int to[MAXT];
int cnt = 0;

bs dp;
bs backup[DEEP];
bs ans;

void addEdge(int i, int v) {
    nxt[++cnt] = head[i];
    to[cnt] = v;
    head[i] = cnt;
}

void add(int jobl, int jobr, int jobv, int l, int r, int i) {
    if (jobl <= l && r <= jobr) {
        addEdge(i, jobv);
    } else {
        int mid = (l + r) >> 1;
        if (jobl <= mid) {
            add(jobl, jobr, jobv, l, mid, i << 1);
        }
        if (jobr > mid) {
            add(jobl, jobr, jobv, mid + 1, r, i << 1 | 1);
        }
    }
}

void dfs(int l, int r, int i, int dep) {
    backup[dep] = dp;
    for (int e = head[i]; e > 0; e = nxt[e]) {
        dp |= dp << to[e];
    }
    if (l == r) {
        ans |= dp;
    } else {
        int mid = (l + r) >> 1;
        dfs(l, mid, i << 1, dep + 1);
        dfs(mid + 1, r, i << 1 | 1, dep + 1);
    }
    dp = backup[dep];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> q;
    for (int i = 1, l, r, k; i <= q; i++) {
        cin >> l >> r >> k;
        add(l, r, k, 1, n, 1);
    }
    dp[0] = 1;
    dfs(1, n, 1, 1);
    int ansCnt = 0;
    for (int i = 1; i <= n; i++) {
        if (ans[i] == 1) {
            ansCnt++;
        }
    }
    cout << ansCnt << '\n';
    for (int i = 1; i <= n; i++) {
        if (ans[i] == 1) {
            cout << i << ' ';
        }
    }
    cout << '\n';
    return 0;
}

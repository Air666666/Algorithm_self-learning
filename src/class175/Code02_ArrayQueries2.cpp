// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/CF797E
// https://codeforces.com/problemset/problem/797/E

// Source: https://github.com/algorithmzuo/algorithm-journey/blob/8a7aa9993c3f5a8752c328831a5ddf9028ca18a1/src/class175/Code02_ArrayQueries2.java
// Restored from the upstream author's commented C++ implementation.
// 数组查询，C++版
// 给定一个长度为n的数组arr，接下来有q条查询，查询格式如下
// 查询 p k : p 不断变成 p + arr[p] + k，直到 p > n 停止，打印操作次数
// 1 <= n、q <= 10 ^ 5
// 1 <= arr[i] <= n
// 测试链接 : https://www.luogu.com.cn/problem/CF797E
// 测试链接 : https://codeforces.com/problemset/problem/797/E
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
const int MAXB = 401;
int n, q, blen;
int arr[MAXN];
int dp[MAXN][MAXB];

int query(int p, int k) {
    if (k <= blen) {
        return dp[p][k];
    }
    int ans = 0;
    while (p <= n) {
        ans++;
        p += arr[p] + k;
    }
    return ans;
}

void prepare() {
    blen = (int)sqrt(n);
    for (int p = n; p >= 1; p--) {
        for (int k = 1; k <= blen; k++) {
            dp[p][k] = 1 + (p + arr[p] + k > n ? 0 : dp[p + arr[p] + k][k]);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    prepare();
    cin >> q;
    for (int i = 1, p, k; i <= q; i++) {
        cin >> p >> k;
        cout << query(p, k) << '\n';
    }
    return 0;
}

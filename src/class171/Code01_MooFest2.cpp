// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P5094

// Source: https://github.com/algorithmzuo/algorithm-journey/blob/8a7aa9993c3f5a8752c328831a5ddf9028ca18a1/src/class171/Code01_MooFest2.java
// Restored from the upstream author's commented C++ implementation.
// 奶牛音量和，C++版
// 一共有n只奶牛，每只奶牛给定，听力v、坐标x
// 任何一对奶牛产生的音量 = max(vi, vj) * 两只奶牛的距离
// 一共有n * (n - 1) / 2对奶牛，打印音量总和
// 1 <= n、v、x <= 5 * 10^4
// 测试链接 : https://www.luogu.com.cn/problem/P5094
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

struct Node {
    int v, x;
};

bool NodeCmp(Node a, Node b) {
    return a.v < b.v;
}

const int MAXN = 50001;
int n;
Node arr[MAXN];
Node tmp[MAXN];

long long merge(int l, int m, int r) {
    int p1, p2;
    long long rsum = 0, lsum = 0, ans = 0;
    for (p1 = l; p1 <= m; p1++) {
        rsum += arr[p1].x;
    }
    for (p1 = l - 1, p2 = m + 1; p2 <= r; p2++) {
        while (p1 + 1 <= m && arr[p1 + 1].x < arr[p2].x) {
            p1++;
            rsum -= arr[p1].x;
            lsum += arr[p1].x;
        }
        ans += (1LL * (p1 - l + 1) * arr[p2].x - lsum + rsum - 1LL * (m - p1) * arr[p2].x) * arr[p2].v;
    }
    p1 = l;
    p2 = m + 1;
    int i = l;
    while (p1 <= m && p2 <= r) {
        tmp[i++] = arr[p1].x <= arr[p2].x ? arr[p1++] : arr[p2++];
    }
    while (p1 <= m) {
        tmp[i++] = arr[p1++];
    }
    while (p2 <= r) {
        tmp[i++] = arr[p2++];
    }
    for (i = l; i <= r; i++) {
        arr[i] = tmp[i];
    }
    return ans;
}

long long cdq(int l, int r) {
    if (l == r) {
        return 0;
    }
    int mid = (l + r) / 2;
    return cdq(l, mid) + cdq(mid + 1, r) + merge(l, mid, r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i].v >> arr[i].x;
    }
    sort(arr + 1, arr + n + 1, NodeCmp);
    cout << cdq(1, n) << '\n';
    return 0;
}

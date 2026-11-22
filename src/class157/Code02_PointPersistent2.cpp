// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P3834

// Source: https://github.com/algorithmzuo/algorithm-journey/blob/8a7aa9993c3f5a8752c328831a5ddf9028ca18a1/src/class157/Code02_PointPersistent2.java
// Restored from the upstream author's commented C++ implementation.
// 单点修改的可持久化线段树模版题2，C++版
// 给定一个长度为n的数组arr，下标1~n，一共有m条查询
// 每条查询 l r k : 打印arr[l..r]中第k小的数字
// 1 <= n、m <= 2 * 10^5
// 0 <= arr[i] <= 10^9
// 测试链接 : https://www.luogu.com.cn/problem/P3834
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

const int MAXN = 200001;
const int MAXT = MAXN * 22;
int n, m, s;
int arr[MAXN];
int sorted[MAXN];
int root[MAXN];
int ls[MAXT];
int rs[MAXT];
int siz[MAXT];
int cnt;

int kth(int num) {
    int left = 1, right = s, mid, ans = 0;
    while (left <= right) {
        mid = (left + right) / 2;
        if (sorted[mid] <= num) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return ans;
}

int build(int l, int r) {
    int rt = ++cnt;
    siz[rt] = 0;
    if (l < r) {
        int mid = (l + r) / 2;
        ls[rt] = build(l, mid);
        rs[rt] = build(mid + 1, r);
    }
    return rt;
}

int insert(int jobi, int l, int r, int i) {
    int rt = ++cnt;
    ls[rt] = ls[i];
    rs[rt] = rs[i];
    siz[rt] = siz[i] + 1;
    if (l < r) {
        int mid = (l + r) / 2;
        if (jobi <= mid) {
            ls[rt] = insert(jobi, l, mid, ls[rt]);
        } else {
            rs[rt] = insert(jobi, mid + 1, r, rs[rt]);
        }
    }
    return rt;
}

int query(int jobk, int l, int r, int u, int v) {
    if (l == r) {
        return l;
    }
    int lsiz = siz[ls[v]] - siz[ls[u]];
    int mid = (l + r) / 2;
    if (lsiz >= jobk) {
        return query(jobk, l, mid, ls[u], ls[v]);
    } else {
        return query(jobk - lsiz, mid + 1, r, rs[u], rs[v]);
    }
}

void prepare() {
    cnt = 0;
    for (int i = 1; i <= n; i++) {
        sorted[i] = arr[i];
    }
    sort(sorted + 1, sorted + n + 1);
    s = 1;
    for (int i = 2; i <= n; i++) {
        if (sorted[s] != sorted[i]) {
            sorted[++s] = sorted[i];
        }
    }
    root[0] = build(1, s);
    for (int i = 1, x; i <= n; i++) {
        x = kth(arr[i]);
        root[i] = insert(x, 1, s, root[i - 1]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    prepare();
    for (int i = 1, l, r, k, rank; i <= m; i++) {
        cin >> l >> r >> k;
        rank = query(k, 1, s, root[l - 1], root[r]);
        cout << sorted[rank] << '\n';
    }
    return 0;
}

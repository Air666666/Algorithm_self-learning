// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P3157

// Source: https://github.com/algorithmzuo/algorithm-journey/blob/8a7aa9993c3f5a8752c328831a5ddf9028ca18a1/src/class170/Code02_DynamicInversion2.java
// Restored from the upstream author's commented C++ implementation.
// 动态逆序对，C++版
// 给定一个长度为n的排列，1~n所有数字都出现一次
// 如果，前面的数 > 后面的数，那么这两个数就组成一个逆序对
// 给定一个长度为m的数组，表示依次删除的数字
// 打印每次删除数字前，排列中一共有多少逆序对，一共m条打印
// 1 <= n <= 10^5
// 1 <= m <= 5 * 10^4
// 测试链接 : https://www.luogu.com.cn/problem/P3157
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
    int v, i, d, q;
};

bool NodeCmp(Node x, Node y) {
    return x.i < y.i;
}

const int MAXN = 100001;
const int MAXM = 50001;
int n, m;

int num[MAXN];
int pos[MAXN];
int del[MAXM];

Node arr[MAXN + MAXM];
int cnt = 0;

int tree[MAXN];

long long ans[MAXM];

int lowbit(int i) {
    return i & -i;
}

void add(int i, int v) {
    while (i <= n) {
        tree[i] += v;
        i += lowbit(i);
    }
}

int query(int i) {
    int ret = 0;
    while (i > 0) {
        ret += tree[i];
        i -= lowbit(i);
    }
    return ret;
}

void merge(int l, int m, int r) {
    int p1, p2;
    for (p1 = l - 1, p2 = m + 1; p2 <= r; p2++) {
        while (p1 + 1 <= m && arr[p1 + 1].i < arr[p2].i) {
            p1++;
            add(arr[p1].v, arr[p1].d);
        }
        ans[arr[p2].q] += arr[p2].d * (query(n) - query(arr[p2].v));
    }
    for (int i = l; i <= p1; i++) {
        add(arr[i].v, -arr[i].d);
    }
    for (p1 = m + 1, p2 = r; p2 > m; p2--) {
        while (p1 - 1 >= l && arr[p1 - 1].i > arr[p2].i) {
            p1--;
            add(arr[p1].v, arr[p1].d);
        }
        ans[arr[p2].q] += arr[p2].d * query(arr[p2].v - 1);
    }
    for (int i = m; i >= p1; i--) {
        add(arr[i].v, -arr[i].d);
    }
    sort(arr + l, arr + r + 1, NodeCmp);
}

void cdq(int l, int r) {
    if (l == r) {
        return;
    }
    int mid = (l + r) / 2;
    cdq(l, mid);
    cdq(mid + 1, r);
    merge(l, mid, r);
}

void prepare() {
    for (int i = 1; i <= n; i++) {
        arr[++cnt].v = num[i];
        arr[cnt].i = i;
        arr[cnt].d = 1;
        arr[cnt].q = 0;
    }
    for (int i = 1; i <= m; i++) {
        arr[++cnt].v = del[i];
        arr[cnt].i = pos[del[i]];
        arr[cnt].d = -1;
        arr[cnt].q = i;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> num[i];
        pos[num[i]] = i;
    }
    for (int i = 1; i <= m; i++) {
        cin >> del[i];
    }
    prepare();
    cdq(1, cnt);
    for (int i = 1; i < m; i++) {
        ans[i] += ans[i - 1];
    }
    for (int i = 0; i < m; i++) {
        cout << ans[i] << '\n';
    }
    return 0;
}

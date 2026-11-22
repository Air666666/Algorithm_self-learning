// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P3224

// Source: https://github.com/algorithmzuo/algorithm-journey/blob/8a7aa9993c3f5a8752c328831a5ddf9028ca18a1/src/class181/Code02_NeverLand2.java
// Restored from the upstream author's commented C++ implementation.
// 永无乡，C++版
// 一共有n个岛，每个岛分配到一个不同的数字，数字范围1~n
// 给定初始的m座桥梁，若干点会连通起来，接下来有q条操作，格式如下
// 操作 B x y : x号岛和y号岛之间新修建了一座桥
// 操作 Q x k : x号岛所在的连通区里，打印第k小的数字来自几号岛，不存在打印-1
// 1 <= n、m <= 10^5
// 测试链接 : https://www.luogu.com.cn/problem/P3224
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
const int MAXT = MAXN * 40;
int n, m, q;
int pos[MAXN];
int father[MAXN];

int root[MAXN];
int ls[MAXT];
int rs[MAXT];
int siz[MAXT];
int cntt;

void up(int i) {
    siz[i] = siz[ls[i]] + siz[rs[i]];
}

int add(int jobi, int l, int r, int i) {
    int rt = i;
    if (rt == 0) {
        rt = ++cntt;
    }
    if (l == r) {
        siz[rt]++;
    } else {
        int mid = (l + r) >> 1;
        if (jobi <= mid) {
            ls[rt] = add(jobi, l, mid, ls[rt]);
        } else {
            rs[rt] = add(jobi, mid + 1, r, rs[rt]);
        }
        up(rt);
    }
    return rt;
}

int merge(int l, int r, int t1, int t2) {
    if (t1 == 0 || t2 == 0) {
        return t1 + t2;
    }
    if (l == r) {
        siz[t1] += siz[t2];
    } else {
        int mid = (l + r) >> 1;
        ls[t1] = merge(l, mid, ls[t1], ls[t2]);
        rs[t1] = merge(mid + 1, r, rs[t1], rs[t2]);
        up(t1);
    }
    return t1;
}

int query(int jobk, int l, int r, int i) {
    if (i == 0 || jobk > siz[i]) {
        return -1;
    }
    if (l == r) {
        return pos[l];
    }
    int mid = (l + r) >> 1;
    if (siz[ls[i]] >= jobk) {
        return query(jobk, l, mid, ls[i]);
    } else {
        return query(jobk - siz[ls[i]], mid + 1, r, rs[i]);
    }
}

int find(int i) {
    if (i != father[i]) {
        father[i] = find(father[i]);
    }
    return father[i];
}

void Union(int x, int y) {
    int xfa = find(x);
    int yfa = find(y);
    if (xfa != yfa) {
        father[xfa] = yfa;
        root[yfa] = merge(1, n, root[yfa], root[xfa]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1, num; i <= n; i++) {
        cin >> num;
        pos[num] = i;
        father[i] = i;
        root[i] = add(num, 1, n, root[i]);
    }
    for (int i = 1, x, y; i <= m; i++) {
        cin >> x >> y;
        Union(x, y);
    }
    cin >> q;
    char op;
    int x, y, k;
    for (int i = 1; i <= q; i++) {
        cin >> op;
        if (op == 'B') {
            cin >> x >> y;
            Union(x, y);
        } else {
            cin >> x >> k;
            cout << query(k, 1, n, root[find(x)]) << '\n';
        }
    }
    return 0;
}

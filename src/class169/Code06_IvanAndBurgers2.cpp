// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/CF1100F
// https://codeforces.com/problemset/problem/1100/F

// Source: https://github.com/algorithmzuo/algorithm-journey/blob/8a7aa9993c3f5a8752c328831a5ddf9028ca18a1/src/class169/Code06_IvanAndBurgers2.java
// Restored from the upstream author's commented C++ implementation.
// 范围最大异或和，C++版
// 给定一个长度为n的数组arr，下标1~n，接下来有q条查询，格式如下
// 查询 l r : arr[l..r]中选若干个数，打印最大的异或和
// 1 <= n、q <= 5 * 10^5
// 0 <= arr[i] <= 10^6
// 测试链接 : https://www.luogu.com.cn/problem/CF1100F
// 测试链接 : https://codeforces.com/problemset/problem/1100/F
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
const int BIT = 21;
int n, q;

int arr[MAXN];
int qid[MAXN];
int l[MAXN];
int r[MAXN];

int baset[MAXN][BIT + 1];
int tmp[BIT + 1];

int lset[MAXN];
int rset[MAXN];

int ans[MAXN];

void insert(int* basis, int num) {
    for (int i = BIT; i >= 0; i--) {
        if ((num >> i) & 1) {
            if (basis[i] == 0) {
                basis[i] = num;
                return;
            }
            num ^= basis[i];
        }
    }
}

void clear(int* basis) {
    for (int i = 0; i <= BIT; i++) {
        basis[i] = 0;
    }
}

int maxEor(int* basis) {
    int ret = 0;
    for (int i = BIT; i >= 0; i--) {
        ret = max(ret, ret ^ basis[i]);
    }
    return ret;
}

void clone(int* b1, int* b2) {
    for (int i = 0; i <= BIT; i++) {
        b1[i] = b2[i];
    }
}

void merge(int* b1, int* b2) {
    clone(tmp, b1);
    for (int i = 0; i <= BIT; i++) {
        insert(tmp, b2[i]);
    }
}

void compute(int ql, int qr, int vl, int vr) {
    if (ql > qr) {
        return;
    }
    if (vl == vr) {
        for (int i = ql; i <= qr; i++) {
            ans[qid[i]] = arr[vl];
        }
    } else {
        int mid = (vl + vr) >> 1;
        clear(baset[mid]);
        insert(baset[mid], arr[mid]);
        for (int i = mid - 1; i >= vl; i--) {
            clone(baset[i], baset[i + 1]);
            insert(baset[i], arr[i]);
        }
        for (int i = mid + 1; i <= vr; i++) {
            clone(baset[i], baset[i - 1]);
            insert(baset[i], arr[i]);
        }
        int lsiz = 0, rsiz = 0;
        for (int i = ql, id; i <= qr; i++) {
            id = qid[i];
            if (r[id] < mid) {
                lset[++lsiz] = id;
            } else if (l[id] > mid) {
                rset[++rsiz] = id;
            } else {
                merge(baset[l[id]], baset[r[id]]);
                ans[id] = maxEor(tmp);
            }
        }
        for (int i = 1; i <= lsiz; i++) {
            qid[ql + i - 1] = lset[i];
        }
        for (int i = 1; i <= rsiz; i++) {
            qid[ql + lsiz + i - 1] = rset[i];
        }
        compute(ql, ql + lsiz - 1, vl, mid);
        compute(ql + lsiz, ql + lsiz + rsiz - 1, mid + 1, vr);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    cin >> q;
    for (int i = 1; i <= q; i++) {
        qid[i] = i;
        cin >> l[i] >> r[i];
    }
    compute(1, q, 1, n);
    for (int i = 1; i <= q; i++) {
        cout << ans[i] << '\n';
    }
    return 0;
}

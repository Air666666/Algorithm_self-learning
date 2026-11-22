// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P4396

// Source: https://github.com/algorithmzuo/algorithm-journey/blob/8a7aa9993c3f5a8752c328831a5ddf9028ca18a1/src/class179/Code05_Homework2.java
// Restored from the upstream author's commented C++ implementation.
// 作业，C++版
// 给定一个长度为n的数组arr，接下来有m条查询，格式如下
// 查询 l r a b : 打印arr[l..r]范围上的两个答案
//                答案1，数值范围在[a, b]的数字个数
//                答案2，数值范围在[a, b]的数字种数
// 1 <= 所有数据 <= 10^5
// 测试链接 : https://www.luogu.com.cn/problem/P4396
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

struct Query {
    int l, r, a, b, id;
};

const int MAXN = 100001;
const int MAXV = 100000;
const int MAXB = 401;
int n, m;
int arr[MAXN];
Query query[MAXN];
int bi[MAXN];
int bl[MAXB];
int br[MAXB];

int numCnt[MAXN];
int blockCnt[MAXB];
int blockKind[MAXB];

int ans1[MAXN];
int ans2[MAXN];

bool QueryCmp(Query &a, Query &b) {
    if (bi[a.l] != bi[b.l]) {
        return bi[a.l] < bi[b.l];
    }
    if (bi[a.l] & 1) {
        return a.r < b.r;
    } else {
        return a.r > b.r;
    }
}

void add(int x) {
    numCnt[x]++;
    blockCnt[bi[x]]++;
    if (numCnt[x] == 1) {
        blockKind[bi[x]]++;
    }
}

void del(int x) {
    numCnt[x]--;
    blockCnt[bi[x]]--;
    if (numCnt[x] == 0) {
        blockKind[bi[x]]--;
    }
}

void setAns(int a, int b, int id) {
    if (bi[a] == bi[b]) {
        for (int i = a; i <= b; i++) {
            if (numCnt[i] > 0) {
                ans1[id] += numCnt[i];
                ans2[id]++;
            }
        }
    } else {
        for (int i = a; i <= br[bi[a]]; i++) {
            if (numCnt[i] > 0) {
                ans1[id] += numCnt[i];
                ans2[id]++;
            }
        }
        for (int i = bl[bi[b]]; i <= b; i++) {
            if (numCnt[i] > 0) {
                ans1[id] += numCnt[i];
                ans2[id]++;
            }
        }
        for (int i = bi[a] + 1; i <= bi[b] - 1; i++) {
            ans1[id] += blockCnt[i];
            ans2[id] += blockKind[i];
        }
    }
}

void compute() {
    int winl = 1, winr = 0;
    for (int i = 1; i <= m; i++) {
        int jobl = query[i].l;
        int jobr = query[i].r;
        int joba = query[i].a;
        int jobb = query[i].b;
        int id = query[i].id;
        while (winl > jobl) {
            add(arr[--winl]);
        }
        while (winr < jobr) {
            add(arr[++winr]);
        }
        while (winl < jobl) {
            del(arr[winl++]);
        }
        while (winr > jobr) {
            del(arr[winr--]);
        }
        setAns(joba, jobb, id);
    }
}

void prepare() {
    int blen = (int)sqrt(MAXV);
    int bnum = (MAXV + blen - 1) / blen;
    for (int i = 1; i <= MAXV; i++) {
        bi[i] = (i - 1) / blen + 1;
    }
    for (int i = 1; i <= bnum; i++) {
        bl[i] = (i - 1) * blen + 1;
        br[i] = min(i * blen, MAXV);
    }
    sort(query + 1, query + m + 1, QueryCmp);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> query[i].l >> query[i].r >> query[i].a >> query[i].b;
        query[i].id = i;
    }
    prepare();
    compute();
    for (int i = 1; i <= m; i++) {
        cout << ans1[i] << ' ' << ans2[i] << '\n';
    }
    return 0;
}

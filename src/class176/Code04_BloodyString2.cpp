// Source: https://github.com/algorithmzuo/algorithm-journey/blob/8a7aa9993c3f5a8752c328831a5ddf9028ca18a1/src/class176/Code04_BloodyString2.java
// Restored from the upstream author's commented C++ implementation.
// 大爷的字符串题，C++版
// 给定一个长度为n的数组arr，一共有m条查询，格式如下
// 查询 l r : arr[l..r]范围上，众数出现了几次，打印次数的相反数
// 1 <= n、m <= 2 * 10^5
// 1 <= arr[i] <= 10^9
// 测试链接 : https://www.luogu.com.cn/problem/P3709
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
    int l, r, id;
};

const int MAXN = 200001;
int n, m;
int arr[MAXN];
int sorted[MAXN];
Query query[MAXN];
int bi[MAXN];

int cnt1[MAXN];
int cnt2[MAXN];
int maxCnt = 0;

int ans[MAXN];

bool QueryCmp(Query &a, Query &b) {
    if (bi[a.l] != bi[b.l]) {
        return bi[a.l] < bi[b.l];
    }
    return a.r < b.r;
}

int kth(int len, int num) {
    int left = 1, right = len, mid, ret = 0;
    while (left <= right) {
        mid = (left + right) >> 1;
        if (sorted[mid] <= num) {
        	ret = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return ret;
}

void del(int num) {
    if (cnt1[num] == maxCnt && cnt2[cnt1[num]] == 1) {
        maxCnt--;
    }
    cnt2[cnt1[num]]--;
    cnt1[num]--;
    cnt2[cnt1[num]]++;
}

void add(int num) {
    cnt2[cnt1[num]]--;
    cnt1[num]++;
    cnt2[cnt1[num]]++;
    maxCnt = max(maxCnt, cnt1[num]);
}

void prepare() {
    for (int i = 1; i <= n; i++) {
        sorted[i] = arr[i];
    }
    sort(sorted + 1, sorted + n + 1);
    int len = 1;
    for (int i = 2; i <= n; i++) {
        if (sorted[len] != sorted[i]) {
            sorted[++len] = sorted[i];
        }
    }
    for (int i = 1; i <= n; i++) {
        arr[i] = kth(len, arr[i]);
    }
    int blen = (int)sqrt(n);
    for (int i = 1; i <= n; i++) {
        bi[i] = (i - 1) / blen + 1;
    }
    sort(query + 1, query + m + 1, QueryCmp);
}

void compute() {
    int winl = 1, winr = 0;
    for (int i = 1; i <= m; i++) {
        int jobl = query[i].l;
        int jobr = query[i].r;
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
        ans[query[i].id] = maxCnt;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> query[i].l;
        cin >> query[i].r;
        query[i].id = i;
    }
    prepare();
    compute();
    for (int i = 1; i <= m; i++) {
        cout << -ans[i] << '\n';
    }
    return 0;
}

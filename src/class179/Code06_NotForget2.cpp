// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P5072

// Source: https://github.com/algorithmzuo/algorithm-journey/blob/8a7aa9993c3f5a8752c328831a5ddf9028ca18a1/src/class179/Code06_NotForget2.java
// Restored from the upstream author's commented C++ implementation.
// 盼君勿忘，C++版
// 一个序列中每种数字只保留一个，得到的累加和，叫做去重累加和
// 给定一个长度为n的数组arr，接下来是m条查询，查询格式如下
// 查询 l r p : arr[l..r]范围上，每个子序列的去重累加和，都累加起来 % p 的结果打印
// 1 <= n、m、arr[i] <= 10^5
// 1 <= p <= 10^9
// 测试链接 : https://www.luogu.com.cn/problem/P5072
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
    int l, r, p, id;
};

const int MAXN = 100001;
const int MAXB = 401;
int n, m;
int arr[MAXN];
Query query[MAXN];
int bi[MAXN];

int head;
int lst[MAXN];
int nxt[MAXN];

int cnt[MAXN];
long long sum[MAXN];

long long smlPower[MAXB];
long long bigPower[MAXB];

long long ans[MAXN];

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

void addNode(int x) {
    lst[head] = x;
    nxt[x] = head;
    head = x;
}

void delNode(int x) {
    if (x == head) {
        head = nxt[head];
        lst[head] = 0;
        nxt[x] = 0;
    } else {
        nxt[lst[x]] = nxt[x];
        lst[nxt[x]] = lst[x];
        lst[x] = 0;
        nxt[x] = 0;
    }
}

void add(int num) {
    if (cnt[num] > 0) {
        sum[cnt[num]] -= num;
    }
    if (cnt[num] > 0 && sum[cnt[num]] == 0) {
        delNode(cnt[num]);
    }
    cnt[num]++;
    if (cnt[num] > 0 && sum[cnt[num]] == 0) {
        addNode(cnt[num]);
    }
    if (cnt[num] > 0) {
        sum[cnt[num]] += num;
    }
}

void del(int num) {
    if (cnt[num] > 0) {
        sum[cnt[num]] -= num;
    }
    if (cnt[num] > 0 && sum[cnt[num]] == 0) {
        delNode(cnt[num]);
    }
    cnt[num]--;
    if (cnt[num] > 0 && sum[cnt[num]] == 0) {
        addNode(cnt[num]);
    }
    if (cnt[num] > 0) {
        sum[cnt[num]] += num;
    }
}

void setAns(int len, int p, int id) {
    int blockLen = (int)sqrt(len);
    int blockNum = (len + blockLen - 1) / blockLen;
    smlPower[0] = 1;
    for (int i = 1; i <= blockLen; i++) {
        smlPower[i] = (smlPower[i - 1] << 1) % p;
    }
    bigPower[0] = 1;
    for (int i = 1; i <= blockNum; i++) {
        bigPower[i] = (bigPower[i - 1] * smlPower[blockLen]) % p;
    }
    long long res = 0, p1, p2, tmp;
    p1 = bigPower[len / blockLen] * smlPower[len % blockLen] % p;
    for (int t = head; t > 0; t = nxt[t]) {
        p2 = bigPower[(len - t) / blockLen] * smlPower[(len - t) % blockLen] % p;
        tmp = (p1 - p2) * sum[t] % p;
        res = ((res + tmp) % p + p) % p;
    }
    ans[id] = res;
}

void compute() {
    int winl = 1, winr = 0;
    for (int i = 1; i <= m; i++) {
        int jobl = query[i].l;
        int jobr = query[i].r;
        int jobp = query[i].p;
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
        setAns(jobr - jobl + 1, jobp, id);
    }
}

void prepare() {
    int blen = (int)sqrt(n);
    for (int i = 1; i <= n; i++) {
        bi[i] = (i - 1) / blen + 1;
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
        cin >> query[i].l >> query[i].r >> query[i].p;
        query[i].id = i;
    }
    prepare();
    compute();
    for (int i = 1; i <= m; i++) {
        cout << ans[i] << '\n';
    }
    return 0;
}

// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P4098

// Source: https://github.com/algorithmzuo/algorithm-journey/blob/8a7aa9993c3f5a8752c328831a5ddf9028ca18a1/src/class159/Code05_ALO2.java
// Restored from the upstream author's commented C++ implementation.
// 生成能量密度最大的宝石，C++版
// 给定一个长度为n的数组arr，数组中没有重复数字
// 你可以随意选择一个子数组，长度要求大于等于2，因为这样一来，子数组必存在次大值
// 子数组的次大值 ^ 子数组中除了次大值之外随意选一个数字
// 所能得到的最大结果，叫做子数组的能量密度
// 那么必有某个子数组，拥有最大的能量密度，打印这个最大的能量密度
// 2 <= n <= 5 * 10^4
// 0 <= arr[i] <= 10^9
// 测试链接 : https://www.luogu.com.cn/problem/P4098
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

const int MAXN = 50002;
const int MAXT = MAXN * 32;
const int BIT = 30;
int n;
vector<pair<int, int>> arr;
int root[MAXN];
int tree[MAXT][2];
int pass[MAXT];
int cnt;
int last[MAXN];
int nxt[MAXN];

int insert(int num, int i) {
    int rt = ++cnt;
    tree[rt][0] = tree[i][0];
    tree[rt][1] = tree[i][1];
    pass[rt] = pass[i] + 1;
    for (int b = BIT, path, pre = rt, cur; b >= 0; b--, pre = cur) {
        path = (num >> b) & 1;
        i = tree[i][path];
        cur = ++cnt;
        tree[cur][0] = tree[i][0];
        tree[cur][1] = tree[i][1];
        pass[cur] = pass[i] + 1;
        tree[pre][path] = cur;
    }
    return rt;
}

int query(int num, int u, int v) {
    int ans = 0;
    for (int b = BIT, path, best; b >= 0; b--) {
        path = (num >> b) & 1;
        best = path ^ 1;
        if (pass[tree[v][best]] > pass[tree[u][best]]) {
            ans += 1 << b;
            u = tree[u][best];
            v = tree[v][best];
        } else {
            u = tree[u][path];
            v = tree[v][path];
        }
    }
    return ans;
}

void prepare() {
    last[0] = 0;
    nxt[0] = 1;
    last[n + 1] = n;
    nxt[n + 1] = n + 1;
    for (int i = 1; i <= n; i++) {
        root[i] = insert(arr[i].second, root[i - 1]);
        last[i] = i - 1;
        nxt[i] = i + 1;
    }
    sort(arr.begin() + 1, arr.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    });
}

int compute() {
    int ans = 0;
    for (int i = 1, index, value, l1, l2, r1, r2; i <= n; i++) {
        index = arr[i].first;
        value = arr[i].second;
        l1 = last[index];
        l2 = last[l1];
        r1 = nxt[index];
        r2 = nxt[r1];
        if (l1 != 0) {
            ans = max(ans, query(value, root[l2], root[r1 - 1]));
        }
        if (r1 != n + 1) {
            ans = max(ans, query(value, root[l1], root[r2 - 1]));
        }
        nxt[l1] = r1;
        last[r1] = l1;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    arr.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        arr[i].first = i;
        cin >> arr[i].second;
    }
    prepare();
    cout << compute() << "\n";
    return 0;
}

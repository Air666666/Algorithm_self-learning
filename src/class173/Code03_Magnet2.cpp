// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P10590
// https://codeforces.com/problemset/problem/198/E

// Source: https://github.com/algorithmzuo/algorithm-journey/blob/8a7aa9993c3f5a8752c328831a5ddf9028ca18a1/src/class173/Code03_Magnet2.java
// Restored from the upstream author's commented C++ implementation.
// 磁力块，C++版
// 磁块有五个属性值，x、y、m、p、range，磁块在(x, y)位置、质量为m、磁力为p、吸引半径range
// 磁块A可以把磁块B吸到磁块A的位置，需要满足如下的条件
// A与B的距离不大于A的吸引半径，并且B的质量不大于A的磁力
// 你有一个初始磁块，给定初始磁块的4个属性值(不给质量，因为没用)，你永远在初始磁块的位置
// 接下来给定n个磁块各自的5个属性值，你可以用初始磁块，吸过来其中的磁块
// 吸过来的磁块可以被你随意使用，返回你最多能吸过来多少磁块
// 1 <= n <= 3 * 10^5    -10^9 <= x、y <= +10^9    1 <= m、p、range <= 10^9
// 测试链接 : https://www.luogu.com.cn/problem/P10590
// 测试链接 : https://codeforces.com/problemset/problem/198/E
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
    int x, y, m, p;
    long long range;
    long long dist;
};

bool cmp1(Node &a, Node &b) {
    return a.m < b.m;
}

bool cmp2(Node &a, Node &b) {
    return a.dist < b.dist;
}

const int MAXN = 300001;
const int MAXB = 601;
int n;
Node arr[MAXN];

int blen, bnum;
int bi[MAXN];
int bl[MAXB];
int br[MAXB];
int maxm[MAXB];

int que[MAXN];
bool vis[MAXN];

int bfs() {
    int ans = 0;
    vis[0] = true;
    int l = 1, r = 1;
    que[r++] = 0;
    while (l < r) {
        int cur = que[l++];
        for (int b = 1; b <= bnum; b++) {
            if (maxm[b] <= arr[cur].p) {
                while (bl[b] <= br[b] && arr[bl[b]].dist <= arr[cur].range) {
                    int i = bl[b];
                    if (!vis[i]) {
                        vis[i] = true;
                        que[r++] = i;
                        ans++;
                    }
                    bl[b]++;
                }
            } else {
                for (int i = bl[b]; i <= br[b]; i++) {
                    if (arr[i].dist <= arr[cur].range && arr[i].m <= arr[cur].p && !vis[i]) {
                        vis[i] = true;
                        que[r++] = i;
                        ans++;
                    }
                }
                break;
            }
        }
    }
    return ans;
}

void prepare() {
    blen = (int)sqrt(n);
    bnum = (n + blen - 1) / blen;
    for (int i = 1; i <= n; i++) {
        bi[i] = (i - 1) / blen + 1;
    }
    for (int i = 1; i <= bnum; i++) {
        bl[i] = (i - 1) * blen + 1;
        br[i] = min(i * blen, n);
    }
    sort(arr + 1, arr + n + 1, cmp1);
    for (int i = 1; i <= bnum; i++) {
        maxm[i] = arr[br[i]].m;
        sort(arr + bl[i], arr + br[i] + 1, cmp2);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int x, y, m, p, range;
    cin >> x >> y >> p >> range >> n;
    arr[0] = {x, y, 0, p, range, 0};
    for (int i = 1; i <= n; i++) {
        cin >> x >> y >> m >> p >> range;
        arr[i] = {x, y, m, p, range, 0};
    }
    long long xd, yd;
    for (int i = 0; i <= n; i++) {
        arr[i].range = arr[i].range * arr[i].range;
        xd = arr[0].x - arr[i].x;
        yd = arr[0].y - arr[i].y;
        arr[i].dist = xd * xd + yd * yd;
    }
    prepare();
    cout << bfs() << '\n';
    return 0;
}

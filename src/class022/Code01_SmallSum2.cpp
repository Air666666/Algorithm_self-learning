// Source: https://github.com/algorithmzuo/algorithm-journey/blob/8a7aa9993c3f5a8752c328831a5ddf9028ca18a1/src/class022/Code01_SmallSum2.java
// Restored from the upstream author's commented C++ implementation.
// 小和问题，C++版
// 测试链接 : https://www.nowcoder.com/practice/edfe05a1d45c4ea89101d936cac32469
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
int n;

int arr[MAXN];
int help[MAXN];

long long merge(int l, int m, int r) {
    long long ans = 0;
    for (int j = m + 1, i = l, sum = 0; j <= r; j++) {
        while (i <= m && arr[i] <= arr[j]) {
            sum += arr[i++];
        }
        ans += sum;
    }
    int i = l, a = l, b = m + 1;
    while (a <= m && b <= r) {
        help[i++] = (arr[a] <= arr[b] ? arr[a++] : arr[b++]);
    }
    while (a <= m) {
        help[i++] = arr[a++];
    }
    while (b <= r) {
        help[i++] = arr[b++];
    }
    for (i = l; i <= r; i++) {
        arr[i] = help[i];
    }
    return ans;
}

long long smallSum(int l, int r) {
    if (l == r) {
        return 0;
    }
    int m = (l + r) >> 1;
    return smallSum(l, m) + smallSum(m + 1, r) + merge(l, m, r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while (cin >> n) {
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cout << smallSum(0, n - 1) << '\n';
    }
    return 0;
}

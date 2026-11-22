// Restored original C++ teaching code.
#include <algorithm>
#include <cctype>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <iostream>
#include <random>
#include <utility>
#include <vector>

using namespace std;

const int MAXN = 100001;

int head[MAXN];
int nxt[MAXN];
int to[MAXN];
int cntg;

int state[MAXN];
int from[MAXN];
bool cycle[MAXN];

bool dfs(int u) {
  state[u] = 1;
  bool find = false;
  for (int e = head[u]; e > 0; e = nxt[e]) {
    int v = to[e];
    if (state[v] == 0) {
      from[v] = u;
      if (dfs(v)) {
        find = true;
      }
    } else if (state[v] == 1) {
      cycle[v] = true;
      for (int i = u; i != v; i = from[i]) {
        cycle[i] = true;
      }
      find = true;
    }
    if (find) {
      break;
    }
  }
  state[u] = 2;
  return find;
}
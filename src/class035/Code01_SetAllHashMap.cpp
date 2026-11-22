// 原题测试 / 参考链接（保留上游原始地址）
// https://www.nowcoder.com/practice/7c4559f138e74ceb9ba57d76fd169967

// Source: src/class035/Code01_SetAllHashMap.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_SetAllHashMap {
  inline static JMap<int, Array<int>> map = JMap<int, Array<int>>();
  inline static int setAllValue = {};
  inline static int setAllTime = {};
  inline static int cnt = {};
  inline static int n = {};
  inline static int op = {};
  inline static int a = {};
  inline static int b = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_SetAllHashMap() {}
  static void put(int k, int v) {
    if (map.containsKey(k)) {
      Array<int> value = map.get(k);
      (value[0] = v);
      (value[1] = (cnt++));
    } else {
      map.put(k, Array<int>{v, (cnt++)});
    }
  }
  static void setAll(int v) {
    (setAllValue = v);
    (setAllTime = (cnt++));
  }
  static int get(int k) {
    if ((!map.containsKey(k))) {
      return (-1);
    }
    Array<int> value = map.get(k);
    if ((value[1] > setAllTime)) {
      return value[0];
    } else {
      return setAllValue;
    }
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    while ((in.nextToken() != -1)) {
      map.clear();
      (setAllValue = 0);
      (setAllTime = (-1));
      (cnt = 0);
      (n = static_cast<int>(in.nval));
      for (int i = 0; (i < n); (i++)) {
        in.nextToken();
        (op = static_cast<int>(in.nval));
        if ((op == 1)) {
          in.nextToken();
          (a = static_cast<int>(in.nval));
          in.nextToken();
          (b = static_cast<int>(in.nval));
          Code01_SetAllHashMap::put(a, b);
        } else if ((op == 2)) {
          in.nextToken();
          (a = static_cast<int>(in.nval));
          out.println(Code01_SetAllHashMap::get(a));
        } else {
          in.nextToken();
          (a = static_cast<int>(in.nval));
          Code01_SetAllHashMap::setAll(a);
        }
      }
    }
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code01_SetAllHashMap::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// setAll功能的哈希表
// 测试链接 : https://www.nowcoder.com/practice/7c4559f138e74ceb9ba57d76fd169967
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下的code，提交时请把类名改成"Main"，可以直接通过
*/

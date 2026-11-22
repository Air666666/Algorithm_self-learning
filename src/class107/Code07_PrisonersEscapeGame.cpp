// Source: src/class107/Code07_PrisonersEscapeGame.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code07_PrisonersEscapeGame {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code07_PrisonersEscapeGame() {}
  static double escape1(int people, int tryTimes, int testTimes) {
    int escape = 0;
    for (int i = 0; (i < testTimes); (i++)) {
      Array<int> arr = Code07_PrisonersEscapeGame::generateRandomArray(people);
      if ((Code07_PrisonersEscapeGame::maxCircle(arr) <= tryTimes)) {
        (escape++);
      }
    }
    return jdiv(static_cast<double>(escape), static_cast<double>(testTimes));
  }
  static int maxCircle(Array<int> arr) {
    int maxCircle = 1;
    for (int i = 0; (i < arr.length); (i++)) {
      int curCircle = 1;
      while ((i != arr[i])) {
        Code07_PrisonersEscapeGame::swap(arr, i, arr[i]);
        (curCircle++);
      }
      (maxCircle = jmax(maxCircle, curCircle));
    }
    return maxCircle;
  }
  static Array<int> generateRandomArray(int len) {
    Array<int> arr = make_array<int>(len);
    for (int i = 0; (i < len); (i++)) {
      (arr[i] = i);
    }
    for (int i = (len - 1); (i > 0); (i--)) {
      Code07_PrisonersEscapeGame::swap(
          arr, i, static_cast<int>((j::random() * (i + 1))));
    }
    return arr;
  }
  static void swap(Array<int> arr, int i, int j) {
    int tmp = arr[i];
    (arr[i] = arr[j]);
    (arr[j] = tmp);
  }
  static double escape2(int people, int tryTimes) {
    double a = 0;
    for (int r = (tryTimes + 1); (r <= people); (r++)) {
      (a += jdiv(static_cast<double>(1), static_cast<double>(r)));
    }
    return (static_cast<double>(1) - a);
  }
  static void java_main(Array<String> args) {
    int people = 100;
    int tryTimes = 50;
    int testTimes = 100000;
    jout.println((String(u"参与游戏的人数 : ") + people));
    jout.println((String(u"每人的尝试次数 : ") + tryTimes));
    jout.println((String(u"模拟实验的次数 : ") + testTimes));
    jout.println(
        (String(u"通过模拟实验得到的概率为 : ") +
         Code07_PrisonersEscapeGame::escape1(people, tryTimes, testTimes)));
    jout.println((String(u"通过公式计算得到的概率为 : ") +
                  Code07_PrisonersEscapeGame::escape2(people, tryTimes)));
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code07_PrisonersEscapeGame::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 囚徒生存问题
// 有100个犯人被关在监狱，犯人编号0~99，监狱长准备了100个盒子，盒子编号0~99
// 这100个盒子排成一排，放在一个房间里面，盒子编号从左往右有序排列
//
最开始时，每个犯人的编号放在每个盒子里，两种编号一一对应，监狱长构思了一个处决犯人的计划
// 监狱长打开了很多盒子，并交换了盒子里犯人的编号
// 交换行为完全随机，但依然保持每个盒子都有一个犯人编号
// 监狱长规定，每个犯人单独进入房间，可以打开50个盒子，寻找自己的编号
// 该犯人全程无法和其他犯人进行任何交流，并且不能交换盒子中的编号，只能打开查看
//
寻找过程结束后把所有盒子关上，走出房间，然后下一个犯人再进入房间，重复上述过程
// 监狱长规定，每个犯人在尝试50次的过程中，都需要找到自己的编号
// 如果有任何一个犯人没有做到这一点，100个犯人全部处决
//
所有犯人在一起交谈的时机只能发生在游戏开始之前，游戏一旦开始直到最后一个人结束都无法交流
// 请尽量制定一个让所有犯人存活概率最大的策略
// 来自论文<The Cell Probe Complexity of Succinct Data Structures>
// 作者Anna Gal和Peter Bro Miltersen写于2007年
// 如今该题变成了流行题，还有大量科普视频
        // 通过多次模拟实验得到的概率
        // 求arr中最大环的长度
        // 生成随机arr
        // 原本每个位置的数都等概率出现在自己或者其他位置
        // 公式版
        // 一定要保证tryTimes大于等于people的一半，否则该函数失效
        // 导致死亡的情况数 : C(r,100) * (r-1)! * (100-r)!，r从51~100，累加起来
        // 死亡概率 : C(r,100) * (r-1)! * (100-r)! / 100!，r从51~100，累加起来
        // 化简后的死亡概率 : 1/r，r从51~100，累加起来
                // 一定要保证tryTimes大于等于people的一半
*/

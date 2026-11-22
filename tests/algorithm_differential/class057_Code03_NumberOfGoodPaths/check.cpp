#define main original_main
#include "../../../src/class057/Code03_NumberOfGoodPaths.cpp"
#undef main
int main(){jout.println(Code03_NumberOfGoodPaths::numberOfGoodPaths(Array<int>{1,3,2,1,3},Array<Array<int>>{Array<int>{0,1},Array<int>{0,2},Array<int>{2,3},Array<int>{2,4}}));jout.println(Code03_NumberOfGoodPaths::numberOfGoodPaths(Array<int>{1,1,2,2,3},Array<Array<int>>{Array<int>{0,1},Array<int>{1,2},Array<int>{2,3},Array<int>{2,4}}));}
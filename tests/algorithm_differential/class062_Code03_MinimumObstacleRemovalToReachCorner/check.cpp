#define main original_main
#include "../../../src/class062/Code03_MinimumObstacleRemovalToReachCorner.cpp"
#undef main
int main(){jout.println(Code03_MinimumObstacleRemovalToReachCorner::minimumObstacles(Array<Array<int>>{Array<int>{0,1,1},Array<int>{1,1,0},Array<int>{1,1,0}}));jout.println(Code03_MinimumObstacleRemovalToReachCorner::minimumObstacles(Array<Array<int>>{Array<int>{0,0},Array<int>{1,0}}));}
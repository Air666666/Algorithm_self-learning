// 原题测试 / 参考链接（保留上游原始地址）
// https://www.nowcoder.com/exam/test/70070648/detail?pid=27976983

// Source: algorithmzuo/algorithm-journey/src/class019/Code04_ReadByLine.java
// 不给定每行数据规模：读完整行后逐个解析数字，再计算这一行的和。
#include <iostream>
#include <sstream>
#include <string>
struct Code04_ReadByLine {
 static void runDemo(){
  std::ios::sync_with_stdio(false);std::cin.tie(nullptr);
  std::string line;
  while(std::getline(std::cin,line)){
   std::istringstream in(line);long long sum=0;int num;
   while(in>>num)sum+=num;
   std::cout<<sum<<'\n';
  }
 }
};
int main(){Code04_ReadByLine::runDemo();return 0;}

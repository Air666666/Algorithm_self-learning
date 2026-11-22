// 原题测试 / 参考链接（保留上游原始地址）
// https://oi-wiki.org/lang/java-pro/

// Source: algorithmzuo/algorithm-journey/src/class019/Code05_Kattio.java
// C++ 对应的按 token 读取示例：整数直接按整数解析，避免先经过 double 丢失精度。
// std::stod 支持科学计数法；无需模拟 Java StreamTokenizer 的解析缺陷。
#include <fstream>
#include <iomanip>
#include <iostream>
#include <optional>
#include <stdexcept>
#include <string>
struct Code05_Kattio {
 struct Kattio {
  std::ifstream inputFile;std::ofstream outputFile;
  std::istream* in;std::ostream* out;
  Kattio():in(&std::cin),out(&std::cout){}
  Kattio(std::istream& i,std::ostream& o):in(&i),out(&o){}
  Kattio(const std::string& i,const std::string& o):inputFile(i),outputFile(o),in(&inputFile),out(&outputFile){if(!inputFile||!outputFile)throw std::runtime_error("open failed");}
  std::optional<std::string> next(){std::string s;if(*in>>s)return s;return std::nullopt;}
  std::string token(){auto s=next();if(!s)throw std::runtime_error("unexpected EOF");return *s;}
  int nextInt(){return std::stoi(token());}
  long long nextLong(){return std::stoll(token());}
  double nextDouble(){return std::stod(token());}
  template<class T>void println(const T& x){*out<<x<<'\n';}
  void flush(){out->flush();}
  void close(){flush();if(inputFile.is_open())inputFile.close();if(outputFile.is_open())outputFile.close();}
 };
 static void show(){Kattio io;io.next();io.nextInt();io.nextDouble();io.nextLong();io.println("ans");io.close();}
 static void runDemo(){
  Kattio io;std::cout<<"请输入整数 131237128371723187 和科学计数法 5.6920E+0001：\n";
  long long n=io.nextLong();double d=io.nextDouble();
  io.println(n);std::cout<<std::setprecision(17);io.println(d);io.flush();
 }
};
int main(){Code05_Kattio::runDemo();return 0;}

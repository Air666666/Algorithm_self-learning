#define main original_main
#include "../../../src/class039/Code01_BasicCalculatorIII.cpp"
#undef main
int main(){jout.println(Code01_BasicCalculatorIII::calculate(String(u"1+2*3")));jout.println(Code01_BasicCalculatorIII::calculate(String(u"(2+3)*4")));jout.println(Code01_BasicCalculatorIII::calculate(String(u"12-(3*2)+8/4")));jout.println(Code01_BasicCalculatorIII::calculate(String(u"4*(3+2)-11")));jout.println(Code01_BasicCalculatorIII::calculate(String(u"100/3+4*2")));}
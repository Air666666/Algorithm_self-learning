// Ported from algorithmzuo/algorithm-journey/src/class003/BinarySystem.java
// 以下保留原课程注释；Java 专属说明不代表 C++ 规则。
#include <algorithm>
#include <chrono>
#include <climits>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <random>
#include <stdexcept>
#include <vector>

// 本文件的实现是用int来举例的
// 对于long类型完全同理
// 不过要注意，如果是long类型的数字num，有64位
// num & (1 << 48)，这种写法不对
// 因为1是一个int类型，只有32位，所以(1 << 48)早就溢出了，所以无意义
// 应该写成 : num & (1L << 48)
struct BinarySystem {
static int signedBits(std::uint32_t u){return u<=0x7fffffffU?static_cast<int>(u):static_cast<int>(static_cast<std::int64_t>(u)-4294967296LL);}
static int negate32(int n){return signedBits(0u-static_cast<std::uint32_t>(n));}
static int logicalRight(int n,unsigned s){return signedBits(static_cast<std::uint32_t>(n)>>(s&31));}
static int arithmeticRight(int n,unsigned s){s&=31;if(!s)return n;auto u=static_cast<std::uint32_t>(n)>>s;if(n<0)u|=(~std::uint32_t{0})<<(32-s);return signedBits(u);}


	// 打印一个int类型的数字，32位进制的状态
	// 左侧是高位，右侧是低位
	static void printBinary(int num) {
		for (int i = 31; i >= 0; i--) {
			// 下面这句写法，可以改成 :
			// std::cout << ((a & (1 << i)) != 0 ? "1" : "0");
			// 但不可以改成 :
			// std::cout << ((a & (1 << i)) == 1 ? "1" : "0");
			// 因为a如果第i位有1，那么(a & (1 << i))是2的i次方，而不一定是1
			// 比如，a = 0010011
			// a的第0位是1，第1位是1，第4位是1
			// (a & (1<<4)) == 16（不是1），说明a的第4位是1状态
			std::cout << ((static_cast<std::uint32_t>(num) & (std::uint32_t{1} << i)) == 0 ? "0" : "1");
		}
		std::cout << "\n";
	}

	static void runDemo() { std::cout<<std::boolalpha;
		// 非负数
		int a = 78;
		std::cout << a << "\n";
		printBinary(a);
		std::cout << "===a===" << "\n";
		// 负数
		int b = -6;
		std::cout << b << "\n";
		printBinary(b);
		std::cout << "===b===" << "\n";
		// 直接写二进制的形式定义变量
		int c = 0b1001110;
		std::cout << c << "\n";
		printBinary(c);
		std::cout << "===c===" << "\n";
		// 直接写十六进制的形式定义变量
		// 0100 -> 4
		// 1110 -> e
		// 0x4e -> 01001110
		int d = 0x4e;
		std::cout << d << "\n";
		printBinary(d);
		std::cout << "===d===" << "\n";
		// ~、相反数
		std::cout << a << "\n";
		printBinary(a);
		printBinary(~a);
		int e = ~a + 1;
		std::cout << e << "\n";
		printBinary(e);
		std::cout << "===e===" << "\n";
		// int、long的最小值，取相反数、绝对值，都是自己
		int f = INT_MIN;
		std::cout << f << "\n";
		printBinary(f);
		std::cout << negate32(f) << "\n";
		printBinary(negate32(f));
		std::cout << negate32(f) << "\n";
		printBinary(negate32(f));
		std::cout << "===f===" << "\n";
		// | & ^
		int g = 0b0001010;
		int h = 0b0001100;
		printBinary(g | h);
		printBinary(g & h);
		printBinary(g ^ h);
		std::cout << "===g、h===" << "\n";
		// 可以这么写 : int num = 3231 | 6434;
		// 可以这么写 : int num = 3231 & 6434;
		// 不能这么写 : int num = 3231 || 6434;
		// 不能这么写 : int num = 3231 && 6434;
		// 因为 ||、&& 是 逻辑或、逻辑与，只能连接bool类型
		// 不仅如此，|、& 连接的两侧一定都会计算
		// 而 ||、&& 有穿透性的特点
		std::cout << "test1测试开始" << "\n";
		bool first1=returnTrue(), second1=returnFalse();
		bool test1=first1 | second1;
		std::cout << "test1结果，" << test1 << "\n";
		std::cout << "test2测试开始" << "\n";
		bool test2 = returnTrue() || returnFalse();
		std::cout << "test2结果，" << test2 << "\n";
		std::cout << "test3测试开始" << "\n";
		bool first3=returnFalse(), second3=returnTrue();
		bool test3=first3 & second3;
		std::cout << "test3结果，" << test3 << "\n";
		std::cout << "test4测试开始" << "\n";
		bool test4 = returnFalse() && returnTrue();
		std::cout << "test4结果，" << test4 << "\n";
		std::cout << "===|、&、||、&&===" << "\n";
		// <<
		int i = 0b0011010;
		printBinary(i);
		printBinary(i << 1);
		printBinary(i << 2);
		printBinary(i << 3);
		std::cout << "===i << ===" << "\n";
		// 非负数 >> >>>，效果一样
		printBinary(i);
		printBinary(i >> 2);
		printBinary(logicalRight(i,2));
		std::cout << "===i >> >>>===" << "\n";
		// 负数 >> >>>，效果不一样
		int j = -268435456;
		printBinary(j);
		printBinary(arithmeticRight(j,2));
		printBinary(logicalRight(j,2));
		std::cout << "===j >> >>>===" << "\n";
		// 非负数 << 1，等同于乘以2
		// 非负数 << 2，等同于乘以4
		// 非负数 << 3，等同于乘以8
		// 非负数 << i，等同于乘以2的i次方
		// ...
		// 非负数 >> 1，等同于除以2
		// 非负数 >> 2，等同于除以4
		// 非负数 >> 3，等同于除以8
		// 非负数 >> i，等同于除以2的i次方
		// 只有非负数符合这个特征，负数不要用
		int k = 10;
		std::cout << k << "\n";
		std::cout << (k << 1) << "\n";
		std::cout << (k << 2) << "\n";
		std::cout << (k << 3) << "\n";
		std::cout << (k >> 1) << "\n";
		std::cout << (k >> 2) << "\n";
		std::cout << (k >> 3) << "\n";
		std::cout << "===k===" << "\n";
	}

	static bool returnTrue() {
		std::cout << "进入了returnTrue函数" << "\n";
		return true;
	}

	static bool returnFalse() {
		std::cout << "进入了returnFalse函数" << "\n";
		return false;
	}

};

int main(){BinarySystem::runDemo();return 0;}
